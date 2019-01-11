#ifndef CASHBOXEMPLOYEERELATIONVIEWCLASS_H
#define CASHBOXEMPLOYEERELATIONVIEWCLASS_H

#include "CashboxEmployeeRelationClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class CashboxEmployeeRelationView : public CashboxEmployeeRelation
	{
		std::string subaccountNumber = "";
		std::string cashboxAddress = "";
		std::string userName = "";
		std::string userSurname = "";
		std::string userPhone = "";
		std::string roleName = "";
	public:
		CashboxEmployeeRelationView(DataLayer::cashboxEmployeeViewCollection);
		CashboxEmployeeRelationView(){};
		~CashboxEmployeeRelationView(){};

		// CashboxEmployeeRelationView class CashboxEmployeeRelationors
		std::string GetSubaccountNumber();
		std::string GetCashboxAddress();
		std::string GetUsername();
		std::string GetUserSurname();
		std::string GetUserPhone();
		std::string GetRoleName();
	};
}
#endif