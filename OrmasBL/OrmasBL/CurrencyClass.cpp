#include "stdafx.h"
#include "CurrencyClass.h"

namespace BusinessLayer
{
	Currency::Currency(DataLayer::currenciesCollection curCollection)
	{
		id = std::get<0>(curCollection);
		code = std::get<1>(curCollection);
		shortName = std::get<2>(curCollection);
		name = std::get<3>(curCollection);
		unit = std::get<4>(curCollection);
		mainTrade = std::get<5>(curCollection);
	}
	
	int Currency::GetID()
	{
		return id;
	}

	int Currency::GetCode()
	{
		return code;
	}

	std::string Currency::GetShortName()
	{
		return shortName;
	}

	std::string Currency::GetName()
	{
		return name;
	}

	int Currency::GetUnit()
	{
		return unit;
	}

	bool Currency::GetMainTrade()
	{
		return mainTrade;
	}

	void Currency::SetID(int cID)
	{
		id = cID;
	}
	void Currency::SetCode(int cCode)
	{
		code = cCode;
	}
	void Currency::SetShortName(std::string cShortName)
	{
		shortName = cShortName;
	}
	void Currency::SetName(std::string cName)
	{
		name = cName;
	}
	void Currency::SetUnit(int cUnit)
	{
		unit = cUnit;
	}
	void Currency::SetMainTrade(bool cMainTrade)
	{
		mainTrade = cMainTrade;
	}

	bool Currency::CreateCurrency(DataLayer::OrmasDal& ormasDal, int cCode, std::string cShortName, std::string cName, int cUnit,
		bool cMainTrade, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		code = cCode;
		shortName = cShortName;
		name = cName;
		unit = cUnit;
		mainTrade = cMainTrade;
		if (0 != id && ormasDal.CreateCurrency(id, code, shortName, name, unit, mainTrade, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Currency::CreateCurrency(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateCurrency(id, code, shortName, name, unit, mainTrade, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Currency::DeleteCurrency(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		code = 0;
		shortName.clear();
		name.clear();
		if (ormasDal.DeleteCurrency(id, errorMessage))
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
	bool Currency::UpdateCurrency(DataLayer::OrmasDal& ormasDal, int cCode, std::string cShortName, std::string cName, int cUnit,
		bool cMainTrade, std::string& errorMessage)
	{
		code = cCode;
		shortName = cShortName;
		name = cName;
		unit = cUnit;
		mainTrade = cMainTrade;
		if (0 != id && ormasDal.UpdateCurrency(id, code, shortName, name, unit, mainTrade, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Currency::UpdateCurrency(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateCurrency(id, code, shortName, name, unit, mainTrade, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	
	std::string Currency::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != code || !name.empty() || !shortName.empty())
		{
			return ormasDal.GetFilterForCurrency(id, code, shortName, name, unit);
		}
		return "";
	}

	bool Currency::GetCurrencyByID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage)
	{
		id = cID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::currenciesCollection> currencyVector = ormasDal.GetCurrencies(errorMessage, filter);
		if (0 != currencyVector.size())
		{
			id = std::get<0>(currencyVector.at(0));
			code = std::get<1>(currencyVector.at(0));
			shortName = std::get<2>(currencyVector.at(0));
			name = std::get<3>(currencyVector.at(0));
			unit = std::get<4>(currencyVector.at(0));
			mainTrade = std::get<5>(currencyVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find currency with this id";
		}
		return false;
	}
	
	bool Currency::IsEmpty()
	{
		if (0 == id && 0 == code && shortName == "" &&	name == "" && 0 == unit && mainTrade == false)
			return true;
		return false;
	}
}