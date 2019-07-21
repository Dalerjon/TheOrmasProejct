#ifndef ShareholderVIEWCLASS_H
#define SHAREHOLDERVIEWCLASS_H

#include "ShareholderClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class ShareholderView : public Shareholder
	{
		std::string userName = "";
		std::string userSurname = "";
		std::string userPhone = "";
		std::string userAddress = "";
	public:
		ShareholderView(DataLayer::shareholdersViewCollection);
		ShareholderView(){};
		~ShareholderView(){};

		// ShareholderView class Shareholderors
		std::string GetUsername();
		std::string GetUserSurname();
		std::string GetUserPhone();
		std::string GetUserAddress();
	};
}
#endif //ShareholderVIEWCLASS_H