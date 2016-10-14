// OrmasDALTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OrmasDAL.h"
//#include <pqxx/pqxx>
#include <iostream>
#include <string>
#include <libpq-fe.h>

int _tmain(int argc, _TCHAR* argv[])
{
	DataLayer::OrmasDal oDal;
	oDal.setDBParams("OrmasDB", "postgres", "postgres", "127.0.0.1", 5432);
	if (PQstatus(oDal.getConnection()) == CONNECTION_BAD)
	{
		std::cout << "Oh sorry cannot connect to db!"<<std::endl;
	}
	else
	{
		/*std::vector<DataLayer::companiesCollection> companiesVector = oDal.getCompanies(oDal.getConnection());
		DataLayer::companiesCollection companiesRow = companiesVector.at(0);
		int id = std::get<0>(companiesRow);
		std::cout << "This is first id= " << id << std::endl;*/
	}
	
	
}

