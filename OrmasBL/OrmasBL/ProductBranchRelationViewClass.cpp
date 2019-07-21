#include "stdafx.h"
#include "ProductBranchRelationViewClass.h"

namespace BusinessLayer{
	ProductBranchRelationView::ProductBranchRelationView(DataLayer::productBranchViewCollection wCollection)
	{
		id = std::get<0>(wCollection);
		branchName = std::get<1>(wCollection);
		branchAddress = std::get<2>(wCollection);
		productName = std::get<3>(wCollection);
		price = std::get<4>(wCollection);
		productID = std::get<5>(wCollection);
		branchID = std::get<6>(wCollection);
	}

	std::string ProductBranchRelationView::GetBranchName()
	{
		return branchName;
	}
	std::string ProductBranchRelationView::GetBranchAddress()
	{
		return branchAddress;
	}
	std::string ProductBranchRelationView::GetProductName()
	{
		return productName;
	}
	double ProductBranchRelationView::GetPrice()
	{
		return price;
	}
}