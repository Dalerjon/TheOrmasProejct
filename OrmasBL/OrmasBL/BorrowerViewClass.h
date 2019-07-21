#ifndef BORROWERVIEWCLASS_H
#define BorrowerVIEWCLASS_H

#include "BorrowerClass.h"

namespace BusinessLayer{
	class BorrowerView : public Borrower
	{
		std::string roleName = "";
	public:
		BorrowerView(DataLayer::borrowersViewCollection);
		BorrowerView(){};
		~BorrowerView(){};

		// BorrowerView class Accessors
		std::string GetRoleName();
	};
}

#endif //BorrowerVIEWCLASS_H