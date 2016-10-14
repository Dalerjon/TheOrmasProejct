#include "stdafx.h"
#include "ProductTypeClass.h"

namespace BusinessLayer
{
	ProductType::ProductType(DataLayer::productTypeCollection pTypeCollection)
	{
		ID = std::get<0>(pTypeCollection);
		name = std::get<1>(pTypeCollection);
		shortName = std::get<2>(pTypeCollection);
	}

	int ProductType::GetID()
	{
		return ID;
	}

	std::string ProductType::GetName()
	{
		return name;
	}

	std::string ProductType::GetShortName()
	{
		return shortName;
	}
}