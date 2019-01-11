#ifndef CASHBOXCLASS_H
#define CASHBOXCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class Cashbox
	{
	protected:
		int id = 0;
		int subaccountID = 0;
		std::string information = "";
		std::string address = "";
	public:
		Cashbox();
		Cashbox(int cID, int subaccID, std::string cInformation, std::string cAddress) :id(cID),
			information(cInformation), address(cAddress){};
		Cashbox(DataLayer::cashboxCollection);
		~Cashbox(){};

		std::string errorMessage = "";
		//Cashbox class Accessors
		int GetID();
		int GetSubaccountID();
		std::string GetInformation();
		std::string GetAddress();

		//Cashbox class Mutators
		void SetID(int);
		void SetSubaccountID(int);
		void SetInformation(std::string);
		void SetAddress(std::string);
		

		// Create, delete and update Cashbox
		bool CreateCashbox(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateCashbox(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteCashbox(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateCashbox(DataLayer::OrmasDal &ormasDal, int subaccID, std::string cInfo, std::string cAddress, std::string& errorMessage);
		bool UpdateCashbox(DataLayer::OrmasDal &ormasDal, int subaccID, std::string cInfo, std::string cAddress, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetCashboxByID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage);
		int GetCashboxID(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		void TrimStrings(std::string&, std::string&);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int subaccID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //CashboxCLASS_H