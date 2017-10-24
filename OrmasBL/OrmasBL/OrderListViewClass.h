#ifndef ORDERLISTVIEWCLASS_H
#define ORDERLISTVIEWCLASS_H

#include "OrderListClass.h"

namespace BusinessLayer
{
	class OrderListView : public OrderList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		OrderListView(DataLayer::orderListViewCollection);
		OrderListView(){};
		~OrderListView(){};

		//OrderListView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName(); 
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //ORDERLISTVIEWCLASS_H