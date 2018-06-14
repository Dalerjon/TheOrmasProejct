#include "stdafx.h"
#include "ConsumeRawViewClass.h"

namespace BusinessLayer
{
	ConsumeRawView::ConsumeRawView(DataLayer::consumeRawsViewCollection cCollection)
	{
		id = std::get<0>(cCollection);
		date = std::get<1>(cCollection);
		executionDate = std::get<2>(cCollection);
		statusCode = std::get<3>(cCollection);
		statusName = std::get<4>(cCollection);
		employeeName = std::get<5>(cCollection);
		employeeSurname = std::get<6>(cCollection);
		employeePhone = std::get<7>(cCollection);
		employeePosition = std::get<8>(cCollection);
		stockEmployeeName = std::get<9>(cCollection);
		stockEmployeeSurname = std::get<10>(cCollection);
		stockEmployeePhone = std::get<11>(cCollection);
		stockEmployeePosition = std::get<12>(cCollection);
		count = std::get<13>(cCollection);
		sum = std::get<14>(cCollection);
		currencyName = std::get<15>(cCollection);
		stockEmployeeID = std::get<16>(cCollection);
		employeeID = std::get<17>(cCollection);
		statusID = std::get<18>(cCollection);
		currencyID = std::get<19>(cCollection);
	}

	std::string ConsumeRawView::GetStatusCode()
	{
		return statusCode;
	}
	std::string ConsumeRawView::GetStatusName()
	{
		return statusName;
	}
	std::string ConsumeRawView::GetEmployeeName()
	{
		return employeeName;
	}
	std::string ConsumeRawView::GetEmployeeSurname()
	{
		return employeeSurname;
	}
	std::string ConsumeRawView::GetEmployeePhone()
	{
		return employeePhone;
	}
	std::string ConsumeRawView::GetEmployeePosition()
	{
		return employeePosition;
	}
	std::string ConsumeRawView::GetStockEmployeeName()
	{
		return stockEmployeeName;
	}
	std::string ConsumeRawView::GetStockEmployeeSurname()
	{
		return stockEmployeeSurname;
	}
	std::string ConsumeRawView::GetStockEmployeePhone()
	{
		return stockEmployeePhone;
	}
	std::string ConsumeRawView::GetStockEmployeePosition()
	{
		return stockEmployeePosition;
	}
	std::string ConsumeRawView::GetCurrencyName()
	{
		return currencyName;
	}

}

