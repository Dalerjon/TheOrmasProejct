#include "stdafx.h"
#include "EntryClass.h"

namespace BusinessLayer{
	Entry::Entry(DataLayer::entriesCollection eCollection)
	{
		id = std::get<0>(eCollection);
		date = std::get<1>(eCollection);
		debitingAccountID = std::get<2>(eCollection);
		value = std::get<3>(eCollection);
		creditingAccountID = std::get<4>(eCollection);
	}
	Entry::Entry()
	{
		date = "";
		debitingAccountID = 0;
		value = 0.0;
		creditingAccountID = 0;
	}
	int Entry::GetID()
	{
		return id;
	}

	std::string Entry::GetDate()
	{
		return date;
	}

	int Entry::GetDebitingAccountID()
	{
		return debitingAccountID;
	}
	
	double Entry::GetValue()
	{
		return value;
	}
	
	int Entry::GetCreditingAccountID()
	{
		return creditingAccountID;
	}

	void Entry::SetID(int eID)
	{
		id = eID;
	}

	void Entry::SetDate(std::string eDate)
	{
		date = eDate;
	}

	void Entry::SetDebitingAccountID(int daID)
	{
		debitingAccountID = daID;
	}

	void Entry::SetValue(double eValue)
	{
		value = eValue;
	}

	void Entry::SetCreditingAccountID(int caID)
	{
		creditingAccountID = caID;
	}


	bool Entry::CreateEntry(DataLayer::OrmasDal &ormasDal, std::string eDate, int daID, double eValue, int caID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, eDate, daID, eValue, caID, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		date = eDate;
		debitingAccountID = daID;
		value = eValue;
		creditingAccountID = caID;
		if (0 != id && ormasDal.CreateEntry(id, date, debitingAccountID, value, creditingAccountID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Entry::CreateEntry(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateEntry(id, date, debitingAccountID, value, creditingAccountID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Entry::DeleteEntry(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteEntry(id, errorMessage))
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

	bool Entry::UpdateEntry(DataLayer::OrmasDal &ormasDal, std::string eDate, int daID, double eValue, int caID, std::string& errorMessage)
	{
		date = eDate;
		debitingAccountID = daID;
		value = eValue;
		creditingAccountID = caID;
		if (0 != id && ormasDal.UpdateEntry(id, date, debitingAccountID, value, creditingAccountID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Entry::UpdateEntry(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateEntry(id, date, debitingAccountID, value, creditingAccountID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string Entry::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || date.empty() || 0.0 != value || 0 != debitingAccountID || 0 != creditingAccountID)
		{
			return ormasDal.GetFilterForEntry(id, date, debitingAccountID, value, creditingAccountID);
		}
		return "";
	}

	bool Entry::GetEntryByID(DataLayer::OrmasDal& ormasDal, int eID, std::string& errorMessage)
	{
		id = eID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::entriesViewCollection> entryVector = ormasDal.GetEntries(errorMessage, filter);
		if (0 != entryVector.size())
		{
			id = std::get<0>(entryVector.at(0));
			date = std::get<1>(entryVector.at(0));
			debitingAccountID = std::get<5>(entryVector.at(0));
			value = std::get<3>(entryVector.at(0));
			creditingAccountID = std::get<6>(entryVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find entry with this id";
		}
		return false;
	}

	bool Entry::IsEmpty()
	{
		if (0 == id && date.empty() && 0.0 == value && 0 == debitingAccountID && 0 == creditingAccountID)
			return true;
		return false;
	}

	void Entry::Clear()
	{
		id = 0;
		date.clear();
		value = 0;
		debitingAccountID = 0;
		creditingAccountID = 0;
	}

	bool Entry::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string eDate, int daID, double eValue, int caID, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(eDate);
		entry.SetDebitingAccountID(daID);
		entry.SetValue(eValue);
		entry.SetCreditingAccountID(caID);
		std::string filter = entry.GenerateFilter(ormasDal);
		std::vector<DataLayer::entriesViewCollection> entryVector = ormasDal.GetEntries(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == entryVector.size())
		{
			return false;
		}
		errorMessage = "Entry with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Entry::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(date);
		entry.SetDebitingAccountID(debitingAccountID);
		entry.SetValue(value);
		entry.SetCreditingAccountID(creditingAccountID);
		std::string filter = entry.GenerateFilter(ormasDal);
		std::vector<DataLayer::entriesViewCollection> entryVector = ormasDal.GetEntries(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == entryVector.size())
		{
			return false;
		}
		errorMessage = "Entry with these parameters are already exist! Please avoid the duplication!";
		return true;
	}
}