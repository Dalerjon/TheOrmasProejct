#ifndef ORDERRAWLISTVIEWCLASS_H
#define ORDEREAWLISTVIEWCLASS_H

#include "OrderRawListClass.h"

namespace BusinessLayer
{
	class OrderRawListView : public OrderRawList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		OrderRawListView(DataLayer::orderRawListViewCollection);
		OrderRawListView(){};
		~OrderRawListView(){};

		//OrderRawListView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //OrderRawLISTVIEWCLASS_H