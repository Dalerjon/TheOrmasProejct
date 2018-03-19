#ifndef SPECIFICATIONLISTCLASS_H
#define SPECIFICATIONLISTCLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer
{
	class SpecificationList
	{
	protected:
		int id = 0;
		int specificationID = 0;
		int productID = 0;
		double count = 0;
	public:
		SpecificationList(int slID, int sID, int pID, double slCount) :id(slID), specificationID(sID), productID(pID), count(slCount){};
		SpecificationList(DataLayer::specificationListCollection);
		SpecificationList(){};
		~SpecificationList(){};

		//SpecificationList class Accessors
		int GetID();
		int GetSpecificationID();
		int GetProductID();
		double GetCount();

		//SpecificationList class Mutators
		void SetID(int);
		void SetSpecificationID(int);
		void SetProductID(int);
		void SetCount(double);
	
		//Create, delete, update methods
		bool CreateSpecificationList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateSpecificationList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteSpecificationList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteListBySpecificationID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage);
		bool CreateSpecificationList(DataLayer::OrmasDal& ormasDal, int sID, int pID, double slCount, std::string& errorMessage);
		bool UpdateSpecificationList(DataLayer::OrmasDal& ormasDal, int sID, int pID, double slCount, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetSpecificationListByID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int sID, int pID, double slCount, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif