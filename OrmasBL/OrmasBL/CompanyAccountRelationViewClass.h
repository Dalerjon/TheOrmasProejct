#ifndef COMPANYACCOUNTRELATIONVIEWCLASS_H
#define COMPANYACCOUNTRELATIONVIEWCLASS_H

#include "CompanyAccountRelationClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class CompanyAccountRelationView : public CompanyAccountRelation
	{
		std::string companyName = "";
		std::string accountNumber = "";
	public:
		CompanyAccountRelationView(DataLayer::companyAccountViewCollection);
		CompanyAccountRelationView(){};
		~CompanyAccountRelationView(){};

		// CompanyAccountRelationView class CompanyAccountRelationors
		std::string GetCompanyName();
		std::string GetAccountNumber();
	};
}
#endif //COMPANYACCOUNTRELATIONVIEWCLASS_H