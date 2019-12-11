#ifndef FIXEDASSETSDETAILSCLASS_H
#define FIXEDASSETSDETAILSCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class FixedAssetsDetails
	{
	protected:
		int id = 0;
		int amortizeGroupID = 0;
		int amortizeTypeID = 0;
		int departmentID = 0;
		std::string fixedAssetsLocation = "";
		int primaryCostAccountID = 0;
		int amortizeAccountID = 0;
		std::string barcodeNumber = "";
	public:
		FixedAssetsDetails(int fID, int agID, int atID, int dID, std::string faLocation, int paID, int aaID, std::string bCode) : id(fID),
			amortizeGroupID(agID), amortizeTypeID(atID), departmentID(dID), fixedAssetsLocation(faLocation), primaryCostAccountID(paID),
			amortizeAccountID(aaID), barcodeNumber(bCode){};
		FixedAssetsDetails(DataLayer::fixedAssetsDetailsCollection);
		FixedAssetsDetails(){};
		~FixedAssetsDetails(){};

		//Consume Product class Accessors
		int GetID();
		int GetAmortizeGroupID();
		int GetAmortizeTypeID();
		int GetDepartmentID();
		std::string GetFixedAssetsLocation();
		int GetPrimaryCostAccountID();
		int GetAmortizeAccountID();
		std::string GetBarcodeNumber();

		//Consume Product class Mutators
		void SetID(int);
		void SetAmortizeGroupID(int);
		void SetAmortizeTypeID(int);
		void SetDepartmentID(int);
		void SetFixedAssetsLocation(std::string);
		void SetPrimaryCostAccountID(int);
		void SetAmortizeAccountID(int);
		void SetBarcodeNumber(std::string);

		//Create, delete, update methods
		bool CreateFixedAssetsDetails(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateFixedAssetsDetails(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteFixedAssetsDetails(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateFixedAssetsDetails(DataLayer::OrmasDal& ormasDal, int agID, int atID, int dID, std::string faLocation,
			int paID, int aaID, std::string bNumber, std::string& errorMessage);
		bool UpdateFixedAssetsDetails(DataLayer::OrmasDal& ormasDal, int agID, int atID, int dID, std::string faLocation,
			int paID, int aaID, std::string bNumber, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetFixedAssetsDetailsByID(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string bNumber, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //FixedAssetsDetailsCLASS_H