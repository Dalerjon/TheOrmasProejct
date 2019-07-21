#include "stdafx.h"
#include "WriteOffViewClass.h"

namespace BusinessLayer
{
	WriteOffView::WriteOffView(DataLayer::writeOffsViewCollection oCollection)
	{
		id = std::get<0>(oCollection);
		date = std::get<1>(oCollection);
		executionDate = std::get<2>(oCollection);
		statusCode = std::get<3>(oCollection);
		statusName = std::get<4>(oCollection);
		clientName = std::get<5>(oCollection);
		clientSurname = std::get<6>(oCollection);
		clientPhone = std::get<7>(oCollection);
		clientAddres = std::get<8>(oCollection);
		clientFirm = std::get<9>(oCollection);
		employeeName = std::get<10>(oCollection);
		employeeSurname = std::get<11>(oCollection);
		employeePhone = std::get<12>(oCollection);
		count = std::get<13>(oCollection);
		sum = std::get<14>(oCollection);
		currencyName = std::get<15>(oCollection);
		employeeID = std::get<16>(oCollection);
		clientID = std::get<17>(oCollection);
		statusID = std::get<18>(oCollection);
		currencyID = std::get<19>(oCollection);
	}

	std::string WriteOffView::GetStatusCode()
	{
		return statusCode;
	}
	std::string WriteOffView::GetStatusName()
	{
		return statusName;
	}
	std::string WriteOffView::GetClientName()
	{
		return clientName;
	}
	std::string WriteOffView::GetClientSurname()
	{
		return clientSurname;
	}
	std::string WriteOffView::GetClientPhone()
	{
		return clientPhone;
	}
	std::string WriteOffView::GetClientAddress()
	{
		return clientAddres;
	}
	std::string WriteOffView::GetClientFirm()
	{
		return clientFirm;
	}
	std::string WriteOffView::GetEmployeeName()
	{
		return employeeName;
	}
	std::string WriteOffView::GetEmployeeSurname()
	{
		return employeeSurname;
	}
	std::string WriteOffView::GetEmployeePhone()
	{
		return employeePhone;
	}
	std::string WriteOffView::GetCurrencyName()
	{
		return currencyName;
	}

}

