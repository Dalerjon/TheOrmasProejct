#include "stdafx.h"
#include "StockTransferListViewClass.h"

namespace BusinessLayer
{
	StockTransferListView::StockTransferListView(DataLayer::stockTransferListViewCollection rCollection)
	{
		id = std::get<0>(rCollection);
		StockTransferID = std::get<1>(rCollection);
		productName = std::get<2>(rCollection);
		price = std::get<3>(rCollection);
		currencyName = std::get<4>(rCollection);
		volume = std::get<5>(rCollection);
		measureName = std::get<6>(rCollection);
		count = std::get<7>(rCollection);
		sum = std::get<8>(rCollection);
		sumCurrencyName = std::get<9>(rCollection);
		statusName = std::get<10>(rCollection);
		productID = std::get<11>(rCollection);
		statusID = std::get<12>(rCollection);
		currencyID = std::get<13>(rCollection);
	}

	std::string StockTransferListView::GetProductName()
	{
		return productName;
	}
	double StockTransferListView::GetPrice()
	{
		return price;
	}
	std::string StockTransferListView::GetCurrencyName()
	{
		return currencyName;
	}
	double StockTransferListView::GetVolume()
	{
		return volume;
	}
	std::string StockTransferListView::GetStatusName()
	{
		return statusName;
	}
	std::string StockTransferListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string StockTransferListView::GetMeasureName()
	{
		return measureName;
	}

}