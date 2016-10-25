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
		regionID = std::get<7>(uCollection);
		password = std::get<8>(uCollection);
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

	int User::GetRegionID()
	{
		return regionID;
	}

	std::string User::GetPassword()
	{
		return password;
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
	void User::SetRegionID(int uRegionID)
	{
		regionID = uRegionID;
	}
	void User::SetPassword(std::string uPassword)
	{
		password = uPassword;
	}

	bool User::CreateUser(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uPhone, std::string uAddress,
		std::string uFirm, std::string uFirmNumber, int uRoleID, int uRegionID, std::string uPassword)
	{
		id = ormasDal.GenerateID();
		name = uName;
		phone = uPhone;
		address = uAddress;
		firm = uFirm;
		firmNumber = uFirmNumber;
		roleID = uRoleID;
		regionID = uRegionID;
		password = uPassword;
		try
		{
			if (ormasDal.CreateUser(id, name, phone, address, firm, firmNumber, roleID, regionID, password))
			{
				return true;
			}
			return false;
		}
		catch (...)
		{
			return false;
		}
	}
	bool User::DeleteUser(DataLayer::OrmasDal& ormasDal)
	{
		name.clear();
		phone.clear();
		address.clear();
		firm.clear();
		firmNumber.clear();
		roleID = 0;
		regionID = 0;
		password.clear();
		try
		{
			if (ormasDal.DeleteUser(id))
			{
				id = 0;
				return true;
			}
			return false;
		}
		catch (...)
		{
			return false;
		}
	}
	bool User::UpdateUser(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uPhone, std::string uAddress,
		std::string uFirm, std::string uFirmNumber, int uRoleID, int uRegionID, std::string uPassword)
	{
		if (0 == id)
			return false;
		name = uName;
		phone = uPhone;
		address = uAddress;
		firm = uFirm;
		firmNumber = uFirmNumber;
		roleID = uRoleID;
		regionID = uRegionID;
		password = uPassword;
		try
		{
			if (ormasDal.UpdateUser(id, name, phone, address, firm, firmNumber, roleID, regionID, password))
			{
				return true;
			}
			return false;
		}
		catch (...)
		{
			return false;
		}
	}
}