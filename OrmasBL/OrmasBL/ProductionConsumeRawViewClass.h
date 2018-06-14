#ifndef ProductionConsumeRawVIEWCLASS_H
#define ProductionConsumeRawVIEWCLASS_H

#include "ProductionConsumeRawClass.h"

namespace BusinessLayer
{
	class ProductionConsumeRawView : public ProductionConsumeRaw
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
		ProductionConsumeRawView(DataLayer::productionConsumeRawsViewCollection);
		ProductionConsumeRawView(){};
		~ProductionConsumeRawView(){};

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
#endif //ProductionConsumeRawVIEWCLASS_H
