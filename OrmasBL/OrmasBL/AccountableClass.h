#ifndef ACCOUNTABLECLASS_H
#define ACCOUNTABLECLASS_H

#include "OrmasDAL.h"
#include "UserClass.h"

namespace BusinessLayer{
	class Accountable : public User
	{
	protected:
		int employeeID = 0;
		std::string information = "";
	public:
		Accountable(){};
		Accountable(int eID, std::string aInformation) : employeeID(eID), information(aInformation) {};
		Accountable(DataLayer::accountableCollection);
		~Accountable(){};

		std::string errorMessage = "";
		//Accountable class Accessors
		int GetEmployeeID();
		std::string GetInformation();


		//Accountable class Mutators
		void SetEmployeeID(int);
		void SetInformation(std::string);


		//Create, delete, update methods
		bool CreateAccountable(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateAccountable(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteAccountable(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateAccountable(DataLayer::OrmasDal& ormasDal, int eID, std::string aInformation, std::string& errorMessage);
		bool UpdateAccountable(DataLayer::OrmasDal& ormasDal, int eID, std::string aInformation, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetAccountableByID(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		void TrimStrings(std::string&);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string aInfromation, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}

#endif //AccountableCLASS_H