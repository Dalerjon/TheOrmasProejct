#ifndef ORMASDAL_H
#define ORMASDAL_H
#include <string>
//#include <pqxx/pqxx>
#include <libpq-fe.h>
#include "ConnString.h"
#include "TupleCollection.h"

//using namespace pqxx;
namespace DataLayer{
	class OrmasDal{
	public:
		//class constructors
		OrmasDal(ConnectionString conn, PGconn *dbCon);
		OrmasDal(const OrmasDal &oDAL){ dbCon = oDAL.dbCon; connString = oDAL.connString; }
		OrmasDal();
		~OrmasDal();
		
		//connection methods
		PGconn* GetConnection();
		bool ConnectToDB(std::string dbname, std::string username, std::string password, std::string host, int port);
		void InitFromConfigFile(std::string path);
		void SetDBParams(std::string dbname, std::string username, std::string password, std::string host, int port);
		int GenerateID();
		int GenerateAccountID();
		std::string GetSystemDate();
		std::string GetSystemDateTime();

		//work with transaction
		bool StartTransaction(std::string& errorMessage);
		bool CommitTransaction(std::string& errorMessage);
		bool CancelTransaction(std::string& errorMessage);

		//view methods
		std::vector<accessItemsCollection> GetAccessItems(std::string& errorMessage, std::string filter = std::string());
		std::vector<accessesViewCollection> GetAccesses(std::string& errorMessage, std::string filter = std::string());
		std::vector<accountEntryCollection> GetAccountEntry(std::string& errorMessage, std::string filter = std::string());
		std::vector<accountTypeCollection> GetAccountType(std::string& errorMessage, std::string filter = std::string());
		std::vector<accountsViewCollection> GetAccounts(std::string& errorMessage, std::string filter = std::string());
		std::vector<balancePaymentCollection> GetBalancePayment(std::string& errorMessage, std::string filter = std::string());
		std::vector<balancePayslipCollection> GetBalancePayslip(std::string& errorMessage, std::string filter = std::string());
		std::vector<balanceRefundCollection> GetBalanceRefund(std::string& errorMessage, std::string filter = std::string());
		std::vector<balanceWithdrawalCollection> GetBalanceWithdrawal(std::string& errorMessage, std::string filter = std::string());
		std::vector<balancesViewCollection> GetBalances(std::string& errorMessage, std::string filter = std::string());
		std::vector<chartOfAccountsViewCollection> GetChartOfAccounts(std::string& errorMessage, std::string filter = std::string());
		std::vector<clientsViewCollection> GetClients(std::string& errorMessage, std::string filter = std::string());
		std::vector<companiesCollection> GetCompanies(std::string& errorMessage, std::string filter = std::string());
		std::vector<companyAccountCollection> GetCompanyAccount(std::string& errorMessage, std::string filter = std::string());
		std::vector<consumeProductListViewCollection> GetConsumeProductList(std::string& errorMessage, std::string filter = std::string());
		std::vector<consumeProductsViewCollection> GetConsumeProducts(std::string& errorMessage, std::string filter = std::string());
		std::vector<consumeRawListViewCollection> GetConsumeRawList(std::string& errorMessage, std::string filter = std::string());
		std::vector<consumeRawsViewCollection> GetConsumeRaws(std::string& errorMessage, std::string filter = std::string());
		std::vector<currenciesCollection> GetCurrencies(std::string& errorMessage, std::string filter = std::string());
		std::vector<employeesViewCollection> GetEmployees(std::string& errorMessage, std::string filter = std::string());
		std::vector<entriesViewCollection> GetEntries(std::string& errorMessage, std::string filter = std::string());
		std::vector<inventorizationListViewCollection> GetInventorizationList(std::string& errorMessage, std::string filter = std::string());
		std::vector<inventorizationsViewCollection> GetInventorizations(std::string& errorMessage, std::string filter = std::string());
		std::vector<jobpriceViewCollection> GetJobprice(std::string& errorMessage, std::string filter = std::string());
		std::vector<jobsheetViewCollection> GetJobsheet(std::string& errorMessage, std::string filter = std::string());
		std::vector<locationsCollection> GetLocations(std::string& errorMessage, std::string filter = std::string());
		std::vector<measuresCollection> GetMeasures(std::string& errorMessage, std::string filter = std::string());
		std::vector<netCostViewCollection> GetNetCost(std::string& errorMessage, std::string filter = std::string());
		std::vector<orderListViewCollection> GetOrderList(std::string& errorMessage, std::string filter = std::string());
		std::vector<ordersViewCollection> GetOrders(std::string& errorMessage, std::string filter = std::string());
		std::vector<orderRawListViewCollection> GetOrderRawList(std::string& errorMessage, std::string filter = std::string());
		std::vector<orderRawsViewCollection> GetOrderRaws(std::string& errorMessage, std::string filter = std::string());
		std::vector<paymentsViewCollection> GetPayments(std::string& errorMessage, std::string filter = std::string());
		std::vector<payslipsViewCollection> GetPayslips(std::string& errorMessage, std::string filter = std::string());
		std::vector<payslipOrderCollection> GetPayslipOrder(std::string& errorMessage, std::string filter = std::string());
		std::vector<percentRateCollection> GetPercentRate(std::string& errorMessage, std::string filter = std::string());
		std::vector<photosCollection> GetPhotos(std::string& errorMessage, std::string filter = std::string());
		std::vector<positionsCollection> GetPositions(std::string& errorMessage, std::string filter = std::string());
		std::vector<pricesViewCollection> GetPrices(std::string& errorMessage, std::string filter = std::string());
		std::vector<productTypeCollection> GetProductTypes(std::string& errorMessage, std::string filter = std::string());
		std::vector<productionCollection> GetProduction(std::string& errorMessage, std::string filter = std::string());
		std::vector<productionListViewCollection> GetProductionList(std::string& errorMessage, std::string filter = std::string());
		std::vector<productionPlanViewCollection> GetProductionPlan(std::string& errorMessage, std::string filter = std::string());
		std::vector<productionPlanListViewCollection> GetProductionPlanList(std::string& errorMessage, std::string filter = std::string());
		std::vector<productsViewCollection> GetProducts(std::string& errorMessage, std::string filter = std::string());
		std::vector<purveyorsViewCollection> GetPurveyors(std::string& errorMessage, std::string filter = std::string());
		std::vector<receiptProductListViewCollection> GetReceiptProductList(std::string& errorMessage, std::string filter = std::string());
		std::vector<receiptProductsViewCollection> GetReceiptProducts(std::string& errorMessage, std::string filter = std::string());
		std::vector<receiptRawListViewCollection> GetReceiptRawList(std::string& errorMessage, std::string filter = std::string());
		std::vector<receiptRawsViewCollection> GetReceiptRaws(std::string& errorMessage, std::string filter = std::string());
		std::vector<refundsViewCollection> GetRefunds(std::string& errorMessage, std::string filter = std::string());
		std::vector<relationTypeCollection> GetRelationType(std::string& errorMessage, std::string filter = std::string());
		std::vector<relationsViewCollection> GetRelations(std::string& errorMessage, std::string filter = std::string());
		std::vector<returnListViewCollection> GetReturnList(std::string& errorMessage, std::string filter = std::string());
		std::vector<returnsViewCollection> GetReturns(std::string& errorMessage, std::string filter = std::string());
		std::vector<rolesCollection> GetRoles(std::string& errorMessage, std::string filter = std::string());
		std::vector<salariesViewCollection> GetSalaries(std::string& errorMessage, std::string filter = std::string());
		std::vector<salaryTypeCollection> GetSalaryType(std::string& errorMessage, std::string filter = std::string());
		std::vector<specificationListViewCollection> GetSpecificationList(std::string& errorMessage, std::string filter = std::string());
		std::vector<specificationsViewCollection> GetSpecifications(std::string& errorMessage, std::string filter = std::string());
		std::vector<spoilageListViewCollection> GetSpoilageList(std::string& errorMessage, std::string filter = std::string());
		std::vector<spoilageViewCollection> GetSpoilage(std::string& errorMessage, std::string filter = std::string());
		std::vector<statusCollection> GetStatus(std::string& errorMessage, std::string filter = std::string());
		std::vector<stockViewCollection> GetStock(std::string& errorMessage, std::string filter = std::string());
		std::vector<timesheetViewCollection> GetTimesheet(std::string& errorMessage, std::string filter = std::string());
		std::vector<transportListViewCollection> GetTransportList(std::string& errorMessage, std::string filter = std::string());
		std::vector<transportsViewCollection> GetTransports(std::string& errorMessage, std::string filter = std::string());
		std::vector<usersViewCollection> GetUsers(std::string& errorMessage, std::string filter = std::string());
		std::vector<withdrawalsViewCollection> GetWithdrawals(std::string& errorMessage, std::string filter = std::string());
		std::vector<writeOffsViewCollection> GetWriteOffs(std::string& errorMessage, std::string filter = std::string());
		std::vector<writeOffListViewCollection> GetWriteOffList(std::string& errorMessage, std::string filter = std::string());
		std::vector<writeOffRawsViewCollection> GetWriteOffRaws(std::string& errorMessage, std::string filter = std::string());
		std::vector<writeOffRawListViewCollection> GetWriteOffRawList(std::string& errorMessage, std::string filter = std::string());

		//create methods
		bool CreateAccessItem(int aID, std::string aItenEng, std::string aItemRu,std::string aDivision, std::string& errorMessage);
		bool CreateAccess(int aID, int rID, int aiID, std::string& errorMessage);
		bool CreateAccountEntry(int aID, int eID, std::string& errorMessage);
		bool CreateAccountType(int atID, std::string atName, int atNumber, std::string atComment, std::string& errorMessage);
		bool CreateAccount(int aID, std::string aNumber, double aStartBalance, double aCurrentBalance, int cID, int sID,
			std::string aOpenDate, std::string aCloseDate, std::string aDetails, std::string& errorMessage);
		bool CreateBalancePayment(int bID, int pID, std::string& errorMessage);
		bool CreateBalancePayslip(int bID, int pID, std::string& errorMessage);
		bool CreateBalanceRefund(int bID, int rID, std::string& errorMessage);
		bool CreateBalanceWithdrawal(int bID, int wID, std::string& errorMessage);
		bool CreateBalance(int bID, int uID, int aID, std::string& errorMessage);
		bool CreateChartOfAccount(int coaID, int caoNumber, std::string caoNameOfAccount, int atID, std::string& errorMessage);
		bool CreateClient(int uID, std::string cFirm, std::string cFirmNumber, int lID, std::string& errorMessage);
		bool CreateCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment,
			std::string& errorMessage);
		bool CreateCompanyAccount(int cID, int aID,	std::string& errorMessage);
		bool CreateConsumeProductList(int clID, int cpID, int pID, int clCount, double clSum, int sID, int cID, std::string& errorMessage);
		bool CreateConsumeProduct(int cID, int eID, std::string cDate, std::string cExecDate, int seID, int cCount, double cSum, int sID, int curID, std::string& errorMessage);
		bool CreateConsumeRawList(int clID, int cpID, int pID, int clCount, double clSum, int sID, int cID, std::string& errorMessage);
		bool CreateConsumeRaw(int cID, int uID, std::string cDate, std::string cExecDate, int seID, int cCount, double cSum, int sID, int curID, std::string& errorMessage);
		bool CreateCurrency(int cID, int cCode, std::string cShortName, std::string cName, int cUnit, bool cMainTrade, std::string& errorMessage);
		bool CreateEmployee(int uID, int pID, std::string eBirthDate, std::string eHireDate, std::string& errorMessage);
		bool CreateEntry(int eID, std::string eDate, int daID, double eValue, int caID, std::string& errorMessage);
		bool CreateInventorizationList(int ilID, int iID, int pID, int ilCount, double ilSum, int sID, int cID, std::string& errorMessage);
		bool CreateInventorization(int iID, int uID, std::string iDate, std::string iExecDate, int seID, int iCount, double iSum, int sID, int cID, std::string& errorMessage);
		bool CreateJobprice(int jID, int pID, double jValue, int cID, double jVolume, int mID, int psID, std::string& errorMessage);
		bool CreateJobsheet(int jID, std::string jDate, double jCount, int pID, int eID, std::string& errorMessage);
		bool CreateLocation(int lID, std::string lCountryName, std::string lCountryCode, std::string lRegionName
			, std::string lCityName, std::string& errorMessage);
		bool CreateMeasure(int mID, std::string mName, std::string mShortName, int mUnit, std::string& errorMessage);
		bool CreateNetCost(int ncID, std::string ncDate, double ncValue, int cID, int pID, bool ncIsOutdated, std::string& errorMessage);
		bool CreateOrderList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID, std::string& errorMessage);
		bool CreateOrder(int oID, int uID, std::string oDate, std::string oExecDate, int eID, int oCount, double oSum, int sID, int cID, std::string& errorMessage);
		bool CreateOrderRawList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID, std::string& errorMessage);
		bool CreateOrderRaw(int oID, int uID, std::string oDate, std::string oExecDate, int seID, int oCount, double oSum, int sID, int cID, std::string& errorMessage);
		bool CreatePayment(int pID, std::string pDate, double pValue, int uID, int cID, std::string& errorMessage);
		bool CreatePayslip(int pID, std::string pDate, double pValue, int sID, int cID, std::string& errorMessage);
		bool CreatePayslipOrder(int pID, int oID, std::string& errorMessage);
		bool CreatePercentRate(int prID, double prValue, std::string prCondition, int psID, std::string& errorMessage);
		bool CreatePhoto(int pID, int uID, int prodId, std::string pSource, std::string& errorMessage);
		bool CreatePosition(int pID, std::string pName, std::string& errorMessage);
		bool CreatePrice(int pID, std::string pDate, double pValue, int cID, int prodID, bool pIsOutdated, std::string& errorMessage);
		bool CreateProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName, std::string& errorMessage);
		bool CreateProduction(int pID, std::string pProductionDate, std::string pExpiryDate, std::string pSessionStart, 
			std::string pSessionEnd, std::string& errorMessage);
		bool CreateProductionList(int plID, int pID, int prodID, int plCount, double plSum, int sID, int cID, std::string& errorMessage);
		bool CreateProductionPlanList(int pplID, int ppID, int pID, int pplCount, double pplSum, int sID, int cID, std::string& errorMessage);
		bool CreateProductionPlan(int pID, std::string pDate, int eID, int pCount, double pSum, int sID, int cID, std::string& errorMessage);
		bool CreateProduct(int pID, int cID, std::string pName, double vol, int mID, double price, int pTypeID, int pShelfLife, 
			int pCur, std::string& errorMessage);
		bool CreatePurveyor(int uID, std::string pCompanyName, int lID, std::string& errorMessage);
		bool CreateReceiptProductList(int rlID, int rpID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage);
		bool CreateReceiptProduct(int rID, int eID, std::string rDate, std::string rExecDate, int seID, int rCount, double rSum, int sID, int cID, std::string& errorMessage);
		bool CreateReceiptRawList(int rlID, int rpID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage);
		bool CreateReceiptRaw(int rID, int uID, std::string rDate, std::string rExecDate, int seID, int rCount, double rSum, int sID, int cID, std::string& errorMessage);
		bool CreateRefund(int rID, std::string rDate, double rValue, int uID, int cID, std::string& errorMessage);
		bool CreateRelationType(int rID, std::string rName, std::string rComment, std::string& errorMessage);
		bool CreateRelation(int rID, int uID1, int uID2, int rtID, std::string& errorMessage);
		bool CreateReturnList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage);
		bool CreateReturn(int rID, int uID, std::string rDate, std::string rExecDate, int eID, int rCount, double rSum, int sID, int cID, std::string& errorMessage);
		bool CreateSalary(int sID, int uID, double sValue, int cID, int stID, std::string sDate, bool sBonus, std::string& errorMessage);
		bool CreateSalaryType(int sID, std::string sCode, std::string sName, std::string& errorMessage);
		bool CreateRole(int rID,std::string rCode, std::string rName, std::string rComment, std::string& errorMessage);
		bool CreateSpecificationList(int slID, int sID, int pID, double tlCount, std::string& errorMessage);
		bool CreateSpecification(int sID, int pID, double sSum, int cID, int eID, std::string sDate, std::string& errorMessage);
		bool CreateSpoilageList(int slID, int sID, int pID, int slCount, double slSum, int stsID, int cID, std::string& errorMessage);
		bool CreateSpoilage(int sID, std::string sDate, int eID, int sCount, double sSum, int stsID, int cID, std::string& errorMessage);
		bool CreateStatus(int sID, std::string sCode, std::string sName, std::string sComment, std::string& errorMessage);
		bool CreateStock(int sID, int pID, int sCount, double sSum, int stsID, int cID, std::string& errorMessage);
		bool CreateTimesheet(int tID, int sID, double tWorkedTime, std::string tDate, std::string& errorMessage);
		bool CreateTransportList(int tlID, int tID, int pID, int tlCount, double tlSum, int sID, int cID, std::string& errorMessage);
		bool CreateTransport(int tID, int uID, std::string tDate, std::string tExecDate, int seID, int tCount, double tSum, int sID, int cID, std::string& errorMessage);
		bool CreateUser(int uID, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone, std::string uAddress,
			int uRoleID, std::string uPassword, bool uActivated, std::string& errorMessage);
		bool CreateWithdrawal(int wID, std::string wDate, double wValue, int uID, int cID, std::string& errorMessage);
		bool CreateWriteOffList(int wlID, int wID, int pID, int wlCount, double wlSum, int sID, int cID, std::string& errorMessage);
		bool CreateWriteOff(int wID, int uID, std::string wDate, int eID, int wCount, double wSum, int sID, int cID, std::string& errorMessage);
		bool CreateWriteOffRawList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage);
		bool CreateWriteOffRaw(int tID, int uID, std::string rDate, int seID, int rCount, double rSum, int sID, int cID, std::string& errorMessage);

		//delete methods
		bool DeleteAccessItem(int id, std::string& errorMessage);
		bool DeleteAccess(int id, std::string& errorMessage);
		bool DeleteAccountEntry(int aID, int eID, std::string& errorMessage);
		bool DeleteAccountType(int id, std::string& errorMessage);
		bool DeleteAccount(int id, std::string& errorMessage);
		bool DeleteBalancePayment(int bID, int pID, std::string& errorMessage);
		bool DeleteBalancePayslip(int bID, int pID, std::string& errorMessage);
		bool DeleteBalanceRefund(int bID, int rID, std::string& errorMessage);
		bool DeleteBalanceWithdrawal(int bID, int wID, std::string& errorMessage);
		bool DeleteBalance(int id, std::string& errorMessage);
		bool DeleteChartOfAccount(int id, std::string& errorMessage);
		bool DeleteClient(int id, std::string& errorMessage);
		bool DeleteCompany(int id, std::string& errorMessage);
		bool DeleteCompanyAccount(int cID, int aID, std::string& errorMessage);
		bool DeleteCurrency(int id, std::string& errorMessage);
		bool DeleteConsumeProduct(int id, std::string& errorMessage);
		bool DeleteItemInConsumeProductList(int id, std::string& errorMessage);
		bool DeleteListByConsumeProductID(int id, std::string& errorMessage);
		bool DeleteConsumeRaw(int id, std::string& errorMessage);
		bool DeleteItemInConsumeRawList(int id, std::string& errorMessage);
		bool DeleteListByConsumeRawID(int id, std::string& errorMessage);
		bool DeleteEmployee(int id, std::string& errorMessage);
		bool DeleteEntry(int id, std::string& errorMessage);
		bool DeleteItemInInventorizationList(int id, std::string& errorMessage);
		bool DeleteListByInventorizationID(int id, std::string& errorMessage);
		bool DeleteInventorization(int id, std::string& errorMessage);
		bool DeleteJobprice(int id, std::string& errorMessage);
		bool DeleteJobsheet(int id, std::string& errorMessage);
		bool DeleteLocation(int id, std::string& errorMessage);
		bool DeleteMeasure(int id, std::string& errorMessage);
		bool DeleteNetCost(int id, std::string& errorMessage);
		bool DeleteItemInOrderList(int id, std::string& errorMessage);
		bool DeleteListByOrderID(int id, std::string& errorMessage);
		bool DeleteOrder(int id, std::string& errorMessage);
		bool DeleteItemInOrderRawList(int id, std::string& errorMessage);
		bool DeleteListByOrderRawID(int id, std::string& errorMessage);
		bool DeleteOrderRaw(int id, std::string& errorMessage);
		bool DeletePayment(int id, std::string& errorMessage);
		bool DeletePayslip(int id, std::string& errorMessage);
		bool DeletePayslipOrder(int pID, int oID, std::string& errorMessage);
		bool DeletePercentRate(int id, std::string& errorMessage);
		bool DeletePhoto(int id, std::string& errorMessage);
		bool DeletePosition(int id, std::string& errorMessage);
		bool DeletePrice(int id, std::string& errorMessage);
		bool DeleteProductType(int id, std::string& errorMessage);
		bool DeleteProduction(int id, std::string& errorMessage);
		bool DeleteItemInProductionList(int id, std::string& errorMessage);
		bool DeleteListByProductionID(int id, std::string& errorMessage);
		bool DeleteProductionPlan(int id, std::string& errorMessage);
		bool DeleteItemInProductionPlanList(int id, std::string& errorMessage);
		bool DeleteListByProductionPlanID(int id, std::string& errorMessage);
		bool DeleteProduct(int id, std::string& errorMessage);
		bool DeletePurveyor(int id, std::string& errorMessage);
		bool DeleteReceiptProduct(int id, std::string& errorMessage);
		bool DeleteItemInReceiptProductList(int id, std::string& errorMessage);
		bool DeleteListByReceiptProductID(int id, std::string& errorMessage);
		bool DeleteReceiptRaw(int id, std::string& errorMessage);
		bool DeleteListByReceiptRawID(int id, std::string& errorMessage);
		bool DeleteItemInReceiptRawList(int id, std::string& errorMessage);
		bool DeleteRefund(int id, std::string& errorMessage);
		bool DeleteRelationType(int id, std::string& errorMessage);
		bool DeleteRelation(int id, std::string& errorMessage);
		bool DeleteItemInReturnList(int id, std::string& errorMessage);
		bool DeleteListByReturnID(int id, std::string& errorMessage);
		bool DeleteReturn(int id, std::string& errorMessage);
		bool DeleteRole(int id, std::string& errorMessage);
		bool DeleteSalary(int id, std::string& errorMessage);
		bool DeleteSalaryType(int id, std::string& errorMessage);
		bool DeleteSpecification(int id, std::string& errorMessage);
		bool DeleteItemInSpecificationList(int id, std::string& errorMessage);
		bool DeleteListBySpecificationID(int id, std::string& errorMessage);
		bool DeleteSpoilage(int id, std::string& errorMessage);
		bool DeleteItemInSpoilageList(int id, std::string& errorMessage);
		bool DeleteListBySpoilageID(int id, std::string& errorMessage);
		bool DeleteStatus(int id, std::string& errorMessage);
		bool DeleteStock(int id, std::string& errorMessage);
		bool DeleteTimesheet(int id, std::string& errorMessage);
		bool DeleteTransport(int id, std::string& errorMessage);
		bool DeleteListByTransportID(int id, std::string& errorMessage);
		bool DeleteItemInTransportList(int id, std::string& errorMessage);
		bool DeleteUser(int id, std::string& errorMessage);
		bool DeleteWithdrawal(int id, std::string& errorMessage);
		bool DeleteWriteOff(int id, std::string& errorMessage);
		bool DeleteListByWriteOffID(int id, std::string& errorMessage);
		bool DeleteItemInWriteOffList(int id, std::string& errorMessage);
		bool DeleteWriteOffRaw(int id, std::string& errorMessage);
		bool DeleteListByWriteOffRawID(int id, std::string& errorMessage);
		bool DeleteItemInWriteOffRawList(int id, std::string& errorMessage);

		//update methods
		bool UpdateAccessItem(int aID, std::string aItemEng, std::string aItemRu, std::string aDivision, std::string& errorMessage);
		bool UpdateAccess(int aID, int rID, int aiID, std::string& errorMessage);
		bool UpdateAccountType(int atID, std::string atName, int atNumber, std::string atComment, std::string& errorMessage);
		bool UpdateAccount(int aID, std::string aNumber, double aStartBalance, double aCurrentBalance, int cID, int sID,
			std::string aOpenDate, std::string aCloseDate, std::string aDetails, std::string& errorMessage);
		bool UpdateBalance(int bID, int uID, int aID, std::string& errorMessage);
		bool UpdateChartOfAccount(int coaID, int caoNumber, std::string caoNameOfAccount, int atID, std::string& errorMessage);
		bool UpdateClient(int uID, std::string cFirm, std::string cFirmNumber, int lID, std::string& errorMessage);
		bool UpdateCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment,
			std::string& errorMessage);
		bool UpdateConsumeProductList(int clID, int cpID, int pID, int clCount, double clSum, int sID, int cID, std::string& errorMessage);
		bool UpdateConsumeProduct(int cID, int eID, std::string cDate, std::string cExecDate, int seID, int cCount, double cSum, int sID, int curID, std::string& errorMessage);
		bool UpdateConsumeRawList(int clID, int cpID, int pID, int clCount, double clSum, int sID, int cID, std::string& errorMessage);
		bool UpdateConsumeRaw(int cID, int uID, std::string cDate, std::string cExecDate, int seID, int cCount, double cSum, int sID, int curID, std::string& errorMessage);
		bool UpdateCurrency(int cID, int cCode, std::string cShortName, std::string cName, int cUnit, bool cMainTrade, std::string& errorMessage);
		bool UpdateEmployee(int uID, int pID, std::string eBirthDate, std::string eHireDate, std::string& errorMessage);
		bool UpdateEntry(int eID, std::string eDate, int daID, double eValue, int caID, std::string& errorMessage);
		bool UpdateInventorizationList(int ilID, int iID, int pID, int ilCount, double ilSum, int sID, int cID, std::string& errorMessage);
		bool UpdateInventorization(int iID, int uID, std::string iDate, std::string iExecDate, int seID, int iCount, double iSum, int sID, int cID, std::string& errorMessage);
		bool UpdateJobprice(int jID, int pID, double jValue, int cID, double jVolume, int mID, int psID, std::string& errorMessage);
		bool UpdateJobsheet(int jID, std::string jDate, double jCount, int pID, int eID, std::string& errorMessage);
		bool UpdateLocation(int lID, std::string lCountryName, std::string lCountryCode, std::string lRegionName
			, std::string lCityName, std::string& errorMessage);
		bool UpdateMeasure(int mID, std::string mName, std::string mShortName, int mUnit, std::string& errorMessage);
		bool UpdateNetCost(int ncID, std::string ncDate, double ncValue, int cID, int pID, bool ncIsOutdated, std::string& errorMessage);
		bool UpdateOrderList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID, std::string& errorMessage);
		bool UpdateOrder(int oID, int uID, std::string oDate, std::string oExecDate, int eID, int oCount, double oSum, int sID, int cID, std::string& errorMessage);
		bool UpdateOrderRawList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID, std::string& errorMessage);
		bool UpdateOrderRaw(int oID, int uID, std::string oDate, std::string oExecDate, int seID, int oCount, double oSum, int sID, int cID, std::string& errorMessage);
		bool UpdatePayment(int pID, std::string pDate, double pValue, int uID, int cID, std::string& errorMessage);
		bool UpdatePayslip(int pID, std::string pDate, double pValue, int sID, int cID, std::string& errorMessage);
		bool UpdatePercentRate(int prID, double prValue, std::string prCondition, int psID, std::string& errorMessage);
		bool UpdatePhoto(int pID, int uID, int prodId, std::string pSource, std::string& errorMessage);
		bool UpdatePosition(int pID, std::string pName, std::string& errorMessage);
		bool UpdatePrice(int pID, std::string pDate, double pValue, int cID, int prodID, bool aIsOutdated, std::string& errorMessage);
		bool UpdateProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName, std::string& errorMessage);
		bool UpdateProduction(int pID, std::string pProductionDate, std::string pExpiryDate, std::string pSessionStart,
			std::string pSessionEnd, std::string& errorMessage);
		bool UpdateProductionList(int plID, int pID, int prodID, int plCount, double plSum, int sID, int cID, std::string& errorMessage);
		bool UpdateProductionPlanList(int pplID, int ppID, int pID, int pplCount, double pplSum, int sID, int cID, std::string& errorMessage);
		bool UpdateProductionPlan(int pID, std::string pDate, int eID, int pCount, double pSum, int sID, int cID, std::string& errorMessage);
		bool UpdateProduct(int pID, int cID, std::string pName, double vol, int mID, double price, int pTypeID, int pShelfLife,
			int pCur, std::string& errorMessage);
		bool UpdatePurveyor(int uID, std::string pCompanyName, int lID, std::string& errorMessage);
		bool UpdateReceiptProductList(int rlID, int rpID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage);
		bool UpdateReceiptProduct(int rID, int eID, std::string rDate, std::string rExecDate, int seID, int rCount, double rSum, int sID, int cID, std::string& errorMessage);
		bool UpdateReceiptRawList(int rlID, int rpID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage);
		bool UpdateReceiptRaw(int rID, int uID, std::string rDate, std::string rExecDate, int seID, int rCount, double rSum, int sID, int cID, std::string& errorMessage);
		bool UpdateRefund(int rID, std::string rDate, double rValue, int uID, int cID, std::string& errorMessage);
		bool UpdateRelationType(int rID, std::string rName, std::string rComment, std::string& errorMessage);
		bool UpdateRelation(int rID, int uID1, int uID2, int rtID, std::string& errorMessage);
		bool UpdateReturnList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage);
		bool UpdateReturn(int rID, int uID, std::string rDate, std::string oExecDate, int eID, int rCount, double rSum, int sID, int cID, std::string& errorMessage);
		bool UpdateRole(int rID, std::string rCode, std::string rName, std::string rComment, std::string& errorMessage);
		bool UpdateSalary(int sID, int uID, double sValue, int cID, int stID, std::string sDate, bool sBonus, std::string& errorMessage);
		bool UpdateSalaryType(int sID, std::string sCode, std::string sName, std::string& errorMessage);
		bool UpdateSpecificationList(int slID, int sID, int pID, double tlCount, std::string& errorMessage);
		bool UpdateSpecification(int sID, int pID, double sSum, int cID, int eID, std::string sDate, std::string& errorMessage);
		bool UpdateSpoilageList(int slID, int sID, int pID, int slCount, double slSum, int stsID, int cID, std::string& errorMessage);
		bool UpdateSpoilage(int sID, std::string sDate, int eID, int sCount, double sSum, int stsID, int cID, std::string& errorMessage);
		bool UpdateStatus(int sID, std::string sCode, std::string sName, std::string sComment, std::string& errorMessage);
		bool UpdateStock(int sID, int pID, int sCount, double sSum, int stsID, int cID, std::string& errorMessage);
		bool UpdateTimesheet(int tID, int sID, double tWorkedTime, std::string tDate, std::string& errorMessage);
		bool UpdateTransportList(int tlID, int tID, int pID, int tlCount, double tlSum, int sID, int cID, std::string& errorMessage);
		bool UpdateTransport(int tID, int uID, std::string tDate, std::string tExecDate, int seID, int tCount, double tSum, int sID, int cID, std::string& errorMessage);
		bool UpdateUser(int uID, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone, std::string uAddress,
			int uRoleID, std::string uPassword, bool uActivated, std::string& errorMessage);
		bool UpdateWithdrawal(int wID, std::string wDate, double wValue, int uID, int cID, std::string& errorMessage);
		bool UpdateWriteOffList(int wlID, int wID, int pID, int wlCount, double wlSum, int sID, int cID, std::string& errorMessage);
		bool UpdateWriteOff(int wID, int uID, std::string wDate, int eID, int wCount, double wSum, int sID, int cID, std::string& errorMessage);
		bool UpdateWriteOffRawList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage);
		bool UpdateWriteOffRaw(int tID, int uID, std::string rDate, int seID, int rCount, double rSum, int sID, int cID, std::string& errorMessage);

		//Filter factory
		std::string GetFilterForAccessItem(int aID, std::string aItemEng, std::string aItemRu, std::string aDivision);
		std::string GetFilterForAccess(int aID, int rID, int aiID);
		std::string GetFilterForAccountEntry(int aID, int eID);
		std::string GetFilterForAccountType(int atID, std::string atName, int atNumber, std::string atComment);
		std::string GetFilterForAccount(int aID, std::string aNumber, double aStartBalance, double aCurrentBalance, int cID, int sID,
			std::string aOpenDate, std::string aCloseDate, std::string aDetails);
		std::string GetFilterForBalancePayment(int bID, int pID);
		std::string GetFilterForBalancePayslip(int bID, int pID);
		std::string GetFilterForBalanceRefund(int bID, int rID);
		std::string GetFilterForBalanceWithdrawal(int bID, int wID);
		std::string GetFilterForBalance(int bID, int uID, int aID);
		std::string GetFilterForClient(int cID, std::string uName, std::string uSurname, std::string uPhone,
			std::string uAddress, std::string cFirm, std::string cFirmNumber, std::string uPassword, std::string uEmail, 
			bool uActivated, int rID, int lID);
		std::string GetFilterForChartOfAccount(int coaID, int caoNumber, std::string caoNameOfAccount, int atID);
		std::string GetFilterForCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment);
		std::string GetFilterForCompanyAccount(int cID, int aID);
		std::string GetFilterForConsumeProductList(int clID, int cpID, int pID, int clCount, double clSum, int sID, int cID);
		std::string GetFilterForConsumeProduct(int cID, int eID, std::string cDate, std::string cExecDate, int seID, int cCount, double cSum, int sID, int curID);
		std::string GetFilterForConsumeRawList(int clID, int cpID, int pID, int clCount, double clSum, int sID, int cID);
		std::string GetFilterForConsumeRaw(int cID, int uID, std::string cDate, std::string cExecDate, int seID, int cCount, double cSum, int sID, int curID);
		std::string GetFilterForCurrency(int cID, int cCode, std::string cShortName, std::string cName, int cUnit);
		std::string GetFilterForEmployee(int eID, std::string uName, std::string uSurname, std::string uPhone, 
			std::string uAddress, std::string eBirthDate, std::string eHireDate, std::string uPassword, 
			std::string uEmail, bool uActivated, int rID, int pID);
		std::string GetFilterForEntry(int eID, std::string eDate, int daID, double eValue, int caID);
		std::string GetFilterForInventorizationList(int ilID, int iID, int pID, int ilCount, double ilSum, int sID, int cID);
		std::string GetFilterForInventorization(int iID, int uID, std::string iDate, std::string iExecDate, int seID, int iCount, double iSum, int sID, int cID);
		std::string GetFilterForJobprice(int jID, int pID, double jValue, int cID, double jVolume, int mID, int psID);
		std::string GetFilterForJobsheet(int jID, std::string jDate, double jCount, int pID, int eID);
		std::string GetFilterForLocation(int lID, std::string lCountryName, std::string lCountryCode, std::string lRegionName
			, std::string lCityName);
		std::string GetFilterForMeasure(int mID, std::string mName, std::string mShortName, int mUnit);
		std::string GetFilterForNetCost(int ncID, std::string ncDate, double ncValue, int cID, int pID, bool ncIsOutdated);
		std::string GetFilterForOrderList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID);
		std::string GetFilterForOrder(int oID, int uID, std::string oDate, std::string oExecDate, int eID, int oCount, double oSum, int sID, int cID);
		std::string GetFilterForOrder(int oID, int uID, std::string oDate, std::string oExecDate, int eID, int oCount, double oSum, int sID, int cID, std::string fromDate, std::string toDate);
		std::string GetFilterForOrderRawList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID);
		std::string GetFilterForOrderRaw(int oID, int uID, std::string oDate, std::string oExecDate, int seID, int oCount, double oSum, int sID, int cID);
		std::string GetFilterForPayment(int pID, std::string pDate, double pValue, int uID, int cID);
		std::string GetFilterForPayslip(int pID, std::string pDate, double pValue, int sID, int cID);
		std::string GetFilterForPayslipOrder(int pID, int oID);
		std::string GetFilterForPercentRate(int prID, double prValue, std::string prCondition, int psID);
		std::string GetFilterForPhoto(int pID, int uID, int prodId, std::string pSource);
		std::string GetFilterForPosition(int pID, std::string pName);
		std::string GetFilterForPrice(int pID, std::string pDate, double pValue, int cID, int prodID, bool ncIsOutdated);
		std::string GetFilterForProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName);
		std::string GetFilterForProduction(int pID, std::string pProductionDate, std::string pExpiryDate, std::string pSessionStart,
			std::string pSessionEnd);
		std::string GetFilterForProductionList(int plID, int pID, int prodID, int plCount, double plSum, int sID, int cID);
		std::string GetFilterForProductionPlanList(int pplID, int ppID, int pID, int pplCount, double pplSum, int sID, int cID);
		std::string GetFilterForProductionPlan(int pID, std::string pDate, int eID, int pCount, double pSum, int sID, int cID);
		std::string GetFilterForProduct(int pID, int cID, std::string pName, double vol, int mID, double price, int pTypeID, int pShelfLife,
			int pCur);
		std::string GetFilterForPurveyor(int pID, std::string uName, std::string uSurname, std::string uPhone,
			std::string uAddress, std::string pCompanyName, std::string uPassword, std::string uEmail,
			bool uActivated, int rID, int lID);
		std::string GetFilterForReceiptProductList(int rlID, int rpID, int pID, int rlCount, double rlSum, int sID, int cID);
		std::string GetFilterForReceiptProduct(int rID, int eID, std::string rDate, std::string rExecDate, int seID, int rCount, double rSum, int sID, int cID);
		std::string GetFilterForReceiptRawList(int rlID, int rpID, int pID, int rlCount, double rlSum, int sID, int cID);
		std::string GetFilterForReceiptRaw(int rID, int uID, std::string rDate, std::string rExecDate, int seID, int rCount, double rSum, int sID, int cID);
		std::string GetFilterForRefund(int rID, std::string rDate, double rValue, int uID, int cID);
		std::string GetFilterForRelationType(int rID, std::string rName, std::string rComment);
		std::string GetFilterForRelation(int rID, int uID1, int uID2, int rtID);
		std::string GetFilterForReturnList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID);
		std::string GetFilterForReturn(int rID, int uID, std::string rDate, std::string rExecDate, int eID, int rCount, double rSum, int sID, int cID);
		std::string GetFilterForRole(int rID, std::string rCode, std::string rName, std::string rComment);
		std::string GetFilterForSalary(int sID, int uID, double sValue, int cID, int stID, std::string sDate, bool sBonus);
		std::string GetFilterForSalaryType(int sID, std::string sCode, std::string sName);
		std::string GetFilterForSpecificationList(int slID, int sID, int pID, double tlCount);
		std::string GetFilterForSpecification(int sID, int pID, double sSum, int cID, int eID, std::string sDate);
		std::string GetFilterForSpoilageList(int slID, int sID, int pID, int slCount, double slSum, int stsID, int cID);
		std::string GetFilterForSpoilage(int sID, std::string sDate, int eID, int sCount, double sSum, int stsID, int cID);
		std::string GetFilterForStatus(int sID, std::string sCode, std::string sName, std::string sComment);
		std::string GetFilterForStock(int sID, int pID, int sCount, double sSum, int stsID, int cID);
		std::string GetFilterForTimesheet(int tID, int sID, double tWorkedTime, std::string tDate);
		std::string GetFilterForTransportList(int tlID, int tID, int pID, int tlCount, double tlSum, int sID, int cID);
		std::string GetFilterForTransport(int tID, int uID, std::string tDate, std::string tExecDate, int seID, int tCount, double tSum, int sID, int cID);
		std::string GetFilterForUser(int uID, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone, std::string uAddress,
			int uRoleID, std::string uPassword, bool uActivated);
		std::string GetFilterForWithdrawal(int wID, std::string wDate, double wValue, int uID, int cID);
		std::string GetFilterForWriteOffList(int wlID, int wID, int pID, int wlCount, double wlSum, int sID, int cID);
		std::string GetFilterForWriteOff(int wID, int uID, std::string wDate, int eID, int wCount, double wSum, int sID, int cID);
		std::string GetFilterForWriteOffRawList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID);
		std::string GetFilterForWriteOffRaw(int tID, int uID, std::string rDate, int seID, int rCount, double rSum, int sID, int cID);

		//overloaded  operators
		OrmasDal& operator=(const OrmasDal& od)
		{
			if (this == &od)
			{
				return *this;
			}
			else
			{
				dbCon = od.dbCon;
				connString = od.connString;
			}
			return *this;
		}
	private:
		PGconn *dbCon;
		ConnectionString connString;
	};
}

#endif //ORMASDAL_H
