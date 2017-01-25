#ifndef ORDERCLASS_H
#define ORDERCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Order
	{
	protected:
		int id = 0;
		int userID = 0;
		std::string date = "";
		int workerID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		Order(int oID, int uID, std::string oDate, int wID, int oCount, double oSum, int sID, int cID) :id(oID),
			userID(uID), date(oDate), workerID(wID), count(oCount), sum(oSum), statusID(sID), currencyID(cID){};
		Order(DataLayer::ordersCollection);
		Order(){};
		~Order(){};
		
		//Order class Accessors
		int GetID();
		int GetUserID();
		std::string GetDate();
		int GetWorkerID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//Order class Mutators
		void SetID(int);
		void SetUserID(int);
		void SetDate(std::string);
		void SetWorkerID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);
				
		//Create, delete, update methods
		bool CreateOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, int oCount, double oSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, int oCount, double oSum, 
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetOrderByID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool IsEmpty();
	};
}
#endif //ORDERCLASS_H