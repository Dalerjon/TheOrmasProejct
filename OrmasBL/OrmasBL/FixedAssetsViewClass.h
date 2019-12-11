#ifndef FIXEDASSETSVIEWCLASS_H
#define FIXEDASSETSVIEWCLASS_H

#include "FixedAssetsClass.h"

namespace BusinessLayer
{
	class FixedAssetsView : public FixedAssets
	{
		std::string name = "";
		double primaryCostValue = 0;
		double amortizeValue = 0;
		std::string divisionName = "";
		std::string statusName = "";
	public:
		FixedAssetsView(DataLayer::fixedAssetsViewCollection);
		FixedAssetsView(){};
		~FixedAssetsView(){};

		// OrderView class Accessors
		std::string GetName();
		double GetPrimaryCostValue();
		double GetAmortizeValue();
		std::string GetDivisionName();
		std::string GetStatusName();
	};
}
#endif //FixedAssetsVIEWCLASS_H
