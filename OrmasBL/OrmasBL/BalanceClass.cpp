#include "stdafx.h"
#include "BalanceClass.h"

namespace BusinessLayer{
	Balance::Balance(DataLayer::balancesCollection balCollection)
	{
		id = std::get<0>(balCollection);
		userID = std::get<1>(balCollection);
		value = std::get<2>(balCollection);
		currencyID = std::get<3>(balCollection);
	}
	Balance::Balance()
	{
		userID = 0;
		value = 0.0;
		currencyID = 0;
	}
	int Balance::GetID()
	{
		return id;
	}

	int Balance::GetUserID()
	{
		return userID;
	}

	double Balance::GetValue()
	{
		return value;
	}

	int Balance::GetCurrencyID()
	{
		return currencyID;
	}

	void Balance::SetID(int cID)
	{
		id = cID;
	}
	void Balance::SetUserID(int uID)
	{
		userID = uID;
	}
	void Balance::SetValue(double bValue)
	{
		value = bValue;
	}
	void Balance::SetCurrencyID(int cID)
	{
		currencyID = cID;
	}

	bool Balance::CreateBalance(DataLayer::OrmasDal &ormasDal, int uID, double bValue, int cID, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (IsDuplicate(ormasDal, uID, cID, errorMessage))
			return false;
		userID = uID;
		value = bValue;
		currencyID = cID;

		if (0 != id && ormasDal.CreateBalance(id, userID, value, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Balance::CreateBalance(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateBalance(id, userID, value, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Balance::DeleteBalance(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteBalance(id, errorMessage))
		{
			id = 0;
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}

	bool Balance::UpdateBalance(DataLayer::OrmasDal &ormasDal, int uID, double bValue, int cID, std::string& errorMessage)
	{
		userID = uID;
		value = bValue;
		currencyID = cID;
		if (0 != id && ormasDal.UpdateBalance(id, userID, value, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Balance::UpdateBalance(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateBalance(id, userID, value, currencyID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string Balance::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != userID || 0!=value || 0!=currencyID)
		{
			return ormasDal.GetFilterForBalance(id, userID, value, currencyID);
		}
		return "";
	}

	bool Balance::GetBalanceByID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage)
	{
		id = bID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::balancesViewCollection> balanceVector = ormasDal.GetBalances(errorMessage, filter);
		if (0 != balanceVector.size())
		{
			id = std::get<0>(balanceVector.at(0));
			userID = std::get<5>(balanceVector.at(0));
			value = std::get<3>(balanceVector.at(0));
			currencyID = std::get<6>(balanceVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find Balance with this id";
		}
		return false;
	}

	bool Balance::IsEmpty()
	{
		if (0 == id && 0 == userID && 0.0 == value && 0 == currencyID)
			return true;
		return false;
	}

	bool Balance::IsDuplicate(DataLayer::OrmasDal& ormasDal, int uID, int cID, std::string& errorMessage)
	{
		Balance balance;
		balance.SetUserID(uID);
		balance.SetCurrencyID(cID);
		std::string filter = balance.GenerateFilter(ormasDal);
		std::vector<DataLayer::balancesViewCollection> balanceVector = ormasDal.GetBalances(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == balanceVector.size())
		{
			return false;
		}
		errorMessage = "User already have account with this currency! Please avoid the duplication!";
		return true;
	}

	bool Balance::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Balance balance;
		balance.SetUserID(userID);
		balance.SetCurrencyID(currencyID);
		std::string filter = balance.GenerateFilter(ormasDal);
		std::vector<DataLayer::balancesViewCollection> balanceVector = ormasDal.GetBalances(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == balanceVector.size())
		{
			return false;
		}
		errorMessage = "User already have account with this currency! Please avoid the duplication!";
		return true;
	}
}