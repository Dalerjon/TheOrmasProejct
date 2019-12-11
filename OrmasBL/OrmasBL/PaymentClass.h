#ifndef PAYMENTCLASS_H
#define PAYMENTCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Payment{
	protected:
		int id = 0;
		std::string date = "";
		double value = 0.0;
		std::string target = "";
		int userID = 0;
		int currencyID = 0;
		int statusID = 0; 
		int accountID = 0;
		int subaccountID = 0;
		std::string who = "";
		int cashboxAccountID = 0;
	public:
		Payment();
		Payment(int pID, std::string pDate, double pValue, std::string pTarget, int uID, int cID, int sID, int aID, int subaID, 
			std::string pWho, int cashboxAccID) :id(pID), date(pDate), value(pValue), target(pTarget), userID(uID), currencyID(cID), statusID(sID), 
			accountID(aID), subaccountID(subaID), who(pWho), cashboxAccountID(cashboxAccID){};
		Payment(DataLayer::paymentsCollection);
		~Payment(){};

		std::string errorMessage = "";
		int loggedUserID = 0;
		
		//Payment class Accessors
		int GetID();
		std::string GetDate();
		double GetValue();
		std::string GetTarget();
		int GetUserID();
		int GetCurrencyID();
		int GetStatusID();
		int GetAccountID();
		int GetSubaccountID();
		std::string GetWho();
		int GetCashboxAccountID();

		//Payment class Mutators
		void SetID(int);
		void SetUserID(int);
		void SetDate(std::string);
		void SetValue(double);
		void SetTarget(std::string);
		void SetCurrencyID(int);
		void SetStatusID(int);
		void SetAccountID(int);
		void SetSubaccountID(int);
		void SetWho(std::string);
		void SetCashboxAccountID(int);

		// Create, delete and update Payment
		bool CreatePayment(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdatePayment(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeletePayment(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreatePayment(DataLayer::OrmasDal &ormasDal, std::string pDate, double pValue, std::string pTarget, int uID, int cID,
			int sID, int aID, int subaId, std::string pWho, int cashboxAccID, std::string& errorMessage);
		bool UpdatePayment(DataLayer::OrmasDal &ormasDal, std::string pDate, double pValue, std::string pTarget, int uID, int cID,
			int sID, int aID, int subaId, std::string pWho, int cashboxAccID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		std::string GenerateFilterForPeriod(DataLayer::OrmasDal& ormasDal, std::string formDate, std::string toDate);
		bool GetPaymentByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double currentValue = 0.0;
		int previousStatusID = 0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string pDate, double pValue, int uID, int cID, int aID,
			std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool Replenishment(DataLayer::OrmasDal& ormasDal, int uID, int cID, int aID, int cbAccID, std::string& errorMessage);
		bool Replenishment(DataLayer::OrmasDal& ormasDal, int uID, int cID, int aID, int cbAccID, double previousValue, std::string& errorMessage);
		bool Replenishment(DataLayer::OrmasDal& ormasDal, int sID, int cbAccID, std::string& errorMessage);
		bool Replenishment(DataLayer::OrmasDal& ormasDal, int sID, int cbAccID, double previousValue, std::string& errorMessage);
		double GetCurrentValue(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool CancelPayment(DataLayer::OrmasDal& ormasDal, int uID, int cID, int aID, int cbAccID, std::string& errorMessage);
		bool CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage);
		bool CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, double previousSum, std::string oExecDate, std::string& errorMessage);
		bool CorrectingEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage);
		int GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		std::string wstring_to_utf8(const std::wstring& str);
	};
}
#endif