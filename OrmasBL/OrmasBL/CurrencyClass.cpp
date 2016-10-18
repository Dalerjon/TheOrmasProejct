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

	bool Currency::CreateCurrency(DataLayer::OrmasDal& ormasDal, int cCode, std::string cShortName, std::string cName)
	{
		id = ormasDal.GenerateID();
		code = cCode;
		shortName = cShortName;
		name = cName;
		try
		{
			if (ormasDal.CreateCurrency(id, code, shortName, name))
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
	bool Currency::DeleteCurrency(DataLayer::OrmasDal& ormasDal)
	{
		code = 0;
		shortName.clear();
		name.clear();
		try
		{
			if (ormasDal.DeleteCurrency(id))
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
	bool Currency::UpdateCurrency(DataLayer::OrmasDal& ormasDal, int cCode, std::string cShortName, std::string cName)
	{
		if (0 == id)
			return false;
		code = cCode;
		shortName = cShortName;
		name = cName;
		try
		{
			if (ormasDal.UpdateCurrency(id, code, shortName, name))
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