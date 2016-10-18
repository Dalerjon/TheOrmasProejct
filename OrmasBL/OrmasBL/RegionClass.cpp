#include "stdafx.h"
#include "RegionClass.h"

namespace BusinessLayer
{
	Region::Region(DataLayer::regionsCollection rCollection)
	{
		id = std::get<0>(rCollection);
		code = std::get<1>(rCollection);
		name = std::get<2>(rCollection);
	}

	int Region::GetID()
	{
		return id;
	}

	std::string Region::GetCode()
	{
		return code;
	}

	std::string Region::GetName()
	{
		return name;
	}

	bool Region::CreateRegion(DataLayer::OrmasDal& ormasDal, std::string rCode, std::string rName)
	{
		id = ormasDal.GenerateID();
		code = rCode;
		name = rName;
		try
		{
			if (ormasDal.CreateRegion(id, code, name))
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
	bool Region::DeleteRegion(DataLayer::OrmasDal& ormasDal)
	{
		code.clear();
		name.clear();
		try
		{
			if (ormasDal.DeleteRegion(id))
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
	bool Region::UpdateRegion(DataLayer::OrmasDal& ormasDal, std::string rCode, std::string rName)
	{
		if (0 == id)
			return false;
		code = rCode;
		name = rName;
		try
		{
			if (ormasDal.UpdateRegion(id, code, name))
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