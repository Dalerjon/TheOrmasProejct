#ifndef RefundCLASS_H
#define RefundCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Refund{
	protected:
		int id = 0;
		std::string date = "";
		double value = 0.0;
		int userID = 0;
		int currencyID = 0;
	public:
		Refund();
		Refund(int pID, std::string pDate, double pValue, int uID, int cID) :id(pID), date(pDate), value(pValue), userID(uID),
			currencyID(cID){};
		Refund(DataLayer::refundsCollection);
		~Refund(){};

		std::string errorMessage = "";
		//Refund class Refundors
		int GetID();
		std::string GetDate();
		double GetValue();
		int GetUserID();
		int GetCurrencyID();

		//Refund class Mutators
		void SetID(int);
		void SetUserID(int);
		void SetDate(std::string);
		void SetValue(double);
		void SetCurrencyID(int);

		// Create, delete and update Refund
		bool CreateRefund(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateRefund(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteRefund(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateRefund(DataLayer::OrmasDal &ormasDal, std::string pDate, double pValue, int uID, int cID,
			std::string& errorMessage);
		bool UpdateRefund(DataLayer::OrmasDal &ormasDal, std::string pDate, double pValue, int uID, int cID,
			std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetRefundByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		double currentValue = 0.0;
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string pDate, double pValue, int uID, int cID,
			std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool Replenishment(DataLayer::OrmasDal& ormasDal, int uID, int cID, std::string& errorMessage);
		bool Replenishment(DataLayer::OrmasDal& ormasDal, int uID, int cID, double previousValue, std::string& errorMessage);
		double GetCurrentValue(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool CancelRefund(DataLayer::OrmasDal& ormasDal, int uID, int cID, std::string& errorMessage);
	};
}

#endif