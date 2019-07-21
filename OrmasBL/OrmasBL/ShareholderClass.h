#ifndef SHAREHOLDERCLASS_H
#define SHAREHOLDERCLASS_H

#include "OrmasDAL.h"
#include "UserClass.h"

namespace BusinessLayer{
	class Shareholder : public User
	{
	protected:
		int userID = 0;
		double countOfStock = 0.0;
		std::string information = "";
	public:
		Shareholder(){};
		Shareholder(int uID, double sCountOfStock, std::string aInformation) : userID(uID), countOfStock(sCountOfStock),
			information(aInformation) {};
		Shareholder(DataLayer::shareholdersCollection);
		~Shareholder(){};

		std::string errorMessage = "";
		//Shareholder class Accessors
		int GetUserID();
		double GetCountOfStock();
		std::string GetInformation();


		//Shareholder class Mutators
		void SetUserID(int);
		void SetCountOfStock(double);
		void SetInformation(std::string);


		//Create, delete, update methods
		bool CreateShareholder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateShareholder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteShareholder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateShareholder(DataLayer::OrmasDal& ormasDal, int uID, double sCountOfStock, std::string aInformation, std::string& errorMessage);
		bool UpdateShareholder(DataLayer::OrmasDal& ormasDal, int uID, double sCountOfStock, std::string aInformation, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetShareholderByID(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		void TrimStrings(std::string&);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}

#endif //ShareholderCLASS_H