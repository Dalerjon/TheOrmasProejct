#include "stdafx.h"
#include "UserClass.h"
#include "BalanceClass.h"
#include "CurrencyClass.h"
#include <boost/algorithm/string.hpp>

namespace BusinessLayer
{
	User::User(DataLayer::usersCollection uCollection)
	{
		id = std::get<0>(uCollection);
		email = std::get<1>(uCollection);
		name = std::get<2>(uCollection);
		surname = std::get<3>(uCollection);
		phone = std::get<4>(uCollection);
		address = std::get<5>(uCollection);
		roleID = std::get<6>(uCollection);
		password = std::get<7>(uCollection);
		activated = std::get<8>(uCollection);
	}

	int User::GetID()
	{
		return id;
	}

	std::string User::GetEmail()
	{
		return email;
	}

	std::string User::GetName()
	{
		return name;
	}

	std::string User::GetSurname()
	{
		return surname;
	}

	std::string User::GetPhone()
	{
		return phone;
	}

	std::string User::GetAddress()
	{
		return address;
	}

	int User::GetRoleID()
	{
		return roleID;
	}

	std::string User::GetPassword()
	{
		return password;
	}

	bool User::GetActivated()
	{
		return activated;
	}

	void User::SetID(int uID)
	{
		id = uID;
	}
	void User::SetEmail(std::string uEmail)
	{
		if (!uEmail.empty())
			boost::trim(uEmail);
		email = uEmail;
	}
	void User::SetName(std::string uName)
	{
		if (!uName.empty())
			boost::trim(uName);
		name = uName;
	}
	void User::SetSurname(std::string uSurname)
	{
		if (!uSurname.empty())
			boost::trim(uSurname);
		surname = uSurname;
	}
	void User::SetPhone(std::string uPhone)
	{
		if (!uPhone.empty())
			boost::trim(uPhone);
		phone = uPhone;
	}
	void User::SetAddress(std::string uAddress)
	{
		if (!uAddress.empty())
			boost::trim(uAddress);
		address = uAddress;
	}
	void User::SetRoleID(int uRoleID)
	{
		roleID = uRoleID;
	}
	void User::SetPassword(std::string uPassword)
	{
		if (!uPassword.empty())
			boost::trim(uPassword);
		password = uPassword;
	}
	void User::SetActivated(bool uActivated)
	{
		activated = uActivated;
	}

	bool User::CreateUser(DataLayer::OrmasDal& ormasDal, std::string uEmail, std::string uName, std::string uSurname, 
		std::string uPhone,	std::string uAddress, int uRoleID, std::string uPassword, bool uActivated, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, uName, uSurname, uPhone, uAddress, uRoleID, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		TrimStrings(uEmail, uName, uSurname, uPhone, uAddress, uPassword);
		email = uEmail;
		name = uName;
		surname = uSurname;
		phone = uPhone;
		address = uAddress;
		roleID = uRoleID;
		password = uPassword;
		activated = uActivated;
		if (0 != id && ormasDal.CreateUser(id, email, name, surname, phone, address, roleID, password, activated, errorMessage))
		{
			CreateAccount(ormasDal, errorMessage);
			return true;
		}
		return false;
	}
	bool User::CreateUser(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateUser(id, email, name, surname, phone, address, roleID, password, activated, errorMessage))
		{
			CreateAccount(ormasDal, errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool User::DeleteUser(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		email.clear();
		name.clear();
		surname.clear();
		phone.clear();
		address.clear();
		roleID = 0;
		password.clear();
		if (ormasDal.DeleteUser(id, errorMessage))
		{
			id = 0;
			return true;
		}
		return false;
	}
	bool User::UpdateUser(DataLayer::OrmasDal& ormasDal, std::string uEmail, std::string uName, std::string uSurname,
		std::string uPhone, std::string uAddress, int uRoleID, std::string uPassword, bool uActivated, std::string& errorMessage)
	{
		TrimStrings(uEmail, uName, uSurname, uPhone, uAddress, uPassword);
		email = uEmail;
		name = uName;
		surname = uSurname;
		phone = uPhone;
		address = uAddress;
		roleID = uRoleID;
		password = uPassword;
		activated = uActivated;
		if (0 != id && ormasDal.UpdateUser(id, email, name, surname, phone, address, roleID, password, activated, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool User::UpdateUser(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateUser(id, email, name, surname, phone, address, roleID, password, activated, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	std::string User::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !email.empty() || !name.empty() || !surname.empty() || !address.empty() || !phone.empty() || !password.empty() 
			|| 0 != roleID)
		{
			return ormasDal.GetFilterForUser(id, email, name, surname, phone, address, roleID, password, activated);
		}
		return "";
	}

	bool User::GetUserByID(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage)
	{
		id = uID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::usersViewCollection> userVector = ormasDal.GetUsers(errorMessage, filter);
		if (0 != userVector.size())
		{
			id = std::get<0>(userVector.at(0));
			email = std::get<1>(userVector.at(0));
			name = std::get<2>(userVector.at(0));
			surname = std::get<3>(userVector.at(0));
			phone = std::get<4>(userVector.at(0));
			address = std::get<5>(userVector.at(0));
			password = std::get<7>(userVector.at(0));
			activated = std::get<8>(userVector.at(0));
			roleID = std::get<9>(userVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find user with this id";
		}
		return false;
	}
	
	bool User::GetUserByCredentials(DataLayer::OrmasDal& ormasDal, std::string uPhoneOrEmail, std::string uPassword)
	{
		std::string errorMessage = "";
		if (!uPhoneOrEmail.empty() && !password.empty())
		{
			phone = uPhoneOrEmail;
			password = uPassword;
			std::string filter1 = GenerateFilter(ormasDal);
			std::vector<DataLayer::usersViewCollection> userVector1 = ormasDal.GetUsers(errorMessage, filter1);
			if (0 != userVector1.size())
			{
				id = std::get<0>(userVector1.at(0));
				email = std::get<1>(userVector1.at(0));
				name = std::get<2>(userVector1.at(0));
				surname = std::get<3>(userVector1.at(0));
				phone = std::get<4>(userVector1.at(0));
				address = std::get<5>(userVector1.at(0));
				password = std::get<7>(userVector1.at(0));
				activated = std::get<8>(userVector1.at(0));
				roleID = std::get<9>(userVector1.at(0));
				return true;
			}
			
			phone = "";
			email = uPhoneOrEmail;
			std::string filter2 = GenerateFilter(ormasDal);
			std::vector<DataLayer::usersViewCollection> userVector2 = ormasDal.GetUsers(errorMessage, filter2);
			if (0 != userVector2.size())
			{
				id = std::get<0>(userVector2.at(0));
				email = std::get<1>(userVector2.at(0));
				name = std::get<2>(userVector2.at(0));
				surname = std::get<3>(userVector2.at(0));
				phone = std::get<4>(userVector2.at(0));
				address = std::get<5>(userVector2.at(0));
				password = std::get<7>(userVector2.at(0));
				activated = std::get<8>(userVector2.at(0));
				roleID = std::get<9>(userVector2.at(0));
				return true;
			}
		}
		return false;
	}
	
	bool User::IsEmpty()
	{
		if (0 == id && email == "" && name == "" && surname == "" && phone == "" && address == "" && password == "" &&
			activated == false && 0 == roleID)
			return true;
		return false;
	}

	void User::TrimStrings(std::string& uEmail, std::string& uName, std::string& uSurname, std::string& uPhone,
		std::string& uAddress, std::string& uPassword)
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
	}

	bool User::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string uName, std::string uSurname, std::string uPhone,
		std::string uAddress, int uRoleID, std::string& errorMessage)
	{
		User user;
		user.SetName(uName);
		user.SetSurname(uSurname);
		user.SetPhone(uPhone);
		user.SetAddress(uAddress);
		user.SetRoleID(uRoleID);
		std::string filter = user.GenerateFilter(ormasDal);
		std::vector<DataLayer::usersViewCollection> userVector = ormasDal.GetUsers(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == userVector.size())
		{
			return false;
		}
		errorMessage = "User with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool User::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		User user;
		user.SetName(name);
		user.SetSurname(surname);
		user.SetPhone(phone);
		user.SetAddress(address);
		user.SetRoleID(roleID);
		std::string filter = user.GenerateFilter(ormasDal);
		std::vector<DataLayer::usersViewCollection> userVector = ormasDal.GetUsers(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == userVector.size())
		{
			return false;
		}
		errorMessage = "User with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	void User::CreateAccount(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Currency currency;
		int currID = currency.GetMainTradeCurrencyID(ormasDal, errorMessage);
		if (0 != currID)
		{
			Balance balance;
			balance.SetUserID(id);
			balance.SetCurrencyID(currID);
			balance.SetValue(0);
			balance.CreateBalance(ormasDal, errorMessage);
		}
	}

	int User::GetUserAccoutID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage)
	{
		Balance balance;
		balance.SetUserID(id);
		balance.SetCurrencyID(cID);
		std::string filter = balance.GenerateFilter(ormasDal);
		std::vector<DataLayer::balancesViewCollection> balanceVector = ormasDal.GetBalances(errorMessage, filter);
		if (0 < balanceVector.size())
		{
			return std::get<0>(balanceVector.at(0));
		}
		return 0;
	}
}

