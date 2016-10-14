#ifndef PRODUCTCLASS_H
#define PRODUCTCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Product
	{
		int ID;
		int companyID;
		std::string name;
		float volume;
		int measureID;
		float price;
		int productTypeID;
		std::string dateProduce;
		std::string dateEnd;
	public:
		Product(int pID, int cID, std::string pName, float vol, int mID, float price, int pTypeID,
			std::string dProduce, std::string dEnd) :ID(pID), companyID(cID), name(pName), volume(vol), measureID(mID),
			price(price), productTypeID(pTypeID), dateProduce(dProduce), dateEnd(dEnd){};
		Product(DataLayer::productsCollection);
		Product(){};
		~Product(){};
		int CreateProduct(int pID, int cID, std::string pName, float vol, int mID, float price, int pTypeID,
			std::string dProduce, std::string dEnd){};

		//Product class Accessors
		int GetID();
		int GetCompanyID();
		std::string GetName();
		float GetVolume();
		int GetMeasureID();
		float GetPrice();
		int GetProductTypeID();
		std::string GetProduceDate();
		std::string GetEndDate();

		//Please implement Mutators
	};
}
#endif //PRODUCTCLASS_H