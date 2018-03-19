#ifndef SPECIFICATIONLISTVIEWCLASS_H
#define SPECIFICATIONLISTVIEWCLASS_H

#include "SpecificationListClass.h"

namespace BusinessLayer
{
	class SpecificationListView : public SpecificationList
	{
		std::string productName = "";
		std::string measureName = "";
	public:
		SpecificationListView(DataLayer::specificationListViewCollection);
		SpecificationListView(){};
		~SpecificationListView(){};

		//SpecificationListView class Accessors
		std::string GetProductName();
		std::string GetMeasureName();
	};
}
#endif //SpecificationLISTVIEWCLASS_