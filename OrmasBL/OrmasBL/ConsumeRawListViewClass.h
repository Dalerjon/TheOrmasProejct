#ifndef CONSUMERAWLISTVIEWCLASS_H
#define CONSUMERAWLISTVIEWCLASS_H

#include "ConsumeRawListClass.h"

namespace BusinessLayer
{
	class ConsumeRawListView : public ConsumeRawList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		ConsumeRawListView(DataLayer::consumeRawListViewCollection);
		ConsumeRawListView(){};
		~ConsumeRawListView(){};

		//ConsumeRawListView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //ConsumeRawLISTVIEWCLASS_H