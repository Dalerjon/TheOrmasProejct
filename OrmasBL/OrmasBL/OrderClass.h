#ifndef ORDERCLASS_H
#define ORDERCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Order
	{
		int id=0;
		int userID;
		std::string date;
		int workerID;
		std::string firmName;
	public:
		Order(int oID, int uID, std::string oDate, int wID, std::string fName) :id(oID),
			userID(uID), date(oDate), workerID(wID), firmName(fName){};
		Order(DataLayer::ordersCollection);
		Order(){};
		~Order(){};
		
		//Order class Accessors
		int GetID();
		int GetUserID();
		std::string GetDate();
		int GetWorkerID();
		std::string GetFirmName();

		//please implement Mutators
		
		//Create, delete, update methods
		bool CreateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string fName);
		bool DeleteOrder(DataLayer::OrmasDal& ormasDal);
		bool UpdateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, std::string fName);
	};
}
#endif //ORDERCLASS_H