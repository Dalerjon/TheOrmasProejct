#ifndef PRODUCTIONLISTVIEWCLASS_H
#define PRODUCTIONLISTVIEWCLASS_H
#include "ProductionListClass.h"

namespace BusinessLayer
{
	class ProductionListView : public ProductionList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		ProductionListView(DataLayer::productionListViewCollection);
		ProductionListView(){};
		~ProductionListView(){};

		//ProductionListView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}

#endif