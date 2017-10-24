#include "stdafx.h"
#include "ReturnClass.h"

namespace BusinessLayer
{
	Return::Return(DataLayer::returnsCollection rCollection)
	{
		id = std::get<0>(rCollection);
		clientID = std::get<1>(rCollection);
		date = std::get<2>(rCollection);
		employeeID = std::get<3>(rCollection);
		count = std::get<4>(rCollection);
		sum = std::get<5>(rCollection);
		statusID = std::get<6>(rCollection);
		currencyID = std::get<7>(rCollection);
	}

	int Return::GetID()
	{
		return id;
	}

	int Return::GetClientID()
	{
		return clientID;
	}

	std::string Return::GetDate()
	{
		return date;
	}

	int Return::GetEmployeeID()
	{
		return employeeID;
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
	void Return::SetClientID(int rClientID)
	{
		clientID = rClientID;
	}
	void Return::SetDate(std::string rDate)
	{
		date = rDate;
	}
	void Return::SetEmployeeID(int rEmployeeID)
	{
		employeeID = rEmployeeID;
	}
	
	void Return::SetCount(int rCount)
	{
		count = rCount;
	}

	void Return::SetSum(double rSum)
	{
		sum = rSum;
	}

	void Return::SetStatusID(int rStatusID)
	{
		statusID = rStatusID;
	}

	void Return::SetCurrencyID(int rCurrencyID)
	{
		currencyID = rCurrencyID;
	}

	bool Return::CreateReturn(DataLayer::OrmasDal& ormasDal, int clID, std::string rDate, int eID, int rCount, double rSum, 
		int sID, int cID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, clID, rDate, rCount, rSum, cID, errorMessage))
			return false;
		//id = ormasDal.GenerateID();
		clientID = clID;
		date = rDate;
		employeeID = eID;
		count = rCount;
		sum = rSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.CreateReturn(id, clientID, date, employeeID, count, sum, statusID, currencyID, errorMessage))
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
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		//id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateReturn(id, clientID, date, employeeID, count, sum, statusID, currencyID, errorMessage))
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
		clientID = 0;
		date.clear();
		employeeID = 0;
		count = 0;
		sum = 0;
		if (ormasDal.DeleteReturn(id, errorMessage))
		{
			id = 0;
			return true;
		}
		return false;
	}
	bool Return::UpdateReturn(DataLayer::OrmasDal& ormasDal, int clID, std::string rDate, int eID, int rCount, double rSum, 
		int sID, int cID, std::string& errorMessage)
	{
		clientID = clID;
		date = rDate;
		employeeID = eID;
		count = rCount;
		sum = rSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.UpdateReturn(id, clientID, date, employeeID, count, sum, statusID, currencyID, errorMessage))
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
		if (0 != id && ormasDal.UpdateReturn(id, clientID, date, employeeID, count, sum, statusID, currencyID, errorMessage))
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
		if (0 != id || 0 != clientID || !date.empty() || 0 != employeeID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForReturn(id, clientID, date, employeeID, count, sum, statusID, currencyID);
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
			count = std::get<12>(returnVector.at(0));
			sum = std::get<13>(returnVector.at(0));
			employeeID = std::get<15>(returnVector.at(0));
			clientID = std::get<16>(returnVector.at(0));
			statusID = std::get<17>(returnVector.at(0));
			currencyID = std::get<18>(returnVector.at(0));
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
		if(0 == id && date == "" && 0 == count && 0 == sum && 0 == employeeID && 0 == clientID && 0 == statusID && 0 == currencyID)
			return true;
		return false;
	}

	bool Return::IsDuplicate(DataLayer::OrmasDal& ormasDal, int clID, std::string rDate, int rCount, double rSum,
		int cID, std::string& errorMessage)
	{
		Return ret;
		ret.SetClientID(clID);
		ret.SetDate(rDate);
		ret.SetCount(rCount);
		ret.SetSum(rSum);
		ret.SetCurrencyID(cID);
		std::string filter = ret.GenerateFilter(ormasDal);
		std::vector<DataLayer::returnsViewCollection> returnVector = ormasDal.GetReturns(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == returnVector.size())
		{
			return false;
		}
		errorMessage = "Return with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Return::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Return ret;
		ret.SetClientID(clientID);
		ret.SetDate(date);
		ret.SetCount(count);
		ret.SetSum(sum);
		ret.SetCurrencyID(currencyID);
		std::string filter = ret.GenerateFilter(ormasDal);
		std::vector<DataLayer::returnsViewCollection> returnVector = ormasDal.GetReturns(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == returnVector.size())
		{
			return false;
		}
		errorMessage = "Return with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}