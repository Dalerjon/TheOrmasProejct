#ifndef PRODUCTLISTCLASS_H
#define PRODUCTLISTCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class ProductList
	{
	protected:
		int id = 0;
		int orderID = 0;
		int returnID = 0;
		int productionID = 0;
		int productID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		ProductList(int pListID, int oID, int rID, int pnID, int pID, int pCount, double pSum, int sID, int cID):id(pListID), 
			orderID(oID), returnID(rID), productionID(pnID),productID(pID), count(pCount), statusID(sID), currencyID(cID){};
		ProductList(DataLayer::productListCollection);
		ProductList(){};
		~ProductList(){};
		
		//ProductList class Accessors
		int GetID();
		int GetOrderID();
		int GetReturnID();
		int GetProductionID();
		int GetProductID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//Please implement Mutators
		void SetID(int);
		void SetOrderID(int);
		void SetReturnID(int);
		void SetProductionID(int);
		void SetProductID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);
		
		//Create, delete, update methods
		bool CreateProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateProductList(DataLayer::OrmasDal& ormasDal, int oID, int rID, int pnID, int pID, int pCount, double pSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateProductList(DataLayer::OrmasDal& ormasDal, int oID, int rID, int pnID, int pID, int pCount, double pSum,
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetProductListByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty();
	};
}
#endif //PRODUCTLISTCLASS_H