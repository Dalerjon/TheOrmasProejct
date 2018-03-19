#include "stdafx.h"
#include "AccountViewClass.h"

namespace BusinessLayer{
	AccountView::AccountView(DataLayer::accountsViewCollection sCollection)
	{
		id = std::get<0>(sCollection);
		number = std::get<1>(sCollection);
		startBalance = std::get<2>(sCollection);
		currentBalance = std::get<3>(sCollection);
		currencyName = std::get<4>(sCollection);
		statusName = std::get<5>(sCollection);
		currencyID = std::get<6>(sCollection);
		statusID = std::get<7>(sCollection);
		openedDate = std::get<8>(sCollection);
		closedDate = std::get<9>(sCollection);
		details = std::get<10>(sCollection);
	}

	std::string AccountView::GetCurrencyName()
	{
		return currencyName;
	}
	std::string AccountView::GetStatusName()
	{
		return statusName;
	}
}