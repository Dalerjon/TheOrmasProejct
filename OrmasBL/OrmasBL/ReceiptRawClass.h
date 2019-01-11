#ifndef RECEIPTRAWCLASS_H
#define RECEIPTRAWCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class ReceiptRaw
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
		ReceiptRaw(int rID, int eID, std::string rDate, std::string rExecDate, int seID, double rCount, double rSum, int sID, int cID) :
			id(rID), employeeID(eID), date(rDate), executionDate(rExecDate), stockEmployeeID(seID), count(rCount), sum(rSum),
			statusID(sID), currencyID(cID){};
		ReceiptRaw(DataLayer::receiptRawsCollection);
		ReceiptRaw(){};
		~ReceiptRaw(){};

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
		bool CreateReceiptRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateReceiptRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteReceiptRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateReceiptRaw(DataLayer::OrmasDal& ormasDal, int eID, std::string rDate, std::string rExecDate, int seID,
			double rCount, double rSum, int sID, int cID, std::string& errorMessage);
		bool UpdateReceiptRaw(DataLayer::OrmasDal& ormasDal, int eID, std::string rDate, std::string rExecDate, int seID, 
			double rCount, double rSum, int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetReceiptRawByID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double prevSum = 0;
		double prevCount = 0;
		int previousStatusID = 0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string rDate, int seID, double rCount, double rSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int rrID, int empID, int stockEmpID, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int rID, int empID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		double GetCurrentSum(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage);
		double GetCurrentCount(DataLayer::OrmasDal& ormasDal, int rrID, std::string& errorMessage);
		int GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		std::map<int, double> GetProductCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
	};
}
#endif //ReceiptRawCLASS_H