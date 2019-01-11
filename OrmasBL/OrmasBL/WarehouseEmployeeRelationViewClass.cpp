#include "stdafx.h"
#include "WarehouseEmployeeRelationViewClass.h"

namespace BusinessLayer{
	WarehouseEmployeeRelationView::WarehouseEmployeeRelationView(DataLayer::warehouseEmployeeViewCollection wCollection)
	{
		id = std::get<0>(wCollection);
		userName = std::get<1>(wCollection);
		userSurname = std::get<2>(wCollection);
		userPhone = std::get<3>(wCollection);
		roleName = std::get<4>(wCollection);
		warehouseName = std::get<5>(wCollection);
		subaccountNumber = std::get<6>(wCollection);
		warehouseID = std::get<7>(wCollection);
		employeeID = std::get<8>(wCollection);
	}

	std::string WarehouseEmployeeRelationView::GetUsername()
	{
		return userName;
	}
	std::string WarehouseEmployeeRelationView::GetUserSurname()
	{
		return userSurname;
	}
	std::string WarehouseEmployeeRelationView::GetUserPhone()
	{
		return userPhone;
	}
	std::string WarehouseEmployeeRelationView::GetRoleName()
	{
		return roleName;
	}
	std::string WarehouseEmployeeRelationView::GetWarehouseName()
	{
		return warehouseName;
	}
	std::string WarehouseEmployeeRelationView::GetSubaccountNumber()
	{
		return subaccountNumber;
	}
}