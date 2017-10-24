#include "stdafx.h"
#include "AccessClass.h"
#include "AccessItemClass.h"

namespace BusinessLayer{
	Access::Access(DataLayer::accessesCollection aCollection)
	{
		id = std::get<0>(aCollection);
		roleID = std::get<1>(aCollection);
		accessItemID = std::get<2>(aCollection);
	}
	Access::Access()
	{
		roleID = 0;
		accessItemID = 0;
	}
	int Access::GetID()
	{
		return id;
	}

	int Access::GetRoleID()
	{
		return roleID;
	}

	int Access::GetAccessItemID()
	{
		return accessItemID;
	}

	void Access::SetID(int cID)
	{
		id = cID;
	}
	void Access::SetRoleID(int rID)
	{
		roleID = rID;
	}
	void Access::SetAccessItemID(int aiID)
	{
		accessItemID = aiID;
	}

	bool Access::CreateAccess(DataLayer::OrmasDal &ormasDal, int rID, int aiID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, rID, aiID, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		roleID = rID;
		accessItemID = aiID;

		if (0 != id && ormasDal.CreateAccess(id, roleID, accessItemID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Access::CreateAccess(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateAccess(id, roleID, accessItemID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Access::DeleteAccess(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteAccess(id, errorMessage))
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

	bool Access::UpdateAccess(DataLayer::OrmasDal &ormasDal, int rID, int aiID, std::string& errorMessage)
	{
		roleID = rID;
		accessItemID = aiID;
		if (0 != id && ormasDal.UpdateAccess(id, roleID, accessItemID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Access::UpdateAccess(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateAccess(id, roleID, accessItemID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string Access::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != roleID || 0 != accessItemID)
		{
			return ormasDal.GetFilterForAccess(id, roleID, accessItemID);
		}
		return "";
	}

	bool Access::GetAccessByID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage)
	{
		id = bID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::accessesCollection> accessVector = ormasDal.GetAccesses(errorMessage, filter);
		if (0 != accessVector.size())
		{
			id = std::get<0>(accessVector.at(0));
			roleID = std::get<1>(accessVector.at(0));
			accessItemID = std::get<2>(accessVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find Access with this id";
		}
		return false;
	}

	bool Access::IsEmpty()
	{
		if (0 == id && 0 == roleID && 0 == accessItemID)
			return true;
		return false;
	}

	bool Access::CheckAccess(DataLayer::OrmasDal* ormasDal, int accessItemID, std::string checkedDivision, std::string checkingItem)
	{
		AccessItem accessItem;
		errorMessage = "";
		accessItem.GetAccessItemByID(*ormasDal, accessItemID, errorMessage);
		if (!errorMessage.empty())
		{
			if (0 == checkedDivision.compare(accessItem.GetDivision()))
			{
				if (0 == checkingItem.compare(accessItem.GetNameEng()) || 0 == checkingItem.compare(accessItem.GetNameRu()))
				return true;
			}
		}
		return false;
	}

	bool Access::CheckAccess(DataLayer::OrmasDal* ormasDal, int accessItemID, std::string checkedDivision)
	{
		AccessItem accessItem;
		errorMessage = "";
		accessItem.GetAccessItemByID(*ormasDal, accessItemID, errorMessage);
		if (!errorMessage.empty())
		{
			if (0 == checkedDivision.compare(accessItem.GetDivision()))
			{
				return true;
			}
		}
		return false;
	}

	std::vector<int> Access::GetRightsList(DataLayer::OrmasDal* ormasDal, User *loggedUser)
	{
		std::vector<int> accessItemIDVector;
		SetRoleID(loggedUser->GetRoleID());
		std::string filter = GenerateFilter(*ormasDal);
		std::vector<DataLayer::accessesCollection> accessVector = ormasDal->GetAccesses(errorMessage, filter);
		if (0 != accessVector.size())
		{
			for each (auto item in accessVector)
			{
				accessItemIDVector.push_back(std::get<2>(item));
			}
		}
		return accessItemIDVector;
	}

	bool Access::IsDuplicate(DataLayer::OrmasDal& ormasDal, int rID, int aiID, std::string& errorMessage)
	{
		Access access;
		access.SetRoleID(rID);
		access.SetAccessItemID(aiID);
		std::string filter = access.GenerateFilter(ormasDal);
		std::vector<DataLayer::accessesCollection> accessVector = ormasDal.GetAccesses(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == accessVector.size())
		{
			return false;
		}
		errorMessage = "Access with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Access::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Access access;
		access.SetRoleID(roleID);
		access.SetAccessItemID(accessItemID);
		std::string filter = access.GenerateFilter(ormasDal);
		std::vector<DataLayer::accessesCollection> accessVector = ormasDal.GetAccesses(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == accessVector.size())
		{
			return false;
		}
		errorMessage = "Access with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}