#include "stdafx.h"
#include "StatusClass.h"

namespace BusinessLayer
{
	Status::Status(DataLayer::statusCollection sCollection)
	{
		id = std::get<0>(sCollection);
		code = std::get<1>(sCollection);
		name = std::get<2>(sCollection);
		comment = std::get<3>(sCollection);
	}

	int Status::GetID()
	{
		return id;
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

	void Status::SetID(int sID)
	{
		id = sID;
	}
	void Status::SetCode(std::string sCode)
	{
		code = sCode;
	}
	void Status::SetName(std::string sName)
	{
		name = sName;
	}
	void Status::SetComment(std::string sComment)
	{
		comment = sComment;
	}


	bool Status::CreateStatus(DataLayer::OrmasDal& ormasDal, std::string sCode, std::string sName, std::string sComment, 
		std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		code = sCode;
		name = sName;
		comment = sComment;
		if (0 != id && ormasDal.CreateStatus(id, code, name, comment, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Status::CreateStatus(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateStatus(id, code, name, comment, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Status::DeleteStatus(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		code.clear();
		name.clear();
		comment.clear();
		if (ormasDal.DeleteStatus(id, errorMessage))
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
	bool Status::UpdateStatus(DataLayer::OrmasDal& ormasDal, std::string sCode, std::string sName, std::string sComment, 
		std::string& errorMessage)
	{
		code = sCode;
		name = sName;
		comment = sComment;
		if (0 != id && ormasDal.UpdateStatus(id, code, name, comment, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Status::UpdateStatus(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateStatus(id, code, name, comment, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string Status::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !code.empty() || !name.empty() || !comment.empty())
		{
			return ormasDal.GetFilterForStatus(id, code, name, comment);
		}
		return "";
	}

	bool Status::GetStatusByID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage)
	{
		id = sID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::statusCollection> statusVector = ormasDal.GetStatus(errorMessage, filter);
		if (0 != statusVector.size())
		{
			id = std::get<0>(statusVector.at(0));
			code = std::get<1>(statusVector.at(0));
			name = std::get<2>(statusVector.at(0));
			comment = std::get<3>(statusVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find status with this id";
		}
		return false;
	}
	bool Status::IsEmpty()
	{
		if(0 == id && code == "" && name == "" && comment == "")
			return true;
		return false;
	}
}