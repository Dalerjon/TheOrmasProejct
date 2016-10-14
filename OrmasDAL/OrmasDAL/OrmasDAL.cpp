/// <summary> Datebase Access Layer </summary>
///
/// <remarks>
/// Developers: Daler Muhamedov
/// 
/// Copyright (c) 2016 Maintech company. All rights reserved.
/// </remarks>

#include "stdafx.h"
#include "OrmasDAL.h"

namespace DataLayer{

	OrmasDal::OrmasDal(ConnectionString conn, PGconn *dbCon)
	{
		this->connString = conn;
		this->dbCon = dbCon;
	}
	OrmasDal::OrmasDal()
	{
		
	}
	OrmasDal::~OrmasDal()
	{
		
	}

	PGconn* OrmasDal::GetConnection()
	{
		dbCon = PQconnectdb(connString.GetConString().c_str());
		if (PQstatus(dbCon) != CONNECTION_OK)
		{
			printf("Connection to database failed");
			PQfinish(dbCon);
			throw;
		}
		return dbCon;
	}
	
	void OrmasDal::InitFromConfigFile(std::string path)
	{
		connString.InitFromConfigFile(path);
	}

	void OrmasDal::SetDBParams(std::string dbname, std::string username, std::string password, std::string host, int port)
	{
		connString.SetDBParams(dbname, username, password, host, port);
	}	

// Get all companies from DB
	std::vector<companiesCollection> OrmasDal::GetCompanies(PGconn *connection, std::string filter)
	{
		if (PQstatus(connection) == CONNECTION_BAD)
			throw;
		companiesCollection rowTuple;
		std::vector<companiesCollection> resultVector;
		PGresult * result;
		result = PQexec(connection, "SELECT * FROM \"OrmasSchema\".companies_view" + *filter.c_str());
		
		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				for (int i = 0; i < PQntuples(result); i++)
				{
					int companyID = std::stoi(PQgetvalue(result, i, 0) == "" ? throw : PQgetvalue(result, i, 0));
					std::string companyName = PQgetvalue(result, i, 1);
					std::string companyAddress = PQgetvalue(result, i, 2);
					std::string companyPhone = PQgetvalue(result, i, 3);
					std::string comment = PQgetvalue(result, i, 4);
					rowTuple = std::make_tuple(companyID, companyName, companyAddress, companyPhone, comment);
					resultVector.push_back(rowTuple);
				}
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				return resultVector;
			}
		}
		else
		{
			//std::string temp = PQresultErrorMessage(result);
			throw;
		}
	}

//Get all currencies
	std::vector<currenciesCollection> OrmasDal::GetCurrencies(PGconn *connection, std::string filter)
	{
		if (PQstatus(connection) == CONNECTION_BAD)
			throw;
		currenciesCollection rowTuple;
		std::vector<currenciesCollection> resultVector;
		PGresult * result;
		result = PQexec(connection, "SELECT * FROM \"OrmasSchema\".currencies_view" + *filter.c_str());

		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				for (int i = 0; i < PQntuples(result); i++)
				{
					int currencyID = std::stoi(PQgetvalue(result, i, 0) == "" ? throw : PQgetvalue(result, i, 0));
					int currencyCode = std::stoi(PQgetvalue(result, i, 1) == "" ? throw : PQgetvalue(result, i, 1));
					std::string currencyShortName = PQgetvalue(result, i, 2);
					std::string currencyName = PQgetvalue(result, i, 3);
					rowTuple = std::make_tuple(currencyID, currencyCode, currencyShortName, currencyName);
					resultVector.push_back(rowTuple);
				}
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				return resultVector;
			}
		}
		else
		{
			//std::string temp = PQresultErrorMessage(result);
			throw;
		}
	}
// Get measures
	std::vector<measuresCollection> OrmasDal::GetMeasures(PGconn *connection, std::string filter)
	{
		if (PQstatus(connection) == CONNECTION_BAD)
			throw;
		measuresCollection rowTuple;
		std::vector<measuresCollection> resultVector;
		PGresult * result;
		result = PQexec(connection, "SELECT * FROM \"OrmasSchema\".measures_view" + *filter.c_str());

		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				for (int i = 0; i < PQntuples(result); i++)
				{
					int measureID = std::stoi(PQgetvalue(result, i, 0) == "" ? throw : PQgetvalue(result, i, 0));
					std::string measureName = PQgetvalue(result, i, 1);
					std::string measureShortName = PQgetvalue(result, i, 2);
					rowTuple = std::make_tuple(measureID, measureName, measureShortName);
					resultVector.push_back(rowTuple);
				}
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				return resultVector;
			}
		}
		else
		{
			//std::string temp = PQresultErrorMessage(result);
			throw;
		}
	}
//Get orders
	std::vector<ordersCollection> OrmasDal::GetOrders(PGconn *connection, std::string filter)
	{
		if (PQstatus(connection) == CONNECTION_BAD)
			throw;
		ordersCollection rowTuple;
		std::vector<ordersCollection> resultVector;
		PGresult * result;
		result = PQexec(connection, "SELECT * FROM \"OrmasSchema\".orders_view" + *filter.c_str());

		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				for (int i = 0; i < PQntuples(result); i++)
				{
					int orderID = std::stoi(PQgetvalue(result, i, 0) == "" ? throw : PQgetvalue(result, i, 0));
					int userID = std::stoi(PQgetvalue(result, i, 1) == "" ? throw : PQgetvalue(result, i, 1));
					std::string orderDate = PQgetvalue(result, i, 2);
					int workerID = std::stoi(PQgetvalue(result, i, 3) == "" ? throw : PQgetvalue(result, i, 3));
					std::string firmName = PQgetvalue(result, i, 4);
					rowTuple = std::make_tuple(orderID, userID, orderDate, workerID, firmName);
					resultVector.push_back(rowTuple);
				}
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				return resultVector;
			}
		}
		else
		{
			//std::string temp = PQresultErrorMessage(result);
			throw;
		}
	}
// Get product list 
	std::vector<productListCollection> OrmasDal::GetProductList(PGconn *connection, std::string filter)
	{
		if (PQstatus(connection) == CONNECTION_BAD)
			throw;
		productListCollection rowTuple;
		std::vector<productListCollection> resultVector;
		PGresult * result;
		result = PQexec(connection, "SELECT * FROM \"OrmasSchema\".product_lists_view" + *filter.c_str());

		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				for (int i = 0; i < PQntuples(result); i++)
				{
					int productListID = std::stoi(PQgetvalue(result, i, 0) == "" ? throw : PQgetvalue(result, i, 0));
					int orderID = std::stoi(PQgetvalue(result, i, 1) == "" ? throw : PQgetvalue(result, i, 1));
					int returnID = std::stoi(PQgetvalue(result, i, 2) == "" ? throw : PQgetvalue(result, i, 2));
					int productID = std::stoi(PQgetvalue(result, i, 3) == "" ? throw : PQgetvalue(result, i, 3));
					int countID = std::stoi(PQgetvalue(result, i, 4) == "" ? throw : PQgetvalue(result, i, 4));
					rowTuple = std::make_tuple(productListID, orderID, returnID, productID, countID);
					resultVector.push_back(rowTuple);
				}
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				return resultVector;
			}
		}
		else
		{
			//std::string temp = PQresultErrorMessage(result);
			throw;
		}
	}
// Get product type
	std::vector<productTypeCollection> OrmasDal::GetProductType(PGconn *connection, std::string filter)
	{
		if (PQstatus(connection) == CONNECTION_BAD)
			throw;
		productTypeCollection rowTuple;
		std::vector<productTypeCollection> resultVector;
		PGresult * result;
		result = PQexec(connection, "SELECT * FROM \"OrmasSchema\".product_types_view" + *filter.c_str());

		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				for (int i = 0; i < PQntuples(result); i++)
				{
					int productTypeID = std::stoi(PQgetvalue(result, i, 0) == "" ? throw : PQgetvalue(result, i, 0));
					std::string productTypeName = PQgetvalue(result, i, 1);
					std::string productTypeShortName = PQgetvalue(result, i, 2);
					rowTuple = std::make_tuple(productTypeID, productTypeName, productTypeShortName);
					resultVector.push_back(rowTuple);
				}
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				return resultVector;
			}
		}
		else
		{
			//std::string temp = PQresultErrorMessage(result);
			throw;
		}
	}
// get products
	std::vector<productsCollection> OrmasDal::GetProducts(PGconn *connection, std::string filter)
	{
		if (PQstatus(connection) == CONNECTION_BAD)
			throw;
		productsCollection rowTuple;
		std::vector<productsCollection> resultVector;
		PGresult * result;
		result = PQexec(connection, "SELECT * FROM \"OrmasSchema\".products_view" + *filter.c_str());

		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				for (int i = 0; i < PQntuples(result); i++)
				{
					int productID = std::stoi(PQgetvalue(result, i, 0) == "" ? throw : PQgetvalue(result, i, 0));
					int companyID = std::stoi(PQgetvalue(result, i, 1) == "" ? throw : PQgetvalue(result, i, 1));
					std::string productName = PQgetvalue(result, i, 2);
					float volume = std::stof(PQgetvalue(result, i, 3) == "" ? throw : PQgetvalue(result, i, 3));
					int measureID = std::stoi(PQgetvalue(result, i, 4) == "" ? throw : PQgetvalue(result, i, 4));
					float price = std::stof(PQgetvalue(result, i, 5) == "" ? throw : PQgetvalue(result, i, 5));
					int productTypeID = std::stoi(PQgetvalue(result, i, 6) == "" ? throw : PQgetvalue(result, i, 6));
					std::string dateProduce = PQgetvalue(result, i, 7);
					std::string dateEnd = PQgetvalue(result, i, 8);
					rowTuple = std::make_tuple(productID, companyID, productName, volume, measureID, price, productTypeID, dateProduce, dateEnd);
					resultVector.push_back(rowTuple);
				}
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				return resultVector;
			}
		}
		else
		{
			//std::string temp = PQresultErrorMessage(result);
			throw;
		}
	}
//Get regions
	std::vector<regionsCollection> OrmasDal::GetRegions(PGconn *connection, std::string filter)
	{
		if (PQstatus(connection) == CONNECTION_BAD)
			throw;
		regionsCollection rowTuple;
		std::vector<regionsCollection> resultVector;
		PGresult * result;
		result = PQexec(connection, "SELECT * FROM \"OrmasSchema\".regions_view" + *filter.c_str());

		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				for (int i = 0; i < PQntuples(result); i++)
				{
					int regionID = std::stoi(PQgetvalue(result, i, 0) == "" ? throw : PQgetvalue(result, i, 0));
					std::string regionCode = PQgetvalue(result, i, 1);
					std::string regionName = PQgetvalue(result, i, 2);
					rowTuple = std::make_tuple(regionID, regionCode, regionName);
					resultVector.push_back(rowTuple);
				}
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				return resultVector;
			}
		}
		else
		{
			//std::string temp = PQresultErrorMessage(result);
			throw;
		}
	}
// Get returns 
	std::vector<returnsCollection> OrmasDal::GetReturns(PGconn *connection, std::string filter)
	{
		if (PQstatus(connection) == CONNECTION_BAD)
			throw;
		returnsCollection rowTuple;
		std::vector<returnsCollection> resultVector;
		PGresult * result;
		result = PQexec(connection, "SELECT * FROM \"OrmasSchema\".returns_view" + *filter.c_str());

		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				for (int i = 0; i < PQntuples(result); i++)
				{
					int returnID = std::stoi(PQgetvalue(result, i, 0) == "" ? throw : PQgetvalue(result, i, 0));
					int userID = std::stoi(PQgetvalue(result, i, 1) == "" ? throw : PQgetvalue(result, i, 1));
					std::string returnDate = PQgetvalue(result, i, 2);
					int workerID = std::stoi(PQgetvalue(result, i, 3) == "" ? throw : PQgetvalue(result, i, 3));
					std::string firmName = PQgetvalue(result, i, 4);
					rowTuple = std::make_tuple(returnID, userID, returnDate, workerID, firmName);
					resultVector.push_back(rowTuple);
				}
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				return resultVector;
			}
		}
		else
		{
			//std::string temp = PQresultErrorMessage(result);
			throw;
		}
	}
// Get roles
	std::vector<rolesCollection> OrmasDal::GetRoles(PGconn *connection, std::string filter)
	{
		if (PQstatus(connection) == CONNECTION_BAD)
			throw;
		rolesCollection rowTuple;
		std::vector<rolesCollection> resultVector;
		PGresult * result;
		result = PQexec(connection, "SELECT * FROM \"OrmasSchema\".roles_view" + *filter.c_str());

		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				for (int i = 0; i < PQntuples(result); i++)
				{
					int roleID = std::stoi(PQgetvalue(result, i, 0) == "" ? throw : PQgetvalue(result, i, 0));
					std::string roleName = PQgetvalue(result, i, 1);
					std::string comment = PQgetvalue(result, i, 2);
					rowTuple = std::make_tuple(roleID, roleName, comment);
					resultVector.push_back(rowTuple);
				}
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				return resultVector;
			}
		}
		else
		{
			//std::string temp = PQresultErrorMessage(result);
			throw;
		}
	}
// Get status
	std::vector<statusCollection> OrmasDal::GetStatus(PGconn *connection, std::string filter)
	{
		if (PQstatus(connection) == CONNECTION_BAD)
			throw;
		statusCollection rowTuple;
		std::vector<statusCollection> resultVector;
		PGresult * result;
		result = PQexec(connection, "SELECT * FROM \"OrmasSchema\".status_view" + *filter.c_str());

		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				for (int i = 0; i < PQntuples(result); i++)
				{
					int statusID = std::stoi(PQgetvalue(result, i, 0) == "" ? throw : PQgetvalue(result, i, 0));
					std::string statusCode = PQgetvalue(result, i, 1);
					std::string statusName = PQgetvalue(result, i, 2);
					std::string comment = PQgetvalue(result, i, 3);
					rowTuple = std::make_tuple(statusID, statusCode, statusName, comment);
					resultVector.push_back(rowTuple);
				}
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				return resultVector;
			}
		}
		else
		{
			//std::string temp = PQresultErrorMessage(result);
			throw;
		}
	}
// Get user
	std::vector<usersCollection> OrmasDal::GetUsers(PGconn *connection, std::string filter)
	{
		if (PQstatus(connection) == CONNECTION_BAD)
			throw;
		usersCollection rowTuple;
		std::vector<usersCollection> resultVector;
		PGresult * result;
		result = PQexec(connection, "SELECT * FROM \"OrmasSchema\".users_view" + *filter.c_str());

		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				for (int i = 0; i < PQntuples(result); i++)
				{
					int userID = std::stoi(PQgetvalue(result, i, 0) == "" ? throw : PQgetvalue(result, i, 0));
					std::string userName = PQgetvalue(result, i, 1);
					std::string userPhone = PQgetvalue(result, i, 2);
					std::string userAddress = PQgetvalue(result, i, 4);
					std::string firm = PQgetvalue(result, i, 5);
					std::string firmNumber = PQgetvalue(result, i, 6);
					int roleID = std::stoi(PQgetvalue(result, i, 7) == "" ? throw : PQgetvalue(result, i, 7));
					int regionID = std::stoi(PQgetvalue(result, i, 8) == "" ? throw : PQgetvalue(result, i, 8));
					std::string password = PQgetvalue(result, i, 9);
					rowTuple = std::make_tuple(userID, userName, userPhone, userAddress, firm, firmNumber, roleID, regionID, password);
					resultVector.push_back(rowTuple);
				}
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				return resultVector;
			}
		}
		else
		{
			//std::string temp = PQresultErrorMessage(result);
			throw;
		}
	}
}