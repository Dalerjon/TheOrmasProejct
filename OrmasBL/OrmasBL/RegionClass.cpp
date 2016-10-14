#include "stdafx.h"
#include "RegionClass.h"

namespace BusinessLayer
{
	Region::Region(DataLayer::regionsCollection rCollection)
	{
		ID = std::get<0>(rCollection);
		code = std::get<1>(rCollection);
		name = std::get<2>(rCollection);
	}

	int Region::GetID()
	{
		return ID;
	}

	std::string Region::GetCode()
	{
		return code;
	}

	std::string Region::GetName()
	{
		return name;
	}
}