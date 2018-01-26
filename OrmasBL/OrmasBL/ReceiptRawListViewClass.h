#ifndef RECEIPTRAWLISTVIEWCLASS_H
#define RECEIPTRAWLISTVIEWCLASS_H

#include "ReceiptRawListClass.h"

namespace BusinessLayer
{
	class ReceiptRawListView : public ReceiptRawList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		ReceiptRawListView(DataLayer::receiptRawListViewCollection);
		ReceiptRawListView(){};
		~ReceiptRawListView(){};

		//ReceiptRawListView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //RECEIPTRAWLISTVIEWCLASS_H