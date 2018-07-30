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
		bool CreateAccount(BusinessLayer::Account*, std::string&);
		bool CreateAccountHistory(BusinessLayer::AccountHistory*, std::string&);
		bool CreateAccountType(BusinessLayer::AccountType*, std::string&);
		bool CreateBalance(BusinessLayer::Balance*, std::string&);
		bool CreateChartOfAccounts(BusinessLayer::ChartOfAccounts*, std::string&);
		bool CreateClient(BusinessLayer::Client*, std::string&);
		bool CreateCompany(BusinessLayer::Company*, std::string&);
		bool CreateCompanyAccountRelation(BusinessLayer::CompanyAccountRelation*, std::string&);
		bool CreateCompanyEmployeeRelation(BusinessLayer::CompanyEmployeeRelation*, std::string&);
		bool CreateConsumeProduct(BusinessLayer::ConsumeProduct*, std::string&);
		bool CreateConsumeProductList(BusinessLayer::ConsumeProductList*, std::string&);
		bool CreateConsumeRaw(BusinessLayer::ConsumeRaw*, std::string&);
		bool CreateConsumeRawList(BusinessLayer::ConsumeRawList*, std::string&);
		bool CreateCurrency(BusinessLayer::Currency*, std::string&);
		bool CreateDivisionAccountRelation(BusinessLayer::DivisionAccountRelation*, std::string&);
		bool CreateDivisionEmployeeRelation(BusinessLayer::DivisionEmployeeRelation*, std::string&);
		bool CreateDivision(BusinessLayer::Division*, std::string&);
		bool CreateEmployee(BusinessLayer::Employee*, std::string&);
		bool CreateEntry(BusinessLayer::Entry*, std::string&);
		bool CreateEntryRouting(BusinessLayer::EntryRouting*, std::string&);
		bool CreateFinancialReport(BusinessLayer::FinancialReport*, std::string&);
		bool CreateInventorization(BusinessLayer::Inventorization*, std::string&);
		bool CreateInventorizationList(BusinessLayer::InventorizationList*, std::string&);
		bool CreateJobprice(BusinessLayer::Jobprice*, std::string&);
		bool CreateJobsheet(BusinessLayer::Jobsheet*, std::string&);
		bool CreateLocation(BusinessLayer::Location*, std::string&);
		bool CreateMeasure(BusinessLayer::Measure*, std::string&);
		bool CreateNetCost(BusinessLayer::NetCost*, std::string&);
		bool CreateOrder(BusinessLayer::Order*, std::string&);
		bool CreateOrderList(BusinessLayer::OrderList*, std::string&);
		bool CreateOrderRaw(BusinessLayer::OrderRaw*, std::string&);
		bool CreateOrderRawList(BusinessLayer::OrderRawList*, std::string&);
		bool CreatePayment(BusinessLayer::Payment*, std::string&);
		bool CreatePayslip(BusinessLayer::Payslip*, std::string&);
		bool CreatePercentRate(BusinessLayer::PercentRate*, std::string&);
		bool CreatePhoto(BusinessLayer::Photo*, std::string&);
		bool CreatePosition(BusinessLayer::Position*, std::string&);
		bool CreatePrice(BusinessLayer::Price*, std::string&);
		bool CreateProduct(BusinessLayer::Product*, std::string&);
		bool CreateProduction(BusinessLayer::Production*, std::string&);
		bool CreateProductionList(BusinessLayer::ProductionList*, std::string&);
		bool CreateProductionConsumeRaw(BusinessLayer::ProductionConsumeRaw*, std::string&);
		bool CreateProductionConsumeRawList(BusinessLayer::ProductionConsumeRawList*, std::string&);
		bool CreateProductionPlan(BusinessLayer::ProductionPlan*, std::string&);
		bool CreateProductionPlanList(BusinessLayer::ProductionPlanList*, std::string&);
		bool CreateProductionStock(BusinessLayer::ProductionStock*, std::string&);
		bool CreatePurveyor(BusinessLayer::Purveyor*, std::string&);
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
		bool CreateSpecificationList(BusinessLayer::SpecificationList*, std::string&);
		bool CreateSpecification(BusinessLayer::Specification*, std::string&);
		bool CreateSpoilageList(BusinessLayer::SpoilageList*, std::string&);
		bool CreateSpoilage(BusinessLayer::Spoilage*, std::string&);
		bool CreateState(BusinessLayer::State*, std::string&);
		bool CreateStatus(BusinessLayer::Status*, std::string&);
		bool CreateStatusRule(BusinessLayer::StatusRule*, std::string&);
		bool CreateStock(BusinessLayer::Stock*, std::string&);
		bool CreateSubaccount(BusinessLayer::Subaccount*, std::string&);
		bool CreateSubaccountHistory(BusinessLayer::SubaccountHistory*, std::string&);
		bool CreateTax(BusinessLayer::Tax*, std::string&);
		bool CreateTimesheet(BusinessLayer::Timesheet*, std::string&);
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
		bool DeleteAccount(BusinessLayer::Account*, std::string&);
		bool DeleteAccountHistory(BusinessLayer::AccountHistory*, std::string&);
		bool DeleteAccountType(BusinessLayer::AccountType*, std::string&);
		bool DeleteBalance(BusinessLayer::Balance*, std::string&);
		bool DeleteChartOfAccounts(BusinessLayer::ChartOfAccounts*, std::string&);
		bool DeleteClient(BusinessLayer::Client*, std::string&);
		bool DeleteCompany(BusinessLayer::Company*, std::string&);
		bool DeleteCompanyAccountRelation(BusinessLayer::CompanyAccountRelation*, std::string&);
		bool DeleteCompanyEmployeeRelation(BusinessLayer::CompanyEmployeeRelation*, std::string&);
		bool DeleteConsumeProduct(BusinessLayer::ConsumeProduct*, std::string&);
		bool DeleteConsumeProductList(BusinessLayer::ConsumeProductList*, std::string&);
		bool DeleteConsumeRaw(BusinessLayer::ConsumeRaw*, std::string&);
		bool DeleteConsumeRawList(BusinessLayer::ConsumeRawList*, std::string&);
		bool DeleteCurrency(BusinessLayer::Currency*, std::string&);
		bool DeleteDivisionAccountRelation(BusinessLayer::DivisionAccountRelation*, std::string&);
		bool DeleteDivisionEmployeeRelation(BusinessLayer::DivisionEmployeeRelation*, std::string&);
		bool DeleteDivision(BusinessLayer::Division*, std::string&);
		bool DeleteEmployee(BusinessLayer::Employee*, std::string&);
		bool DeleteEntry(BusinessLayer::Entry*, std::string&);
		bool DeleteEntryRouting(BusinessLayer::EntryRouting*, std::string&);
		bool DeleteFinancialReport(BusinessLayer::FinancialReport*, std::string&);
		bool DeleteInventorization(BusinessLayer::Inventorization*, std::string&);
		bool DeleteInventorizationList(BusinessLayer::InventorizationList*, std::string&);
		bool DeleteJobprice(BusinessLayer::Jobprice*, std::string&);
		bool DeleteJobsheet(BusinessLayer::Jobsheet*, std::string&);
		bool DeleteLocation(BusinessLayer::Location*, std::string&);
		bool DeleteMeasure(BusinessLayer::Measure*, std::string&);
		bool DeleteNetCost(BusinessLayer::NetCost*, std::string&);
		bool DeleteOrder(BusinessLayer::Order*, std::string&);
		bool DeleteOrderList(BusinessLayer::OrderList*, std::string&);
		bool DeleteOrderRaw(BusinessLayer::OrderRaw*, std::string&);
		bool DeleteOrderRawList(BusinessLayer::OrderRawList*, std::string&);
		bool DeletePayment(BusinessLayer::Payment*, std::string&);
		bool DeletePayslip(BusinessLayer::Payslip*, std::string&);
		bool DeletePercentRate(BusinessLayer::PercentRate*, std::string&);
		bool DeletePhoto(BusinessLayer::Photo*, std::string&);
		bool DeletePosition(BusinessLayer::Position*, std::string&);
		bool DeletePrice(BusinessLayer::Price*, std::string&);
		bool DeleteProduct(BusinessLayer::Product*, std::string&);
		bool DeleteProduction(BusinessLayer::Production*, std::string&);
		bool DeleteProductionList(BusinessLayer::ProductionList*, std::string&);
		bool DeleteProductionConsumeRaw(BusinessLayer::ProductionConsumeRaw*, std::string&);
		bool DeleteProductionConsumeRawList(BusinessLayer::ProductionConsumeRawList*, std::string&);
		bool DeleteProductionPlan(BusinessLayer::ProductionPlan*, std::string&);
		bool DeleteProductionPlanList(BusinessLayer::ProductionPlanList*, std::string&);
		bool DeleteProductionStock(BusinessLayer::ProductionStock*, std::string&);
		bool DeleteProductType(BusinessLayer::ProductType*, std::string&);
		bool DeletePurveyor(BusinessLayer::Purveyor*, std::string&);
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
		bool DeleteSpecificationList(BusinessLayer::SpecificationList*, std::string&);
		bool DeleteSpecification(BusinessLayer::Specification*, std::string&);
		bool DeleteSpoilageList(BusinessLayer::SpoilageList*, std::string&);
		bool DeleteSpoilage(BusinessLayer::Spoilage*, std::string&);
		bool DeleteState(BusinessLayer::State*, std::string&);
		bool DeleteStatus(BusinessLayer::Status*, std::string&);
		bool DeleteStatusRule(BusinessLayer::StatusRule*, std::string&);
		bool DeleteStock(BusinessLayer::Stock*, std::string&);
		bool DeleteSubaccount(BusinessLayer::Subaccount*, std::string&);
		bool DeleteSubaccountHistory(BusinessLayer::SubaccountHistory*, std::string&);
		bool DeleteTax(BusinessLayer::Tax*, std::string&);
		bool DeleteTimesheet(BusinessLayer::Timesheet*, std::string&);
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
		bool UpdateAccount(BusinessLayer::Account*, std::string&);
		bool UpdateAccountHistory(BusinessLayer::AccountHistory*, std::string&);
		bool UpdateAccountType(BusinessLayer::AccountType*, std::string&);
		bool UpdateBalance(BusinessLayer::Balance*, std::string&);
		bool UpdateChartOfAccounts(BusinessLayer::ChartOfAccounts*, std::string&);
		bool UpdateClient(BusinessLayer::Client*, std::string&);
		bool UpdateCompany(BusinessLayer::Company*, std::string&);
		bool UpdateCompanyAccountRelation(BusinessLayer::CompanyAccountRelation*, std::string&);
		bool UpdateCompanyEmployeeRelation(BusinessLayer::CompanyEmployeeRelation*, std::string&);
		bool UpdateConsumeProduct(BusinessLayer::ConsumeProduct*, std::string&);
		bool UpdateConsumeProductList(BusinessLayer::ConsumeProductList*, std::string&);
		bool UpdateConsumeRaw(BusinessLayer::ConsumeRaw*, std::string&);
		bool UpdateConsumeRawList(BusinessLayer::ConsumeRawList*, std::string&);
		bool UpdateCurrency(BusinessLayer::Currency*, std::string&);
		bool UpdateDivisionAccountRelation(BusinessLayer::DivisionAccountRelation*, std::string&);
		bool UpdateDivisionEmployeeRelation(BusinessLayer::DivisionEmployeeRelation*, std::string&);
		bool UpdateDivision(BusinessLayer::Division*, std::string&);
		bool UpdateEmployee(BusinessLayer::Employee*, std::string&);
		bool UpdateEntry(BusinessLayer::Entry*, std::string&);
		bool UpdateEntryRouting(BusinessLayer::EntryRouting*, std::string&);
		bool UpdateFinancialReport(BusinessLayer::FinancialReport*, std::string&);
		bool UpdateInventorization(BusinessLayer::Inventorization*, std::string&);
		bool UpdateInventorizationList(BusinessLayer::InventorizationList*, std::string&);
		bool UpdateJobprice(BusinessLayer::Jobprice*, std::string&);
		bool UpdateJobsheet(BusinessLayer::Jobsheet*, std::string&);
		bool UpdateLocation(BusinessLayer::Location*, std::string&);
		bool UpdateMeasure(BusinessLayer::Measure*, std::string&);
		bool UpdateNetCost(BusinessLayer::NetCost*, std::string&);
		bool UpdateOrder(BusinessLayer::Order*, std::string&);
		bool UpdateOrderList(BusinessLayer::OrderList*, std::string&);
		bool UpdateOrderRaw(BusinessLayer::OrderRaw*, std::string&);
		bool UpdateOrderRawList(BusinessLayer::OrderRawList*, std::string&);
		bool UpdatePayment(BusinessLayer::Payment*, std::string&);
		bool UpdatePayslip(BusinessLayer::Payslip*, std::string&);
		bool UpdatePercentRate(BusinessLayer::PercentRate*, std::string&);
		bool UpdatePhoto(BusinessLayer::Photo*, std::string&);
		bool UpdatePosition(BusinessLayer::Position*, std::string&);
		bool UpdatePrice(BusinessLayer::Price*, std::string&);
		bool UpdateProduct(BusinessLayer::Product*, std::string&);
		bool UpdateProduction(BusinessLayer::Production*, std::string&);
		bool UpdateProductionList(BusinessLayer::ProductionList*, std::string&);
		bool UpdateProductionConsumeRaw(BusinessLayer::ProductionConsumeRaw*, std::string&);
		bool UpdateProductionConsumeRawList(BusinessLayer::ProductionConsumeRawList*, std::string&);
		bool UpdateProductionPlan(BusinessLayer::ProductionPlan*, std::string&);
		bool UpdateProductionPlanList(BusinessLayer::ProductionPlanList*, std::string&);
		bool UpdateProductionStock(BusinessLayer::ProductionStock*, std::string&);
		bool UpdateProductType(BusinessLayer::ProductType*, std::string&);
		bool UpdatePurveyor(BusinessLayer::Purveyor*, std::string&);
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
		bool UpdateSpecificationList(BusinessLayer::SpecificationList*, std::string&);
		bool UpdateSpecification(BusinessLayer::Specification*, std::string&);
		bool UpdateSpoilageList(BusinessLayer::SpoilageList*, std::string&);
		bool UpdateSpoilage(BusinessLayer::Spoilage*, std::string&);
		bool UpdateState(BusinessLayer::State*, std::string&);
		bool UpdateStatus(BusinessLayer::Status*, std::string&);
		bool UpdateStatusRule(BusinessLayer::StatusRule*, std::string&);
		bool UpdateStock(BusinessLayer::Stock*, std::string&);
		bool UpdateSubaccount(BusinessLayer::Subaccount*, std::string&);
		bool UpdateSubaccountHistory(BusinessLayer::SubaccountHistory*, std::string&);
		bool UpdateTax(BusinessLayer::Tax*, std::string&);
		bool UpdateTimesheet(BusinessLayer::Timesheet*, std::string&);
		bool UpdateTransport(BusinessLayer::Transport*, std::string&);
		bool UpdateTransportList(BusinessLayer::TransportList*, std::string&);
		bool UpdateUser(BusinessLayer::User*, std::string&);
		bool UpdateWithdrawal(BusinessLayer::Withdrawal*, std::string&);
		bool UpdateWriteOff(BusinessLayer::WriteOff*, std::string&);
		bool UpdateWriteOffList(BusinessLayer::WriteOffList*, std::string&);
		bool UpdateWriteOffRaw(BusinessLayer::WriteOffRaw*, std::string&);
		bool UpdateWriteOffRawList(BusinessLayer::WriteOffRawList*, std::string&);

		//bool NormalizationOfAccounts();
		bool CloseOfMonth(std::string, std::string);
		bool CloseOfAccount70000();
		bool SaveAccountState(std::string, std::string);
		bool CalculateEmployeeSalary(std::string, std::string);
		bool CalculateCloseOfMonth(std::string, std::string);
		bool CalculateTax(std::string, std::string);
		bool RecalculateNetCost(std::string fromDate, std::string tillDate);
		bool GenerateReports(std::string, std::string);
		bool CorrectingEntries();
		
	};
}
#endif