#include "stdafx.h"
#include "OrderViewClass.h"

namespace BusinessLayer
{
	OrderView::OrderView(DataLayer::ordersViewCollection oCollection)
	{
		id = std::get<0>(oCollection);
		date = std::get<1>(oCollection);
		statusCode = std::get<2>(oCollection);
		statusName = std::get<3>(oCollection);
		clientName = std::get<4>(oCollection);
		clientPhone = std::get<5>(oCollection);
		clientAddres = std::get<6>(oCollection);
		firm = std::get<7>(oCollection);
		workerName = std::get<8>(oCollection);
		workerPhone = std::get<8>(oCollection);
		count = std::get<10>(oCollection);
		sum = std::get<11>(oCollection);
		currencyName = std::get<12>(oCollection);
		workerID = std::get<13>(oCollection);
		userID = std::get<14>(oCollection);
		statusID = std::get<15>(oCollection);
		currencyID = std::get<16>(oCollection);
	}

	std::string OrderView::GetStatusCode()
	{
		return statusCode;
	}
	std::string OrderView::GetStatusName()
	{
		return statusName;
	}
	std::string OrderView::GetClientName()
	{
		return clientName;
	}
	std::string OrderView::GetClientPhone()
	{
		return clientPhone;
	}
	std::string OrderView::GetClientAddress()
	{
		return clientAddres;
	}
	std::string OrderView::GetFirm()
	{
		return firm;
	}
	std::string OrderView::GetWorkerName()
	{
		return workerName;
	}
	std::string OrderView::GetWorkerPhone()
	{
		return workerPhone;
	}
	std::string OrderView::GetCurrencyName()
	{
		return currencyName;
	}

	void OrderView::SetStatusCode(std::string oStatusCode)
	{
		statusCode = oStatusCode;
	}
	void OrderView::SetStatusName(std::string oStatusName)
	{
		statusName = oStatusName;
	}
	void OrderView::SetClientName(std::string oClientName)
	{
		clientName = oClientName;
	}
	void OrderView::SetClientPhone(std::string oClientPhone)
	{
		clientPhone = oClientPhone;
	}
	void OrderView::SetClientAddress(std::string oClientAddress)
	{
		clientAddres = oClientAddress;
	}
	void OrderView::SetFirm(std::string oFirm)
	{
		firm = oFirm;
	}
	void OrderView::SetWorkerName(std::string oWorkerName)
	{
		workerName = oWorkerName;
	}
	void OrderView::SetWorkerPhone(std::string oWorkerPhone)
	{
		workerPhone = oWorkerPhone;
	}
	void OrderView::SetCurrencyName(std::string oCurrencyName)
	{
		currencyName = oCurrencyName;
	}
}

