#include "stdafx.h"
#include "JobsheetViewClass.h"

namespace BusinessLayer{
	JobsheetView::JobsheetView(DataLayer::jobsheetViewCollection pCollection)
	{
		id = std::get<0>(pCollection);
		date = std::get<1>(pCollection);
		employeeName = std::get<2>(pCollection);
		employeeSurname = std::get<3>(pCollection);
		employeePhone = std::get<4>(pCollection);
		productName = std::get<5>(pCollection);
		count = std::get<6>(pCollection);
		measureName = std::get<7>(pCollection);
		productID = std::get<8>(pCollection);
	}

	std::string JobsheetView::GetEmployeeName()
	{
		return employeeName;
	}

	std::string JobsheetView::GetEmployeeSurname()
	{
		return employeeSurname;
	}

	std::string JobsheetView::GetEmployeePhone()
	{
		return employeePhone;
	}

	std::string JobsheetView::GetProductName()
	{
		return productName;
	}

	std::string JobsheetView::GetMeasureName()
	{
		return measureName;
	}
}