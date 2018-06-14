#include "stdafx.h"
#include "TransportViewClass.h"

namespace BusinessLayer
{
	TransportView::TransportView(DataLayer::transportsViewCollection tCollection)
	{
		id = std::get<0>(tCollection);
		date = std::get<1>(tCollection);
		executionDate = std::get<2>(tCollection);
		statusCode = std::get<3>(tCollection);
		statusName = std::get<4>(tCollection);
		employeeName = std::get<5>(tCollection);
		employeeSurname = std::get<6>(tCollection);
		employeePhone = std::get<7>(tCollection);
		employeePosition = std::get<8>(tCollection);
		stockEmployeeName = std::get<9>(tCollection);
		stockEmployeeSurname = std::get<10>(tCollection);
		stockEmployeePhone = std::get<11>(tCollection);
		stockEmployeePosition = std::get<12>(tCollection);
		count = std::get<13>(tCollection);
		sum = std::get<14>(tCollection);
		currencyName = std::get<15>(tCollection);
		stockEmployeeID = std::get<16>(tCollection);
		employeeID = std::get<17>(tCollection);
		statusID = std::get<18>(tCollection);
		currencyID = std::get<19>(tCollection);
	}

	std::string TransportView::GetStatusCode()
	{
		return statusCode;
	}
	std::string TransportView::GetStatusName()
	{
		return statusName;
	}
	std::string TransportView::GetEmployeeName()
	{
		return employeeName;
	}
	std::string TransportView::GetEmployeeSurname()
	{
		return employeeSurname;
	}
	std::string TransportView::GetEmployeePhone()
	{
		return employeePhone;
	}
	std::string TransportView::GetEmployeePosition()
	{
		return employeePosition;
	}
	std::string TransportView::GetStockEmployeeName()
	{
		return stockEmployeeName;
	}
	std::string TransportView::GetStockEmployeeSurname()
	{
		return stockEmployeeSurname;
	}
	std::string TransportView::GetStockEmployeePhone()
	{
		return stockEmployeePhone;
	}
	std::string TransportView::GetStockEmployeePosition()
	{
		return stockEmployeePosition;
	}
	std::string TransportView::GetCurrencyName()
	{
		return currencyName;
	}

}

