#ifndef EXTENDEDENTRYVIEWCLASS_H
#define EXTENDEDENTRYVIEWCLASS_H

#include "EntryClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class ExtendedEntryView : public Entry
	{
		int operationID = 0;
		int subaccountID = 0;
		std::string debitingAccountNumber = "";
		std::string creditingAccountNumber = "";
	public:
		ExtendedEntryView(DataLayer::entriesFullViewCollection);
		ExtendedEntryView(){};
		~ExtendedEntryView(){};

		// EntryView class Accessors
		std::string GetDebitingAccountNumber();
		std::string GetCreditingAccountNumber();
		int GetOperationID();
		int GetSubaccountID();
	};
}

#endif