#include "stdafx.h"
#include "WithdrawalClass.h"
#include "UserClass.h"
#include "BalanceClass.h"
#include "BalanceWithdrawalRelationClass.h"
#include "EntryClass.h"
#include "CashboxEmployeeRelationClass.h"
#include "CashboxClass.h"
#include "StatusClass.h"
#include <codecvt>

namespace BusinessLayer{
	Withdrawal::Withdrawal(DataLayer::withdrawalsCollection wCollection)
	{
		id = std::get<0>(wCollection);
		date = std::get<1>(wCollection);
		value = std::get<2>(wCollection);
		userID = std::get<3>(wCollection);
		subaccountID = std::get<4>(wCollection);
		target = std::get<5>(wCollection);
		currencyID = std::get<6>(wCollection);
	}
	Withdrawal::Withdrawal()
	{
		date = "";
		target = "";
		value = 0.0;
		userID = 0;
		currencyID = 0;
		subaccountID = 0;
	}
	int Withdrawal::GetID()
	{
		return id;
	}

	std::string Withdrawal::GetDate()
	{
		return date;
	}

	std::string Withdrawal::GetTarget()
	{
		return target;
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

	int Withdrawal::GetSubaccountID()
	{
		return subaccountID;
	}

	void Withdrawal::SetID(int wID)
	{
		id = wID;
	}

	void Withdrawal::SetDate(std::string wDate)
	{
		date = wDate;
	}

	void Withdrawal::SetTarget(std::string wTarget)
	{
		target = wTarget;
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
	void Withdrawal::SetSubaccountID(int sID)
	{
		subaccountID = sID;
	}

	bool Withdrawal::CreateWithdrawal(DataLayer::OrmasDal &ormasDal, std::string wDate, double wValue, int uID, int sID, std::string wTaeget,
		int cID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, wDate, wValue, uID, cID, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		date = wDate;
		value = wValue;
		userID = uID;
		currencyID = cID;
		target = wTaeget;
		subaccountID = sID;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateWithdrawal(id, date, value, userID,subaccountID,target, currencyID, errorMessage))
		{
			if (0 == subaccountID)
			{
				if (Payout(ormasDal, userID, currencyID, errorMessage))
				{
					//ormasDal.CommitTransaction(errorMessage);
					return true;
				}
			}
			else
			{
				if (Payout(ormasDal, subaccountID, errorMessage))
				{
					//ormasDal.CommitTransaction(errorMessage);
					return true;
				}
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Withdrawal::CreateWithdrawal(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateWithdrawal(id, date, value, userID, subaccountID, target, currencyID, errorMessage))
		{
			if (0 == subaccountID)
			{
				if (Payout(ormasDal, userID, currencyID, errorMessage))
				{
					//ormasDal.CommitTransaction(errorMessage);
					return true;
				}
			}
			else
			{
				if (Payout(ormasDal, subaccountID, errorMessage))
				{
					//ormasDal.CommitTransaction(errorMessage);
					return true;
				}
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Withdrawal::DeleteWithdrawal(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!this->GetWithdrawalByID(ormasDal, id, errorMessage))
			return false;
		if (ormasDal.DeleteWithdrawal(id, errorMessage))
		{
			if (0 < userID)
			{

				if (CancelWithdrawal(ormasDal, userID, currencyID, errorMessage))
				{
					Clear();
					return true;
				}
			}
			else
			{
				if (CancelWithdrawal(ormasDal, subaccountID, errorMessage))
				{
					Clear();
					return true;
				}
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}

	bool Withdrawal::UpdateWithdrawal(DataLayer::OrmasDal &ormasDal, std::string wDate, double wValue, int uID, int sID, std::string wTaeget,
		int cID, std::string& errorMessage)
	{
		date = wDate;
		value = wValue;
		userID = uID;
		currencyID = cID;
		target = wTaeget;
		subaccountID = sID;
		currentValue = GetCurrentValue(ormasDal, id, errorMessage);
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateWithdrawal(id, date, value, userID, subaccountID, target, currencyID, errorMessage))
		{
			if (0 < userID)
			{
				if (Payout(ormasDal, userID, currencyID, currentValue, errorMessage))
				{
					//ormasDal.CommitTransaction(errorMessage);
					currentValue = 0.0;
					return true;
				}
			}
			else
			{
				if (Payout(ormasDal, subaccountID, currentValue, errorMessage))
				{
					//ormasDal.CommitTransaction(errorMessage);
					currentValue = 0.0;
					return true;
				}
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Withdrawal::UpdateWithdrawal(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		currentValue = GetCurrentValue(ormasDal, id, errorMessage);
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateWithdrawal(id, date, value, userID, subaccountID, target, currencyID, errorMessage))
		{
			if (0 < userID)
			{
				if (Payout(ormasDal, userID, currencyID, currentValue, errorMessage))
				{
					//ormasDal.CommitTransaction(errorMessage);
					currentValue = 0.0;
					return true;
				}
			}
			else
			{
				if (Payout(ormasDal, subaccountID, currentValue, errorMessage))
				{
					//ormasDal.CommitTransaction(errorMessage);
					currentValue = 0.0;
					return true;
				}
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	std::string Withdrawal::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !date.empty() || !target.empty() || 0 != userID || 0 != subaccountID || 0 != currencyID || 0 != value)
		{
			return ormasDal.GetFilterForWithdrawal(id, date, value, userID, subaccountID, target, currencyID);
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
			userID = std::get<8>(withdrawalVector.at(0));
			subaccountID = std::get<10>(withdrawalVector.at(0));
			target = std::get<6>(withdrawalVector.at(0));
			currencyID = std::get<9>(withdrawalVector.at(0));
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
		if (0 == id && date.empty() && 0.0 == value && 0 == userID && 0 == currencyID && 0== subaccountID && target.empty())
			return true;
		return false;
	}

	void Withdrawal::Clear()
	{
		id = 0;
		date.clear();
		target.clear();
		value = 0;
		userID = 0;
		currencyID = 0;
		subaccountID = 0;
	}

	bool Withdrawal::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string pDate, double pValue, int uID, int cID,
		std::string& errorMessage)
	{
		Withdrawal withdrawal;
		withdrawal.Clear();
		errorMessage.clear();
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
		withdrawal.Clear();
		errorMessage.clear();
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

	bool Withdrawal::Payout(DataLayer::OrmasDal& ormasDal, int uID, int cID, std::string& errorMessage)
	{
		CashboxEmployeeRelation cashEmpRel;
		if (!cashEmpRel.GetCashboxByEmployeeID(ormasDal, loggedUserID, errorMessage))
		{
			errorMessage = "Access denied! You haven't rights for doing operations with cashbox!";
			return false;
		}

		Balance balance;
		Cashbox cashbox;
		if (!cashbox.GetCashboxByID(ormasDal, cashEmpRel.GetCashboxID(), errorMessage))
		{
			errorMessage = "Access denied! You haven't rights for doing operations with cashbox!";
			return false;
		}
		if (balance.GetBalanceByUserID(ormasDal, uID, errorMessage))
		{
			int debAccID = balance.GetSubaccountID();
			int credAccID = cashbox.GetSubaccountID();
			if (0 == debAccID || 0 == credAccID)
			{
				return false;
			}
			if (this->CreateEntry(ormasDal, debAccID, value, credAccID, ormasDal.GetSystemDateTime(), errorMessage))
			{
				BalanceWithdrawalRelation bwRelation;
				bwRelation.SetBalanceID(balance.GetID());
				bwRelation.SetWithdrawalID(this->id);
				if (bwRelation.CreateBalanceWithdrawalRelation(ormasDal, errorMessage))
					return true;
			}
		}
		return false;
	}

	bool Withdrawal::Payout(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage)
	{
		CashboxEmployeeRelation cashEmpRel;
		if (!cashEmpRel.GetCashboxByEmployeeID(ormasDal, loggedUserID, errorMessage))
		{
			errorMessage = "Access denied! You haven't rights for doing operations with cashbox!";
			return false;
		}

		Cashbox cashbox;
		if (!cashbox.GetCashboxByID(ormasDal, cashEmpRel.GetCashboxID(), errorMessage))
		{
			errorMessage = "Access denied! You haven't rights for doing operations with cashbox!";
			return false;
		}
		
		int debAccID = sID;
		int credAccID = cashbox.GetSubaccountID();
		if (0 == debAccID || 0 == credAccID)
		{
			return false;
		}
		if (this->CreateEntry(ormasDal, debAccID, value, credAccID, ormasDal.GetSystemDateTime(), errorMessage))
		{
			return true;
		}
		return false;
	}

	bool Withdrawal::Payout(DataLayer::OrmasDal& ormasDal, int uID, int cID, double previousValue, std::string& errorMessage)
	{
		CashboxEmployeeRelation cashEmpRel;
		if (!cashEmpRel.GetCashboxByEmployeeID(ormasDal, loggedUserID, errorMessage))
		{
			errorMessage = "Access denied! You haven't rights for doing operations with cashbox!";
			return false;
		}

		Balance balance;
		Cashbox cashbox;
		if (!cashbox.GetCashboxByID(ormasDal, cashEmpRel.GetCashboxID(), errorMessage))
		{
			errorMessage = "Access denied! You haven't rights for doing operations with cashbox!";
			return false;
		}
		if (balance.GetBalanceByUserID(ormasDal, uID, errorMessage))
		{
			int debAccID = balance.GetSubaccountID();
			int credAccID = cashbox.GetSubaccountID();
			if (0 == debAccID || 0 == credAccID)
			{
				return false;
			}
			if (this->CreateEntry(ormasDal, debAccID, value, credAccID, previousValue, ormasDal.GetSystemDateTime(), errorMessage))
			{
				return true;
			}
		}
		return false;
	}

	bool Withdrawal::Payout(DataLayer::OrmasDal& ormasDal, int sID, double previousValue, std::string& errorMessage)
	{
		CashboxEmployeeRelation cashEmpRel;
		if (!cashEmpRel.GetCashboxByEmployeeID(ormasDal, loggedUserID, errorMessage))
		{
			errorMessage = "Access denied! You haven't rights for doing operations with cashbox!";
			return false;
		}

		Cashbox cashbox;
		if (!cashbox.GetCashboxByID(ormasDal, cashEmpRel.GetCashboxID(), errorMessage))
		{
			errorMessage = "Access denied! You haven't rights for doing operations with cashbox!";
			return false;
		}
		
		int debAccID = sID;
		int credAccID = cashbox.GetSubaccountID();
		if (0 == debAccID || 0 == credAccID)
		{
			return false;
		}
		if (this->CreateEntry(ormasDal, debAccID, value, credAccID, previousValue, ormasDal.GetSystemDateTime(), errorMessage))
		{
			return true;
		}
		return false;
	}

	double Withdrawal::GetCurrentValue(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		Withdrawal payslip;
		if (payslip.GetWithdrawalByID(ormasDal, pID, errorMessage))
			return payslip.GetValue();
		return 0;
	}

	bool Withdrawal::CancelWithdrawal(DataLayer::OrmasDal& ormasDal, int uID, int cID, std::string& errorMessage)
	{
		CashboxEmployeeRelation cashEmpRel;
		if (!cashEmpRel.GetCashboxByEmployeeID(ormasDal, loggedUserID, errorMessage))
		{
			errorMessage = "Access denied! You haven't rights for doing operations with cashbox!";
			return false;
		}

		Balance balance;
		Cashbox cashbox;
		if (!cashbox.GetCashboxByID(ormasDal, cashEmpRel.GetCashboxID(), errorMessage))
		{
			errorMessage = "Access denied! You haven't rights for doing operations with cashbox!";
			return false;
		}
		if (balance.GetBalanceByUserID(ormasDal, uID, errorMessage))
		{
			int credAccID = balance.GetSubaccountID();
			int debAccID = cashbox.GetSubaccountID();
			if (0 == debAccID || 0 == credAccID)
			{
				return false;
			}
			if (this->CorrectingEntry(ormasDal, credAccID, value, debAccID, ormasDal.GetSystemDateTime(), errorMessage))
			{
				BalanceWithdrawalRelation bwRelation;
				bwRelation.SetBalanceID(balance.GetID());
				bwRelation.SetWithdrawalID(this->id);
				if (bwRelation.DeleteBalanceWithdrawalRelation(ormasDal, errorMessage))
					return true;
			}
		}
		return false;
	}

	bool Withdrawal::CancelWithdrawal(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage)
	{
		CashboxEmployeeRelation cashEmpRel;
		if (!cashEmpRel.GetCashboxByEmployeeID(ormasDal, loggedUserID, errorMessage))
		{
			errorMessage = "Access denied! You haven't rights for doing operations with cashbox!";
			return false;
		}

		Cashbox cashbox;
		if (!cashbox.GetCashboxByID(ormasDal, cashEmpRel.GetCashboxID(), errorMessage))
		{
			errorMessage = "Access denied! You haven't rights for doing operations with cashbox!";
			return false;
		}
		
		int credAccID = sID;
		int debAccID = cashbox.GetSubaccountID();
		if (0 == debAccID || 0 == credAccID)
		{
			return false;
		}
		if (this->CorrectingEntry(ormasDal, credAccID, value, debAccID, ormasDal.GetSystemDateTime(), errorMessage))
		{
				return true;
		}
		return false;
	}

	bool Withdrawal::CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		entry.SetDescription(wstring_to_utf8(L"Операция снятие суммы со счета"));
		if (!entry.CreateEntry(ormasDal, errorMessage))
		{
			return false;
		}
		return true;
	}
	bool Withdrawal::CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, double previousSum, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(credAccID);
		entry.SetValue(previousSum);
		entry.SetCreditingAccountID(debAccID);
		entry.SetDescription(wstring_to_utf8(L"Операция снятие суммы со счета"));
		if (!entry.CreateEntry(ormasDal, errorMessage))
		{
			return false;
		}
		entry.Clear();
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		entry.SetDescription(wstring_to_utf8(L"Операция снятие суммы со счета"));
		if (!entry.CreateEntry(ormasDal, errorMessage))
		{
			return false;
		}
		return true;
	}
	bool Withdrawal::CorrectingEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(credAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(debAccID);
		entry.SetDescription(wstring_to_utf8(L"Отмена снятие суммы со счета"));
		if (!entry.CreateEntry(ormasDal, errorMessage))
		{
			return false;
		}
		return true;
	}
	
	std::string Withdrawal::wstring_to_utf8(const std::wstring& str)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
		return myconv.to_bytes(str);
	}
}