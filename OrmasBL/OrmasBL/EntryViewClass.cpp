#include "stdafx.h"
#include "EntryViewClass.h"

namespace BusinessLayer{
	EntryView::EntryView(DataLayer::entriesViewCollection eCollection)
	{
		id = std::get<0>(eCollection);
		date = std::get<1>(eCollection);
		debitingAccountNumber = std::get<2>(eCollection);
		value = std::get<3>(eCollection);
		creditingAccountNumber = std::get<4>(eCollection);
		debitingAccountID = std::get<5>(eCollection);
		creditingAccountID = std::get<6>(eCollection);
	}

	std::string EntryView::GetDebitingAccountNumber()
	{
		return debitingAccountNumber;
	}

	std::string EntryView::GetCreditingAccountNumber()
	{
		return creditingAccountNumber;
	}

}