#ifndef WITHDRAWALVIEWCLASS_H
#define WITHDRAWALVIEWCLASS_H

#include "WithdrawalClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class WithdrawalView : public Withdrawal
	{
		std::string currencyName = "";
	public:
		WithdrawalView(DataLayer::withdrawalsViewCollection);
		WithdrawalView(){};
		~WithdrawalView(){};

		// WithdrawalView class Accessors
		std::string GetCurrencyName();
	};
}

#endif