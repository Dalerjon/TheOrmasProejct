#ifndef PRODUCTCLASS_H
#define PRODUCTCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Product
	{
		int id = 0;
		int companyID = 0;
		std::string name = "";
		float volume = 0;
		int measureID = 0;
		float price = 0;
		int productTypeID = 0;
		int shelfLife = 0;
	public:
		Product(int pID, int cID, std::string pName, float vol, int mID, float price, int pTypeID, int pShelfLife) :id(pID), companyID(cID), name(pName), volume(vol), measureID(mID),
			price(price), productTypeID(pTypeID), shelfLife(pShelfLife){};
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
		int GetShelfLife();

		//Please implement Mutators
		void SetID(int);
		void SetCompanyID(int);
		void SetName(std::string);
		void SetVolume(float);
		void SetMeasureID(int);
		void SetPrice(float);
		void SetProductTypeID(int);
		void SetShelfLife(int);

		//Create, delete, update methods
		bool CreateProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteProduct(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateProduct(DataLayer::OrmasDal& ormasDal, int cID, std::string pName, float vol, int mID, float price,
			int pTypeID, int shelfLife, std::string& errorMessage);
		bool UpdateProduct(DataLayer::OrmasDal& ormasDal, int cID, std::string pName, float vol, int mID, float price,
			int pTypeID, int shelfLife, std::string& errorMessage);
	};
}
#endif //PRODUCTCLASS_H