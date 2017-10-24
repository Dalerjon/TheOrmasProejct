#ifndef BALANCECLASS_H
#define BALANCECLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Balance{
	protected:	
		int id = 0;
		int userID = 0;
		double value = 0.0;
		int currencyID = 0;
	public:
		Balance();
		Balance(int bID, int uID, double bValue, int cID) :id(bID),userID(uID),value(bValue),currencyID(cID){};
		Balance(DataLayer::balancesCollection);
		~Balance(){};

		std::string errorMessage = "";
		//Balance class Accessors
		int GetID();
		int GetUserID();
		double GetValue();
		int GetCurrencyID();

		//Balance class Mutators
		void SetID(int);
		void SetUserID(int);
		void SetValue(double);
		void SetCurrencyID(int);

		// Create, delete and update balance
		bool CreateBalance(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateBalance(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteBalance(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateBalance(DataLayer::OrmasDal &ormasDal, int uID, double bValue, int cID, std::string& errorMessage);
		bool UpdateBalance(DataLayer::OrmasDal &ormasDal, int uID, double bValue, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetBalanceByID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage);
		bool IsEmpty();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int uID, int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //BALANCECLASS_H
