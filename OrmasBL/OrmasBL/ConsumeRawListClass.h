#ifndef CONSUMERAWLISTCLASS_H
#define CONSUMERAWLISTCLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer
{
	class ConsumeRawList
	{
	protected:
		int id = 0;
		int consumeRawID = 0;
		int productID = 0;
		double count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		ConsumeRawList(int clID, int crID, int pID, double clCount, double clSum, int sID, int cID) :id(clID), consumeRawID(crID),
			productID(pID),	count(clCount), sum(clSum), statusID(sID), currencyID(cID){};
		ConsumeRawList(DataLayer::consumeRawListCollection);
		ConsumeRawList(){};
		~ConsumeRawList(){};

		//ConsumeRawList class Accessors
		int GetID();
		int GetConsumeRawID();
		int GetProductID();
		double GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//ConsumeRawList class Mutators
		void SetID(int);
		void SetConsumeRawID(int);
		void SetProductID(int);
		void SetCount(double);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateConsumeRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateConsumeRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteConsumeRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteListByConsumeRawID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage);
		bool CreateConsumeRawList(DataLayer::OrmasDal& ormasDal, int crID, int pID, double clCount, double clSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateConsumeRawList(DataLayer::OrmasDal& ormasDal, int crID, int pID, double clCount, double clSum,
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetConsumeRawListByID(DataLayer::OrmasDal& ormasDal, int cID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int crID, int pID, double clCount, double clSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif