#ifndef RECEIPTRAWLISTCLASS_H
#define RECEIPTRAWLISTCLASS_H
#include "OrmasDAL.h"

namespace BusinessLayer
{
	class ReceiptRawList
	{
	protected:
		int id = 0;
		int receiptRawID = 0;
		int productID = 0;
		double count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
	public:
		ReceiptRawList(int rlID, int rpID, int pID, double rlCount, double rlSum, int sID, int cID) :id(rlID), receiptRawID(rpID),
			productID(pID),	count(rlCount), sum(rlSum), statusID(sID), currencyID(cID){};
		ReceiptRawList(DataLayer::receiptRawListCollection);
		ReceiptRawList(){};
		~ReceiptRawList(){};

		int stockEmployeeID = 0 ;
		//ReceiptRawList class Accessors
		int GetID();
		int GetReceiptRawID();
		int GetProductID();
		double GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();

		//ReceiptRawList class Mutators
		void SetID(int);
		void SetReceiptRawID(int);
		void SetProductID(int);
		void SetCount(double);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);

		//Create, delete, update methods
		bool CreateReceiptRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateReceiptRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteReceiptRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteListByReceiptRawID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage);
		bool CreateReceiptRawList(DataLayer::OrmasDal& ormasDal, int rID, int pID, double rlCount, double rlSum,
			int sID, int cID, std::string& errorMessage);
		bool UpdateReceiptRawList(DataLayer::OrmasDal& ormasDal, int rID, int pID, double rlCount, double rlSum,
			int sID, int cID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetReceiptRawListByID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int rID, int pID, double rlCount, double rlSum,
			int cID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif