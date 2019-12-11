#include "stdafx.h"
#include "FixedAssetsDetailsClass.h"

namespace BusinessLayer
{
	FixedAssetsDetails::FixedAssetsDetails(DataLayer::fixedAssetsDetailsCollection fCollection)
	{
		id = std::get<0>(fCollection);
		amortizeGroupID = std::get<1>(fCollection);
		amortizeTypeID = std::get<2>(fCollection);
		departmentID = std::get<3>(fCollection);
		fixedAssetsLocation = std::get<4>(fCollection);
		primaryCostAccountID = std::get<5>(fCollection);
		amortizeAccountID = std::get<6>(fCollection);
		barcodeNumber = std::get<7>(fCollection);
	}

	int FixedAssetsDetails::GetID()
	{
		return id;
	}

	int FixedAssetsDetails::GetAmortizeGroupID()
	{
		return amortizeGroupID;
	}

	int FixedAssetsDetails::GetAmortizeTypeID()
	{
		return amortizeTypeID;
	}

	int FixedAssetsDetails::GetDepartmentID()
	{
		return departmentID;
	}

	std::string FixedAssetsDetails::GetFixedAssetsLocation()
	{
		return fixedAssetsLocation;
	}

	int FixedAssetsDetails::GetPrimaryCostAccountID()
	{
		return primaryCostAccountID;
	}

	int FixedAssetsDetails::GetAmortizeAccountID()
	{
		return amortizeAccountID;
	}

	std::string FixedAssetsDetails::GetBarcodeNumber()
	{
		return barcodeNumber;
	}

	void FixedAssetsDetails::SetID(int fID)
	{
		id = fID;
	}

	void FixedAssetsDetails::SetAmortizeGroupID(int agID)
	{
		amortizeGroupID = agID;
	}

	void FixedAssetsDetails::SetAmortizeTypeID(int atID)
	{
		amortizeTypeID = atID;
	}

	void FixedAssetsDetails::SetDepartmentID(int dID)
	{
		departmentID = dID;
	}

	void FixedAssetsDetails::SetFixedAssetsLocation(std::string location)
	{
		fixedAssetsLocation = location;
	}

	void FixedAssetsDetails::SetPrimaryCostAccountID(int paID)
	{
		primaryCostAccountID = paID;
	}

	void FixedAssetsDetails::SetAmortizeAccountID(int aaID)
	{
		amortizeAccountID = aaID;
	}

	void FixedAssetsDetails::SetBarcodeNumber(std::string bNumber)
	{
		barcodeNumber = bNumber;
	}

	bool FixedAssetsDetails::CreateFixedAssetsDetails(DataLayer::OrmasDal& ormasDal, int agID, int atID, int dID, std::string faLocation,
		int paID, int aaID, std::string bNumber, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, bNumber, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		amortizeGroupID = agID;
		amortizeTypeID = atID;
		departmentID = dID;
		fixedAssetsLocation = faLocation;
		primaryCostAccountID = paID;
		amortizeAccountID = aaID;
		barcodeNumber = bNumber;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateFixedAssetsDetails(id, amortizeGroupID, amortizeTypeID, departmentID, fixedAssetsLocation,
			primaryCostAccountID, amortizeAccountID, barcodeNumber, errorMessage))
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

	bool FixedAssetsDetails::CreateFixedAssetsDetails(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateFixedAssetsDetails(id, amortizeGroupID, amortizeTypeID, departmentID, fixedAssetsLocation,
			primaryCostAccountID, amortizeAccountID, barcodeNumber, errorMessage))
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
	bool FixedAssetsDetails::DeleteFixedAssetsDetails(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		//if (!ormasDal.StartTransaction(errorMessage))
		//	return false;
		if (ormasDal.DeleteFixedAssetsDetails(id, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool FixedAssetsDetails::UpdateFixedAssetsDetails(DataLayer::OrmasDal& ormasDal, int agID, int atID, int dID, std::string faLocation,
		int paID, int aaID, std::string bNumber, std::string& errorMessage)
	{
		amortizeGroupID = agID;
		amortizeTypeID = atID;
		departmentID = dID;
		fixedAssetsLocation = faLocation;
		primaryCostAccountID = paID;
		amortizeAccountID = aaID;
		barcodeNumber = bNumber;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateFixedAssetsDetails(id, amortizeGroupID, amortizeTypeID, departmentID, fixedAssetsLocation,
			primaryCostAccountID, amortizeAccountID, barcodeNumber, errorMessage))
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
	bool FixedAssetsDetails::UpdateFixedAssetsDetails(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateFixedAssetsDetails(id, amortizeGroupID, amortizeTypeID, departmentID, fixedAssetsLocation,
			primaryCostAccountID, amortizeAccountID, barcodeNumber, errorMessage))
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

	std::string FixedAssetsDetails::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != amortizeGroupID || !fixedAssetsLocation.empty() ||0 != amortizeTypeID || 0 != departmentID 
			|| !barcodeNumber.empty() || 0 != primaryCostAccountID || 0 != amortizeAccountID)
		{
			return ormasDal.GetFilterForFixedAssetsDetails(id, amortizeGroupID, amortizeTypeID, departmentID, fixedAssetsLocation,
				primaryCostAccountID, amortizeAccountID, barcodeNumber);
		}
		return "";
	}

	bool FixedAssetsDetails::GetFixedAssetsDetailsByID(DataLayer::OrmasDal& ormasDal, int fID, std::string& errorMessage)
	{
		if (fID <= 0)
			return false;
		id = fID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::fixedAssetsDetailsViewCollection> fixedAssetsDetailsVector = ormasDal.GetFixedAssetsDetails(errorMessage, filter);
		if (0 != fixedAssetsDetailsVector.size())
		{
			id = std::get<0>(fixedAssetsDetailsVector.at(0));
			amortizeGroupID = std::get<11>(fixedAssetsDetailsVector.at(0));
			amortizeTypeID = std::get<12>(fixedAssetsDetailsVector.at(0));
			departmentID = std::get<13>(fixedAssetsDetailsVector.at(0));
			fixedAssetsLocation = std::get<8>(fixedAssetsDetailsVector.at(0));
			primaryCostAccountID = std::get<9>(fixedAssetsDetailsVector.at(0));
			amortizeAccountID = std::get<10>(fixedAssetsDetailsVector.at(0));
			barcodeNumber = std::get<7>(fixedAssetsDetailsVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find fixed assets details with this id";
		}
		return false;
	}

	bool FixedAssetsDetails::IsEmpty()
	{
		if (0 == id && 0 == amortizeGroupID && 0 == amortizeTypeID && 0 == departmentID && fixedAssetsLocation == ""
			&& 0 == primaryCostAccountID && 0 == amortizeAccountID && barcodeNumber == "")
			return false;
		return true;
	}

	void FixedAssetsDetails::Clear()
	{
		id = 0;
		amortizeGroupID = 0;
		amortizeTypeID = 0;
		departmentID = 0;
		fixedAssetsLocation = "";
		primaryCostAccountID = 0;
		amortizeAccountID = 0;
		barcodeNumber = "";
	}

	bool FixedAssetsDetails::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string bNumber, std::string& errorMessage)
	{
		FixedAssetsDetails fixedAssetsDetails;
		fixedAssetsDetails.Clear();
		errorMessage.clear();
		fixedAssetsDetails.SetBarcodeNumber(bNumber);
		std::string filter = fixedAssetsDetails.GenerateFilter(ormasDal);
		std::vector<DataLayer::fixedAssetsDetailsViewCollection> fixedAssetsDetailsVector = ormasDal.GetFixedAssetsDetails(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == fixedAssetsDetailsVector.size())
		{
			return false;
		}
		errorMessage = "Fixed assets details with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool FixedAssetsDetails::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		FixedAssetsDetails fixedAssetsDetails;
		fixedAssetsDetails.Clear();
		errorMessage.clear();
		fixedAssetsDetails.SetBarcodeNumber(barcodeNumber);
		std::string filter = fixedAssetsDetails.GenerateFilter(ormasDal);
		std::vector<DataLayer::fixedAssetsDetailsViewCollection> fixedAssetsDetailsVector = ormasDal.GetFixedAssetsDetails(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == fixedAssetsDetailsVector.size())
		{
			return false;
		}
		errorMessage = "Fixed assets details with these parameters are already exist! Please avoid the duplication!";
		return true;
	}
}
