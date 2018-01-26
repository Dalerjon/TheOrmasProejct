#include "stdafx.h"
#include "ReceiptRawViewClass.h"

namespace BusinessLayer
{
	ReceiptRawView::ReceiptRawView(DataLayer::receiptRawsViewCollection rCollection)
	{
		id = std::get<0>(rCollection);
		date = std::get<1>(rCollection);
		executionDate = std::get<2>(rCollection);
		statusCode = std::get<3>(rCollection);
		statusName = std::get<4>(rCollection);
		employeeName = std::get<5>(rCollection);
		employeeSurname = std::get<6>(rCollection);
		employeePhone = std::get<7>(rCollection);
		employeePosition = std::get<8>(rCollection);
		stockEmployeeName = std::get<9>(rCollection);
		stockEmployeeSurname = std::get<10>(rCollection);
		stockEmployeePhone = std::get<11>(rCollection);
		stockEmployeePosition = std::get<12>(rCollection);
		count = std::get<13>(rCollection);
		sum = std::get<14>(rCollection);
		currencyName = std::get<15>(rCollection);
		stockEmployeeID = std::get<16>(rCollection);
		employeeID = std::get<17>(rCollection);
		statusID = std::get<18>(rCollection);
		currencyID = std::get<19>(rCollection);
	}

	std::string ReceiptRawView::GetStatusCode()
	{
		return statusCode;
	}
	std::string ReceiptRawView::GetStatusName()
	{
		return statusName;
	}
	std::string ReceiptRawView::GetEmployeeName()
	{
		return employeeName;
	}
	std::string ReceiptRawView::GetEmployeeSurname()
	{
		return employeeSurname;
	}
	std::string ReceiptRawView::GetEmployeePhone()
	{
		return employeePhone;
	}
	std::string ReceiptRawView::GetEmployeePosition()
	{
		return employeePosition;
	}
	std::string ReceiptRawView::GetStockEmployeeName()
	{
		return stockEmployeeName;
	}
	std::string ReceiptRawView::GetStockEmployeeSurname()
	{
		return stockEmployeeSurname;
	}
	std::string ReceiptRawView::GetStockEmployeePhone()
	{
		return stockEmployeePhone;
	}
	std::string ReceiptRawView::GetStockEmployeePosition()
	{
		return stockEmployeePhone;
	}
	std::string ReceiptRawView::GetCurrencyName()
	{
		return currencyName;
	}

}

