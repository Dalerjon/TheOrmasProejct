#ifndef STOCKVIEWCLASS_H
#define STOCKVIEWCLASS_H

#include "StockClass.h"

namespace BusinessLayer
{
	class StockView : public Stock
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		StockView(DataLayer::stockViewCollection);
		StockView(){};
		~StockView(){};

		//StockView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //StockVIEWCLASS_H