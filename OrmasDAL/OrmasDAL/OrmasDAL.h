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

		//work with transaction
		bool StartTransaction(std::string& errorMessage);
		bool CommitTransaction(std::string& errorMessage);
		bool CancelTransaction(std::string& errorMessage);

		//view methods
		std::vector<accessItemsCollection> GetAccessItems(std::string& errorMessage, std::string filter = std::string());
		std::vector<accessesCollection> GetAccesses(std::string& errorMessage, std::string filter = std::string());
		std::vector<balancesViewCollection> GetBalances(std::string& errorMessage, std::string filter = std::string());
		std::vector<clientsViewCollection> GetClients(std::string& errorMessage, std::string filter = std::string());
		std::vector<companiesCollection> GetCompanies(std::string& errorMessage, std::string filter = std::string());
		std::vector<currenciesCollection> GetCurrencies(std::string& errorMessage, std::string filter = std::string());
		std::vector<employeesViewCollection> GetEmployees(std::string& errorMessage, std::string filter = std::string());
		std::vector<locationsCollection> GetLocations(std::string& errorMessage, std::string filter = std::string());
		std::vector<measuresCollection> GetMeasures(std::string& errorMessage, std::string filter = std::string());
		std::vector<orderListViewCollection> GetOrderList(std::string& errorMessage, std::string filter = std::string());
		std::vector<ordersViewCollection> GetOrders(std::string& errorMessage, std::string filter = std::string());
		std::vector<paymentsViewCollection> GetPayments(std::string& errorMessage, std::string filter = std::string());
		std::vector<photosCollection> GetPhotos(std::string& errorMessage, std::string filter = std::string());
		std::vector<positionsCollection> GetPositions(std::string& errorMessage, std::string filter = std::string());
		std::vector<pricesViewCollection> GetPrices(std::string& errorMessage, std::string filter = std::string());
		std::vector<productTypeCollection> GetProductTypes(std::string& errorMessage, std::string filter = std::string());
		std::vector<productionCollection> GetProduction(std::string& errorMessage, std::string filter = std::string());
		std::vector<productionListViewCollection> GetProductionList(std::string& errorMessage, std::string filter = std::string());
		std::vector<productsViewCollection> GetProducts(std::string& errorMessage, std::string filter = std::string());
		std::vector<relationTypeCollection> GetRelationType(std::string& errorMessage, std::string filter = std::string());
		std::vector<relationsCollection> GetRelations(std::string& errorMessage, std::string filter = std::string());
		std::vector<returnListViewCollection> GetReturnList(std::string& errorMessage, std::string filter = std::string());
		std::vector<returnsViewCollection> GetReturns(std::string& errorMessage, std::string filter = std::string());
		std::vector<rolesCollection> GetRoles(std::string& errorMessage, std::string filter = std::string());
		std::vector<salariesViewCollection> GetSalaries(std::string& errorMessage, std::string filter = std::string());
		std::vector<salaryTypeCollection> GetSalaryType(std::string& errorMessage, std::string filter = std::string());
		std::vector<statusCollection> GetStatus(std::string& errorMessage, std::string filter = std::string());
		std::vector<usersViewCollection> GetUsers(std::string& errorMessage, std::string filter = std::string());
		std::vector<writeOffsViewCollection> GetWriteOffs(std::string& errorMessage, std::string filter = std::string());
		std::vector<writeOffListViewCollection> GetWriteOffList(std::string& errorMessage, std::string filter = std::string());

		//create methods
		bool CreateAccessItem(int aID, std::string aItenEng, std::string aItemRu,std::string aDivision, std::string& errorMessage);
		bool CreateAccess(int aID, int rID, int aiID, std::string& errorMessage);
		bool CreateBalance(int bID, int uID, double bValue, int cID, std::string& errorMessage);
		bool CreateClient(int uID, std::string cFirm, std::string cFirmNumber, int lID, std::string& errorMessage);
		bool CreateCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment,
			std::string& errorMessage);
		bool CreateCurrency(int cID, int cCode, std::string cShortName, std::string cName, int cUnit, bool cMainTrade, std::string& errorMessage);
		bool CreateEmployee(int uID, int pID, std::string eBirthDate, std::string eHireDate, std::string& errorMessage);
		bool CreateLocation(int lID, std::string lCountryName, std::string lCountryCode, std::string lRegionName
			, std::string lCityName, std::string& errorMessage);
		bool CreateMeasure(int mID, std::string mName, std::string mShortName, int mUnit, std::string& errorMessage);
		bool CreateOrderList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID, std::string& errorMessage);
		bool CreateOrder(int oID, int uID, std::string oDate, int eID, int oCount, double oSum, int sID, int cID, std::string& errorMessage);
		bool CreatePayment(int pID, std::string pDate, double pValue, int uID, int cID, std::string& errorMessage);
		bool CreatePhoto(int pID, int uID, int prodId, std::string pSource, std::string& errorMessage);
		bool CreatePosition(int pID, std::string pName, std::string& errorMessage);
		bool CreatePrice(int pID, std::string pDate, double pValue, int cID, int prodID, std::string& errorMessage);
		bool CreateProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName, std::string& errorMessage);
		bool CreateProduction(int pID, std::string pProductionDate, std::string pExpiryDate, std::string pSessionStart, 
			std::string pSessionEnd, std::string& errorMessage);
		bool CreateProductionList(int plID, int pID, int prodID, int plCount, double plSum, int sID, int cID, std::string& errorMessage);
		bool CreateProduct(int pID, int cID, std::string pName, double vol, int mID, double price, int pTypeID, int pShelfLife, 
			int pCur, std::string& errorMessage);
		bool CreateRelationType(int rID, std::string rName, std::string rComment, std::string& errorMessage);
		bool CreateRelation(int rID, int uID1, int uID2, int rtID, std::string& errorMessage);
		bool CreateReturnList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage);
		bool CreateReturn(int rID, int uID, std::string rDate, int eID, int rCount, double rSum, int sID, int cID, std::string& errorMessage);
		bool CreateSalary(int sID, int uID, double sValue, int cID, int stID, std::string sDate, bool sBonus, std::string& errorMessage);
		bool CreateSalaryType(int sID, std::string sCode, std::string sName, std::string& errorMessage);
		bool CreateRole(int rID,std::string rCode, std::string rName, std::string rComment, std::string& errorMessage);
		bool CreateStatus(int sID, std::string sCode, std::string sName, std::string sComment, std::string& errorMessage);
		bool CreateUser(int uID, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone, std::string uAddress,
			int uRoleID, std::string uPassword, bool uActivated, std::string& errorMessage);
		bool CreateWriteOffList(int wlID, int wID, int pID, int wlCount, double wlSum, int sID, int cID, std::string& errorMessage);
		bool CreateWriteOff(int wID, int uID, std::string wDate, int eID, int wCount, double wSum, int sID, int cID, std::string& errorMessage);

		//delete methods
		bool DeleteAccessItem(int id, std::string& errorMessage);
		bool DeleteAccess(int id, std::string& errorMessage);
		bool DeleteBalance(int id, std::string& errorMessage);
		bool DeleteClient(int id, std::string& errorMessage);
		bool DeleteCompany(int id, std::string& errorMessage);
		bool DeleteCurrency(int id, std::string& errorMessage);
		bool DeleteEmployee(int id, std::string& errorMessage);
		bool DeleteLocation(int id, std::string& errorMessage);
		bool DeleteMeasure(int id, std::string& errorMessage);
		bool DeleteItemInOrderList(int id, std::string& errorMessage);
		bool DeleteOrder(int id, std::string& errorMessage);
		bool DeletePayment(int id, std::string& errorMessage);
		bool DeletePhoto(int id, std::string& errorMessage);
		bool DeletePosition(int id, std::string& errorMessage);
		bool DeletePrice(int id, std::string& errorMessage);
		bool DeleteProductType(int id, std::string& errorMessage);
		bool DeleteProduction(int id, std::string& errorMessage);
		bool DeleteItemInProductionList(int id, std::string& errorMessage);
		bool DeleteProduct(int id, std::string& errorMessage);
		bool DeleteRelationType(int id, std::string& errorMessage);
		bool DeleteRelation(int id, std::string& errorMessage);
		bool DeleteItemInReturnList(int id, std::string& errorMessage);
		bool DeleteReturn(int id, std::string& errorMessage);
		bool DeleteRole(int id, std::string& errorMessage);
		bool DeleteSalary(int id, std::string& errorMessage);
		bool DeleteSalaryType(int id, std::string& errorMessage);
		bool DeleteStatus(int id, std::string& errorMessage);
		bool DeleteUser(int id, std::string& errorMessage);
		bool DeleteWriteOff(int id, std::string& errorMessage);
		bool DeleteItemInWriteOffList(int id, std::string& errorMessage);

		//update methods
		bool UpdateAccessItem(int aID, std::string aItemEng, std::string aItemRu, std::string aDivision, std::string& errorMessage);
		bool UpdateAccess(int aID, int rID, int aiID, std::string& errorMessage);
		bool UpdateBalance(int bID, int uID, double bValue, int cID, std::string& errorMessage);
		bool UpdateClient(int uID, std::string cFirm, std::string cFirmNumber, int lID, std::string& errorMessage);
		bool UpdateCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment,
			std::string& errorMessage);
		bool UpdateCurrency(int cID, int cCode, std::string cShortName, std::string cName, int cUnit, bool cMainTrade, std::string& errorMessage);
		bool UpdateEmployee(int uID, int pID, std::string eBirthDate, std::string eHireDate, std::string& errorMessage);
		bool UpdateLocation(int lID, std::string lCountryName, std::string lCountryCode, std::string lRegionName
			, std::string lCityName, std::string& errorMessage);
		bool UpdateMeasure(int mID, std::string mName, std::string mShortName, int mUnit, std::string& errorMessage);
		bool UpdateOrderList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID, std::string& errorMessage);
		bool UpdateOrder(int oID, int uID, std::string oDate, int eID, int oCount, double oSum, int sID, int cID, std::string& errorMessage);
		bool UpdatePayment(int pID, std::string pDate, double pValue, int uID, int cID, std::string& errorMessage);
		bool UpdatePhoto(int pID, int uID, int prodId, std::string pSource, std::string& errorMessage);
		bool UpdatePosition(int pID, std::string pName, std::string& errorMessage);
		bool UpdatePrice(int pID, std::string pDate, double pValue, int cID, int prodID, std::string& errorMessage);
		bool UpdateProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName, std::string& errorMessage);
		bool UpdateProduction(int pID, std::string pProductionDate, std::string pExpiryDate, std::string pSessionStart,
			std::string pSessionEnd, std::string& errorMessage);
		bool UpdateProductionList(int plID, int pID, int prodID, int plCount, double plSum, int sID, int cID, std::string& errorMessage);
		bool UpdateProduct(int pID, int cID, std::string pName, double vol, int mID, double price, int pTypeID, int pShelfLife,
			int pCur, std::string& errorMessage);
		bool UpdateRelationType(int rID, std::string rName, std::string rComment, std::string& errorMessage);
		bool UpdateRelation(int rID, int uID1, int uID2, int rtID, std::string& errorMessage);
		bool UpdateReturnList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage);
		bool UpdateReturn(int rID, int uID, std::string rDate, int eID, int rCount, double rSum, int sID, int cID, std::string& errorMessage);
		bool UpdateRole(int rID, std::string rCode, std::string rName, std::string rComment, std::string& errorMessage);
		bool UpdateSalary(int sID, int uID, double sValue, int cID, int stID, std::string sDate, bool sBonus, std::string& errorMessage);
		bool UpdateSalaryType(int sID, std::string sCode, std::string sName, std::string& errorMessage);
		bool UpdateStatus(int sID, std::string sCode, std::string sName, std::string sComment, std::string& errorMessage);
		bool UpdateUser(int uID, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone, std::string uAddress,
			int uRoleID, std::string uPassword, bool uActivated, std::string& errorMessage);
		bool UpdateWriteOffList(int wlID, int wID, int pID, int wlCount, double wlSum, int sID, int cID, std::string& errorMessage);
		bool UpdateWriteOff(int wID, int uID, std::string wDate, int eID, int wCount, double wSum, int sID, int cID, std::string& errorMessage);

		//Filter factory
		std::string GetFilterForAccessItem(int aID, std::string aItemEng, std::string aItemRu, std::string aDivision);
		std::string GetFilterForAccess(int aID, int rID, int aiID);
		std::string GetFilterForBalance(int bID, int uID, double bValue, int cID);
		std::string GetFilterForClient(int cID, std::string uName, std::string uSurname, std::string uPhone,
			std::string uAddress, std::string cFirm, std::string cFirmNumber, std::string uPassword, std::string uEmail, 
			bool uActivated, int rID, int lID);
		std::string GetFilterForCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment);
		std::string GetFilterForCurrency(int cID, int cCode, std::string cShortName, std::string cName, int cUnit);
		std::string GetFilterForEmployee(int eID, std::string uName, std::string uSurname, std::string uPhone, 
			std::string uAddress, std::string eBirthDate, std::string eHireDate, std::string uPassword, 
			std::string uEmail, bool uActivated, int rID, int pID);
		std::string GetFilterForLocation(int lID, std::string lCountryName, std::string lCountryCode, std::string lRegionName
			, std::string lCityName);
		std::string GetFilterForMeasure(int mID, std::string mName, std::string mShortName, int mUnit);
		std::string GetFilterForOrderList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID);
		std::string GetFilterForOrder(int oID, int uID, std::string oDate, int eID, int oCount, double oSum, int sID, int cID);
		std::string GetFilterForPayment(int pID, std::string pDate, double pValue, int uID, int cID);
		std::string GetFilterForPhoto(int pID, int uID, int prodId, std::string pSource);
		std::string GetFilterForPosition(int pID, std::string pName);
		std::string GetFilterForPrice(int pID, std::string pDate, double pValue, int cID, int prodID);
		std::string GetFilterForProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName);
		std::string GetFilterForProduction(int pID, std::string pProductionDate, std::string pExpiryDate, std::string pSessionStart,
			std::string pSessionEnd);
		std::string GetFilterForProductionList(int plID, int pID, int prodID, int plCount, double plSum, int sID, int cID);
		std::string GetFilterForProduct(int pID, int cID, std::string pName, double vol, int mID, double price, int pTypeID, int pShelfLife,
			int pCur);
		std::string GetFilterForRelationType(int rID, std::string rName, std::string rComment);
		std::string GetFilterForRelation(int rID, int uID1, int uID2, int rtID);
		std::string GetFilterForReturnList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID);
		std::string GetFilterForReturn(int rID, int uID, std::string rDate, int eID, int rCount, double rSum, int sID, int cID);
		std::string GetFilterForRole(int rID, std::string rCode, std::string rName, std::string rComment);
		std::string GetFilterForSalary(int sID, int uID, double sValue, int cID, int stID, std::string sDate, bool sBonus);
		std::string GetFilterForSalaryType(int sID, std::string sCode, std::string sName);
		std::string GetFilterForStatus(int sID, std::string sCode, std::string sName, std::string sComment);
		std::string GetFilterForUser(int uID, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone, std::string uAddress,
			int uRoleID, std::string uPassword, bool uActivated);
		std::string GetFilterForWriteOffList(int wlID, int wID, int pID, int wlCount, double wlSum, int sID, int cID);
		std::string GetFilterForWriteOff(int wID, int uID, std::string wDate, int eID, int wCount, double wSum, int sID, int cID);

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