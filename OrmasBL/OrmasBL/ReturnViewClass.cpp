#include "stdafx.h"
#include "ReturnViewClass.h"

namespace BusinessLayer
{
	ReturnView::ReturnView(DataLayer::returnsViewCollection rCollection)
	{
		id = std::get<0>(rCollection);
		date = std::get<1>(rCollection);
		executionDate = std::get<2>(rCollection);
		statusCode = std::get<3>(rCollection);
		statusName = std::get<4>(rCollection);
		clientName = std::get<5>(rCollection);
		clientSurname = std::get<6>(rCollection);
		clientPhone = std::get<7>(rCollection);
		clientAddres = std::get<8>(rCollection);
		clientFirm = std::get<9>(rCollection);
		employeeName = std::get<10>(rCollection);
		employeeSurname = std::get<11>(rCollection);
		employeePhone = std::get<12>(rCollection);
		count = std::get<13>(rCollection);
		sum = std::get<14>(rCollection);
		currencyName = std::get<15>(rCollection);
		employeeID = std::get<16>(rCollection);
		clientID = std::get<17>(rCollection);
		statusID = std::get<18>(rCollection);
		currencyID = std::get<19>(rCollection);
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

