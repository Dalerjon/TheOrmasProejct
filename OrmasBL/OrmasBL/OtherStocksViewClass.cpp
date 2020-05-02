#include "stdafx.h"
#include "OtherStocksViewClass.h"

namespace BusinessLayer
{
	OtherStocksView::OtherStocksView(DataLayer::otherStocksViewCollection pCollection)
	{
		id = std::get<0>(pCollection);
		name = std::get<1>(pCollection);
		price = std::get<2>(pCollection);
		currencyName = std::get<3>(pCollection);
		volume = std::get<4>(pCollection);
		measureName = std::get<5>(pCollection);
		companyName = std::get<6>(pCollection);
		companyID = std::get<8>(pCollection);
		measureID = std::get<9>(pCollection);
		currencyID = std::get<10>(pCollection);
		otherStocksTypeID = std::get<10>(pCollection);
	}

	std::string OtherStocksView::GetCompanyName()
	{
		return companyName;
	}
	std::string OtherStocksView::GetMeasureName()
	{
		return measureName;
	}
	std::string OtherStocksView::GetCurrencyName()
	{
		return currencyName;
	}
}