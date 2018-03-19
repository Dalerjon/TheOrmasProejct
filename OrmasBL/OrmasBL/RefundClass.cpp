#include "stdafx.h"
#include "RefundClass.h"
#include "UserClass.h"
#include "BalanceClass.h"
#include "BalanceRefundRelationClass.h"

namespace BusinessLayer{
	Refund::Refund(DataLayer::refundsCollection rCollection)
	{
		id = std::get<0>(rCollection);
		date = std::get<1>(rCollection);
		value = std::get<2>(rCollection);
		userID = std::get<3>(rCollection);
		currencyID = std::get<4>(rCollection);
	}
	Refund::Refund()
	{
		date = "";
		value = 0.0;
		userID = 0;
		currencyID = 0;
	}
	int Refund::GetID()
	{
		return id;
	}

	std::string Refund::GetDate()
	{
		return date;
	}

	double Refund::GetValue()
	{
		return value;
	}

	int Refund::GetUserID()
	{
		return userID;
	}

	int Refund::GetCurrencyID()
	{
		return currencyID;
	}

	void Refund::SetID(int pID)
	{
		id = pID;
	}

	void Refund::SetDate(std::string pDate)
	{
		date = pDate;
	}

	void Refund::SetValue(double pValue)
	{
		value = pValue;
	}

	void Refund::SetUserID(int uID)
	{
		userID = uID;
	}
	void Refund::SetCurrencyID(int cID)
	{
		currencyID = cID;
	}

	bool Refund::CreateRefund(DataLayer::OrmasDal &ormasDal, std::string pDate, double pValue, int uID, int cID,
		std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, pDate, pValue, uID, cID, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		date = pDate;
		value = pValue;
		userID = uID;
		currencyID = cID;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateRefund(id, date, value, userID, currencyID, errorMessage))
		{
			if (Replenishment(ormasDal, userID, currencyID, errorMessage))
			{
				ormasDal.CommitTransaction(errorMessage);
				return true;
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Refund::CreateRefund(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateRefund(id, date, value, userID, currencyID, errorMessage))
		{
			if (Replenishment(ormasDal, userID, currencyID, errorMessage))
			{
				ormasDal.CommitTransaction(errorMessage);
				return true;
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Refund::DeleteRefund(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!this->GetRefundByID(ormasDal, id, errorMessage))
			return false;
		ormasDal.StartTransaction(errorMessage);
		if (ormasDal.DeleteRefund(id, errorMessage))
		{
			if (CancelRefund(ormasDal, userID, currencyID, errorMessage))
			{
				ormasDal.CommitTransaction(errorMessage);
				Clear();
				return true;
			}	
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	bool Refund::UpdateRefund(DataLayer::OrmasDal &ormasDal, std::string pDate, double pValue, int uID, int cID,
		std::string& errorMessage)
	{
		date = pDate;
		value = pValue;
		userID = uID;
		currencyID = cID;
		currentValue = GetCurrentValue(ormasDal, id, errorMessage);
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateRefund(id, date, value, userID, currencyID, errorMessage))
		{
			if (Replenishment(ormasDal, userID, currencyID, currentValue, errorMessage))
			{
				ormasDal.CommitTransaction(errorMessage);
				currentValue = 0.0;
				return true;
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Refund::UpdateRefund(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		currentValue = GetCurrentValue(ormasDal, id, errorMessage);
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateRefund(id, date, value, userID, currencyID, errorMessage))
		{
			if (Replenishment(ormasDal, userID, currencyID, currentValue, errorMessage))
			{
				ormasDal.CommitTransaction(errorMessage);
				currentValue = 0.0;
				return true;
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	std::string Refund::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || date.empty() || 0 != userID || 0 != currencyID || 0 != value)
		{
			return ormasDal.GetFilterForRefund(id, date, value, userID, currencyID);
		}
		return "";
	}

	bool Refund::GetRefundByID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage)
	{
		id = bID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::refundsViewCollection> refundVector = ormasDal.GetRefunds(errorMessage, filter);
		if (0 != refundVector.size())
		{
			id = std::get<0>(refundVector.at(0));
			date = std::get<1>(refundVector.at(0));
			value = std::get<2>(refundVector.at(0));
			userID = std::get<4>(refundVector.at(0));
			currencyID = std::get<5>(refundVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find Refund with this id";
		}
		return false;
	}

	bool Refund::IsEmpty()
	{
		if (0 == id && date.empty() && 0.0 == value && 0 == userID && 0 == currencyID)
			return true;
		return false;
	}

	void Refund::Clear()
	{
		id = 0;
		date.clear();
		value = 0;
		userID = 0;
		currencyID = 0;
	}

	bool Refund::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string pDate, double pValue, int uID, int cID,
		std::string& errorMessage)
	{
		Refund refund;
		refund.SetDate(pDate);
		refund.SetValue(pValue);
		refund.SetUserID(uID);
		refund.SetCurrencyID(cID);
		std::string filter = refund.GenerateFilter(ormasDal);
		std::vector<DataLayer::refundsViewCollection> refundVector = ormasDal.GetRefunds(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == refundVector.size())
		{
			return false;
		}
		errorMessage = "Refund with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Refund::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Refund refund;
		refund.SetDate(date);
		refund.SetValue(value);
		refund.SetUserID(userID);
		refund.SetCurrencyID(currencyID);
		std::string filter = refund.GenerateFilter(ormasDal);
		std::vector<DataLayer::refundsViewCollection> refundVector = ormasDal.GetRefunds(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == refundVector.size())
		{
			return false;
		}
		errorMessage = "Refund with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Refund::Replenishment(DataLayer::OrmasDal& ormasDal, int uID, int cID, std::string& errorMessage)
	{
		User user;
		user.SetID(uID);
		int balanceID = user.GetUserAccoutID(ormasDal, cID, errorMessage);
		if (0 != balanceID && errorMessage.empty())
		{
			BalanceRefundRelation brRelation;
			Balance balance;
			if (balance.GetBalanceByID(ormasDal, balanceID, errorMessage))
			{
				brRelation.SetBalanceID(balanceID);
				brRelation.SetRefundID(id);
				//balance.SetValue(balance.GetValue() + value);
				if (balance.UpdateBalance(ormasDal, errorMessage) && brRelation.CreateBalanceRefundRelation(ormasDal, errorMessage))
					return true;
			}
		}
		return false;
	}

	bool Refund::Replenishment(DataLayer::OrmasDal& ormasDal, int uID, int cID, double currentValue, std::string& errorMessage)
	{
		User user;
		user.SetID(uID);
		int balanceID = user.GetUserAccoutID(ormasDal, cID, errorMessage);
		if (0 != balanceID && errorMessage.empty())
		{
			Balance balance;
			if (balance.GetBalanceByID(ormasDal, balanceID, errorMessage))
			{
				//balance.SetValue(balance.GetValue() + (currentValue - value));
				if(balance.UpdateBalance(ormasDal, errorMessage))
					return true;
			}
		}
		return false;
	}

	double Refund::GetCurrentValue(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		Refund Refund;
		if (Refund.GetRefundByID(ormasDal, pID, errorMessage))
			return Refund.GetValue();
		return 0;
	}

	bool Refund::CancelRefund(DataLayer::OrmasDal& ormasDal, int uID, int cID, std::string& errorMessage)
	{
		User user;
		user.SetID(uID);
		int balanceID = user.GetUserAccoutID(ormasDal, cID, errorMessage);
		if (0 != balanceID && errorMessage.empty())
		{
			BalanceRefundRelation brRelation;
			Balance balance;
			if (balance.GetBalanceByID(ormasDal, balanceID, errorMessage))
			{
				brRelation.SetBalanceID(balanceID);
				brRelation.SetRefundID(id);
				//.SetValue(balance.GetValue() - value);
				if (balance.UpdateBalance(ormasDal, errorMessage) && brRelation.DeleteBalanceRefundRelation(ormasDal, errorMessage))
					return true;
			}
		}
		return false;
	}

}