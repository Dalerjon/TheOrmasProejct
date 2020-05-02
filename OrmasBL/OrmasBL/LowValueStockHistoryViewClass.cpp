#include "stdafx.h"
#include "LowValueStockHistoryViewClass.h"

namespace BusinessLayer
{
	LowValueStockHistoryView::LowValueStockHistoryView(DataLayer::lowValueStockHistoryViewCollection sCollection)
	{
		id = std::get<0>(sCollection);
		otherStocksName = std::get<1>(sCollection);
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
		otherStocksID = std::get<12>(sCollection);
		statusID = std::get<13>(sCollection);
		currencyID = std::get<14>(sCollection);
		warehouseID = std::get<15>(sCollection);
		historyDate = std::get<16>(sCollection);
	}

	std::string LowValueStockHistoryView::GetOtherStocksName()
	{
		return otherStocksName;
	}
	double LowValueStockHistoryView::GetPrice()
	{
		return price;
	}
	std::string LowValueStockHistoryView::GetCurrencyName()
	{
		return currencyName;
	}
	double LowValueStockHistoryView::GetVolume()
	{
		return volume;
	}
	std::string LowValueStockHistoryView::GetStatusName()
	{
		return statusName;
	}
	std::string LowValueStockHistoryView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string LowValueStockHistoryView::GetMeasureName()
	{
		return measureName;
	}
	std::string LowValueStockHistoryView::GetWarehouseName()
	{
		return warehouseName;
	}
	std::string LowValueStockHistoryView::GetSubaccountNumber()
	{
		return subaccountNumber;
	}

}