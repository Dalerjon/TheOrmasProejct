#ifndef PRODUCTCLASS_H
#define PRODUCTCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Product
	{
		int id=0;
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
			std::string dProduce, std::string dEnd) :id(pID), companyID(cID), name(pName), volume(vol), measureID(mID),
			price(price), productTypeID(pTypeID), dateProduce(dProduce), dateEnd(dEnd){};
		Product(DataLayer::productsCollection);
		Product(){};
		~Product(){};
		
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
		void GetID(int);
		void GetCompanyID(int);
		void GetName(std::string);
		void GetVolume(float);
		void GetMeasureID(int);
		void GetPrice(float);
		void GetProductTypeID(int);
		void GetProduceDate(std::string);
		void GetEndDate(std::string);

		//Create, delete, update methods
		bool CreateProduct(DataLayer::OrmasDal& ormasDal, int cID, std::string pName, float vol, int mID, float price, 
			int pTypeID,std::string dProduce, std::string dEnd);
		bool DeleteProduct(DataLayer::OrmasDal& ormasDal);
		bool UpdateProduct(DataLayer::OrmasDal& ormasDal, int cID, std::string pName, float vol, int mID, float price,
			int pTypeID, std::string dProduce, std::string dEnd);
	};
}
#endif //PRODUCTCLASS_H