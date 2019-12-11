#ifndef INVENTORYVIEWCLASS_H
#define INVENTORYVIEWCLASS_H

#include "InventoryClass.h"

namespace BusinessLayer{
	class InventoryView : public Inventory
	{
		std::string divisionName = "";
		std::string statusName = "";
	public:
		InventoryView(DataLayer::inventoryViewCollection);
		InventoryView(){};
		~InventoryView(){};

		// InventoryView class Accessors
		std::string GetDivisionName();
		std::string GetStatusName();
	};
}

#endif //InventoryVIEWCLASS_H