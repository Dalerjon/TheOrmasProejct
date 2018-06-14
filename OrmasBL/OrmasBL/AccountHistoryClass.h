#ifndef ACCOUNTHISTORYCLASS_H
#define ACCOUNTHISTORYCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class AccountHistory{
	protected:
		int id = 0;
		int accountID = 0;
		std::string number = "";
		double startBalance = 0.0;
		double currentBalance = 0.0;
		std::string fromDate = "";
		std::string tillDate = "";
	public:
		AccountHistory();
		AccountHistory(int ahID, int aID, std::string aNumber, double aStartBalance, double aCurrentBalance, std::string aFromDate,
			std::string aTillDate) :id(ahID), accountID(aID), number(aNumber), startBalance(aStartBalance),
			currentBalance(aCurrentBalance), fromDate(aFromDate), tillDate(aTillDate){};
		AccountHistory(DataLayer::accountHistoryCollection);
		~AccountHistory(){};

		std::string errorMessage = "";

		//AccountHistory class Accessors
		int GetID();
		int GetAccountID();
		std::string GetNumber();
		double GetStartBalance();
		double GetCurrentBalance();
		std::string GetFromDate();
		std::string GetTillDate();

		//AccountHistory class Mutators
		void SetID(int);
		void SetAccountID(int);
		void SetNumber(std::string);
		void SetStartBalance(double);
		void SetCurrentBalance(double);
		void SetFromDate(std::string);
		void SetTillDate(std::string);

		// Create, delete and update AccountHistory
		bool CreateAccountHistory(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateAccountHistory(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteAccountHistory(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateAccountHistory(DataLayer::OrmasDal &ormasDal, int aID, std::string aNumber, double aStartBalance, 
			double aCurrentBalance, std::string aFromDate, std::string aTillDate, std::string& errorMessage);
		bool UpdateAccountHistory(DataLayer::OrmasDal &ormasDal, int aID, std::string aNumber, double aStartBalance,
			double aCurrentBalance, std::string aFromDate, std::string aTillDate, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetAccountHistoryByID(DataLayer::OrmasDal& ormasDal, int ahID, std::string& errorMessage);
		bool GetAccountHistoryByAccountID(DataLayer::OrmasDal& ormasDal, int aAccountID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int aID, std::string aFromDate, std::string aTillDate, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //ACCOUNTHISTORYCLASS_H