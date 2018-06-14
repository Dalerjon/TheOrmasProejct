#ifndef ProductionStockVIEWCLASS_H
#define ProductionStockVIEWCLASS_H

#include "ProductionStockClass.h"

namespace BusinessLayer
{
	class ProductionStockView : public ProductionStock
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		ProductionStockView(DataLayer::productionStockViewCollection);
		ProductionStockView(){};
		~ProductionStockView(){};

		//ProductionStockView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //ProductionStockVIEWCLASS_H