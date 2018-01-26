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
	
	std::string OrmasDal::GetSystemDateTime()
	{
		std::string currentDate = "";
		if (PQstatus(dbCon) == CONNECTION_BAD)
			return currentDate;
		PGresult * result;
		result = PQexec(dbCon, "SELECT to_char(now()::timestamp(0), 'yyyy.MM.dd hh:mm:ss')");
		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				currentDate = PQgetvalue(result, 0, 0);
				PQclear(result);
				return currentDate;
			}
			PQclear(result);
			return currentDate;
		}
		PQclear(result);
		return currentDate;
	}

	std::string OrmasDal::GetSystemDate()
	{
		std::string currentDate = "";
		if (PQstatus(dbCon) == CONNECTION_BAD)
			return currentDate;
		PGresult * result;
		result = PQexec(dbCon, "SELECT to_char(DATE(now()::timestamp(0)), 'yyyy.MM.dd')");
		if (PQresultStatus(result) == PGRES_TUPLES_OK)
		{
			if (PQntuples(result) > 0)
			{
				currentDate = PQgetvalue(result, 0, 0);
				PQclear(result);
				return currentDate;
			}
			PQclear(result);
			return currentDate;
		}
		PQclear(result);
		return currentDate;
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
	//Get access items from DB
	std::vector<accessItemsCollection> OrmasDal::GetAccessItems(std::string& errorMessage, std::string filter)
	{
		accessItemsCollection rowTuple;
		std::vector<accessItemsCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".access_items_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int accessItemID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string itemEng = PQgetvalue(result, i, 1);
						std::string itemRu = PQgetvalue(result, i, 2);
						std::string division = PQgetvalue(result, i, 3);
						rowTuple = std::make_tuple(accessItemID, itemEng, itemRu, division);
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
				errorMessage = "Cannot get information from DB for access items, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Get all access rights from DB
	std::vector<accessesCollection> OrmasDal::GetAccesses(std::string& errorMessage, std::string filter)
	{
		accessesCollection rowTuple;
		std::vector<accessesCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult* result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".accesses_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{

						int accessID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int roleID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						int accessItemID = std::stoi(std::string(PQgetvalue(result, i, 2)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 2)));
						rowTuple = std::make_tuple(accessID, roleID, accessItemID);
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
				errorMessage = "Cannot get information from DB for access, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	
	// Balance-Payment relation
	std::vector<balancePaymentCollection> OrmasDal::GetBalancePayment(std::string& errorMessage, std::string filter)
	{
		balancePaymentCollection rowTuple;
		std::vector<balancePaymentCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult* result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".balance_payment_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{

						int balanceID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int paymentID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						rowTuple = std::make_tuple(balanceID, paymentID);
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
				errorMessage = "Cannot get information from DB for balance-payment relation, please contact with appliction provider!";
			}
		}
		return resultVector;
	}


	// Balance-Payslip relation
	std::vector<balancePayslipCollection> OrmasDal::GetBalancePayslip(std::string& errorMessage, std::string filter)
	{
		balancePayslipCollection rowTuple;
		std::vector<balancePayslipCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult* result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".balance_payslip_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{

						int balanceID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int payslipID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						rowTuple = std::make_tuple(balanceID, payslipID);
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
				errorMessage = "Cannot get information from DB for balance-payslip relation, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Balance-Refund relation
	std::vector<balanceRefundCollection> OrmasDal::GetBalanceRefund(std::string& errorMessage, std::string filter)
	{
		balanceRefundCollection rowTuple;
		std::vector<balanceRefundCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult* result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".balance_refund_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{

						int balanceID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int refundID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						rowTuple = std::make_tuple(balanceID, refundID);
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
				errorMessage = "Cannot get information from DB for balance-refund relation, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Balance-Withdrawal relation
	std::vector<balanceWithdrawalCollection> OrmasDal::GetBalanceWithdrawal(std::string& errorMessage, std::string filter)
	{
		balanceWithdrawalCollection rowTuple;
		std::vector<balanceWithdrawalCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult* result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".balance_withdrawal_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{

						int balanceID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int withdrawalID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						rowTuple = std::make_tuple(balanceID, withdrawalID);
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
				errorMessage = "Cannot get information from DB for balance-withdrawal relation, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Get all balances from DB
	std::vector<balancesViewCollection> OrmasDal::GetBalances(std::string& errorMessage, std::string filter)
	{
		balancesViewCollection rowTuple;
		std::vector<balancesViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult* result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".balances_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{

						int balanceID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string clientName = PQgetvalue(result, i, 1);
						std::string clientSurname = PQgetvalue(result, i, 2);
						double balanceValue = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string currencyName = PQgetvalue(result, i, 4);
						int userID = std::stoi(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 6)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 6)));
						rowTuple = std::make_tuple(balanceID, clientName, clientSurname, balanceValue, currencyName, userID, currencyID);
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
				errorMessage = "Cannot get information from DB for balance, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	
	// Get all clients from DB
	std::vector<clientsViewCollection> OrmasDal::GetClients(std::string& errorMessage, std::string filter)
	{
		clientsViewCollection rowTuple;
		std::vector<clientsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult* result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".clients_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{

						int userID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string name = PQgetvalue(result, i, 1);
						std::string surname = PQgetvalue(result, i, 2);
						std::string phone = PQgetvalue(result, i, 3);
						std::string country = PQgetvalue(result, i, 4);
						std::string region = PQgetvalue(result, i, 5);
						std::string city = PQgetvalue(result, i, 6);
						std::string address = PQgetvalue(result, i, 7);
						std::string firm = PQgetvalue(result, i, 8);
						std::string firmNumber = PQgetvalue(result, i, 9);
						std::string roleName = PQgetvalue(result, i, 10);
						std::string password = PQgetvalue(result, i, 11);
						std::string email = PQgetvalue(result, i, 12);
						std::string actStr = (PQgetvalue(result, i, 13));
						bool activated = (actStr.compare("t") == 0 ? true : false);
						int roleID = std::stoi(std::string(PQgetvalue(result, i, 14)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 14)));
						int locationID = std::stoi(std::string(PQgetvalue(result, i, 15)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 15)));
						rowTuple = std::make_tuple(userID, name, surname, phone, country, region, city, address, firm, firmNumber, 
							roleName, password, email, activated, roleID, locationID);
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
				errorMessage = "Cannot get information from DB for clients, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

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
						
						int companyID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
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
				errorMessage = "Cannot get information from DB for company, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get consume product list
	std::vector<consumeProductListViewCollection> OrmasDal::GetConsumeProductList(std::string& errorMessage, std::string filter)
	{
		consumeProductListViewCollection rowTuple;
		std::vector<consumeProductListViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".consume_product_list_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int clID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int consumeProductID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						std::string productName = PQgetvalue(result, i, 2);
						double price = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string currencyName = std::string(PQgetvalue(result, i, 4));
						double volume = std::stod(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						std::string measureName = std::string(PQgetvalue(result, i, 6));
						int count = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 8)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 8)));
						std::string sumCurrencyName = std::string(PQgetvalue(result, i, 9));
						std::string statusName = std::string(PQgetvalue(result, i, 10));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 11)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 11)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						rowTuple = std::make_tuple(clID, consumeProductID, productName, price, currencyName, volume, measureName, count, sum, sumCurrencyName,
							statusName, productID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for consume product list, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get consume products
	std::vector<consumeProductsViewCollection> OrmasDal::GetConsumeProducts(std::string& errorMessage, std::string filter)
	{
		consumeProductsViewCollection rowTuple;
		std::vector<consumeProductsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".consume_products_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int consumeProductID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string consumeProductDate = PQgetvalue(result, i, 1);
						std::string consumeProductExecutionDate = PQgetvalue(result, i, 2);
						std::string statusCode = PQgetvalue(result, i, 3);
						std::string statusName = PQgetvalue(result, i, 4);
						std::string employeeName = PQgetvalue(result, i, 5);
						std::string employeeSurname = PQgetvalue(result, i, 6);
						std::string employeePhone = PQgetvalue(result, i, 7);
						std::string employeePosition = PQgetvalue(result, i, 8);
						std::string stockEmployeeName = PQgetvalue(result, i, 9);
						std::string stockEmployeeSurname = PQgetvalue(result, i, 10);
						std::string stockEmployeePhone = PQgetvalue(result, i, 11);
						std::string stockEmployeePosition = PQgetvalue(result, i, 12);
						int count = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 14)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 14)));
						std::string currencyName = PQgetvalue(result, i, 15);
						int employeeID = std::stoi(std::string(PQgetvalue(result, i, 16)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 16)));
						int userID = std::stoi(std::string(PQgetvalue(result, i, 17)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 17)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 18)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 18)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 19)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 19)));

						rowTuple = std::make_tuple(consumeProductID, consumeProductDate, consumeProductExecutionDate, statusCode,
							statusName, employeeName, employeeSurname, employeePhone, employeePosition, stockEmployeeName, 
							stockEmployeeSurname, stockEmployeePhone, stockEmployeePosition, count, sum, currencyName, employeeID,
							userID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for consume product, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get consume raw list
	std::vector<consumeRawListViewCollection> OrmasDal::GetConsumeRawList(std::string& errorMessage, std::string filter)
	{
		consumeRawListViewCollection rowTuple;
		std::vector<consumeRawListViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".consume_product_list_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int clID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int consumeRawID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						std::string productName = PQgetvalue(result, i, 2);
						double price = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string currencyName = std::string(PQgetvalue(result, i, 4));
						double volume = std::stod(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						std::string measureName = std::string(PQgetvalue(result, i, 6));
						int count = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 8)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 8)));
						std::string sumCurrencyName = std::string(PQgetvalue(result, i, 9));
						std::string statusName = std::string(PQgetvalue(result, i, 10));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 11)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 11)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						rowTuple = std::make_tuple(clID, consumeRawID, productName, price, currencyName, volume, measureName, count, sum, sumCurrencyName,
							statusName, productID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for consume raw list, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get consume products
	std::vector<consumeRawsViewCollection> OrmasDal::GetConsumeRaws(std::string& errorMessage, std::string filter)
	{
		consumeRawsViewCollection rowTuple;
		std::vector<consumeRawsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".consume_products_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int consumeRawID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string consumeRawDate = PQgetvalue(result, i, 1);
						std::string consumeRawExecutionDate = PQgetvalue(result, i, 2);
						std::string statusCode = PQgetvalue(result, i, 3);
						std::string statusName = PQgetvalue(result, i, 4);
						std::string employeeName = PQgetvalue(result, i, 5);
						std::string employeeSurname = PQgetvalue(result, i, 6);
						std::string employeePhone = PQgetvalue(result, i, 7);
						std::string employeePosition = PQgetvalue(result, i, 8);
						std::string stockEmployeeName = PQgetvalue(result, i, 9);
						std::string stockEmployeeSurname = PQgetvalue(result, i, 10);
						std::string stockEmployeePhone = PQgetvalue(result, i, 11);
						std::string stockEmployeePosition = PQgetvalue(result, i, 12);
						int count = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 14)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 14)));
						std::string currencyName = PQgetvalue(result, i, 15);
						int employeeID = std::stoi(std::string(PQgetvalue(result, i, 16)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 16)));
						int userID = std::stoi(std::string(PQgetvalue(result, i, 17)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 17)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 18)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 18)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 19)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 19)));

						rowTuple = std::make_tuple(consumeRawID, consumeRawDate, consumeRawExecutionDate, statusCode,
							statusName, employeeName, employeeSurname, employeePhone, employeePosition, stockEmployeeName,
							stockEmployeeSurname, stockEmployeePhone, stockEmployeePosition, count, sum, currencyName, employeeID,
							userID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for consume raw, please contact with appliction provider!";
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
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int currencyCode = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						std::string currencyShortName = PQgetvalue(result, i, 2);
						std::string currencyName = PQgetvalue(result, i, 3);
						int currencyUnit = std::stoi(std::string(PQgetvalue(result, i, 4)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 4)));
						std::string cMT = (PQgetvalue(result, i, 5));
						bool currencyMainTrade = (cMT.compare("t") == 0 ? true : false);
						rowTuple = std::make_tuple(currencyID, currencyCode, currencyShortName, currencyName, currencyUnit, currencyMainTrade);
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
				errorMessage = "Cannot get information from DB for currency, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	
	// Get all employees from DB
	std::vector<employeesViewCollection> OrmasDal::GetEmployees(std::string& errorMessage, std::string filter)
	{
		employeesViewCollection rowTuple;
		std::vector<employeesViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult* result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".employees_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int userID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string name = PQgetvalue(result, i, 1);
						std::string surname = PQgetvalue(result, i, 2);
						std::string positionName = PQgetvalue(result, i, 3);
						std::string phone = PQgetvalue(result, i, 4);
						std::string address = PQgetvalue(result, i, 5);
						std::string birthDate = PQgetvalue(result, i, 6);
						std::string roleName = PQgetvalue(result, i, 7);
						std::string hireDate = PQgetvalue(result, i, 8);
						std::string password = PQgetvalue(result, i, 9);
						std::string email = PQgetvalue(result, i, 10);
						std::string actStr = (PQgetvalue(result, i, 11));
						bool activated = (actStr.compare("t") == 0 ? true : false);
						int roleID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						int positionID = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						rowTuple = std::make_tuple(userID, name, surname, positionName, phone, address, birthDate, roleName, hireDate,
							password, email, activated, roleID, positionID);
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
				errorMessage = "Cannot get information from DB for employee, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get inventorization list
	std::vector<inventorizationListViewCollection> OrmasDal::GetInventorizationList(std::string& errorMessage, std::string filter)
	{
		inventorizationListViewCollection rowTuple;
		std::vector<inventorizationListViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".inventorization_list_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int ilID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int inventorizationID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						std::string productName = PQgetvalue(result, i, 2);
						double price = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string currencyName = std::string(PQgetvalue(result, i, 4));
						double volume = std::stod(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						std::string measureName = std::string(PQgetvalue(result, i, 6));
						int count = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 8)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 8)));
						std::string sumCurrencyName = std::string(PQgetvalue(result, i, 9));
						std::string statusName = std::string(PQgetvalue(result, i, 10));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 11)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 11)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						rowTuple = std::make_tuple(ilID, inventorizationID, productName, price, currencyName, volume, measureName, count, sum, sumCurrencyName,
							statusName, productID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for inventorization list, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get inventorizations
	std::vector<inventorizationsViewCollection> OrmasDal::GetInventorizations(std::string& errorMessage, std::string filter)
	{
		inventorizationsViewCollection rowTuple;
		std::vector<inventorizationsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".inventorizations_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int inventorizationID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string inventorizationDate = PQgetvalue(result, i, 1);
						std::string inventorizationExecutionDate = PQgetvalue(result, i, 2);
						std::string statusCode = PQgetvalue(result, i, 3);
						std::string statusName = PQgetvalue(result, i, 4);
						std::string employeeName = PQgetvalue(result, i, 5);
						std::string employeeSurname = PQgetvalue(result, i, 6);
						std::string employeePhone = PQgetvalue(result, i, 7);
						std::string employeePosition = PQgetvalue(result, i, 8);
						std::string stockEmployeeName = PQgetvalue(result, i, 9);
						std::string stockEmployeeSurname = PQgetvalue(result, i, 10);
						std::string stockEmployeePhone = PQgetvalue(result, i, 11);
						std::string stockEmployeePosition = PQgetvalue(result, i, 12);
						int count = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 14)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 14)));
						std::string currencyName = PQgetvalue(result, i, 15);
						int employeeID = std::stoi(std::string(PQgetvalue(result, i, 16)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 16)));
						int userID = std::stoi(std::string(PQgetvalue(result, i, 17)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 17)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 18)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 18)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 19)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 19)));

						rowTuple = std::make_tuple(inventorizationID, inventorizationDate, inventorizationExecutionDate, statusCode,
							statusName, employeeName, employeeSurname, employeePhone, employeePosition, stockEmployeeName,
							stockEmployeeSurname, stockEmployeePhone, stockEmployeePosition, count, sum, currencyName, employeeID,
							userID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for inventorization, please contact with appliction provider!";
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
						int locationID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
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
				errorMessage = "Cannot get information from DB for location, please contact with appliction provider!";
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
						int measureID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string measureName = PQgetvalue(result, i, 1);
						std::string measureShortName = PQgetvalue(result, i, 2);
						std::string mUnit = std::string(PQgetvalue(result, i, 3));
						int measureUnit = std::stoi(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						rowTuple = std::make_tuple(measureID, measureName, measureShortName, measureUnit);
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
				errorMessage = "Cannot get information from DB for measure, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	
	//Get order list
	std::vector<orderListViewCollection> OrmasDal::GetOrderList(std::string& errorMessage, std::string filter)
	{
		orderListViewCollection rowTuple;
		std::vector<orderListViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".order_list_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int olID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int orderID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						std::string productName = PQgetvalue(result, i, 2);
						double price = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string currencyName = std::string(PQgetvalue(result, i, 4));
						double volume = std::stod(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						std::string measureName = std::string(PQgetvalue(result, i, 6));
						int count = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 8)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 8)));
						std::string sumCurrencyName = std::string(PQgetvalue(result, i, 9));
						std::string statusName = std::string(PQgetvalue(result, i, 10));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 11)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 11)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						rowTuple = std::make_tuple(olID, orderID, productName, price, currencyName, volume, measureName, count, sum, sumCurrencyName,
							statusName, productID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for order list, please contact with appliction provider!";
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
						int orderID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string orderDate = PQgetvalue(result, i, 1);
						std::string orderExecutionDate = PQgetvalue(result, i, 2);
						std::string statusCode = PQgetvalue(result, i, 3);
						std::string statusName = PQgetvalue(result, i, 4);
						std::string clientName = PQgetvalue(result, i, 5);
						std::string clientSurname = PQgetvalue(result, i, 6);
						std::string clientPhone = PQgetvalue(result, i, 7);
						std::string clientAddress = PQgetvalue(result, i, 8);
						std::string firm = PQgetvalue(result, i, 9);
						std::string employeeName = PQgetvalue(result, i, 10);
						std::string employeeSurname = PQgetvalue(result, i, 11);
						std::string employeePhone = PQgetvalue(result, i, 12);
						int count = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 14)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 14)));
						std::string currencyName = PQgetvalue(result, i, 15);
						int employeeID = std::stoi(std::string(PQgetvalue(result, i, 16)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 16)));
						int userID = std::stoi(std::string(PQgetvalue(result, i, 17)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 17)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 18)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 18)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 19)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 19)));

						rowTuple = std::make_tuple(orderID, orderDate, orderExecutionDate, statusCode, statusName, clientName, clientSurname, clientPhone,
							clientAddress, firm, employeeName, employeeSurname, employeePhone, count, sum, currencyName, employeeID, 
							userID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for order, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	
	//Get order raw list
	std::vector<orderRawListViewCollection> OrmasDal::GetOrderRawList(std::string& errorMessage, std::string filter)
	{
		orderRawListViewCollection rowTuple;
		std::vector<orderRawListViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".order_raw_list_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int olID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int orderRawID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						std::string productName = PQgetvalue(result, i, 2);
						double price = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string currencyName = std::string(PQgetvalue(result, i, 4));
						double volume = std::stod(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						std::string measureName = std::string(PQgetvalue(result, i, 6));
						int count = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 8)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 8)));
						std::string sumCurrencyName = std::string(PQgetvalue(result, i, 9));
						std::string statusName = std::string(PQgetvalue(result, i, 10));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 11)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 11)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						rowTuple = std::make_tuple(olID, orderRawID, productName, price, currencyName, volume, measureName, count, sum, sumCurrencyName,
							statusName, productID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for order raw list, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get order raws
	std::vector<orderRawsViewCollection> OrmasDal::GetOrderRaws(std::string& errorMessage, std::string filter)
	{
		orderRawsViewCollection rowTuple;
		std::vector<orderRawsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".order_raws_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int orderRawID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string orderRawDate = PQgetvalue(result, i, 1);
						std::string orderRawExecutionDate = PQgetvalue(result, i, 2);
						std::string statusCode = PQgetvalue(result, i, 3);
						std::string statusName = PQgetvalue(result, i, 4);
						std::string employeeName = PQgetvalue(result, i, 5);
						std::string employeeSurname = PQgetvalue(result, i, 6);
						std::string employeePhone = PQgetvalue(result, i, 7);
						std::string employeePosition = PQgetvalue(result, i, 8);
						std::string stockEmployeeName = PQgetvalue(result, i, 9);
						std::string stockEmployeeSurname = PQgetvalue(result, i, 10);
						std::string stockEmployeePhone = PQgetvalue(result, i, 11);
						std::string stockEmployeePosition = PQgetvalue(result, i, 12);
						int count = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 14)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 14)));
						std::string currencyName = PQgetvalue(result, i, 15);
						int employeeID = std::stoi(std::string(PQgetvalue(result, i, 16)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 16)));
						int userID = std::stoi(std::string(PQgetvalue(result, i, 17)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 17)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 18)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 18)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 19)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 19)));

						rowTuple = std::make_tuple(orderRawID, orderRawDate, orderRawExecutionDate, statusCode,
							statusName, employeeName, employeeSurname, employeePhone, employeePosition, stockEmployeeName,
							stockEmployeeSurname, stockEmployeePhone, stockEmployeePosition, count, sum, currencyName, employeeID,
							userID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for order raw, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Get payments
	std::vector<paymentsViewCollection> OrmasDal::GetPayments(std::string& errorMessage, std::string filter)
	{
		paymentsViewCollection rowTuple;
		std::vector<paymentsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".payments_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int paymentID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string paymentDate = PQgetvalue(result, i, 1);
						double paymentValue = std::stod(std::string(PQgetvalue(result, i, 2)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 2)));
						std::string currencyName = PQgetvalue(result, i, 3);
						int userID = std::stoi(std::string(PQgetvalue(result, i, 4)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 4)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						rowTuple = std::make_tuple(paymentID, paymentDate, paymentValue, currencyName, userID, currencyID);
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
				errorMessage = "Cannot get information from DB for payment, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get payslip
	std::vector<payslipsViewCollection> OrmasDal::GetPayslips(std::string& errorMessage, std::string filter)
	{
		payslipsViewCollection rowTuple;
		std::vector<payslipsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".payslips_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int payslipID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string payslipDate = PQgetvalue(result, i, 1);
						double payslipValue = std::stod(std::string(PQgetvalue(result, i, 2)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 2)));
						std::string currencyName = PQgetvalue(result, i, 3);
						int salaryID = std::stoi(std::string(PQgetvalue(result, i, 4)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						rowTuple = std::make_tuple(payslipID, payslipDate, payslipValue, currencyName, salaryID, currencyID);
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
				errorMessage = "Cannot get information from DB for payslip, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Payslip-Order relation
	std::vector<payslipOrderCollection> OrmasDal::GetPayslipOrder(std::string& errorMessage, std::string filter)
	{
		payslipOrderCollection rowTuple;
		std::vector<payslipOrderCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult* result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".payslip_order_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{

						int payslipID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int orderID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						rowTuple = std::make_tuple(payslipID, orderID);
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
				errorMessage = "Cannot get information from DB for payslip-order relation, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Get photos
	std::vector<photosCollection> OrmasDal::GetPhotos(std::string& errorMessage, std::string filter)
	{
		photosCollection rowTuple;
		std::vector<photosCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".photos_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int photoID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int userID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 2)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 2)));
						std::string source = PQgetvalue(result, i, 3);
						rowTuple = std::make_tuple(photoID, userID, productID, source);
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
				errorMessage = "Cannot get information from DB for photo, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Get positions
	std::vector<positionsCollection> OrmasDal::GetPositions(std::string& errorMessage, std::string filter)
	{
		positionsCollection rowTuple;
		std::vector<positionsCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".positions_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int positionID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string positionName = PQgetvalue(result, i, 1);
						rowTuple = std::make_tuple(positionID, positionName);
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
				errorMessage = "Cannot get information from DB for position, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Get prices
	std::vector<pricesViewCollection> OrmasDal::GetPrices(std::string& errorMessage, std::string filter)
	{
		pricesViewCollection rowTuple;
		std::vector<pricesViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".prices_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int priceID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string priceDate = PQgetvalue(result, i, 1);
						std::string productName = PQgetvalue(result, i, 2);
						double productVolume = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string measureName = PQgetvalue(result, i, 4);
						double priceValue = std::stod(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						std::string currencyName = PQgetvalue(result, i, 6);
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 8)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 8)));
						rowTuple = std::make_tuple(priceID, priceDate, productName, productVolume, measureName, priceValue, currencyName, currencyID, productID);
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
				errorMessage = "Cannot get information from DB for price, please contact with appliction provider!";
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
						int productTypeID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
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
				errorMessage = "Cannot get information from DB for product type, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	
	// Get production
	std::vector<productionCollection> OrmasDal::GetProduction(std::string& errorMessage, std::string filter)
	{
		productionCollection rowTuple;
		std::vector<productionCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".production_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int productionID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string productionDate = PQgetvalue(result, i, 1);
						std::string expiryDate = PQgetvalue(result, i, 2);
						std::string sessionStart = PQgetvalue(result, i, 3);
						std::string sessionEnd = PQgetvalue(result, i, 4);
						rowTuple = std::make_tuple(productionID, productionDate, expiryDate, sessionStart, sessionEnd);
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
				errorMessage = "Cannot get information from DB for production, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	
	//Get production list
	std::vector<productionListViewCollection> OrmasDal::GetProductionList(std::string& errorMessage, std::string filter)
	{
		productionListViewCollection rowTuple;
		std::vector<productionListViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".production_list_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int plID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int productionID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						std::string productName = PQgetvalue(result, i, 2);
						double price = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string currencyName = std::string(PQgetvalue(result, i, 4));
						double volume = std::stod(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						std::string measureName = std::string(PQgetvalue(result, i, 6));
						int count = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 8)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 8)));
						std::string sumCurrencyName = std::string(PQgetvalue(result, i, 9));
						std::string statusName = std::string(PQgetvalue(result, i, 10));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 11)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 11)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						rowTuple = std::make_tuple(plID, productionID, productName, price, currencyName, volume, measureName, count, sum, sumCurrencyName,
							statusName, productID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for production list, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Get products
	std::vector<productsViewCollection> OrmasDal::GetProducts(std::string& errorMessage, std::string filter)
	{
		productsViewCollection rowTuple;
		std::vector<productsViewCollection> resultVector;
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
						int productID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string productName = PQgetvalue(result, i, 1);
						double price = std::stod(std::string(PQgetvalue(result, i, 2)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 2)));
						std::string currencyName = PQgetvalue(result, i, 3);
						double volume = std::stod(std::string(PQgetvalue(result, i, 4)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 4)));
						std::string measureName = PQgetvalue(result, i, 5);
						std::string productTypeName = PQgetvalue(result, i, 6);
						int shelfLife = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						std::string companyName = PQgetvalue(result, i, 8);
						int companyID = std::stoi(std::string(PQgetvalue(result, i, 9)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 9)));
						int measureID = std::stoi(std::string(PQgetvalue(result, i, 10)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 10)));
						int productTypeID = std::stoi(std::string(PQgetvalue(result, i, 11)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 11)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));

						rowTuple = std::make_tuple(productID, productName, price, currencyName, volume, measureName, productTypeName, 
							shelfLife, companyName, companyID, measureID, productTypeID, currencyID);
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
				errorMessage = "Cannot get information from DB for product, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	
	//Get receipt product list
	std::vector<receiptProductListViewCollection> OrmasDal::GetReceiptProductList(std::string& errorMessage, std::string filter)
	{
		receiptProductListViewCollection rowTuple;
		std::vector<receiptProductListViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".receipt_product_list_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int rlID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int receiptProductID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						std::string productName = PQgetvalue(result, i, 2);
						double price = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string currencyName = std::string(PQgetvalue(result, i, 4));
						double volume = std::stod(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						std::string measureName = std::string(PQgetvalue(result, i, 6));
						int count = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 8)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 8)));
						std::string sumCurrencyName = std::string(PQgetvalue(result, i, 9));
						std::string statusName = std::string(PQgetvalue(result, i, 10));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 11)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 11)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						rowTuple = std::make_tuple(rlID, receiptProductID, productName, price, currencyName, volume, measureName, count, sum, sumCurrencyName,
							statusName, productID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for receipt product list, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get receipt products
	std::vector<receiptProductsViewCollection> OrmasDal::GetReceiptProducts(std::string& errorMessage, std::string filter)
	{
		receiptProductsViewCollection rowTuple;
		std::vector<receiptProductsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".receipt_products_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int receiptProductID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string receiptProductDate = PQgetvalue(result, i, 1);
						std::string receiptProductExecutionDate = PQgetvalue(result, i, 2);
						std::string statusCode = PQgetvalue(result, i, 3);
						std::string statusName = PQgetvalue(result, i, 4);
						std::string employeeName = PQgetvalue(result, i, 5);
						std::string employeeSurname = PQgetvalue(result, i, 6);
						std::string employeePhone = PQgetvalue(result, i, 7);
						std::string employeePosition = PQgetvalue(result, i, 8);
						std::string stockEmployeeName = PQgetvalue(result, i, 9);
						std::string stockEmployeeSurname = PQgetvalue(result, i, 10);
						std::string stockEmployeePhone = PQgetvalue(result, i, 11);
						std::string stockEmployeePosition = PQgetvalue(result, i, 12);
						int count = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 14)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 14)));
						std::string currencyName = PQgetvalue(result, i, 15);
						int employeeID = std::stoi(std::string(PQgetvalue(result, i, 16)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 16)));
						int userID = std::stoi(std::string(PQgetvalue(result, i, 17)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 17)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 18)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 18)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 19)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 19)));

						rowTuple = std::make_tuple(receiptProductID, receiptProductDate, receiptProductExecutionDate, statusCode,
							statusName, employeeName, employeeSurname, employeePhone, employeePosition, stockEmployeeName,
							stockEmployeeSurname, stockEmployeePhone, stockEmployeePosition, count, sum, currencyName, employeeID,
							userID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for receipt product, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get receipt raw list
	std::vector<receiptRawListViewCollection> OrmasDal::GetReceiptRawList(std::string& errorMessage, std::string filter)
	{
		receiptRawListViewCollection rowTuple;
		std::vector<receiptRawListViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".receipt_raw_list_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int rlID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int receiptRawID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						std::string productName = PQgetvalue(result, i, 2);
						double price = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string currencyName = std::string(PQgetvalue(result, i, 4));
						double volume = std::stod(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						std::string measureName = std::string(PQgetvalue(result, i, 6));
						int count = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 8)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 8)));
						std::string sumCurrencyName = std::string(PQgetvalue(result, i, 9));
						std::string statusName = std::string(PQgetvalue(result, i, 10));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 11)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 11)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						rowTuple = std::make_tuple(rlID, receiptRawID, productName, price, currencyName, volume, measureName, count, sum, sumCurrencyName,
							statusName, productID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for receipt raw list, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get receipt raws
	std::vector<receiptRawsViewCollection> OrmasDal::GetReceiptRaws(std::string& errorMessage, std::string filter)
	{
		receiptRawsViewCollection rowTuple;
		std::vector<receiptRawsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".receipt_raws_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int receiptRawID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string receiptRawDate = PQgetvalue(result, i, 1);
						std::string receiptRawExecutionDate = PQgetvalue(result, i, 2);
						std::string statusCode = PQgetvalue(result, i, 3);
						std::string statusName = PQgetvalue(result, i, 4);
						std::string employeeName = PQgetvalue(result, i, 5);
						std::string employeeSurname = PQgetvalue(result, i, 6);
						std::string employeePhone = PQgetvalue(result, i, 7);
						std::string employeePosition = PQgetvalue(result, i, 8);
						std::string stockEmployeeName = PQgetvalue(result, i, 9);
						std::string stockEmployeeSurname = PQgetvalue(result, i, 10);
						std::string stockEmployeePhone = PQgetvalue(result, i, 11);
						std::string stockEmployeePosition = PQgetvalue(result, i, 12);
						int count = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 14)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 14)));
						std::string currencyName = PQgetvalue(result, i, 15);
						int employeeID = std::stoi(std::string(PQgetvalue(result, i, 16)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 16)));
						int userID = std::stoi(std::string(PQgetvalue(result, i, 17)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 17)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 18)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 18)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 19)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 19)));

						rowTuple = std::make_tuple(receiptRawID, receiptRawDate, receiptRawExecutionDate, statusCode,
							statusName, employeeName, employeeSurname, employeePhone, employeePosition, stockEmployeeName,
							stockEmployeeSurname, stockEmployeePhone, stockEmployeePosition, count, sum, currencyName, employeeID,
							userID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for receipt raw, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Get refunds
	std::vector<refundsViewCollection> OrmasDal::GetRefunds(std::string& errorMessage, std::string filter)
	{
		refundsViewCollection rowTuple;
		std::vector<refundsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".refunds_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int refundID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string refundDate = PQgetvalue(result, i, 1);
						double refundValue = std::stod(std::string(PQgetvalue(result, i, 2)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 2)));
						std::string currencyName = PQgetvalue(result, i, 3);
						int userID = std::stoi(std::string(PQgetvalue(result, i, 4)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 4)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						rowTuple = std::make_tuple(refundID, refundDate, refundValue, currencyName, userID, currencyID);
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
				errorMessage = "Cannot get information from DB for refunds, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Get relation type
	std::vector<relationTypeCollection> OrmasDal::GetRelationType(std::string& errorMessage, std::string filter)
	{
		relationTypeCollection rowTuple;
		std::vector<relationTypeCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".relation_type_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());
			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int relationTypeID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string relationTypeName = PQgetvalue(result, i, 1);
						std::string comment = PQgetvalue(result, i, 2);
						rowTuple = std::make_tuple(relationTypeID, relationTypeName, comment);
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
				errorMessage = "Cannot get information from DB for relation type, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Get relations
	std::vector<relationsCollection> OrmasDal::GetRelations(std::string& errorMessage, std::string filter)
	{
		relationsCollection rowTuple;
		std::vector<relationsCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".relations_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());
			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int relationID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int userID1 = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						int userID2 = std::stoi(std::string(PQgetvalue(result, i, 2)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 2)));
						int relationTypeID = std::stoi(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						
						rowTuple = std::make_tuple(relationID, userID1, userID2, relationTypeID);
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
				errorMessage = "Cannot get information from DB for relation, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	
	//Get return list
	std::vector<returnListViewCollection> OrmasDal::GetReturnList(std::string& errorMessage, std::string filter)
	{
		returnListViewCollection rowTuple;
		std::vector<returnListViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".return_list_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int rlID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int returnID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						std::string productName = PQgetvalue(result, i, 2);
						double price = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string currencyName = std::string(PQgetvalue(result, i, 4));
						double volume = std::stod(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						std::string measureName = std::string(PQgetvalue(result, i, 6));
						int count = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 8)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 8)));
						std::string sumCurrencyName = std::string(PQgetvalue(result, i, 9));
						std::string statusName = std::string(PQgetvalue(result, i, 10));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 11)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 11)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						rowTuple = std::make_tuple(rlID, returnID, productName, price, currencyName, volume, measureName, count, sum, sumCurrencyName,
							statusName, productID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for return list, please contact with appliction provider!";
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
						int returnID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string returnDate = PQgetvalue(result, i, 1);
						std::string returnExecutionDate = PQgetvalue(result, i, 2);
						std::string statusCode = PQgetvalue(result, i, 3);
						std::string statusName = PQgetvalue(result, i, 4);
						std::string clientName = PQgetvalue(result, i, 5);
						std::string clientSurname = PQgetvalue(result, i, 6);
						std::string clientPhone = PQgetvalue(result, i, 7);
						std::string clientAddress = PQgetvalue(result, i, 8);
						std::string firm = PQgetvalue(result, i, 9);
						std::string employeeName = PQgetvalue(result, i, 10);
						std::string employeeSurname = PQgetvalue(result, i, 11);
						std::string employeePhone = PQgetvalue(result, i, 12);
						int count = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 14)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 14)));
						std::string currencyName = PQgetvalue(result, i, 15);
						int employeeID = std::stoi(std::string(PQgetvalue(result, i, 16)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 16)));
						int userID = std::stoi(std::string(PQgetvalue(result, i, 17)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 17)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 18)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 18)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 19)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 19)));

						rowTuple = std::make_tuple(returnID, returnDate, returnExecutionDate, statusCode, statusName, clientName, clientSurname,
							clientPhone, clientAddress, firm, employeeName, employeeSurname, employeePhone, count, sum, currencyName,
							employeeID, userID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for return, please contact with appliction provider!";
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
						int roleID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string roleCode = PQgetvalue(result, i, 1);
						std::string roleName = PQgetvalue(result, i, 2);
						std::string comment = PQgetvalue(result, i, 3);
						rowTuple = std::make_tuple(roleID, roleCode, roleName, comment);
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
				errorMessage = "Cannot get information from DB for role, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	
	// Get all salaries from DB
	std::vector<salariesViewCollection> OrmasDal::GetSalaries(std::string& errorMessage, std::string filter)
	{
		salariesViewCollection rowTuple;
		std::vector<salariesViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult* result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".salaries_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int salaryID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int userID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						std::string userName = PQgetvalue(result, i, 2);
						std::string userSurname = PQgetvalue(result, i, 3);
						std::string userPhone = PQgetvalue(result, i, 4);
						std::string salaryDate = PQgetvalue(result, i, 5);
						double salaryValue = std::stod(std::string(PQgetvalue(result, i, 6)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 6)));
						std::string currencyName = PQgetvalue(result, i, 7);
						std::string salaryTypeName = PQgetvalue(result, i, 8);
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 9)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 9)));
						int salaryTypeID = std::stoi(std::string(PQgetvalue(result, i, 10)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 10)));
						std::string bonusStr = (PQgetvalue(result, i, 11));
						bool salaryBonus = (bonusStr.compare("t") == 0 ? true : false);
						rowTuple = std::make_tuple(salaryID, userID, userName, userSurname, userPhone, salaryDate, salaryValue, 
							currencyName, salaryTypeName, currencyID, salaryTypeID, salaryBonus);
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
				errorMessage = "Cannot get information from DB for salary, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Get all salaries from DB
	std::vector<salaryTypeCollection> OrmasDal::GetSalaryType(std::string& errorMessage, std::string filter)
	{
		salaryTypeCollection rowTuple;
		std::vector<salaryTypeCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult* result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".salary_type_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{

						int salaryTypeID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string salaryTypeCode = PQgetvalue(result, i, 1);
						std::string salaryTypeName = PQgetvalue(result, i, 2);
						rowTuple = std::make_tuple(salaryTypeID, salaryTypeCode, salaryTypeName);
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
				errorMessage = "Cannot get information from DB for salary type, please contact with appliction provider!";
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
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
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
				errorMessage = "Cannot get information from DB for status, please contact with appliction provider!";
			}
		}
		return resultVector;
	}
	
	//Get stock
	std::vector<stockViewCollection> OrmasDal::GetStock(std::string& errorMessage, std::string filter)
	{
		stockViewCollection rowTuple;
		std::vector<stockViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".stock_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int sID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string productName = PQgetvalue(result, i, 2);
						double price = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string currencyName = std::string(PQgetvalue(result, i, 4));
						double volume = std::stod(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						std::string measureName = std::string(PQgetvalue(result, i, 6));
						int count = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 8)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 8)));
						std::string sumCurrencyName = std::string(PQgetvalue(result, i, 9));
						std::string statusName = std::string(PQgetvalue(result, i, 10));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 11)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 11)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						rowTuple = std::make_tuple(sID, productName, price, currencyName, volume, measureName, count, sum, sumCurrencyName,
							statusName, productID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for stock, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get transport list
	std::vector<transportListViewCollection> OrmasDal::GetTransportList(std::string& errorMessage, std::string filter)
	{
		transportListViewCollection rowTuple;
		std::vector<transportListViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".transport_list_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int tlID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int transportID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						std::string productName = PQgetvalue(result, i, 2);
						double price = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string currencyName = std::string(PQgetvalue(result, i, 4));
						double volume = std::stod(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						std::string measureName = std::string(PQgetvalue(result, i, 6));
						int count = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 8)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 8)));
						std::string sumCurrencyName = std::string(PQgetvalue(result, i, 9));
						std::string statusName = std::string(PQgetvalue(result, i, 10));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 11)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 11)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						rowTuple = std::make_tuple(tlID, transportID, productName, price, currencyName, volume, measureName, count, sum, sumCurrencyName,
							statusName, productID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for transport list, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get transports
	std::vector<transportsViewCollection> OrmasDal::GetTransports(std::string& errorMessage, std::string filter)
	{
		transportsViewCollection rowTuple;
		std::vector<transportsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".transports_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int transportID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string transportDate = PQgetvalue(result, i, 1);
						std::string transportExecutionDate = PQgetvalue(result, i, 2);
						std::string statusCode = PQgetvalue(result, i, 3);
						std::string statusName = PQgetvalue(result, i, 4);
						std::string employeeName = PQgetvalue(result, i, 5);
						std::string employeeSurname = PQgetvalue(result, i, 6);
						std::string employeePhone = PQgetvalue(result, i, 7);
						std::string employeePosition = PQgetvalue(result, i, 8);
						std::string stockEmployeeName = PQgetvalue(result, i, 9);
						std::string stockEmployeeSurname = PQgetvalue(result, i, 10);
						std::string stockEmployeePhone = PQgetvalue(result, i, 11);
						std::string stockEmployeePosition = PQgetvalue(result, i, 12);
						int count = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 14)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 14)));
						std::string currencyName = PQgetvalue(result, i, 15);
						int employeeID = std::stoi(std::string(PQgetvalue(result, i, 16)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 16)));
						int userID = std::stoi(std::string(PQgetvalue(result, i, 17)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 17)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 18)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 18)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 19)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 19)));

						rowTuple = std::make_tuple(transportID, transportDate, transportExecutionDate, statusCode,
							statusName, employeeName, employeeSurname, employeePhone, employeePosition, stockEmployeeName,
							stockEmployeeSurname, stockEmployeePhone, stockEmployeePosition, count, sum, currencyName, employeeID,
							userID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for transports, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Get user
	std::vector<usersViewCollection> OrmasDal::GetUsers(std::string& errorMessage, std::string filter)
	{
		usersViewCollection rowTuple;
		std::vector<usersViewCollection> resultVector;
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
						int userID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string userEmail = PQgetvalue(result, i, 1);
						std::string userName = PQgetvalue(result, i, 2);
						std::string userSurname = PQgetvalue(result, i, 3);
						std::string userPhone = PQgetvalue(result, i, 4);
						std::string userAddress = PQgetvalue(result, i, 5);
						std::string roleName = PQgetvalue(result, i, 6);
						std::string password = PQgetvalue(result, i, 7);
						std::string actStr = (PQgetvalue(result, i, 8));
						bool activated = (actStr.compare("t") == 0 ? true : false);
						int roleID = std::stoi(std::string(PQgetvalue(result, i, 9)).length() == 0 ? "0" : PQgetvalue(result, i, 9));
						rowTuple = std::make_tuple(userID, userEmail, userName, userSurname, userPhone, userAddress,
							roleName, password, activated, roleID);
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
				errorMessage = "Cannot get information from DB for user, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Get withdrawals
	std::vector<withdrawalsViewCollection> OrmasDal::GetWithdrawals(std::string& errorMessage, std::string filter)
	{
		withdrawalsViewCollection rowTuple;
		std::vector<withdrawalsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".withdrawals_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int withdrawalID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string withdrawalDate = PQgetvalue(result, i, 1);
						double withdrawalValue = std::stod(std::string(PQgetvalue(result, i, 2)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 2)));
						std::string currencyName = PQgetvalue(result, i, 3);
						int userID = std::stoi(std::string(PQgetvalue(result, i, 4)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 4)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						rowTuple = std::make_tuple(withdrawalID, withdrawalDate, withdrawalValue, currencyName, userID, currencyID);
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
				errorMessage = "Cannot get information from DB for withdrawal, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get write off list
	std::vector<writeOffListViewCollection> OrmasDal::GetWriteOffList(std::string& errorMessage, std::string filter)
	{
		writeOffListViewCollection rowTuple;
		std::vector<writeOffListViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".write_off_list_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int olID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int orderID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						std::string productName = PQgetvalue(result, i, 2);
						double price = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string currencyName = std::string(PQgetvalue(result, i, 4));
						double volume = std::stod(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						std::string measureName = std::string(PQgetvalue(result, i, 6));
						int count = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 8)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 8)));
						std::string sumCurrencyName = std::string(PQgetvalue(result, i, 9));
						std::string statusName = std::string(PQgetvalue(result, i, 10));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 11)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 11)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						rowTuple = std::make_tuple(olID, orderID, productName, price, currencyName, volume, measureName, count, sum, sumCurrencyName,
							statusName, productID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for order list, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get write-offs
	std::vector<writeOffsViewCollection> OrmasDal::GetWriteOffs(std::string& errorMessage, std::string filter)
	{
		writeOffsViewCollection rowTuple;
		std::vector<writeOffsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".write_offs_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int orderID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string orderDate = PQgetvalue(result, i, 1);
						std::string statusCode = PQgetvalue(result, i, 2);
						std::string statusName = PQgetvalue(result, i, 3);
						std::string clientName = PQgetvalue(result, i, 4);
						std::string clientSurname = PQgetvalue(result, i, 5);
						std::string clientPhone = PQgetvalue(result, i, 6);
						std::string clientAddress = PQgetvalue(result, i, 7);
						std::string firm = PQgetvalue(result, i, 8);
						std::string employeeName = PQgetvalue(result, i, 9);
						std::string employeeSurname = PQgetvalue(result, i, 10);
						std::string employeePhone = PQgetvalue(result, i, 11);
						int count = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						std::string currencyName = PQgetvalue(result, i, 14);
						int employeeID = std::stoi(std::string(PQgetvalue(result, i, 15)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 15)));
						int userID = std::stoi(std::string(PQgetvalue(result, i, 16)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 16)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 17)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 17)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 18)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 18)));

						rowTuple = std::make_tuple(orderID, orderDate, statusCode, statusName, clientName, clientSurname, clientPhone,
							clientAddress, firm, employeeName, employeeSurname, employeePhone, count, sum, currencyName, employeeID,
							userID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for order, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get write-off raw list
	std::vector<writeOffRawListViewCollection> OrmasDal::GetWriteOffRawList(std::string& errorMessage, std::string filter)
	{
		writeOffRawListViewCollection rowTuple;
		std::vector<writeOffRawListViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".write_off_raw_list_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int wlID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						int writeOffRawID = std::stoi(std::string(PQgetvalue(result, i, 1)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 1)));
						std::string productName = PQgetvalue(result, i, 2);
						double price = std::stod(std::string(PQgetvalue(result, i, 3)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 3)));
						std::string currencyName = std::string(PQgetvalue(result, i, 4));
						double volume = std::stod(std::string(PQgetvalue(result, i, 5)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 5)));
						std::string measureName = std::string(PQgetvalue(result, i, 6));
						int count = std::stoi(std::string(PQgetvalue(result, i, 7)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 7)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 8)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 8)));
						std::string sumCurrencyName = std::string(PQgetvalue(result, i, 9));
						std::string statusName = std::string(PQgetvalue(result, i, 10));
						int productID = std::stoi(std::string(PQgetvalue(result, i, 11)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 11)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 12)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 12)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						rowTuple = std::make_tuple(wlID, writeOffRawID, productName, price, currencyName, volume, measureName, count, sum, sumCurrencyName,
							statusName, productID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for write-off raw list, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	//Get write-off raw
	std::vector<writeOffRawsViewCollection> OrmasDal::GetWriteOffRaws(std::string& errorMessage, std::string filter)
	{
		writeOffRawsViewCollection rowTuple;
		std::vector<writeOffRawsViewCollection> resultVector;
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
		}
		else
		{
			PGresult * result;
			std::string sqlCommand = "SELECT * FROM \"OrmasSchema\".write_off_raws_view";
			sqlCommand += filter;
			sqlCommand += ";";
			result = PQexec(dbCon, sqlCommand.c_str());

			if (PQresultStatus(result) == PGRES_TUPLES_OK)
			{
				if (PQntuples(result) > 0)
				{
					for (int i = 0; i < PQntuples(result); i++)
					{
						int writeOffRawID = std::stoi(std::string(PQgetvalue(result, i, 0)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 0)));
						std::string writeOffRawDate = PQgetvalue(result, i, 1);
						std::string statusCode = PQgetvalue(result, i, 3);
						std::string statusName = PQgetvalue(result, i, 4);
						std::string employeeName = PQgetvalue(result, i, 5);
						std::string employeeSurname = PQgetvalue(result, i, 6);
						std::string employeePhone = PQgetvalue(result, i, 7);
						std::string employeePosition = PQgetvalue(result, i, 8);
						std::string stockEmployeeName = PQgetvalue(result, i, 9);
						std::string stockEmployeeSurname = PQgetvalue(result, i, 10);
						std::string stockEmployeePhone = PQgetvalue(result, i, 11);
						std::string stockEmployeePosition = PQgetvalue(result, i, 12);
						int count = std::stoi(std::string(PQgetvalue(result, i, 13)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 13)));
						double sum = std::stod(std::string(PQgetvalue(result, i, 14)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 14)));
						std::string currencyName = PQgetvalue(result, i, 15);
						int employeeID = std::stoi(std::string(PQgetvalue(result, i, 16)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 16)));
						int userID = std::stoi(std::string(PQgetvalue(result, i, 17)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 17)));
						int statusID = std::stoi(std::string(PQgetvalue(result, i, 18)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 18)));
						int currencyID = std::stoi(std::string(PQgetvalue(result, i, 19)).length() == 0 ? "0" : std::string(PQgetvalue(result, i, 19)));

						rowTuple = std::make_tuple(writeOffRawID, writeOffRawDate, statusCode,
							statusName, employeeName, employeeSurname, employeePhone, employeePosition, stockEmployeeName,
							stockEmployeeSurname, stockEmployeePhone, stockEmployeePosition, count, sum, currencyName, employeeID,
							userID, statusID, currencyID);
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
				errorMessage = "Cannot get information from DB for write-off raws, please contact with appliction provider!";
			}
		}
		return resultVector;
	}

	// Create section----------------------------------------------------------------
	// Create access item
	bool OrmasDal::CreateAccessItem(int aID, std::string aItenEng, std::string aItemRu,std::string aDivision, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".access_items(access_item_id, access_item_eng, access_item_ru, access_division) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(aID);
		sqlCommand += ", '";
		sqlCommand += aItenEng;
		sqlCommand += "', '";
		sqlCommand += aItemRu;
		sqlCommand += "', '";
		sqlCommand += aDivision;
		sqlCommand += "');";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the item creation in order list is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create access
	bool OrmasDal::CreateAccess(int aID, int rID, int aiID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".accesses(access_id, role_id, access_item_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(aID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(aiID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the access creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	
	// Create Balance-Payment relation
	bool OrmasDal::CreateBalancePayment(int bID, int pID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".balance_payment(balance_id, payment_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(bID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the balance-payment relation creating is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create Balance-Payslip relation
	bool OrmasDal::CreateBalancePayslip(int bID, int pID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".balance_payslip(balance_id, payslip_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(bID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the balance-payslip relation creating is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create Balance-Refund relation
	bool OrmasDal::CreateBalanceRefund(int bID, int rID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".balance_refund(balance_id, refund_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(bID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the balance-refund relation creating is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create Balance-Withdrawal relation
	bool OrmasDal::CreateBalanceWithdrawal(int bID, int wID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".balance_refund(balance_id, withdrawal_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(bID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the balance-withdrawal relation creating is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create balance
	bool OrmasDal::CreateBalance(int bID, int uID, double bValue, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".balances(balance_id, user_id, balance_value, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(bID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(bValue);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the balance creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	

	// Create client
	bool OrmasDal::CreateClient(int uID, std::string cFirm, std::string cFirmNumber, int lID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".clients(user_id, firm, firm_number, location_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += cFirm;
		sqlCommand += "', '";
		sqlCommand += cFirmNumber;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(lID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the client creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
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
	
	// Create an item in consume product list
	bool OrmasDal::CreateConsumeProductList(int clID, int cpID, int pID, int clCount, double clSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".consume_product_list(consume_product_list_id, consume_product_id, \
										product_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(clID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cpID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(clCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(clSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the item creation in consume product list is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateConsumeProduct(int cID, int uID, std::string cDate, std::string cExecDate, int eID, int cCount, double cSum, int sID, int curID,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".consume_products(consume_product_id, user_id, consume_product_date, \
										execution_date, employee_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += cDate;
		sqlCommand += "', '";
		sqlCommand += cExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(curID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the consume product creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create an item in consume raw list
	bool OrmasDal::CreateConsumeRawList(int clID, int cpID, int pID, int clCount, double clSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".consume_raw_list(consume_raw_list_id, consume_raw_id, \
								 										product_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(clID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cpID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(clCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(clSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the item creation in consume raw list is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateConsumeRaw(int cID, int uID, std::string cDate, std::string cExecDate, int eID, int cCount, double cSum, int sID, int curID,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".consume_raws(consume_raw_id, user_id, consume_raw_date, \
								 										execution_date, employee_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += cDate;
		sqlCommand += "', '";
		sqlCommand += cExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(curID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the consume raw creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateCurrency(int cID, int cCode, std::string cShortName, std::string cName, int cUnit, bool cMainTrade,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".currencies(currency_id, currency_code, currency_short_name, \
								  currency_name, currency_unit, currency_main_trade) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cCode);
		sqlCommand += ", '";
		sqlCommand += cShortName;
		sqlCommand += "', '";
		sqlCommand += cName;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(cUnit);
		sqlCommand += ", ";
		sqlCommand += cMainTrade ? "TRUE" : "FALSE";
		sqlCommand += ");";
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
	
	// Create employee
	bool OrmasDal::CreateEmployee(int uID, int pID, std::string eBirthDate, std::string eHireDate, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".employees(user_id, position_id, birth_date, hire_date) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", '";
		sqlCommand += eBirthDate;
		sqlCommand += "', '";
		sqlCommand += eHireDate;
		sqlCommand += "');";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the employee creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create an item in inventorization list
	bool OrmasDal::CreateInventorizationList(int ilID, int iID, int pID, int ilCount, double ilSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".inventorization_list(inventorization_list_id, inventorization_id, \
								 								 										product_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(ilID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(iID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(ilCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(ilSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the item creation in inventorization list is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateInventorization(int iID, int uID, std::string iDate, std::string iExecDate, int eID, int iCount, double iSum, int sID, int curID,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".inventorizations(inventorization_id, user_id, inventorization_date, \
								 						execution_date, employee_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(iID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += iDate;
		sqlCommand += "', '";
		sqlCommand += iExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(iCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(iSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(curID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the inventorization creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}


	bool OrmasDal::CreateLocation(int rID, std::string lCountryName, std::string lCountryCode, std::string lRegionName,
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

	bool OrmasDal::CreateMeasure(int mID, std::string mName, std::string mShortName, int mUnit, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".measures(measure_id, measure_name, measure_short_name, measure_unit) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(mID);
		sqlCommand += ", '";
		sqlCommand += mName;
		sqlCommand += "', '";
		sqlCommand += mShortName;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(mUnit);
		sqlCommand += ");";
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

	// Create an item in order list
	bool OrmasDal::CreateOrderList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".order_list(order_list_id, order_id, product_id, count, sum, status_id,\
								 								  currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(olID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(olCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(olSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the item creation in order list is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateOrder(int oID, int uID, std::string oDate, std::string oExecDate, int eID, int oCount, double oSum, int sID, int cID,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".orders(order_id, user_id, order_date, execution_date, \
									employee_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(oID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += oDate;
		sqlCommand += "', '";
		sqlCommand += oExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
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
	
	// Create an item in order raw list
	bool OrmasDal::CreateOrderRawList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".order_raw_list(order_raw_list_id, order_raw_id, \
								 								 										product_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(olID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(olCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(olSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the item creation in order raw list is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateOrderRaw(int oID, int uID, std::string oDate, std::string oExecDate, int eID, int oCount, double oSum, int sID, int curID,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".order_raws(order_raw_id, user_id, order_raw_date, \
								 								 										execution_date, employee_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(oID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += oDate;
		sqlCommand += "', '";
		sqlCommand += oExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(curID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the order raw creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create payment
	bool OrmasDal::CreatePayment(int pID, std::string pDate, double pValue, int uID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".payments(payment_id, payment_date, payment_value, user_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", '";
		sqlCommand += pDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(pValue);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the payment creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create payslip
	bool OrmasDal::CreatePayslip(int pID, std::string pDate, double pValue, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".payslip(payslip_id, payslip_date, payslip_value, salary_id,currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", '";
		sqlCommand += pDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(pValue);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the payslip creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create Payslip-Order relation
	bool OrmasDal::CreatePayslipOrder(int pID, int oID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".payslip(payslip_id, order_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the payslip-order relation creating is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create photo
	bool OrmasDal::CreatePhoto(int pID, int uID, int prodId, std::string pSource, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".photos(photo_id, user_id, product_id, photo_source) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(prodId);
		sqlCommand += ", '";
		sqlCommand += pSource;
		sqlCommand += "');";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the photo creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create postion
	bool OrmasDal::CreatePosition(int pID, std::string pName, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".positions(position_id, position_name) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", '";
		sqlCommand += pName;
		sqlCommand += "');";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the position creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create prices
	bool OrmasDal::CreatePrice(int pID, std::string pDate, double pValue, int cID, int prodID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".prices(price_id, price_date, price_value, currency_id, product_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", '";
		sqlCommand += pDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(pValue);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(prodID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the price creation is failed, please contact with application provider!";
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
	
	bool OrmasDal::CreateProduction(int pID, std::string pProductionDate, std::string pExpiryDate, std::string pSessionStart,
		std::string pSessionEnd, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".production(production_id, production_date,\
								 								  expiry_date, session_start, session_end) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", '";
		sqlCommand += pProductionDate;
		sqlCommand += "', '";
		sqlCommand += pExpiryDate;
		sqlCommand += "', '";
		sqlCommand += pSessionStart;
		sqlCommand += "', '";
		sqlCommand += pSessionEnd;
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
	
	// Create item in production list
	bool OrmasDal::CreateProductionList(int plID, int pID, int prodID, int plCount, double plSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".production_list(production_list_id, production_id, product_id, count,\
								  sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(plID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(prodID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(plCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(plSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the item creation in production list is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateProduct(int pID, int cID, std::string pName, double vol, int mID, double price, int pTypeID, int pShelfLife, 
		int pCur, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".products(product_id, company_id, product_name, volume, measure_id,\
								 price, product_type_id, shelf_life, currency_id) VALUES(";
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
		sqlCommand += ",";
		sqlCommand += boost::lexical_cast<std::string>(pCur);
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

	// Create an item in consume product list
	bool OrmasDal::CreateReceiptProductList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".receipt_product_list(receipt_product_list_id, receipt_product_id, \
								 										product_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(rlID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rlCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rlSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the item creation in receipt product list is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateReceiptProduct(int rID, int uID, std::string rDate, std::string rExecDate, int eID, int rCount, double rSum, int sID, int curID,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".receipt_products(receipt_product_id, user_id, receipt_product_date, \
								 										execution_date, employee_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += rDate;
		sqlCommand += "', '";
		sqlCommand += rExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(curID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the receipt product creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create an item in consume raw list
	bool OrmasDal::CreateReceiptRawList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".receipt_raw_list(receipt_raw_list_id, receipt_raw_id, \
								 								 										product_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(rlID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rlCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rlSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the item creation in receipt raw list is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateReceiptRaw(int rID, int uID, std::string rDate, std::string rExecDate, int eID, int rCount, double rSum, int sID, int curID,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".receipt_raws(receipt_raw_id, user_id, receipt_raw_date, \
								 								 										execution_date, employee_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += rDate;
		sqlCommand += "', '";
		sqlCommand += rExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(curID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the receiprt raw creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create refund
	bool OrmasDal::CreateRefund(int rID, std::string rDate, double rValue, int uID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".refunds(refund_id, refund_date, refund_value, user_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", '";
		sqlCommand += rDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(rValue);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the refund creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create relation type
	bool OrmasDal::CreateRelationType(int rID, std::string rName, std::string rComment, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".relation_type(relation_type_id, relation_name, comment) VALUES(";
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
			errorMessage = "SQL command for the relation type creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create relation
	bool OrmasDal::CreateRelation(int rID, int uID1, int uID2, int rtID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".relations(relation_id, user_id_1, user_id_2, relation_type_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID1);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID2);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rtID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the relation creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateReturnList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".return_list(return_list_id, return_id, product_id, count,\
								 								  sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(rlID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rlCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rlSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the item creation in return list is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateReturn(int rID, int uID, std::string rDate, std::string rExecDate, int eID, int oCount, double oSum, int sID, int cID,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			errorMessage = "SQL command for creation company is failed, please contact with application provider!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".returns(return_id, user_id, return_date, execution_date,  employee_id,\
								  count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += rDate;
		sqlCommand += "', '";
		sqlCommand += rExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
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
	
	bool OrmasDal::CreateRole(int rID, std::string rCode, std::string rName, std::string rComment, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".roles(role_id, role_code, role_name, comment) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", '";
		sqlCommand += rCode;
		sqlCommand += "', '";
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
	
	bool OrmasDal::CreateSalary(int sID, int uID, double sValue, int cID, int stID, std::string sDate, bool sBonus, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".salaries(salary_id, user_id, salary_value, currency_id, salary_type_id, salary_date, salary_bonus) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sValue);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(stID);
		sqlCommand += ", '";
		sqlCommand += sDate;
		sqlCommand += "', ";
		sqlCommand += sBonus ? "TRUE" : "FALSE";
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the salary creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateSalaryType(int sID, std::string sCode, std::string sName, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".salary_type(salary_type_id, salary_type_code, salary_type_name) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", '";
		sqlCommand += sCode;
		sqlCommand += "', '";
		sqlCommand += sName;
		sqlCommand += "');";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the salary type creation is failed, please contact with application provider!";
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
	
	// Create stock
	bool OrmasDal::CreateStock(int sID, int pID, int sCount, double sSum, int stsID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".stock(stock_id, stock_id, \
								 								 product_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the item creation in stock is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}


	// Create an item in transport list
	bool OrmasDal::CreateTransportList(int tlID, int tID, int pID, int tlCount, double tlSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".transport_list(transport_list_id, transport_id, \
								 								 				product_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(tlID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(tID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(tlCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(tlSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the item creation in transport list is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateTransport(int tID, int uID, std::string tDate, std::string tExecDate, int eID, int tCount, double tSum, int sID, int curID,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".transports(transport_id, user_id, transport_date, \
								 							execution_date, employee_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(tID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += tDate;
		sqlCommand += "', '";
		sqlCommand += tExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(tCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(tSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(curID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the transport creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateUser(int uID, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone, std::string uAddress,
		int uRoleID, std::string uPassword, bool uActivated, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".users(user_id, user_email, user_name, user_surname, user_phone, \
								 user_address, role_id, password, activated) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += uEmail;
		sqlCommand += "', '";
		sqlCommand += uName;
		sqlCommand += "', '";
		sqlCommand += uSurname;
		sqlCommand += "', '";
		sqlCommand += uPhone;
		sqlCommand += "', '";
		sqlCommand += uAddress;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(uRoleID);
		sqlCommand += ", '";
		sqlCommand += uPassword;
		sqlCommand += "', ";
		sqlCommand += uActivated?"TRUE":"FALSE";
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
	
	// Create withdrawal
	bool OrmasDal::CreateWithdrawal(int wID, std::string wDate, double wValue, int uID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".withdrawals(withdrawal_id, withdrawal_date, withdrawal_value, user_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ", '";
		sqlCommand += wDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(wValue);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the withdrawal creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Create an item in write-off list
	bool OrmasDal::CreateWriteOffList(int wlID, int wID, int pID, int wlCount, double wlSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".write_off_list(write_off_list_id, write_off_id, product_id, count, \
																							sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(wlID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wlCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wlSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the item creation in order list is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateWriteOff(int wID, int uID, std::string wDate, int eID, int wCount, double wSum, int sID, int cID,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".write_offs(write_off_id, user_id, write_off_date, employee_id, count,\
			sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += wDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
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

	// Create an item in write-off raw list
	bool OrmasDal::CreateWriteOffRawList(int wlID, int wID, int pID, int wlCount, double wlSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".write_off_raw_list(write_off_raw_list_id, write_off_raw_id, \
								 								 								 				product_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(wlID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wlCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wlSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the item creation in write-off raw list is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::CreateWriteOffRaw(int wID, int uID, std::string wDate, int eID, int wCount, double wSum, int sID, int curID,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "INSERT INTO \"OrmasSchema\".write_off_raws(write_off_raw_id, user_id, write_off_raw_date, \
								 								 							execution_date, employee_id, count, sum, status_id, currency_id) VALUES(";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += wDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(curID);
		sqlCommand += ");";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command for the write-off raw creation is failed, please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}


	// Delete section----------------------------------------------------------------
	// Delete access item
	bool OrmasDal::DeleteAccessItem(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".access_items where access_item_id=";
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
			errorMessage = "Could not delete access item! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete access 
	bool OrmasDal::DeleteAccess(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".accesses where access_id=";
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
			errorMessage = "Could not delete access! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
	
	// Delete balance-payment
	bool OrmasDal::DeleteBalancePayment(int bID, int pID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".balance_payment where ";
		if (0 == pID)
		{
			sqlCommand += "balance_id = ";
			sqlCommand += boost::lexical_cast<std::string>(bID);
			sqlCommand += ";";
		}
		if (0 == bID)
		{
			sqlCommand += "payment_id = ";
			sqlCommand += boost::lexical_cast<std::string>(pID);
			sqlCommand += ";";
		}
		if (0 != bID && 0 != pID)
		{
			sqlCommand += "balance_id = ";
			sqlCommand += boost::lexical_cast<std::string>(bID);
			sqlCommand += " AND ";
			sqlCommand += "payment_id = ";
			sqlCommand += boost::lexical_cast<std::string>(pID);
			sqlCommand += ";";
		}
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
			errorMessage = "Could not delete balance-payment relation! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete balance-payslip
	bool OrmasDal::DeleteBalancePayslip(int bID, int pID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".balance_payslip where ";
		if (0 == pID)
		{
			sqlCommand += "balance_id = ";
			sqlCommand += boost::lexical_cast<std::string>(bID);
			sqlCommand += ";";
		}
		if (0 == bID)
		{
			sqlCommand += "payslip_id = ";
			sqlCommand += boost::lexical_cast<std::string>(pID);
			sqlCommand += ";";
		}
		if (0 != bID && 0 != pID)
		{
			sqlCommand += "balance_id = ";
			sqlCommand += boost::lexical_cast<std::string>(bID);
			sqlCommand += " AND ";
			sqlCommand += "payslip_id = ";
			sqlCommand += boost::lexical_cast<std::string>(pID);
			sqlCommand += ";";
		}
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
			errorMessage = "Could not delete balance-payslip relation! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete balance-refund
	bool OrmasDal::DeleteBalanceRefund(int bID, int rID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".balance_refund where ";
		if (0 == rID)
		{
			sqlCommand += "balance_id = ";
			sqlCommand += boost::lexical_cast<std::string>(bID);
			sqlCommand += ";";
		}
		if (0 == bID)
		{
			sqlCommand += "refund_id = ";
			sqlCommand += boost::lexical_cast<std::string>(rID);
			sqlCommand += ";";
		}
		if (0 != bID && 0 != rID)
		{
			sqlCommand += "balance_id = ";
			sqlCommand += boost::lexical_cast<std::string>(bID);
			sqlCommand += " AND ";
			sqlCommand += "refund_id = ";
			sqlCommand += boost::lexical_cast<std::string>(rID);
			sqlCommand += ";";
		}
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
			errorMessage = "Could not delete balance-refund relation! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete balance-withdrawal
	bool OrmasDal::DeleteBalanceWithdrawal(int bID, int wID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".balance_withdrawal where ";
		if (0 == wID)
		{
			sqlCommand += "balance_id = ";
			sqlCommand += boost::lexical_cast<std::string>(bID);
			sqlCommand += ";";
		}
		if (0 == bID)
		{
			sqlCommand += "withdrawal_id = ";
			sqlCommand += boost::lexical_cast<std::string>(wID);
			sqlCommand += ";";
		}
		if (0 != bID && 0 != wID)
		{
			sqlCommand += "balance_id = ";
			sqlCommand += boost::lexical_cast<std::string>(bID);
			sqlCommand += " AND ";
			sqlCommand += "withdrawal_id = ";
			sqlCommand += boost::lexical_cast<std::string>(wID);
			sqlCommand += ";";
		}
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
			errorMessage = "Could not delete balance-withdrawal relation! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete balance
	bool OrmasDal::DeleteBalance(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".balances where balance_id=";
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
			errorMessage = "Could not delete balance! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
	
	// Delete clients
	bool OrmasDal::DeleteClient(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".clients where user_id=";
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
			errorMessage = "Could not delete client! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
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
	
	// Delete item in consume product list
	bool OrmasDal::DeleteItemInConsumeProductList(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".consume_product_list where consume_product_list_id=";
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
			errorMessage = "Could not delete item from consume product list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete list in consume product list by consume product id
	bool OrmasDal::DeleteListByConsumeProductID(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".consume_product_list where consume_product_id=";
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
			errorMessage = "Could not delete item from consume product list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete consume product
	bool OrmasDal::DeleteConsumeProduct(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}

		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".consume_products where consume_product_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete consume product! SQL command is failed. Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	
	// Delete item in consume raw list
	bool OrmasDal::DeleteItemInConsumeRawList(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".consume_raw_list where consume_raw_list_id=";
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
			errorMessage = "Could not delete item from consume raw list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete list in consume raw list by consume raw id
	bool OrmasDal::DeleteListByConsumeRawID(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".consume_raw_list where consume_raw_id=";
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
			errorMessage = "Could not delete item from consume product list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete consume raw
	bool OrmasDal::DeleteConsumeRaw(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}

		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".consume_raws where consume_raw_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete consume raw! SQL command is failed. Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
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
	// Delete employee
	bool OrmasDal::DeleteEmployee(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".employees where user_id=";
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
			errorMessage = "Could not delete empoyee! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete item in inventorization list
	bool OrmasDal::DeleteItemInInventorizationList(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".inventorization_list where inventorization_list_id=";
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
			errorMessage = "Could not delete item from inventorization list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete list in inventorization list by inventorization id
	bool OrmasDal::DeleteListByInventorizationID(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".inventorization_list where inventorization_id=";
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
			errorMessage = "Could not delete item from inventorization list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete inventorization
	bool OrmasDal::DeleteInventorization(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}

		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".inventorizations where inventorization_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete inventorization! SQL command is failed. Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
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
	
	// Delete item in order list
	bool OrmasDal::DeleteItemInOrderList(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".order_list where order_list_id=";
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
			errorMessage = "Could not delete item from order list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
	
	// Delete list in order list by order id
	bool OrmasDal::DeleteListByOrderID(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".order_list where order_id=";
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
			errorMessage = "Could not delete item from order list! SQL command is failed. Please contact with application provider!";
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
		
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".orders where order_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete order! SQL command is failed. Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Delete item in order raw list
	bool OrmasDal::DeleteItemInOrderRawList(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".order_raw_list where order_raw_list_id=";
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
			errorMessage = "Could not delete item from order raw list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete list in order raw list by order raw id
	bool OrmasDal::DeleteListByOrderRawID(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".order_raw_list where order_raw_id=";
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
			errorMessage = "Could not delete item from order raw list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete order
	bool OrmasDal::DeleteOrderRaw(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}

		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".order_raws where order_raw_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete order raw! SQL command is failed. Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	
	// Delete payment
	bool OrmasDal::DeletePayment(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".payments where payment_id=";
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
			errorMessage = "Could not delete payment! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete payment
	bool OrmasDal::DeletePayslip(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".payslips where payslip_id=";
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
			errorMessage = "Could not delete payslip! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete payslip-order
	bool OrmasDal::DeletePayslipOrder(int pID, int oID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".payslip_order where ";
		if (0 == oID)
		{
			sqlCommand += "payslip_id = ";
			sqlCommand += boost::lexical_cast<std::string>(pID);
			sqlCommand += ";";
		}
		if (0 == pID)
		{
			sqlCommand += "order_id = ";
			sqlCommand += boost::lexical_cast<std::string>(oID);
			sqlCommand += ";";
		}
		if (0 != oID && 0 != oID)
		{
			sqlCommand += "payslip_id = ";
			sqlCommand += boost::lexical_cast<std::string>(pID);
			sqlCommand += " AND ";
			sqlCommand += "order_id = ";
			sqlCommand += boost::lexical_cast<std::string>(oID);
			sqlCommand += ";";
		}
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
			errorMessage = "Could not delete payslip-order relation! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete photo
	bool OrmasDal::DeletePhoto(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".photos where photo_id=";
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
			errorMessage = "Could not delete photo! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete position
	bool OrmasDal::DeletePosition(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".positions where position_id=";
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
			errorMessage = "Could not delete position! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete price
	bool OrmasDal::DeletePrice(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".prices where price_id=";
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
			errorMessage = "Could not delete price! SQL command is failed. Please contact with application provider!";
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

	// Delete production
	bool OrmasDal::DeleteProduction(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".production where production_id=";
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
	
	// Delete item in production list
	bool OrmasDal::DeleteItemInProductionList(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".production_list where production_list_id=";
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
			errorMessage = "Could not delete item in production list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete list in production list by production id
	bool OrmasDal::DeleteListByProductionID(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".production_list where production_id=";
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
			errorMessage = "Could not delete item from production list! SQL command is failed. Please contact with application provider!";
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
	
	// Delete item in receipt product list
	bool OrmasDal::DeleteItemInReceiptProductList(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".receipt_product_list where receipt_product_list_id=";
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
			errorMessage = "Could not delete item from receipt product list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete list in receipt product list by receipt product id
	bool OrmasDal::DeleteListByReceiptProductID(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".receipt_product_list where receipt_product_id=";
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
			errorMessage = "Could not delete item from receipt product list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete consume product
	bool OrmasDal::DeleteReceiptProduct(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}

		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".receipt_products where receipt_product_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete receipt product! SQL command is failed. Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}


	// Delete list in receipt raw list by receipt raw id
	bool OrmasDal::DeleteListByReceiptRawID(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".receipt_raw_list where receipt_raw_id=";
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
			errorMessage = "Could not delete item from receipt raw list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete item in receipt raw list
	bool OrmasDal::DeleteItemInReceiptRawList(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".receipt_raw_list where receipt_raw_list_id=";
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
			errorMessage = "Could not delete item from receipt raw list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete receipt raw
	bool OrmasDal::DeleteReceiptRaw(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}

		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".receipt_raws where receipt_raw_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete receipt raw! SQL command is failed. Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Delete refund
	bool OrmasDal::DeleteRefund(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".refunds where payslip_id=";
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
			errorMessage = "Could not delete refund! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete relation type
	bool OrmasDal::DeleteRelationType(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".relation_type where relation_type_id=";
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
			errorMessage = "Could not delete relation type! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete relation
	bool OrmasDal::DeleteRelation(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".relations where relation_id=";
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

	// Delete item in return list
	bool OrmasDal::DeleteItemInReturnList(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".return_list where return_list_id=";
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
			errorMessage = "Could not delete item in return list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
	// Delete list in return list by return id
	bool OrmasDal::DeleteListByReturnID(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".return_list where return_id=";
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
			errorMessage = "Could not delete item from return list! SQL command is failed. Please contact with application provider!";
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
		
		PGresult * result;
		//cascading detele
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".returns where return_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete return! SQL command is failed. Please contact with application provider!";
			return false;
		}
		PQclear(result);
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
	
	// Delete salary
	bool OrmasDal::DeleteSalary(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".salaries where salary_id=";
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
			errorMessage = "Could not delete salary! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete salary type
	bool OrmasDal::DeleteSalaryType(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".salary_type where salary_type_id=";
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
			errorMessage = "Could not delete salary type! SQL command is failed. Please contact with application provider!";
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
	
	// Delete item in stock
	bool OrmasDal::DeleteStock(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".stock where stock_id=";
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
			errorMessage = "Could not delete item from stock! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete item in transport list
	bool OrmasDal::DeleteItemInTransportList(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".transport_list where transport_list_id=";
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
			errorMessage = "Could not delete item from transport list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete list in transport list by transport id
	bool OrmasDal::DeleteListByTransportID(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".transport_list where transport_id=";
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
			errorMessage = "Could not delete item from transport list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete transport
	bool OrmasDal::DeleteTransport(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}

		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".transports where transport_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete transport! SQL command is failed. Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
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

	// Delete payment
	bool OrmasDal::DeleteWithdrawal(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".withdrawals where withdrawal_id=";
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
			errorMessage = "Could not delete withdrawal! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}
	
	// Delete item in write-off list
	bool OrmasDal::DeleteItemInWriteOffList(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".write_off_list where write_off_list_id=";
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
			errorMessage = "Could not delete item from write-off list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	bool OrmasDal::DeleteListByWriteOffID(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".write_off_list where write_off_id=";
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
			errorMessage = "Could not delete item from write-off list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete write-off
	bool OrmasDal::DeleteWriteOff(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".write_offs where write_off_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete write-off! SQL command is failed. Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::DeleteListByWriteOffRawID(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".write_off_raw_list where write_off_raw_id=";
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
			errorMessage = "Could not delete item from write-off raw list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}


	// Delete item in write-off raw list
	bool OrmasDal::DeleteItemInWriteOffRawList(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".write_off_raw_list where write_off_raw_list_id=";
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
			errorMessage = "Could not delete item from write off raw list! SQL command is failed. Please contact with application provider!";
			return false;
		}
	}

	// Delete transport
	bool OrmasDal::DeleteWriteOffRaw(int id, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}

		PGresult * result;
		std::string sqlCommand = "DELETE FROM \"OrmasSchema\".write_off_raws where write_off_raw_id=";
		sqlCommand += boost::lexical_cast<std::string>(id);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());
		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "Could not delete write off raw! SQL command is failed. Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Update section----------------------------------------------------------------
	
	bool OrmasDal::UpdateAccessItem(int aID, std::string aItemEng, std::string aItemRu, std::string aDivision, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".access_items SET(access_item_eng, access_item_ru, access_division) = ('";
		sqlCommand += aItemEng;
		sqlCommand += "', '";
		sqlCommand += aItemRu;
		sqlCommand += "', '";
		sqlCommand += aDivision;
		sqlCommand += "') WHERE access_item_id=";
		sqlCommand += boost::lexical_cast<std::string>(aID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the access item with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(aID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	//Update access
	bool OrmasDal::UpdateAccess(int aID, int rID, int aiID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".accesses SET(role_id, access_item_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(aiID);
		sqlCommand += ") WHERE access_id=";
		sqlCommand += boost::lexical_cast<std::string>(aID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the access with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(aID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	
	//Update balance
	bool OrmasDal::UpdateBalance(int bID, int uID, double bValue, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".balances SET(user_id, balance_value, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(bValue);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE balance_id=";
		sqlCommand += boost::lexical_cast<std::string>(bID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the balance with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(bID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	
	bool OrmasDal::UpdateClient(int uID, std::string cFirm, std::string cFirmNumber, int lID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".clients SET(firm, firm_number, location_id) = ('";
		sqlCommand += cFirm;
		sqlCommand += "', '";
		sqlCommand += cFirmNumber;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(lID);
		sqlCommand += ") WHERE user_id=";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the client with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(uID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

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
	
	bool OrmasDal::UpdateConsumeProductList(int clID, int cpID, int pID, int clCount, double clSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".consume_product_list SET(consume_product_id, product_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(cpID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(clCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(clSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE consume_product_list_id=";
		sqlCommand += boost::lexical_cast<std::string>(clID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the item in consume product list with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(clID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateConsumeProduct(int cID, int uID, std::string cDate, std::string cExecDate, int eID, 
			int cCount, double cSum, int sID, int currID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".consume_products SET(user_id, consume_product_date, execution_date, employee_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += cDate;
		sqlCommand += "', '";
		sqlCommand += cExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(currID);
		sqlCommand += ") WHERE consume_product_id=";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the consume product with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(cID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateConsumeRawList(int clID, int cpID, int pID, int clCount, double clSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".consume_raw_list SET(consume_raw_id, product_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(cpID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(clCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(clSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE consume_raw_list_id=";
		sqlCommand += boost::lexical_cast<std::string>(clID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the item in consume raw list with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(clID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateConsumeRaw(int cID, int uID, std::string cDate, std::string cExecDate, int eID,
		int cCount, double cSum, int sID, int currID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".consume_raws SET(user_id, consume_raw_date, execution_date, employee_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += cDate;
		sqlCommand += "', '";
		sqlCommand += cExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(currID);
		sqlCommand += ") WHERE consume_raw_id=";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the consume raw with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(cID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateCurrency(int cID, int cCode, std::string cShortName, std::string cName, int cUnit, bool cMainTrade,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".currencies SET(currency_code, currency_short_name, \
								  currency_name, currency_unit, currency_main_trade) = (";
		sqlCommand += boost::lexical_cast<std::string>(cCode);
		sqlCommand += ", '";
		sqlCommand += cShortName;
		sqlCommand += "', '";
		sqlCommand += cName;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(cUnit);
		sqlCommand += ", ";
		sqlCommand += cMainTrade? "TRUE" : "FALSE";
		sqlCommand += ") WHERE currency_id=";
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
	
	bool OrmasDal::UpdateEmployee(int uID, int pID, std::string eBirthDate, std::string eHireDate, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".employees SET(position_id, birth_date, hire_date) = (";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", '";
		sqlCommand += eBirthDate;
		sqlCommand += "', '";
		sqlCommand += eHireDate;
		sqlCommand += "') WHERE user_id=";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the employee with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(uID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateInventorizationList(int ilID, int iID, int pID, int ilCount, double ilSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".inventorization_list SET(inventorization_id, product_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(iID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(ilCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(ilSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE inventorization_list_id=";
		sqlCommand += boost::lexical_cast<std::string>(ilID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the item in inventorization list with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(ilID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateInventorization(int iID, int uID, std::string iDate, std::string iExecDate, int eID,
		int iCount, double iSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".inventorizations SET(user_id, inventorization_date, execution_date, employee_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += iDate;
		sqlCommand += "', '";
		sqlCommand += iExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(iCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(iSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE inventorization_id=";
		sqlCommand += boost::lexical_cast<std::string>(iID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the inventorization with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(iID);
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


	bool OrmasDal::UpdateMeasure(int mID, std::string mName, std::string mShortName, int mUnit, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".measures SET(measure_name, measure_short_name, measure_unit) = ('";
		sqlCommand += mName;
		sqlCommand += "', '";
		sqlCommand += mShortName;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(mUnit);
		sqlCommand += ") WHERE measure_id=";
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

	bool OrmasDal::UpdateOrderList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".order_list SET(order_id, product_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(oID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(olCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(olSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE order_list_id=";
		sqlCommand += boost::lexical_cast<std::string>(olID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the intem in order list with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(olID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateOrder(int oID, int uID, std::string oDate, std::string oExecDate, int eID, int oCount, double oSum, int sID, int cID,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".orders SET(user_id, order_date, execution_date, employee_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += oDate;
		sqlCommand += "', '";
		sqlCommand += oExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE order_id=";
		sqlCommand += boost::lexical_cast<std::string>(oID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the order with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(oID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateOrderRawList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".order_raw_list SET(order_raw_id, product_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(oID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(olCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(olSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE order_raw_list_id=";
		sqlCommand += boost::lexical_cast<std::string>(olID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the item in order raw list with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(olID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateOrderRaw(int oID, int uID, std::string oDate, std::string oExecDate, int eID,
		int oCount, double oSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".order_raws SET(user_id, order_raw_date, execution_date, employee_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += oDate;
		sqlCommand += "', '";
		sqlCommand += oExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE order_raw_id=";
		sqlCommand += boost::lexical_cast<std::string>(oID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the order raw with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(oID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	
	bool OrmasDal::UpdatePayment(int pID, std::string pDate, double pValue, int uID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".payments SET(payment_date, payment_value, user_id, currency_id) = ('";
		sqlCommand += pDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(pValue);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE payment_id=";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the payment with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(pID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdatePayslip(int pID, std::string pDate, double pValue, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".payslips SET(payslip_date, payslip_value, salary_id, currency_id) = ('";
		sqlCommand += pDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(pValue);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE payslip_id=";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the payslip with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(pID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdatePhoto(int pID, int uID, int prodId, std::string pSource, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".photos SET(user_id, product_id, photo_source) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(prodId);
		sqlCommand += ", '";
		sqlCommand += pSource;
		sqlCommand += "') WHERE photo_id=";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the photo with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(pID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}


	bool OrmasDal::UpdatePosition(int pID, std::string pName, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".positions SET(position_name) = ('";
		sqlCommand += pName;
		sqlCommand += "') WHERE position_id=";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the position with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(pID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdatePrice(int pID, std::string pDate, double pValue, int cID, int prodID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".prices SET(price_date, price_value, currency_id, product_id) = ('";
		sqlCommand += pDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(pValue);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(prodID);
		sqlCommand += ") WHERE price_id=";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the payment with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(pID);
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

	bool OrmasDal::UpdateProduction(int pID, std::string pProductionDate, std::string pExpiryDate, std::string pSessionStart,
		std::string pSessionEnd, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".production SET(production_date, expiry_date,\
								 								  session_start, session_end) = ('";
		sqlCommand += pProductionDate;
		sqlCommand += "', '";
		sqlCommand += pExpiryDate;
		sqlCommand += "', '";
		sqlCommand += pSessionStart;
		sqlCommand += "', '";
		sqlCommand += pSessionEnd;
		sqlCommand += "') WHERE product_type_id=";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the product type with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(pID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}
	
	bool OrmasDal::UpdateProductionList(int plID, int pID, int prodID, int plCount, double plSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".production_list SET(production_id, product_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(prodID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(plCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(plSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE production_list_id=";
		sqlCommand += boost::lexical_cast<std::string>(plID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the intem in production list with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(plID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateProduct(int pID, int cID, std::string pName, double vol, int mID, double price, int pTypeID, int pShelfLife, 
		int pCur,std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".products SET(company_id, product_name, volume, measure_id,\
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
	
	bool OrmasDal::UpdateReceiptProductList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".receipt_product_list SET(receipt_product_id, product_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rlCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rlSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE receipt_product_list_id=";
		sqlCommand += boost::lexical_cast<std::string>(rlID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the item in receipt product list with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(rlID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateReceiptProduct(int rID, int uID, std::string rDate, std::string rExecDate, int eID,
		int rCount, double rSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".receipt_products SET(user_id, receipt_product_date, execution_date, employee_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += rDate;
		sqlCommand += "', '";
		sqlCommand += rExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE receipt_product_id=";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the receipt product with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(rID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateReceiptRawList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".receipt_raw_list SET(receipt_raw_id, product_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rlCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rlSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE receipt_raw_list_id=";
		sqlCommand += boost::lexical_cast<std::string>(rlID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the item in receipt raw list with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(rlID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateReceiptRaw(int rID, int uID, std::string rDate, std::string rExecDate, int eID,
		int rCount, double rSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".receipt_raws SET(user_id, receipt_raw_date, execution_date, employee_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += rDate;
		sqlCommand += "', '";
		sqlCommand += rExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE receipt_raw_id=";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the receipt raw with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(rID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateRefund(int rID, std::string rDate, double rValue, int uID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".refunds SET(refund_date, refund_value, user_id, currency_id) = ('";
		sqlCommand += rDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(rValue);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE refund_id=";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the refund with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(rID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateRelationType(int rID, std::string rName, std::string rComment, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".relation_type SET(relation_name, comment) = ('";
		sqlCommand += rName;
		sqlCommand += "', '";
		sqlCommand += rComment;
		sqlCommand += "') WHERE relation_type_id=";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the relation type with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(rID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateRelation(int rID, int uID1, int uID2, int rtID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".relations SET(user_id_1, user_id_2, relation_type_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID1);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID2);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rtID);
		sqlCommand += ") WHERE relation_id=";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the relation with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(rID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateReturnList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".return_list SET(return_id, product_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(rID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rlCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(rlSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE return_list_id=";
		sqlCommand += boost::lexical_cast<std::string>(rlID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the intem in return list with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(rlID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateReturn(int rID, int uID, std::string rDate, std::string rExecDate, int eID, int oCount, double oSum, int sID, int cID,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".returns SET(user_id, return_date, execution_date, employee_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += rDate;
		sqlCommand += "', '";
		sqlCommand += rExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(oSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
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
	
	bool OrmasDal::UpdateRole(int rID, std::string rCode,std::string rName, std::string rComment, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".roles SET(role_code, role_name, comment) = ('";
		sqlCommand += rCode;
		sqlCommand += "', '";
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

	bool OrmasDal::UpdateSalary(int sID, int uID, double sValue, int cID, int stID, std::string sDate, bool sBonus, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".salaries SET(user_id, salary_value, currency_id, salary_type_id, salary_date, salary_bonus) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sValue);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(stID);
		sqlCommand += ", '";
		sqlCommand += sDate;
		sqlCommand += "',";
		sqlCommand += sBonus ? "TRUE" : "FALSE";
		sqlCommand += ") WHERE salary_id=";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the salary with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(uID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateSalaryType(int sID, std::string sCode, std::string sName, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".salary_type SET(salary_type_code, salary_type_name) = ('";
		sqlCommand += sCode;
		sqlCommand += "', '";
		sqlCommand += sName;
		sqlCommand += "') WHERE salary_type_id=";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the salary type with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(sID);
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
	
	bool OrmasDal::UpdateStock(int sID, int pID, int sCount, double sSum, int stsID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".stock SET(stock_id, product_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(stsID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE stock_id=";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the item in stock with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(sID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateTransportList(int tlID, int tID, int pID, int tlCount, double tlSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".transport_list SET(transport_id, product_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(tID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(tlCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(tlSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE transport_list_id=";
		sqlCommand += boost::lexical_cast<std::string>(tlID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the item in transport list with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(tlID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateTransport(int tID, int uID, std::string tDate, std::string tExecDate, int eID,
		int tCount, double tSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".transports SET(user_id, transport_date, execution_date, employee_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += tDate;
		sqlCommand += "', '";
		sqlCommand += tExecDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(tCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(tSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE transport_id=";
		sqlCommand += boost::lexical_cast<std::string>(tID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the transport with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(tID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateUser(int uID, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone, std::string uAddress,
		int uRoleID, std::string uPassword, bool uActivated, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".users SET(user_email, user_name, user_surname, user_phone, user_address, \
								 role_id, password, activated) = ('";
		sqlCommand += uEmail;
		sqlCommand += "', '";
		sqlCommand += uName;
		sqlCommand += "', '";
		sqlCommand += uSurname;
		sqlCommand += "', '";
		sqlCommand += uPhone;
		sqlCommand += "', '";
		sqlCommand += uAddress;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(uRoleID);
		sqlCommand += ", '";
		sqlCommand += uPassword;
		sqlCommand += "',";
		sqlCommand += uActivated ? "TRUE" : "FALSE";
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

	bool OrmasDal::UpdateWithdrawal(int wID, std::string wDate, double wValue, int uID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".withdrawals SET(withdrawal_date, withdrawal_value, user_id, currency_id) = ('";
		sqlCommand += wDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(wValue);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE withdrawal_id=";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the withdrawal with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(wID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateWriteOffList(int wlID, int wID, int pID, int wlCount, double wlSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".write_off_list SET(write_off_id, product_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wlCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wlSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE write_off_list_id=";
		sqlCommand += boost::lexical_cast<std::string>(wlID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the item in write-off list with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(wlID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateWriteOff(int wID, int uID, std::string wDate, int eID, int wCount, double wSum, int sID, int cID,
		std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".write-offs SET(user_id, write_off_date, employee_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += wDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE write_off_id=";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the company with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(wID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateWriteOffRawList(int wlID, int wID, int pID, int wlCount, double wlSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".write_off_raw_list SET(write_off_raw_id, product_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(pID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wlCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wlSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE write_off_raw_list_id=";
		sqlCommand += boost::lexical_cast<std::string>(wlID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the item in write_off_raw list with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(wlID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	bool OrmasDal::UpdateWriteOffRaw(int wID, int uID, std::string wDate, int eID,
		int wCount, double wSum, int sID, int cID, std::string& errorMessage)
	{
		if (PQstatus(dbCon) == CONNECTION_BAD)
		{
			errorMessage = "DB connection was lost! Please restart application!";
			return false;
		}
		PGresult * result;
		std::string sqlCommand = "UPDATE \"OrmasSchema\".write_off_raws SET(user_id, write_off_raw_date, execution_date, employee_id, count, sum, status_id, currency_id) = (";
		sqlCommand += boost::lexical_cast<std::string>(uID);
		sqlCommand += ", '";
		sqlCommand += wDate;
		sqlCommand += "', ";
		sqlCommand += boost::lexical_cast<std::string>(eID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wCount);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(wSum);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(sID);
		sqlCommand += ", ";
		sqlCommand += boost::lexical_cast<std::string>(cID);
		sqlCommand += ") WHERE write_off_raw_id=";
		sqlCommand += boost::lexical_cast<std::string>(wID);
		sqlCommand += ";";
		result = PQexec(dbCon, sqlCommand.c_str());

		if (PQresultStatus(result) != PGRES_COMMAND_OK)
		{
			std::string logStr = PQresultErrorMessage(result);
			//WriteLog(logStr);
			PQclear(result);
			errorMessage = "SQL command is failing while updating the write off raw with this ID = ";
			errorMessage += boost::lexical_cast<std::string>(wID);
			errorMessage += " .Please contact with application provider!";
			return false;
		}
		PQclear(result);
		return true;
	}

	// Fillter section ----------------------------------------------
	
	std::string OrmasDal::GetFilterForAccessItem(int aID, std::string aItemEng, std::string aItemRu, std::string aDivision)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != aID)
		{
			tempString = "";
			tempString += "access_item_id = ";
			tempString += boost::lexical_cast<std::string>(aID);
			conditionVec.push_back(tempString);
		}
		if (!aItemEng.empty())
		{
			tempString = "";
			tempString += " access_item_eng = '";
			tempString += aItemEng;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!aItemRu.empty())
		{
			tempString = "";
			tempString += " access_item_ru = '";
			tempString += aItemRu;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!aDivision.empty())
		{
			tempString = "";
			tempString += " access_division = '";
			tempString += aDivision;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForAccess(int aID, int rID, int aiID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != aID)
		{
			tempString = "";
			tempString += " access_id = ";
			tempString += boost::lexical_cast<std::string>(aID);
			conditionVec.push_back(tempString);
		}
		if (0 != rID)
		{
			tempString = "";
			tempString += " role_id = ";
			tempString += boost::lexical_cast<std::string>(rID);
			conditionVec.push_back(tempString);
		}
		if (0 != aiID)
		{
			tempString = "";
			tempString += " access_item_id = ";
			tempString += boost::lexical_cast<std::string>(aiID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}


	std::string OrmasDal::GetFilterForBalancePayment(int bID, int pID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != bID)
		{
			tempString = "";
			tempString += " balance_id = ";
			tempString += boost::lexical_cast<std::string>(bID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " payment_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForBalancePayslip(int bID, int pID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != bID)
		{
			tempString = "";
			tempString += " balance_id = ";
			tempString += boost::lexical_cast<std::string>(bID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " payslip_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForBalanceRefund(int bID, int rID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != bID)
		{
			tempString = "";
			tempString += " balance_id = ";
			tempString += boost::lexical_cast<std::string>(bID);
			conditionVec.push_back(tempString);
		}
		if (0 != rID)
		{
			tempString = "";
			tempString += " refund_id = ";
			tempString += boost::lexical_cast<std::string>(rID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForBalanceWithdrawal(int bID, int wID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != bID)
		{
			tempString = "";
			tempString += " balance_id = ";
			tempString += boost::lexical_cast<std::string>(bID);
			conditionVec.push_back(tempString);
		}
		if (0 != wID)
		{
			tempString = "";
			tempString += " withdrawal_id = ";
			tempString += boost::lexical_cast<std::string>(wID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	/// \brief	Gets filter for balance.
	///
	/// \param bID   	The identifier.
	/// \param uID   	The identifier.
	/// \param bValue	The value.
	/// \param cID   	The identifier.
	///
	/// \return	The filter for balance.

	std::string OrmasDal::GetFilterForBalance(int bID, int uID, double bValue, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != bID)
		{
			tempString = "";
			tempString += " balance_id = ";
			tempString += boost::lexical_cast<std::string>(bID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (0 != bValue)
		{
			tempString = "";
			tempString += " balance_value = ";
			tempString += boost::lexical_cast<std::string>(bValue);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForClient(int cID, std::string uName, std::string uSurname, std::string uPhone,
		std::string uAddress, std::string cFirm, std::string cFirmNumber, std::string uPassword, std::string uEmail,
		bool uActivated, int rID, int lID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != cID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (!uName.empty())
		{
			tempString = "";
			tempString += " user_name = '";
			tempString += uName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!uSurname.empty())
		{
			tempString = "";
			tempString += " user_surname = '";
			tempString += uSurname;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!uPhone.empty())
		{
			tempString = "";
			tempString += " user_phone = '";
			tempString += uPhone;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!uAddress.empty())
		{
			tempString = "";
			tempString += " user_address = '";
			tempString += uAddress;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!cFirm.empty())
		{
			tempString = "";
			tempString += " firm = '";
			tempString += cFirm;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!cFirmNumber.empty())
		{
			tempString = "";
			tempString += " firm_number LIKE '%";
			tempString += cFirmNumber;
			tempString += "%'";
			conditionVec.push_back(tempString);
		}
		if (!uPassword.empty())
		{
			tempString = "";
			tempString += " password = '";
			tempString += uPassword;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!uEmail.empty())
		{
			tempString = "";
			tempString += " user_email = '";
			tempString += uEmail;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != lID)
		{
			tempString = "";
			tempString += " location_id = ";
			tempString += boost::lexical_cast<std::string>(lID);
			conditionVec.push_back(tempString);
		}
		if (0 != rID)
		{
			tempString = "";
			tempString += " role_id = ";
			tempString += boost::lexical_cast<std::string>(rID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}
	/// \brief	Gets filter for company.C
	///
	/// \param cID	   	The identifier.
	/// \param cName   	The name.
	/// \param cAddress	The address.
	/// \param cPhone  	The phone.
	/// \param cComment	The comment.
	///
	/// \return	The filter for company.

	std::string OrmasDal::GetFilterForCompany(int cID, std::string cName, std::string cAddress, std::string cPhone, std::string cComment)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != cID)
		{
			tempString = "";
			tempString += "company_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (!cName.empty())
		{
			tempString = "";
			tempString += " company_name = '";
			tempString += cName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!cAddress.empty())
		{
			tempString = "";
			tempString += " company_address = '";
			tempString += cAddress;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!cPhone.empty())
		{
			tempString = "";
			tempString += " company_phone = '";
			tempString += cPhone;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!cComment.empty())
		{
			tempString = "";
			tempString += " comment LIKE '%";
			tempString += cComment;
			tempString += "%'";
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForConsumeProductList(int clID, int cpID, int pID, int clCount, double clSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != clID)
		{
			tempString = "";
			tempString += " consume_product_list_id = ";
			tempString += boost::lexical_cast<std::string>(clID);
			conditionVec.push_back(tempString);
		}
		if (0 != cpID)
		{
			tempString = "";
			tempString += " consume_product_id = ";
			tempString += boost::lexical_cast<std::string>(cpID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != clCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(clCount);
			conditionVec.push_back(tempString);
		}
		if (0 != clSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(clSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForConsumeProduct(int cID, int uID, std::string cDate, std::string cExecDate, int eID, int cCount,
		double cSum, int sID, int currID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != cID)
		{
			tempString = "";
			tempString += " consume_product_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (!cDate.empty())
		{
			tempString = "";
			tempString += " consume_product_date = '";
			tempString += cDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!cExecDate.empty())
		{
			tempString = "";
			tempString += " execution_date = '";
			tempString += cExecDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != eID)
		{
			tempString = "";
			tempString += " employee_id = ";
			tempString += boost::lexical_cast<std::string>(eID);
			conditionVec.push_back(tempString);
		}
		if (0 != cCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(cCount);
			conditionVec.push_back(tempString);
		}
		if (0 != cSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(cSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(currID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForConsumeRawList(int clID, int cpID, int pID, int clCount, double clSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != clID)
		{
			tempString = "";
			tempString += " consume_raw_list_id = ";
			tempString += boost::lexical_cast<std::string>(clID);
			conditionVec.push_back(tempString);
		}
		if (0 != cpID)
		{
			tempString = "";
			tempString += " consume_raw_id = ";
			tempString += boost::lexical_cast<std::string>(cpID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != clCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(clCount);
			conditionVec.push_back(tempString);
		}
		if (0 != clSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(clSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForConsumeRaw(int cID, int uID, std::string cDate, std::string cExecDate, int eID, int cCount,
		double cSum, int sID, int currID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != cID)
		{
			tempString = "";
			tempString += " consume_raw_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (!cDate.empty())
		{
			tempString = "";
			tempString += " consume_raw_date = '";
			tempString += cDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!cExecDate.empty())
		{
			tempString = "";
			tempString += " execution_date = '";
			tempString += cExecDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != eID)
		{
			tempString = "";
			tempString += " employee_id = ";
			tempString += boost::lexical_cast<std::string>(eID);
			conditionVec.push_back(tempString);
		}
		if (0 != cCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(cCount);
			conditionVec.push_back(tempString);
		}
		if (0 != cSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(cSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(currID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForCurrency(int cID, int cCode, std::string cShortName, std::string cName, int cUnit)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (0 != cCode)
		{
			tempString = "";
			tempString += " currency_code = ";
			tempString += cCode;
			conditionVec.push_back(tempString);
		}
		if (!cShortName.empty())
		{
			tempString = "";
			tempString += " currency_short_name = '";
			tempString += cShortName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!cName.empty())
		{
			tempString = "";
			tempString += " currency_name = '";
			tempString += cName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != cUnit)
		{
			tempString = "";
			tempString += " currency_unit = ";
			tempString += boost::lexical_cast<std::string>(cUnit);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}
	
	std::string OrmasDal::GetFilterForEmployee(int eID, std::string uName, std::string uSurname, std::string uPhone,
		std::string uAddress, std::string eBirthDate, std::string eHireDate, std::string uPassword,
		std::string uEmail, bool uActivated, int rID, int pID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != eID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(eID);
			conditionVec.push_back(tempString);
		}
		if (!uName.empty())
		{
			tempString = "";
			tempString += " user_name = '";
			tempString += uName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!uSurname.empty())
		{
			tempString = "";
			tempString += " user_surname = '";
			tempString += uSurname;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!uPhone.empty())
		{
			tempString = "";
			tempString += " user_phone = '";
			tempString += uPhone;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!uAddress.empty())
		{
			tempString = "";
			tempString += " user_address = '";
			tempString += uAddress;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!eBirthDate.empty())
		{
			tempString = "";
			tempString += " birth_date = '";
			tempString += eBirthDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!eHireDate.empty())
		{
			tempString = "";
			tempString += " hire_date = '";
			tempString += eHireDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!uPassword.empty())
		{
			tempString = "";
			tempString += " password = '";
			tempString += uPassword;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!uEmail.empty())
		{
			tempString = "";
			tempString += " user_email = '";
			tempString += uEmail;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != rID)
		{
			tempString = "";
			tempString += " role_id = ";
			tempString += boost::lexical_cast<std::string>(rID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " position_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForInventorizationList(int ilID, int iID, int pID, int ilCount, double ilSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != ilID)
		{
			tempString = "";
			tempString += " inventorization_list_id = ";
			tempString += boost::lexical_cast<std::string>(ilID);
			conditionVec.push_back(tempString);
		}
		if (0 != iID)
		{
			tempString = "";
			tempString += " inventorization_id = ";
			tempString += boost::lexical_cast<std::string>(iID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != ilCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(ilCount);
			conditionVec.push_back(tempString);
		}
		if (0 != ilSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(ilSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForInventorization(int iID, int uID, std::string iDate, std::string iExecDate, int eID, int iCount,
		double iSum, int sID, int currID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != iID)
		{
			tempString = "";
			tempString += " inventorization_id = ";
			tempString += boost::lexical_cast<std::string>(iID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (!iDate.empty())
		{
			tempString = "";
			tempString += " inventorization_date = '";
			tempString += iDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!iExecDate.empty())
		{
			tempString = "";
			tempString += " execution_date = '";
			tempString += iExecDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != eID)
		{
			tempString = "";
			tempString += " employee_id = ";
			tempString += boost::lexical_cast<std::string>(eID);
			conditionVec.push_back(tempString);
		}
		if (0 != iCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(iCount);
			conditionVec.push_back(tempString);
		}
		if (0 != iSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(iSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != currID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(currID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}


	std::string OrmasDal::GetFilterForLocation(int lID, std::string lCountryName, std::string lCountryCode, std::string lRegionName
		, std::string lCityName)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != lID)
		{
			tempString = "";
			tempString += " location_id = ";
			tempString += boost::lexical_cast<std::string>(lID);
			conditionVec.push_back(tempString);
		}
		if (!lCountryName.empty())
		{
			tempString = "";
			tempString += " country_name = '";
			tempString += lCountryName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!lCountryCode.empty())
		{
			tempString = "";
			tempString += " country_code LIKE '%";
			tempString += lCountryCode;
			tempString += "%'";
			conditionVec.push_back(tempString);
		}
		if (!lRegionName.empty())
		{
			tempString = "";
			tempString += " region_name = '";
			tempString += lRegionName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!lCityName.empty())
		{
			tempString = "";
			tempString += " city_name = '";
			tempString += lCityName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForMeasure(int mID, std::string mName, std::string mShortName, int mUnit)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != mID)
		{
			tempString = "";
			tempString += " measure_id = ";
			tempString += boost::lexical_cast<std::string>(mID);
			conditionVec.push_back(tempString);
		}
		if (!mName.empty())
		{
			tempString = "";
			tempString += " measure_name = '";
			tempString += mName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!mShortName.empty())
		{
			tempString = "";
			tempString += " measure_short_name = '";
			tempString += mShortName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != mUnit)
		{
			tempString = "";
			tempString += " measure_unit = ";
			tempString += boost::lexical_cast<std::string>(mUnit);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}
	
	std::string OrmasDal::GetFilterForOrderList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != olID)
		{
			tempString = "";
			tempString += " order_list_id = ";
			tempString += boost::lexical_cast<std::string>(olID);
			conditionVec.push_back(tempString);
		}
		if (0 != oID)
		{
			tempString = "";
			tempString += " order_id = ";
			tempString += boost::lexical_cast<std::string>(oID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != olCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(olCount);
			conditionVec.push_back(tempString);
		}
		if (0 != olSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(olSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForPayslipOrder(int pID, int oID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != pID)
		{
			tempString = "";
			tempString += " payslip_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != oID)
		{
			tempString = "";
			tempString += " order_id = ";
			tempString += boost::lexical_cast<std::string>(oID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForOrder(int oID, int uID, std::string oDate, std::string oExecDate, int eID, int oCount,
		double oSum, int sID, int cID, std::string fromDate, std::string toDate)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != oID)
		{
			tempString = "";
			tempString += " order_id = ";
			tempString += boost::lexical_cast<std::string>(oID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (!fromDate.empty())
		{
			tempString = "";
			tempString += " (DATE(execution_date) BETWEEN '";
			tempString += fromDate;
			tempString += "' AND '";
			if (toDate.empty())
			{
				tempString += GetSystemDate();
			}
			else
			{
				tempString += toDate;
			}
			tempString += "')";
			conditionVec.push_back(tempString);
		}
		if (0 != eID)
		{
			tempString = "";
			tempString += " employee_id = ";
			tempString += boost::lexical_cast<std::string>(eID);
			conditionVec.push_back(tempString);
		}
		if (0 != oCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(oCount);
			conditionVec.push_back(tempString);
		}
		if (0 != oSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(oSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForOrder(int oID, int uID, std::string oDate, std::string oExecDate, int eID, int oCount,
											double oSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != oID)
		{
			tempString = "";
			tempString += " order_id = ";
			tempString += boost::lexical_cast<std::string>(oID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (!oDate.empty())
		{
			tempString = "";
			tempString += " order_date = '";
			tempString += oDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!oExecDate.empty())
		{
			tempString = "";
			tempString += " execution_date = '";
			tempString += oExecDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != eID)
		{
			tempString = "";
			tempString += " employee_id = ";
			tempString += boost::lexical_cast<std::string>(eID);
			conditionVec.push_back(tempString);
		}
		if (0 != oCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(oCount);
			conditionVec.push_back(tempString);
		}
		if (0 != oSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(oSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForOrderRawList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != olID)
		{
			tempString = "";
			tempString += " order_raw_list_id = ";
			tempString += boost::lexical_cast<std::string>(olID);
			conditionVec.push_back(tempString);
		}
		if (0 != oID)
		{
			tempString = "";
			tempString += " order_raw_id = ";
			tempString += boost::lexical_cast<std::string>(oID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != olCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(olCount);
			conditionVec.push_back(tempString);
		}
		if (0 != olSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(olSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForOrderRaw(int oID, int uID, std::string oDate, std::string oExecDate, int eID, int oCount,
		double oSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != oID)
		{
			tempString = "";
			tempString += " order_raw_id = ";
			tempString += boost::lexical_cast<std::string>(oID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (!oDate.empty())
		{
			tempString = "";
			tempString += " order_raw_date = '";
			tempString += oDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!oExecDate.empty())
		{
			tempString = "";
			tempString += " execution_date = '";
			tempString += oExecDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != eID)
		{
			tempString = "";
			tempString += " employee_id = ";
			tempString += boost::lexical_cast<std::string>(eID);
			conditionVec.push_back(tempString);
		}
		if (0 != oCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(oCount);
			conditionVec.push_back(tempString);
		}
		if (0 != oSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(oSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForPayment(int pID, std::string pDate, double pValue, int uID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != pID)
		{
			tempString = "";
			tempString += " payment_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (!pDate.empty())
		{
			tempString = "";
			tempString += " payment_date = '";
			tempString += pDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != pValue)
		{
			tempString = "";
			tempString += " payment_value = ";
			tempString += boost::lexical_cast<std::string>(pValue);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForPayslip(int pID, std::string pDate, double pValue, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != pID)
		{
			tempString = "";
			tempString += " payslip_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (!pDate.empty())
		{
			tempString = "";
			tempString += " payslip_date = '";
			tempString += pDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != pValue)
		{
			tempString = "";
			tempString += " payslip_value = ";
			tempString += boost::lexical_cast<std::string>(pValue);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " salary_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForPhoto(int pID, int uID, int prodId, std::string pSource)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != pID)
		{
			tempString = "";
			tempString += " photo_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (0 != prodId)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(prodId);
			conditionVec.push_back(tempString);
		}
		if (!pSource.empty())
		{
			tempString = "";
			tempString += " photo_source = '";
			tempString += pSource;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForPosition(int pID, std::string pName)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != pID)
		{
			tempString = "";
			tempString += " position_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (!pName.empty())
		{
			tempString = "";
			tempString += " position_name = '";
			tempString += pName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForPrice(int pID, std::string pDate, double pValue, int cID, int prodID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != pID)
		{
			tempString = "";
			tempString += " price_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (!pDate.empty())
		{
			tempString = "";
			tempString += " price_date = '";
			tempString += pDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != pValue)
		{
			tempString = "";
			tempString += " price_value = ";
			tempString += boost::lexical_cast<std::string>(pValue);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (0 != prodID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(prodID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForProductType(int pTypeID, std::string pTypeName, std::string pTypeShortName)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != pTypeID)
		{
			tempString = "";
			tempString += " product_type_id = ";
			tempString += boost::lexical_cast<std::string>(pTypeID);
			conditionVec.push_back(tempString);
		}
		if (!pTypeName.empty())
		{
			tempString = "";
			tempString += " product_type_name = '";
			tempString += pTypeName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!pTypeShortName.empty())
		{
			tempString = "";
			tempString += " product_type_short_name = '";
			tempString += pTypeShortName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}		
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForProduction(int pID, std::string pProductionDate, std::string pExpiryDate, std::string pSessionStart,
		std::string pSessionEnd)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != pID)
		{
			tempString = "";
			tempString += " production_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (!pProductionDate.empty())
		{
			tempString = "";
			tempString += " production_date = '";
			tempString += pProductionDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!pExpiryDate.empty())
		{
			tempString = "";
			tempString += " expiry_date = '";
			tempString += pExpiryDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!pSessionStart.empty())
		{
			tempString = "";
			tempString += " session_start = '";
			tempString += pSessionStart;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!pSessionEnd.empty())
		{
			tempString = "";
			tempString += " session_end = '";
			tempString += pSessionEnd;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}


	std::string OrmasDal::GetFilterForProductionList(int plID, int pID, int prodID, int plCount, double plSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != plID)
		{
			tempString = "";
			tempString += " production_list_id = ";
			tempString += boost::lexical_cast<std::string>(plID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString += " production_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != prodID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(prodID);
			conditionVec.push_back(tempString);
		}
		if (0 != plCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(plCount);
			conditionVec.push_back(tempString);
		}
		if (0 != plSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(plSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForProduct(int pID, int cID, std::string pName, double vol, int mID, double price, 
		int pTypeID, int pShelfLife, int pCur)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != pID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " company_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (!pName.empty())
		{
			tempString = "";
			tempString += " product_name = '";
			tempString += pName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != vol)
		{
			tempString = "";
			tempString += " volume = ";
			tempString += boost::lexical_cast<std::string>(vol);
			conditionVec.push_back(tempString);
		}
		if (0 != mID)
		{
			tempString = "";
			tempString += " measure_id = ";
			tempString += boost::lexical_cast<std::string>(mID);
			conditionVec.push_back(tempString);
		}
		if (0 != price)
		{
			tempString = "";
			tempString += " price = ";
			tempString += boost::lexical_cast<std::string>(price);
			conditionVec.push_back(tempString);
		}
		if (0 != pTypeID)
		{
			tempString = "";
			tempString += " product_type_id = ";
			tempString += boost::lexical_cast<std::string>(pTypeID);
			conditionVec.push_back(tempString);
		}
		if (0 != pShelfLife)
		{
			tempString = "";
			tempString += " shelf_life = ";
			tempString += boost::lexical_cast<std::string>(pShelfLife);
			conditionVec.push_back(tempString);
		}
		if (0 != pCur)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(pCur);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForReceiptProductList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != rlID)
		{
			tempString = "";
			tempString += " receipt_product_list_id = ";
			tempString += boost::lexical_cast<std::string>(rlID);
			conditionVec.push_back(tempString);
		}
		if (0 != rID)
		{
			tempString = "";
			tempString += " receipt_product_id = ";
			tempString += boost::lexical_cast<std::string>(rID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != rlCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(rlCount);
			conditionVec.push_back(tempString);
		}
		if (0 != rlSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(rlSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForReceiptProduct(int rID, int uID, std::string rDate, std::string rExecDate, int eID, int rCount,
		double rSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != rID)
		{
			tempString = "";
			tempString += " receipt_product_id = ";
			tempString += boost::lexical_cast<std::string>(rID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (!rDate.empty())
		{
			tempString = "";
			tempString += " receipt_product_date = '";
			tempString += rDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!rExecDate.empty())
		{
			tempString = "";
			tempString += " execution_date = '";
			tempString += rExecDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != eID)
		{
			tempString = "";
			tempString += " employee_id = ";
			tempString += boost::lexical_cast<std::string>(eID);
			conditionVec.push_back(tempString);
		}
		if (0 != rCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(rCount);
			conditionVec.push_back(tempString);
		}
		if (0 != rSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(rSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForReceiptRawList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != rlID)
		{
			tempString = "";
			tempString += " consume_raw_list_id = ";
			tempString += boost::lexical_cast<std::string>(rlID);
			conditionVec.push_back(tempString);
		}
		if (0 != rID)
		{
			tempString = "";
			tempString += " consume_raw_id = ";
			tempString += boost::lexical_cast<std::string>(rID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != rlCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(rlCount);
			conditionVec.push_back(tempString);
		}
		if (0 != rlSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(rlSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForReceiptRaw(int rID, int uID, std::string rDate, std::string rExecDate, int eID, int rCount,
		double rSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != rID)
		{
			tempString = "";
			tempString += " consume_raw_id = ";
			tempString += boost::lexical_cast<std::string>(rID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (!rDate.empty())
		{
			tempString = "";
			tempString += " consume_raw_date = '";
			tempString += rDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!rExecDate.empty())
		{
			tempString = "";
			tempString += " execution_date = '";
			tempString += rExecDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != eID)
		{
			tempString = "";
			tempString += " employee_id = ";
			tempString += boost::lexical_cast<std::string>(eID);
			conditionVec.push_back(tempString);
		}
		if (0 != rCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(rCount);
			conditionVec.push_back(tempString);
		}
		if (0 != rSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(rSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForRefund(int rID, std::string rDate, double rValue, int uID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != rID)
		{
			tempString = "";
			tempString += " refund_id = ";
			tempString += boost::lexical_cast<std::string>(rID);
			conditionVec.push_back(tempString);
		}
		if (!rDate.empty())
		{
			tempString = "";
			tempString += " refund_date = '";
			tempString += rDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != rValue)
		{
			tempString = "";
			tempString += " refund_value = ";
			tempString += boost::lexical_cast<std::string>(rValue);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForRelationType(int rID, std::string rName, std::string rComment)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != rID)
		{
			tempString = "";
			tempString += " relation_type_id = ";
			tempString += boost::lexical_cast<std::string>(rID);
			conditionVec.push_back(tempString);
		}
		if (!rName.empty())
		{
			tempString = "";
			tempString += " relation_name = '";
			tempString += rName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!rComment.empty())
		{
			tempString = "";
			tempString += " comment LIKE '%";
			tempString += rComment;
			tempString += "%'";
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}
	
	std::string OrmasDal::GetFilterForRelation(int rID, int uID1, int uID2, int rtID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != rID)
		{
			tempString = "";
			tempString += " relation_id = ";
			tempString += boost::lexical_cast<std::string>(rID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID1)
		{
			tempString = "";
			tempString += " user_id_1 = ";
			tempString += boost::lexical_cast<std::string>(uID1);
			conditionVec.push_back(tempString);
		}
		if (0 != uID2)
		{
			tempString = "";
			tempString += " user_id_2 = ";
			tempString += boost::lexical_cast<std::string>(uID2);
			conditionVec.push_back(tempString);
		}
		if (0 != rtID)
		{
			tempString = "";
			tempString += " relation_type_id = ";
			tempString += boost::lexical_cast<std::string>(rtID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForReturnList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != rlID)
		{
			tempString = "";
			tempString += " return_list_id = ";
			tempString += boost::lexical_cast<std::string>(rlID);
			conditionVec.push_back(tempString);
		}
		if (0 != rID)
		{
			tempString = "";
			tempString += " return_id = ";
			tempString += boost::lexical_cast<std::string>(rID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != rlCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(rlCount);
			conditionVec.push_back(tempString);
		}
		if (0 != rlSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(rlSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForReturn(int rID, int uID, std::string rDate, std::string rExecDate, int eID, int rCount, 
											double rSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != rID)
		{
			tempString = "";
			tempString += " return_id = ";
			tempString += boost::lexical_cast<std::string>(rID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (!rDate.empty())
		{
			tempString = "";
			tempString += " return_date = '";
			tempString += rDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!rExecDate.empty())
		{
			tempString = "";
			tempString += " execution_date = '";
			tempString += rExecDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != eID)
		{
			tempString = "";
			tempString += " employee_id = ";
			tempString += boost::lexical_cast<std::string>(eID);
			conditionVec.push_back(tempString);
		}
		if (0 != rCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(rCount);
			conditionVec.push_back(tempString);
		}
		if (0 != rSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(rSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForRole(int rID, std::string rCode, std::string rName, std::string rComment)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != rID)
		{
			tempString = "";
			tempString += " role_id = ";
			tempString += boost::lexical_cast<std::string>(rID);
			conditionVec.push_back(tempString);
		}
		if (!rCode.empty())
		{
			tempString = "";
			tempString += " role_code = '";
			tempString += rCode;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!rName.empty())
		{
			tempString = "";
			tempString += " role_name = '";
			tempString += rName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!rComment.empty())
		{
			tempString = "";
			tempString += " comment LIKE '%";
			tempString += rComment;
			tempString += "%'";
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}
	
	std::string OrmasDal::GetFilterForSalary(int sID, int uID, double sValue, int cID, int stID, std::string sDate, bool sBonus)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != sID)
		{
			tempString = "";
			tempString += " salary_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (0 != sValue)
		{
			tempString = "";
			tempString += " salary_value = ";
			tempString += boost::lexical_cast<std::string>(sValue);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (0 != stID)
		{
			tempString = "";
			tempString += " salary_type_id = ";
			tempString += boost::lexical_cast<std::string>(stID);
			conditionVec.push_back(tempString);
		}
		if (!sDate.empty())
		{
			tempString = "";
			tempString += " salary_date = '";
			tempString += sDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForSalaryType(int sID, std::string sCode, std::string sName)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != sID)
		{
			tempString = "";
			tempString += "salary_type_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (!sCode.empty())
		{
			tempString = "";
			tempString += " salary_type_code = '";
			tempString += sCode;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!sName.empty())
		{
			tempString = "";
			tempString += " salary_type_name = '";
			tempString += sName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForStatus(int sID, std::string sCode, std::string sName , std::string sComment)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (!sCode.empty())
		{
			tempString = "";
			tempString += " status_code = '";
			tempString += sCode;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!sName.empty())
		{
			tempString = "";
			tempString += " status_name = '";
			tempString += sName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!sComment.empty())
		{
			tempString = "";
			tempString += " comment LIKE '%";
			tempString += sComment;
			tempString += "%'";
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}
	
	std::string OrmasDal::GetFilterForStock(int sID, int pID, int sCount, double sSum, int stsID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != sID)
		{
			tempString = "";
			tempString += " stock_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != sCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(sCount);
			conditionVec.push_back(tempString);
		}
		if (0 != sSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(sSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(stsID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForTransportList(int tlID, int tID, int pID, int tlCount, double tlSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != tlID)
		{
			tempString = "";
			tempString += " transport_list_id = ";
			tempString += boost::lexical_cast<std::string>(tlID);
			conditionVec.push_back(tempString);
		}
		if (0 != tID)
		{
			tempString = "";
			tempString += " transport_id = ";
			tempString += boost::lexical_cast<std::string>(tID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != tlCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(tlCount);
			conditionVec.push_back(tempString);
		}
		if (0 != tlSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(tlSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForTransport(int tID, int uID, std::string tDate, std::string tExecDate, int eID, int tCount,
		double tSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != tID)
		{
			tempString = "";
			tempString += " transport_id = ";
			tempString += boost::lexical_cast<std::string>(tID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (!tDate.empty())
		{
			tempString = "";
			tempString += " transport_date = '";
			tempString += tDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!tExecDate.empty())
		{
			tempString = "";
			tempString += " execution_date = '";
			tempString += tExecDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != eID)
		{
			tempString = "";
			tempString += " employee_id = ";
			tempString += boost::lexical_cast<std::string>(eID);
			conditionVec.push_back(tempString);
		}
		if (0 != tCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(tCount);
			conditionVec.push_back(tempString);
		}
		if (0 != tSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(tSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForUser(int uID, std::string uEmail, std::string uName, std::string uSurname, std::string uPhone, std::string uAddress,
		int uRoleID, std::string uPassword, bool uActivated)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (!uEmail.empty())
		{
			tempString = "";
			tempString += " user_email = '";
			tempString += uEmail;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!uName.empty())
		{
			tempString = "";
			tempString += " user_name = '";
			tempString += uName;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!uSurname.empty())
		{
			tempString = "";
			tempString += " user_surname = '";
			tempString += uSurname;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!uPhone.empty())
		{
			tempString = "";
			tempString += " user_phone = '";
			tempString += uPhone;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (!uAddress.empty())
		{
			tempString = "";
			tempString += " user_address = '";
			tempString += uAddress;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != uRoleID)
		{
			tempString = "";
			tempString += " role_id = ";
			tempString += boost::lexical_cast<std::string>(uRoleID);
			conditionVec.push_back(tempString);
		}
		if (!uPassword.empty())
		{
			tempString = "";
			tempString += " password = '";
			tempString += uPassword;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForWithdrawal(int wID, std::string wDate, double wValue, int uID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != wID)
		{
			tempString = "";
			tempString += " withdrawal_id = ";
			tempString += boost::lexical_cast<std::string>(wID);
			conditionVec.push_back(tempString);
		}
		if (!wDate.empty())
		{
			tempString = "";
			tempString += " withdrawal_date = '";
			tempString += wDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != wValue)
		{
			tempString = "";
			tempString += " withdrawal_value = ";
			tempString += boost::lexical_cast<std::string>(wValue);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForWriteOffList(int wlID, int wID, int pID, int wlCount, double wlSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != wlID)
		{
			tempString = "";
			tempString += " write-off_list_id = ";
			tempString += boost::lexical_cast<std::string>(wlID);
			conditionVec.push_back(tempString);
		}
		if (0 != wID)
		{
			tempString = "";
			tempString += " write_off_id = ";
			tempString += boost::lexical_cast<std::string>(wID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != wlCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(wlCount);
			conditionVec.push_back(tempString);
		}
		if (0 != wlSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(wlSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForWriteOff(int wID, int uID, std::string wDate, int eID, int wCount, double wSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != wID)
		{
			tempString = "";
			tempString += " write_off_id = ";
			tempString += boost::lexical_cast<std::string>(wID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (!wDate.empty())
		{
			tempString = "";
			tempString += " write_off_date = '";
			tempString += wDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != eID)
		{
			tempString = "";
			tempString += " employee_id = ";
			tempString += boost::lexical_cast<std::string>(eID);
			conditionVec.push_back(tempString);
		}
		if (0 != wCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(wCount);
			conditionVec.push_back(tempString);
		}
		if (0 != wSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(wSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForWriteOffRawList(int wlID, int wID, int pID, int wlCount, double wlSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != wlID)
		{
			tempString = "";
			tempString += " write_off_raw_list_id = ";
			tempString += boost::lexical_cast<std::string>(wlID);
			conditionVec.push_back(tempString);
		}
		if (0 != wID)
		{
			tempString = "";
			tempString += " write_off_raw_id = ";
			tempString += boost::lexical_cast<std::string>(wID);
			conditionVec.push_back(tempString);
		}
		if (0 != pID)
		{
			tempString = "";
			tempString += " product_id = ";
			tempString += boost::lexical_cast<std::string>(pID);
			conditionVec.push_back(tempString);
		}
		if (0 != wlCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(wlCount);
			conditionVec.push_back(tempString);
		}
		if (0 != wlSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(wlSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}

	std::string OrmasDal::GetFilterForWriteOffRaw(int wID, int uID, std::string wDate, int eID, int wCount,
		double wSum, int sID, int cID)
	{
		std::string tempString = "";
		std::string filter = " where ";
		std::vector<std::string> conditionVec;
		if (0 != wID)
		{
			tempString = "";
			tempString += " write_off_raw_id = ";
			tempString += boost::lexical_cast<std::string>(wID);
			conditionVec.push_back(tempString);
		}
		if (0 != uID)
		{
			tempString = "";
			tempString += " user_id = ";
			tempString += boost::lexical_cast<std::string>(uID);
			conditionVec.push_back(tempString);
		}
		if (!wDate.empty())
		{
			tempString = "";
			tempString += " write_off_raw_date = '";
			tempString += wDate;
			tempString += "'";
			conditionVec.push_back(tempString);
		}
		if (0 != eID)
		{
			tempString = "";
			tempString += " employee_id = ";
			tempString += boost::lexical_cast<std::string>(eID);
			conditionVec.push_back(tempString);
		}
		if (0 != wCount)
		{
			tempString = "";
			tempString += " count = ";
			tempString += boost::lexical_cast<std::string>(wCount);
			conditionVec.push_back(tempString);
		}
		if (0 != wSum)
		{
			tempString = "";
			tempString += " sum = ";
			tempString += boost::lexical_cast<std::string>(wSum);
			conditionVec.push_back(tempString);
		}
		if (0 != sID)
		{
			tempString = "";
			tempString += " status_id = ";
			tempString += boost::lexical_cast<std::string>(sID);
			conditionVec.push_back(tempString);
		}
		if (0 != cID)
		{
			tempString = "";
			tempString += " currency_id = ";
			tempString += boost::lexical_cast<std::string>(cID);
			conditionVec.push_back(tempString);
		}
		if (conditionVec.size() >= 1)
		{
			filter += conditionVec.at(0);
			for (unsigned int i = 1; i < conditionVec.size(); i++)
			{
				filter += " AND ";
				filter += conditionVec.at(i);
			}
		}
		else
		{
			return "";
		}
		return filter;
	}
}