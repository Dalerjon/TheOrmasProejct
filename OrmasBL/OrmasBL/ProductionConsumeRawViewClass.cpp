#include "stdafx.h"
#include "ProductionConsumeRawViewClass.h"

namespace BusinessLayer
{
	ProductionConsumeRawView::ProductionConsumeRawView(DataLayer::productionConsumeRawsViewCollection cCollection)
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

	std::string ProductionConsumeRawView::GetStatusCode()
	{
		return statusCode;
	}
	std::string ProductionConsumeRawView::GetStatusName()
	{
		return statusName;
	}
	std::string ProductionConsumeRawView::GetEmployeeName()
	{
		return employeeName;
	}
	std::string ProductionConsumeRawView::GetEmployeeSurname()
	{
		return employeeSurname;
	}
	std::string ProductionConsumeRawView::GetEmployeePhone()
	{
		return employeePhone;
	}
	std::string ProductionConsumeRawView::GetEmployeePosition()
	{
		return employeePosition;
	}
	std::string ProductionConsumeRawView::GetStockEmployeeName()
	{
		return stockEmployeeName;
	}
	std::string ProductionConsumeRawView::GetStockEmployeeSurname()
	{
		return stockEmployeeSurname;
	}
	std::string ProductionConsumeRawView::GetStockEmployeePhone()
	{
		return stockEmployeePhone;
	}
	std::string ProductionConsumeRawView::GetStockEmployeePosition()
	{
		return stockEmployeePosition;
	}
	std::string ProductionConsumeRawView::GetCurrencyName()
	{
		return currencyName;
	}

}

