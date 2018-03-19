#ifndef ACCOUNTVIEWCLASS_H
#define ACCOUNTVIEWCLASS_H

#include "AccountClass.h"

namespace BusinessLayer{
	class AccountView : public Account
	{
		std::string currencyName = "";
		std::string statusName = "";
	public:
		AccountView(DataLayer::accountsViewCollection);
		AccountView(){};
		~AccountView(){};

		// AccountView class Accessors
		std::string GetCurrencyName();
		std::string GetStatusName();
	};
}

#endif //AccountVIEWCLASS_H