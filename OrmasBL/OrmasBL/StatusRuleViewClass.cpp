#include "stdafx.h"
#include "StatusRuleViewClass.h"

namespace BusinessLayer{
	StatusRuleView::StatusRuleView(DataLayer::statusRuleViewCollection sCollection)
	{
		id = std::get<0>(sCollection);
		operation = std::get<1>(sCollection);
		statusName = std::get<2>(sCollection);
		statusID = std::get<3>(sCollection);
	}

	std::string StatusRuleView::GetStatusName()
	{
		return statusName;
	}
}