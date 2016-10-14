#ifndef USERCLASS_H
#define USERCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class User
	{
		int ID;
		std::string name;
		std::string phone;
		std::string address;
		std::string firm;
		std::string firmNumber;
		int roleID;
		int regionID;
		std::string password;
	public:
		User(int uID, std::string uName, std::string uPhone, std::string uAddress, std::string firm, std::string firmNumber,
			int uRoleID, int uRegionID, std::string uPassword) :ID(uID),	name(uName),phone(uPhone), address(uAddress), firm(firm),
			firmNumber(firmNumber),roleID(uRoleID),regionID(uRegionID),password(uPassword){};
		User(DataLayer::usersCollection);
		User(){};
		~User(){};
		int CreateUser(int uID, std::string uName, std::string uPhone, std::string uAddress, std::string firm, std::string firmNumber,
			int uRoleID, int uRegionID, std::string uPassword){};

		//User class Accessors
		int GetID();
		std::string GetName();
		std::string GetPhone();
		std::string GetAddress();
		std::string GetFirm();
		std::string GetFirmNumber();
		int GetRoleID();
		int GetRegionID();
		std::string GetPassword();

		//Mutators
	};
}
#endif //USERCLASS_H
