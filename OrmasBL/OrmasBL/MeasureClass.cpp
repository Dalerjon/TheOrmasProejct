#include "stdafx.h"
#include "MeasureClass.h"

namespace BusinessLayer{
	Measure::Measure(DataLayer::measuresCollection mCollection)
	{
		id = std::get<0>(mCollection);
		name = std::get<1>(mCollection);
		shortName = std::get<2>(mCollection);
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

	bool Measure::CreateMeasure(DataLayer::OrmasDal& ormasDal, std::string mName, std::string mShortName, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		name = mName;
		shortName = mShortName;
		if (0 != id && ormasDal.CreateMeasure(id, name, shortName, errorMessage))
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
		if (0 != id && ormasDal.CreateMeasure(id, name, shortName, errorMessage))
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
	bool Measure::UpdateMeasure(DataLayer::OrmasDal& ormasDal, std::string mName, std::string mShortName, std::string& errorMessage)
	{
		name = mName;
		shortName = mShortName;
		if (0 != id && ormasDal.UpdateMeasure(id, name, shortName, errorMessage))
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
		if (0 != id && ormasDal.UpdateMeasure(id, name, shortName, errorMessage))
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