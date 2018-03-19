#include "stdafx.h"
#include "ProductionPlanListViewClass.h"

namespace BusinessLayer
{
	ProductionPlanListView::ProductionPlanListView(DataLayer::productionPlanListViewCollection ppCollection)
	{
		id = std::get<0>(ppCollection);
		productionPlanID = std::get<1>(ppCollection);
		productName = std::get<2>(ppCollection);
		price = std::get<3>(ppCollection);
		currencyName = std::get<4>(ppCollection);
		volume = std::get<5>(ppCollection);
		measureName = std::get<6>(ppCollection);
		count = std::get<7>(ppCollection);
		sum = std::get<8>(ppCollection);
		sumCurrencyName = std::get<9>(ppCollection);
		statusName = std::get<10>(ppCollection);
		productID = std::get<11>(ppCollection);
		statusID = std::get<12>(ppCollection);
		currencyID = std::get<13>(ppCollection);
	}

	std::string ProductionPlanListView::GetProductName()
	{
		return productName;
	}
	double ProductionPlanListView::GetPrice()
	{
		return price;
	}
	std::string ProductionPlanListView::GetCurrencyName()
	{
		return currencyName;
	}
	double ProductionPlanListView::GetVolume()
	{
		return volume;
	}
	std::string ProductionPlanListView::GetStatusName()
	{
		return statusName;
	}
	std::string ProductionPlanListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string ProductionPlanListView::GetMeasureName()
	{
		return measureName;
	}

}