#include "stdafx.h"
#include "ReceiptProductClass.h"
#include "ReceiptProductListClass.h"
#include "UserClass.h"
#include "StatusClass.h"
#include "StockClass.h"
#include "ProductionStockClass.h"

namespace BusinessLayer
{
	ReceiptProduct::ReceiptProduct(DataLayer::receiptProductsCollection rpCollection)
	{
		id = std::get<0>(rpCollection);
		employeeID = std::get<1>(rpCollection);
		date = std::get<2>(rpCollection);
		executionDate = std::get<3>(rpCollection);
		stockEmployeeID = std::get<4>(rpCollection);
		count = std::get<5>(rpCollection);
		sum = std::get<6>(rpCollection);
		statusID = std::get<7>(rpCollection);
		currencyID = std::get<8>(rpCollection);
	}

	int ReceiptProduct::GetID()
	{
		return id;
	}

	int ReceiptProduct::GetEmployeeID()
	{
		return employeeID;
	}

	std::string ReceiptProduct::GetDate()
	{
		return date;
	}

	std::string ReceiptProduct::GetExecutionDate()
	{
		return executionDate;
	}

	int ReceiptProduct::GetStockEmployeeID()
	{
		return stockEmployeeID;
	}

	double ReceiptProduct::GetCount()
	{
		return count;
	}

	double ReceiptProduct::GetSum()
	{
		return sum;
	}

	int ReceiptProduct::GetStatusID()
	{
		return statusID;
	}

	int ReceiptProduct::GetCurrencyID()
	{
		return currencyID;
	}

	void ReceiptProduct::SetID(int rID)
	{
		id = rID;
	}
	void ReceiptProduct::SetEmployeeID(int rEmployeeID)
	{
		employeeID = rEmployeeID;
	}
	void ReceiptProduct::SetDate(std::string rDate)
	{
		date = rDate;
	}
	void ReceiptProduct::SetExecutionDate(std::string rExecutionDate)
	{
		executionDate = rExecutionDate;
	}
	void ReceiptProduct::SetStockEmployeeID(int rStockEmployeeID)
	{
		stockEmployeeID = rStockEmployeeID;
	}

	void ReceiptProduct::SetCount(double rCount)
	{
		count = rCount;
	}

	void ReceiptProduct::SetSum(double rSum)
	{
		sum = rSum;
	}

	void ReceiptProduct::SetStatusID(int rStatusID)
	{
		statusID = rStatusID;
	}

	void ReceiptProduct::SetCurrencyID(int rCurrencyID)
	{
		currencyID = rCurrencyID;
	}

	bool ReceiptProduct::CreateReceiptProduct(DataLayer::OrmasDal& ormasDal, int uID, std::string rpDate, std::string rpExecDate, 
		int seID, double rpCount, double rpSum, int sID, int cID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, uID, rpDate, seID ,rpCount, rpSum, cID, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		employeeID = uID;
		date = rpDate;
		executionDate = rpExecDate;
		stockEmployeeID = seID;
		count = rpCount;
		sum = rpSum;
		statusID = sID;
		currencyID = cID;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateReceiptProduct(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
				{
					//ormasDal.CommitTransaction(errorMessage);
					return true;
				}
				else
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
			//ormasDal.CommitTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	bool ReceiptProduct::CreateReceiptProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateReceiptProduct(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
				{
					//ormasDal.CommitTransaction(errorMessage);
					return true;
				}
				else
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
				
			}
			//ormasDal.CommitTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool ReceiptProduct::DeleteReceiptProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		//if (!ormasDal.StartTransaction(errorMessage))
		//	return false;
		ReceiptProduct rProduct;
		if (!rProduct.GetReceiptProductByID(ormasDal, id, errorMessage))
		{
			return false;
		}
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		if (rProduct.GetStatusID() == statusMap.find("EXECUTED")->second)
		{
			errorMessage = "Cannot delete document with \"EXECUTED\" status!";
			return false;
		}
		if (rProduct.GetStatusID() == statusMap.find("ERROR")->second)
		{
			errorMessage = "Cannot delete document with \"ERROR\" status!";
			return false;
		}
		if (ormasDal.DeleteReceiptProduct(id, errorMessage))
		{
			if (ormasDal.DeleteListByReceiptProductID(id, errorMessage))
			{
				Clear();
				//ormasDal.CommitTransaction(errorMessage);
				return true;
			}
			else
			{
				//ormasDal.CancelTransaction(errorMessage);
			}
		}
		else
		{
			//ormasDal.CancelTransaction(errorMessage);
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool ReceiptProduct::UpdateReceiptProduct(DataLayer::OrmasDal& ormasDal, int uID, std::string rpDate, std::string rpExecnDate,
		int eID, double rpCount, double rpSum, int sID, int cID, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		std::map<int, double> prodCountMap = GetProductCount(ormasDal, id, errorMessage);
		if (0 == prodCountMap.size())
			return false;
		employeeID = uID;
		date = rpDate;
		executionDate = rpExecnDate;
		stockEmployeeID = eID;
		count = rpCount;
		sum = rpSum;
		statusID = sID;
		currencyID = cID;
		prevSum = GetCurrentSum(ormasDal, id, errorMessage);
		prevCount = GetCurrentCount(ormasDal, id, errorMessage);
		previousStatusID = GetCurrentStatusID(ormasDal, id, errorMessage);
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateReceiptProduct(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (statusID == statusMap.find("EXECUTED")->second)
				{
					if (ChangesAtStock(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
					{						
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CommitTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					return true;
				}
			}
			else
			{
				if (statusID == statusMap.find("ERROR")->second)
				{
					if (ChangesAtStockCancel(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
					{
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CommitTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					errorMessage = "Cannot update this document, only \"Error\" status is acceptable!";
					return false;
				}
			}
			/*if (statusID == statusMap.find("EXECUTED")->second && previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
				{
					//ormasDal.CommitTransaction(errorMessage);
					return true;
				}
				else
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID == statusMap.find("EXECUTED")->second)
			{
				if (count != prevCount || sum != prevSum)
				{
					if (ChangesAtStock(ormasDal, id, employeeID, stockEmployeeID, prodCountMap, prevSum, errorMessage))
					{
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}					
				}
				else
				{
					//ormasDal.CommitTransaction(errorMessage);
					return true;
				}
			}
			//ormasDal.CommitTransaction(errorMessage);
			return true;*/
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool ReceiptProduct::UpdateReceiptProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		std::map<int, double> prodCountMap = GetProductCount(ormasDal, id, errorMessage);
		if (0 == prodCountMap.size())
			return false;
		prevSum = GetCurrentSum(ormasDal, id, errorMessage);
		prevCount = GetCurrentCount(ormasDal, id, errorMessage);
		previousStatusID = GetCurrentStatusID(ormasDal, id, errorMessage);
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateReceiptProduct(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (statusID == statusMap.find("EXECUTED")->second)
				{
					if (ChangesAtStock(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
					{
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CommitTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					return true;
				}
			}
			else
			{
				if (statusID == statusMap.find("ERROR")->second)
				{
					if (ChangesAtStockCancel(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
					{
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CommitTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					errorMessage = "Cannot update this document, only \"Error\" status is acceptable!";
					return false;
				}
			}
			/*if (statusID == statusMap.find("EXECUTED")->second && previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
				{
					//ormasDal.CommitTransaction(errorMessage);
					return true;
				}
				else
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID == statusMap.find("EXECUTED")->second)
			{
				if (count != prevCount || sum != prevSum)
				{
					if (ChangesAtStock(ormasDal, id, employeeID, stockEmployeeID, prodCountMap, prevSum, errorMessage))
					{
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					//ormasDal.CommitTransaction(errorMessage);
					return true;
				}
			}
			//ormasDal.CommitTransaction(errorMessage);
			return true;*/
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	std::string ReceiptProduct::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != employeeID || !date.empty() || !executionDate.empty() || 0 != stockEmployeeID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForReceiptProduct(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool ReceiptProduct::GetReceiptProductByID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage)
	{
		if (cID <= 0)
			return false;
		id = cID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptProductsViewCollection> receiptProductVector = ormasDal.GetReceiptProducts(errorMessage, filter);
		if (0 != receiptProductVector.size())
		{
			id = std::get<0>(receiptProductVector.at(0));
			date = std::get<1>(receiptProductVector.at(0));
			executionDate = std::get<2>(receiptProductVector.at(0));
			count = std::get<13>(receiptProductVector.at(0));
			sum = std::get<14>(receiptProductVector.at(0));
			stockEmployeeID = std::get<16>(receiptProductVector.at(0));
			employeeID = std::get<17>(receiptProductVector.at(0));
			statusID = std::get<18>(receiptProductVector.at(0));
			currencyID = std::get<19>(receiptProductVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find receipt product with this id";
		}
		return false;
	}

	bool ReceiptProduct::IsEmpty()
	{
		if (0 == id && date == "" && executionDate == "" && 0 == count && 0 == sum && 0 == stockEmployeeID && 0 == employeeID && 0 == statusID
			&& 0 == currencyID)
			return false;
		return true;
	}

	void ReceiptProduct::Clear()
	{
		id = 0;
		date.clear();
		executionDate.clear();
		count = 0;
		sum = 0;
		stockEmployeeID = 0;
		employeeID = 0;
		statusID = 0;
		currencyID = 0;
	}

	bool ReceiptProduct::IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string rDate, int seID, double rCount, double rSum,
		int cID, std::string& errorMessage)
	{
		ReceiptProduct receiptProduct;
		receiptProduct.Clear();
		errorMessage.clear();
		receiptProduct.SetEmployeeID(eID);
		receiptProduct.SetDate(rDate);
		receiptProduct.SetStockEmployeeID(seID);
		receiptProduct.SetCount(rCount);
		receiptProduct.SetSum(rSum);
		receiptProduct.SetCurrencyID(cID);
		std::string filter = receiptProduct.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptProductsViewCollection> receiptProductVector = ormasDal.GetReceiptProducts(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == receiptProductVector.size())
		{
			return false;
		}
		errorMessage = "Receipt product with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool ReceiptProduct::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		ReceiptProduct receiptProduct;
		receiptProduct.Clear();
		errorMessage.clear();
		receiptProduct.SetEmployeeID(employeeID);
		receiptProduct.SetDate(date);
		receiptProduct.SetStockEmployeeID(stockEmployeeID);
		receiptProduct.SetCount(count);
		receiptProduct.SetSum(sum);
		receiptProduct.SetCurrencyID(currencyID);
		std::string filter = receiptProduct.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptProductsViewCollection> receiptProductVector = ormasDal.GetReceiptProducts(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == receiptProductVector.size())
		{
			return false;
		}
		errorMessage = "Receipt product with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	/*bool ReceiptProduct::ChangesAtProdStock(DataLayer::OrmasDal& ormasDal, int crID, std::string& errorMessage)
	{
		Stock pStock;
		return pStock.ChangingByConsumeProduct(ormasDal, crID, errorMessage);
	}

	bool ReceiptProduct::ChangesAtProdStock(DataLayer::OrmasDal& ormasDal, int crID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		Stock pStock;
		return pStock.ChangingByReceiptProductA(ormasDal, crID, pProdCountMap, pSum, errorMessage);
	}*/

	bool ReceiptProduct::ChangesAtStock(DataLayer::OrmasDal& ormasDal, int rpID, int empID, int stockEmpID, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByReceiptProduct(ormasDal, rpID, empID, stockEmpID, errorMessage);
	}

	bool ReceiptProduct::ChangesAtStockCancel(DataLayer::OrmasDal& ormasDal, int rpID, int empID, int stockEmpID, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByReceiptProductCancel(ormasDal, rpID, empID, stockEmpID, errorMessage);
	}

	bool ReceiptProduct::ChangesAtStock(DataLayer::OrmasDal& ormasDal, int rpID, int empID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByReceiptProduct(ormasDal, rpID, empID, stockEmpID, pProdCountMap, pSum, errorMessage);
	}

	double ReceiptProduct::GetCurrentSum(DataLayer::OrmasDal& ormasDal, int rpID, std::string& errorMessage)
	{
		ReceiptProduct rProduct;
		if (rProduct.GetReceiptProductByID(ormasDal, rpID, errorMessage))
			return rProduct.GetSum();
		return 0;
	}

	double ReceiptProduct::GetCurrentCount(DataLayer::OrmasDal& ormasDal, int rpID, std::string& errorMessage)
	{
		ReceiptProduct rProduct;
		if (rProduct.GetReceiptProductByID(ormasDal, rpID, errorMessage))
			return rProduct.GetCount();
		return 0;
	}

	int ReceiptProduct::GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage)
	{
		ReceiptProduct rProduct;
		if (rProduct.GetReceiptProductByID(ormasDal, cID, errorMessage))
			return rProduct.GetStatusID();
		return 0;
	}

	std::map<int, double> ReceiptProduct::GetProductCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		std::map<int, double> mapProdCount;
		ReceiptProductList rPList;
		rPList.SetReceiptProductID(cpID);
		std::string filter = rPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptProductListViewCollection> productListVector = ormasDal.GetReceiptProductList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				mapProdCount.insert(std::make_pair(std::get<11>(item), std::get<7>(item)));
			}
		}
		return mapProdCount;
	}
}