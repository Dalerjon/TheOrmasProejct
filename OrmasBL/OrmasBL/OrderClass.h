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
	public:
		Order(int oID, int uID, std::string oDate, int wID) :id(oID),
			userID(uID), date(oDate), workerID(wID){};
		Order(DataLayer::ordersCollection);
		Order(){};
		~Order(){};
		
		//Order class Accessors
		int GetID();
		int GetUserID();
		std::string GetDate();
		int GetWorkerID();

		//Order class Mutators
		void SetID(int);
		void SetUserID(int);
		void SetDate(std::string);
		void SetWorkerID(int);
				
		//Create, delete, update methods
		bool CreateOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage){};
		bool UpdateOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage){};
		bool DeleteOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string& errorMessage);
		bool UpdateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string& errorMessage);
	};
}
#endif //ORDERCLASS_H