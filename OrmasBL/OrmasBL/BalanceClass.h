#ifndef BALANCECLASS_H
#define BALANCECLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Balance{
	protected:	
		int id = 0;
		int userID = 0;
		int subaccountID = 0;
	public:
		Balance();
		Balance(int bID, int uID, int aID) :id(bID),userID(uID),subaccountID(aID){};
		Balance(DataLayer::balancesCollection);
		~Balance(){};

		std::string errorMessage = "";
		//Balance class Accessors
		int GetID();
		int GetUserID();
		int GetSubaccountID();

		//Balance class Mutators
		void SetID(int);
		void SetUserID(int);
		void SetSubaccountID(int);

		// Create, delete and update balance
		bool CreateBalance(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateBalance(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteBalance(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateBalance(DataLayer::OrmasDal &ormasDal, int uID, int saID, std::string& errorMessage);
		bool UpdateBalance(DataLayer::OrmasDal &ormasDal, int uID, int saID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetBalanceByID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage);
		bool GetBalanceByUserID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int uID, int saID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //BALANCECLASS_H
