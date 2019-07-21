#ifndef RECEIPTPRODUCTCLASS_H
#define RECEIPTPRODUCTCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class ReceiptProduct
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
		ReceiptProduct(int rpID, int eID, std::string rpDate, std::string rpExecDate, int seID, double rpCount, double rpSum, int sID, int cID) :
			id(rpID), employeeID(eID), date(rpDate), executionDate(rpExecDate), stockEmployeeID(seID), count(rpCount), sum(rpSum),
			statusID(sID), currencyID(cID){};
		ReceiptProduct(DataLayer::receiptProductsCollection);
		ReceiptProduct(){};
		~ReceiptProduct(){};

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
		bool CreateReceiptProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateReceiptProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteReceiptProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateReceiptProduct(DataLayer::OrmasDal& ormasDal, int eID, std::string rpDate, std::string rpExecDate, int seID,
			double rpCount, double rpSum, int sID, int cID, std::string& errorMessage);
		bool UpdateReceiptProduct(DataLayer::OrmasDal& ormasDal, int eID, std::string rpDate, std::string rpExecDate, int seID, 
			double rpCount, double rpSum, int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetReceiptProductByID(DataLayer::OrmasDal& ormasDal, int rpID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double prevSum = 0;
		double prevCount = 0;
		int previousStatusID = 0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string rpDate, int seID, double rpCount, double rpSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int rpID, int empID, int stockEmpID, std::string& errorMessage);
		bool ChangesAtStockCancel(DataLayer::OrmasDal& ormasDal, int rpID, int empID, int stockEmpID, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int rpID, int empID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		//bool ChangesAtProdStock(DataLayer::OrmasDal& ormasDal, int crID, std::string& errorMessage);
		//bool ChangesAtProdStock(DataLayer::OrmasDal& ormasDal, int crID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		double GetCurrentSum(DataLayer::OrmasDal& ormasDal, int rpID, std::string& errorMessage);
		double GetCurrentCount(DataLayer::OrmasDal& ormasDal, int rpID, std::string& errorMessage);
		int GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		std::map<int, double> GetProductCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
	};
}
#endif //RECEIPTPRODUCTCLASS_H