#ifndef FIXEDASSETSDETAILSVIEWCLASS_H
#define FIXEDASSETSDETAILSVIEWCLASS_H

#include "FixedAssetsDetailsClass.h"

namespace BusinessLayer
{
	class FixedAssetsDetailsView : public FixedAssetsDetails
	{
	protected:
		int groupNumber = 0;
		std::string amortizeTypeName = "";
		std::string amortizeTypeCode = "";
		std::string divisionName = "";
		double primaryAccValue = 0;
		double amortizeAccValue = 0;
	public:
		FixedAssetsDetailsView(DataLayer::fixedAssetsDetailsViewCollection);
		FixedAssetsDetailsView(){};
		~FixedAssetsDetailsView(){};

		// OrderView class Accessors
		int GetGroupNumber();
		std::string GetAmortizeTypeName();
		std::string GetAmortizeTypeCode();
		std::string GetDivisionName();
		double GetPrimaryAccValue();
		double GetAmortizeAccValue();
	};
}
#endif //FixedAssetsDetailsVIEWCLASS_H
