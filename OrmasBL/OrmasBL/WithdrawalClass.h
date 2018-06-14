#ifndef WITHDRAWALCLASS_H
#define WITHDRAWALCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Withdrawal{
	protected:
		int id = 0;
		std::string date = "";
		double value = 0.0;
		int userID = 0;
		int currencyID = 0;
	public:
		Withdrawal();
		Withdrawal(int pID, std::string pDate, double pValue, int uID, int cID) :id(pID), date(pDate), value(pValue), userID(uID),
			currencyID(cID){};
		Withdrawal(DataLayer::withdrawalsCollection);
		~Withdrawal(){};

		std::string errorMessage = "";
		//Withdrawal class Withdrawalors
		int GetID();
		std::string GetDate();
		double GetValue();
		int GetUserID();
		int GetCurrencyID();

		//Withdrawal class Mutators
		void SetID(int);
		void SetUserID(int);
		void SetDate(std::string);
		void SetValue(double);
		void SetCurrencyID(int);

		// Create, delete and update Withdrawal
		bool CreateWithdrawal(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateWithdrawal(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteWithdrawal(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateWithdrawal(DataLayer::OrmasDal &ormasDal, std::string wDate, double wValue, int uID, int cID,
			std::string& errorMessage);
		bool UpdateWithdrawal(DataLayer::OrmasDal &ormasDal, std::string wDate, double wValue, int uID, int cID,
			std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetWithdrawalByID(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double currentValue = 0.0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string wDate, double wValue, int uID, int cID,
			std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool Payout(DataLayer::OrmasDal& ormasDal, int uID, int cID, std::string& errorMessage);
		bool Payout(DataLayer::OrmasDal& ormasDal, int uID, int cID, double previousValue, std::string& errorMessage);
		double GetCurrentValue(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool CancelWithdrawal(DataLayer::OrmasDal& ormasDal, int sID, int cID, std::string& errorMessage);
		bool CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage);
		bool CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, double previousSum, std::string oExecDate, std::string& errorMessage);
		bool CorrectingEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage);
	};
}

#endif