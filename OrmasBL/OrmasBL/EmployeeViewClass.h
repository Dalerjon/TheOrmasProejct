#ifndef EMPLOYEEVIEWCLASS_H
#define EMPLOYEEVIEWCLASS_H

#include "EmployeeClass.h"

namespace BusinessLayer{
	class EmployeeView : public Employee
	{
		std::string positionName = "";
		std::string roleName = "";
	public:
		EmployeeView(DataLayer::employeesViewCollection);
		EmployeeView(){};
		~EmployeeView(){};

		// EmployeeView class Accessors
		std::string GetPositionName();
		std::string GetRoleName();
	};
}

#endif //EMPLOYEEVIEWCLASS_H