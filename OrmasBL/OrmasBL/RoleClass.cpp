#include "stdafx.h"
#include "RoleClass.h"
#include <boost/algorithm/string.hpp>

namespace BusinessLayer
{
	Role::Role(DataLayer::rolesCollection rCollection)
	{
		id = std::get<0>(rCollection);
		code = std::get<1>(rCollection);
		name = std::get<2>(rCollection);
		comment = std::get<3>(rCollection);
	}

	int Role::GetID()
	{
		return id;
	}
	
	std::string Role::GetCode()
	{
		return code;
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
	void Role::SetCode(std::string rCode)
	{
		if (!rCode.empty())
			boost::trim(rCode);
		code = boost::to_upper_copy(rCode);
	}
	void Role::SetName(std::string rName)
	{
		if (!rName.empty())
			boost::trim(rName);
		name = boost::to_upper_copy(rName);
	}
	void Role::SetComment(std::string rComment)
	{
		comment = rComment;
	}

	bool Role::CreateRole(DataLayer::OrmasDal& ormasDal, std::string rCode, std::string rName, std::string rComment, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, rCode, rName, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		TrimStrings(rCode, rName);
		code = boost::to_upper_copy(rCode);
		name = boost::to_upper_copy(rName);
		comment = rComment;
		if (0 != id && ormasDal.CreateRole(id, code, name, comment, errorMessage))
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
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateRole(id, code, name, comment, errorMessage))
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
		if (ormasDal.DeleteRole(id, errorMessage))
		{
			Clear();
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}
	bool Role::UpdateRole(DataLayer::OrmasDal& ormasDal, std::string rCode, std::string rName, std::string rComment, std::string& errorMessage)
	{
		TrimStrings(rCode, rName);
		code = boost::to_upper_copy(rCode);
		name = boost::to_upper_copy(rName);
		comment = rComment;
		if (0 != id && ormasDal.UpdateRole(id, code, name, comment, errorMessage))
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
		if (0 != id && ormasDal.UpdateRole(id, code, name, comment, errorMessage))
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
		if (0 != id || !code.empty() || !name.empty() || !comment.empty())
		{
			return ormasDal.GetFilterForRole(id, code, name, comment);
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
			code = std::get<1>(roleVector.at(0));
			name = std::get<2>(roleVector.at(0));
			comment = std::get<3>(roleVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find role with this id";
		}
		return false;
	}

	int Role::GetRoleIDByName(DataLayer::OrmasDal& ormasDal, std::string rName, std::string& errorMessage)
	{
		name = rName;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::rolesCollection> roleVector = ormasDal.GetRoles(errorMessage, filter);
		if (0 != roleVector.size())
		{
			return std::get<0>(roleVector.at(0));
		}
		else
		{
			errorMessage = "Cannot find role with this id";
		}
		return 0;
	}
	
	bool Role::IsEmpty()
	{
		if(0 == id && code == "" && name == "" && comment == "")
			return true;
		return false;
	}

	void Role::Clear()
	{
		id = 0;
		code.clear();
		name.clear();
		comment.clear();
	}

	void Role::TrimStrings(std::string& rCode, std::string& rName)
	{
		if (!rCode.empty())
			boost::trim(rCode);
		if (!rName.empty())
			boost::trim(rName);
	}

	bool Role::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string rCode, std::string rName, std::string& errorMessage)
	{
		Role role;
		role.Clear();
		errorMessage.clear();
		role.SetCode(rCode);
		role.SetName(rName);
		std::string filter = role.GenerateFilter(ormasDal);
		std::vector<DataLayer::rolesCollection> roleVector = ormasDal.GetRoles(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == roleVector.size())
		{
			return false;
		}
		errorMessage = "Role with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Role::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Role role;
		role.Clear();
		errorMessage.clear();
		role.SetCode(code);
		role.SetName(name);
		std::string filter = role.GenerateFilter(ormasDal);
		std::vector<DataLayer::rolesCollection> roleVector = ormasDal.GetRoles(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == roleVector.size())
		{
			return false;
		}
		errorMessage = "Role with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}