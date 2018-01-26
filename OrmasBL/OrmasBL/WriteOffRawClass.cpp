#include "stdafx.h"
#include "WriteOffRawClass.h"
#include "UserClass.h"
#include "StatusClass.h"
#include "StockClass.h"

namespace BusinessLayer
{
	WriteOffRaw::WriteOffRaw(DataLayer::writeOffRawsCollection wCollection)
	{
		id = std::get<0>(wCollection);
		employeeID = std::get<1>(wCollection);
		date = std::get<2>(wCollection);
		stockEmployeeID = std::get<3>(wCollection);
		count = std::get<4>(wCollection);
		sum = std::get<5>(wCollection);
		statusID = std::get<6>(wCollection);
		currencyID = std::get<7>(wCollection);
	}

	int WriteOffRaw::GetID()
	{
		return id;
	}

	int WriteOffRaw::GetEmployeeID()
	{
		return employeeID;
	}

	std::string WriteOffRaw::GetDate()
	{
		return date;
	}

	int WriteOffRaw::GetStockEmployeeID()
	{
		return stockEmployeeID;
	}

	int WriteOffRaw::GetCount()
	{
		return count;
	}

	double WriteOffRaw::GetSum()
	{
		return sum;
	}

	int WriteOffRaw::GetStatusID()
	{
		return statusID;
	}

	int WriteOffRaw::GetCurrencyID()
	{
		return currencyID;
	}

	void WriteOffRaw::SetID(int wID)
	{
		id = wID;
	}
	void WriteOffRaw::SetEmployeeID(int wEmployeeID)
	{
		employeeID = wEmployeeID;
	}
	void WriteOffRaw::SetDate(std::string wDate)
	{
		date = wDate;
	}
	void WriteOffRaw::SetStockEmployeeID(int wStockEmployeeID)
	{
		stockEmployeeID = wStockEmployeeID;
	}

	void WriteOffRaw::SetCount(int wCount)
	{
		count = wCount;
	}

	void WriteOffRaw::SetSum(double wSum)
	{
		sum = wSum;
	}

	void WriteOffRaw::SetStatusID(int wStatusID)
	{
		statusID = wStatusID;
	}

	void WriteOffRaw::SetCurrencyID(int wCurrencyID)
	{
		currencyID = wCurrencyID;
	}

	bool WriteOffRaw::CreateWriteOffRaw(DataLayer::OrmasDal& ormasDal, int uID, std::string wDate,
		int seID, int wCount, double wSum, int sID, int cID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, uID, wDate, seID , wCount, wSum, cID, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		employeeID = uID;
		date = wDate;
		stockEmployeeID = seID;
		count = wCount;
		sum = wSum;
		statusID = sID;
		currencyID = cID;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateWriteOffRaw(id, employeeID, date, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (ChangesAtStock(ormasDal, id, errorMessage))
			{
				ormasDal.CommitTransaction(errorMessage);
				return true;
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	bool WriteOffRaw::CreateWriteOffRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateWriteOffRaw(id, employeeID, date, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (ChangesAtStock(ormasDal, id, errorMessage))
			{
				ormasDal.CommitTransaction(errorMessage);
				return true;
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool WriteOffRaw::DeleteWriteOffRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!ormasDal.StartTransaction(errorMessage))
			return false;
		if (ormasDal.DeleteWriteOffRaw(id, errorMessage))
		{
			if (ormasDal.DeleteListByWriteOffRawID(id, errorMessage))
			{
				id = 0;
				employeeID = 0;
				date.clear();
				stockEmployeeID = 0;
				count = 0;
				sum = 0;
				statusID = 0;
				ormasDal.CommitTransaction(errorMessage);
				return true;
			}
			else
			{
				ormasDal.CancelTransaction(errorMessage);
			}
		}
		else
		{
			ormasDal.CancelTransaction(errorMessage);
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool WriteOffRaw::UpdateWriteOffRaw(DataLayer::OrmasDal& ormasDal, int uID, std::string wDate, 
		int eID, int wCount, double wSum, int sID, int cID, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		employeeID = uID;
		date = wDate;
		stockEmployeeID = eID;
		count = wCount;
		sum = wSum;
		statusID = sID;
		currencyID = cID;
		prevSum = GetCurrentSum(ormasDal, id, errorMessage);
		prevCount = GetCurrentCount(ormasDal, id, errorMessage);
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateWriteOffRaw(id, employeeID, date, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (ChangesAtStock(ormasDal, id, prevSum, prevCount, errorMessage))
			{
				ormasDal.CommitTransaction(errorMessage);
				return true;
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool WriteOffRaw::UpdateWriteOffRaw(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		prevSum = GetCurrentSum(ormasDal, id, errorMessage);
		prevCount = GetCurrentCount(ormasDal, id, errorMessage);
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateWriteOffRaw(id, employeeID, date, stockEmployeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (ChangesAtStock(ormasDal, id, prevSum, prevCount, errorMessage))
			{
				ormasDal.CommitTransaction(errorMessage);
				return true;
			}
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	std::string WriteOffRaw::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != employeeID || !date.empty() || 0 != stockEmployeeID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForWriteOffRaw(id, employeeID, date, stockEmployeeID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool WriteOffRaw::GetWriteOffRawByID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage)
	{
		id = cID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::writeOffRawsViewCollection> writeOffRawVector = ormasDal.GetWriteOffRaws(errorMessage, filter);
		if (0 != writeOffRawVector.size())
		{
			id = std::get<0>(writeOffRawVector.at(0));
			date = std::get<1>(writeOffRawVector.at(0));
			count = std::get<12>(writeOffRawVector.at(0));
			sum = std::get<13>(writeOffRawVector.at(0));
			stockEmployeeID = std::get<15>(writeOffRawVector.at(0));
			employeeID = std::get<16>(writeOffRawVector.at(0));
			statusID = std::get<17>(writeOffRawVector.at(0));
			currencyID = std::get<18>(writeOffRawVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find write-off raw with this id";
		}
		return false;
	}

	bool WriteOffRaw::IsEmpty()
	{
		if (0 == id && date == "" && 0 == count && 0 == sum && 0 == stockEmployeeID && 0 == employeeID && 0 == statusID
			&& 0 == currencyID)
			return false;
		return true;
	}

	void WriteOffRaw::Clear()
	{
		id = 0;
		date.clear();
		count = 0;
		sum = 0;
		stockEmployeeID = 0;
		employeeID = 0;
		statusID = 0;
		currencyID = 0;
	}

	bool WriteOffRaw::IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string wDate, int seID, int wCount, double wSum,
		int cID, std::string& errorMessage)
	{
		WriteOffRaw writeOffRaw;
		writeOffRaw.SetEmployeeID(eID);
		writeOffRaw.SetDate(wDate);
		writeOffRaw.SetStockEmployeeID(seID);
		writeOffRaw.SetCount(wCount);
		writeOffRaw.SetSum(wSum);
		writeOffRaw.SetCurrencyID(cID);
		std::string filter = writeOffRaw.GenerateFilter(ormasDal);
		std::vector<DataLayer::writeOffRawsViewCollection> writeOffRawVector = ormasDal.GetWriteOffRaws(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == writeOffRawVector.size())
		{
			return false;
		}
		errorMessage = "Write-off raw with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool WriteOffRaw::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		WriteOffRaw writeOffRaw;
		writeOffRaw.SetEmployeeID(employeeID);
		writeOffRaw.SetDate(date);
		writeOffRaw.SetStockEmployeeID(stockEmployeeID);
		writeOffRaw.SetCount(count);
		writeOffRaw.SetSum(sum);
		writeOffRaw.SetCurrencyID(currencyID);
		std::string filter = writeOffRaw.GenerateFilter(ormasDal);
		std::vector<DataLayer::writeOffRawsViewCollection> writeOffRawVector = ormasDal.GetWriteOffRaws(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == writeOffRawVector.size())
		{
			return false;
		}
		errorMessage = "Write-off raw with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool WriteOffRaw::ChangesAtStock(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByWriteOffRaw(ormasDal, cpID, errorMessage);
	}

	bool WriteOffRaw::ChangesAtStock(DataLayer::OrmasDal& ormasDal, int cpID, double pSum, int pCount, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByWriteOffRaw(ormasDal, cpID, pSum, pCount, errorMessage);
	}

	double WriteOffRaw::GetCurrentSum(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		WriteOffRaw wProduct;
		if (wProduct.GetWriteOffRawByID(ormasDal, cpID, errorMessage))
			return wProduct.GetSum();
		return 0;
	}

	int WriteOffRaw::GetCurrentCount(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage)
	{
		WriteOffRaw wProduct;
		if (wProduct.GetWriteOffRawByID(ormasDal, cpID, errorMessage))
			return wProduct.GetCount();
		return 0;
	}
}