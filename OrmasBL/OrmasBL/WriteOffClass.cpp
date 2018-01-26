#include "stdafx.h"
#include "WriteOffClass.h"
#include "StockClass.h"

namespace BusinessLayer
{
	WriteOff::WriteOff(DataLayer::writeOffsCollection wCollection)
	{
		id = std::get<0>(wCollection);
		clientID = std::get<1>(wCollection);
		date = std::get<2>(wCollection);
		employeeID = std::get<3>(wCollection);
		count = std::get<4>(wCollection);
		sum = std::get<5>(wCollection);
		statusID = std::get<6>(wCollection);
		currencyID = std::get<7>(wCollection);
	}

	int WriteOff::GetID()
	{
		return id;
	}

	int WriteOff::GetClientID()
	{
		return clientID;
	}

	std::string WriteOff::GetDate()
	{
		return date;
	}

	int WriteOff::GetEmployeeID()
	{
		return employeeID;
	}

	int WriteOff::GetCount()
	{
		return count;
	}

	double WriteOff::GetSum()
	{
		return sum;
	}

	int WriteOff::GetStatusID()
	{
		return statusID;
	}

	int WriteOff::GetCurrencyID()
	{
		return currencyID;
	}

	void WriteOff::SetID(int wID)
	{
		id = wID;
	}
	void WriteOff::SetClientID(int wClientID)
	{
		clientID = wClientID;
	}
	void WriteOff::SetDate(std::string wDate)
	{
		date = wDate;
	}
	void WriteOff::SetEmployeeID(int wEmployeeID)
	{
		employeeID = wEmployeeID;
	}

	void WriteOff::SetCount(int wCount)
	{
		count = wCount;
	}

	void WriteOff::SetSum(double wSum)
	{
		sum = wSum;
	}

	void WriteOff::SetStatusID(int wStatusID)
	{
		statusID = wStatusID;
	}

	void WriteOff::SetCurrencyID(int wCurrencyID)
	{
		currencyID = wCurrencyID;
	}

	bool WriteOff::CreateWriteOff(DataLayer::OrmasDal& ormasDal, int clID, std::string wDate, int eID, int wCount, double wSum,
		int sID, int cID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, clID, wDate, wCount, wSum, cID, errorMessage))
			return false;
		clientID = clID;
		date = wDate;
		employeeID = eID;
		count = wCount;
		sum = wSum;
		statusID = sID;
		currencyID = cID;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateWriteOff(id, clientID, date, employeeID, count, sum, statusID, currencyID, errorMessage))
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

	bool WriteOff::CreateWriteOff(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateWriteOff(id, clientID, date, employeeID, count, sum, statusID, currencyID, errorMessage))
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
	bool WriteOff::DeleteWriteOff(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!ormasDal.StartTransaction(errorMessage))
			return false;
		if (ormasDal.DeleteWriteOff(id, errorMessage))
		{
			if (ormasDal.DeleteListByWriteOffID(id, errorMessage))
			{
				id = 0;
				clientID = 0;
				date.clear();
				employeeID = 0;
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
	bool WriteOff::UpdateWriteOff(DataLayer::OrmasDal& ormasDal, int clID, std::string wDate, int eID, int wCount, double wSum,
		int sID, int cID, std::string& errorMessage)
	{
		clientID = clID;
		date = wDate;
		employeeID = eID;
		count = wCount;
		sum = wSum;
		statusID = sID;
		currencyID = cID;
		prevSum = GetCurrentSum(ormasDal, id, errorMessage);
		prevCount = GetCurrentCount(ormasDal, id, errorMessage);
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateWriteOff(id, clientID, date, employeeID, count, sum, statusID, currencyID, errorMessage))
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
	bool WriteOff::UpdateWriteOff(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		prevSum = GetCurrentSum(ormasDal, id, errorMessage);
		prevCount = GetCurrentCount(ormasDal, id, errorMessage);
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateWriteOff(id, clientID, date, employeeID, count, sum, statusID, currencyID, errorMessage))
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

	std::string WriteOff::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != clientID || !date.empty() || 0 != employeeID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForWriteOff(id, clientID, date, employeeID, count, sum, statusID, currencyID);
		}
		return "";
	}
	bool WriteOff::GetWriteOffByID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		id = oID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::writeOffsViewCollection> writeOffVector = ormasDal.GetWriteOffs(errorMessage, filter);
		if (0 != writeOffVector.size())
		{
			id = std::get<0>(writeOffVector.at(0));
			date = std::get<1>(writeOffVector.at(0));
			count = std::get<12>(writeOffVector.at(0));
			sum = std::get<13>(writeOffVector.at(0));
			employeeID = std::get<15>(writeOffVector.at(0));
			clientID = std::get<16>(writeOffVector.at(0));
			statusID = std::get<17>(writeOffVector.at(0));
			currencyID = std::get<18>(writeOffVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find write-off with this id";
		}
		return false;
	}
	
	bool WriteOff::IsEmpty()
	{
		if (0 == id && date == "" && 0 == count && 0 == sum && 0 == employeeID && 0 == clientID && 0 == statusID && 0 == currencyID)
			return false;
		return true;
	}

	void WriteOff::Clear()
	{
		id = 0;
		date.clear();
		count = 0;
		sum = 0;
		employeeID = 0;
		clientID = 0;
		statusID = 0;
		currencyID = 0;
	}

	bool WriteOff::IsDuplicate(DataLayer::OrmasDal& ormasDal, int clID, std::string wDate, int wCount, double wSum,
		int cID, std::string& errorMessage)
	{
		WriteOff writeOff;
		writeOff.SetClientID(clID);
		writeOff.SetDate(wDate);
		writeOff.SetCount(wCount);
		writeOff.SetSum(wSum);
		writeOff.SetCurrencyID(cID);
		std::string filter = writeOff.GenerateFilter(ormasDal);
		std::vector<DataLayer::writeOffsViewCollection> writeOffVector = ormasDal.GetWriteOffs(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == writeOffVector.size())
		{
			return false;
		}
		errorMessage = "Write-off with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool WriteOff::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		WriteOff writeOff;
		writeOff.SetClientID(clientID);
		writeOff.SetDate(date);
		writeOff.SetCount(count);
		writeOff.SetSum(sum);
		writeOff.SetCurrencyID(currencyID);
		std::string filter = writeOff.GenerateFilter(ormasDal);
		std::vector<DataLayer::writeOffsViewCollection> writeOffVector = ormasDal.GetWriteOffs(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == writeOffVector.size())
		{
			return false;
		}
		errorMessage = "Write-off with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool WriteOff::ChangesAtStock(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByWriteOff(ormasDal, wID, errorMessage);
	}

	bool WriteOff::ChangesAtStock(DataLayer::OrmasDal& ormasDal, int wID, double pSum, int pCount, std::string& errorMessage)
	{
		Stock stock;
		return stock.ChangingByWriteOff(ormasDal, wID, pSum, pCount, errorMessage);
	}

	double WriteOff::GetCurrentSum(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage)
	{
		WriteOff wProduct;
		if (wProduct.GetWriteOffByID(ormasDal, wID, errorMessage))
			return wProduct.GetSum();
		return 0;
	}

	int WriteOff::GetCurrentCount(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage)
	{
		WriteOff wProduct;
		if (wProduct.GetWriteOffByID(ormasDal, wID, errorMessage))
			return wProduct.GetCount();
		return 0;
	}
}