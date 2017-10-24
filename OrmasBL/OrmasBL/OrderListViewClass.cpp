#include "stdafx.h"
#include "OrderListViewClass.h"

namespace BusinessLayer
{
	OrderListView::OrderListView(DataLayer::orderListViewCollection oCollection)
	{
		id = std::get<0>(oCollection);
		orderID = std::get<1>(oCollection);
		productName = std::get<2>(oCollection);
		price = std::get<3>(oCollection);
		currencyName = std::get<4>(oCollection);
		volume = std::get<5>(oCollection);
		measureName = std::get<6>(oCollection);
		count = std::get<7>(oCollection);
		sum = std::get<8>(oCollection);
		sumCurrencyName = std::get<9>(oCollection);
		statusName = std::get<10>(oCollection);
		productID = std::get<11>(oCollection);
		statusID = std::get<12>(oCollection);
		currencyID = std::get<13>(oCollection);
	}

	std::string OrderListView::GetProductName()
	{
		return productName;
	}
	double OrderListView::GetPrice()
	{
		return price;
	}
	std::string OrderListView::GetCurrencyName()
	{
		return currencyName;
	}
	double OrderListView::GetVolume()
	{
		return volume;
	}
	std::string OrderListView::GetStatusName()
	{
		return statusName;
	}
	std::string OrderListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string OrderListView::GetMeasureName()
	{
		return measureName;
	}

}