#include "stdafx.h"
#include "BalanceViewClass.h"

namespace BusinessLayer{
	BalanceView::BalanceView(DataLayer::balancesViewCollection bCollection)
	{
		id = std::get<0>(bCollection);
		userName = std::get<1>(bCollection);
		userSurname = std::get<2>(bCollection);
		currentBalance = std::get<3>(bCollection);
		currencyName = std::get<4>(bCollection);
		userID = std::get<5>(bCollection);
		accountID = std::get<6>(bCollection);
	}

	std::string BalanceView::GetUsername()
	{
		return userName;
	}
	std::string BalanceView::GetUserSurname()
	{
		return userSurname;
	}
	double BalanceView::GetCurrentBalance()
	{
		return currentBalance;
	}
	std::string BalanceView::GetCurrencyName()
	{
		return currencyName;
	}
}