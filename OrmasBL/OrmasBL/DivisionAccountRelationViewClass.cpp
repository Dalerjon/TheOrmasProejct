#include "stdafx.h"
#include "DivisionAccountRelationViewClass.h"

namespace BusinessLayer{
	DivisionAccountRelationView::DivisionAccountRelationView(DataLayer::divisionAccountViewCollection dCollection)
	{
		id = std::get<0>(dCollection);
		divisionName = std::get<1>(dCollection);
		accountNumber = std::get<2>(dCollection);
		accountName = std::get<3>(dCollection);
		code = std::get<4>(dCollection);
		divisionID = std::get<5>(dCollection);
		accountID = std::get<6>(dCollection);
	}

	std::string DivisionAccountRelationView::GetDivisionName()
	{
		return divisionName;
	}

	std::string DivisionAccountRelationView::GetAccountNumber()
	{
		return accountNumber;
	}

	std::string DivisionAccountRelationView::GetAccountName()
	{
		return accountName;
	}
}