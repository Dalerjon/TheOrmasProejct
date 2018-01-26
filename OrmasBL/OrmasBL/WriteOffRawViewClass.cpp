#include "stdafx.h"
#include "WriteOffRawViewClass.h"

namespace BusinessLayer
{
	WriteOffRawView::WriteOffRawView(DataLayer::writeOffRawsViewCollection wCollection)
	{
		id = std::get<0>(wCollection);
		date = std::get<1>(wCollection);
		statusCode = std::get<2>(wCollection);
		statusName = std::get<3>(wCollection);
		employeeName = std::get<4>(wCollection);
		employeeSurname = std::get<5>(wCollection);
		employeePhone = std::get<6>(wCollection);
		employeePosition = std::get<7>(wCollection);
		stockEmployeeName = std::get<8>(wCollection);
		stockEmployeeSurname = std::get<9>(wCollection);
		stockEmployeePhone = std::get<10>(wCollection);
		stockEmployeePosition = std::get<11>(wCollection);
		count = std::get<12>(wCollection);
		sum = std::get<13>(wCollection);
		currencyName = std::get<14>(wCollection);
		stockEmployeeID = std::get<15>(wCollection);
		employeeID = std::get<16>(wCollection);
		statusID = std::get<17>(wCollection);
		currencyID = std::get<18>(wCollection);
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
		return stockEmployeePhone;
	}
	std::string WriteOffRawView::GetCurrencyName()
	{
		return currencyName;
	}

}

