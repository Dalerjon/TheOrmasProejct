#include "stdafx.h"
#include "PostingFixedAssetsViewClass.h"

namespace BusinessLayer
{
	PostingFixedAssetsView::PostingFixedAssetsView(DataLayer::postingFixedAssetsViewCollection pCollection)
	{
		id = std::get<0>(pCollection);
		surname = std::get<1>(pCollection);
		accountName = std::get<2>(pCollection);
		userID = std::get<3>(pCollection);
		subaccountID = std::get<4>(pCollection);
		accountID = std::get<5>(pCollection);
		fixedAssetsID = std::get<6>(pCollection);
		inventoryID = std::get<7>(pCollection);
	}

	std::string PostingFixedAssetsView::GetSurname()
	{
		return surname;
	}
	std::string PostingFixedAssetsView::GetAccountName()
	{
		return accountName;
	}
}

