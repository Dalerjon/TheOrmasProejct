#ifndef PAYMENTVIEWCLASS_H
#define PAYMENTVIEWCLASS_H

#include "PaymentClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class PaymentView : public Payment
	{
		std::string currencyName = "";
	public:
		PaymentView(DataLayer::paymentsViewCollection);
		PaymentView(){};
		~PaymentView(){};

		// PaymentView class Accessors
		std::string GetCurrencyName();
	};
}

#endif