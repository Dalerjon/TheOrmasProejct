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
		amortizeValue = std::get<4>(fCollection);
		divisionName = std::get<5>(fCollection);
		primaryAccValue = std::get<6>(fCollection);
		amortizeAccValue = std::get<7>(fCollection);
		barcodeNumber = std::get<8>(fCollection);
		fixedAssetsLocation = std::get<9>(fCollection);
		primaryCostAccountID = std::get<10>(fCollection);
		amortizeAccountID = std::get<11>(fCollection);
		amortizeGroupID = std::get<12>(fCollection);
		amortizeTypeID = std::get<13>(fCollection);
		departmentID = std::get<14>(fCollection);
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
	double FixedAssetsDetailsView::GetPrimaryAccValue()
	{
		return primaryAccValue;
	}
	double FixedAssetsDetailsView::GetAmortizeAccValue()
	{
		return amortizeAccValue;
	}
}

