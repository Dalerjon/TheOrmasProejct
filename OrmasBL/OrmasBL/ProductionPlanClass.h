#ifndef PRODUCTIONPLANCLASS_H
#define PRODUCTIONPLANCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class ProductionPlan
	{
	protected:
		int id = 0;
		std::string date = "";
		int employeeID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		ProductionPlan(int pID, std::string pDate, int eID, int pCount, double pSum, int sID, int cID) :
			id(pID), date(pDate), employeeID(eID), count(pCount), sum(pSum), statusID(sID), currencyID(cID){};
		ProductionPlan(DataLayer::productionPlanCollection);
		ProductionPlan(){};
		~ProductionPlan(){};

		//ProductionPlan class Accessors
		int GetID();
		std::string GetDate();
		int GetEmployeeID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//ProductionPlan class Mutators
		void SetID(int);
		void SetDate(std::string);
		void SetEmployeeID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateProductionPlan(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateProductionPlan(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteProductionPlan(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateProductionPlan(DataLayer::OrmasDal& ormasDal, std::string oDate, int eID, int oCount,
			double oSum, int sID, int cID, std::string& errorMessage);
		bool UpdateProductionPlan(DataLayer::OrmasDal& ormasDal, std::string oDate, int eID, int oCount,
			double oSum, int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetProductionPlanByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string oDate, int oCount, double oSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //PRODUCTIONPLANCLASS_H