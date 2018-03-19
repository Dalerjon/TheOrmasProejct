#include "stdafx.h"
#include "ChartOfAccountsViewClass.h"

namespace BusinessLayer{
	ChartOfAccountsView::ChartOfAccountsView(DataLayer::chartOfAccountsViewCollection cCollection)
	{
		id = std::get<0>(cCollection);
		number = std::get<1>(cCollection);
		name = std::get<2>(cCollection);
		accountTypeName = std::get<3>(cCollection);
		accountTypeID = std::get<4>(cCollection);
	}

	std::string ChartOfAccountsView::GetAccountTypeName()
	{
		return accountTypeName;
	}
}