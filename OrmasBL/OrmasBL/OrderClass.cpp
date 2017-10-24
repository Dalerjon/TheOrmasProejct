#include "stdafx.h"
#include "OrderClass.h"

namespace BusinessLayer
{
	Order::Order(DataLayer::ordersCollection oCollection)
	{
		id = std::get<0>(oCollection);
		clientID = std::get<1>(oCollection);
		date = std::get<2>(oCollection);
		employeeID = std::get<3>(oCollection);
		count = std::get<4>(oCollection);
		sum = std::get<5>(oCollection);
		statusID = std::get<6>(oCollection);
		currencyID = std::get<7>(oCollection);
	}

	int Order::GetID()
	{
		return id;
	}

	int Order::GetClientID()
	{
		return clientID;
	}

	std::string Order::GetDate()
	{
		return date;
	}

	int Order::GetEmployeeID()
	{
		return employeeID;
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
	void Order::SetClientID(int oClientID)
	{
		clientID = oClientID;
	}
	void Order::SetDate(std::string oDate)
	{
		date = oDate;
	}
	void Order::SetEmployeeID(int oEmployeeID)
	{
		employeeID = oEmployeeID;
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

	bool Order::CreateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int eID, int oCount, double oSum,
		int sID, int cID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, uID, oDate, oCount, oSum, cID, errorMessage))
			return false;
		//id = ormasDal.GenerateID();
		clientID = uID;
		date = oDate;
		employeeID = eID;
		count = oCount;
		sum = oSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.CreateOrder(id, clientID, date, employeeID, count, sum, statusID, currencyID,errorMessage))
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
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		//id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateOrder(id, clientID, date, employeeID, count, sum, statusID, currencyID, errorMessage))
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
		clientID = 0;
		date.clear();
		employeeID = 0;
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
	bool Order::UpdateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int eID, int oCount, double oSum, 
		int sID, int cID, std::string& errorMessage)
	{
		clientID = uID;
		date = oDate;
		employeeID = eID;
		count = oCount;
		sum = oSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.UpdateOrder(id, clientID, date, employeeID, count, sum, statusID, currencyID, errorMessage))
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
		if (0 != id && ormasDal.UpdateOrder(id, clientID, date, employeeID, count, sum, statusID, currencyID, errorMessage))
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
		if (0 != id || 0 != clientID || !date.empty() ||0 != employeeID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForOrder(id, clientID, date, employeeID, count, sum, statusID, currencyID);
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
			count = std::get<12>(orderVector.at(0));
			sum = std::get<13>(orderVector.at(0));
			employeeID = std::get<15>(orderVector.at(0));
			clientID = std::get<16>(orderVector.at(0));
			statusID = std::get<17>(orderVector.at(0));
			currencyID = std::get<18>(orderVector.at(0));
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
		if(0 == id && date == "" && 0 == count && 0 == sum && 0 == employeeID && 0 == clientID && 0 == statusID && 0 == currencyID)
			return false;
		return true;
	}
	
	bool Order::IsDuplicate(DataLayer::OrmasDal& ormasDal, int clID, std::string oDate, int oCount, double oSum,
		int cID, std::string& errorMessage)
	{
		Order order;
		order.SetClientID(clID);
		order.SetDate(oDate);
		order.SetCount(oCount);
		order.SetSum(oSum);
		order.SetCurrencyID(cID);
		std::string filter = order.GenerateFilter(ormasDal);
		std::vector<DataLayer::ordersViewCollection> orderVector = ormasDal.GetOrders(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == orderVector.size())
		{
			return false;
		}
		errorMessage = "Order with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Order::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Order order;
		order.SetClientID(clientID);
		order.SetDate(date);
		order.SetCount(count);
		order.SetSum(sum);
		order.SetCurrencyID(currencyID);
		std::string filter = order.GenerateFilter(ormasDal);
		std::vector<DataLayer::ordersViewCollection> orderVector = ormasDal.GetOrders(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == orderVector.size())
		{
			return false;
		}
		errorMessage = "Order with these parameters are already exist! Please avoid the duplication!";
		return true;
	}
}