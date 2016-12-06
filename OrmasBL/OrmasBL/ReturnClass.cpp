#include "stdafx.h"
#include "ReturnClass.h"

namespace BusinessLayer
{
	Return::Return(DataLayer::returnsCollection rCollection)
	{
		id = std::get<0>(rCollection);
		userID = std::get<1>(rCollection);
		date = std::get<2>(rCollection);
		workerID = std::get<3>(rCollection);
	}

	int Return::GetID()
	{
		return id;
	}

	int Return::GetUserID()
	{
		return userID;
	}

	std::string Return::GetDate()
	{
		return date;
	}

	int Return::GetWorkerID()
	{
		return workerID;
	}

	void Return::SetID(int rID)
	{
		id = rID;
	}
	void Return::SetUserID(int rUserID)
	{
		userID = rUserID;
	}
	void Return::SetDate(std::string rDate)
	{
		date = rDate;
	}
	void Return::SetWorkerID(int rWorkerID)
	{
		workerID = rWorkerID;
	}
	
	bool Return::CreateReturn(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		userID = uID;
		date = oDate;
		workerID = wID;
		if (0 != id && ormasDal.CreateReturn(id, userID, date, workerID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool Return::DeleteReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		userID = 0;
		date.clear();
		workerID = 0;
		if (ormasDal.DeleteReturn(id, errorMessage))
		{
			id = 0;
			return true;
		}
		return false;
	}
	bool Return::UpdateReturn(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string& errorMessage)
	{
		userID = uID;
		date = oDate;
		workerID = wID;
		if (0 != id && ormasDal.UpdateReturn(id, userID, date, workerID, errorMessage))
		{
			return true;
		}
		return false;
	}
}