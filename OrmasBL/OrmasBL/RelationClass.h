#ifndef RELATIONCLASS_H
#define RELATIONCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Relation{
	protected:
		int id = 0;
		int user1ID = 0;
		int user2ID = 0;
		int relationTypeID = 0;
	public:
		Relation();
		Relation(int rID, int u1ID, int u2ID, int rtID) :id(rID), user1ID(u1ID), user2ID(u2ID), relationTypeID(rtID){};
		Relation(DataLayer::relationsCollection);
		~Relation(){};

		std::string errorMessage = "";
		//Relation class Accessors
		int GetID();
		int GetUser1ID();
		int GetUser2ID();
		int GetRelationTypeID();

		//Relation class Mutators
		void SetID(int);
		void SetUser1ID(int);
		void SetUser2ID(int);
		void SetRelationTypeID(int);

		// Create, delete and update Relation
		bool CreateRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateRelation(DataLayer::OrmasDal &ormasDal, int u1ID, int u2ID, int rtID, std::string& errorMessage);
		bool UpdateRelation(DataLayer::OrmasDal &ormasDal, int u1ID, int u2ID, int rtID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetRelationByID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage);
		bool IsEmpty();
	};
}
#endif