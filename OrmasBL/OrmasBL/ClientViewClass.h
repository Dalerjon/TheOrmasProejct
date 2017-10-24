#ifndef CLIENTVIEWCLASS_H
#define CLIENTVIEWCLASS_H

#include "ClientClass.h"

namespace BusinessLayer{
	class ClientView : public Client
	{
		std::string countryName = "";
		std::string regionName = "";
		std::string cityName = "";
		std::string roleName = "";
	public:
		ClientView(DataLayer::clientsViewCollection);
		ClientView(){};
		~ClientView(){};

		// ClientView class Accessors
		std::string GetCountryName();
		std::string GetRegionName();
		std::string GetCityName();
		std::string GetRoleName();
	};
}

#endif