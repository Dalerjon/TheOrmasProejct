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
		void InitFromConfigFile(std::string path);
		void SetDBParams(std::string dbname, std::string username, std::string password, std::string host, int port);
		int GetNextID(PGconn *connection);

		//view methods
		std::vector<companiesCollection> GetCompanies(PGconn *connection, std::string filter = std::string());
		std::vector<currenciesCollection> GetCurrencies(PGconn *connection, std::string filter = std::string());
		std::vector<measuresCollection> GetMeasures(PGconn *connection, std::string filter = std::string());
		std::vector<ordersCollection> GetOrders(PGconn *connection, std::string filter = std::string());
		std::vector<productListCollection> GetProductLists(PGconn *connection, std::string filter = std::string());
		std::vector<productTypeCollection> GetProductTypes(PGconn *connection, std::string filter = std::string());
		std::vector<productsCollection> GetProducts(PGconn *connection, std::string filter = std::string());
		std::vector<regionsCollection> GetRegions(PGconn *connection, std::string filter = std::string());
		std::vector<returnsCollection> GetReturns(PGconn *connection, std::string filter = std::string());
		std::vector<rolesCollection> GetRoles(PGconn *connection, std::string filter = std::string());
		std::vector<statusCollection> GetStatus(PGconn *connection, std::string filter = std::string());
		std::vector<usersCollection> GetUsers(PGconn *connection, std::string filter = std::string());

		//create methods
		bool CreateCompany(PGconn *connection, int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment);
		bool CreateCurrency(PGconn *connection, int cID, int cCode, std::string cShortName, std::string cName);
		bool CreateMeasure(PGconn *connection, int mID, std::string mName, std::string mShortName);
		bool CreateOrder(PGconn *connection, int oID, int uID, std::string oDate, int wID, std::string fName);
		bool CreateProductList(PGconn *connection, int pListID, int oID, int rID, int pID, int count);
		bool CreateProductType(PGconn *connection, int pTypeID, std::string pTypeName, std::string pTypeShortName);
		bool CreateProduct(PGconn *connection, int pID, int cID, std::string pName, float vol, int mID, float price, int pTypeID,
			std::string dProduce, std::string dEnd);
		bool CreateRegion(PGconn *connection, int rID, std::string rCode, std::string rName);
		bool CreateReturn(PGconn *connection, int rID, int uID, std::string rDate, int wID, std::string fName);
		bool CreateRole(PGconn *connection, int rID, std::string rName, std::string rComment);
		bool CreateStatus(PGconn *connection, int sID, std::string sCode, std::string sName, std::string sComment);
		bool CreateUser(PGconn *connection, int uID, std::string uName, std::string uPhone, std::string uAddress, std::string firm, std::string firmNumber,
			int uRoleID, int uRegionID, std::string uPassword);

		//delete methods
		bool DeleteCompany(PGconn *connection, int id);
		bool DeleteCurrency(PGconn *connection, int id);
		bool DeleteMeasure(PGconn *connection, int id);
		bool DeleteOrder(PGconn *connection, int id);
		bool DeleteProductList(PGconn *connection, int id);
		bool DeleteProductType(PGconn *connection, int id);
		bool DeleteProduct(PGconn *connection, int id);
		bool DeleteRegion(PGconn *connection, int id);
		bool DeleteReturn(PGconn *connection, int id);
		bool DeleteRole(PGconn *connection, int id);
		bool DeleteStatus(PGconn *connection, int id);
		bool DeleteUser(PGconn *connection, int id);

		//update methods
		bool UpdateCompany(PGconn *connection, int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment);
		bool UpdateCurrency(PGconn *connection, int cID, int cCode, std::string cShortName, std::string cName);
		bool UpdateMeasure(PGconn *connection, int mID, std::string mName, std::string mShortName);
		bool UpdateOrder(PGconn *connection, int oID, int uID, std::string oDate, int wID, std::string fName);
		bool UpdateProductList(PGconn *connection, int pListID, int oID, int rID, int pID, int count);
		bool UpdateProductType(PGconn *connection, int pTypeID, std::string pTypeName, std::string pTypeShortName);
		bool UpdateProduct(PGconn *connection, int pID, int cID, std::string pName, float vol, int mID, float price, int pTypeID,
			std::string dProduce, std::string dEnd);
		bool UpdateRegion(PGconn *connection, int rID, std::string rCode, std::string rName);
		bool UpdateReturn(PGconn *connection, int rID, int uID, std::string rDate, int wID, std::string fName);
		bool UpdateRole(PGconn *connection, int rID, std::string rName, std::string rComment);
		bool UpdateStatus(PGconn *connection, int sID, std::string sCode, std::string sName, std::string sComment);
		bool UpdateUser(PGconn *connection, int uID, std::string uName, std::string uPhone, std::string uAddress, std::string firm, std::string firmNumber,
			int uRoleID, int uRegionID, std::string uPassword);

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