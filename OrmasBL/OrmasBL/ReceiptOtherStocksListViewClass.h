#ifndef RECEIPTOTHERSTOCKSLISTVIEWCLASS_H
#define RECEIPTOTHERSTOCKSLISTVIEWCLASS_H

#include "ReceiptOtherStocksListClass.h"

namespace BusinessLayer
{
	class ReceiptOtherStocksListView : public ReceiptOtherStocksList
	{
		std::string otherStocksName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		ReceiptOtherStocksListView(DataLayer::receiptOtherStocksListViewCollection);
		ReceiptOtherStocksListView(){};
		~ReceiptOtherStocksListView(){};

		//ReceiptOtherStocksListView class Accessors
		std::string GetOtherStocksName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //ReceiptOtherStocksLISTVIEWCLASS_H