#ifndef WRITEOFFCLASS_H
#define WRITEOFFCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class WriteOff
	{
	protected:
		int id = 0;
		int clientID = 0;
		std::string date = "";
		int employeeID = 0;
		double count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		WriteOff(int wID, int clID, std::string wDate, int eID, double wCount, double wSum, int sID, int cID) :id(wID),
			clientID(clID), date(wDate), employeeID(eID), count(wCount), sum(wSum), statusID(sID), currencyID(cID){};
		WriteOff(DataLayer::writeOffsCollection);
		WriteOff(){};
		~WriteOff(){};

		//Order class Accessors
		int GetID();
		int GetClientID();
		std::string GetDate();
		int GetEmployeeID();
		double GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//Order class Mutators
		void SetID(int);
		void SetClientID(int);
		void SetDate(std::string);
		void SetEmployeeID(int);
		void SetCount(double);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateWriteOff(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateWriteOff(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteWriteOff(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateWriteOff(DataLayer::OrmasDal& ormasDal, int clID, std::string wDate, int eID, double wCount, double wSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateWriteOff(DataLayer::OrmasDal& ormasDal, int clID, std::string wDate, int eID, double wCount, double wSum,
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetWriteOffByID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double prevSum = 0;
		double prevCount = 0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int clID, std::string wDate, double wCount, double wSum,
			 int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int wID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		double GetCurrentSum(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		double GetCurrentCount(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		std::map<int, double> GetProductCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
	};
}
#endif //WRITEOFFCLASS_H