#include "stdafx.h"
#include "PriceClass.h"

namespace BusinessLayer{
	Price::Price(DataLayer::pricesCollection pCollection)
	{
		id = std::get<0>(pCollection);
		date = std::get<1>(pCollection);
		value = std::get<2>(pCollection);
		currencyID = std::get<3>(pCollection);
		productID = std::get<4>(pCollection);
		isOutdated = std::get<5>(pCollection);
	}
	Price::Price()
	{
		date = "";
		value = 0.0;
		currencyID = 0;
		productID = 0;
		isOutdated = true;
	}
	int Price::GetID()
	{
		return id;
	}

	std::string Price::GetDate()
	{
		return date;
	}

	double Price::GetValue()
	{
		return value;
	}

	int Price::GetCurrencyID()
	{
		return currencyID;
	}

	int Price::GetProductID()
	{
		return productID;
	}

	bool Price::GetIsOutdated()
	{
		return isOutdated;
	}

	void Price::SetID(int pID)
	{
		id = pID;
	}

	void Price::SetDate(std::string pDate)
	{
		date = pDate;
	}

	void Price::SetValue(double pValue)
	{
		value = pValue;
	}

	void Price::SetCurrencyID(int cID)
	{
		currencyID = cID;
	}

	void Price::SetProductID(int prID)
	{
		productID = prID;
	}

	void Price::SetIsOutdated(bool prIsOutdated)
	{
		isOutdated = prIsOutdated;
	}

	bool Price::CreatePrice(DataLayer::OrmasDal &ormasDal, std::string pDate, double pValue, int cID, int prID, bool pIsOutdated,
		std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, pDate, pValue, cID, prID, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		date = pDate;
		value = pValue;
		currencyID = cID;
		productID = prID;
		isOutdated = pIsOutdated;
		if (0 != id && ormasDal.CreatePrice(id, date, value, currencyID, productID, isOutdated, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Price::CreatePrice(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreatePrice(id, date, value, currencyID, productID, isOutdated, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Price::DeletePrice(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeletePrice(id, errorMessage))
		{
			Clear();
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}

	bool Price::UpdatePrice(DataLayer::OrmasDal &ormasDal, std::string pDate, double pValue, int cID, int prID, bool pIsOutdated,
		std::string& errorMessage)
	{
		date = pDate;
		value = pValue;
		currencyID = cID;
		productID = prID;
		isOutdated = pIsOutdated;
		if (0 != id && ormasDal.UpdatePrice(id, date, value, currencyID, productID, isOutdated, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Price::UpdatePrice(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdatePrice(id, date, value, currencyID, productID, isOutdated, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}

	std::string Price::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || date.empty() || 0 != productID || 0 != currencyID || 0 != value || (isOutdated == true || isOutdated == false))
		{
			return ormasDal.GetFilterForPrice(id, date, value, currencyID, productID, isOutdated);
		}
		return "";
	}

	bool Price::GetPriceByID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage)
	{
		id = bID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::pricesViewCollection> priceVector = ormasDal.GetPrices(errorMessage, filter);
		if (0 != priceVector.size())
		{
			id = std::get<0>(priceVector.at(0));
			date = std::get<1>(priceVector.at(0));
			value = std::get<5>(priceVector.at(0));
			currencyID = std::get<7>(priceVector.at(0));
			productID = std::get<8>(priceVector.at(0));
			isOutdated = std::get<9>(priceVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find price with this id";
		}
		return false;
	}

	bool Price::GetPriceByProductID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		productID = pID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::pricesViewCollection> priceVector = ormasDal.GetPrices(errorMessage, filter);
		if (0 != priceVector.size())
		{
			id = std::get<0>(priceVector.at(0));
			date = std::get<1>(priceVector.at(0));
			value = std::get<5>(priceVector.at(0));
			currencyID = std::get<7>(priceVector.at(0));
			productID = std::get<8>(priceVector.at(0));
			isOutdated = std::get<9>(priceVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find price with this product id";
		}
		return false;
	}

	bool Price::IsEmpty()
	{
		if (0 == id && date.empty() && 0.0 == value && 0 == currencyID && 0 == productID && isOutdated == true)
			return true;
		return false;
	}

	void Price::Clear()
	{
		id = 0;
		date.clear();
		value = 0;
		currencyID = 0;
		productID = 0;
		isOutdated = true;
	}

	bool Price::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string pDate, double pValue, int cID, int prID,
		std::string& errorMessage)
	{
		Price price;
		price.Clear();
		errorMessage.clear();
		price.SetDate(pDate);
		price.SetValue(pValue);
		price.SetCurrencyID(cID);
		price.SetProductID(prID);
		std::string filter = price.GenerateFilter(ormasDal);
		std::vector<DataLayer::pricesViewCollection> priceVector = ormasDal.GetPrices(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == priceVector.size())
		{
			return false;
		}
		errorMessage = "Price with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Price::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Price price;
		price.Clear();
		errorMessage.clear();
		price.SetDate(date);
		price.SetValue(value);
		price.SetCurrencyID(currencyID);
		price.SetProductID(productID);
		std::string filter = price.GenerateFilter(ormasDal);
		std::vector<DataLayer::pricesViewCollection> priceVector = ormasDal.GetPrices(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == priceVector.size())
		{
			return false;
		}
		errorMessage = "Price with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}