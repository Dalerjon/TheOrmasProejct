#ifndef RECEIPTOTHERSTOCKSVIEWCLASS_H
#define RECEIPTOTHERSTOCKSVIEWCLASS_H

#include "ReceiptOtherStocksClass.h"

namespace BusinessLayer
{
	class ReceiptOtherStocksView : public ReceiptOtherStocks
	{
		std::string statusCode = "";
		std::string statusName = "";
		std::string purveyorName = "";
		std::string purveyorSurname = "";
		std::string purveyorPhone = "";
		std::string purveyorCompanyName = "";
		std::string employeeName = "";
		std::string employeeSurname = "";
		std::string employeePhone = "";
		std::string employeePosition = "";
		std::string currencyName = "";
	public:
		ReceiptOtherStocksView(DataLayer::receiptOtherStocksViewCollection);
		ReceiptOtherStocksView(){};
		~ReceiptOtherStocksView(){};

		// OrderView class Accessors
		std::string GetStatusCode();
		std::string GetStatusName();
		std::string GetPurveyorName();
		std::string GetPurveyorSurname();
		std::string GetPurveyorPhone();
		std::string GetPurveyorCompanyName();
		std::string GetEmployeeName();
		std::string GetEmployeeSurname();
		std::string GetEmployeePhone();
		std::string GetEmployeePosition();
		std::string GetCurrencyName();

	};
}
#endif //ReceiptOtherStocksVIEWCLASS_H
