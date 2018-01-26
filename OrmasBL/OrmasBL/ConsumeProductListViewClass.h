#ifndef CONSUMEPRODUCTLISTVIEWCLASS_H
#define CONSUMEPRODUCTLISTVIEWCLASS_H

#include "ConsumeProductListClass.h"

namespace BusinessLayer
{
	class ConsumeProductListView : public ConsumeProductList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		ConsumeProductListView(DataLayer::consumeProductListViewCollection);
		ConsumeProductListView(){};
		~ConsumeProductListView(){};

		//ConsumeProductListView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //ConsumeProductLISTVIEWCLASS_H