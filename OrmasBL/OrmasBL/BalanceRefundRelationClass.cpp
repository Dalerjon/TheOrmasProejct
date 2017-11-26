#include "stdafx.h"
#include "BalanceRefundRelationClass.h"


namespace BusinessLayer{
	BalanceRefundRelation::BalanceRefundRelation(DataLayer::balanceRefundCollection brCollection)
	{
		balanceID = std::get<0>(brCollection);
		refundID = std::get<1>(brCollection);
	}
	BalanceRefundRelation::BalanceRefundRelation()
	{
		balanceID = 0;
		refundID = 0;
	}

	int BalanceRefundRelation::GetBalanceID()
	{
		return balanceID;
	}

	int BalanceRefundRelation::GetRefundID()
	{
		return refundID;
	}

	void BalanceRefundRelation::SetBalanceID(int bID)
	{
		balanceID = bID;
	}
	void BalanceRefundRelation::SetRefundID(int rID)
	{
		refundID = rID;
	}

	bool BalanceRefundRelation::CreateBalanceRefundRelation(DataLayer::OrmasDal &ormasDal, int bID, int rID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, bID, rID, errorMessage))
			return false;
		balanceID = bID;
		refundID = rID;

		if (ormasDal.CreateBalanceRefund(balanceID, refundID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool BalanceRefundRelation::CreateBalanceRefundRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		if (ormasDal.CreateBalanceRefund(balanceID, refundID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool BalanceRefundRelation::DeleteBalanceRefundRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeleteBalanceRefund(balanceID, refundID, errorMessage))
		{
			balanceID = 0;
			refundID = 0;
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Unexpected error. Please contact with application provider.";
		}
		return false;
	}



	std::string BalanceRefundRelation::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != balanceID || 0 != refundID)
		{
			return ormasDal.GetFilterForBalanceRefund(balanceID, refundID);
		}
		return "";
	}

	std::vector<int> BalanceRefundRelation::GetAllRefundByBalanceID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage)
	{
		std::vector<int> refundIDVector;
		BalanceRefundRelation bpRelation;
		bpRelation.SetBalanceID(bID);
		bpRelation.SetRefundID(0);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balanceRefundCollection> balanceRefundVector = ormasDal.GetBalanceRefund(errorMessage, filter);
		if (0 != balanceRefundVector.size())
		{
			for each (auto item in balanceRefundVector)
			{
				refundIDVector.push_back(std::get<1>(item));
			}
		}
		return refundIDVector;
	}

	std::vector<int> BalanceRefundRelation::GetAllBalanceByRefundID(DataLayer::OrmasDal& ormasDal, int rID, std::string& errorMessage)
	{
		std::vector<int> balanceIDVector;
		BalanceRefundRelation bpRelation;
		bpRelation.SetBalanceID(0);
		bpRelation.SetRefundID(rID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balanceRefundCollection> balanceRefundVector = ormasDal.GetBalanceRefund(errorMessage, filter);
		if (0 != balanceRefundVector.size())
		{
			for each (auto item in balanceRefundVector)
			{
				balanceIDVector.push_back(std::get<0>(item));
			}
		}
		return balanceIDVector;
	}


	bool BalanceRefundRelation::IsEmpty()
	{
		if (0 == balanceID && 0 == refundID)
			return true;
		return false;
	}

	void BalanceRefundRelation::Clear()
	{
		balanceID = 0;
		refundID = 0;
	}

	bool BalanceRefundRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, int bID, int rID, std::string& errorMessage)
	{
		BalanceRefundRelation bpRelation;
		bpRelation.SetBalanceID(bID);
		bpRelation.SetRefundID(rID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balanceRefundCollection> balanceRefundVector = ormasDal.GetBalanceRefund(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == balanceRefundVector.size())
		{
			return false;
		}
		errorMessage = "Balance-Refund Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool BalanceRefundRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		BalanceRefundRelation bpRelation;
		bpRelation.SetBalanceID(balanceID);
		bpRelation.SetRefundID(refundID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::balanceRefundCollection> balanceRefundVector = ormasDal.GetBalanceRefund(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == balanceRefundVector.size())
		{
			return false;
		}
		errorMessage = "Balance-Refund Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}