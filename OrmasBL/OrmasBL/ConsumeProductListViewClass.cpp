#include "stdafx.h"
#include "ConsumeProductListViewClass.h"

namespace BusinessLayer
{
	ConsumeProductListView::ConsumeProductListView(DataLayer::consumeProductListViewCollection cCollection)
	{
		id = std::get<0>(cCollection);
		consumeProductID = std::get<1>(cCollection);
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

	std::string ConsumeProductListView::GetProductName()
	{
		return productName;
	}
	double ConsumeProductListView::GetPrice()
	{
		return price;
	}
	std::string ConsumeProductListView::GetCurrencyName()
	{
		return currencyName;
	}
	double ConsumeProductListView::GetVolume()
	{
		return volume;
	}
	std::string ConsumeProductListView::GetStatusName()
	{
		return statusName;
	}
	std::string ConsumeProductListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string ConsumeProductListView::GetMeasureName()
	{
		return measureName;
	}

}