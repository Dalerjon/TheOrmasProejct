#ifndef WRITEOFFCLASS_H
#define WRITEOFFCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class WriteOff
	{
	protected:
		int id = 0;
		int clientID = 0;
		std::string date = "";
		int employeeID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		WriteOff(int wID, int clID, std::string wDate, int eID, int wCount, double wSum, int sID, int cID) :id(wID),
			clientID(clID), date(wDate), employeeID(eID), count(wCount), sum(wSum), statusID(sID), currencyID(cID){};
		WriteOff(DataLayer::writeOffsCollection);
		WriteOff(){};
		~WriteOff(){};

		//Order class Accessors
		int GetID();
		int GetClientID();
		std::string GetDate();
		int GetEmployeeID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//Order class Mutators
		void SetID(int);
		void SetClientID(int);
		void SetDate(std::string);
		void SetEmployeeID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateWriteOff(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateWriteOff(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteWriteOff(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateWriteOff(DataLayer::OrmasDal& ormasDal, int clID, std::string wDate, int eID, int wCount, double wSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateWriteOff(DataLayer::OrmasDal& ormasDal, int clID, std::string wDate, int eID, int wCount, double wSum,
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetWriteOffByID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double prevSum = 0;
		int prevCount = 0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int clID, std::string wDate, int wCount, double wSum,
			 int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int wID, double pSum, int pCount, std::string& errorMessage);
		double GetCurrentSum(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		int GetCurrentCount(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
	};
}
#endif //WRITEOFFCLASS_H