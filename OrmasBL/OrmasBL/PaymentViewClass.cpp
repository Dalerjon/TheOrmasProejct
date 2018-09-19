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
		statusName = std::get<7>(pCollection);
		userID = std::get<8>(pCollection);
		currencyID = std::get<9>(pCollection);
		statusID = std::get<10>(pCollection);
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
	std::string PaymentView::GetStatusName()
	{
		return statusName;
	}
}