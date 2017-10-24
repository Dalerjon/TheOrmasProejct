#include "stdafx.h"
#include "ProductViewClass.h"

namespace BusinessLayer
{
	ProductView::ProductView(DataLayer::productsViewCollection pCollection)
	{
		id = std::get<0>(pCollection);
		name = std::get<1>(pCollection);
		price = std::get<2>(pCollection);
		currencyName = std::get<3>(pCollection);
		volume = std::get<4>(pCollection);
		measureName = std::get<5>(pCollection);
		productTypeName = std::get<6>(pCollection);
		shelfLife = std::get<7>(pCollection);
		companyName = std::get<8>(pCollection);
		companyID = std::get<9>(pCollection);
		measureID = std::get<10>(pCollection);
		productTypeID = std::get<11>(pCollection);
		currencyID = std::get<12>(pCollection);
	}

	std::string ProductView::GetCompanyName()
	{
		return companyName;
	}
	std::string ProductView::GetMeasureName()
	{
		return measureName;
	}
	std::string ProductView::GetProductTypeName()
	{
		return productTypeName;
	}
	std::string ProductView::GetCurrencyName()
	{
		return currencyName;
	}
}