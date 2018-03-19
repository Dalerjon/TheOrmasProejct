#ifndef ACCOUNTENTRYRELATIONCLASS_H
#define SCCOUNTENTRYRELATIONCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class AccountEntryRelation
	{
	protected:
		int accountID = 0;
		int entryID = 0;
	public:
		AccountEntryRelation();
		AccountEntryRelation(int aID, int eID) : accountID(aID), entryID(eID){};
		AccountEntryRelation(DataLayer::accountEntryCollection);
		~AccountEntryRelation(){};

		std::string errorMessage = "";
		//Access class Accessors
		int GetAccountID();
		int GetEntryID();

		//Access class Mutators
		void SetAccountID(int);
		void SetEntryID(int);

		// Create, delete and update Access
		bool CreateAccountEntryRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteAccountEntryRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateAccountEntryRelation(DataLayer::OrmasDal &ormasDal, int aID, int eID, std::string& errorMessage);


		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		std::vector<int> GetAllAccountByEntryID(DataLayer::OrmasDal& ormasDal, int eID, std::string& errorMessage);
		std::vector<int> GetAllEntryByAccountID(DataLayer::OrmasDal& ormasDal, int aID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int aID, int eID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif