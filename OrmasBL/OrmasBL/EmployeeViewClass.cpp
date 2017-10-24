#include "stdafx.h"
#include "EmployeeViewClass.h"

namespace BusinessLayer{
	EmployeeView::EmployeeView(DataLayer::employeesViewCollection cCollection)
	{
		id = std::get<0>(cCollection);
		name = std::get<1>(cCollection);
		surname = std::get<2>(cCollection);
		positionName = std::get<3>(cCollection);
		phone = std::get<4>(cCollection);
		address = std::get<5>(cCollection);
		birthDate = std::get<6>(cCollection);
		roleName = std::get<7>(cCollection);
		hireDate = std::get<8>(cCollection);
		password = std::get<9>(cCollection);
		email = std::get<10>(cCollection);
		activated = std::get<11>(cCollection);
		roleID = std::get<12>(cCollection);
		positionID = std::get<13>(cCollection);
	}

	std::string EmployeeView::GetPositionName()
	{
		return positionName;
	}
	std::string EmployeeView::GetRoleName()
	{
		return roleName;
	}
}