#ifndef PRODUCTIONCLASS_H
#define PRODUCTIONCLASS_h

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class Production
	{
		int id = 0;
		std::string productionDate = "";
		std::string expiryDate = "";
		std::string sessionStart = "";
		std::string sessionEnd = "";
	public:
		Production(int pID, std::string pProductionDate, std::string pExpiryDate, std::string pSessionStart, std::string pSessionEnd) 
			:id(pID), productionDate(pProductionDate), expiryDate(pExpiryDate), sessionStart(pSessionStart), sessionEnd(pSessionEnd){};
		Production(DataLayer::productionCollection);
		Production(){};
		~Production(){};
		std::map<int, double> prodCountMap;

		int warehouseID = 0;
		//ProductType class Accessors
		int GetID();
		std::string GetProductionDate();
		std::string GetExpiryDate();
		std::string GetSessionStart();
		std::string GetSessionEnd();

		//Please implement Muttators
		void SetID(int);
		void SetProductionDate(std::string);
		void SetExpiryDate(std::string);
		void SetSessionStart(std::string);
		void SetSessionEnd(std::string);

		//Create, delete, update methods
		bool CreateProduction(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateProduction(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteProduction(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateProduction(DataLayer::OrmasDal& ormasDal, std::string pProductionDate, std::string pExpiryDate,
			std::string pSessionStart, std::string pSessionEnd, std::string& errorMessage);
		bool UpdateProduction(DataLayer::OrmasDal& ormasDal, std::string pProductionDate, std::string pExpiryDate,
			std::string pSessionStart, std::string pSessionEnd, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		std::string GenerateFilterForPeriod(DataLayer::OrmasDal& ormasDal, std::string fromDate, std::string toDate);
		bool GetProductionByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string pProductionDate, std::string pExpiryDate,
			std::string pSessionStart, std::string pSessionEnd, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int pID, int warID, std::string& errorMessage);
		bool ChangesAtStock(DataLayer::OrmasDal& ormasDal, int pID, int warID, std::map<int, double> pProdCountMap, std::string& errorMessage);
	};
}
#endif //PRODYUCTIONCLASS_H