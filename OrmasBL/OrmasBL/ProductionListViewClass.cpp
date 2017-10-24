#include "stdafx.h"
#include "ProductionListViewClass.h"

namespace BusinessLayer
{
	ProductionListView::ProductionListView(DataLayer::productionListViewCollection pCollection)
	{
		id = std::get<0>(pCollection);
		productionID = std::get<1>(pCollection);
		productName = std::get<2>(pCollection);
		price = std::get<3>(pCollection);
		currencyName = std::get<4>(pCollection);
		volume = std::get<5>(pCollection);
		measureName = std::get<6>(pCollection);
		count = std::get<7>(pCollection);
		sum = std::get<8>(pCollection);
		sumCurrencyName = std::get<9>(pCollection);
		statusName = std::get<10>(pCollection);
		productID = std::get<11>(pCollection);
		statusID = std::get<12>(pCollection);
		currencyID = std::get<13>(pCollection);
	}

	std::string ProductionListView::GetProductName()
	{
		return productName;
	}
	double ProductionListView::GetPrice()
	{
		return price;
	}
	std::string ProductionListView::GetCurrencyName()
	{
		return currencyName;
	}
	double ProductionListView::GetVolume()
	{
		return volume;
	}
	std::string ProductionListView::GetStatusName()
	{
		return statusName;
	}
	std::string ProductionListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string ProductionListView::GetMeasureName()
	{
		return measureName;
	}

}