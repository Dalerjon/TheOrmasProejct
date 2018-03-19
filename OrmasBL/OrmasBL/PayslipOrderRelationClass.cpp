#include "stdafx.h"
#include "PayslipOrderRelationClass.h"


namespace BusinessLayer{
	PayslipOrderRelation::PayslipOrderRelation(DataLayer::payslipOrderCollection poCollection)
	{
		payslipID = std::get<0>(poCollection);
		orderID = std::get<1>(poCollection);
	}
	PayslipOrderRelation::PayslipOrderRelation()
	{
		payslipID = 0;
		orderID = 0;
	}

	int PayslipOrderRelation::GetOrderID()
	{
		return orderID;
	}

	int PayslipOrderRelation::GetPayslipID()
	{
		return payslipID;
	}

	void PayslipOrderRelation::SetOrderID(int oID)
	{
		orderID = oID;
	}
	void PayslipOrderRelation::SetPayslipID(int pID)
	{
		payslipID = pID;
	}

	bool PayslipOrderRelation::CreatePayslipOrderRelation(DataLayer::OrmasDal &ormasDal, int pID, int oID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, pID, oID, errorMessage))
			return false;
		orderID = oID;
		payslipID = pID;

		if (ormasDal.CreatePayslipOrder(payslipID, orderID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool PayslipOrderRelation::CreatePayslipOrderRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		if (ormasDal.CreatePayslipOrder(payslipID, orderID, errorMessage))
		{
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool PayslipOrderRelation::DeletePayslipOrderRelation(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (ormasDal.DeletePayslipOrder(payslipID, orderID, errorMessage))
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



	std::string PayslipOrderRelation::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != orderID || 0 != payslipID)
		{
			return ormasDal.GetFilterForPayslipOrder(payslipID, orderID);
		}
		return "";
	}

	std::vector<int> PayslipOrderRelation::GetAllPayslipByOrderID(DataLayer::OrmasDal& ormasDal, int bID, std::string& errorMessage)
	{
		std::vector<int> payslipIDVector;
		PayslipOrderRelation bpRelation;
		bpRelation.SetOrderID(bID);
		bpRelation.SetPayslipID(0);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::payslipOrderCollection> payslipOrderVector = ormasDal.GetPayslipOrder(errorMessage, filter);
		if (0 != payslipOrderVector.size())
		{
			for each (auto item in payslipOrderVector)
			{
				payslipIDVector.push_back(std::get<1>(item));
			}
		}
		return payslipIDVector;
	}

	std::vector<int> PayslipOrderRelation::GetAllOrderByPayslipID(DataLayer::OrmasDal& ormasDal, int pID, std::string& errorMessage)
	{
		std::vector<int> OrderIDVector;
		PayslipOrderRelation bpRelation;
		bpRelation.SetOrderID(0);
		bpRelation.SetPayslipID(pID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::payslipOrderCollection> payslipOrderVector = ormasDal.GetPayslipOrder(errorMessage, filter);
		if (0 != payslipOrderVector.size())
		{
			for each (auto item in payslipOrderVector)
			{
				OrderIDVector.push_back(std::get<0>(item));
			}
		}
		return OrderIDVector;
	}


	bool PayslipOrderRelation::IsEmpty()
	{
		if (0 == orderID && 0 == payslipID)
			return true;
		return false;
	}

	void PayslipOrderRelation::Clear()
	{
		orderID = 0;
		payslipID = 0;
	}


	bool PayslipOrderRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, int bID, int pID, std::string& errorMessage)
	{
		PayslipOrderRelation bpRelation;
		bpRelation.SetOrderID(bID);
		bpRelation.SetPayslipID(pID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::payslipOrderCollection> payslipOrderVector = ormasDal.GetPayslipOrder(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == payslipOrderVector.size())
		{
			return false;
		}
		errorMessage = "Payslip-Order Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool PayslipOrderRelation::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		PayslipOrderRelation bpRelation;
		bpRelation.SetOrderID(orderID);
		bpRelation.SetPayslipID(payslipID);
		std::string filter = bpRelation.GenerateFilter(ormasDal);
		std::vector<DataLayer::payslipOrderCollection> payslipOrderVector = ormasDal.GetPayslipOrder(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == payslipOrderVector.size())
		{
			return false;
		}
		errorMessage = "Payslip-Order Relation with this parameters are already exist! Please avoid the duplication!";
		return true;
	}
}