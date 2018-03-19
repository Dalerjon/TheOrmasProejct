#include "stdafx.h"
#include "NetCostViewClass.h"

namespace BusinessLayer{
	NetCostView::NetCostView(DataLayer::netCostViewCollection nCollection)
	{
		id = std::get<0>(nCollection);
		date = std::get<1>(nCollection);
		productName = std::get<2>(nCollection);
		volume = std::get<3>(nCollection);
		measureName = std::get<4>(nCollection);
		value = std::get<5>(nCollection);
		currencyName = std::get<6>(nCollection);
		currencyID = std::get<7>(nCollection);
		productID = std::get<8>(nCollection);
		isOutdated = std::get<9>(nCollection);
	}

	std::string NetCostView::GetProductName()
	{
		return productName;
	}

	double NetCostView::GetVolume()
	{
		return volume;
	}

	std::string NetCostView::GetMeasureName()
	{
		return measureName;
	}


	std::string NetCostView::GetCurrencyName()
	{
		return currencyName;
	}
}