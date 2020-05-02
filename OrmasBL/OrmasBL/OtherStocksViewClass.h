#ifndef OTHERSTOCKSVIEWCLASS_H
#define OTHERSTOCKSVIEWCLASS_H
#include "OtherStocksClass.h"

namespace BusinessLayer
{
	class OtherStocksView : public OtherStocks
	{
		std::string companyName = "";
		std::string currencyName = "";
		std::string measureName = "";
	public:
		OtherStocksView(DataLayer::otherStocksViewCollection);
		OtherStocksView(){};
		~OtherStocksView(){};

		//UserView class Accessors
		std::string GetCompanyName();
		std::string GetMeasureName();
		std::string GetCurrencyName();
	};
}
#endif //OtherStocksVIEWCLASS_H