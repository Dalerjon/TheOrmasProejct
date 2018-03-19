#include "stdafx.h"
#include "SpecificationListViewClass.h"

namespace BusinessLayer
{
	SpecificationListView::SpecificationListView(DataLayer::specificationListViewCollection sCollection)
	{
		id = std::get<0>(sCollection);
		specificationID = std::get<1>(sCollection);
		productName = std::get<2>(sCollection);
		count = std::get<3>(sCollection);
		measureName = std::get<4>(sCollection);
		productID = std::get<5>(sCollection);
	}

	std::string SpecificationListView::GetProductName()
	{
		return productName;
	}

	std::string SpecificationListView::GetMeasureName()
	{
		return measureName;
	}

}