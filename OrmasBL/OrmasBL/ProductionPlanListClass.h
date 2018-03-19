#ifndef PRODUCTIONPLANLISTCLASS_H
#define PRODUCTIONPLANLISTCLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer
{
	class ProductionPlanList
	{
	protected:
		int id = 0;
		int productionPlanID = 0;
		int productID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		ProductionPlanList(int pplID, int ppID, int pID, int pplCount, double pplSum, int sID, int cID) :id(pplID),
			productionPlanID(ppID), productID(pID), count(pplCount), sum(pplSum), statusID(sID), currencyID(cID){};
		ProductionPlanList(DataLayer::productionPlanListCollection);
		ProductionPlanList(){};
		~ProductionPlanList(){};

		//ProductionPlanList class Accessors
		int GetID();
		int GetProductionPlanID();
		int GetProductID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//ProductionPlanList class Mutators
		void SetID(int);
		void SetProductionPlanID(int);
		void SetProductID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateProductionPlanList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateProductionPlanList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteProductionPlanList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteListByProductionPlanID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool CreateProductionPlanList(DataLayer::OrmasDal& ormasDal, int ppID, int pID, int pplCount, double pplSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateProductionPlanList(DataLayer::OrmasDal& ormasDal, int ppID, int pID, int pplCount, double pplSum,
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetProductionPlanListByID(DataLayer::OrmasDal& ormasDal, int ppID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int ppID, int pID, int pplCount, double pplSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif