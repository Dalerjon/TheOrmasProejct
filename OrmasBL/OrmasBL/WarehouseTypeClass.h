#ifndef WAREHOUSETYPECLASS_H
#define WAREHOUSETYPECLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer{
	class WarehouseType
	{
		int id = 0;
		std::string code = "";
		std::string purpose = "";
		std::string name = "";
	public:
		WarehouseType();
		WarehouseType(int wtID, std::string wtCode, std::string wtPurpose, std::string wtName) :id(wtID),
			code(wtCode), purpose(wtPurpose), name(wtName){};
		WarehouseType(DataLayer::warehouseTypeCollection);
		~WarehouseType(){};

		std::string errorMessage = "";
		//WarehouseType class Accessors
		int GetID();
		std::string GetCode();
		std::string GetPurpose();
		std::string GetName();
	
		//WarehouseType class Mutators
		void SetID(int);
		void SetCode(std::string);
		void SetPurpose(std::string);
		void SetName(std::string);

		// Create, delete and update WarehouseType
		bool CreateWarehouseType(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateWarehouseType(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteWarehouseType(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateWarehouseType(DataLayer::OrmasDal &ormasDal, std::string wtCode, std::string wtPurpose, std::string wtName, std::string& errorMessage);
		bool UpdateWarehouseType(DataLayer::OrmasDal &ormasDal, std::string wtCode, std::string wtPurpose, std::string wtName, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetWarehouseTypeByID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage);
		bool GetWarehouseTypeByCode(DataLayer::OrmasDal& ormasDal, std::string wtCode, std::string& errorMessage);
		int GetWarehouseTypeID(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
		static std::map<std::string, int> GetWarehouseTypesAsMap(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	private:
		void TrimStrings(std::string&, std::string&, std::string&);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string cName, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //WarehouseTypeCLASS_H