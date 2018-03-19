#include "stdafx.h"
#include "SpoilageListViewClass.h"

namespace BusinessLayer
{
	SpoilageListView::SpoilageListView(DataLayer::spoilageListViewCollection sCollection)
	{
		id = std::get<0>(sCollection);
		spoilageID = std::get<1>(sCollection);
		productName = std::get<2>(sCollection);
		price = std::get<3>(sCollection);
		currencyName = std::get<4>(sCollection);
		volume = std::get<5>(sCollection);
		measureName = std::get<6>(sCollection);
		count = std::get<7>(sCollection);
		sum = std::get<8>(sCollection);
		sumCurrencyName = std::get<9>(sCollection);
		statusName = std::get<10>(sCollection);
		productID = std::get<11>(sCollection);
		statusID = std::get<12>(sCollection);
		currencyID = std::get<13>(sCollection);
	}

	std::string SpoilageListView::GetProductName()
	{
		return productName;
	}
	double SpoilageListView::GetPrice()
	{
		return price;
	}
	std::string SpoilageListView::GetCurrencyName()
	{
		return currencyName;
	}
	double SpoilageListView::GetVolume()
	{
		return volume;
	}
	std::string SpoilageListView::GetStatusName()
	{
		return statusName;
	}
	std::string SpoilageListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string SpoilageListView::GetMeasureName()
	{
		return measureName;
	}

}