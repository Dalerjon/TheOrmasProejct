#ifndef STOCKHISTORYVIEWCLASS_H
#define STOCKHISTORYVIEWCLASS_H

#include "StockHistoryClass.h"

namespace BusinessLayer
{
	class StockHistoryView : public StockHistory
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string warehouseName = "";
		std::string subaccountNumber = "";
		std::string statusName = "";
	public:
		StockHistoryView(DataLayer::stockHistoryViewCollection);
		StockHistoryView(){};
		~StockHistoryView(){};

		//StockHistoryView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetWarehouseName();
		std::string GetSubaccountNumber();
		std::string GetStatusName();
	};
}
#endif //StockHistoryVIEWCLASS_H