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

	bool ProductList::CreateProductList(DataLayer::OrmasDal& ormasDal, int oID, int rID, int pID, int pCount, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		orderID = oID;
		returnID = rID;
		productID = pID;
		count = pCount;
		if (0 != id && ormasDal.CreateProductList(id, orderID, returnID, productID, count, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool ProductList::CreateProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateProductList(id, orderID, returnID, productID, count, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool ProductList::DeleteProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		orderID = 0;
		returnID = 0;
		productID = 0;
		count = 0;
		if (ormasDal.DeleteProductList(id, errorMessage))
		{
			id = 0;
			return true;
		}
		return false;
	}
	bool ProductList::UpdateProductList(DataLayer::OrmasDal& ormasDal, int oID, int rID, int pID, int pCount, 
		std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		orderID = oID;
		returnID = rID;
		productID = pID;
		count = pCount;
		if (0 != id && ormasDal.UpdateProductList(id, orderID, returnID, productID, count, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool ProductList::UpdateProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateProductList(id, orderID, returnID, productID, count, errorMessage))
		{
			return true;
		}
		return false;
	}
}