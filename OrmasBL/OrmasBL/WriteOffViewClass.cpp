#include "stdafx.h"
#include "WriteOffViewClass.h"

namespace BusinessLayer
{
	WriteOffView::WriteOffView(DataLayer::writeOffsViewCollection oCollection)
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

