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

	bool Order::CreateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		userID = uID;
		date = oDate;
		workerID = wID;
		if (0 != id && ormasDal.CreateOrder(id, userID, date, workerID, errorMessage))
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
	bool Order::UpdateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string& errorMessage)
	{
		userID = uID;
		date = oDate;
		workerID = wID;
		if (0 != id && ormasDal.UpdateOrder(id, userID, date, workerID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
}