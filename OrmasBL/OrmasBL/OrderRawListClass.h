#ifndef ORDERRAWLISTCLASS_H
#define ORDERRAWLISTCLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer
{
	class OrderRawList
	{
	protected:
		int id = 0;
		int orderRawID = 0;
		int productID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		OrderRawList(int olID, int oID, int pID, int olCount, double olSum, int sID, int cID) :id(olID), orderRawID(oID),
			productID(pID),	count(olCount), sum(olSum), statusID(sID), currencyID(cID){};
		OrderRawList(DataLayer::orderRawListCollection);
		OrderRawList(){};
		~OrderRawList(){};

		//OrderRawList class Accessors
		int GetID();
		int GetOrderRawID();
		int GetProductID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//OrderRawList class Mutators
		void SetID(int);
		void SetOrderRawID(int);
		void SetProductID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateOrderRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateOrderRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteOrderRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteListByOrderRawID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool CreateOrderRawList(DataLayer::OrmasDal& ormasDal, int oID, int pID, int olCount, double olSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateOrderRawList(DataLayer::OrmasDal& ormasDal, int oID, int pID, int olCount, double olSum,
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetOrderRawListByID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int oID, int pID, int olCount, double olSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif