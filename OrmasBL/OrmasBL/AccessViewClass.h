#ifndef ACCESSVIEWCLASS_H
#define ACCESSVIEWCLASS_H

#include "AccessClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class AccessView : public Access
	{
		std::string roleName = "";
		std::string accessItemEng = "";
		std::string accessItemRu = "";
		std::string division = "";
	public:
		AccessView(DataLayer::accessesViewCollection);
		AccessView(){};
		~AccessView(){};

		// AccessView class Accessors
		std::string GetRoleName();
		std::string GetAccessItemEng();
		std::string GetAccessItemRu();
		std::string GetDivision();
	};
}
#endif //ACCESSVIEWCLASS_H