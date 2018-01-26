#include "stdafx.h"
#include "StockClass.h"
#include "ConsumeProductListClass.h"
#include "ConsumeProductListViewClass.h"
#include "ConsumeRawListClass.h"
#include "ConsumeRawListViewClass.h"
#include "ReceiptProductListClass.h"
#include "ReceiptProductListViewClass.h"
#include "ReceiptRawListClass.h"
#include "ReceiptRawListViewClass.h"
#include "WriteOffListClass.h"
#include "WriteOffListViewClass.h"
#include "WriteOffRawListClass.h"
#include "WriteOffRawListViewClass.h"
#include "ProductClass.h"
#include "StatusClass.h"

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

	int Stock::GetCount()
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
	void Stock::SetCount(int sCount)
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

	bool Stock::CreateStock(DataLayer::OrmasDal& ormasDal, int pID, int sCount, double sSum,
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
			id = 0;
			productID = 0;
			count = 0;
			sum = 0;
			statusID = 0;
			currencyID = 0;
			return true;
		}
		return false;
	}

	bool Stock::UpdateStock(DataLayer::OrmasDal& ormasDal, int pID, int sCount, double sSum,
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
			for each (auto item in cPListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += stock.GetCount();
						return false;
					}
					else
					{
						stock.SetCount(stock.GetCount() - item.GetCount());
						stock.SetSum(stock.GetSum() - item.GetSum());
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
			errorMessage = "ERROR! Consume product list is empty!";
			return false;
		}
		return true;
	}

	bool Stock::ChangingByConsumeProduct(DataLayer::OrmasDal& ormasDal, int cpID, double pSum, int pCount, std::string& errorMessage)
	{
		ConsumeProductList cPList;
		std::vector<ConsumeProductListView> cPListVec;

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
			for each (auto item in cPListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += stock.GetCount();
						return false;
					}
					else
					{
						stock.SetCount(stock.GetCount() - (item.GetCount() - pCount));
						stock.SetSum(stock.GetSum() - (item.GetSum() - pSum));
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
			errorMessage = "ERROR! Consume product list is empty!";
			return false;
		}
		return true;
	}

	bool Stock::ChangingByConsumeRaw(DataLayer::OrmasDal& ormasDal, int crID, std::string& errorMessage)
	{
		ConsumeRawList cRList;
		std::vector<ConsumeRawListView> cRListVec;

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
			for each (auto item in cRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += stock.GetCount();
						return false;
					}
					else
					{
						stock.SetCount(stock.GetCount() - item.GetCount());
						stock.SetSum(stock.GetSum() - item.GetSum());
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
			return false;
		}
		return true;
	}

	bool Stock::ChangingByConsumeRaw(DataLayer::OrmasDal& ormasDal, int crID, double pSum, int pCount, std::string& errorMessage)
	{
		ConsumeRawList cRList;
		std::vector<ConsumeRawListView> cRListVec;

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
			for each (auto item in cRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += stock.GetCount();
						return false;
					}
					else
					{
						stock.SetCount(stock.GetCount() - (item.GetCount() - pCount));
						stock.SetSum(stock.GetSum() - (item.GetSum() - pSum));
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
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReceiptProduct(DataLayer::OrmasDal& ormasDal, int rpID, std::string& errorMessage)
	{
		ReceiptProductList rPList;
		std::vector<ReceiptProductListView> rPListVec;

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
			for each (auto item in rPListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						return false;
					}
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetSum());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					if (!stock.CreateStock(ormasDal,errorMessage))
					{
						return false;
					}
				}
				else
				{
					stock.SetCount(stock.GetCount() + item.GetCount());
					stock.SetSum(stock.GetSum() + item.GetSum());
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt product list is empty!";
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReceiptProduct(DataLayer::OrmasDal& ormasDal, int rpID, double pSum, int pCount, std::string& errorMessage)
	{
		ReceiptProductList rPList;
		std::vector<ReceiptProductListView> rPListVec;

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
			for each (auto item in rPListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						return false;
					}
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetSum());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						return false;
					}
				}
				else
				{
					stock.SetCount(stock.GetCount() + (item.GetCount() - pCount));
					stock.SetSum(stock.GetSum() + (item.GetSum() -  pSum));
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt product list is empty!";
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReceiptRaw(DataLayer::OrmasDal& ormasDal, int rrID, std::string& errorMessage)
	{
		ReceiptRawList rRList;
		std::vector<ReceiptRawListView> rRListVec;

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
			for each (auto item in rRListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						return false;
					}
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetSum());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						return false;
					}
				}
				else
				{
					stock.SetCount(stock.GetCount() + item.GetCount());
					stock.SetSum(stock.GetSum() + item.GetSum());
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt raw list is empty!";
			return false;
		}
		return true;
	}

	bool Stock::ChangingByReceiptRaw(DataLayer::OrmasDal& ormasDal, int rrID, double pSum, int pCount, std::string& errorMessage)
	{
		ReceiptRawList rRList;
		std::vector<ReceiptRawListView> rRListVec;

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
			for each (auto item in rRListVec)
			{
				stock.Clear();
				product.Clear();
				status.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					if (!status.GetStatusByName(ormasDal, "IN STOCK", errorMessage))
					{
						errorMessage = "ERROR! Cannot receipt this product, status is not valied!";
						return false;
					}
					stock.SetProductID(item.GetProductID());
					stock.SetCount(item.GetCount());
					stock.SetSum(item.GetSum());
					stock.SetCurrencyID(item.GetCurrencyID());
					stock.SetStatusID(status.GetID());
					if (!stock.CreateStock(ormasDal, errorMessage))
					{
						return false;
					}
				}
				else
				{
					stock.SetCount(stock.GetCount() + (item.GetCount() - pCount));
					stock.SetSum(stock.GetSum() + (item.GetSum() - pSum));
					if (!stock.UpdateStock(ormasDal, errorMessage))
					{
						return false;
					}
				}
			}
		}
		else
		{
			errorMessage = "ERROR! Receipt raw list is empty!";
			return false;
		}
		return true;
	}

	bool Stock::ChangingByWriteOff(DataLayer::OrmasDal& ormasDal, int wpID, std::string& errorMessage)
	{
		WriteOffList cPList;
		std::vector<WriteOffListView> cPListVec;

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
			for each (auto item in cPListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += stock.GetCount();
						return false;
					}
					else
					{
						stock.SetCount(stock.GetCount() - item.GetCount());
						stock.SetSum(stock.GetSum() - item.GetSum());
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
			errorMessage = "ERROR! Write-off product list is empty!";
			return false;
		}
		return true;
	}

	bool Stock::ChangingByWriteOff(DataLayer::OrmasDal& ormasDal, int wpID, double pSum, int pCount, std::string& errorMessage)
	{
		WriteOffList cPList;
		std::vector<WriteOffListView> cPListVec;

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
			for each (auto item in cPListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += stock.GetCount();
						return false;
					}
					else
					{
						stock.SetCount(stock.GetCount() - (item.GetCount() - pCount));
						stock.SetSum(stock.GetSum() - (item.GetSum() - pSum));
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
			errorMessage = "ERROR! Write-off product list is empty!";
			return false;
		}
		return true;
	}

	bool Stock::ChangingByWriteOffRaw(DataLayer::OrmasDal& ormasDal, int wrID, std::string& errorMessage)
	{
		WriteOffRawList wRList;
		std::vector<WriteOffRawListView> wRListVec;

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
			for each (auto item in wRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += stock.GetCount();
						return false;
					}
					else
					{
						stock.SetCount(stock.GetCount() - item.GetCount());
						stock.SetSum(stock.GetSum() - item.GetSum());
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
			errorMessage = "ERROR! Write-off raw list is empty!";
			return false;
		}
		return true;
	}

	bool Stock::ChangingByWriteOffRaw(DataLayer::OrmasDal& ormasDal, int wrID, double pSum, int pCount, std::string& errorMessage)
	{
		WriteOffRawList wRList;
		std::vector<WriteOffRawListView> wRListVec;

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
			for each (auto item in wRListVec)
			{
				stock.Clear();
				product.Clear();
				if (!stock.GetStockByProductID(ormasDal, item.GetProductID(), errorMessage))
				{
					product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
					errorMessage = "ERROR! This product is out of stock:";
					errorMessage += product.GetName();
					return false;
				}
				else
				{
					if (stock.GetCount() < item.GetCount())
					{
						product.GetProductByID(ormasDal, item.GetProductID(), errorMessage);
						errorMessage = "ERROR! There is not enough product in the stock!";
						errorMessage += " Product name:";
						errorMessage += product.GetName();
						errorMessage += ", Product count:";
						errorMessage += stock.GetCount();
						return false;
					}
					else
					{
						stock.SetCount(stock.GetCount() - (item.GetCount() - pCount));
						stock.SetSum(stock.GetSum() - (item.GetSum() - pSum));
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
			errorMessage = "ERROR! Write-off raw list is empty!";
			return false;
		}
		return true;
	}
}