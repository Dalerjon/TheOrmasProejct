#include "stdafx.h"
#include "AccessViewClass.h"

namespace BusinessLayer{
	AccessView::AccessView(DataLayer::accessesViewCollection aCollection)
	{
		id = std::get<0>(aCollection);
		roleName = std::get<1>(aCollection);
		accessItemEng = std::get<2>(aCollection);
		accessItemRu = std::get<3>(aCollection);
		division = std::get<4>(aCollection);
		roleID = std::get<5>(aCollection);
		accessItemID = std::get<6>(aCollection);
	}

	std::string AccessView::GetRoleName()
	{
		return roleName;
	}
	std::string AccessView::GetAccessItemEng()
	{
		return accessItemEng;
	}
	std::string AccessView::GetAccessItemRu()
	{
		return accessItemRu;
	}
	std::string AccessView::GetDivision()
	{
		return division;
	}
}