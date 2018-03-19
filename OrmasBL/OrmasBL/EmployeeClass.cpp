#include "stdafx.h"
#include "EmployeeClass.h"
#include <boost/algorithm/string.hpp>

namespace BusinessLayer{
	Employee::Employee(DataLayer::employeesCollection cCollection)
	{
		userID = std::get<0>(cCollection);
		positionID = std::get<1>(cCollection);
		birthDate = std::get<2>(cCollection);
		hireDate = std::get<3>(cCollection);
	}

	int Employee::GetUserID()
	{
		return userID;
	}
	int Employee::GetPositionID()
	{
		return positionID;
	}
	std::string Employee::GetBirthDate()
	{
		return birthDate;
	}
	std::string Employee::GetHireDate()
	{
		return hireDate;
	}
	

	void Employee::SetUserID(int eID)
	{
		userID = eID;
		if (0 == id || id != eID)
			id = userID;
	}
	void Employee::SetPositionID(int ePositionID)
	{
		positionID = ePositionID;
	}
	void Employee::SetBirthDate(std::string eBirthDate)
	{
		if (!eBirthDate.empty())
			boost::trim(eBirthDate);
		birthDate = eBirthDate;
	}
	void Employee::SetHireDate(std::string eHireDate)
	{
		if (!eHireDate.empty())
			boost::trim(eHireDate);
		hireDate = eHireDate;
	}
	

	bool Employee::CreateEmployee(DataLayer::OrmasDal& ormasDal, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone,
		std::string uAddress, int uRoleID, std::string uPassword, bool uActivated, int pID, std::string eBirthDate,
		std::string eHireDate, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, uName, uSurname, uPhone, uRoleID, eBirthDate, errorMessage))
			return false;
		if (!IsUnique(ormasDal, uPhone, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		TrimStrings(uEmail, uName, uSurname, uPhone, uAddress, uPassword, eBirthDate, eHireDate);
		userID = id;
		email = uEmail;
		name = uName;
		surname = uSurname;
		phone = uPhone;
		address = uAddress;
		roleID = uRoleID;
		password = uPassword;
		activated = uActivated;
		userID = id;
		positionID = pID;
		birthDate = eBirthDate;
		hireDate = eHireDate;
		if (0 != id && ormasDal.CreateUser(id, email, name, surname, phone, address, roleID, password, activated, errorMessage))
		{
			if (ormasDal.CreateEmployee(userID, positionID, birthDate, hireDate, errorMessage))
			{
				if (CreateAccount(ormasDal, errorMessage))
					return true;
				return false;
			}
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Employee::CreateEmployee(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		if (!IsUnique(ormasDal, phone, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		userID = id;
		if (0 != id && ormasDal.CreateUser(id, email, name, surname, phone, address, roleID, password, activated, errorMessage))
		{
			if (ormasDal.CreateEmployee(userID, positionID, birthDate, hireDate, errorMessage))
			{
				if (CreateAccount(ormasDal, errorMessage))
					return true;
				return false;
			}
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Employee::DeleteEmployee(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		ormasDal.StartTransaction(errorMessage);
		if (!errorMessage.empty())
			return false;
		if (ormasDal.DeleteEmployee(id, errorMessage))
		{
			if (ormasDal.DeleteUser(id, errorMessage))
			{
				ormasDal.CommitTransaction(errorMessage);
				if (!errorMessage.empty())
				{
					return false;
				}
				Clear();
				return true;
			}
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Employee::UpdateEmployee(DataLayer::OrmasDal& ormasDal, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone,
		std::string uAddress, int uRoleID, std::string uPassword, bool uActivated, int pID, std::string eBirthDate,
		std::string eHireDate, std::string& errorMessage)
	{
		if (!IsUnique(ormasDal, uPhone, errorMessage))
			return false;
		TrimStrings(uEmail, uName, uSurname, uPhone, uAddress, uPassword, eBirthDate, eHireDate);
		email = uEmail;
		name = uName;
		surname = uSurname;
		phone = uPhone;
		address = uAddress;
		roleID = uRoleID;
		password = uPassword;
		activated = uActivated;
		userID = id;
		positionID = pID;
		birthDate = eBirthDate;
		hireDate = eHireDate;
		userID = id;
		ormasDal.StartTransaction(errorMessage);
		if (!errorMessage.empty())
			return false;
		if (0 != id && ormasDal.UpdateUser(id, email, name, surname, phone, address, roleID, password, activated, errorMessage))
		{
			if (ormasDal.UpdateEmployee(userID, positionID, birthDate, hireDate, errorMessage))
			{
				ormasDal.CommitTransaction(errorMessage);
				if (!errorMessage.empty())
				{
					return false;
				}
				return true;
			}
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Employee::UpdateEmployee(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!IsUnique(ormasDal, phone, errorMessage))
			return false;
		ormasDal.StartTransaction(errorMessage);
		userID = id;
		if (!errorMessage.empty())
			return false;
		if (0 != id && ormasDal.UpdateUser(id, email, name, surname, phone, address, roleID, password, activated, errorMessage))
		{
			if (ormasDal.UpdateEmployee(userID, positionID, birthDate, hireDate, errorMessage))
			{
				ormasDal.CommitTransaction(errorMessage);
				if (!errorMessage.empty())
				{
					return false;
				}
				return true;
			}
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	
	std::string Employee::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !name.empty() || !surname.empty() || !address.empty() || !phone.empty() || !birthDate.empty() || !hireDate.empty()
			|| !password.empty() || !email.empty() || 0 != roleID || 0 != positionID)
		{
			return ormasDal.GetFilterForEmployee(id, name, surname, phone, address, birthDate, hireDate, password, email, activated,
				roleID, positionID);
		}
		return "";
	}

	bool Employee::GetEmployeeByID(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage)
	{
		id = uID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::employeesViewCollection> employeeVector = ormasDal.GetEmployees(errorMessage, filter);
		if (0 != employeeVector.size())
		{
			id = std::get<0>(employeeVector.at(0));
			name = std::get<1>(employeeVector.at(0));
			surname = std::get<2>(employeeVector.at(0));
			phone = std::get<4>(employeeVector.at(0));
			address = std::get<5>(employeeVector.at(0));
			birthDate = std::get<6>(employeeVector.at(0));
			hireDate = std::get<8>(employeeVector.at(0));
			password = std::get<9>(employeeVector.at(0));
			email = std::get<10>(employeeVector.at(0));
			activated = std::get<11>(employeeVector.at(0));
			roleID = std::get<12>(employeeVector.at(0));
			positionID = std::get<13>(employeeVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find employee with this id";
		}
		return false;
	}

	bool Employee::GetEmployeeByCredentials(DataLayer::OrmasDal& ormasDal, std::string uPhone, std::string uEmail, std::string uPassword)
	{
		std::string errorMessage = "";
		if (!uPhone.empty())
		{
			phone = uPhone;
		}
		if (!uEmail.empty())
		{
			email = uEmail;
		}
		password = uPassword;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::employeesViewCollection> employeeVector = ormasDal.GetEmployees(errorMessage, filter);
		if (0 != employeeVector.size())
		{
			id = std::get<0>(employeeVector.at(0));
			name = std::get<1>(employeeVector.at(0));
			surname = std::get<2>(employeeVector.at(0));
			phone = std::get<4>(employeeVector.at(0));
			address = std::get<5>(employeeVector.at(0));
			birthDate = std::get<6>(employeeVector.at(0));
			hireDate = std::get<8>(employeeVector.at(0));
			password = std::get<9>(employeeVector.at(0));
			email = std::get<10>(employeeVector.at(0));
			activated = std::get<11>(employeeVector.at(0));
			roleID = std::get<12>(employeeVector.at(0));
			positionID = std::get<13>(employeeVector.at(0));
			return true;
		}
		return false;
	}

	bool Employee::IsEmpty()
	{
		if (0 == id && name.empty() && surname.empty() && address.empty() && phone.empty() && birthDate.empty() && hireDate.empty()
			&& password.empty() && email.empty() && 0 == roleID && 0 == positionID)
			return true;
		return false;
	}
	
	void Employee::Clear()
	{
		id = 0;
		name.clear();
		address.clear();
		phone.clear();
		birthDate.clear();
		hireDate.clear();
		password.clear();
		email.clear();
		roleID = 0;
		positionID = 0;
	}

	void Employee::TrimStrings(std::string& uEmail, std::string& uName, std::string& uSurname, std::string& uPhone,
		std::string& uAddress, std::string& uPassword, std::string& eBirthDate, std::string& eHireDate)
	{
		if (!uEmail.empty())
			boost::trim(uEmail);
		if (!uName.empty())
			boost::trim(uName);
		if (!uSurname.empty())
			boost::trim(uSurname);
		if (!uPhone.empty())
			boost::trim(uPhone);
		if (!uAddress.empty())
			boost::trim(uAddress);
		if (!uPassword.empty())
			boost::trim(uPassword);
		if (!eBirthDate.empty())
			boost::trim(eBirthDate);
		if (!eHireDate.empty())
			boost::trim(eHireDate);
	}

	bool Employee::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uSurname, std::string uPhone,
		int uRoleID, std::string eBirthDate, std::string& errorMessage)
	{
		Employee employee;
		employee.SetName(uName);
		employee.SetSurname(uSurname);
		employee.SetPhone(uPhone);
		employee.SetRoleID(uRoleID);
		employee.SetBirthDate(eBirthDate);
		std::string filter = employee.GenerateFilter(ormasDal);
		std::vector<DataLayer::employeesViewCollection> employeeVector = ormasDal.GetEmployees(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == employeeVector.size())
		{
			return false;
		}
		errorMessage = "Employee with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Employee::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Employee employee;
		employee.SetName(name);
		employee.SetSurname(surname);
		employee.SetPhone(phone);
		employee.SetRoleID(roleID);
		employee.SetBirthDate(birthDate);
		std::string filter = employee.GenerateFilter(ormasDal);
		std::vector<DataLayer::employeesViewCollection> employeeVector = ormasDal.GetEmployees(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == employeeVector.size())
		{
			return false;
		}
		errorMessage = "Employee with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}