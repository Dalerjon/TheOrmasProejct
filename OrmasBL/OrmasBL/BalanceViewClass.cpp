#include "stdafx.h"
#include "BalanceViewClass.h"

namespace BusinessLayer{
	BalanceView::BalanceView(DataLayer::balancesViewCollection bCollection)
	{
		id = std::get<0>(bCollection);
		userName = std::get<1>(bCollection);
		userSurname = std::get<2>(bCollection);
		value = std::get<3>(bCollection);
		currencyName = std::get<4>(bCollection);
		userID = std::get<5>(bCollection);
		currencyID = std::get<6>(bCollection);
	}

	std::string BalanceView::GetUsername()
	{
		return userName;
	}
	std::string BalanceView::GetUserSurname()
	{
		return userSurname;
	}
	std::string BalanceView::GetCurrencyName()
	{
		return currencyName;
	}
}