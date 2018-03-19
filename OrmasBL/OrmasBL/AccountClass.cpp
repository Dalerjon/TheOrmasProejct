#include "stdafx.h"
#include "AccountClass.h"
#include "ChartOfAccountsClass.h"
#include <boost/algorithm/string.hpp>

namespace BusinessLayer{
	Account::Account(DataLayer::accountsCollection aCollection)
	{
		id = std::get<0>(aCollection);
		number = std::get<1>(aCollection);
		startBalance = std::get<2>(aCollection);
		currentBalance = std::get<3>(aCollection);
		currencyID = std::get<4>(aCollection);
		statusID = std::get<5>(aCollection);
		openedDate = std::get<6>(aCollection);
		closedDate = std::get<7>(aCollection);
		details = std::get<8>(aCollection);
	}
	Account::Account()
	{
		id = 0;
		number = "";
		startBalance = 0.0;
		currentBalance = 0.0;
		currencyID = 0;
		statusID = 0;
		openedDate = "";
		closedDate = "";
		details = "";
	}

	int Account::GetID()
	{
		return id;
	}

	std::string Account::GetNumber()
	{
		return number;
	}

	double Account::GetStartBalance()
	{
		return startBalance;
	}

	double Account::GetCurrentBalance()
	{
		return currentBalance;
	}

	int Account::GetCurrencyID()
	{
		return currencyID;
	}
	
	int Account::GetStatusID()
	{
		return statusID;
	}

	std::string Account::GetOpenedDate()
	{
		return openedDate;
	}

	std::string Account::GetClosedDate()
	{
		return closedDate;
	}

	std::string Account::GetDetails()
	{
		return details;
	}

	void Account::SetID(int aID)
	{
		id = aID;
	}

	void Account::SetNumber(std::string aNumber)
	{
		number = aNumber;
	}

	void Account::SetStartBalance(double aStartBalance)
	{
		startBalance = aStartBalance;
	}

	void Account::SetCurrentBalance(double aCurrentBalance)
	{
		currentBalance = aCurrentBalance;
	}

	void Account::SetCurrencyID(int cID)
	{
		currencyID = cID;
	}

	void Account::SetStatusID(int sID)
	{
		statusID = sID;
	}

	void Account::SetOpenedDate(std::string aOpenedDate)
	{
		openedDate = aOpenedDate;
	}

	void Account::SetClosedDate(std::string aClosedDate)
	{
		closedDate = aClosedDate;
	}
	
	void Account::SetDetails(std::string aDetails)
	{
		details = aDetails;
	}

	bool Account::CreateAccount(DataLayer::OrmasDal &ormasDal, std::string aNumber, double aStartBalance, double aCurrentBalance, int cID,
		int sID, std::string aOpenedDate, std::string aClosedDate, std::string aDetails, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, aNumber, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		number = aNumber;
		startBalance = aStartBalance;
		currentBalance = aCurrentBalance;
		currencyID = cID;
		statusID = sID;
		openedDate = aOpenedDate;
		closedDate = aClosedDate;
		details = aDetails;
		if (0 != id && ormasDal.CreateAccount(id, number, startBalance, currentBalance, currencyID, statusID, openedDate, closedDate,
			details, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Account::CreateAccount(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		if (ormasDal.CreateAccount(id, number, startBalance, currentBalance, currencyID, statusID, openedDate, closedDate,
			details, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Account::DeleteAccount(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteAccount(id, errorMessage))
		{
			Clear();
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}

	bool Account::UpdateAccount(DataLayer::OrmasDal &ormasDal, std::string aNumber, double aStartBalance, double aCurrentBalance, int cID,
		int sID, std::string aOpenedDate, std::string aClosedDate, std::string aDetails, std::string& errorMessage)
	{
		number = aNumber;
		startBalance = aStartBalance;
		currentBalance = aCurrentBalance;
		currencyID = cID;
		statusID = sID;
		openedDate = aOpenedDate;
		closedDate = aClosedDate;
		details = aDetails;
		if (0 != id && ormasDal.UpdateAccount(id, number, startBalance, currentBalance, currencyID, statusID, openedDate, closedDate,
			details, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Account::UpdateAccount(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.UpdateAccount(id, number, startBalance, currentBalance, currencyID, statusID, openedDate, closedDate,
			details, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string Account::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !number.empty() || 0.0 != startBalance || 0.0 != currentBalance || 0 != currencyID || 0 != statusID 
			|| !openedDate.empty() || !closedDate.empty() || !details.empty())
		{
			return ormasDal.GetFilterForAccount(id, number, startBalance, currentBalance, currencyID, statusID, openedDate, closedDate,
				details);
		}
		return "";
	}

	bool Account::GetAccountByID(DataLayer::OrmasDal& ormasDal, int aID, std::string& errorMessage)
	{
		id = aID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::accountsViewCollection> accountVector = ormasDal.GetAccounts(errorMessage, filter);
		if (0 != accountVector.size())
		{
			id = std::get<0>(accountVector.at(0));
			number = std::get<1>(accountVector.at(0));
			startBalance = std::get<2>(accountVector.at(0));
			currentBalance = std::get<3>(accountVector.at(0));
			currencyID = std::get<6>(accountVector.at(0));
			statusID = std::get<7>(accountVector.at(0));
			openedDate = std::get<8>(accountVector.at(0));
			closedDate = std::get<9>(accountVector.at(0));
			details = std::get<10>(accountVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find account with this id";
		}
		return false;
	}

	bool Account::GetAccountByNumber(DataLayer::OrmasDal& ormasDal, std::string aNumber, std::string& errorMessage)
	{
		number = aNumber;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::accountsViewCollection> accountVector = ormasDal.GetAccounts(errorMessage, filter);
		if (0 != accountVector.size())
		{
			id = std::get<0>(accountVector.at(0));
			number = std::get<1>(accountVector.at(0));
			startBalance = std::get<2>(accountVector.at(0));
			currentBalance = std::get<3>(accountVector.at(0));
			currencyID = std::get<6>(accountVector.at(0));
			statusID = std::get<7>(accountVector.at(0));
			openedDate = std::get<8>(accountVector.at(0));
			closedDate = std::get<9>(accountVector.at(0));
			details = std::get<10>(accountVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find account with this id";
		}
		return false;
	}

	std::string Account::GenerateRawNumber(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		int countOfNulls;
		int genNumber = ormasDal.GenerateAccountID();
		std::string accNumber = "";
		std::string genNumberStr = std::to_string(genNumber);
		if (genNumberStr.length() < 15)
		{
			countOfNulls = 15 - genNumberStr.length();
			for (int i = 0; i < countOfNulls; i++)
			{
				accNumber.append("0");
			}
			accNumber.append(genNumberStr);
			return accNumber;
		}
		return "";
	}

	bool Account::IsEmpty()
	{
		if (0 == id && number.empty() && 0.0 == startBalance && 0.0 == currentBalance && 0 == currencyID && 0 == statusID 
			&& openedDate.empty() && closedDate.empty() && details.empty())
			return true;
		return false;
	}

	void Account::Clear()
	{
		id = 0;
		number = "";
		startBalance = 0.0;
		currentBalance = 0.0;
		currencyID = 0;
		statusID = 0;
		openedDate = "";
		closedDate = "";
		details = "";
	}

	bool Account::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string aNumber, std::string& errorMessage)
	{
		Account account;
		account.SetNumber(aNumber);
		std::string filter = account.GenerateFilter(ormasDal);
		std::vector<DataLayer::accountsViewCollection> accountVector = ormasDal.GetAccounts(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == accountVector.size())
		{
			return false;
		}
		errorMessage = "Account with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Account::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Account account;
		account.SetNumber(number);
		std::string filter = account.GenerateFilter(ormasDal);
		std::vector<DataLayer::accountsViewCollection> accountVector = ormasDal.GetAccounts(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == accountVector.size())
		{
			return false;
		}
		errorMessage = "Account with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	std::string Account::GetName(DataLayer::OrmasDal& ormasDal)
	{
		ChartOfAccounts chartOfAccounts;
		std::vector<DataLayer::chartOfAccountsViewCollection> chartOfAccountssVector;
		if (!this->GetNumber().empty() && this->GetNumber().length() > 0)
		{
			std::string numberOfAccount = this->GetNumber().substr(0, 4);
			std::string partentNumberOfAccount = this->GetNumber().substr(0, 2);
			std::string childNumberOfAccount = this->GetNumber().substr(2, 4);
			if (0 == childNumberOfAccount.compare("00"))
			{
				chartOfAccounts.SetNumber(std::stoi(partentNumberOfAccount));
				std::string filter = chartOfAccounts.GenerateFilter(ormasDal);
				ormasDal.GetChartOfAccounts(errorMessage, filter);
				if (0 < chartOfAccountssVector.size())
				{
					return std::get<2>(chartOfAccountssVector.at(0));
				}
			}
			else
			{
				chartOfAccounts.SetNumber(std::stoi(numberOfAccount));
				std::string filter = chartOfAccounts.GenerateFilter(ormasDal);
				ormasDal.GetChartOfAccounts(errorMessage, filter);
				if (0 < chartOfAccountssVector.size())
				{
					return std::get<2>(chartOfAccountssVector.at(0));
				}
			}
		}
		return nullptr;
	}
}