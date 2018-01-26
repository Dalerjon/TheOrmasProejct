#include "stdafx.h"
#include "ConsumeRawListViewClass.h"

namespace BusinessLayer
{
	ConsumeRawListView::ConsumeRawListView(DataLayer::consumeRawListViewCollection cCollection)
	{
		id = std::get<0>(cCollection);
		consumeRawID = std::get<1>(cCollection);
		productName = std::get<2>(cCollection);
		price = std::get<3>(cCollection);
		currencyName = std::get<4>(cCollection);
		volume = std::get<5>(cCollection);
		measureName = std::get<6>(cCollection);
		count = std::get<7>(cCollection);
		sum = std::get<8>(cCollection);
		sumCurrencyName = std::get<9>(cCollection);
		statusName = std::get<10>(cCollection);
		productID = std::get<11>(cCollection);
		statusID = std::get<12>(cCollection);
		currencyID = std::get<13>(cCollection);
	}

	std::string ConsumeRawListView::GetProductName()
	{
		return productName;
	}
	double ConsumeRawListView::GetPrice()
	{
		return price;
	}
	std::string ConsumeRawListView::GetCurrencyName()
	{
		return currencyName;
	}
	double ConsumeRawListView::GetVolume()
	{
		return volume;
	}
	std::string ConsumeRawListView::GetStatusName()
	{
		return statusName;
	}
	std::string ConsumeRawListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string ConsumeRawListView::GetMeasureName()
	{
		return measureName;
	}

}