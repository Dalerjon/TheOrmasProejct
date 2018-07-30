#ifndef BALANCEPAYSLIPRELATIONCLASS_H
#define BALANCEPAYSLIPRELATIONCLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer{
	class BalancePayslipRelation
	{
	protected:
		int id = 0;
		int balanceID = 0;
		int payslipID = 0;
	public:
		BalancePayslipRelation();
		BalancePayslipRelation(int bpID, int bID, int pID) :id(bpID), balanceID(bID), payslipID(pID){};
		BalancePayslipRelation(DataLayer::balancePayslipCollection);
		~BalancePayslipRelation(){};

		std::string errorMessage = "";
		//Access class Accessors
		int GetID();
		int GetBalanceID();
		int GetPayslipID();

		//Access class Mutators
		void SetID(int);
		void SetBalanceID(int);
		void SetPayslipID(int);

		// Create, delete and update Access
		bool CreateBalancePayslipRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteBalancePayslipRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateBalancePayslipRelation(DataLayer::OrmasDal &ormasDal, int bID, int pID, std::string& errorMessage);


		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		std::vector<int> GetAllPayslipByBalanceID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage);
		std::vector<int> GetAllBalanceByPayslipID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int bID, int pID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif