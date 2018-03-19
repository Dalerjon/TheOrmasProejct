#include "stdafx.h"
#include "PriceViewClass.h"

namespace BusinessLayer{
	PriceView::PriceView(DataLayer::pricesViewCollection pCollection)
	{
		id = std::get<0>(pCollection);
		date = std::get<1>(pCollection);
		productName = std::get<2>(pCollection);
		volume = std::get<3>(pCollection);
		measureName = std::get<4>(pCollection);
		value = std::get<5>(pCollection);
		currencyName = std::get<6>(pCollection);
		currencyID = std::get<7>(pCollection);
		productID = std::get<8>(pCollection);
		isOutdated = std::get<9>(pCollection);
	}

	std::string PriceView::GetProductName()
	{
		return productName;
	}

	double PriceView::GetVolume()
	{
		return volume;
	}

	std::string PriceView::GetMeasureName()
	{
		return measureName;
	}


	std::string PriceView::GetCurrencyName()
	{
		return currencyName;
	}
}