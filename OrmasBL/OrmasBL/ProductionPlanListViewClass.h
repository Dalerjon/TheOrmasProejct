#ifndef PRODUCTIONPLANLISTVIEWCLASS_H
#define PRODUCTIONPLANLISTVIEWCLASS_H

#include "ProductionPlanListClass.h"

namespace BusinessLayer
{
	class ProductionPlanListView : public ProductionPlanList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		ProductionPlanListView(DataLayer::productionPlanListViewCollection);
		ProductionPlanListView(){};
		~ProductionPlanListView(){};

		//ProductionPlanListView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //PRODUCTIONPLANLISTVIEWCLASS_H