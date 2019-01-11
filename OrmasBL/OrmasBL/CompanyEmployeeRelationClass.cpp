#include "stdafx.h"
#include "CompanyEmployeeRelationClass.h"
#include "EmployeeClass.h"


namespace BusinessLayer{
	CompanyEmployeeRelation::CompanyEmployeeRelation(DataLayer::companyEmployeeCollection ceCollection)
	{
		id = std::get<0>(ceCollection);
		companyID = std::get<1>(ceCollection);
		employeeID = std::get<2>(ceCollection);
		branchID = std::get<3>(ceCollection);
	}
	CompanyEmployeeRelation::CompanyEmployeeRelation()
	{
		id = 0;
		companyID = 0;
		employeeID = 0;
		branchID = 0;
	}

	int CompanyEmployeeRelation::GetID()
	{
		return id;
	}

	int CompanyEmployeeRelation::GetCompanyID()
	{
		return companyID;
	}

	int CompanyEmployeeRelation::GetEmployeeID()
	{
		return employeeID;
	}

	int CompanyEmployeeRelation::GetBranchID()
	{
		return branchID;
	}

	void CompanyEmployeeRelation::SetID(int ceID)
	{
		id = ceID;
	}
	void CompanyEmployeeRelation::SetCompanyID(int cID)
	{
		companyID = cID;
	}
	void CompanyEmployeeRelation::SetEmployeeID(int aID)
	{
		employeeID = aID;
	}
	void CompanyEmployeeRelation::SetBranchID(int aID)
	{
		branchID = aID;
	}

	bool CompanyEmployeeRelation::CreateCompanyEmployeeRelation(DataLayer::OrmasDal &ormasDal, int cID, int eID, int bID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, cID, eID, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		companyID = cID;
		employeeID = eID;
		branchID = bID;

		if (ormasDal.CreateCompanyEmployee(id, companyID, employeeID, branchID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool CompanyEmployeeRelation::CreateCompanyEmployeeRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		if (ormasDal.CreateCompanyEmployee(id, companyID, employeeID, branchID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool CompanyEmployeeRelation::DeleteCompanyEmployeeRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteCompanyEmployee(companyID, employeeID, errorMessage))
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

	bool CompanyEmployeeRelation::UpdateCompanyEmployeeRelation(DataLayer::OrmasDal &ormasDal, int cID, int eID, int bID, std::string& errorMessage)
	{
		companyID = cID;
		employeeID = eID;
		branchID = bID;
		if (0 != id && ormasDal.UpdateCompanyEmployee(id, companyID, employeeID, branchID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool CompanyEmployeeRelation::UpdateCompanyEmployeeRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateCompanyEmployee(id, companyID, employeeID, branchID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string CompanyEmployeeRelation::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != companyID || 0 != employeeID)
		{
			return ormasDal.GetFilterForCompanyEmployee(id, companyID, employeeID, branchID);
		}
		return "";
	}

	bool CompanyEmployeeRelation::GetCompanyEmployeeByID(DataLayer::OrmasDal& ormasDal, int id, std::string& errorMessage)
	{
		CompanyEmployeeRelation ceRelation;
		ceRelation.SetID(id);
		std::string filter = ceRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::companyEmployeeViewCollection> companyEmployeeVector = ormasDal.GetCompanyEmployee(errorMessage, filter);
		if (0 != companyEmployeeVector.size())
		{
			id = std::get<0>(companyEmployeeVector.at(0));
			companyID = std::get<6>(companyEmployeeVector.at(0));
			employeeID = std::get<7>(companyEmployeeVector.at(0));
			branchID = std::get<7>(companyEmployeeVector.at(0));
			return true;
		}
		return false;
	}

	int CompanyEmployeeRelation::GetCompanyByEmployeeID(DataLayer::OrmasDal& ormasDal, int eID, std::string& errorMessage)
	{
		CompanyEmployeeRelation ceRelation;
		ceRelation.SetEmployeeID(eID);
		ceRelation.SetCompanyID(0);
		std::string filter = ceRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::companyEmployeeViewCollection> companyEmployeeVector = ormasDal.GetCompanyEmployee(errorMessage, filter);
		if (0 != companyEmployeeVector.size())
		{
			return std::get<6>(companyEmployeeVector.at(0));
		}
		return 0;
	}

	int CompanyEmployeeRelation::GetEmployeeByCompanyID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage)
	{
		CompanyEmployeeRelation ceRelation;
		ceRelation.SetEmployeeID(0);
		ceRelation.SetCompanyID(cID);
		std::string filter = ceRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::companyEmployeeViewCollection> companyEmployeeVector = ormasDal.GetCompanyEmployee(errorMessage, filter);
		if (0 != companyEmployeeVector.size())
		{
			return std::get<7>(companyEmployeeVector.at(0));
		}
		return 0;
	}


	bool CompanyEmployeeRelation::IsEmpty()
	{
		if (0 == id && 0 == companyID && 0 == employeeID)
			return true;
		return false;
	}

	void CompanyEmployeeRelation::Clear()
	{
		id = 0;
		companyID = 0;
		employeeID = 0;
	}

	bool CompanyEmployeeRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, int cID, int eID, std::string& errorMessage)
	{
		CompanyEmployeeRelation ceRelation;
		ceRelation.Clear();
		errorMessage.clear();
		ceRelation.SetCompanyID(cID);
		ceRelation.SetEmployeeID(eID);
		std::string filter = ceRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::companyEmployeeViewCollection> companyEmployeeVector = ormasDal.GetCompanyEmployee(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == companyEmployeeVector.size())
		{
			return false;
		}
		errorMessage = "Company-employee Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool CompanyEmployeeRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		CompanyEmployeeRelation ceRelation;
		ceRelation.Clear();
		errorMessage.clear();
		ceRelation.SetCompanyID(companyID);
		ceRelation.SetEmployeeID(employeeID);
		std::string filter = ceRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::companyEmployeeViewCollection> companyEmployeeVector = ormasDal.GetCompanyEmployee(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == companyEmployeeVector.size())
		{
			return false;
		}
		errorMessage = "Company-employee Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}