#include "stdafx.h"
#include "InventoryClass.h"

namespace BusinessLayer
{
	Inventory::Inventory(DataLayer::inventoryCollection iCollection)
	{
		id = std::get<0>(iCollection);
		name = std::get<1>(iCollection);
		cost = std::get<2>(iCollection);
		departmentID = std::get<3>(iCollection);
		location = std::get<4>(iCollection);
		statusID = std::get<5>(iCollection);
		startOfOperationDate = std::get<6>(iCollection);
		endOfOperationDate = std::get<7>(iCollection);
		inventoryNumber = std::get<8>(iCollection);
		barcodeNumber = std::get<9>(iCollection);
	}

	int Inventory::GetID()
	{
		return id;
	}

	std::string Inventory::GetName()
	{
		return name;
	}

	double Inventory::GetCost()
	{
		return cost;
	}

	int Inventory::GetDepartmentID()
	{
		return departmentID;
	}

	std::string Inventory::GetLocation()
	{
		return location;
	}

	int Inventory::GetStatusID()
	{
		return statusID;
	}

	std::string Inventory::GetStartOfOperationDate()
	{
		return startOfOperationDate;
	}
	
	std::string Inventory::GetEndOfOperationDate()
	{
		return endOfOperationDate;
	}

	std::string Inventory::GetInventoryNumber()
	{
		return inventoryNumber;
	}
	
	std::string Inventory::GetBarcodeNumber()
	{
		return barcodeNumber;
	}

	void Inventory::SetID(int iID)
	{
		id = iID;
	}

	void Inventory::SetName(std::string iName)
	{
		name = iName;
	}

	void Inventory::SetCost(double iCost)
	{
		cost = iCost;
	}

	void Inventory::SetDepartmentID(int iDepID)
	{
		departmentID = iDepID;
	}

	void Inventory::SetLocation(std::string iLocation)
	{
		location = iLocation;
	}

	void Inventory::SetStatusID(int statID)
	{
		statusID = statID;
	}

	void Inventory::SetStartOfOperationDate(std::string sooDate)
	{
		startOfOperationDate = sooDate;
	}

	void Inventory::SetEndOfOperationDate(std::string eooDate)
	{
		endOfOperationDate = eooDate;
	}

	void Inventory::SetInventoryNumber(std::string iNumber)
	{
		inventoryNumber = iNumber;
	}

	void Inventory::SetBarcodeNumber(std::string bNumber)
	{
		barcodeNumber = bNumber;
	}

	bool Inventory::CreateInventory(DataLayer::OrmasDal& ormasDal, std::string iName, double iCost, int depID, std::string iLocation, 
		int sID, std::string sooDate, std::string eooDate, std::string iNumber, std::string bNumber, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, iName, iNumber, bNumber, iCost, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		name = iName;
		cost = iCost;
		departmentID = depID;
		location = iLocation;
		statusID = sID;
		startOfOperationDate = sooDate;
		endOfOperationDate = eooDate;
		inventoryNumber = iNumber;
		barcodeNumber = bNumber;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateInventory(id, name, cost, departmentID, location, statusID, startOfOperationDate,
			endOfOperationDate, inventoryNumber, barcodeNumber, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	bool Inventory::CreateInventory(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateInventory(id, name, cost, departmentID, location, statusID, startOfOperationDate,
			endOfOperationDate, inventoryNumber, barcodeNumber, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Inventory::DeleteInventory(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		//if (!ormasDal.StartTransaction(errorMessage))
		//	return false;
		if (ormasDal.DeleteFixedAssetsOperation(id, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Inventory::UpdateInventory(DataLayer::OrmasDal& ormasDal, std::string iName, double iCost, int depID, std::string iLocation, 
		int sID, std::string sooDate, std::string eooDate, std::string iNumber, std::string bNumber, std::string& errorMessage)
	{
		name = iName;
		cost = iCost;
		departmentID = depID;
		location = iLocation;
		statusID = sID;
		startOfOperationDate = sooDate;
		endOfOperationDate = eooDate;
		inventoryNumber = iNumber;
		barcodeNumber = bNumber;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateInventory(id, name, cost, departmentID, location, statusID, startOfOperationDate,
			endOfOperationDate, inventoryNumber, barcodeNumber, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Inventory::UpdateInventory(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateInventory(id, name, cost, departmentID, location, statusID, startOfOperationDate,
			endOfOperationDate, inventoryNumber, barcodeNumber, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	std::string Inventory::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !name.empty() || 0 != cost || 0 != departmentID || !location.empty() || 0 != statusID || !startOfOperationDate.empty()
			|| !endOfOperationDate.empty() || !inventoryNumber.empty() || !barcodeNumber.empty())
		{
			return ormasDal.GetFilterForInventory(id, name, cost, departmentID, location, statusID, startOfOperationDate,
				endOfOperationDate, inventoryNumber, barcodeNumber);
		}
		return "";
	}

	bool Inventory::GetInventoryByID(DataLayer::OrmasDal& ormasDal, int iID, std::string& errorMessage)
	{
		if (iID <= 0)
			return false;
		id = iID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::inventoryViewCollection> inventoryVector = ormasDal.GetInventory(errorMessage, filter);
		if (0 != inventoryVector.size())
		{
			id = std::get<0>(inventoryVector.at(0));
			name = std::get<1>(inventoryVector.at(0));
			cost = std::get<2>(inventoryVector.at(0));
			departmentID = std::get<11>(inventoryVector.at(0));
			location = std::get<7>(inventoryVector.at(0));
			statusID = std::get<10>(inventoryVector.at(0));
			startOfOperationDate = std::get<8>(inventoryVector.at(0));
			endOfOperationDate = std::get<9>(inventoryVector.at(0));
			inventoryNumber = std::get<3>(inventoryVector.at(0));
			barcodeNumber = std::get<4>(inventoryVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find inventry with this id";
		}
		return false;
	}

	bool Inventory::IsEmpty()
	{
		if (0 == id && name == "" && 0.0 == cost && 0 == departmentID && location == "" && 0 == statusID
			&& startOfOperationDate == "" && endOfOperationDate == "" && inventoryNumber == "" && barcodeNumber == "")
			return false;
		return true;
	}

	void Inventory::Clear()
	{
		id = 0;
		name = "";
		cost = 0.0;
		departmentID = 0;
		location = "";
		statusID = 0;
		startOfOperationDate = "";
		endOfOperationDate = "";
		inventoryNumber = "";
		barcodeNumber = "";
	}

	bool Inventory::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string iName, std::string iNumber, std::string bNumber, double iCost, std::string& errorMessage)
	{
		Inventory inventory;
		inventory.Clear();
		errorMessage.clear();
		inventory.SetName(iName);
		inventory.SetInventoryNumber(iNumber);
		inventory.SetBarcodeNumber(bNumber);
		inventory.SetCost(iCost);
		std::string filter = inventory.GenerateFilter(ormasDal);
		std::vector<DataLayer::inventoryViewCollection> inventoryVector = ormasDal.GetInventory(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == inventoryVector.size())
		{
			return false;
		}
		errorMessage = "inventory with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Inventory::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Inventory inventory;
		inventory.Clear();
		errorMessage.clear();
		inventory.SetName(name);
		inventory.SetInventoryNumber(inventoryNumber);
		inventory.SetBarcodeNumber(barcodeNumber);
		inventory.SetCost(cost);
		std::string filter = inventory.GenerateFilter(ormasDal);
		std::vector<DataLayer::inventoryViewCollection> inventoryVector = ormasDal.GetInventory(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == inventoryVector.size())
		{
			return false;
		}
		errorMessage = "inventory with these parameters are already exist! Please avoid the duplication!";
		return true;
	}
}
