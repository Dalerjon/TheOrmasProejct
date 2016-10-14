#ifndef ROLECLASS_H
#define ROLECLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Role
	{
		int ID;
		std::string name;
		std::string comment;
	public:
		Role(int rID, std::string rName, std::string comment) :ID(rID), name(rName), comment(comment){};
		Role(DataLayer::rolesCollection);
		Role(){};
		~Role(){};
		int CreateRole(int rID, std::string rName, std::string comment){};

		//Role class Accessors
		int GetID();
		std::string GetName();
		std::string GetComment();

		//Please implement Mutators
	};
}
#endif //ROLECLASS_H