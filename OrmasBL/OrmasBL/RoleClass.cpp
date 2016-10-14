#include "stdafx.h"
#include "RoleClass.h"

namespace BusinessLayer
{
	Role::Role(DataLayer::rolesCollection rCollection)
	{
		ID = std::get<0>(rCollection);
		name = std::get<1>(rCollection);
		comment = std::get<2>(rCollection);
	}

	int Role::GetID()
	{
		return ID;
	}
	
	std::string Role::GetName()
	{
		return name;
	}

	std::string Role::GetComment()
	{
		return comment;
	}
}