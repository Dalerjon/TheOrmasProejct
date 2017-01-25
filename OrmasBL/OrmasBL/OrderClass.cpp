#include "stdafx.h"
#include "OrderClass.h"

namespace BusinessLayer
{
	Order::Order(DataLayer::ordersCollection oCollection)
	{
		id = std::get<0>(oCollection);
		userID = std::get<1>(oCollection);
		date = std::get<2>(oCollection);
		workerID = std::get<3>(oCollection);
		count = std::get<4>(oCollection);
		sum = std::get<5>(oCollection);
		statusID = std::get<6>(oCollection);
		currencyID = std::get<7>(oCollection);
	}

	int Order::GetID()
	{
		return id;
	}

	int Order::GetUserID()
	{
		return userID;
	}

	std::string Order::GetDate()
	{
		return date;
	}

	int Order::GetWorkerID()
	{
		return workerID;
	}

	int Order::GetCount()
	{
		return count;
	}

	double Order::GetSum()
	{
		return sum;
	}

	int Order::GetStatusID()
	{
		return statusID;
	}

	int Order::GetCurrencyID()
	{
		return currencyID;
	}

	void Order::SetID(int oID)
	{
		id = oID;
	}
	void Order::SetUserID(int oUserID)
	{
		userID = oUserID;
	}
	void Order::SetDate(std::string oDate)
	{
		date = oDate;
	}
	void Order::SetWorkerID(int oWorkerID)
	{
		workerID = oWorkerID;
	}
	
	void Order::SetCount(int oCount)
	{
		count = oCount;
	}

	void Order::SetSum(double oSum)
	{
		sum = oSum;
	}

	void Order::SetStatusID(int oStatusID)
	{
		statusID = oStatusID;
	}

	void Order::SetCurrencyID(int oCurrencyID)
	{
		currencyID = oCurrencyID;
	}

	bool Order::CreateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, int oCount, double oSum,
		int sID, int cID, std::string& errorMessage)
	{
		//id = ormasDal.GenerateID();
		userID = uID;
		date = oDate;
		workerID = wID;
		count = oCount;
		sum = oSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.CreateOrder(id, userID, date, workerID, count, sum, statusID, currencyID,errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	bool Order::CreateOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		//id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateOrder(id, userID, date, workerID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Order::DeleteOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		userID = 0;
		date.clear();
		workerID = 0;
		count = 0;
		sum = 0;
		statusID = 0;
		if (ormasDal.DeleteOrder(id, errorMessage))
		{
			id = 0;
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Order::UpdateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, int oCount, double oSum, 
		int sID, int cID, std::string& errorMessage)
	{
		userID = uID;
		date = oDate;
		workerID = wID;
		count = oCount;
		sum = oSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.UpdateOrder(id, userID, date, workerID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Order::UpdateOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateOrder(id, userID, date, workerID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string Order::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != userID || !date.empty() ||0 != workerID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForOrder(id, userID, date, workerID, count, sum, statusID, currencyID);
		}
		return "";
	}
	bool Order::GetOrderByID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		id = oID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::ordersViewCollection> orderVector = ormasDal.GetOrders(errorMessage, filter);
		if (0 != orderVector.size())
		{
			id = std::get<0>(orderVector.at(0));
			date = std::get<1>(orderVector.at(0));
			count = std::get<10>(orderVector.at(0));
			sum = std::get<11>(orderVector.at(0));
			workerID = std::get<13>(orderVector.at(0));
			userID = std::get<14>(orderVector.at(0));
			statusID = std::get<15>(orderVector.at(0));
			currencyID = std::get<16>(orderVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find order with this id";
		}
		return false;
	}
	bool Order::IsEmpty()
	{
		if(0 == id && date == "" && 0 == count && 0 == sum && 0 == workerID && 0 == userID && 0 == statusID && 0 == currencyID)
			return false;
		return true;
	}
}