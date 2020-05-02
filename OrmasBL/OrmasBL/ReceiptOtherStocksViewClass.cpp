#include "stdafx.h"
#include "ReceiptOtherStocksViewClass.h"

namespace BusinessLayer
{
	ReceiptOtherStocksView::ReceiptOtherStocksView(DataLayer::receiptOtherStocksViewCollection oCollection)
	{
		id = std::get<0>(oCollection);
		date = std::get<1>(oCollection);
		executionDate = std::get<2>(oCollection);
		statusCode = std::get<3>(oCollection);
		statusName = std::get<4>(oCollection);
		purveyorName = std::get<5>(oCollection);
		purveyorSurname = std::get<6>(oCollection);
		purveyorPhone = std::get<7>(oCollection);
		purveyorCompanyName = std::get<8>(oCollection);
		employeeName = std::get<9>(oCollection);
		employeeSurname = std::get<10>(oCollection);
		employeePhone = std::get<11>(oCollection);
		employeePosition = std::get<12>(oCollection);
		count = std::get<13>(oCollection);
		sum = std::get<14>(oCollection);
		currencyName = std::get<15>(oCollection);
		employeeID = std::get<16>(oCollection);
		purveyorID = std::get<17>(oCollection);
		statusID = std::get<18>(oCollection);
		currencyID = std::get<19>(oCollection);
	}

	std::string ReceiptOtherStocksView::GetStatusCode()
	{
		return statusCode;
	}
	std::string ReceiptOtherStocksView::GetStatusName()
	{
		return statusName;
	}
	std::string ReceiptOtherStocksView::GetPurveyorName()
	{
		return purveyorName;
	}
	std::string ReceiptOtherStocksView::GetPurveyorSurname()
	{
		return purveyorSurname;
	}
	std::string ReceiptOtherStocksView::GetPurveyorPhone()
	{
		return purveyorPhone;
	}
	std::string ReceiptOtherStocksView::GetPurveyorCompanyName()
	{
		return purveyorCompanyName;
	}
	std::string ReceiptOtherStocksView::GetEmployeeName()
	{
		return employeeName;
	}
	std::string ReceiptOtherStocksView::GetEmployeeSurname()
	{
		return employeeSurname;
	}
	std::string ReceiptOtherStocksView::GetEmployeePhone()
	{
		return employeePhone;
	}
	std::string ReceiptOtherStocksView::GetEmployeePosition()
	{
		return employeePosition;
	}
	std::string ReceiptOtherStocksView::GetCurrencyName()
	{
		return currencyName;
	}

}

