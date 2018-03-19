#include "stdafx.h"
#include "PurveyorViewClass.h"

namespace BusinessLayer{
	PurveyorView::PurveyorView(DataLayer::purveyorsViewCollection pCollection)
	{
		id = std::get<0>(pCollection);
		name = std::get<1>(pCollection);
		surname = std::get<2>(pCollection);
		phone = std::get<3>(pCollection);
		countryName = std::get<4>(pCollection);
		regionName = std::get<5>(pCollection);
		cityName = std::get<6>(pCollection);
		address = std::get<7>(pCollection);
		companyName = std::get<8>(pCollection);
		roleName = std::get<9>(pCollection);
		password = std::get<10>(pCollection);
		email = std::get<11>(pCollection);
		activated = std::get<12>(pCollection);
		roleID = std::get<13>(pCollection);
		locationID = std::get<14>(pCollection);
	}

	std::string PurveyorView::GetCountryName()
	{
		return countryName;
	}
	std::string PurveyorView::GetRegionName()
	{
		return regionName;
	}
	std::string PurveyorView::GetCityName()
	{
		return cityName;
	}
	std::string PurveyorView::GetRoleName()
	{
		return roleName;
	}
}