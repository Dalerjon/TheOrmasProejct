#include "stdafx.h"
#include "EntrySubccountRelationClass.h"


namespace BusinessLayer{
	EntrySubaccountRelation::EntrySubaccountRelation(DataLayer::entrySubaccountCollection aeCollection)
	{
		entryID = std::get<0>(aeCollection);
		subaccountID = std::get<1>(aeCollection);
	}
	EntrySubaccountRelation::EntrySubaccountRelation()
	{
		entryID = 0;
		subaccountID = 0;
	}

	int EntrySubaccountRelation::GetSubaccountID()
	{
		return subaccountID;
	}

	int EntrySubaccountRelation::GetEntryID()
	{
		return entryID;
	}

	void EntrySubaccountRelation::SetSubaccountID(int sID)
	{
		subaccountID = sID;
	}
	void EntrySubaccountRelation::SetEntryID(int eID)
	{
		entryID = eID;
	}

	bool EntrySubaccountRelation::CreateEntrySubaccountRelation(DataLayer::OrmasDal &ormasDal, int eID, int sID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, eID, sID, errorMessage))
			return false;
		subaccountID = sID;
		entryID = eID;

		if (ormasDal.CreateEntrySubaccount(entryID, subaccountID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool EntrySubaccountRelation::CreateEntrySubaccountRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		if (ormasDal.CreateEntrySubaccount(entryID, subaccountID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool EntrySubaccountRelation::DeleteEntrySubaccountRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteEntrySubaccount(entryID, subaccountID, errorMessage))
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



	std::string EntrySubaccountRelation::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != subaccountID || 0 != entryID)
		{
			return ormasDal.GetFilterForEntrySubaccount(entryID, subaccountID);
		}
		return "";
	}

	std::vector<int> EntrySubaccountRelation::GetAllEntryBySubaccountID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage)
	{
		std::vector<int> entryIDVector;
		EntrySubaccountRelation aeRelation;
		aeRelation.SetSubaccountID(sID);
		aeRelation.SetEntryID(0);
		std::string filter = aeRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::entrySubaccountCollection> entrySubaccountVector = ormasDal.GetEntrySubaccount(errorMessage, filter);
		if (0 != entrySubaccountVector.size())
		{
			for each (auto item in entrySubaccountVector)
			{
				entryIDVector.push_back(std::get<1>(item));
			}
		}
		return entryIDVector;
	}

	std::vector<int> EntrySubaccountRelation::GetAllSubaccountByEntryID(DataLayer::OrmasDal& ormasDal, int eID, std::string& errorMessage)
	{
		std::vector<int> accountIDVector;
		EntrySubaccountRelation aeRelation;
		aeRelation.SetSubaccountID(0);
		aeRelation.SetEntryID(eID);
		std::string filter = aeRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::entrySubaccountCollection> entrySubaccountVector = ormasDal.GetEntrySubaccount(errorMessage, filter);
		if (0 != entrySubaccountVector.size())
		{
			for each (auto item in entrySubaccountVector)
			{
				accountIDVector.push_back(std::get<0>(item));
			}
		}
		return accountIDVector;
	}


	bool EntrySubaccountRelation::IsEmpty()
	{
		if (0 == subaccountID && 0 == entryID)
			return true;
		return false;
	}

	void EntrySubaccountRelation::Clear()
	{
		subaccountID = 0;
		entryID = 0;
	}

	bool EntrySubaccountRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, int sID, std::string& errorMessage)
	{
		EntrySubaccountRelation aeRelation;
		aeRelation.SetSubaccountID(sID);
		aeRelation.SetEntryID(eID);
		std::string filter = aeRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::entrySubaccountCollection> entrySubaccountVector = ormasDal.GetEntrySubaccount(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == entrySubaccountVector.size())
		{
			return false;
		}
		errorMessage = "Entry-Subaccount Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool EntrySubaccountRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		EntrySubaccountRelation aeRelation;
		aeRelation.SetSubaccountID(subaccountID);
		aeRelation.SetEntryID(entryID);
		std::string filter = aeRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::entrySubaccountCollection> entrySubaccountVector = ormasDal.GetEntrySubaccount(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == entrySubaccountVector.size())
		{
			return false;
		}
		errorMessage = "Entry-Subaccount Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}