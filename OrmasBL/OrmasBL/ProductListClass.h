#ifndef PRODUCTLISTCLASS_H
#define PRODUCTLISTCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class ProductList
	{
		int id;
		int orderID;
		int returnID;
		int productID;
		int count;
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
		bool CreateProductList(DataLayer::OrmasDal& ormasDal, int oID, int rID, int pID, int pCount);
		bool DeleteProductList(DataLayer::OrmasDal& ormasDal);
		bool UpdateProductList(DataLayer::OrmasDal& ormasDal, int oID, int rID, int pID, int pCount);
		
	};
}
#endif //PRODUCTLISTCLASS_H