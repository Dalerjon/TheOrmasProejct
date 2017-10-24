#ifndef RETURNLISTCLASS_H
#define RETURNLISTCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class ReturnList
	{
	protected:
		int id = 0;
		int returnID = 0;
		int productID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		ReturnList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID) :id(rlID), returnID(rID), productID(pID),
			count(rlCount), sum(rlSum), statusID(sID), currencyID(cID){};
		ReturnList(DataLayer::returnListCollection);
		ReturnList(){};
		~ReturnList(){};

		//ReturnList class Accessors
		int GetID();
		int GetReturnID();
		int GetProductID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//ReturnList class Mutators
		void SetID(int);
		void SetReturnID(int);
		void SetProductID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateReturnList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateReturnList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteReturnList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateReturnList(DataLayer::OrmasDal& ormasDal, int rID, int pID, int rlCount, double rlSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateReturnList(DataLayer::OrmasDal& ormasDal, int rID, int pID, int rlCount, double rlSum,
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetReturnListByID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage);
		bool IsEmpty();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int rID, int pID, int rlCount, double rlSum,
			 int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif