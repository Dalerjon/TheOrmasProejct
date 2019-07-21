#include "stdafx.h"
#include "AccountableTransactionClass.h"
#include <boost/algorithm/string.hpp>

namespace BusinessLayer{
	AccountableTransaction::AccountableTransaction(DataLayer::accountableTransactionCollection aCollection)
	{
		id = std::get<0>(aCollection);
		accountableID = std::get<1>(aCollection);
		startValue = std::get<2>(aCollection);
		endValue = std::get<3>(aCollection);
		operationID = std::get<4>(aCollection);
	}
	AccountableTransaction::AccountableTransaction()
	{
		id = 0;
		accountableID = 0;
		startValue = 0.0;
		endValue = 0.0;
		operationID = 0;
	}

	int AccountableTransaction::GetID()
	{
		return id;
	}

	int AccountableTransaction::GetAccountableID()
	{
		return accountableID;
	}


	double AccountableTransaction::GetStartValue()
	{
		return startValue;
	}

	double AccountableTransaction::GetEndValue()
	{
		return endValue;
	}

	int AccountableTransaction::GetOperationID()
	{
		return operationID;
	}


	void AccountableTransaction::SetID(int aID)
	{
		id = aID;
	}

	void AccountableTransaction::SetAccountableID(int acID)
	{
		accountableID = acID;
	}

	void AccountableTransaction::SetStartValue(double aStartValue)
	{
		startValue = aStartValue;
	}

	void AccountableTransaction::SetEndValue(double aEndValue)
	{
		endValue = aEndValue;
	}

	void AccountableTransaction::SetOperationID(int oID)
	{
		operationID = oID;
	}


	bool AccountableTransaction::CreateAccountableTransaction(DataLayer::OrmasDal &ormasDal, int aID, double aStartValue, double aEndValue, int oID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, aID, startValue, endValue, oID, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		accountableID = aID;
		startValue = aStartValue;
		endValue = aEndValue;
		operationID = oID;
		if (0 != id && ormasDal.CreateAccountableTransaction(id, accountableID, startValue, endValue, operationID,  errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool AccountableTransaction::CreateAccountableTransaction(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		if (ormasDal.CreateAccountableTransaction(id, accountableID, startValue, endValue, operationID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool AccountableTransaction::DeleteAccountableTransaction(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteAccountableTransaction(id, errorMessage))
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

	bool AccountableTransaction::UpdateAccountableTransaction(DataLayer::OrmasDal &ormasDal, int aID, double aStartValue, double aEndValue, int oID, std::string& errorMessage)
	{
		accountableID = aID;
		startValue = aStartValue;
		endValue = aEndValue;
		operationID = oID;
		if (0 != id && ormasDal.UpdateAccountableTransaction(id, accountableID, startValue, endValue, operationID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool AccountableTransaction::UpdateAccountableTransaction(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.UpdateAccountableTransaction(id, accountableID, startValue, endValue, operationID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string AccountableTransaction::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != accountableID || 0.0 != startValue || 0.0 != endValue || 0 != operationID)
		{
			return ormasDal.GetFilterForAccountableTransaction(id, accountableID, startValue, endValue, operationID);
		}
		return "";
	}

	bool AccountableTransaction::GetAccountableTransactionByID(DataLayer::OrmasDal& ormasDal, int atID, std::string& errorMessage)
	{
		if (atID <= 0)
			return false;
		id = atID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::accountableTransactionCollection> accountableTransactionVector = ormasDal.GetAccountableTransaction(errorMessage, filter);
		if (0 != accountableTransactionVector.size())
		{
			id = std::get<0>(accountableTransactionVector.at(0));
			accountableID = std::get<1>(accountableTransactionVector.at(0));
			startValue = std::get<2>(accountableTransactionVector.at(0));
			endValue = std::get<3>(accountableTransactionVector.at(0));
			operationID = std::get<4>(accountableTransactionVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find accountable transaction with this id";
		}
		return false;
	}

	bool AccountableTransaction::GetAccountableTransactionByAccountableID(DataLayer::OrmasDal& ormasDal, int aID, std::string& errorMessage)
	{
		if (aID <= 0)
			return false;
		accountableID = aID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::accountableTransactionCollection> accountableTransactionVector = ormasDal.GetAccountableTransaction(errorMessage, filter);
		if (0 != accountableTransactionVector.size())
		{
			id = std::get<0>(accountableTransactionVector.at(0));
			accountableID = std::get<1>(accountableTransactionVector.at(0));
			startValue = std::get<2>(accountableTransactionVector.at(0));
			endValue = std::get<3>(accountableTransactionVector.at(0));
			operationID = std::get<4>(accountableTransactionVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find accountable transaction with this id";
		}
		return false;
	}

	bool AccountableTransaction::GetAccountableTransactionByOperationID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		operationID = oID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::accountableTransactionCollection> accountableTransactionVector = ormasDal.GetAccountableTransaction(errorMessage, filter);
		if (0 != accountableTransactionVector.size())
		{
			id = std::get<0>(accountableTransactionVector.at(0));
			accountableID = std::get<1>(accountableTransactionVector.at(0));
			startValue = std::get<2>(accountableTransactionVector.at(0));
			endValue = std::get<3>(accountableTransactionVector.at(0));
			operationID = std::get<4>(accountableTransactionVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find accountable transaction with this id";
		}
		return false;
	}

	bool AccountableTransaction::IsEmpty()
	{
		if (0 == id && 0 == accountableID && 0.0 == startValue && 0.0 == endValue && 0.0 == operationID)
			return true;
		return false;
	}

	

	void AccountableTransaction::Clear()
	{
		id = 0;
		accountableID = 0;
		startValue = 0.0;
		endValue = 0.0;
		operationID = 0;
	}

	bool AccountableTransaction::IsDuplicate(DataLayer::OrmasDal& ormasDal, int aID, double aStartValue, double aEndValue, int oID, std::string& errorMessage)
	{
		AccountableTransaction accountableTransaction;
		accountableTransaction.Clear();
		errorMessage.clear();
		accountableTransaction.SetAccountableID(aID);
		accountableTransaction.SetStartValue(aStartValue);
		accountableTransaction.SetEndValue(aEndValue);
		accountableTransaction.SetOperationID(oID);
		std::string filter = accountableTransaction.GenerateFilter(ormasDal);
		std::vector<DataLayer::accountableTransactionCollection> accountableTransactionVector = ormasDal.GetAccountableTransaction(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == accountableTransactionVector.size())
		{
			return false;
		}
		errorMessage = "Accountable transaction with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool AccountableTransaction::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		AccountableTransaction accountableTransaction;
		accountableTransaction.Clear();
		errorMessage.clear();
		accountableTransaction.SetAccountableID(accountableID);
		accountableTransaction.SetStartValue(startValue);
		accountableTransaction.SetEndValue(endValue);
		accountableTransaction.SetOperationID(operationID);
		std::string filter = accountableTransaction.GenerateFilter(ormasDal);
		std::vector<DataLayer::accountableTransactionCollection> accountableTransactionVector = ormasDal.GetAccountableTransaction(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == accountableTransactionVector.size())
		{
			return false;
		}
		errorMessage = "Accountable transaction with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}