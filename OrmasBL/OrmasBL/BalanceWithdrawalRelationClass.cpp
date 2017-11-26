#include "stdafx.h"
#include "BalanceWithdrawalRelationClass.h"


namespace BusinessLayer{
	BalanceWithdrawalRelation::BalanceWithdrawalRelation(DataLayer::balanceWithdrawalCollection bwCollection)
	{
		balanceID = std::get<0>(bwCollection);
		withdrawalID = std::get<1>(bwCollection);
	}
	BalanceWithdrawalRelation::BalanceWithdrawalRelation()
	{
		balanceID = 0;
		withdrawalID = 0;
	}

	int BalanceWithdrawalRelation::GetBalanceID()
	{
		return balanceID;
	}

	int BalanceWithdrawalRelation::GetWithdrawalID()
	{
		return withdrawalID;
	}

	void BalanceWithdrawalRelation::SetBalanceID(int bID)
	{
		balanceID = bID;
	}
	void BalanceWithdrawalRelation::SetWithdrawalID(int wID)
	{
		withdrawalID = wID;
	}

	bool BalanceWithdrawalRelation::CreateBalanceWithdrawalRelation(DataLayer::OrmasDal &ormasDal, int bID, int wID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, bID, wID, errorMessage))
			return false;
		balanceID = bID;
		withdrawalID = wID;

		if (ormasDal.CreateBalanceWithdrawal(balanceID, withdrawalID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool BalanceWithdrawalRelation::CreateBalanceWithdrawalRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		if (ormasDal.CreateBalanceWithdrawal(balanceID, withdrawalID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool BalanceWithdrawalRelation::DeleteBalanceWithdrawalRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteBalanceWithdrawal(balanceID, withdrawalID, errorMessage))
		{
			balanceID = 0;
			withdrawalID = 0;
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}



	std::string BalanceWithdrawalRelation::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != balanceID || 0 != withdrawalID)
		{
			return ormasDal.GetFilterForBalanceWithdrawal(balanceID, withdrawalID);
		}
		return "";
	}

	std::vector<int> BalanceWithdrawalRelation::GetAllWithdrawalByBalanceID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage)
	{
		std::vector<int> withdrawalIDVector;
		BalanceWithdrawalRelation bpRelation;
		bpRelation.SetBalanceID(bID);
		bpRelation.SetWithdrawalID(0);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balanceWithdrawalCollection> balanceWithdrawalVector = ormasDal.GetBalanceWithdrawal(errorMessage, filter);
		if (0 != balanceWithdrawalVector.size())
		{
			for each (auto item in balanceWithdrawalVector)
			{
				withdrawalIDVector.push_back(std::get<1>(item));
			}
		}
		return withdrawalIDVector;
	}

	std::vector<int> BalanceWithdrawalRelation::GetAllBalanceByWithdrawalID(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage)
	{
		std::vector<int> balanceIDVector;
		BalanceWithdrawalRelation bpRelation;
		bpRelation.SetBalanceID(0);
		bpRelation.SetWithdrawalID(wID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balanceWithdrawalCollection> balanceWithdrawalVector = ormasDal.GetBalanceWithdrawal(errorMessage, filter);
		if (0 != balanceWithdrawalVector.size())
		{
			for each (auto item in balanceWithdrawalVector)
			{
				balanceIDVector.push_back(std::get<0>(item));
			}
		}
		return balanceIDVector;
	}


	bool BalanceWithdrawalRelation::IsEmpty()
	{
		if (0 == balanceID && 0 == withdrawalID)
			return true;
		return false;
	}

	void BalanceWithdrawalRelation::Clear()
	{
		balanceID = 0;
		withdrawalID = 0;
	}


	bool BalanceWithdrawalRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, int bID, int pID, std::string& errorMessage)
	{
		BalanceWithdrawalRelation bpRelation;
		bpRelation.SetBalanceID(bID);
		bpRelation.SetWithdrawalID(pID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balanceWithdrawalCollection> balanceWithdrawalVector = ormasDal.GetBalanceWithdrawal(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == balanceWithdrawalVector.size())
		{
			return false;
		}
		errorMessage = "Balance-Withdrawal Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool BalanceWithdrawalRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		BalanceWithdrawalRelation bpRelation;
		bpRelation.SetBalanceID(balanceID);
		bpRelation.SetWithdrawalID(withdrawalID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balanceWithdrawalCollection> balanceWithdrawalVector = ormasDal.GetBalanceWithdrawal(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == balanceWithdrawalVector.size())
		{
			return false;
		}
		errorMessage = "Balance-Withdrawal Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}