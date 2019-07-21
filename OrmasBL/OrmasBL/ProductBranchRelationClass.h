#ifndef ProductBranchRELATIONCLASS_H
#define ProductBranchRELATIONCLASS_H

#include "OrmasDAL.h"

namespace BusinessLayer{
	class ProductBranchRelation
	{
	protected:
		int id = 0;
		int productID = 0;
		int branchID = 0;
	public:
		ProductBranchRelation();
		ProductBranchRelation(int pbID, int pID, int bID) : id(pbID), productID(pID), branchID(bID){};
		ProductBranchRelation(DataLayer::productBranchCollection);
		~ProductBranchRelation(){};

		std::string errorMessage = "";
		//Access class Accessors
		int GetID();
		int GetBranchID();
		int GetProductID();

		//Access class Mutators
		void SetID(int);
		void SetBranchID(int);
		void SetProductID(int);

		// Create, delete and update Access
		bool CreateProductBranchRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool DeleteProductBranchRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool CreateProductBranchRelation(DataLayer::OrmasDal &ormasDal, int pID, int bID, std::string& errorMessage);
		bool UpdateProductBranchRelation(DataLayer::OrmasDal &ormasDal, std::string& errorMessage);
		bool UpdateProductBranchRelation(DataLayer::OrmasDal &ormasDal, int pID, int bID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetProductBranchByID(DataLayer::OrmasDal& ormasDal, int pbID, std::string& errorMessage);
		std::vector<int> GetAllProductByBranchID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage);
		std::vector<int> GetAllBranchByProductID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int pID, int bID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif