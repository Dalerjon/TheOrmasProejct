#include "stdafx.h"
#include "SubaccountViewClass.h"

namespace BusinessLayer{
	SubaccountView::SubaccountView(DataLayer::subaccountsViewCollection sCollection)
	{
		id = std::get<0>(sCollection);
		parentSubaccountID = std::get<1>(sCollection);
		parentAccountNumber = std::get<2>(sCollection);
		number = std::get<3>(sCollection);
		startBalance = std::get<4>(sCollection);
		currentBalance = std::get<5>(sCollection);
		currencyName = std::get<6>(sCollection);
		statusName = std::get<7>(sCollection);
		currencyID = std::get<8>(sCollection);
		statusID = std::get<9>(sCollection);
		openedDate = std::get<10>(sCollection);
		closedDate = std::get<11>(sCollection);
		details = std::get<12>(sCollection);
	}

	std::string SubaccountView::GetParentAccountNumber()
	{
		return parentAccountNumber;
	}
	std::string SubaccountView::GetCurrencyName()
	{
		return currencyName;
	}
	std::string SubaccountView::GetStatusName()
	{
		return statusName;
	}
}