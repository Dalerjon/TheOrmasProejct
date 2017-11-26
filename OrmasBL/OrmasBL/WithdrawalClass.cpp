#include "stdafx.h"
#include "WithdrawalClass.h"
#include "UserClass.h"
#include "BalanceClass.h"

namespace BusinessLayer{
	Withdrawal::Withdrawal(DataLayer::withdrawalsCollection wCollection)
	{
		id = std::get<0>(wCollection);
		date = std::get<1>(wCollection);
		value = std::get<2>(wCollection);
		userID = std::get<3>(wCollection);
		currencyID = std::get<4>(wCollection);
	}
	Withdrawal::Withdrawal()
	{
		date = "";
		value = 0.0;
		userID = 0;
		currencyID = 0;
	}
	int Withdrawal::GetID()
	{
		return id;
	}

	std::string Withdrawal::GetDate()
	{
		return date;
	}

	double Withdrawal::GetValue()
	{
		return value;
	}

	int Withdrawal::GetUserID()
	{
		return userID;
	}

	int Withdrawal::GetCurrencyID()
	{
		return currencyID;
	}

	void Withdrawal::SetID(int wID)
	{
		id = wID;
	}

	void Withdrawal::SetDate(std::string wDate)
	{
		date = wDate;
	}

	void Withdrawal::SetValue(double wValue)
	{
		value = wValue;
	}

	void Withdrawal::SetUserID(int uID)
	{
		userID = uID;
	}
	void Withdrawal::SetCurrencyID(int cID)
	{
		currencyID = cID;
	}

	bool Withdrawal::CreateWithdrawal(DataLayer::OrmasDal &ormasDal, std::string wDate, double wValue, int uID, int cID,
		std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, wDate, wValue, uID, cID, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		date = wDate;
		value = wValue;
		userID = uID;
		currencyID = cID;

		if (0 != id && ormasDal.CreateWithdrawal(id, date, value, userID, currencyID, errorMessage))
		{
			if (Credit(ormasDal, userID, currencyID, errorMessage))
				return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Withdrawal::CreateWithdrawal(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateWithdrawal(id, date, value, userID, currencyID, errorMessage))
		{
			if (Credit(ormasDal, userID, currencyID, errorMessage))
				return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Withdrawal::DeleteWithdrawal(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!this->GetWithdrawalByID(ormasDal, id, errorMessage))
			return false;
		if (ormasDal.DeleteWithdrawal(id, errorMessage))
		{
			if (CancelCredit(ormasDal, userID, currencyID, errorMessage))
			{
				Clear();
				return true;
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}

	bool Withdrawal::UpdateWithdrawal(DataLayer::OrmasDal &ormasDal, std::string wDate, double wValue, int uID, int cID,
		std::string& errorMessage)
	{
		date = wDate;
		value = wValue;
		userID = uID;
		currencyID = cID;
		currentValue = GetCurrentValue(ormasDal, id, errorMessage);
		if (0 != id && ormasDal.UpdateWithdrawal(id, date, value, userID, currencyID, errorMessage))
		{
			if (Credit(ormasDal, userID, currencyID, currentValue, errorMessage))
			{
				currentValue = 0.0;
				return true;
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Withdrawal::UpdateWithdrawal(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		currentValue = GetCurrentValue(ormasDal, id, errorMessage);
		if (0 != id && ormasDal.UpdateWithdrawal(id, date, value, userID, currencyID, errorMessage))
		{
			if (Credit(ormasDal, userID, currencyID, currentValue, errorMessage))
			{
				currentValue = 0.0;
				return true;
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string Withdrawal::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || date.empty() || 0 != userID || 0 != currencyID || 0 != value)
		{
			return ormasDal.GetFilterForWithdrawal(id, date, value, userID, currencyID);
		}
		return "";
	}

	bool Withdrawal::GetWithdrawalByID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage)
	{
		id = bID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::withdrawalsViewCollection> withdrawalVector = ormasDal.GetWithdrawals(errorMessage, filter);
		if (0 != withdrawalVector.size())
		{
			id = std::get<0>(withdrawalVector.at(0));
			date = std::get<1>(withdrawalVector.at(0));
			value = std::get<2>(withdrawalVector.at(0));
			userID = std::get<4>(withdrawalVector.at(0));
			currencyID = std::get<5>(withdrawalVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find Withdrawal with this id";
		}
		return false;
	}

	bool Withdrawal::IsEmpty()
	{
		if (0 == id && date.empty() && 0.0 == value && 0 == userID && 0 == currencyID)
			return true;
		return false;
	}

	void Withdrawal::Clear()
	{
		id = 0;
		date.clear();
		value = 0;
		userID = 0;
		currencyID = 0;
	}

	bool Withdrawal::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string pDate, double pValue, int uID, int cID,
		std::string& errorMessage)
	{
		Withdrawal withdrawal;
		withdrawal.SetDate(pDate);
		withdrawal.SetValue(pValue);
		withdrawal.SetUserID(uID);
		withdrawal.SetCurrencyID(cID);
		std::string filter = withdrawal.GenerateFilter(ormasDal);
		std::vector<DataLayer::withdrawalsViewCollection> withdrawalVector = ormasDal.GetWithdrawals(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == withdrawalVector.size())
		{
			return false;
		}
		errorMessage = "Withdrawal with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Withdrawal::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Withdrawal withdrawal;
		withdrawal.SetDate(date);
		withdrawal.SetValue(value);
		withdrawal.SetUserID(userID);
		withdrawal.SetCurrencyID(currencyID);
		std::string filter = withdrawal.GenerateFilter(ormasDal);
		std::vector<DataLayer::withdrawalsViewCollection> withdrawalVector = ormasDal.GetWithdrawals(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == withdrawalVector.size())
		{
			return false;
		}
		errorMessage = "Withdrawal with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Withdrawal::Credit(DataLayer::OrmasDal& ormasDal, int uID, int cID, std::string& errorMessage)
	{
		User user;
		user.SetID(uID);
		int balanceID = user.GetUserAccoutID(ormasDal, cID, errorMessage);
		if (0 != balanceID && errorMessage.empty())
		{
			Balance balance;
			balance.GetBalanceByID(ormasDal, balanceID, errorMessage);
			if (errorMessage.empty())
			{
				balance.SetValue(balance.GetValue() - value);
				balance.UpdateBalance(ormasDal, errorMessage);
				return true;
			}
		}
		return false;
	}

	bool Withdrawal::Credit(DataLayer::OrmasDal& ormasDal, int uID, int cID, double currentValue, std::string& errorMessage)
	{
		User user;
		user.SetID(uID);
		int balanceID = user.GetUserAccoutID(ormasDal, cID, errorMessage);
		if (0 != balanceID && errorMessage.empty())
		{
			Balance balance;
			balance.GetBalanceByID(ormasDal, balanceID, errorMessage);
			if (errorMessage.empty())
			{
				balance.SetValue(balance.GetValue() - (value - currentValue));
				balance.UpdateBalance(ormasDal, errorMessage);
				return true;
			}
		}
		return false;
	}

	double Withdrawal::GetCurrentValue(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		Withdrawal withdrawal;
		withdrawal.GetWithdrawalByID(ormasDal, pID, errorMessage);
		if (errorMessage.empty())
			return withdrawal.GetValue();
		return 0;
	}

	bool Withdrawal::CancelCredit(DataLayer::OrmasDal& ormasDal, int uID, int cID, std::string& errorMessage)
	{
		User user;
		user.SetID(uID);
		int balanceID = user.GetUserAccoutID(ormasDal, cID, errorMessage);
		if (0 != balanceID && errorMessage.empty())
		{
			Balance balance;
			balance.GetBalanceByID(ormasDal, balanceID, errorMessage);
			if (errorMessage.empty())
			{
				balance.SetValue(balance.GetValue() + value);
				balance.UpdateBalance(ormasDal, errorMessage);
				return true;
			}
		}
		return false;
	}
}