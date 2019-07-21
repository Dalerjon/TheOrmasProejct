#include "stdafx.h"
#include "StockHistoryViewClass.h"

namespace BusinessLayer
{
	StockHistoryView::StockHistoryView(DataLayer::stockHistoryViewCollection sCollection)
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
		historyDate = std::get<16>(sCollection);
	}

	std::string StockHistoryView::GetProductName()
	{
		return productName;
	}
	double StockHistoryView::GetPrice()
	{
		return price;
	}
	std::string StockHistoryView::GetCurrencyName()
	{
		return currencyName;
	}
	double StockHistoryView::GetVolume()
	{
		return volume;
	}
	std::string StockHistoryView::GetStatusName()
	{
		return statusName;
	}
	std::string StockHistoryView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string StockHistoryView::GetMeasureName()
	{
		return measureName;
	}
	std::string StockHistoryView::GetWarehouseName()
	{
		return warehouseName;
	}
	std::string StockHistoryView::GetSubaccountNumber()
	{
		return subaccountNumber;
	}

}