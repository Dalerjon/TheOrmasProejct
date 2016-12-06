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
}