#ifndef BALANCEREFUNDRELATIONCLASS_H
#define BALANCEREFUNDRELATIONCLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer{
	class BalanceRefundRelation
	{
	protected:
		int id = 0;
		int balanceID = 0;
		int refundID = 0;
	public:
		BalanceRefundRelation();
		BalanceRefundRelation(int brID, int bID, int rID) :id(brID), balanceID(bID), refundID(rID){};
		BalanceRefundRelation(DataLayer::balanceRefundCollection);
		~BalanceRefundRelation(){};

		std::string errorMessage = "";
		//Access class Accessors
		int GetID();
		int GetBalanceID();
		int GetRefundID();

		//Access class Mutators
		void SetID(int);
		void SetBalanceID(int);
		void SetRefundID(int);

		// Create, delete and update Access
		bool CreateBalanceRefundRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteBalanceRefundRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateBalanceRefundRelation(DataLayer::OrmasDal &ormasDal, int bID, int rID, std::string& errorMessage);


		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		std::vector<int> GetAllRefundByBalanceID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage);
		std::vector<int> GetAllBalanceByRefundID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int bID, int rID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif