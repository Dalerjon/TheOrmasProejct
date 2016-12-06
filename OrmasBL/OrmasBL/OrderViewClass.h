#ifndef ORDERVIEWCLASS_H
#define ORDERVIEWCLASS_H

#include "OrderClass.h"

namespace BusinessLayer
{
	class OrderView : public Order
	{
		std::string clientName = "";
		std::string clientPhone = "";
		std::string clientAddres = "";
		std::string firm = "";
		std::string workerName = "";
		std::string workerPhone = "";
	public:
		OrderView(int oID, std::string oDate, std::string oClientName, std::string oClientPhone, std::string oClientAddres,
			std::string oFirm, std::string oWorkerName, std::string oWorkerPhone, int wID, int uID) : Order(oID,uID,oDate,wID),
			clientName(oClientName), clientPhone(oClientPhone), clientAddres(oClientAddres), firm(oFirm), workerName(oWorkerName), 
			workerPhone(oWorkerPhone){};
		OrderView(DataLayer::ordersViewCollection);
		OrderView(){};
		~OrderView(){};

		// OrderView class Accessors
		std::string GetClientName();
		std::string GetClientPhone();
		std::string GetClientAddress();
		std::string GetFirm();
		std::string GetWorkerName();
		std::string GetWorkerPhone();
		
		// OrderView class Mutators
		void SetClientName(std::string);
		void SetClientPhone(std::string);
		void SetClientAddress(std::string);
		void SetFirm(std::string);
		void SetWorkerName(std::string);
		void SetWorkerPhone(std::string);

	};
}
#endif //ORDERVIEWCLASS_H
