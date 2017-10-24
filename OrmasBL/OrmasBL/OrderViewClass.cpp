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
		clientSurname = std::get<5>(oCollection);
		clientPhone = std::get<6>(oCollection);
		clientAddres = std::get<7>(oCollection);
		clientFirm = std::get<8>(oCollection);
		employeeName = std::get<9>(oCollection);
		employeeSurname = std::get<10>(oCollection);
		employeePhone = std::get<11>(oCollection);
		count = std::get<12>(oCollection);
		sum = std::get<13>(oCollection);
		currencyName = std::get<14>(oCollection);
		employeeID = std::get<15>(oCollection);
		clientID = std::get<16>(oCollection);
		statusID = std::get<17>(oCollection);
		currencyID = std::get<18>(oCollection);
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
	std::string OrderView::GetClientSurname()
	{
		return clientSurname;
	}
	std::string OrderView::GetClientPhone()
	{
		return clientPhone;
	}
	std::string OrderView::GetClientAddress()
	{
		return clientAddres;
	}
	std::string OrderView::GetClientFirm()
	{
		return clientFirm;
	}
	std::string OrderView::GetEmployeeName()
	{
		return employeeName;
	}
	std::string OrderView::GetEmployeeSurname()
	{
		return employeeSurname;
	}
	std::string OrderView::GetEmployeePhone()
	{
		return employeePhone;
	}
	std::string OrderView::GetCurrencyName()
	{
		return currencyName;
	}

}

