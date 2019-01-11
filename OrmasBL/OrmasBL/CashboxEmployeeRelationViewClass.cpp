#include "stdafx.h"
#include "CashboxEmployeeRelationViewClass.h"

namespace BusinessLayer{
	CashboxEmployeeRelationView::CashboxEmployeeRelationView(DataLayer::cashboxEmployeeViewCollection cCollection)
	{
		id = std::get<0>(cCollection);
		subaccountNumber = std::get<1>(cCollection);
		cashboxAddress = std::get<2>(cCollection);
		userName = std::get<3>(cCollection);
		userSurname = std::get<4>(cCollection);
		userPhone = std::get<5>(cCollection);
		roleName = std::get<6>(cCollection);
		cashboxID = std::get<7>(cCollection);
		employeeID = std::get<8>(cCollection);
	}

	std::string CashboxEmployeeRelationView::GetSubaccountNumber()
	{
		return subaccountNumber;
	}
	std::string CashboxEmployeeRelationView::GetCashboxAddress()
	{
		return cashboxAddress;
	}
	std::string CashboxEmployeeRelationView::GetUsername()
	{
		return userName;
	}
	std::string CashboxEmployeeRelationView::GetUserSurname()
	{
		return userSurname;
	}
	std::string CashboxEmployeeRelationView::GetUserPhone()
	{
		return userPhone;
	}
	std::string CashboxEmployeeRelationView::GetRoleName()
	{
		return roleName;
	}
}