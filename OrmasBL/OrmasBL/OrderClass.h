#ifndef ORDERCLASS_H
#define ORDERCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Order
	{
		int ID;
		int userID;
		std::string date;
		int workerID;
		std::string firmName;
	public:
		Order(int oID, int uID, std::string oDate, int wID, std::string fName) :ID(oID),
			userID(uID), date(oDate), workerID(wID), firmName(fName){};
		Order(DataLayer::ordersCollection);
		Order(){};
		~Order(){};
		int CreateOrder(int oID, int uID, std::string oDate, int wID, std::string fName){};

		//Order class Accessors
		int GetID();
		int GetUserID();
		std::string GetDate();
		int GetWorkerID();
		std::string GetFirmName();

		//please implement Mutators
	};
}
#endif //ORDERCLASS_H