#ifndef STOCKCLASS_H
#define STOCKCLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Stock
	{
	protected:
		int id = 0;
		int productID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		Stock(int sID, int pID, int sCount, double sSum, int stsID, int cID) :id(sID),
			productID(pID),	count(sCount), sum(sSum), statusID(sID), currencyID(cID){};
		Stock(DataLayer::stockCollection);
		Stock(){};
		~Stock(){};

		//Stock class Accessors
		int GetID();
		int GetProductID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//Stock class Mutators
		void SetID(int);
		void SetProductID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateStock(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateStock(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteStock(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateStock(DataLayer::OrmasDal& ormasDal, int pID, int sCount, double sSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateStock(DataLayer::OrmasDal& ormasDal, int pID, int sCount, double sSum,
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetStockByID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage);
		bool GetStockByProductID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();

		bool ChangingByConsumeProduct(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		bool ChangingByConsumeProduct(DataLayer::OrmasDal& ormasDal, int cpID, double pSum, int pCount, std::string& errorMessage);
		bool ChangingByConsumeRaw(DataLayer::OrmasDal& ormasDal, int crID, std::string& errorMessage);
		bool ChangingByConsumeRaw(DataLayer::OrmasDal& ormasDal, int crID, double pSum, int pCount, std::string& errorMessage);
		bool ChangingByReceiptProduct(DataLayer::OrmasDal& ormasDal, int rpID, std::string& errorMessage);
		bool ChangingByReceiptProduct(DataLayer::OrmasDal& ormasDal, int rpID, double pSum, int pCount, std::string& errorMessage);
		bool ChangingByReceiptRaw(DataLayer::OrmasDal& ormasDal, int rrID, std::string& errorMessage);
		bool ChangingByReceiptRaw(DataLayer::OrmasDal& ormasDal, int rrID, double pSum, int pCount, std::string& errorMessage);
		bool ChangingByWriteOff(DataLayer::OrmasDal& ormasDal, int wpID, std::string& errorMessage);
		bool ChangingByWriteOff(DataLayer::OrmasDal& ormasDal, int wpID, double pSum, int pCount, std::string& errorMessage);
		bool ChangingByWriteOffRaw(DataLayer::OrmasDal& ormasDal, int wrID, std::string& errorMessage);
		bool ChangingByWriteOffRaw(DataLayer::OrmasDal& ormasDal, int wrID, double pSum, int pCount, std::string& errorMessage);
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif