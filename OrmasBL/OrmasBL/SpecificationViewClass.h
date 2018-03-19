#ifndef SPECIFICATIONVIEWCLASS_H
#define SPECIFICATIONVIEWCLASS_H

#include "SpecificationClass.h"

namespace BusinessLayer
{
	class SpecificationView : public Specification
	{
		std::string productName = "";
		std::string currencyName = "";
		std::string employeeName = "";
		std::string employeeSurname = "";
		std::string employeePhone = "";
		std::string employeePositionName = "";
		
	public:
		SpecificationView(DataLayer::specificationsViewCollection);
		SpecificationView(){};
		~SpecificationView(){};

		// SpecificationView class Accessors
		std::string GetProductName();
		std::string GetCurrencyName();
		std::string GetEmployeeName();
		std::string GetEmployeeSurname();
		std::string GetEmployeePhone();
		std::string GetEmployeePositionName();

	};
}
#endif //SPECIFICATIONVIEWCLASS_H
