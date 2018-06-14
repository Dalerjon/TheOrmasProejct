#ifndef ORDERLISTCLASS_H
#define ORDERLISTCLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer
{
	class OrderList
	{
	protected:
		int id = 0;
		int orderID = 0;
		int productID = 0;
		double count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		OrderList(int olID, int oID, int pID, double olCount, double olSum, int sID, int cID) :id(olID), orderID(oID), productID(pID),
			count(olCount), sum(olSum), statusID(sID), currencyID(cID){};
		OrderList(DataLayer::orderListCollection);
		OrderList(){};
		~OrderList(){};

		//OrderList class Accessors
		int GetID();
		int GetOrderID();
		int GetProductID();
		double GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//OrderList class Mutators
		void SetID(int);
		void SetOrderID(int);
		void SetProductID(int);
		void SetCount(double);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateOrderList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateOrderList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteOrderList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteListByOrderID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage);
		bool CreateOrderList(DataLayer::OrmasDal& ormasDal, int oID, int pID, double olCount, double olSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateOrderList(DataLayer::OrmasDal& ormasDal, int oID, int pID, double olCount, double olSum,
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetOrderListByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int oID, int pID, double olCount, double olSum,
			 int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif