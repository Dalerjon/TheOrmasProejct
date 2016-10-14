#include "stdafx.h"
#include "ProductClass.h"

namespace BusinessLayer
{
	Product::Product(DataLayer::productsCollection pCollection)
	{
		ID = std::get<0>(pCollection);
		companyID = std::get<1>(pCollection);
		name = std::get<2>(pCollection);
		volume = std::get<3>(pCollection);
		measureID = std::get<4>(pCollection);
		price = std::get<5>(pCollection);
		productTypeID = std::get<6>(pCollection);
		dateProduce = std::get<7>(pCollection);
		dateEnd = std::get<8>(pCollection);
	}

	int Product::GetID()
	{
		return ID;
	}

	int Product::GetCompanyID()
	{
		return companyID;
	}

	std::string Product::GetName()
	{
		return name;
	}

	float Product::GetVolume()
	{
		return volume;
	}

	int Product::GetMeasureID()
	{
		return measureID;
	}

	float Product::GetPrice()
	{
		return price;
	}

	int Product::GetProductTypeID()
	{
		return productTypeID;
	}

	std::string Product::GetProduceDate()
	{
		return dateProduce;
	}

	std::string Product::GetEndDate()
	{
		return dateEnd;
	}
}