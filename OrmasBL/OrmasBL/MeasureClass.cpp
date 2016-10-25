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

	bool Measure::CreateMeasure(DataLayer::OrmasDal& ormasDal, std::string mName, std::string mShortName)
	{
		id = ormasDal.GenerateID();
		name = mName;
		shortName = mShortName;
		try
		{
			if (ormasDal.CreateMeasure(id, name,shortName))
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
	bool Measure::DeleteMeasure(DataLayer::OrmasDal& ormasDal)
	{
		name.clear();
		shortName.clear();
		try
		{
			if (ormasDal.DeleteMeasure(id))
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
	bool Measure::UpdateMeasure(DataLayer::OrmasDal& ormasDal, std::string mName, std::string mShortName)
	{
		if (0 == id)
			return false;
		name = mName;
		shortName = mShortName;
		try
		{
			if (ormasDal.UpdateMeasure(id, name, shortName))
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