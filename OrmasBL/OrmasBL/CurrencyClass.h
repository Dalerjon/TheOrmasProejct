#ifndef CURRENCYCLASS_H
#define CURRENCYCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Currency
	{
		int ID;
		int code;
		std::string shortName;
		std::string name;
	public:
		Currency(){};
		Currency(int cID, int cCode, std::string cShortName, std::string cName) :ID(cID), code(cCode),
			shortName(cShortName), name(cName){};
		Currency(DataLayer::currenciesCollection);
		~Currency(){};
		int CreateCurrency(int cID, int cCode, std::string cShortName, std::string cName){};

		//Currency class Accessors
		int GetID();
		int GetCode();
		std::string GetShortName();
		std::string GetName();

		//Please implement Mutators
	};
}
#endif //CURRENCYCLASS_H