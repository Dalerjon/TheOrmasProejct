#include "stdafx.h"
#include "WriteOffRawViewClass.h"

namespace BusinessLayer
{
	WriteOffRawView::WriteOffRawView(DataLayer::writeOffRawsViewCollection wCollection)
	{
		id = std::get<0>(wCollection);
		date = std::get<1>(wCollection);
		executionDate = std::get<2>(wCollection);
		statusCode = std::get<3>(wCollection);
		statusName = std::get<4>(wCollection);
		employeeName = std::get<5>(wCollection);
		employeeSurname = std::get<6>(wCollection);
		employeePhone = std::get<7>(wCollection);
		employeePosition = std::get<8>(wCollection);
		stockEmployeeName = std::get<9>(wCollection);
		stockEmployeeSurname = std::get<10>(wCollection);
		stockEmployeePhone = std::get<11>(wCollection);
		stockEmployeePosition = std::get<12>(wCollection);
		count = std::get<13>(wCollection);
		sum = std::get<14>(wCollection);
		currencyName = std::get<15>(wCollection);
		stockEmployeeID = std::get<16>(wCollection);
		employeeID = std::get<17>(wCollection);
		statusID = std::get<18>(wCollection);
		currencyID = std::get<19>(wCollection);
	}

	std::string WriteOffRawView::GetStatusCode()
	{
		return statusCode;
	}
	std::string WriteOffRawView::GetStatusName()
	{
		return statusName;
	}
	std::string WriteOffRawView::GetEmployeeName()
	{
		return employeeName;
	}
	std::string WriteOffRawView::GetEmployeeSurname()
	{
		return employeeSurname;
	}
	std::string WriteOffRawView::GetEmployeePhone()
	{
		return employeePhone;
	}
	std::string WriteOffRawView::GetEmployeePosition()
	{
		return employeePosition;
	}
	std::string WriteOffRawView::GetStockEmployeeName()
	{
		return stockEmployeeName;
	}
	std::string WriteOffRawView::GetStockEmployeeSurname()
	{
		return stockEmployeeSurname;
	}
	std::string WriteOffRawView::GetStockEmployeePhone()
	{
		return stockEmployeePhone;
	}
	std::string WriteOffRawView::GetStockEmployeePosition()
	{
		return stockEmployeePosition;
	}
	std::string WriteOffRawView::GetCurrencyName()
	{
		return currencyName;
	}

}

