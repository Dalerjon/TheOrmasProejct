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
		count = std::get<4>(rCollection);
		sum = std::get<5>(rCollection);
		statusID = std::get<6>(rCollection);
		currencyID = std::get<7>(rCollection);
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

	int Return::GetCount()
	{
		return count;
	}

	double Return::GetSum()
	{
		return sum;
	}

	int Return::GetStatusID()
	{
		return statusID;
	}

	int Return::GetCurrencyID()
	{
		return currencyID;
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
	
	void Return::SetCount(int oCount)
	{
		count = oCount;
	}

	void Return::SetSum(double oSum)
	{
		sum = oSum;
	}

	void Return::SetStatusID(int rStatusID)
	{
		statusID = rStatusID;
	}

	void Return::SetCurrencyID(int rCurrencyID)
	{
		currencyID = rCurrencyID;
	}

	bool Return::CreateReturn(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, int oCount, double oSum, 
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
		if (0 != id && ormasDal.CreateReturn(id, userID, date, workerID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Return::CreateReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		//id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateReturn(id, userID, date, workerID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Return::DeleteReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		userID = 0;
		date.clear();
		workerID = 0;
		count = 0;
		sum = 0;
		if (ormasDal.DeleteReturn(id, errorMessage))
		{
			id = 0;
			return true;
		}
		return false;
	}
	bool Return::UpdateReturn(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, int oCount, double oSum, 
		int sID, int cID, std::string& errorMessage)
	{
		userID = uID;
		date = oDate;
		workerID = wID;
		count = oCount;
		sum = oSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.UpdateReturn(id, userID, date, workerID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Return::UpdateReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateReturn(id, userID, date, workerID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string Return::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != userID || !date.empty() || 0 != workerID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForReturn(id, userID, date, workerID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool Return::GetRetrunByID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage)
	{
		id = rID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::returnsViewCollection> returnVector = ormasDal.GetReturns(errorMessage, filter);
		if (0 != returnVector.size())
		{
			id = std::get<0>(returnVector.at(0));
			date = std::get<1>(returnVector.at(0));
			count = std::get<10>(returnVector.at(0));
			sum = std::get<11>(returnVector.at(0));
			workerID = std::get<13>(returnVector.at(0));
			userID = std::get<14>(returnVector.at(0));
			statusID = std::get<15>(returnVector.at(0));
			currencyID = std::get<16>(returnVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find return with this id";
		}
		return false;
	}
	bool Return::IsEmpty()
	{
		if(0 == id && date == "" && 0 == count && 0 == sum && 0 == workerID && 0 == userID && 0 == statusID && 0 == currencyID)
			return true;
		return false;
	}
}