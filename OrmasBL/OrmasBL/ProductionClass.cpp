#include "stdafx.h"
#include "ProductionClass.h"

namespace BusinessLayer
{
	Production::Production(DataLayer::productionCollection pCollection)
	{
		id = std::get<0>(pCollection);
		productionDate = std::get<1>(pCollection);
		expiryDate = std::get<2>(pCollection);
		sessionStart = std::get<3>(pCollection);
		sessionEnd = std::get<4>(pCollection);
	}

	int Production::GetID()
	{
		return id;
	}

	std::string Production::GetProductionDate()
	{
		return productionDate;
	}

	std::string Production::GetExpiryDate()
	{
		return expiryDate;
	}

	std::string Production::GetSessionStart()
	{
		return sessionStart;
	}

	std::string Production::GetSessionEnd()
	{
		return sessionEnd;
	}

	void Production::SetID(int pID)
	{
		id = pID;
	}
	void Production::SetProductionDate(std::string pProductionDate)
	{
		productionDate = pProductionDate;
	}
	void Production::SetExpiryDate(std::string pExpiryDate)
	{
		expiryDate = pExpiryDate;
	}
	void Production::SetSessionStart(std::string pSessionStart)
	{
		sessionStart = pSessionStart;
	}
	void Production::SetSessionEnd(std::string pSessionEnd)
	{
		sessionEnd = pSessionEnd;
	}

	bool Production::CreateProduction(DataLayer::OrmasDal& ormasDal, std::string pProductionDate, std::string pExpiryDate,
		std::string pSessionStart, std::string pSessionEnd, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, pProductionDate, pExpiryDate, pSessionStart, pSessionEnd, errorMessage))
			return false;
		productionDate = pProductionDate;
		expiryDate = pExpiryDate;
		sessionStart = pSessionStart;
		sessionEnd = pSessionEnd;
		if (0 != id && ormasDal.CreateProduction(id, productionDate, expiryDate, sessionStart, sessionEnd, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Production::CreateProduction(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		if (0 != id &&ormasDal.CreateProduction(id, productionDate, expiryDate, sessionStart, sessionEnd, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Production::DeleteProduction(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		productionDate.clear();
		expiryDate.clear();
		sessionStart.clear();
		sessionEnd.clear();
		if (ormasDal.DeleteProductType(id, errorMessage))
		{
			id = 0;
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}
	bool Production::UpdateProduction(DataLayer::OrmasDal& ormasDal, std::string pProductionDate, std::string pExpiryDate,
		std::string pSessionStart, std::string pSessionEnd, std::string& errorMessage)
	{
		productionDate = pProductionDate;
		expiryDate = pExpiryDate;
		sessionStart = pSessionStart;
		sessionEnd = pSessionEnd;
		if (0 != id &&ormasDal.UpdateProduction(id, productionDate, expiryDate, sessionStart, sessionEnd, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Production::UpdateProduction(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id &&ormasDal.UpdateProduction(id, productionDate, expiryDate, sessionStart, sessionEnd, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string Production::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || !productionDate.empty() || !expiryDate.empty() || !sessionStart.empty() || !sessionEnd.empty())
		{
			return ormasDal.GetFilterForProduction(id, productionDate, expiryDate, sessionStart, sessionEnd);
		}
		return "";
	}
	bool Production::GetProductionByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		id = pID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::productionCollection> productionVector = ormasDal.GetProduction(errorMessage, filter);
		if (0 != productionVector.size())
		{
			id = std::get<0>(productionVector.at(0));
			productionDate = std::get<1>(productionVector.at(0));
			expiryDate = std::get<2>(productionVector.at(0));
			sessionStart = std::get<3>(productionVector.at(0));
			sessionEnd = std::get<4>(productionVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find production with this id";
		}
		return false;
	}
	
	bool Production::IsEmpty()
	{
		if (0 == id && productionDate == "" && expiryDate == "" && sessionStart == "" && sessionEnd == "")
			return true;
		return false;
	}

	void Production::Clear()
	{
		id = 0;
		productionDate.clear();
		expiryDate.clear();
		sessionEnd.clear();
		sessionStart.clear();
	}

	bool Production::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string pProductionDate, std::string pExpiryDate,
		std::string pSessionStart, std::string pSessionEnd, std::string& errorMessage)
	{
		Production production;
		production.SetProductionDate(pProductionDate);
		production.SetExpiryDate(pExpiryDate);
		production.SetSessionStart(pSessionStart);
		production.SetSessionEnd(pSessionEnd);
		std::string filter = production.GenerateFilter(ormasDal);
		std::vector<DataLayer::productionCollection> productionVector = ormasDal.GetProduction(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == productionVector.size())
		{
			return false;
		}
		errorMessage = "Production with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Production::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Production production;
		production.SetProductionDate(productionDate);
		production.SetExpiryDate(expiryDate);
		production.SetSessionStart(sessionStart);
		production.SetSessionEnd(sessionEnd);
		std::string filter = production.GenerateFilter(ormasDal);
		std::vector<DataLayer::productionCollection> productionVector = ormasDal.GetProduction(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == productionVector.size())
		{
			return false;
		}
		errorMessage = "Production with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}

