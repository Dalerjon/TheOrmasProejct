#ifndef ORDERRAWCLASS_H
#define ORDERRAWCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class OrderRaw
	{
	protected:
		int id = 0;
		int employeeID = 0;
		std::string date = "";
		std::string executionDate = "";
		int stockEmployeeID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		OrderRaw(int oID, int eID, std::string oDate, std::string oExecDate, int seID, int oCount, double oSum, int sID, int cID) :
			id(oID), employeeID(eID), date(oDate), executionDate(oExecDate), stockEmployeeID(seID), count(oCount), sum(oSum),
			statusID(sID), currencyID(cID){};
		OrderRaw(DataLayer::orderRawsCollection);
		OrderRaw(){};
		~OrderRaw(){};

		//Consume Product class Accessors
		int GetID();
		int GetEmployeeID();
		std::string GetDate();
		std::string GetExecutionDate();
		int GetStockEmployeeID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//Consume Product class Mutators
		void SetID(int);
		void SetEmployeeID(int);
		void SetDate(std::string);
		void SetExecutionDate(std::string);
		void SetStockEmployeeID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateOrderRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateOrderRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteOrderRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateOrderRaw(DataLayer::OrmasDal& ormasDal, int eID, std::string oDate, std::string oExecDate, int seID,
			int oCount, double oSum, int sID, int cID, std::string& errorMessage);
		bool UpdateOrderRaw(DataLayer::OrmasDal& ormasDal, int eID, std::string oDate, std::string oExecDate, int seID, 
			int oCount, double oSum, int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetOrderRawByID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string oDate, int seID, int oCount, double oSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //OrderRawCLASS_H