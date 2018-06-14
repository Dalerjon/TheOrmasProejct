#include "stdafx.h"
#include "CompanyEmployeeRelationViewClass.h"

namespace BusinessLayer{
	CompanyEmployeeRelationView::CompanyEmployeeRelationView(DataLayer::companyEmployeeViewCollection aCollection)
	{
		id = std::get<0>(aCollection);
		companyName = std::get<1>(aCollection);
		userName = std::get<2>(aCollection);
		userSurname = std::get<3>(aCollection);
		userPhone = std::get<4>(aCollection);
		companyID = std::get<5>(aCollection);
		employeeID = std::get<6>(aCollection);
	}

	std::string CompanyEmployeeRelationView::GetCompanyName()
	{
		return companyName;
	}
	std::string CompanyEmployeeRelationView::GetUsername()
	{
		return userName;
	}
	std::string CompanyEmployeeRelationView::GetUserSurname()
	{
		return userSurname;
	}
	std::string CompanyEmployeeRelationView::GetUserPhone()
	{
		return userPhone;
	}
}