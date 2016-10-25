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


	bool Status::CreateStatus(DataLayer::OrmasDal& ormasDal, std::string sCode, std::string sName, std::string sComment)
	{
		id = ormasDal.GenerateID();
		code = sCode;
		name = sName;
		comment = sComment;
		try
		{
			if (ormasDal.CreateStatus(id, code, name, comment))
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
	bool Status::DeleteStatus(DataLayer::OrmasDal& ormasDal)
	{
		code.clear();
		name.clear();
		comment.clear();
		try
		{
			if (ormasDal.DeleteStatus(id))
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
	bool Status::UpdateStatus(DataLayer::OrmasDal& ormasDal, std::string sCode, std::string sName, std::string sComment)
	{
		if (0 == id)
			return false;
		code = sCode;
		name = sName;
		comment = sComment;
		try
		{
			if (ormasDal.UpdateStatus(id,code, name, comment))
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