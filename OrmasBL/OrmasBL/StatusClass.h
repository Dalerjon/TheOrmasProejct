#ifndef STATUSCLASS_H
#define STATUSCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Status
	{
		int ID;
		std::string code;
		std::string name;
		std::string comment;
	public:
		Status(int sID, std::string sCode, std::string sName, std::string comment):ID(sID), code(sCode),
			name(sName), comment(comment){};
		Status(DataLayer::statusCollection);
		Status(){};
		~Status(){};
		int CreateStatus(int sID, std::string sCode, std::string sName, std::string comment){};

		//Status class Accessors
		int GetID();
		std::string GetCode();
		std::string GetName();
		std::string GetComment();

		//Mutators
	};
}
#endif // STATUSCLASS_H