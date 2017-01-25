#ifndef PRODUCTVIEWCLASS_H
#define PRODUCTVIEWCLASS_H
#include "ProductClass.h"

namespace BusinessLayer
{
	class ProductView : public Product
	{
		std::string companyName = "";
		std::string currencyName = "";
		std::string measureName = "";
		std::string productTypeName = "";
	public:
		ProductView(int pID, int cID, std::string pName, float vol, int mID, float price, int pTypeID, int pShelfLife, int curID,
			std::string pCompanyName, std::string pCurrencyName, std::string pMeasureName, std::string pProductTypeName) :
			Product(pID, cID, pName, vol, mID, price, pTypeID, pShelfLife, curID),
			companyName(pCompanyName), currencyName(pCurrencyName), measureName(pMeasureName), productTypeName(pProductTypeName){};
		ProductView(DataLayer::productsViewCollection);
		ProductView(){};
		~ProductView(){};

		//UserView class Accessors
		std::string GetCompanyName();
		std::string GetMeasureName();
		std::string GetProductTypeName();
		std::string GetCurrencyName();

		//UserView class Mutators
		void SetCompanyName(std::string);
		void SetMeasureName(std::string);
		void SetProductTypeName(std::string);
		void SetCurrencyName(std::string currencyName);
	};
}
#endif //PRODUCTVIEWCLASS_H