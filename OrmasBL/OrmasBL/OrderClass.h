#ifndef ORDERCLASS_H
#define ORDERCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Order
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
		Order(int oID, int clID, std::string oDate, int eID, int oCount, double oSum, int sID, int cID) :id(oID),
			clientID(clID), date(oDate), employeeID(eID), count(oCount), sum(oSum), statusID(sID), currencyID(cID){};
		Order(DataLayer::ordersCollection);
		Order(){};
		~Order(){};
		
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
		bool CreateOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateOrder(DataLayer::OrmasDal& ormasDal, int clID, std::string oDate, int eID, int oCount, double oSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateOrder(DataLayer::OrmasDal& ormasDal, int clID, std::string oDate, int eID, int oCount, double oSum, 
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetOrderByID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool IsEmpty();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int clID, std::string oDate, int oCount, double oSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //ORDERCLASS_H