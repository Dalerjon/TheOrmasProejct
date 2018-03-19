#include "stdafx.h"
#include "ReceiptRawListClass.h"

namespace BusinessLayer
{
	ReceiptRawList::ReceiptRawList(DataLayer::receiptRawListCollection rListCollection)
	{
		id = std::get<0>(rListCollection);
		receiptRawID = std::get<1>(rListCollection);
		productID = std::get<2>(rListCollection);
		count = std::get<3>(rListCollection);
		sum = std::get<4>(rListCollection);
		statusID = std::get<5>(rListCollection);
		currencyID = std::get<6>(rListCollection);
	}

	int ReceiptRawList::GetID()
	{
		return id;
	}

	int ReceiptRawList::GetReceiptRawID()
	{
		return receiptRawID;
	}

	int ReceiptRawList::GetProductID()
	{
		return productID;
	}

	int ReceiptRawList::GetCount()
	{
		return count;
	}

	double ReceiptRawList::GetSum()
	{
		return sum;
	}

	int ReceiptRawList::GetStatusID()
	{
		return statusID;
	}

	int ReceiptRawList::GetCurrencyID()
	{
		return currencyID;
	}

	void ReceiptRawList::SetID(int rID)
	{
		id = rID;
	}
	void ReceiptRawList::SetReceiptRawID(int rReceiptRawID)
	{
		receiptRawID = rReceiptRawID;
	}
	void ReceiptRawList::SetProductID(int rProductID)
	{
		productID = rProductID;
	}
	void ReceiptRawList::SetCount(int rCount)
	{
		count = rCount;
	}
	void ReceiptRawList::SetSum(double rSum)
	{
		sum = rSum;
	}
	void ReceiptRawList::SetStatusID(int rStatusID)
	{
		statusID = rStatusID;
	}
	void ReceiptRawList::SetCurrencyID(int rCurrencyID)
	{
		currencyID = rCurrencyID;
	}

	bool ReceiptRawList::CreateReceiptRawList(DataLayer::OrmasDal& ormasDal, int rID, int pID, int rlCount, double rlSum,
		int sID, int cID, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		receiptRawID = rID;
		productID = pID;
		count = rlCount;
		sum = rlSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.CreateReceiptRawList(id, receiptRawID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool ReceiptRawList::CreateReceiptRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		id = ormasDal.GenerateID();
		if (0 != id && ormasDal.CreateReceiptRawList(id, receiptRawID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool ReceiptRawList::DeleteReceiptRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteItemInReceiptRawList(id, errorMessage))
		{
			Clear();
			return true;
		}
		return false;
	}
	bool ReceiptRawList::DeleteListByReceiptRawID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		receiptRawID = oID;
		if (ormasDal.DeleteListByReceiptRawID(receiptRawID, errorMessage))
		{
			Clear();
			return true;
		}
		return false;
	}

	bool ReceiptRawList::UpdateReceiptRawList(DataLayer::OrmasDal& ormasDal, int rID, int pID, int rlCount, double rlSum,
		int sID, int cID, std::string& errorMessage)
	{
		receiptRawID = rID;
		productID = pID;
		count = rlCount;
		sum = rlSum;
		statusID = sID;
		currencyID = cID;
		if (0 != id && ormasDal.UpdateReceiptRawList(id, receiptRawID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}
	bool ReceiptRawList::UpdateReceiptRawList(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (0 != id && ormasDal.UpdateReceiptRawList(id, receiptRawID, productID, count, sum, statusID, currencyID, errorMessage))
		{
			return true;
		}
		return false;
	}

	std::string ReceiptRawList::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != receiptRawID || 0 != productID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForReceiptRawList(id, receiptRawID, productID, count, sum, statusID, currencyID);
		}
		return "";
	}

	bool ReceiptRawList::GetReceiptRawListByID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		id = pID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptRawListViewCollection> receiptRawListVector = ormasDal.GetReceiptRawList(errorMessage, filter);
		if (0 != receiptRawListVector.size())
		{

			id = std::get<0>(receiptRawListVector.at(0));
			receiptRawID = std::get<1>(receiptRawListVector.at(0));
			count = std::get<7>(receiptRawListVector.at(0));
			sum = std::get<8>(receiptRawListVector.at(0));
			productID = std::get<11>(receiptRawListVector.at(0));
			statusID = std::get<12>(receiptRawListVector.at(0));
			currencyID = std::get<13>(receiptRawListVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find receipt raw list with this id";
		}
		return false;
	}

	bool ReceiptRawList::IsEmpty()
	{
		if (0 == id && 0 == receiptRawID && 0 == count && 0 == sum && 0 == productID && 0 == statusID && 0 == currencyID)
			return true;
		return false;
	}

	void ReceiptRawList::Clear()
	{
		id = 0;
		receiptRawID = 0;
		count = 0;
		sum = 0;
		productID = 0;
		statusID = 0;
		currencyID = 0;
	}

	bool ReceiptRawList::IsDuplicate(DataLayer::OrmasDal& ormasDal, int rID, int pID, int rlCount, double rlSum,
		int cID, std::string& errorMessage)
	{
		ReceiptRawList receiptRawList;
		receiptRawList.SetReceiptRawID(rID);
		receiptRawList.SetProductID(pID);
		receiptRawList.SetCount(rlCount);
		receiptRawList.SetSum(rlSum);
		receiptRawList.SetCurrencyID(cID);
		std::string filter = receiptRawList.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptRawListViewCollection> receiptRawListVector = ormasDal.GetReceiptRawList(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == receiptRawListVector.size())
		{
			return false;
		}
		errorMessage = "Receipt product list with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool ReceiptRawList::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		ReceiptRawList receiptRawList;
		receiptRawList.SetReceiptRawID(receiptRawID);
		receiptRawList.SetProductID(productID);
		receiptRawList.SetCount(count);
		receiptRawList.SetSum(sum);
		receiptRawList.SetCurrencyID(currencyID);
		std::string filter = receiptRawList.GenerateFilter(ormasDal);
		std::vector<DataLayer::receiptRawListViewCollection> receiptRawListVector = ormasDal.GetReceiptRawList(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == receiptRawListVector.size())
		{
			return false;
		}
		errorMessage = "Receipt product list with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}