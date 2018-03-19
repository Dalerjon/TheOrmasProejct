#include "stdafx.h"
#include "SpecificationListClass.h"

namespace BusinessLayer
{
	SpecificationList::SpecificationList(DataLayer::specificationListCollection sListCollection)
	{
		id = std::get<0>(sListCollection);
		specificationID = std::get<1>(sListCollection);
		productID = std::get<2>(sListCollection);
		count = std::get<3>(sListCollection);
	}

	int SpecificationList::GetID()
	{
		return id;
	}

	int SpecificationList::GetSpecificationID()
	{
		return specificationID;
	}

	int SpecificationList::GetProductID()
	{
		return productID;
	}

	double SpecificationList::GetCount()
	{
		return count;
	}

	void SpecificationList::SetID(int sID)
	{
		id = sID;
	}
	void SpecificationList::SetSpecificationID(int pSpecificationID)
	{
		specificationID = pSpecificationID;
	}
	void SpecificationList::SetProductID(int pProductID)
	{
		productID = pProductID;
	}
	void SpecificationList::SetCount(double pCount)
	{
		count = pCount;
	}

	bool SpecificationList::CreateSpecificationList(DataLayer::OrmasDal& ormasDal, int sID, int pID, double slCount, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		specificationID = sID;
		productID = pID;
		count = slCount;
		if (0 != id && ormasDal.CreateSpecificationList(id, specificationID, productID, count, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool SpecificationList::CreateSpecificationList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateSpecificationList(id, specificationID, productID, count, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool SpecificationList::DeleteSpecificationList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteItemInSpecificationList(id, errorMessage))
		{
			Clear();
			return true;
		}
		return false;
	}
	bool SpecificationList::DeleteListBySpecificationID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage)
	{
		specificationID = sID;
		if (ormasDal.DeleteListBySpecificationID(specificationID, errorMessage))
		{
			Clear();
			return true;
		}
		return false;
	}

	bool SpecificationList::UpdateSpecificationList(DataLayer::OrmasDal& ormasDal, int sID, int pID, double slCount, std::string& errorMessage)
	{
		specificationID = sID;
		productID = pID;
		count = slCount;
		if (0 != id && ormasDal.UpdateSpecificationList(id, specificationID, productID, count, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool SpecificationList::UpdateSpecificationList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateSpecificationList(id, specificationID, productID, count, errorMessage))
		{
			return true;
		}
		return false;
	}

	std::string SpecificationList::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != specificationID || 0 != productID || 0 != count)
		{
			return ormasDal.GetFilterForSpecificationList(id, specificationID, productID, count);
		}
		return "";
	}

	bool SpecificationList::GetSpecificationListByID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage)
	{
		id = sID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::specificationListViewCollection> specificationListVector = ormasDal.GetSpecificationList(errorMessage, filter);
		if (0 != specificationListVector.size())
		{
			id = std::get<0>(specificationListVector.at(0));
			specificationID = std::get<1>(specificationListVector.at(0));
			productID = std::get<5>(specificationListVector.at(0));
			count = std::get<3>(specificationListVector.at(0));			
			return true;
		}
		else
		{
			errorMessage = "Cannot find specification list with this id";
		}
		return false;
	}

	bool SpecificationList::IsEmpty()
	{
		if (0 == id && 0 == specificationID && 0 == count &&  0 == productID )
			return true;
		return false;
	}

	void SpecificationList::Clear()
	{
		id = 0;
		specificationID = 0;
		productID = 0;
		count = 0;
	}

	bool SpecificationList::IsDuplicate(DataLayer::OrmasDal& ormasDal, int sID, int pID, double slCount, std::string& errorMessage)
	{
		SpecificationList specificationList;
		specificationList.SetSpecificationID(sID);
		specificationList.SetProductID(pID);
		specificationList.SetCount(slCount);
		std::string filter = specificationList.GenerateFilter(ormasDal);
		std::vector<DataLayer::specificationListViewCollection> specificationListVector = ormasDal.GetSpecificationList(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == specificationListVector.size())
		{
			return false;
		}
		errorMessage = "Specification list with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool SpecificationList::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		SpecificationList specificationList;
		specificationList.SetSpecificationID(specificationID);
		specificationList.SetProductID(productID);
		specificationList.SetCount(count);
		std::string filter = specificationList.GenerateFilter(ormasDal);
		std::vector<DataLayer::specificationListViewCollection> specificationListVector = ormasDal.GetSpecificationList(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == specificationListVector.size())
		{
			return false;
		}
		errorMessage = "Specification list with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}