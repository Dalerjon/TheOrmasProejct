// OrmasBL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "OrmasBL.h"
#include <typeinfo>
#include <math.h>
#include <algorithm>
#include <codecvt>
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
	std::vector<AccessView> OrmasBL::GetAllDataForClass<AccessView>(std::string& errorMessage, std::string filter)
	{
		std::vector<AccessView> vecForAccess;
		std::vector<DataLayer::accessesViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetAccesses(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetAccesses(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForAccess.push_back(AccessView(data));
			}
		}
		return vecForAccess;
	}

	template<>
	std::vector<AccessItem> OrmasBL::GetAllDataForClass<AccessItem>(std::string& errorMessage, std::string filter)
	{
		std::vector<AccessItem> vecForAccessItems;
		std::vector<DataLayer::accessItemsCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetAccessItems(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetAccessItems(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForAccessItems.push_back(AccessItem(data));
			}
		}
		return vecForAccessItems;
	}

	template<>
	std::vector<Account> OrmasBL::GetAllDataForClass<Account>(std::string& errorMessage, std::string filter)
	{
		std::vector<Account> vecForAccount;
		std::vector<DataLayer::accountsCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetAccounts(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetAccounts(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForAccount.push_back(Account(data));
			}
		}
		return vecForAccount;
	}

	template<>
	std::vector<AccountHistory> OrmasBL::GetAllDataForClass<AccountHistory>(std::string& errorMessage, std::string filter)
	{
		std::vector<AccountHistory> vecForAccountHis;
		std::vector<DataLayer::accountHistoryCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetAccountHistory(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetAccountHistory(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForAccountHis.push_back(AccountHistory(data));
			}
		}
		return vecForAccountHis;
	}


	template<>
	std::vector<AccountType> OrmasBL::GetAllDataForClass<AccountType>(std::string& errorMessage, std::string filter)
	{
		std::vector<AccountType> vecForAccountType;
		std::vector<DataLayer::accountTypeCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetAccountType(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetAccountType(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForAccountType.push_back(AccountType(data));
			}
		}
		return vecForAccountType;
	}

	template<>
	std::vector<BalanceView> OrmasBL::GetAllDataForClass<BalanceView>(std::string& errorMessage, std::string filter)
	{
		std::vector<BalanceView> vecForBalance;
		std::vector<DataLayer::balancesViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetBalances(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetBalances(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForBalance.push_back(BalanceView(data));
			}
		}
		return vecForBalance;
	}


	template<>
	std::vector<ChartOfAccountsView> OrmasBL::GetAllDataForClass<ChartOfAccountsView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ChartOfAccountsView> vecForChartOfAccount;
		std::vector<DataLayer::chartOfAccountsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetChartOfAccounts(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetChartOfAccounts(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForChartOfAccount.push_back(ChartOfAccountsView(data));
			}
		}
		return vecForChartOfAccount;
	}

	template<>
	std::vector<ClientView> OrmasBL::GetAllDataForClass<ClientView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ClientView> vecForClient;
		std::vector<DataLayer::clientsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetClients(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetClients(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForClient.push_back(ClientView(data));
			}
		}
		return vecForClient;
	}

	template<>
	std::vector<CompanyAccountRelationView> OrmasBL::GetAllDataForClass<CompanyAccountRelationView>(std::string& errorMessage, std::string filter)
	{
		std::vector<CompanyAccountRelationView> vecForComAccRel;
		std::vector<DataLayer::companyAccountViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetCompanyAccount(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetCompanyAccount(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForComAccRel.push_back(CompanyAccountRelationView(data));
			}
		}
		return vecForComAccRel;
	}

	template<>
	std::vector<CompanyEmployeeRelationView> OrmasBL::GetAllDataForClass<CompanyEmployeeRelationView>(std::string& errorMessage, std::string filter)
	{
		std::vector<CompanyEmployeeRelationView> vecForComEmpRel;
		std::vector<DataLayer::companyEmployeeViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetCompanyEmployee(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetCompanyEmployee(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForComEmpRel.push_back(CompanyEmployeeRelationView(data));
			}
		}
		return vecForComEmpRel;
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
	std::vector<ConsumeProductView> OrmasBL::GetAllDataForClass<ConsumeProductView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ConsumeProductView> vecForConsumeProduct;
		std::vector<DataLayer::consumeProductsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetConsumeProducts(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetConsumeProducts(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForConsumeProduct.push_back(ConsumeProductView(data));
			}
		}
		return vecForConsumeProduct;
	}

	template<>
	std::vector<ConsumeProductListView> OrmasBL::GetAllDataForClass<ConsumeProductListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ConsumeProductListView> vecForConsumeProductList;
		std::vector<DataLayer::consumeProductListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetConsumeProductList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetConsumeProductList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForConsumeProductList.push_back(ConsumeProductListView(data));
			}
		}
		return vecForConsumeProductList;
	}

	template<>
	std::vector<ConsumeRawView> OrmasBL::GetAllDataForClass<ConsumeRawView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ConsumeRawView> vecForConsumeRaw;
		std::vector<DataLayer::consumeRawsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetConsumeRaws(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetConsumeRaws(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForConsumeRaw.push_back(ConsumeRawView(data));
			}
		}
		return vecForConsumeRaw;
	}

	template<>
	std::vector<ConsumeRawListView> OrmasBL::GetAllDataForClass<ConsumeRawListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ConsumeRawListView> vecForConsumeRawList;
		std::vector<DataLayer::consumeRawListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetConsumeRawList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetConsumeRawList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForConsumeRawList.push_back(ConsumeRawListView(data));
			}
		}
		return vecForConsumeRawList;
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
	std::vector<DivisionAccountRelationView> OrmasBL::GetAllDataForClass<DivisionAccountRelationView>(std::string& errorMessage, std::string filter)
	{
		std::vector<DivisionAccountRelationView> vecForDivisionAccount;
		std::vector<DataLayer::divisionAccountViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetDivisionAccount(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetDivisionAccount(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForDivisionAccount.push_back(DivisionAccountRelationView(data));
			}
		}
		return vecForDivisionAccount;
	}

	template<>
	std::vector<DivisionEmployeeRelation> OrmasBL::GetAllDataForClass<DivisionEmployeeRelation>(std::string& errorMessage, std::string filter)
	{
		std::vector<DivisionEmployeeRelation> vecForDivisionEmployee;
		std::vector<DataLayer::divisionEmployeeCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetDivisionEmployee(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetDivisionEmployee(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForDivisionEmployee.push_back(DivisionEmployeeRelation(data));
			}
		}
		return vecForDivisionEmployee;
	}

	template<>
	std::vector<Division> OrmasBL::GetAllDataForClass<Division>(std::string& errorMessage, std::string filter)
	{
		std::vector<Division> vecForDivision;
		std::vector<DataLayer::divisionsCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetDivisions(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetDivisions(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForDivision.push_back(Division(data));
			}
		}
		return vecForDivision;
	}

	template<>
	std::vector<EmployeeView> OrmasBL::GetAllDataForClass<EmployeeView>(std::string& errorMessage, std::string filter)
	{
		std::vector<EmployeeView> vecForEmployee;
		std::vector<DataLayer::employeesViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetEmployees(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetEmployees(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForEmployee.push_back(EmployeeView(data));
			}
		}
		return vecForEmployee;
	}

	template<>
	std::vector<EntryView> OrmasBL::GetAllDataForClass<EntryView>(std::string& errorMessage, std::string filter)
	{
		std::vector<EntryView> vecForEntry;
		std::vector<DataLayer::entriesViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetEntries(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetEntries(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForEntry.push_back(EntryView(data));
			}
		}
		return vecForEntry;
	}

	template<>
	std::vector<EntryRouting> OrmasBL::GetAllDataForClass<EntryRouting>(std::string& errorMessage, std::string filter)
	{
		std::vector<EntryRouting> vecForEntryRouting;
		std::vector<DataLayer::entryRoutingCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetEntryRouting(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetEntryRouting(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForEntryRouting.push_back(EntryRouting(data));
			}
		}
		return vecForEntryRouting;
	}

	template<>
	std::vector<FinancialReport> OrmasBL::GetAllDataForClass<FinancialReport>(std::string& errorMessage, std::string filter)
	{
		std::vector<FinancialReport> vecForFinRep;
		std::vector<DataLayer::financialReportCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetFinancialReport(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetFinancialReport(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForFinRep.push_back(FinancialReport(data));
			}
		}
		return vecForFinRep;
	}

	template<>
	std::vector<InventorizationView> OrmasBL::GetAllDataForClass<InventorizationView>(std::string& errorMessage, std::string filter)
	{
		std::vector<InventorizationView> vecForInventorization;
		std::vector<DataLayer::inventorizationsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetInventorizations(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetInventorizations(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForInventorization.push_back(InventorizationView(data));
			}
		}
		return vecForInventorization;
	}

	template<>
	std::vector<InventorizationListView> OrmasBL::GetAllDataForClass<InventorizationListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<InventorizationListView> vecForInventorizationList;
		std::vector<DataLayer::inventorizationListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetInventorizationList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetInventorizationList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForInventorizationList.push_back(InventorizationListView(data));
			}
		}
		return vecForInventorizationList;
	}

	template<>
	std::vector<JobpriceView> OrmasBL::GetAllDataForClass<JobpriceView>(std::string& errorMessage, std::string filter)
	{
		std::vector<JobpriceView> vecForJobprice;
		std::vector<DataLayer::jobpriceViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetJobprice(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetJobprice(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForJobprice.push_back(JobpriceView(data));
			}
		}
		return vecForJobprice;
	}

	template<>
	std::vector<JobsheetView> OrmasBL::GetAllDataForClass<JobsheetView>(std::string& errorMessage, std::string filter)
	{
		std::vector<JobsheetView> vecForJobsheet;
		std::vector<DataLayer::jobsheetViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetJobsheet(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetJobsheet(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForJobsheet.push_back(JobsheetView(data));
			}
		}
		return vecForJobsheet;
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
	std::vector<NetCostView> OrmasBL::GetAllDataForClass<NetCostView>(std::string& errorMessage, std::string filter)
	{
		std::vector<NetCostView> vecFornetCost;
		std::vector<DataLayer::netCostViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetNetCost(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetNetCost(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecFornetCost.push_back(NetCostView(data));
			}
		}
		return vecFornetCost;
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
	std::vector<OrderListView> OrmasBL::GetAllDataForClass<OrderListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<OrderListView> vecForOrderList;
		std::vector<DataLayer::orderListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetOrderList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetOrderList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForOrderList.push_back(OrderListView(data));
			}
		}
		return vecForOrderList;
	}

	template<>
	std::vector<OrderRawView> OrmasBL::GetAllDataForClass<OrderRawView>(std::string& errorMessage, std::string filter)
	{
		std::vector<OrderRawView> vecForOrderRaw;
		std::vector<DataLayer::orderRawsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetOrderRaws(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetOrderRaws(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForOrderRaw.push_back(OrderRawView(data));
			}
		}
		return vecForOrderRaw;
	}

	template<>
	std::vector<OrderRawListView> OrmasBL::GetAllDataForClass<OrderRawListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<OrderRawListView> vecForOrderRawList;
		std::vector<DataLayer::orderListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetOrderRawList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetOrderRawList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForOrderRawList.push_back(OrderRawListView(data));
			}
		}
		return vecForOrderRawList;
	}

	template<>
	std::vector<PaymentView> OrmasBL::GetAllDataForClass<PaymentView>(std::string& errorMessage, std::string filter)
	{
		std::vector<PaymentView> vecForPayment;
		std::vector<DataLayer::paymentsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetPayments(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetPayments(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForPayment.push_back(PaymentView(data));
			}
		}
		return vecForPayment;
	}

	template<>
	std::vector<PayslipView> OrmasBL::GetAllDataForClass<PayslipView>(std::string& errorMessage, std::string filter)
	{
		std::vector<PayslipView> vecForPayslip;
		std::vector<DataLayer::payslipsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetPayslips(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetPayslips(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForPayslip.push_back(PayslipView(data));
			}
		}
		return vecForPayslip;
	}

	template<>
	std::vector<PercentRate> OrmasBL::GetAllDataForClass<PercentRate>(std::string& errorMessage, std::string filter)
	{
		std::vector<PercentRate> vecForPercentRate;
		std::vector<DataLayer::percentRateCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetPercentRate(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetPercentRate(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForPercentRate.push_back(PercentRate(data));
			}
		}
		return vecForPercentRate;
	}

	template<>
	std::vector<Photo> OrmasBL::GetAllDataForClass<Photo>(std::string& errorMessage, std::string filter)
	{
		std::vector<Photo> vecForPhoto;
		std::vector<DataLayer::photosCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetPhotos(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetPhotos(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForPhoto.push_back(Photo(data));
			}
		}
		return vecForPhoto;
	}

	template<>
	std::vector<Position> OrmasBL::GetAllDataForClass<Position>(std::string& errorMessage, std::string filter)
	{
		std::vector<Position> vecForPosition;
		std::vector<DataLayer::positionsCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetPositions(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetPositions(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForPosition.push_back(Position(data));
			}
		}
		return vecForPosition;
	}

	template<>
	std::vector<PriceView> OrmasBL::GetAllDataForClass<PriceView>(std::string& errorMessage, std::string filter)
	{
		std::vector<PriceView> vecForPrices;
		std::vector<DataLayer::pricesViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetPrices(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetPrices(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForPrices.push_back(PriceView(data));
			}
		}
		return vecForPrices;
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
	std::vector<ProductionListView> OrmasBL::GetAllDataForClass<ProductionListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ProductionListView> vecForProductionList;
		std::vector<DataLayer::productionListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetProductionList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetProductionList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProductionList.push_back(ProductionListView(data));
			}
		}
		return vecForProductionList;
	}

	template<>
	std::vector<ProductionConsumeRawView> OrmasBL::GetAllDataForClass<ProductionConsumeRawView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ProductionConsumeRawView> vecForProdConsumeRaw;
		std::vector<DataLayer::productionConsumeRawsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetProductionConsumeRaws(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetProductionConsumeRaws(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProdConsumeRaw.push_back(ProductionConsumeRawView(data));
			}
		}
		return vecForProdConsumeRaw;
	}

	template<>
	std::vector<ProductionConsumeRawListView> OrmasBL::GetAllDataForClass<ProductionConsumeRawListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ProductionConsumeRawListView> vecForProdConsumeRawList;
		std::vector<DataLayer::productionConsumeRawListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetProductionConsumeRawList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetProductionConsumeRawList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProdConsumeRawList.push_back(ProductionConsumeRawListView(data));
			}
		}
		return vecForProdConsumeRawList;
	}

	template<>
	std::vector<ProductionPlanView> OrmasBL::GetAllDataForClass<ProductionPlanView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ProductionPlanView> vecForProductionPlan;
		std::vector<DataLayer::productionPlanViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetProductionPlan(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetProductionPlan(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProductionPlan.push_back(ProductionPlanView(data));
			}
		}
		return vecForProductionPlan;
	}

	template<>
	std::vector<ProductionPlanListView> OrmasBL::GetAllDataForClass<ProductionPlanListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ProductionPlanListView> vecForProductionPlanList;
		std::vector<DataLayer::productionPlanListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetProductionPlanList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetProductionPlanList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProductionPlanList.push_back(ProductionPlanListView(data));
			}
		}
		return vecForProductionPlanList;
	}


	template<>
	std::vector<ProductionStockView> OrmasBL::GetAllDataForClass<ProductionStockView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ProductionStockView> vecForProductionStock;
		std::vector<DataLayer::productionStockViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetProductionStock(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetProductionStock(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProductionStock.push_back(ProductionStockView(data));
			}
		}
		return vecForProductionStock;
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
	std::vector<PurveyorView> OrmasBL::GetAllDataForClass<PurveyorView>(std::string& errorMessage, std::string filter)
	{
		std::vector<PurveyorView> vecForProductType;
		std::vector<DataLayer::purveyorsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetPurveyors(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetPurveyors(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForProductType.push_back(PurveyorView(data));
			}
		}
		return vecForProductType;
	}

	template<>
	std::vector<ReceiptProductView> OrmasBL::GetAllDataForClass<ReceiptProductView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ReceiptProductView> vecForReceiptProduct;
		std::vector<DataLayer::receiptProductsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetReceiptProducts(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetReceiptProducts(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForReceiptProduct.push_back(ReceiptProductView(data));
			}
		}
		return vecForReceiptProduct;
	}

	template<>
	std::vector<ReceiptProductListView> OrmasBL::GetAllDataForClass<ReceiptProductListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ReceiptProductListView> vecForReceiptProducList;
		std::vector<DataLayer::receiptProductListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetReceiptProductList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetReceiptProductList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForReceiptProducList.push_back(ReceiptProductListView(data));
			}
		}
		return vecForReceiptProducList;
	}

	template<>
	std::vector<ReceiptRawView> OrmasBL::GetAllDataForClass<ReceiptRawView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ReceiptRawView> vecForReceiptRaw;
		std::vector<DataLayer::receiptRawsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetReceiptRaws(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetReceiptRaws(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForReceiptRaw.push_back(ReceiptRawView(data));
			}
		}
		return vecForReceiptRaw;
	}

	template<>
	std::vector<ReceiptRawListView> OrmasBL::GetAllDataForClass<ReceiptRawListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ReceiptRawListView> vecForReceiptRawList;
		std::vector<DataLayer::receiptRawListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetReceiptRawList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetReceiptRawList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForReceiptRawList.push_back(ReceiptRawListView(data));
			}
		}
		return vecForReceiptRawList;
	}

	template<>
	std::vector<RefundView> OrmasBL::GetAllDataForClass<RefundView>(std::string& errorMessage, std::string filter)
	{
		std::vector<RefundView> vecForRefund;
		std::vector<DataLayer::refundsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetRefunds(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetRefunds(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForRefund.push_back(RefundView(data));
			}
		}
		return vecForRefund;
	}

	template<>
	std::vector<RelationView> OrmasBL::GetAllDataForClass<RelationView>(std::string& errorMessage, std::string filter)
	{
		std::vector<RelationView> vecForRelation;
		std::vector<DataLayer::relationsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetRelations(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetRelations(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForRelation.push_back(RelationView(data));
			}
		}
		return vecForRelation;
	}

	template<>
	std::vector<RelationType> OrmasBL::GetAllDataForClass<RelationType>(std::string& errorMessage, std::string filter)
	{
		std::vector<RelationType> vecForRelationType;
		std::vector<DataLayer::relationTypeCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetRelationType(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetRelationType(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForRelationType.push_back(RelationType(data));
			}
		}
		return vecForRelationType;
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
	std::vector<ReturnListView> OrmasBL::GetAllDataForClass<ReturnListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<ReturnListView> vecForReturnList;
		std::vector<DataLayer::returnListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetReturnList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetReturnList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForReturnList.push_back(ReturnListView(data));
			}
		}
		return vecForReturnList;
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
	std::vector<SalaryView> OrmasBL::GetAllDataForClass<SalaryView>(std::string& errorMessage, std::string filter)
	{
		std::vector<SalaryView> vecForSalary;
		std::vector<DataLayer::salariesViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetSalaries(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetSalaries(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForSalary.push_back(SalaryView(data));
			}
		}
		return vecForSalary;
	}

	template<>
	std::vector<SalaryType> OrmasBL::GetAllDataForClass<SalaryType>(std::string& errorMessage, std::string filter)
	{
		std::vector<SalaryType> vecForSalaryType;
		std::vector<DataLayer::salaryTypeCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetSalaryType(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetSalaryType(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForSalaryType.push_back(SalaryType(data));
			}
		}
		return vecForSalaryType;
	}

	template<>
	std::vector<SpecificationListView> OrmasBL::GetAllDataForClass<SpecificationListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<SpecificationListView> vecForSpecificationList;
		std::vector<DataLayer::specificationListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetSpecificationList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetSpecificationList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForSpecificationList.push_back(SpecificationListView(data));
			}
		}
		return vecForSpecificationList;
	}

	template<>
	std::vector<SpecificationView> OrmasBL::GetAllDataForClass<SpecificationView>(std::string& errorMessage, std::string filter)
	{
		std::vector<SpecificationView> vecForSpecification;
		std::vector<DataLayer::specificationsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetSpecifications(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetSpecifications(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForSpecification.push_back(SpecificationView(data));
			}
		}
		return vecForSpecification;
	}

	template<>
	std::vector<SpoilageListView> OrmasBL::GetAllDataForClass<SpoilageListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<SpoilageListView> vecForSpoilageList;
		std::vector<DataLayer::spoilageListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetSpoilageList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetSpoilageList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForSpoilageList.push_back(SpoilageListView(data));
			}
		}
		return vecForSpoilageList;
	}

	template<>
	std::vector<SpoilageView> OrmasBL::GetAllDataForClass<SpoilageView>(std::string& errorMessage, std::string filter)
	{
		std::vector<SpoilageView> vecForSpoilage;
		std::vector<DataLayer::spoilageViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetSpoilage(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetSpoilage(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForSpoilage.push_back(SpoilageView(data));
			}
		}
		return vecForSpoilage;
	}

	template<>
	std::vector<State> OrmasBL::GetAllDataForClass<State>(std::string& errorMessage, std::string filter)
	{
		std::vector<State> vecForState;
		std::vector<DataLayer::stateCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetState(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetState(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForState.push_back(State(data));
			}
		}
		return vecForState;
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
	std::vector<StatusRuleView> OrmasBL::GetAllDataForClass<StatusRuleView>(std::string& errorMessage, std::string filter)
	{
		std::vector<StatusRuleView> vecForStatusRule;
		std::vector<DataLayer::statusRuleViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetStatusRule(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetStatusRule(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForStatusRule.push_back(StatusRuleView(data));
			}
		}
		return vecForStatusRule;
	}

	template<>
	std::vector<StockView> OrmasBL::GetAllDataForClass<StockView>(std::string& errorMessage, std::string filter)
	{
		std::vector<StockView> vecForStock;
		std::vector<DataLayer::stockViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetStock(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetStock(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForStock.push_back(StockView(data));
			}
		}
		return vecForStock;
	}

	template<>
	std::vector<SubaccountView> OrmasBL::GetAllDataForClass<SubaccountView>(std::string& errorMessage, std::string filter)
	{
		std::vector<SubaccountView> vecForSubaccount;
		std::vector<DataLayer::subaccountsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetSubaccounts(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetSubaccounts(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForSubaccount.push_back(SubaccountView(data));
			}
		}
		return vecForSubaccount;
	}

	template<>
	std::vector<SubaccountHistory> OrmasBL::GetAllDataForClass<SubaccountHistory>(std::string& errorMessage, std::string filter)
	{
		std::vector<SubaccountHistory> vecForSubaccountHis;
		std::vector<DataLayer::subaccountHistoryCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetSubaccountHistory(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetSubaccountHistory(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForSubaccountHis.push_back(SubaccountHistory(data));
			}
		}
		return vecForSubaccountHis;
	}

	template<>
	std::vector<Tax> OrmasBL::GetAllDataForClass<Tax>(std::string& errorMessage, std::string filter)
	{
		std::vector<Tax> vecForTax;
		std::vector<DataLayer::taxesCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetTaxes(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetTaxes(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForTax.push_back(Tax(data));
			}
		}
		return vecForTax;
	}


	template<>
	std::vector<TimesheetView> OrmasBL::GetAllDataForClass<TimesheetView>(std::string& errorMessage, std::string filter)
	{
		std::vector<TimesheetView> vecForStock;
		std::vector<DataLayer::timesheetViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetTimesheet(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetTimesheet(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForStock.push_back(TimesheetView(data));
			}
		}
		return vecForStock;
	}

	template<>
	std::vector<TransportView> OrmasBL::GetAllDataForClass<TransportView>(std::string& errorMessage, std::string filter)
	{
		std::vector<TransportView> vecForTransport;
		std::vector<DataLayer::transportsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetTransports(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetTransports(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForTransport.push_back(TransportView(data));
			}
		}
		return vecForTransport;
	}

	template<>
	std::vector<TransportListView> OrmasBL::GetAllDataForClass<TransportListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<TransportListView> vecForTransportList;
		std::vector<DataLayer::transportListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetTransportList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetTransportList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForTransportList.push_back(TransportListView(data));
			}
		}
		return vecForTransportList;
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
	
	template<>
	std::vector<WithdrawalView> OrmasBL::GetAllDataForClass<WithdrawalView>(std::string& errorMessage, std::string filter)
	{
		std::vector<WithdrawalView> vecForWithdrawal;
		std::vector<DataLayer::withdrawalsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetWithdrawals(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetWithdrawals(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForWithdrawal.push_back(WithdrawalView(data));
			}
		}
		return vecForWithdrawal;
	}

	template<>
	std::vector<WriteOffView> OrmasBL::GetAllDataForClass<WriteOffView>(std::string& errorMessage, std::string filter)
	{
		std::vector<WriteOffView> vecForWriteOff;
		std::vector<DataLayer::writeOffsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetWriteOffs(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetWriteOffs(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForWriteOff.push_back(WriteOffView(data));
			}
		}
		return vecForWriteOff;
	}

	template<>
	std::vector<WriteOffListView> OrmasBL::GetAllDataForClass<WriteOffListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<WriteOffListView> vecForWriteOffList;
		std::vector<DataLayer::writeOffListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetWriteOffList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetWriteOffList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForWriteOffList.push_back(WriteOffListView(data));
			}
		}
		return vecForWriteOffList;
	}

	template<>
	std::vector<WriteOffRawView> OrmasBL::GetAllDataForClass<WriteOffRawView>(std::string& errorMessage, std::string filter)
	{
		std::vector<WriteOffRawView> vecForWriteOffRaw;
		std::vector<DataLayer::writeOffRawsViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetWriteOffRaws(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetWriteOffRaws(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForWriteOffRaw.push_back(WriteOffRawView(data));
			}
		}
		return vecForWriteOffRaw;
	}

	template<>
	std::vector<WriteOffRawListView> OrmasBL::GetAllDataForClass<WriteOffRawListView>(std::string& errorMessage, std::string filter)
	{
		std::vector<WriteOffRawListView> vecForWriteOffRawList;
		std::vector<DataLayer::writeOffListViewCollection> dataCollection;
		if (filter.empty())
		{
			dataCollection = ormasDal.GetWriteOffRawList(errorMessage);
		}
		else
		{
			dataCollection = ormasDal.GetWriteOffRawList(errorMessage, filter);
		}
		if (!dataCollection.empty()){
			for (auto data : dataCollection)
			{
				vecForWriteOffRawList.push_back(WriteOffRawListView(data));
			}
		}
		return vecForWriteOffRawList;
	}

	/// \brief	Creates the access.///
	///
	/// \param [in,out] access			If non-null, the access.
	/// \param [in,out] errorMessage	Message describing the error.
	///
	/// \return	true if it succeeds, false if it fails.
	
	bool OrmasBL::CreateAccess(BusinessLayer::Access* access, std::string& errorMessage)
	{
		try
		{
			if (0 != access->GetRoleID() && 0 != access->GetAccessItemID())
			{
				return access->CreateAccess(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Access item or role must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateAccess(BusinessLayer::Access* access, std::string& errorMessage)
	{
		try
		{
			if (0 != access->GetRoleID() && 0 != access->GetAccessItemID())
			{
				return access->UpdateAccess(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Access item or role must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteAccess(BusinessLayer::Access* access, std::string& errorMessage)
	{
		try
		{
			if (0 != access->GetID())
			{
				return access->DeleteAccess(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Access ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}
	
	bool OrmasBL::CreateAccessItem(BusinessLayer::AccessItem* accessItem, std::string& errorMessage)
	{
		try
		{
			if (!accessItem->GetNameEng().empty() && !accessItem->GetNameRu().empty() && !accessItem->GetDivision().empty())
			{
				return accessItem->CreateAccessItem(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! English item name or Russiam item name also division must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateAccessItem(BusinessLayer::AccessItem* accessItem, std::string& errorMessage)
	{
		try
		{
			if (!accessItem->GetNameEng().empty() && !accessItem->GetNameRu().empty() && !accessItem->GetDivision().empty())
			{
				return accessItem->UpdateAccessItem(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! English item name or Russiam item name also division must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteAccessItem(BusinessLayer::AccessItem* accessItem, std::string& errorMessage)
	{
		try
		{
			if (0 != accessItem->GetID())
			{
				return accessItem->DeleteAccessItem(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Access item ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateAccount(BusinessLayer::Account* account, std::string& errorMessage)
	{
		try
		{
			if (!account->GetNumber().empty())
			{
				return account->CreateAccount(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateAccount(BusinessLayer::Account* account, std::string& errorMessage)
	{
		try
		{
			if (!account->GetNumber().empty())
			{
				return account->UpdateAccount(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteAccount(BusinessLayer::Account* account, std::string& errorMessage)
	{
		try
		{
			if (0 != account->GetID())
			{
				return account->DeleteAccount(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Account item ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateAccountHistory(BusinessLayer::AccountHistory* accountHis, std::string& errorMessage)
	{
		try
		{
			if (!accountHis->GetNumber().empty() && !accountHis->GetFromDate().empty()
				&& !accountHis->GetTillDate().empty())
			{
				return accountHis->CreateAccountHistory(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateAccountHistory(BusinessLayer::AccountHistory* accountHis, std::string& errorMessage)
	{
		try
		{
			if (!accountHis->GetNumber().empty() && !accountHis->GetFromDate().empty()
				&& !accountHis->GetTillDate().empty())
			{
				return accountHis->UpdateAccountHistory(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteAccountHistory(BusinessLayer::AccountHistory* accountHis, std::string& errorMessage)
	{
		try
		{
			if (0 != accountHis->GetID())
			{
				return accountHis->DeleteAccountHistory(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Account history item ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateAccountType(BusinessLayer::AccountType* accountType, std::string& errorMessage)
	{
		try
		{
			if (!accountType->GetName().empty() && 0 != accountType->GetNumber())
			{
				return accountType->CreateAccountType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Name and number fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateAccountType(BusinessLayer::AccountType* accountType, std::string& errorMessage)
	{
		try
		{
			if (!accountType->GetName().empty() && 0 != accountType->GetNumber())
			{
				return accountType->UpdateAccountType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Name and number fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteAccountType(BusinessLayer::AccountType* accountType, std::string& errorMessage)
	{
		try
		{
			if (0 != accountType->GetID())
			{
				return accountType->DeleteAccountType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Account type item ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateBalance(BusinessLayer::Balance* balance, std::string& errorMessage)
	{
		try
		{
			if (0 != balance->GetUserID() && 0 != balance->GetSubaccountID())
			{
				return balance->CreateBalance(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, account and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateBalance(BusinessLayer::Balance* balance, std::string& errorMessage)
	{
		try
		{
			if (0 != balance->GetUserID() && 0 != balance->GetSubaccountID())
			{
				return balance->UpdateBalance(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, account and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteBalance(BusinessLayer::Balance* balance, std::string& errorMessage)
	{
		try
		{
			if (0 != balance->GetID())
			{
				return balance->DeleteBalance(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Balance ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateChartOfAccounts(BusinessLayer::ChartOfAccounts* chartOfAccounts, std::string& errorMessage)
	{
		try
		{
			if (!chartOfAccounts->GetNumber().empty() && 0 != chartOfAccounts->GetAccountTypeID() && !chartOfAccounts->GetName().empty())
			{
				return chartOfAccounts->CreateChartOfAccounts(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Name, number and account type ID must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateChartOfAccounts(BusinessLayer::ChartOfAccounts* chartOfAccounts, std::string& errorMessage)
	{
		try
		{
			if (!chartOfAccounts->GetNumber().empty() && 0 != chartOfAccounts->GetAccountTypeID() && !chartOfAccounts->GetName().empty())
			{
				return chartOfAccounts->UpdateChartOfAccounts(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Name, number and account type ID must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteChartOfAccounts(BusinessLayer::ChartOfAccounts* chartOfAccounts, std::string& errorMessage)
	{
		try
		{
			if (0 != chartOfAccounts->GetID())
			{
				return chartOfAccounts->DeleteChartOfAccounts(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Chart of accounts ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateClient(BusinessLayer::Client* client, std::string& errorMessage)
	{
		try
		{
			if (!client->GetName().empty() && !client->GetSurname().empty() && !client->GetPhone().empty()
				&& !client->GetAddress().empty() && !client->GetPassword().empty() && 0 != client->GetRoleID() && !client->GetFirm().empty()
				&& 0 != client->GetLocationID())
			{
				return client->CreateClient(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateClient(BusinessLayer::Client* client, std::string& errorMessage)
	{
		try
		{
			if (!client->GetName().empty() && !client->GetSurname().empty() && !client->GetPhone().empty()
				&& !client->GetAddress().empty() && !client->GetPassword().empty() && 0 != client->GetRoleID() && !client->GetFirm().empty()
				&& 0 != client->GetLocationID())
			{
				return client->UpdateClient(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteClient(BusinessLayer::Client* client, std::string& errorMessage)
	{
		try
		{
			if (0 != client->GetID())
			{
				return client->DeleteClient(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Client ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateCompanyAccountRelation(BusinessLayer::CompanyAccountRelation* caRelation, std::string& errorMessage)
	{
		try
		{
			if (0 != caRelation->GetCompanyID() && 0 != caRelation->GetAccountID())
			{
				return caRelation->CreateCompanyAccountRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Company and account must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateCompanyAccountRelation(BusinessLayer::CompanyAccountRelation* caRelation, std::string& errorMessage)
	{
		try
		{
			if (0 != caRelation->GetAccountID() && 0 != caRelation->GetCompanyID())
			{
				return caRelation->UpdateCompanyAccountRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Company and account must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteCompanyAccountRelation(BusinessLayer::CompanyAccountRelation* caRelation, std::string& errorMessage)
	{
		try
		{
			if (0 != caRelation->GetCompanyID() && 0 != caRelation->GetAccountID())
			{
				return caRelation->DeleteCompanyAccountRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Company account relation ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	/// \brief	Creates a company. Creation section
	///
	/// \param [in,out] company			If non-null, the company.
	/// \param [in,out] errorMessage	Message describing the error.
	///
	/// \return	true if it succeeds, false if it fails.

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

	bool OrmasBL::CreateCompanyEmployeeRelation(BusinessLayer::CompanyEmployeeRelation* ceRelation, std::string& errorMessage)
	{
		try
		{
			if (0 != ceRelation->GetEmployeeID() && 0 != ceRelation->GetCompanyID())
			{
				return ceRelation->CreateCompanyEmployeeRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Company and employee must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateCompanyEmployeeRelation(BusinessLayer::CompanyEmployeeRelation* ceRelation, std::string& errorMessage)
	{
		try
		{
			if (0 != ceRelation->GetEmployeeID() && 0 != ceRelation->GetCompanyID())
			{
				return ceRelation->UpdateCompanyEmployeeRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Company and employee must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteCompanyEmployeeRelation(BusinessLayer::CompanyEmployeeRelation* ceRelation, std::string& errorMessage)
	{
		try
		{
			if (0 != ceRelation->GetEmployeeID() && 0 != ceRelation->GetCompanyID())
			{
				return ceRelation->DeleteCompanyEmployeeRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Company id or employee id is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateConsumeProduct(BusinessLayer::ConsumeProduct* consumeProduct, std::string& errorMessage)
	{
		try
		{
			if (!consumeProduct->GetDate().empty() && 0 != consumeProduct->GetEmployeeID() && 0 != consumeProduct->GetCount()
				&& 0 != consumeProduct->GetSum() && 0 != consumeProduct->GetStatusID() && 0 != consumeProduct->GetCurrencyID()
				&& 0 != consumeProduct->GetStockEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, consumeProduct->GetCurrencyID(), errorMessage))
				{
					roundSum = round(consumeProduct->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				consumeProduct->SetSum(roundSum);
				return consumeProduct->CreateConsumeProduct(ormasDal, errorMessage);
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

	bool OrmasBL::UpdateConsumeProduct(BusinessLayer::ConsumeProduct* consumeProduct, std::string& errorMessage)
	{
		try
		{
			if (!consumeProduct->GetDate().empty() && 0 != consumeProduct->GetEmployeeID() && 0 != consumeProduct->GetCount()
				&& 0 != consumeProduct->GetSum() && 0 != consumeProduct->GetStatusID() && 0 != consumeProduct->GetCurrencyID()
				&& 0 != consumeProduct->GetStockEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, consumeProduct->GetCurrencyID(), errorMessage))
				{
					roundSum = round(consumeProduct->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				consumeProduct->SetSum(roundSum);
				return consumeProduct->UpdateConsumeProduct(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteConsumeProduct(BusinessLayer::ConsumeProduct* consumeProduct, std::string& errorMessage)
	{
		try
		{
			if (0 != consumeProduct->GetID())
			{
				return consumeProduct->DeleteConsumeProduct(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Consume product ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateConsumeProductList(BusinessLayer::ConsumeProductList* consumeProductList, std::string& errorMessage)
	{
		try
		{
			if (0 != consumeProductList->GetConsumeProductID() && 0 != consumeProductList->GetProductID()
				&& 0 != consumeProductList->GetCount() && 0 != consumeProductList->GetSum() && 0 != consumeProductList->GetStatusID()
				&& 0 != consumeProductList->GetCurrencyID())
			{
				return consumeProductList->CreateConsumeProductList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateConsumeProductList(BusinessLayer::ConsumeProductList* consumeProductList, std::string& errorMessage)
	{
		try
		{
			if (0 != consumeProductList->GetConsumeProductID() && 0 != consumeProductList->GetProductID()
				&& 0 != consumeProductList->GetCount() && 0 != consumeProductList->GetSum() && 0 != consumeProductList->GetStatusID()
				&& 0 != consumeProductList->GetCurrencyID())
			{
				return consumeProductList->UpdateConsumeProductList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteConsumeProductList(BusinessLayer::ConsumeProductList* consumeProductList, std::string& errorMessage)
	{
		try
		{
			if (0 != consumeProductList->GetID())
			{
				return consumeProductList->DeleteConsumeProductList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Consume product list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateConsumeRaw(BusinessLayer::ConsumeRaw* consumeRaw, std::string& errorMessage)
	{
		try
		{
			if (!consumeRaw->GetDate().empty() && 0 != consumeRaw->GetEmployeeID() && 0 != consumeRaw->GetCount()
				&& 0 != consumeRaw->GetSum() && 0 != consumeRaw->GetStatusID() && 0 != consumeRaw->GetCurrencyID()
				&& 0 != consumeRaw->GetStockEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, consumeRaw->GetCurrencyID(), errorMessage))
				{
					roundSum = round(consumeRaw->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				consumeRaw->SetSum(roundSum);
				return consumeRaw->CreateConsumeRaw(ormasDal, errorMessage);
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

	bool OrmasBL::UpdateConsumeRaw(BusinessLayer::ConsumeRaw* consumeRaw, std::string& errorMessage)
	{
		try
		{
			if (!consumeRaw->GetDate().empty() && 0 != consumeRaw->GetEmployeeID() && 0 != consumeRaw->GetCount()
				&& 0 != consumeRaw->GetSum() && 0 != consumeRaw->GetStatusID() && 0 != consumeRaw->GetCurrencyID()
				&& 0 != consumeRaw->GetStockEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, consumeRaw->GetCurrencyID(), errorMessage))
				{
					roundSum = round(consumeRaw->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				consumeRaw->SetSum(roundSum);
				return consumeRaw->UpdateConsumeRaw(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteConsumeRaw(BusinessLayer::ConsumeRaw* consumeRaw, std::string& errorMessage)
	{
		try
		{
			if (0 != consumeRaw->GetID())
			{
				return consumeRaw->DeleteConsumeRaw(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Consume raw ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateConsumeRawList(BusinessLayer::ConsumeRawList* consumeRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != consumeRawList->GetConsumeRawID() && 0 != consumeRawList->GetProductID()
				&& 0 != consumeRawList->GetCount() && 0 != consumeRawList->GetSum() && 0 != consumeRawList->GetStatusID()
				&& 0 != consumeRawList->GetCurrencyID())
			{
				return consumeRawList->CreateConsumeRawList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateConsumeRawList(BusinessLayer::ConsumeRawList* consumeRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != consumeRawList->GetConsumeRawID() && 0 != consumeRawList->GetProductID()
				&& 0 != consumeRawList->GetCount() && 0 != consumeRawList->GetSum() && 0 != consumeRawList->GetStatusID()
				&& 0 != consumeRawList->GetCurrencyID())
			{
				return consumeRawList->UpdateConsumeRawList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteConsumeRawList(BusinessLayer::ConsumeRawList* consumeRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != consumeRawList->GetID())
			{
				return consumeRawList->DeleteConsumeRawList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Consume raw list ID is 0. Something goes wrong!";
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

	bool OrmasBL::CreateDivisionAccountRelation(BusinessLayer::DivisionAccountRelation* divisionAccountReletion, std::string& errorMessage)
	{
		try
		{
			if (0 != divisionAccountReletion->GetDivisionID() && 0 != divisionAccountReletion->GetAccountID() && !divisionAccountReletion->GetCode().empty())
			{
				return divisionAccountReletion->CreateDivisionAccountRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Division-Account relation division ID, account ID and code name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateDivisionAccountRelation(BusinessLayer::DivisionAccountRelation* divisionAccountReletion, std::string& errorMessage)
	{
		try
		{
			if (0 != divisionAccountReletion->GetDivisionID() && 0 != divisionAccountReletion->GetAccountID() && !divisionAccountReletion->GetCode().empty())
			{
				return divisionAccountReletion->UpdateDivisionAccountRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Division-Account relation division ID, account ID and code name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteDivisionAccountRelation(BusinessLayer::DivisionAccountRelation* divisionAccountReletion, std::string& errorMessage)
	{
		try
		{
			if (0 != divisionAccountReletion->GetID())
			{
				return divisionAccountReletion->DeleteDivisionAccountRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Division-Account relation ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateDivisionEmployeeRelation(BusinessLayer::DivisionEmployeeRelation* divisionEmployeeRelation, std::string& errorMessage)
	{
		try
		{
			if (0 != divisionEmployeeRelation->GetDivisionID() && 0 != divisionEmployeeRelation->GetEmployeeID())
			{
				return divisionEmployeeRelation->CreateDivisionEmployeeRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Division-Employee relation division ID, employee ID and code name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateDivisionEmployeeRelation(BusinessLayer::DivisionEmployeeRelation* divisionEmployeeRelation, std::string& errorMessage)
	{
		try
		{
			if (0 != divisionEmployeeRelation->GetDivisionID() && 0 != divisionEmployeeRelation->GetEmployeeID())
			{
				return divisionEmployeeRelation->UpdateDivisionEmployeeRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Division-Account relation division ID, employee ID and code name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteDivisionEmployeeRelation(BusinessLayer::DivisionEmployeeRelation* divisionEmployeeReletion, std::string& errorMessage)
	{
		try
		{
			if (0 != divisionEmployeeReletion->GetID())
			{
				return divisionEmployeeReletion->DeleteDivisionEmployeeRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Division-Account relation ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateDivision(BusinessLayer::Division* division, std::string& errorMessage)
	{
		try
		{
			if (!division->GetCode().empty() && !division->GetName().empty())
			{
				return division->CreateDivision(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Division code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateDivision(BusinessLayer::Division* division, std::string& errorMessage)
	{
		try
		{
			if (!division->GetCode().empty() && !division->GetName().empty())
			{
				return division->UpdateDivision(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Division code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteDivision(BusinessLayer::Division* division, std::string& errorMessage)
	{
		try
		{
			if (0 != division->GetID())
			{
				return division->DeleteDivision(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Division ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}
    
	bool OrmasBL::CreateEmployee(BusinessLayer::Employee* employee, std::string& errorMessage)
	{
		try
		{
			if (!employee->GetName().empty() && !employee->GetSurname().empty() && !employee->GetPhone().empty()
				&& !employee->GetAddress().empty() && !employee->GetPassword().empty() && 0 != employee->GetRoleID() 
				&& !employee->GetBirthDate().empty() && !employee->GetHireDate().empty() && 0 != employee->GetPositionID())
			{
				return employee->CreateEmployee(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateEmployee(BusinessLayer::Employee* employee, std::string& errorMessage)
	{
		try
		{
			if (!employee->GetName().empty() && !employee->GetSurname().empty() && !employee->GetPhone().empty()
				&& !employee->GetAddress().empty() && !employee->GetPassword().empty() && 0 != employee->GetRoleID()
				&& !employee->GetBirthDate().empty() && !employee->GetHireDate().empty() && 0 != employee->GetPositionID())
			{
				return employee->UpdateEmployee(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteEmployee(BusinessLayer::Employee* employee, std::string& errorMessage)
	{
		try
		{
			if (0 != employee->GetID())
			{
				return employee->DeleteEmployee(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Employee ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateEntry(BusinessLayer::Entry* entry, std::string& errorMessage)
	{
		try
		{
			if (0 != entry->GetCreditingAccountID() && 0 != entry->GetDebitingAccountID() && !entry->GetDate().empty() 
				&& 0 != entry->GetValue())
			{
				return entry->CreateEntry(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fienlds name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateEntry(BusinessLayer::Entry* entry, std::string& errorMessage)
	{
		try
		{
			if (0 != entry->GetCreditingAccountID() && 0 != entry->GetDebitingAccountID() && !entry->GetDate().empty()
				&& 0 != entry->GetValue())
			{
				return entry->UpdateEntry(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fienlds name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteEntry(BusinessLayer::Entry* entry, std::string& errorMessage)
	{
		try
		{
			if (0 != entry->GetID())
			{
				return entry->DeleteEntry(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Entry ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateEntryRouting(BusinessLayer::EntryRouting* entryRouting, std::string& errorMessage)
	{
		try
		{
			if (0 != entryRouting->GetCreditAccountID() && 0 != entryRouting->GetDebitAccountID() && !entryRouting->GetOperation().empty())
			{
				return entryRouting->CreateEntryRouting(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fienlds name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateEntryRouting(BusinessLayer::EntryRouting* entryRouting, std::string& errorMessage)
	{
		try
		{
			if (0 != entryRouting->GetCreditAccountID() && 0 != entryRouting->GetDebitAccountID() && !entryRouting->GetOperation().empty())
			{
				return entryRouting->UpdateEntryRouting(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fienlds name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteEntryRouting(BusinessLayer::EntryRouting* entryRouting, std::string& errorMessage)
	{
		try
		{
			if (0 != entryRouting->GetID())
			{
				return entryRouting->DeleteEntryRouting(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Entry routing ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateFinancialReport(BusinessLayer::FinancialReport* finRep, std::string& errorMessage)
	{
		try
		{
			if (0 != finRep->GetAccount44010() && 0 != finRep->GetAccount55010() && !finRep->GetFromDate().empty()
				&& !finRep->GetTillDate().empty())
			{
				return finRep->CreateFinancialReport(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fienlds name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateFinancialReport(BusinessLayer::FinancialReport* finRep, std::string& errorMessage)
	{
		try
		{
			if (0 != finRep->GetAccount44010() && 0 != finRep->GetAccount55010() && !finRep->GetFromDate().empty()
				&& !finRep->GetTillDate().empty())
			{
				return finRep->UpdateFinancialReport(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fienlds name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteFinancialReport(BusinessLayer::FinancialReport* finRep, std::string& errorMessage)
	{
		try
		{
			if (0 != finRep->GetID())
			{
				return finRep->DeleteFinancialReport(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Financial report ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateInventorization(BusinessLayer::Inventorization* inventorization, std::string& errorMessage)
	{
		try
		{
			if (!inventorization->GetDate().empty() && 0 != inventorization->GetEmployeeID() && 0 != inventorization->GetCount()
				&& 0 != inventorization->GetSum() && 0 != inventorization->GetStatusID() && 0 != inventorization->GetCurrencyID()
				&& 0 != inventorization->GetStockEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, inventorization->GetCurrencyID(), errorMessage))
				{
					roundSum = round(inventorization->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				inventorization->SetSum(roundSum);
				return inventorization->CreateInventorization(ormasDal, errorMessage);
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

	bool OrmasBL::UpdateInventorization(BusinessLayer::Inventorization* inventorization, std::string& errorMessage)
	{
		try
		{
			if (!inventorization->GetDate().empty() && 0 != inventorization->GetEmployeeID() && 0 != inventorization->GetCount()
				&& 0 != inventorization->GetSum() && 0 != inventorization->GetStatusID() && 0 != inventorization->GetCurrencyID()
				&& 0 != inventorization->GetStockEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, inventorization->GetCurrencyID(), errorMessage))
				{
					roundSum = round(inventorization->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				inventorization->SetSum(roundSum);
				return inventorization->UpdateInventorization(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteInventorization(BusinessLayer::Inventorization* inventorization, std::string& errorMessage)
	{
		try
		{
			if (0 != inventorization->GetID())
			{
				return inventorization->DeleteInventorization(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Inventorization ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateInventorizationList(BusinessLayer::InventorizationList* inventorizationList, std::string& errorMessage)
	{
		try
		{
			if (0 != inventorizationList->GetInventorizationID() && 0 != inventorizationList->GetProductID()
				&& 0 != inventorizationList->GetCount() && 0 != inventorizationList->GetSum() && 0 != inventorizationList->GetStatusID()
				&& 0 != inventorizationList->GetCurrencyID())
			{
				return inventorizationList->CreateInventorizationList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateInventorizationList(BusinessLayer::InventorizationList* inventorizationList, std::string& errorMessage)
	{
		try
		{
			if (0 != inventorizationList->GetInventorizationID() && 0 != inventorizationList->GetProductID()
				&& 0 != inventorizationList->GetCount() && 0 != inventorizationList->GetSum() && 0 != inventorizationList->GetStatusID()
				&& 0 != inventorizationList->GetCurrencyID())
			{
				return inventorizationList->UpdateInventorizationList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteInventorizationList(BusinessLayer::InventorizationList* inventorizationList, std::string& errorMessage)
	{
		try
		{
			if (0 != inventorizationList->GetID())
			{
				return inventorizationList->DeleteInventorizationList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Inventorization list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateJobprice(BusinessLayer::Jobprice* jobprice, std::string& errorMessage)
	{
		try
		{
			if (0 != jobprice->GetProductID() && 0.0 != jobprice->GetValue() && 0 != jobprice->GetCurrencyID() && 
				0.0 != jobprice->GetVolume() && 0 != jobprice->GetMeasureID() && 0 != jobprice->GetPositionID())
			{
				return jobprice->CreateJobprice(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Jobprice code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateJobprice(BusinessLayer::Jobprice* jobprice, std::string& errorMessage)
	{
		try
		{
			if (0 != jobprice->GetProductID() && 0.0 != jobprice->GetValue() && 0 != jobprice->GetCurrencyID() &&
				0.0 != jobprice->GetVolume() && 0 != jobprice->GetMeasureID() && 0 != jobprice->GetPositionID())
			{
				return jobprice->UpdateJobprice(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Jobprice code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteJobprice(BusinessLayer::Jobprice* jobprice, std::string& errorMessage)
	{
		try
		{
			if (0 != jobprice->GetID())
			{
				return jobprice->DeleteJobprice(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Jobprice ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateJobsheet(BusinessLayer::Jobsheet* jobsheet, std::string& errorMessage)
	{
		try
		{
			if (!jobsheet->GetDate().empty() && 0.0 != jobsheet->GetCount() && 0 != jobsheet->GetProductID() && 0 != jobsheet->GetEmployeeID())
			{
				return jobsheet->CreateJobsheet(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Jobsheet code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateJobsheet(BusinessLayer::Jobsheet* jobsheet, std::string& errorMessage)
	{
		try
		{
			if (!jobsheet->GetDate().empty() && 0.0 != jobsheet->GetCount() && 0 != jobsheet->GetProductID() && 0 != jobsheet->GetEmployeeID())
			{
				return jobsheet->UpdateJobsheet(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Jobsheet code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteJobsheet(BusinessLayer::Jobsheet* jobsheet, std::string& errorMessage)
	{
		try
		{
			if (0 != jobsheet->GetID())
			{
				return jobsheet->DeleteJobsheet(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Jobsheet ID is 0. Some thing goes wrong!";
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

	bool OrmasBL::CreateNetCost(BusinessLayer::NetCost* netCost, std::string& errorMessage)
	{
		try
		{
			if (0 != netCost->GetProductID() && 0.0 != netCost->GetValue() && 0 != netCost->GetCurrencyID() && !netCost->GetDate().empty())
			{
				return netCost->CreateNetCost(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product , currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateNetCost(BusinessLayer::NetCost* netCost, std::string& errorMessage)
	{
		try
		{
			if (0 != netCost->GetProductID() && 0.0 != netCost->GetValue() && 0 != netCost->GetCurrencyID() && !netCost->GetDate().empty())
			{
				return netCost->UpdateNetCost(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product, currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteNetCost(BusinessLayer::NetCost* netCost, std::string& errorMessage)
	{
		try
		{
			if (0 != netCost->GetID())
			{
				return netCost->DeleteNetCost(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Price ID is 0. Some thing goes wrong!";
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
			if (!order->GetDate().empty() &&  0 != order->GetClientID() && 0 != order->GetCount()
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
			if (!order->GetDate().empty() && 0 != order->GetClientID() && 0 != order->GetCount()
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


	bool OrmasBL::CreateOrderList(BusinessLayer::OrderList* orderList, std::string& errorMessage)
	{
		try
		{
			if (0 != orderList->GetOrderID() && 0 != orderList->GetProductID()
				&& 0 != orderList->GetCount() && 0 != orderList->GetSum() && 0 != orderList->GetStatusID()
				&& 0 != orderList->GetCurrencyID())
			{
				return orderList->CreateOrderList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateOrderList(BusinessLayer::OrderList* orderList, std::string& errorMessage)
	{
		try
		{
			if (0 != orderList->GetOrderID() && 0 != orderList->GetProductID()
				&& 0 != orderList->GetCount() && 0 != orderList->GetSum() && 0 != orderList->GetStatusID()
				&& 0 != orderList->GetCurrencyID())
			{
				return orderList->UpdateOrderList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteOrderList(BusinessLayer::OrderList* orderList, std::string& errorMessage)
	{
		try
		{
			if (0 != orderList->GetID())
			{
				return orderList->DeleteOrderList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Order list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateOrderRaw(BusinessLayer::OrderRaw* orderRaw, std::string& errorMessage)
	{
		try
		{
			if (!orderRaw->GetDate().empty() && 0 != orderRaw->GetPurveyorID() && 0 != orderRaw->GetCount()
				&& 0 != orderRaw->GetSum() && 0 != orderRaw->GetStatusID() && 0 != orderRaw->GetCurrencyID()
				&& 0 != orderRaw->GetEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, orderRaw->GetCurrencyID(), errorMessage))
				{
					roundSum = round(orderRaw->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				orderRaw->SetSum(roundSum);
				return orderRaw->CreateOrderRaw(ormasDal, errorMessage);
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

	bool OrmasBL::UpdateOrderRaw(BusinessLayer::OrderRaw* orderRaw, std::string& errorMessage)
	{
		try
		{
			if (!orderRaw->GetDate().empty() && 0 != orderRaw->GetPurveyorID() && 0 != orderRaw->GetCount()
				&& 0 != orderRaw->GetSum() && 0 != orderRaw->GetStatusID() && 0 != orderRaw->GetCurrencyID()
				&& 0 != orderRaw->GetEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, orderRaw->GetCurrencyID(), errorMessage))
				{
					roundSum = round(orderRaw->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				orderRaw->SetSum(roundSum);
				return orderRaw->UpdateOrderRaw(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteOrderRaw(BusinessLayer::OrderRaw* orderRaw, std::string& errorMessage)
	{
		try
		{
			if (0 != orderRaw->GetID())
			{
				return orderRaw->DeleteOrderRaw(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Order raw ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateOrderRawList(BusinessLayer::OrderRawList* orderRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != orderRawList->GetOrderRawID() && 0 != orderRawList->GetProductID()
				&& 0 != orderRawList->GetCount() && 0 != orderRawList->GetSum() && 0 != orderRawList->GetStatusID()
				&& 0 != orderRawList->GetCurrencyID())
			{
				return orderRawList->CreateOrderRawList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateOrderRawList(BusinessLayer::OrderRawList* orderRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != orderRawList->GetOrderRawID() && 0 != orderRawList->GetProductID()
				&& 0 != orderRawList->GetCount() && 0 != orderRawList->GetSum() && 0 != orderRawList->GetStatusID()
				&& 0 != orderRawList->GetCurrencyID())
			{
				return orderRawList->UpdateOrderRawList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteOrderRawList(BusinessLayer::OrderRawList* orderRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != orderRawList->GetID())
			{
				return orderRawList->DeleteOrderRawList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Order Raw list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreatePayment(BusinessLayer::Payment* payment, std::string& errorMessage)
	{
		try
		{
			if (0 != payment->GetUserID() && 0.0 != payment->GetValue() && 0 != payment->GetCurrencyID() && !payment->GetDate().empty()
				&& 0 != payment->GetStatusID())
			{
				return payment->CreatePayment(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdatePayment(BusinessLayer::Payment* payment, std::string& errorMessage)
	{
		try
		{
			if (0 != payment->GetUserID() && 0.0 != payment->GetValue() && 0 != payment->GetCurrencyID() && !payment->GetDate().empty()
				&& 0 != payment->GetStatusID())
			{
				return payment->UpdatePayment(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeletePayment(BusinessLayer::Payment* payment, std::string& errorMessage)
	{
		try
		{
			if (0 != payment->GetID())
			{
				return payment->DeletePayment(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Payment ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreatePayslip(BusinessLayer::Payslip* payslip, std::string& errorMessage)
	{
		try
		{
			if (0 != payslip->GetSalaryID() && 0.0 != payslip->GetValue() && 0 != payslip->GetCurrencyID() && !payslip->GetDate().empty())
			{
				return payslip->CreatePayslip(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Salary, currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdatePayslip(BusinessLayer::Payslip* payslip, std::string& errorMessage)
	{
		try
		{
			if (0 != payslip->GetSalaryID() && 0.0 != payslip->GetValue() && 0 != payslip->GetCurrencyID() && !payslip->GetDate().empty())
			{
				return payslip->UpdatePayslip(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Salary, currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeletePayslip(BusinessLayer::Payslip* payslip, std::string& errorMessage)
	{
		try
		{
			if (0 != payslip->GetID())
			{
				return payslip->DeletePayslip(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Payslip ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreatePercentRate(BusinessLayer::PercentRate* percentRate, std::string& errorMessage)
	{
		try
		{
			if ((0.0 != percentRate->GetValue() || 0 != percentRate->GetPositionID()) && !percentRate->GetCondition().empty())
			{
				return percentRate->CreatePercentRate(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Value, postion and condition must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdatePercentRate(BusinessLayer::PercentRate* percentRate, std::string& errorMessage)
	{
		try
		{
			if ((0.0 != percentRate->GetValue() || 0 != percentRate->GetPositionID()) && !percentRate->GetCondition().empty())
			{
				return percentRate->UpdatePercentRate(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Value, postion and condition must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeletePercentRate(BusinessLayer::PercentRate* percentRate, std::string& errorMessage)
	{
		try
		{
			if (0 != percentRate->GetID())
			{
				return percentRate->DeletePercentRate(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Percent rate ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreatePhoto(BusinessLayer::Photo* photo, std::string& errorMessage)
	{
		try
		{
			if ((0 != photo->GetUserID() || 0 != photo->GetProductID()) && !photo->GetSource().empty())
			{
				return photo->CreatePhoto(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, product and source must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdatePhoto(BusinessLayer::Photo* photo, std::string& errorMessage)
	{
		try
		{
			if ((0 != photo->GetUserID() || 0 != photo->GetProductID()) && !photo->GetSource().empty())
			{
				return photo->UpdatePhoto(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, product and source must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeletePhoto(BusinessLayer::Photo* photo, std::string& errorMessage)
	{
		try
		{
			if (0 != photo->GetID())
			{
				return photo->DeletePhoto(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Photo ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreatePosition(BusinessLayer::Position* position, std::string& errorMessage)
	{
		try
		{
			if (!position->GetName().empty())
			{
				return position->CreatePosition(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdatePosition(BusinessLayer::Position* position, std::string& errorMessage)
	{
		try
		{
			if (!position->GetName().empty())
			{
				return position->UpdatePosition(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeletePosition(BusinessLayer::Position* position, std::string& errorMessage)
	{
		try
		{
			if (0 != position->GetID())
			{
				return position->DeletePosition(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Position ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreatePrice(BusinessLayer::Price* price, std::string& errorMessage)
	{
		try
		{
			if (0 != price->GetProductID() && 0.0 != price->GetValue() && 0 != price->GetCurrencyID() && !price->GetDate().empty())
			{
				return price->CreatePrice(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product , currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdatePrice(BusinessLayer::Price* price, std::string& errorMessage)
	{
		try
		{
			if (0 != price->GetProductID() && 0.0 != price->GetValue() && 0 != price->GetCurrencyID() && !price->GetDate().empty())
			{
				return price->UpdatePrice(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product, currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeletePrice(BusinessLayer::Price* price, std::string& errorMessage)
	{
		try
		{
			if (0 != price->GetID())
			{
				return price->DeletePrice(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Price ID is 0. Some thing goes wrong!";
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
				&& 0 != product->GetPrice() && 0 != product->GetProductTypeID() && 0 != product->GetShelfLife() && 0 != product->GetCurrencyID())
			{
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

	bool OrmasBL::CreateProductionList(BusinessLayer::ProductionList* productionList, std::string& errorMessage)
	{
		try
		{
			if (0 != productionList->GetProductionID() && 0 != productionList->GetProductID()
				&& 0 != productionList->GetCount() && 0 != productionList->GetSum() && 0 != productionList->GetStatusID()
				&& 0 != productionList->GetCurrencyID())
			{
				return productionList->CreateProductionList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateProductionList(BusinessLayer::ProductionList* productionList, std::string& errorMessage)
	{
		try
		{
			if (0 != productionList->GetProductionID() && 0 != productionList->GetProductID()
				&& 0 != productionList->GetCount() && 0 != productionList->GetSum() && 0 != productionList->GetStatusID()
				&& 0 != productionList->GetCurrencyID())
			{
				return productionList->UpdateProductionList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteProductionList(BusinessLayer::ProductionList* productionList, std::string& errorMessage)
	{
		try
		{
			if (0 != productionList->GetID())
			{
				return productionList->DeleteProductionList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Production list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateProductionConsumeRaw(BusinessLayer::ProductionConsumeRaw* pConsumeRaw, std::string& errorMessage)
	{
		try
		{
			if (!pConsumeRaw->GetDate().empty() && 0 != pConsumeRaw->GetCount()
				&& 0 != pConsumeRaw->GetSum() && 0 != pConsumeRaw->GetStatusID() && 0 != pConsumeRaw->GetCurrencyID()
				&& 0 != pConsumeRaw->GetStockEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, pConsumeRaw->GetCurrencyID(), errorMessage))
				{
					roundSum = round(pConsumeRaw->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				pConsumeRaw->SetSum(roundSum);
				return pConsumeRaw->CreateProductionConsumeRaw(ormasDal, errorMessage);
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

	bool OrmasBL::UpdateProductionConsumeRaw(BusinessLayer::ProductionConsumeRaw* pConsumeRaw, std::string& errorMessage)
	{
		try
		{
			if (!pConsumeRaw->GetDate().empty() && 0 != pConsumeRaw->GetCount()
				&& 0 != pConsumeRaw->GetSum() && 0 != pConsumeRaw->GetStatusID() && 0 != pConsumeRaw->GetCurrencyID()
				&& 0 != pConsumeRaw->GetStockEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, pConsumeRaw->GetCurrencyID(), errorMessage))
				{
					roundSum = round(pConsumeRaw->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				pConsumeRaw->SetSum(roundSum);
				return pConsumeRaw->UpdateProductionConsumeRaw(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteProductionConsumeRaw(BusinessLayer::ProductionConsumeRaw* pConsumeRaw, std::string& errorMessage)
	{
		try
		{
			if (0 != pConsumeRaw->GetID())
			{
				return pConsumeRaw->DeleteProductionConsumeRaw(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Consume raw ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateProductionConsumeRawList(BusinessLayer::ProductionConsumeRawList* pConsumeRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != pConsumeRawList->GetProductionConsumeRawID() && 0 != pConsumeRawList->GetProductID()
				&& 0 != pConsumeRawList->GetCount() && 0 != pConsumeRawList->GetSum() && 0 != pConsumeRawList->GetStatusID()
				&& 0 != pConsumeRawList->GetCurrencyID())
			{
				return pConsumeRawList->CreateProductionConsumeRawList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateProductionConsumeRawList(BusinessLayer::ProductionConsumeRawList* pConsumeRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != pConsumeRawList->GetProductionConsumeRawID() && 0 != pConsumeRawList->GetProductID()
				&& 0 != pConsumeRawList->GetCount() && 0 != pConsumeRawList->GetSum() && 0 != pConsumeRawList->GetStatusID()
				&& 0 != pConsumeRawList->GetCurrencyID())
			{
				return pConsumeRawList->UpdateProductionConsumeRawList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteProductionConsumeRawList(BusinessLayer::ProductionConsumeRawList* pConsumeRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != pConsumeRawList->GetID())
			{
				return pConsumeRawList->DeleteProductionConsumeRawList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Consume raw list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateProductionPlan(BusinessLayer::ProductionPlan* pPlan, std::string& errorMessage)
	{
		try
		{
			if (!pPlan->GetDate().empty() && 0 != pPlan->GetCount()
				&& 0 != pPlan->GetSum() && 0 != pPlan->GetStatusID() && 0 != pPlan->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, pPlan->GetCurrencyID(), errorMessage))
				{
					roundSum = round(pPlan->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				pPlan->SetSum(roundSum);
				return pPlan->CreateProductionPlan(ormasDal, errorMessage);
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

	bool OrmasBL::UpdateProductionPlan(BusinessLayer::ProductionPlan* pPlan, std::string& errorMessage)
	{
		try
		{
			if (!pPlan->GetDate().empty() && 0 != pPlan->GetCount()
				&& 0 != pPlan->GetSum() && 0 != pPlan->GetStatusID() && 0 != pPlan->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, pPlan->GetCurrencyID(), errorMessage))
				{
					roundSum = round(pPlan->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				pPlan->SetSum(roundSum);
				return pPlan->UpdateProductionPlan(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteProductionPlan(BusinessLayer::ProductionPlan* pPlan, std::string& errorMessage)
	{
		try
		{
			if (0 != pPlan->GetID())
			{
				return pPlan->DeleteProductionPlan(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Production plan ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}


	bool OrmasBL::CreateProductionPlanList(BusinessLayer::ProductionPlanList* pPlanList, std::string& errorMessage)
	{
		try
		{
			if (0 != pPlanList->GetProductionPlanID() && 0 != pPlanList->GetProductID()
				&& 0 != pPlanList->GetCount() && 0 != pPlanList->GetSum() && 0 != pPlanList->GetStatusID()
				&& 0 != pPlanList->GetCurrencyID())
			{
				return pPlanList->CreateProductionPlanList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateProductionPlanList(BusinessLayer::ProductionPlanList* pPlanList, std::string& errorMessage)
	{
		try
		{
			if (0 != pPlanList->GetProductionPlanID() && 0 != pPlanList->GetProductID()
				&& 0 != pPlanList->GetCount() && 0 != pPlanList->GetSum() && 0 != pPlanList->GetStatusID()
				&& 0 != pPlanList->GetCurrencyID())
			{
				return pPlanList->UpdateProductionPlanList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteProductionPlanList(BusinessLayer::ProductionPlanList* pPlanList, std::string& errorMessage)
	{
		try
		{
			if (0 != pPlanList->GetID())
			{
				return pPlanList->DeleteProductionPlanList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Production plan list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateProductionStock(BusinessLayer::ProductionStock* pStock, std::string& errorMessage)
	{
		try
		{
			if (0 != pStock->GetProductID() && 0 != pStock->GetCount() &&
				0 != pStock->GetSum() && 0 != pStock->GetStatusID() && 0 != pStock->GetCurrencyID())
			{
				return pStock->CreateProductionStock(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateProductionStock(BusinessLayer::ProductionStock* pStock, std::string& errorMessage)
	{
		try
		{
			if (0 != pStock->GetProductID() && 0 != pStock->GetCount() &&
				0 != pStock->GetSum() && 0 != pStock->GetStatusID() && 0 != pStock->GetCurrencyID())
			{
				return pStock->UpdateProductionStock(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteProductionStock(BusinessLayer::ProductionStock* pStock, std::string& errorMessage)
	{
		try
		{
			if (0 != pStock->GetID())
			{
				return pStock->DeleteProductionStock(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Production stock ID is 0. Something goes wrong!";
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
			if (!pType->GetName().empty() && !pType->GetShortName().empty() && !pType->GetCode().empty())
			{
				return pType->CreateProductType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product type name, code and short name must not be empty. Please fill up them!";
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
			if (!pType->GetName().empty() && !pType->GetShortName().empty() && !pType->GetCode().empty())
			{
				return pType->UpdateProductType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product type name, code and short name must not be empty. Please fill up them!";
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

	bool OrmasBL::CreatePurveyor(BusinessLayer::Purveyor* purveyor, std::string& errorMessage)
	{
		try
		{
			if (!purveyor->GetName().empty() && !purveyor->GetSurname().empty() && !purveyor->GetPhone().empty()
				&& !purveyor->GetAddress().empty() && !purveyor->GetPassword().empty() && 0 != purveyor->GetRoleID()
				&& !purveyor->GetCompanyName().empty() && 0 != purveyor->GetLocationID())
			{
				return purveyor->CreatePurveyor(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdatePurveyor(BusinessLayer::Purveyor* purveyor, std::string& errorMessage)
	{
		try
		{
			if (!purveyor->GetName().empty() && !purveyor->GetSurname().empty() && !purveyor->GetPhone().empty()
				&& !purveyor->GetAddress().empty() && !purveyor->GetPassword().empty() && 0 != purveyor->GetRoleID()
				&& !purveyor->GetCompanyName().empty() && 0 != purveyor->GetLocationID())
			{
				return purveyor->UpdatePurveyor(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeletePurveyor(BusinessLayer::Purveyor* purveyor, std::string& errorMessage)
	{
		try
		{
			if (0 != purveyor->GetID())
			{
				return purveyor->DeletePurveyor(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Purveyor ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateReceiptProduct(BusinessLayer::ReceiptProduct* receiptProduct, std::string& errorMessage)
	{
		try
		{
			if (!receiptProduct->GetDate().empty() && 0 != receiptProduct->GetEmployeeID() && 0 != receiptProduct->GetCount()
				&& 0 != receiptProduct->GetSum() && 0 != receiptProduct->GetStatusID() && 0 != receiptProduct->GetCurrencyID()
				&& 0 != receiptProduct->GetStockEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, receiptProduct->GetCurrencyID(), errorMessage))
				{
					roundSum = round(receiptProduct->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				receiptProduct->SetSum(roundSum);
				return receiptProduct->CreateReceiptProduct(ormasDal, errorMessage);
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

	bool OrmasBL::UpdateReceiptProduct(BusinessLayer::ReceiptProduct* receiptProduct, std::string& errorMessage)
	{
		try
		{
			if (!receiptProduct->GetDate().empty() && 0 != receiptProduct->GetEmployeeID() && 0 != receiptProduct->GetCount()
				&& 0 != receiptProduct->GetSum() && 0 != receiptProduct->GetStatusID() && 0 != receiptProduct->GetCurrencyID()
				&& 0 != receiptProduct->GetStockEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, receiptProduct->GetCurrencyID(), errorMessage))
				{
					roundSum = round(receiptProduct->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				receiptProduct->SetSum(roundSum);
				return receiptProduct->UpdateReceiptProduct(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteReceiptProduct(BusinessLayer::ReceiptProduct* receiptProduct, std::string& errorMessage)
	{
		try
		{
			if (0 != receiptProduct->GetID())
			{
				return receiptProduct->DeleteReceiptProduct(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Reciept product ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateReceiptProductList(BusinessLayer::ReceiptProductList* receiptProductList, std::string& errorMessage)
	{
		try
		{
			if (0 != receiptProductList->GetReceiptProductID() && 0 != receiptProductList->GetProductID()
				&& 0 != receiptProductList->GetCount() && 0 != receiptProductList->GetSum() && 0 != receiptProductList->GetStatusID()
				&& 0 != receiptProductList->GetCurrencyID())
			{
				return receiptProductList->CreateReceiptProductList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateReceiptProductList(BusinessLayer::ReceiptProductList* receiptProductList, std::string& errorMessage)
	{
		try
		{
			if (0 != receiptProductList->GetReceiptProductID() && 0 != receiptProductList->GetProductID()
				&& 0 != receiptProductList->GetCount() && 0 != receiptProductList->GetSum() && 0 != receiptProductList->GetStatusID()
				&& 0 != receiptProductList->GetCurrencyID())
			{
				return receiptProductList->UpdateReceiptProductList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteReceiptProductList(BusinessLayer::ReceiptProductList* receiptProductList, std::string& errorMessage)
	{
		try
		{
			if (0 != receiptProductList->GetID())
			{
				return receiptProductList->DeleteReceiptProductList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Receipt product list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateReceiptRaw(BusinessLayer::ReceiptRaw* receiptRaw, std::string& errorMessage)
	{
		try
		{
			if (!receiptRaw->GetDate().empty() && 0 != receiptRaw->GetEmployeeID() && 0 != receiptRaw->GetCount()
				&& 0 != receiptRaw->GetSum() && 0 != receiptRaw->GetStatusID() && 0 != receiptRaw->GetCurrencyID()
				&& 0 != receiptRaw->GetStockEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, receiptRaw->GetCurrencyID(), errorMessage))
				{
					roundSum = round(receiptRaw->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				receiptRaw->SetSum(roundSum);
				return receiptRaw->CreateReceiptRaw(ormasDal, errorMessage);
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

	bool OrmasBL::UpdateReceiptRaw(BusinessLayer::ReceiptRaw* receiptRaw, std::string& errorMessage)
	{
		try
		{
			if (!receiptRaw->GetDate().empty() && 0 != receiptRaw->GetEmployeeID() && 0 != receiptRaw->GetCount()
				&& 0 != receiptRaw->GetSum() && 0 != receiptRaw->GetStatusID() && 0 != receiptRaw->GetCurrencyID()
				&& 0 != receiptRaw->GetStockEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, receiptRaw->GetCurrencyID(), errorMessage))
				{
					roundSum = round(receiptRaw->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				receiptRaw->SetSum(roundSum);
				return receiptRaw->UpdateReceiptRaw(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteReceiptRaw(BusinessLayer::ReceiptRaw* receiptRaw, std::string& errorMessage)
	{
		try
		{
			if (0 != receiptRaw->GetID())
			{
				return receiptRaw->DeleteReceiptRaw(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Receipt raw ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateReceiptRawList(BusinessLayer::ReceiptRawList* receiptRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != receiptRawList->GetReceiptRawID() && 0 != receiptRawList->GetProductID()
				&& 0 != receiptRawList->GetCount() && 0 != receiptRawList->GetSum() && 0 != receiptRawList->GetStatusID()
				&& 0 != receiptRawList->GetCurrencyID())
			{
				return receiptRawList->CreateReceiptRawList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateReceiptRawList(BusinessLayer::ReceiptRawList* receiptRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != receiptRawList->GetReceiptRawID() && 0 != receiptRawList->GetProductID()
				&& 0 != receiptRawList->GetCount() && 0 != receiptRawList->GetSum() && 0 != receiptRawList->GetStatusID()
				&& 0 != receiptRawList->GetCurrencyID())
			{
				return receiptRawList->UpdateReceiptRawList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteReceiptRawList(BusinessLayer::ReceiptRawList* receiptRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != receiptRawList->GetID())
			{
				return receiptRawList->DeleteReceiptRawList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Receipt raw list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateRefund(BusinessLayer::Refund* refund, std::string& errorMessage)
	{
		try
		{
			if (0 != refund->GetUserID() && 0.0 != refund->GetValue() && 0 != refund->GetCurrencyID() && !refund->GetDate().empty())
			{
				return refund->CreateRefund(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateRefund(BusinessLayer::Refund* refund, std::string& errorMessage)
	{
		try
		{
			if (0 != refund->GetUserID() && 0.0 != refund->GetValue() && 0 != refund->GetCurrencyID() && !refund->GetDate().empty())
			{
				return refund->UpdateRefund(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteRefund(BusinessLayer::Refund* refund, std::string& errorMessage)
	{
		try
		{
			if (0 != refund->GetID())
			{
				return refund->DeleteRefund(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Refund ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateRelation(BusinessLayer::Relation* relation, std::string& errorMessage)
	{
		try
		{
			if (0 != relation->GetUser1ID() && 0.0 != relation->GetUser2ID() && 0 != relation->GetRelationTypeID())
			{
				return relation->CreateRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User 1, user 2 and relation type must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateRelation(BusinessLayer::Relation* relation, std::string& errorMessage)
	{
		try
		{
			if (0 != relation->GetUser1ID() && 0.0 != relation->GetUser2ID() && 0 != relation->GetRelationTypeID())
			{
				return relation->UpdateRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User 1, user 2 and relation type must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteRelation(BusinessLayer::Relation* relation, std::string& errorMessage)
	{
		try
		{
			if (0 != relation->GetID())
			{
				return relation->DeleteRelation(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Relation ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateRelationType(BusinessLayer::RelationType* relationType, std::string& errorMessage)
	{
		try
		{
			if (!relationType->GetName().empty())
			{
				return relationType->CreateRelationType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Relation type name must not be empty. Please fill up it!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateRelationType(BusinessLayer::RelationType* relationType, std::string& errorMessage)
	{
		try
		{
			if (!relationType->GetName().empty())
			{
				return relationType->UpdateRelationType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Relation type name must not be empty. Please fill up it!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteRelationType(BusinessLayer::RelationType* relationType, std::string& errorMessage)
	{
		try
		{
			if (0 != relationType->GetID())
			{
				return relationType->DeleteRelationType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Relation type ID is 0. Some thing goes wrong!";
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
			if (!ret->GetDate().empty() && 0 != ret->GetClientID() && 0 != ret->GetCount()
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
			if (!ret->GetDate().empty() && 0 != ret->GetClientID() && 0 != ret->GetCount()
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
	
	bool OrmasBL::CreateReturnList(BusinessLayer::ReturnList* returnList, std::string& errorMessage)
	{
		try
		{
			if (0 != returnList->GetReturnID() && 0 != returnList->GetProductID()
				&& 0 != returnList->GetCount() && 0 != returnList->GetSum() && 0 != returnList->GetStatusID()
				&& 0 != returnList->GetCurrencyID())
			{
				return returnList->CreateReturnList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateReturnList(BusinessLayer::ReturnList* returnList, std::string& errorMessage)
	{
		try
		{
			if (0 != returnList->GetReturnID() && 0 != returnList->GetProductID()
				&& 0 != returnList->GetCount() && 0 != returnList->GetSum() && 0 != returnList->GetStatusID()
				&& 0 != returnList->GetCurrencyID())
			{
				return returnList->UpdateReturnList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteReturnList(BusinessLayer::ReturnList* returnList, std::string& errorMessage)
	{
		try
		{
			if (0 != returnList->GetID())
			{
				return returnList->DeleteReturnList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Return list ID is 0. Something goes wrong!";
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
			if (!role->GetCode().empty() && !role->GetName().empty())
			{
				return role->CreateRole(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Role name and code must not be empty. Please fill up it!";
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
			if (!role->GetCode().empty() && !role->GetName().empty())
			{
				return role->UpdateRole(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Role name and code must not be empty. Please fill up it!";
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

	bool OrmasBL::CreateSalary(BusinessLayer::Salary* salary, std::string& errorMessage)
	{
		try
		{
			if (0 != salary->GetEmployeeID() && 0.0 != salary->GetValue() && 0 != salary->GetCurrencyID() && 0 != salary->GetSalaryTypeID()
				&& !salary->GetDate().empty())
			{
				return salary->CreateSalary(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product , currency, date, salary type and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateSalary(BusinessLayer::Salary* salary, std::string& errorMessage)
	{
		try
		{
			if (0 != salary->GetEmployeeID() && 0.0 != salary->GetValue() && 0 != salary->GetCurrencyID() && 0 != salary->GetSalaryTypeID()
				&& !salary->GetDate().empty())
			{
				return salary->UpdateSalary(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Product , currency, date, salary type and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteSalary(BusinessLayer::Salary* salary, std::string& errorMessage)
	{
		try
		{
			if (0 != salary->GetID())
			{
				return salary->DeleteSalary(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Salary ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateSalaryType(BusinessLayer::SalaryType* salaryType, std::string& errorMessage)
	{
		try
		{
			if (!salaryType->GetCode().empty() && !salaryType->GetName().empty())
			{
				return salaryType->CreateSalaryType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Salary type code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateSalaryType(BusinessLayer::SalaryType* salaryType, std::string& errorMessage)
	{
		try
		{
			if (!salaryType->GetCode().empty() && !salaryType->GetName().empty())
			{
				return salaryType->UpdateSalaryType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Salary type code and name must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteSalaryType(BusinessLayer::SalaryType* salaryType, std::string& errorMessage)
	{
		try
		{
			if (0 != salaryType->GetID())
			{
				return salaryType->DeleteSalaryType(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Salary type ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateSpecification(BusinessLayer::Specification* specification, std::string& errorMessage)
	{
		try
		{
			if (0 != specification->GetProductID() && 0 != specification->GetSum() && 0 != specification->GetCurrencyID()
				&& 0 != specification->GetEmployeeID() && !specification->GetDate().empty())
			{
				return specification->CreateSpecification(ormasDal, errorMessage);
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

	bool OrmasBL::UpdateSpecification(BusinessLayer::Specification* specification, std::string& errorMessage)
	{
		try
		{
			if (0 != specification->GetProductID() && 0 != specification->GetSum() && 0 != specification->GetCurrencyID()
				&& 0 != specification->GetEmployeeID() && !specification->GetDate().empty())
			{
				return specification->UpdateSpecification(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteSpecification(BusinessLayer::Specification* specification, std::string& errorMessage)
	{
		try
		{
			if (0 != specification->GetID())
			{
				return specification->DeleteSpecification(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Specification raw ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateSpecificationList(BusinessLayer::SpecificationList* specificationList, std::string& errorMessage)
	{
		try
		{
			if (0 != specificationList->GetSpecificationID() && 0 != specificationList->GetProductID()
				&& 0 != specificationList->GetCount())
			{
				return specificationList->CreateSpecificationList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateSpecificationList(BusinessLayer::SpecificationList* specificationList, std::string& errorMessage)
	{
		try
		{
			if (0 != specificationList->GetSpecificationID() && 0 != specificationList->GetProductID()
				&& 0.0 != specificationList->GetCount())
			{
				return specificationList->UpdateSpecificationList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteSpecificationList(BusinessLayer::SpecificationList* specificationList, std::string& errorMessage)
	{
		try
		{
			if (0 != specificationList->GetID())
			{
				return specificationList->DeleteSpecificationList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Specification list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateSpoilage(BusinessLayer::Spoilage* spoilage, std::string& errorMessage)
	{
		try
		{
			if (!spoilage->GetDate().empty() && 0 != spoilage->GetCount()
				&& 0 != spoilage->GetSum() && 0 != spoilage->GetStatusID() && 0 != spoilage->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, spoilage->GetCurrencyID(), errorMessage))
				{
					roundSum = round(spoilage->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				spoilage->SetSum(roundSum);
				return spoilage->CreateSpoilage(ormasDal, errorMessage);
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

	bool OrmasBL::UpdateSpoilage(BusinessLayer::Spoilage* spoilage, std::string& errorMessage)
	{
		try
		{
			if (!spoilage->GetDate().empty() && 0 != spoilage->GetCount()
				&& 0 != spoilage->GetSum() && 0 != spoilage->GetStatusID() && 0 != spoilage->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, spoilage->GetCurrencyID(), errorMessage))
				{
					roundSum = round(spoilage->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				spoilage->SetSum(roundSum);
				return spoilage->UpdateSpoilage(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteSpoilage(BusinessLayer::Spoilage* spoilage, std::string& errorMessage)
	{
		try
		{
			if (0 != spoilage->GetID())
			{
				return spoilage->DeleteSpoilage(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Spoilage ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}


	bool OrmasBL::CreateSpoilageList(BusinessLayer::SpoilageList* spoilageList, std::string& errorMessage)
	{
		try
		{
			if (0 != spoilageList->GetSpoilageID() && 0 != spoilageList->GetProductID()
				&& 0 != spoilageList->GetCount() && 0 != spoilageList->GetSum() && 0 != spoilageList->GetStatusID()
				&& 0 != spoilageList->GetCurrencyID())
			{
				return spoilageList->CreateSpoilageList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateSpoilageList(BusinessLayer::SpoilageList* spoilageList, std::string& errorMessage)
	{
		try
		{
			if (0 != spoilageList->GetSpoilageID() && 0 != spoilageList->GetProductID()
				&& 0 != spoilageList->GetCount() && 0 != spoilageList->GetSum() && 0 != spoilageList->GetStatusID()
				&& 0 != spoilageList->GetCurrencyID())
			{
				return spoilageList->UpdateSpoilageList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteSpoilageList(BusinessLayer::SpoilageList* spoilageList, std::string& errorMessage)
	{
		try
		{
			if (0 != spoilageList->GetID())
			{
				return spoilageList->DeleteSpoilageList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Spoilage list list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateState(BusinessLayer::State* state, std::string& errorMessage)
	{
		try
		{
			if (0 != state->GetUniversalID() && 0 != state->GetStatusID() && !state->GetLastChange().empty())
			{
				return state->CreateState(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! State last change, universal ID and status ID must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateState(BusinessLayer::State* state, std::string& errorMessage)
	{
		try
		{
			if (0 != state->GetUniversalID() && 0 != state->GetStatusID() && !state->GetLastChange().empty())
			{
				return state->UpdateState(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! State last change, universal ID and status ID must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteState(BusinessLayer::State* state, std::string& errorMessage)
	{
		try
		{
			if (0 != state->GetID())
			{
				return state->DeleteState(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! State ID is 0. Some thing goes wrong!";
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

	bool OrmasBL::CreateStatusRule(BusinessLayer::StatusRule* statusRule, std::string& errorMessage)
	{
		try
		{
			if (!statusRule->GetOperation().empty() && 0 != statusRule->GetStatusID())
			{
				return statusRule->CreateStatusRule(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Status rule operation and status ID must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateStatusRule(BusinessLayer::StatusRule* statusRule, std::string& errorMessage)
	{
		try
		{
			if (!statusRule->GetOperation().empty() && 0 != statusRule->GetStatusID())
			{
				return statusRule->UpdateStatusRule(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Status rule operation and status ID must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteStatusRule(BusinessLayer::StatusRule* statusRule, std::string& errorMessage)
	{
		try
		{
			if (0 != statusRule->GetID())
			{
				return statusRule->DeleteStatusRule(ormasDal, errorMessage);
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

	bool OrmasBL::CreateStock(BusinessLayer::Stock* stock, std::string& errorMessage)
	{
		try
		{
			if (0 != stock->GetProductID() && 0 != stock->GetCount() &&
				0 != stock->GetSum() && 0 != stock->GetStatusID() && 0 != stock->GetCurrencyID())
			{
				return stock->CreateStock(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateStock(BusinessLayer::Stock* stock, std::string& errorMessage)
	{
		try
		{
			if (0 != stock->GetProductID() && 0 != stock->GetCount() &&
				0 != stock->GetSum() && 0 != stock->GetStatusID() && 0 != stock->GetCurrencyID())
			{
				return stock->UpdateStock(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteStock(BusinessLayer::Stock* stock, std::string& errorMessage)
	{
		try
		{
			if (0 != stock->GetID())
			{
				return stock->DeleteStock(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Stock ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateSubaccount(BusinessLayer::Subaccount* subaccount, std::string& errorMessage)
	{
		try
		{
			if (0 != subaccount->GetParentAccountID() && !subaccount->GetNumber().empty() && 0 != subaccount->GetCurrencyID() 
				&& !subaccount->GetOpenedDate().empty() && 0 != subaccount->GetStatusID())
			{
				return subaccount->CreateSubaccount(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateSubaccount(BusinessLayer::Subaccount* subaccount, std::string& errorMessage)
	{
		try
		{
			if (0 != subaccount->GetParentAccountID() && !subaccount->GetNumber().empty() && 0 != subaccount->GetCurrencyID()
				&& !subaccount->GetOpenedDate().empty() && 0 != subaccount->GetStatusID())
			{
				return subaccount->UpdateSubaccount(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteSubaccount(BusinessLayer::Subaccount* subaccount, std::string& errorMessage)
	{
		try
		{
			if (0 != subaccount->GetID())
			{
				return subaccount->DeleteSubaccount(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Subaccount item ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateSubaccountHistory(BusinessLayer::SubaccountHistory* subaccountHis, std::string& errorMessage)
	{
		try
		{
			if (!subaccountHis->GetFromDate().empty() && !subaccountHis->GetTillDate().empty())
			{
				return subaccountHis->CreateSubaccountHistory(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateSubaccountHistory(BusinessLayer::SubaccountHistory* subaccountHis, std::string& errorMessage)
	{
		try
		{
			if (!subaccountHis->GetFromDate().empty() && !subaccountHis->GetTillDate().empty())
			{
				return subaccountHis->UpdateSubaccountHistory(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteSubaccountHistory(BusinessLayer::SubaccountHistory* subaccountHis, std::string& errorMessage)
	{
		try
		{
			if (0 != subaccountHis->GetID())
			{
				return subaccountHis->DeleteSubaccountHistory(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Subaccount history item ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateTax(BusinessLayer::Tax* tax, std::string& errorMessage)
	{
		try
		{
			if (!tax->GetName().empty() && !tax->GetCode().empty())
			{
				return tax->CreateTax(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateTax(BusinessLayer::Tax* tax, std::string& errorMessage)
	{
		try
		{
			if (!tax->GetName().empty() && !tax->GetCode().empty())
			{
				return tax->UpdateTax(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! All fields must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteTax(BusinessLayer::Tax* tax, std::string& errorMessage)
	{
		try
		{
			if (0 != tax->GetID())
			{
				return tax->DeleteTax(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Tax item ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateTimesheet(BusinessLayer::Timesheet* timesheet, std::string& errorMessage)
	{
		try
		{
			if (0 != timesheet->GetSalaryID() && 0 != timesheet->GetWorkedTime() && !timesheet->GetDate().empty())
			{
				return timesheet->CreateTimesheet(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateTimesheet(BusinessLayer::Timesheet* timesheet, std::string& errorMessage)
	{
		try
		{
			if (0 != timesheet->GetSalaryID() && 0 != timesheet->GetWorkedTime() && !timesheet->GetDate().empty())
			{
				return timesheet->UpdateTimesheet(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteTimesheet(BusinessLayer::Timesheet* timesheet, std::string& errorMessage)
	{
		try
		{
			if (0 != timesheet->GetID())
			{
				return timesheet->DeleteTimesheet(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Timesheet ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateTransport(BusinessLayer::Transport* transport, std::string& errorMessage)
	{
		try
		{
			if (!transport->GetDate().empty() && 0 != transport->GetUserID() && 0 != transport->GetCount()
				&& 0 != transport->GetSum() && 0 != transport->GetStatusID() && 0 != transport->GetCurrencyID()
				&& 0 != transport->GetEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, transport->GetCurrencyID(), errorMessage))
				{
					roundSum = round(transport->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				transport->SetSum(roundSum);
				return transport->CreateTransport(ormasDal, errorMessage);
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

	bool OrmasBL::UpdateTransport(BusinessLayer::Transport* transport, std::string& errorMessage)
	{
		try
		{
			if (!transport->GetDate().empty() && 0 != transport->GetUserID() && 0 != transport->GetCount()
				&& 0 != transport->GetSum() && 0 != transport->GetStatusID() && 0 != transport->GetCurrencyID()
				&& 0 != transport->GetEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, transport->GetCurrencyID(), errorMessage))
				{
					roundSum = round(transport->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				transport->SetSum(roundSum);
				return transport->UpdateTransport(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteTransport(BusinessLayer::Transport* transport, std::string& errorMessage)
	{
		try
		{
			if (0 != transport->GetID())
			{
				return transport->DeleteTransport(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Transport ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateTransportList(BusinessLayer::TransportList* transportList, std::string& errorMessage)
	{
		try
		{
			if (0 != transportList->GetTransportID() && 0 != transportList->GetProductID()
				&& 0 != transportList->GetCount() && 0 != transportList->GetSum() && 0 != transportList->GetStatusID()
				&& 0 != transportList->GetCurrencyID())
			{
				return transportList->CreateTransportList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateTransportList(BusinessLayer::TransportList* transportList, std::string& errorMessage)
	{
		try
		{
			if (0 != transportList->GetTransportID() && 0 != transportList->GetProductID()
				&& 0 != transportList->GetCount() && 0 != transportList->GetSum() && 0 != transportList->GetStatusID()
				&& 0 != transportList->GetCurrencyID())
			{
				return transportList->UpdateTransportList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteTransportList(BusinessLayer::TransportList* transportList, std::string& errorMessage)
	{
		try
		{
			if (0 != transportList->GetID())
			{
				return transportList->DeleteTransportList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Transport list ID is 0. Something goes wrong!";
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
			if (!user->GetName().empty() && !user->GetSurname().empty() && !user->GetPhone().empty() && !user->GetAddress().empty()
				&& !user->GetPassword().empty() && 0 != user->GetRoleID())
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
			if (!user->GetName().empty() && !user->GetSurname().empty() && !user->GetPhone().empty() && !user->GetAddress().empty()
				&& !user->GetPassword().empty()  && 0 != user->GetRoleID())
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
	
	bool OrmasBL::CreateWithdrawal(BusinessLayer::Withdrawal* payment, std::string& errorMessage)
	{
		try
		{
			if (0 != payment->GetUserID() && 0.0 != payment->GetValue() && 0 != payment->GetCurrencyID() && !payment->GetDate().empty())
			{
				return payment->CreateWithdrawal(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateWithdrawal(BusinessLayer::Withdrawal* payment, std::string& errorMessage)
	{
		try
		{
			if (0 != payment->GetUserID() && 0.0 != payment->GetValue() && 0 != payment->GetCurrencyID() && !payment->GetDate().empty())
			{
				return payment->UpdateWithdrawal(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! User, currency, date and value must not be empty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::DeleteWithdrawal(BusinessLayer::Withdrawal* payment, std::string& errorMessage)
	{
		try
		{
			if (0 != payment->GetID())
			{
				return payment->DeleteWithdrawal(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Payment ID is 0. Some thing goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateWriteOff(BusinessLayer::WriteOff* writeOff, std::string& errorMessage)
	{
		try
		{
			if (!writeOff->GetDate().empty() && 0 != writeOff->GetClientID() && 0 != writeOff->GetCount()
				&& 0 != writeOff->GetSum() && 0 != writeOff->GetStatusID() && 0 != writeOff->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, writeOff->GetCurrencyID(), errorMessage))
				{
					roundSum = round(writeOff->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				writeOff->SetSum(roundSum);
				return writeOff->CreateWriteOff(ormasDal, errorMessage);
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

	bool OrmasBL::UpdateWriteOff(BusinessLayer::WriteOff* writeOff, std::string& errorMessage)
	{
		try
		{
			if (!writeOff->GetDate().empty() && 0 != writeOff->GetClientID() && 0 != writeOff->GetCount()
				&& 0 != writeOff->GetSum() && 0 != writeOff->GetStatusID() && 0 != writeOff->GetCurrencyID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, writeOff->GetCurrencyID(), errorMessage))
				{
					roundSum = round(writeOff->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				writeOff->SetSum(roundSum);
				return writeOff->UpdateWriteOff(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteWriteOff(BusinessLayer::WriteOff* writeOff, std::string& errorMessage)
	{
		try
		{
			if (0 != writeOff->GetID())
			{
				return writeOff->DeleteWriteOff(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Write-off ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateWriteOffList(BusinessLayer::WriteOffList* writeOffList, std::string& errorMessage)
	{
		try
		{
			if (0 != writeOffList->GetWriteOffID() && 0 != writeOffList->GetProductID()
				&& 0 != writeOffList->GetCount() && 0 != writeOffList->GetSum() && 0 != writeOffList->GetStatusID()
				&& 0 != writeOffList->GetCurrencyID())
			{
				return writeOffList->CreateWriteOffList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateWriteOffList(BusinessLayer::WriteOffList* writeOffList, std::string& errorMessage)
	{
		try
		{
			if (0 != writeOffList->GetWriteOffID() && 0 != writeOffList->GetProductID()
				&& 0 != writeOffList->GetCount() && 0 != writeOffList->GetSum() && 0 != writeOffList->GetStatusID()
				&& 0 != writeOffList->GetCurrencyID())
			{
				return writeOffList->UpdateWriteOffList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteWriteOffList(BusinessLayer::WriteOffList* writeOffList, std::string& errorMessage)
	{
		try
		{
			if (0 != writeOffList->GetID())
			{
				return writeOffList->DeleteWriteOffList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Write-off list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::CreateWriteOffRaw(BusinessLayer::WriteOffRaw* writeOffRaw, std::string& errorMessage)
	{
		try
		{
			if (!writeOffRaw->GetDate().empty() && 0 != writeOffRaw->GetEmployeeID() && 0 != writeOffRaw->GetCount()
				&& 0 != writeOffRaw->GetSum() && 0 != writeOffRaw->GetStatusID() && 0 != writeOffRaw->GetCurrencyID()
				&& 0 != writeOffRaw->GetStockEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, writeOffRaw->GetCurrencyID(), errorMessage))
				{
					roundSum = round(writeOffRaw->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				writeOffRaw->SetSum(roundSum);
				return writeOffRaw->CreateWriteOffRaw(ormasDal, errorMessage);
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

	bool OrmasBL::UpdateWriteOffRaw(BusinessLayer::WriteOffRaw* writeOffRaw, std::string& errorMessage)
	{
		try
		{
			if (!writeOffRaw->GetDate().empty() && 0 != writeOffRaw->GetEmployeeID() && 0 != writeOffRaw->GetCount()
				&& 0 != writeOffRaw->GetSum() && 0 != writeOffRaw->GetStatusID() && 0 != writeOffRaw->GetCurrencyID()
				&& 0 != writeOffRaw->GetStockEmployeeID())
			{
				double roundSum = 0;
				Currency *cur = new Currency();
				if (cur->GetCurrencyByID(ormasDal, writeOffRaw->GetCurrencyID(), errorMessage))
				{
					roundSum = round(writeOffRaw->GetSum() * cur->GetUnit()) / cur->GetUnit();
				}
				else
				{
					return false;
				}
				delete cur;
				writeOffRaw->SetSum(roundSum);
				return writeOffRaw->UpdateWriteOffRaw(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteWriteOffRaw(BusinessLayer::WriteOffRaw* writeOffRaw, std::string& errorMessage)
	{
		try
		{
			if (0 != writeOffRaw->GetID())
			{
				return writeOffRaw->DeleteWriteOffRaw(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Write-off raw ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}
	
	bool OrmasBL::CreateWriteOffRawList(BusinessLayer::WriteOffRawList* writeOffRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != writeOffRawList->GetWriteOffRawID() && 0 != writeOffRawList->GetProductID()
				&& 0 != writeOffRawList->GetCount() && 0 != writeOffRawList->GetSum() && 0 != writeOffRawList->GetStatusID()
				&& 0 != writeOffRawList->GetCurrencyID())
			{
				return writeOffRawList->CreateWriteOffRawList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! One or several feilds are emplty. Please fill up them!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}

	bool OrmasBL::UpdateWriteOffRawList(BusinessLayer::WriteOffRawList* writeOffRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != writeOffRawList->GetWriteOffRawID() && 0 != writeOffRawList->GetProductID()
				&& 0 != writeOffRawList->GetCount() && 0 != writeOffRawList->GetSum() && 0 != writeOffRawList->GetStatusID()
				&& 0 != writeOffRawList->GetCurrencyID())
			{
				return writeOffRawList->UpdateWriteOffRawList(ormasDal, errorMessage);
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

	bool OrmasBL::DeleteWriteOffRawList(BusinessLayer::WriteOffRawList* writeOffRawList, std::string& errorMessage)
	{
		try
		{
			if (0 != writeOffRawList->GetID())
			{
				return writeOffRawList->DeleteWriteOffRawList(ormasDal, errorMessage);
			}
			else
			{
				errorMessage = "Error! Write-off raw  list ID is 0. Something goes wrong!";
			}
		}
		catch (...)
		{
			errorMessage = "Fatal error! Please contact with application provider.";
		}
		return false;
	}


	//Close of month functions
	//Close of month
	bool OrmasBL::CloseOfMonth(std::string fromDate, std::string tillDate)
	{
		std::string errorMessage = "";
		ormasDal.StartTransaction(errorMessage);
		if (CalculateEmployeeSalary(fromDate, tillDate))
		{
			ormasDal.CommitTransaction(errorMessage);
		}
		else
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		ormasDal.StartTransaction(errorMessage);
		if (!SaveAccountState(fromDate, ""))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!CorrectingEntries())
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!GenerateReports(fromDate, tillDate))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!CalculateTax(fromDate, tillDate))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!RecalculateNetCost(fromDate, tillDate))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		if (!CalculateCloseOfMonth(fromDate, tillDate))
		{
			ormasDal.CancelTransaction(errorMessage);
			return false;
		}
		ormasDal.CommitTransaction(errorMessage);
		CloseOfAccount70000();
		if (!SaveAccountState("", tillDate))
		{
			return false;
		}
		return true;
	}

	bool OrmasBL::SaveAccountState(std::string fromDate, std::string tillDate)
	{
		std::string errorMessage = "";
		if (tillDate.empty())
		{
			//save state of accounts
			std::vector<Account> vecForAccount;
			std::vector<DataLayer::accountsCollection> accCollection;
			accCollection = ormasDal.GetAccounts(errorMessage);
			if (!accCollection.empty()){
				for (auto data : accCollection)
				{
					vecForAccount.push_back(Account(data));
				}
			}
			AccountHistory accHis;
			for each (auto item in vecForAccount)
			{
				accHis.Clear();
				accHis.SetID(ormasDal.GenerateID());
				accHis.SetAccountID(item.GetID());
				accHis.SetNumber(item.GetNumber());
				accHis.SetStartBalance(item.GetStartBalance());
				accHis.SetCurrentBalance(item.GetCurrentBalance());
				accHis.SetFromDate(fromDate);
				accHis.SetTillDate(fromDate);
				if (!accHis.CreateAccountHistory(ormasDal, errorMessage))
					return false;
			}

			//save state of subaccounts
			std::vector<SubaccountView> vecForSubaccountHis;
			std::vector<DataLayer::subaccountsViewCollection> subaccCollection;
			subaccCollection = ormasDal.GetSubaccounts(errorMessage);
			if (!subaccCollection.empty()){
				for (auto data : subaccCollection)
				{
					vecForSubaccountHis.push_back(SubaccountView(data));
				}
			}
			SubaccountHistory saccHis;
			for each (auto item in vecForSubaccountHis)
			{
				saccHis.Clear();
				saccHis.SetID(ormasDal.GenerateID());
				saccHis.SetSubaccountID(item.GetID());
				saccHis.SetStartBalance(item.GetStartBalance());
				saccHis.SetCurrentBalance(item.GetCurrentBalance());
				saccHis.SetFromDate(fromDate);
				saccHis.SetTillDate(fromDate);
				if (!saccHis.CreateSubaccountHistory(ormasDal, errorMessage))
					return false;
			}
		}
		if (fromDate.empty())
		{
			//save state of accounts
			std::vector<Account> vecForAccount;
			std::vector<DataLayer::accountsCollection> accCollection;
			accCollection = ormasDal.GetAccounts(errorMessage);
			if (!accCollection.empty()){
				for (auto data : accCollection)
				{
					vecForAccount.push_back(Account(data));
				}
			}
			AccountHistory accHis;
			for each (auto item in vecForAccount)
			{
				accHis.Clear();
				accHis.SetID(ormasDal.GenerateID());
				accHis.SetAccountID(item.GetID());
				accHis.SetNumber(item.GetNumber());
				accHis.SetStartBalance(item.GetStartBalance());
				accHis.SetCurrentBalance(item.GetCurrentBalance());
				accHis.SetFromDate(tillDate);
				accHis.SetTillDate(tillDate);
				if (!accHis.CreateAccountHistory(ormasDal, errorMessage))
					return false;
			}

			//save state of subaccounts
			std::vector<SubaccountView> vecForSubaccountHis;
			std::vector<DataLayer::subaccountsViewCollection> subaccCollection;
			subaccCollection = ormasDal.GetSubaccounts(errorMessage);
			if (!subaccCollection.empty()){
				for (auto data : subaccCollection)
				{
					vecForSubaccountHis.push_back(SubaccountView(data));
				}
			}
			SubaccountHistory saccHis;
			for each (auto item in vecForSubaccountHis)
			{
				saccHis.Clear();
				saccHis.SetID(ormasDal.GenerateID());
				saccHis.SetSubaccountID(item.GetID());
				saccHis.SetStartBalance(item.GetStartBalance());
				saccHis.SetCurrentBalance(item.GetCurrentBalance());
				saccHis.SetFromDate(tillDate);
				saccHis.SetTillDate(tillDate);
				if (!saccHis.CreateSubaccountHistory(ormasDal, errorMessage))
					return false;
			}
		}
		return true;
	}

	bool OrmasBL::CalculateEmployeeSalary(std::string fromDate, std::string tillDate)
	{
		std::string errorMessage = "";
		double sum = 0;
		double count = 0;
		std::vector<EmployeeView> employeeVector = this->GetAllDataForClass<EmployeeView>(errorMessage);
		if (employeeVector.size() > 0)
		{
			Salary salary;
			std::string salaryFilter;
			std::vector<SalaryView> salaryVector;
			std::map<std::string, int> salaryTypeMap = SalaryType::GetSalaryTypesAsMap(ormasDal, errorMessage);
			std::map<std::string, int> statusMap = Status::GetStatusesAsMap(ormasDal, errorMessage);
			Payslip payslip;
			Order order;
			Timesheet timesheet;
			Jobsheet jobsheet;
			Jobprice jobprice;
			std::string orderFilter;
			std::string timesheetFilter;
			std::string jobsheetFilter;
			std::vector<OrderView> orderVector;
			std::vector<TimesheetView> timesheetVector;
			std::vector<JobsheetView> jobsheetVector;
			std::map<int, double> workedPieceMap;

			for each (auto employeeItem in employeeVector)
			{
				if (!employeeItem.IsEmpty())
				{
					errorMessage = "";
					salary.Clear();
					salary.SetEmployeeID(employeeItem.GetID());
					salaryFilter = salary.GenerateFilter(ormasDal);
					salaryVector.clear();
					salaryVector = this->GetAllDataForClass<SalaryView>(errorMessage, salaryFilter);
					if (errorMessage.empty())
					{
						if (1 <= salaryVector.size())
						{
							if (salaryTypeMap.size() > 0 && statusMap.size() > 0)
							{
								for each (auto salaryItem in salaryVector)
								{
									try
									{
										if (salaryItem.GetSalaryTypeID() == salaryTypeMap.find("FIXED")->second)
										{
											payslip.Clear();
											payslip.SetDate(ormasDal.GetSystemDateTime());
											payslip.SetSalaryID(salaryItem.GetID());
											payslip.SetCurrencyID(salaryItem.GetCurrencyID());
											payslip.SetValue(salaryItem.GetValue());
											if (!payslip.CreatePayslip(ormasDal, errorMessage))
												return false;
										}
										if (salaryItem.GetSalaryTypeID() == salaryTypeMap.find("PERCENT")->second)
										{
											order.Clear();
											order.SetEmployeeID(salary.GetEmployeeID());
											order.SetStatusID(statusMap.find("EXECUTED")->second);
											orderFilter.clear();
											orderFilter = order.GenerateFilterForPeriod(ormasDal, fromDate, tillDate);
											orderVector.clear();
											orderVector = this->GetAllDataForClass<OrderView>(errorMessage, orderFilter);
											sum = 0;
											if (orderVector.size() > 0)
											{
												for each (auto orderItem in orderVector)
												{
													sum += orderItem.GetSum();
												}
											}
											if (sum > 0)
											{
												payslip.Clear();
												payslip.SetDate(ormasDal.GetSystemDateTime());
												payslip.SetSalaryID(salaryItem.GetID());
												payslip.SetCurrencyID(salaryItem.GetCurrencyID());
												payslip.SetValue(sum * salaryItem.GetValue() / 1000);
												if (!payslip.CreatePayslip(ormasDal, errorMessage))
													return false;
											}
										}
										if (salaryItem.GetSalaryTypeID() == salaryTypeMap.find("HOURLY")->second)
										{
											timesheet.Clear();
											timesheet.SetSalaryID(salary.GetID());
											timesheetFilter.clear();
											timesheetFilter = timesheet.GenerateFilterForPeriod(ormasDal, fromDate, tillDate);
											timesheetVector.clear();
											timesheetVector = this->GetAllDataForClass<TimesheetView>(errorMessage, timesheetFilter);
											count = 0;
											if (timesheetVector.size() > 0)
											{
												for each (auto timesheetItem in timesheetVector)
												{
													count += timesheetItem.GetWorkedTime();
												}
											}
											if (count > 0)
											{
												payslip.Clear();
												payslip.SetDate(ormasDal.GetSystemDateTime());
												payslip.SetSalaryID(salaryItem.GetID());
												payslip.SetCurrencyID(salaryItem.GetCurrencyID());
												payslip.SetValue(std::round(salaryItem.GetValue()* count * 100) / 100);
												if (!payslip.CreatePayslip(ormasDal, errorMessage))
													return false;
											}
										}
										if (salaryItem.GetSalaryTypeID() == salaryTypeMap.find("SHIFT")->second)
										{
											/*payslip.Clear();
											payslip.SetDate(ormasDal.GetSystemDateTime());
											payslip.SetSalaryID(salaryItem.GetID());
											payslip.SetCurrencyID(salaryItem.GetCurrencyID());
											payslip.SetValue(salaryItem.GetValue());
											if (!payslip.CreatePayslip(ormasDal, errorMessage))
												return false;*/
										}
										if (salaryItem.GetSalaryTypeID() == salaryTypeMap.find("PIECE")->second)
										{
											jobsheet.Clear();
											jobsheet.SetEmployeeID(salary.GetEmployeeID());
											jobsheetFilter.clear();
											jobsheetFilter = jobsheet.GenerateFilterForPeriod(ormasDal, fromDate, tillDate);
											jobsheetVector.clear();
											jobsheetVector = this->GetAllDataForClass<JobsheetView>(errorMessage, timesheetFilter);
											if (jobsheetVector.size() > 0)
											{
												for each (auto jobsheetItem in jobsheetVector)
												{
													if (workedPieceMap.find(jobsheetItem.GetProductID()) == workedPieceMap.end())
													{
														workedPieceMap.insert(std::make_pair(jobsheetItem.GetProductID(), jobsheetItem.GetCount()));
													}
													else
													{
														workedPieceMap.find(jobsheetItem.GetProductID())->second = workedPieceMap.find(jobsheetItem.GetProductID())->second + jobsheetItem.GetCount();
													}
												}
											}
											if (workedPieceMap.size() > 0)
											{
												sum = 0;
												for each (auto workedPieceItem in workedPieceMap)
												{
													jobprice.Clear();
													if (!jobprice.GetJobpriceByID(ormasDal, workedPieceItem.first, errorMessage))
														return false;
													sum += std::round(jobprice.GetValue() * workedPieceItem.second * 100) / 100;
												}
											}
											payslip.Clear();
											payslip.SetDate(ormasDal.GetSystemDateTime());
											payslip.SetSalaryID(salaryItem.GetID());
											payslip.SetCurrencyID(salaryItem.GetCurrencyID());
											payslip.SetValue(sum);
											if (!payslip.CreatePayslip(ormasDal, errorMessage))
												return false;
										}
									}
									catch (...)
									{
										return false;
									}
								}
							}
							else
							{
								return false;
							}
						}
					}
					else
					{
						return false;
					}
				}
			}
			return true;
		}
		return false;
	}

	bool OrmasBL::CorrectingEntries()
	{
		std::string errorMessage = "";
		std::vector<ProductionStockView> vecForPStock;
		std::vector<DataLayer::productionStockViewCollection> pStockCollection;
		pStockCollection = ormasDal.GetProductionStock(errorMessage);
		if (!pStockCollection.empty()){
			for (auto data : pStockCollection)
			{
				vecForPStock.push_back(ProductionStockView(data));
			}
		}
		double productSum = 0;
		for each (auto item in vecForPStock)
		{
			productSum += item.GetSum();
		}

		Account account10730;
		Account account55020;
		if (!account10730.GetAccountByNumber(ormasDal, "10730", errorMessage))
			return false;
		if (!account55020.GetAccountByNumber(ormasDal, "55020", errorMessage))
			return false;
		double correctingValue = 0;
		double correctingStockValue = 0;
		double temp = account10730.GetCurrentBalance();
		correctingValue = std::round((account10730.GetCurrentBalance() - productSum) * 10000)/10000;
		correctingStockValue = account55020.GetCurrentBalance();
		Entry entry;
		CompanyAccountRelation cAccRel;
		Company company;
		int companyID = company.GetCompanyID(ormasDal, errorMessage);
		int acc55010 = cAccRel.GetAccountIDByCompanyID(ormasDal, companyID, "55010", errorMessage);

		if (correctingValue > 0)
		{
			entry.Clear();
			entry.SetID(ormasDal.GenerateID());
			entry.SetDebitingAccountID(acc55010);
			entry.SetValue(correctingValue);
			entry.SetCreditingAccountID(account10730.GetID());
			entry.SetDate(ormasDal.GetSystemDateTime());
			entry.SetDescription(wstring_to_utf8(L"Коррекция счета 55010 при закрытии месяца"));
			if (!entry.CreateEntry(ormasDal, errorMessage))
				return false;
		}
		else if (correctingValue < 0)
		{
			entry.Clear();
			entry.SetID(ormasDal.GenerateID());
			entry.SetDebitingAccountID(account10730.GetID());
			entry.SetValue(correctingValue * (-1));
			entry.SetCreditingAccountID(acc55010);
			entry.SetDate(ormasDal.GetSystemDateTime());
			entry.SetDescription(wstring_to_utf8(L"Коррекция счета 55010 при закрытии месяца"));
			if (!entry.CreateEntry(ormasDal, errorMessage))
				return false;
		}
		if (correctingStockValue > 0)
		{
			entry.Clear();
			entry.SetID(ormasDal.GenerateID());
			entry.SetDebitingAccountID(acc55010);
			entry.SetValue(correctingStockValue);
			entry.SetCreditingAccountID(account55020.GetID());
			entry.SetDate(ormasDal.GetSystemDateTime());
			entry.SetDescription(wstring_to_utf8(L"Коррекция счета 55010 при закрытии месяца"));
			if (!entry.CreateEntry(ormasDal, errorMessage))
				return false;
		}
		else if (correctingStockValue < 0)
		{
			entry.Clear();
			entry.SetID(ormasDal.GenerateID());
			entry.SetDebitingAccountID(account55020.GetID());
			entry.SetValue(correctingStockValue * (-1));
			entry.SetCreditingAccountID(acc55010);
			entry.SetDate(ormasDal.GetSystemDateTime());
			entry.SetDescription(wstring_to_utf8(L"Коррекция счета 55010 при закрытии месяца"));
			if (!entry.CreateEntry(ormasDal, errorMessage))
				return false;
		}
		return true;
	}

	bool OrmasBL::CalculateTax(std::string fromDate, std::string tillDate)
	{
		//to do list
		return true;
	}

	bool OrmasBL::RecalculateNetCost(std::string fromDate, std::string tillDate)
	{
		//Get all produced products ID  as vector<int productionID>
		std::string errorMessage = "";
		std::vector<Production> vecForProd;
		std::vector<DataLayer::productionCollection> pCollection;
		Production production;
		std::string filter = production.GenerateFilterForPeriod(ormasDal, fromDate, tillDate);
		pCollection = ormasDal.GetProduction(errorMessage, filter);
		if (!pCollection.empty()){
			for (auto data : pCollection)
			{
				vecForProd.push_back(Production(data));
			}
		}
		std::vector<int> vecProductionID;
		for each (auto item in vecForProd)
		{
			vecProductionID.push_back(item.GetID());
		}

		if (vecProductionID.size() == 0)
			return false;

		//Get all produced products ID  as map<int productID, double count>
		ProductionList pList;
		std::string pListFilter = pList.GenerateFilterForEnum(ormasDal, vecProductionID);
		std::vector<ProductionListView> vecForProdList;
		std::vector<DataLayer::productionListViewCollection> pListCollection;
		pListCollection = ormasDal.GetProductionList(errorMessage, pListFilter);
		if (!pListCollection.empty()){
			for (auto data : pListCollection)
			{
				vecForProdList.push_back(ProductionListView(data));
			}
		}
		std::map<int, double> mapProducedProducts;
		for each (auto item in vecForProdList)
		{
			std::map<int, double>::iterator it = mapProducedProducts.find(item.GetProductID());
			if (it != mapProducedProducts.end())
			{
				it->second += item.GetCount();
			}
			else
			{
				mapProducedProducts.insert(std::make_pair(item.GetProductID(), item.GetCount()));
			}
		}

		//Get pure net cost from specification list as map<int productID, double netCost>
		std::vector<SpecificationView> vecForSpec;
		std::vector<DataLayer::specificationsViewCollection> pSpecCollection;
		pSpecCollection = ormasDal.GetSpecifications(errorMessage);
		if (!pSpecCollection.empty()){
			for (auto data : pSpecCollection)
			{
				vecForSpec.push_back(SpecificationView(data));
			}
		}
		std::map<double, int> mapNetCost;
		for each (auto item in vecForSpec)
		{
			mapNetCost.insert(std::make_pair(item.GetSum(), item.GetProductID()));
		}

		//Calculate product coificient
		std::map<int, double> coif;

		int i = 0;
		double divide = 0;
		divide = mapNetCost.begin()->first;
		for each (auto item in mapNetCost)
		{
			if (i == 0)
				coif.insert(std::make_pair(item.second, 1));
			coif.insert(std::make_pair(item.second, (item.first / divide)));
			i++;
		}


		//Calculate tolal count
		double totalCount = 0;
		for each (auto item in mapProducedProducts)
		{
			if (coif.find(item.first) != coif.end())
			{
				totalCount += item.second * coif.find(item.first)->second;
			}
			else
			{
				return false;
			}
		}

		Account account55010;
		if (!account55010.GetAccountByNumber(ormasDal, "55010", errorMessage))
			return false;

		double totalNetCost = 0;
		totalNetCost = account55010.GetCurrentBalance() / totalCount;

		NetCost nCost;
		for each (auto item in mapProducedProducts)
		{
			nCost.Clear();
			if (!nCost.GetNetCostByProductID(ormasDal, item.first, errorMessage))
				return false;
			if (coif.find(item.first) != coif.end())
				nCost.SetValue(std::round(totalNetCost * coif.find(item.first)->second * 100) / 100);
			if (!nCost.UpdateNetCost(ormasDal, errorMessage))
				return false;
		}

		return true;
	}

	bool OrmasBL::GenerateReports(std::string fromDate, std::string tillDate)
	{
		std::string errorMessage = "";
		FinancialReport fReport;
		Company company;
		Account account44010;
		Account account55010;
		Account account55200;
		Account account55300;
		Account account55270;
		Account account55321;
		Account account44020;
		Account account44090;
		double account66010 = 0;
		double account66020 = 0;
		double account66040 = 0;
		double account66050 = 0;
		double account66060 = 0;
		double account66070 = 0;
		double account66110 = 0;
		double account66120 = 0;
		double account66140 = 0;
		double account66150 = 0;
		double account66160 = 0;
		double account66170 = 0;
		double account66130 = 0;
		int companyID = company.GetCompanyID(ormasDal, errorMessage);
		account44010.Clear();
		if (!account44010.GetAccountByNumber(ormasDal, "44010", errorMessage))
			return false;
		account55010.Clear();
		if (!account55010.GetAccountByNumber(ormasDal, "55010", errorMessage))
			return false;
		account55200.Clear();
		if (!account55200.GetAccountByNumber(ormasDal, "55200", errorMessage))
			return false;
		account55300.Clear();
		if (!account55300.GetAccountByNumber(ormasDal, "55300", errorMessage))
			return false;
		account55270.Clear();
		if (!account55270.GetAccountByNumber(ormasDal, "55270", errorMessage))
			return false;
		account55321.Clear();
		if (!account55321.GetAccountByNumber(ormasDal, "55321", errorMessage))
			return false;
		account44020.Clear();
		if (!account44020.GetAccountByNumber(ormasDal, "44020", errorMessage))
			return false;
		account44020.Clear();
		if (!account44090.GetAccountByNumber(ormasDal, "44090", errorMessage))
			return false;

		std::vector<Account> vecForAccount;
		std::vector<DataLayer::accountsCollection> accCollection;
		accCollection = ormasDal.GetAccounts(errorMessage);
		if (!accCollection.empty()){
			for (auto data : accCollection)
			{
				vecForAccount.push_back(Account(data));
			}
		}
		for each (auto item in vecForAccount)
		{
			if (0 == item.GetNumber().substr(0, 1).compare("6"))
			{
				if (0 == item.GetNumber().compare("66010"))
					account66010 = item.GetCurrentBalance();
				if (0 == item.GetNumber().compare("66020"))
					account66020 = item.GetCurrentBalance();
				if (0 == item.GetNumber().compare("66040"))
					account66040 = item.GetCurrentBalance();
				if (0 == item.GetNumber().compare("66050"))
					account66050 = item.GetCurrentBalance();
				if (0 == item.GetNumber().compare("66060"))
					account66060 = item.GetCurrentBalance();
				if (0 == item.GetNumber().compare("66070"))
					account66070 = item.GetCurrentBalance();
				if (0 == item.GetNumber().compare("66110"))
					account66110 = item.GetCurrentBalance();
				if (0 == item.GetNumber().compare("66120"))
					account66120 = item.GetCurrentBalance();
				if (0 == item.GetNumber().compare("66140"))
					account66140 = item.GetCurrentBalance();
				if (0 == item.GetNumber().compare("66150"))
					account66150 = item.GetCurrentBalance();
				if (0 == item.GetNumber().compare("66160"))
					account66160 = item.GetCurrentBalance();
				if (0 == item.GetNumber().compare("66170"))
					account66170 = item.GetCurrentBalance();
				if (0 == item.GetNumber().compare("66130"))
					account66130 = item.GetCurrentBalance();
			}
		}

		fReport.SetAccount44010(std::round(account44010.GetCurrentBalance() * 100) / 100);
		fReport.SetAccount55010(std::round(account55010.GetCurrentBalance() * 100) / 100);
		fReport.SetAccount552(std::round(account55200.GetCurrentBalance() * 100) / 100);
		fReport.SetAccount55270(std::round(account55270.GetCurrentBalance() * 100) / 100);
		fReport.SetAccount553(std::round(account55300.GetCurrentBalance() * 100) / 100);
		fReport.SetAccount55321(std::round(account55321.GetCurrentBalance() * 100) / 100);
		fReport.SetAccount44020_90(std::round((account44020.GetCurrentBalance() + account44090.GetCurrentBalance()) * 100) / 100);
		fReport.SetAccount66010_66110(std::round((account66010 + account66110) * 100) / 100);
		fReport.SetAccount66020_66120(std::round((account66020 + account66120) * 100) / 100);
		fReport.SetAccount66040_66140(std::round((account66040 + account66140) * 100) / 100);
		fReport.SetAccount66050_66150(std::round((account66050 + account66150) * 100) / 100);
		fReport.SetAccount66060_66160(std::round((account66060 + account66160) * 100) / 100);
		fReport.SetAccount66130(std::round((account66130) * 100) / 100);
		fReport.SetAccount66070_66170(std::round((account66070 + account66170) * 100) / 100);
		fReport.SetFromDate(fromDate);
		fReport.SetTillDate(tillDate);
		if (!fReport.CreateFinancialReport(ormasDal, errorMessage))
			return false;
		return true;
	}

	bool OrmasBL::CalculateCloseOfMonth(std::string fromDate, std::string tillDate)
	{
		//save state of accounts
		std::string errorMessage = "";
		std::vector<Account> vecForAccount;
		std::vector<DataLayer::accountsCollection> accCollection;
		accCollection = ormasDal.GetAccounts(errorMessage);
		Entry entry;
		CompanyAccountRelation cAccRel;
		Company company;
		int companyID = company.GetCompanyID(ormasDal, errorMessage);
		int acc70000 = cAccRel.GetAccountIDByCompanyID(ormasDal, companyID, "70000", errorMessage);
		if (!accCollection.empty()){
			for (auto data : accCollection)
			{
				vecForAccount.push_back(Account(data));
			}
		}
		for each (auto item in vecForAccount)
		{
			if (0 == item.GetNumber().substr(0, 1).compare("4") || 0 == item.GetNumber().substr(0, 1).compare("5")
				|| 0 == item.GetNumber().substr(0, 1).compare("6"))
			{
				if (0 == acc70000)
					return false;
				if (0 == item.GetNumber().compare("44000") || 0 == item.GetNumber().compare("55000") || 0 == item.GetNumber().compare("55200")
					|| 0 == item.GetNumber().compare("55300") || 0 == item.GetNumber().compare("66000") || 0 == item.GetNumber().compare("66100"))
				{					
				}
				else
				{
					if (item.GetCurrentBalance() > 0)
					{
						entry.Clear();
						entry.SetID(ormasDal.GenerateID());
						entry.SetDebitingAccountID(acc70000);
						entry.SetValue(item.GetCurrentBalance());
						entry.SetCreditingAccountID(item.GetID());
						entry.SetDate(ormasDal.GetSystemDateTime());
						entry.SetDescription(wstring_to_utf8(L"Закрытие счетов на конец месяца"));
						if (!entry.CreateEntry(ormasDal, errorMessage))
							return false;
					}
					else if (item.GetCurrentBalance() < 0)
					{
						entry.Clear();
						entry.SetID(ormasDal.GenerateID());
						entry.SetDebitingAccountID(item.GetID());
						entry.SetValue(item.GetCurrentBalance() * (-1));
						entry.SetCreditingAccountID(acc70000);
						entry.SetDate(ormasDal.GetSystemDateTime());
						entry.SetDescription(wstring_to_utf8(L"Закрытие счетов на конец месяца"));
						if (!entry.CreateEntry(ormasDal, errorMessage))
							return false;
					}
				}
			}
			else
			{
				if (0 == item.GetNumber().substr(0, 1).compare("7"))
				{
				}
				else
				{
					item.SetStartBalance(item.GetCurrentBalance());
					if (!item.UpdateAccount(ormasDal, errorMessage))
						return false;
				}
			}
		}

		std::vector<SubaccountView> vecForSubaccountHis;
		std::vector<DataLayer::subaccountsViewCollection> subaccCollection;
		subaccCollection = ormasDal.GetSubaccounts(errorMessage);
		if (!subaccCollection.empty()){
			for (auto data : subaccCollection)
			{
				vecForSubaccountHis.push_back(SubaccountView(data));
			}
		}
		for each (auto item in vecForSubaccountHis)
		{
			item.SetStartBalance(item.GetCurrentBalance());
			if (!item.UpdateSubaccount(ormasDal, errorMessage))
				return false;
		}
		return true;
	}

	bool OrmasBL::CloseOfAccount70000()
	{
		std::string errorMessage = "";
		Account account70000;
		if (!account70000.GetAccountByNumber(ormasDal, "70000", errorMessage))
			return false;
		Account account33210;
		if (!account33210.GetAccountByNumber(ormasDal, "33210", errorMessage))
			return false;
		double correctingValue = 0;
		correctingValue = account70000.GetCurrentBalance()*(-1);

		Entry entry;
		CompanyAccountRelation cAccRel;
		Company company;
		int companyID = company.GetCompanyID(ormasDal, errorMessage);
		
		if (correctingValue > 0)
		{
			entry.Clear();
			entry.SetID(ormasDal.GenerateID());
			entry.SetDebitingAccountID(account70000.GetID());
			entry.SetValue(correctingValue);
			entry.SetCreditingAccountID(account33210.GetID());
			entry.SetDate(ormasDal.GetSystemDateTime());
			entry.SetDescription(wstring_to_utf8(L"Операция закрытие счета 70000"));
			if (!entry.CreateEntry(ormasDal, errorMessage))
				return false;
		}
		else if (correctingValue < 0)
		{
			entry.Clear();
			entry.SetID(ormasDal.GenerateID());
			entry.SetDebitingAccountID(account33210.GetID());
			entry.SetValue(correctingValue * (-1));
			entry.SetCreditingAccountID(account70000.GetID());
			entry.SetDate(ormasDal.GetSystemDateTime());
			entry.SetDescription(wstring_to_utf8(L"Операция закрытие счета 70000"));
			if (!entry.CreateEntry(ormasDal, errorMessage))
				return false;
		}
		
		account33210.SetStartBalance(account33210.GetCurrentBalance());
		if (!account33210.UpdateAccount(ormasDal, errorMessage))
			return false;
		return true;
	}

	std::string OrmasBL::wstring_to_utf8(const std::wstring& str)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
		return myconv.to_bytes(str);
	}
}