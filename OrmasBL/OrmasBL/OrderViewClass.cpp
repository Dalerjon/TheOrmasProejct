#include "stdafx.h"
#include "OrderViewClass.h"

namespace BusinessLayer
{
	OrderView::OrderView(DataLayer::ordersViewCollection oCollection)
	{
		id = std::get<0>(oCollection);
		date = std::get<1>(oCollection);
		clientName = std::get<2>(oCollection);
		clientPhone = std::get<3>(oCollection);
		clientAddres = std::get<4>(oCollection);
		firm = std::get<5>(oCollection);
		workerName = std::get<6>(oCollection);
		workerPhone = std::get<7>(oCollection);
		workerID = std::get<8>(oCollection);
		userID = std::get<9>(oCollection);
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
}

