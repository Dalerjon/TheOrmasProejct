#ifndef WAREHOUSEEMPLOYEERELATIONCLASS_H
#define WAREHOUSEEMPLOYEERELATIONCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class WarehouseEmployeeRelation
	{
	protected:
		int id = 0;
		int warehouseID = 0;
		int employeeID = 0;
	public:
		WarehouseEmployeeRelation();
		WarehouseEmployeeRelation(int weID, int wID, int eID) :id(weID), warehouseID(wID), employeeID(eID){};
		WarehouseEmployeeRelation(DataLayer::warehouseEmployeeCollection);
		~WarehouseEmployeeRelation(){};

		std::string errorMessage = "";
		//Warehouse-Employee relation class Accessors
		int GetID();
		int GetWarehouseID();
		int GetEmployeeID();

		//Warehouse-Employee relation  class Mutators
		void SetID(int);
		void SetWarehouseID(int);
		void SetEmployeeID(int);

		// Create, delete  Warehouse-Employee relation
		bool CreateWarehouseEmployeeRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteWarehouseEmployeeRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateWarehouseEmployeeRelation(DataLayer::OrmasDal &ormasDal, int wID, int eID, std::string& errorMessage);
		bool UpdateWarehouseEmployeeRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateWarehouseEmployeeRelation(DataLayer::OrmasDal &ormasDal, int wID, int eID, std::string& errorMessage);


		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetWarehouseEmployeeByID(DataLayer::OrmasDal& ormasDal, int id, std::string& errorMessage);
		bool GetWarehouseEmployeeByEmployeeID(DataLayer::OrmasDal& ormasDal, int eID, std::string& errorMessage);
		bool GetWarehouseEmployeeByWarehouseID(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		int GetWarehouseIDByEmployeeID(DataLayer::OrmasDal& ormasDal, int eID, std::string& errorMessage);
		int GetEmployeeIDByWarehouseID(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int wID, int eID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif