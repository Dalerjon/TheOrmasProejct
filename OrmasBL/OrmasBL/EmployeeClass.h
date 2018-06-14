#ifndef EMPLOYEECLASS_H
#define EMPLOYEECLASS_H

#include "OrmasDAL.h"
#include "UserClass.h"

namespace BusinessLayer{
	class Employee : public User
	{
	protected:
		int userID = 0;
		int positionID = 0;
		std::string birthDate = "";
		std::string hireDate = "";
	public:
		Employee(){};
		Employee(int uID, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone, std::string uAddress,
			int uRoleID, std::string uPassword, bool uActivated, int ePositionID, std::string eBirthDate, std::string eHireDate) :
			User(uID, uEmail, uName, uSurname, uPhone, uAddress, uRoleID, uPassword, uActivated), positionID(ePositionID), 
			birthDate(eBirthDate), hireDate(eHireDate){};
		Employee(DataLayer::employeesCollection);
		~Employee(){};

		std::string errorMessage = "";
		//Employee class Accessors
		int GetUserID();
		int GetPositionID();
		std::string GetBirthDate();
		std::string GetHireDate();
		

		//Employee class Mutators
		void SetUserID(int);
		void SetPositionID(int);
		void SetBirthDate(std::string);
		void SetHireDate(std::string);
		

		//Create, delete, update methods
		bool CreateEmployee(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateEmployee(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteEmployee(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateEmployee(DataLayer::OrmasDal& ormasDal, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone,
			std::string uAddress, int uRoleID, std::string uPassword, bool uActivated, int pID, std::string eBirthDate,
			std::string eHireDate, std::string& errorMessage);
		bool UpdateEmployee(DataLayer::OrmasDal& ormasDal, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone,
			std::string uAddress, int uRoleID, std::string uPassword, bool uActivated, int pID, std::string eBirthDate,
			std::string eHireDate, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetEmployeeByID(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
		bool GetEmployeeByCredentials(DataLayer::OrmasDal& ormasDal, std::string uPhone, std::string uEmail, std::string uPassword);
		bool IsEmpty();
		void Clear();
	private:
		void TrimStrings(std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, std::string&, std::string&);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uSurname, std::string uPhone,
			int uRoleID, std::string eBirthDate, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		std::string GetCurrentPhone(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
	};
}

#endif //EMPLOYEECLASS_H