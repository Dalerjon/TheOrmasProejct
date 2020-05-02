#ifndef CONSUMEOTHERSTOCKSLISTCLASS_H
#define CONSUMEOTHERSTOCKSLISTCLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer
{
	class ConsumeOtherStocksList
	{
	protected:
		int id = 0;
		int consumeOtherStocksID = 0;
		int otherStocksID = 0;
		double count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		ConsumeOtherStocksList(int clID, int crID, int osID, double clCount, double clSum, int sID, int cID) :id(clID), consumeOtherStocksID(crID),
			otherStocksID(osID), count(clCount), sum(clSum), statusID(sID), currencyID(cID){};
		ConsumeOtherStocksList(DataLayer::consumeOtherStocksListCollection);
		ConsumeOtherStocksList(){};
		~ConsumeOtherStocksList(){};

		int employeeID = 0;
		int stockEmployeeID = 0;

		//ConsumeOtherStocksList class Accessors
		int GetID();
		int GetConsumeOtherStocksID();
		int GetOtherStocksID();
		double GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//ConsumeOtherStocksList class Mutators
		void SetID(int);
		void SetConsumeOtherStocksID(int);
		void SetOtherStocksID(int);
		void SetCount(double);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateConsumeOtherStocksList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateConsumeOtherStocksList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteConsumeOtherStocksList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteListByConsumeOtherStocksID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage);
		bool CreateConsumeOtherStocksList(DataLayer::OrmasDal& ormasDal, int crID, int osID, double clCount, double clSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateConsumeOtherStocksList(DataLayer::OrmasDal& ormasDal, int crID, int osID, double clCount, double clSum,
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetConsumeOtherStocksListByID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int crID, int osID, double clCount, double clSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif