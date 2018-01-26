#ifndef CONSUMEPRODUCTCLASS_H
#define CONSUMEPRODUCTCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class ConsumeProduct
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
		ConsumeProduct(int cpID, int eID, std::string cpDate, std::string cpExecDate, int seID, int cpCount, double cpSum, int sID, int cID) :
			id(cpID), employeeID(eID), date(cpDate), executionDate(cpExecDate), stockEmployeeID(seID), count(cpCount), sum(cpSum),
			statusID(sID), currencyID(cID){};
		ConsumeProduct(DataLayer::consumeProductsCollection);
		ConsumeProduct(){};
		~ConsumeProduct(){};

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
		bool CreateConsumeProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateConsumeProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteConsumeProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateConsumeProduct(DataLayer::OrmasDal& ormasDal, int eID, std::string cpDate, std::string cpExecDate, int seID,
			int cpCount, double cpSum, int sID, int cID, std::string& errorMessage);
		bool UpdateConsumeProduct(DataLayer::OrmasDal& ormasDal, int eID, std::string cpDate, std::string cpExecDate, int seID, 
			int cpCount, double cpSum, int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetConsumeProductByID(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double prevSum = 0;
		int prevCount = 0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string cpDate, int seID, int cpCount, double cpSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int cpID, double pSum, int pCount, std::string& errorMessage);
		double GetCurrentSum(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		int GetCurrentCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
	};
}
#endif //CONSUMEPRODUCTCLASS_H