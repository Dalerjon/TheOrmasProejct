#include "stdafx.h"
#include "ReceiptProductListViewClass.h"

namespace BusinessLayer
{
	ReceiptProductListView::ReceiptProductListView(DataLayer::receiptProductListViewCollection rCollection)
	{
		id = std::get<0>(rCollection);
		receiptProductID = std::get<1>(rCollection);
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

	std::string ReceiptProductListView::GetProductName()
	{
		return productName;
	}
	double ReceiptProductListView::GetPrice()
	{
		return price;
	}
	std::string ReceiptProductListView::GetCurrencyName()
	{
		return currencyName;
	}
	double ReceiptProductListView::GetVolume()
	{
		return volume;
	}
	std::string ReceiptProductListView::GetStatusName()
	{
		return statusName;
	}
	std::string ReceiptProductListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string ReceiptProductListView::GetMeasureName()
	{
		return measureName;
	}

}