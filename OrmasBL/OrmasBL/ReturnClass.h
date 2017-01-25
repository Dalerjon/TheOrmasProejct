#ifndef RETURNCLASS_H
#define RETURNCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Return
	{
	protected:
		int id = 0;
		int userID = 0;
		std::string date = "";
		int workerID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		Return(int rID, int uID, std::string rDate, int wID, int oCount, double oSum, int sID, int cID) :id(rID), userID(uID),
			date(rDate), workerID(wID), count(oCount), sum(oSum), statusID(sID), currencyID(cID){};
		Return(DataLayer::returnsCollection);
		Return(){};
		~Return(){};
		
		//Return class Accessors
		int GetID();
		int GetUserID();
		std::string GetDate();
		int GetWorkerID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();
		
		//Please implement Mutators
		void SetID(int);
		void SetUserID(int);
		void SetDate(std::string);
		void SetWorkerID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);
		
		//Create, delete, update methods
		bool CreateReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateReturn(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, int oCount, double oSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateReturn(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, int wID, int oCount, double oSum, 
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetRetrunByID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage);
		bool IsEmpty();
	};
}
#endif //RETURNCLASS_H