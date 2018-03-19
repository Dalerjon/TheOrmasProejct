#ifndef ACCOUNTCLASS_H
#define ACCOUNTCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Account{
	protected:
		int id = 0;
		std::string number = "";
		double startBalance = 0.0;
		double currentBalance = 0.0;
		int currencyID = 0;		
		int statusID = 0;
		std::string openedDate = "";
		std::string closedDate = "";
		std::string details = "";
	public:
		Account();
		Account(int aID, std::string aNumber, double aStartBalance, double aCurrentBalance, int cID, int sID, std::string aOpenedDate,
			std::string aClosedDate, std::string aDetails) :id(aID), number(aNumber), startBalance(aStartBalance),
			currentBalance(aCurrentBalance), currencyID(cID), statusID(sID), openedDate(aOpenedDate), closedDate(aClosedDate), 
			details(aDetails){};
		Account(DataLayer::accountsCollection);
		~Account(){};

		std::string errorMessage = "";

		//Account class Accessors
		int GetID();
		std::string GetNumber();
		double GetStartBalance();
		double GetCurrentBalance();
		int GetCurrencyID();
		int GetStatusID();
		std::string GetOpenedDate();
		std::string GetClosedDate();
		std::string GetDetails();
		std::string GetName(DataLayer::OrmasDal& ormasDal);

		//Account class Mutators
		void SetID(int);
		void SetNumber(std::string);
		void SetStartBalance(double);
		void SetCurrentBalance(double);
		void SetCurrencyID(int);
		void SetStatusID(int);
		void SetOpenedDate(std::string);
		void SetClosedDate(std::string);
		void SetDetails(std::string);

		// Create, delete and update Account
		bool CreateAccount(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateAccount(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteAccount(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateAccount(DataLayer::OrmasDal &ormasDal, std::string aNumber, double aStartBalance, double aCurrentBalance, int cID,
			int sID, std::string aOpenedDate, std::string aClosedDate, std::string aDetails, std::string& errorMessage);
		bool UpdateAccount(DataLayer::OrmasDal &ormasDal, std::string aNumber, double aStartBalance, double aCurrentBalance, int cID,
			int sID, std::string aOpenedDate, std::string aClosedDate, std::string aDetails, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetAccountByID(DataLayer::OrmasDal& ormasDal, int aID, std::string& errorMessage);
		bool GetAccountByNumber(DataLayer::OrmasDal& ormasDal, std::string aNumber, std::string& errorMessage);
		std::string GenerateRawNumber(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string aNumber, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //ACCOUNTCLASS_H