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
		int subaccountID = 0;
		std::string target = "";
		int currencyID = 0;
		int statusID = 0;
		int accountID = 0;
	public:
		Withdrawal();
		Withdrawal(int pID, std::string pDate, double pValue, int uID, int sID, std::string wTarget, int cID, int stsID, int aID) :id(pID), 
			date(pDate), value(pValue), userID(uID), subaccountID(sID), target(wTarget), currencyID(cID), statusID(stsID), accountID(aID){};
		Withdrawal(DataLayer::withdrawalsCollection);
		~Withdrawal(){};

		std::string errorMessage = "";
		int loggedUserID = 0;
		//Withdrawal class Withdrawalors
		int GetID();
		std::string GetDate();
		double GetValue();
		int GetUserID();
		int GetSubaccountID();
		std::string GetTarget();
		int GetCurrencyID();
		int GetStatusID();
		int GetAccountID();

		//Withdrawal class Mutators
		void SetID(int);
		void SetUserID(int);
		void SetSubaccountID(int);
		void SetDate(std::string);
		void SetTarget(std::string);
		void SetValue(double);
		void SetCurrencyID(int);
		void SetStatusID(int);
		void SetAccountID(int);

		// Create, delete and update Withdrawal
		bool CreateWithdrawal(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateWithdrawal(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteWithdrawal(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateWithdrawal(DataLayer::OrmasDal &ormasDal, std::string wDate, double wValue, int uID, int sID, std::string wTaeget,
			int cID, int stsID, int aID, std::string& errorMessage);
		bool UpdateWithdrawal(DataLayer::OrmasDal &ormasDal, std::string wDate, double wValue, int uID, int sID, std::string wTaeget,
			int cID, int stsID, int aID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetWithdrawalByID(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double currentValue = 0.0;
		int previousStatusID = 0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string wDate, double wValue, int uID, int cID, int aID,
			std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool Payout(DataLayer::OrmasDal& ormasDal, int uID, int cID, int aID, std::string& errorMessage);
		bool Payout(DataLayer::OrmasDal& ormasDal, int uID, int cID, int aID, double previousValue, std::string& errorMessage);
		bool Payout(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage);
		bool Payout(DataLayer::OrmasDal& ormasDal, int sID, double previousValue, std::string& errorMessage);
		double GetCurrentValue(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool CancelWithdrawal(DataLayer::OrmasDal& ormasDal, int uID, int cID, int aID, std::string& errorMessage);
		bool CancelWithdrawal(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage);
		bool CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage);
		bool CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, double previousSum, std::string oExecDate, std::string& errorMessage);
		bool CorrectingEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage);
		int GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		std::string wstring_to_utf8(const std::wstring& str);
	};
}

#endif
