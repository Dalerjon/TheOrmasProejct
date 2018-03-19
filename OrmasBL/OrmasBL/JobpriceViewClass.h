#ifndef JOBPRICEVIEWCLASS_H
#define JOBPRICEVIEWCLASS_H

#include "JobpriceClass.h"

namespace BusinessLayer{
	class JobpriceView : public Jobprice
	{
		std::string productName = "";
		std::string currencyName = "";
		std::string measureName = "";
		std::string positionName = "";
	public:
		JobpriceView(DataLayer::jobpriceViewCollection);
		JobpriceView(){};
		~JobpriceView(){};

		// BalanceView class Accessors
		std::string GetProductName();
		std::string GetCurrencyName();
		std::string GetMeasureName();
		std::string GetPositionName();
	};
}

#endif //JOBPRICEVIEWCLASS_H