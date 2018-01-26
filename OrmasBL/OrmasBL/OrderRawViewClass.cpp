#include "stdafx.h"
#include "OrderRawViewClass.h"

namespace BusinessLayer
{
	OrderRawView::OrderRawView(DataLayer::orderRawsViewCollection oCollection)
	{
		id = std::get<0>(oCollection);
		date = std::get<1>(oCollection);
		executionDate = std::get<2>(oCollection);
		statusCode = std::get<3>(oCollection);
		statusName = std::get<4>(oCollection);
		employeeName = std::get<5>(oCollection);
		employeeSurname = std::get<6>(oCollection);
		employeePhone = std::get<7>(oCollection);
		employeePosition = std::get<8>(oCollection);
		stockEmployeeName = std::get<9>(oCollection);
		stockEmployeeSurname = std::get<10>(oCollection);
		stockEmployeePhone = std::get<11>(oCollection);
		stockEmployeePosition = std::get<12>(oCollection);
		count = std::get<13>(oCollection);
		sum = std::get<14>(oCollection);
		currencyName = std::get<15>(oCollection);
		stockEmployeeID = std::get<16>(oCollection);
		employeeID = std::get<17>(oCollection);
		statusID = std::get<18>(oCollection);
		currencyID = std::get<19>(oCollection);
	}

	std::string OrderRawView::GetStatusCode()
	{
		return statusCode;
	}
	std::string OrderRawView::GetStatusName()
	{
		return statusName;
	}
	std::string OrderRawView::GetEmployeeName()
	{
		return employeeName;
	}
	std::string OrderRawView::GetEmployeeSurname()
	{
		return employeeSurname;
	}
	std::string OrderRawView::GetEmployeePhone()
	{
		return employeePhone;
	}
	std::string OrderRawView::GetEmployeePosition()
	{
		return employeePosition;
	}
	std::string OrderRawView::GetStockEmployeeName()
	{
		return stockEmployeeName;
	}
	std::string OrderRawView::GetStockEmployeeSurname()
	{
		return stockEmployeeSurname;
	}
	std::string OrderRawView::GetStockEmployeePhone()
	{
		return stockEmployeePhone;
	}
	std::string OrderRawView::GetStockEmployeePosition()
	{
		return stockEmployeePhone;
	}
	std::string OrderRawView::GetCurrencyName()
	{
		return currencyName;
	}

}

