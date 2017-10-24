#ifndef USERVIEWCLASS_H
#define USERVIEWCLASS_H
#include "UserClass.h"

namespace BusinessLayer
{
	class UserView : public User
	{
		std::string countryName = "";
		std::string countryCode = "";
		std::string regionName = "";
		std::string cityName = "";
		std::string roleName = "";
	public:
		UserView(DataLayer::usersViewCollection);
		UserView(){};
		~UserView(){};

		//UserView class Accessors
		std::string GetCountryName();
		std::string GetCountryCode();
		std::string GetRegionName();
		std::string GetCityName();
		std::string GetRoleName();

		
	};
}

#endif //USERVIEWCLASS_H