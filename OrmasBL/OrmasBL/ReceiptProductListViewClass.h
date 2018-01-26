#ifndef RECEIPTPRODUCTLISTVIEWCLASS_H
#define RECEIPTPRODUCTLISTVIEWCLASS_H

#include "ReceiptProductListClass.h"

namespace BusinessLayer
{
	class ReceiptProductListView : public ReceiptProductList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		ReceiptProductListView(DataLayer::receiptProductListViewCollection);
		ReceiptProductListView(){};
		~ReceiptProductListView(){};

		//ReceiptProductListView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //RECEIPTPRODUCTLISTVIEWCLASS_H