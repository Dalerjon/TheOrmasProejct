#ifndef COMPANYACCOUNTRELATIONCLASS_H
#define COMPANYACCOUNTRELATIONCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class CompanyAccountRelation
	{
	protected:
		int companyID = 0;
		int accountID = 0;
	public:
		CompanyAccountRelation();
		CompanyAccountRelation(int cID, int aID) : companyID(cID), accountID(aID){};
		CompanyAccountRelation(DataLayer::companyAccountCollection);
		~CompanyAccountRelation(){};

		std::string errorMessage = "";
		//Access class Accessors
		int GetCompanyID();
		int GetAccountID();

		//Access class Mutators
		void SetCompanyID(int);
		void SetAccountID(int);

		// Create, delete and update Access
		bool CreateCompanyAccountRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteCompanyAccountRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateCompanyAccountRelation(DataLayer::OrmasDal &ormasDal, int cID, int aID, std::string& errorMessage);


		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		std::vector<int> GetAllCompanyByAccountID(DataLayer::OrmasDal& ormasDal, int aID, std::string& errorMessage);
		std::vector<int> GetAllAccountByCompanyID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int cID, int aID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif