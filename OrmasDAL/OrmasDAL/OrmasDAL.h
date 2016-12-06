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
		std::vector<companiesCollection> GetCompanies(std::string& errorMessage, std::string filter = std::string());
		std::vector<currenciesCollection> GetCurrencies(std::string& errorMessage, std::string filter = std::string());
		std::vector<measuresCollection> GetMeasures(std::string& errorMessage, std::string filter = std::string());
		std::vector<ordersViewCollection> GetOrders(std::string& errorMessage, std::string filter = std::string());
		std::vector<productListCollection> GetProductLists(std::string& errorMessage, std::string filter = std::string());
		std::vector<productTypeCollection> GetProductTypes(std::string& errorMessage, std::string filter = std::string());
		std::vector<productsCollection> GetProducts(std::string& errorMessage, std::string filter = std::string());
		std::vector<locationsCollection> GetLocations(std::string& errorMessage, std::string filter = std::string());
		std::vector<returnsViewCollection> GetReturns(std::string& errorMessage, std::string filter = std::string());
		std::vector<rolesCollection> GetRoles(std::string& errorMessage, std::string filter = std::string());
		std::vector<statusCollection> GetStatus(std::string& errorMessage, std::string filter = std::string());
		std::vector<usersCollection> GetUsers(std::string& errorMessage, std::string filter = std::string());

		//create methods
		bool CreateCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment,
			std::string& errorMessage);
		bool CreateCurrency(int cID, int cCode, std::string cShortName, std::string cName, std::string& errorMessage);
		bool CreateMeasure(int mID, std::string mName, std::string mShortName, std::string& errorMessage);
		bool CreateOrder(int oID, int uID, std::string oDate, int wID, std::string& errorMessage);
		bool CreateProductList(int pListID, int oID, int rID, int pID, int count, std::string& errorMessage);
		bool CreateProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName, std::string& errorMessage);
		bool CreateProduct(int pID, int cID, std::string pName, float vol, int mID, float price, int pTypeID, int pShelfLife, 
			std::string& errorMessage);
		bool CreateLocation(int lID, std::string lCountryName, std::string lCountryCode, std::string lRegionName
			, std::string lCityName, std::string& errorMessage);
		bool CreateReturn(int rID, int uID, std::string rDate, int wID, std::string& errorMessage);
		bool CreateRole(int rID, std::string rName, std::string rComment, std::string& errorMessage);
		bool CreateStatus(int sID, std::string sCode, std::string sName, std::string sComment, std::string& errorMessage);
		bool CreateUser(int uID, std::string uName, std::string uPhone, std::string uAddress, std::string firm, std::string firmNumber,
			int uRoleID, int uLocationID, std::string uPassword, bool uActivated, std::string& errorMessage);

		//delete methods
		bool DeleteCompany(int id, std::string& errorMessage);
		bool DeleteCurrency(int id, std::string& errorMessage);
		bool DeleteMeasure(int id, std::string& errorMessage);
		bool DeleteOrder(int id, std::string& errorMessage);
		bool DeleteProductList(int id, std::string& errorMessage);
		bool DeleteProductType(int id, std::string& errorMessage);
		bool DeleteProduct(int id, std::string& errorMessage);
		bool DeleteLocation(int id, std::string& errorMessage);
		bool DeleteReturn(int id, std::string& errorMessage);
		bool DeleteRole(int id, std::string& errorMessage);
		bool DeleteStatus(int id, std::string& errorMessage);
		bool DeleteUser(int id, std::string& errorMessage);

		//update methods
		bool UpdateCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment, 
			std::string& errorMessage);
		bool UpdateCurrency(int cID, int cCode, std::string cShortName, std::string cName, std::string& errorMessage);
		bool UpdateMeasure(int mID, std::string mName, std::string mShortName, std::string& errorMessage);
		bool UpdateOrder(int oID, int uID, std::string oDate, int wID, std::string& errorMessage);
		bool UpdateProductList(int pListID, int oID, int rID, int pID, int count, std::string& errorMessage);
		bool UpdateProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName, std::string& errorMessage);
		bool UpdateProduct(int pID, int cID, std::string pName, float vol, int mID, float price, int pTypeID, int pShelfLife, 
			std::string& errorMessage);
		bool UpdateLocation(int lID, std::string lCountryName, std::string lCountryCode, std::string lRegionName
			, std::string lCityName, std::string& errorMessage);
		bool UpdateReturn(int rID, int uID, std::string rDate, int wID, std::string& errorMessage);
		bool UpdateRole(int rID, std::string rName, std::string rComment, std::string& errorMessage);
		bool UpdateStatus(int sID, std::string sCode, std::string sName, std::string sComment, std::string& errorMessage);
		bool UpdateUser(int uID, std::string uName, std::string uPhone, std::string uAddress, std::string firm, std::string firmNumber,
			int uRoleID, int uLocationID, std::string uPassword, bool uActivated, std::string& errorMessage);

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