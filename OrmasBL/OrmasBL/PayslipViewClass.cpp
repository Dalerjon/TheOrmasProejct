#include "stdafx.h"
#include "PayslipViewClass.h"

namespace BusinessLayer{
	PayslipView::PayslipView(DataLayer::payslipsViewCollection pCollection)
	{
		id = std::get<0>(pCollection);
		date = std::get<1>(pCollection);
		value = std::get<2>(pCollection);
		currencyName = std::get<3>(pCollection);
		salaryID = std::get<4>(pCollection);
		currencyID = std::get<5>(pCollection);
	}

	std::string PayslipView::GetCurrencyName()
	{
		return currencyName;
	}
}