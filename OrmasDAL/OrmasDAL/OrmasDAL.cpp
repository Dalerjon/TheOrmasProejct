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
			PQfinish(dbCon);
			return nullptr;
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
			return id; // return id as 0, just use 0 for logical statements in your functions, for example for canceling some actions
		PGresult * result;
		result = PQexec(dbCon, "SELECT nextval('\"OrmasSchema\".id_seq');");
		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				id = std::stoi(PQgetvalue(result, 0, 0) == "" ? 0 : PQgetvalue(result, 0, 0));
				PQclear(result);
				return id;
			}
			PQclear(result);
			return id;
		}
		PQclear(result);
		return id;
	}
	//transaction functions
	bool OrmasDal::StartTransaction(std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;

		//start transaction
		std::string sqlCommand = "BEGIN;";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CommitTransaction(std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;

		//start transaction
		std::string sqlCommand = "COMMIT;";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CancelTransaction(std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;

		//start transaction
		std::string sqlCommand = "ROLLBACK;";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			return false;
		}
		PQclear(result);
		return true;
	}
	// View section --------------------------------------------------------------------------------------
	// Get all companies from DB
	std::vector<companiesCollection> OrmasDal::GetCompanies(std::string& errorMessage, std::string filter)
	{
		companiesCollection rowTuple;
		std::vector<companiesCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
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
						int companyID = std::stoi(PQgetvalue(result, i, 0) == "" ? 0 : PQgetvalue(result, i, 0));
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
				}
			}
			else
			{
				std::string logStr = PQresultErrorMessage(result);
				//WriteLog(logStr);
				PQclear(result);
				errorMessage = "Cannot get information from DB, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get all currencies
	std::vector<currenciesCollection> OrmasDal::GetCurrencies(std::string& errorMessage, std::string filter)
	{
		currenciesCollection rowTuple;
		std::vector<currenciesCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
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
						int currencyID = std::stoi(PQgetvalue(result, i, 0) == "" ? 0 : PQgetvalue(result, i, 0));
						int currencyCode = std::stoi(PQgetvalue(result, i, 1) == "" ? 0 : PQgetvalue(result, i, 1));
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
				}
			}
			else
			{
				std::string logStr = PQresultErrorMessage(result);
				//WriteLog(logStr);
				PQclear(result);
				errorMessage = "Cannot get information from DB, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	// Get measures
	std::vector<measuresCollection> OrmasDal::GetMeasures(std::string& errorMessage, std::string filter)
	{
		measuresCollection rowTuple;
		std::vector<measuresCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
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
						int measureID = std::stoi(PQgetvalue(result, i, 0) == "" ? 0 : PQgetvalue(result, i, 0));
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
				}
			}
			else
			{
				std::string logStr = PQresultErrorMessage(result);
				//WriteLog(logStr);
				PQclear(result);
				errorMessage = "Cannot get information from DB, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	//Get orders
	std::vector<ordersViewCollection> OrmasDal::GetOrders(std::string& errorMessage, std::string filter)
	{
		ordersViewCollection rowTuple;
		std::vector<ordersViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
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
						int orderID = std::stoi(PQgetvalue(result, i, 0) == "" ? 0 : PQgetvalue(result, i, 0));
						std::string orderDate = PQgetvalue(result, i, 1);
						std::string clientName = PQgetvalue(result, i, 2);
						std::string clientPhone = PQgetvalue(result, i, 3);
						std::string clientAddres = PQgetvalue(result, i, 4);
						std::string firm = PQgetvalue(result, i, 5);
						std::string workerName = PQgetvalue(result, i, 6);
						std::string workerPhone = PQgetvalue(result, i, 7);
						int workerID = std::stoi(PQgetvalue(result, i, 8) == "" ? 0 : PQgetvalue(result, i, 8));
						int userID = std::stoi(PQgetvalue(result, i, 9) == "" ? 0 : PQgetvalue(result, i, 9));
						rowTuple = std::make_tuple(orderID, orderDate, clientName, clientPhone, clientAddres, firm, workerName
							, workerPhone, workerID, userID);
						resultVector.push_back(rowTuple);
					}
					PQclear(result);
					return resultVector;
				}
				else
				{
					// if result of query does not contain information and have 0 row, then function return an empty vector;
					PQclear(result);
				}
			}
			else
			{
				std::string logStr = PQresultErrorMessage(result);
				//WriteLog(logStr);
				PQclear(result);
				errorMessage = "Cannot get information from DB, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	// Get product list 
	std::vector<productListCollection> OrmasDal::GetProductLists(std::string& errorMessage, std::string filter)
	{
		productListCollection rowTuple;
		std::vector<productListCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
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
						int productListID = std::stoi(PQgetvalue(result, i, 0) == "" ? 0 : PQgetvalue(result, i, 0));
						int orderID = std::stoi(PQgetvalue(result, i, 1) == "" ? 0 : PQgetvalue(result, i, 1));
						int returnID = std::stoi(PQgetvalue(result, i, 2) == "" ? 0 : PQgetvalue(result, i, 2));
						int productID = std::stoi(PQgetvalue(result, i, 3) == "" ? 0 : PQgetvalue(result, i, 3));
						int countID = std::stoi(PQgetvalue(result, i, 4) == "" ? 0 : PQgetvalue(result, i, 4));
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
				}
			}
			else
			{
				std::string logStr = PQresultErrorMessage(result);
				//WriteLog(logStr);
				PQclear(result);
				errorMessage = "Cannot get information from DB, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	// Get product type
	std::vector<productTypeCollection> OrmasDal::GetProductTypes(std::string& errorMessage, std::string filter)
	{
		productTypeCollection rowTuple;
		std::vector<productTypeCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
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
						int productTypeID = std::stoi(PQgetvalue(result, i, 0) == "" ? 0 : PQgetvalue(result, i, 0));
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
				}
			}
			else
			{
				std::string logStr = PQresultErrorMessage(result);
				//WriteLog(logStr);
				PQclear(result);
				errorMessage = "Cannot get information from DB, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	// get products
	std::vector<productsCollection> OrmasDal::GetProducts(std::string& errorMessage, std::string filter)
	{
		productsCollection rowTuple;
		std::vector<productsCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
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
						int productID = std::stoi(PQgetvalue(result, i, 0) == "" ? 0 : PQgetvalue(result, i, 0));
						int companyID = std::stoi(PQgetvalue(result, i, 1) == "" ? 0 : PQgetvalue(result, i, 1));
						std::string productName = PQgetvalue(result, i, 2);
						float volume = std::stof(PQgetvalue(result, i, 3) == "" ? 0 : PQgetvalue(result, i, 3));
						int measureID = std::stoi(PQgetvalue(result, i, 4) == "" ? 0 : PQgetvalue(result, i, 4));
						float price = std::stof(PQgetvalue(result, i, 5) == "" ? 0 : PQgetvalue(result, i, 5));
						int productTypeID = std::stoi(PQgetvalue(result, i, 6) == "" ? 0 : PQgetvalue(result, i, 6));
						int shelfLife = std::stoi(PQgetvalue(result, i, 7) == "" ? 0 : PQgetvalue(result, i, 7));
						rowTuple = std::make_tuple(productID, companyID, productName, volume, measureID, price, productTypeID, shelfLife);
						resultVector.push_back(rowTuple);
					}
					PQclear(result);
					return resultVector;
				}
				else
				{
					// if result of query does not contain information and have 0 row, then function return an empty vector;
					PQclear(result);
				}
			}
			else
			{
				std::string logStr = PQresultErrorMessage(result);
				//WriteLog(logStr);
				PQclear(result);
				errorMessage = "Cannot get information from DB, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	//Get Locations
	std::vector<locationsCollection> OrmasDal::GetLocations(std::string& errorMessage, std::string filter)
	{
		locationsCollection rowTuple;
		std::vector<locationsCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".locations_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int locationID = std::stoi(PQgetvalue(result, i, 0) == "" ? 0 : PQgetvalue(result, i, 0));
						std::string countryName = PQgetvalue(result, i, 1);
						std::string countryCode = PQgetvalue(result, i, 2);
						std::string regionName = PQgetvalue(result, i, 3);
						std::string cityName = PQgetvalue(result, i, 4);
						rowTuple = std::make_tuple(locationID, countryName, countryCode, regionName, cityName);
						resultVector.push_back(rowTuple);
					}
					PQclear(result);
					return resultVector;
				}
				else
				{
					// if result of query does not contain information and have 0 row, then function return an empty vector;
					PQclear(result);
				}
			}
			else
			{
				std::string logStr = PQresultErrorMessage(result);
				//WriteLog(logStr);
				PQclear(result);
				errorMessage = "Cannot get information from DB, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	// Get returns 
	std::vector<returnsViewCollection> OrmasDal::GetReturns(std::string& errorMessage, std::string filter)
	{
		returnsViewCollection rowTuple;
		std::vector<returnsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
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
						int returnID = std::stoi(PQgetvalue(result, i, 0) == "" ? 0 : PQgetvalue(result, i, 0));
						std::string orderDate = PQgetvalue(result, i, 1);
						std::string clientName = PQgetvalue(result, i, 2);
						std::string clientPhone = PQgetvalue(result, i, 3);
						std::string clientAddres = PQgetvalue(result, i, 4);
						std::string firm = PQgetvalue(result, i, 5);
						std::string workerName = PQgetvalue(result, i, 6);
						std::string workerPhone = PQgetvalue(result, i, 7);
						int workerID = std::stoi(PQgetvalue(result, i, 8) == "" ? 0 : PQgetvalue(result, i, 8));
						int userID = std::stoi(PQgetvalue(result, i, 9) == "" ? 0 : PQgetvalue(result, i, 9));
						rowTuple = std::make_tuple(returnID, orderDate, clientName, clientPhone, clientAddres, firm, workerName
							, workerPhone, workerID, userID);
						resultVector.push_back(rowTuple);
					}
					PQclear(result);
					return resultVector;
				}
				else
				{
					// if result of query does not contain information and have 0 row, then function return an empty vector;
					PQclear(result);
				}
			}
			else
			{
				std::string logStr = PQresultErrorMessage(result);
				//WriteLog(logStr);
				PQclear(result);
				errorMessage = "Cannot get information from DB, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	// Get roles
	std::vector<rolesCollection> OrmasDal::GetRoles(std::string& errorMessage, std::string filter)
	{
		rolesCollection rowTuple;
		std::vector<rolesCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
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
						int roleID = std::stoi(PQgetvalue(result, i, 0) == "" ? 0 : PQgetvalue(result, i, 0));
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
				}
			}
			else
			{
				std::string logStr = PQresultErrorMessage(result);
				//WriteLog(logStr);
				PQclear(result);
				errorMessage = "Cannot get information from DB, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	// Get status
	std::vector<statusCollection> OrmasDal::GetStatus(std::string& errorMessage, std::string filter)
	{
		statusCollection rowTuple;
		std::vector<statusCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
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
						int statusID = std::stoi(PQgetvalue(result, i, 0) == "" ? 0 : PQgetvalue(result, i, 0));
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
				}
			}
			else
			{
				std::string logStr = PQresultErrorMessage(result);
				//WriteLog(logStr);
				PQclear(result);
				errorMessage = "Cannot get information from DB, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	// Get user
	std::vector<usersCollection> OrmasDal::GetUsers(std::string& errorMessage, std::string filter)
	{
		usersCollection rowTuple;
		std::vector<usersCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
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
						int userID = std::stoi(PQgetvalue(result, i, 0) == "" ? 0 : PQgetvalue(result, i, 0));
						std::string userName = PQgetvalue(result, i, 1);
						std::string userPhone = PQgetvalue(result, i, 2);
						std::string userAddress = PQgetvalue(result, i, 4);
						std::string firm = PQgetvalue(result, i, 5);
						std::string firmNumber = PQgetvalue(result, i, 6);
						int roleID = std::stoi(PQgetvalue(result, i, 7) == "" ? 0 : PQgetvalue(result, i, 7));
						int locationID = std::stoi(PQgetvalue(result, i, 8) == "" ? 0 : PQgetvalue(result, i, 8));
						std::string password = PQgetvalue(result, i, 9);
						bool activated = boost::lexical_cast<bool>(PQgetvalue(result, i, 10));
						rowTuple = std::make_tuple(userID, userName, userPhone, userAddress, firm, firmNumber, roleID, locationID, password, activated);
						resultVector.push_back(rowTuple);
					}
					PQclear(result);
					return resultVector;
				}
				else
				{
					PQclear(result);
					// if result of query does not contain information and have 0 row, then function return an empty vector;
				}
			}
			else
			{
				std::string logStr = PQresultErrorMessage(result);
				//WriteLog(logStr);
				PQclear(result);
				errorMessage = "Cannot get information from DB, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Create section----------------------------------------------------------------
	// Create company
	bool OrmasDal::CreateCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment, 
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".companies(company_id, company_name, company_address, company_phone,\
			comment) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ", '";
		sqlCommand += cName;
		sqlCommand += "', '";
		sqlCommand += cAddress;
		sqlCommand += "', '";
		sqlCommand += cPhone;
		sqlCommand += "', '";
		sqlCommand += cComment;
		sqlCommand += "');";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the company creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateCurrency(int cID, int cCode, std::string cShortName, std::string cName, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".currencies(currency_id, currency_code, currency_short_name, \
								  currency_name) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cCode);
		sqlCommand += ", '";
		sqlCommand += cShortName;
		sqlCommand += "', '";
		sqlCommand += cName;
		sqlCommand += "');";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the curency creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateMeasure(int mID, std::string mName, std::string mShortName, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".measures(measure_id, measure_name, measure_short_name) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(mID);
		sqlCommand += ", '";
		sqlCommand += mName;
		sqlCommand += "', '";
		sqlCommand += mShortName;
		sqlCommand += "');";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the measure creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateOrder(int oID, int uID, std::string oDate, int wID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".orders(order_id, user_id, order_date, worker_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(oID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += oDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the order creation is failed, please contact with application provider!"; 
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateProductList(int pListID, int oID, int rID, int pID, int count, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".product_list(product_list_id, order_id, return_id, \
								  product_id, count) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(pListID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(count);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the product list creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".product_type(product_type_id, product_type_name,\
								  product_type_short_name) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(pTypeID);
		sqlCommand += ", '";
		sqlCommand += pTypeName;
		sqlCommand += "', '";
		sqlCommand += pTypeShortName;
		sqlCommand += "');";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the ptoduct type creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateProduct(int pID, int cID, std::string pName, float vol, int mID, float price, int pTypeID, int pShelfLife, 
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".products(product_id, company_id, product_name, volume, measure_id\
								 price, product_type_id, shelf_life) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ", '";
		sqlCommand += pName;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(vol);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(mID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(price);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pTypeID);
		sqlCommand += ",";
		sqlCommand += boost::lexical_cast<std::string>(pShelfLife);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the product creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateLocation(int rID, std::string lCountryName, std::string lCountryCode , std::string lRegionName,
			std::string lCityName, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".locations(location_id, country_name, country_code,\
								  region_name, city_name) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", '";
		sqlCommand += lCountryName;
		sqlCommand += "', '";
		sqlCommand += lCountryCode;
		sqlCommand += "', '";
		sqlCommand += lRegionName;
		sqlCommand += "', '";
		sqlCommand += lCityName;
		sqlCommand += "');";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the Location creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateReturn(int rID, int uID, std::string rDate, int wID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			errorMessage = "SQL command for creation company is failed, please contact with application provider!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".returns(return_id, user_id, order_date, worker_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += rDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the return creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateRole(int rID, std::string rName, std::string rComment, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".roles(role_id, role_name, comment) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", '";
		sqlCommand += rName;
		sqlCommand += "', '";
		sqlCommand += rComment;
		sqlCommand += "');";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the role creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateStatus(int sID, std::string sCode, std::string sName, std::string sComment, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".status(status_id, status_code, status_name, comment) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", '";
		sqlCommand += sCode;
		sqlCommand += "', '";
		sqlCommand += sName;
		sqlCommand += "', '";
		sqlCommand += sComment;
		sqlCommand += "');";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the status creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::CreateUser(int uID, std::string uName, std::string uPhone, std::string uAddress, std::string firm,
		std::string firmNumber, int uRoleID, int uLocationID, std::string uPassword, bool uActivated, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".users(user_id, user_name, user_phone, user_addres, firm, firm_number, \
								 role_id, location_id, password, activated) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += uName;
		sqlCommand += "', '";
		sqlCommand += uPhone;
		sqlCommand += "', '";
		sqlCommand += uAddress;
		sqlCommand += "', '";
		sqlCommand += firm;
		sqlCommand += "', '";
		sqlCommand += firmNumber;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(uRoleID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uLocationID);
		sqlCommand += ", '";
		sqlCommand += uPassword;
		sqlCommand += ", ";
		sqlCommand += uActivated;
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the user creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	// Delete section----------------------------------------------------------------
	// Delete company
	bool OrmasDal::DeleteCompany(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".companies where company_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);PQclear(result);
			errorMessage = "Could not delete company! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
	// Delete currency
	bool OrmasDal::DeleteCurrency(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".currencies where currency_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete currency! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
	// Delete measure
	bool OrmasDal::DeleteMeasure(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".measures where measure_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete measure! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
	// Delete order
	bool OrmasDal::DeleteOrder(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		//start transaction 
		if (!StartTransaction(errorMessage))
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}

		PGresult * result;
		//cascading detele
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".product_list where order_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			if (!CancelTransaction(errorMessage))
			{
				errorMessage = "DB connection was lost! Please restart application!";
				return false;
			}
			return false;
		}
		PQclear(result);
		
		sqlCommand = "DELETE FROM \"OrmasSchema\".orders where order_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			if (!CancelTransaction(errorMessage))
			{
				errorMessage = "DB connection was lost! Please restart application!";
			}
			errorMessage = "Could not delete order! SQL command is failed. Please contact with application provider!";
			return false;
		}
		PQclear(result);

		//Commit changes
		if (!CommitTransaction(errorMessage))
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		return true;
	}
	// Delete product list
	bool OrmasDal::DeleteProductList(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".product_list where product_list_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete product list! SQL command is failed. Please contact with application provider!";
			return false;			
		}
	}
	// Delete product type
	bool OrmasDal::DeleteProductType(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".product_type where product_type_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete product type! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
	// Delete product
	bool OrmasDal::DeleteProduct(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".products where product_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete product! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
	// Delete Location
	bool OrmasDal::DeleteLocation(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".locations where location_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete location! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
	// Delete return
	bool OrmasDal::DeleteReturn(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		//start transaction 
		if (!StartTransaction(errorMessage))
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
			errorMessage = "Could not delete company! SQL command is failed. Please contact with application provider!";
		}

		PGresult * result;
		//cascading detele
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".product_list where return_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			PQclear(result);
			return false;
		}
		PQclear(result);

		sqlCommand = "DELETE FROM \"OrmasSchema\".returns where return_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			if (!CancelTransaction(errorMessage))
			{
				errorMessage = "DB connection was lost! Please restart application!";
			}
			errorMessage = "Could not delete return! SQL command is failed. Please contact with application provider!";
			return false;
		}
		PQclear(result);

		//Commit changes
		if (!CommitTransaction(errorMessage))
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		return true;
	}
	// Delete role
	bool OrmasDal::DeleteRole(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".roles where role_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete role! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
	// Delete status
	bool OrmasDal::DeleteStatus(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".status where status_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete status! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
	// Delete user
	bool OrmasDal::DeleteUser(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".users where user_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		
		if (PQresultStatus(result) == PGRES_COMMAND_OK)
		{
			PQclear(result);
			return true;
		}
		else
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete user! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
	// Update section----------------------------------------------------------------
	// Update company
	bool OrmasDal::UpdateCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment, 
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".companies SET(company_name, company_address, company_phone,\
			comment) = ('";
		sqlCommand += cName;
		sqlCommand += "', '";
		sqlCommand += cAddress;
		sqlCommand += "', '";
		sqlCommand += cPhone;
		sqlCommand += "', '";
		sqlCommand += cComment;
		sqlCommand += "') WHERE company_id=";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the company with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(cID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateCurrency(int cID, int cCode, std::string cShortName, std::string cName, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".currencies SET(currency_code, currency_short_name, \
								  currency_name) = (";
		sqlCommand += boost::lexical_cast<std::string>(cCode);
		sqlCommand += ", '";
		sqlCommand += cShortName;
		sqlCommand += "', '";
		sqlCommand += cName;
		sqlCommand += "') WHERE currency_id=";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the currency with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(cID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateMeasure(int mID, std::string mName, std::string mShortName, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".measures SET(measure_name, measure_short_name) = ('";
		sqlCommand += mName;
		sqlCommand += "', '";
		sqlCommand += mShortName;
		sqlCommand += "') WHERE measure_id=";
		sqlCommand += boost::lexical_cast<std::string>(mID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the measure with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(mID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateOrder(int oID, int uID, std::string oDate, int wID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".orders SET(user_id, order_date, worker_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += oDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ") WHERE order_id=";
		sqlCommand += boost::lexical_cast<std::string>(oID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while order the company with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(oID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateProductList(int pListID, int oID, int rID, int pID, int count, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".product_list SET(order_id, return_id, \
								  product_id, count) = (";
		sqlCommand += boost::lexical_cast<std::string>(oID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(count);
		sqlCommand += ") WHERE product_list_id=";
		sqlCommand += boost::lexical_cast<std::string>(pListID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the product list with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(pListID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".product_type SET(product_type_name,\
								  product_type_short_name) = ('";
		sqlCommand += pTypeName;
		sqlCommand += "', '";
		sqlCommand += pTypeShortName;
		sqlCommand += "') WHERE product_type_id=";
		sqlCommand += boost::lexical_cast<std::string>(pTypeID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the product type with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(pTypeID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateProduct(int pID, int cID, std::string pName, float vol, int mID, float price, int pTypeID, int pShelfLife, 
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".products SET(company_id, product_name, volume, measure_id\
								 price, product_type_id, shelf_life) = (";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ", '";
		sqlCommand += pName;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(vol);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(mID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(price);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pTypeID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pShelfLife);
		sqlCommand += ") WHERE product_id=";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the product with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(pID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateLocation(int rID, std::string lCountryName, std::string lCountryCode, std::string lRegionName,
		std::string lCityName, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".locations SET(country_name, country_code, region_name, \
								 city_name) = ('";
		sqlCommand += lCountryName;
		sqlCommand += "', '";
		sqlCommand += lCountryCode;
		sqlCommand += "', '";
		sqlCommand += lRegionName;
		sqlCommand += "', '";
		sqlCommand += lCityName;
		sqlCommand += "') WHERE location_id=";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the location with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(rID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateReturn(int rID, int uID, std::string rDate, int wID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".returns SET(user_id, order_date, worker_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += rDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ") WHERE return_id=";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the return with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(rID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateRole(int rID, std::string rName, std::string rComment, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".roles SET(role_name, comment) = ('";
		sqlCommand += rName;
		sqlCommand += "', '";
		sqlCommand += rComment;
		sqlCommand += "') WHERE role_id=";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the role with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(rID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateStatus(int sID, std::string sCode, std::string sName, std::string sComment, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".status SET(status_code, status_name, comment) = ('";
		sqlCommand += sCode;
		sqlCommand += "', '";
		sqlCommand += sName;
		sqlCommand += "', '";
		sqlCommand += sComment;
		sqlCommand += "') WHERE status_id=";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the status with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(sID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	bool OrmasDal::UpdateUser(int uID, std::string uName, std::string uPhone, std::string uAddress, 
		std::string firm, std::string firmNumber, int uRoleID, int uLocationID, std::string uPassword, bool uActivated, 
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".users SET(user_name, user_phone, user_addres, firm, firm_number, \
								 role_id, location_id, password, activated) = ('";
		sqlCommand += uName;
		sqlCommand += "', '";
		sqlCommand += uPhone;
		sqlCommand += "', '";
		sqlCommand += uAddress;
		sqlCommand += "', '";
		sqlCommand += firm;
		sqlCommand += "', '";
		sqlCommand += firmNumber;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(uRoleID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uLocationID);
		sqlCommand += ", '";
		sqlCommand += uPassword;
		sqlCommand += ",";
		sqlCommand += uActivated;
		sqlCommand += ") WHERE user_id=";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the user with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(uID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
}