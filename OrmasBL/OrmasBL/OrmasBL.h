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
		User* loggedUser;

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

		int GenerateInventoryNumber();

		//ormasDal, connection to DB 
		bool ConnectToDB(std::string dbname, std::string username, std::string password, std::string host, int port);

		//ormasDal, connection to DB get status
		bool IsConnected();

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
		std::string ConcatenateFilters(std::vector<std::string> filterList);

		//Create, delete and update for all classes
		bool CreateAccess(BusinessLayer::Access*, std::string&);
		bool CreateAccessItem(BusinessLayer::AccessItem*, std::string&);
		bool CreateAccount(BusinessLayer::Account*, std::string&);
		bool CreateAccountable(BusinessLayer::Accountable*, std::string&);
		bool CreateAccountableTransaction(BusinessLayer::AccountableTransaction*, std::string&);
		bool CreateAccountHistory(BusinessLayer::AccountHistory*, std::string&);
		bool CreateAccountType(BusinessLayer::AccountType*, std::string&); 
		bool CreateAmortizeGroup(BusinessLayer::AmortizeGroup*, std::string&);
		bool CreateAmortizeType(BusinessLayer::AmortizeType*, std::string&);
		bool CreateBalance(BusinessLayer::Balance*, std::string&);
		bool CreateBranch(BusinessLayer::Branch*, std::string&);
		bool CreateBorrower(BusinessLayer::Borrower*, std::string&);
		bool CreateCashbox(BusinessLayer::Cashbox*, std::string&);
		bool CreateCashboxTransaction(BusinessLayer::CashboxTransaction*, std::string&);
		bool CreateCashboxEmployeeRelation(BusinessLayer::CashboxEmployeeRelation*, std::string&);
		bool CreateChartOfAccounts(BusinessLayer::ChartOfAccounts*, std::string&);
		bool CreateClient(BusinessLayer::Client*, std::string&);
		bool CreateCreditor(BusinessLayer::Creditor*, std::string&);
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
		bool CreateEmployeeProductRelation(BusinessLayer::EmployeeProductRelation*, std::string&);
		bool CreateEntry(BusinessLayer::Entry*, std::string&);
		bool CreateEntryRouting(BusinessLayer::EntryRouting*, std::string&);
		bool CreateFinancialReport(BusinessLayer::FinancialReport*, std::string&);
		bool CreateFixedAssets(BusinessLayer::FixedAssets*, std::string&);
		bool CreateFixedAssetsUnion(BusinessLayer::FixedAssetsUnion*, std::string&);
		bool CreateFixedAssetsDetails(BusinessLayer::FixedAssetsDetails*, std::string&);
		bool CreateFixedAssetsOperation(BusinessLayer::FixedAssetsOperations*, std::string&);
		bool CreateFixedAssetsSpecification(BusinessLayer::FixedAssetsSpecification*, std::string&);
		bool CreateInventorization(BusinessLayer::Inventorization*, std::string&);
		bool CreateInventorizationList(BusinessLayer::InventorizationList*, std::string&);
		bool CreateInventory(BusinessLayer::Inventory*, std::string&);
		bool CreateInventoryHistory(BusinessLayer::InventoryHistory*, std::string&);
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
		bool CreatePostingFixedAssets(BusinessLayer::PostingFixedAssets*, std::string&);
		bool CreatePosition(BusinessLayer::Position*, std::string&);
		bool CreatePrice(BusinessLayer::Price*, std::string&);
		bool CreateProduct(BusinessLayer::Product*, std::string&);
		bool CreateProductBranchRelation(BusinessLayer::ProductBranchRelation*, std::string&);
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
		bool CreateStockTransfer(BusinessLayer::StockTransfer*, std::string&);
		bool CreateStockTransferList(BusinessLayer::StockTransferList*, std::string&);
		bool CreateRefund(BusinessLayer::Refund*, std::string&);
		bool CreateRelation(BusinessLayer::Relation*, std::string&);
		bool CreateRelationType(BusinessLayer::RelationType*, std::string&);
		bool CreateReturn(BusinessLayer::Return*, std::string&);
		bool CreateReturnList(BusinessLayer::ReturnList*, std::string&);
		bool CreateRole(BusinessLayer::Role*, std::string&);
		bool CreateSalary(BusinessLayer::Salary*, std::string&);
		bool CreateSalaryType(BusinessLayer::SalaryType*, std::string&);
		bool CreateShareholder(BusinessLayer::Shareholder*, std::string&);
		bool CreateSpecificationList(BusinessLayer::SpecificationList*, std::string&);
		bool CreateSpecification(BusinessLayer::Specification*, std::string&);
		bool CreateSpoilageList(BusinessLayer::SpoilageList*, std::string&);
		bool CreateSpoilage(BusinessLayer::Spoilage*, std::string&);
		bool CreateState(BusinessLayer::State*, std::string&);
		bool CreateStatus(BusinessLayer::Status*, std::string&);
		bool CreateStatusRule(BusinessLayer::StatusRule*, std::string&);
		bool CreateStock(BusinessLayer::Stock*, std::string&);
		bool CreateStockHistory(BusinessLayer::StockHistory*, std::string&);
		bool CreateSubaccount(BusinessLayer::Subaccount*, std::string&);
		bool CreateSubaccountHistory(BusinessLayer::SubaccountHistory*, std::string&);
		bool CreateTax(BusinessLayer::Tax*, std::string&);
		bool CreateTimesheet(BusinessLayer::Timesheet*, std::string&);
		bool CreateTransport(BusinessLayer::Transport*, std::string&);
		bool CreateTransportList(BusinessLayer::TransportList*, std::string&);
		bool CreateUser(BusinessLayer::User*, std::string&);
		bool CreateWarehouse(BusinessLayer::Warehouse*, std::string&);
		bool CreateWarehouseType(BusinessLayer::WarehouseType*, std::string&);
		bool CreateWarehouseEmployeeRelation(BusinessLayer::WarehouseEmployeeRelation*, std::string&);
		bool CreateWithdrawal(BusinessLayer::Withdrawal*, std::string&);
		bool CreateWriteOff(BusinessLayer::WriteOff*, std::string&);
		bool CreateWriteOffList(BusinessLayer::WriteOffList*, std::string&);
		bool CreateWriteOffRaw(BusinessLayer::WriteOffRaw*, std::string&);
		bool CreateWriteOffRawList(BusinessLayer::WriteOffRawList*, std::string&);

		bool DeleteAccess(BusinessLayer::Access*, std::string&);
		bool DeleteAccessItem(BusinessLayer::AccessItem*, std::string&);
		bool DeleteAccount(BusinessLayer::Account*, std::string&);
		bool DeleteAccountable(BusinessLayer::Accountable*, std::string&);
		bool DeleteAccountableTransaction(BusinessLayer::AccountableTransaction*, std::string&);
		bool DeleteAccountHistory(BusinessLayer::AccountHistory*, std::string&);
		bool DeleteAccountType(BusinessLayer::AccountType*, std::string&);
		bool DeleteAmortizeGroup(BusinessLayer::AmortizeGroup*, std::string&);
		bool DeleteAmortizeType(BusinessLayer::AmortizeType*, std::string&);
		bool DeleteBalance(BusinessLayer::Balance*, std::string&);
		bool DeleteBranch(BusinessLayer::Branch*, std::string&);
		bool DeleteBorrower(BusinessLayer::Borrower*, std::string&);
		bool DeleteCashbox(BusinessLayer::Cashbox*, std::string&);
		bool DeleteCashboxTransaction(BusinessLayer::CashboxTransaction*, std::string&);
		bool DeleteCashboxEmployeeRelation(BusinessLayer::CashboxEmployeeRelation*, std::string&);
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
		bool DeleteCreditor(BusinessLayer::Creditor*, std::string&);
		bool DeleteDivisionAccountRelation(BusinessLayer::DivisionAccountRelation*, std::string&);
		bool DeleteDivisionEmployeeRelation(BusinessLayer::DivisionEmployeeRelation*, std::string&);
		bool DeleteDivision(BusinessLayer::Division*, std::string&);
		bool DeleteEmployee(BusinessLayer::Employee*, std::string&);
		bool DeleteEmployeeProductRelation(BusinessLayer::EmployeeProductRelation*, std::string&);
		bool DeleteEntry(BusinessLayer::Entry*, std::string&);
		bool DeleteEntryRouting(BusinessLayer::EntryRouting*, std::string&);
		bool DeleteFinancialReport(BusinessLayer::FinancialReport*, std::string&);
		bool DeleteFixedAssets(BusinessLayer::FixedAssets*, std::string&);
		bool DeleteFixedAssetsUnion(BusinessLayer::FixedAssetsUnion*, std::string&);
		bool DeleteFixedAssetsDetails(BusinessLayer::FixedAssetsDetails*, std::string&);
		bool DeleteFixedAssetsOperation(BusinessLayer::FixedAssetsOperations*, std::string&);
		bool DeleteFixedAssetsSpecification(BusinessLayer::FixedAssetsSpecification*, std::string&);
		bool DeleteInventorization(BusinessLayer::Inventorization*, std::string&);
		bool DeleteInventorizationList(BusinessLayer::InventorizationList*, std::string&);
		bool DeleteInventory(BusinessLayer::Inventory*, std::string&);
		bool DeleteInventoryHistory(BusinessLayer::InventoryHistory*, std::string&);
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
		bool DeletePostingFixedAssets(BusinessLayer::PostingFixedAssets*, std::string&);
		bool DeletePosition(BusinessLayer::Position*, std::string&);
		bool DeletePrice(BusinessLayer::Price*, std::string&);
		bool DeleteProduct(BusinessLayer::Product*, std::string&);
		bool DeleteProductBranchRelation(BusinessLayer::ProductBranchRelation*, std::string&);
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
		bool DeleteStockTransfer(BusinessLayer::StockTransfer*, std::string&);
		bool DeleteStockTransferList(BusinessLayer::StockTransferList*, std::string&);
		bool DeleteRefund(BusinessLayer::Refund*, std::string&);
		bool DeleteRelation(BusinessLayer::Relation*, std::string&);
		bool DeleteRelationType(BusinessLayer::RelationType*, std::string&);
		bool DeleteReturn(BusinessLayer::Return*, std::string&);
		bool DeleteReturnList(BusinessLayer::ReturnList*, std::string&);
		bool DeleteRole(BusinessLayer::Role*, std::string&);
		bool DeleteSalary(BusinessLayer::Salary*, std::string&);
		bool DeleteSalaryType(BusinessLayer::SalaryType*, std::string&);
		bool DeleteShareholder(BusinessLayer::Shareholder*, std::string&);
		bool DeleteSpecificationList(BusinessLayer::SpecificationList*, std::string&);
		bool DeleteSpecification(BusinessLayer::Specification*, std::string&);
		bool DeleteSpoilageList(BusinessLayer::SpoilageList*, std::string&);
		bool DeleteSpoilage(BusinessLayer::Spoilage*, std::string&);
		bool DeleteState(BusinessLayer::State*, std::string&);
		bool DeleteStatus(BusinessLayer::Status*, std::string&);
		bool DeleteStatusRule(BusinessLayer::StatusRule*, std::string&);
		bool DeleteStock(BusinessLayer::Stock*, std::string&);
		bool DeleteStockHistory(BusinessLayer::StockHistory*, std::string&);
		bool DeleteSubaccount(BusinessLayer::Subaccount*, std::string&);
		bool DeleteSubaccountHistory(BusinessLayer::SubaccountHistory*, std::string&);
		bool DeleteTax(BusinessLayer::Tax*, std::string&);
		bool DeleteTimesheet(BusinessLayer::Timesheet*, std::string&);
		bool DeleteTransport(BusinessLayer::Transport*, std::string&);
		bool DeleteTransportList(BusinessLayer::TransportList*, std::string&);
		bool DeleteUser(BusinessLayer::User*, std::string&);
		bool DeleteWarehouse(BusinessLayer::Warehouse*, std::string&);
		bool DeleteWarehouseType(BusinessLayer::WarehouseType*, std::string&);
		bool DeleteWarehouseEmployeeRelation(BusinessLayer::WarehouseEmployeeRelation*, std::string&);
		bool DeleteWithdrawal(BusinessLayer::Withdrawal*, std::string&);
		bool DeleteWriteOff(BusinessLayer::WriteOff*, std::string&);
		bool DeleteWriteOffList(BusinessLayer::WriteOffList*, std::string&);
		bool DeleteWriteOffRaw(BusinessLayer::WriteOffRaw*, std::string&);
		bool DeleteWriteOffRawList(BusinessLayer::WriteOffRawList*, std::string&);

		bool UpdateAccess(BusinessLayer::Access*, std::string&);
		bool UpdateAccessItem(BusinessLayer::AccessItem*, std::string&);
		bool UpdateAccount(BusinessLayer::Account*, std::string&);
		bool UpdateAccountable(BusinessLayer::Accountable*, std::string&);
		bool UpdateAccountableTransaction(BusinessLayer::AccountableTransaction*, std::string&);
		bool UpdateAccountHistory(BusinessLayer::AccountHistory*, std::string&);
		bool UpdateAccountType(BusinessLayer::AccountType*, std::string&);
		bool UpdateAmortizeGroup(BusinessLayer::AmortizeGroup*, std::string&);
		bool UpdateAmortizeType(BusinessLayer::AmortizeType*, std::string&);
		bool UpdateBranch(BusinessLayer::Branch*, std::string&);
		bool UpdateBorrower(BusinessLayer::Borrower*, std::string&);
		bool UpdateCashbox(BusinessLayer::Cashbox*, std::string&);
		bool UpdateCashboxTransaction(BusinessLayer::CashboxTransaction*, std::string&);
		bool UpdateCashboxEmployeeRelation(BusinessLayer::CashboxEmployeeRelation*, std::string&);
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
		bool UpdateCreditor(BusinessLayer::Creditor*, std::string&);
		bool UpdateDivisionAccountRelation(BusinessLayer::DivisionAccountRelation*, std::string&);
		bool UpdateDivisionEmployeeRelation(BusinessLayer::DivisionEmployeeRelation*, std::string&);
		bool UpdateDivision(BusinessLayer::Division*, std::string&);
		bool UpdateEmployee(BusinessLayer::Employee*, std::string&);
		bool UpdateEmployeeProductRelation(BusinessLayer::EmployeeProductRelation*, std::string&);
		bool UpdateEntry(BusinessLayer::Entry*, std::string&);
		bool UpdateEntryRouting(BusinessLayer::EntryRouting*, std::string&);
		bool UpdateFinancialReport(BusinessLayer::FinancialReport*, std::string&);
		bool UpdateFixedAssets(BusinessLayer::FixedAssets*, std::string&);
		bool UpdateFixedAssetsUnion(BusinessLayer::FixedAssetsUnion*, std::string&);
		bool UpdateFixedAssetsDetails(BusinessLayer::FixedAssetsDetails*, std::string&);
		bool UpdateFixedAssetsOperation(BusinessLayer::FixedAssetsOperations*, std::string&);
		bool UpdateFixedAssetsSpecification(BusinessLayer::FixedAssetsSpecification*, std::string&);
		bool UpdateInventorization(BusinessLayer::Inventorization*, std::string&);
		bool UpdateInventorizationList(BusinessLayer::InventorizationList*, std::string&);
		bool UpdateInventory(BusinessLayer::Inventory*, std::string&);
		bool UpdateInventoryHistory(BusinessLayer::InventoryHistory*, std::string&);
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
		bool UpdatePostingFixedAssets(BusinessLayer::PostingFixedAssets*, std::string&);
		bool UpdatePosition(BusinessLayer::Position*, std::string&);
		bool UpdatePrice(BusinessLayer::Price*, std::string&);
		bool UpdateProduct(BusinessLayer::Product*, std::string&);
		bool UpdateProductBranchRelation(BusinessLayer::ProductBranchRelation*, std::string&);
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
		bool UpdateStockTransfer(BusinessLayer::StockTransfer*, std::string&);
		bool UpdateStockTransferList(BusinessLayer::StockTransferList*, std::string&);
		bool UpdateRefund(BusinessLayer::Refund*, std::string&);
		bool UpdateRelation(BusinessLayer::Relation*, std::string&);
		bool UpdateRelationType(BusinessLayer::RelationType*, std::string&);
		bool UpdateReturn(BusinessLayer::Return*, std::string&);
		bool UpdateReturnList(BusinessLayer::ReturnList*, std::string&);
		bool UpdateRole(BusinessLayer::Role*, std::string&);
		bool UpdateSalary(BusinessLayer::Salary*, std::string&);
		bool UpdateSalaryType(BusinessLayer::SalaryType*, std::string&);
		bool UpdateShareholder(BusinessLayer::Shareholder*, std::string&);
		bool UpdateSpecificationList(BusinessLayer::SpecificationList*, std::string&);
		bool UpdateSpecification(BusinessLayer::Specification*, std::string&);
		bool UpdateSpoilageList(BusinessLayer::SpoilageList*, std::string&);
		bool UpdateSpoilage(BusinessLayer::Spoilage*, std::string&);
		bool UpdateState(BusinessLayer::State*, std::string&);
		bool UpdateStatus(BusinessLayer::Status*, std::string&);
		bool UpdateStatusRule(BusinessLayer::StatusRule*, std::string&);
		bool UpdateStock(BusinessLayer::Stock*, std::string&);
		bool UpdateStockHistory(BusinessLayer::StockHistory*, std::string&);
		bool UpdateSubaccount(BusinessLayer::Subaccount*, std::string&);
		bool UpdateSubaccountHistory(BusinessLayer::SubaccountHistory*, std::string&);
		bool UpdateTax(BusinessLayer::Tax*, std::string&);
		bool UpdateTimesheet(BusinessLayer::Timesheet*, std::string&);
		bool UpdateTransport(BusinessLayer::Transport*, std::string&);
		bool UpdateTransportList(BusinessLayer::TransportList*, std::string&);
		bool UpdateUser(BusinessLayer::User*, std::string&);
		bool UpdateWarehouse(BusinessLayer::Warehouse*, std::string&);
		bool UpdateWarehouseType(BusinessLayer::WarehouseType*, std::string&);
		bool UpdateWarehouseEmployeeRelation(BusinessLayer::WarehouseEmployeeRelation*, std::string&);
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
		bool CorrectingNetCostInStock();
		bool CorrectingNetCostInTransport();
		bool SaveStockState(std::string, std::string);
		bool CorrectDates(std::string);
		std::string wstring_to_utf8(const std::wstring& str);
	};
}
#endif