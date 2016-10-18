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
		firmName = std::get<4>(oCollection);
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

	std::string Order::GetFirmName()
	{
		return firmName;
	}

	bool Order::CreateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string fName)
	{
		id = ormasDal.GenerateID();
		userID = uID;
		date = oDate;
		workerID = wID;
		firmName = fName;
		try
		{
			if (ormasDal.CreateOrder(id, userID, date, workerID, firmName))
			{
				return true;
			}
			return false;
		}
		catch (...)
		{
			return false;
		}
	}
	bool Order::DeleteOrder(DataLayer::OrmasDal& ormasDal)
	{
		userID = 0;
		date.clear();
		workerID = 0;
		firmName.clear();
		try
		{
			if (ormasDal.DeleteOrder(id))
			{
				id = 0;
				return true;
			}
			return false;
		}
		catch (...)
		{
			return false;
		}
	}
	bool Order::UpdateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string fName)
	{
		if (0 == id)
			return false;
		userID = uID;
		date = oDate;
		workerID = wID;
		firmName = fName; 
		try
		{
			if (ormasDal.UpdateOrder(id, userID, date, workerID, firmName))
			{
				return true;
			}
			return false;
		}
		catch (...)
		{
			return false;
		}
	}
}