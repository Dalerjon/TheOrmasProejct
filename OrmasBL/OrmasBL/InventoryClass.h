#ifndef INVENTORYCLASS_H
#define INVENTORYCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class Inventory
	{
	protected:
		int id = 0;
		std::string name = "";
		double cost = 0.0;
		int departmentID = 0;
		std::string location = "";
		int statusID = 0;
		std::string startOfOperationDate = "";
		std::string endOfOperationDate = "";
		std::string inventoryNumber = "";
		std::string barcodeNumber = "";
	public:
		Inventory(int iID, std::string iName, double iCost, int depID, std::string iLocation, int sID, std::string sooDate,
			std::string eooDate, std::string iNumber, std::string bNumber) : id(iID), name(iName), cost(iCost), departmentID(depID),
			location(iLocation), statusID(sID), startOfOperationDate(sooDate), endOfOperationDate(eooDate), inventoryNumber(iNumber),
			barcodeNumber(bNumber){};
		Inventory(DataLayer::inventoryCollection);
		Inventory(){};
		~Inventory(){};

		//Consume Product class Accessors
		int GetID();
		std::string GetName();
		double GetCost();
		int GetDepartmentID();
		std::string GetLocation();
		int GetStatusID();
		std::string GetStartOfOperationDate();
		std::string GetEndOfOperationDate();
		std::string GetInventoryNumber();
		std::string GetBarcodeNumber();

		//Consume Product class Mutators
		void SetID(int);
		void SetName(std::string);
		void SetCost(double);
		void SetDepartmentID(int);
		void SetLocation(std::string);
		void SetStatusID(int);
		void SetStartOfOperationDate(std::string);
		void SetEndOfOperationDate(std::string);
		void SetInventoryNumber(std::string);
		void SetBarcodeNumber(std::string);

		//Create, delete, update methods
		bool CreateInventory(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateInventory(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteInventory(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateInventory(DataLayer::OrmasDal& ormasDal, std::string iName, double iCost, int depID, std::string iLocation, int sID, std::string sooDate,
			std::string eooDate, std::string iNumber, std::string bNumber, std::string& errorMessage);
		bool UpdateInventory(DataLayer::OrmasDal& ormasDal, std::string iName, double iCost, int depID, std::string iLocation, int sID, std::string sooDate,
			std::string eooDate, std::string iNumber, std::string bNumber, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetInventoryByID(DataLayer::OrmasDal& ormasDal, int iID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string iName, std::string iNumber, std::string bNumber, double iCost, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //InventoryCLASS_H