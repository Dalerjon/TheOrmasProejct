#include "stdafx.h"
#include "ProductionStockViewClass.h"

namespace BusinessLayer
{
	ProductionStockView::ProductionStockView(DataLayer::productionStockViewCollection sCollection)
	{
		id = std::get<0>(sCollection);
		productName = std::get<1>(sCollection);
		price = std::get<2>(sCollection);
		currencyName = std::get<3>(sCollection);
		volume = std::get<4>(sCollection);
		measureName = std::get<5>(sCollection);
		count = std::get<6>(sCollection);
		sum = std::get<7>(sCollection);
		sumCurrencyName = std::get<8>(sCollection);
		statusName = std::get<9>(sCollection);
		productID = std::get<10>(sCollection);
		statusID = std::get<11>(sCollection);
		currencyID = std::get<12>(sCollection);
	}

	std::string ProductionStockView::GetProductName()
	{
		return productName;
	}
	double ProductionStockView::GetPrice()
	{
		return price;
	}
	std::string ProductionStockView::GetCurrencyName()
	{
		return currencyName;
	}
	double ProductionStockView::GetVolume()
	{
		return volume;
	}
	std::string ProductionStockView::GetStatusName()
	{
		return statusName;
	}
	std::string ProductionStockView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string ProductionStockView::GetMeasureName()
	{
		return measureName;
	}

}