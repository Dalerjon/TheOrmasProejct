#include "stdafx.h"
#include "UserClass.h"

namespace BusinessLayer
{
	User::User(DataLayer::usersCollection uCollection)
	{
		id = std::get<0>(uCollection);
		name = std::get<1>(uCollection);
		phone = std::get<2>(uCollection);
		address = std::get<3>(uCollection);
		firm = std::get<4>(uCollection);
		firmNumber = std::get<5>(uCollection);
		roleID = std::get<6>(uCollection);
		locationID = std::get<7>(uCollection);
		password = std::get<8>(uCollection);
		activated = std::get<9>(uCollection);
	}

	int User::GetID()
	{
		return id;
	}

	std::string User::GetName()
	{
		return name;
	}

	std::string User::GetPhone()
	{
		return phone;
	}

	std::string User::GetAddress()
	{
		return address;
	}

	std::string User::GetFirm()
	{
		return firm;
	}

	std::string User::GetFirmNumber()
	{
		return firmNumber;
	}

	int User::GetRoleID()
	{
		return roleID;
	}

	int User::GetLocationID()
	{
		return locationID;
	}

	std::string User::GetPassword()
	{
		return password;
	}

	bool User::GetActivated()
	{
		return activated;
	}

	void User::SetID(int uID)
	{
		id = uID;
	}
	void User::SetName(std::string uName)
	{
		name = uName;
	}
	void User::SetPhone(std::string uPhone)
	{
		phone = uPhone;
	}
	void User::SetAddress(std::string uAddress)
	{
		address = uAddress;
	}
	void User::SetFirm(std::string uFirm)
	{
		firm = uFirm;
	}
	void User::SetFirmNumber(std::string uFirmNumber)
	{
		firmNumber = uFirmNumber;
	}
	void User::SetRoleID(int uRoleID)
	{
		roleID = uRoleID;
	}
	void User::SetLocationID(int uLocationID)
	{
		locationID = uLocationID;
	}
	void User::SetPassword(std::string uPassword)
	{
		password = uPassword;
	}
	void User::SetActivated(bool uActivated)
	{
		activated = uActivated;
	}

	bool User::CreateUser(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uPhone, std::string uAddress,
		std::string uFirm, std::string uFirmNumber, int uRoleID, int uLocationID, std::string uPassword, bool uAtivated, 
		std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		name = uName;
		phone = uPhone;
		address = uAddress;
		firm = uFirm;
		firmNumber = uFirmNumber;
		roleID = uRoleID;
		locationID = uLocationID;
		password = uPassword;
		if (0 != id && ormasDal.CreateUser(id, name, phone, address, firm, firmNumber, roleID, locationID, password,
			activated, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool User::CreateUser(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateUser(id, name, phone, address, firm, firmNumber, roleID, locationID, password,
			activated, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool User::DeleteUser(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		name.clear();
		phone.clear();
		address.clear();
		firm.clear();
		firmNumber.clear();
		roleID = 0;
		locationID = 0;
		password.clear();
		if (ormasDal.DeleteUser(id, errorMessage))
		{
			id = 0;
			return true;
		}
		return false;
	}
	bool User::UpdateUser(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uPhone, std::string uAddress,
		std::string uFirm, std::string uFirmNumber, int uRoleID, int uLocationID, std::string uPassword, bool uAtivated,
		std::string& errorMessage)
	{
		name = uName;
		phone = uPhone;
		address = uAddress;
		firm = uFirm;
		firmNumber = uFirmNumber;
		roleID = uRoleID;
		locationID = uLocationID;
		password = uPassword;
		if (0 != id && ormasDal.UpdateUser(id, name, phone, address, firm, firmNumber, roleID, locationID, password, 
			activated, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool User::UpdateUser(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateUser(id, name, phone, address, firm, firmNumber, roleID, locationID, password,
			activated, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	std::string User::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !name.empty() || !address.empty() || !phone.empty() || !firm.empty() || !firmNumber.empty()
			|| !password.empty() || 0 != roleID || 0 != locationID)
		{
			return ormasDal.GetFilterForUser(id, name, phone, address, firm, firmNumber, roleID, locationID, password,
				activated);
		}
		return "";
	}

	bool User::GetUserByID(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage)
	{
		id = uID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::usersViewCollection> userVector = ormasDal.GetUsers(errorMessage, filter);
		if (0 != userVector.size())
		{
			id = std::get<0>(userVector.at(0));
			name = std::get<1>(userVector.at(0));
			phone = std::get<2>(userVector.at(0));
			address = std::get<3>(userVector.at(0));
			firm = std::get<9>(userVector.at(0));
			firmNumber = std::get<10>(userVector.at(0));
			password = std::get<11>(userVector.at(0));
			activated = std::get<12>(userVector.at(0));
			roleID = std::get<13>(userVector.at(0));
			locationID = std::get<14>(userVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find user with this id";
		}
		return false;
	}
	
	bool User::GetUserByCredentials(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uPassword)
	{
		std::string errorMessage = "";
		name = uName;
		password = uPassword;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::usersViewCollection> userVector = ormasDal.GetUsers(errorMessage, filter);
		if (0 != userVector.size())
		{
			id = std::get<0>(userVector.at(0));
			name = std::get<1>(userVector.at(0));
			phone = std::get<2>(userVector.at(0));
			address = std::get<3>(userVector.at(0));
			firm = std::get<9>(userVector.at(0));
			firmNumber = std::get<10>(userVector.at(0));
			password = std::get<11>(userVector.at(0));
			activated = std::get<12>(userVector.at(0));
			roleID = std::get<13>(userVector.at(0));
			locationID = std::get<14>(userVector.at(0));
			return true;
		}
		return false;
	}
	
	bool User::IsEmpty()
	{
		if (0 == id && name == "" && phone == "" && address == "" && firm == "" && firmNumber == "" && password == "" &&
			activated == false && 0 == roleID && 0 == locationID)
			return true;
		return false;
	}
}

