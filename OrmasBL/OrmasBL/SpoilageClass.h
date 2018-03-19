#ifndef SPOILAGECLASS_H
#define SPOILAGECLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class Spoilage
	{
	protected:
		int id = 0;
		std::string date = "";
		int employeeID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		Spoilage(int sID, std::string sDate, int eID, int sCount, double sSum, int stsID, int cID) :
			id(sID), date(sDate), employeeID(eID), count(sCount), sum(sSum), statusID(stsID), currencyID(cID){};
		Spoilage(DataLayer::spoilageCollection);
		Spoilage(){};
		~Spoilage(){};

		//Spoilage class Accessors
		int GetID();
		std::string GetDate();
		int GetEmployeeID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//Spoilage class Mutators
		void SetID(int);
		void SetDate(std::string);
		void SetEmployeeID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateSpoilage(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateSpoilage(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteSpoilage(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateSpoilage(DataLayer::OrmasDal& ormasDal, std::string sDate, int eID, int sCount,
			double sSum, int stsID, int cID, std::string& errorMessage);
		bool UpdateSpoilage(DataLayer::OrmasDal& ormasDal, std::string sDate, int eID, int sCount,
			double sSum, int stsID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetSpoilageByID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string sDate, int sCount, double sSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //SPOILAGECLASS_H