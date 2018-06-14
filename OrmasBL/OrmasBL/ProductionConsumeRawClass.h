#ifndef PRODUCTIONCONSUMERAWCLASS_H
#define PRODUCTIONCONSUMERAWCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class ProductionConsumeRaw
	{
	protected:
		int id = 0;
		int employeeID = 0;
		std::string date = "";
		std::string executionDate = "";
		int stockEmployeeID = 0;
		double count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		ProductionConsumeRaw(int crID, int eID, std::string crDate, std::string crExecDate, int seID, double crCount, double crSum, int sID, int cID) :
			id(crID), employeeID(eID), date(crDate), executionDate(crExecDate), stockEmployeeID(seID), count(crCount), sum(crSum),
			statusID(sID), currencyID(cID){};
		ProductionConsumeRaw(DataLayer::productionConsumeRawsCollection);
		ProductionConsumeRaw(){};
		~ProductionConsumeRaw(){};

		//Consume Product class Accessors
		int GetID();
		int GetEmployeeID();
		std::string GetDate();
		std::string GetExecutionDate();
		int GetStockEmployeeID();
		double GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//Consume Product class Mutators
		void SetID(int);
		void SetEmployeeID(int);
		void SetDate(std::string);
		void SetExecutionDate(std::string);
		void SetStockEmployeeID(int);
		void SetCount(double);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateProductionConsumeRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateProductionConsumeRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteProductionConsumeRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateProductionConsumeRaw(DataLayer::OrmasDal& ormasDal, int eID, std::string crDate, std::string crExecDate, int seID,
			double crCount, double crSum, int sID, int cID, std::string& errorMessage);
		bool UpdateProductionConsumeRaw(DataLayer::OrmasDal& ormasDal, int eID, std::string crDate, std::string crExecDate, int seID, 
			double crCount, double crSum, int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetProductionConsumeRawByID(DataLayer::OrmasDal& ormasDal, int crID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double prevSum = 0;
		double prevCount = 0;
		int previousStatusID = 0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string crDate, int seID, double crCount, double crSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool ChangesAtProdStock(DataLayer::OrmasDal& ormasDal, int crID, std::string& errorMessage);
		bool ChangesAtProdStock(DataLayer::OrmasDal& ormasDal, int cpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		double GetCurrentSum(DataLayer::OrmasDal& ormasDal, int crID, std::string& errorMessage);
		double GetCurrentCount(DataLayer::OrmasDal& ormasDal, int crID, std::string& errorMessage);
		int GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		std::map<int, double> GetProductCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
	};
}
#endif //ProductionConsumeRawCLASS_H