#include "stdafx.h"
#include "EntryClass.h"
#include "EntryRoutingClass.h"
#include "AccountClass.h"
#include "SubaccountClass.h"
#include "AccountTypeClass.h"
#include "EntrySubccountRelationClass.h"

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


	bool Entry::CreateEntry(DataLayer::OrmasDal &ormasDal, std::string eDate, int daID, double eValue, int caID, 
		std::string& errorMessage, bool corrEntry)
	{
		if (IsDuplicate(ormasDal, eDate, daID, eValue, caID, errorMessage))
			return false;
		if (corrEntry == false)
		{
			if (!EntryRoutingValidation(ormasDal, daID, caID, errorMessage))
				return false;
		}
		id = ormasDal.GenerateID();
		date = eDate;
		debitingAccountID = daID;
		value = eValue;
		creditingAccountID = caID;
		ormasDal.StartTransaction(errorMessage);
		Subaccount dSAcc;
		Subaccount cSAcc;
		int dSAccParentID = 0;
		int cSAccParentID = 0;
		if (!dSAcc.GetSubaccountByID(ormasDal, debitingAccountID, errorMessage))
		{
			dSAccParentID = debitingAccountID;
			dSAcc.Clear();
			errorMessage.clear();
		}
		else
		{
			dSAccParentID = dSAcc.GetParentAccountID();
			errorMessage.clear();
		}
		if (!cSAcc.GetSubaccountByID(ormasDal, creditingAccountID, errorMessage))
		{
			cSAccParentID = creditingAccountID;
			cSAcc.Clear();
			errorMessage.clear();
		}
		else
		{
			cSAccParentID = cSAcc.GetParentAccountID();
			errorMessage.clear();
		}
		if (0 != id && ormasDal.CreateEntry(id, date, dSAccParentID, value, cSAccParentID, errorMessage))
		{
			if (DebitAccount(ormasDal, debitingAccountID, value) && CreditAccount(ormasDal, creditingAccountID, value))
			{
				EntrySubaccountRelation debRelation;
				EntrySubaccountRelation credRelation;
				if (!dSAcc.IsEmpty())
				{
					debRelation.SetSubaccountID(debitingAccountID);
					debRelation.SetEntryID(id);
					if (!debRelation.CreateEntrySubaccountRelation(ormasDal, errorMessage))
					{
						return false;
					}
				}
				if (!cSAcc.IsEmpty())
				{
					credRelation.SetSubaccountID(creditingAccountID);
					credRelation.SetEntryID(id);
					if (!credRelation.CreateEntrySubaccountRelation(ormasDal, errorMessage))
					{
						return false;
					}
				}
				ormasDal.CommitTransaction(errorMessage);
				return true;
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.StartTransaction(errorMessage);
		return false;
	}
	bool Entry::CreateEntry(DataLayer::OrmasDal& ormasDal, std::string& errorMessage, bool corrEntry)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		if (corrEntry == false)
		{
			if (!EntryRoutingValidation(ormasDal, debitingAccountID, creditingAccountID, errorMessage))
				return false;
		}
		
		id = ormasDal.GenerateID();
		ormasDal.StartTransaction(errorMessage);
		Subaccount dSAcc;
		Subaccount cSAcc;
		int dSAccParentID = 0;
		int cSAccParentID = 0;
		if (!dSAcc.GetSubaccountByID(ormasDal, debitingAccountID, errorMessage))
		{
			dSAccParentID = debitingAccountID;
			dSAcc.Clear();
			errorMessage.clear();
		}
		else
		{
			dSAccParentID = dSAcc.GetParentAccountID();
			errorMessage.clear();
		}
		if (!cSAcc.GetSubaccountByID(ormasDal, creditingAccountID, errorMessage))
		{
			cSAccParentID = creditingAccountID;
			cSAcc.Clear();
			errorMessage.clear();
		}
		else
		{
			cSAccParentID = cSAcc.GetParentAccountID();
			errorMessage.clear();
		}
		if (0 != id && ormasDal.CreateEntry(id, date, dSAccParentID, value, cSAccParentID, errorMessage))
		{
			if (DebitAccount(ormasDal, debitingAccountID, value) && CreditAccount(ormasDal, creditingAccountID, value))
			{
				EntrySubaccountRelation debRelation;
				EntrySubaccountRelation credRelation;
				debRelation.SetSubaccountID(debitingAccountID);
				debRelation.SetEntryID(id);
				credRelation.SetSubaccountID(creditingAccountID);
				credRelation.SetEntryID(id);
				if (!dSAcc.IsEmpty())
				{
					debRelation.SetSubaccountID(debitingAccountID);
					debRelation.SetEntryID(id);
					if (!debRelation.CreateEntrySubaccountRelation(ormasDal, errorMessage))
					{
						return false;
					}
				}
				if (!cSAcc.IsEmpty())
				{
					credRelation.SetSubaccountID(creditingAccountID);
					credRelation.SetEntryID(id);
					if (!credRelation.CreateEntrySubaccountRelation(ormasDal, errorMessage))
					{
						return false;
					}
				}
				ormasDal.CommitTransaction(errorMessage);
				return true;
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.StartTransaction(errorMessage);
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

	bool Entry::UpdateEntry(DataLayer::OrmasDal &ormasDal, std::string eDate, int daID, double eValue, int caID, 
		std::string& errorMessage, bool corrEntry)
	{
		date = eDate;
		debitingAccountID = daID;
		value = eValue;
		creditingAccountID = caID;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateEntry(id, date, debitingAccountID, value, creditingAccountID, errorMessage))
		{
			ormasDal.CommitTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.StartTransaction(errorMessage);
		return false;
	}
	bool Entry::UpdateEntry(DataLayer::OrmasDal& ormasDal, std::string& errorMessage, bool corrEntry)
	{
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateEntry(id, date, debitingAccountID, value, creditingAccountID, errorMessage))
		{
			ormasDal.CommitTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.StartTransaction(errorMessage);
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
		if (0 == entryVector.size())
		{
			return false;
		}
		errorMessage = "Entry with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Entry::DebitAccount(DataLayer::OrmasDal& ormasDal, int accountID, double value)
	{
		Subaccount subAcc;
		Account dAcc;
		AccountType atype;
		if (dAcc.GetAccountByID(ormasDal, accountID, errorMessage))
		{
			/*if (atype.GetAccountTypeByNumber(ormasDal, dAcc.GetAccountTypeNumber(ormasDal), errorMessage))
			{
				if (0 == atype.GetName().compare("ACTIVE"))
				{
					dAcc.SetCurrentBalance(dAcc.GetCurrentBalance() + value);
				}
				else if (0 == atype.GetName().compare("PASSIVE"))
				{
					dAcc.SetCurrentBalance(dAcc.GetCurrentBalance() - value);
				}
			}*/
			if (dAcc.AccountOperationValidation(ormasDal, dAcc.GetCurrentBalance() + value))
			{
				dAcc.SetCurrentBalance(dAcc.GetCurrentBalance() + value);
				if (dAcc.UpdateAccount(ormasDal, errorMessage))
					return true;
			}
			
		}
		else if(subAcc.GetSubaccountByID(ormasDal, accountID, errorMessage))
		{
			/*if (atype.GetAccountTypeByNumber(ormasDal, dAcc.GetAccountTypeNumber(ormasDal), errorMessage))
			{
			if (0 == atype.GetName().compare("ACTIVE"))
			{
			dAcc.SetCurrentBalance(dAcc.GetCurrentBalance() + value);
			}
			else if (0 == atype.GetName().compare("PASSIVE"))
			{
			dAcc.SetCurrentBalance(dAcc.GetCurrentBalance() - value);
			}
			}*/
			if (dAcc.GetAccountByID(ormasDal, subAcc.GetParentAccountID(), errorMessage))
			{
				if (dAcc.AccountOperationValidation(ormasDal, dAcc.GetCurrentBalance() + value))
				{
					dAcc.SetCurrentBalance(dAcc.GetCurrentBalance() + value);
					subAcc.SetCurrentBalance(subAcc.GetCurrentBalance() + value);
					if (dAcc.UpdateAccount(ormasDal, errorMessage) && subAcc.UpdateSubaccount(ormasDal, errorMessage))
						return true;
				}
			}
		}
		return false;
	}

	bool Entry::CreditAccount(DataLayer::OrmasDal& ormasDal, int accountID, double value)
	{
		Subaccount subAcc;
		Account cAcc;
		AccountType atype;
		if (cAcc.GetAccountByID(ormasDal, accountID, errorMessage))
		{
			/*if (atype.GetAccountTypeByNumber(ormasDal, cAcc.GetAccountTypeNumber(ormasDal), errorMessage))
			{
				if (0 == atype.GetName().compare("ACTIVE"))
				{
					cAcc.SetCurrentBalance(cAcc.GetCurrentBalance() - value);
				}
				else if (0 == atype.GetName().compare("PASSIVE"))
				{
					cAcc.SetCurrentBalance(cAcc.GetCurrentBalance() + value);
				}
			}*/
			if (cAcc.AccountOperationValidation(ormasDal, cAcc.GetCurrentBalance() - value))
			{
				cAcc.SetCurrentBalance(cAcc.GetCurrentBalance() - value);
				if (cAcc.UpdateAccount(ormasDal, errorMessage))
					return true;
			}
		}
		else if (subAcc.GetSubaccountByID(ormasDal, accountID, errorMessage))
		{
			/*if (atype.GetAccountTypeByNumber(ormasDal, cAcc.GetAccountTypeNumber(ormasDal), errorMessage))
			{
			if (0 == atype.GetName().compare("ACTIVE"))
			{
			cAcc.SetCurrentBalance(cAcc.GetCurrentBalance() - value);
			}
			else if (0 == atype.GetName().compare("PASSIVE"))
			{
			cAcc.SetCurrentBalance(cAcc.GetCurrentBalance() + value);
			}
			}*/
			if (cAcc.GetAccountByID(ormasDal, subAcc.GetParentAccountID(), errorMessage))
			{
				if (cAcc.AccountOperationValidation(ormasDal, cAcc.GetCurrentBalance() - value))
				{
					cAcc.SetCurrentBalance(cAcc.GetCurrentBalance() - value);
					subAcc.SetCurrentBalance(subAcc.GetCurrentBalance() - value);
					if (cAcc.UpdateAccount(ormasDal, errorMessage) && subAcc.UpdateSubaccount(ormasDal, errorMessage))
						return true;
				}
			}
		}
		return false;
	}

	bool Entry::EntryRoutingValidation(DataLayer::OrmasDal& ormasDal, int daID, int caID, std::string& errorMessage)
	{
		/*EntryRouting eRouting;
		Account dAcc;
		Account cAcc;
		if (dAcc.GetAccountByID(ormasDal, daID, errorMessage) && cAcc.GetAccountByID(ormasDal, caID, errorMessage))
		{
			return eRouting.CheckEntryRouting(ormasDal, std::stoi(dAcc.GetNumber()), std::stoi(cAcc.GetNumber()), errorMessage);
		}
		return false;*/
		return true;
	}
}
