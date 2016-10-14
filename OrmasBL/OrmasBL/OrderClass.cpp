#include "stdafx.h"
#include "OrderClass.h"

namespace BusinessLayer
{
	Order::Order(DataLayer::ordersCollection oCollection)
	{
		ID = std::get<0>(oCollection);
		userID = std::get<1>(oCollection);
		date = std::get<2>(oCollection);
		workerID = std::get<3>(oCollection);
		firmName = std::get<4>(oCollection);
	}

	int Order::GetID()
	{
		return ID;
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
}