#include "stdafx.h"
#include "OrderClass.h"
#include "BalanceClass.h"
#include "UserClass.h"
#include "EntryClass.h"
#include "StatusClass.h"
#include "CompanyAccountRelationClass.h"
#include "CompanyEmployeeRelationClass.h"
#include "TransportClass.h"
#include <codecvt>

namespace BusinessLayer
{
	Order::Order(DataLayer::ordersCollection oCollection)
	{
		id = std::get<0>(oCollection);
		clientID = std::get<1>(oCollection);
		date = std::get<2>(oCollection);
		executionDate = std::get<3>(oCollection);
		employeeID = std::get<4>(oCollection);
		count = std::get<5>(oCollection);
		sum = std::get<6>(oCollection);
		statusID = std::get<7>(oCollection);
		currencyID = std::get<8>(oCollection);
	}

	int Order::GetID()
	{
		return id;
	}

	int Order::GetClientID()
	{
		return clientID;
	}

	std::string Order::GetDate()
	{
		return date;
	}

	std::string Order::GetExecutionDate()
	{
		return executionDate;
	}

	int Order::GetEmployeeID()
	{
		return employeeID;
	}

	double Order::GetCount()
	{
		return count;
	}

	double Order::GetSum()
	{
		return sum;
	}

	int Order::GetStatusID()
	{
		return statusID;
	}

	int Order::GetCurrencyID()
	{
		return currencyID;
	}

	void Order::SetID(int oID)
	{
		id = oID;
	}
	void Order::SetClientID(int oClientID)
	{
		clientID = oClientID;
	}
	void Order::SetDate(std::string oDate)
	{
		date = oDate;
	}
	void Order::SetExecutionDate(std::string oExecutionDate)
	{
		executionDate = oExecutionDate;
	}
	void Order::SetEmployeeID(int oEmployeeID)
	{
		employeeID = oEmployeeID;
	}
	
	void Order::SetCount(double oCount)
	{
		count = oCount;
	}

	void Order::SetSum(double oSum)
	{
		sum = oSum;
	}

	void Order::SetStatusID(int oStatusID)
	{
		statusID = oStatusID;
	}

	void Order::SetCurrencyID(int oCurrencyID)
	{
		currencyID = oCurrencyID;
	}

	bool Order::CreateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, std::string oExecDate, int eID, double oCount,
		double oSum, int sID, int cID, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, uID, oDate, oCount, oSum, cID, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		clientID = uID;
		date = oDate;
		executionDate = oExecDate;
		employeeID = eID;
		count = oCount;
		sum = oSum;
		statusID = sID;
		currencyID = cID;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateOrder(id, clientID, date, executionDate, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second)
			{
				if (CreateOrderEntry(ormasDal, clientID, employeeID, sum, currencyID, executionDate, errorMessage))
				{
					if (ChangesAtTransport(ormasDal, id, errorMessage))
					{
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
			//ormasDal.CommitTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	bool Order::CreateOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (IsDuplicate(ormasDal, errorMessage))
			return false;
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.CreateOrder(id, clientID, date, executionDate, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second)
			{
				if (CreateOrderEntry(ormasDal, clientID, employeeID, sum, currencyID, executionDate, errorMessage))
				{
					if (ChangesAtTransport(ormasDal, id, errorMessage))
					{
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
			//ormasDal.CommitTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Order::DeleteOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		if (!ormasDal.StartTransaction(errorMessage))
			return false;
		Order ord;
		if (!ord.GetOrderByID(ormasDal, id, errorMessage))
		{
			return false;
		}
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		if (ord.GetStatusID() == statusMap.find("EXECUTED")->second)
		{
			errorMessage = "Cannot delete document with \"EXECUTED\" status!";
			return false;
		}
		if (ormasDal.DeleteOrder(id, errorMessage))
		{			
			if (ormasDal.DeleteListByOrderID(id, errorMessage))
			{
				Clear();
				//ormasDal.CommitTransaction(errorMessage);
				return true;
			}
			else
			{
				//ormasDal.CancelTransaction(errorMessage);
			}
		}
		else
		{
			//ormasDal.CancelTransaction(errorMessage);
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		return false;
	}
	bool Order::UpdateOrder(DataLayer::OrmasDal& ormasDal, int uID, std::string oDate, std::string oExecnDate, int eID, double oCount,
		double oSum, int sID, int cID, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		clientID = uID;
		date = oDate;
		executionDate = oExecnDate;
		employeeID = eID;
		count = oCount;
		sum = oSum;
		statusID = sID;
		currencyID = cID;
		previousSum = GetCurrentSum(ormasDal, id, errorMessage);
		prevCount = GetCurrentCount(ormasDal, id, errorMessage);
		previousStatusID = GetCurrentStatusID(ormasDal, id, errorMessage);
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateOrder(id, clientID, date, executionDate, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (CreateOrderEntry(ormasDal, clientID, employeeID, sum, currencyID, executionDate, errorMessage))
				{
					if (ChangesAtTransport(ormasDal, id, errorMessage))
					{
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID == statusMap.find("EXECUTED")->second && previousSum != sum)
			{
				if (count != prevCount || sum != previousSum)
				{
					if (count != prevCount || sum != previousSum)
					{
						if (CreateOrderEntry(ormasDal, clientID, employeeID, sum, previousSum, currencyID, executionDate, errorMessage))
						{
							//ormasDal.CommitTransaction(errorMessage);
							return true;
						}
						else
						{
							//ormasDal.CancelTransaction(errorMessage);
							return false;
						}
					}
				}
			}
			//ormasDal.CommitTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}
	bool Order::UpdateOrder(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		std::map<std::string, int> statusMap = BusinessLayer::Status::GetStatusesAsMap(ormasDal, errorMessage);
		if (0 == statusMap.size())
			return false;
		previousSum = GetCurrentSum(ormasDal, id, errorMessage);
		previousStatusID = GetCurrentStatusID(ormasDal, id, errorMessage);
		prevCount = GetCurrentCount(ormasDal, id, errorMessage);
		//ormasDal.StartTransaction(errorMessage);
		if (0 != id && ormasDal.UpdateOrder(id, clientID, date, executionDate, employeeID, count, sum, statusID, currencyID, errorMessage))
		{
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID != statusMap.find("EXECUTED")->second)
			{
				if (CreateOrderEntry(ormasDal, clientID, employeeID, sum, currencyID, executionDate, errorMessage))
				{
					if (ChangesAtTransport(ormasDal, id, errorMessage))
					{
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
				else
				{
					//ormasDal.CancelTransaction(errorMessage);
					return false;
				}
			}
			if (statusID == statusMap.find("EXECUTED")->second && previousStatusID == statusMap.find("EXECUTED")->second && previousSum != sum)
			{
				if (count != prevCount || sum != previousSum)
				{
					if (CreateOrderEntry(ormasDal, clientID, employeeID, sum, previousSum, currencyID, executionDate, errorMessage))
					{
						//ormasDal.CommitTransaction(errorMessage);
						return true;
					}
					else
					{
						//ormasDal.CancelTransaction(errorMessage);
						return false;
					}
				}
			}
			//ormasDal.CommitTransaction(errorMessage);
			return true;
		}
		if (errorMessage.empty())
		{
			errorMessage = "Warning! ID is 0, or some unexpected error. Please contact with provider.";
		}
		//ormasDal.CancelTransaction(errorMessage);
		return false;
	}

	std::string Order::GenerateFilter(DataLayer::OrmasDal& ormasDal)
	{
		if (0 != id || 0 != clientID || !date.empty() || !executionDate.empty() || 0 != employeeID || 0 != count || 0 != sum || 0 != statusID)
		{
			return ormasDal.GetFilterForOrder(id, clientID, date, executionDate, employeeID, count, sum, statusID, currencyID);
		}
		return "";
	}

	std::string Order::GenerateFilterForPeriod(DataLayer::OrmasDal& ormasDal, std::string fromDate, std::string toDate)
	{
		if (!toDate.empty() && !fromDate.empty())
		{
			return ormasDal.GetFilterForOrderForPeriod(id, clientID, date, executionDate, employeeID, count, sum, statusID, currencyID, fromDate, toDate);
		}
		return "";
	}

	bool Order::GetOrderByID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		id = oID;
		std::string filter = GenerateFilter(ormasDal);
		std::vector<DataLayer::ordersViewCollection> orderVector = ormasDal.GetOrders(errorMessage, filter);
		if (0 != orderVector.size())
		{
			id = std::get<0>(orderVector.at(0));
			date = std::get<1>(orderVector.at(0));
			executionDate = std::get<2>(orderVector.at(0));
			count = std::get<13>(orderVector.at(0));
			sum = std::get<14>(orderVector.at(0));
			employeeID = std::get<16>(orderVector.at(0));
			clientID = std::get<17>(orderVector.at(0));
			statusID = std::get<18>(orderVector.at(0));
			currencyID = std::get<19>(orderVector.at(0));
			return true;
		}
		else
		{
			errorMessage = "Cannot find order with this id";
		}
		return false;
	}
	
	bool Order::IsEmpty()
	{
		if (0 == id && date == "" && executionDate == "" && 0 == count && 0 == sum && 0 == employeeID && 0 == clientID && 0 == statusID 
			&& 0 == currencyID)
			return false;
		return true;
	}

	void Order::Clear()
	{
		id = 0;
		date.clear();
		executionDate.clear();
		count = 0;
		sum = 0;
		employeeID = 0;
		clientID = 0;
		statusID = 0;
		currencyID = 0;
	}
	
	bool Order::IsDuplicate(DataLayer::OrmasDal& ormasDal, int clID, std::string oDate, double oCount, double oSum,
		int cID, std::string& errorMessage)
	{
		Order order;
		order.Clear();
		errorMessage.clear();
		order.SetClientID(clID);
		order.SetDate(oDate);
		order.SetCount(oCount);
		order.SetSum(oSum);
		order.SetCurrencyID(cID);
		std::string filter = order.GenerateFilter(ormasDal);
		std::vector<DataLayer::ordersViewCollection> orderVector = ormasDal.GetOrders(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == orderVector.size())
		{
			return false;
		}
		errorMessage = "Order with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Order::IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage)
	{
		Order order;
		order.Clear();
		errorMessage.clear();
		order.SetClientID(clientID);
		order.SetDate(date);
		order.SetCount(count);
		order.SetSum(sum);
		order.SetCurrencyID(currencyID);
		std::string filter = order.GenerateFilter(ormasDal);
		std::vector<DataLayer::ordersViewCollection> orderVector = ormasDal.GetOrders(errorMessage, filter);
		if (!errorMessage.empty())
			return true;
		if (0 == orderVector.size())
		{
			return false;
		}
		errorMessage = "Order with these parameters are already exist! Please avoid the duplication!";
		return true;
	}

	bool Order::CreateOrderEntry(DataLayer::OrmasDal& ormasDal, int clID, int eID, double oSum, int cID, std::string oExecDate, std::string& errorMessage)
	{
		Balance balance;
		CompanyAccountRelation cAccRel;
		CompanyEmployeeRelation cEmpRel;

		if(balance.GetBalanceByUserID(ormasDal, clID, errorMessage))
		{
			int debAccID = 0;
			int credAccID = 0;
			int companyID = cEmpRel.GetCompanyByEmployeeID(ormasDal, eID, errorMessage);
			debAccID = balance.GetSubaccountID();
			credAccID = cAccRel.GetAccountIDByCompanyID(ormasDal, companyID, "44010", errorMessage);
			if (this->CreateEntry(ormasDal, debAccID, oSum, credAccID, oExecDate, errorMessage))
			{
				return true;
			}
		}
		return false;
	}

	bool Order::CreateOrderEntry(DataLayer::OrmasDal& ormasDal, int clID, int eID, double oSum, double prevSum, int cID, std::string oExecDate, std::string& errorMessage)
	{
		Balance balance;
		CompanyAccountRelation cAccRel;
		CompanyEmployeeRelation cEmpRel;

		if (balance.GetBalanceByUserID(ormasDal, clID, errorMessage))
		{
			int debAccID = 0;
			int credAccID = 0;
			int companyID = cEmpRel.GetCompanyByEmployeeID(ormasDal, eID, errorMessage);
			debAccID = balance.GetSubaccountID();
			credAccID = cAccRel.GetAccountIDByCompanyID(ormasDal, companyID, "44010", errorMessage);
			if (this->CreateEntry(ormasDal, debAccID, oSum, credAccID, prevSum, oExecDate, errorMessage))
			{
				return true;
			}
		}
		return false;
	}

	double Order::GetCurrentSum(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		Order order;
		if (order.GetOrderByID(ormasDal, oID, errorMessage))
			return order.GetSum();
		return 0;
	}

	double Order::GetCurrentCount(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		Order order;
		if (order.GetOrderByID(ormasDal, oID, errorMessage))
			return order.GetCount();
		return 0;
	}

	int Order::GetCurrentStatusID(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		Order order;
		if (order.GetOrderByID(ormasDal, oID, errorMessage))
			return order.GetStatusID();
		return 0;
	}

	bool Order::CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		entry.SetDescription(wstring_to_utf8(L"����� ������ � �������� ������� � ID =") + std::to_string(clientID));
		if (!entry.CreateEntry(ormasDal, errorMessage))
		{
			return false;
		}
		return true;
	}
	bool Order::CreateEntry(DataLayer::OrmasDal& ormasDal, int debAccID, double currentSum, int credAccID, double previousSum, std::string oExecDate, std::string& errorMessage)
	{
		Entry entry;
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(credAccID);
		entry.SetValue(previousSum);
		entry.SetCreditingAccountID(debAccID);
		entry.SetDescription(wstring_to_utf8(L"����� ������ � �������� ������� � ID =") + std::to_string(clientID));
		if (!entry.CreateEntry(ormasDal, errorMessage, true))
		{
			return false;
		}
		entry.Clear();
		entry.SetDate(oExecDate);
		entry.SetDebitingAccountID(debAccID);
		entry.SetValue(currentSum);
		entry.SetCreditingAccountID(credAccID);
		entry.SetDescription(wstring_to_utf8(L"����� ������ � �������� ������� � ID =") + std::to_string(clientID));
		if (!entry.CreateEntry(ormasDal, errorMessage))
		{
			return false;
		}
		return true;
	}

	bool Order::ChangesAtTransport(DataLayer::OrmasDal& ormasDal, int oID, std::string& errorMessage)
	{
		Transport transport;
		return transport.ChangingByConsumeProduct(ormasDal, oID, errorMessage);
	}

	bool Order::ChangesAtTransport(DataLayer::OrmasDal& ormasDal, int oID, std::map<int, double> pProdCountMap, double previousSum, std::string& errorMessage)
	{
		Transport transport;
		return transport.ChangingByConsumeProduct(ormasDal, oID, pProdCountMap, previousSum, errorMessage);
	}

	std::string Order::wstring_to_utf8(const std::wstring& str)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
		return myconv.to_bytes(str);
	}
}