#include "stdafx.h"
#include "TransportListViewClass.h"

namespace BusinessLayer
{
	TransportListView::TransportListView(DataLayer::transportListViewCollection tCollection)
	{
		id = std::get<0>(tCollection);
		transportID = std::get<1>(tCollection);
		productName = std::get<2>(tCollection);
		price = std::get<3>(tCollection);
		currencyName = std::get<4>(tCollection);
		volume = std::get<5>(tCollection);
		measureName = std::get<6>(tCollection);
		count = std::get<7>(tCollection);
		sum = std::get<8>(tCollection);
		sumCurrencyName = std::get<9>(tCollection);
		statusName = std::get<10>(tCollection);
		productID = std::get<11>(tCollection);
		statusID = std::get<12>(tCollection);
		currencyID = std::get<13>(tCollection);
	}

	std::string TransportListView::GetProductName()
	{
		return productName;
	}
	double TransportListView::GetPrice()
	{
		return price;
	}
	std::string TransportListView::GetCurrencyName()
	{
		return currencyName;
	}
	double TransportListView::GetVolume()
	{
		return volume;
	}
	std::string TransportListView::GetStatusName()
	{
		return statusName;
	}
	std::string TransportListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string TransportListView::GetMeasureName()
	{
		return measureName;
	}

}