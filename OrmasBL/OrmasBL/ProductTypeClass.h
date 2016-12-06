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
	public:
		ProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName):id(pTypeID),
			name(pTypeName), shortName(pTypeShortName){};
		ProductType(DataLayer::productTypeCollection);
		ProductType(){};
		~ProductType(){};
		
		//ProductType class Accessors
		int GetID();
		std::string GetName();
		std::string GetShortName();

		//Please implement Muttators
		void SetID(int);
		void SetName(std::string);
		void SetShortName(std::string);
		
		//Create, delete, update methods
		bool CreateProductType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateProductType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteProductType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateProductType(DataLayer::OrmasDal& ormasDal, std::string pTypeName, std::string pTypeShortName, 
			std::string& errorMessage);
		bool UpdateProductType(DataLayer::OrmasDal& ormasDal, std::string pTypeName, std::string pTypeShortName, 
			std::string& errorMessage);
	};
}
#endif //PRODUCTTYPECLASS_H