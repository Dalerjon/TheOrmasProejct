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
		double count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		ConsumeProduct(int cpID, int eID, std::string cpDate, std::string cpExecDate, int seID, double cpCount, double cpSum, int sID, int cID) :
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
		bool CreateConsumeProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateConsumeProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteConsumeProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateConsumeProduct(DataLayer::OrmasDal& ormasDal, int eID, std::string cpDate, std::string cpExecDate, int seID,
			double cpCount, double cpSum, int sID, int cID, std::string& errorMessage);
		bool UpdateConsumeProduct(DataLayer::OrmasDal& ormasDal, int eID, std::string cpDate, std::string cpExecDate, int seID, 
			double cpCount, double cpSum, int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		std::string GenerateINFilterForStockEmployee(DataLayer::OrmasDal& ormasDal, std::vector<int> sEmpIDList);
		std::string GenerateFilterForPeriod(DataLayer::OrmasDal& ormasDal, std::string formDate, std::string toDate);
		bool GetConsumeProductByID(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double prevSum = 0;
		double prevCount = 0;
		int previousStatusID = 0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string cpDate, int seID, double cpCount, double cpSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int cpID, int stockEmpID, std::string& errorMessage);
		bool ChangesAtStockReverse(DataLayer::OrmasDal& ormasDal, int cpID, int stockEmpID, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int cpID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangesAtTransport(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		bool ChangesAtTransport(DataLayer::OrmasDal& ormasDal, int cpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangesAtTransportReverse(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		double GetCurrentSum(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		double GetCurrentCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		int GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		std::map<int, double> GetProductCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		bool CheckDocumentCorrectness(DataLayer::OrmasDal& ormasDal);
	};
}
#endif //CONSUMEPRODUCTCLASS_H