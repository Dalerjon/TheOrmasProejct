#ifndef BALANCEVIEWCLASS_H
#define BALANCEVIEWCLASS_H

#include "BalanceClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class BalanceView : public Balance
	{
		std::string userName = "";
		std::string userSurname = "";
		std::string currencyName = "";
	public:
		BalanceView(DataLayer::balancesViewCollection);
		BalanceView(){};
		~BalanceView(){};

		// BalanceView class Accessors
		std::string GetUsername();
		std::string GetUserSurname();
		std::string GetCurrencyName();
	};
}
#endif //BALANCEVIEWCLASS_H