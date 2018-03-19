#ifndef CHARTOFACCOUNTSCLASS_H
#define CHARTOFACCOUNTSCLASS_H

#include "OrmasDAL.h"
namespace BusinessLayer
{
	class ChartOfAccounts
	{
	protected:
		int id = 0;
		int number = 0;
		std::string name = "";
		int accountTypeID = 0;
	public:
		ChartOfAccounts(){};
		ChartOfAccounts(int cID, int cNumber, std::string cName, int cAccountTypeID) :id(cID),
			number(cNumber), name(cName),  accountTypeID(cAccountTypeID){};
		ChartOfAccounts(DataLayer::chartOfAccountsCollection);
		~ChartOfAccounts(){};

		//ChartOfAccounts class Accessors
		int GetID();
		int GetNumber();
		std::string GetName();
		int GetAccountTypeID();
		

		//ChartOfAccounts class Mutators
		void SetID(int);
		void SetNumber(int);
		void SetName(std::string);
		void SetAccountTypeID(int);

		//Create, delete and update methods 
		bool CreateChartOfAccounts(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateChartOfAccounts(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteChartOfAccounts(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateChartOfAccounts(DataLayer::OrmasDal& ormasDal, int cNumber, std::string cName, int cAccountTypeID, std::string& errorMessage);
		bool UpdateChartOfAccounts(DataLayer::OrmasDal& ormasDal, int cNumber, std::string cName, int cAccountTypeID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetChartOfAccountsByID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage);
		bool GetChartOfAccountsByNumber(DataLayer::OrmasDal& ormasDal, int cNumber, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		void TrimStrings(std::string&);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int cNumber, std::string cName, int cAccountTypeID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //ChartOfAccountsCLASS_H