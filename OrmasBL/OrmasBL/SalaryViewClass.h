#ifndef SALARYVIEWCLASS_H
#define SALARYVIEWCLASS_H

#include "SalaryClass.h"

namespace BusinessLayer{
	class SalaryView : public Salary
	{
		std::string employeeName = "";
		std::string employeeSurname = "";
		std::string employeePhone = "";
		std::string currencyName = "";
		std::string salaryTypeName = "";
	public:
		SalaryView(DataLayer::salariesViewCollection);
		SalaryView(){};
		~SalaryView(){};

		// BalanceView class Accessors
		std::string GetEmployeeName();
		std::string GetEmployeeSurname();
		std::string GetEmployeePhone();
		std::string GetCurrencyName();
		std::string GetSalaryTypeName();


	};
}

#endif