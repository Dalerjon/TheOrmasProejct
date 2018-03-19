#include "stdafx.h"
#include "CompanyAccountRelationClass.h"


namespace BusinessLayer{
	CompanyAccountRelation::CompanyAccountRelation(DataLayer::companyAccountCollection caCollection)
	{
		companyID = std::get<0>(caCollection);
		accountID = std::get<1>(caCollection);
	}
	CompanyAccountRelation::CompanyAccountRelation()
	{
		companyID = 0;
		accountID = 0;
	}

	int CompanyAccountRelation::GetCompanyID()
	{
		return companyID;
	}

	int CompanyAccountRelation::GetAccountID()
	{
		return accountID;
	}

	void CompanyAccountRelation::SetCompanyID(int cID)
	{
		companyID = cID;
	}
	void CompanyAccountRelation::SetAccountID(int aID)
	{
		accountID = aID;
	}

	bool CompanyAccountRelation::CreateCompanyAccountRelation(DataLayer::OrmasDal &ormasDal, int cID, int aID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, cID, aID, errorMessage))
			return false;
		companyID = cID;
		accountID = aID;

		if (ormasDal.CreateCompanyAccount(companyID, accountID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool CompanyAccountRelation::CreateCompanyAccountRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		if (ormasDal.CreateCompanyAccount(companyID, accountID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool CompanyAccountRelation::DeleteCompanyAccountRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteCompanyAccount(companyID, accountID, errorMessage))
		{
			Clear();
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}



	std::string CompanyAccountRelation::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != companyID || 0 != accountID)
		{
			return ormasDal.GetFilterForCompanyAccount(companyID, accountID);
		}
		return "";
	}

	std::vector<int> CompanyAccountRelation::GetAllCompanyByAccountID(DataLayer::OrmasDal& ormasDal, int aID, std::string& errorMessage)
	{
		std::vector<int> companyIDVector;
		CompanyAccountRelation caRelation;
		caRelation.SetAccountID(aID);
		caRelation.SetCompanyID(0);
		std::string filter = caRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::companyAccountCollection> companyAccountVector = ormasDal.GetCompanyAccount(errorMessage, filter);
		if (0 != companyAccountVector.size())
		{
			for each (auto item in companyAccountVector)
			{
				companyIDVector.push_back(std::get<1>(item));
			}
		}
		return companyIDVector;
	}

	std::vector<int> CompanyAccountRelation::GetAllAccountByCompanyID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage)
	{
		std::vector<int> accountIDVector;
		CompanyAccountRelation caRelation;
		caRelation.SetAccountID(0);
		caRelation.SetCompanyID(cID);
		std::string filter = caRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::companyAccountCollection> companyAccountVector = ormasDal.GetCompanyAccount(errorMessage, filter);
		if (0 != companyAccountVector.size())
		{
			for each (auto item in companyAccountVector)
			{
				accountIDVector.push_back(std::get<0>(item));
			}
		}
		return accountIDVector;
	}


	bool CompanyAccountRelation::IsEmpty()
	{
		if (0 == companyID && 0 == accountID)
			return true;
		return false;
	}

	void CompanyAccountRelation::Clear()
	{
		companyID = 0;
		accountID = 0;
	}

	bool CompanyAccountRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, int cID, int aID, std::string& errorMessage)
	{
		CompanyAccountRelation caRelation;
		caRelation.SetCompanyID(cID);
		caRelation.SetAccountID(aID);
		std::string filter = caRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::companyAccountCollection> companyAccountVector = ormasDal.GetCompanyAccount(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == companyAccountVector.size())
		{
			return false;
		}
		errorMessage = "Company-Account Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool CompanyAccountRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		CompanyAccountRelation caRelation;
		caRelation.SetCompanyID(companyID);
		caRelation.SetAccountID(accountID);
		std::string filter = caRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::companyAccountCollection> companyAccountVector = ormasDal.GetCompanyAccount(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == companyAccountVector.size())
		{
			return false;
		}
		errorMessage = "Company-Account Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}