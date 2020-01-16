#include "stdafx.h"
#include "FixedAssetsUnionClass.h"
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
#include "DivisionClass.h"
#include <codecvt>


namespace BusinessLayer
{
	FixedAssetsUnion::FixedAssetsUnion(DataLayer::fixedAssetsUnionCollection fCollection)
	{
		fixedAssets->SetID(std::get<0>(fCollection));
		fixedAssets->SetSpecificationID(std::get<22>(fCollection));
		fixedAssets->SetInventoryNumber(std::get<6>(fCollection));
		fixedAssets->SetPrimaryCost(std::get<3>(fCollection));
		fixedAssets->SetStopCost(std::get<4>(fCollection));
		fixedAssets->SetServiceLife(std::get<8>(fCollection));
		fixedAssets->SetIsAmortize(std::get<9>(fCollection));
		fixedAssets->SetBuyDate(std::get<11>(fCollection));
		fixedAssets->SetStartOfOperationDate(std::get<12>(fCollection));
		fixedAssets->SetEndOfOperationDate(std::get<13>(fCollection));
		fixedAssets->SetStatusID(std::get<23>(fCollection));
		fixedAssets->SetFixedAssetsDetailsID(std::get<24>(fCollection));
		
		fixedAssetsSpecification->SetID(std::get<22>(fCollection));
		fixedAssetsSpecification->SetName(std::get<1>(fCollection));
		fixedAssetsSpecification->SetFactoryNumber(std::get<16>(fCollection));
		fixedAssetsSpecification->SetDeveloper(std::get<17>(fCollection));
		fixedAssetsSpecification->SetDocument(std::get<18>(fCollection));
		fixedAssetsSpecification->SetObjectCharacters(std::get<19>(fCollection));
		fixedAssetsSpecification->SetCondition(std::get<20>(fCollection));
		fixedAssetsSpecification->SetDateOfConstruction(std::get<21>(fCollection));
		
		fixedAssetsDetails->SetID(std::get<24>(fCollection));
		fixedAssetsDetails->SetAmortizeGroupID(std::get<25>(fCollection));
		fixedAssetsDetails->SetAmortizeTypeID(std::get<26>(fCollection));
		fixedAssetsDetails->SetDepartmentID(std::get<27>(fCollection));
		fixedAssetsDetails->SetFixedAssetsLocation(std::get<14>(fCollection));
		fixedAssetsDetails->SetPrimaryCostAccountID(std::get<28>(fCollection));
		fixedAssetsDetails->SetAmortizeAccountID(std::get<29>(fCollection));
		fixedAssetsDetails->SetBarcodeNumber(std::get<15>(fCollection));
		fixedAssetsDetails->SetAmortizeValue(std::get<7>(fCollection));

		postingFixedAssets->SetID(std::get<30>(fCollection));
		postingFixedAssets->SetUserID(std::get<31>(fCollection));
		postingFixedAssets->SetSubaccountID(std::get<32>(fCollection));
		postingFixedAssets->SetAccountID(std::get<33>(fCollection));
	}

	FixedAssets* FixedAssetsUnion::GetFixedAssets()
	{
		return fixedAssets;
	}

	FixedAssetsDetails* FixedAssetsUnion::GetFixedAssetsDetails()
	{
		return fixedAssetsDetails;
	}

	FixedAssetsSpecification* FixedAssetsUnion::GetFixedAssetsSpecification()
	{
		return fixedAssetsSpecification;
	}

	PostingFixedAssets* FixedAssetsUnion::GetPostingFixedAssets()
	{
		return postingFixedAssets;
	}

	void FixedAssetsUnion::SetFixedAssets(FixedAssets* fs)
	{
		fixedAssets = fs;
	}

	void FixedAssetsUnion::SetFixedAssetsDetails(FixedAssetsDetails* faD)
	{
		fixedAssetsDetails = faD;
	}

	void FixedAssetsUnion::SetFixedAssetsSpecification(FixedAssetsSpecification* faS)
	{
		fixedAssetsSpecification = faS;
	}

	void FixedAssetsUnion::SetPostingFixedAssets(PostingFixedAssets* pfa)
	{
		postingFixedAssets = pfa;
	}

	bool FixedAssetsUnion::CreateFixedAssetsUnion(DataLayer::OrmasDal& ormasDal, FixedAssets* fAssets, FixedAssetsDetails* faDetails, FixedAssetsSpecification* faSpecification, PostingFixedAssets* pfAssets, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		fixedAssets = fAssets;
		fixedAssetsDetails = faDetails;
		fixedAssetsSpecification = faSpecification;
		postingFixedAssets = pfAssets;
		//ormasDal.StartTransaction(errorMessage);
		if (fixedAssetsSpecification->CreateFixedAssetsSpecification(ormasDal, errorMessage))
		{
			fixedAssetsDetails->fixedAssetsAccountID = fixedAssetsAccountID;
			int primAccID = 0;
			int amoAccID = 0;
			if (isNewFixedAssets)
			{
				primAccID = fixedAssetsDetails->GeneratePrimeSubaccount(ormasDal, 0, errorMessage);
				amoAccID = fixedAssetsDetails->GenerateAmortizeSubaccount(ormasDal, 0, errorMessage);
			}
			else
			{
				primAccID = fixedAssetsDetails->GeneratePrimeSubaccount(ormasDal, primaryValue, errorMessage);
				amoAccID = fixedAssetsDetails->GenerateAmortizeSubaccount(ormasDal, amortizeValue, errorMessage);
			}
			fixedAssetsDetails->SetPrimaryCostAccountID(primAccID);
			fixedAssetsDetails->SetAmortizeAccountID(amoAccID);
			if (fixedAssetsDetails->CreateFixedAssetsDetails(ormasDal, errorMessage))
			{
				fixedAssets->SetFixedAssetsDetailsID(fixedAssetsDetails->GetID());
				fixedAssets->SetSpecificationID(fixedAssetsSpecification->GetID());
				if (fixedAssets->CreateFixedAssets(ormasDal, errorMessage))
				{
					if (fixedAssets->GetStatusID() == statusMap.find("IN USE")->second)
					{
						if (fixedAssets->CreatePostingFixedAssetsEntry(ormasDal, accountableID, purveyorID, accountID, fixedAssetsAccountID, fixedAssets->GetPrimaryCost(), fixedAssets->GetStartOfOperationDate(), errorMessage))
						{
							return true;
						}
						else
						{
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
					if (fixedAssets->GetStatusID() == statusMap.find("ERROR")->second)
					{
						Subaccount sub;
						if (!sub.GetSubaccountByID(ormasDal, fixedAssetsDetails->GetAmortizeAccountID(), errorMessage))
							return false;
						if (sub.GetCurrentBalance() != 0)
						{
							errorMessage = "Cannot set status to \"ERROR\", amortize account value does not equal to 0";
							return false;
						}
						if (fixedAssets->CreatePostingFixedAssetsEntryReverce(ormasDal, accountableID, purveyorID, accountID, fixedAssetsAccountID, fixedAssets->GetPrimaryCost(), fixedAssets->GetStartOfOperationDate(), errorMessage))
						{
							return true;
						}
						else
						{
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
					if (fixedAssets->GetStatusID() == statusMap.find("WRITE-OFF")->second)
					{
						if (fixedAssets->CreatePostingFixedAssetsEntryWriteOFF(ormasDal, fixedAssets->GetID(), errorMessage))
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
						return true;
					}
				}
			}
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	bool FixedAssetsUnion::CreateFixedAssetsUnion(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		//ormasDal.StartTransaction(errorMessage);
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		//ormasDal.StartTransaction(errorMessage);
		if (fixedAssetsSpecification->CreateFixedAssetsSpecification(ormasDal, errorMessage))
		{
			fixedAssetsDetails->fixedAssetsAccountID = fixedAssetsAccountID;
			int primAccID = 0;
			int amoAccID = 0;
			if (isNewFixedAssets)
			{
				primAccID = fixedAssetsDetails->GeneratePrimeSubaccount(ormasDal, 0, errorMessage);
				amoAccID = fixedAssetsDetails->GenerateAmortizeSubaccount(ormasDal, 0, errorMessage);
			}
			else
			{
				primAccID = fixedAssetsDetails->GeneratePrimeSubaccount(ormasDal, primaryValue, errorMessage);
				amoAccID = fixedAssetsDetails->GenerateAmortizeSubaccount(ormasDal, amortizeValue, errorMessage);
			}
			fixedAssetsDetails->SetPrimaryCostAccountID(primAccID);
			fixedAssetsDetails->SetAmortizeAccountID(amoAccID);
			if (fixedAssetsDetails->CreateFixedAssetsDetails(ormasDal, errorMessage))
			{
				fixedAssets->SetFixedAssetsDetailsID(fixedAssetsDetails->GetID());
				fixedAssets->SetSpecificationID(fixedAssetsSpecification->GetID());
				if (fixedAssets->CreateFixedAssets(ormasDal, errorMessage))
				{
					if (fixedAssets->GetStatusID() == statusMap.find("IN USE")->second)
					{
						if (fixedAssets->CreatePostingFixedAssetsEntry(ormasDal, accountableID, purveyorID, accountID, fixedAssetsAccountID, fixedAssets->GetPrimaryCost(), fixedAssets->GetStartOfOperationDate(), errorMessage))
						{
							return true;
						}
						else
						{
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
					if (fixedAssets->GetStatusID() == statusMap.find("ERROR")->second)
					{
						Subaccount sub;
						if (!sub.GetSubaccountByID(ormasDal, fixedAssetsDetails->GetAmortizeAccountID(), errorMessage))
							return false;
						if (sub.GetCurrentBalance() != 0)
						{
							errorMessage = "Cannot set status to \"ERROR\", amortize account value does not equal to 0";
							return false;
						}
						if (fixedAssets->CreatePostingFixedAssetsEntryReverce(ormasDal, accountableID, purveyorID, accountID, fixedAssetsAccountID, fixedAssets->GetPrimaryCost(), fixedAssets->GetStartOfOperationDate(), errorMessage))
						{
							return true;
						}
						else
						{
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
					if (fixedAssets->GetStatusID() == statusMap.find("WRITE-OFFED")->second)
					{
						if (fixedAssets->CreatePostingFixedAssetsEntryWriteOFF(ormasDal, fixedAssets->GetID(), errorMessage))
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
						return true;
					}
				}
			}
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool FixedAssetsUnion::DeleteFixedAssetsUnion(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		if (fixedAssets->GetStatusID() == statusMap.find("WRITE-OFF")->second || fixedAssets->GetStatusID() == statusMap.find("ERROR")->second)
		{
			if (!fixedAssets->DeleteFixedAssets(ormasDal, errorMessage))
				return false;
			if (!fixedAssetsDetails->DeleteFixedAssetsDetails(ormasDal, errorMessage))
				return false;
			if (!postingFixedAssets->DeletePostingFixedAssets(ormasDal, errorMessage))
				return false;
			return true;
		}
		return false;
	}
	bool FixedAssetsUnion::UpdateFixedAssetsUnion(DataLayer::OrmasDal& ormasDal, FixedAssets* fAssets, FixedAssetsDetails* faDetails, FixedAssetsSpecification* faSpecification, PostingFixedAssets* pfAssets, std::string& errorMessage)
	{
		fixedAssets = fAssets;
		fixedAssetsDetails = faDetails;
		fixedAssetsSpecification = faSpecification;
		postingFixedAssets = pfAssets;
		//ormasDal.StartTransaction(errorMessage);
		if (!fixedAssets->IsEmpty() && !fixedAssetsDetails->IsEmpty() && fixedAssetsSpecification->IsEmpty())
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
	bool FixedAssetsUnion::UpdateFixedAssetsUnion(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		//ormasDal.StartTransaction(errorMessage);
		if (!fixedAssets->IsEmpty() && !fixedAssetsDetails->IsEmpty() && fixedAssetsSpecification->IsEmpty())
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

	bool FixedAssetsUnion::IsEmpty()
	{
		if (fixedAssets->IsEmpty() && fixedAssetsDetails->IsEmpty() && fixedAssetsSpecification->IsEmpty() && postingFixedAssets->IsEmpty())
			return false;
		return true;
	}

	void FixedAssetsUnion::Clear()
	{
		fixedAssets->Clear();
		fixedAssetsDetails->Clear();
		fixedAssetsSpecification->Clear();
		postingFixedAssets->Clear();
	}

	std::string FixedAssetsUnion::GenerateInventoryNumber(DataLayer::OrmasDal& ormasDal, int divID)
	{
		std::string errorMessage="";
		std::string invNumber="";
		invNumber += "F";
		Division div;
		if (!div.GetDivisionByID(ormasDal, divID, errorMessage))
			return "";
		if (0 == div.GetCode().compare("PRODUCTION"))
		{
			invNumber += "P";
		}
		if (0 == div.GetCode().compare("RELEASE"))
		{
			invNumber += "R";
		}
		if (0 == div.GetCode().compare("ADMINISTRATION"))
		{
			invNumber += "A";
		}
		std::string rawNumber = GenerateInvRawNumber(ormasDal, errorMessage);
		invNumber += rawNumber;
		if (invNumber.size() < 9)
			return "";
		return invNumber;
	}

	std::string FixedAssetsUnion::GenerateInvRawNumber(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		int countOfNulls;
		int genNumber = ormasDal.GenerateInventoryNumber();
		std::string invNumber = "";
		std::string genNumberStr = std::to_string(genNumber);
		if (genNumberStr.length() < 9)
		{
			countOfNulls = 9 - genNumberStr.length();
			for (int i = 0; i < countOfNulls; i++)
			{
				invNumber.append("0");
			}
			invNumber.append(genNumberStr);
			return invNumber;
		}
		return "";
	}
}
