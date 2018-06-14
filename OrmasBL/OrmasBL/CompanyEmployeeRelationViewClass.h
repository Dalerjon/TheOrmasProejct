#ifndef COMPANYEMPLOYEERELATIONVIEWCLASS_H
#define COMPANYEMPLOYEERELATIONVIEWCLASS_H

#include "CompanyEmployeeRelationClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class CompanyEmployeeRelationView : public CompanyEmployeeRelation
	{
		std::string companyName = "";
		std::string userName = "";
		std::string userSurname = "";
		std::string userPhone = "";
	public:
		CompanyEmployeeRelationView(DataLayer::companyEmployeeViewCollection);
		CompanyEmployeeRelationView(){};
		~CompanyEmployeeRelationView(){};

		// CompanyEmployeeRelationView class CompanyEmployeeRelationors
		std::string GetCompanyName();
		std::string GetUsername();
		std::string GetUserSurname();
		std::string GetUserPhone();
	};
}
#endif //COMPANYEMPLOYEERELATIONVIEWCLASS_H