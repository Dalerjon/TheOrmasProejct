#ifndef TIMESHEETVIEWCLASS_H
#define TIMESHEETVIEWCLASS_H

#include "TimesheetClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class TimesheetView : public Timesheet
	{
		std::string userName = "";
		std::string userSurname = "";
		std::string userPhone = "";
	public:
		TimesheetView(DataLayer::timesheetViewCollection);
		TimesheetView(){};
		~TimesheetView(){};

		// TimesheetView class Accessors
		std::string GetUsername();
		std::string GetUserSurname();
		std::string GetUserPhone();
	};
}

#endif