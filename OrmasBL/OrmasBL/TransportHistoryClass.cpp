#include "stdafx.h"
#include "TransportHistoryClass.h"
#include <codecvt>

namespace BusinessLayer
{
	TransportHistory::TransportHistory(DataLayer::transportHistoryCollection sCollection)
	{
		id = std::get<0>(sCollection);
		transportID = std::get<1>(sCollection);
		productID = std::get<2>(sCollection);
		count = std::get<3>(sCollection);
		sum = std::get<4>(sCollection);
		statusID = std::get<5>(sCollection);
		currencyID = std::get<6>(sCollection);
		historyDate = std::get<7>(sCollection);
	}

	int TransportHistory::GetID()
	{
		return id;
	}

	int TransportHistory::GetProductID()
	{
		return productID;
	}

	double TransportHistory::GetCount()
	{
		return count;
	}

	double TransportHistory::GetSum()
	{
		return sum;
	}

	int TransportHistory::GetStatusID()
	{
		return statusID;
	}

	int TransportHistory::GetCurrencyID()
	{
		return currencyID;
	}

	int TransportHistory::GetTransportID()
	{
		return transportID;
	}

	std::string TransportHistory::GetHistoryDate()
	{
		return historyDate;
	}

	void TransportHistory::SetID(int sID)
	{
		id = sID;
	}

	void TransportHistory::SetProductID(int sProductID)
	{
		productID = sProductID;
	}
	void TransportHistory::SetCount(double sCount)
	{
		count = sCount;
	}
	void TransportHistory::SetSum(double sSum)
	{
		sum = sSum;
	}
	void TransportHistory::SetStatusID(int sStatusID)
	{
		statusID = sStatusID;
	}
	void TransportHistory::SetCurrencyID(int sCurrencyID)
	{
		currencyID = sCurrencyID;
	}
	void TransportHistory::SetTransportID(int stransportID)
	{
		transportID = stransportID;
	}

	void TransportHistory::SetHistoryDate(std::string date)
	{
		historyDate = date;
	}

	bool TransportHistory::CreateTransportHistory(DataLayer::OrmasDal& ormasDal, int pID, double sCount, double sSum,
		int sID, int cID, int wID, std::string sHistoryDate, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		productID = pID;
		count = sCount;
		sum = sSum;
		statusID = sID;
		currencyID = cID;
		transportID = wID;
		historyDate = sHistoryDate;
		if (0 != id && ormasDal.CreateTransportHistory(id, transportID, productID, count, sum, statusID, currencyID, historyDate, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool TransportHistory::CreateTransportHistory(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateTransportHistory(id, transportID, productID, count, sum, statusID, currencyID, historyDate, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool TransportHistory::DeleteTransportHistory(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteTransportHistory(id, errorMessage))
		{
			Clear();
			return true;
		}
		return false;
	}

	bool TransportHistory::UpdateTransportHistory(DataLayer::OrmasDal& ormasDal, int pID, double sCount, double sSum,
		int sID, int cID, int wID, std::string sHistoryDate, std::string& errorMessage)
	{
		productID = pID;
		count = sCount;
		sum = sSum;
		statusID = sID;
		currencyID = cID;
		transportID = wID;
		historyDate = sHistoryDate;
		if (count < 0 || sum < 0)
		{
			errorMessage = "Count or sum cannot be less then 0!";
			return false;
		}
		if (0 != id && ormasDal.UpdateTransportHistory(id, transportID, productID, count, sum, statusID, currencyID,  historyDate, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool TransportHistory::UpdateTransportHistory(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (count < 0 || sum < 0)
		{
			errorMessage = "Count or sum cannot be less then 0!";
			return false;
		}
		if (0 != id && ormasDal.UpdateTransportHistory(id, transportID, productID, count, sum, statusID, currencyID,  historyDate, errorMessage))
		{
			return true;
		}
		return false;
	}

	std::string TransportHistory::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != productID || 0 != count || 0 != sum || 0 != statusID || 0 != transportID || !historyDate.empty())
		{
			return ormasDal.GetFilterForTransportHistory(id, transportID, productID, count, sum, statusID, currencyID, historyDate);
		}
		return "";
	}

	bool TransportHistory::GetTransportHistoryByID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage)
	{
		if (sID <= 0)
			return false;
		id = sID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::transportHistoryCollection> transportHistoryVector = ormasDal.GetTransportHistory(errorMessage, filter);
		if (0 != transportHistoryVector.size())
		{
			id = std::get<0>(transportHistoryVector.at(0));
			transportID = std::get<1>(transportHistoryVector.at(0));
			productID = std::get<2>(transportHistoryVector.at(0));
			count = std::get<3>(transportHistoryVector.at(0));
			sum = std::get<4>(transportHistoryVector.at(0));
			statusID = std::get<5>(transportHistoryVector.at(0));
			currencyID = std::get<6>(transportHistoryVector.at(0));
			historyDate = std::get<7>(transportHistoryVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find TransportHistory with this id";
		}
		return false;
	}

	bool TransportHistory::GetTransportHistoryByProductID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		if (pID <= 0)
			return false;
		productID = pID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::transportHistoryCollection> transportHistoryVector = ormasDal.GetTransportHistory(errorMessage, filter);
		if (0 != transportHistoryVector.size())
		{
			id = std::get<0>(transportHistoryVector.at(0));
			transportID = std::get<1>(transportHistoryVector.at(0));
			productID = std::get<2>(transportHistoryVector.at(0));
			count = std::get<3>(transportHistoryVector.at(0));
			sum = std::get<4>(transportHistoryVector.at(0));
			statusID = std::get<5>(transportHistoryVector.at(0));
			currencyID = std::get<6>(transportHistoryVector.at(0));
			historyDate = std::get<7>(transportHistoryVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find TransportHistory with this id";
		}
		return false;
	}

	bool TransportHistory::GetTransportHistoryByProductAndtransportID(DataLayer::OrmasDal& ormasDal, int pID, int wID, std::string& errorMessage)
	{
		if (pID <= 0)
			return false;
		if (wID <= 0)
			return false;
		productID = pID;
		transportID = wID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::transportHistoryCollection> transportHistoryVector = ormasDal.GetTransportHistory(errorMessage, filter);
		if (0 != transportHistoryVector.size())
		{
			id = std::get<0>(transportHistoryVector.at(0));
			transportID = std::get<1>(transportHistoryVector.at(0));
			productID = std::get<2>(transportHistoryVector.at(0));
			count = std::get<3>(transportHistoryVector.at(0));
			sum = std::get<4>(transportHistoryVector.at(0));
			statusID = std::get<5>(transportHistoryVector.at(0));
			currencyID = std::get<6>(transportHistoryVector.at(0));
			historyDate = std::get<7>(transportHistoryVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find TransportHistory with this product ID and transport ID";
		}
		return false;
	}

	bool TransportHistory::IsEmpty()
	{
		if (0 == id && 0 == count && 0 == sum && 0 == productID && 0 == statusID && 0 == currencyID && 0 == transportID && historyDate.empty())
			return true;
		return false;
	}

	void TransportHistory::Clear()
	{
		id = 0;
		count = 0;
		sum = 0;
		productID = 0;
		statusID = 0;
		currencyID = 0;
		transportID = 0;
		historyDate.empty();
	}

	bool TransportHistory::IsDuplicate(DataLayer::OrmasDal& ormasDal, int pID, int wID, std::string& errorMessage)
	{
		TransportHistory transportHistory;
		transportHistory.Clear();
		errorMessage.clear();
		transportHistory.SetProductID(pID);
		transportHistory.SetTransportID(wID);
		std::string filter = transportHistory.GenerateFilter(ormasDal);
		std::vector<DataLayer::transportHistoryCollection> transportHistoryVector = ormasDal.GetTransportHistory(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == transportHistoryVector.size())
		{
			return false;
		}
		errorMessage = "Transport history with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool TransportHistory::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		TransportHistory transportHistory;
		transportHistory.Clear();
		errorMessage.clear();
		transportHistory.SetProductID(productID);
		transportHistory.SetTransportID(transportID);
		std::string filter = transportHistory.GenerateFilter(ormasDal);
		std::vector<DataLayer::transportHistoryCollection> transportHistoryVector = ormasDal.GetTransportHistory(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == transportHistoryVector.size())
		{
			return false;
		}
		errorMessage = "TransportHistory with this parameters are already exist! Please avoid the duplication!";
		return true;
	}


}