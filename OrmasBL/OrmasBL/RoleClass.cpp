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

	void Role::SetID(int rID)
	{
		id = rID;
	}
	void Role::SetName(std::string rName)
	{
		name = rName;
	}
	void Role::SetComment(std::string rComment)
	{
		comment = rComment;
	}

	bool Role::CreateRole(DataLayer::OrmasDal& ormasDal, std::string rName, std::string rComment, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		name = rName;
		comment = rComment;
		if (0 != id && ormasDal.CreateRole(id, name, comment, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Role::CreateRole(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateRole(id, name, comment, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Role::DeleteRole(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		name.clear();
		comment.clear();
		if (ormasDal.DeleteRole(id, errorMessage))
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
	bool Role::UpdateRole(DataLayer::OrmasDal& ormasDal, std::string rName, std::string rComment, std::string& errorMessage)
	{
		name = rName;
		comment = rComment;
		if (0 != id && ormasDal.UpdateRole(id, name, comment, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Role::UpdateRole(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateRole(id, name, comment, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string Role::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !name.empty() || !comment.empty())
		{
			return ormasDal.GetFilterForRole(id, name, comment);
		}
		return "";
	}

	bool Role::GetRoleByID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage)
	{
		id = rID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::rolesCollection> roleVector = ormasDal.GetRoles(errorMessage, filter);
		if (0 != roleVector.size())
		{
			id = std::get<0>(roleVector.at(0));
			name = std::get<1>(roleVector.at(0));
			comment = std::get<2>(roleVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find role with this id";
		}
		return false;
	}
	bool Role::IsEmpty()
	{
		if(0 == id && name == "" && comment == "")
			return true;
		return false;
	}
}