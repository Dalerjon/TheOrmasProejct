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
		bool CreateConsumeProduct(BusinessLayer::ConsumeProduct*, std::string&);
		bool CreateConsumeProductList(BusinessLayer::ConsumeProductList*, std::string&);
		bool CreateConsumeRaw(BusinessLayer::ConsumeRaw*, std::string&);
		bool CreateConsumeRawList(BusinessLayer::ConsumeRawList*, std::string&);
		bool CreateCurrency(BusinessLayer::Currency*, std::string&);
		bool CreateEmployee(BusinessLayer::Employee*, std::string&);
		bool CreateInventorization(BusinessLayer::Inventorization*, std::string&);
		bool CreateInventorizationList(BusinessLayer::InventorizationList*, std::string&);
		bool CreateLocation(BusinessLayer::Location*, std::string&);
		bool CreateMeasure(BusinessLayer::Measure*, std::string&);
		bool CreateOrder(BusinessLayer::Order*, std::string&);
		bool CreateOrderList(BusinessLayer::OrderList*, std::string&);
		bool CreateOrderRaw(BusinessLayer::OrderRaw*, std::string&);
		bool CreateOrderRawList(BusinessLayer::OrderRawList*, std::string&);
		bool CreatePayment(BusinessLayer::Payment*, std::string&);
		bool CreatePayslip(BusinessLayer::Payslip*, std::string&);
		bool CreatePhoto(BusinessLayer::Photo*, std::string&);
		bool CreatePosition(BusinessLayer::Position*, std::string&);
		bool CreatePrice(BusinessLayer::Price*, std::string&);
		bool CreateProduct(BusinessLayer::Product*, std::string&);
		bool CreateProduction(BusinessLayer::Production*, std::string&);
		bool CreateProductionList(BusinessLayer::ProductionList*, std::string&);
		bool CreateProductType(BusinessLayer::ProductType*, std::string&);
		bool CreateReceiptProduct(BusinessLayer::ReceiptProduct*, std::string&);
		bool CreateReceiptProductList(BusinessLayer::ReceiptProductList*, std::string&);
		bool CreateReceiptRaw(BusinessLayer::ReceiptRaw*, std::string&);
		bool CreateReceiptRawList(BusinessLayer::ReceiptRawList*, std::string&);
		bool CreateRefund(BusinessLayer::Refund*, std::string&);
		bool CreateRelation(BusinessLayer::Relation*, std::string&);
		bool CreateRelationType(BusinessLayer::RelationType*, std::string&);
		bool CreateReturn(BusinessLayer::Return*, std::string&);
		bool CreateReturnList(BusinessLayer::ReturnList*, std::string&);
		bool CreateRole(BusinessLayer::Role*, std::string&);
		bool CreateSalary(BusinessLayer::Salary*, std::string&);
		bool CreateSalaryType(BusinessLayer::SalaryType*, std::string&);
		bool CreateStatus(BusinessLayer::Status*, std::string&);
		bool CreateStock(BusinessLayer::Stock*, std::string&);
		bool CreateTransport(BusinessLayer::Transport*, std::string&);
		bool CreateTransportList(BusinessLayer::TransportList*, std::string&);
		bool CreateUser(BusinessLayer::User*, std::string&);
		bool CreateWithdrawal(BusinessLayer::Withdrawal*, std::string&);
		bool CreateWriteOff(BusinessLayer::WriteOff*, std::string&);
		bool CreateWriteOffList(BusinessLayer::WriteOffList*, std::string&);
		bool CreateWriteOffRaw(BusinessLayer::WriteOffRaw*, std::string&);
		bool CreateWriteOffRawList(BusinessLayer::WriteOffRawList*, std::string&);

		bool DeleteAccess(BusinessLayer::Access*, std::string&);
		bool DeleteAccessItem(BusinessLayer::AccessItem*, std::string&);
		bool DeleteBalance(BusinessLayer::Balance*, std::string&);
		bool DeleteClient(BusinessLayer::Client*, std::string&);
		bool DeleteCompany(BusinessLayer::Company*, std::string&);
		bool DeleteConsumeProduct(BusinessLayer::ConsumeProduct*, std::string&);
		bool DeleteConsumeProductList(BusinessLayer::ConsumeProductList*, std::string&);
		bool DeleteConsumeRaw(BusinessLayer::ConsumeRaw*, std::string&);
		bool DeleteConsumeRawList(BusinessLayer::ConsumeRawList*, std::string&);
		bool DeleteCurrency(BusinessLayer::Currency*, std::string&);
		bool DeleteEmployee(BusinessLayer::Employee*, std::string&);
		bool DeleteInventorization(BusinessLayer::Inventorization*, std::string&);
		bool DeleteInventorizationList(BusinessLayer::InventorizationList*, std::string&);
		bool DeleteLocation(BusinessLayer::Location*, std::string&);
		bool DeleteMeasure(BusinessLayer::Measure*, std::string&);
		bool DeleteOrder(BusinessLayer::Order*, std::string&);
		bool DeleteOrderList(BusinessLayer::OrderList*, std::string&);
		bool DeleteOrderRaw(BusinessLayer::OrderRaw*, std::string&);
		bool DeleteOrderRawList(BusinessLayer::OrderRawList*, std::string&);
		bool DeletePayment(BusinessLayer::Payment*, std::string&);
		bool DeletePayslip(BusinessLayer::Payslip*, std::string&);
		bool DeletePhoto(BusinessLayer::Photo*, std::string&);
		bool DeletePosition(BusinessLayer::Position*, std::string&);
		bool DeletePrice(BusinessLayer::Price*, std::string&);
		bool DeleteProduct(BusinessLayer::Product*, std::string&);
		bool DeleteProduction(BusinessLayer::Production*, std::string&);
		bool DeleteProductionList(BusinessLayer::ProductionList*, std::string&);
		bool DeleteProductType(BusinessLayer::ProductType*, std::string&);
		bool DeleteReceiptProduct(BusinessLayer::ReceiptProduct*, std::string&);
		bool DeleteReceiptProductList(BusinessLayer::ReceiptProductList*, std::string&);
		bool DeleteReceiptRaw(BusinessLayer::ReceiptRaw*, std::string&);
		bool DeleteReceiptRawList(BusinessLayer::ReceiptRawList*, std::string&);
		bool DeleteRefund(BusinessLayer::Refund*, std::string&);
		bool DeleteRelation(BusinessLayer::Relation*, std::string&);
		bool DeleteRelationType(BusinessLayer::RelationType*, std::string&);
		bool DeleteReturn(BusinessLayer::Return*, std::string&);
		bool DeleteReturnList(BusinessLayer::ReturnList*, std::string&);
		bool DeleteRole(BusinessLayer::Role*, std::string&);
		bool DeleteSalary(BusinessLayer::Salary*, std::string&);
		bool DeleteSalaryType(BusinessLayer::SalaryType*, std::string&);
		bool DeleteStatus(BusinessLayer::Status*, std::string&);
		bool DeleteStock(BusinessLayer::Stock*, std::string&);
		bool DeleteTransport(BusinessLayer::Transport*, std::string&);
		bool DeleteTransportList(BusinessLayer::TransportList*, std::string&);
		bool DeleteUser(BusinessLayer::User*, std::string&);
		bool DeleteWithdrawal(BusinessLayer::Withdrawal*, std::string&);
		bool DeleteWriteOff(BusinessLayer::WriteOff*, std::string&);
		bool DeleteWriteOffList(BusinessLayer::WriteOffList*, std::string&);
		bool DeleteWriteOffRaw(BusinessLayer::WriteOffRaw*, std::string&);
		bool DeleteWriteOffRawList(BusinessLayer::WriteOffRawList*, std::string&);

		bool UpdateAccess(BusinessLayer::Access*, std::string&);
		bool UpdateAccessItem(BusinessLayer::AccessItem*, std::string&);
		bool UpdateBalance(BusinessLayer::Balance*, std::string&);
		bool UpdateClient(BusinessLayer::Client*, std::string&);
		bool UpdateCompany(BusinessLayer::Company*, std::string&);
		bool UpdateConsumeProduct(BusinessLayer::ConsumeProduct*, std::string&);
		bool UpdateConsumeProductList(BusinessLayer::ConsumeProductList*, std::string&);
		bool UpdateConsumeRaw(BusinessLayer::ConsumeRaw*, std::string&);
		bool UpdateConsumeRawList(BusinessLayer::ConsumeRawList*, std::string&);
		bool UpdateCurrency(BusinessLayer::Currency*, std::string&);
		bool UpdateEmployee(BusinessLayer::Employee*, std::string&);
		bool UpdateInventorization(BusinessLayer::Inventorization*, std::string&);
		bool UpdateInventorizationList(BusinessLayer::InventorizationList*, std::string&);
		bool UpdateLocation(BusinessLayer::Location*, std::string&);
		bool UpdateMeasure(BusinessLayer::Measure*, std::string&);
		bool UpdateOrder(BusinessLayer::Order*, std::string&);
		bool UpdateOrderList(BusinessLayer::OrderList*, std::string&);
		bool UpdateOrderRaw(BusinessLayer::OrderRaw*, std::string&);
		bool UpdateOrderRawList(BusinessLayer::OrderRawList*, std::string&);
		bool UpdatePayment(BusinessLayer::Payment*, std::string&);
		bool UpdatePayslip(BusinessLayer::Payslip*, std::string&);
		bool UpdatePhoto(BusinessLayer::Photo*, std::string&);
		bool UpdatePosition(BusinessLayer::Position*, std::string&);
		bool UpdatePrice(BusinessLayer::Price*, std::string&);
		bool UpdateProduct(BusinessLayer::Product*, std::string&);
		bool UpdateProduction(BusinessLayer::Production*, std::string&);
		bool UpdateProductionList(BusinessLayer::ProductionList*, std::string&);
		bool UpdateProductType(BusinessLayer::ProductType*, std::string&);
		bool UpdateReceiptProduct(BusinessLayer::ReceiptProduct*, std::string&);
		bool UpdateReceiptProductList(BusinessLayer::ReceiptProductList*, std::string&);
		bool UpdateReceiptRaw(BusinessLayer::ReceiptRaw*, std::string&);
		bool UpdateReceiptRawList(BusinessLayer::ReceiptRawList*, std::string&);
		bool UpdateRefund(BusinessLayer::Refund*, std::string&);
		bool UpdateRelation(BusinessLayer::Relation*, std::string&);
		bool UpdateRelationType(BusinessLayer::RelationType*, std::string&);
		bool UpdateReturn(BusinessLayer::Return*, std::string&);
		bool UpdateReturnList(BusinessLayer::ReturnList*, std::string&);
		bool UpdateRole(BusinessLayer::Role*, std::string&);
		bool UpdateSalary(BusinessLayer::Salary*, std::string&);
		bool UpdateSalaryType(BusinessLayer::SalaryType*, std::string&);
		bool UpdateStatus(BusinessLayer::Status*, std::string&);
		bool UpdateStock(BusinessLayer::Stock*, std::string&);
		bool UpdateTransport(BusinessLayer::Transport*, std::string&);
		bool UpdateTransportList(BusinessLayer::TransportList*, std::string&);
		bool UpdateUser(BusinessLayer::User*, std::string&);
		bool UpdateWithdrawal(BusinessLayer::Withdrawal*, std::string&);
		bool UpdateWriteOff(BusinessLayer::WriteOff*, std::string&);
		bool UpdateWriteOffList(BusinessLayer::WriteOffList*, std::string&);
		bool UpdateWriteOffRaw(BusinessLayer::WriteOffRaw*, std::string&);
		bool UpdateWriteOffRawList(BusinessLayer::WriteOffRawList*, std::string&);
	};
}
#endif