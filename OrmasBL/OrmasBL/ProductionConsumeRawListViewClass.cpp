#include "stdafx.h"
#include "ProductionConsumeRawListViewClass.h"

namespace BusinessLayer
{
	ProductionConsumeRawListView::ProductionConsumeRawListView(DataLayer::productionConsumeRawListViewCollection cCollection)
	{
		id = std::get<0>(cCollection);
		ProductionConsumeRawID = std::get<1>(cCollection);
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

	std::string ProductionConsumeRawListView::GetProductName()
	{
		return productName;
	}
	double ProductionConsumeRawListView::GetPrice()
	{
		return price;
	}
	std::string ProductionConsumeRawListView::GetCurrencyName()
	{
		return currencyName;
	}
	double ProductionConsumeRawListView::GetVolume()
	{
		return volume;
	}
	std::string ProductionConsumeRawListView::GetStatusName()
	{
		return statusName;
	}
	std::string ProductionConsumeRawListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string ProductionConsumeRawListView::GetMeasureName()
	{
		return measureName;
	}

}