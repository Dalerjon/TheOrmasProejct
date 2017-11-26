#ifndef BALANCEWITHDRAWALRELATIONCLASS_H
#define BALANCEWITHDRAWALRELATIONCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class BalanceWithdrawalRelation
	{
	protected:
		int balanceID = 0;
		int withdrawalID = 0;
	public:
		BalanceWithdrawalRelation();
		BalanceWithdrawalRelation(int bID, int wID) : balanceID(bID), withdrawalID(wID){};
		BalanceWithdrawalRelation(DataLayer::balanceWithdrawalCollection);
		~BalanceWithdrawalRelation(){};

		std::string errorMessage = "";
		//Access class Accessors
		int GetBalanceID();
		int GetWithdrawalID();

		//Access class Mutators
		void SetBalanceID(int);
		void SetWithdrawalID(int);

		// Create, delete and update Access
		bool CreateBalanceWithdrawalRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteBalanceWithdrawalRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateBalanceWithdrawalRelation(DataLayer::OrmasDal &ormasDal, int bID, int wID, std::string& errorMessage);


		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		std::vector<int> GetAllWithdrawalByBalanceID(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		std::vector<int> GetAllBalanceByWithdrawalID(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int bID, int wID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif