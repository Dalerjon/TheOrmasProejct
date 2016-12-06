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

	void ProductType::SetID(int pID)
	{
		id = pID;
	}
	void ProductType::SetName(std::string pName)
	{
		name = pName;
	}
	void ProductType::SetShortName(std::string pShortName)
	{
		shortName = pShortName;
	}

	bool ProductType::CreateProductType(DataLayer::OrmasDal& ormasDal, std::string pTypeName, std::string pTypeShortName, 
		std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		name = pTypeName;
		shortName = pTypeShortName;
		if (0 != id && ormasDal.CreateProductType(id, name, shortName, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool ProductType::CreateProductType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id &&ormasDal.CreateProductType(id, name, shortName, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool ProductType::DeleteProductType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		name.clear();
		shortName.clear();
		if (ormasDal.DeleteProductType(id, errorMessage))
		{
			id = 0;
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}
	bool ProductType::UpdateProductType(DataLayer::OrmasDal& ormasDal, std::string pTypeName, std::string pTypeShortName, 
		std::string& errorMessage)
	{
		name = pTypeName;
		shortName = pTypeShortName;
		if (0 != id &&ormasDal.UpdateProductType(id, name, shortName, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool ProductType::UpdateProductType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateProductType(id, name, shortName, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
}