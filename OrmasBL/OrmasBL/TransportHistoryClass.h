#ifndef TransportHISTORYCLASS_H
#define TransportHISTORYCLASS_H
#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class TransportHistory
	{
	protected:
		int id = 0;
		int productID = 0;
		double count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
		int transportID = 0;
		std::string historyDate = "";
	public:
		TransportHistory(int sID, int pID, int sCount, double sSum, int stsID, int cID, int wID, std::string sHistoryDate) :id(sID),
			productID(pID), count(sCount), sum(sSum), statusID(stsID), currencyID(cID), transportID(wID), historyDate(sHistoryDate){};
		TransportHistory(DataLayer::transportHistoryCollection);
		TransportHistory(){};
		~TransportHistory(){};

		//TransportHistory class Accessors
		int GetID();
		int GetProductID();
		double GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();
		int GetTransportID();
		std::string GetHistoryDate();


		//TransportHistory class Mutators
		void SetID(int);
		void SetProductID(int);
		void SetCount(double);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);
		void SetTransportID(int);
		void SetHistoryDate(std::string);

		//Create, delete, update methods
		bool CreateTransportHistory(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateTransportHistory(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteTransportHistory(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateTransportHistory(DataLayer::OrmasDal& ormasDal, int pID, double sCount, double sSum,
			int sID, int cID, int wID, std::string sHistoryDate, std::string& errorMessage);
		bool UpdateTransportHistory(DataLayer::OrmasDal& ormasDal, int pID, double sCount, double sSum,
			int sID, int cID, int wID, std::string sHistoryDate, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetTransportHistoryByID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage);
		bool GetTransportHistoryByProductID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool GetTransportHistoryByProductAndtransportID(DataLayer::OrmasDal& ormasDal, int pID, int wID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();


	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int pID, int wID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif