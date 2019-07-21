#ifndef BORROWERCLASS_H
#define BORROWERCLASS_H

#include "OrmasDAL.h"
#include "UserClass.h"


namespace BusinessLayer{
	class Borrower : public User
	{
	protected:
		int userID = 0;
		std::string comment = "";
	public:
		Borrower(){};
		Borrower(int uID, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone, std::string uAddress,
			int uRoleID, std::string uPassword, bool uActivated, std::string bComment) :
			User(uID, uEmail, uName, uSurname, uPhone, uAddress, uRoleID, uPassword, uActivated), comment(bComment){};
		Borrower(DataLayer::borrowersCollection);
		~Borrower(){};

		std::string errorMessage = "";
		//Borrower class Accessors
		int GetUserID();
		std::string GetComment();

		//Borrower class Mutators
		void SetUserID(int);
		void SetComment(std::string);


		//Create, delete, update methods
		bool CreateBorrower(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateBorrower(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteBorrower(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateBorrower(DataLayer::OrmasDal& ormasDal, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone,
			std::string uAddress, int uRoleID, std::string uPassword, bool uActivated, std::string bComment, std::string& errorMessage);
		bool UpdateBorrower(DataLayer::OrmasDal& ormasDal, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone,
			std::string uAddress, int uRoleID, std::string uPassword, bool uActivated, std::string bComment, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetBorrowerByID(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
		bool GetBorrowerByCredentials(DataLayer::OrmasDal& ormasDal, std::string uPhone, std::string uEmail, std::string uPassword);
		bool CreateCompanyEmployeeRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		void TrimStrings(std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, std::string&);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uSurname, std::string uPhone, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		std::string GetCurrentPhone(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
	};
}

#endif //BorrowerCLASS_H