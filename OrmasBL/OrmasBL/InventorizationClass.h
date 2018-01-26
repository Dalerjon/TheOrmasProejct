#ifndef INVENTORIZATIONCLASS_H
#define INVENTORIZATIONCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class Inventorization
	{
	protected:
		int id = 0;
		int employeeID = 0;
		std::string date = "";
		std::string executionDate = "";
		int stockEmployeeID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		Inventorization(int iID, int eID, std::string iDate, std::string iExecDate, int seID, int iCount, double iSum, int sID, int cID) :
			id(iID), employeeID(eID), date(iDate), executionDate(iExecDate), stockEmployeeID(seID), count(iCount), sum(iSum),
			statusID(sID), currencyID(cID){};
		Inventorization(DataLayer::inventorizationsCollection);
		Inventorization(){};
		~Inventorization(){};

		//Consume Product class Accessors
		int GetID();
		int GetEmployeeID();
		std::string GetDate();
		std::string GetExecutionDate();
		int GetStockEmployeeID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//Consume Product class Mutators
		void SetID(int);
		void SetEmployeeID(int);
		void SetDate(std::string);
		void SetExecutionDate(std::string);
		void SetStockEmployeeID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateInventorization(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateInventorization(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteInventorization(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateInventorization(DataLayer::OrmasDal& ormasDal, int eID, std::string iDate, std::string iExecDate, int seID,
			int iCount, double iSum, int sID, int cID, std::string& errorMessage);
		bool UpdateInventorization(DataLayer::OrmasDal& ormasDal, int eID, std::string iDate, std::string iExecDate, int seID, 
			int iCount, double iSum, int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetInventorizationByID(DataLayer::OrmasDal& ormasDal, int iID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string iDate, int seID, int iCount, double iSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //InventorizationCLASS_H