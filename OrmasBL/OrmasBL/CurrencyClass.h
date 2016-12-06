#ifndef CURRENCYCLASS_H
#define CURRENCYCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Currency
	{
		int id = 0;
		int code = 0;
		std::string shortName = "";
		std::string name = "";
	public:
		Currency(){};
		Currency(int cID, int cCode, std::string cShortName, std::string cName) :id(cID), code(cCode),
			shortName(cShortName), name(cName){};
		Currency(DataLayer::currenciesCollection);
		~Currency(){};
		
		//Currency class Accessors
		int GetID();
		int GetCode();
		std::string GetShortName();
		std::string GetName();

		//Currency class Mutators
		void SetID(int);
		void SetCode(int);
		void SetShortName(std::string);
		void SetName(std::string);
		
		// Create, delete and update company
		bool CreateCurrency(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateCurrency(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteCurrency(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateCurrency(DataLayer::OrmasDal& ormasDal, int cCode, std::string cShortName, std::string cName,
			std::string& errorMessage);
		bool UpdateCurrency(DataLayer::OrmasDal& ormasDal, int cCode, std::string cShortName, std::string cName, 
			std::string& errorMessage);
	};
}
#endif //CURRENCYCLASS_H