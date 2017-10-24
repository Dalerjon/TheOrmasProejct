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
		bool CreateAccess(BusinessLayer::Access*, std::string&);
		bool CreateAccessItem(BusinessLayer::AccessItem*, std::string&);
		bool CreateBalance(BusinessLayer::Balance*, std::string&);
		bool CreateClient(BusinessLayer::Client*, std::string&);
		bool CreateCompany(BusinessLayer::Company*, std::string&);
		bool CreateCurrency(BusinessLayer::Currency*, std::string&);
		bool CreateEmployee(BusinessLayer::Employee*, std::string&);
		bool CreateLocation(BusinessLayer::Location*, std::string&);
		bool CreateMeasure(BusinessLayer::Measure*, std::string&);
		bool CreateOrder(BusinessLayer::Order*, std::string&);
		bool CreateOrderList(BusinessLayer::OrderList*, std::string&);
		bool CreatePayment(BusinessLayer::Payment*, std::string&);
		bool CreatePhoto(BusinessLayer::Photo*, std::string&);
		bool CreatePosition(BusinessLayer::Position*, std::string&);
		bool CreatePrice(BusinessLayer::Price*, std::string&);
		bool CreateProduct(BusinessLayer::Product*, std::string&);
		bool CreateProduction(BusinessLayer::Production*, std::string&);
		bool CreateProductionList(BusinessLayer::ProductionList*, std::string&);
		bool CreateProductType(BusinessLayer::ProductType*, std::string&);
		bool CreateRelation(BusinessLayer::Relation*, std::string&);
		bool CreateRelationType(BusinessLayer::RelationType*, std::string&);
		bool CreateReturn(BusinessLayer::Return*, std::string&);
		bool CreateReturnList(BusinessLayer::ReturnList*, std::string&);
		bool CreateRole(BusinessLayer::Role*, std::string&);
		bool CreateSalary(BusinessLayer::Salary*, std::string&);
		bool CreateSalaryType(BusinessLayer::SalaryType*, std::string&);
		bool CreateStatus(BusinessLayer::Status*, std::string&);
		bool CreateUser(BusinessLayer::User*, std::string&);
		bool CreateWriteOff(BusinessLayer::WriteOff*, std::string&);
		bool CreateWriteOffList(BusinessLayer::WriteOffList*, std::string&);

		bool DeleteAccess(BusinessLayer::Access*, std::string&);
		bool DeleteAccessItem(BusinessLayer::AccessItem*, std::string&);
		bool DeleteBalance(BusinessLayer::Balance*, std::string&);
		bool DeleteClient(BusinessLayer::Client*, std::string&);
		bool DeleteCompany(BusinessLayer::Company*, std::string&);
		bool DeleteCurrency(BusinessLayer::Currency*, std::string&);
		bool DeleteEmployee(BusinessLayer::Employee*, std::string&);
		bool DeleteLocation(BusinessLayer::Location*, std::string&);
		bool DeleteMeasure(BusinessLayer::Measure*, std::string&);
		bool DeleteOrder(BusinessLayer::Order*, std::string&);
		bool DeleteOrderList(BusinessLayer::OrderList*, std::string&);
		bool DeletePayment(BusinessLayer::Payment*, std::string&);
		bool DeletePhoto(BusinessLayer::Photo*, std::string&);
		bool DeletePosition(BusinessLayer::Position*, std::string&);
		bool DeletePrice(BusinessLayer::Price*, std::string&);
		bool DeleteProduct(BusinessLayer::Product*, std::string&);
		bool DeleteProduction(BusinessLayer::Production*, std::string&);
		bool DeleteProductionList(BusinessLayer::ProductionList*, std::string&);
		bool DeleteProductType(BusinessLayer::ProductType*, std::string&);
		bool DeleteRelation(BusinessLayer::Relation*, std::string&);
		bool DeleteRelationType(BusinessLayer::RelationType*, std::string&);
		bool DeleteReturn(BusinessLayer::Return*, std::string&);
		bool DeleteReturnList(BusinessLayer::ReturnList*, std::string&);
		bool DeleteRole(BusinessLayer::Role*, std::string&);
		bool DeleteSalary(BusinessLayer::Salary*, std::string&);
		bool DeleteSalaryType(BusinessLayer::SalaryType*, std::string&);
		bool DeleteStatus(BusinessLayer::Status*, std::string&);
		bool DeleteUser(BusinessLayer::User*, std::string&);
		bool DeleteWriteOff(BusinessLayer::WriteOff*, std::string&);
		bool DeleteWriteOffList(BusinessLayer::WriteOffList*, std::string&);

		bool UpdateAccess(BusinessLayer::Access*, std::string&);
		bool UpdateAccessItem(BusinessLayer::AccessItem*, std::string&);
		bool UpdateBalance(BusinessLayer::Balance*, std::string&);
		bool UpdateClient(BusinessLayer::Client*, std::string&);
		bool UpdateCompany(BusinessLayer::Company*, std::string&);
		bool UpdateCurrency(BusinessLayer::Currency*, std::string&);
		bool UpdateEmployee(BusinessLayer::Employee*, std::string&);
		bool UpdateLocation(BusinessLayer::Location*, std::string&);
		bool UpdateMeasure(BusinessLayer::Measure*, std::string&);
		bool UpdateOrder(BusinessLayer::Order*, std::string&);
		bool UpdateOrderList(BusinessLayer::OrderList*, std::string&);
		bool UpdatePayment(BusinessLayer::Payment*, std::string&);
		bool UpdatePhoto(BusinessLayer::Photo*, std::string&);
		bool UpdatePosition(BusinessLayer::Position*, std::string&);
		bool UpdatePrice(BusinessLayer::Price*, std::string&);
		bool UpdateProduct(BusinessLayer::Product*, std::string&);
		bool UpdateProduction(BusinessLayer::Production*, std::string&);
		bool UpdateProductionList(BusinessLayer::ProductionList*, std::string&);
		bool UpdateProductType(BusinessLayer::ProductType*, std::string&);
		bool UpdateRelation(BusinessLayer::Relation*, std::string&);
		bool UpdateRelationType(BusinessLayer::RelationType*, std::string&);
		bool UpdateReturn(BusinessLayer::Return*, std::string&);
		bool UpdateReturnList(BusinessLayer::ReturnList*, std::string&);
		bool UpdateRole(BusinessLayer::Role*, std::string&);
		bool UpdateSalary(BusinessLayer::Salary*, std::string&);
		bool UpdateSalaryType(BusinessLayer::SalaryType*, std::string&);
		bool UpdateStatus(BusinessLayer::Status*, std::string&);
		bool UpdateUser(BusinessLayer::User*, std::string&);
		bool UpdateWriteOff(BusinessLayer::WriteOff*, std::string&);
		bool UpdateWriteOffList(BusinessLayer::WriteOffList*, std::string&);
	};
}
#endif