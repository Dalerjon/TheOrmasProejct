#ifndef ORDERVIEWCLASS_H
#define ORDERVIEWCLASS_H

#include "OrderClass.h"

namespace BusinessLayer
{
	class OrderView : public Order
	{
		std::string statusCode = "";
		std::string statusName = "";
		std::string clientName = "";
		std::string clientPhone = "";
		std::string clientAddres = "";
		std::string firm = "";
		std::string workerName = "";
		std::string workerPhone = "";
		std::string currencyName = "";
	public:
		OrderView(int oID, std::string oDate, std::string oStatusCode, std::string oStatusName, std::string oClientName, 
			std::string oClientPhone, std::string oClientAddres, std::string oFirm, std::string oWorkerName, std::string oWorkerPhone,
			int oCount, double oSum, std::string oCurrencyName, int wID, int uID, int sID, int cID) : Order(oID,uID,oDate,wID,oCount,
			oSum, sID, cID), statusCode(oStatusCode), statusName(oStatusName),clientName(oClientName), clientPhone(oClientPhone), 
			clientAddres(oClientAddres), firm(oFirm), workerName(oWorkerName), workerPhone(oWorkerPhone), currencyName(oCurrencyName){};
		OrderView(DataLayer::ordersViewCollection);
		OrderView(){};
		~OrderView(){};

		// OrderView class Accessors
		std::string GetStatusCode();
		std::string GetStatusName();
		std::string GetClientName();
		std::string GetClientPhone();
		std::string GetClientAddress();
		std::string GetFirm();
		std::string GetWorkerName();
		std::string GetWorkerPhone();
		std::string GetCurrencyName();
		
		// OrderView class Mutators
		void SetStatusCode(std::string);
		void SetStatusName(std::string);
		void SetClientName(std::string);
		void SetClientPhone(std::string);
		void SetClientAddress(std::string);
		void SetFirm(std::string);
		void SetWorkerName(std::string);
		void SetWorkerPhone(std::string);
		void SetCurrencyName(std::string);

	};
}
#endif //ORDERVIEWCLASS_H
