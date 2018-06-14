#ifndef WRITEOFFRAWLISTCLASS_H
#define WRITEOFFRAWLISTCLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer
{
	class WriteOffRawList
	{
	protected:
		int id = 0;
		int writeOffRawID = 0;
		int productID = 0;
		double count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		WriteOffRawList(int wlID, int wID, int pID, double wlCount, double wlSum, int sID, int cID) :id(wlID), writeOffRawID(wID),
			productID(pID),	count(wlCount), sum(wlSum), statusID(sID), currencyID(cID){};
		WriteOffRawList(DataLayer::writeOffRawListCollection);
		WriteOffRawList(){};
		~WriteOffRawList(){};

		//WriteOffRawList class Accessors
		int GetID();
		int GetWriteOffRawID();
		int GetProductID();
		double GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//WriteOffRawList class Mutators
		void SetID(int);
		void SetWriteOffRawID(int);
		void SetProductID(int);
		void SetCount(double);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateWriteOffRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateWriteOffRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteWriteOffRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteListByWriteOffRawID(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		bool CreateWriteOffRawList(DataLayer::OrmasDal& ormasDal, int wID, int pID, double wlCount, double wlSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateWriteOffRawList(DataLayer::OrmasDal& ormasDal, int wID, int pID, double wlCount, double wlSum,
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetWriteOffRawListByID(DataLayer::OrmasDal& ormasDal, int wID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int wID, int pID, double wlCount, double wlSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif