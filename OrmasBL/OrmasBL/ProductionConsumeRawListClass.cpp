#include "stdafx.h"
#include "ProductionConsumeRawListClass.h"
#include "ProductionConsumeRawClass.h"
#include "StockClass.h"
#include "WarehouseEmployeeRelationClass.h"

namespace BusinessLayer
{
	ProductionConsumeRawList::ProductionConsumeRawList(DataLayer::productionConsumeRawListCollection cListCollection)
	{
		id = std::get<0>(cListCollection);
		productionConsumeRawID = std::get<1>(cListCollection);
		productID = std::get<2>(cListCollection);
		count = std::get<3>(cListCollection);
		sum = std::get<4>(cListCollection);
		statusID = std::get<5>(cListCollection);
		currencyID = std::get<6>(cListCollection);
	}

	int ProductionConsumeRawList::GetID()
	{
		return id;
	}

	int ProductionConsumeRawList::GetProductionConsumeRawID()
	{
		return productionConsumeRawID;
	}

	int ProductionConsumeRawList::GetProductID()
	{
		return productID;
	}

	double ProductionConsumeRawList::GetCount()
	{
		return count;
	}

	double ProductionConsumeRawList::GetSum()
	{
		return sum;
	}

	int ProductionConsumeRawList::GetStatusID()
	{
		return statusID;
	}

	int ProductionConsumeRawList::GetCurrencyID()
	{
		return currencyID;
	}

	void ProductionConsumeRawList::SetID(int cID)
	{
		id = cID;
	}
	void ProductionConsumeRawList::SetProductionConsumeRawID(int cProductionConsumeRawID)
	{
		productionConsumeRawID = cProductionConsumeRawID;
	}
	void ProductionConsumeRawList::SetProductID(int cProductID)
	{
		productID = cProductID;
	}
	void ProductionConsumeRawList::SetCount(double cCount)
	{
		count = cCount;
	}
	void ProductionConsumeRawList::SetSum(double cSum)
	{
		sum = cSum;
	}
	void ProductionConsumeRawList::SetStatusID(int cStatusID)
	{
		statusID = cStatusID;
	}
	void ProductionConsumeRawList::SetCurrencyID(int cCurrencyID)
	{
		currencyID = cCurrencyID;
	}

	bool ProductionConsumeRawList::CreateProductionConsumeRawList(DataLayer::OrmasDal& ormasDal, int crID, int pID, double crlCount, double crlSum,
		int sID, int cID, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		productionConsumeRawID = crID;
		productID = pID;
		count = crlCount;
		sum = crlSum;
		statusID = sID;
		currencyID = cID;
		double middlePrice = CalculateMiddleSum(ormasDal, stockEmployeeID, pID, errorMessage);
		if (0 == middlePrice)
			return false;
		sum = crlCount * middlePrice;
		if (0 != id && ormasDal.CreateProductionConsumeRawList(id, productionConsumeRawID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool ProductionConsumeRawList::CreateProductionConsumeRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		double middlePrice = CalculateMiddleSum(ormasDal, stockEmployeeID, productID, errorMessage);
		if (0 == middlePrice)
			return false;
		sum = count * middlePrice;
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateProductionConsumeRawList(id, productionConsumeRawID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool ProductionConsumeRawList::DeleteProductionConsumeRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteItemInProductionConsumeRawList(id, errorMessage))
		{
			Clear();
			return true;
		}
		return false;
	}
	bool ProductionConsumeRawList::DeleteListByProductionConsumeRawID(DataLayer::OrmasDal& ormasDal, int crID, std::string& errorMessage)
	{
		productionConsumeRawID = crID;
		if (ormasDal.DeleteListByProductionConsumeRawID(productionConsumeRawID, errorMessage))
		{
			Clear();
			return true;
		}
		return false;
	}

	bool ProductionConsumeRawList::UpdateProductionConsumeRawList(DataLayer::OrmasDal& ormasDal, int crID, int pID, double crlCount, double crlSum,
		int sID, int cID, std::string& errorMessage)
	{
		productionConsumeRawID = crID;
		productID = pID;
		count = crlCount;
		sum = crlSum;
		statusID = sID;
		currencyID = cID;
		double middlePrice = CalculateMiddleSum(ormasDal, stockEmployeeID, pID, errorMessage);
		if (0 == middlePrice)
			return false;
		sum = crlCount * middlePrice;
		if (0 != id && ormasDal.UpdateProductionConsumeRawList(id, productionConsumeRawID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool ProductionConsumeRawList::UpdateProductionConsumeRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		double middlePrice = CalculateMiddleSum(ormasDal, stockEmployeeID, productID, errorMessage);
		if (0 == middlePrice)
			return false;
		sum = count * middlePrice;
		if (0 != id && ormasDal.UpdateProductionConsumeRawList(id, productionConsumeRawID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}

	std::string ProductionConsumeRawList::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != productionConsumeRawID || 0 != productID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForProductionConsumeRawList(id, productionConsumeRawID, productID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool ProductionConsumeRawList::GetProductionConsumeRawListByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		if (pID <= 0)
			return false;
		id = pID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::productionConsumeRawListViewCollection> productionConsumeRawListVector = ormasDal.GetProductionConsumeRawList(errorMessage, filter);
		if (0 != productionConsumeRawListVector.size())
		{
			id = std::get<0>(productionConsumeRawListVector.at(0));
			productionConsumeRawID = std::get<1>(productionConsumeRawListVector.at(0));
			count = std::get<7>(productionConsumeRawListVector.at(0));
			sum = std::get<8>(productionConsumeRawListVector.at(0));
			productID = std::get<11>(productionConsumeRawListVector.at(0));
			statusID = std::get<12>(productionConsumeRawListVector.at(0));
			currencyID = std::get<13>(productionConsumeRawListVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find consume raw list with this id";
		}
		return false;
	}

	bool ProductionConsumeRawList::IsEmpty()
	{
		if (0 == id && 0 == productionConsumeRawID && 0 == count && 0 == sum && 0 == productID && 0 == statusID && 0 == currencyID)
			return true;
		return false;
	}

	void ProductionConsumeRawList::Clear()
	{
		id = 0;
		productionConsumeRawID = 0;
		count = 0;
		sum = 0;
		productID = 0;
		statusID = 0;
		currencyID = 0;
	}

	bool ProductionConsumeRawList::IsDuplicate(DataLayer::OrmasDal& ormasDal, int crID, int pID, double crlCount, double crlSum,
		int cID, std::string& errorMessage)
	{
		ProductionConsumeRawList productionConsumeRawList;
		productionConsumeRawList.Clear();
		errorMessage.clear();
		productionConsumeRawList.SetProductionConsumeRawID(crID);
		productionConsumeRawList.SetProductID(pID);
		productionConsumeRawList.SetCount(crlCount);
		productionConsumeRawList.SetSum(crlSum);
		productionConsumeRawList.SetCurrencyID(cID);
		std::string filter = productionConsumeRawList.GenerateFilter(ormasDal);
		std::vector<DataLayer::productionConsumeRawListViewCollection> productionConsumeRawListVector = ormasDal.GetProductionConsumeRawList(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == productionConsumeRawListVector.size())
		{
			return false;
		}
		errorMessage = "Production consume raw list with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool ProductionConsumeRawList::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		ProductionConsumeRawList productionConsumeRawList;
		productionConsumeRawList.Clear();
		errorMessage.clear();
		productionConsumeRawList.SetProductionConsumeRawID(productionConsumeRawID);
		productionConsumeRawList.SetProductID(productID);
		productionConsumeRawList.SetCount(count);
		productionConsumeRawList.SetSum(sum);
		productionConsumeRawList.SetCurrencyID(currencyID);
		std::string filter = productionConsumeRawList.GenerateFilter(ormasDal);
		std::vector<DataLayer::productionConsumeRawListViewCollection> productionConsumeRawListVector = ormasDal.GetProductionConsumeRawList(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == productionConsumeRawListVector.size())
		{
			return false;
		}
		errorMessage = "Production consume raw list with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
	double ProductionConsumeRawList::CalculateMiddleSum(DataLayer::OrmasDal& ormasDal, int seID, int pID, std::string& errorMessage)
	{
		WarehouseEmployeeRelation weRel;
		Stock stock;
		double mPrice;
		if (!weRel.GetWarehouseEmployeeByEmployeeID(ormasDal, seID, errorMessage))
			return 0;
		if (!stock.GetStockByProductAndWarehouseID(ormasDal, pID, weRel.GetWarehouseID(), errorMessage))
		{
			return 0;
		}
		else
		{
			mPrice = std::round(stock.GetSum() / stock.GetCount() * 1000) / 1000;
			return mPrice;
		}
		return 0;
	}
}