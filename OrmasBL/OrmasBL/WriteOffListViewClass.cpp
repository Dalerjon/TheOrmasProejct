#include "stdafx.h"
#include "WriteOffListViewClass.h"

namespace BusinessLayer
{
	WriteOffListView::WriteOffListView(DataLayer::writeOffListViewCollection wCollection)
	{
		id = std::get<0>(wCollection);
		writeOffID = std::get<1>(wCollection);
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

	std::string WriteOffListView::GetProductName()
	{
		return productName;
	}
	double WriteOffListView::GetPrice()
	{
		return price;
	}
	std::string WriteOffListView::GetCurrencyName()
	{
		return currencyName;
	}
	double WriteOffListView::GetVolume()
	{
		return volume;
	}
	std::string WriteOffListView::GetStatusName()
	{
		return statusName;
	}
	std::string WriteOffListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string WriteOffListView::GetMeasureName()
	{
		return measureName;
	}

}