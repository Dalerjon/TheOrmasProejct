#ifndef ORDERCLASS_H
#define ORDERCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class Order
	{
	protected:
		int id = 0;
		int clientID = 0;
		std::string date = "";
		std::string executionDate = "";
		int employeeID = 0;
		double count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		Order(int oID, int clID, std::string oDate, std::string oExecDate, int eID, double oCount, double oSum, int sID, int cID) :
			id(oID), clientID(clID), date(oDate), executionDate(oExecDate), employeeID(eID), count(oCount), sum(oSum), 
			statusID(sID), currencyID(cID){};
		Order(DataLayer::ordersCollection);
		Order(){};
		~Order(){};
		
		//Order class Accessors
		int GetID();
		int GetClientID();
		std::string GetDate();
		std::string GetExecutionDate();
		int GetEmployeeID();
		double GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//Order class Mutators
		void SetID(int);
		void SetClientID(int);
		void SetDate(std::string);
		void SetExecutionDate(std::string);
		void SetEmployeeID(int);
		void SetCount(double);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);
				
		//Create, delete, update methods
		bool CreateOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateOrder(DataLayer::OrmasDal& ormasDal, int clID, std::string oDate, std::string oExecDate, int eID, double oCount,
			double oSum, int sID, int cID, std::string& errorMessage);
		bool UpdateOrder(DataLayer::OrmasDal& ormasDal, int clID, std::string oDate, std::string oExecDate, int eID, double oCount,
			double oSum, int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		std::string GenerateFilterForPeriod(DataLayer::OrmasDal& ormasDal, std::string formDate, std::string toDate);
		bool GetOrderByID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double previousSum = 0.0;
		int previousStatusID = 0;
		double prevCount = 0.0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int clID, std::string oDate, double oCount, double oSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateOrderEntry(DataLayer::OrmasDal& ormasDal, int clID, int eID, double oSum, int cID, std::string oExecDate, std::string& errorMessage);
		bool CreateOrderEntryCancel(DataLayer::OrmasDal& ormasDal, int clID, int eID, double oSum, int cID, std::string oExecDate, std::string& errorMessage);
		bool CreateOrderEntry(DataLayer::OrmasDal& ormasDal, int clID, int eID, double oSum, double prevSum, int cID, std::string oExecDate, std::string& errorMessage);
		double GetCurrentSum(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		int GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		double GetCurrentCount(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage);
		bool CreateEntryCancel(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage);
		bool CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, double previousSum, std::string oExecDate, std::string& errorMessage);
		bool ChangesAtTransport(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool ChangesAtTransportCancel(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool ChangesAtTransport(DataLayer::OrmasDal& ormasDal, int oID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		std::string wstring_to_utf8(const std::wstring& str);
	};
}
#endif //ORDERCLASS_H