#include "stdafx.h"
#include "StockClass.h"
#include "EntryOperationRelationClass.h"
#include "BalanceClass.h"
#include "OrderRawClass.h"
#include "OrderRawListClass.h"
#include "OrderRawListViewClass.h"
#include "ConsumeProductClass.h"
#include "ConsumeProductListClass.h"
#include "ConsumeProductListViewClass.h"
#include "ConsumeRawClass.h"
#include "ConsumeRawListClass.h"
#include "ConsumeRawListViewClass.h"
#include "ReceiptProductClass.h"
#include "ReceiptProductListClass.h"
#include "ReceiptProductListViewClass.h"
#include "StockTransferClass.h"
#include "StockTransferListClass.h"
#include "StockTransferListViewClass.h"
#include "ReturnClass.h"
#include "ReturnListClass.h"
#include "ReturnListViewClass.h"
#include "WriteOffClass.h"
#include "WriteOffListClass.h"
#include "WriteOffListViewClass.h"
#include "WriteOffRawClass.h"
#include "WriteOffRawListClass.h"
#include "WriteOffRawListViewClass.h"
#include "ProductClass.h"
#include "StatusClass.h"
#include "EntryClass.h"
#include "AccountClass.h"
#include "SubaccountClass.h"
#include "CompanyAccountRelationClass.h"
#include "NetCostClass.h"
#include "ProductTypeClass.h"
#include "WarehouseClass.h"
#include "WarehouseTypeClass.h"
#include "WarehouseEmployeeRelationClass.h"
#include "UserClass.h"
#include "ProductionConsumeRawClass.h"
#include "ProductionConsumeRawListClass.h"
#include "ProductionConsumeRawListViewClass.h"
#include "ProductionListClass.h"
#include "ProductionListViewClass.h"
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
		warehouseID = std::get<6>(sCollection);
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

	int Stock::GetWarehouseID()
	{
		return warehouseID;
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
	void Stock::SetWarehouseID(int sWarehouseID)
	{
		warehouseID = sWarehouseID;
	}

	bool Stock::CreateStock(DataLayer::OrmasDal& ormasDal, int pID, double sCount, double sSum,
		int sID, int cID, int wID, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		productID = pID;
		count = sCount;
		sum = sSum;
		statusID = sID;
		currencyID = cID;
		warehouseID = wID;
		if (0 != id && ormasDal.CreateStock(id, productID, count, sum, statusID, currencyID, warehouseID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool Stock::CreateStock(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateStock(id, productID, count, sum, statusID, currencyID, warehouseID, errorMessage))
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
		int sID, int cID, int wID, std::string& errorMessage)
	{
		productID = pID;
		count = sCount;
		sum = sSum;
		statusID = sID;
		currencyID = cID;
		warehouseID = wID;
		if (count < 0 || sum < 0)
		{
			errorMessage += "Count or sum cannot be less then 0! Product ID = ";
			errorMessage += std::to_string(productID);
			return false;
		}
		if (0 != id && ormasDal.UpdateStock(id, productID, count, sum, statusID, currencyID, warehouseID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool Stock::UpdateStock(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (count < 0 || sum < 0)
		{
			errorMessage += "Count or sum cannot be less then 0! Product ID = ";
			errorMessage += std::to_string(productID);
			return false;
		}
		if (0 != id && ormasDal.UpdateStock(id, productID, count, sum, statusID, currencyID, warehouseID, errorMessage))
		{
			return true;
		}
		return false;
	}

	std::string Stock::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != productID || 0 != count || 0 != sum || 0 != statusID || 0 != warehouseID)
		{
			return ormasDal.GetFilterForStock(id, productID, count, sum, statusID, currencyID, warehouseID);
		}
		return "";
	}

	bool Stock::GetStockByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		if (pID <= 0)
			return false;
		id = pID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::stockViewCollection> stockVector = ormasDal.GetStock(errorMessage, filter);
		if (0 != stockVector.size())
		{
			id = std::get<0>(stockVector.at(0));
			count = std::get<6>(stockVector.at(0));
			sum = std::get<7>(stockVector.at(0));
			productID = std::get<12>(stockVector.at(0));
			statusID = std::get<13>(stockVector.at(0));
			currencyID = std::get<14>(stockVector.at(0));
			warehouseID = std::get<15>(stockVector.at(0));
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
		if (pID <= 0)
			return false;
		productID = pID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::stockViewCollection> stockVector = ormasDal.GetStock(errorMessage, filter);
		if (0 != stockVector.size())
		{
			id = std::get<0>(stockVector.at(0));
			count = std::get<6>(stockVector.at(0));
			sum = std::get<7>(stockVector.at(0));
			productID = std::get<12>(stockVector.at(0));
			statusID = std::get<13>(stockVector.at(0));
			currencyID = std::get<14>(stockVector.at(0));
			warehouseID = std::get<15>(stockVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find stock with this id";
		}
		return false;
	}

	bool Stock::GetStockByProductAndWarehouseID(DataLayer::OrmasDal& ormasDal, int pID, int wID, std::string& errorMessage)
	{
		if (pID <= 0)
			return false;
		if (wID <= 0)
			return false;
		productID = pID;
		warehouseID = wID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::stockViewCollection> stockVector = ormasDal.GetStock(errorMessage, filter);
		if (0 != stockVector.size())
		{
			id = std::get<0>(stockVector.at(0));
			count = std::get<6>(stockVector.at(0));
			sum = std::get<7>(stockVector.at(0));
			productID = std::get<12>(stockVector.at(0));
			statusID = std::get<13>(stockVector.at(0));
			currencyID = std::get<14>(stockVector.at(0));
			warehouseID = std::get<15>(stockVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find stock with this product ID and warehouse ID";
		}
		return false;
	}

	bool Stock::IsEmpty()
	{
		if (0 == id && 0 == count && 0 == sum && 0 == productID && 0 == statusID && 0 == currencyID && 0 == warehouseID)
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
		warehouseID = 0;
	}

	bool Stock::IsDuplicate(DataLayer::OrmasDal& ormasDal, int pID, int wID, std::string& errorMessage)
	{
		Stock stock;
		stock.Clear();
		errorMessage.clear();
		stock.SetProductID(pID);
		stock.SetWarehouseID(wID);
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
		stock.SetWarehouseID(warehouseID);
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

	bool Stock::ChangingByConsumeProduct(DataLayer::OrmasDal& ormasDal, int cpID, int stockEmpID, std::string& errorMessage)
	{
		ConsumeProductList cPList;
		std::vector<ConsumeProductListView> cPListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int subAccID = 0;
		int warehouseID = 0;
		
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
			if (!GetSubIDAndWerhIDFromConProd(ormasDal, stockEmpID , warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in cPListVec)
			{
				//clear section
				stock.Clear();
				product.Clear();
				nCost.Clear();
				
				//check stock for existens of product
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
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
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10742", errorMessage);
		int credAccID = subAccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		
		if (!this->CreateEntry(ormasDal, cpID, debAccID, totalSum, credAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByConsumeProductCancel(DataLayer::OrmasDal& ormasDal, int cpID, int stockEmpID, std::string& errorMessage)
	{
		ConsumeProductList cPList;
		std::vector<ConsumeProductListView> cPListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int subAccID = 0;
		int warehouseID = 0;

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
			if (!GetSubIDAndWerhIDFromConProd(ormasDal, stockEmpID, warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			Status status;
			NetCost nCost;

			for each (auto item in cPListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				nCost.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
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
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
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
					totalSum = totalSum + item.GetCount()*nCost.GetValue();
					stock.SetCount(stock.GetCount() + item.GetCount());
					stock.SetSum(stock.GetSum() + (item.GetCount()*nCost.GetValue()));
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		CompanyAccountRelation caRel;
		int debAccID = subAccID;
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10742", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, cpID, debAccID, totalSum, credAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByConsumeProduct(DataLayer::OrmasDal& ormasDal, int cpID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		ConsumeProductList cPList;
		std::vector<ConsumeProductListView> cPListVec;
		double totalSum = 0.0;
		int companyID = 0; 
		int subAccID = 0;
		int warehouseID = 0;

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
			if (!GetSubIDAndWerhIDFromConProd(ormasDal, stockEmpID, warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in cPListVec)
			{
				stock.Clear();
				product.Clear();
				nCost.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
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
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10742", errorMessage);
		int credAccID = subAccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, cpID, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		
		return true;
	}

	bool Stock::ChangingByConsumeRaw(DataLayer::OrmasDal& ormasDal, int crID, int empID, int stockEmpID, std::string& errorMessage)
	{
		ConsumeRawList cRList;
		std::vector<ConsumeRawListView> cRListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int debSaccID = 0;
		int credSaccID = 0;
		int debWerID = 0;
		int credWerID = 0;
		double correctingConRawSum = 0;
		double correctingConRawTotalSum = 0;
		int acc55020ID = 0;

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
			if (!GetSubIDAndWerhIDFromConRaw(ormasDal, empID, stockEmpID, debWerID, credWerID, debSaccID, credSaccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			correctingConRawSum = 0;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in cRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), credWerID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum = totalSum + item.GetSum();
						stock.SetCount(stock.GetCount() - item.GetCount());
						correctingConRawSum = std::round(product.GetPrice()* item.GetCount() - item.GetSum()) * 1000 / 1000;
						correctingConRawTotalSum += correctingConRawSum;
						if (0 == correctingConRawSum)
						{
							stock.SetSum((stock.GetSum() - item.GetSum()));
						}
						else if (correctingConRawSum > 0)
						{
							if ((stock.GetSum() - item.GetSum() - correctingConRawSum) < 0.5 &&
								(stock.GetSum() - item.GetSum() - correctingConRawSum) > -0.5
								&& stock.GetCount() == 0 )
							{
								stock.SetSum(0);
							}
							else
							{
								stock.SetSum(std::round((stock.GetSum() - item.GetSum() - correctingConRawSum)*1000)/1000);
							}
						}
						else if (correctingConRawSum < 0)
						{
							if ((stock.GetSum() - item.GetSum() - correctingConRawSum) < 0.5 &&
								(stock.GetSum() - item.GetSum() - correctingConRawSum) > -0.5
								&& stock.GetCount() == 0)
							{
								stock.SetSum(0);
							}
							else
							{
								stock.SetSum(std::round((stock.GetSum() - item.GetSum() + correctingConRawSum*(-1) * 1000) / 1000));
							}
						}

						if (!stock.UpdateStock(ormasDal, errorMessage))
						{
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = debSaccID;
		int credAccID = credSaccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, crID, debAccID, totalSum, credAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (0 != correctingConRawTotalSum)
		{
			acc55020ID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "55020", errorMessage);
			if (correctingConRawTotalSum > 0)
			{
				if (!this->CreateEntry(ormasDal, id, acc55020ID, correctingConRawTotalSum, credAccID, errorMessage))
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
			else if (correctingConRawTotalSum < 0)
			{
				if (!this->CreateEntry(ormasDal, id, credAccID, correctingConRawTotalSum*(-1), acc55020ID, errorMessage))
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
		}
		if (!ChangingByConsumeRawAtSecondStock(ormasDal, crID, debWerID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByConsumeRawCancel(DataLayer::OrmasDal& ormasDal, int crID, int empID, int stockEmpID, std::string& errorMessage)
	{
		ConsumeRawList cRList;
		std::vector<ConsumeRawListView> cRListVec;
		double totalSum = 0.0;
		double correctingSum = 0.0;
		int companyID = 0;
		int debSaccID = 0;
		int credSaccID = 0;
		int debWerID = 0;
		int credWerID = 0;
		double correctingConRawSum = 0;
		int acc55020ID = 0;

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
			if (!GetSubIDAndWerhIDFromConRaw(ormasDal, empID, stockEmpID, debWerID, credWerID, debSaccID, credSaccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			Status status;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in cRListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), credWerID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot order this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum += item.GetSum(); 
					correctingSum += std::round((product.GetPrice() * item.GetCount()) * 1000) / 1000;
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(std::round((product.GetPrice() * item.GetCount()) * 1000) / 1000);
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					stock.SetWarehouseID(warehouseID);
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum += item.GetSum();
					correctingSum += std::round((product.GetPrice() * item.GetCount()) * 1000) / 1000;
					stock.SetCount(stock.GetCount() + item.GetCount());
					stock.SetSum(stock.GetSum() + (std::round((product.GetPrice() * item.GetCount()) * 1000) / 1000));
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = credSaccID;
		int credAccID = debSaccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, crID, debAccID, totalSum, credAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		correctingConRawSum = totalSum - correctingSum;
		if (0 != correctingConRawSum)
		{
			acc55020ID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "55020", errorMessage);
			if (correctingConRawSum > 0)
			{
				if (!this->CreateEntry(ormasDal, id, acc55020ID, correctingConRawSum, credAccID, errorMessage))
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
			else if (correctingConRawSum < 0)
			{
				if (!this->CreateEntry(ormasDal, id, credAccID, correctingConRawSum*(-1), acc55020ID, errorMessage))
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
		}
		if (!ChangingByConsumeRawAtSecondStockCancel(ormasDal, crID, debWerID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByConsumeRaw(DataLayer::OrmasDal& ormasDal, int crID, int empID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		ConsumeRawList cRList;
		std::vector<ConsumeRawListView> cRListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int debSaccID = 0;
		int credSaccID = 0;
		int debWerID = 0;
		int credWerID = 0;
		int acc55020ID = 0;
		double correctingConRawSum = 0;

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
			if (!GetSubIDAndWerhIDFromConRaw(ormasDal, empID, stockEmpID, debWerID, credWerID, debSaccID, credSaccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in cRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), credWerID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum = totalSum + item.GetSum();
						stock.SetCount(stock.GetCount() - (item.GetCount() - pProdCountMap.find(product.GetID())->second));
						if (0 == stock.GetCount())
						{
							stock.SetSum(0);
						}
						else
						{
							correctingConRawSum = std::round(product.GetPrice()* item.GetCount() - item.GetSum()) * 1000 / 1000;
							if (0 == correctingConRawSum)
							{
								stock.SetSum(stock.GetSum() - (item.GetSum() - (pProdCountMap.find(product.GetID())->second * product.GetPrice())));
							}
							else if (correctingConRawSum > 0)
							{
								stock.SetSum(stock.GetSum() - (item.GetSum() + correctingConRawSum - (pProdCountMap.find(product.GetID())->second * product.GetPrice())));
							}
							else if (correctingConRawSum < 0)
							{
								stock.SetSum(stock.GetSum() - (item.GetSum() + correctingConRawSum - (pProdCountMap.find(product.GetID())->second * product.GetPrice())));
							}
							
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
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = debSaccID;
		int credAccID = credSaccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, crID, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (0 != correctingConRawSum)
		{
			acc55020ID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "55020", errorMessage);
			if (correctingConRawSum > 0)
			{
				if (!this->CreateEntry(ormasDal, id, acc55020ID, correctingConRawSum, credAccID, errorMessage))
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
			else if (correctingConRawSum < 0)
			{
				if (!this->CreateEntry(ormasDal, id, credAccID, correctingConRawSum*(-1), acc55020ID, errorMessage))
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
		}
		if (!ChangingByConsumeRawAtSecondStock(ormasDal, crID, debWerID, pProdCountMap, pSum, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByConsumeRawAtSecondStock(DataLayer::OrmasDal& ormasDal, int rrID, int debWerID, std::string& errorMessage)
	{
		ConsumeRawList cRList;
		std::vector<ConsumeRawListView> rRListVec;
		double totalSum = 0.0;
		int companyID = 0;

		cRList.SetConsumeRawID(rrID);
		std::string filter = cRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeRawListViewCollection> productListVector = ormasDal.GetConsumeRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rRListVec.push_back(ConsumeRawListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			return false;
		}
		if (rRListVec.size() > 0)
		{
			Stock pStock;
			Product product;
			Status status;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in rRListVec)
			{
				pStock.Clear();
				product.Clear();
				status.Clear();
				if (!pStock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), debWerID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot consume this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetSum();
					pStock.SetProductID(item.GetProductID());
					pStock.SetCount(item.GetCount());
					pStock.SetSum(item.GetSum());
					pStock.SetCurrencyID(item.GetCurrencyID());
					pStock.SetStatusID(status.GetID());
					if (!pStock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetSum();
					pStock.SetCount(pStock.GetCount() + item.GetCount());
					pStock.SetSum(pStock.GetSum() + item.GetSum());
					if (!pStock.UpdateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByConsumeRawAtSecondStockCancel(DataLayer::OrmasDal& ormasDal, int rrID, int debWerID, std::string& errorMessage)
	{
		ConsumeRawList cRList;
		std::vector<ConsumeRawListView> rRListVec;
		double totalSum = 0.0;
		int companyID = 0;

		cRList.SetConsumeRawID(rrID);
		std::string filter = cRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeRawListViewCollection> productListVector = ormasDal.GetConsumeRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rRListVec.push_back(ConsumeRawListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			return false;
		}
		if (rRListVec.size() > 0)
		{
			Stock pStock;
			Product product;
			Status status;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in rRListVec)
			{
				pStock.Clear();
				product.Clear();
				if (!pStock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), debWerID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				else
				{
					if (pStock.GetCount() < item.GetCount())
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += std::to_string(pStock.GetCount());
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum = totalSum + item.GetSum();
						pStock.SetCount(pStock.GetCount() - item.GetCount());
						if (0 == pStock.GetCount())
						{
							pStock.SetSum(0);
						}
						else
						{
							pStock.SetSum((pStock.GetSum() - item.GetSum()));
						}
						if (!pStock.UpdateStock(ormasDal, errorMessage))
						{
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByConsumeRawAtSecondStock(DataLayer::OrmasDal& ormasDal, int rrID, int debWerID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		ConsumeRawList cRList;
		std::vector<ConsumeRawListView> rRListVec;
		double totalSum = 0.0;
		int companyID = 0;

		cRList.SetConsumeRawID(rrID);
		std::string filter = cRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeRawListViewCollection> productListVector = ormasDal.GetConsumeRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rRListVec.push_back(ConsumeRawListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			return false;
		}
		if (rRListVec.size() > 0)
		{
			Stock pStock;
			Product product;
			Status status;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in rRListVec)
			{
				pStock.Clear();
				product.Clear();
				status.Clear();
				if (!pStock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), debWerID,errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetSum();
					pStock.SetProductID(item.GetProductID());
					pStock.SetCount(item.GetCount());
					pStock.SetSum(item.GetSum());
					pStock.SetCurrencyID(item.GetCurrencyID());
					pStock.SetStatusID(status.GetID());
					if (!pStock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetSum();
					pStock.SetCount(pStock.GetCount() + (item.GetCount() - pProdCountMap.find(product.GetID())->second));
					pStock.SetSum(pStock.GetSum() + (item.GetSum() - (pProdCountMap.find(product.GetID())->second * product.GetPrice())));
					if (!pStock.UpdateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByOrderRaw(DataLayer::OrmasDal& ormasDal, int orID, int empID, std::string& errorMessage)
	{
		OrderRaw oRaw;
		OrderRawList oRList;
		std::vector<OrderRawListView> oRListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int subAccID = 0;
		int warehouseID = 0;

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
			if (!GetSubIDAndWerhIDFromOrderRaw(ormasDal, empID, warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			Status status;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in oRListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot order this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + (item.GetSum());
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetCount()*product.GetPrice());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					stock.SetWarehouseID(warehouseID);
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
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
					stock.SetSum(stock.GetSum() + (item.GetCount()*product.GetPrice()));
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Order raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!oRaw.GetOrderRawByID(ormasDal, orID, errorMessage))
			return false;
		Balance balance;
		if (!balance.GetBalanceByUserID(ormasDal, oRaw.GetPurveyorID(), errorMessage))
			return false;
		CompanyAccountRelation caRel;
		int debAccID = subAccID;
		int credAccID = balance.GetSubaccountID();
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, orID, debAccID, totalSum, credAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByOrderRawCancel(DataLayer::OrmasDal& ormasDal, int orID, int empID, std::string& errorMessage)
	{
		OrderRaw oRaw;
		OrderRawList oRList;
		std::vector<OrderRawListView> oRListVec;
		double totalSum = 0.0;
		double newSum = 0.0;
		int companyID = 0;
		int subAccID = 0;
		int warehouseID = 0;

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
			if (!GetSubIDAndWerhIDFromOrderRaw(ormasDal, empID, warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			Status status;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in oRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum = totalSum + item.GetSum();
						newSum = newSum + std::round(item.GetCount()* product.GetPrice() * 1000) / 1000;
						stock.SetCount(stock.GetCount() - item.GetCount());
						if (0 == stock.GetCount())
						{
							stock.SetSum(0);
						}
						else
						{
							stock.SetSum((stock.GetSum() - std::round(item.GetCount()* product.GetPrice() * 1000) / 1000));
						}
						if (!stock.UpdateStock(ormasDal, errorMessage))
						{
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Order raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!oRaw.GetOrderRawByID(ormasDal, orID, errorMessage))
			return false;
		Balance balance;
		if (!balance.GetBalanceByUserID(ormasDal, oRaw.GetPurveyorID(), errorMessage))
			return false;
		CompanyAccountRelation caRel;
		int debAccID = subAccID;
		int credAccID = balance.GetSubaccountID();
		int acc55020ID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "55020", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, orID, credAccID, totalSum, debAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		double checkSum = totalSum - newSum;
		if (checkSum > 0)
		{
			if (!this->CreateEntry(ormasDal, orID, acc55020ID, checkSum, debAccID, errorMessage))
			{
				//ormasDal.CancelTransaction(errorMessage);
				return false;
			}
		}
		else if (checkSum < 0)
		{
			if (!this->CreateEntry(ormasDal, orID, debAccID, checkSum *(-1), acc55020ID, errorMessage))
			{
				//ormasDal.CancelTransaction(errorMessage);
				return false;
			}
		}
		return true;
	}

	bool Stock::ChangingByOrderRaw(DataLayer::OrmasDal& ormasDal, int orID, int empID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		OrderRaw oRaw;
		OrderRawList oRList;
		std::vector<OrderRawListView> oRListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int subAccID = 0;
		int warehouseID = 0;

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
			if (!GetSubIDAndWerhIDFromOrderRaw(ormasDal, empID, warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			Status status;
			for each (auto item in oRListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot order this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
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
					stock.SetWarehouseID(warehouseID);
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
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
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Order raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!oRaw.GetOrderRawByID(ormasDal, orID, errorMessage))
			return false;
		Balance balance;
		if (!balance.GetBalanceByUserID(ormasDal, oRaw.GetPurveyorID(), errorMessage))
			return false;
		CompanyAccountRelation caRel;
		int debAccID = subAccID;
		int credAccID = balance.GetSubaccountID();
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, orID, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReceiptProduct(DataLayer::OrmasDal& ormasDal, int rpID, int empID, int stockEmpID, std::string& errorMessage)
	{
		ReceiptProductList rPList;
		std::vector<ReceiptProductListView> rPListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int debSaccID = 0;
		int credSaccID = 0;
		int debWerID = 0;
		int credWerID = 0;

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
			if (!GetSubIDAndWerhIDFromRcpProd(ormasDal, empID, stockEmpID, debWerID, credWerID, debSaccID, credSaccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			Status status;
			NetCost nCost;
			
			for each (auto item in rPListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				nCost.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), debWerID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = debSaccID;
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, rpID, debAccID, totalSum, credAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!ChangingByReceiptProductAtSecondStock(ormasDal, rpID, credWerID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReceiptProductCancel(DataLayer::OrmasDal& ormasDal, int rpID, int empID, int stockEmpID, std::string& errorMessage)
	{
		ReceiptProductList rPList;
		std::vector<ReceiptProductListView> rPListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int debSaccID = 0;
		int credSaccID = 0;
		int debWerID = 0;
		int credWerID = 0;

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
			if (!GetSubIDAndWerhIDFromRcpProd(ormasDal, empID, stockEmpID, debWerID, credWerID, debSaccID, credSaccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			Status status;
			NetCost nCost;

			for each (auto item in rPListVec)
			{
				//clear section
				stock.Clear();
				product.Clear();
				nCost.Clear();

				//check stock for existens of product
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), debWerID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
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
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = debSaccID;
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, rpID, credAccID, totalSum, debAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!ChangingByReceiptProductAtSecondStockCancel(ormasDal, rpID, credWerID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReceiptProduct(DataLayer::OrmasDal& ormasDal, int rpID, int empID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		ReceiptProductList rPList;
		std::vector<ReceiptProductListView> rPListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int debSaccID = 0;
		int credSaccID = 0;
		int debWerID = 0;
		int credWerID = 0;

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
			if (!GetSubIDAndWerhIDFromRcpProd(ormasDal, empID, stockEmpID, debWerID, credWerID, debSaccID, credSaccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			Status status;
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in rPListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				nCost.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), debWerID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = debSaccID;
		int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, rpID, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!ChangingByReceiptProductAtSecondStock(ormasDal, rpID, credWerID, pProdCountMap, pSum, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReceiptProductAtSecondStock(DataLayer::OrmasDal& ormasDal, int rpID, int credWerID, std::string& errorMessage)
	{
		ReceiptProductListView rPList;
		std::vector<ReceiptProductListView> cPListVec;
		double totalSum = 0.0;
		int companyID = 0;

		rPList.SetReceiptProductID(rpID);
		std::string filter = rPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptProductListViewCollection> productListVector = ormasDal.GetReceiptProductList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				cPListVec.push_back(ReceiptProductListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Consume product list is empty!";
			return false;
		}
		if (cPListVec.size() > 0)
		{
			Stock pStock;
			Product product;
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in cPListVec)
			{
				pStock.Clear();
				product.Clear();
				nCost.Clear();
				if (!pStock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), credWerID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				else
				{
					if (pStock.GetCount() < item.GetCount())
					{
						if (product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						{
							errorMessage = "ERROR! There is not enough product in the production stock!";
							errorMessage += " Product name:";
							errorMessage += product.GetName();
							errorMessage += ", Product count:";
							errorMessage += std::to_string(pStock.GetCount());

						}
						//ormasDal.CancelTransaction(errorMessage);
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
						pStock.SetCount(pStock.GetCount() - item.GetCount());
						if (0 == pStock.GetCount())
						{
							pStock.SetSum(0);
						}
						else
						{
							pStock.SetSum(pStock.GetSum() - (item.GetCount()*nCost.GetValue()));
						}

						if (!pStock.UpdateStock(ormasDal, errorMessage))
						{
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}


		return true;
	}

	bool Stock::ChangingByReceiptProductAtSecondStockCancel(DataLayer::OrmasDal& ormasDal, int rpID, int credWerID, std::string& errorMessage)
	{
		ReceiptProductListView rPList;
		std::vector<ReceiptProductListView> cPListVec;
		double totalSum = 0.0;
		int companyID = 0;

		rPList.SetReceiptProductID(rpID);
		std::string filter = rPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptProductListViewCollection> productListVector = ormasDal.GetReceiptProductList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				cPListVec.push_back(ReceiptProductListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Consume product list is empty!";
			return false;
		}
		if (cPListVec.size() > 0)
		{
			Stock pStock;
			Product product;
			NetCost nCost;
			Status status;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in cPListVec)
			{
				pStock.Clear();
				product.Clear();
				status.Clear();
				nCost.Clear();
				if (!pStock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), credWerID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					if (!nCost.GetNetCostByProductID(ormasDal, product.GetID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetCount()*nCost.GetValue();
					pStock.SetProductID(item.GetProductID());
					pStock.SetCount(item.GetCount());
					pStock.SetSum((item.GetCount()*nCost.GetValue()));
					pStock.SetCurrencyID(item.GetCurrencyID());
					pStock.SetStatusID(status.GetID());
					if (!pStock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
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
					totalSum = totalSum + item.GetCount()*nCost.GetValue();
					pStock.SetCount(pStock.GetCount() + item.GetCount());
					pStock.SetSum(pStock.GetSum() + (item.GetCount()*nCost.GetValue()));
					if (!pStock.UpdateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}


		return true;
	}

	bool Stock::ChangingByReceiptProductAtSecondStock(DataLayer::OrmasDal& ormasDal, int rpID, int credWerID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		ReceiptProductListView rPList;
		std::vector<ReceiptProductListView> cPListVec;
		double totalSum = 0.0;
		int companyID = 0;

		rPList.SetReceiptProductID(rpID);
		std::string filter = rPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptProductListViewCollection> productListVector = ormasDal.GetReceiptProductList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				cPListVec.push_back(ReceiptProductListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Consume product list is empty!";
			return false;
		}
		if (cPListVec.size() > 0)
		{
			Stock pStock;
			Product product;
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in cPListVec)
			{
				pStock.Clear();
				product.Clear();
				nCost.Clear();
				if (!pStock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), credWerID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				else
				{
					if (pStock.GetCount() < item.GetCount())
					{
						if (product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						{
							errorMessage = "ERROR! There is not enough product in the stock!";
							errorMessage += " Product name:";
							errorMessage += product.GetName();
							errorMessage += ", Product count:";
							errorMessage += std::to_string(pStock.GetCount());

						}
						//ormasDal.CancelTransaction(errorMessage);
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
						pStock.SetCount(pStock.GetCount() - (item.GetCount() - pProdCountMap.find(product.GetID())->second));
						if (0 == pStock.GetCount())
						{
							pStock.SetSum(0);
						}
						else
						{
							pStock.SetSum(pStock.GetSum() - ((item.GetCount()*nCost.GetValue()) - (pProdCountMap.find(product.GetID())->second * nCost.GetValue())));
						}

						if (!pStock.UpdateStock(ormasDal, errorMessage))
						{
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}


		return true;
	}

	bool Stock::ChangingByStockTransfer(DataLayer::OrmasDal& ormasDal, int rrID, int empID, int stockEmpID, std::string& errorMessage)
	{
		StockTransferList rRList;
		std::vector<StockTransferListView> rRListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int debSaccID = 0;
		int credSaccID = 0;
		int debWerID = 0;
		int credWerID = 0;

		rRList.SetStockTransferID(rrID);
		std::string filter = rRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::stockTransferListViewCollection> productListVector = ormasDal.GetStockTransferList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rRListVec.push_back(StockTransferListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt raw list is empty!";
			return false;
		}
		if (rRListVec.size() > 0)
		{
			if (!GetSubIDAndWerhIDFromRcpRaw(ormasDal, empID, stockEmpID, debWerID, credWerID, debSaccID, credSaccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in rRListVec)
			{
				stock.Clear();
				product.Clear();
				nCost.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), credWerID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						if (!nCost.GetNetCostByProductID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += std::to_string(stock.GetCount());
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum = totalSum + item.GetSum();
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
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = debSaccID;
		int credAccID = credSaccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!this->CreateEntry(ormasDal, rrID, debAccID, totalSum, credAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!ChangingByStockTransferAtSecondStock(ormasDal, rrID, debWerID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByStockTransferCancel(DataLayer::OrmasDal& ormasDal, int rrID, int empID, int stockEmpID, std::string& errorMessage)
	{
		StockTransferList rRList;
		std::vector<StockTransferListView> rRListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int debSaccID = 0;
		int credSaccID = 0;
		int debWerID = 0;
		int credWerID = 0;

		rRList.SetStockTransferID(rrID);
		std::string filter = rRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::stockTransferListViewCollection> productListVector = ormasDal.GetStockTransferList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rRListVec.push_back(StockTransferListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt raw list is empty!";
			return false;
		}
		if (rRListVec.size() > 0)
		{
			if (!GetSubIDAndWerhIDFromRcpRaw(ormasDal, empID, stockEmpID, debWerID, credWerID, debSaccID, credSaccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			NetCost nCost;
			Status status;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in rRListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				nCost.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), credWerID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
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
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
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
					totalSum = totalSum + item.GetCount()*nCost.GetValue();
					stock.SetCount(stock.GetCount() + item.GetCount());
					stock.SetSum(stock.GetSum() + (item.GetCount()*nCost.GetValue()));
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Stock transfer list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = debSaccID;
		int credAccID = credSaccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!this->CreateEntry(ormasDal, rrID, credAccID, totalSum, debAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!ChangingByStockTransferAtSecondStockCancel(ormasDal, rrID, debWerID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByStockTransfer(DataLayer::OrmasDal& ormasDal, int rrID, int empID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		StockTransferList rRList;
		std::vector<StockTransferListView> rRListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int debSaccID = 0;
		int credSaccID = 0;
		int debWerID = 0;
		int credWerID = 0;

		rRList.SetStockTransferID(rrID);
		std::string filter = rRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::stockTransferListViewCollection> productListVector = ormasDal.GetStockTransferList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rRListVec.push_back(StockTransferListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt raw list is empty!";
			return false;
		}
		if (rRListVec.size() > 0)
		{
			if (!GetSubIDAndWerhIDFromRcpRaw(ormasDal, empID, stockEmpID, debWerID, credWerID, debSaccID, credSaccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			Status status;
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in rRListVec)
			{
				stock.Clear();
				product.Clear();
				nCost.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), credWerID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						if (!nCost.GetNetCostByProductID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum = totalSum + item.GetSum();
						stock.SetCount(stock.GetCount() - (item.GetCount() - pProdCountMap.find(product.GetID())->second));
						if (0 == stock.GetCount())
						{
							stock.SetSum(0);
						}
						else
						{
							stock.SetSum(stock.GetSum() - (item.GetSum() - (pProdCountMap.find(product.GetID())->second * nCost.GetValue())));
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
			errorMessage = "ERROR! Receipt raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = debSaccID;
		int credAccID = credSaccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, rrID, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!ChangingByStockTransferAtSecondStock(ormasDal, rrID, debWerID, pProdCountMap, pSum, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByStockTransferAtSecondStock(DataLayer::OrmasDal& ormasDal, int rrID, int debWerID, std::string& errorMessage)
	{
		StockTransferList cRList;
		std::vector<StockTransferListView> rRListVec;
		double totalSum = 0.0;
		int companyID = 0;

		cRList.SetStockTransferID(rrID);
		std::string filter = cRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::stockTransferListViewCollection> productListVector = ormasDal.GetStockTransferList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rRListVec.push_back(StockTransferListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt raw list is empty!";
			return false;
		}
		if (rRListVec.size() > 0)
		{
			Stock pStock;
			Product product;
			Status status;
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in rRListVec)
			{
				pStock.Clear();
				product.Clear();
				status.Clear();
				nCost.Clear();
				if (!pStock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), debWerID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					if (!nCost.GetNetCostByProductID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetSum();
					pStock.SetProductID(item.GetProductID());
					pStock.SetCount(item.GetCount());
					pStock.SetSum(item.GetSum());
					pStock.SetCurrencyID(item.GetCurrencyID());
					pStock.SetStatusID(status.GetID());
					if (!pStock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetSum();
					pStock.SetCount(pStock.GetCount() + item.GetCount());
					pStock.SetSum(pStock.GetSum() + item.GetSum());
					if (!pStock.UpdateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByStockTransferAtSecondStockCancel(DataLayer::OrmasDal& ormasDal, int rrID, int debWerID, std::string& errorMessage)
	{
		StockTransferList cRList;
		std::vector<StockTransferListView> rRListVec;
		double totalSum = 0.0;
		int companyID = 0;

		cRList.SetStockTransferID(rrID);
		std::string filter = cRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::stockTransferListViewCollection> productListVector = ormasDal.GetStockTransferList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rRListVec.push_back(StockTransferListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Stock transfer list is empty!";
			return false;
		}
		if (rRListVec.size() > 0)
		{
			Stock pStock;
			Product product;
			Status status;
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in rRListVec)
			{
				//clear section
				pStock.Clear();
				product.Clear();
				nCost.Clear();

				//check stock for existens of product
				if (!pStock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), debWerID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				else
				{
					if (pStock.GetCount() < item.GetCount())
					{
						if (product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						{
							errorMessage = "ERROR! There is not enough product in the stock!";
							errorMessage += " Product name:";
							errorMessage += product.GetName();
							errorMessage += ", Product count:";
							errorMessage += std::to_string(pStock.GetCount());

						}
						//ormasDal.CancelTransaction(errorMessage);
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
						pStock.SetCount(pStock.GetCount() - item.GetCount());
						if (0 == pStock.GetCount())
						{
							pStock.SetSum(0);
						}
						else
						{
							pStock.SetSum(pStock.GetSum() - (item.GetCount()*nCost.GetValue()));
						}
						if (!pStock.UpdateStock(ormasDal, errorMessage))
						{
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Stock transfer list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByStockTransferAtSecondStock(DataLayer::OrmasDal& ormasDal, int rrID, int debWerID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		StockTransferList cRList;
		std::vector<StockTransferListView> rRListVec;
		double totalSum = 0.0;
		int companyID = 0;

		cRList.SetStockTransferID(rrID);
		std::string filter = cRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::stockTransferListViewCollection> productListVector = ormasDal.GetStockTransferList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				rRListVec.push_back(StockTransferListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			return false;
		}
		if (rRListVec.size() > 0)
		{
			Stock pStock;
			Product product;
			Status status;
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in rRListVec)
			{
				pStock.Clear();
				product.Clear();
				status.Clear();
				nCost.Clear();
				if (!pStock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), debWerID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					if (!nCost.GetNetCostByProductID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetSum();
					pStock.SetProductID(item.GetProductID());
					pStock.SetCount(item.GetCount());
					pStock.SetSum(item.GetSum());
					pStock.SetCurrencyID(item.GetCurrencyID());
					pStock.SetStatusID(status.GetID());
					if (!pStock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetSum();
					pStock.SetCount(pStock.GetCount() + (item.GetCount() - pProdCountMap.find(product.GetID())->second));
					pStock.SetSum(pStock.GetSum() + (item.GetSum() - (pProdCountMap.find(product.GetID())->second * nCost.GetValue())));
					if (!pStock.UpdateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReturnProduct(DataLayer::OrmasDal& ormasDal, int rpID, int cID, int wareID, std::string& errorMessage)
	{
		ReturnList rList;
		std::vector<ReturnListView> rListVec;
		double totalSum = 0.0;
		double netSum = 0.0;
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
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in rListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				nCost.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), wareID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot return this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					if (!nCost.GetNetCostByProductID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum += (item.GetSum() - item.GetCount()*nCost.GetValue());
					netSum += item.GetCount()*nCost.GetValue();
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetCount()*nCost.GetValue());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					if (!nCost.GetNetCostByProductID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum += (item.GetSum() - item.GetCount()*nCost.GetValue());
					netSum += item.GetCount()*nCost.GetValue();
					stock.SetCount(stock.GetCount() + item.GetCount());
					stock.SetSum(stock.GetSum() + item.GetCount()*nCost.GetValue());
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Return list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		Balance balance;
		if (!balance.GetBalanceByUserID(ormasDal, cID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		Warehouse warehouse;
		if (!warehouse.GetWarehouseByID(ormasDal, wareID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		int debAccID10740 = warehouse.GetSubaccountID();
		int credAccID = balance.GetSubaccountID();
		int debAccID44090 = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "44090", errorMessage);
		if (0 == debAccID10740 || 0 == credAccID || 0 == debAccID44090)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, rpID, debAccID10740, netSum, credAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!this->CreateEntry(ormasDal, rpID, debAccID44090, totalSum, credAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReturnProductCancel(DataLayer::OrmasDal& ormasDal, int rpID, int cID, int wareID, std::string& errorMessage)
	{
		ReturnList rList;
		std::vector<ReturnListView> rListVec;
		double totalSum = 0.0;
		double netSum = 0.0;
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
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in rListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				nCost.Clear();
				//check stock for existens of product
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), wareID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						if (!nCost.GetNetCostByProductID(ormasDal, product.GetID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						netSum += round(item.GetCount()*nCost.GetValue() * 1000) / 1000;
						totalSum += round(item.GetCount()*product.GetPrice() * 1000) / 1000;
						stock.SetCount(stock.GetCount() - item.GetCount());
						if (0 == stock.GetCount())
						{
							stock.SetSum(0);
						}
						else
						{
							stock.SetSum(stock.GetSum() - round(item.GetCount()*nCost.GetValue() * 1000) / 1000);
						}
						if (!stock.UpdateStock(ormasDal, errorMessage))
						{
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Return list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		Balance balance;
		if (!balance.GetBalanceByUserID(ormasDal, cID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		Warehouse warehouse;
		if (!warehouse.GetWarehouseByID(ormasDal, wareID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		int debAccID10740 = warehouse.GetSubaccountID();
		int credAccID = balance.GetSubaccountID();
		int debAccID44090 = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "44090", errorMessage);
		if (0 == debAccID10740 || 0 == credAccID || 0 == debAccID44090)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, rpID, credAccID, netSum, debAccID10740, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!this->CreateEntry(ormasDal, rpID, credAccID, totalSum - netSum, debAccID44090, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReturnProduct(DataLayer::OrmasDal& ormasDal, int rpID, int cID, int wareID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		ReturnList rList;
		std::vector<ReturnListView> rListVec;
		double totalSum = 0.0;
		double netSum = 0.0;
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
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in rListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				nCost.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), wareID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					if (!nCost.GetNetCostByProductID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum += (item.GetSum() - item.GetCount()*nCost.GetValue());
					netSum += item.GetCount()*nCost.GetValue();
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetCount()*nCost.GetValue());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					if (!nCost.GetNetCostByProductID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum += (item.GetSum() - item.GetCount()*nCost.GetValue());
					netSum += item.GetCount()*nCost.GetValue();
					stock.SetCount(stock.GetCount() + item.GetCount());
					stock.SetSum(stock.GetSum() + item.GetCount()*nCost.GetValue());
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		Balance balance;
		if (!balance.GetBalanceByUserID(ormasDal, cID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		Warehouse warehouse;
		if (!warehouse.GetWarehouseByID(ormasDal, wareID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		int debAccID10740 = warehouse.GetSubaccountID();
		int credAccID = balance.GetSubaccountID();
		int debAccID44090 = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "44090", errorMessage);
		if (0 == debAccID10740 || 0 == credAccID || 0 == debAccID44090)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, rpID, debAccID10740, netSum, credAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!this->CreateEntry(ormasDal, rpID, debAccID44090, totalSum, credAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByWriteOff(DataLayer::OrmasDal& ormasDal, int wpID, int empID, std::string& errorMessage)
	{
		WriteOffList cPList;
		std::vector<WriteOffListView> cPListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int subAccID = 0;
		int warehouseID = 0;

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
			if (!GetSubIDAndWerhIDFromWOffProd(ormasDal, empID, warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in cPListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
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
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Write-off product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "44090", errorMessage);
		int credAccID = subAccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, wpID, debAccID, totalSum, credAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByWriteOffCancel(DataLayer::OrmasDal& ormasDal, int wpID, int empID, std::string& errorMessage)
	{
		WriteOffList cPList;
		std::vector<WriteOffListView> cPListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int subAccID = 0;
		int warehouseID = 0;

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
			if (!GetSubIDAndWerhIDFromWOffProd(ormasDal, empID, warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			Status status;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in cPListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Write-off product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "44090", errorMessage);
		int credAccID = subAccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, wpID, credAccID, totalSum, debAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByWriteOff(DataLayer::OrmasDal& ormasDal, int wpID, int empID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		WriteOffList cPList;
		std::vector<WriteOffListView> cPListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int subAccID = 0;
		int warehouseID = 0;

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
			if (!GetSubIDAndWerhIDFromWOffProd(ormasDal, empID, warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in cPListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName(); 
					//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
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
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Write-off product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "44090", errorMessage);
		int credAccID = subAccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, wpID, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByWriteOffRaw(DataLayer::OrmasDal& ormasDal, int wrID, int empID, std::string& errorMessage)
	{
		WriteOffRawList wRList;
		std::vector<WriteOffRawListView> wRListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int subAccID = 0;
		int warehouseID = 0;

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
			if (!GetSubIDAndWerhIDFromWOffRaw(ormasDal, empID, warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in wRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
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
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Write-off raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		int credAccID = subAccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, wrID, debAccID, totalSum, credAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByWriteOffRawCancel(DataLayer::OrmasDal& ormasDal, int wrID, int empID, std::string& errorMessage)
	{
		WriteOffRawList wRList;
		std::vector<WriteOffRawListView> wRListVec;
		double totalSum = 0.0;
		double newSum = 0.0;
		int companyID = 0;
		int subAccID = 0;
		int warehouseID = 0;

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
			if (!GetSubIDAndWerhIDFromWOffRaw(ormasDal, empID, warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			Status status;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in wRListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot order this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + std::round((product.GetPrice() * item.GetCount()) * 1000) / 1000;
					newSum = newSum + (item.GetSum());
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(std::round((product.GetPrice() * item.GetCount()) * 1000) / 1000);
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					stock.SetWarehouseID(warehouseID);
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + std::round((product.GetPrice() * item.GetCount()) * 1000) / 1000;
					newSum = newSum + (item.GetSum());
					stock.SetCount(stock.GetCount() + item.GetCount());
					stock.SetSum(stock.GetSum() + (std::round((product.GetPrice() * item.GetCount()) * 1000) / 1000));
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Write-off raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		int acc55020ID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "55020", errorMessage);
		int credAccID = subAccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, wrID, credAccID, totalSum, debAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		double checkSum = totalSum - newSum;
		if (checkSum > 0)
		{
			if (!this->CreateEntry(ormasDal, wrID, acc55020ID, checkSum, credAccID, errorMessage))
			{
				//ormasDal.CancelTransaction(errorMessage);
				return false;
			}
		}
		else if (checkSum < 0)
		{
			if (!this->CreateEntry(ormasDal, wrID, credAccID, checkSum *(-1), acc55020ID, errorMessage))
			{
				//ormasDal.CancelTransaction(errorMessage);
				return false;
			}
		}
		return true;
	}

	bool Stock::ChangingByWriteOffRaw(DataLayer::OrmasDal& ormasDal, int wrID, int empID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		WriteOffRawList wRList;
		std::vector<WriteOffRawListView> wRListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int subAccID = 0;
		int warehouseID = 0;

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
			if (!GetSubIDAndWerhIDFromWOffRaw(ormasDal, empID, warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in wRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
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
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Write-off raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		int credAccID = subAccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, wrID, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByProdConsumeRaw(DataLayer::OrmasDal& ormasDal, int pcrID, int stockEmpID, std::string& errorMessage)
	{
		ProductionConsumeRawList cRList;
		std::vector<ProductionConsumeRawListView> cRListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int subAccID = 0;
		int warehouseID = 0;

		cRList.SetProductionConsumeRawID(pcrID);
		std::string filter = cRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::productionConsumeRawListViewCollection> productListVector = ormasDal.GetProductionConsumeRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				cRListVec.push_back(ProductionConsumeRawListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			return false;
		}
		if (cRListVec.size() > 0)
		{
			if (!GetSubIDAndWerhIDFromProdnConRaw(ormasDal, stockEmpID, warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in cRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum = totalSum + item.GetSum();
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
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		int credAccID = subAccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, pcrID, debAccID, totalSum, credAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByProdConsumeRawCancel(DataLayer::OrmasDal& ormasDal, int pcrID, int stockEmpID, std::string& errorMessage)
	{
		ProductionConsumeRawList cRList;
		std::vector<ProductionConsumeRawListView> cRListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int subAccID = 0;
		int warehouseID = 0;

		cRList.SetProductionConsumeRawID(pcrID);
		std::string filter = cRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::productionConsumeRawListViewCollection> productListVector = ormasDal.GetProductionConsumeRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				cRListVec.push_back(ProductionConsumeRawListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			return false;
		}
		if (cRListVec.size() > 0)
		{
			if (!GetSubIDAndWerhIDFromProdnConRaw(ormasDal, stockEmpID, warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			Status status;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in cRListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot order this product, status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + (item.GetSum());
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetCount()*product.GetPrice());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					stock.SetWarehouseID(warehouseID);
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		int credAccID = subAccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, pcrID, credAccID, totalSum, debAccID, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByProdConsumeRaw(DataLayer::OrmasDal& ormasDal, int pcrID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		ProductionConsumeRawList cRList;
		std::vector<ProductionConsumeRawListView> cRListVec;
		double totalSum = 0.0;
		int companyID = 0;
		int subAccID = 0;
		int warehouseID = 0;

		cRList.SetProductionConsumeRawID(pcrID);
		std::string filter = cRList.GenerateFilter(ormasDal);
		std::vector<DataLayer::productionConsumeRawListViewCollection> productListVector = ormasDal.GetProductionConsumeRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				cRListVec.push_back(ProductionConsumeRawListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Consume raw list is empty!";
			return false;
		}
		if (cRListVec.size() > 0)
		{
			if (!GetSubIDAndWerhIDFromProdnConRaw(ormasDal, stockEmpID, warehouseID, subAccID, errorMessage))
				return false;
			Stock stock;
			Product product;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in cRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warehouseID, errorMessage))
				{
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					//ormasDal.CancelTransaction(errorMessage);
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
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					else
					{
						if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
							return false;
						companyID = product.GetCompanyID();
						totalSum = totalSum + item.GetSum();
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
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		CompanyAccountRelation caRel;
		int debAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		int credAccID = subAccID;
		if (0 == debAccID || 0 == credAccID)
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		if (!this->CreateEntry(ormasDal, pcrID, debAccID, totalSum, credAccID, pSum, errorMessage))
		{
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		return true;
	}

	bool Stock::ChangingByProduction(DataLayer::OrmasDal& ormasDal, int pID, int warID, std::string& errorMessage)
	{
		ProductionList rPList;
		std::vector<ProductionListView> pListVec;
		double totalSum = 0.0;
		int companyID = 0;

		rPList.SetProductionID(pID);
		std::string filter = rPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::productionListViewCollection> productListVector = ormasDal.GetProductionList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				pListVec.push_back(ProductionListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Product list is empty!";
			return false;
		}
		if (pListVec.size() > 0)
		{
			Stock pStock;
			Product product;
			Status status;
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in pListVec)
			{
				pStock.Clear();
				product.Clear();
				status.Clear();
				nCost.Clear();
				if (!pStock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					if (!nCost.GetNetCostByProductID(ormasDal, product.GetID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + round(item.GetCount()*nCost.GetValue() * 1000) / 1000;
					pStock.SetProductID(item.GetProductID());
					pStock.SetCount(item.GetCount());
					pStock.SetSum(round((item.GetCount()*nCost.GetValue()) * 1000) / 1000);
					pStock.SetCurrencyID(item.GetCurrencyID());
					pStock.SetStatusID(status.GetID());
					if (!pStock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
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
					totalSum = totalSum + item.GetCount()*nCost.GetValue();
					pStock.SetCount(pStock.GetCount() + item.GetCount());
					pStock.SetSum(pStock.GetSum() + (item.GetCount()*nCost.GetValue()));
					if (!pStock.UpdateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		return true;
	}

	bool Stock::ChangingByProduction(DataLayer::OrmasDal& ormasDal, int pID, int warID, std::map<int, double> pProdCountMap, std::string& errorMessage)
	{
		ProductionList rPList;
		std::vector<ProductionListView> pListVec;
		double totalSum = 0.0;
		int companyID = 0;

		rPList.SetProductionID(pID);
		std::string filter = rPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::productionListViewCollection> productListVector = ormasDal.GetProductionList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				pListVec.push_back(ProductionListView(item));
			}
		}
		else
		{
			errorMessage = "ERROR! Product list is empty!";
			return false;
		}
		if (pListVec.size() > 0)
		{
			Stock pStock;
			Product product;
			Status status;
			NetCost nCost;
			//ormasDal.StartTransaction(errorMessage);
			for each (auto item in pListVec)
			{
				pStock.Clear();
				product.Clear();
				status.Clear();
				nCost.Clear();
				if (!pStock.GetStockByProductAndWarehouseID(ormasDal, item.GetProductID(), warID, errorMessage))
				{
					errorMessage.clear();
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Status is not valied!";
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
					if (!product.GetProductByID(ormasDal, item.GetProductID(), errorMessage))
						return false;
					if (!nCost.GetNetCostByProductID(ormasDal, product.GetID(), errorMessage))
						return false;
					companyID = product.GetCompanyID();
					totalSum = totalSum + item.GetCount()*nCost.GetValue();
					pStock.SetProductID(item.GetProductID());
					pStock.SetCount(item.GetCount());
					pStock.SetSum((item.GetCount()*nCost.GetValue()));
					pStock.SetCurrencyID(item.GetCurrencyID());
					pStock.SetStatusID(status.GetID());
					if (!pStock.CreateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
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
					totalSum = totalSum + item.GetCount()*nCost.GetValue();
					pStock.SetCount(pStock.GetCount() + (item.GetCount() - pProdCountMap.find(product.GetID())->second));
					pStock.SetSum(pStock.GetSum() + ((item.GetCount()*nCost.GetValue()) - (pProdCountMap.find(product.GetID())->second * nCost.GetValue())));
					if (!pStock.UpdateStock(ormasDal, errorMessage))
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Product list is empty!";
			//ormasDal.CancelTransaction(errorMessage);
			return false;
		}

		return true;
	}

	bool Stock::RecalculateStock(DataLayer::OrmasDal& ormasDal, int pID, double oldPrice, double newPrice, std::string& errorMessage)
	{
		Stock checkStock;
		Stock stock;
		std::vector<DataLayer::stockViewCollection> stockVector;
		std::string filter;
		WarehouseType wType;
		Warehouse warehouse;
		Product product;
		ProductType pType;
		checkStock.Clear();
		int companyID = 0;
		double difference = 0;
		if (!wType.GetWarehouseTypeByCode(ormasDal, "RAW", errorMessage))
		{
			return false;
		}
		checkStock.SetProductID(pID);
		filter = checkStock.GenerateFilter(ormasDal);
		stockVector = ormasDal.GetStock(errorMessage, filter);
		if (stockVector.size() == 0)
		{
			return true;
		}
		else
		{
			for each (auto stockObject in stockVector)
			{
				stock.Clear();
				warehouse.Clear();
				product.Clear();
				pType.Clear();
				if (!stock.GetStockByID(ormasDal, std::get<0>(stockObject), errorMessage))
					return false;
				if (stock.GetCount() > 0)
				{
					if (!warehouse.GetWarehouseByID(ormasDal, stock.GetWarehouseID(), errorMessage))
						return false;
					if (warehouse.GetWarehouseTypeID() == wType.GetID())
					{
						if (!product.GetProductByID(ormasDal, pID, errorMessage))
							return false;
						if (!pType.GetProductTypeByCode(ormasDal, "PRODUCT", errorMessage))
							return false;
						if (product.GetProductTypeID() == pType.GetID())
							continue;

						companyID = product.GetCompanyID();
						difference = std::round((stock.GetCount()*newPrice - stock.GetCount()*oldPrice) * 1000) / 1000;
						stock.SetSum(stock.GetSum() + difference);
						stock.UpdateStock(ormasDal, errorMessage);


						if (difference > 0 && difference != 0)
						{
							CompanyAccountRelation caRel;
							int debAccID = warehouse.GetSubaccountID();
							int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "55020", errorMessage);
							if (0 == debAccID || 0 == credAccID)
							{
								return false;
							}
							if (!this->CreateEntry(ormasDal, product.GetID(), debAccID, difference, credAccID, errorMessage))
							{
								return false;
							}
						}
						if (difference < 0 && difference != 0)
						{
							CompanyAccountRelation caRel;
							int debAccID = warehouse.GetSubaccountID();
							int credAccID = caRel.GetAccountIDByCompanyID(ormasDal, companyID, "55020", errorMessage);
							if (0 == debAccID || 0 == credAccID)
							{
								return false;
							}
							if (!this->CreateEntry(ormasDal, product.GetID(), credAccID, difference * (-1), debAccID, errorMessage))
							{
								return false;
							}
						}
					}
				}
			}
		}
		return true;		
	}
	
	bool Stock::CreateEntry(DataLayer::OrmasDal& ormasDal, int operationID, int debAccID, double currentSum, int credAccID, std::string& errorMessage)
	{
		Entry entry;
		EntryOperationRelation eoRelation;
		entry.SetDate(ormasDal.GetSystemDateTime());
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		std::string	entryText;
		entryText += wstring_to_utf8(L"��������� ��������. ID �������� = ");
		entryText += std::to_string(operationID);
		entry.SetDescription(entryText);
		if (entry.CreateEntry(ormasDal, errorMessage))
		{
			eoRelation.SetEntryID(entry.GetID());
			eoRelation.SetOperationID(operationID);
			if (!eoRelation.CreateEntryOperationRelation(ormasDal, errorMessage))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		return true;
	}
	bool Stock::CreateEntry(DataLayer::OrmasDal& ormasDal, int operationID, int debAccID, double currentSum, int credAccID, double previousSum, std::string& errorMessage)
	{
		Entry entry;
		EntryOperationRelation eoRelation;
		entry.SetDate(ormasDal.GetSystemDateTime());
		entry.SetDebitingAccountID(credAccID);
		entry.SetValue(previousSum);
		entry.SetCreditingAccountID(debAccID);
		std::string	entryText;
		entryText += wstring_to_utf8(L"��������� ��������. ID �������� = ");
		entryText += std::to_string(operationID);
		entry.SetDescription(entryText);
		if (entry.CreateEntry(ormasDal, errorMessage, true))
		{
			eoRelation.SetEntryID(entry.GetID());
			eoRelation.SetOperationID(operationID);
			if (!eoRelation.CreateEntryOperationRelation(ormasDal, errorMessage))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		entry.Clear();
		eoRelation.Clear();
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		entryText += wstring_to_utf8(L"��������� ��������. ID �������� = ");
		entryText += std::to_string(operationID);
		entry.SetDescription(entryText);
		if (entry.CreateEntry(ormasDal, errorMessage))
		{
			eoRelation.SetEntryID(entry.GetID());
			eoRelation.SetOperationID(operationID);
			if (!eoRelation.CreateEntryOperationRelation(ormasDal, errorMessage))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		return true;
	}

	bool Stock::CreateCorrectongEntry(DataLayer::OrmasDal& ormasDal, int operationID, int debAccID, double currentSum, int credAccID, std::string& errorMessage)
	{
		Entry entry;
		EntryOperationRelation eoRelation;
		entry.SetDate(ormasDal.GetSystemDateTime());
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		std::string	entryText;
		entryText += wstring_to_utf8(L"��������� ����� 10740 ������� ���������, ����� ���������� ������������� ��������, ID �������� = ");
		entryText += std::to_string(operationID);
		entry.SetDescription(entryText);
		if (entry.CreateEntry(ormasDal, errorMessage))
		{
			eoRelation.SetEntryID(entry.GetID());
			eoRelation.SetOperationID(operationID);
			if (!eoRelation.CreateEntryOperationRelation(ormasDal, errorMessage))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		return true;
	}
	
	bool Stock::CreateCorrectongEntry(DataLayer::OrmasDal& ormasDal, int operationID, int debAccID, double currentSum, int credAccID, double previousSum, std::string& errorMessage)
	{
		Entry entry;
		EntryOperationRelation eoRelation;
		entry.SetDate(ormasDal.GetSystemDateTime());
		entry.SetDebitingAccountID(credAccID);
		entry.SetValue(previousSum);
		entry.SetCreditingAccountID(debAccID);
		std::string	entryText;
		entryText += wstring_to_utf8(L"��������� ����� 10740 ������� ���������, ����� ���������� ������������� ��������, ID �������� = ");
		entryText += std::to_string(operationID);
		entry.SetDescription(entryText);
		if (entry.CreateEntry(ormasDal, errorMessage, true))
		{
			eoRelation.SetEntryID(entry.GetID());
			eoRelation.SetOperationID(operationID);
			if (!eoRelation.CreateEntryOperationRelation(ormasDal, errorMessage))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		entry.Clear();
		eoRelation.Clear();
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		entryText += wstring_to_utf8(L"��������� ����� 10740 ������� ���������, ����� ���������� ������������� ��������, ID �������� = ");
		entryText += std::to_string(operationID);
		entry.SetDescription(entryText);
		if (entry.CreateEntry(ormasDal, errorMessage))
		{
			eoRelation.SetEntryID(entry.GetID());
			eoRelation.SetOperationID(operationID);
			if (!eoRelation.CreateEntryOperationRelation(ormasDal, errorMessage))
			{
				return false;
			}
		}
		else
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

	bool Stock::GetSubIDAndWerhIDFromConProd(DataLayer::OrmasDal& ormasDal, int stockEmpID, int& warehouseID, int& subAccID, std::string& errorMessage)
	{
		WarehouseEmployeeRelation weRel;
		Warehouse warehouse;
		if (!weRel.GetWarehouseEmployeeByEmployeeID(ormasDal, stockEmpID, errorMessage))
			return false;
		if (!warehouse.GetWarehouseByID(ormasDal, weRel.GetWarehouseID(), errorMessage))
			return false;
		warehouseID = warehouse.GetID();
		subAccID = warehouse.GetSubaccountID();
		return true;
	}

	bool Stock::GetSubIDAndWerhIDFromConRaw(DataLayer::OrmasDal& ormasDal, int empID, int stockEmpID,  int& debWerID, int& credWerID, int& debSaccID, int& credSaccID, std::string& errorMessage)
	{
		
		WarehouseEmployeeRelation weRel;
		Warehouse warehouse;
		if (!weRel.GetWarehouseEmployeeByEmployeeID(ormasDal, empID, errorMessage))
			return false;
		if (!warehouse.GetWarehouseByID(ormasDal, weRel.GetWarehouseID(), errorMessage))
			return false;
		debSaccID = warehouse.GetSubaccountID();
		debWerID = warehouse.GetID();
		weRel.Clear();
		warehouse.Clear();
		if (!weRel.GetWarehouseEmployeeByEmployeeID(ormasDal, stockEmpID, errorMessage))
			return false;
		if (!warehouse.GetWarehouseByID(ormasDal, weRel.GetWarehouseID(), errorMessage))
			return false;
		credSaccID = warehouse.GetSubaccountID();
		credWerID = warehouse.GetID();
		return true;
	}

	bool Stock::GetSubIDAndWerhIDFromOrderRaw(DataLayer::OrmasDal& ormasDal, int empID, int& warehouseID, int& subAccID, std::string& errorMessage)
	{
		WarehouseEmployeeRelation weRel;
		Warehouse warehouse;
		if (!weRel.GetWarehouseEmployeeByEmployeeID(ormasDal, empID, errorMessage))
			return false;
		if (!warehouse.GetWarehouseByID(ormasDal, weRel.GetWarehouseID(), errorMessage))
			return false;
		warehouseID = warehouse.GetID();
		subAccID = warehouse.GetSubaccountID();
		return true;
	}

	bool Stock::GetSubIDAndWerhIDFromRcpRaw(DataLayer::OrmasDal& ormasDal, int empID, int stockEmpID, int& debWerID, int& credWerID, int& debSaccID, int& credSaccID, std::string& errorMessage)
	{
		WarehouseEmployeeRelation weRel;
		Warehouse warehouse;
		if (!weRel.GetWarehouseEmployeeByEmployeeID(ormasDal, empID, errorMessage))
			return false;
		if (!warehouse.GetWarehouseByID(ormasDal, weRel.GetWarehouseID(), errorMessage))
			return false;
		credSaccID = warehouse.GetSubaccountID();
		credWerID = warehouse.GetID();
		weRel.Clear();
		warehouse.Clear();
		if (!weRel.GetWarehouseEmployeeByEmployeeID(ormasDal, stockEmpID, errorMessage))
			return false;
		if (!warehouse.GetWarehouseByID(ormasDal, weRel.GetWarehouseID(), errorMessage))
			return false;
		debSaccID = warehouse.GetSubaccountID();
		debWerID = warehouse.GetID();
		return true;
	}

	bool Stock::GetSubIDAndWerhIDFromRcpProd(DataLayer::OrmasDal& ormasDal, int empID, int stockEmpID, int& debWerID, int& credWerID, int& debSaccID, int& credSaccID, std::string& errorMessage)
	{
		WarehouseEmployeeRelation weRel;
		Warehouse warehouse;
		if (!weRel.GetWarehouseEmployeeByEmployeeID(ormasDal, empID, errorMessage))
			return false;
		if (!warehouse.GetWarehouseByID(ormasDal, weRel.GetWarehouseID(), errorMessage))
			return false;
		credSaccID = warehouse.GetSubaccountID();
		credWerID = warehouse.GetID();
		weRel.Clear();
		warehouse.Clear();
		if (!weRel.GetWarehouseEmployeeByEmployeeID(ormasDal, stockEmpID, errorMessage))
			return false;
		if (!warehouse.GetWarehouseByID(ormasDal, weRel.GetWarehouseID(), errorMessage))
			return false;
		debSaccID = warehouse.GetSubaccountID();
		debWerID = warehouse.GetID();
		return true;
	}

	bool Stock::GetSubIDAndWerhIDFromRtrnProd(DataLayer::OrmasDal& ormasDal, int empID, int& warehouseID, int& subAccID, std::string& errorMessage)
	{
		WarehouseEmployeeRelation weRel;
		Warehouse warehouse;
		if (!weRel.GetWarehouseEmployeeByEmployeeID(ormasDal, empID, errorMessage))
			return false;
		if (!warehouse.GetWarehouseByID(ormasDal, weRel.GetWarehouseID(), errorMessage))
			return false;
		subAccID = warehouse.GetSubaccountID();
		warehouseID = warehouse.GetID();
		return true;
	}

	bool Stock::GetSubIDAndWerhIDFromWOffProd(DataLayer::OrmasDal& ormasDal, int empID, int& warehouseID, int& subAccID, std::string& errorMessage)
	{
		WarehouseEmployeeRelation weRel;
		Warehouse warehouse;
		if (!weRel.GetWarehouseEmployeeByEmployeeID(ormasDal, empID, errorMessage))
			return false;
		if (!warehouse.GetWarehouseByID(ormasDal, weRel.GetWarehouseID(), errorMessage))
			return false;
		subAccID = warehouse.GetSubaccountID();
		warehouseID = warehouse.GetID();
		return true;
	}

	bool Stock::GetSubIDAndWerhIDFromProdnConRaw(DataLayer::OrmasDal& ormasDal, int stockEmpID, int& warehouseID, int& subAccID, std::string& errorMessage)
	{
		WarehouseEmployeeRelation weRel;
		Warehouse warehouse;
		if (!weRel.GetWarehouseEmployeeByEmployeeID(ormasDal, stockEmpID, errorMessage))
			return false;
		if (!warehouse.GetWarehouseByID(ormasDal, weRel.GetWarehouseID(), errorMessage))
			return false;
		subAccID = warehouse.GetSubaccountID();
		warehouseID = warehouse.GetID();
		return true;
	}

	bool Stock::GetSubIDAndWerhIDFromWOffRaw(DataLayer::OrmasDal& ormasDal, int empID, int& warehouseID, int& subAccID, std::string& errorMessage)
	{
		WarehouseEmployeeRelation weRel;
		Warehouse warehouse;
		if (!weRel.GetWarehouseEmployeeByEmployeeID(ormasDal, empID, errorMessage))
			return false;
		if (!warehouse.GetWarehouseByID(ormasDal, weRel.GetWarehouseID(), errorMessage))
			return false;
		subAccID = warehouse.GetSubaccountID();
		warehouseID = warehouse.GetID();
		return true;
	}
}