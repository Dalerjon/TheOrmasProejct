#ifndef PRODUCTLISTCLASS_H
#define PRODUCTLISTCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class ProductList
	{
		int ID;
		int orderID;
		int returnID;
		int productID;
		int count;
	public:
		ProductList(int pListID, int oID, int rID, int pID, int count):ID(pListID), orderID(oID), returnID(rID),
			productID(pID), count(count){};
		ProductList(DataLayer::productListCollection);
		ProductList(){};
		~ProductList(){};
		int CreateProductList(int pListID, int oID, int rID, int pID, int count){};

		//ProductList class Accessors
		int GetID();
		int GetOrderID();
		int GetReturnID();
		int GetProductID();
		int GetCount();

		//Please implement Mutators
	};
}
#endif //PRODUCTLISTCLASS_H