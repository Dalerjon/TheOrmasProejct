#include "stdafx.h"
#include "ConsumeRawClass.h"
#include "ConsumeRawListClass.h"
#include "UserClass.h"
#include "StatusClass.h"
#include "StockClass.h"
#include "ProductionStockClass.h"

namespace BusinessLayer
{
	ConsumeRaw::ConsumeRaw(DataLayer::consumeRawsCollection cCollection)
	{
		id = std::get<0>(cCollection);
		employeeID = std::get<1>(cCollection);
		date = std::get<2>(cCollection);
		executionDate = std::get<3>(cCollection);
		stockEmployeeID = std::get<4>(cCollection);
		count = std::get<5>(cCollection);
		sum = std::get<6>(cCollection);
		statusID = std::get<7>(cCollection);
		currencyID = std::get<8>(cCollection);
	}

	int ConsumeRaw::GetID()
	{
		return id;
	}

	int ConsumeRaw::GetEmployeeID()
	{
		return employeeID;
	}

	std::string ConsumeRaw::GetDate()
	{
		return date;
	}

	std::string ConsumeRaw::GetExecutionDate()
	{
		return executionDate;
	}

	int ConsumeRaw::GetStockEmployeeID()
	{
		return stockEmployeeID;
	}

	double ConsumeRaw::GetCount()
	{
		return count;
	}

	double ConsumeRaw::GetSum()
	{
		return sum;
	}

	int ConsumeRaw::GetStatusID()
	{
		return statusID;
	}

	int ConsumeRaw::GetCurrencyID()
	{
		return currencyID;
	}

	void ConsumeRaw::SetID(int cID)
	{
		id = cID;
	}
	void ConsumeRaw::SetEmployeeID(int cEmployeeID)
	{
		employeeID = cEmployeeID;
	}
	void ConsumeRaw::SetDate(std::string cDate)
	{
		date = cDate;
	}
	void ConsumeRaw::SetExecutionDate(std::string cExecutionDate)
	{
		executionDate = cExecutionDate;
	}
	void ConsumeRaw::SetStockEmployeeID(int cStockEmployeeID)
	{
		stockEmployeeID = cStockEmployeeID;
	}

	void ConsumeRaw::SetCount(double cCount)
	{
		count = cCount;
	}

	void ConsumeRaw::SetSum(double cSum)
	{
		sum = cSum;
	}

	void ConsumeRaw::SetStatusID(int cStatusID)
	{
		statusID = cStatusID;
	}

	void ConsumeRaw::SetCurrencyID(int cCurrencyID)
	{
		currencyID = cCurrencyID;
	}

	bool ConsumeRaw::CreateConsumeRaw(DataLayer::OrmasDal& ormasDal, int uID, std::string cpDate, std::string cpExecDate, 
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
		if (0 != id && ormasDal.CreateConsumeRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
				{
					if (!CheckDocumentCorrectness(ormasDal))
					{
						errorMessage = "Document isn't correct. Check sum and count in list!";
						return false;
					}
					return true;
				}
				else
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
			if (statusID == statusMap.find("RETURN")->second)
			{
				if (ChangesAtStockReverse(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
				{
					if (!CheckDocumentCorrectness(ormasDal))
					{
						errorMessage = "Document isn't correct. Check sum and count in list!";
						return false;
					}
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

	bool ConsumeRaw::CreateConsumeRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateConsumeRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second)
			{
				if (ChangesAtStock(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
				{
					if (!CheckDocumentCorrectness(ormasDal))
					{
						errorMessage = "Document isn't correct. Check sum and count in list!";
						return false;
					}
						return true;
				}
				else
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
			if (statusID == statusMap.find("RETURN")->second)
			{
				if (ChangesAtStockReverse(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
				{
					if (!CheckDocumentCorrectness(ormasDal))
					{
						errorMessage = "Document isn't correct. Check sum and count in list!";
						return false;
					}
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
	bool ConsumeRaw::DeleteConsumeRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		//if (!ormasDal.StartTransaction(errorMessage))
		//	return false;
		ConsumeRaw cRaw;
		if (!cRaw.GetConsumeRawByID(ormasDal, id, errorMessage))
		{
			return false;
		}
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		if (cRaw.GetStatusID() == statusMap.find("EXECUTED")->second)
		{
			errorMessage = "Cannot delete document with \"EXECUTED\" status!";
			return false;
		}
		if (cRaw.GetStatusID() == statusMap.find("ERROR")->second)
		{
			errorMessage = "Cannot delete document with \"ERROR\" status!";
			return false;
		}
		if (cRaw.GetStatusID() == statusMap.find("RETURN")->second)
		{
			errorMessage = "Cannot delete document with \"RETURN\" status!";
			return false;
		}
		if (ormasDal.DeleteConsumeRaw(id, errorMessage))
		{
			if (ormasDal.DeleteListByConsumeRawID(id, errorMessage))
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
	bool ConsumeRaw::UpdateConsumeRaw(DataLayer::OrmasDal& ormasDal, int uID, std::string cpDate, std::string cpExecnDate,
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
		if (0 != id && ormasDal.UpdateConsumeRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID != statusMap.find("ERROR")->second &&
				previousStatusID != statusMap.find("EXECUTED")->second &&
				previousStatusID != statusMap.find("RETURN")->second)
			{
				if (statusID == statusMap.find("EXECUTED")->second)
				{
					if (ChangesAtStock(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
					{
						if (!CheckDocumentCorrectness(ormasDal))
						{
							errorMessage = "Document isn't correct. Check sum and count in list!";
							return false;
						}
						//ormasDal.CommitTransaction(errorMessage);
							return true;
					}
					else
					{
						//ormasDal.CommitTransaction(errorMessage);
						return false;
					}
				}
				if (statusID == statusMap.find("RETURN")->second)
				{
					if (ChangesAtStockReverse(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
					{
						if (!CheckDocumentCorrectness(ormasDal))
						{
							errorMessage = "Document isn't correct. Check sum and count in list!";
							return false;
						}
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
					if (previousStatusID == statusMap.find("EXECUTED")->second)
					{
						if (ChangesAtStockReverse(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
						{
							if (!CheckDocumentCorrectness(ormasDal))
							{
								errorMessage = "Document isn't correct. Check sum and count in list!";
								return false;
							}
							//ormasDal.CommitTransaction(errorMessage);
							return true;
						}
						else
						{
							//ormasDal.CommitTransaction(errorMessage);
							return false;
						}
					}
					if (previousStatusID == statusMap.find("RETURN")->second)
					{
						if (ChangesAtStock(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
						{
							if (!CheckDocumentCorrectness(ormasDal))
							{
								errorMessage = "Document isn't correct. Check sum and count in list!";
								return false;
							}
							//ormasDal.CommitTransaction(errorMessage);
							return true;
						}
						else
						{
							//ormasDal.CommitTransaction(errorMessage);
							return false;
						}
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
			return true;
			*/
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool ConsumeRaw::UpdateConsumeRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
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
		if (0 != id && ormasDal.UpdateConsumeRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID != statusMap.find("ERROR")->second &&
				previousStatusID != statusMap.find("EXECUTED")->second &&
				previousStatusID != statusMap.find("RETURN")->second)
			{
				if (statusID == statusMap.find("EXECUTED")->second)
				{
					if (ChangesAtStock(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
					{
						if (!CheckDocumentCorrectness(ormasDal))
						{
							errorMessage = "Document isn't correct. Check sum and count in list!";
							return false;
						}
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						if (!CheckDocumentCorrectness(ormasDal))
						{
							errorMessage = "Document isn't correct. Check sum and count in list!";
							return false;
						}
						//ormasDal.CommitTransaction(errorMessage);
						return false;
					}
				}
				else if (statusID == statusMap.find("RETURN")->second)
				{
					if (ChangesAtStockReverse(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
					{
						if (!CheckDocumentCorrectness(ormasDal))
						{
							errorMessage = "Document isn't correct. Check sum and count in list!";
							return false;
						}
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
					if (previousStatusID == statusMap.find("EXECUTED")->second)
					{
						if (ChangesAtStockReverse(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
						{
							if (!CheckDocumentCorrectness(ormasDal))
							{
								errorMessage = "Document isn't correct. Check sum and count in list!";
								return false;
							}
							//ormasDal.CommitTransaction(errorMessage);
							return true;
						}
						else
						{
							//ormasDal.CommitTransaction(errorMessage);
							return false;
						}
					}
					if (previousStatusID == statusMap.find("RETURN")->second)
					{
						if (ChangesAtStock(ormasDal, id, employeeID, stockEmployeeID, errorMessage))
						{
							if (!CheckDocumentCorrectness(ormasDal))
							{
								errorMessage = "Document isn't correct. Check sum and count in list!";
								return false;
							}
							//ormasDal.CommitTransaction(errorMessage);
							return true;
						}
						else
						{
							//ormasDal.CommitTransaction(errorMessage);
							return false;
						}
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
			}*/
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

	std::string ConsumeRaw::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != employeeID || !date.empty() || !executionDate.empty() || 0 != stockEmployeeID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForConsumeRaw(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID);
		}
		return "";
	}

	std::string ConsumeRaw::GenerateINFilterForStockEmployee(DataLayer::OrmasDal& ormasDal, std::vector<int> sEmpIDList)
	{
		if (sEmpIDList.size()>0)
		{
			return ormasDal.GetINFilterForStockEmployeeID(sEmpIDList);
		}
		return "";
	}

	std::string ConsumeRaw::GenerateFilterForPeriod(DataLayer::OrmasDal& ormasDal, std::string fromDate, std::string toDate)
	{
		if (!toDate.empty() && !fromDate.empty())
		{
			return ormasDal.GetFilterForConsumeRawForPeriod(id, employeeID, date, executionDate, stockEmployeeID, count, sum, statusID, currencyID, fromDate, toDate);
		}
		return "";
	}

	bool ConsumeRaw::GetConsumeRawByID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage)
	{
		if (cID <= 0)
			return false;
		id = cID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeRawsViewCollection> consumeRawVector = ormasDal.GetConsumeRaws(errorMessage, filter);
		if (0 != consumeRawVector.size())
		{
			id = std::get<0>(consumeRawVector.at(0));
			date = std::get<1>(consumeRawVector.at(0));
			executionDate = std::get<2>(consumeRawVector.at(0));
			count = std::get<13>(consumeRawVector.at(0));
			sum = std::get<14>(consumeRawVector.at(0));
			stockEmployeeID = std::get<16>(consumeRawVector.at(0));
			employeeID = std::get<17>(consumeRawVector.at(0));
			statusID = std::get<18>(consumeRawVector.at(0));
			currencyID = std::get<19>(consumeRawVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find consume product with this id";
		}
		return false;
	}

	bool ConsumeRaw::IsEmpty()
	{
		if (0 == id && date == "" && executionDate == "" && 0 == count && 0 == sum && 0 == stockEmployeeID && 0 == employeeID && 0 == statusID
			&& 0 == currencyID)
			return false;
		return true;
	}

	void ConsumeRaw::Clear()
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

	bool ConsumeRaw::IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string cDate, int seID, double cCount, double cSum,
		int cID, std::string& errorMessage)
	{
		ConsumeRaw consumeRaw;
		consumeRaw.Clear();
		errorMessage.clear();
		consumeRaw.SetEmployeeID(eID);
		consumeRaw.SetDate(cDate);
		consumeRaw.SetStockEmployeeID(seID);
		consumeRaw.SetCount(cCount);
		consumeRaw.SetSum(cSum);
		consumeRaw.SetCurrencyID(cID);
		std::string filter = consumeRaw.GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeRawsViewCollection> consumeRawVector = ormasDal.GetConsumeRaws(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == consumeRawVector.size())
		{
			return false;
		}
		errorMessage = "Consume raw with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool ConsumeRaw::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		ConsumeRaw consumeRaw;
		consumeRaw.Clear();
		errorMessage.clear();
		consumeRaw.SetEmployeeID(employeeID);
		consumeRaw.SetDate(date);
		consumeRaw.SetStockEmployeeID(stockEmployeeID);
		consumeRaw.SetCount(count);
		consumeRaw.SetSum(sum);
		consumeRaw.SetCurrencyID(currencyID);
		std::string filter = consumeRaw.GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeRawsViewCollection> consumeRawVector = ormasDal.GetConsumeRaws(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == consumeRawVector.size())
		{
			return false;
		}
		errorMessage = "Consume raw with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool ConsumeRaw::ChangesAtStock(DataLayer::OrmasDal& ormasDal, int crID, int empID, int stockEmpID, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByConsumeRaw(ormasDal, crID, empID, stockEmpID,  errorMessage);
	}

	bool ConsumeRaw::ChangesAtStockReverse(DataLayer::OrmasDal& ormasDal, int crID, int empID, int stockEmpID, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByConsumeRawReverse(ormasDal, crID, empID, stockEmpID, errorMessage);
	}

	bool ConsumeRaw::ChangesAtStock(DataLayer::OrmasDal& ormasDal, int crID, int empID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByConsumeRaw(ormasDal, crID, empID, stockEmpID, pProdCountMap, pSum, errorMessage);
	}

	double ConsumeRaw::GetCurrentSum(DataLayer::OrmasDal& ormasDal, int crID, std::string& errorMessage)
	{
		ConsumeRaw cRaw;
		if (cRaw.GetConsumeRawByID(ormasDal, crID, errorMessage))
			return cRaw.GetSum();
		return 0;
	}

	double ConsumeRaw::GetCurrentCount(DataLayer::OrmasDal& ormasDal, int crID, std::string& errorMessage)
	{
		ConsumeRaw cRaw;
		if (cRaw.GetConsumeRawByID(ormasDal, crID, errorMessage))
			return cRaw.GetCount();
		return 0;
	}

	int ConsumeRaw::GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage)
	{
		ConsumeRaw cRaw;
		if (cRaw.GetConsumeRawByID(ormasDal, cID, errorMessage))
			return cRaw.GetStatusID();
		return 0;
	}

	std::map<int, double> ConsumeRaw::GetProductCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		std::map<int, double> mapProdCount;
		ConsumeRawList rPList;
		rPList.SetConsumeRawID(cpID);
		std::string filter = rPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeRawListViewCollection> productListVector = ormasDal.GetConsumeRawList(errorMessage, filter);
		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				mapProdCount.insert(std::make_pair(std::get<11>(item), std::get<7>(item)));
			}
		}
		return mapProdCount;
	}

	bool ConsumeRaw::CheckDocumentCorrectness(DataLayer::OrmasDal& ormasDal)
	{
		std::string errorMessage;
		ConsumeRawList rPList;
		double checkCount = 0;
		double checkSum = 0;
		rPList.SetConsumeRawID(id);
		std::string filter = rPList.GenerateFilter(ormasDal);
		std::vector<DataLayer::consumeRawListViewCollection> productListVector = ormasDal.GetConsumeRawList(errorMessage, filter);

		if (productListVector.size() > 0)
		{
			for each (auto item in productListVector)
			{
				checkCount += std::get<7>(item);
				checkSum += std::get<8>(item);
			}
		}

		if (std::round(sum * 10) / 10 != std::round(checkSum * 10) / 10
			|| std::round(count * 10) / 10 != std::round(checkCount * 10) / 10)
			return false;
		return true;
	}
}