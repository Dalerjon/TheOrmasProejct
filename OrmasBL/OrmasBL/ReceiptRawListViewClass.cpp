#include "stdafx.h"
#include "ReceiptRawListViewClass.h"

namespace BusinessLayer
{
	ReceiptRawListView::ReceiptRawListView(DataLayer::receiptRawListViewCollection rCollection)
	{
		id = std::get<0>(rCollection);
		receiptRawID = std::get<1>(rCollection);
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

	std::string ReceiptRawListView::GetProductName()
	{
		return productName;
	}
	double ReceiptRawListView::GetPrice()
	{
		return price;
	}
	std::string ReceiptRawListView::GetCurrencyName()
	{
		return currencyName;
	}
	double ReceiptRawListView::GetVolume()
	{
		return volume;
	}
	std::string ReceiptRawListView::GetStatusName()
	{
		return statusName;
	}
	std::string ReceiptRawListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string ReceiptRawListView::GetMeasureName()
	{
		return measureName;
	}

}