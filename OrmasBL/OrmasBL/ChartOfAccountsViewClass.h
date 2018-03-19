#ifndef CHARTOFACCOUNTSVIEWCLASS_H
#define CHARTOFACCOUNTSVIEWCLASS_H

#include "ChartOfAccountsClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class ChartOfAccountsView : public ChartOfAccounts
	{
		std::string accountTypeName = "";
	public:
		ChartOfAccountsView(DataLayer::chartOfAccountsViewCollection);
		ChartOfAccountsView(){};
		~ChartOfAccountsView(){};

		// Chart Of Accounts View class Accessors
		std::string GetAccountTypeName();
	};
}

#endif