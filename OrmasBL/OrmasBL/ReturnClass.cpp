#include "stdafx.h"
#include "ReturnClass.h"

namespace BusinessLayer
{
	Return::Return(DataLayer::returnsCollection rCollection)
	{
		ID = std::get<0>(rCollection);
		userID = std::get<1>(rCollection);
		returnDate = std::get<2>(rCollection);
		workerID = std::get<3>(rCollection);
		firmName = std::get<4>(rCollection);
	}

	int Return::GetID()
	{
		return ID;
	}

	int Return::GetUserID()
	{
		return userID;
	}

	std::string Return::GetReturnDate()
	{
		return returnDate;
	}

	int Return::GetWorkerID()
	{
		return workerID;
	}

	std::string Return::GetFirmName()
	{
		return firmName;
	}
}