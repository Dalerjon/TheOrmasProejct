#include "stdafx.h"
#include "FixedAssetsViewClass.h"

namespace BusinessLayer
{
	FixedAssetsView::FixedAssetsView(DataLayer::fixedAssetsViewCollection fCollection)
	{
		id = std::get<0>(fCollection);
		name = std::get<1>(fCollection);
		inventoryNumber = std::get<2>(fCollection);
		primaryCost = std::get<3>(fCollection);
		stopCost = std::get<4>(fCollection);
		primaryCostValue = std::get<5>(fCollection);
		amortizeValue = std::get<6>(fCollection);
		divisionName = std::get<7>(fCollection);
		statusName = std::get<8>(fCollection);
		serviceLife = std::get<9>(fCollection);
		isAmortize = std::get<10>(fCollection);
		buyDate = std::get<11>(fCollection);
		startOfOperationDate = std::get<12>(fCollection);
		endOfOperationDate = std::get<13>(fCollection);
		specificationID = std::get<14>(fCollection);
		statusID = std::get<15>(fCollection);
		fixedAssetsDetailsID = std::get<16>(fCollection);
	}

	std::string FixedAssetsView::GetName()
	{
		return name;
	}
	double FixedAssetsView::GetPrimaryCostValue()
	{
		return primaryCostValue;
	}
	double FixedAssetsView::GetAmortizeValue()
	{
		return amortizeValue;
	}
	std::string FixedAssetsView::GetDivisionName()
	{
		return divisionName;
	}
	std::string FixedAssetsView::GetStatusName()
	{
		return statusName;
	}
}

