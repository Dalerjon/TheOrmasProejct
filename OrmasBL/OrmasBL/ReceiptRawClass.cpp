#include "stdafx.h"
#include "ReceiptRawClass.h"
#include "ReceiptRawListClass.h"
#include "UserClass.h"
#include "StatusClass.h"
#include "StockClass.h"

namespace BusinessLayer
{
	ReceiptRaw::ReceiptRaw(DataLayer::receiptRawsCollection rCollection)
	{
		id = std::get<0>(rCollection);
		employeeID = std::get<1>(rCollection);
		date = std::get<2>(rCollection);
		executionDate = std::get<3>(rCollection);
		stockEmployeeID = std::get<4>(rCollection);
		count = std::get<5>(rCollection);
		sum = std::get<6>(rCollection);
		statusID = std::get<7>(rCollection);
		currencyID = std::get<8>(rCollection);
	}

	int ReceiptRaw::GetID()
	{
		return id;
	}

	int ReceiptRaw::GetEmployeeID()
	{
		return employeeID;
	}

	std::string ReceiptRaw::GetDate()
	{
		return date;
	}

	std::string ReceiptRaw::GetExecutionDate()
	{
		return executionDate;
	}

	int ReceiptRaw::GetStockEmployeeID()
	{
		return stockEmployeeID;
	}

	double ReceiptRaw::GetCount()
	{
		return count;
	}

	double ReceiptRaw::GetSum()
	{
		return sum;
	}

	int ReceiptRaw::GetStatusID()
	{
		return statusID;
	}

	int ReceiptRaw::GetCurrencyID()
	{
		return currencyID;
	}

	void ReceiptRaw::SetID(int rID)
	{
		id = rID;
	}
	void ReceiptRaw::SetEmployeeID(int rEmployeeID)
	{
		employeeID = rEmployeeID;
	}
	void ReceiptRaw::SetDate(std::string rDate)
	{
		date = rDate;
	}
	void ReceiptRaw::SetExecutionDate(std::string rExecutionDate)
	{
		executionDate = rExecutionDate;
	}
	void ReceiptRaw::SetStockEmployeeID(int rStockEmployeeID)
	{
		stockEmployeeID = rStockEmployeeID;
	}

	void ReceiptRaw::SetCount(double rCount)
	{
		count = rCount;
	}

	void ReceiptRaw::SetSum(double rSum)
	{
		sum = rSum;
	}

	void ReceiptRaw::SetStatusID(int rStatusID)
	{
		statusID = rStatusID;
	}

	void ReceiptRaw::SetCurrencyID(int rCurrencyID)
	{
		currencyID = rCurrencyID;
	}

	bool ReceiptRaw::CreateReceiptRaw(DataLayer::OrmasDal& ormasDal, int uID, std::string rDate, std::string rExecDate, 
		int seID, double rCount, double rSum, int sID, int cID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, uID, rDate, seID , rCount, rSum, cID, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		employeeID = uID;
		date = rDate;
		executionDate = rExecDate;
		stockEmployeeID = seID;
		count = rCount;
		sum = rSum;
		statusID = sID;
		currencyID = cID;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateReceiptRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, errorMessage))
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

	bool ReceiptRaw::CreateReceiptRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateReceiptRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, errorMessage))
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
	bool ReceiptRaw::DeleteReceiptRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!ormasDal.StartTransaction(errorMessage))
			return false;
		ReceiptRaw rRaw;
		if (!rRaw.GetReceiptRawByID(ormasDal, id, errorMessage))
		{
			return false;
		}
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		if (rRaw.GetStatusID() == statusMap.find("EXECUTED")->second)
		{
			errorMessage = "Cannot delete document with \"EXECUTED\" status!";
			return false;
		}
		if (ormasDal.DeleteReceiptRaw(id, errorMessage))
		{
			if (ormasDal.DeleteListByReceiptRawID(id, errorMessage))
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
	bool ReceiptRaw::UpdateReceiptRaw(DataLayer::OrmasDal& ormasDal, int uID, std::string rDate, std::string rExecnDate,
		int eID, double rCount, double rSum, int sID, int cID, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		std::map<int, double> prodCountMap = GetProductCount(ormasDal, id, errorMessage);
		if (0 == prodCountMap.size())
			return false;
		employeeID = uID;
		date = rDate;
		executionDate = rExecnDate;
		stockEmployeeID = eID;
		count = rCount;
		sum = rSum;
		statusID = sID;
		currencyID = cID;
		prevSum = GetCurrentSum(ormasDal, id, errorMessage);
		prevCount = GetCurrentCount(ormasDal, id, errorMessage);
		previousStatusID = GetCurrentStatusID(ormasDal, id, errorMessage);
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateReceiptRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, errorMessage))
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
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID == statusMap.find("EXECUTED")->second)
			{
				if (count != prevCount || sum != prevSum)
				{
					if (ChangesAtStock(ormasDal, id, prodCountMap, prevSum, errorMessage))
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
				else
				{
					ormasDal.CommitTransaction(errorMessage);
					return true;
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
	bool ReceiptRaw::UpdateReceiptRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		std::map<int, double> prodCountMap = GetProductCount(ormasDal, id, errorMessage);
		if (0 == prodCountMap.size())
			return false;
		prevSum = GetCurrentSum(ormasDal, id, errorMessage);
		prevCount = GetCurrentCount(ormasDal, id, errorMessage);
		previousStatusID = GetCurrentStatusID(ormasDal, id, errorMessage);
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateReceiptRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, errorMessage))
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
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID == statusMap.find("EXECUTED")->second)
			{
				if (count != prevCount || sum != prevSum)
				{
					if (ChangesAtStock(ormasDal, id, prodCountMap, prevSum, errorMessage))
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
				else
				{
					ormasDal.CommitTransaction(errorMessage);
					return true;
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

	std::string ReceiptRaw::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != employeeID || !date.empty() || !executionDate.empty() || 0 != stockEmployeeID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForReceiptRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool ReceiptRaw::GetReceiptRawByID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage)
	{
		id = rID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptRawsViewCollection> receiptRawVector = ormasDal.GetReceiptRaws(errorMessage, filter);
		if (0 != receiptRawVector.size())
		{
			id = std::get<0>(receiptRawVector.at(0));
			date = std::get<1>(receiptRawVector.at(0));
			executionDate = std::get<2>(receiptRawVector.at(0));
			count = std::get<13>(receiptRawVector.at(0));
			sum = std::get<14>(receiptRawVector.at(0));
			stockEmployeeID = std::get<16>(receiptRawVector.at(0));
			employeeID = std::get<17>(receiptRawVector.at(0));
			statusID = std::get<18>(receiptRawVector.at(0));
			currencyID = std::get<19>(receiptRawVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find receipt raw with this id";
		}
		return false;
	}

	bool ReceiptRaw::IsEmpty()
	{
		if (0 == id && date == "" && executionDate == "" && 0 == count && 0 == sum && 0 == stockEmployeeID && 0 == employeeID && 0 == statusID
			&& 0 == currencyID)
			return false;
		return true;
	}

	void ReceiptRaw::Clear()
	{
		id = 0;
		date.clear();
		executionDate.clear();
		count = 0;
		sum = 0;
		stockEmployeeID = 0;
		employeeID = 0;
		statusID = 0;
		currencyID = 0;
	}

	bool ReceiptRaw::IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string rDate, int seID, double rCount, double rSum,
		int cID, std::string& errorMessage)
	{
		ReceiptRaw receiptRaw;
		receiptRaw.Clear();
		errorMessage.clear();
		receiptRaw.SetEmployeeID(eID);
		receiptRaw.SetDate(rDate);
		receiptRaw.SetStockEmployeeID(seID);
		receiptRaw.SetCount(rCount);
		receiptRaw.SetSum(rSum);
		receiptRaw.SetCurrencyID(cID);
		std::string filter = receiptRaw.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptRawsViewCollection> receiptRawVector = ormasDal.GetReceiptRaws(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == receiptRawVector.size())
		{
			return false;
		}
		errorMessage = "Receipt raw with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool ReceiptRaw::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		ReceiptRaw receiptRaw;
		receiptRaw.Clear();
		errorMessage.clear();
		receiptRaw.SetEmployeeID(employeeID);
		receiptRaw.SetDate(date);
		receiptRaw.SetStockEmployeeID(stockEmployeeID);
		receiptRaw.SetCount(count);
		receiptRaw.SetSum(sum);
		receiptRaw.SetCurrencyID(currencyID);
		std::string filter = receiptRaw.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptRawsViewCollection> receiptRawVector = ormasDal.GetReceiptRaws(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == receiptRawVector.size())
		{
			return false;
		}
		errorMessage = "Receipt raw with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool ReceiptRaw::ChangesAtStock(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByReceiptRaw(ormasDal, cpID, errorMessage);
	}

	bool ReceiptRaw::ChangesAtStock(DataLayer::OrmasDal& ormasDal, int cpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByReceiptRaw(ormasDal, cpID, pProdCountMap, pSum, errorMessage);
	}

	double ReceiptRaw::GetCurrentSum(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		ReceiptRaw rRaw;
		if (rRaw.GetReceiptRawByID(ormasDal, cpID, errorMessage))
			return rRaw.GetSum();
		return 0;
	}

	double ReceiptRaw::GetCurrentCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		ReceiptRaw rRaw;
		if (rRaw.GetReceiptRawByID(ormasDal, cpID, errorMessage))
			return rRaw.GetCount();
		return 0;
	}

	int ReceiptRaw::GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage)
	{
		ReceiptRaw rRaw;
		if (rRaw.GetReceiptRawByID(ormasDal, cID, errorMessage))
			return rRaw.GetStatusID();
		return 0;
	}

	std::map<int, double> ReceiptRaw::GetProductCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		std::map<int, double> mapProdCount;
		ReceiptRawList rPList;
		rPList.SetReceiptRawID(cpID);
		std::string filter = rPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptRawListViewCollection> productListVector = ormasDal.GetReceiptRawList(errorMessage, filter);
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