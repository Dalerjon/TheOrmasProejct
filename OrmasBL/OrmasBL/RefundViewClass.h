#ifndef REFUNDVIEWCLASS_H
#define REFUNDVIEWCLASS_H

#include "RefundClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class RefundView : public Refund
	{
		std::string currencyName = "";
	public:
		RefundView(DataLayer::refundsViewCollection);
		RefundView(){};
		~RefundView(){};

		// RefundView class Accessors
		std::string GetCurrencyName();
	};
}

#endif