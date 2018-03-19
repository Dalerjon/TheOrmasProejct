#include "stdafx.h"
#include "ProductionPlanViewClass.h"

namespace BusinessLayer
{
	ProductionPlanView::ProductionPlanView(DataLayer::productionPlanViewCollection pCollection)
	{
		id = std::get<0>(pCollection);
		date = std::get<1>(pCollection);
		count = std::get<2>(pCollection);
		sum = std::get<3>(pCollection);
		currencyName = std::get<4>(pCollection);
		statusName = std::get<5>(pCollection);
		employeeName = std::get<6>(pCollection);
		employeeSurname = std::get<7>(pCollection);
		employeePhone = std::get<8>(pCollection);
		employeePosition = std::get<9>(pCollection);
		employeeID = std::get<10>(pCollection);
		statusID = std::get<11>(pCollection);
		currencyID = std::get<12>(pCollection);
	}

	std::string ProductionPlanView::GetStatusName()
	{
		return statusName;
	}
	std::string ProductionPlanView::GetEmployeeName()
	{
		return employeeName;
	}
	std::string ProductionPlanView::GetEmployeeSurname()
	{
		return employeeSurname;
	}
	std::string ProductionPlanView::GetEmployeePhone()
	{
		return employeePhone;
	}
	std::string ProductionPlanView::GetEmployeePosition()
	{
		return employeePosition;
	}
	std::string ProductionPlanView::GetCurrencyName()
	{
		return currencyName;
	}

}

