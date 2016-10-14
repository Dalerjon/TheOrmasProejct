#include "stdafx.h"
#include "ProductListClass.h"

namespace BusinessLayer
{
	ProductList::ProductList(DataLayer::productListCollection pListCollection)
	{
		ID = std::get<0>(pListCollection);
		orderID = std::get<1>(pListCollection);
		returnID = std::get<2>(pListCollection);
		productID = std::get<3>(pListCollection);
		count = std::get<4>(pListCollection);
	}

	int ProductList::GetID()
	{
		return ID;
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
}