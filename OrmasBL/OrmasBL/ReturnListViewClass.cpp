#include "stdafx.h"
#include "ReturnListViewClass.h"

namespace BusinessLayer
{
	ReturnListView::ReturnListView(DataLayer::returnListViewCollection rCollection)
	{
		id = std::get<0>(rCollection);
		returnID = std::get<1>(rCollection);
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

	std::string ReturnListView::GetProductName()
	{
		return productName;
	}
	double ReturnListView::GetPrice()
	{
		return price;
	}
	std::string ReturnListView::GetCurrencyName()
	{
		return currencyName;
	}
	double ReturnListView::GetVolume()
	{
		return volume;
	}
	std::string ReturnListView::GetStatusName()
	{
		return statusName;
	}
	std::string ReturnListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string ReturnListView::GetMeasureName()
	{
		return measureName;
	}

}