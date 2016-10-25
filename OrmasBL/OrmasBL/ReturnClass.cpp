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
		firmName = std::get<4>(rCollection);
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

	std::string Return::GetFirmName()
	{
		return firmName;
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
	void Return::SetFirmName(std::string rFirmName)
	{
		firmName = rFirmName;
	}

	bool Return::CreateReturn(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string fName)
	{
		id = ormasDal.GenerateID();
		userID = uID;
		date = oDate;
		workerID = wID;
		firmName = fName;
		try
		{
			if (ormasDal.CreateReturn(id, userID, date, workerID, firmName))
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
	bool Return::DeleteReturn(DataLayer::OrmasDal& ormasDal)
	{
		userID = 0;
		date.clear();
		workerID = 0;
		firmName.clear();
		try
		{
			if (ormasDal.DeleteReturn(id))
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
	bool Return::UpdateReturn(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string fName)
	{
		if (0 == id)
			return false;
		userID = uID;
		date = oDate;
		workerID = wID;
		firmName = fName;
		try
		{
			if (ormasDal.UpdateReturn(id, userID, date, workerID, firmName))
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