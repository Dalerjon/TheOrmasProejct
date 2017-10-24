#ifndef CLIENTCLASS_H
#define CLIENTCLASS_H

#include "OrmasDAL.h"
#include "UserClass.h"

namespace BusinessLayer{
	class Client : public User
	{
	    protected:
			int userID = 0;
			std::string firm = "";
			std::string firmNumber = "";
			int locationID = 0;
		public:
			Client(){};
			Client(int uID, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone, std::string uAddress,
				int uRoleID, std::string uPassword, bool uActivated, std::string cFirm, std::string cFirmNumber, int lID ) :
				User(uID, uEmail, uName, uSurname, uPhone, uAddress, uRoleID, uPassword,uActivated), firm(cFirm), firmNumber(cFirmNumber),
				locationID(lID) {};
			Client(DataLayer::clientsCollection);
			~Client(){};

		std::string errorMessage = "";
		//Client class Accessors
		int GetUserID();
		std::string GetFirm();
		std::string GetFirmNumber();
		int GetLocationID();
		
		//Client class Mutators
		void SetUserID(int);
		void SetFirm(std::string);
		void SetFirmNumber(std::string);
		void SetLocationID(int);

		//Create, delete, update methods
		bool CreateClient(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateClient(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteClient(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateClient(DataLayer::OrmasDal& ormasDal, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone,
			std::string uAddress, int uRoleID, std::string uPassword, bool uActivated, std::string cFirm, std::string cFirmNumber,
			int lID, std::string& errorMessage);
		bool UpdateClient(DataLayer::OrmasDal& ormasDal, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone,
			std::string uAddress, int uRoleID, std::string uPassword, bool uActivated, std::string cFirm, std::string cFirmNumber,
			int lID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetClientByID(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
		bool GetClientByCredentials(DataLayer::OrmasDal& ormasDal, std::string uPhone, std::string uEmail, std::string uPassword);
		bool IsEmpty();
	private:
		void TrimStrings(std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, std::string&);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uSurname, std::string uPhone,
			 int uRoleID, std::string cFirm, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif
