#ifndef WRITEOFFRAWLISTVIEWCLASS_H
#define WRITEOFFRAWLISTVIEWCLASS_H

#include "WriteOffRawListClass.h"

namespace BusinessLayer
{
	class WriteOffRawListView : public WriteOffRawList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string measureName = "";
		std::string sumCurrencyName = "";
		std::string statusName = "";
	public:
		WriteOffRawListView(DataLayer::writeOffRawListViewCollection);
		WriteOffRawListView(){};
		~WriteOffRawListView(){};

		//WriteOffRawListView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetMeasureName();
		std::string GetSumCurrencyName();
		std::string GetStatusName();
	};
}
#endif //WRITEOFFRAWLISTVIEWCLASS_H