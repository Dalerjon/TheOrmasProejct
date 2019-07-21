#ifndef StockTransferLISTVIEWCLASS_H
#define StockTransferLISTVIEWCLASS_H

#include "StockTransferListClass.h"

namespace BusinessLayer
{
	class StockTransferListView : public StockTransferList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		StockTransferListView(DataLayer::stockTransferListViewCollection);
		StockTransferListView(){};
		~StockTransferListView(){};

		//StockTransferListView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //StockTransferLISTVIEWCLASS_H