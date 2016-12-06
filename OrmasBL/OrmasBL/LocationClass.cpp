#include "stdafx.h"
#include "LocationClass.h"

namespace BusinessLayer
{
	Location::Location(DataLayer::locationsCollection rCollection)
	{
		id = std::get<0>(rCollection);
		countryName = std::get<1>(rCollection);
		countryCode = std::get<2>(rCollection);
		regionName = std::get<3>(rCollection);
		cityName = std::get<4>(rCollection);
	}

	int Location::GetID()
	{
		return id;
	}

	std::string Location::GetCountryName()
	{
		return countryName;
	}

	std::string Location::GetCountryCode()
	{
		return countryCode;
	}

	std::string Location::GetRegionName()
	{
		return regionName;
	}

	std::string Location::GetCityName()
	{
		return cityName;
	}
	void Location::SetID(int rID)
	{
		id = rID;
	}
	void Location::SetCountryName(std::string lCountryName)
	{
		countryName = lCountryName;
	}
	void Location::SetCountryCode(std::string lCountryCode)
	{
		countryCode = lCountryCode;
	}
	void Location::SetRegionName(std::string lRegionName)
	{
		regionName = lRegionName;
	}
	void Location::SetCityName(std::string lCityName)
	{
		cityName = lCityName;
	}

	bool Location::CreateLocation(DataLayer::OrmasDal& ormasDal, std::string lCountryName, std::string lCountryCode,
		std::string lRegionName, std::string lCityName, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		countryName = lCountryName;
		countryCode = lCountryCode;
		regionName = lRegionName;
		cityName = lCityName;
		if (0 != id && ormasDal.CreateLocation(id, countryName, countryCode, regionName, cityName, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Location::CreateLocation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateLocation(id, countryName, countryCode, regionName, cityName, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Location::DeleteLocation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		countryName.clear();
		countryCode.clear();
		regionName.clear();
		cityName.clear();
		if (ormasDal.DeleteLocation(id, errorMessage))
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
	bool Location::UpdateLocation(DataLayer::OrmasDal& ormasDal, std::string lCountryName, std::string lCountryCode,
		std::string lRegionName, std::string lCityName, std::string& errorMessage)
	{
		countryName = lCountryName;
		countryCode = lCountryCode;
		regionName = lRegionName;
		cityName = lCityName;
		if (0 != id && ormasDal.UpdateLocation(id, countryName, countryCode, regionName, cityName, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Location::UpdateLocation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateLocation(id, countryName, countryCode, regionName, cityName, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
}