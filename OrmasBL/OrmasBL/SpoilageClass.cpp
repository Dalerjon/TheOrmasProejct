#include "stdafx.h"
#include "SpoilageClass.h"
#include "StatusClass.h"
#include "UserClass.h"
#include "EntryClass.h"
#include "StatusClass.h"
#include "CompanyAccountRelationClass.h"
#include "CompanyEmployeeRelationClass.h"
#include <codecvt>

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

	double Spoilage::GetCount()
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

	void Spoilage::SetCount(double sCount)
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

	bool Spoilage::CreateSpoilage(DataLayer::OrmasDal& ormasDal, std::string sDate, int eID, double sCount,
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
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateSpoilage(id, date, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (CreateSpoilageEntry(ormasDal, employeeID, sum, currencyID, errorMessage))
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
		//ormasDal.StartTransaction(errorMessage);
		return false;
	}

	bool Spoilage::CreateSpoilage(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateSpoilage(id, date, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (CreateSpoilageEntry(ormasDal, employeeID, sum, currencyID, errorMessage))
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
		//ormasDal.StartTransaction(errorMessage);
		return false;
	}
	bool Spoilage::DeleteSpoilage(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		//if (!ormasDal.StartTransaction(errorMessage))
		//	return false;
		Spoilage spl;
		if (!spl.GetSpoilageByID(ormasDal, id, errorMessage))
		{
			return false;
		}
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		if (spl.GetStatusID() == statusMap.find("EXECUTED")->second)
		{
			errorMessage = "Cannot delete document with \"EXECUTED\" status!";
			return false;
		}
		if (ormasDal.DeleteSpoilage(id, errorMessage))
		{
			if (ormasDal.DeleteListBySpoilageID(id, errorMessage))
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
	bool Spoilage::UpdateSpoilage(DataLayer::OrmasDal& ormasDal, std::string sDate, int eID, double sCount,
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
		//ormasDal.StartTransaction(errorMessage);
		previousSum = GetCurrentSum(ormasDal, id, errorMessage);
		prevCount = GetCurrentCount(ormasDal, id, errorMessage);
		previousStatusID = GetCurrentStatusID(ormasDal, id, errorMessage);
		if (0 != id && ormasDal.UpdateSpoilage(id, date, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (CreateSpoilageEntry(ormasDal, employeeID, sum, previousSum, currencyID, errorMessage))
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
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID == statusMap.find("EXECUTED")->second)
			{
				if (count != prevCount || sum != previousSum)
				{
					if (CreateSpoilageEntry(ormasDal, employeeID, sum, previousSum, currencyID, errorMessage))
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
	bool Spoilage::UpdateSpoilage(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		//ormasDal.StartTransaction(errorMessage);
		previousSum = GetCurrentSum(ormasDal, id, errorMessage);
		prevCount = GetCurrentCount(ormasDal, id, errorMessage);
		previousStatusID = GetCurrentStatusID(ormasDal, id, errorMessage);
		if (0 != id && ormasDal.UpdateSpoilage(id, date, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (CreateSpoilageEntry(ormasDal, employeeID, sum, previousSum, currencyID, errorMessage))
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
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID == statusMap.find("EXECUTED")->second)
			{
				if (count != prevCount || sum != previousSum)
				{
					if (CreateSpoilageEntry(ormasDal, employeeID, sum, previousSum, currencyID, errorMessage))
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

	bool Spoilage::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string sDate, double sCount, double sSum,
		int cID, std::string& errorMessage)
	{
		Spoilage spoilage;
		spoilage.Clear();
		errorMessage.clear();
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
		spoilage.Clear();
		errorMessage.clear();
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
	
	bool Spoilage::CreateSpoilageEntry(DataLayer::OrmasDal& ormasDal, int eID, double oSum, int cID, std::string& errorMessage)
	{
		CompanyAccountRelation cAccRel;
		CompanyEmployeeRelation cEmpRel;

		int companyID = cEmpRel.GetCompanyByEmployeeID(ormasDal, eID, errorMessage);
		int debAccID = cAccRel.GetAccountIDByCompanyID(ormasDal, companyID, "55040", errorMessage);
		int credAccID = cAccRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			return false;
		}
		if (this->CreateEntry(ormasDal, debAccID, oSum, credAccID, ormasDal.GetSystemDateTime(), errorMessage))
		{
			return true;
		}
		return false;
	}

	bool Spoilage::CreateSpoilageEntry(DataLayer::OrmasDal& ormasDal, int eID, double oSum, double prevSum, int cID, std::string& errorMessage)
	{
		CompanyAccountRelation cAccRel;
		CompanyEmployeeRelation cEmpRel;
		
		int companyID = cEmpRel.GetCompanyByEmployeeID(ormasDal, eID, errorMessage);
		int debAccID = cAccRel.GetAccountIDByCompanyID(ormasDal, companyID, "55040", errorMessage);
		int credAccID = cAccRel.GetAccountIDByCompanyID(ormasDal, companyID, "10730", errorMessage);
		if (0 == debAccID || 0 == credAccID)
		{
			return false;
		}
		if (this->CreateEntry(ormasDal, debAccID, oSum, credAccID, prevSum, ormasDal.GetSystemDateTime(), errorMessage))
		{
			return true;
		}
		return false;
	}

	double Spoilage::GetCurrentSum(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		Spoilage spoilage;
		if (spoilage.GetSpoilageByID(ormasDal, oID, errorMessage))
			return spoilage.GetSum();
		return 0;
	}

	double Spoilage::GetCurrentCount(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		Spoilage spoilage;
		if (spoilage.GetSpoilageByID(ormasDal, oID, errorMessage))
			return spoilage.GetCount();
		return 0;
	}

	int Spoilage::GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		Spoilage spoilage;
		if (spoilage.GetSpoilageByID(ormasDal, oID, errorMessage))
			return spoilage.GetStatusID();
		return 0;
	}

	bool Spoilage::CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		entry.SetDescription(wstring_to_utf8(L"Операция списания"));
		if (!entry.CreateEntry(ormasDal, errorMessage))
		{
			return false;
		}
		return true;
	}
	bool Spoilage::CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, double previousSum, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(credAccID);
		entry.SetValue(previousSum);
		entry.SetCreditingAccountID(debAccID);
		entry.SetDescription(wstring_to_utf8(L"Операция списания"));
		if (!entry.CreateEntry(ormasDal, errorMessage))
		{
			return false;
		}
		entry.Clear();
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		entry.SetDescription(wstring_to_utf8(L"Операция списания"));
		if (!entry.CreateEntry(ormasDal, errorMessage))
		{
			return false;
		}
		return true;
	}

	std::string Spoilage::wstring_to_utf8(const std::wstring& str)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
		return myconv.to_bytes(str);
	}
}