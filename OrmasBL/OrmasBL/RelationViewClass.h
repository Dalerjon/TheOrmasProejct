#ifndef RELATIONVIEWCLASS_H
#define RELATIONVIEWCLASS_H

#include "RelationClass.h"

namespace BusinessLayer
{
	class RelationView : public Relation
	{
		std::string employeeName = "";
		std::string employeeSurname = "";
		std::string employeePhone = "";
		std::string relationName = "";
		std::string userName = "";
		std::string userSurname = "";
		std::string userPhone = "";
	public:
		RelationView(DataLayer::relationsViewCollection);
		RelationView(){};
		~RelationView(){};

		// RelationView class Accessors
		std::string GetEmployeeName();
		std::string GetEmployeeSurname();
		std::string GetEmployeePhone();
		std::string GetRelationName();
		std::string GetUsername();
		std::string GetUserSurname();
		std::string GetUserPhone();
	};
}
#endif //RELATIONVIEWCLASS_H