#ifndef TRANSPORTLISTVIEWCLASS_H
#define TRANSPORTLISTVIEWCLASS_H

#include "TransportListClass.h"

namespace BusinessLayer
{
	class TransportListView : public TransportList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		TransportListView(DataLayer::transportListViewCollection);
		TransportListView(){};
		~TransportListView(){};

		//TransportListView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //TransportLISTVIEWCLASS_H