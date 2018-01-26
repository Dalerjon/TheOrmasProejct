#include "stdafx.h"
#include "WriteOffRawListViewClass.h"

namespace BusinessLayer
{
	WriteOffRawListView::WriteOffRawListView(DataLayer::writeOffRawListViewCollection wCollection)
	{
		id = std::get<0>(wCollection);
		writeOffRawID = std::get<1>(wCollection);
		productName = std::get<2>(wCollection);
		price = std::get<3>(wCollection);
		currencyName = std::get<4>(wCollection);
		volume = std::get<5>(wCollection);
		measureName = std::get<6>(wCollection);
		count = std::get<7>(wCollection);
		sum = std::get<8>(wCollection);
		sumCurrencyName = std::get<9>(wCollection);
		statusName = std::get<10>(wCollection);
		productID = std::get<11>(wCollection);
		statusID = std::get<12>(wCollection);
		currencyID = std::get<13>(wCollection);
	}

	std::string WriteOffRawListView::GetProductName()
	{
		return productName;
	}
	double WriteOffRawListView::GetPrice()
	{
		return price;
	}
	std::string WriteOffRawListView::GetCurrencyName()
	{
		return currencyName;
	}
	double WriteOffRawListView::GetVolume()
	{
		return volume;
	}
	std::string WriteOffRawListView::GetStatusName()
	{
		return statusName;
	}
	std::string WriteOffRawListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string WriteOffRawListView::GetMeasureName()
	{
		return measureName;
	}

}