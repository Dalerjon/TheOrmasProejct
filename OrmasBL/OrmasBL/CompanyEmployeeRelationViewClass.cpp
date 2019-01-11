#include "stdafx.h"
#include "CompanyEmployeeRelationViewClass.h"

namespace BusinessLayer{
	CompanyEmployeeRelationView::CompanyEmployeeRelationView(DataLayer::companyEmployeeViewCollection aCollection)
	{
		id = std::get<0>(aCollection);
		companyName = std::get<1>(aCollection);
		branchName = std::get<2>(aCollection);
		userName = std::get<3>(aCollection);
		userSurname = std::get<4>(aCollection);
		userPhone = std::get<5>(aCollection);
		companyID = std::get<6>(aCollection);
		employeeID = std::get<7>(aCollection);
		branchID = std::get<8>(aCollection);
	}

	std::string CompanyEmployeeRelationView::GetCompanyName()
	{
		return companyName;
	}
	std::string CompanyEmployeeRelationView::GetBranchName()
	{
		return branchName;
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