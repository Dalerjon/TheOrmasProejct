#ifndef MEASURECLASS_H
#define MEASURECLASS_H

#include "OrmasDAL.h"
namespace BusinessLayer
{
	class Measure
	{
		int ID;
		std::string name;
		std::string shortName;
	public:
		Measure(){};
		Measure(int mID, std::string mName, std::string mShortName) :ID(mID),
			name(mName), shortName(mShortName){};
		Measure(DataLayer::measuresCollection);
		~Measure(){};
		int CreateMeasure(int mID, std::string mName, std::string mShortName){};

		//Measure class Accessors
		int GetID();
		std::string GetName();
		std::string GetShortName();

		//please implement Mutators
	};
}
#endif //MEASURECLASS_H