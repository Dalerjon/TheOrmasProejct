/// <summary> Datebase Access Layer </summary>
///
/// <remarks>
/// Developers: Daler Muhamedov
/// 
/// Copyright (c) 2016 Maintech company. All rights reserved.
/// </remarks>

#include "stdafx.h"
#include "OrmasDAL.h"
#include <boost/lexical_cast.hpp> 

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
		if (PQstatus(dbCon) != CONNECTION_OK)
		{
			printf("Connection to database failed");
			PQfinish(dbCon);
			throw;
		}
		return dbCon;
	}

	bool OrmasDal::ConnectToDB(std::string dbname, std::string username, std::string password, std::string host, int port)
	{
		SetDBParams(dbname, username, password, host, port);
		dbCon = PQconnectdb(connString.GetConString().c_str());
		if (PQstatus(dbCon) != CONNECTION_OK)
		{
			PQfinish(dbCon);
			return false;
		}
		return true;
	}

	void OrmasDal::InitFromConfigFile(std::string path)
	{
		connString.InitFromConfigFile(path);
	}

	void OrmasDal::SetDBParams(std::string dbname, std::string username, std::string password, std::string host, int port)
	{
		connString.SetDBParams(dbname, username, password, host, port);
	}

	int OrmasDal::GenerateID()
	{
		int id = 0;
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		result = PQexec(dbCon, "SELECT nextval('\"OrmasSchema\".id_seq');");
		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				id = std::stoi(PQgetvalue(result, 0, 0) == "" ? throw : PQgetvalue(result, 0, 0));
				PQclear(result);
				return id;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an 0 as id;
				PQclear(result);
				return id;
			}
		}
		else
		{
			PQclear(result);
			throw;
		}
		return id;
	}

	// View section --------------------------------------------------------------------------------------
	// Get all companies from DB
	std::vector<companiesCollection> OrmasDal::GetCompanies(std::string filter)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		companiesCollection rowTuple;
		std::vector<companiesCollection> resultVector;
		PGresult* result;
		std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".companies_view";
		sqlCommand += filter;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

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
				PQclear(result);
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				PQclear(result);
				return resultVector;
			}
		}
		else
		{
			PQclear(result);
			throw;
		}
	}

	//Get all currencies
	std::vector<currenciesCollection> OrmasDal::GetCurrencies(std::string filter)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		currenciesCollection rowTuple;
		std::vector<currenciesCollection> resultVector;
		PGresult * result;
		std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".currencies_view";
		sqlCommand += filter;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

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
				PQclear(result);
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				PQclear(result);
				return resultVector;
			}
		}
		else
		{
			PQclear(result);
			throw;
		}
	}
	// Get measures
	std::vector<measuresCollection> OrmasDal::GetMeasures(std::string filter)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		measuresCollection rowTuple;
		std::vector<measuresCollection> resultVector;
		PGresult * result;
		std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".measures_view";
		sqlCommand += filter;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
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
				PQclear(result);
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				PQclear(result);
				return resultVector;
			}
		}
		else
		{
			PQclear(result);
			throw;
		}
	}
	//Get orders
	std::vector<ordersCollection> OrmasDal::GetOrders(std::string filter)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		ordersCollection rowTuple;
		std::vector<ordersCollection> resultVector;
		PGresult * result;
		std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".orders_view";
		sqlCommand += filter;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

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
				PQclear(result);
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				PQclear(result);
				return resultVector;
			}
		}
		else
		{
			PQclear(result);
			throw;
		}
	}
	// Get product list 
	std::vector<productListCollection> OrmasDal::GetProductLists(std::string filter)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		productListCollection rowTuple;
		std::vector<productListCollection> resultVector;
		PGresult * result;
		std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".product_lists_view";
		sqlCommand += filter;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

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
				PQclear(result);
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				PQclear(result);
				return resultVector;
			}
		}
		else
		{
			PQclear(result);
			throw;
		}
	}
	// Get product type
	std::vector<productTypeCollection> OrmasDal::GetProductTypes(std::string filter)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		productTypeCollection rowTuple;
		std::vector<productTypeCollection> resultVector;
		PGresult * result;
		std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".product_types_view";
		sqlCommand += filter;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

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
				PQclear(result);
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				PQclear(result);
				return resultVector;
			}
		}
		else
		{
			PQclear(result);
			throw;
		}
	}
	// get products
	std::vector<productsCollection> OrmasDal::GetProducts(std::string filter)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		productsCollection rowTuple;
		std::vector<productsCollection> resultVector;
		PGresult * result;
		std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".products_view";
		sqlCommand += filter;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		

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
				PQclear(result);
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				PQclear(result);
				return resultVector;
			}
		}
		else
		{
			PQclear(result);
			throw;
		}
	}
	//Get regions
	std::vector<regionsCollection> OrmasDal::GetRegions(std::string filter)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		regionsCollection rowTuple;
		std::vector<regionsCollection> resultVector;
		PGresult * result;
		std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".regions_view";
		sqlCommand += filter;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

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
				PQclear(result);
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				PQclear(result);
				return resultVector;
			}
		}
		else
		{
			PQclear(result);
			throw;
		}
	}
	// Get returns 
	std::vector<returnsCollection> OrmasDal::GetReturns(std::string filter)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		returnsCollection rowTuple;
		std::vector<returnsCollection> resultVector;
		PGresult * result;
		std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".returns_view";
		sqlCommand += filter;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
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
				PQclear(result);
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				PQclear(result);
				return resultVector;
			}
		}
		else
		{
			PQclear(result);
			throw;
		}
	}
	// Get roles
	std::vector<rolesCollection> OrmasDal::GetRoles(std::string filter)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		rolesCollection rowTuple;
		std::vector<rolesCollection> resultVector;
		PGresult * result;
		std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".roles_view";
		sqlCommand += filter;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
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
				PQclear(result);
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				PQclear(result);
				return resultVector;
			}
		}
		else
		{
			PQclear(result);
			throw;
		}
	}
	// Get status
	std::vector<statusCollection> OrmasDal::GetStatus(std::string filter)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		statusCollection rowTuple;
		std::vector<statusCollection> resultVector;
		PGresult * result;
		std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".status_view";
		sqlCommand += filter;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

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
				PQclear(result);
				return resultVector;
			}
			else
			{
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				PQclear(result);
				return resultVector;
			}
		}
		else
		{
			PQclear(result);
			throw;
		}
	}
	// Get user
	std::vector<usersCollection> OrmasDal::GetUsers(std::string filter)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		usersCollection rowTuple;
		std::vector<usersCollection> resultVector;
		PGresult * result;
		std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".users_view";
		sqlCommand += filter;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
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
				PQclear(result);
				return resultVector;
			}
			else
			{
				PQclear(result);
				// if result of query does not contain information and have 0 row, then function return an empty vector;
				return resultVector;
			}
		}
		else
		{
			PQclear(result);
			throw;
		}
	}

	// Create section----------------------------------------------------------------
	// Create company
	bool OrmasDal::CreateCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".companies(company_id, company_name, company_address, company_phone,\
			comment) VALUES(";
		sqlCommand += cID;
		sqlCommand += ", ";
		sqlCommand += cName;
		sqlCommand += ", ";
		sqlCommand += cAddress;
		sqlCommand += ", ";
		sqlCommand += cPhone;
		sqlCommand += ", ";
		sqlCommand += cComment;
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateCurrency(int cID, int cCode, std::string cShortName, std::string cName)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".currencies(currency_id, currency_code, currency_short_name, \
								  currency_name) VALUES(";
		sqlCommand += cID;
		sqlCommand += ", ";
		sqlCommand += cCode;
		sqlCommand += ", ";
		sqlCommand += cShortName;
		sqlCommand += ", ";
		sqlCommand += cName;
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateMeasure(int mID, std::string mName, std::string mShortName)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".measures(measure_id, measure_name, measure_short_name) VALUES(";
		sqlCommand += mID;
		sqlCommand += ", ";
		sqlCommand += mName;
		sqlCommand += ", ";
		sqlCommand += mShortName;
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateOrder(int oID, int uID, std::string oDate, int wID, std::string fName)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".orders(order_id, user_id, order_date, worker_id, firm_name) VALUES(";
		sqlCommand += oID;
		sqlCommand += ", ";
		sqlCommand += uID;
		sqlCommand += ", ";
		sqlCommand += oDate;
		sqlCommand += ", ";
		sqlCommand += wID;
		sqlCommand += ", ";
		sqlCommand += fName;
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateProductList(int pListID, int oID, int rID, int pID, int count)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".product_list(product_list_id, order_id, return_id, \
								  product_id, count) VALUES(";
		sqlCommand += pListID;
		sqlCommand += ", ";
		sqlCommand += oID;
		sqlCommand += ", ";
		sqlCommand += rID;
		sqlCommand += ", ";
		sqlCommand += pID;
		sqlCommand += ", ";
		sqlCommand += count;
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".product_type(product_type_id, product_type_name,\
								  product_type_short_name) VALUES(";
		sqlCommand += pTypeID;
		sqlCommand += ", ";
		sqlCommand += pTypeName;
		sqlCommand += ", ";
		sqlCommand += pTypeShortName;
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateProduct(int pID, int cID, std::string pName, float vol, int mID, float price, int pTypeID,
		std::string dProduce, std::string dEnd)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".products(product_id, company_id, product_name, volume, measure_id\
								 price, product_type_id, date_produce, date_end) VALUES(";
		sqlCommand += pID;
		sqlCommand += ", ";
		sqlCommand += cID;
		sqlCommand += ", ";
		sqlCommand += pName;
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(vol);
		sqlCommand += ", ";
		sqlCommand += mID;
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(price);
		sqlCommand += ", ";
		sqlCommand += pTypeID;
		sqlCommand += ", ";
		sqlCommand += dProduce;
		sqlCommand += ", ";
		sqlCommand += dEnd;
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateRegion(int rID, std::string rCode, std::string rName)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".regions(region_id, region_code, region_name) VALUES(";
		sqlCommand += rID;
		sqlCommand += ", ";
		sqlCommand += rCode;
		sqlCommand += ", ";
		sqlCommand += rName;
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateReturn(int rID, int uID, std::string rDate, int wID, std::string fName)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".returns(return_id, user_id, order_date, worker_id, firm_name) VALUES(";
		sqlCommand += rID;
		sqlCommand += ", ";
		sqlCommand += uID;
		sqlCommand += ", ";
		sqlCommand += rDate;
		sqlCommand += ", ";
		sqlCommand += wID;
		sqlCommand += ", ";
		sqlCommand += fName;
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateRole(int rID, std::string rName, std::string rComment)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".roles(role_id, role_name, comment) VALUES(";
		sqlCommand += rID;
		sqlCommand += ", ";
		sqlCommand += rName;
		sqlCommand += ", ";
		sqlCommand += rComment;
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateStatus(int sID, std::string sCode, std::string sName, std::string sComment)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".status(status_id, status_code, status_name, comment) VALUES(";
		sqlCommand += sID;
		sqlCommand += ", ";
		sqlCommand += sCode;
		sqlCommand += ", ";
		sqlCommand += sName;
		sqlCommand += ", ";
		sqlCommand += sComment;
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateUser(int uID, std::string uName, std::string uPhone, std::string uAddress, std::string firm,
		std::string firmNumber,	int uRoleID, int uRegionID, std::string uPassword)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".users(user_id, user_name, user_phone, user_addres, firm, firm_number, \
								 role_id, region_id, password) VALUES(";
		sqlCommand += uID;
		sqlCommand += ", ";
		sqlCommand += uName;
		sqlCommand += ", ";
		sqlCommand += uPhone;
		sqlCommand += ", ";
		sqlCommand += uAddress;
		sqlCommand += ", ";
		sqlCommand += firm;
		sqlCommand += ", ";
		sqlCommand += firmNumber;
		sqlCommand += ", ";
		sqlCommand += uRoleID;
		sqlCommand += ", ";
		sqlCommand += uRegionID;
		sqlCommand += ", ";
		sqlCommand += uPassword;
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	// Delete section----------------------------------------------------------------
	// Delete company
	bool OrmasDal::DeleteCompany(int id)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".companies where company_id=";
		sqlCommand += id;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			PQclear(result);
			return false;
		}
	}
	// Delete currency
	bool OrmasDal::DeleteCurrency(int id)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".currencies where currency_id=";
		sqlCommand += id;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			PQclear(result);
			return false;
		}
	}
	// Delete measure
	bool OrmasDal::DeleteMeasure(int id)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".measures where measure_id=";
		sqlCommand += id;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			PQclear(result);
			return false;
		}
	}
	// Delete order
	bool OrmasDal::DeleteOrder(int id)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		
		//start transaction
		std::string sqlCommand = "BEGIN;";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);

		//cascading detele
		sqlCommand = "DELETE FROM \"OrmasSchema\".product_list where order_id=";
		sqlCommand += id;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		
		sqlCommand = "DELETE FROM \"OrmasSchema\".orders where order_id=";
		sqlCommand += id;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);

		//Commit changes
		sqlCommand = "Commit;";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	// Delete product list
	bool OrmasDal::DeleteProductList(int id)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".product_list where product_list_id=";
		sqlCommand += id;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			PQclear(result);
			return false;
		}
	}
	// Delete product type
	bool OrmasDal::DeleteProductType(int id)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".product_type where product_type_id=";
		sqlCommand += id;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			PQclear(result);
			return false;
		}
	}
	// Delete product
	bool OrmasDal::DeleteProduct(int id)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".products where product_id=";
		sqlCommand += id;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			PQclear(result);
			return false;
		}
	}
	// Delete region
	bool OrmasDal::DeleteRegion(int id)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".regions where region_id=";
		sqlCommand += id;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			PQclear(result);
			return false;
		}
	}
	// Delete return
	bool OrmasDal::DeleteReturn(int id)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;

		//start transaction
		std::string sqlCommand = "BEGIN;";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);

		//cascading detele
		sqlCommand = "DELETE FROM \"OrmasSchema\".product_list where return_id=";
		sqlCommand += id;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);

		sqlCommand = "DELETE FROM \"OrmasSchema\".returns where return_id=";
		sqlCommand += id;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);

		//Commit changes
		sqlCommand = "Commit;";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	// Delete role
	bool OrmasDal::DeleteRole(int id)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".roles where role_id=";
		sqlCommand += id;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			PQclear(result);
			return false;
		}
	}
	// Delete status
	bool OrmasDal::DeleteStatus(int id)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".status where status_id=";
		sqlCommand += id;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			PQclear(result);
			return false;
		}
	}
	// Delete user
	bool OrmasDal::DeleteUser(int id)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".users where user_id=";
		sqlCommand += id;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			PQclear(result);
			return false;
		}
	}
	// Update section----------------------------------------------------------------
	// Update company
	bool OrmasDal::UpdateCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".companies SET(company_name, company_address, company_phone,\
			comment) = (";
		sqlCommand += cName;
		sqlCommand += ", ";
		sqlCommand += cAddress;
		sqlCommand += ", ";
		sqlCommand += cPhone;
		sqlCommand += ", ";
		sqlCommand += cComment;
		sqlCommand += ") WHERE company_id=";
		sqlCommand += cID;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateCurrency(int cID, int cCode, std::string cShortName, std::string cName)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".currencies SET(currency_code, currency_short_name, \
								  currency_name) = (";
		sqlCommand += cCode;
		sqlCommand += ", ";
		sqlCommand += cShortName;
		sqlCommand += ", ";
		sqlCommand += cName;
		sqlCommand += ") WHERE currency_id=";
		sqlCommand += cID;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateMeasure(int mID, std::string mName, std::string mShortName)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".measures SET(measure_id, measure_name, measure_short_name) = (";
		sqlCommand += mName;
		sqlCommand += ", ";
		sqlCommand += mShortName;
		sqlCommand += ") WHERE measure_id=";
		sqlCommand += mID;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateOrder(int oID, int uID, std::string oDate, int wID, std::string fName)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".orders SET(order_id, user_id, order_date, worker_id, firm_name) = (";
		sqlCommand += uID;
		sqlCommand += ", ";
		sqlCommand += oDate;
		sqlCommand += ", ";
		sqlCommand += wID;
		sqlCommand += ", ";
		sqlCommand += fName;
		sqlCommand += ") WHERE order_id=";
		sqlCommand += oID;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateProductList(int pListID, int oID, int rID, int pID, int count)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".product_list SET(product_list_id, order_id, return_id, \
								  product_id, count) = (";
		sqlCommand += oID;
		sqlCommand += ", ";
		sqlCommand += rID;
		sqlCommand += ", ";
		sqlCommand += pID;
		sqlCommand += ", ";
		sqlCommand += count;
		sqlCommand += ") WHERE product_list_id=";
		sqlCommand += pListID;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".product_type SET(product_type_id, product_type_name,\
								  product_type_short_name) = (";
		sqlCommand += pTypeName;
		sqlCommand += ", ";
		sqlCommand += pTypeShortName;
		sqlCommand += ") WHERE product_type_id=";
		sqlCommand += pTypeID;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateProduct(int pID, int cID, std::string pName, float vol, int mID, float price, int pTypeID,
		std::string dProduce, std::string dEnd)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".products SET(product_id, company_id, product_name, volume, measure_id\
								 price, product_type_id, date_produce, date_end) = (";
		sqlCommand += cID;
		sqlCommand += ", ";
		sqlCommand += pName;
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(vol);
		sqlCommand += ", ";
		sqlCommand += mID;
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(price);
		sqlCommand += ", ";
		sqlCommand += pTypeID;
		sqlCommand += ", ";
		sqlCommand += dProduce;
		sqlCommand += ", ";
		sqlCommand += dEnd;
		sqlCommand += ") WHERE product_id=";
		sqlCommand += pID;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateRegion(int rID, std::string rCode, std::string rName)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".regions SET(region_id, region_code, region_name) = (";
		sqlCommand += rCode;
		sqlCommand += ", ";
		sqlCommand += rName;
		sqlCommand += ") WHERE region_id=";
		sqlCommand += rID;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateReturn(int rID, int uID, std::string rDate, int wID, std::string fName)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".returns SET(return_id, user_id, order_date, worker_id, firm_name) = (";
		sqlCommand += uID;
		sqlCommand += ", ";
		sqlCommand += rDate;
		sqlCommand += ", ";
		sqlCommand += wID;
		sqlCommand += ", ";
		sqlCommand += fName;
		sqlCommand += ") WHERE return_id=";
		sqlCommand += rID;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateRole(int rID, std::string rName, std::string rComment)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".roles SET(role_id, role_name, comment) = (";
		sqlCommand += rName;
		sqlCommand += ", ";
		sqlCommand += rComment;
		sqlCommand += ") WHERE role_id=";
		sqlCommand += rID;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateStatus(int sID, std::string sCode, std::string sName, std::string sComment)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".status SET(status_id, status_code, status_name, comment) = (";
		sqlCommand += sCode;
		sqlCommand += ", ";
		sqlCommand += sName;
		sqlCommand += ", ";
		sqlCommand += sComment;
		sqlCommand += ") WHERE status_id=";
		sqlCommand += sID;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateUser(int uID, std::string uName, std::string uPhone, std::string uAddress, 
		std::string firm, std::string firmNumber, int uRoleID, int uRegionID, std::string uPassword)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
			throw;
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".users SET(user_id, user_name, user_phone, user_addres, firm, firm_number, \
								 role_id, region_id, password) = (";
		sqlCommand += uName;
		sqlCommand += ", ";
		sqlCommand += uPhone;
		sqlCommand += ", ";
		sqlCommand += uAddress;
		sqlCommand += ", ";
		sqlCommand += firm;
		sqlCommand += ", ";
		sqlCommand += firmNumber;
		sqlCommand += ", ";
		sqlCommand += uRoleID;
		sqlCommand += ", ";
		sqlCommand += uRegionID;
		sqlCommand += ", ";
		sqlCommand += uPassword;
		sqlCommand += ") WHERE user_id=";
		sqlCommand += uID;
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
}