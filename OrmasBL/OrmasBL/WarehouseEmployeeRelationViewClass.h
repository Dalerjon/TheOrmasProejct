#ifndef WAREHOUSEEMPLOYEERELATIONVIEWCLASS_H
#define WAREHOUSEEMPLOYEERELATIONVIEWCLASS_H

#include "WarehouseEmployeeRelationClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class WarehouseEmployeeRelationView : public WarehouseEmployeeRelation
	{
		std::string userName = "";
		std::string userSurname = "";
		std::string userPhone = "";
		std::string roleName = "";
		std::string warehouseName = "";
		std::string subaccountNumber = "";
	public:
		WarehouseEmployeeRelationView(DataLayer::warehouseEmployeeViewCollection);
		WarehouseEmployeeRelationView(){};
		~WarehouseEmployeeRelationView(){};

		// WarehouseEmployeeRelationView class WarehouseEmployeeRelationors
		std::string GetUsername();
		std::string GetUserSurname();
		std::string GetUserPhone();
		std::string GetRoleName();
		std::string GetWarehouseName();
		std::string GetSubaccountNumber();
	};
}
#endif