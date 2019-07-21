#ifndef WITHDRAWALVIEWCLASS_H
#define WITHDRAWALVIEWCLASS_H

#include "WithdrawalClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class WithdrawalView : public Withdrawal
	{
		std::string userName = "";
		std::string userSurname = "";
		std::string subaccountNumber = "";
		std::string currencyName = "";
		std::string statusName = "";
		std::string accountNumber = "";
	public:
		WithdrawalView(DataLayer::withdrawalsViewCollection);
		WithdrawalView(){};
		~WithdrawalView(){};

		// WithdrawalView class Accessors
		std::string GetUsername();
		std::string GetUserSurname();
		std::string GetSubaccountNumber();
		std::string GetCurrencyName();
		std::string GetStatusName();
		std::string GetAccountNumber();
	};
}

#endif