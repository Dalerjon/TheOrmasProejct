#include "stdafx.h"
#include "WithdrawalViewClass.h"

namespace BusinessLayer{
	WithdrawalView::WithdrawalView(DataLayer::withdrawalsViewCollection wCollection)
	{
		id = std::get<0>(wCollection);
		date = std::get<1>(wCollection);
		value = std::get<2>(wCollection);
		userName = std::get<3>(wCollection);
		userSurname = std::get<4>(wCollection);
		subaccountNumber = std::get<5>(wCollection);
		target = std::get<6>(wCollection);
		currencyName = std::get<7>(wCollection);
		userID = std::get<8>(wCollection);
		currencyID = std::get<9>(wCollection);
		subaccountID = std::get<10>(wCollection);
	}

	std::string WithdrawalView::GetUsername()
	{
		return userName;
	}
	std::string WithdrawalView::GetUserSurname()
	{
		return userSurname;
	}
	std::string WithdrawalView::GetSubaccountNumber()
	{
		return subaccountNumber;
	}
	std::string WithdrawalView::GetCurrencyName()
	{
		return currencyName;
	}
}