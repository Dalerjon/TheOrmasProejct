#ifndef WRITEOFFLISTCLASS_H
#define WRITEOFFLISTCLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer
{
	class WriteOffList
	{
	protected:
		int id = 0;
		int writeOffID = 0;
		int productID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		WriteOffList(int wlID, int wID, int pID, int wlCount, double wlSum, int sID, int cID) :id(wlID), writeOffID(wID), productID(pID),
			count(wlCount), sum(wlSum), statusID(sID), currencyID(cID){};
		WriteOffList(DataLayer::writeOffListCollection);
		WriteOffList(){};
		~WriteOffList(){};

		//WriteOffList class Accessors
		int GetID();
		int GetWriteOffID();
		int GetProductID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//WriteOffList class Mutators
		void SetID(int);
		void SetWriteOffID(int);
		void SetProductID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateWriteOffList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateWriteOffList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteWriteOffList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateWriteOffList(DataLayer::OrmasDal& ormasDal, int wID, int pID, int wlCount, double wlSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateWriteOffList(DataLayer::OrmasDal& ormasDal, int wID, int pID, int wlCount, double wlSum,
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetWriteOffListByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int wID, int pID, int wlCount, double wlSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif