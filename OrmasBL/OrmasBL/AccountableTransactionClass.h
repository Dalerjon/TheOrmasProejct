#ifndef ACCOUNTABLETRANSACTIONCLASS_H
#define ACCOUNTABLETRANSACTIONCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class AccountableTransaction{
	protected:
		int id = 0;
		int accountableID = 0;
		double startValue = 0.0;
		double endValue = 0.0;
		int operationID = 0;
	public:
		AccountableTransaction();
		AccountableTransaction(int atID, int aID, double aStartValue, double aEndValue, int oID) :id(atID), accountableID(aID),
			startValue(aStartValue), endValue(aEndValue), operationID(oID){};
		AccountableTransaction(DataLayer::accountableTransactionCollection);
		~AccountableTransaction(){};

		std::string errorMessage = "";

		//AccountableTransaction class Accessors
		int GetID();
		int GetAccountableID();
		double GetStartValue();
		double GetEndValue();
		int GetOperationID();

		//AccountableTransaction class Mutators
		void SetID(int);
		void SetAccountableID(int);
		void SetStartValue(double);
		void SetEndValue(double);
		void SetOperationID(int);

		// Create, delete and update AccountableTransaction
		bool CreateAccountableTransaction(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateAccountableTransaction(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteAccountableTransaction(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateAccountableTransaction(DataLayer::OrmasDal &ormasDal, int aID, double aStartValue, double aEndValue, int oID, std::string& errorMessage);
		bool UpdateAccountableTransaction(DataLayer::OrmasDal &ormasDal, int aID, double aStartValue, double aEndValue, int oID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetAccountableTransactionByID(DataLayer::OrmasDal& ormasDal, int atID, std::string& errorMessage);
		bool GetAccountableTransactionByAccountableID(DataLayer::OrmasDal& ormasDal, int aID, std::string& errorMessage);
		bool GetAccountableTransactionByOperationID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int aID, double aStartValue, double aEndValue, int oID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //AccountableTransactionCLASS_H