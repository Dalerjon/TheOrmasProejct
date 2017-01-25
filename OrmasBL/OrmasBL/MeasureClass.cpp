#include "stdafx.h"
#include "MeasureClass.h"

namespace BusinessLayer{
	Measure::Measure(DataLayer::measuresCollection mCollection)
	{
		id = std::get<0>(mCollection);
		name = std::get<1>(mCollection);
		shortName = std::get<2>(mCollection);
		unit = std::get<3>(mCollection);
	}

	int Measure::GetID()
	{
		return id;
	}

	std::string Measure::GetName()
	{
		return name;
	}

	std::string Measure::GetShortName()
	{
		return shortName;
	}

	int Measure::GetUnit()
	{
		return unit;
	}

	void Measure::SetID(int mID)
	{
		id = mID;
	}
	void Measure::SetName(std::string mName)
	{
		name = mName;
	}
	void Measure::SetShortName(std::string mShortName)
	{
		shortName = mShortName;
	}

	void Measure::SetUnit(int mUnit)
	{
		unit = mUnit;
	}

	bool Measure::CreateMeasure(DataLayer::OrmasDal& ormasDal, std::string mName, std::string mShortName, int mUnit, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		name = mName;
		shortName = mShortName;
		unit = mUnit;
		if (0 != id && ormasDal.CreateMeasure(id, name, shortName, unit, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Measure::CreateMeasure(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateMeasure(id, name, shortName, unit, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Measure::DeleteMeasure(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		name.clear();
		shortName.clear();
		if (ormasDal.DeleteMeasure(id, errorMessage))
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
	bool Measure::UpdateMeasure(DataLayer::OrmasDal& ormasDal, std::string mName, std::string mShortName, int mUnit, std::string& errorMessage)
	{
		name = mName;
		shortName = mShortName;
		if (0 != id && ormasDal.UpdateMeasure(id, name, shortName, mUnit, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Measure::UpdateMeasure(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateMeasure(id, name, shortName, unit, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string Measure::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !name.empty() ||  !shortName.empty())
		{
			return ormasDal.GetFilterForMeasure(id, name, shortName, unit);
		}
		return "";
	}

	bool Measure::GetMeasureByID(DataLayer::OrmasDal& ormasDal, int mID, std::string& errorMessage)
	{
		id = mID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::measuresCollection> measuresVector = ormasDal.GetMeasures(errorMessage, filter);
		if (0 != measuresVector.size())
		{
			id = std::get<0>(measuresVector.at(0));
			name = std::get<1>(measuresVector.at(0));
			shortName = std::get<2>(measuresVector.at(0));
			unit = std::get<3>(measuresVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find measure with this id";
		}
		return false;
	}
	bool Measure::IsEmpty()
	{
		if (0 == id && name == "" && shortName == "" && 0 == unit)
			return true;
		return false;
	}
}