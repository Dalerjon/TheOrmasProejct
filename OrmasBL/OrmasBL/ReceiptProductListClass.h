#ifndef RECEIPTPRODUCTLISTCLASS_H
#define RECEIPTPRODUCTLISTCLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer
{
	class ReceiptProductList
	{
	protected:
		int id = 0;
		int receiptProductID = 0;
		int productID = 0;
		int count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		ReceiptProductList(int rlID, int rID, int pID, int rlCount, double rlSum, int sID, int cID) :id(rlID), receiptProductID(rID),
			productID(pID),	count(rlCount), sum(rlSum), statusID(sID), currencyID(cID){};
		ReceiptProductList(DataLayer::receiptProductListCollection);
		ReceiptProductList(){};
		~ReceiptProductList(){};

		//ReceiptProductList class Accessors
		int GetID();
		int GetReceiptProductID();
		int GetProductID();
		int GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//ReceiptProductList class Mutators
		void SetID(int);
		void SetReceiptProductID(int);
		void SetProductID(int);
		void SetCount(int);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateReceiptProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateReceiptProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteReceiptProductList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteListByReceiptProductID(DataLayer::OrmasDal& ormasDal, int rpID, std::string& errorMessage);
		bool CreateReceiptProductList(DataLayer::OrmasDal& ormasDal, int rpID, int pID, int rlCount, double rlSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateReceiptProductList(DataLayer::OrmasDal& ormasDal, int rpID, int pID, int rlCount, double rlSum,
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetReceiptProductListByID(DataLayer::OrmasDal& ormasDal, int rpID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int rpID, int pID, int rlCount, double rlSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //RECEIPTPRODUCTLISTCLASS_H