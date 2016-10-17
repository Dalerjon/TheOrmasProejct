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

		//view methods
		std::vector<companiesCollection> GetCompanies(std::string filter = std::string());
		std::vector<currenciesCollection> GetCurrencies(std::string filter = std::string());
		std::vector<measuresCollection> GetMeasures(std::string filter = std::string());
		std::vector<ordersCollection> GetOrders(std::string filter = std::string());
		std::vector<productListCollection> GetProductLists(std::string filter = std::string());
		std::vector<productTypeCollection> GetProductTypes(std::string filter = std::string());
		std::vector<productsCollection> GetProducts(std::string filter = std::string());
		std::vector<regionsCollection> GetRegions(std::string filter = std::string());
		std::vector<returnsCollection> GetReturns(std::string filter = std::string());
		std::vector<rolesCollection> GetRoles(std::string filter = std::string());
		std::vector<statusCollection> GetStatus(std::string filter = std::string());
		std::vector<usersCollection> GetUsers(std::string filter = std::string());

		//create methods
		bool CreateCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment);
		bool CreateCurrency(int cID, int cCode, std::string cShortName, std::string cName);
		bool CreateMeasure(int mID, std::string mName, std::string mShortName);
		bool CreateOrder(int oID, int uID, std::string oDate, int wID, std::string fName);
		bool CreateProductList(int pListID, int oID, int rID, int pID, int count);
		bool CreateProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName);
		bool CreateProduct(int pID, int cID, std::string pName, float vol, int mID, float price, int pTypeID,
			std::string dProduce, std::string dEnd);
		bool CreateRegion(int rID, std::string rCode, std::string rName);
		bool CreateReturn(int rID, int uID, std::string rDate, int wID, std::string fName);
		bool CreateRole(int rID, std::string rName, std::string rComment);
		bool CreateStatus(int sID, std::string sCode, std::string sName, std::string sComment);
		bool CreateUser(int uID, std::string uName, std::string uPhone, std::string uAddress, std::string firm, std::string firmNumber,
			int uRoleID, int uRegionID, std::string uPassword);

		//delete methods
		bool DeleteCompany(int id);
		bool DeleteCurrency(int id);
		bool DeleteMeasure(int id);
		bool DeleteOrder(int id);
		bool DeleteProductList(int id);
		bool DeleteProductType(int id);
		bool DeleteProduct(int id);
		bool DeleteRegion(int id);
		bool DeleteReturn(int id);
		bool DeleteRole(int id);
		bool DeleteStatus(int id);
		bool DeleteUser(int id);

		//update methods
		bool UpdateCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment);
		bool UpdateCurrency(int cID, int cCode, std::string cShortName, std::string cName);
		bool UpdateMeasure(int mID, std::string mName, std::string mShortName);
		bool UpdateOrder(int oID, int uID, std::string oDate, int wID, std::string fName);
		bool UpdateProductList(int pListID, int oID, int rID, int pID, int count);
		bool UpdateProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName);
		bool UpdateProduct(int pID, int cID, std::string pName, float vol, int mID, float price, int pTypeID,
			std::string dProduce, std::string dEnd);
		bool UpdateRegion(int rID, std::string rCode, std::string rName);
		bool UpdateReturn(int rID, int uID, std::string rDate, int wID, std::string fName);
		bool UpdateRole(int rID, std::string rName, std::string rComment);
		bool UpdateStatus(int sID, std::string sCode, std::string sName, std::string sComment);
		bool UpdateUser(int uID, std::string uName, std::string uPhone, std::string uAddress, std::string firm, std::string firmNumber,
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