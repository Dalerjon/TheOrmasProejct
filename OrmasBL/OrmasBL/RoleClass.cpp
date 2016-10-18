#include "stdafx.h"
#include "RoleClass.h"

namespace BusinessLayer
{
	Role::Role(DataLayer::rolesCollection rCollection)
	{
		id = std::get<0>(rCollection);
		name = std::get<1>(rCollection);
		comment = std::get<2>(rCollection);
	}

	int Role::GetID()
	{
		return id;
	}
	
	std::string Role::GetName()
	{
		return name;
	}

	std::string Role::GetComment()
	{
		return comment;
	}

	bool Role::CreateRole(DataLayer::OrmasDal& ormasDal, std::string rName, std::string rComment)
	{
		id = ormasDal.GenerateID();
		name = rName;
		comment = rComment;
		try
		{
			if (ormasDal.CreateRole(id, name, comment))
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
	bool Role::DeleteRole(DataLayer::OrmasDal& ormasDal)
	{
		name.clear();
		comment.clear();
		try
		{
			if (ormasDal.DeleteRole(id))
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
	bool Role::UpdateRole(DataLayer::OrmasDal& ormasDal, std::string rName, std::string rComment)
	{
		if (0 == id)
			return false;
		name = rName;
		comment = rComment;
		try
		{
			if (ormasDal.UpdateRole(id, name, comment))
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