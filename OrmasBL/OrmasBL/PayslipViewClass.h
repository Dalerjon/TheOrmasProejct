#ifndef PAYSLIPVIEWCLASS_H
#define PAYSLIPVIEWCLASS_H

#include "PayslipClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class PayslipView : public Payslip
	{
		std::string currencyName = "";
	public:
		PayslipView(DataLayer::payslipsViewCollection);
		PayslipView(){};
		~PayslipView(){};

		// PayslipView class Accessors
		std::string GetCurrencyName();
	};
}

#endif