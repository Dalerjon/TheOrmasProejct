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

	
	void OrmasBL::SetDBParams(std::string dbname, std::string username, std::string password, std::string host, int port)
	{
		ormasDal.SetDBParams(dbname, username, password, host, port);
	}

	
	template<>
	std::vector<Company> OrmasBL::GetAllDataForClass<Company>()
	{
		std::vector<Company> vecForCompany;
		std::vector<DataLayer::companiesCollection> dataCollection = ormasDal.GetCompanies(ormasDal.GetConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForCompany.push_back(Company(data));
			}
		}
		return vecForCompany;
	}

	template<>
	std::vector<Currency> OrmasBL::GetAllDataForClass<Currency>()
	{
		std::vector<Currency> vecForCurrency;
		std::vector<DataLayer::currenciesCollection> dataCollection = ormasDal.GetCurrencies(ormasDal.GetConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForCurrency.push_back(Currency(data));
			}
		}
		return vecForCurrency;
	}

	template<>
	std::vector<Measure> OrmasBL::GetAllDataForClass<Measure>()
	{
		std::vector<Measure> vecForMeasure;
		std::vector<DataLayer::measuresCollection> dataCollection = ormasDal.GetMeasures(ormasDal.GetConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForMeasure.push_back(Measure(data));
			}
		}
		return vecForMeasure;
	}

	template<>
	std::vector<Order> OrmasBL::GetAllDataForClass<Order>()
	{
		std::vector<Order> vecForOrder;
		std::vector<DataLayer::ordersCollection> dataCollection = ormasDal.GetOrders(ormasDal.GetConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForOrder.push_back(Order(data));
			}
		}
		return vecForOrder;
	}

	template<>
	std::vector<Product> OrmasBL::GetAllDataForClass<Product>()
	{
		std::vector<Product> vecForProduct;
		std::vector<DataLayer::productsCollection> dataCollection = ormasDal.GetProducts(ormasDal.GetConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProduct.push_back(Product(data));
			}
		}
		return vecForProduct;
	}

	template<>
	std::vector<ProductList> OrmasBL::GetAllDataForClass<ProductList>()
	{
		std::vector<ProductList> vecForProductList;
		std::vector<DataLayer::productListCollection> dataCollection = ormasDal.GetProductList(ormasDal.GetConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProductList.push_back(ProductList(data));
			}
		}
		return vecForProductList;
	}

	template<>
	std::vector<ProductType> OrmasBL::GetAllDataForClass<ProductType>()
	{
		std::vector<ProductType> vecForProductType;
		std::vector<DataLayer::productTypeCollection> dataCollection = ormasDal.GetProductType(ormasDal.GetConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProductType.push_back(ProductType(data));
			}
		}
		return vecForProductType;
	}
	
	template<>
	std::vector<Region> OrmasBL::GetAllDataForClass<Region>()
	{
		std::vector<Region> vecForRegion;
		std::vector<DataLayer::regionsCollection> dataCollection = ormasDal.GetRegions(ormasDal.GetConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForRegion.push_back(Region(data));
			}
		}
		return vecForRegion;
	}

	template<>
	std::vector<Return> OrmasBL::GetAllDataForClass<Return>()
	{
		std::vector<Return> vecForReturn;
		std::vector<DataLayer::returnsCollection> dataCollection = ormasDal.GetReturns(ormasDal.GetConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForReturn.push_back(Return(data));
			}
		}
		return vecForReturn;
	}

	template<>
	std::vector<Role> OrmasBL::GetAllDataForClass<Role>()
	{
		std::vector<Role> vecForRole;
		std::vector<DataLayer::rolesCollection> dataCollection = ormasDal.GetRoles(ormasDal.GetConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForRole.push_back(Role(data));
			}
		}
		return vecForRole;
	}

	template<>
	std::vector<Status> OrmasBL::GetAllDataForClass<Status>()
	{
		std::vector<Status> vecForStatus;
		std::vector<DataLayer::statusCollection> dataCollection = ormasDal.GetStatus(ormasDal.GetConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForStatus.push_back(Status(data));
			}
		}
		return vecForStatus;
	}

	template<>
	std::vector<User> OrmasBL::GetAllDataForClass<User>()
	{
		std::vector<User> vecForUser;
		std::vector<DataLayer::usersCollection> dataCollection = ormasDal.GetUsers(ormasDal.GetConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForUser.push_back(User(data));
			}
		}
		return vecForUser;
	}
}
