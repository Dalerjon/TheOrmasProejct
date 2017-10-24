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
		ProductView(DataLayer::productsViewCollection);
		ProductView(){};
		~ProductView(){};

		//UserView class Accessors
		std::string GetCompanyName();
		std::string GetMeasureName();
		std::string GetProductTypeName();
		std::string GetCurrencyName();


	};
}
#endif //PRODUCTVIEWCLASS_H