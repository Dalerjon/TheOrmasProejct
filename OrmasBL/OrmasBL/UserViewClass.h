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
		UserView(int uID, std::string uName, std::string uPhone, std::string uAddress, std::string uCountryName,
			std::string uCountryCode, std::string uRegionName, std::string uCityName, std::string uRoleName, std::string firm,
			std::string firmNumber, int uRoleID, int uLocationID, std::string uPassword, bool uActivated) :
			User(uID, uName, uPhone, uAddress, firm, firmNumber, uRoleID, uLocationID, uPassword, uActivated),
			countryName(uCountryName), countryCode(uCountryCode), regionName(uRegionName), cityName(uCityName),
			roleName(uRoleName){};
		UserView(DataLayer::usersViewCollection);
		UserView(){};
		~UserView(){};

		//UserView class Accessors
		std::string GetCountryName();
		std::string GetCountryCode();
		std::string GetRegionName();
		std::string GetCityName();
		std::string GetRoleName();

		//UserView class Mutators
		void SetCountryName(std::string);
		void SetCountryCode(std::string);
		void SetRegionName(std::string);
		void SetCityName(std::string);
		void SetRoleName(std::string);
	};
}

#endif //USERVIEWCLASS_H