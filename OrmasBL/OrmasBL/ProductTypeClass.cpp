#include "stdafx.h"
#include "ProductTypeClass.h"
#include <boost/algorithm/string.hpp>

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
		if (!pName.empty())
			boost::trim(pName);
		name = pName;
	}
	void ProductType::SetShortName(std::string pShortName)
	{
		if (!pShortName.empty())
			boost::trim(pShortName);
		shortName = pShortName;
	}

	bool ProductType::CreateProductType(DataLayer::OrmasDal& ormasDal, std::string pTypeName, std::string pTypeShortName, 
		std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, pTypeName, pTypeShortName, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		TrimStrings(pTypeName, pTypeShortName);
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
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
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
		if (ormasDal.DeleteProductType(id, errorMessage))
		{
			Clear();
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
		TrimStrings(pTypeName, pTypeShortName);
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

	std::string ProductType::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !name.empty() || !shortName.empty())
		{
			return ormasDal.GetFilterForProductType(id, name, shortName);
		}
		return "";
	}

	bool ProductType::GetProductTypeByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		id = pID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::productTypeCollection> productTypeVector = ormasDal.GetProductTypes(errorMessage, filter);
		if (0 != productTypeVector.size())
		{
			id = std::get<0>(productTypeVector.at(0));
			name = std::get<1>(productTypeVector.at(0));
			shortName = std::get<2>(productTypeVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find product type with this id";
		}
		return false;
	}
	
	bool ProductType::IsEmpty()
	{
		if (0 == id && name == "" && shortName == "")
			return true;
		return false;
	}

	void ProductType::Clear()
	{
		id = 0;
		name.clear();
		shortName.clear();
	}

	void ProductType::TrimStrings(std::string& pTypeName, std::string& pTypeShortName)
	{
		if (!pTypeName.empty())
			boost::trim(pTypeName);
		if (!pTypeShortName.empty())
			boost::trim(pTypeShortName);
	}

	bool ProductType::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string pTypeName, std::string pTypeShortName, std::string& errorMessage)
	{
		ProductType productType;
		productType.SetName(pTypeName);
		productType.SetShortName(pTypeShortName);
		std::string filter = productType.GenerateFilter(ormasDal);
		std::vector<DataLayer::productTypeCollection> productTypeVector = ormasDal.GetProductTypes(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == productTypeVector.size())
		{
			return false;
		}
		errorMessage = "Product type with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool ProductType::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		ProductType productType;
		productType.SetName(name);
		productType.SetShortName(shortName);
		std::string filter = productType.GenerateFilter(ormasDal);
		std::vector<DataLayer::productTypeCollection> productTypeVector = ormasDal.GetProductTypes(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == productTypeVector.size())
		{
			return false;
		}
		errorMessage = "Product type with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}