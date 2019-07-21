#include "stdafx.h"
#include "EmployeeProductRelationViewClass.h"

namespace BusinessLayer{
	EmployeeProductRelationView::EmployeeProductRelationView(DataLayer::employeeProductViewCollection wCollection)
	{
		id = std::get<0>(wCollection);
		userName = std::get<1>(wCollection);
		userSurname = std::get<2>(wCollection);
		userPhone = std::get<3>(wCollection);
		productName = std::get<4>(wCollection);
		price = std::get<5>(wCollection);
		employeeID = std::get<6>(wCollection);
		productID = std::get<7>(wCollection);
	}

	std::string EmployeeProductRelationView::GetUsername()
	{
		return userName;
	}
	std::string EmployeeProductRelationView::GetUserSurname()
	{
		return userSurname;
	}
	std::string EmployeeProductRelationView::GetUserPhone()
	{
		return userPhone;
	}
	std::string EmployeeProductRelationView::GetProductName()
	{
		return productName;
	}
	double EmployeeProductRelationView::GetPrice()
	{
		return price;
	}
}