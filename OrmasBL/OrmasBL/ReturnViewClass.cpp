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
		clientSurname = std::get<5>(rCollection);
		clientPhone = std::get<6>(rCollection);
		clientAddres = std::get<7>(rCollection);
		clientFirm = std::get<8>(rCollection);
		employeeName = std::get<9>(rCollection);
		employeeSurname = std::get<10>(rCollection);
		employeePhone = std::get<11>(rCollection);
		count = std::get<12>(rCollection);
		sum = std::get<13>(rCollection);
		currencyName = std::get<14>(rCollection);
		employeeID = std::get<15>(rCollection);
		clientID = std::get<16>(rCollection);
		statusID = std::get<17>(rCollection);
		currencyID = std::get<18>(rCollection);
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
	std::string ReturnView::GetClientSurname()
	{
		return clientSurname;
	}
	std::string ReturnView::GetClientPhone()
	{
		return clientPhone;
	}
	std::string ReturnView::GetClientAddress()
	{
		return clientAddres;
	}
	std::string ReturnView::GetClientFirm()
	{
		return clientFirm;
	}
	std::string ReturnView::GetEmployeeName()
	{
		return employeeName;
	}
	std::string ReturnView::GetEmployeeSurname()
	{
		return employeeSurname;
	}
	std::string ReturnView::GetEmployeePhone()
	{
		return employeePhone;
	}
	std::string ReturnView::GetCurrencyName()
	{
		return currencyName;
	}
}

