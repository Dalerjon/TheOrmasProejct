#include "stdafx.h"
#include "ProductTypeClass.h"

namespace BusinessLayer
{
	ProductType::ProductType(DataLayer::productTypeCollection pTypeCollection)
	{
		id = std::get<0>(pTypeCollection);
		name = std::get<1>(pTypeCollection);
		shortName = std::get<2>(pTypeCollection);
	}

	int ProductType::GetID()
	{
		return id;
	}

	std::string ProductType::GetName()
	{
		return name;
	}

	std::string ProductType::GetShortName()
	{
		return shortName;
	}

	bool ProductType::CreateProductType(DataLayer::OrmasDal& ormasDal, std::string pTypeName, std::string pTypeShortName)
	{
		id = ormasDal.GenerateID();
		name = pTypeName;
		shortName = pTypeShortName;
		try
		{
			if (ormasDal.CreateProductType(id, name, shortName))
			{
				return true;
			}
			return false;
		}
		catch (...)
		{
			return false;
		}
	}
	bool ProductType::DeleteProductType(DataLayer::OrmasDal& ormasDal)
	{
		name.clear();
		shortName.clear();
		try
		{
			if (ormasDal.DeleteProductType(id))
			{
				id = 0;
				return true;
			}
			return false;
		}
		catch (...)
		{
			return false;
		}
	}
	bool ProductType::UpdatePrdouctType(DataLayer::OrmasDal& ormasDal, std::string pTypeName, std::string pTypeShortName)
	{
		if (0 == id)
			return false;
		name = pTypeName;
		shortName = pTypeShortName;
		try
		{
			if (ormasDal.UpdateProductType(id, name, shortName))
			{
				return true;
			}
			return false;
		}
		catch (...)
		{
			return false;
		}
	}
}