#ifndef DIVISIONACCOUNTRELATIONVIEW_H
#define DIVISIONACCOUNTRELATIONVIEW_H

#include "DivisionAccountRelationClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class DivisionAccountRelationView : public DivisionAccountRelation
	{
		std::string divisionName = "";
		std::string accountNumber = "";
		std::string accountName = "";
	public:
		DivisionAccountRelationView(DataLayer::divisionAccountViewCollection);
		DivisionAccountRelationView(){};
		~DivisionAccountRelationView(){};

		// Chart Of Accounts View class Accessors
		std::string GetDivisionName();
		std::string GetAccountNumber();
		std::string GetAccountName();
	};
}

#endif