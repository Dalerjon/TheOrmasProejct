// OrmasBL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "OrmasBL.h"
#include <typeinfo>
#include <math.h>

namespace BusinessLayer{
	
	OrmasBL::OrmasBL()
	{
	}
	
	OrmasBL::OrmasBL(const OrmasBL &oBL)
	{ 
		ormasDal = oBL.ormasDal; 
	}
	
	OrmasBL::~OrmasBL()
	{
	}

	bool OrmasBL::ConnectToDB(std::string dbname, std::string username, std::string password, std::string host, int port)
	{
		if (ormasDal.ConnectToDB(dbname, username, password, host, port))
			return true;
		return false;
	}
	
	DataLayer::OrmasDal& OrmasBL::GetOrmasDal()
	{
		return ormasDal;
	}

	int OrmasBL::GenerateID()
	{
		return ormasDal.GenerateID();
	}

	bool OrmasBL::StartTransaction(std::string& errorMessage)
	{
		return ormasDal.StartTransaction(errorMessage);
	}
	bool OrmasBL::CommitTransaction(std::string& errorMessage)
	{
		return ormasDal.CommitTransaction(errorMessage);
	}
	bool OrmasBL::CancelTransaction(std::string& errorMessage)
	{
		return ormasDal.CancelTransaction(errorMessage);
	}

	template<>
	std::vector<Company> OrmasBL::GetAllDataForClass<Company>(std::string& errorMessage, std::string filter)
	{
		std::vector<Company> vecForCompany;
		std::vector<DataLayer::companiesCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetCompanies(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetCompanies(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForCompany.push_back(Company(data));
			}
		}
		return vecForCompany;
	}

	template<>
	std::vector<Currency> OrmasBL::GetAllDataForClass<Currency>(std::string& errorMessage, std::string filter)
	{
		std::vector<Currency> vecForCurrency;
		std::vector<DataLayer::currenciesCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetCurrencies(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetCurrencies(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForCurrency.push_back(Currency(data));
			}
		}
		return vecForCurrency;
	}

	template<>
	std::vector<Measure> OrmasBL::GetAllDataForClass<Measure>(std::string& errorMessage, std::string filter)
	{
		std::vector<Measure> vecForMeasure;
		std::vector<DataLayer::measuresCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetMeasures(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetMeasures(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForMeasure.push_back(Measure(data));
			}
		}
		return vecForMeasure;
	}

	template<>
	std::vector<OrderView> OrmasBL::GetAllDataForClass<OrderView>(std::string& errorMessage, std::string filter)
	{
		std::vector<OrderView> vecForOrder;
		std::vector<DataLayer::ordersViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetOrders(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetOrders(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForOrder.push_back(OrderView(data));
			}
		}
		return vecForOrder;
	}

	template<>
	std::vector<ProductView> OrmasBL::GetAllDataForClass<ProductView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ProductView> vecForProduct;
		std::vector<DataLayer::productsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetProducts(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetProducts(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProduct.push_back(ProductView(data));
			}
		}
		return vecForProduct;
	}

	template<>
	std::vector<ProductListView> OrmasBL::GetAllDataForClass<ProductListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ProductListView> vecForProductList;
		std::vector<DataLayer::productListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetProductLists(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetProductLists(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProductList.push_back(ProductListView(data));
			}
		}
		return vecForProductList;
	}

	template<>
	std::vector<ProductType> OrmasBL::GetAllDataForClass<ProductType>(std::string& errorMessage, std::string filter)
	{
		std::vector<ProductType> vecForProductType;
		std::vector<DataLayer::productTypeCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetProductTypes(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetProductTypes(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProductType.push_back(ProductType(data));
			}
		}
		return vecForProductType;
	}
	
	template<>
	std::vector<Production> OrmasBL::GetAllDataForClass<Production>(std::string& errorMessage, std::string filter)
	{
		std::vector<Production> vecForProduction;
		std::vector<DataLayer::productionCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetProduction(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetProduction(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProduction.push_back(Production(data));
			}
		}
		return vecForProduction;
	}

	template<>
	std::vector<Location> OrmasBL::GetAllDataForClass<Location>(std::string& errorMessage, std::string filter)
	{
		std::vector<Location> vecForLocation;
		std::vector<DataLayer::locationsCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetLocations(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetLocations(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForLocation.push_back(Location(data));
			}
		}
		return vecForLocation;
	}

	template<>
	std::vector<ReturnView> OrmasBL::GetAllDataForClass<ReturnView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ReturnView> vecForReturn;
		std::vector<DataLayer::returnsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetReturns(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetReturns(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForReturn.push_back(ReturnView(data));
			}
		}
		return vecForReturn;
	}

	template<>
	std::vector<Role> OrmasBL::GetAllDataForClass<Role>(std::string& errorMessage, std::string filter)
	{
		std::vector<Role> vecForRole;
		std::vector<DataLayer::rolesCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetRoles(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetRoles(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForRole.push_back(Role(data));
			}
		}
		return vecForRole;
	}

	template<>
	std::vector<Status> OrmasBL::GetAllDataForClass<Status>(std::string& errorMessage, std::string filter)
	{
		std::vector<Status> vecForStatus;
		std::vector<DataLayer::statusCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetStatus(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetStatus(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForStatus.push_back(Status(data));
			}
		}
		return vecForStatus;
	}

	template<>
	std::vector<UserView> OrmasBL::GetAllDataForClass<UserView>(std::string& errorMessage, std::string filter)
	{
		std::vector<UserView> vecForUser;
		std::vector<DataLayer::usersViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetUsers(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetUsers(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForUser.push_back(UserView(data));
			}
		}
		return vecForUser;
	}
	
	bool OrmasBL::CreateCompany(BusinessLayer::Company* company, std::string& errorMessage)
	{
		try
		{
			if (!company->GetName().empty() && !company->GetAddress().empty() && !company->GetPhone().empty())
			{
				return company->CreateCompany(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Company name, address and phone must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateCompany(BusinessLayer::Company* company, std::string& errorMessage)
	{
		try
		{
			if (!company->GetName().empty() && !company->GetAddress().empty() && !company->GetPhone().empty())
			{
				return company->UpdateCompany(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Company name, address and phone must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteCompany(BusinessLayer::Company* company, std::string& errorMessage)
	{
		try
		{
			if (0 != company->GetID())
			{
				return company->DeleteCompany(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Company ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateCurrency(BusinessLayer::Currency* currency, std::string& errorMessage)
	{
		try
		{
			if (0 != currency->GetCode() && !currency->GetName().empty() && !currency->GetShortName().empty() && 0 != currency->GetUnit())
			{
				return currency->CreateCurrency(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Currency code, name and short name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateCurrency(BusinessLayer::Currency* currency, std::string& errorMessage)
	{
		try
		{
			if (0 != currency->GetCode() && !currency->GetName().empty() && !currency->GetShortName().empty() && 0 != currency->GetUnit())
			{
				return currency->UpdateCurrency(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Currency code, name and short name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteCurrency(BusinessLayer::Currency* currency, std::string& errorMessage)
	{
		try
		{
			if (0 != currency->GetID())
			{
				return currency->DeleteCurrency(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Currency ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateMeasure(BusinessLayer::Measure* measure, std::string& errorMessage)
	{
		try
		{
			if (!measure->GetName().empty() && !measure->GetShortName().empty() && 0 != measure->GetUnit())
			{
				return measure->CreateMeasure(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Measure name and short name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateMeasure(BusinessLayer::Measure* measure, std::string& errorMessage)
	{
		try
		{
			if (!measure->GetName().empty() && !measure->GetShortName().empty() && 0 != measure->GetUnit())
			{
				return measure->UpdateMeasure(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Measure name and short name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteMeasure(BusinessLayer::Measure* measure, std::string& errorMessage)
	{
		try
		{
			if (0 != measure->GetID())
			{
				return measure->DeleteMeasure(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Measure ID is 0. Some thing goes wrong!";
			}			
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider."; 
		}
		return false;
	}

	bool OrmasBL::CreateProductType(BusinessLayer::ProductType* pType, std::string& errorMessage)
	{
		try
		{
			if (!pType->GetName().empty() && !pType->GetShortName().empty())
			{
				return pType->CreateProductType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product type name and short name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateProductType(BusinessLayer::ProductType* pType, std::string& errorMessage)
	{
		try
		{
			if (!pType->GetName().empty() && !pType->GetShortName().empty())
			{
				return pType->UpdateProductType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product type name and short name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteProductType(BusinessLayer::ProductType* pType, std::string& errorMessage)
	{
		try
		{
			if (0 != pType->GetID())
			{
				return pType->DeleteProductType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product type ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateLocation(BusinessLayer::Location* location, std::string& errorMessage)
	{
		try
		{
			if (!location->GetCountryName().empty() && !location->GetCountryCode().empty() && !location->GetRegionName().empty()
				&& !location->GetCityName().empty())
			{
				return location->CreateLocation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Location code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateLocation(BusinessLayer::Location* location, std::string& errorMessage)
	{
		try
		{
			if (!location->GetCountryName().empty() && !location->GetCountryCode().empty() && !location->GetRegionName().empty()
				&& !location->GetCityName().empty())
			{
				return location->UpdateLocation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Location code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteLocation(BusinessLayer::Location* location, std::string& errorMessage)
	{
		try
		{
			if (0 != location->GetID())
			{
				return location->DeleteLocation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Location ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateRole(BusinessLayer::Role* role, std::string& errorMessage)
	{
		try
		{
			if (!role->GetName().empty())
			{
				return role->CreateRole(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Role name must not be empty. Please fill up it!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateRole(BusinessLayer::Role* role, std::string& errorMessage)
	{
		try
		{
			if (!role->GetName().empty())
			{
				return role->UpdateRole(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Role name must not be empty. Please fill up it!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteRole(BusinessLayer::Role* role, std::string& errorMessage)
	{
		try
		{
			if (0 != role->GetID())
			{
				return role->DeleteRole(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Role ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}
	bool OrmasBL::CreateStatus(BusinessLayer::Status* status, std::string& errorMessage)
	{
		try
		{
			if (!status->GetCode().empty() && !status->GetName().empty())
			{
				return status->CreateStatus(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Status code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateStatus(BusinessLayer::Status* status, std::string& errorMessage)
	{
		try
		{
			if (!status->GetCode().empty() && !status->GetName().empty())
			{
				return status->UpdateStatus(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Status code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteStatus(BusinessLayer::Status* status, std::string& errorMessage)
	{
		try
		{
			if (0 != status->GetID())
			{
				return status->DeleteStatus(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Status ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateUser(BusinessLayer::User* user, std::string& errorMessage)
	{
		try
		{
			if (!user->GetName().empty() && !user->GetPhone().empty() && !user->GetAddress().empty() && !user->GetFirm().empty()
				&& !user->GetFirmNumber().empty() && !user->GetPassword().empty() && 0 != user->GetLocationID() && 0 != user->GetRoleID())
			{
				return user->CreateUser(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateUser(BusinessLayer::User* user, std::string& errorMessage)
	{
		try
		{
			if (!user->GetName().empty() && !user->GetPhone().empty() && !user->GetAddress().empty() && !user->GetFirm().empty()
				&& !user->GetFirmNumber().empty() && !user->GetPassword().empty() && 0 != user->GetLocationID() && 0 != user->GetRoleID())
			{
				return user->UpdateUser(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteUser(BusinessLayer::User* user, std::string& errorMessage)
	{
		try
		{
			if (0 != user->GetID())
			{
				return user->DeleteUser(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}
	
	bool OrmasBL::CreateOrder(BusinessLayer::Order* order, std::string& errorMessage)
	{
		try
		{
			if (!order->GetDate().empty() && 0 != order->GetUserID() && 0 != order->GetCount()
				&& 0 != order->GetSum() && 0 != order->GetStatusID() && 0 != order->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, order->GetCurrencyID(), errorMessage))
				{
					roundSum = round(order->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				order->SetSum(roundSum);
				return order->CreateOrder(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateOrder(BusinessLayer::Order* order, std::string& errorMessage)
	{
		try
		{
			if (!order->GetDate().empty() && 0 != order->GetUserID() && 0 != order->GetCount() 
				&& 0 != order->GetSum() && 0 != order->GetStatusID() && 0 != order->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, order->GetCurrencyID(), errorMessage))
				{
					roundSum = round(order->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				order->SetSum(roundSum);
				return order->UpdateOrder(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteOrder(BusinessLayer::Order* order, std::string& errorMessage)
	{
		try
		{
			if (0 != order->GetID())
			{
				return order->DeleteOrder(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Order ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateReturn(BusinessLayer::Return* ret, std::string& errorMessage)
	{
		try
		{
			if (!ret->GetDate().empty() && 0 != ret->GetUserID() && 0 != ret->GetCount() 
				&& 0 != ret->GetSum() && 0 != ret->GetStatusID() && 0 != ret->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, ret->GetCurrencyID(), errorMessage))
				{
					roundSum = round(ret->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				ret->SetSum(roundSum);
				return ret->CreateReturn(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateReturn(BusinessLayer::Return* ret, std::string& errorMessage)
	{
		try
		{
			if (!ret->GetDate().empty() && 0 != ret->GetUserID() && 0 != ret->GetCount() 
				&& 0 != ret->GetSum() && 0 != ret->GetStatusID() && 0 != ret->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, ret->GetCurrencyID(), errorMessage))
				{
					roundSum = round(ret->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				ret->SetSum(roundSum);
				return ret->UpdateReturn(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteReturn(BusinessLayer::Return* ret, std::string& errorMessage)
	{
		try
		{
			if (0 != ret->GetID())
			{
				return ret->DeleteReturn(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Return ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}
	bool OrmasBL::CreateProduction(BusinessLayer::Production* production, std::string& errorMessage)
	{
		try
		{
			if (!production->GetProductionDate().empty() && !production->GetExpiryDate().empty() && !production->GetSessionStart().empty()
				&& !production->GetSessionEnd().empty())
			{
				return production->CreateProduction(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateProduction(BusinessLayer::Production* production, std::string& errorMessage)
	{
		try
		{
			if (!production->GetProductionDate().empty() && !production->GetExpiryDate().empty() && !production->GetSessionStart().empty()
				&& !production->GetSessionEnd().empty())
			{
				return production->UpdateProduction(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteProduction(BusinessLayer::Production* production, std::string& errorMessage)
	{
		try
		{
			if (0 != production->GetID())
			{
				return production->DeleteProduction(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Production ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}
	
	bool OrmasBL::CreateProduct(BusinessLayer::Product* product, std::string& errorMessage)
	{
		try
		{
			if (0 != product->GetCompanyID() && !product->GetName().empty() && 0 != product->GetVolume() && 0 != product->GetMeasureID()
				&& 0 != product->GetPrice() && 0!= product->GetProductTypeID() && 0 != product->GetShelfLife() && 0 != product->GetCurrencyID()) 
			{
				double roundPrice = 0;
				double roundVolume = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, product->GetCurrencyID(), errorMessage))
				{
					roundPrice = round(product->GetPrice() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				Measure *mea = new Measure();
				if (mea->GetMeasureByID(ormasDal, product->GetMeasureID(), errorMessage))
				{
					roundVolume = round(product->GetVolume() * mea->GetUnit()) / mea->GetUnit();
				}
				else
				{
					return false;
				}
				delete mea;
				product->SetVolume(roundVolume);
				product->SetPrice(roundPrice);
				return product->CreateProduct(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateProduct(BusinessLayer::Product* product, std::string& errorMessage)
	{
		try
		{
			if (0 != product->GetCompanyID() && !product->GetName().empty() && 0 != product->GetVolume() && 0 != product->GetMeasureID()
				&& 0 != product->GetPrice() && 0 != product->GetProductTypeID() && 0 != product->GetShelfLife() && 0 != product->GetCurrencyID())
			{
				double roundPrice = 0;
				double roundVolume = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, product->GetCurrencyID(), errorMessage))
				{
					roundPrice = round(product->GetPrice() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				Measure *mea = new Measure();
				if (mea->GetMeasureByID(ormasDal, product->GetMeasureID(), errorMessage))
				{
					roundVolume = round(product->GetVolume() * mea->GetUnit()) / mea->GetUnit();
				}
				else
				{
					return false;
				}
				delete mea;
				product->SetVolume(roundVolume);
				product->SetPrice(roundPrice);
				return product->UpdateProduct(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteProduct(BusinessLayer::Product* product, std::string& errorMessage)
	{
		try
		{
			if (0 != product->GetID())
			{
				return product->DeleteProduct(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateProductList(BusinessLayer::ProductList* productList, std::string& errorMessage)
	{
		try
		{
			if ((0 != productList->GetOrderID() || 0 != productList->GetReturnID() || 0 != productList->GetProductionID())
				&& 0 != productList->GetProductID() && 0 != productList->GetProductID() && 0 != productList->GetCount() 
				&& 0 != productList->GetSum() && 0 != productList->GetStatusID() && 0!= productList->GetCurrencyID())
			{
				return productList->CreateProductList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateProductList(BusinessLayer::ProductList* productList, std::string& errorMessage)
	{
		try
		{
			if ((0 != productList->GetOrderID() || 0 != productList->GetReturnID() || 0 != productList->GetProductionID())
				&& 0 != productList->GetProductID() && 0 != productList->GetProductID() && 0 != productList->GetCount()
				&& 0 != productList->GetSum() && 0 != productList->GetStatusID() && 0 != productList->GetCurrencyID())
			{
				return productList->UpdateProductList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One of feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteProductList(BusinessLayer::ProductList* productList, std::string& errorMessage)
	{
		try
		{
			if (0 != productList->GetID())
			{
				return productList->DeleteProductList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}
}
