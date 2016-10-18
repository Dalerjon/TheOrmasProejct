#ifndef REGIONCLASS_H
#define REGIONCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Region
	{
		int id = 0;
		std::string code;
		std::string name;
	public:
		Region(int rID, std::string rCode, std::string rName) :id(rID), code(rCode), name(rName){};
		Region(DataLayer::regionsCollection);
		Region(){};
		~Region(){};
		
		//Region class Accessors
		int GetID();
		std::string GetCode();
		std::string GetName();

		//Please implement Mutators
		
		//Create, delete, update methods
		bool CreateRegion(DataLayer::OrmasDal& ormasDal, std::string rCode, std::string rName);
		bool DeleteRegion(DataLayer::OrmasDal& ormasDal);
		bool UpdateRegion(DataLayer::OrmasDal& ormasDal, std::string rCode, std::string rName);
	};
}
#endif // REGIONCLASS_H