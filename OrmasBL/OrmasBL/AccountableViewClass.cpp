#include "stdafx.h"
#include "AccountableViewClass.h"

namespace BusinessLayer{
	AccountableView::AccountableView(DataLayer::accountableViewCollection aCollection)
	{
		id = std::get<0>(aCollection);
		employeeID = std::get<0>(aCollection);
		name = std::get<1>(aCollection);
		surname = std::get<2>(aCollection);
		information = std::get<3>(aCollection);
		phone = std::get<4>(aCollection);
		address = std::get<5>(aCollection);
		roleName = std::get<6>(aCollection);
	}

	std::string AccountableView::GetRoleName()
	{
		return roleName;
	}
}