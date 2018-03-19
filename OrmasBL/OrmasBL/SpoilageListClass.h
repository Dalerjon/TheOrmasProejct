#ifndef SpoilageLISTCLASS_H
#define SpoilageLISTCLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer
{
	class SpoilageList
	{
	protected:
		int id = 0;
		int spoilageID = 0;
		int productID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		SpoilageList(int slID, int sID, int pID, int slCount, double slSum, int stsID, int cID) :id(slID), spoilageID(sID), 
			productID(pID),	count(slCount), sum(slSum), statusID(stsID), currencyID(cID){};
		SpoilageList(DataLayer::spoilageListCollection);
		SpoilageList(){};
		~SpoilageList(){};

		//SpoilageList class Accessors
		int GetID();
		int GetSpoilageID();
		int GetProductID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//SpoilageList class Mutators
		void SetID(int);
		void SetSpoilageID(int);
		void SetProductID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateSpoilageList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateSpoilageList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteSpoilageList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteListBySpoilageID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool CreateSpoilageList(DataLayer::OrmasDal& ormasDal, int sID, int pID, int slCount, double slSum,
			int stsID, int cID, std::string& errorMessage);
		bool UpdateSpoilageList(DataLayer::OrmasDal& ormasDal, int sID, int pID, int slCount, double slSum,
			int stsID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetSpoilageListByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int sID, int pID, int slCount, double slSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif