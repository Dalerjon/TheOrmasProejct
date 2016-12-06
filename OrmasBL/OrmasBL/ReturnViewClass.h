#ifndef RETURNVIEWCLASS_H
#define RETURNVIEWCLASS_H

#include "ReturnClass.h"

namespace BusinessLayer
{
	class ReturnView : public Return
	{
		std::string clientName = "";
		std::string clientPhone = "";
		std::string clientAddres = "";
		std::string firm = "";
		std::string workerName = "";
		std::string workerPhone = "";
	public:
		ReturnView(int rID, std::string rDate, std::string rClientName, std::string rClientPhone, std::string rClientAddres,
			std::string rFirm, std::string rWorkerName, std::string rWorkerPhone, int wID, int uID) : Return(rID, uID, rDate, wID),
			clientName(rClientName), clientPhone(rClientPhone), clientAddres(rClientAddres), firm(rFirm), workerName(rWorkerName),
			workerPhone(rWorkerPhone){};
		ReturnView(DataLayer::returnsViewCollection);
		ReturnView(){};
		~ReturnView(){};

		// ReturnView class Accessors
		std::string GetClientName();
		std::string GetClientPhone();
		std::string GetClientAddress();
		std::string GetFirm();
		std::string GetWorkerName();
		std::string GetWorkerPhone();

		// ReturnView class Mutators
		void SetClientName(std::string);
		void SetClientPhone(std::string);
		void SetClientAddress(std::string);
		void SetFirm(std::string);
		void SetWorkerName(std::string);
		void SetWorkerPhone(std::string);

	};
}
#endif //RETURNVIEWCLASS