#include "stdafx.h"
#include "ProductListViewClass.h"

namespace BusinessLayer
{
	ProductListView::ProductListView(DataLayer::productListViewCollection pCollection)
	{
		id = std::get<0>(pCollection);
		orderID = std::get<1>(pCollection);
		returnID = std::get<2>(pCollection);
		productionID = std::get<3>(pCollection);
		productName = std::get<4>(pCollection);
		price = std::get<5>(pCollection);
		currencyName = std::get<6>(pCollection);
		volume = std::get<7>(pCollection);
		measureName = std::get<8>(pCollection);
		count = std::get<9>(pCollection);
		sum = std::get<10>(pCollection);
		sumCurrencyName = std::get<11>(pCollection);
		statusName = std::get<12>(pCollection);
		productID = std::get<13>(pCollection);
		statusID = std::get<14>(pCollection);
		currencyID = std::get<15>(pCollection);
	}

	std::string ProductListView::GetProductName()
	{
		return productName;
	}
	double ProductListView::GetPrice()
	{
		return price;
	}
	std::string ProductListView::GetCurrencyName()
	{
		return currencyName;
	}
	double ProductListView::GetVolume()
	{
		return volume;
	}
	std::string ProductListView::GetStatusName()
	{
		return statusName;
	}
	std::string ProductListView::GetSumCurrencyName()
	{
		return sumCurrencyName;
	}
	std::string ProductListView::GetMeasureName()
	{
		return measureName;
	}

	void ProductListView::SetProductName(std::string pProductName)
	{
		productName = pProductName;
	}
	
	void ProductListView::SetCurrencyName(std::string pCurrencyName)
	{
		currencyName = pCurrencyName;
	}

	void ProductListView::SetPrice(double pPrice)
	{
		price = pPrice;
	}
	void ProductListView::SetVolume(double pVolume)
	{
		volume = pVolume;
	}
	void ProductListView::SetStatusName(std::string pStatusName)
	{
		statusName = pStatusName;
	}
	void ProductListView::SetSumCurrencyName(std::string pSumCurrencyName)
	{
		sumCurrencyName = pSumCurrencyName;
	}
	void ProductListView::SetMeasureName(std::string pMeasureName)
	{
		measureName = pMeasureName;
	}
}