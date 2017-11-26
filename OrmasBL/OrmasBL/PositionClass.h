#ifndef POSITIONCLASS_H
#define POSITIONCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Position{
	protected:
		int id = 0;
		std::string name = "";
	public:
		Position();
		Position(int pID, std::string pName) :id(pID), name(pName){};
		Position(DataLayer::positionsCollection);
		~Position(){};

		std::string errorMessage = "";
		//Position class Accessors
		int GetID();
		std::string GetName();

		//Position class Mutators
		void SetID(int);
		void SetName(std::string);

		// Create, delete and update Position
		bool CreatePosition(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdatePosition(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeletePosition(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreatePosition(DataLayer::OrmasDal &ormasDal, std::string pName, std::string& errorMessage);
		bool UpdatePosition(DataLayer::OrmasDal &ormasDal, std::string pName, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetPositionByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty(); 
		void Clear();
	private:
		void TrimStrings(std::string&);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string pName, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}

#endif 