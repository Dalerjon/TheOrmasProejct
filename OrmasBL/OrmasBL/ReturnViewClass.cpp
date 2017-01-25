#include "stdafx.h"
#include "ReturnViewClass.h"

namespace BusinessLayer
{
	ReturnView::ReturnView(DataLayer::returnsViewCollection rCollection)
	{
		id = std::get<0>(rCollection);
		date = std::get<1>(rCollection);
		statusCode = std::get<2>(rCollection);
		statusName = std::get<3>(rCollection);
		clientName = std::get<4>(rCollection);
		clientPhone = std::get<5>(rCollection);
		clientAddres = std::get<6>(rCollection);
		firm = std::get<7>(rCollection);
		workerName = std::get<8>(rCollection);
		workerPhone = std::get<9>(rCollection);
		count = std::get<10>(rCollection);
		sum = std::get<11>(rCollection);
		currencyName = std::get<12>(rCollection);
		workerID = std::get<13>(rCollection);
		userID = std::get<14>(rCollection);
		statusID = std::get<15>(rCollection);
		currencyID = std::get<16>(rCollection);
	}
	
	std::string ReturnView::GetStatusCode()
	{
		return statusCode;
	}
	std::string ReturnView::GetStatusName()
	{
		return statusName;
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
	std::string ReturnView::GetCurrencyName()
	{
		return currencyName;
	}

	void ReturnView::SetStatusCode(std::string rStatusCode)
	{
		statusCode = rStatusCode;
	}
	void ReturnView::SetStatusName(std::string rStatusName)
	{
		statusName = rStatusName;
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
	void ReturnView::SetCurrencyName(std::string rCurrencyName)
	{
		currencyName = rCurrencyName;
	}
}

