#ifndef LOWVALUESTOCKVIEWCLASS_H
#define LOWVALUESTOCKVIEWCLASS_H

#include "LowValueStockClass.h"

namespace BusinessLayer
{
	class LowValueStockView : public LowValueStock
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
		LowValueStockView(DataLayer::lowValueStockViewCollection);
		LowValueStockView(){};
		~LowValueStockView(){};

		//LowValueStockView class Accessors
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
#endif //LowValueStockVIEWCLASS_H