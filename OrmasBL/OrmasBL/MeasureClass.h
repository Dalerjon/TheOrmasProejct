#ifndef MEASURECLASS_H
#define MEASURECLASS_H

#include "OrmasDAL.h"
namespace BusinessLayer
{
	class Measure
	{
		int id = 0;
		std::string name = "";
		std::string shortName = "";
	public:
		Measure(){};
		Measure(int mID, std::string mName, std::string mShortName) :id(mID),
			name(mName), shortName(mShortName){};
		Measure(DataLayer::measuresCollection);
		~Measure(){};
		
		//Measure class Accessors
		int GetID();
		std::string GetName();
		std::string GetShortName();

		//Measure class Mutators
		void SetID(int);
		void SetName(std::string);
		void SetShortName(std::string);

		//Create, delete and update methods 
		bool CreateMeasure(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateMeasure(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteMeasure(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateMeasure(DataLayer::OrmasDal& ormasDal, std::string mName, std::string mShortName, std::string& errorMessage);
		bool UpdateMeasure(DataLayer::OrmasDal& ormasDal, std::string mName, std::string mShortName, std::string& errorMessage);
	};
}
#endif //MEASURECLASS_H