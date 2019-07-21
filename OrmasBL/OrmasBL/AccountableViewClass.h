#ifndef ACCOUNTABLEVIEWCLASS_H
#define ACCOUNTABLEVIEWCLASS_H

#include "AccountableClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class AccountableView : public Accountable
	{
		std::string roleName = "";
		
	public:
		AccountableView(DataLayer::accountableViewCollection);
		AccountableView(){};
		~AccountableView(){};

		// AccountableView class Accountableors
		std::string GetRoleName();
	};
}
#endif 