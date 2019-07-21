#ifndef STOCKCLASS_H
#define STOCKCLASS_H
#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class Stock
	{
	protected:
		int id = 0;
		int productID = 0;
		double count = 0;
		double sum = 0;
		int statusID = 0;
		int currencyID = 0;
		int warehouseID = 0;
	public:
		Stock(int sID, int pID, int sCount, double sSum, int stsID, int cID, int wID) :id(sID),
			productID(pID),	count(sCount), sum(sSum), statusID(stsID), currencyID(cID), warehouseID(wID){};
		Stock(DataLayer::stockCollection);
		Stock(){};
		~Stock(){};

		//Stock class Accessors
		int GetID();
		int GetProductID();
		double GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();
		int GetWarehouseID();


		//Stock class Mutators
		void SetID(int);
		void SetProductID(int);
		void SetCount(double);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);
		void SetWarehouseID(int);

		//Create, delete, update methods
		bool CreateStock(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateStock(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteStock(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateStock(DataLayer::OrmasDal& ormasDal, int pID, double sCount, double sSum,
			int sID, int cID, int wID, std::string& errorMessage);
		bool UpdateStock(DataLayer::OrmasDal& ormasDal, int pID, double sCount, double sSum,
			int sID, int cID, int wID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetStockByID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage);
		bool GetStockByProductID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool GetStockByProductAndWarehouseID(DataLayer::OrmasDal& ormasDal, int pID, int wID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();

		bool ChangingByConsumeProduct(DataLayer::OrmasDal& ormasDal, int cpID, int stockEmpID, std::string& errorMessage);
		bool ChangingByConsumeProductCancel(DataLayer::OrmasDal& ormasDal, int cpID, int stockEmpID, std::string& errorMessage);
		bool ChangingByConsumeProduct(DataLayer::OrmasDal& ormasDal, int cpID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByConsumeRaw(DataLayer::OrmasDal& ormasDal, int crID, int empID, int stockEmpID, std::string& errorMessage);
		bool ChangingByConsumeRawCancel(DataLayer::OrmasDal& ormasDal, int crID, int empID, int stockEmpID, std::string& errorMessage);
		bool ChangingByConsumeRaw(DataLayer::OrmasDal& ormasDal, int crID, int empID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByConsumeRawAtSecondStock(DataLayer::OrmasDal& ormasDal, int crID, int debWerID, std::string& errorMessage);
		bool ChangingByConsumeRawAtSecondStockCancel(DataLayer::OrmasDal& ormasDal, int crID, int debWerID, std::string& errorMessage);
		bool ChangingByConsumeRawAtSecondStock(DataLayer::OrmasDal& ormasDal, int crID, int debWerID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByProdConsumeRaw(DataLayer::OrmasDal& ormasDal, int pcrID, int stockEmpID, std::string& errorMessage);
		bool ChangingByProdConsumeRawCancel(DataLayer::OrmasDal& ormasDal, int pcrID, int stockEmpID, std::string& errorMessage);
		bool ChangingByProdConsumeRaw(DataLayer::OrmasDal& ormasDal, int pcrID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByOrderRaw(DataLayer::OrmasDal& ormasDal, int orID, int empID, std::string& errorMessage);
		bool ChangingByOrderRawCancel(DataLayer::OrmasDal& ormasDal, int orID, int empID, std::string& errorMessage);
		bool ChangingByOrderRaw(DataLayer::OrmasDal& ormasDal, int orID, int empID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByReceiptProduct(DataLayer::OrmasDal& ormasDal, int rpID, int empID, int stockEmpID, std::string& errorMessage);
		bool ChangingByReceiptProductCancel(DataLayer::OrmasDal& ormasDal, int rpID, int empID, int stockEmpID, std::string& errorMessage);
		bool ChangingByReceiptProduct(DataLayer::OrmasDal& ormasDal, int rpID, int empID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByReceiptProductAtSecondStock(DataLayer::OrmasDal& ormasDal, int rpID, int credWerID, std::string& errorMessage);
		bool ChangingByReceiptProductAtSecondStockCancel(DataLayer::OrmasDal& ormasDal, int rpID, int credWerID, std::string& errorMessage);
		bool ChangingByReceiptProductAtSecondStock(DataLayer::OrmasDal& ormasDal, int rpID, int credWerID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByStockTransfer(DataLayer::OrmasDal& ormasDal, int rrID, int empID, int stockEmpID, std::string& errorMessage);
		bool ChangingByStockTransferCancel(DataLayer::OrmasDal& ormasDal, int rrID, int empID, int stockEmpID, std::string& errorMessage);
		bool ChangingByStockTransfer(DataLayer::OrmasDal& ormasDal, int rrID, int empID, int stockEmpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByStockTransferAtSecondStock(DataLayer::OrmasDal& ormasDal, int rpID, int credWerID, std::string& errorMessage);
		bool ChangingByStockTransferAtSecondStockCancel(DataLayer::OrmasDal& ormasDal, int rpID, int credWerID, std::string& errorMessage);
		bool ChangingByStockTransferAtSecondStock(DataLayer::OrmasDal& ormasDal, int rpID, int credWerID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByReturnProduct(DataLayer::OrmasDal& ormasDal, int rpID, int cID, int empID, std::string& errorMessage);
		bool ChangingByReturnProductCancel(DataLayer::OrmasDal& ormasDal, int rpID, int cID, int empID, std::string& errorMessage);
		bool ChangingByReturnProduct(DataLayer::OrmasDal& ormasDal, int rpID, int cID, int empID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByWriteOff(DataLayer::OrmasDal& ormasDal, int wpID, int empID, std::string& errorMessage);
		bool ChangingByWriteOffCancel(DataLayer::OrmasDal& ormasDal, int wpID, int empID, std::string& errorMessage);
		bool ChangingByWriteOff(DataLayer::OrmasDal& ormasDal, int wpID, int empID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByWriteOffRaw(DataLayer::OrmasDal& ormasDal, int wrID, int empID, std::string& errorMessage);
		bool ChangingByWriteOffRawCancel(DataLayer::OrmasDal& ormasDal, int wrID, int empID, std::string& errorMessage);
		bool ChangingByWriteOffRaw(DataLayer::OrmasDal& ormasDal, int wrID, int empID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByProduction(DataLayer::OrmasDal& ormasDal, int pID, int warID, std::string& errorMessage);
		bool ChangingByProduction(DataLayer::OrmasDal& ormasDal, int pID, int warID, std::map<int, double> pProdCountMap, std::string& errorMessage);
		bool RecalculateStock(DataLayer::OrmasDal& ormasDal, int pID, double oldPrice, double newPrice, std::string& errorMessage);
		bool CreateEntry(DataLayer::OrmasDal& ormasDal, int operationID, int debAccID, double currentSum, int credAccID, std::string& errorMessage);
		bool CreateEntry(DataLayer::OrmasDal& ormasDal, int operationID, int debAccID, double currentSum, int credAccID, double previousSum, std::string& errorMessage);
		bool CreateCorrectongEntry(DataLayer::OrmasDal& ormasDal, int id, int debAccID, double currentSum, int credAccID, std::string& errorMessage);
		bool CreateCorrectongEntry(DataLayer::OrmasDal& ormasDal, int id, int debAccID, double currentSum, int credAccID, double previousSum, std::string& errorMessage);
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int pID, int wID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		std::string wstring_to_utf8(const std::wstring& str);

		bool GetSubIDAndWerhIDFromConProd(DataLayer::OrmasDal& ormasDal, int stockEmpID, int& warehouseID, int& subAccID, std::string& errorMessage);
		bool GetSubIDAndWerhIDFromConRaw(DataLayer::OrmasDal& ormasDal, int empID, int stockEmpID, int& debWerID, int& credWerID, int& debSaccID, int& credSaccID, std::string& errorMessage);
		bool GetSubIDAndWerhIDFromOrderRaw(DataLayer::OrmasDal& ormasDal, int empID, int& warehouseID, int& subAccID, std::string& errorMessage);
		bool GetSubIDAndWerhIDFromRcpRaw(DataLayer::OrmasDal& ormasDal, int empID, int stockEmpID, int& debWerID, int& credWerID, int& debSaccID, int& credSaccID, std::string& errorMessage);
		bool GetSubIDAndWerhIDFromRcpProd(DataLayer::OrmasDal& ormasDal, int empID, int stockEmpID, int& debWerID, int& credWerID, int& debSaccID, int& credSaccID, std::string& errorMessage);
		bool GetSubIDAndWerhIDFromRtrnProd(DataLayer::OrmasDal& ormasDal, int empID, int& warehouseID, int& subAccID, std::string& errorMessage);
		bool GetSubIDAndWerhIDFromWOffProd(DataLayer::OrmasDal& ormasDal, int empID, int& warehouseID, int& subAccID, std::string& errorMessage);
		bool GetSubIDAndWerhIDFromWOffRaw(DataLayer::OrmasDal& ormasDal, int empID, int& warehouseID, int& subAccID, std::string& errorMessage);
		bool GetSubIDAndWerhIDFromProdnConRaw(DataLayer::OrmasDal& ormasDal, int stockEmpID, int& warehouseID, int& subAccID, std::string& errorMessage);

	};
}
#endif