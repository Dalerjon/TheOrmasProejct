#include "stdafx.h"
#include "FixedAssetsDetailsViewClass.h"

namespace BusinessLayer
{
	FixedAssetsDetailsView::FixedAssetsDetailsView(DataLayer::fixedAssetsDetailsViewCollection fCollection)
	{
		id = std::get<0>(fCollection);
		groupNumber = std::get<1>(fCollection);
		amortizeTypeName = std::get<2>(fCollection);
		amortizeTypeCode = std::get<3>(fCollection);
		divisionName = std::get<4>(fCollection);
		primaryCostValue = std::get<5>(fCollection);
		amortizeValue = std::get<6>(fCollection);
		barcodeNumber = std::get<7>(fCollection);
		fixedAssetsLocation = std::get<8>(fCollection);
		primaryCostAccountID = std::get<9>(fCollection);
		amortizeAccountID = std::get<10>(fCollection);
		amortizeGroupID = std::get<11>(fCollection);
		amortizeTypeID = std::get<12>(fCollection);
		departmentID = std::get<13>(fCollection);
	}

	int FixedAssetsDetailsView::GetGroupNumber()
	{
		return groupNumber;
	}
	std::string FixedAssetsDetailsView::GetAmortizeTypeName()
	{
		return amortizeTypeName;
	}
	std::string FixedAssetsDetailsView::GetAmortizeTypeCode()
	{
		return amortizeTypeCode;
	}
	std::string FixedAssetsDetailsView::GetDivisionName()
	{
		return divisionName;
	}
	double FixedAssetsDetailsView::GetPrimaryCostValue()
	{
		return primaryCostValue;
	}
	double FixedAssetsDetailsView::GetAmortizeValue()
	{
		return amortizeValue;
	}
}

