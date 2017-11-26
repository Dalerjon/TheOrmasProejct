#ifndef RELATIONTYPECLASS_H
#define RELATIONTYPECLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer{
	class RelationType{
	protected:
		int id = 0;
		std::string name = "";
		std::string comment = "";
	public:
		RelationType();
		RelationType(int rtID, std::string rtName, std::string rtComment) :id(rtID), name(rtName), comment(rtComment){};
		RelationType(DataLayer::relationTypeCollection);
		~RelationType(){};

		std::string errorMessage = "";
		//RelationType class Accessors
		int GetID();
		std::string GetName();
		std::string GetComment();
		
		//RelationType class Mutators
		void SetID(int);
		void SetName(std::string);
		void SetComment(std::string);
		
		// Create, delete and update RelationType
		bool CreateRelationType(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateRelationType(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteRelationType(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateRelationType(DataLayer::OrmasDal &ormasDal, std::string rtName, std::string rtComment, std::string& errorMessage);
		bool UpdateRelationType(DataLayer::OrmasDal &ormasDal, std::string rtName, std::string rtComment, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetRelationTypeByID(DataLayer::OrmasDal& ormasDal, int rtID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		void TrimStrings(std::string&);
	};
}

#endif