#ifndef RETURNCLASS_H
#define RETURNCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class Return
	{
	protected:
		int id = 0;
		int clientID = 0;
		std::string date = "";
		int employeeID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		Return(int rID, int clID, std::string rDate, int eID, int oCount, double oSum, int sID, int cID) :id(rID), clientID(clID),
			date(rDate), employeeID(eID), count(oCount), sum(oSum), statusID(sID), currencyID(cID){};
		Return(DataLayer::returnsCollection);
		Return(){};
		~Return(){};
		
		//Return class Accessors
		int GetID();
		int GetClientID();
		std::string GetDate();
		int GetEmployeeID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();
		
		//Please implement Mutators
		void SetID(int);
		void SetClientID(int);
		void SetDate(std::string);
		void SetEmployeeID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);
		
		//Create, delete, update methods
		bool CreateReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteReturn(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateReturn(DataLayer::OrmasDal& ormasDal, int clID, std::string rDate, int eID, int rCount, double rSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateReturn(DataLayer::OrmasDal& ormasDal, int clID, std::string rDate, int eID, int rCount, double rSum, 
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetRetrunByID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage);
		bool IsEmpty();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int clID, std::string oDate,  int oCount, double oSum,
			 int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //RETURNCLASS_H