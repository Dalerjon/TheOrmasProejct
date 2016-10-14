#ifndef REGIONCLASS_H
#define REGIONCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Region
	{
		int ID;
		std::string code;
		std::string name;
	public:
		Region(int rID, std::string rCode, std::string rName) :ID(rID), code(rCode), name(rName){};
		Region(DataLayer::regionsCollection);
		Region(){};
		~Region(){};
		int CreateRegion(int rID, std::string rCode, std::string rName){};

		//Region class Accessors
		int GetID();
		std::string GetCode();
		std::string GetName();

		//Please implement Mutators
	};
}
#endif // REGIONCLASS_H