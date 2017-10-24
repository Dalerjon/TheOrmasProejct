#include "stdafx.h"
#include "PaymentViewClass.h"

namespace BusinessLayer{
	PaymentView::PaymentView(DataLayer::paymentsViewCollection pCollection)
	{
		id = std::get<0>(pCollection);
		date = std::get<1>(pCollection);
		value = std::get<2>(pCollection);
		currencyName = std::get<3>(pCollection);
		userID = std::get<4>(pCollection);
		currencyID = std::get<5>(pCollection);
	}

	std::string PaymentView::GetCurrencyName()
	{
		return currencyName;
	}
}