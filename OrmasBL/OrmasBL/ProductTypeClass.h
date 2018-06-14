#ifndef PRODUCTTYPECLASS_H
#define PRODUCTTYPECLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class ProductType
	{
		int id = 0;
		std::string name = "";
		std::string shortName = "";
		std::string code = "";
	public:
		ProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName, std::string pTypeCode) :id(pTypeID),
			name(pTypeName), shortName(pTypeShortName), code(pTypeCode){};
		ProductType(DataLayer::productTypeCollection);
		ProductType(){};
		~ProductType(){};
		
		//ProductType class Accessors
		int GetID();
		std::string GetName();
		std::string GetShortName();
		std::string GetCode();

		//Please implement Muttators
		void SetID(int);
		void SetName(std::string);
		void SetShortName(std::string);
		void SetCode(std::string);
		
		//Create, delete, update methods
		bool CreateProductType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateProductType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteProductType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateProductType(DataLayer::OrmasDal& ormasDal, std::string pTypeName, std::string pTypeShortName, std::string pTypeCode,
			std::string& errorMessage);
		bool UpdateProductType(DataLayer::OrmasDal& ormasDal, std::string pTypeName, std::string pTypeShortName, std::string pTypeCode,
			std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetProductTypeByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		void TrimStrings(std::string&, std::string&, std::string&);
		bool IsDuplicate(DataLayer::OrmasDal&, std::string pTypeName, std::string pTypeShortName, std::string pCode, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //PRODUCTTYPECLASS_H