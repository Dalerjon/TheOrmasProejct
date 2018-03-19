#ifndef TUPLECOLLECTION_H
#define TUPLECOLLECTION_H

namespace DataLayer{
	typedef std::tuple<int, std::string, std::string, std::string> accessItemsCollection;

	typedef std::tuple<int, int, int> accessesCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, int, int> accessesViewCollection;
	
	typedef std::tuple<int, int> accountEntryCollection;

	typedef std::tuple<int, std::string, int, std::string> accountTypeCollection;

	typedef std::tuple<int, std::string, double, double, int, int, std::string, std::string, std::string> accountsCollection;

	typedef std::tuple<int, std::string, double, double, std::string, std::string, int, int, std::string, std::string, 
		std::string> accountsViewCollection;
	
	typedef std::tuple<int, int> balancePaymentCollection;

	typedef std::tuple<int, int> balancePayslipCollection;
	
	typedef std::tuple<int, int> balanceRefundCollection;
	
	typedef std::tuple<int, int> balanceWithdrawalCollection;

	typedef std::tuple<int, int, int> balancesCollection;

	typedef std::tuple<int,std::string, std::string, double, std::string, int, int> balancesViewCollection;

	typedef std::tuple<int, int, std::string, int> chartOfAccountsCollection;

	typedef std::tuple<int, int, std::string, std::string, int> chartOfAccountsViewCollection;

	typedef std::tuple<int, std::string, std::string, int> clientsCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, 
		std::string, std::string, std::string, std::string, bool, int, int> clientsViewCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string> companiesCollection;
	
	typedef std::tuple<int, int> companyAccountCollection;

	typedef std::tuple<int, int, int, int, double, int, int> consumeProductListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> consumeProductListViewCollection;

	typedef std::tuple<int, int, std::string, std::string, int, int, double, int, int> consumeProductsCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, 
		std::string, std::string, std::string, std::string, int, double, std::string, int, int, int, int> consumeProductsViewCollection;

	typedef std::tuple<int, int, int, int, double, int, int> consumeRawListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> consumeRawListViewCollection;

	typedef std::tuple<int, int, std::string, std::string, int, int, double, int, int> consumeRawsCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, std::string, int, double, std::string, int, int, int, int> consumeRawsViewCollection;
	
	typedef std::tuple<int, int, std::string, std::string, int, bool> currenciesCollection;

	typedef std::tuple<int, int, std::string, std::string> employeesCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, 
		std::string, std::string, std::string, bool, int, int> employeesViewCollection;

	typedef std::tuple<int, std::string, int, double, int> entriesCollection;

	typedef std::tuple<int, std::string, std::string, double, std::string, int, int> entriesViewCollection;

	typedef std::tuple<int, int, int, int, double, int, int> inventorizationListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> inventorizationListViewCollection;

	typedef std::tuple<int, int, std::string, std::string, int, int, double, int, int> inventorizationsCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, std::string, int, double, std::string, int, int, int, int> inventorizationsViewCollection;

	typedef std::tuple<int, int, double, int, double, int, int> jobpriceCollection;

	typedef std::tuple<int, std::string, double, std::string, double, std::string, std::string, int, int, int, int> jobpriceViewCollection;

	typedef std::tuple<int, std::string, double, int, int> jobsheetCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, double, std::string, int, int> jobsheetViewCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string> locationsCollection;
	
	typedef std::tuple<int, std::string, std::string, int> measuresCollection;

	typedef std::tuple<int, std::string, double, int, int, bool> netCostCollection;

	typedef std::tuple<int, std::string, std::string, double, std::string, double, std::string, int, int, bool> netCostViewCollection;

	typedef std::tuple<int, int, int, int, double, int, int> orderListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> orderListViewCollection;

	typedef std::tuple<int, int> payslipOrderCollection;
	
	typedef std::tuple<int, int, std::string, std::string, int, int, double, int, int> ordersCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, int, double, std::string, int, int, int, int> ordersViewCollection;

	typedef std::tuple<int, int, int, int, double, int, int> orderRawListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> orderRawListViewCollection;

	typedef std::tuple<int, int, std::string, std::string, int, int, double, int, int> orderRawsCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, std::string, int, double, std::string, int, int, int, int> orderRawsViewCollection;

	typedef std::tuple<int, std::string, double, int, int> paymentsCollection;

	typedef std::tuple<int, std::string, double, std::string, int, int> paymentsViewCollection;

	typedef std::tuple<int, std::string, double, int, int> payslipsCollection;

	typedef std::tuple<int, std::string, double, std::string, int, int> payslipsViewCollection;

	typedef std::tuple<int, double, std::string, int> percentRateCollection;

	typedef std::tuple<int, int, int, std::string> photosCollection;

	typedef std::tuple<int, std::string> positionsCollection;

	typedef std::tuple<int, std::string, double, int, int, bool> pricesCollection;

	typedef std::tuple<int, std::string, std::string, double, std::string, double, std::string, int, int, bool> pricesViewCollection;
	
	typedef std::tuple<int, std::string, std::string> productTypeCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string> productionCollection;

	typedef std::tuple<int, int, int, int, double, int, int> productionListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> productionListViewCollection;

	typedef std::tuple<int, int, int, int, double, int, int> productionPlanListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int>  productionPlanListViewCollection;

	typedef std::tuple<int, std::string, int, int, double, int, int> productionPlanCollection;

	typedef std::tuple<int, std::string, int, double, std::string, std::string, std::string, std::string, std::string, std::string,
		 int, int, int> productionPlanViewCollection;
	
	typedef std::tuple<int, int, std::string, double, int, double, int, int, int> productsCollection;

	typedef std::tuple<int, std::string, double, std::string, double, std::string, std::string, int, std::string, int, int,
		int, int> productsViewCollection;

	typedef std::tuple<int, std::string, int> purveyorsCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, bool, int, int> purveyorsViewCollection;

	typedef std::tuple<int, int, int, int, double, int, int> receiptProductListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> receiptProductListViewCollection;

	typedef std::tuple<int, int, std::string, std::string, int, int, double, int, int> receiptProductsCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, std::string, int, double, std::string, int, int, int, int> receiptProductsViewCollection;

	typedef std::tuple<int, int, int, int, double, int, int> receiptRawListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> receiptRawListViewCollection;

	typedef std::tuple<int, int, std::string, std::string, int, int, double, int, int> receiptRawsCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, std::string, int, double, std::string, int, int, int, int> receiptRawsViewCollection;

	typedef std::tuple<int, std::string, double, int, int> refundsCollection;
	
	typedef std::tuple<int, std::string, double, std::string, int, int> refundsViewCollection;

	typedef std::tuple<int, std::string, std::string> relationTypeCollection;

	typedef std::tuple<int, int, int, int> relationsCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		int, int, int> relationsViewCollection;

	typedef std::tuple<int, int, int, int, double, int, int> returnListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> returnListViewCollection;
	
	typedef std::tuple<int, int, std::string, std::string, int, int, double, int, int> returnsCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, int, double, std::string, int, int, int, int> returnsViewCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string> rolesCollection;

	typedef std::tuple<int, int, double, int, int, std::string, bool> salariesCollection;

	typedef std::tuple<int, int, std::string, std::string, std::string, std::string, double, std::string, 
		std::string, int, int, bool> salariesViewCollection;

	typedef std::tuple<int, std::string, std::string> salaryTypeCollection;

	typedef std::tuple<int, int, int, double> specificationListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, int> specificationListViewCollection;

	typedef std::tuple<int, int, double, int, int, std::string> specificationsCollection;

	typedef std::tuple<int, std::string, std::string, double, std::string, std::string, std::string, std::string, std::string, 
		int, int, int> specificationsViewCollection;

	typedef std::tuple<int, int, int, int, double, int, int> spoilageListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int>  spoilageListViewCollection;

	typedef std::tuple<int, std::string, int, int, double, int, int> spoilageCollection;

	typedef std::tuple<int, std::string, int, double, std::string, std::string, std::string, std::string, std::string, std::string,
		int, int, int> spoilageViewCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string> statusCollection;

	typedef std::tuple<int, int, int, double, int, int> stockCollection;

	typedef std::tuple<int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> stockViewCollection;

	typedef std::tuple<int, int, double, std::string> timesheetCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, double, int> timesheetViewCollection;

	typedef std::tuple<int, int, int, int, double, int, int> transportListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> transportListViewCollection;

	typedef std::tuple<int, int, std::string, std::string, int, int, double, int, int> transportsCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, std::string, int, double, std::string, int, int, int, int> transportsViewCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, int, 
		std::string, bool> usersCollection;
	
	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, bool, int> usersViewCollection;

	typedef std::tuple<int, std::string, double, int, int> withdrawalsCollection;

	typedef std::tuple<int, std::string, double, std::string, int, int> withdrawalsViewCollection;

	typedef std::tuple<int, int, int, int, double, int, int> writeOffListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> writeOffListViewCollection;
	
	typedef std::tuple<int, int, std::string, int, int, double, int, int> writeOffsCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, int, double, std::string, int, int, int, int> writeOffsViewCollection;
	
	typedef std::tuple<int, int, int, int, double, int, int> writeOffRawListCollection;

	typedef std::tuple<int, int, std::string, double, std::string, double, std::string, int, double, std::string,
		std::string, int, int, int> writeOffRawListViewCollection;

	typedef std::tuple<int, int, std::string, int, int, double, int, int> writeOffRawsCollection;

	typedef std::tuple<int, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
		std::string, std::string, std::string, std::string, int, double, std::string, int, int, int, int> writeOffRawsViewCollection;

}

#endif //TUPLECOLLECTION_H