#ifndef SPOILAGELISTVIEWCLASS_H
#define SPOILAGELISTVIEWCLASS_H

#include "SpoilageListClass.h"

namespace BusinessLayer
{
	class SpoilageListView : public SpoilageList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		SpoilageListView(DataLayer::spoilageListViewCollection);
		SpoilageListView(){};
		~SpoilageListView(){};

		//SpoilageListView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //SPOILAGELISTVIEWCLASS_H