#ifndef ORMASBL_H
#define ORMASBL_H

#include "AllClassHeaders.h"

namespace BusinessLayer
{
	class OrmasBL
	{
		DataLayer::OrmasDal ormasDal;
	public:
		OrmasBL();
		OrmasBL(const OrmasBL &oBL);
		~OrmasBL();
		
		OrmasBL& operator=(const OrmasBL& ob)
		{
			if (this == &ob)
			{
				return *this;
			}
			else
			{
				ormasDal = ob.ormasDal;
			}
			return *this;
		}
		DataLayer::OrmasDal& GetOrmasDal();
		//OrmasBL class Accessor
		
		//Generate id
		int GenerateID();

		//ormasDal, connection to DB 
		bool ConnectToDB(std::string dbname, std::string username, std::string password, std::string host, int port);

		template<class T>
		std::vector<T> GetAllDataForClass(std::string& errorMessage, std::string filter = "");

		template<class T>
		std::string GenerateFilter(T* T)
		{
			return T->GenerateFilter(ormasDal);
		}

		//Transaction methids
		bool StartTransaction(std::string& errorMessage);
		bool CommitTransaction(std::string& errorMessage);
		bool CancelTransaction(std::string& errorMessage);

		//Create, delete and update for all classes
		bool CreateCompany(BusinessLayer::Company*, std::string&);
		bool CreateCurrency(BusinessLayer::Currency*, std::string&);
		bool CreateMeasure(BusinessLayer::Measure*, std::string&);
		bool CreateOrder(BusinessLayer::Order*, std::string&);
		bool CreateProductList(BusinessLayer::ProductList*, std::string&);
		bool CreateProductType(BusinessLayer::ProductType*, std::string&);
		bool CreateProduction(BusinessLayer::Production*, std::string&);
		bool CreateProduct(BusinessLayer::Product*, std::string&);
		bool CreateLocation(BusinessLayer::Location*, std::string&);
		bool CreateReturn(BusinessLayer::Return*, std::string&);
		bool CreateRole(BusinessLayer::Role*, std::string&);
		bool CreateStatus(BusinessLayer::Status*, std::string&);
		bool CreateUser(BusinessLayer::User*, std::string&);
		bool DeleteCompany(BusinessLayer::Company*, std::string&);
		bool DeleteCurrency(BusinessLayer::Currency*, std::string&);
		bool DeleteMeasure(BusinessLayer::Measure*, std::string&);
		bool DeleteOrder(BusinessLayer::Order*, std::string&);
		bool DeleteProductList(BusinessLayer::ProductList*, std::string&);
		bool DeleteProductType(BusinessLayer::ProductType*, std::string&);
		bool DeleteProduction(BusinessLayer::Production*, std::string&);
		bool DeleteProduct(BusinessLayer::Product*, std::string&);
		bool DeleteLocation(BusinessLayer::Location*, std::string&);
		bool DeleteReturn(BusinessLayer::Return*, std::string&);
		bool DeleteRole(BusinessLayer::Role*, std::string&);
		bool DeleteStatus(BusinessLayer::Status*, std::string&);
		bool DeleteUser(BusinessLayer::User*, std::string&);
		bool UpdateCompany(BusinessLayer::Company*, std::string&);
		bool UpdateCurrency(BusinessLayer::Currency*, std::string&);
		bool UpdateMeasure(BusinessLayer::Measure*, std::string&);
		bool UpdateOrder(BusinessLayer::Order*, std::string&);
		bool UpdateProductList(BusinessLayer::ProductList*, std::string&);
		bool UpdateProductType(BusinessLayer::ProductType*, std::string&);
		bool UpdateProduction(BusinessLayer::Production*, std::string&);
		bool UpdateProduct(BusinessLayer::Product*, std::string&);
		bool UpdateLocation(BusinessLayer::Location*, std::string&);
		bool UpdateReturn(BusinessLayer::Return*, std::string&);
		bool UpdateRole(BusinessLayer::Role*, std::string&);
		bool UpdateStatus(BusinessLayer::Status*, std::string&);
		bool UpdateUser(BusinessLayer::User*, std::string&);
	};
}
#endif