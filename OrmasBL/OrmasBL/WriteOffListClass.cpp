#include "stdafx.h"
#include "WriteOffListClass.h"

namespace BusinessLayer
{
	WriteOffList::WriteOffList(DataLayer::writeOffListCollection wListCollection)
	{
		id = std::get<0>(wListCollection);
		writeOffID = std::get<1>(wListCollection);
		productID = std::get<2>(wListCollection);
		count = std::get<3>(wListCollection);
		sum = std::get<4>(wListCollection);
		statusID = std::get<5>(wListCollection);
		currencyID = std::get<6>(wListCollection);
	}

	int WriteOffList::GetID()
	{
		return id;
	}

	int WriteOffList::GetWriteOffID()
	{
		return writeOffID;
	}

	int WriteOffList::GetProductID()
	{
		return productID;
	}

	int WriteOffList::GetCount()
	{
		return count;
	}

	double WriteOffList::GetSum()
	{
		return sum;
	}

	int WriteOffList::GetStatusID()
	{
		return statusID;
	}

	int WriteOffList::GetCurrencyID()
	{
		return currencyID;
	}

	void WriteOffList::SetID(int pID)
	{
		id = pID;
	}
	void WriteOffList::SetWriteOffID(int wWriteOffID)
	{
		writeOffID = wWriteOffID;
	}
	void WriteOffList::SetProductID(int pProductID)
	{
		productID = pProductID;
	}
	void WriteOffList::SetCount(int wCount)
	{
		count = wCount;
	}
	void WriteOffList::SetSum(double wSum)
	{
		sum = wSum;
	}
	void WriteOffList::SetStatusID(int pStatusID)
	{
		statusID = pStatusID;
	}
	void WriteOffList::SetCurrencyID(int pCurrencyID)
	{
		currencyID = pCurrencyID;
	}

	bool WriteOffList::CreateWriteOffList(DataLayer::OrmasDal& ormasDal, int wID, int pID, int wCount, double wSum,
		int sID, int cID, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		writeOffID = wID;
		productID = pID;
		count = wCount;
		sum = wSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.CreateWriteOffList(id, writeOffID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool WriteOffList::CreateWriteOffList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateWriteOffList(id, writeOffID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool WriteOffList::DeleteWriteOffList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		writeOffID = 0;
		productID = 0;
		count = 0;
		sum = 0;
		statusID = 0;
		currencyID = 0;
		if (ormasDal.DeleteItemInWriteOffList(id, errorMessage))
		{
			id = 0;
			return true;
		}
		return false;
	}
	bool WriteOffList::DeleteListByWriteOffID(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage)
	{
		writeOffID = wID;
		if (ormasDal.DeleteListByOrderID(writeOffID, errorMessage))
		{
			id = 0;
			writeOffID = 0;
			productID = 0;
			count = 0;
			sum = 0;
			statusID = 0;
			currencyID = 0;
			return true;
		}
		return false;
	}

	bool WriteOffList::UpdateWriteOffList(DataLayer::OrmasDal& ormasDal, int wID, int pID, int wCount, double wSum,
		int sID, int cID, std::string& errorMessage)
	{
		writeOffID = wID;
		productID = pID;
		count = wCount;
		sum = wSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.UpdateWriteOffList(id, writeOffID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool WriteOffList::UpdateWriteOffList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateWriteOffList(id, writeOffID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}

	std::string WriteOffList::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != writeOffID || 0 != productID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForWriteOffList(id, writeOffID, productID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool WriteOffList::GetWriteOffListByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		id = pID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::writeOffListViewCollection> writeOffListVector = ormasDal.GetWriteOffList(errorMessage, filter);
		if (0 != writeOffListVector.size())
		{
			id = std::get<0>(writeOffListVector.at(0));
			writeOffID = std::get<1>(writeOffListVector.at(0));
			count = std::get<7>(writeOffListVector.at(0));
			sum = std::get<8>(writeOffListVector.at(0));
			productID = std::get<11>(writeOffListVector.at(0));
			statusID = std::get<12>(writeOffListVector.at(0));
			currencyID = std::get<13>(writeOffListVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find write-off list with this id";
		}
		return false;
	}
	
	bool WriteOffList::IsEmpty()
	{
		if (0 == id && 0 == writeOffID && 0 == count && 0 == sum && 0 == productID && 0 == statusID && 0 == currencyID)
			return true;
		return false;
	}

	void WriteOffList::Clear()
	{
		id = 0;
		writeOffID = 0;
		count = 0;
		sum = 0;
		productID = 0;
		statusID = 0;
		currencyID = 0;
	}

	bool WriteOffList::IsDuplicate(DataLayer::OrmasDal& ormasDal, int wID, int pID, int wlCount, double wlSum,
		int cID, std::string& errorMessage)
	{
		WriteOffList writeOffList;
		writeOffList.SetWriteOffID(wID);
		writeOffList.SetProductID(pID);
		writeOffList.SetCount(wlCount);
		writeOffList.SetSum(wlSum);
		writeOffList.SetCurrencyID(cID);
		std::string filter = writeOffList.GenerateFilter(ormasDal);
		std::vector<DataLayer::writeOffListViewCollection> writeOffListVector = ormasDal.GetWriteOffList(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == writeOffListVector.size())
		{
			return false;
		}
		errorMessage = "Write-off list with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool WriteOffList::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		WriteOffList writeOffList;
		writeOffList.SetWriteOffID(writeOffID);
		writeOffList.SetProductID(productID);
		writeOffList.SetCount(count);
		writeOffList.SetSum(sum);
		writeOffList.SetCurrencyID(currencyID);
		std::string filter = writeOffList.GenerateFilter(ormasDal);
		std::vector<DataLayer::writeOffListViewCollection> writeOffListVector = ormasDal.GetWriteOffList(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == writeOffListVector.size())
		{
			return false;
		}
		errorMessage = "Write-off list with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}