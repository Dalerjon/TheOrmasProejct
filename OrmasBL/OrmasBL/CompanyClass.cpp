#include "stdafx.h"
#include "CompanyClass.h"

namespace BusinessLayer{

	Company::Company(DataLayer::companiesCollection compCollection)
	{
		id = std::get<0>(compCollection);
		name = std::get<1>(compCollection);
		address = std::get<2>(compCollection);
		phone = std::get<3>(compCollection);
		comment = std::get<4>(compCollection);
	}
	Company::Company()
	{
		name = "";
		address = "";
		phone = "";
		comment = "";
	}
	int Company::GetID()
	{
		return id;
	}

	std::string Company::GetName()
	{
		return name;
	}

	std::string Company::GetAddress()
	{
		return address;
	}

	std::string Company::GetPhone()
	{
		return phone;
	}

	std::string Company::GetComment()
	{
		return comment;
	}

	void Company::SetID(int cID)
	{
		id = cID;
	}
	void Company::SetName(std::string cName)
	{
		name = cName;
	}
	void Company::SetAddress(std::string cPhone)
	{
		phone = cPhone;
	}
	void Company::SetPhone(std::string cAddress)
	{
		address = cAddress;
	}
	void Company::SetComment(std::string cComment)
	{
		comment = cComment;
	}

	bool Company::CreateCompany(DataLayer::OrmasDal& ormasDal, std::string cName, std::string cAddress, std::string cPhone,
		std::string cComment, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		name = cName;
		address = cAddress;
		phone = cPhone;
		comment = cComment;
		if (0 != id && ormasDal.CreateCompany(id, name, address, phone, comment, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Company::CreateCompany(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateCompany(id, name, address, phone, comment, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Company::DeleteCompany(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteCompany(id, errorMessage))
		{
			id = 0;
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}

	bool Company::UpdateCompany(DataLayer::OrmasDal& ormasDal, std::string cName, std::string cAddress, std::string cPhone
		, std::string cComment, std::string& errorMessage)
	{
		name = cName;
		address = cAddress;
		phone = cPhone;
		comment = cComment;
		if (0 != id && ormasDal.UpdateCompany(id, name, address, phone, comment, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Company::UpdateCompany(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateCompany(id, name, address, phone, comment, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string Company::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !name.empty() || !address.empty() || !phone.empty() || !comment.empty())
		{
			return ormasDal.GetFilterForCompany(id, name, address, phone, comment);
		}
		return "";
	}

	bool Company::GetCompanyByID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage)
	{
		id = cID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::companiesCollection> companyVector = ormasDal.GetCompanies(errorMessage, filter);
		if (0 != companyVector.size())
		{
			id = std::get<0>(companyVector.at(0));
			name = std::get<1>(companyVector.at(0));
			address = std::get<2>(companyVector.at(0));
			phone = std::get<3>(companyVector.at(0));
			comment = std::get<4>(companyVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find company with this id";
		}
		return false;
	}

	bool Company::IsEmpty()
	{
		if (0 == id && name == "" && address == "" && phone == "" && comment == "")
			return true;
		return false;
	}
}

