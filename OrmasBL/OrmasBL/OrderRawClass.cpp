#include "stdafx.h"
#include "OrderRawClass.h"
#include "UserClass.h"
#include "StatusClass.h"

namespace BusinessLayer
{
	OrderRaw::OrderRaw(DataLayer::orderRawsCollection oCollection)
	{
		id = std::get<0>(oCollection);
		employeeID = std::get<1>(oCollection);
		date = std::get<2>(oCollection);
		executionDate = std::get<3>(oCollection);
		stockEmployeeID = std::get<4>(oCollection);
		count = std::get<5>(oCollection);
		sum = std::get<6>(oCollection);
		statusID = std::get<7>(oCollection);
		currencyID = std::get<8>(oCollection);
	}

	int OrderRaw::GetID()
	{
		return id;
	}

	int OrderRaw::GetEmployeeID()
	{
		return employeeID;
	}

	std::string OrderRaw::GetDate()
	{
		return date;
	}

	std::string OrderRaw::GetExecutionDate()
	{
		return executionDate;
	}

	int OrderRaw::GetStockEmployeeID()
	{
		return stockEmployeeID;
	}

	int OrderRaw::GetCount()
	{
		return count;
	}

	double OrderRaw::GetSum()
	{
		return sum;
	}

	int OrderRaw::GetStatusID()
	{
		return statusID;
	}

	int OrderRaw::GetCurrencyID()
	{
		return currencyID;
	}

	void OrderRaw::SetID(int oID)
	{
		id = oID;
	}
	void OrderRaw::SetEmployeeID(int oEmployeeID)
	{
		employeeID = oEmployeeID;
	}
	void OrderRaw::SetDate(std::string oDate)
	{
		date = oDate;
	}
	void OrderRaw::SetExecutionDate(std::string oExecutionDate)
	{
		executionDate = oExecutionDate;
	}
	void OrderRaw::SetStockEmployeeID(int oStockEmployeeID)
	{
		stockEmployeeID = oStockEmployeeID;
	}

	void OrderRaw::SetCount(int oCount)
	{
		count = oCount;
	}

	void OrderRaw::SetSum(double oSum)
	{
		sum = oSum;
	}

	void OrderRaw::SetStatusID(int oStatusID)
	{
		statusID = oStatusID;
	}

	void OrderRaw::SetCurrencyID(int oCurrencyID)
	{
		currencyID = oCurrencyID;
	}

	bool OrderRaw::CreateOrderRaw(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, std::string oExecDate, 
		int seID, int oCount, double oSum, int sID, int cID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, uID, oDate, seID ,oCount, oSum, cID, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		employeeID = uID;
		date = oDate;
		executionDate = oExecDate;
		stockEmployeeID = seID;
		count = oCount;
		sum = oSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.CreateOrderRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	bool OrderRaw::CreateOrderRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		if (0 != id && ormasDal.CreateOrderRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool OrderRaw::DeleteOrderRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!ormasDal.StartTransaction(errorMessage))
			return false;
		if (ormasDal.DeleteOrderRaw(id, errorMessage))
		{
			if (ormasDal.DeleteListByOrderRawID(id, errorMessage))
			{
				id = 0;
				employeeID = 0;
				date.clear();
				executionDate.clear();
				stockEmployeeID = 0;
				count = 0;
				sum = 0;
				statusID = 0;
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
	bool OrderRaw::UpdateOrderRaw(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, std::string oExecnDate,
		int eID, int oCount, double oSum, int sID, int cID, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		employeeID = uID;
		date = oDate;
		executionDate = oExecnDate;
		stockEmployeeID = eID;
		count = oCount;
		sum = oSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.UpdateOrderRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool OrderRaw::UpdateOrderRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		if (0 != id && ormasDal.UpdateOrderRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string OrderRaw::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != employeeID || !date.empty() || !executionDate.empty() || 0 != stockEmployeeID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForOrderRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool OrderRaw::GetOrderRawByID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage)
	{
		id = cID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::orderRawsViewCollection> orderRawVector = ormasDal.GetOrderRaws(errorMessage, filter);
		if (0 != orderRawVector.size())
		{
			id = std::get<0>(orderRawVector.at(0));
			date = std::get<1>(orderRawVector.at(0));
			executionDate = std::get<2>(orderRawVector.at(0));
			count = std::get<13>(orderRawVector.at(0));
			sum = std::get<14>(orderRawVector.at(0));
			stockEmployeeID = std::get<16>(orderRawVector.at(0));
			employeeID = std::get<17>(orderRawVector.at(0));
			statusID = std::get<18>(orderRawVector.at(0));
			currencyID = std::get<19>(orderRawVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find consume product with this id";
		}
		return false;
	}

	bool OrderRaw::IsEmpty()
	{
		if (0 == id && date == "" && executionDate == "" && 0 == count && 0 == sum && 0 == stockEmployeeID && 0 == employeeID && 0 == statusID
			&& 0 == currencyID)
			return false;
		return true;
	}

	void OrderRaw::Clear()
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

	bool OrderRaw::IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string oDate, int seID, int oCount, double oSum,
		int cID, std::string& errorMessage)
	{
		OrderRaw orderRaw;
		orderRaw.SetEmployeeID(eID);
		orderRaw.SetDate(oDate);
		orderRaw.SetStockEmployeeID(seID);
		orderRaw.SetCount(oCount);
		orderRaw.SetSum(oSum);
		orderRaw.SetCurrencyID(cID);
		std::string filter = orderRaw.GenerateFilter(ormasDal);
		std::vector<DataLayer::orderRawsViewCollection> orderRawVector = ormasDal.GetOrderRaws(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == orderRawVector.size())
		{
			return false;
		}
		errorMessage = "Order raw with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool OrderRaw::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		OrderRaw orderRaw;
		orderRaw.SetEmployeeID(employeeID);
		orderRaw.SetDate(date);
		orderRaw.SetStockEmployeeID(stockEmployeeID);
		orderRaw.SetCount(count);
		orderRaw.SetSum(sum);
		orderRaw.SetCurrencyID(currencyID);
		std::string filter = orderRaw.GenerateFilter(ormasDal);
		std::vector<DataLayer::orderRawsViewCollection> orderRawVector = ormasDal.GetOrderRaws(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == orderRawVector.size())
		{
			return false;
		}
		errorMessage = "Order raw with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

}