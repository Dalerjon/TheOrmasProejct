#ifndef SUBACCOUNTCLASS_H
#define SUBACCOUNTCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Subaccount{
	protected:
		int id = 0;
		int parentSubaccountID = 0;
		std::string number = "";
		double startBalance = 0.0;
		double currentBalance = 0.0;
		int currencyID = 0;		
		int statusID = 0;
		std::string openedDate = "";
		std::string closedDate = "";
		std::string details = "";
	public:
		Subaccount();
		Subaccount(int aID, int paID, std::string aNumber, double aStartBalance, double aCurrentBalance, int cID, int sID, std::string aOpenedDate,
			std::string aClosedDate, std::string aDetails) :id(aID), parentSubaccountID(paID), number(aNumber), startBalance(aStartBalance),
			currentBalance(aCurrentBalance), currencyID(cID), statusID(sID), openedDate(aOpenedDate), closedDate(aClosedDate), 
			details(aDetails){};
		Subaccount(DataLayer::subaccountsCollection);
		~Subaccount(){};

		std::string errorMessage = "";

		//Subaccount class Accessors
		int GetID();
		int GetParentAccountID();
		std::string GetNumber();
		double GetStartBalance();
		double GetCurrentBalance();
		int GetCurrencyID();
		int GetStatusID();
		std::string GetOpenedDate();
		std::string GetClosedDate();
		std::string GetDetails();

		//Subaccount class Mutators
		void SetID(int);
		void SetParentAccountID(int);
		void SetNumber(std::string);
		void SetStartBalance(double);
		void SetCurrentBalance(double);
		void SetCurrencyID(int);
		void SetStatusID(int);
		void SetOpenedDate(std::string);
		void SetClosedDate(std::string);
		void SetDetails(std::string);

		// Create, delete and update Subaccount
		bool CreateSubaccount(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateSubaccount(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteSubaccount(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateSubaccount(DataLayer::OrmasDal &ormasDal, int paID, std::string aNumber, double aStartBalance, double aCurrentBalance, int cID,
			int sID, std::string aOpenedDate, std::string aClosedDate, std::string aDetails, std::string& errorMessage);
		bool UpdateSubaccount(DataLayer::OrmasDal &ormasDal, int paID, std::string aNumber, double aStartBalance, double aCurrentBalance, int cID,
			int sID, std::string aOpenedDate, std::string aClosedDate, std::string aDetails, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetSubaccountByID(DataLayer::OrmasDal& ormasDal, int aID, std::string& errorMessage);
		bool GetSubaccountByNumber(DataLayer::OrmasDal& ormasDal, std::string aNumber, std::string& errorMessage);
		std::string GenerateRawNumber(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		std::string GetName(DataLayer::OrmasDal& ormasDal);
		std::string GetSubaccountParentNumber(DataLayer::OrmasDal& ormasDal);
		int GetSubaccountTypeNumber(DataLayer::OrmasDal& ormasDal);
		bool SubaccountOperationValidation(DataLayer::OrmasDal& ormasDal, double aValue);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string aNumber, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //SUBACCOUNTCLASS_H