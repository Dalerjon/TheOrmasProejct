#ifndef RETURNLISTVIEWCLASS_H
#define RETURNLISTVIEWCLASS_H
#include "ReturnListClass.h"

namespace BusinessLayer
{
	class ReturnListView : public ReturnList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		ReturnListView(DataLayer::returnListViewCollection);
		ReturnListView(){};
		~ReturnListView(){};

		//ReturnListView class Accessors
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