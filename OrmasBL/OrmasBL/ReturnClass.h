#ifndef RETURNCLASS_H
#define RETURNCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class Return
	{
	protected:
		int id = 0;
		int clientID = 0;
		std::string date = "";
		std::string executionDate = "";
		int employeeID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		Return(int rID, int clID, std::string rDate, std::string rExecDate, int eID, int oCount, double oSum, int sID, int cID) :
			id(rID), clientID(clID), date(rDate), executionDate(rExecDate), employeeID(eID), count(oCount), sum(oSum), statusID(sID),
			currencyID(cID){};
		Return(DataLayer::returnsCollection);
		Return(){};
		~Return(){};
		
		//Return class Accessors
		int GetID();
		int GetClientID();
		std::string GetDate();
		std::string GetExecutionDate();
		int GetEmployeeID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();
		
		//Please implement Mutators
		void SetID(int);
		void SetClientID(int);
		void SetDate(std::string);
		void SetExecutionDate(std::string);
		void SetEmployeeID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);
		
		//Create, delete, update methods
		bool CreateReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateReturn(DataLayer::OrmasDal& ormasDal, int clID, std::string rDate, std::string rExecDate, int eID, int rCount, 
			double rSum, int sID, int cID, std::string& errorMessage);
		bool UpdateReturn(DataLayer::OrmasDal& ormasDal, int clID, std::string rDate, std::string rExecDate, int eID, int rCount, 
			double rSum, int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetReturnByID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double previousSum = 0.0;
		double previousCount = 0.0;
		double previousStatusID = 0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int clID, std::string oDate,  int oCount, double oSum,
			 int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool BalanceRefund(DataLayer::OrmasDal& ormasDal, int clID, double rSum, int cID, std::string rExecDate, std::string& errorMessage);
		bool BalanceRefund(DataLayer::OrmasDal& ormasDal, int clID, double rSum, double prevSum, int cID, std::string rExecDate, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int cpID, double pSum, double pCount, std::string& errorMessage);
		double GetCurrentSum(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage);
		double GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage);
		int GetCurrentCount(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage);
	};
}
#endif //RETURNCLASS_H