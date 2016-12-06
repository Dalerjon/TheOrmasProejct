// OrmasBL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "OrmasBL.h"
#include <typeinfo>

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
	std::vector<Product> OrmasBL::GetAllDataForClass<Product>(std::string& errorMessage, std::string filter)
	{
		std::vector<Product> vecForProduct;
		std::vector<DataLayer::productsCollection> dataCollection;
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
				vecForProduct.push_back(Product(data));
			}
		}
		return vecForProduct;
	}

	template<>
	std::vector<ProductList> OrmasBL::GetAllDataForClass<ProductList>(std::string& errorMessage, std::string filter)
	{
		std::vector<ProductList> vecForProductList;
		std::vector<DataLayer::productListCollection> dataCollection;
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
				vecForProductList.push_back(ProductList(data));
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
	std::vector<User> OrmasBL::GetAllDataForClass<User>(std::string& errorMessage, std::string filter)
	{
		std::vector<User> vecForUser;
		std::vector<DataLayer::usersCollection> dataCollection;
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
				vecForUser.push_back(User(data));
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
			if (!currency->GetName().empty() && !currency->GetShortName().empty())
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
			if (0 != currency->GetCode() && !currency->GetName().empty() && !currency->GetShortName().empty())
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
			if (!measure->GetName().empty() && !measure->GetShortName().empty())
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
			if (!measure->GetName().empty() && !measure->GetShortName().empty())
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
				errorMessage = "Error! Role ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}
}
