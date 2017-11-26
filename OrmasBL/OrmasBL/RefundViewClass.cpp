#include "stdafx.h"
#include "RefundViewClass.h"

namespace BusinessLayer{
	RefundView::RefundView(DataLayer::refundsViewCollection rCollection)
	{
		id = std::get<0>(rCollection);
		date = std::get<1>(rCollection);
		value = std::get<2>(rCollection);
		currencyName = std::get<3>(rCollection);
		userID = std::get<4>(rCollection);
		currencyID = std::get<5>(rCollection);
	}

	std::string RefundView::GetCurrencyName()
	{
		return currencyName;
	}
}