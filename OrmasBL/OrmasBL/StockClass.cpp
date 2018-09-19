#include "stdafx.h"
#include "StockClass.h"
#include "BalanceClass.h"
#include "OrderRawClass.h"
#include "OrderRawListClass.h"
#include "OrderRawListViewClass.h"
#include "ConsumeProductListClass.h"
#include "ConsumeProductListViewClass.h"
#include "ConsumeRawListClass.h"
#include "ConsumeRawListViewClass.h"
#include "ReceiptProductListClass.h"
#include "ReceiptProductListViewClass.h"
#include "ReceiptRawListClass.h"
#include "ReceiptRawListViewClass.h"
#include "ReturnListClass.h"
#include "ReturnListViewClass.h"
#include "WriteOffListClass.h"
#include "WriteOffListViewClass.h"
#include "WriteOffRawListClass.h"
#include "WriteOffRawListViewClass.h"
#include "ProductClass.h"
#include "StatusClass.h"
#include "EntryClass.h"
#include "AccountClass.h"
#include "SubaccountClass.h"
#include "CompanyAccountRelationClass.h"
#include "NetCostClass.h"
#include <codecvt>

namespace BusinessLayer
{
	Stock::Stock(DataLayer::stockCollection sCollection)
	{
		id = std::get<0>(sCollection);
		productID = std::get<1>(sCollection);
		count = std::get<2>(sCollection);
		sum = std::get<3>(sCollection);
		statusID = std::get<4>(sCollection);
		currencyID = std::get<5>(sCollection);
	}

	int Stock::GetID()
	{
		return id;
	}

	int Stock::GetProductID()
	{
		return productID;
	}

	double Stock::GetCount()
	{
		return count;
	}

	double Stock::GetSum()
	{
		return sum;
	}

	int Stock::GetStatusID()
	{
		return statusID;
	}

	int Stock::GetCurrencyID()
	{
		return currencyID;
	}

	void Stock::SetID(int sID)
	{
		id = sID;
	}
	
	void Stock::SetProductID(int sProductID)
	{
		productID = sProductID;
	}
	void Stock::SetCount(double sCount)
	{
		count = sCount;
	}
	void Stock::SetSum(double sSum)
	{
		sum = sSum;
	}
	void Stock::SetStatusID(int sStatusID)
	{
		statusID = sStatusID;
	}
	void Stock::SetCurrencyID(int sCurrencyID)
	{
		currencyID = sCurrencyID;
	}

	bool Stock::CreateStock(DataLayer::OrmasDal& ormasDal, int pID, double sCount, double sSum,
		int sID, int cID, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		productID = pID;
		count = sCount;
		sum = sSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.CreateStock(id, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool Stock::CreateStock(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateStock(id, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool Stock::DeleteStock(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteStock(id, errorMessage))
		{
			Clear();
			return true;
		}
		return false;
	}

	bool Stock::UpdateStock(DataLayer::OrmasDal& ormasDal, int pID, double sCount, double sSum,
		int sID, int cID, std::string& errorMessage)
	{
		productID = pID;
		count = sCount;
		sum = sSum;
		statusID = sID;
		currencyID = cID;
		if (count < 0 || sum < 0)
		{
			errorMessage = "Count or sum cannot be less then 0!";
			return false;
		}
		if (0 != id && ormasDal.UpdateStock(id, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool Stock::UpdateStock(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (count < 0 || sum < 0)
		{
			errorMessage = "Count or sum cannot be less then 0!";
			return false;
		}
		if (0 != id && ormasDal.UpdateStock(id, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}

	std::string Stock::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != productID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForStock(id, productID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool Stock::GetStockByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		id = pID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::stockViewCollection> stockVector = ormasDal.GetStock(errorMessage, filter);
		if (0 != stockVector.size())
		{
			id = std::get<0>(stockVector.at(0));
			count = std::get<6>(stockVector.at(0));
			sum = std::get<7>(stockVector.at(0));
			productID = std::get<10>(stockVector.at(0));
			statusID = std::get<11>(stockVector.at(0));
			currencyID = std::get<12>(stockVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find stock with this id";
		}
		return false;
	}

	bool Stock::GetStockByProductID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		productID = pID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::stockViewCollection> stockVector = ormasDal.GetStock(errorMessage, filter);
		if (0 != stockVector.size())
		{
			id = std::get<0>(stockVector.at(0));
			count = std::get<6>(stockVector.at(0));
			sum = std::get<7>(stockVector.at(0));
			productID = std::get<10>(stockVector.at(0));
			statusID = std::get<11>(stockVector.at(0));
			currencyID = std::get<12>(stockVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find stock with this id";
		}
		return false;
	}

	bool Stock::IsEmpty()
	{
		if (0 == id && 0 == count && 0 == sum && 0 == productID && 0 == statusID && 0 == currencyID)
			return true;
		return false;
	}

	void Stock::Clear()
	{
		id = 0;
		count = 0;
		sum = 0;
		productID = 0;
		statusID = 0;
		currencyID = 0;
	}

	bool Stock::IsDuplicate(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		Stock stock;
		stock.Clear();
		errorMessage.clear();
		stock.SetProductID(pID);
		std::string filter = stock.GenerateFilter(ormasDal);
		std::vector<DataLayer::stockViewCollection> stockVector = ormasDal.GetStock(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == stockVector.size())
		{
			return false;
		}
		errorMessage = "Stock with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Stock::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Stock stock;
		stock.Clear();
		errorMessage.clear();
		stock.SetProductID(productID);
		std::string filter = stock.GenerateFilter(ormasDal);
		std::vector<DataLayer::stockViewCollection> stockVector = ormasDal.GetStock(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == stockVector.size())
		{
			return false;
		}
		errorMessage = "Stock with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Stock::ChangingByConsumeProduct(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		ConsumeProductList cPList;
		std::vector<ConsumeProductListView> cPListVec;
		double totalSum = 0.0;
		int companyID = 0;
		
		cPList.SetConsumeProductID(cpID);
		std::string filter = cPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeProductListViewCollection> productListVector = ormasDal.GetConsumeProductList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				cPListVec.push_back(ConsumeProductListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Consume product list is empty!";
			return false;
		}
		if (cPListVec.size() > 0)
		{
			Stock stock;
			Product product;
			NetCost nCost;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in cPListVec)
			{
				stock.Clear();
				product.Clear();
				nCost.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						if (product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						{
							errorMessage = "ERROR! There is not enough product in the stock!";
							errorMessage += " Product name:";
							errorMessage += product.GetName();
							errorMessage += ", Product count:";
							errorMessage += std::to_string(stock.GetCount());
							
						}
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						if (!nCost.GetNetCostByProductID(ormasDal, product.GetID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum = totalSum + round(item.GetCount()*nCost.GetValue() * 1000) / 1000;
						stock.SetCount(stock.GetCount() - item.GetCount());
						if (0 == stock.GetCount())
						{
							stock.SetSum(0);
						}
						else
						{
							stock.SetSum(stock.GetSum() - (item.GetCount()*nCost.GetValue()));
						}
						if (!stock.UpdateStock(ormasDal, errorMessage))
						{
							ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume product list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		CompanyAccountRelation caRel;
		//int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "55010", errorMessage);
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10742", errorMessage);
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10740", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		
		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByConsumeProduct(DataLayer::OrmasDal& ormasDal, int cpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		ConsumeProductList cPList;
		std::vector<ConsumeProductListView> cPListVec;
		double totalSum = 0.0;
		int companyID = 0;

		cPList.SetConsumeProductID(cpID);
		std::string filter = cPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeProductListViewCollection> productListVector = ormasDal.GetConsumeProductList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				cPListVec.push_back(ConsumeProductListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Consume product list is empty!";
			return false;
		}
		if (cPListVec.size() > 0)
		{
			Stock stock;
			Product product;
			NetCost nCost;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in cPListVec)
			{
				stock.Clear();
				product.Clear();
				nCost.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						if (product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						{
							errorMessage = "ERROR! There is not enough product in the stock!";
							errorMessage += " Product name:";
							errorMessage += product.GetName();
							errorMessage += ", Product count:";
							errorMessage += std::to_string(stock.GetCount());

						}
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						if (!nCost.GetNetCostByProductID(ormasDal, product.GetID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum = totalSum + item.GetCount()*nCost.GetValue();
						stock.SetCount(stock.GetCount() - (item.GetCount() - pProdCountMap.find(product.GetID())->second));
						if (0 == stock.GetCount())
						{
							stock.SetSum(0);
						}
						else
						{
							stock.SetSum(stock.GetSum() - ((item.GetCount()*nCost.GetValue()) - (pProdCountMap.find(product.GetID())->second * nCost.GetValue())));
						}
						if (!stock.UpdateStock(ormasDal, errorMessage))
						{
							ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume product list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10742", errorMessage);
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10740", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		
		return true;
	}

	bool Stock::ChangingByConsumeRaw(DataLayer::OrmasDal& ormasDal, int crID, std::string& errorMessage)
	{
		ConsumeRawList cRList;
		std::vector<ConsumeRawListView> cRListVec;
		double totalSum = 0.0;
		int companyID = 0;

		cRList.SetConsumeRawID(crID);
		std::string filter = cRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeRawListViewCollection> productListVector = ormasDal.GetConsumeRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				cRListVec.push_back(ConsumeRawListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			return false;
		}
		if (cRListVec.size() > 0)
		{
			Stock stock;
			Product product;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in cRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += std::to_string(stock.GetCount());
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum= totalSum+ item.GetSum();
						stock.SetCount(stock.GetCount() - item.GetCount());
						if (0 == stock.GetCount())
						{
							stock.SetSum(0);
						}
						else
						{
							stock.SetSum((stock.GetSum() - item.GetSum()));
						}
						if (!stock.UpdateStock(ormasDal, errorMessage))
						{
							ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10720", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByConsumeRaw(DataLayer::OrmasDal& ormasDal, int crID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		ConsumeRawList cRList;
		std::vector<ConsumeRawListView> cRListVec;
		double totalSum = 0.0;
		int companyID = 0;

		cRList.SetConsumeRawID(crID);
		std::string filter = cRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeRawListViewCollection> productListVector = ormasDal.GetConsumeRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				cRListVec.push_back(ConsumeRawListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			return false;
		}
		if (cRListVec.size() > 0)
		{
			Stock stock;
			Product product;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in cRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += std::to_string(stock.GetCount());
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum= totalSum+ item.GetSum();
						stock.SetCount(stock.GetCount() - (item.GetCount() - pProdCountMap.find(product.GetID())->second));
						if (0 == stock.GetCount())
						{
							stock.SetSum(0);
						}
						else
						{
							stock.SetSum(stock.GetSum() - (item.GetSum() - (pProdCountMap.find(product.GetID())->second * product.GetPrice())));	
						}
						if (!stock.UpdateStock(ormasDal, errorMessage))
						{
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10720", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByOrderRaw(DataLayer::OrmasDal& ormasDal, int orID, std::string& errorMessage)
	{
		OrderRaw oRaw;
		OrderRawList oRList;
		std::vector<OrderRawListView> oRListVec;
		double totalSum = 0.0;
		int companyID = 0;

		oRList.SetOrderRawID(orID);
		std::string filter = oRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::orderRawListViewCollection> productListVector = ormasDal.GetOrderRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				oRListVec.push_back(OrderRawListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Order raw list is empty!";
			return false;
		}
		if (oRListVec.size() > 0)
		{
			Stock stock;
			Product product;
			Status status;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in oRListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot order this product, status is not valied!";
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetSum();
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetSum());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetSum();
					stock.SetCount(stock.GetCount() + item.GetCount());
					stock.SetSum(stock.GetSum() + item.GetSum());
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Order raw list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!oRaw.GetOrderRawByID(ormasDal, orID, errorMessage))
			return false;
		Balance balance;
		if (!balance.GetBalanceByUserID(ormasDal, oRaw.GetPurveyorID(), errorMessage))
			return false;
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10720", errorMessage);
		int credAccID = balance.GetSubaccountID();
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByOrderRaw(DataLayer::OrmasDal& ormasDal, int orID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		OrderRaw oRaw;
		OrderRawList oRList;
		std::vector<OrderRawListView> oRListVec;
		double totalSum = 0.0;
		int companyID = 0;

		oRList.SetOrderRawID(orID);
		std::string filter = oRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::orderRawListViewCollection> productListVector = ormasDal.GetOrderRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				oRListVec.push_back(OrderRawListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Order raw list is empty!";
			return false;
		}
		if (oRListVec.size() > 0)
		{
			Stock stock;
			Product product;
			Status status;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in oRListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot order this product, status is not valied!";
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetSum();
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetSum());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetSum();
					stock.SetCount(stock.GetCount() + (item.GetCount() - pProdCountMap.find(product.GetID())->second));
					stock.SetSum(stock.GetSum() + (item.GetSum() - (pProdCountMap.find(product.GetID())->second * product.GetPrice())));
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Order raw list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!oRaw.GetOrderRawByID(ormasDal, orID, errorMessage))
			return false;
		Balance balance;
		if (!balance.GetBalanceByUserID(ormasDal, oRaw.GetPurveyorID(), errorMessage))
			return false;
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10720", errorMessage);
		int credAccID = balance.GetSubaccountID();
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReceiptProduct(DataLayer::OrmasDal& ormasDal, int rpID, std::string& errorMessage)
	{
		ReceiptProductList rPList;
		std::vector<ReceiptProductListView> rPListVec;
		double totalSum = 0.0;
		int companyID = 0;

		rPList.SetReceiptProductID(rpID);
		std::string filter = rPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptProductListViewCollection> productListVector = ormasDal.GetReceiptProductList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rPListVec.push_back(ReceiptProductListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt product list is empty!";
			return false;
		}
		if (rPListVec.size() > 0)
		{
			Stock stock;
			Product product;
			Status status;
			NetCost nCost;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in rPListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				nCost.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					if (!nCost.GetNetCostByProductID(ormasDal, product.GetID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetCount()*nCost.GetValue();
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum((item.GetCount()*nCost.GetValue()));
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					if (!stock.CreateStock(ormasDal,errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					if (!nCost.GetNetCostByProductID(ormasDal, product.GetID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum +item.GetCount()*nCost.GetValue() ;
					stock.SetCount(stock.GetCount() + item.GetCount());
					stock.SetSum(stock.GetSum() + (item.GetCount()*nCost.GetValue()));
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt product list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10740", errorMessage);
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReceiptProduct(DataLayer::OrmasDal& ormasDal, int rpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		ReceiptProductList rPList;
		std::vector<ReceiptProductListView> rPListVec;
		double totalSum = 0.0;
		int companyID = 0;

		rPList.SetReceiptProductID(rpID);
		std::string filter = rPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptProductListViewCollection> productListVector = ormasDal.GetReceiptProductList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rPListVec.push_back(ReceiptProductListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt product list is empty!";
			return false;
		}
		if (rPListVec.size() > 0)
		{
			Stock stock;
			Product product;
			Status status;
			NetCost nCost;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in rPListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				nCost.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					if (!nCost.GetNetCostByProductID(ormasDal, product.GetID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetCount()*nCost.GetValue();
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetCount()*nCost.GetValue());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					if (!nCost.GetNetCostByProductID(ormasDal, product.GetID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetCount()*nCost.GetValue() ;
					stock.SetCount(stock.GetCount() + (item.GetCount() - pProdCountMap.find(product.GetID())->second));
					stock.SetSum(stock.GetSum() + ((item.GetCount()*nCost.GetValue()) - (pProdCountMap.find(product.GetID())->second * nCost.GetValue())));
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt product list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10740", errorMessage);
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReceiptRaw(DataLayer::OrmasDal& ormasDal, int rrID, std::string& errorMessage)
	{
		ReceiptRawList rRList;
		std::vector<ReceiptRawListView> rRListVec;
		double totalSum = 0.0;
		int companyID = 0;

		rRList.SetReceiptRawID(rrID);
		std::string filter = rRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptRawListViewCollection> productListVector = ormasDal.GetReceiptRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rRListVec.push_back(ReceiptRawListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt raw list is empty!";
			return false;
		}
		if (rRListVec.size() > 0)
		{
			Stock stock;
			Product product;
			Status status;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in rRListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum= totalSum+ item.GetSum();
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetSum());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum= totalSum+ item.GetSum();
					stock.SetCount(stock.GetCount() + item.GetCount());
					stock.SetSum(stock.GetSum() + item.GetSum());
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt raw list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10720", errorMessage);
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "22010", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReceiptRaw(DataLayer::OrmasDal& ormasDal, int rrID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		ReceiptRawList rRList;
		std::vector<ReceiptRawListView> rRListVec;
		double totalSum = 0.0;
		int companyID = 0;

		rRList.SetReceiptRawID(rrID);
		std::string filter = rRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptRawListViewCollection> productListVector = ormasDal.GetReceiptRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rRListVec.push_back(ReceiptRawListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt raw list is empty!";
			return false;
		}
		if (rRListVec.size() > 0)
		{
			Stock stock;
			Product product;
			Status status;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in rRListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum= totalSum+ item.GetSum();
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetSum());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum= totalSum+ item.GetSum();
					stock.SetCount(stock.GetCount() + (item.GetCount() - pProdCountMap.find(product.GetID())->second));
					stock.SetSum(stock.GetSum() + (item.GetSum() - (pProdCountMap.find(product.GetID())->second * product.GetPrice())));
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt raw list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10720", errorMessage);
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "22010", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReturnProduct(DataLayer::OrmasDal& ormasDal, int rpID, int cID, std::string& errorMessage)
	{
		ReturnList rList;
		std::vector<ReturnListView> rListVec;
		double totalSum = 0.0;
		int companyID = 0;

		rList.SetReturnID(rpID);
		std::string filter = rList.GenerateFilter(ormasDal);
		std::vector<DataLayer::returnListViewCollection> productListVector = ormasDal.GetReturnList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rListVec.push_back(ReturnListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Return list is empty!";
			return false;
		}
		if (rListVec.size() > 0)
		{
			Stock stock;
			Product product;
			Status status;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in rListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot return this product, status is not valied!";
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetSum();
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetSum());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetSum();
					stock.SetCount(stock.GetCount() + item.GetCount());
					stock.SetSum(stock.GetSum() + item.GetSum());
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Return list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		Balance balance;
		if (!balance.GetBalanceByUserID(ormasDal, cID, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10740", errorMessage); 
		int credAccID = balance.GetSubaccountID();
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReturnProduct(DataLayer::OrmasDal& ormasDal, int rpID, int cID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		ReturnList rList;
		std::vector<ReturnListView> rListVec;
		double totalSum = 0.0;
		int companyID = 0;

		rList.SetReturnID(rpID);
		std::string filter = rList.GenerateFilter(ormasDal);
		std::vector<DataLayer::returnListViewCollection> productListVector = ormasDal.GetReturnList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rListVec.push_back(ReturnListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Return list is empty!";
			return false;
		}
		if (rListVec.size() > 0)
		{
			Stock stock;
			Product product;
			Status status;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in rListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum= totalSum+ item.GetSum();
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetSum());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum= totalSum+ item.GetSum();
					stock.SetCount(stock.GetCount() + (item.GetCount() - pProdCountMap.find(product.GetID())->second));
					stock.SetSum(stock.GetSum() + (item.GetSum() - (pProdCountMap.find(product.GetID())->second * product.GetPrice())));
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt product list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		Balance balance;
		if (!balance.GetBalanceByUserID(ormasDal, cID, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10740", errorMessage);
		int credAccID = balance.GetSubaccountID();
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByWriteOff(DataLayer::OrmasDal& ormasDal, int wpID, std::string& errorMessage)
	{
		WriteOffList cPList;
		std::vector<WriteOffListView> cPListVec;
		double totalSum = 0.0;
		int companyID = 0;

		cPList.SetWriteOffID(wpID);
		std::string filter = cPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::writeOffListViewCollection> productListVector = ormasDal.GetWriteOffList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				cPListVec.push_back(WriteOffListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Write-off product list is empty!";
			return false;
		}
		if (cPListVec.size() > 0)
		{
			Stock stock;
			Product product;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in cPListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += std::to_string(stock.GetCount());
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum= totalSum+ item.GetSum();
						stock.SetCount(stock.GetCount() - item.GetCount());
						if (0 == stock.GetCount())
						{
							stock.SetSum(0);
						}
						else
						{
							stock.SetSum(stock.GetSum() - item.GetSum());
						}
						if (!stock.UpdateStock(ormasDal, errorMessage))
						{
							ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Write-off product list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "44090", errorMessage);
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10740", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByWriteOff(DataLayer::OrmasDal& ormasDal, int wpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		WriteOffList cPList;
		std::vector<WriteOffListView> cPListVec;
		double totalSum = 0.0;
		int companyID = 0;

		cPList.SetWriteOffID(wpID);
		std::string filter = cPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::writeOffListViewCollection> productListVector = ormasDal.GetWriteOffList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				cPListVec.push_back(WriteOffListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Write-off product list is empty!";
			return false;
		}
		if (cPListVec.size() > 0)
		{
			Stock stock;
			Product product;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in cPListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName(); 
					ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += std::to_string(stock.GetCount());
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum= totalSum+ item.GetSum();
						stock.SetCount(stock.GetCount() - (item.GetCount() - pProdCountMap.find(product.GetID())->second));
						if (0 == stock.GetCount())
						{
							stock.SetSum(0);
						}
						else
						{
							stock.SetSum(stock.GetSum() - (item.GetSum() - (pProdCountMap.find(product.GetID())->second * product.GetPrice())));
						}
						if (!stock.UpdateStock(ormasDal, errorMessage))
						{
							ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Write-off product list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "44090", errorMessage);
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10740", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByWriteOffRaw(DataLayer::OrmasDal& ormasDal, int wrID, std::string& errorMessage)
	{
		WriteOffRawList wRList;
		std::vector<WriteOffRawListView> wRListVec;
		double totalSum = 0.0;
		int companyID = 0;


		wRList.SetWriteOffRawID(wrID);
		std::string filter = wRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::writeOffRawListViewCollection> productListVector = ormasDal.GetWriteOffRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				wRListVec.push_back(WriteOffRawListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Write-off raw list is empty!";
			return false;
		}
		if (wRListVec.size() > 0)
		{
			Stock stock;
			Product product;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in wRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += std::to_string(stock.GetCount());
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum= totalSum+ item.GetSum();
						if (0 == stock.GetCount())
						{
							stock.SetSum(0);
						}
						else
						{
							stock.SetSum(stock.GetSum() - item.GetSum());
						}
						if (!stock.UpdateStock(ormasDal, errorMessage))
						{
							ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Write-off raw list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "44090", errorMessage);
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10720", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByWriteOffRaw(DataLayer::OrmasDal& ormasDal, int wrID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		WriteOffRawList wRList;
		std::vector<WriteOffRawListView> wRListVec;
		double totalSum = 0.0;
		int companyID = 0;

		wRList.SetWriteOffRawID(wrID);
		std::string filter = wRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::writeOffRawListViewCollection> productListVector = ormasDal.GetWriteOffRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				wRListVec.push_back(WriteOffRawListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Write-off raw list is empty!";
			return false;
		}
		if (wRListVec.size() > 0)
		{
			Stock stock;
			Product product;
			ormasDal.StartTransaction(errorMessage);
			for each (auto item in wRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += std::to_string(stock.GetCount());
						ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum= totalSum+ item.GetSum();
						stock.SetCount(stock.GetCount() - (item.GetCount() - pProdCountMap.find(product.GetID())->second));
						if (0 == stock.GetCount())
						{
							stock.SetSum(0);
						}
						else
						{
							stock.SetSum(stock.GetSum() - (item.GetSum() - (pProdCountMap.find(product.GetID())->second * product.GetPrice())));
						}
						if (!stock.UpdateStock(ormasDal, errorMessage))
						{
							ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Write-off raw list is empty!";
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "44090", errorMessage);
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10720", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::RecalculateStock(DataLayer::OrmasDal& ormasDal, int pID, double oldPrice, double newPrice, std::string& errorMessage)
	{ 
		Stock stock;
		Product product;
		stock.Clear();
		product.Clear();
		int companyID = 0;
		double difference = 0;
		if (!stock.GetStockByProductID(ormasDal, pID, errorMessage))
		{
			return true;
		}
		else
		{
			if (0 == stock.GetCount())
			{
				return true;
			}
			else
			{
				if (!product.GetProductByID(ormasDal, pID, errorMessage))
					return false;
				companyID = product.GetCompanyID();
				difference = stock.GetCount()*newPrice - stock.GetCount()*oldPrice;
			}
		}
		if (difference != 0)
		{
			CompanyAccountRelation caRel;
			int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10720", errorMessage);
			int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "55020", errorMessage);
			if (0 == debAccID || 0 == credAccID)
			{
				return false;
			}
			if (!this->CreateEntry(ormasDal, debAccID, difference, credAccID, errorMessage))
			{
				return false;
			}
			return true;
		}
		return false;		
	}

	bool Stock::CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(ormasDal.GetSystemDateTime());
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		entry.SetDescription(wstring_to_utf8(L"Складская операция"));
		if (!entry.CreateEntry(ormasDal, errorMessage))
		{
			return false;
		}
		return true;
	}
	bool Stock::CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, double previousSum, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(ormasDal.GetSystemDateTime());
		entry.SetDebitingAccountID(credAccID);
		entry.SetValue(previousSum);
		entry.SetCreditingAccountID(debAccID);
		entry.SetDescription(wstring_to_utf8(L"Складская операция"));
		if (!entry.CreateEntry(ormasDal, errorMessage, true))
		{
			return false;
		}
		entry.Clear();
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		entry.SetDescription(wstring_to_utf8(L"Складская операция"));
		if (!entry.CreateEntry(ormasDal, errorMessage))
		{
			return false;
		}
		return true;
	}

	std::string Stock::wstring_to_utf8(const std::wstring& str)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
		return myconv.to_bytes(str);
	}
}