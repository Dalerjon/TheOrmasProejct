#ifndef WRITEOFFVIEWCLASS_H
#define WRITEOFFVIEWCLASS_H

#include "WriteOffClass.h"

namespace BusinessLayer
{
	class WriteOffView : public WriteOff
	{
		std::string statusCode = "";
		std::string statusName = "";
		std::string clientName = "";
		std::string clientSurname = "";
		std::string clientPhone = "";
		std::string clientAddres = "";
		std::string clientFirm = "";
		std::string employeeName = "";
		std::string employeeSurname = "";
		std::string employeePhone = "";
		std::string currencyName = "";
	public:
		WriteOffView(DataLayer::writeOffsViewCollection);
		WriteOffView(){};
		~WriteOffView(){};

		// WriteOffView class Accessors
		std::string GetStatusCode();
		std::string GetStatusName();
		std::string GetClientName();
		std::string GetClientSurname();
		std::string GetClientPhone();
		std::string GetClientAddress();
		std::string GetClientFirm();
		std::string GetEmployeeName();
		std::string GetEmployeeSurname();
		std::string GetEmployeePhone();
		std::string GetCurrencyName();

	};
}
#endif //WRITEOFFVIEWCLASS_H
