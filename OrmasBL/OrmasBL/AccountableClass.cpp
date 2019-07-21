#include "stdafx.h"
#include "AccountableClass.h"
#include <boost/algorithm/string.hpp>


namespace BusinessLayer{
	Accountable::Accountable(DataLayer::accountableCollection cCollection)
	{
		employeeID = std::get<0>(cCollection);
		information = std::get<1>(cCollection);
	}

	int Accountable::GetEmployeeID()
	{
		return employeeID;
	}
	std::string Accountable::GetInformation()
	{
		return information;
	}
	
	void Accountable::SetEmployeeID(int eID)
	{
		employeeID = eID;
	}
	void Accountable::SetInformation(std::string aInformation)
	{
		if (!aInformation.empty())
			boost::trim(aInformation);
		information = aInformation;
	}
	
	bool Accountable::CreateAccountable(DataLayer::OrmasDal& ormasDal, int eID, std::string aInformation, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, eID, aInformation, errorMessage))
			return false;
		TrimStrings(aInformation);
		employeeID = eID;
		information = aInformation;
		if (ormasDal.CreateAccountable(employeeID, information, errorMessage))
		{
			if (CreateBalanceForAccountable(ormasDal,  employeeID, errorMessage))
				return true;
			return false;
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Accountable::CreateAccountable(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		if (ormasDal.CreateAccountable(employeeID, information, errorMessage))
		{
			if (CreateBalanceForAccountable(ormasDal, employeeID, errorMessage))
				return true;
			return false;
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Accountable::DeleteAccountable(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		//ormasDal.StartTransaction(errorMessage);
		if (!errorMessage.empty())
			return false;
		if (ormasDal.DeleteAccountable(id, errorMessage))
		{
			return true;
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Accountable::UpdateAccountable(DataLayer::OrmasDal& ormasDal, int eID, std::string aInformation, std::string& errorMessage)
	{
		TrimStrings(aInformation);
		employeeID = eID;
		information = aInformation;
		//ormasDal.StartTransaction(errorMessage);
		if (ormasDal.UpdateAccountable(employeeID, information, errorMessage))
		{
				return true;
		}
		return false;
	}
	bool Accountable::UpdateAccountable(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.UpdateAccountable(employeeID, information, errorMessage))
		{
			return true;
		}
		return false;
	}

	std::string Accountable::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !name.empty() || !surname.empty() || !address.empty() || !phone.empty() || !information.empty()
			|| !password.empty() || !email.empty() || 0 != roleID )
		{
			return ormasDal.GetFilterForAccountable(id, name, surname, phone, address, roleID, information);
		}
		return "";
	}

	bool Accountable::GetAccountableByID(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage)
	{
		if (uID <= 0)
			return false;
		employeeID = uID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::accountableViewCollection> accountableVector = ormasDal.GetAccountable(errorMessage, filter);
		if (0 != accountableVector.size())
		{
			employeeID = std::get<0>(accountableVector.at(0));
			information = std::get<3>(accountableVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find Accountable with this id";
		}
		return false;
	}

	bool Accountable::IsEmpty()
	{
		if (0 == employeeID && information.empty())
			return true;
		return false;
	}

	void Accountable::Clear()
	{
		employeeID = 0;
		information.clear();
	}

	void Accountable::TrimStrings(std::string& aInformation)
	{
		if (!aInformation.empty())
			boost::trim(aInformation);
		
	}

	bool Accountable::IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string aInformation, std::string& errorMessage)
	{
		Accountable accountable;
		accountable.Clear();
		errorMessage.clear();
		accountable.SetEmployeeID(eID);
		accountable.SetInformation(aInformation);
		std::string filter = accountable.GenerateFilter(ormasDal);
		std::vector<DataLayer::accountableViewCollection> accountableVector = ormasDal.GetAccountable(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == accountableVector.size())
		{
			return false;
		}
		errorMessage = "Accountable with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Accountable::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Accountable accountable;
		accountable.Clear();
		errorMessage.clear();
		accountable.SetEmployeeID(employeeID);
		accountable.SetInformation(information);
		std::string filter = accountable.GenerateFilter(ormasDal);
		std::vector<DataLayer::accountableViewCollection> accountableVector = ormasDal.GetAccountable(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == accountableVector.size())
		{
			return false;
		}
		errorMessage = "Accountable with this parameters are already exist! Please avoid the duplication!";
		return true;
	}	
}