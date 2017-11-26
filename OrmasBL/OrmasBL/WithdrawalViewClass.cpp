#include "stdafx.h"
#include "WithdrawalViewClass.h"

namespace BusinessLayer{
	WithdrawalView::WithdrawalView(DataLayer::withdrawalsViewCollection wCollection)
	{
		id = std::get<0>(wCollection);
		date = std::get<1>(wCollection);
		value = std::get<2>(wCollection);
		currencyName = std::get<3>(wCollection);
		userID = std::get<4>(wCollection);
		currencyID = std::get<5>(wCollection);
	}

	std::string WithdrawalView::GetCurrencyName()
	{
		return currencyName;
	}
}