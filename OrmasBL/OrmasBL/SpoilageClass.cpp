#include "stdafx.h"
#include "SpoilageClass.h"
#include "UserClass.h"
#include "StatusClass.h"

namespace BusinessLayer
{
	Spoilage::Spoilage(DataLayer::spoilageCollection sCollection)
	{
		id = std::get<0>(sCollection);
		date = std::get<1>(sCollection);
		employeeID = std::get<2>(sCollection);
		count = std::get<3>(sCollection);
		sum = std::get<4>(sCollection);
		statusID = std::get<5>(sCollection);
		currencyID = std::get<6>(sCollection);
	}

	int Spoilage::GetID()
	{
		return id;
	}

	std::string Spoilage::GetDate()
	{
		return date;
	}

	int Spoilage::GetEmployeeID()
	{
		return employeeID;
	}

	int Spoilage::GetCount()
	{
		return count;
	}

	double Spoilage::GetSum()
	{
		return sum;
	}

	int Spoilage::GetStatusID()
	{
		return statusID;
	}

	int Spoilage::GetCurrencyID()
	{
		return currencyID;
	}

	void Spoilage::SetID(int sID)
	{
		id = sID;
	}
	void Spoilage::SetDate(std::string sDate)
	{
		date = sDate;
	}
	void Spoilage::SetEmployeeID(int sEmployeeID)
	{
		employeeID = sEmployeeID;
	}

	void Spoilage::SetCount(int sCount)
	{
		count = sCount;
	}

	void Spoilage::SetSum(double sSum)
	{
		sum = sSum;
	}

	void Spoilage::SetStatusID(int sStatusID)
	{
		statusID = sStatusID;
	}

	void Spoilage::SetCurrencyID(int sCurrencyID)
	{
		currencyID = sCurrencyID;
	}

	bool Spoilage::CreateSpoilage(DataLayer::OrmasDal& ormasDal, std::string sDate, int eID, int sCount,
		double sSum, int stsID, int cID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, sDate, sCount, sSum, cID, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		date = sDate;
		employeeID = eID;
		count = sCount;
		sum = sSum;
		statusID = stsID;
		currencyID = cID;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateSpoilage(id, date, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			ormasDal.CommitTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.StartTransaction(errorMessage);
		return false;
	}

	bool Spoilage::CreateSpoilage(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateSpoilage(id, date, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			ormasDal.CommitTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.StartTransaction(errorMessage);
		return false;
	}
	bool Spoilage::DeleteSpoilage(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!ormasDal.StartTransaction(errorMessage))
			return false;
		if (ormasDal.DeleteSpoilage(id, errorMessage))
		{
			if (ormasDal.DeleteListBySpoilageID(id, errorMessage))
			{
				Clear();
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
	bool Spoilage::UpdateSpoilage(DataLayer::OrmasDal& ormasDal, std::string sDate, int eID, int sCount,
		double sSum, int stsID, int cID, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		date = sDate;
		employeeID = eID;
		count = sCount;
		sum = sSum;
		statusID = stsID;
		currencyID = cID;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateSpoilage(id, date, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			ormasDal.CommitTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Spoilage::UpdateSpoilage(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateSpoilage(id, date, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			ormasDal.CommitTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	std::string Spoilage::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !date.empty() || 0 != employeeID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForSpoilage(id, date, employeeID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool Spoilage::GetSpoilageByID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		id = oID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::spoilageViewCollection> spoilageVector = ormasDal.GetSpoilage(errorMessage, filter);
		if (0 != spoilageVector.size())
		{
			id = std::get<0>(spoilageVector.at(0));
			date = std::get<1>(spoilageVector.at(0));
			count = std::get<2>(spoilageVector.at(0));
			sum = std::get<3>(spoilageVector.at(0));
			employeeID = std::get<10>(spoilageVector.at(0));
			statusID = std::get<11>(spoilageVector.at(0));
			currencyID = std::get<12>(spoilageVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find spoilage with this id";
		}
		return false;
	}

	bool Spoilage::IsEmpty()
	{
		if (0 == id && date == "" && 0 == count && 0 == sum && 0 == employeeID && 0 == statusID && 0 == currencyID)
			return false;
		return true;
	}

	void Spoilage::Clear()
	{
		id = 0;
		date.clear();
		count = 0;
		sum = 0;
		employeeID = 0;
		statusID = 0;
		currencyID = 0;
	}

	bool Spoilage::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string sDate, int sCount, double sSum,
		int cID, std::string& errorMessage)
	{
		Spoilage spoilage;
		spoilage.SetDate(sDate);
		spoilage.SetCount(sCount);
		spoilage.SetSum(sSum);
		spoilage.SetCurrencyID(cID);
		std::string filter = spoilage.GenerateFilter(ormasDal);
		std::vector<DataLayer::spoilageViewCollection> spoilageVector = ormasDal.GetSpoilage(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == spoilageVector.size())
		{
			return false;
		}
		errorMessage = "Spoilage with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Spoilage::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Spoilage spoilage;
		spoilage.SetDate(date);
		spoilage.SetCount(count);
		spoilage.SetSum(sum);
		spoilage.SetCurrencyID(currencyID);
		std::string filter = spoilage.GenerateFilter(ormasDal);
		std::vector<DataLayer::spoilageViewCollection> spoilageVector = ormasDal.GetSpoilage(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == spoilageVector.size())
		{
			return false;
		}
		errorMessage = "Spoilage with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

}