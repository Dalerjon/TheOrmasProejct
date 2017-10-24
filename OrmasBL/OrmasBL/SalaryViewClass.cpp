#include "stdafx.h"
#include "SalaryViewClass.h"

namespace BusinessLayer{
	SalaryView::SalaryView(DataLayer::salariesViewCollection sCollection)
	{
		id = std::get<0>(sCollection);
		userID = std::get<1>(sCollection);
		userName = std::get<2>(sCollection);
		userSurname = std::get<3>(sCollection);
		userPhone = std::get<4>(sCollection);
		date = std::get<5>(sCollection);
		value = std::get<6>(sCollection);
		currencyName = std::get<7>(sCollection);
		salaryTypeName = std::get<8>(sCollection);
		currencyID = std::get<9>(sCollection);
		salaryTypeID = std::get<10>(sCollection);
		isBonus = std::get<11>(sCollection);
	}

	std::string SalaryView::GetUsername()
	{
		return userName;
	}
	std::string SalaryView::GetUserSurname()
	{
		return userSurname;
	}
	std::string SalaryView::GetUserPhone()
	{
		return userPhone;
	}
	std::string SalaryView::GetCurrencyName()
	{
		return currencyName;
	}
	std::string SalaryView::GetSalaryTypeName()
	{
		return salaryTypeName;
	}
}