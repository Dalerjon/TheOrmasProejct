#ifndef USERCLASS_H
#define USERCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class User
	{
	protected:
		int id = 0;
		std::string email = "";
		std::string name = "";
		std::string surname = "";
		std::string phone = "";
		std::string address = "";
		int roleID = 0;
		std::string password = "";
		bool activated = false;

		void TrimStrings(std::string&, std::string&, std::string&, std::string&, std::string&, std::string&);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uSurname, std::string uPhone,
			std::string uAddress, int uRoleID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool IsUnique(DataLayer::OrmasDal& ormasDal, std::string uPhone, std::string& errorMessage);
		bool IsUnique(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateBalance(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateBalanceForAccountable(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
		bool CreateBalanceForBorrower(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
		bool CreateBalanceForShareholder(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
	public:
		User(int uID, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone, std::string uAddress, 
			int uRoleID, std::string uPassword, bool uActivated) :id(uID), email(uEmail), name(uName), phone(uPhone), surname(uSurname)
			, address(uAddress), roleID(uRoleID), password(uPassword),
			activated(uActivated){};
		User(DataLayer::usersCollection);
		User(){};
		~User(){};
		
		//User class Accessors
		int GetID();
		std::string GetEmail();
		std::string GetName();
		std::string GetSurname();
		std::string GetPhone();
		std::string GetAddress();
		int GetRoleID();
		std::string GetPassword();
		bool GetActivated();
		//Mutators
		void SetID(int);
		void SetEmail(std::string);
		void SetName(std::string);
		void SetSurname(std::string);
		void SetPhone(std::string);
		void SetAddress(std::string);
		void SetRoleID(int);
		void SetPassword(std::string);
		void SetActivated(bool);
		
		//Create, delete, update methods
		bool CreateUser(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateUser(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteUser(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateUser(DataLayer::OrmasDal& ormasDal, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone,
			std::string uAddress, int uRoleID, std::string uPassword, bool uActivated, std::string& errorMessage);
		bool UpdateUser(DataLayer::OrmasDal& ormasDal, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone, 
			std::string uAddress, int uRoleID, std::string uPassword, bool uActivated, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetUserByID(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
		bool GetUserByCredentials(DataLayer::OrmasDal& ormasDal, std::string uPhoneOrEmail, std::string uPassword);
		bool IsEmpty();
		void Clear();
		int GetUserBalanceID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage);
		std::string GetCurrentPhone(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
	};
}
#endif //USERCLASS_H
