#include "stdafx.h"
#include "FixedAssetsClass.h"
#include "BalanceClass.h"
#include "UserClass.h"
#include "EntryClass.h"
#include "SubaccountClass.h"
#include "AccountClass.h"
#include "EntryOperationRelationClass.h"
#include "StatusClass.h"
#include "CompanyAccountRelationClass.h"
#include "CompanyEmployeeRelationClass.h"
#include "CompanyClass.h"
#include <codecvt>

namespace BusinessLayer
{
	FixedAssets::FixedAssets(DataLayer::fixedAssetsCollection fCollection)
	{
		id = std::get<0>(fCollection);
		specificationID = std::get<1>(fCollection);
		inventoryNumber = std::get<2>(fCollection);
		primaryCost = std::get<3>(fCollection);
		stopCost = std::get<4>(fCollection);
		serviceLife = std::get<5>(fCollection);
		isAmortize = std::get<6>(fCollection);
		buyDate = std::get<7>(fCollection);
		startOfOperationDate = std::get<8>(fCollection);
		endOfOperationDate = std::get<9>(fCollection);
		statusID = std::get<10>(fCollection);
		fixedAssetsDetailsID = std::get<11>(fCollection);
	}

	int FixedAssets::GetID()
	{
		return id;
	}

	int FixedAssets::GetSpecificationID()
	{
		return specificationID;
	}

	std::string FixedAssets::GetInventoryNumber()
	{
		return inventoryNumber;
	}

	double FixedAssets::GetPrimaryCost()
	{
		return primaryCost;
	}

	double FixedAssets::GetStopCost()
	{
		return stopCost;
	}

	int FixedAssets::GetServiceLife()
	{
		return serviceLife;
	}

	bool FixedAssets::GetIsAmortize()
	{
		return isAmortize;
	}

	std::string FixedAssets::GetBuyDate()
	{
		return buyDate;
	}

	std::string FixedAssets::GetStartOfOperationDate()
	{
		return startOfOperationDate;
	}

	std::string FixedAssets::GetEndOfOperationDate()
	{
		return endOfOperationDate;
	}

	int FixedAssets::GetStatusID()
	{
		return statusID;
	}

	int FixedAssets::GetFixedAssetsDetailsID()
	{
		return fixedAssetsDetailsID;
	}

	void FixedAssets::SetID(int fID)
	{
		id = fID;
	}

	void FixedAssets::SetSpecificationID(int fsID)
	{
		specificationID = fsID;
	}

	void FixedAssets::SetInventoryNumber(std::string iNumber)
	{
		inventoryNumber = iNumber;
	}

	void FixedAssets::SetPrimaryCost(double pCost)
	{
		primaryCost = pCost;
	}

	void FixedAssets::SetStopCost(double sCost)
	{
		stopCost = sCost;
	}

	void FixedAssets::SetServiceLife(int sLife)
	{
		serviceLife = sLife;
	}

	void FixedAssets::SetIsAmortize(bool iAmor)
	{
		isAmortize = iAmor;
	}

	void FixedAssets::SetBuyDate(std::string bDate)
	{
		buyDate = bDate;
	}

	void FixedAssets::SetStartOfOperationDate(std::string sDate)
	{
		startOfOperationDate = sDate;
	}
	
	void FixedAssets::SetEndOfOperationDate(std::string eDate)
	{
		endOfOperationDate = eDate;
	}
	
	void FixedAssets::SetStatusID(int sID)
	{
		statusID = sID;
	}

	void FixedAssets::SetFixedAssetsDetailsID(int fAssetsID)
	{
		fixedAssetsDetailsID = fAssetsID;
	}

	bool FixedAssets::CreateFixedAssets(DataLayer::OrmasDal& ormasDal, int sID, std::string iNumber, double pCost, double sCost,
		int sLife, bool isAmor, std::string bDate, std::string sOfDate, std::string eOfDate, int statID, int fadID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, sID, iNumber, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		specificationID = sID;
		inventoryNumber = iNumber;
		primaryCost = pCost;
		stopCost = sCost;
		serviceLife = sLife;
		isAmortize = isAmor;
		buyDate = bDate;
		startOfOperationDate = sOfDate;
		endOfOperationDate = eOfDate;
		statusID = statID;
		fixedAssetsDetailsID = fadID;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateFixedAssets(id, specificationID, inventoryNumber, primaryCost, stopCost, serviceLife, 
			isAmortize, buyDate, startOfOperationDate, endOfOperationDate, statusID, fixedAssetsDetailsID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	bool FixedAssets::CreateFixedAssets(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateFixedAssets(id, specificationID, inventoryNumber, primaryCost, stopCost, serviceLife,
			isAmortize, buyDate, startOfOperationDate, endOfOperationDate, statusID, fixedAssetsDetailsID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool FixedAssets::DeleteFixedAssets(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		//if (!ormasDal.StartTransaction(errorMessage))
		//	return false;
		if (ormasDal.DeleteFixedAssets(id, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool FixedAssets::UpdateFixedAssets(DataLayer::OrmasDal& ormasDal, int sID, std::string iNumber, double pCost, double sCost, int sLife, bool isAmor, std::string bDate,
		std::string sOfDate, std::string eOfDate, int statID, int fadID, std::string& errorMessage)
	{
		specificationID = sID;
		inventoryNumber = iNumber;
		primaryCost = pCost;
		stopCost = sCost;
		serviceLife = sLife;
		isAmortize = isAmor;
		buyDate = bDate;
		startOfOperationDate = sOfDate;
		endOfOperationDate = eOfDate;
		statusID = statID;
		fixedAssetsDetailsID = fadID;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateFixedAssets(id, specificationID, inventoryNumber, primaryCost, stopCost, serviceLife,
			isAmortize, buyDate, startOfOperationDate, endOfOperationDate, statusID, fixedAssetsDetailsID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool FixedAssets::UpdateFixedAssets(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateFixedAssets(id, specificationID, inventoryNumber, primaryCost, stopCost, serviceLife,
			isAmortize, buyDate, startOfOperationDate, endOfOperationDate, statusID, fixedAssetsDetailsID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	std::string FixedAssets::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != specificationID || !inventoryNumber.empty() || 0.0 != primaryCost || 0.0 != stopCost || 0 != serviceLife 
			|| !buyDate.empty() || !startOfOperationDate.empty() || !endOfOperationDate.empty() || 0 != statusID || 0 != fixedAssetsDetailsID)
		{
			return ormasDal.GetFilterForFixedAssets(id, specificationID, inventoryNumber, primaryCost, stopCost, serviceLife,
				isAmortize, buyDate, startOfOperationDate, endOfOperationDate, statusID, fixedAssetsDetailsID);
		}
		return "";
	}

	bool FixedAssets::GetFixedAssetsByID(DataLayer::OrmasDal& ormasDal, int fID, std::string& errorMessage)
	{
		if (fID <= 0)
			return false;
		id = fID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::fixedAssetsViewCollection> fixedAssetsVector = ormasDal.GetFixedAssets(errorMessage, filter);
		if (0 != fixedAssetsVector.size())
		{
			id = std::get<0>(fixedAssetsVector.at(0));
			specificationID = std::get<14>(fixedAssetsVector.at(0));
			inventoryNumber = std::get<2>(fixedAssetsVector.at(0));
			primaryCost = std::get<3>(fixedAssetsVector.at(0));
			stopCost = std::get<4>(fixedAssetsVector.at(0));
			serviceLife = std::get<9>(fixedAssetsVector.at(0));
			isAmortize = std::get<10>(fixedAssetsVector.at(0));
			buyDate = std::get<11>(fixedAssetsVector.at(0));
			startOfOperationDate = std::get<12>(fixedAssetsVector.at(0));
			endOfOperationDate = std::get<13>(fixedAssetsVector.at(0));
			statusID = std::get<15>(fixedAssetsVector.at(0));
			fixedAssetsDetailsID = std::get<16>(fixedAssetsVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find fixed assets with this id";
		}
		return false;
	}

	bool FixedAssets::IsEmpty()
	{
		if (0 == id && 0 == specificationID && inventoryNumber == "" && 0 == primaryCost && 0 == stopCost && 0 == serviceLife
			&& buyDate == "" && startOfOperationDate == "" && endOfOperationDate == "" && 0 == statusID && 0 == fixedAssetsDetailsID)
			return false;
		return true;
	}

	void FixedAssets::Clear()
	{
		id = 0;
		specificationID = 0;
		inventoryNumber = "";
		primaryCost = 0;
		stopCost = 0;
		serviceLife = 0;
		isAmortize = false;
		buyDate = "";
		startOfOperationDate = "";
		endOfOperationDate = "";
		statusID =0;
		fixedAssetsDetailsID = 0;
	}

	bool FixedAssets::IsDuplicate(DataLayer::OrmasDal& ormasDal, int sID, std::string iNumber, std::string& errorMessage)
	{
		FixedAssets fixedAssets;
		fixedAssets.Clear();
		errorMessage.clear();
		fixedAssets.SetSpecificationID(sID);
		fixedAssets.SetInventoryNumber(iNumber);
		std::string filter = fixedAssets.GenerateFilter(ormasDal);
		std::vector<DataLayer::fixedAssetsViewCollection> fixedAssetsVector = ormasDal.GetFixedAssets(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == fixedAssetsVector.size())
		{
			return false;
		}
		errorMessage = "Fixed assets with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool FixedAssets::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		FixedAssets fixedAssets;
		fixedAssets.Clear();
		errorMessage.clear();
		fixedAssets.SetSpecificationID(specificationID);
		fixedAssets.SetInventoryNumber(inventoryNumber);
		std::string filter = fixedAssets.GenerateFilter(ormasDal);
		std::vector<DataLayer::fixedAssetsViewCollection> fixedAssetsVector = ormasDal.GetFixedAssets(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == fixedAssetsVector.size())
		{
			return false;
		}
		errorMessage = "Fixed assets with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool FixedAssets::CreatePostingFixedAssetsEntry(DataLayer::OrmasDal& ormasDal, int acctbID, int purID, int accID, int debitingAccID, double value, std::string execDate, std::string& errorMessage)
	{
		if (purID > 0)
		{
			Balance balance;
			if (balance.GetBalanceByUserID(ormasDal, purID, errorMessage))
			{
				int debAccID = 0;
				int credAccID = 0;
				debAccID = debitingAccID;
				credAccID = balance.GetSubaccountID();
				if (this->CreateEntry(ormasDal, debAccID, value, credAccID, execDate, errorMessage))
				{
					return true;
				}
			}
			return false;
		}
		if (acctbID > 0)
		{
			Balance balance;
			Balance tempBalance;
			Subaccount sub;
			Account account;
			if (!account.GetAccountByNumber(ormasDal, "10520", errorMessage))
				return false;
			balance.SetUserID(acctbID);
			std::string filter = balance.GenerateFilter(ormasDal);
			std::vector<DataLayer::balancesViewCollection> balanceVector = ormasDal.GetBalances(errorMessage, filter);
			if (0 < balanceVector.size())
			{
				balance.Clear();
				for each (auto item in balanceVector)
				{
					sub.Clear();
					tempBalance.Clear();
					if (!tempBalance.GetBalanceByID(ormasDal, std::get<0>(item), errorMessage))
						return false;
					if (sub.GetSubaccountByID(ormasDal, tempBalance.GetSubaccountID(), errorMessage))
					{
						if (sub.GetParentAccountID() == account.GetID())
						{
							balance.SetSubaccountID(sub.GetID());
						}
					}
				}
			}
			else
			{
				return false;
			}
			if (balance.GetSubaccountID() <= 0)
				return false;
			if (balance.GetBalanceBySubaccountID(ormasDal, balance.GetSubaccountID(), errorMessage))
			{
				int credAccID = balance.GetSubaccountID();
				int debAccID = debitingAccID;
				if (0 == debAccID || 0 == credAccID)
				{
					return false;
				}
				if (this->CreateEntry(ormasDal, debAccID, value, credAccID, execDate, errorMessage))
				{
					return true;
				}
			}
		}
		else if (accID > 0)
		{
			int credAccID = accID;
			int debAccID = debitingAccID;
			if (0 == debAccID || 0 == credAccID)
			{
				return false;
			}
			if (this->CreateEntry(ormasDal, debAccID, value, credAccID, execDate, errorMessage))
			{
				return true;
			}
		}
		return false;
	}

	bool FixedAssets::CreatePostingFixedAssetsEntryReverce(DataLayer::OrmasDal& ormasDal, int acctbID, int purID, int accID, int debitingAccID, double value, std::string execDate, std::string& errorMessage)
	{
		if (purID > 0)
		{
			Balance balance;
			if (balance.GetBalanceByUserID(ormasDal, purID, errorMessage))
			{
				int debAccID = 0;
				int credAccID = 0;
				debAccID = debitingAccID;
				credAccID = balance.GetSubaccountID();
				if (this->CreateEntry(ormasDal, debAccID, value, credAccID, execDate, errorMessage))
				{
					return true;
				}
			}
			return false;
		}
		if (acctbID > 0)
		{
			Balance balance;
			Balance tempBalance;
			Subaccount sub;
			Account account;
			if (!account.GetAccountByNumber(ormasDal, "10520", errorMessage))
				return false;
			balance.SetUserID(acctbID);
			std::string filter = balance.GenerateFilter(ormasDal);
			std::vector<DataLayer::balancesViewCollection> balanceVector = ormasDal.GetBalances(errorMessage, filter);
			if (0 < balanceVector.size())
			{
				balance.Clear();
				for each (auto item in balanceVector)
				{
					sub.Clear();
					tempBalance.Clear();
					if (!tempBalance.GetBalanceByID(ormasDal, std::get<0>(item), errorMessage))
						return false;
					if (sub.GetSubaccountByID(ormasDal, tempBalance.GetSubaccountID(), errorMessage))
					{
						if (sub.GetParentAccountID() == account.GetID())
						{
							balance.SetSubaccountID(sub.GetID());
						}
					}
				}
			}
			else
			{
				return false;
			}
			if (balance.GetSubaccountID() <= 0)
				return false;
			if (balance.GetBalanceBySubaccountID(ormasDal, balance.GetSubaccountID(), errorMessage))
			{
				int credAccID = balance.GetSubaccountID();
				int debAccID = debitingAccID;
				if (0 == debAccID || 0 == credAccID)
				{
					return false;
				}
				if (this->CreateEntry(ormasDal, credAccID, value, debAccID, execDate, errorMessage))
				{
					return true;
				}
			}
		}
		else if (accID > 0)
		{
			int credAccID = accID;
			int debAccID = debitingAccID;
			if (0 == debAccID || 0 == credAccID)
			{
				return false;
			}
			if (this->CreateEntry(ormasDal, credAccID, value, debAccID, execDate, errorMessage))
			{
				return true;
			}
		}
		return false;
	}

	bool FixedAssets::CreatePostingFixedAssetsEntryWriteOFF(DataLayer::OrmasDal& ormasDal, int fixedAssetsID, std::string& errorMessage)
	{
		FixedAssets fx;
		if (!fx.GetFixedAssetsByID(ormasDal, fixedAssetsID, errorMessage))
			return false;

	}

	bool FixedAssets::CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		EntryOperationRelation eoRelation;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		entry.SetDescription(wstring_to_utf8(L"�������� ��������� ��������!"));
		if (entry.CreateEntry(ormasDal, errorMessage))
		{
			eoRelation.SetEntryID(entry.GetID());
			eoRelation.SetOperationID(id);
			if (!eoRelation.CreateEntryOperationRelation(ormasDal, errorMessage))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		return true;
	}

	bool FixedAssets::CreateEntryCancel(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		EntryOperationRelation eoRelation;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		entry.SetDescription(wstring_to_utf8(L"������ ������� ��������� ��������"));
		if (entry.CreateEntry(ormasDal, errorMessage))
		{
			eoRelation.SetEntryID(entry.GetID());
			eoRelation.SetOperationID(id);
			if (!eoRelation.CreateEntryOperationRelation(ormasDal, errorMessage))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		return true;
	}

	bool FixedAssets::CreateEntryWriteOFF(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		EntryOperationRelation eoRelation;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		entry.SetDescription(wstring_to_utf8(L"�������� ��������� ��������"));
		if (entry.CreateEntry(ormasDal, errorMessage))
		{
			eoRelation.SetEntryID(entry.GetID());
			eoRelation.SetOperationID(id);
			if (!eoRelation.CreateEntryOperationRelation(ormasDal, errorMessage))
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		return true;
	}

	std::string FixedAssets::wstring_to_utf8(const std::wstring& str)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
		return myconv.to_bytes(str);
	}
}

