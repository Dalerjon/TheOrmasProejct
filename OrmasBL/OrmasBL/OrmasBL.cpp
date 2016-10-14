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

	
	void OrmasBL::setDBParams(std::string dbname, std::string username, std::string password, std::string host, int port)
	{
		ormasDal.setDBParams(dbname, username, password, host, port);
	}

	
	template<>
	std::vector<Company> OrmasBL::getAllDataForClass<Company>()
	{
		std::vector<Company> vecForCompany;
		std::vector<DataLayer::companiesCollection> dataCollection = ormasDal.getCompanies(ormasDal.getConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForCompany.push_back(Company(data));
			}
		}
		return vecForCompany;
	}

	template<>
	std::vector<Currency> OrmasBL::getAllDataForClass<Currency>()
	{
		std::vector<Currency> vecForCurrency;
		std::vector<DataLayer::currenciesCollection> dataCollection = ormasDal.getCurrencies(ormasDal.getConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForCurrency.push_back(Currency(data));
			}
		}
		return vecForCurrency;
	}

	template<>
	std::vector<Measure> OrmasBL::getAllDataForClass<Measure>()
	{
		std::vector<Measure> vecForMeasure;
		std::vector<DataLayer::measuresCollection> dataCollection = ormasDal.getMeasures(ormasDal.getConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForMeasure.push_back(Measure(data));
			}
		}
		return vecForMeasure;
	}

	template<>
	std::vector<Order> OrmasBL::getAllDataForClass<Order>()
	{
		std::vector<Order> vecForOrder;
		std::vector<DataLayer::ordersCollection> dataCollection = ormasDal.getOrders(ormasDal.getConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForOrder.push_back(Order(data));
			}
		}
		return vecForOrder;
	}

	template<>
	std::vector<Product> OrmasBL::getAllDataForClass<Product>()
	{
		std::vector<Product> vecForProduct;
		std::vector<DataLayer::productsCollection> dataCollection = ormasDal.getProducts(ormasDal.getConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProduct.push_back(Product(data));
			}
		}
		return vecForProduct;
	}

	template<>
	std::vector<ProductList> OrmasBL::getAllDataForClass<ProductList>()
	{
		std::vector<ProductList> vecForProductList;
		std::vector<DataLayer::productListCollection> dataCollection = ormasDal.getProductList(ormasDal.getConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProductList.push_back(ProductList(data));
			}
		}
		return vecForProductList;
	}

	template<>
	std::vector<ProductType> OrmasBL::getAllDataForClass<ProductType>()
	{
		std::vector<ProductType> vecForProductType;
		std::vector<DataLayer::productTypeCollection> dataCollection = ormasDal.getProductType(ormasDal.getConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProductType.push_back(ProductType(data));
			}
		}
		return vecForProductType;
	}
	
	template<>
	std::vector<Region> OrmasBL::getAllDataForClass<Region>()
	{
		std::vector<Region> vecForRegion;
		std::vector<DataLayer::regionsCollection> dataCollection = ormasDal.getRegions(ormasDal.getConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForRegion.push_back(Region(data));
			}
		}
		return vecForRegion;
	}

	template<>
	std::vector<Return> OrmasBL::getAllDataForClass<Return>()
	{
		std::vector<Return> vecForReturn;
		std::vector<DataLayer::returnsCollection> dataCollection = ormasDal.getReturns(ormasDal.getConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForReturn.push_back(Return(data));
			}
		}
		return vecForReturn;
	}

	template<>
	std::vector<Role> OrmasBL::getAllDataForClass<Role>()
	{
		std::vector<Role> vecForRole;
		std::vector<DataLayer::rolesCollection> dataCollection = ormasDal.getRoles(ormasDal.getConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForRole.push_back(Role(data));
			}
		}
		return vecForRole;
	}

	template<>
	std::vector<Status> OrmasBL::getAllDataForClass<Status>()
	{
		std::vector<Status> vecForStatus;
		std::vector<DataLayer::statusCollection> dataCollection = ormasDal.getStatus(ormasDal.getConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForStatus.push_back(Status(data));
			}
		}
		return vecForStatus;
	}

	template<>
	std::vector<User> OrmasBL::getAllDataForClass<User>()
	{
		std::vector<User> vecForUser;
		std::vector<DataLayer::usersCollection> dataCollection = ormasDal.getUsers(ormasDal.getConnection());
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForUser.push_back(User(data));
			}
		}
		return vecForUser;
	}
}
