#include "stdafx.h"
#include "PayslipClass.h"
#include "UserClass.h"
#include "SalaryClass.h"
#include "BalanceClass.h"
#include "BalancePayslipRelationClass.h"
#include "EntryClass.h"
#include "CompanyAccountRelationClass.h"
#include "CompanyEmployeeRelationClass.h"
#include "CompanyClass.h"

namespace BusinessLayer{
	Payslip::Payslip(DataLayer::payslipsCollection pCollection)
	{
		id = std::get<0>(pCollection);
		date = std::get<1>(pCollection);
		value = std::get<2>(pCollection);
		salaryID = std::get<3>(pCollection);
		currencyID = std::get<4>(pCollection);
	}
	Payslip::Payslip()
	{
		date = "";
		value = 0.0;
		salaryID = 0;
		currencyID = 0;
	}
	int Payslip::GetID()
	{
		return id;
	}

	std::string Payslip::GetDate()
	{
		return date;
	}

	double Payslip::GetValue()
	{
		return value;
	}

	int Payslip::GetSalaryID()
	{
		return salaryID;
	}

	int Payslip::GetCurrencyID()
	{
		return currencyID;
	}

	void Payslip::SetID(int pID)
	{
		id = pID;
	}

	void Payslip::SetDate(std::string pDate)
	{
		date = pDate;
	}

	void Payslip::SetValue(double pValue)
	{
		value = pValue;
	}

	void Payslip::SetSalaryID(int sID)
	{
		salaryID = sID;
	}
	void Payslip::SetCurrencyID(int cID)
	{
		currencyID = cID;
	}

	bool Payslip::CreatePayslip(DataLayer::OrmasDal &ormasDal, std::string pDate, double pValue, int sID, int cID,
		std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, pDate, pValue, sID, cID, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		date = pDate;
		value = pValue;
		salaryID = sID;
		currencyID = cID;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreatePayslip(id, date, value, salaryID, currencyID, errorMessage))
		{
			if (Payout(ormasDal, salaryID, currencyID, errorMessage))
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
	bool Payslip::CreatePayslip(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreatePayslip(id, date, value, salaryID, currencyID, errorMessage))
		{
			if (Payout(ormasDal, salaryID, currencyID, errorMessage))
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
	bool Payslip::DeletePayslip(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!this->GetPayslipByID(ormasDal, id, errorMessage))
			return false;
		if (ormasDal.DeletePayslip(id, errorMessage))
		{
			if (CancelPayslip(ormasDal, salaryID, currencyID, errorMessage))
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

	bool Payslip::UpdatePayslip(DataLayer::OrmasDal &ormasDal, std::string pDate, double pValue, int sID, int cID,
		std::string& errorMessage)
	{
		date = pDate;
		value = pValue;
		salaryID = sID;
		currencyID = cID;
		currentValue = GetCurrentValue(ormasDal, id, errorMessage);
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdatePayslip(id, date, value, salaryID, currencyID, errorMessage))
		{
			if (Payout(ormasDal, salaryID, currencyID, currentValue, errorMessage))
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
	bool Payslip::UpdatePayslip(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		currentValue = GetCurrentValue(ormasDal, id, errorMessage);
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdatePayslip(id, date, value, salaryID, currencyID, errorMessage))
		{
			if (Payout(ormasDal, salaryID, currencyID, currentValue, errorMessage))
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

	std::string Payslip::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || date.empty() || 0 != salaryID || 0 != currencyID || 0 != value)
		{
			return ormasDal.GetFilterForPayslip(id, date, value, salaryID, currencyID);
		}
		return "";
	}

	bool Payslip::GetPayslipByID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage)
	{
		id = bID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::payslipsViewCollection> payslipVector = ormasDal.GetPayslips(errorMessage, filter);
		if (0 != payslipVector.size())
		{
			id = std::get<0>(payslipVector.at(0));
			date = std::get<1>(payslipVector.at(0));
			value = std::get<2>(payslipVector.at(0));
			salaryID = std::get<4>(payslipVector.at(0));
			currencyID = std::get<5>(payslipVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find Payslip with this id";
		}
		return false;
	}

	bool Payslip::IsEmpty()
	{
		if (0 == id && date.empty() && 0.0 == value && 0 == salaryID && 0 == currencyID)
			return true;
		return false;
	}

	void Payslip::Clear()
	{
		id = 0;
		date.clear();
		value = 0;
		salaryID = 0;
		currencyID = 0;
	}

	bool Payslip::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string pDate, double pValue, int uID, int cID,
		std::string& errorMessage)
	{
		Payslip payslip;
		payslip.SetDate(pDate);
		payslip.SetValue(pValue);
		payslip.SetSalaryID(uID);
		payslip.SetCurrencyID(cID);
		std::string filter = payslip.GenerateFilter(ormasDal);
		std::vector<DataLayer::payslipsViewCollection> payslipVector = ormasDal.GetPayslips(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == payslipVector.size())
		{
			return false;
		}
		errorMessage = "Payslip with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Payslip::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Payslip payslip;
		payslip.SetDate(date);
		payslip.SetValue(value);
		payslip.SetSalaryID(salaryID);
		payslip.SetCurrencyID(currencyID);
		std::string filter = payslip.GenerateFilter(ormasDal);
		std::vector<DataLayer::payslipsViewCollection> payslipVector = ormasDal.GetPayslips(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == payslipVector.size())
		{
			return false;
		}
		errorMessage = "Payslip with these parameters are already exist! Please avoid the duplication!";
		return true;
	}


	bool Payslip::Payout(DataLayer::OrmasDal& ormasDal, int sID, int cID, std::string& errorMessage)
	{
		CompanyAccountRelation cAccRel;
		CompanyEmployeeRelation cEmpRel;
		Balance balance;
		Company company;
		Salary salary;
		if (!salary.GetSalaryByID(ormasDal, sID, errorMessage))
		{
			if (errorMessage.empty())
				errorMessage = "Cannot find salary with this ID!";
			return false;
		}
		if (balance.GetBalanceByUserID(ormasDal, salary.GetEmployeeID(), errorMessage))
		{
			int companyID = company.GetCompanyID(ormasDal, errorMessage);
			int debAccID = cAccRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
			int credAccID = balance.GetSubaccountID(); 
			if (0 == debAccID || 0 == credAccID || 0 == companyID)
			{
				return false;
			}
			if (this->CreateEntry(ormasDal, debAccID, value, credAccID, ormasDal.GetSystemDateTime(), errorMessage))
			{
				BalancePayslipRelation bpRelation;
				bpRelation.SetBalanceID(balance.GetID());
				bpRelation.SetPayslipID(this->id);
				if (bpRelation.CreateBalancePayslipRelation(ormasDal, errorMessage))
					return true;
			}
		}
		return false;
	}

	bool Payslip::Payout(DataLayer::OrmasDal& ormasDal, int sID, int cID, double previousValue, std::string& errorMessage)
	{
		CompanyAccountRelation cAccRel;
		CompanyEmployeeRelation cEmpRel;
		Balance balance;
		Company company;
		Salary salary;
		if (!salary.GetSalaryByID(ormasDal, sID, errorMessage))
		{
			if (errorMessage.empty())
				errorMessage = "Cannot find salary with this ID!";
			return false;
		}
		if (balance.GetBalanceByUserID(ormasDal, salary.GetEmployeeID(), errorMessage))
		{
			int companyID = company.GetCompanyID(ormasDal, errorMessage);
			int debAccID = cAccRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
			int credAccID = balance.GetSubaccountID();
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

	double Payslip::GetCurrentValue(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		Payslip payslip;
		if (payslip.GetPayslipByID(ormasDal, pID, errorMessage))
			return payslip.GetValue();
		return 0;
	}

	bool Payslip::CancelPayslip(DataLayer::OrmasDal& ormasDal, int sID, int cID, std::string& errorMessage)
	{
		CompanyAccountRelation cAccRel;
		CompanyEmployeeRelation cEmpRel;
		Balance balance;
		Company company;
		Salary salary;
		if (!salary.GetSalaryByID(ormasDal, sID, errorMessage))
		{
			if (errorMessage.empty())
				errorMessage = "Cannot find salary with this ID!";
			return false;
		}
		if (balance.GetBalanceByUserID(ormasDal, salary.GetEmployeeID(), errorMessage))
		{
			int companyID = company.GetCompanyID(ormasDal, errorMessage);
			int debAccID = cAccRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
			int credAccID = balance.GetSubaccountID();
			if (0 == debAccID || 0 == credAccID || 0 == companyID)
			{
				return false;
			}
			if (this->CorrectingEntry(ormasDal, debAccID, value, credAccID, ormasDal.GetSystemDateTime(), errorMessage))
			{
				BalancePayslipRelation bpRelation;
				bpRelation.SetBalanceID(balance.GetID());
				bpRelation.SetPayslipID(this->id);
				if (bpRelation.DeleteBalancePayslipRelation(ormasDal, errorMessage))
					return true;
			}
		}
		return false;
	}

	bool Payslip::CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage)
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
	bool Payslip::CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, double previousSum, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(credAccID);
		entry.SetValue(previousSum);
		entry.SetCreditingAccountID(debAccID);
		if (!entry.CreateEntry(ormasDal, errorMessage))
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
	bool Payslip::CorrectingEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(credAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(debAccID);
		if (!entry.CreateEntry(ormasDal, errorMessage))
		{
			return false;
		}
		return true;
	}
}