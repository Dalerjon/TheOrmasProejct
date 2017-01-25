#include "stdafx.h"
#include "ProductListClass.h"

namespace BusinessLayer
{
	ProductList::ProductList(DataLayer::productListCollection pListCollection)
	{
		id = std::get<0>(pListCollection);
		orderID = std::get<1>(pListCollection);
		returnID = std::get<2>(pListCollection);
		productionID = std::get<3>(pListCollection);
		productID = std::get<4>(pListCollection);
		count = std::get<5>(pListCollection);
		sum = std::get<6>(pListCollection);
		statusID = std::get<7>(pListCollection);
		currencyID = std::get<8>(pListCollection);
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

	int ProductList::GetProductionID()
	{
		return productionID;
	}

	int ProductList::GetProductID()
	{
		return productID;
	}

	int ProductList::GetCount()
	{
		return count;
	}
	
	double ProductList::GetSum()
	{
		return sum;
	}
	
	int ProductList::GetStatusID()
	{
		return statusID;
	}

	int ProductList::GetCurrencyID()
	{
		return currencyID;
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
	void ProductList::SetProductionID(int pProductionID)
	{
		productionID = pProductionID;
	}
	void ProductList::SetProductID(int pProductID)
	{
		productID = pProductID;
	}
	void ProductList::SetCount(int pCount)
	{
		count = pCount;
	}
	void ProductList::SetSum(double pSum)
	{
		sum = pSum;
	}
	void ProductList::SetStatusID(int pStatusID)
	{
		statusID = pStatusID;
	}
	void ProductList::SetCurrencyID(int pCurrencyID)
	{
		currencyID = pCurrencyID;
	}

	bool ProductList::CreateProductList(DataLayer::OrmasDal& ormasDal, int oID, int rID, int pnID, int pID, int pCount, double pSum,
		int sID, int cID, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		orderID = oID;
		returnID = rID;
		productionID = pnID;
		productID = pID;
		count = pCount;
		sum = pSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.CreateProductList(id, orderID, returnID, productionID, productID, count, sum, statusID, currencyID,
			errorMessage))
		{
			return true;
		}
		return false;
	}
	bool ProductList::CreateProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateProductList(id, orderID, returnID, productionID, productID, count, sum, statusID, currencyID, 
			errorMessage))
		{
			return true;
		}
		return false;
	}
	bool ProductList::DeleteProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		orderID = 0;
		returnID = 0;
		productionID = 0;
		productID = 0;
		count = 0;
		sum = 0;
		statusID = 0;
		currencyID = 0;
		if (ormasDal.DeleteProductList(id, errorMessage))
		{
			id = 0;
			return true;
		}
		return false;
	}
	bool ProductList::UpdateProductList(DataLayer::OrmasDal& ormasDal, int oID, int rID, int pnID, int pID, int pCount, double pSum,
		int sID, int cID, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		orderID = oID;
		returnID = rID;
		productionID = pnID;
		productID = pID;
		count = pCount;
		sum = pSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.UpdateProductList(id, orderID, returnID, productionID, productID, count, sum, statusID, currencyID,
			errorMessage))
		{
			return true;
		}
		return false;
	}
	bool ProductList::UpdateProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateProductList(id, orderID, returnID, productionID, productID, count, sum, statusID, currencyID,
			errorMessage))
		{
			return true;
		}
		return false;
	}

	std::string ProductList::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != orderID || 0 != returnID || 0 != productionID || 0 != productID || 0 != count 
			|| 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForProductList(id, orderID, returnID, productionID, productID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool ProductList::GetProductListByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		id = pID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::productListViewCollection> productListVector = ormasDal.GetProductLists(errorMessage, filter);
		if (0 != productListVector.size())
		{
			id = std::get<0>(productListVector.at(0));
			orderID = std::get<1>(productListVector.at(0));
			returnID = std::get<2>(productListVector.at(0));
			productionID = std::get<3>(productListVector.at(0));
			count = std::get<9>(productListVector.at(0));
			sum = std::get<10>(productListVector.at(0));
			productID = std::get<13>(productListVector.at(0));
			statusID = std::get<14>(productListVector.at(0));
			currencyID = std::get<15>(productListVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find product list with this id";
		}
		return false;
	}
	bool ProductList::IsEmpty()
	{
		if (0 == id && 0 == orderID && 0 == returnID && 0 == productionID && 0 == count && 0 == sum && 0 == productID
			&& 0 == statusID && 0 == currencyID)
			return true;
		return false;
	}
}