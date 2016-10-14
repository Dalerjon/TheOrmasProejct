#ifndef PRODUCTTYPECLASS_H
#define PRODUCTTYPECLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class ProductType
	{
		int ID;
		std::string name;
		std::string shortName;
	public:
		ProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName):ID(pTypeID),
			name(pTypeName), shortName(pTypeShortName){};
		ProductType(DataLayer::productTypeCollection);
		ProductType(){};
		~ProductType(){};
		int CreateProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName){};

		//ProductType class Accessors
		int GetID();
		std::string GetName();
		std::string GetShortName();

		//Please implement Muttators
	};
}
#endif //PRODUCTTYPECLASS_H