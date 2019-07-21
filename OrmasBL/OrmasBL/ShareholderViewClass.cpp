#include "stdafx.h"
#include "ShareholderViewClass.h"

namespace BusinessLayer{
	ShareholderView::ShareholderView(DataLayer::shareholdersViewCollection sCollection)
	{
		id = std::get<0>(sCollection);
		userName = std::get<1>(sCollection);
		userSurname = std::get<2>(sCollection);
		userPhone = std::get<3>(sCollection);
		userAddress = std::get<4>(sCollection);
		countOfStock = std::get<5>(sCollection);
		information = std::get<6>(sCollection);
	}

	std::string ShareholderView::GetUsername()
	{
		return userName;
	}
	std::string ShareholderView::GetUserSurname()
	{
		return userSurname;
	}
	std::string ShareholderView::GetUserPhone()
	{
		return userPhone;
	}
	std::string ShareholderView::GetUserAddress()
	{
		return userAddress;
	}
}