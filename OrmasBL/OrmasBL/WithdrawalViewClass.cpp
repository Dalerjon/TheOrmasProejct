#include "stdafx.h"
#include "WithdrawalViewClass.h"

namespace BusinessLayer{
	WithdrawalView::WithdrawalView(DataLayer::withdrawalsViewCollection wCollection)
	{
		id = std::get<0>(wCollection);
		date = std::get<1>(wCollection);
		value = std::get<2>(wCollection);
		currencyName = std::get<3>(wCollection);
		userName = std::get<4>(wCollection);
		userSurname = std::get<5>(wCollection);
		statusName = std::get<6>(wCollection);
		accountNumber = std::get<7>(wCollection);
		subaccountNumber = std::get<8>(wCollection);
		target = std::get<9>(wCollection);
		userID = std::get<10>(wCollection);
		currencyID = std::get<11>(wCollection);
		subaccountID = std::get<12>(wCollection);
		statusID = std::get<13>(wCollection);
		accountID = std::get<14>(wCollection);
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
	std::string WithdrawalView::GetStatusName()
	{
		return statusName;
	}
	std::string WithdrawalView::GetAccountNumber()
	{
		return accountNumber;
	}
}