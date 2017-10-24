#ifndef ACCESSCLASS_H
#define ACCESSCLASS_H

#include "OrmasDAL.h"
#include "UserClass.h"


namespace BusinessLayer{
	class Access{
	protected:
		int id = 0;
		int roleID = 0;
		int accessItemID = 0;
	public:
		Access();
		Access(int aID, int rID, int aiID) :id(aID), roleID(rID), accessItemID(aiID){};
		Access(DataLayer::accessesCollection);
		~Access(){};

		std::string errorMessage = "";
		//Access class Accessors
		int GetID();
		int GetRoleID();
		int GetAccessItemID();

		//Access class Mutators
		void SetID(int);
		void SetRoleID(int);
		void SetAccessItemID(int);

		// Create, delete and update Access
		bool CreateAccess(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateAccess(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteAccess(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateAccess(DataLayer::OrmasDal &ormasDal, int rID, int aiID, std::string& errorMessage);
		bool UpdateAccess(DataLayer::OrmasDal &ormasDal, int rID, int aiID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetAccessByID(DataLayer::OrmasDal& ormasDal, int aID, std::string& errorMessage);
		bool IsEmpty();
		bool CheckAccess(DataLayer::OrmasDal* ormasDal, int accessItemID, std::string checkedDivision, std::string checkingItem);
		bool CheckAccess(DataLayer::OrmasDal* ormasDal, int accessItemID, std::string checkedDivision);
		std::vector<int> GetRightsList(DataLayer::OrmasDal* ormasDal, User*);
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int rID, int aiID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}

#endif //ACCESSCLASS_H