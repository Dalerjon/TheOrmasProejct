#include "stdafx.h"
#include "TransportClass.h"
#include "UserClass.h"
#include "StatusClass.h"

namespace BusinessLayer
{
	Transport::Transport(DataLayer::transportsCollection tCollection)
	{
		id = std::get<0>(tCollection);
		employeeID = std::get<1>(tCollection);
		date = std::get<2>(tCollection);
		executionDate = std::get<3>(tCollection);
		stockEmployeeID = std::get<4>(tCollection);
		count = std::get<5>(tCollection);
		sum = std::get<6>(tCollection);
		statusID = std::get<7>(tCollection);
		currencyID = std::get<8>(tCollection);
	}

	int Transport::GetID()
	{
		return id;
	}

	int Transport::GetEmployeeID()
	{
		return employeeID;
	}

	std::string Transport::GetDate()
	{
		return date;
	}

	std::string Transport::GetExecutionDate()
	{
		return executionDate;
	}

	int Transport::GetStockEmployeeID()
	{
		return stockEmployeeID;
	}

	int Transport::GetCount()
	{
		return count;
	}

	double Transport::GetSum()
	{
		return sum;
	}

	int Transport::GetStatusID()
	{
		return statusID;
	}

	int Transport::GetCurrencyID()
	{
		return currencyID;
	}

	void Transport::SetID(int tID)
	{
		id = tID;
	}
	void Transport::SetEmployeeID(int tEmployeeID)
	{
		employeeID = tEmployeeID;
	}
	void Transport::SetDate(std::string tDate)
	{
		date = tDate;
	}
	void Transport::SetExecutionDate(std::string tExecutionDate)
	{
		executionDate = tExecutionDate;
	}
	void Transport::SetStockEmployeeID(int tStockEmployeeID)
	{
		stockEmployeeID = tStockEmployeeID;
	}

	void Transport::SetCount(int tCount)
	{
		count = tCount;
	}

	void Transport::SetSum(double tSum)
	{
		sum = tSum;
	}

	void Transport::SetStatusID(int tStatusID)
	{
		statusID = tStatusID;
	}

	void Transport::SetCurrencyID(int tCurrencyID)
	{
		currencyID = tCurrencyID;
	}

	bool Transport::CreateTransport(DataLayer::OrmasDal& ormasDal, int uID, std::string tDate, std::string tExecDate, 
		int seID, int tCount, double tSum, int sID, int cID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, uID, tDate, seID ,tCount, tSum, cID, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		employeeID = uID;
		date = tDate;
		executionDate = tExecDate;
		stockEmployeeID = seID;
		count = tCount;
		sum = tSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.CreateTransport(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	bool Transport::CreateTransport(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		if (0 != id && ormasDal.CreateTransport(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Transport::DeleteTransport(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!ormasDal.StartTransaction(errorMessage))
			return false;
		if (ormasDal.DeleteTransport(id, errorMessage))
		{
			if (ormasDal.DeleteListByTransportID(id, errorMessage))
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
	bool Transport::UpdateTransport(DataLayer::OrmasDal& ormasDal, int uID, std::string tDate, std::string tExecnDate,
		int eID, int tCount, double tSum, int sID, int cID, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		employeeID = uID;
		date = tDate;
		executionDate = tExecnDate;
		stockEmployeeID = eID;
		count = tCount;
		sum = tSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.UpdateTransport(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Transport::UpdateTransport(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		if (0 != id && ormasDal.UpdateTransport(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string Transport::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != employeeID || !date.empty() || !executionDate.empty() || 0 != stockEmployeeID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForTransport(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool Transport::GetTransportByID(DataLayer::OrmasDal& ormasDal, int tID, std::string& errorMessage)
	{
		id = tID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::transportsViewCollection> transportVector = ormasDal.GetTransports(errorMessage, filter);
		if (0 != transportVector.size())
		{
			id = std::get<0>(transportVector.at(0));
			date = std::get<1>(transportVector.at(0));
			executionDate = std::get<2>(transportVector.at(0));
			count = std::get<13>(transportVector.at(0));
			sum = std::get<14>(transportVector.at(0));
			stockEmployeeID = std::get<16>(transportVector.at(0));
			employeeID = std::get<17>(transportVector.at(0));
			statusID = std::get<18>(transportVector.at(0));
			currencyID = std::get<19>(transportVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find transport with this id";
		}
		return false;
	}

	bool Transport::IsEmpty()
	{
		if (0 == id && date == "" && executionDate == "" && 0 == count && 0 == sum && 0 == stockEmployeeID && 0 == employeeID && 0 == statusID
			&& 0 == currencyID)
			return false;
		return true;
	}

	void Transport::Clear()
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

	bool Transport::IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string tDate, int seID, int tCount, double tSum,
		int cID, std::string& errorMessage)
	{
		Transport transport;
		transport.SetEmployeeID(eID);
		transport.SetDate(tDate);
		transport.SetStockEmployeeID(seID);
		transport.SetCount(tCount);
		transport.SetSum(tSum);
		transport.SetCurrencyID(cID);
		std::string filter = transport.GenerateFilter(ormasDal);
		std::vector<DataLayer::transportsViewCollection> transportVector = ormasDal.GetTransports(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == transportVector.size())
		{
			return false;
		}
		errorMessage = "Transport with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Transport::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Transport transport;
		transport.SetEmployeeID(employeeID);
		transport.SetDate(date);
		transport.SetStockEmployeeID(stockEmployeeID);
		transport.SetCount(count);
		transport.SetSum(sum);
		transport.SetCurrencyID(currencyID);
		std::string filter = transport.GenerateFilter(ormasDal);
		std::vector<DataLayer::transportsViewCollection> transportVector = ormasDal.GetTransports(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == transportVector.size())
		{
			return false;
		}
		errorMessage = "Transport with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

}