#include "stdafx.h"
#include "ConsumeProductClass.h"
#include "ConsumeProductListClass.h"
#include "UserClass.h"
#include "StatusClass.h"
#include "StockClass.h"
#include "TransportClass.h"

namespace BusinessLayer
{
	ConsumeProduct::ConsumeProduct(DataLayer::consumeProductsCollection cpCollection)
	{
		id = std::get<0>(cpCollection);
		employeeID = std::get<1>(cpCollection);
		date = std::get<2>(cpCollection);
		executionDate = std::get<3>(cpCollection);
		stockEmployeeID = std::get<4>(cpCollection);
		count = std::get<5>(cpCollection);
		sum = std::get<6>(cpCollection);
		statusID = std::get<7>(cpCollection);
		currencyID = std::get<8>(cpCollection);
	}

	int ConsumeProduct::GetID()
	{
		return id;
	}

	int ConsumeProduct::GetEmployeeID()
	{
		return employeeID;
	}

	std::string ConsumeProduct::GetDate()
	{
		return date;
	}

	std::string ConsumeProduct::GetExecutionDate()
	{
		return executionDate;
	}

	int ConsumeProduct::GetStockEmployeeID()
	{
		return stockEmployeeID;
	}

	double ConsumeProduct::GetCount()
	{
		return count;
	}

	double ConsumeProduct::GetSum()
	{
		return sum;
	}

	int ConsumeProduct::GetStatusID()
	{
		return statusID;
	}

	int ConsumeProduct::GetCurrencyID()
	{
		return currencyID;
	}

	void ConsumeProduct::SetID(int cID)
	{
		id = cID;
	}
	void ConsumeProduct::SetEmployeeID(int cEmployeeID)
	{
		employeeID = cEmployeeID;
	}
	void ConsumeProduct::SetDate(std::string cDate)
	{
		date = cDate;
	}
	void ConsumeProduct::SetExecutionDate(std::string cExecutionDate)
	{
		executionDate = cExecutionDate;
	}
	void ConsumeProduct::SetStockEmployeeID(int cStockEmployeeID)
	{
		stockEmployeeID = cStockEmployeeID;
	}

	void ConsumeProduct::SetCount(double cCount)
	{
		count = cCount;
	}

	void ConsumeProduct::SetSum(double cSum)
	{
		sum = cSum;
	}

	void ConsumeProduct::SetStatusID(int cStatusID)
	{
		statusID = cStatusID;
	}

	void ConsumeProduct::SetCurrencyID(int cCurrencyID)
	{
		currencyID = cCurrencyID;
	}

	bool ConsumeProduct::CreateConsumeProduct(DataLayer::OrmasDal& ormasDal, int uID, std::string cpDate, std::string cpExecDate, 
		int seID, double cpCount, double cpSum, int sID, int cID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, uID, cpDate, seID ,cpCount, cpSum, cID, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		employeeID = uID;
		date = cpDate;
		executionDate = cpExecDate;
		stockEmployeeID = seID;
		count = cpCount;
		sum = cpSum;
		statusID = sID;
		currencyID = cID;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateConsumeProduct(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, stockEmployeeID, errorMessage))
				{
					if (ChangesAtTransport(ormasDal, id, errorMessage))
					{
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CancelTransaction(errorMessage);
						return true;
					}
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

	bool ConsumeProduct::CreateConsumeProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateConsumeProduct(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, stockEmployeeID, errorMessage))
				{
					if (ChangesAtTransport(ormasDal, id, errorMessage))
					{
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CancelTransaction(errorMessage);
						return true;
					}
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
	bool ConsumeProduct::DeleteConsumeProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!ormasDal.StartTransaction(errorMessage))
			return false;
		ConsumeProduct cProduct;
		if (!cProduct.GetConsumeProductByID(ormasDal, id, errorMessage))
		{
			return false;
		}
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		if (cProduct.GetStatusID() == statusMap.find("EXECUTED")->second)
		{
			errorMessage = "Cannot delete document with \"EXECUTED\" status!";
			return false;
		}
		if (ormasDal.DeleteConsumeProduct(id, errorMessage))
		{
			if (ormasDal.DeleteListByConsumeProductID(id, errorMessage))
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
	bool ConsumeProduct::UpdateConsumeProduct(DataLayer::OrmasDal& ormasDal, int uID, std::string cpDate, std::string cpExecnDate,
		int eID, double cpCount, double cpSum, int sID, int cID, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		std::map<int, double> prodCountMap = GetProductCount(ormasDal, id, errorMessage);
		if (0 == prodCountMap.size())
			return false;
		employeeID = uID;
		date = cpDate;
		executionDate = cpExecnDate;
		stockEmployeeID = eID;
		count = cpCount;
		sum = cpSum;
		statusID = sID;
		currencyID = cID;
		prevSum = GetCurrentSum(ormasDal, id, errorMessage);
		prevCount = GetCurrentCount(ormasDal, id, errorMessage);
		previousStatusID = GetCurrentStatusID(ormasDal, id, errorMessage);
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateConsumeProduct(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, stockEmployeeID, errorMessage))
				{
					if (ChangesAtTransport(ormasDal, id, errorMessage))
					{
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CancelTransaction(errorMessage);
						return true;
					}
				}
				else
				{
					//ormasDal.CommitTransaction(errorMessage);
					return false;
				}
			}
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID == statusMap.find("EXECUTED")->second)
			{
				if (count != prevCount || sum != prevSum)
				{
					if (ChangesAtStock(ormasDal, id, stockEmployeeID, prodCountMap, prevSum, errorMessage))
					{
						if (ChangesAtTransport(ormasDal, id, prodCountMap, prevSum, errorMessage))
						{
							//ormasDal.CommitTransaction(errorMessage);
							return true;
						}
						else
						{
							//ormasDal.CancelTransaction(errorMessage);
							return true;
						}
					}
					else
					{
						//ormasDal.CommitTransaction(errorMessage);
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
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool ConsumeProduct::UpdateConsumeProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		std::map<int, double> prodCountMap = GetProductCount(ormasDal, id, errorMessage);
		if (0 == prodCountMap.size())
			return false;
		prevSum = GetCurrentSum(ormasDal, id, errorMessage);
		prevCount = GetCurrentCount(ormasDal, id, errorMessage);
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateConsumeProduct(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, stockEmployeeID, errorMessage))
				{
					if (ChangesAtTransport(ormasDal, id, errorMessage))
					{
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CancelTransaction(errorMessage);
						return true;
					}
				}
				else
				{
					//ormasDal.CommitTransaction(errorMessage);
					return false;
				}
			}
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID == statusMap.find("EXECUTED")->second)
			{
				if (count != prevCount || sum != prevSum)
				{
					if (ChangesAtStock(ormasDal, id, stockEmployeeID, prodCountMap, prevSum, errorMessage))
					{
						if (ChangesAtTransport(ormasDal, id, prodCountMap, prevSum, errorMessage))
						{
							//ormasDal.CommitTransaction(errorMessage);
							return true;
						}
						else
						{
							//ormasDal.CancelTransaction(errorMessage);
							return true;
						}
					}
					else
					{
						//ormasDal.CommitTransaction(errorMessage);
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
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	std::string ConsumeProduct::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != employeeID || !date.empty() || !executionDate.empty() || 0 != stockEmployeeID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForConsumeProduct(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool ConsumeProduct::GetConsumeProductByID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage)
	{
		id = cID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeProductsViewCollection> consumeProductVector = ormasDal.GetConsumeProducts(errorMessage, filter);
		if (0 != consumeProductVector.size())
		{
			id = std::get<0>(consumeProductVector.at(0));
			date = std::get<1>(consumeProductVector.at(0));
			executionDate = std::get<2>(consumeProductVector.at(0));
			count = std::get<13>(consumeProductVector.at(0));
			sum = std::get<14>(consumeProductVector.at(0));
			stockEmployeeID = std::get<16>(consumeProductVector.at(0));
			employeeID = std::get<17>(consumeProductVector.at(0));
			statusID = std::get<18>(consumeProductVector.at(0));
			currencyID = std::get<19>(consumeProductVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find consume product with this id";
		}
		return false;
	}

	bool ConsumeProduct::IsEmpty()
	{
		if (0 == id && date == "" && executionDate == "" && 0 == count && 0 == sum && 0 == stockEmployeeID && 0 == employeeID && 0 == statusID
			&& 0 == currencyID)
			return false;
		return true;
	}

	void ConsumeProduct::Clear()
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

	bool ConsumeProduct::IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string oDate, int seID, double oCount, double oSum,
		int cID, std::string& errorMessage)
	{
		ConsumeProduct consumeProduct;
		consumeProduct.Clear();
		errorMessage.clear();
		consumeProduct.SetEmployeeID(eID);
		consumeProduct.SetDate(oDate);
		consumeProduct.SetStockEmployeeID(seID);
		consumeProduct.SetCount(oCount);
		consumeProduct.SetSum(oSum);
		consumeProduct.SetCurrencyID(cID);
		std::string filter = consumeProduct.GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeProductsViewCollection> consumeProductVector = ormasDal.GetConsumeProducts(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == consumeProductVector.size())
		{
			return false;
		}
		errorMessage = "Consume product with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool ConsumeProduct::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		ConsumeProduct consumeProduct;
		consumeProduct.Clear();
		errorMessage.clear();
		consumeProduct.SetEmployeeID(employeeID);
		consumeProduct.SetDate(date);
		consumeProduct.SetStockEmployeeID(stockEmployeeID);
		consumeProduct.SetCount(count);
		consumeProduct.SetSum(sum);
		consumeProduct.SetCurrencyID(currencyID);
		std::string filter = consumeProduct.GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeProductsViewCollection> consumeProductVector = ormasDal.GetConsumeProducts(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == consumeProductVector.size())
		{
			return false;
		}
		errorMessage = "Consume product with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool ConsumeProduct::ChangesAtStock(DataLayer::OrmasDal& ormasDal, int cpID, int stockEmpID, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByConsumeProduct(ormasDal, cpID, stockEmpID, errorMessage);
	}

	bool ConsumeProduct::ChangesAtStock(DataLayer::OrmasDal& ormasDal, int cpID, int stockEmpID, std::map<int, double> pProdCountMap, double previousSum, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByConsumeProduct(ormasDal, cpID, stockEmpID, pProdCountMap, previousSum, errorMessage);
	}

	bool ConsumeProduct::ChangesAtTransport(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		Transport transport;
		return transport.ChangingByReceiptProduct(ormasDal, cpID, errorMessage);
	}

	bool ConsumeProduct::ChangesAtTransport(DataLayer::OrmasDal& ormasDal, int cpID, std::map<int, double> pProdCountMap, double previousSum, std::string& errorMessage)
	{
		Transport transport;
		return transport.ChangingByReceiptProduct(ormasDal, cpID, pProdCountMap, previousSum, errorMessage);
	}

	double ConsumeProduct::GetCurrentSum(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		ConsumeProduct cProduct;
		if (cProduct.GetConsumeProductByID(ormasDal, cpID, errorMessage))
			return cProduct.GetSum();
		return 0;
	}

	double ConsumeProduct::GetCurrentCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		ConsumeProduct cProduct;
		if (cProduct.GetConsumeProductByID(ormasDal, cpID, errorMessage))
			return cProduct.GetCount();
		return 0;
	}
	
	int ConsumeProduct::GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage)
	{
		ConsumeProduct cProduct;
		if (cProduct.GetConsumeProductByID(ormasDal, cID, errorMessage))
			return cProduct.GetStatusID();
		return 0;
	}

	std::map<int, double> ConsumeProduct::GetProductCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		std::map<int, double> mapProdCount;
		ConsumeProductList rPList;
		rPList.SetConsumeProductID(cpID);
		std::string filter = rPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeProductListViewCollection> productListVector = ormasDal.GetConsumeProductList(errorMessage, filter);
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