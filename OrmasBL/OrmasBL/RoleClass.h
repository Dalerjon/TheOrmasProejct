#ifndef ROLECLASS_H
#define ROLECLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Role
	{
		int id=0;
		std::string name;
		std::string comment;
	public:
		Role(int rID, std::string rName, std::string comment) :id(rID), name(rName), comment(comment){};
		Role(DataLayer::rolesCollection);
		Role(){};
		~Role(){};
		
		//Role class Accessors
		int GetID();
		std::string GetName();
		std::string GetComment();

		//Please implement Mutators
		
		//Create, delete, update methods
		bool CreateRole(DataLayer::OrmasDal& ormasDal, std::string rName, std::string rComment);
		bool DeleteRole(DataLayer::OrmasDal& ormasDal);
		bool UpdateRole(DataLayer::OrmasDal& ormasDal, std::string rName, std::string rComment);
	};
}
#endif //ROLECLASS_H