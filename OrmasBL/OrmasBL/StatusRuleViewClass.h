#ifndef STATUSRULEVIEWCLASS_H
#define STATUSRULEVIEWCLASS_H

#include "StatusRuleClass.h"

namespace BusinessLayer{
	class StatusRuleView : public StatusRule
	{
		std::string statusName = "";
	public:
		StatusRuleView(DataLayer::statusRuleViewCollection);
		StatusRuleView(){};
		~StatusRuleView(){};

		// StatusRuleView class Accessors
		std::string GetStatusName();
	};
}

#endif