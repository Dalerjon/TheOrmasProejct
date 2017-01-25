#ifndef PRODUCTLISTVIEWCLASS_H
#define PRODUCTLISTVIEWCLASS_H
#include "ProductListClass.h"

namespace BusinessLayer
{
	class ProductListView : public ProductList
	{
		std::string productName = "";
		double price = 0;
		std::string currencyName = "";
		double volume = 0;
		std::string statusName = "";
		std::string sumCurrencyName = "";
		std::string measureName;
	public:
		ProductListView(int pListID, int oID, int rID, int pnID, std::string pProductName, double pPrice, std::string pCurrencyName, 
			double pVolume, std::string pMeasureName, int pCount, double pSum, std::string pStatusName, std::string pSumCurrencyName, 
			int pID, int sID, int cID) : ProductList(pListID, oID, rID, pnID, pID, pCount, pSum, sID, cID),
			productName(pProductName), price(pPrice), currencyName(pCurrencyName), volume(pVolume), statusName(pStatusName), 
			sumCurrencyName(pSumCurrencyName), measureName(pMeasureName){};
		ProductListView(DataLayer::productListViewCollection);
		ProductListView(){};
		~ProductListView(){};

		//ProductListView class Accessors
		std::string GetProductName();
		double GetPrice();
		std::string GetCurrencyName();
		double GetVolume();
		std::string GetStatusName();
		std::string GetSumCurrencyName();
		std::string GetMeasureName();

		//ProductListView class Mutators
		void SetProductName(std::string);
		void SetPrice(double);
		void SetCurrencyName(std::string);
		void SetVolume(double);
		void SetStatusName(std::string);
		void SetSumCurrencyName(std::string);
		void SetMeasureName(std::string);
	};
}
#endif //PRODUCTLISTVIEWCLASS_H