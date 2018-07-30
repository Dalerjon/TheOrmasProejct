#ifndef EntrySubaccountRELATIONCLASS_H
#define SCCOUNTENTRYRELATIONCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class EntrySubaccountRelation
	{
	protected:
		int id = 0;
		int entryID = 0;
		int subaccountID = 0;
	public:
		EntrySubaccountRelation();
		EntrySubaccountRelation(int esID, int eID, int saID) : id(esID), entryID(eID), subaccountID(saID){};
		EntrySubaccountRelation(DataLayer::entrySubaccountCollection);
		~EntrySubaccountRelation(){};

		std::string errorMessage = "";
		//Access class Accessors
		int GetID();
		int GetSubaccountID();
		int GetEntryID();

		//Access class Mutators
		void SetID(int);
		void SetSubaccountID(int);
		void SetEntryID(int);

		// Create, delete and update Access
		bool CreateEntrySubaccountRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteEntrySubaccountRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateEntrySubaccountRelation(DataLayer::OrmasDal &ormasDal, int eID, int sID, std::string& errorMessage);


		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		std::vector<int> GetAllSubaccountByEntryID(DataLayer::OrmasDal& ormasDal, int eID, std::string& errorMessage);
		std::vector<int> GetAllEntryBySubaccountID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, int sID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif