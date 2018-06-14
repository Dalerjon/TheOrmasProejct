#include "stdafx.h"
#include "EntryRoutingClass.h"

namespace BusinessLayer{
	EntryRouting::EntryRouting(DataLayer::entryRoutingCollection eCollection)
	{
		id = std::get<0>(eCollection);
		operation = std::get<1>(eCollection);
		debit = std::get<2>(eCollection);
		credit = std::get<3>(eCollection);
	}
	EntryRouting::EntryRouting()
	{
		operation = "";
		debit = 0;
		credit = 0;
	}
	int EntryRouting::GetID()
	{
		return id;
	}

	std::string EntryRouting::GetOperation()
	{
		return operation;
	}

	int EntryRouting::GetDebit()
	{
		return debit;
	}

	int EntryRouting::GetCredit()
	{
		return credit;
	}

	void EntryRouting::SetID(int eID)
	{
		id = eID;
	}

	void EntryRouting::SetOperation(std::string eOperation)
	{
		operation = eOperation;
	}

	void EntryRouting::SetDebit(int eDebit)
	{
		debit = eDebit;
	}

	void EntryRouting::SetCredit(int eCredit)
	{
		credit = eCredit;
	}


	bool EntryRouting::CreateEntryRouting(DataLayer::OrmasDal &ormasDal, std::string eOperation, int eDebit, int eCredit, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, eOperation, eDebit, eCredit, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		operation = eOperation;
		debit = eDebit;
		credit = eCredit;
		if (0 != id && ormasDal.CreateEntryRouting(id, operation, debit, credit, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool EntryRouting::CreateEntryRouting(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateEntryRouting(id, operation, debit, credit, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool EntryRouting::DeleteEntryRouting(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteEntryRouting(id, errorMessage))
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

	bool EntryRouting::UpdateEntryRouting(DataLayer::OrmasDal &ormasDal, std::string eOperation, int eDebit, int eCredit, std::string& errorMessage)
	{
		operation = eOperation;
		debit = eDebit;
		credit = eCredit;
		if (0 != id && ormasDal.UpdateEntryRouting(id, operation, debit, credit, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool EntryRouting::UpdateEntryRouting(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateEntryRouting(id, operation, debit, credit, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string EntryRouting::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || operation.empty() || 0 != debit || 0 != credit)
		{
			return ormasDal.GetFilterForEntryRouting(id, operation, debit, credit);
		}
		return "";
	}

	bool EntryRouting::GetEntryRoutingByID(DataLayer::OrmasDal& ormasDal, int eID, std::string& errorMessage)
	{
		id = eID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::entryRoutingCollection> entryRoutingVector = ormasDal.GetEntryRouting(errorMessage, filter);
		if (0 != entryRoutingVector.size())
		{
			id = std::get<0>(entryRoutingVector.at(0));
			operation = std::get<1>(entryRoutingVector.at(0));
			debit = std::get<2>(entryRoutingVector.at(0));
			credit = std::get<3>(entryRoutingVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find entry routing with this id";
		}
		return false;
	}

	bool EntryRouting::IsEmpty()
	{
		if (0 == id && operation.empty()  && 0 == debit && 0 == credit)
			return true;
		return false;
	}

	void EntryRouting::Clear()
	{
		id = 0;
		operation.clear();
		debit = 0;
		credit = 0;
	}

	bool EntryRouting::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string eOperation, int eDebit, int eCredit, std::string& errorMessage)
	{
		EntryRouting entryRouting;
		entryRouting.SetOperation(eOperation);
		entryRouting.SetDebit(eDebit);
		entryRouting.SetCredit(eCredit);
		std::string filter = entryRouting.GenerateFilter(ormasDal);
		errorMessage.clear();
		std::vector<DataLayer::entryRoutingCollection> entryRoutingVector = ormasDal.GetEntryRouting(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == entryRoutingVector.size())
		{
			return false;
		}
		errorMessage = "Entry routing with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool EntryRouting::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		EntryRouting EntryRouting;
		EntryRouting.SetOperation(operation);
		EntryRouting.SetDebit(debit);
		EntryRouting.SetCredit(credit);
		std::string filter = EntryRouting.GenerateFilter(ormasDal);
		errorMessage.clear();
		std::vector<DataLayer::entryRoutingCollection> entryRoutingVector = ormasDal.GetEntryRouting(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == entryRoutingVector.size())
		{
			return false;
		}
		errorMessage = "Entry routing with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool EntryRouting::CheckEntryRouting(DataLayer::OrmasDal& ormasDal, int eDebit, int eCredit, std::string& errorMessage)
	{
		EntryRouting entryRouting;
		entryRouting.SetDebit(eDebit);
		entryRouting.SetCredit(eCredit);
		std::string filter = entryRouting.GenerateFilter(ormasDal);
		errorMessage.clear();
		std::vector<DataLayer::entryRoutingCollection> entryRoutingVector = ormasDal.GetEntryRouting(errorMessage, filter);
		if (!errorMessage.empty())
			return false;
		if (0 < entryRoutingVector.size())
		{
			return true;
		}
		errorMessage = "Entry routing with these parameters does not exist! This entry isn't valid!";
		return false;
	}
}