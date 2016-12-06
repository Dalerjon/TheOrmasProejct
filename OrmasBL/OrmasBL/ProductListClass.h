#ifndef PRODUCTLISTCLASS_H
#define PRODUCTLISTCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class ProductList
	{
		int id = 0;
		int orderID = 0;
		int returnID = 0;
		int productID = 0;
		int count = 0;
	public:
		ProductList(int pListID, int oID, int rID, int pID, int count):id(pListID), orderID(oID), returnID(rID),
			productID(pID), count(count){};
		ProductList(DataLayer::productListCollection);
		ProductList(){};
		~ProductList(){};
		
		//ProductList class Accessors
		int GetID();
		int GetOrderID();
		int GetReturnID();
		int GetProductID();
		int GetCount();

		//Please implement Mutators
		void SetID(int);
		void SetOrderID(int);
		void SetReturnID(int);
		void SetProductID(int);
		void SetCount(int);
		
		//Create, delete, update methods
		bool CreateProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateProductList(DataLayer::OrmasDal& ormasDal, int oID, int rID, int pID, int pCount, std::string& errorMessage);
		bool UpdateProductList(DataLayer::OrmasDal& ormasDal, int oID, int rID, int pID, int pCount, std::string& errorMessage);
	};
}
#endif //PRODUCTLISTCLASS_H