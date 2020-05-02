#ifndef RECEIPTOTHERSTOCKSCLASS_H
#define RECEIPTOTHERSTOCKSCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class ReceiptOtherStocks
	{
	protected:
		int id = 0;
		int purveyorID = 0;
		std::string date = "";
		std::string executionDate = "";
		int employeeID = 0;
		double count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		ReceiptOtherStocks(int oID, int pID, std::string oDate, std::string oExecDate, int eID, double oCount, double oSum, int sID, int cID) :
			id(oID), purveyorID(pID), date(oDate), executionDate(oExecDate), employeeID(eID), count(oCount), sum(oSum),
			statusID(sID), currencyID(cID){};
		ReceiptOtherStocks(DataLayer::receiptOtherStocksCollection);
		ReceiptOtherStocks(){};
		~ReceiptOtherStocks(){};

		//Consume Product class Accessors
		int GetID();
		int GetPurveyorID();
		std::string GetDate();
		std::string GetExecutionDate();
		int GetEmployeeID();
		double GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//Consume Product class Mutators
		void SetID(int);
		void SetPurveyorID(int);
		void SetDate(std::string);
		void SetExecutionDate(std::string);
		void SetEmployeeID(int);
		void SetCount(double);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateReceiptOtherStocks(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateReceiptOtherStocks(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteReceiptOtherStocks(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateReceiptOtherStocks(DataLayer::OrmasDal& ormasDal, int pID, std::string oDate, std::string oExecDate, int eID,
			double oCount, double oSum, int sID, int cID, std::string& errorMessage);
		bool UpdateReceiptOtherStocks(DataLayer::OrmasDal& ormasDal, int pID, std::string oDate, std::string oExecDate, int eID,
			double oCount, double oSum, int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		std::string GenerateFilterForPeriod(DataLayer::OrmasDal& ormasDal, std::string formDate, std::string toDate);
		bool GetReceiptOtherStocksByID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double previousSum = 0.0;
		int previousStatusID = 0;
		double previousCount = 0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int pID, std::string oDate, int eID, double oCount, double oSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		double GetCurrentSum(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		int GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int rrID, int empID, std::string& errorMessage);
		bool ChangesAtStockReverse(DataLayer::OrmasDal& ormasDal, int rrID, int empID, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int rID, int empID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		double GetCurrentCount(DataLayer::OrmasDal& ormasDal, int rrID, std::string& errorMessage);
		std::map<int, double> GetOtherStocksCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		bool CheckDocumentCorrectness(DataLayer::OrmasDal& ormasDal);
	};
}
#endif //ReceiptOtherStocksCLASS_H