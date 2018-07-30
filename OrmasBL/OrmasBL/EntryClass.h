#ifndef ENTRYCLASS_H
#define ENTRYCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Entry{
	protected:
		int id = 0;
		std::string date = "";
		int debitingAccountID = 0;
		double value = 0.0;
		int creditingAccountID = 0;
		std::string description = "";
	public:
		Entry();
		Entry(int eID, std::string eDate, int eDebitingAccountID, double eValue, int eCreditingAccountID, std::string eDescription) :
			id(eID), date(eDate), debitingAccountID(eDebitingAccountID), value(eValue), creditingAccountID(eCreditingAccountID),
			description(eDescription){};
		Entry(DataLayer::entriesCollection);
		~Entry(){};

		std::string errorMessage = "";
		//Entry class Entryors
		int GetID();
		std::string GetDate();
		int GetDebitingAccountID();
		double GetValue();
		int GetCreditingAccountID();
		std::string GetDescription();

		//Entry class Mutators
		void SetID(int);
		void SetDate(std::string);
		void SetDebitingAccountID(int);
		void SetValue(double);
		void SetCreditingAccountID(int);
		void SetDescription(std::string);

		// Create, delete and update Entry
		bool CreateEntry(DataLayer::OrmasDal &ormasDal, std::string& errorMessage, bool corrEntry = false);
		bool UpdateEntry(DataLayer::OrmasDal &ormasDal, std::string& errorMessage, bool corrEntry = false);
		bool DeleteEntry(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateEntry(DataLayer::OrmasDal &ormasDal, std::string eDate, int daID, double eValue, int caID, std::string eDescription, std::string& errorMessage, bool corrEntry = false);
		bool UpdateEntry(DataLayer::OrmasDal &ormasDal, std::string eDate, int daID, double eValue, int caID, std::string eDescription, std::string& errorMessage, bool corrEntry = false);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetEntryByID(DataLayer::OrmasDal& ormasDal, int eID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string eDate, int daID, double eValue, int caID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool EntryRoutingValidation(DataLayer::OrmasDal& ormasDal, int daID, int caID, std::string& errorMessage);
		bool DebitAccount(DataLayer::OrmasDal& ormasDal, int accountID, double value);
		bool CreditAccount(DataLayer::OrmasDal& ormasDal, int accountID, double value);
		bool ReCalculateParentAccount(DataLayer::OrmasDal& ormasDal, int dAccID, int cAccID, double value, std::string& errorMessage);
	};
}

#endif //ENTRYCLASS_H