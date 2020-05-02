#ifndef LOWVALUESTOCKHISTORYVIEWCLASS_H
#define LOWVALUESTOCKHISTORYVIEWCLASS_H

#include "LowValueStockHistoryClass.h"

namespace BusinessLayer
{
	class LowValueStockHistoryView : public LowValueStockHistory
	{
		std::string otherStocksName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string warehouseName = "";
		std::string subaccountNumber = "";
		std::string statusName = "";
	public:
		LowValueStockHistoryView(DataLayer::lowValueStockHistoryViewCollection);
		LowValueStockHistoryView(){};
		~LowValueStockHistoryView(){};

		//LowValueStockHistoryView class Accessors
		std::string GetOtherStocksName();
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
#endif //LowValueStockHistoryVIEWCLASS_H