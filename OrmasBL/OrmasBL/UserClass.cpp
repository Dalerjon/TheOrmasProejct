#include "stdafx.h"
#include "UserClass.h"

namespace BusinessLayer
{
	User::User(DataLayer::usersCollection uCollection)
	{
		ID = std::get<0>(uCollection);
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
		return ID;
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
}