#ifndef CAHSBOXEMPLOYEERELATIONCLASS_H
#define CAHSBOXEMPLOYEERELATIONCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class CashboxEmployeeRelation
	{
	protected:
		int id = 0;
		int cashboxID = 0;
		int employeeID = 0;
	public:
		CashboxEmployeeRelation();
		CashboxEmployeeRelation(int ceID, int cID, int aID) :id(ceID), cashboxID(cID), employeeID(aID){};
		CashboxEmployeeRelation(DataLayer::cashboxEmployeeCollection);
		~CashboxEmployeeRelation(){};

		std::string errorMessage = "";
		//Cashbox-Employee relation class Accessors
		int GetID();
		int GetCashboxID();
		int GetEmployeeID();

		//Cashbox-Employee relation  class Mutators
		void SetID(int);
		void SetCashboxID(int);
		void SetEmployeeID(int);

		// Create, delete  Cashbox-Employee relation
		bool CreateCashboxEmployeeRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteCashboxEmployeeRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateCashboxEmployeeRelation(DataLayer::OrmasDal &ormasDal, int cID, int eID, std::string& errorMessage);
		bool UpdateCashboxEmployeeRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateCashboxEmployeeRelation(DataLayer::OrmasDal &ormasDal, int cID, int eID, std::string& errorMessage);


		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetCashboxEmployeeByID(DataLayer::OrmasDal& ormasDal, int id, std::string& errorMessage);
		bool GetCashboxEmployeeByEmployeeID(DataLayer::OrmasDal& ormasDal, int eID, std::string& errorMessage);
		int GetCashboxIDByEmployeeID(DataLayer::OrmasDal& ormasDal, int eID, std::string& errorMessage);
		int GetEmployeeIDByCashboxID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int cID, int aID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif