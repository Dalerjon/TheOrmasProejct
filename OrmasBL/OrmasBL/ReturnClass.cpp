#include "stdafx.h"
#include "ReturnClass.h"
#include "ReturnListClass.h"
#include "UserClass.h"
#include "BalanceClass.h"
#include "RefundClass.h"
#include "StatusClass.h"
#include "StockClass.h"

namespace BusinessLayer
{
	Return::Return(DataLayer::returnsCollection rCollection)
	{
		id = std::get<0>(rCollection);
		clientID = std::get<1>(rCollection);
		date = std::get<2>(rCollection);
		executionDate = std::get<3>(rCollection);
		employeeID = std::get<4>(rCollection);
		count = std::get<5>(rCollection);
		sum = std::get<6>(rCollection);
		statusID = std::get<7>(rCollection);
		currencyID = std::get<8>(rCollection);
	}

	int Return::GetID()
	{
		return id;
	}

	int Return::GetClientID()
	{
		return clientID;
	}

	std::string Return::GetDate()
	{
		return date;
	}

	std::string Return::GetExecutionDate()
	{
		return executionDate;
	}

	int Return::GetEmployeeID()
	{
		return employeeID;
	}

	double Return::GetCount()
	{
		return count;
	}

	double Return::GetSum()
	{
		return sum;
	}

	int Return::GetStatusID()
	{
		return statusID;
	}

	int Return::GetCurrencyID()
	{
		return currencyID;
	}

	void Return::SetID(int rID)
	{
		id = rID;
	}
	void Return::SetClientID(int rClientID)
	{
		clientID = rClientID;
	}
	void Return::SetDate(std::string rDate)
	{
		date = rDate;
	}
	void Return::SetExecutionDate(std::string rExecutionDate)
	{
		executionDate = rExecutionDate;
	}
	void Return::SetEmployeeID(int rEmployeeID)
	{
		employeeID = rEmployeeID;
	}
	
	void Return::SetCount(double rCount)
	{
		count = rCount;
	}

	void Return::SetSum(double rSum)
	{
		sum = rSum;
	}

	void Return::SetStatusID(int rStatusID)
	{
		statusID = rStatusID;
	}

	void Return::SetCurrencyID(int rCurrencyID)
	{
		currencyID = rCurrencyID;
	}

	bool Return::CreateReturn(DataLayer::OrmasDal& ormasDal, int clID, std::string rDate, std::string rExecDate, int eID, double rCount,
		double rSum, int sID, int cID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, clID, rDate, rCount, rSum, cID, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		clientID = clID;
		date = rDate;
		executionDate = rExecDate;
		employeeID = eID;
		count = rCount;
		sum = rSum;
		statusID = sID;
		currencyID = cID;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateReturn(id, clientID, date, executionDate, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, clientID, errorMessage))
				{
					ormasDal.CommitTransaction(errorMessage);
					return true;
				}
				else
				{
					ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
			ormasDal.CommitTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Return::CreateReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateReturn(id, clientID, date, executionDate, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, clientID, errorMessage))
				{
					ormasDal.CommitTransaction(errorMessage);
					return true;
				}
				else
				{
					ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
			ormasDal.CommitTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Return::DeleteReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!ormasDal.StartTransaction(errorMessage))
			return false;
		Return ret;
		if (!ret.GetReturnByID(ormasDal, id, errorMessage))
		{
			return false;
		}
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		if (ret.GetStatusID() == statusMap.find("EXECUTED")->second)
		{
			errorMessage = "Cannot delete document with \"EXECUTED\" status!";
			return false;
		}
		if (ormasDal.DeleteReturn(id, errorMessage))
		{
			if (ormasDal.DeleteListByReturnID(id, errorMessage))
			{
				Clear();
				ormasDal.CommitTransaction(errorMessage);
				return true;
			}
			else
			{
				ormasDal.CancelTransaction(errorMessage);
			}
		}
		else
		{
			ormasDal.CancelTransaction(errorMessage);
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Return::UpdateReturn(DataLayer::OrmasDal& ormasDal, int clID, std::string rDate, std::string rExecDate, int eID, double rCount,
		double rSum, int sID, int cID, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		std::map<int, double> prodCountMap = GetProductCount(ormasDal, id, errorMessage);
		if (0 == prodCountMap.size())
			return false;
		clientID = clID;
		date = rDate;
		executionDate = rExecDate;
		employeeID = eID;
		count = rCount;
		sum = rSum;
		statusID = sID;
		currencyID = cID;
		previousSum = GetCurrentSum(ormasDal, id, errorMessage);
		previousCount = GetCurrentCount(ormasDal, id, errorMessage);
		previousStatusID = GetCurrentStatusID(ormasDal, id, errorMessage);
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateReturn(id, clientID, date, executionDate, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (!ChangesAtStock(ormasDal, id, clientID, errorMessage))
				{
					ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				else
				{
					ormasDal.CommitTransaction(errorMessage);
					return false;
				}
			}
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID == statusMap.find("EXECUTED")->second && previousSum != sum)
			{
				if (count != previousCount || sum != previousSum)
				{
					if (ChangesAtStock(ormasDal, id, clientID, prodCountMap, previousSum, errorMessage))
					{
						ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						ormasDal.CommitTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					ormasDal.CommitTransaction(errorMessage);
					return true;
				}
			}
			ormasDal.CancelTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Return::UpdateReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		std::map<int, double> prodCountMap = GetProductCount(ormasDal, id, errorMessage);
		if (0 == prodCountMap.size())
			return false;
		previousSum = GetCurrentSum(ormasDal, id, errorMessage);
		previousCount = GetCurrentCount(ormasDal, id, errorMessage);
		previousStatusID = GetCurrentStatusID(ormasDal, id, errorMessage);
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateReturn(id, clientID, date, executionDate, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, clientID, errorMessage))
				{
					ormasDal.CommitTransaction(errorMessage);
					return true;
				}
				else
				{
					ormasDal.CommitTransaction(errorMessage);
					return false;
				}
			}
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID == statusMap.find("EXECUTED")->second && previousSum != sum)
			{
				if (count != previousCount || sum != previousSum)
				{
					if (ChangesAtStock(ormasDal, id, clientID, prodCountMap, previousSum, errorMessage))
					{
						ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						ormasDal.CommitTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					ormasDal.CommitTransaction(errorMessage);
					return true;
				}
			}
			ormasDal.CancelTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	std::string Return::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != clientID || !date.empty() || !executionDate.empty() || 0 != employeeID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForReturn(id, clientID, date, executionDate, employeeID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool Return::GetReturnByID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage)
	{
		id = rID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::returnsViewCollection> returnVector = ormasDal.GetReturns(errorMessage, filter);
		if (0 != returnVector.size())
		{
			id = std::get<0>(returnVector.at(0));
			date = std::get<1>(returnVector.at(0));
			executionDate = std::get<2>(returnVector.at(0));
			count = std::get<13>(returnVector.at(0));
			sum = std::get<14>(returnVector.at(0));
			employeeID = std::get<16>(returnVector.at(0));
			clientID = std::get<17>(returnVector.at(0));
			statusID = std::get<18>(returnVector.at(0));
			currencyID = std::get<19>(returnVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find return with this id";
		}
		return false;
	}
	
	bool Return::IsEmpty()
	{
		if (0 == id && date == "" && date == "" && 0 == count && 0 == sum && 0 == employeeID && 0 == clientID && 0 == statusID && 0 == currencyID)
			return true;
		return false;
	}

	void Return::Clear()
	{
		id = 0;
		date.clear();
		count = 0;
		sum = 0;
		employeeID = 0;
		clientID = 0;
		statusID = 0;
		currencyID = 0;
	}

	bool Return::IsDuplicate(DataLayer::OrmasDal& ormasDal, int clID, std::string rDate, double rCount, double rSum,
		int cID, std::string& errorMessage)
	{
		Return ret;
		ret.SetClientID(clID);
		ret.SetDate(rDate);
		ret.SetCount(rCount);
		ret.SetSum(rSum);
		ret.SetCurrencyID(cID);
		std::string filter = ret.GenerateFilter(ormasDal);
		std::vector<DataLayer::returnsViewCollection> returnVector = ormasDal.GetReturns(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == returnVector.size())
		{
			return false;
		}
		errorMessage = "Return with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Return::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Return ret;
		ret.SetClientID(clientID);
		ret.SetDate(date);
		ret.SetCount(count);
		ret.SetSum(sum);
		ret.SetCurrencyID(currencyID);
		std::string filter = ret.GenerateFilter(ormasDal);
		std::vector<DataLayer::returnsViewCollection> returnVector = ormasDal.GetReturns(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == returnVector.size())
		{
			return false;
		}
		errorMessage = "Return with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	double Return::GetCurrentSum(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage)
	{
		Return ret;
		ret.GetReturnByID(ormasDal, rID, errorMessage);
		if (errorMessage.empty())
			return ret.GetSum();
		return 0;
	}

	double Return::GetCurrentCount(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage)
	{
		Return ret;
		ret.GetReturnByID(ormasDal, rID, errorMessage);
		if (errorMessage.empty())
			return ret.GetCount();
		return 0;
	}

	bool Return::ChangesAtStock(DataLayer::OrmasDal& ormasDal, int rID, int cID, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByReturnProduct(ormasDal, rID, cID, errorMessage);
	}

	bool Return::ChangesAtStock(DataLayer::OrmasDal& ormasDal, int rID, int cID, std::map<int, double> pProdCountMap, double rSum, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByReturnProduct(ormasDal, rID, cID, pProdCountMap, rSum, errorMessage);
	}

	int Return::GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage)
	{
		Return ret;
		ret.GetReturnByID(ormasDal, rID, errorMessage);
		if (errorMessage.empty())
			return ret.GetStatusID();
		return 0;
	}
	std::map<int, double> Return::GetProductCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		std::map<int, double> mapProdCount;
		ReturnList rPList;
		rPList.SetReturnID(cpID);
		std::string filter = rPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::returnListViewCollection> productListVector = ormasDal.GetReturnList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				mapProdCount.insert(std::make_pair(std::get<11>(item), std::get<7>(item)));
			}
		}
		return mapProdCount;
	}
}