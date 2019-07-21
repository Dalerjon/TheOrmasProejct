#ifndef ProductBranchRELATIONVIEWCLASS_H
#define ProductBranchRELATIONVIEWCLASS_H

#include "ProductBranchRelationClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class ProductBranchRelationView : public ProductBranchRelation
	{
		std::string branchName = "";
		std::string branchAddress = "";
		std::string productName = "";
		double price = 0;
	public:
		ProductBranchRelationView(DataLayer::productBranchViewCollection);
		ProductBranchRelationView(){};
		~ProductBranchRelationView(){};

		// ProductBranchRelationView class ProductBranchRelationors
		std::string GetBranchName();
		std::string GetBranchAddress();
		std::string GetProductName();
		double GetPrice();
	};
}
#endif