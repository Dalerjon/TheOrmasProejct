#include "stdafx.h"
#include "RelationViewClass.h"

namespace BusinessLayer
{
	RelationView::RelationView(DataLayer::relationsViewCollection rCollection)
	{
		id = std::get<0>(rCollection);
		employeeName = std::get<1>(rCollection);
		employeeSurname = std::get<2>(rCollection);
		employeePhone = std::get<3>(rCollection);
		relationName = std::get<4>(rCollection);
		userName = std::get<5>(rCollection);
		userSurname = std::get<6>(rCollection);
		userPhone = std::get<7>(rCollection);
		user1ID = std::get<8>(rCollection);
		user2ID = std::get<9>(rCollection);
		relationTypeID = std::get<10>(rCollection);
	}

	std::string RelationView::GetEmployeeName()
	{
		return employeeName;
	}
	std::string RelationView::GetEmployeeSurname()
	{
		return employeeSurname;
	}
	std::string RelationView::GetEmployeePhone()
	{
		return employeePhone;
	}
	std::string RelationView::GetRelationName()
	{
		return relationName;
	}
	std::string RelationView::GetUsername()
	{
		return userName;
	}
	std::string RelationView::GetUserSurname()
	{
		return userSurname;
	}
	std::string RelationView::GetUserPhone()
	{
		return userPhone;
	}
}

