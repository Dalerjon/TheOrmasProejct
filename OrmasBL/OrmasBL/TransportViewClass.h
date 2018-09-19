#ifndef TRANSPORTVIEWCLASS_H
#define TRANSPORTVIEWCLASS_H

#include "TransportClass.h"

namespace BusinessLayer
{
	class TransportView : public Transport
	{
		std::string statusCode = "";
		std::string statusName = "";
		std::string userName = "";
		std::string userSurname = "";
		std::string userPhone = "";
		std::string userPosition = "";
		std::string employeeName = "";
		std::string employeeSurname = "";
		std::string employeePhone = "";
		std::string employeePosition = "";
		std::string currencyName = "";
	public:
		TransportView(DataLayer::transportsViewCollection);
		TransportView(){};
		~TransportView(){};

		// OrderView class Accessors
		std::string GetStatusCode();
		std::string GetStatusName();
		std::string GetUsername();
		std::string GetUserSurname();
		std::string GetUserPhone();
		std::string GetUserPosition();
		std::string GetEmployeeName();
		std::string GetEmployeeSurname();
		std::string GetEmployeePhone();
		std::string GetEmployeePosition();
		std::string GetCurrencyName();

	};
}
#endif //TRANSPORTVIEWCLASS_H
