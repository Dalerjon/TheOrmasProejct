#ifndef USERCLASS_H
#define USERCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class User
	{
		int id=0;
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
			int uRoleID, int uRegionID, std::string uPassword) :id(uID),	name(uName),phone(uPhone), address(uAddress), firm(firm),
			firmNumber(firmNumber),roleID(uRoleID),regionID(uRegionID),password(uPassword){};
		User(DataLayer::usersCollection);
		User(){};
		~User(){};
		
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
		
		//Create, delete, update methods
		bool CreateUser(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uPhone, std::string uAddress, 
			std::string uFirm, std::string uFirmNumber, int uRoleID, int uRegionID, std::string uPassword);
		bool DeleteUser(DataLayer::OrmasDal& ormasDal);
		bool UpdateUser(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uPhone, std::string uAddress,
			std::string uFirm, std::string uFirmNumber, int uRoleID, int uRegionID, std::string uPassword);
	};
}
#endif //USERCLASS_H
