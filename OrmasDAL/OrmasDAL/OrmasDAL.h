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

		//view methods
		std::vector<companiesCollection> GetCompanies(PGconn *connection, std::string filter = std::string());
		std::vector<currenciesCollection> GetCurrencies(PGconn *connection, std::string filter = std::string());
		std::vector<measuresCollection> GetMeasures(PGconn *connection, std::string filter = std::string());
		std::vector<ordersCollection> GetOrders(PGconn *connection, std::string filter = std::string());
		std::vector<productListCollection> GetProductList(PGconn *connection, std::string filter = std::string());
		std::vector<productTypeCollection> GetProductType(PGconn *connection, std::string filter = std::string());
		std::vector<productsCollection> GetProducts(PGconn *connection, std::string filter = std::string());
		std::vector<regionsCollection> GetRegions(PGconn *connection, std::string filter = std::string());
		std::vector<returnsCollection> GetReturns(PGconn *connection, std::string filter = std::string());
		std::vector<rolesCollection> GetRoles(PGconn *connection, std::string filter = std::string());
		std::vector<statusCollection> GetStatus(PGconn *connection, std::string filter = std::string());
		std::vector<usersCollection> GetUsers(PGconn *connection, std::string filter = std::string());

		//create methods
		bool CreateCompany();
		bool CreateCurrency();
		bool CreateMeasure();
		bool CreateProductList();
		bool CreateProductType();
		bool CreateProducts();
		bool CreateRegion();
		bool CreateReturns();
		bool CreateRoles();
		bool CreateStatus();
		bool CreateUser();

		//delete methods
		bool DeleteCompany();
		bool DeleteCurrency();
		bool DeleteMeasure();
		bool DeleteProductList();
		bool DeleteProductType();
		bool DeleteProducts();
		bool DeleteRegion();
		bool DeleteReturns();
		bool DeleteRoles();
		bool DeleteStatus();
		bool DeleteUser();

		//update methods
		bool UpdateCompany();
		bool UpdateCurrency();
		bool UpdateMeasure();
		bool UpdateProductList();
		bool UpdateProductType();
		bool UpdateProducts();
		bool UpdateRegion();
		bool UpdateReturns();
		bool UpdateRoles();
		bool UpdateStatus();
		bool UpdateUser();

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