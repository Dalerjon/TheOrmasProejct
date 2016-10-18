#include "stdafx.h"
#include "ProductClass.h"

namespace BusinessLayer
{
	Product::Product(DataLayer::productsCollection pCollection)
	{
		id = std::get<0>(pCollection);
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
		return id;
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

	bool Product::CreateProduct(DataLayer::OrmasDal& ormasDal, int cID, std::string pName, float vol, int mID, float pri,
		int pTypeID, std::string dProduce, std::string dEnd)
	{
		id = ormasDal.GenerateID();
		companyID = cID;
		name = pName;
		volume = vol;
		measureID = mID;
		price = pri;
		productTypeID = pTypeID;
		dateProduce = dProduce;
		dateEnd = dEnd;
		try
		{
			if (ormasDal.CreateProduct(id, companyID, name, volume, measureID, price, productTypeID, dateProduce, dateEnd))
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
	bool Product::DeleteProduct(DataLayer::OrmasDal& ormasDal)
	{
		companyID = 0;
		name.clear();
		volume = 0.0;;
		measureID = 0;
		price =  0.0;
		productTypeID = 0;
		dateProduce.clear();
		dateEnd.clear();
		try
		{
			if (ormasDal.DeleteProduct(id))
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
	bool Product::UpdateProduct(DataLayer::OrmasDal& ormasDal, int cID, std::string pName, float vol, int mID, float pri,
		int pTypeID, std::string dProduce, std::string dEnd)
	{
		if (0 == id)
			return false;
		id = ormasDal.GenerateID();
		companyID = cID;
		name = pName;
		volume = vol;
		measureID = mID;
		price = pri;
		productTypeID = pTypeID;
		dateProduce = dProduce;
		dateEnd = dEnd;
		try
		{
			if (ormasDal.UpdateProduct(id, companyID, name, volume, measureID, price, productTypeID, dateProduce, dateEnd))
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