#ifndef USERCLASS_H
#define USERCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class User
	{
	protected:
		int id = 0;
		std::string name = "";
		std::string phone = "";
		std::string address = "";
		std::string firm = "";
		std::string firmNumber = "";
		int roleID = 0;
		int locationID = 0;
		std::string password = "";
		bool activated = false;
	public:
		User(int uID, std::string uName, std::string uPhone, std::string uAddress, std::string firm, std::string firmNumber,
			int uRoleID, int uLocationID, std::string uPassword, bool uActivated) :id(uID), name(uName), phone(uPhone),
			address(uAddress), firm(firm), firmNumber(firmNumber), roleID(uRoleID), locationID(uLocationID), password(uPassword),
			activated(uActivated){};
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
		int GetLocationID();
		std::string GetPassword();
		bool GetActivated();
		//Mutators
		void SetID(int);
		void SetName(std::string);
		void SetPhone(std::string);
		void SetAddress(std::string);
		void SetFirm(std::string);
		void SetFirmNumber(std::string);
		void SetRoleID(int);
		void SetLocationID(int);
		void SetPassword(std::string);
		void SetActivated(bool);
		
		//Create, delete, update methods
		bool CreateUser(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateUser(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteUser(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateUser(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uPhone, std::string uAddress,
			std::string uFirm, std::string uFirmNumber, int uRoleID, int uLocationID, std::string uPassword, bool uActivated,
			std::string& errorMessage);
		bool UpdateUser(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uPhone, std::string uAddress,
			std::string uFirm, std::string uFirmNumber, int uRoleID, int uLocationID, std::string uPassword, bool uActivated,
			std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetUserByID(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
		bool GetUserByCredentials(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uPassword);
		bool IsEmpty();
	};
}
#endif //USERCLASS_H
