#include "stdafx.h"
#include "PaymentClass.h"
#include "UserClass.h"
#include "BalanceClass.h"
#include "BalancePaymentRelationClass.h"
#include "EntryClass.h"
#include "CompanyAccountRelationClass.h"
#include "CompanyEmployeeRelationClass.h"
#include "CompanyClass.h"
#include "StatusClass.h"

namespace BusinessLayer{
	Payment::Payment(DataLayer::paymentsCollection pCollection)
	{
		id = std::get<0>(pCollection);
		date = std::get<1>(pCollection);
		value = std::get<2>(pCollection);
		userID = std::get<3>(pCollection);
		currencyID = std::get<4>(pCollection);
	}
	Payment::Payment()
	{
		date = "";
		value = 0.0;
		userID = 0;
		currencyID = 0;
	}
	int Payment::GetID()
	{
		return id;
	}

	std::string Payment::GetDate()
	{
		return date;
	}	
	
	double Payment::GetValue()
	{
		return value;
	}

	int Payment::GetUserID()
	{
		return userID;
	}

	int Payment::GetCurrencyID()
	{
		return currencyID;
	}

	void Payment::SetID(int pID)
	{
		id = pID;
	}

	void Payment::SetDate(std::string pDate)
	{
		date = pDate;
	}

	void Payment::SetValue(double pValue)
	{
		value = pValue;
	}

	void Payment::SetUserID(int uID)
	{
		userID = uID;
	}
	void Payment::SetCurrencyID(int cID)
	{
		currencyID = cID;
	}

	bool Payment::CreatePayment(DataLayer::OrmasDal &ormasDal, std::string pDate, double pValue, int uID, int cID,
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
		if (0 != id && ormasDal.CreatePayment(id, date, value, userID, currencyID, errorMessage))
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
	bool Payment::CreatePayment(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreatePayment(id, date, value, userID, currencyID, errorMessage))
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
	bool Payment::DeletePayment(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!this->GetPaymentByID(ormasDal, id, errorMessage))
			return false;
		if (ormasDal.DeletePayment(id, errorMessage))
		{
			if (CancelPayment(ormasDal, userID, currencyID, errorMessage))
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

	bool Payment::UpdatePayment(DataLayer::OrmasDal &ormasDal, std::string pDate, double pValue, int uID, int cID,
		std::string& errorMessage)
	{
		date = pDate;
		value = pValue;
		userID = uID;
		currencyID = cID;
		currentValue = GetCurrentValue(ormasDal, id, errorMessage);
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdatePayment(id, date, value, userID, currencyID, errorMessage))
		{
			if (Replenishment(ormasDal, userID, currencyID, currentValue, errorMessage))
			{
				currentValue = 0.0;
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
	bool Payment::UpdatePayment(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		currentValue = GetCurrentValue(ormasDal, id, errorMessage);
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdatePayment(id, date, value, userID, currencyID, errorMessage))
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

	std::string Payment::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || date.empty() || 0 != userID || 0 != currencyID || 0 != value)
		{
			return ormasDal.GetFilterForPayment(id, date, value, userID, currencyID);
		}
		return "";
	}

	bool Payment::GetPaymentByID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage)
	{
		id = bID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::paymentsViewCollection> paymentVector = ormasDal.GetPayments(errorMessage, filter);
		if (0 != paymentVector.size())
		{
			id = std::get<0>(paymentVector.at(0));
			date = std::get<1>(paymentVector.at(0));
			value = std::get<2>(paymentVector.at(0));
			userID = std::get<4>(paymentVector.at(0));
			currencyID = std::get<5>(paymentVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find Payment with this id";
		}
		return false;
	}

	bool Payment::IsEmpty()
	{
		if (0 == id && date.empty() && 0.0 == value && 0 == userID && 0 == currencyID)
			return true;
		return false;
	}

	void Payment::Clear()
	{
		id = 0;
		date.clear();
		value = 0;
		userID = 0;
		currencyID = 0;
	}

	bool Payment::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string pDate, double pValue, int uID, int cID,
		std::string& errorMessage)
	{
		Payment payment;
		payment.SetDate(pDate);
		payment.SetValue(pValue);
		payment.SetUserID(uID);
		payment.SetCurrencyID(cID);
		std::string filter = payment.GenerateFilter(ormasDal);
		std::vector<DataLayer::paymentsViewCollection> paymentVector = ormasDal.GetPayments(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == paymentVector.size())
		{
			return false;
		}
		errorMessage = "Payment with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Payment::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Payment payment;
		payment.SetDate(date);
		payment.SetValue(value);
		payment.SetUserID(userID);
		payment.SetCurrencyID(currencyID);
		std::string filter = payment.GenerateFilter(ormasDal);
		std::vector<DataLayer::paymentsViewCollection> paymentVector = ormasDal.GetPayments(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == paymentVector.size())
		{
			return false;
		}
		errorMessage = "Payment with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Payment::Replenishment(DataLayer::OrmasDal& ormasDal, int uID, int cID, std::string& errorMessage)
	{
		CompanyAccountRelation cAccRel;
		CompanyEmployeeRelation cEmpRel;
		Balance balance;
		Company company;
		if (balance.GetBalanceByUserID(ormasDal, uID, errorMessage))
		{
			int credAccID = balance.GetSubaccountID();
			int companyID = company.GetCompanyID(ormasDal, errorMessage);
			int debAccID = cAccRel.GetAccountIDByCompanyID(ormasDal, companyID, "10110", errorMessage);
			if (0 == debAccID || 0 == credAccID || 0 == companyID)
			{
				return false;
			}
			if (this->CreateEntry(ormasDal, debAccID, value, credAccID, ormasDal.GetSystemDateTime(), errorMessage))
			{
				BalancePaymentRelation bpRelation;
				bpRelation.SetBalanceID(balance.GetID());
				bpRelation.SetPaymentID(this->id);
				if (bpRelation.CreateBalancePaymentRelation(ormasDal, errorMessage))
					return true;
			}
		}
		return false;
	}

	bool Payment::Replenishment(DataLayer::OrmasDal& ormasDal, int uID, int cID, double previousValue, std::string& errorMessage)
	{
		CompanyAccountRelation cAccRel;
		CompanyEmployeeRelation cEmpRel;
		Balance balance;
		Company company;
		if (balance.GetBalanceByUserID(ormasDal, uID, errorMessage))
		{
			int credAccID = balance.GetSubaccountID();
			int companyID = company.GetCompanyID(ormasDal, errorMessage);
			int debAccID = cAccRel.GetAccountIDByCompanyID(ormasDal, companyID, "10110", errorMessage);
			if (0 == debAccID || 0 == credAccID || 0 == companyID)
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

	double Payment::GetCurrentValue(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		Payment payment;
		if (payment.GetPaymentByID(ormasDal, pID, errorMessage))
			return payment.GetValue();
		return 0;
	}

	bool Payment::CancelPayment(DataLayer::OrmasDal& ormasDal, int uID, int cID, std::string& errorMessage)
	{
		CompanyAccountRelation cAccRel;
		CompanyEmployeeRelation cEmpRel;
		Balance balance;
		Company company;
		if (balance.GetBalanceByUserID(ormasDal, uID, errorMessage))
		{
			int credAccID = balance.GetSubaccountID();
			int companyID = company.GetCompanyID(ormasDal, errorMessage);
			int debAccID = cAccRel.GetAccountIDByCompanyID(ormasDal, companyID, "10110", errorMessage);
			if (0 == debAccID || 0 == credAccID || 0 == companyID)
			{
				return false;
			}
			if (this->CorrectingEntry(ormasDal, debAccID, value, credAccID, ormasDal.GetSystemDateTime(), errorMessage))
			{
				BalancePaymentRelation bpRelation;
				bpRelation.SetBalanceID(balance.GetID());
				bpRelation.SetPaymentID(this->id);
				if (bpRelation.DeleteBalancePaymentRelation(ormasDal, errorMessage))
					return true;
			}
		}
		return false;
	}

	bool Payment::CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		if (!entry.CreateEntry(ormasDal, errorMessage))
		{
			return false;
		}
		return true;
	}
	bool Payment::CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, double previousSum, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(credAccID);
		entry.SetValue(previousSum);
		entry.SetCreditingAccountID(debAccID);
		if (!entry.CreateEntry(ormasDal, errorMessage, true))
		{
			return false;
		}
		entry.Clear();
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		if (!entry.CreateEntry(ormasDal, errorMessage))
		{
			return false;
		}
		return true;
	}
	bool Payment::CorrectingEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(credAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(debAccID);
		if (!entry.CreateEntry(ormasDal, errorMessage, true))
		{
			return false;
		}
		return true;
	}
}