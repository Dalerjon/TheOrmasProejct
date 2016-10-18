#ifndef STATUSCLASS_H
#define STATUSCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Status
	{
		int id=0;
		std::string code;
		std::string name;
		std::string comment;
	public:
		Status(int sID, std::string sCode, std::string sName, std::string comment):id(sID), code(sCode),
			name(sName), comment(comment){};
		Status(DataLayer::statusCollection);
		Status(){};
		~Status(){};

		//Status class Accessors
		int GetID();
		std::string GetCode();
		std::string GetName();
		std::string GetComment();

		//Mutators
		
		//Create, delete, update methods
		bool CreateStatus(DataLayer::OrmasDal& ormasDal, std::string sCode, std::string sName, std::string sComment);
		bool DeleteStatus(DataLayer::OrmasDal& ormasDal);
		bool UpdateStatus(DataLayer::OrmasDal& ormasDal, std::string sCode, std::string sName, std::string sComment);
	};
}
#endif // STATUSCLASS_H