#ifndef ProductionStockCLASS_H
#define ProductionStockCLASS_H
#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class ProductionStock
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
		ProductionStock(int psID, int pID, double psCount, double psSum, int stsID, int cID, int wID) :id(psID),
			productID(pID), count(psCount), sum(psSum), statusID(stsID), currencyID(cID), warehouseID(wID){};
		ProductionStock(DataLayer::productionStockCollection);
		ProductionStock(){};
		~ProductionStock(){};

		//ProductionStock class Accessors
		int GetID();
		int GetProductID();
		double GetCount();
		double GetSum();
		int GetStatusID();
		int GetCurrencyID();
		int GetWarehouseID();

		//ProductionStock class Mutators
		void SetID(int);
		void SetProductID(int);
		void SetCount(double);
		void SetSum(double);
		void SetStatusID(int);
		void SetCurrencyID(int);
		void SetWarehouseID(int);

		//Create, delete, update methods
		bool CreateProductionStock(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateProductionStock(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteProductionStock(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateProductionStock(DataLayer::OrmasDal& ormasDal, int pID, double sCount, double sSum,
			int sID, int cID, int wID, std::string& errorMessage);
		bool UpdateProductionStock(DataLayer::OrmasDal& ormasDal, int pID, double sCount, double sSum,
			int sID, int cID, int wID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetProductionStockByID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage);
		bool GetProductionStockByProductID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();

		bool ChangingByProduction(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		bool ChangingByProduction(DataLayer::OrmasDal& ormasDal, int cpID, std::map<int, double> pProdCountMap, std::string& errorMessage);
		bool ChangingByStockTransfer(DataLayer::OrmasDal& ormasDal, int rrID, std::string& errorMessage);
		bool ChangingByStockTransfer(DataLayer::OrmasDal& ormasDal, int rrID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByConsumeProduct(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		bool ChangingByConsumeProduct(DataLayer::OrmasDal& ormasDal, int cpID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByConsumeRaw(DataLayer::OrmasDal& ormasDal, int cpID, std::string& errorMessage);
		bool ChangingByConsumeRaw(DataLayer::OrmasDal& ormasDal, int crID, std::map<int, double> pProdCountMap, double pSum, std::string& errorMessage);
		bool ChangingByReworkRawDec(DataLayer::OrmasDal& ormasDal, int pID, double count, double sum, std::string& errorMessage);
		bool ChangingByReworkRawInc(DataLayer::OrmasDal& ormasDal, int pID, double count, double sum, std::string& errorMessage);
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string& errorMessage);
		bool CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, double previousSum, std::string& errorMessage);
		std::string wstring_to_utf8(const std::wstring& str);
	};
}
#endif