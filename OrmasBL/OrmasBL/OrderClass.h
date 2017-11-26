#ifndef ORDERCLASS_H
#define ORDERCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class Order
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
		Order(int oID, int clID, std::string oDate, std::string oExecDate, int eID, int oCount, double oSum, int sID, int cID) :
			id(oID), clientID(clID), date(oDate), executionDate(oExecDate), employeeID(eID), count(oCount), sum(oSum), 
			statusID(sID), currencyID(cID){};
		Order(DataLayer::ordersCollection);
		Order(){};
		~Order(){};
		
		//Order class Accessors
		int GetID();
		int GetClientID();
		std::string GetDate();
		std::string GetExecutionDate();
		int GetEmployeeID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//Order class Mutators
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
		bool CreateOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateOrder(DataLayer::OrmasDal& ormasDal, int clID, std::string oDate, std::string oExecDate, int eID, int oCount, 
			double oSum, int sID, int cID, std::string& errorMessage);
		bool UpdateOrder(DataLayer::OrmasDal& ormasDal, int clID, std::string oDate, std::string oExecDate, int eID, int oCount, 
			double oSum, int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal, std::string formDate, std::string toDate = "");
		bool GetOrderByID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double previousSum = 0.0;
		double previousStatusID = 0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int clID, std::string oDate, int oCount, double oSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool BalanceWithdrawal(DataLayer::OrmasDal& ormasDal, int clID, double oSum, int cID, std::string oExecDate, std::string& errorMessage);
		bool BalanceWithdrawal(DataLayer::OrmasDal& ormasDal, int clID, double oSum, double prevSum, int cID, std::string oExecDate, std::string& errorMessage);
		double GetCurrentSum(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		double GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
	};
}
#endif //ORDERCLASS_H