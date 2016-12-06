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
}