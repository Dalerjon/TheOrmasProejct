#include "stdafx.h"
#include "AccountEntryRelationClass.h"


namespace BusinessLayer{
	AccountEntryRelation::AccountEntryRelation(DataLayer::accountEntryCollection aeCollection)
	{
		accountID = std::get<0>(aeCollection);
		entryID = std::get<1>(aeCollection);
	}
	AccountEntryRelation::AccountEntryRelation()
	{
		accountID = 0;
		entryID = 0;
	}

	int AccountEntryRelation::GetAccountID()
	{
		return accountID;
	}

	int AccountEntryRelation::GetEntryID()
	{
		return entryID;
	}

	void AccountEntryRelation::SetAccountID(int aID)
	{
		accountID = aID;
	}
	void AccountEntryRelation::SetEntryID(int eID)
	{
		entryID = eID;
	}

	bool AccountEntryRelation::CreateAccountEntryRelation(DataLayer::OrmasDal &ormasDal, int aID, int eID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, aID, eID, errorMessage))
			return false;
		accountID = aID;
		entryID = eID;

		if (ormasDal.CreateAccountEntry(accountID, entryID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool AccountEntryRelation::CreateAccountEntryRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		if (ormasDal.CreateAccountEntry(accountID, entryID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool AccountEntryRelation::DeleteAccountEntryRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteAccountEntry(accountID, entryID, errorMessage))
		{
			Clear();
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}



	std::string AccountEntryRelation::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != accountID || 0 != entryID)
		{
			return ormasDal.GetFilterForAccountEntry(accountID, entryID);
		}
		return "";
	}

	std::vector<int> AccountEntryRelation::GetAllEntryByAccountID(DataLayer::OrmasDal& ormasDal, int aID, std::string& errorMessage)
	{
		std::vector<int> entryIDVector;
		AccountEntryRelation aeRelation;
		aeRelation.SetAccountID(aID);
		aeRelation.SetEntryID(0);
		std::string filter = aeRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::accountEntryCollection> accountEntryVector = ormasDal.GetAccountEntry(errorMessage, filter);
		if (0 != accountEntryVector.size())
		{
			for each (auto item in accountEntryVector)
			{
				entryIDVector.push_back(std::get<1>(item));
			}
		}
		return entryIDVector;
	}

	std::vector<int> AccountEntryRelation::GetAllAccountByEntryID(DataLayer::OrmasDal& ormasDal, int eID, std::string& errorMessage)
	{
		std::vector<int> accountIDVector;
		AccountEntryRelation aeRelation;
		aeRelation.SetAccountID(0);
		aeRelation.SetEntryID(eID);
		std::string filter = aeRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::accountEntryCollection> accountEntryVector = ormasDal.GetAccountEntry(errorMessage, filter);
		if (0 != accountEntryVector.size())
		{
			for each (auto item in accountEntryVector)
			{
				accountIDVector.push_back(std::get<0>(item));
			}
		}
		return accountIDVector;
	}


	bool AccountEntryRelation::IsEmpty()
	{
		if (0 == accountID && 0 == entryID)
			return true;
		return false;
	}

	void AccountEntryRelation::Clear()
	{
		accountID = 0;
		entryID = 0;
	}

	bool AccountEntryRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, int aID, int eID, std::string& errorMessage)
	{
		AccountEntryRelation aeRelation;
		aeRelation.SetAccountID(aID);
		aeRelation.SetEntryID(eID);
		std::string filter = aeRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::accountEntryCollection> accountEntryVector = ormasDal.GetAccountEntry(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == accountEntryVector.size())
		{
			return false;
		}
		errorMessage = "Account-Entry Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool AccountEntryRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		AccountEntryRelation aeRelation;
		aeRelation.SetAccountID(accountID);
		aeRelation.SetEntryID(entryID);
		std::string filter = aeRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::accountEntryCollection> accountEntryVector = ormasDal.GetAccountEntry(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == accountEntryVector.size())
		{
			return false;
		}
		errorMessage = "Account-Entry Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}