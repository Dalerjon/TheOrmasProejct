#include "stdafx.h"
#include "ReturnViewClass.h";

namespace BusinessLayer
{
	ReturnView::ReturnView(DataLayer::returnsViewCollection oCollection)
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

	std::string ReturnView::GetClientName()
	{
		return clientName;
	}
	std::string ReturnView::GetClientPhone()
	{
		return clientPhone;
	}
	std::string ReturnView::GetClientAddress()
	{
		return clientAddres;
	}
	std::string ReturnView::GetFirm()
	{
		return firm;
	}
	std::string ReturnView::GetWorkerName()
	{
		return workerName;
	}
	std::string ReturnView::GetWorkerPhone()
	{
		return workerPhone;
	}

	void ReturnView::SetClientName(std::string rClientName)
	{
		clientName = rClientName;
	}
	void ReturnView::SetClientPhone(std::string rClientPhone)
	{
		clientPhone = rClientPhone;
	}
	void ReturnView::SetClientAddress(std::string rClientAddress)
	{
		clientAddres = rClientAddress;
	}
	void ReturnView::SetFirm(std::string rFirm)
	{
		firm = rFirm;
	}
	void ReturnView::SetWorkerName(std::string rWorkerName)
	{
		workerName = rWorkerName;
	}
	void ReturnView::SetWorkerPhone(std::string rWorkerPhone)
	{
		workerPhone = rWorkerPhone;
	}
}

