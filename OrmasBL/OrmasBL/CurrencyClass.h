#ifndef CURRENCYCLASS_H
#define CURRENCYCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Currency
	{
		int id = 0;
		int code;
		std::string shortName;
		std::string name;
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

		//Please implement Mutators
		
		// Create, delete and update company
		bool CreateCurrency(DataLayer::OrmasDal& ormasDal,int cCode, std::string cShortName, std::string cName);
		bool DeleteCurrency(DataLayer::OrmasDal& ormasDal);
		bool UpdateCurrency(DataLayer::OrmasDal& ormasDal, int cCode, std::string cShortName, std::string cName);
	};
}
#endif //CURRENCYCLASS_H