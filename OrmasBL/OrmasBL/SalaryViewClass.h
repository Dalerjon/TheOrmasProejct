#ifndef SALARYVIEWCLASS_H
#define SALARYVIEWCLASS_H

#include "SalaryClass.h"

namespace BusinessLayer{
	class SalaryView : public Salary
	{
		std::string userName = "";
		std::string userSurname = "";
		std::string userPhone = "";
		std::string currencyName = "";
		std::string salaryTypeName = "";
	public:
		SalaryView(DataLayer::salariesViewCollection);
		SalaryView(){};
		~SalaryView(){};

		// BalanceView class Accessors
		std::string GetUsername();
		std::string GetUserSurname();
		std::string GetUserPhone();
		std::string GetCurrencyName();
		std::string GetSalaryTypeName();


	};
}

#endif