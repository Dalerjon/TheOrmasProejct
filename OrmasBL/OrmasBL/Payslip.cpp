#include "stdafx.h"
#include "PayslipClass.h"
#include "UserClass.h"
#include "SalaryClass.h"
#include "BalanceClass.h"
#include "BalancePayslipRelationClass.h"

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
			if (Replenishment(ormasDal, salaryID, currencyID, errorMessage))
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
			if (Replenishment(ormasDal, salaryID, currencyID, errorMessage))
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
			if (Replenishment(ormasDal, salaryID, currencyID, currentValue, errorMessage))
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
			if (Replenishment(ormasDal, salaryID, currencyID, currentValue, errorMessage))
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

	bool Payslip::Replenishment(DataLayer::OrmasDal& ormasDal, int sID, int cID, std::string& errorMessage)
	{
		errorMessage = "";
		Salary salary;
		if (!salary.GetSalaryByID(ormasDal, sID, errorMessage))
		{
			return false;
		}
		User user;
		if (user.GetUserByID(ormasDal, salary.GetEmployeeID(), errorMessage))
		{
			return false;
		}
		int balanceID = user.GetUserAccoutID(ormasDal, cID, errorMessage);
		if (0 != balanceID && errorMessage.empty())
		{
			BalancePayslipRelation bpRelation;
			Balance balance;
			if (balance.GetBalanceByID(ormasDal, balanceID, errorMessage))
			{
				balance.SetValue(balance.GetValue() + value);
				bpRelation.SetBalanceID(balanceID);
				bpRelation.SetPayslipID(id);
				if (balance.UpdateBalance(ormasDal, errorMessage) && bpRelation.CreateBalancePayslipRelation(ormasDal, errorMessage))
					return true;
			}
		}
		return false;
	}

	bool Payslip::Replenishment(DataLayer::OrmasDal& ormasDal, int sID, int cID, double currentValue, std::string& errorMessage)
	{
		errorMessage = "";
		Salary salary;
		if (!salary.GetSalaryByID(ormasDal, sID, errorMessage))
		{
			return false;
		}
		User user;
		if (!user.GetUserByID(ormasDal, salary.GetEmployeeID(), errorMessage))
		{
			return false;
		}
		int balanceID = user.GetUserAccoutID(ormasDal, cID, errorMessage);
		if (0 != balanceID && errorMessage.empty())
		{
			Balance balance;
			if (balance.GetBalanceByID(ormasDal, balanceID, errorMessage))
			{
				balance.SetValue(balance.GetValue() + (currentValue - value));
				if(balance.UpdateBalance(ormasDal, errorMessage))
					return true;
			}
		}
		return false;
	}

	double Payslip::GetCurrentValue(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		Payslip Payslip;
		if (Payslip.GetPayslipByID(ormasDal, pID, errorMessage))
			return Payslip.GetValue();
		return 0;
	}

	bool Payslip::CancelPayslip(DataLayer::OrmasDal& ormasDal, int sID, int cID, std::string& errorMessage)
	{
		errorMessage = "";
		Salary salary;
		if (!salary.GetSalaryByID(ormasDal, sID, errorMessage))
		{
			return false;
		}
		User user;
		if (!user.GetUserByID(ormasDal, salary.GetEmployeeID(), errorMessage))
		{
			return false;
		}
		int balanceID = user.GetUserAccoutID(ormasDal, cID, errorMessage);
		if (0 != balanceID && errorMessage.empty())
		{
			BalancePayslipRelation bpRelation;
			Balance balance;
			if (balance.GetBalanceByID(ormasDal, balanceID, errorMessage))
			{
				bpRelation.SetBalanceID(balanceID);
				bpRelation.SetPayslipID(id);
				balance.SetValue(balance.GetValue() - value);
				if (balance.UpdateBalance(ormasDal, errorMessage) && bpRelation.DeleteBalancePayslipRelation(ormasDal, errorMessage))
					return true;
			}
		}
		return false;
	}
}