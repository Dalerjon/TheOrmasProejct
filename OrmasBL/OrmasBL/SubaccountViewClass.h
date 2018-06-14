#ifndef SUBACCOUNTVIEWCLASS_H
#define SUBACCOUNTVIEWCLASS_H

#include "SubaccountClass.h"

namespace BusinessLayer{
	class SubaccountView : public Subaccount
	{
		std::string parentAccountNumber = "";
		std::string currencyName = "";
		std::string statusName = "";
	public:
		SubaccountView(DataLayer::subaccountsViewCollection);
		SubaccountView(){};
		~SubaccountView(){};

		// AccountView class Accessors
		std::string GetParentAccountNumber();
		std::string GetCurrencyName();
		std::string GetStatusName();
	};
}

#endif //SUBACCOUNTVIEWCLASS_H