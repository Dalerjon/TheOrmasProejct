#include "stdafx.h"
#include "TimesheetViewClass.h"

namespace BusinessLayer{
	TimesheetView::TimesheetView(DataLayer::timesheetViewCollection tCollection)
	{
		id = std::get<0>(tCollection);
		userName = std::get<1>(tCollection);
		userSurname = std::get<2>(tCollection);
		userPhone = std::get<3>(tCollection);
		date = std::get<4>(tCollection);
		workedTime = std::get<5>(tCollection);
		salaryID = std::get<6>(tCollection);
	}

	std::string TimesheetView::GetUsername()
	{
		return userName;
	}
	std::string TimesheetView::GetUserSurname()
	{
		return userSurname;
	}
	std::string TimesheetView::GetUserPhone()
	{
		return userPhone;
	}
}