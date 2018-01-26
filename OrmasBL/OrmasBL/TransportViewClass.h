#ifndef TRANSPORTVIEWCLASS_H
#define TRANSPORTVIEWCLASS_H

#include "TransportClass.h"

namespace BusinessLayer
{
	class TransportView : public Transport
	{
		std::string statusCode = "";
		std::string statusName = "";
		std::string employeeName = "";
		std::string employeeSurname = "";
		std::string employeePhone = "";
		std::string employeePosition = "";
		std::string stockEmployeeName = "";
		std::string stockEmployeeSurname = "";
		std::string stockEmployeePhone = "";
		std::string stockEmployeePosition = "";
		std::string currencyName = "";
	public:
		TransportView(DataLayer::transportsViewCollection);
		TransportView(){};
		~TransportView(){};

		// OrderView class Accessors
		std::string GetStatusCode();
		std::string GetStatusName();
		std::string GetEmployeeName();
		std::string GetEmployeeSurname();
		std::string GetEmployeePhone();
		std::string GetEmployeePosition();
		std::string GetStockEmployeeName();
		std::string GetStockEmployeeSurname();
		std::string GetStockEmployeePhone();
		std::string GetStockEmployeePosition();
		std::string GetCurrencyName();

	};
}
#endif //TRANSPORTVIEWCLASS_H
