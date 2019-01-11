#include "stdafx.h"
#include "StockViewClass.h"

namespace BusinessLayer
{
	StockView::StockView(DataLayer::stockViewCollection sCollection)
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
		warehouseName = std::get<9>(sCollection);
		subaccountNumber = std::get<10>(sCollection);
		statusName = std::get<11>(sCollection);
		productID = std::get<12>(sCollection);
		statusID = std::get<13>(sCollection);
		currencyID = std::get<14>(sCollection);
		warehouseID = std::get<15>(sCollection);
	}

	std::string StockView::GetProductName()
	{
		return productName;
	}
	double StockView::GetPrice()
	{
		return price;
	}
	std::string StockView::GetCurrencyName()
	{
		return currencyName;
	}
	double StockView::GetVolume()
	{
		return volume;
	}
	std::string StockView::GetStatusName()
	{
		return statusName;
	}
	std::string StockView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string StockView::GetMeasureName()
	{
		return measureName;
	}
	std::string StockView::GetWarehouseName()
	{
		return warehouseName;
	}
	std::string StockView::GetSubaccountNumber()
	{
		return subaccountNumber;
	}

}