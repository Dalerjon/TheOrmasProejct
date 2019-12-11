#include "stdafx.h"
#include "ExtendedEntryViewClass.h"

namespace BusinessLayer{
	ExtendedEntryView::ExtendedEntryView(DataLayer::entriesFullViewCollection eCollection)
	{
		id = std::get<0>(eCollection);
		date = std::get<1>(eCollection);
		debitingAccountNumber = std::get<2>(eCollection);
		value = std::get<3>(eCollection);
		creditingAccountNumber = std::get<4>(eCollection);
		operationID = std::get<5>(eCollection);
		subaccountID = std::get<6>(eCollection);
		debitingAccountID = std::get<7>(eCollection);
		creditingAccountID = std::get<8>(eCollection);
		description = std::get<9>(eCollection);
	}

	std::string ExtendedEntryView::GetDebitingAccountNumber()
	{
		return debitingAccountNumber;
	}

	std::string ExtendedEntryView::GetCreditingAccountNumber()
	{
		return creditingAccountNumber;
	}

	int ExtendedEntryView::GetOperationID()
	{
		return operationID;
	}

	int ExtendedEntryView::GetSubaccountID()
	{
		return subaccountID;
	}
}