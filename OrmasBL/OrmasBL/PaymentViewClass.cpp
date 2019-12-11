#include "stdafx.h"
#include "PaymentViewClass.h"

namespace BusinessLayer{
	PaymentView::PaymentView(DataLayer::paymentsViewCollection pCollection)
	{
		id = std::get<0>(pCollection);
		date = std::get<1>(pCollection);
		userName = std::get<2>(pCollection);
		userSurname = std::get<3>(pCollection);
		userPhone = std::get<4>(pCollection);
		value = std::get<5>(pCollection);
		currencyName = std::get<6>(pCollection);
		target = std::get<7>(pCollection);
		accountNumber = std::get<8>(pCollection);
		subaccountNumber = std::get<9>(pCollection);
		who = std::get<10>(pCollection);
		statusName = std::get<11>(pCollection);
		userID = std::get<12>(pCollection);
		currencyID = std::get<13>(pCollection);
		statusID = std::get<14>(pCollection);
		accountID = std::get<15>(pCollection);
		subaccountID = std::get<16>(pCollection);
		cashboxAccountID = std::get<17>(pCollection);
	}

	std::string PaymentView::GetUsername()
	{
		return userName;
	}
	std::string PaymentView::GetUserSurname()
	{
		return userSurname;
	}
	std::string PaymentView::GetUserPhone()
	{
		return userPhone;
	}
	std::string PaymentView::GetCurrencyName()
	{
		return currencyName;
	}
	std::string PaymentView::GetAccountNumber()
	{
		return accountNumber;
	}
	std::string PaymentView::GetStatusName()
	{
		return statusName;
	}
	std::string PaymentView::GetSubaccountNumber()
	{
		return subaccountNumber;
	}
}