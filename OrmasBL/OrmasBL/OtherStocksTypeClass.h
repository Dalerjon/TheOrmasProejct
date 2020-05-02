#ifndef OTHERSTOCKSTYPECLASS_H
#define OTHERSTOCKSTYPECLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer
{
	class OtherStocksType
	{
		int id = 0;
		std::string name = "";
		std::string shortName = "";
		std::string code = "";
	public:
		OtherStocksType(int pTypeID, std::string pTypeName, std::string pTypeShortName, std::string pTypeCode) :id(pTypeID),
			name(pTypeName), shortName(pTypeShortName), code(pTypeCode){};
		OtherStocksType(DataLayer::otherStocksTypeCollection);
		OtherStocksType(){};
		~OtherStocksType(){};

		//OtherStocksType class Accessors
		int GetID();
		std::string GetName();
		std::string GetShortName();
		std::string GetCode();

		//Please implement Muttators
		void SetID(int);
		void SetName(std::string);
		void SetShortName(std::string);
		void SetCode(std::string);

		//Create, delete, update methods
		bool CreateOtherStocksType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdateOtherStocksType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeleteOtherStocksType(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreateOtherStocksType(DataLayer::OrmasDal& ormasDal, std::string pTypeName, std::string pTypeShortName, std::string pTypeCode,
			std::string& errorMessage);
		bool UpdateOtherStocksType(DataLayer::OrmasDal& ormasDal, std::string pTypeName, std::string pTypeShortName, std::string pTypeCode,
			std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetOtherStocksTypeByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool GetOtherStocksTypeByCode(DataLayer::OrmasDal& ormasDal, std::string pCode, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		void TrimStrings(std::string&, std::string&, std::string&);
		bool IsDuplicate(DataLayer::OrmasDal&, std::string pTypeName, std::string pTypeShortName, std::string pCode, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //OtherStocksTYPECLASS_H