#include "stdafx.h"
#include "StatusClass.h"

namespace BusinessLayer
{
	Status::Status(DataLayer::statusCollection sCollection)
	{
		ID = std::get<0>(sCollection);
		code = std::get<1>(sCollection);
		name = std::get<2>(sCollection);
		comment = std::get<3>(sCollection);
	}

	int Status::GetID()
	{
		return ID;
	}

	std::string Status::GetCode()
	{
		return  code;
	}

	std::string Status::GetName()
	{
		return name;
	}

	std::string Status::GetComment()
	{
		return comment;
	}
}