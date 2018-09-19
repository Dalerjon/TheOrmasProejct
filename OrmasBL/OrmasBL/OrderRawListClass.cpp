#include "stdafx.h"
#include "OrderRawListClass.h"

namespace BusinessLayer
{
	OrderRawList::OrderRawList(DataLayer::orderRawListCollection oListCollection)
	{
		id = std::get<0>(oListCollection);
		orderRawID = std::get<1>(oListCollection);
		productID = std::get<2>(oListCollection);
		count = std::get<3>(oListCollection);
		sum = std::get<4>(oListCollection);
		statusID = std::get<5>(oListCollection);
		currencyID = std::get<6>(oListCollection);
	}

	int OrderRawList::GetID()
	{
		return id;
	}

	int OrderRawList::GetOrderRawID()
	{
		return orderRawID;
	}

	int OrderRawList::GetProductID()
	{
		return productID;
	}

	double OrderRawList::GetCount()
	{
		return count;
	}

	double OrderRawList::GetSum()
	{
		return sum;
	}

	int OrderRawList::GetStatusID()
	{
		return statusID;
	}

	int OrderRawList::GetCurrencyID()
	{
		return currencyID;
	}

	void OrderRawList::SetID(int oID)
	{
		id = oID;
	}
	void OrderRawList::SetOrderRawID(int oOrderRawID)
	{
		orderRawID = oOrderRawID;
	}
	void OrderRawList::SetProductID(int oProductID)
	{
		productID = oProductID;
	}
	void OrderRawList::SetCount(double oCount)
	{
		count = oCount;
	}
	void OrderRawList::SetSum(double oSum)
	{
		sum = oSum;
	}
	void OrderRawList::SetStatusID(int oStatusID)
	{
		statusID = oStatusID;
	}
	void OrderRawList::SetCurrencyID(int oCurrencyID)
	{
		currencyID = oCurrencyID;
	}

	bool OrderRawList::CreateOrderRawList(DataLayer::OrmasDal& ormasDal, int oID, int pID, double olCount, double olSum,
		int sID, int cID, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		orderRawID = oID;
		productID = pID;
		count = olCount;
		sum = olSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.CreateOrderRawList(id, orderRawID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool OrderRawList::CreateOrderRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateOrderRawList(id, orderRawID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool OrderRawList::DeleteOrderRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteItemInOrderRawList(id, errorMessage))
		{
			Clear();
			return true;
		}
		return false;
	}
	bool OrderRawList::DeleteListByOrderRawID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		orderRawID = oID;
		if (ormasDal.DeleteListByOrderRawID(orderRawID, errorMessage))
		{
			Clear();
			return true;
		}
		return false;
	}

	bool OrderRawList::UpdateOrderRawList(DataLayer::OrmasDal& ormasDal, int oID, int pID, double olCount, double olSum,
		int sID, int cID, std::string& errorMessage)
	{
		orderRawID = oID;
		productID = pID;
		count = olCount;
		sum = olSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.UpdateOrderRawList(id, orderRawID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool OrderRawList::UpdateOrderRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateOrderRawList(id, orderRawID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}

	std::string OrderRawList::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != orderRawID || 0 != productID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForOrderRawList(id, orderRawID, productID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool OrderRawList::GetOrderRawListByID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		id = oID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::orderRawListViewCollection> orderRawListVector = ormasDal.GetOrderRawList(errorMessage, filter);
		if (0 != orderRawListVector.size())
		{
			id = std::get<0>(orderRawListVector.at(0));
			orderRawID = std::get<1>(orderRawListVector.at(0));
			count = std::get<7>(orderRawListVector.at(0));
			sum = std::get<8>(orderRawListVector.at(0));
			productID = std::get<11>(orderRawListVector.at(0));
			statusID = std::get<12>(orderRawListVector.at(0));
			currencyID = std::get<13>(orderRawListVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find order raw list with this id";
		}
		return false;
	}

	bool OrderRawList::IsEmpty()
	{
		if (0 == id && 0 == orderRawID && 0 == count && 0 == sum && 0 == productID && 0 == statusID && 0 == currencyID)
			return true;
		return false;
	}

	void OrderRawList::Clear()
	{
		id = 0;
		orderRawID = 0;
		count = 0;
		sum = 0;
		productID = 0;
		statusID = 0;
		currencyID = 0;
	}

	bool OrderRawList::IsDuplicate(DataLayer::OrmasDal& ormasDal, int oID, int pID, double olCount, double olSum,
		int cID, std::string& errorMessage)
	{
		OrderRawList orderRawList;
		orderRawList.Clear();
		errorMessage.clear();
		orderRawList.SetOrderRawID(oID);
		orderRawList.SetProductID(pID);
		orderRawList.SetCount(olCount);
		orderRawList.SetSum(olSum);
		orderRawList.SetCurrencyID(cID);
		std::string filter = orderRawList.GenerateFilter(ormasDal);
		std::vector<DataLayer::orderRawListViewCollection> orderRawListVector = ormasDal.GetOrderRawList(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == orderRawListVector.size())
		{
			return false;
		}
		errorMessage = "Order raw list with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool OrderRawList::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		OrderRawList orderRawList;
		orderRawList.Clear();
		errorMessage.clear();
		orderRawList.SetOrderRawID(orderRawID);
		orderRawList.SetProductID(productID);
		orderRawList.SetCount(count);
		orderRawList.SetSum(sum);
		orderRawList.SetCurrencyID(currencyID);
		std::string filter = orderRawList.GenerateFilter(ormasDal);
		std::vector<DataLayer::orderRawListViewCollection> orderRawListVector = ormasDal.GetOrderRawList(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == orderRawListVector.size())
		{
			return false;
		}
		errorMessage = "Order raw list with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}