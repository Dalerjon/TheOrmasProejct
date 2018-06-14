#ifndef PRICECLASS_H
#define PRICECLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Price{
	protected:
		int id = 0;
		std::string date = "";
		double value = 0.0;
		int currencyID = 0;
		int productID = 0;
		bool isOutdated = true;
	public:
		Price();
		Price(int pID, std::string pDate, double pValue, int cID, int prID, bool pIsOutdated) :id(pID), date(pDate), value(pValue), 
			currencyID(cID), productID(prID), isOutdated(pIsOutdated){};
		Price(DataLayer::pricesCollection);
		~Price(){};

		std::string errorMessage = "";
		//Price class Priceors
		int GetID();
		std::string GetDate();
		double GetValue();
		int GetCurrencyID();
		int GetProductID();
		bool GetIsOutdated();

		//Price class Mutators
		void SetID(int);
		void SetDate(std::string);
		void SetValue(double);
		void SetCurrencyID(int);
		void SetProductID(int);
		void SetIsOutdated(bool);

		// Create, delete and update Price
		bool CreatePrice(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdatePrice(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeletePrice(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreatePrice(DataLayer::OrmasDal &ormasDal, std::string pDate, double pValue, int cID, int prID,
			bool pIsOutdated, std::string& errorMessage);
		bool UpdatePrice(DataLayer::OrmasDal &ormasDal, std::string pDate, double pValue, int cID, int prID,
			bool pIsOutdated, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetPriceByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool GetPriceByProductID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string pDate, double pValue, int cID, int prID,
			std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}

#endif //PRICECLASS_H