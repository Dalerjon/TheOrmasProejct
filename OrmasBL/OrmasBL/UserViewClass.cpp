#include "stdafx.h"
#include "UserViewClass.h"

namespace BusinessLayer
{
	UserView::UserView(DataLayer::usersViewCollection uCollection)
	{
		id = std::get<0>(uCollection);
		name = std::get<1>(uCollection);
		phone = std::get<2>(uCollection);
		address = std::get<3>(uCollection);
		countryName = std::get<4>(uCollection);
		countryCode = std::get<5>(uCollection);
		regionName = std::get<6>(uCollection);
		cityName = std::get<7>(uCollection);
		roleName = std::get<8>(uCollection);
		firm = std::get<9>(uCollection);
		firmNumber = std::get<10>(uCollection);
		password = std::get<11>(uCollection);
		activated = std::get<12>(uCollection);
		roleID = std::get<13>(uCollection);
		locationID = std::get<14>(uCollection);
	}

	std::string UserView::GetCountryName()
	{
		return countryName;
	}
	std::string UserView::GetCountryCode()
	{
		return countryCode;
	}
	std::string UserView::GetRegionName()
	{
		return regionName;
	}
	std::string UserView::GetCityName()
	{
		return cityName;
	}
	std::string UserView::GetRoleName()
	{
		return roleName;
	}

	void UserView::SetCountryName(std::string uCountryName)
	{
		countryName = uCountryName;
	}
	void UserView::SetCountryCode(std::string uCountryCode)
	{
		countryCode = uCountryCode;
	}
	void UserView::SetRegionName(std::string uRegionName)
	{
		regionName = uRegionName;
	}
	void UserView::SetCityName(std::string uCityName)
	{
		cityName = uCityName;
	}
	void UserView::SetRoleName(std::string uRoleName)
	{
		roleName = uRoleName;
	}
}