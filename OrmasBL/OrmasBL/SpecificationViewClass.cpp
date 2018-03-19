#include "stdafx.h"
#include "SpecificationViewClass.h"

namespace BusinessLayer
{
	SpecificationView::SpecificationView(DataLayer::specificationsViewCollection sCollection)
	{
		id = std::get<0>(sCollection);
		date = std::get<1>(sCollection);
		productName = std::get<2>(sCollection);
		sum = std::get<3>(sCollection);
		currencyName = std::get<4>(sCollection);
		employeeName = std::get<5>(sCollection);
		employeeSurname = std::get<6>(sCollection);
		employeePhone = std::get<7>(sCollection);
		employeePositionName = std::get<8>(sCollection);
		productID = std::get<9>(sCollection);
		currencyID = std::get<10>(sCollection);
		employeeID = std::get<11>(sCollection);
	}

	std::string SpecificationView::GetProductName()
	{
		return productName;
	}
	std::string SpecificationView::GetCurrencyName()
	{
		return currencyName;
	}
	std::string SpecificationView::GetEmployeeName()
	{
		return employeeName;
	}
	std::string SpecificationView::GetEmployeeSurname()
	{
		return employeeSurname;
	}
	std::string SpecificationView::GetEmployeePhone()
	{
		return employeePhone;
	}
	std::string SpecificationView::GetEmployeePositionName()
	{
		return employeePositionName;
	}
}

