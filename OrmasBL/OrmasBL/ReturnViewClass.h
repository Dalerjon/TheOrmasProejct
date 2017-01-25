#ifndef RETURNVIEWCLASS_H
#define RETURNVIEWCLASS_H

#include "ReturnClass.h"

namespace BusinessLayer
{
	class ReturnView : public Return
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
		ReturnView(int rID, std::string rDate,std::string rStatusCode, std::string rStatusName, std::string rClientName, 
			std::string rClientPhone, std::string rClientAddres, std::string rFirm, std::string rWorkerName, std::string rWorkerPhone,
			int rCount, double rSum, std::string rCurrencyName, int wID, int uID, int sID, int cID) : Return(rID, uID, rDate, wID, 
			rCount, rSum, sID, cID), statusCode(rStatusCode), statusName(rStatusName),clientName(rClientName), 
			clientPhone(rClientPhone), clientAddres(rClientAddres), firm(rFirm), workerName(rWorkerName), workerPhone(rWorkerPhone),
			currencyName(rCurrencyName){};
		ReturnView(DataLayer::returnsViewCollection);
		ReturnView(){};
		~ReturnView(){};

		// ReturnView class Accessors
		std::string GetStatusCode();
		std::string GetStatusName();
		std::string GetClientName();
		std::string GetClientPhone();
		std::string GetClientAddress();
		std::string GetFirm();
		std::string GetWorkerName();
		std::string GetWorkerPhone();
		std::string GetCurrencyName();

		// ReturnView class Mutators
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
#endif //RETURNVIEWCLASS