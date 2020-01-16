#ifndef POSTINGFIXEDASSETSVIEWCLASS_H
#define POSTINGFIXEDASSETSVIEWCLASS_H

#include "PostingFixedAssetsClass.h"

namespace BusinessLayer
{
	class PostingFixedAssetsView : public PostingFixedAssets
	{
	protected:
		std::string surname = "";
		std::string accountName = "";
	public:
		PostingFixedAssetsView(DataLayer::postingFixedAssetsViewCollection);
		PostingFixedAssetsView(){};
		~PostingFixedAssetsView(){};

		// OrderView class Accessors
		std::string GetSurname();
		std::string GetAccountName();
	};
}
#endif //POSTINGFIXEDASSETSVIEWCLASS_H
