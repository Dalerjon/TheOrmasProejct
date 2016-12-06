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

	bool Currency::CreateCurrency(DataLayer::OrmasDal& ormasDal, int cCode, std::string cShortName, std::string cName, 
		std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		code = cCode;
		shortName = cShortName;
		name = cName;
		if (0 != id && ormasDal.CreateCurrency(id, code, shortName, name, errorMessage))
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
		if (0 != id && ormasDal.CreateCurrency(id, code, shortName, name, errorMessage))
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
	bool Currency::UpdateCurrency(DataLayer::OrmasDal& ormasDal, int cCode, std::string cShortName, std::string cName, 
		std::string& errorMessage)
	{
		code = cCode;
		shortName = cShortName;
		name = cName;
		if (0 != id && ormasDal.UpdateCurrency(id, code, shortName, name, errorMessage))
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
		if (0 != id && ormasDal.UpdateCurrency(id, code, shortName, name, errorMessage))
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