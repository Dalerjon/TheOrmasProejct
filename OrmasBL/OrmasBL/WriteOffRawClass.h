#ifndef WRITEOFFRAWCLASS_H
#define WRITEOFFRAWCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class WriteOffRaw
	{
	protected:
		int id = 0;
		int employeeID = 0;
		std::string date = "";
		int stockEmployeeID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		WriteOffRaw(int wID, int eID, std::string wDate, int seID, int wCount, double wSum, int sID, int cID) :
			id(wID), employeeID(eID), date(wDate), stockEmployeeID(seID), count(wCount), sum(wSum),
			statusID(sID), currencyID(cID){};
		WriteOffRaw(DataLayer::writeOffRawsCollection);
		WriteOffRaw(){};
		~WriteOffRaw(){};

		//Consume Product class Accessors
		int GetID();
		int GetEmployeeID();
		std::string GetDate();
		int GetStockEmployeeID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//Consume Product class Mutators
		void SetID(int);
		void SetEmployeeID(int);
		void SetDate(std::string);
		void SetStockEmployeeID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateWriteOffRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateWriteOffRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteWriteOffRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateWriteOffRaw(DataLayer::OrmasDal& ormasDal, int eID, std::string wDate, int seID,
			int wCount, double wSum, int sID, int cID, std::string& errorMessage);
		bool UpdateWriteOffRaw(DataLayer::OrmasDal& ormasDal, int eID, std::string wDate, int seID, 
			int wCount, double wSum, int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetWriteOffRawByID(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double prevSum = 0;
		int prevCount = 0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string wDate, int seID, int wCount, double wSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int wID, double pSum, int pCount, std::string& errorMessage);
		double GetCurrentSum(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		int GetCurrentCount(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
	};
}
#endif //WRITEOFFRAWCLASS_H