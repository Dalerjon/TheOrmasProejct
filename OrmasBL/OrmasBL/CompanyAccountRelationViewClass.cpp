#include "stdafx.h"
#include "CompanyAccountRelationViewClass.h"

namespace BusinessLayer{
	CompanyAccountRelationView::CompanyAccountRelationView(DataLayer::companyAccountViewCollection aCollection)
	{
		id = std::get<0>(aCollection);
		companyName = std::get<1>(aCollection);
		accountNumber = std::get<2>(aCollection);
		companyID = std::get<3>(aCollection);
		accountID = std::get<4>(aCollection);
	}

	std::string CompanyAccountRelationView::GetCompanyName()
	{
		return companyName;
	}
	std::string CompanyAccountRelationView::GetAccountNumber()
	{
		return accountNumber;
	}
}