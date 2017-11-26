#include "stdafx.h"
#include "BalancePayslipRelationClass.h"


namespace BusinessLayer{
	BalancePayslipRelation::BalancePayslipRelation(DataLayer::balancePayslipCollection bpCollection)
	{
		balanceID = std::get<0>(bpCollection);
		payslipID = std::get<1>(bpCollection);
	}
	BalancePayslipRelation::BalancePayslipRelation()
	{
		balanceID = 0;
		payslipID = 0;
	}

	int BalancePayslipRelation::GetBalanceID()
	{
		return balanceID;
	}

	int BalancePayslipRelation::GetPayslipID()
	{
		return payslipID;
	}

	void BalancePayslipRelation::SetBalanceID(int bID)
	{
		balanceID = bID;
	}
	void BalancePayslipRelation::SetPayslipID(int pID)
	{
		payslipID = pID;
	}

	bool BalancePayslipRelation::CreateBalancePayslipRelation(DataLayer::OrmasDal &ormasDal, int bID, int pID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, bID, pID, errorMessage))
			return false;
		balanceID = bID;
		payslipID = pID;

		if (ormasDal.CreateBalancePayslip(balanceID, payslipID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool BalancePayslipRelation::CreateBalancePayslipRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		if (ormasDal.CreateBalancePayslip(balanceID, payslipID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool BalancePayslipRelation::DeleteBalancePayslipRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteBalancePayslip(balanceID, payslipID, errorMessage))
		{
			balanceID = 0;
			payslipID = 0;
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}



	std::string BalancePayslipRelation::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != balanceID || 0 != payslipID)
		{
			return ormasDal.GetFilterForBalancePayslip(balanceID, payslipID);
		}
		return "";
	}

	std::vector<int> BalancePayslipRelation::GetAllPayslipByBalanceID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage)
	{
		std::vector<int> payslipIDVector;
		BalancePayslipRelation bpRelation;
		bpRelation.SetBalanceID(bID);
		bpRelation.SetPayslipID(0);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balancePayslipCollection> balancePayslipVector = ormasDal.GetBalancePayslip(errorMessage, filter);
		if (0 != balancePayslipVector.size())
		{
			for each (auto item in balancePayslipVector)
			{
				payslipIDVector.push_back(std::get<1>(item));
			}
		}
		return payslipIDVector;
	}

	std::vector<int> BalancePayslipRelation::GetAllBalanceByPayslipID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		std::vector<int> balanceIDVector;
		BalancePayslipRelation bpRelation;
		bpRelation.SetBalanceID(0);
		bpRelation.SetPayslipID(pID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balancePayslipCollection> balancePayslipVector = ormasDal.GetBalancePayslip(errorMessage, filter);
		if (0 != balancePayslipVector.size())
		{
			for each (auto item in balancePayslipVector)
			{
				balanceIDVector.push_back(std::get<0>(item));
			}
		}
		return balanceIDVector;
	}


	bool BalancePayslipRelation::IsEmpty()
	{
		if (0 == balanceID && 0 == payslipID)
			return true;
		return false;
	}

	void BalancePayslipRelation::Clear()
	{
		balanceID = 0;
		payslipID = 0;
	}


	bool BalancePayslipRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, int bID, int pID, std::string& errorMessage)
	{
		BalancePayslipRelation bpRelation;
		bpRelation.SetBalanceID(bID);
		bpRelation.SetPayslipID(pID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balancePayslipCollection> balancePayslipVector = ormasDal.GetBalancePayslip(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == balancePayslipVector.size())
		{
			return false;
		}
		errorMessage = "Balance-Payslip Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool BalancePayslipRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		BalancePayslipRelation bpRelation;
		bpRelation.SetBalanceID(balanceID);
		bpRelation.SetPayslipID(payslipID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balancePayslipCollection> balancePayslipVector = ormasDal.GetBalancePayslip(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == balancePayslipVector.size())
		{
			return false;
		}
		errorMessage = "Balance-Payslip Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}