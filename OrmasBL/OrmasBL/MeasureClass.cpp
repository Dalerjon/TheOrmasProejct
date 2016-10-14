#include "stdafx.h"
#include "MeasureClass.h"

namespace BusinessLayer{
	Measure::Measure(DataLayer::measuresCollection mCollection)
	{
		ID = std::get<0>(mCollection);
		name = std::get<1>(mCollection);
		shortName = std::get<2>(mCollection);
	}

	int Measure::GetID()
	{
		return ID;
	}

	std::string Measure::GetName()
	{
		return name;
	}

	std::string Measure::GetShortName()
	{
		return shortName;
	}
}