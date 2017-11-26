#include "stdafx.h"
#include "BalancePaymentRelationClass.h"


namespace BusinessLayer{
	BalancePaymentRelation::BalancePaymentRelation(DataLayer::balancePaymentCollection bpCollection)
	{
		balanceID = std::get<0>(bpCollection);
		paymentID = std::get<1>(bpCollection);
	}
	BalancePaymentRelation::BalancePaymentRelation()
	{
		balanceID = 0;
		paymentID = 0;
	}
	
	int BalancePaymentRelation::GetBalanceID()
	{
		return balanceID;
	}

	int BalancePaymentRelation::GetPaymentID()
	{
		return paymentID;
	}

	void BalancePaymentRelation::SetBalanceID(int bID)
	{
		balanceID = bID;
	}
	void BalancePaymentRelation::SetPaymentID(int pID)
	{
		paymentID = pID;
	}
	
	bool BalancePaymentRelation::CreateBalancePaymentRelation(DataLayer::OrmasDal &ormasDal, int bID, int pID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, bID, pID, errorMessage))
			return false;
		balanceID = bID;
		paymentID = pID;

		if (ormasDal.CreateBalancePayment(balanceID, paymentID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool BalancePaymentRelation::CreateBalancePaymentRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		if (ormasDal.CreateBalancePayment(balanceID, paymentID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool BalancePaymentRelation::DeleteBalancePaymentRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteBalancePayment(balanceID, paymentID, errorMessage))
		{
			balanceID = 0;
			paymentID = 0;
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}

	

	std::string BalancePaymentRelation::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != balanceID || 0 != paymentID)
		{
			return ormasDal.GetFilterForBalancePayment(balanceID, paymentID);
		}
		return "";
	}

	std::vector<int> BalancePaymentRelation::GetAllPaymentByBalanceID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage)
	{
		std::vector<int> paymentIDVector;
		BalancePaymentRelation bpRelation;
		bpRelation.SetBalanceID(bID);
		bpRelation.SetPaymentID(0);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balancePaymentCollection> balancePaymentVector = ormasDal.GetBalancePayment(errorMessage, filter);
		if (0 != balancePaymentVector.size())
		{
			for each (auto item in balancePaymentVector)
			{
				paymentIDVector.push_back(std::get<1>(item));
			}
		}
		return paymentIDVector;
	}

	std::vector<int> BalancePaymentRelation::GetAllBalanceByPaymentID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		std::vector<int> balanceIDVector;
		BalancePaymentRelation bpRelation;
		bpRelation.SetBalanceID(0);
		bpRelation.SetPaymentID(pID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balancePaymentCollection> balancePaymentVector = ormasDal.GetBalancePayment(errorMessage, filter);
		if (0 != balancePaymentVector.size())
		{
			for each (auto item in balancePaymentVector)
			{
				balanceIDVector.push_back(std::get<0>(item));
			}
		}
		return balanceIDVector;
	}


	bool BalancePaymentRelation::IsEmpty()
	{
		if (0 == balanceID && 0 == paymentID)
			return true;
		return false;
	}

	void BalancePaymentRelation::Clear()
	{
		balanceID = 0;
		paymentID = 0;
	}
	
	bool BalancePaymentRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, int bID, int pID, std::string& errorMessage)
	{
		BalancePaymentRelation bpRelation;
		bpRelation.SetBalanceID(bID);
		bpRelation.SetPaymentID(pID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balancePaymentCollection> balancePaymentVector = ormasDal.GetBalancePayment(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == balancePaymentVector.size())
		{
			return false;
		}
		errorMessage = "Balance-Payment Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool BalancePaymentRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		BalancePaymentRelation bpRelation;
		bpRelation.SetBalanceID(balanceID);
		bpRelation.SetPaymentID(paymentID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balancePaymentCollection> balancePaymentVector = ormasDal.GetBalancePayment(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == balancePaymentVector.size())
		{
			return false;
		}
		errorMessage = "Balance-Payment Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}