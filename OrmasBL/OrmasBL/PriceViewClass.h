#ifndef PRICEVIEWCLASS_H
#define PRICEVIEWCLASS_H

#include "PriceClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class PriceView : public Price
	{
		std::string productName = ""; 
		double volume = 0.0;
		std::string measureName = "";
		std::string currencyName = "";
	public:
		PriceView(DataLayer::pricesViewCollection);
		PriceView(){};
		~PriceView(){};

		// PriceView class Accessors
		std::string GetProductName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetCurrencyName();
		
	};
}

#endif