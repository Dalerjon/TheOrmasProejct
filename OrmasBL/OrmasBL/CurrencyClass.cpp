#include "stdafx.h"
#include "CurrencyClass.h"

namespace BusinessLayer
{
	Currency::Currency(DataLayer::currenciesCollection curCollection)
	{
		ID = std::get<0>(curCollection);
		code = std::get<1>(curCollection);
		shortName = std::get<2>(curCollection);
		name = std::get<3>(curCollection);
	}
	
	int Currency::GetID()
	{
		return ID;
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
}