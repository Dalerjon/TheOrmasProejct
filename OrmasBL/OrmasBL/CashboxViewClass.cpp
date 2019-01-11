#include "stdafx.h"
#include "CashboxViewClass.h"

namespace BusinessLayer{
	CashboxView::CashboxView(DataLayer::cashboxViewCollection cCollection)
	{
		id = std::get<0>(cCollection);
		subaccountNumber = std::get<1>(cCollection);
		information = std::get<2>(cCollection);
		address = std::get<3>(cCollection);
		subaccountID = std::get<4>(cCollection);
	}

	std::string CashboxView::GetSubaccountNumber()
	{
		return subaccountNumber;
	}
}