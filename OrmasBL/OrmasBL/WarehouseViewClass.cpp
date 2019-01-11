#include "stdafx.h"
#include "WarehouseViewClass.h"

namespace BusinessLayer{
	WarehouseView::WarehouseView(DataLayer::warehouseViewCollection wCollection)
	{
		id = std::get<0>(wCollection);
		name = std::get<1>(wCollection);
		subaccountNumber = std::get<2>(wCollection);
		warehouseTypeName = std::get<3>(wCollection);
		address = std::get<4>(wCollection);
		phone = std::get<5>(wCollection);
		warehouseTypeID = std::get<6>(wCollection);
		subaccountID = std::get<7>(wCollection);
	}

	std::string WarehouseView::GetWarehouseTypeName()
	{
		return warehouseTypeName;
	}

	std::string WarehouseView::GetSubaccountNumber()
	{
		return subaccountNumber;
	}
}