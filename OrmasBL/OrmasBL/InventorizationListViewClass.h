#ifndef INVENTORIZATIONLISTVIEWCLASS_H
#define INVENTORIZATIONLISTVIEWCLASS_H

#include "InventorizationListClass.h"

namespace BusinessLayer
{
	class InventorizationListView : public InventorizationList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		InventorizationListView(DataLayer::inventorizationListViewCollection);
		InventorizationListView(){};
		~InventorizationListView(){};

		//InventorizationListView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //InventorizationLISTVIEWCLASS_H