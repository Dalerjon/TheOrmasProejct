#include "stdafx.h"
#include "ProductListClass.h"

namespace BusinessLayer
{
	ProductList::ProductList(DataLayer::productListCollection pListCollection)
	{
		id = std::get<0>(pListCollection);
		orderID = std::get<1>(pListCollection);
		returnID = std::get<2>(pListCollection);
		productID = std::get<3>(pListCollection);
		count = std::get<4>(pListCollection);
	}

	int ProductList::GetID()
	{
		return id;
	}

	int ProductList::GetOrderID()
	{
		return orderID;
	}

	int ProductList::GetReturnID()
	{
		return returnID;
	}

	int ProductList::GetProductID()
	{
		return productID;
	}

	int ProductList::GetCount()
	{
		return count;
	}

	void ProductList::SetID(int pID)
	{
		id = pID;
	}
	void ProductList::SetOrderID(int pOrderID)
	{
		orderID = pOrderID;
	}
	void ProductList::SetReturnID(int pReturnID)
	{
		returnID = pReturnID;
	}
	void ProductList::SetProductID(int pProductID)
	{
		productID = pProductID;
	}
	void ProductList::SetCount(int pCount)
	{
		count = pCount;
	}

	bool ProductList::CreateProductList(DataLayer::OrmasDal& ormasDal, int oID, int rID, int pID, int pCount)
	{
		id = ormasDal.GenerateID();
		orderID = oID;
		returnID = rID;
		productID = pID;
		count = pCount;
		try
		{
			if (ormasDal.CreateProductList(id, orderID, returnID, productID, count))
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
	bool ProductList::DeleteProductList(DataLayer::OrmasDal& ormasDal)
	{
		orderID = 0;
		returnID = 0;
		productID = 0;
		count = 0;
		try
		{
			if (ormasDal.DeleteProductList(id))
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
	bool ProductList::UpdateProductList(DataLayer::OrmasDal& ormasDal, int oID, int rID, int pID, int pCount)
	{
		if (0 == id)
			return false;
		id = ormasDal.GenerateID();
		orderID = oID;
		returnID = rID;
		productID = pID;
		count = pCount;
		try
		{
			if (ormasDal.UpdateProductList(id, orderID, returnID, productID, count))
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