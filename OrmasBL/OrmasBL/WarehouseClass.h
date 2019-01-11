#ifndef WAREHOUSECLASS_H
#define WAREHOUSECLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Warehouse
	{
	protected:
		int id = 0;
		std::string name = "";
		std::string address = "";
		std::string phone = "";
		int warehouseTypeID = 0;
		int subaccountID = 0;
	public:
		Warehouse();
		Warehouse(int wID, std::string wName, std::string wAddress, std::string wPhone, int wTypeID, int subaccID) :id(wID),
			name(wName), address(wAddress), phone(wPhone), warehouseTypeID(wTypeID), subaccountID(subaccID){};
		Warehouse(DataLayer::warehouseCollection);
		~Warehouse(){};

		std::string errorMessage = "";
		//Warehouse class Accessors
		int GetID();
		std::string GetName();
		std::string GetAddress();
		std::string GetPhone();
		int GetWarehouseTypeID();
		int GetSubaccountID();

		//Warehouse class Mutators
		void SetID(int);
		void SetName(std::string);
		void SetAddress(std::string);
		void SetPhone(std::string);
		void SetWarehouseTypeID(int);
		void SetSubaccountID(int);

		// Create, delete and update Warehouse
		bool CreateWarehouse(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateWarehouse(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteWarehouse(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateWarehouse(DataLayer::OrmasDal &ormasDal, std::string wName, std::string wAddress, std::string wPhone, 
				int wTypeID, int subaccID, std::string& errorMessage);
		bool UpdateWarehouse(DataLayer::OrmasDal &ormasDal, std::string wName, std::string wAddress, std::string wPhone,
			    int wTypeID, int subaccID, std::string& errorMessage);
		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetWarehouseByID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage);
		int GetWarehouseID(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		void TrimStrings(std::string&, std::string&, std::string&);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int subaccID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //WarehouseCLASS_H