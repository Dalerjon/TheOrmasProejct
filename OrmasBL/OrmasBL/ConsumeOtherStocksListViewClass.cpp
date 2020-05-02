#include "stdafx.h"
#include "ConsumeOtherStocksListViewClass.h"

namespace BusinessLayer
{
	ConsumeOtherStocksListView::ConsumeOtherStocksListView(DataLayer::consumeOtherStocksListViewCollection cCollection)
	{
		id = std::get<0>(cCollection);
		consumeOtherStocksID = std::get<1>(cCollection);
		otherStocksName = std::get<2>(cCollection);
		price = std::get<3>(cCollection);
		currencyName = std::get<4>(cCollection);
		volume = std::get<5>(cCollection);
		measureName = std::get<6>(cCollection);
		count = std::get<7>(cCollection);
		sum = std::get<8>(cCollection);
		sumCurrencyName = std::get<9>(cCollection);
		statusName = std::get<10>(cCollection);
		otherStocksID = std::get<11>(cCollection);
		statusID = std::get<12>(cCollection);
		currencyID = std::get<13>(cCollection);
	}

	std::string ConsumeOtherStocksListView::GetOtherStocksName()
	{
		return otherStocksName;
	}
	double ConsumeOtherStocksListView::GetPrice()
	{
		return price;
	}
	std::string ConsumeOtherStocksListView::GetCurrencyName()
	{
		return currencyName;
	}
	double ConsumeOtherStocksListView::GetVolume()
	{
		return volume;
	}
	std::string ConsumeOtherStocksListView::GetStatusName()
	{
		return statusName;
	}
	std::string ConsumeOtherStocksListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string ConsumeOtherStocksListView::GetMeasureName()
	{
		return measureName;
	}

}