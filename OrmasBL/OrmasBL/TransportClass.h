#ifndef TRANSPORTCLASS_H
#define TRANSPORTCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class Transport
	{
	protected:
		int id = 0;
		int employeeID = 0;
		std::string date = "";
		std::string executionDate = "";
		int stockEmployeeID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		Transport(int tID, int eID, std::string tDate, std::string tExecDate, int seID, int tCount, double tSum, int sID, int cID) :
			id(tID), employeeID(eID), date(tDate), executionDate(tExecDate), stockEmployeeID(seID), count(tCount), sum(tSum),
			statusID(sID), currencyID(cID){};
		Transport(DataLayer::transportsCollection);
		Transport(){};
		~Transport(){};

		//Consume Product class Accessors
		int GetID();
		int GetEmployeeID();
		std::string GetDate();
		std::string GetExecutionDate();
		int GetStockEmployeeID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//Consume Product class Mutators
		void SetID(int);
		void SetEmployeeID(int);
		void SetDate(std::string);
		void SetExecutionDate(std::string);
		void SetStockEmployeeID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateTransport(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateTransport(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteTransport(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateTransport(DataLayer::OrmasDal& ormasDal, int eID, std::string tDate, std::string tExecDate, int seID,
			int tCount, double tSum, int sID, int cID, std::string& errorMessage);
		bool UpdateTransport(DataLayer::OrmasDal& ormasDal, int eID, std::string tDate, std::string tExecDate, int seID, 
			int tCount, double tSum, int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetTransportByID(DataLayer::OrmasDal& ormasDal, int tID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int eID, std::string tDate, int seID, int tCount, double tSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //TransportCLASS_H