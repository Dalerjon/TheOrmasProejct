#ifndef POSTINGFIXEDASSETSCLASS_H
#define POSTINGFIXEDASSETSCLASS_H

#include "OrmasDAL.h"
#include <map>

namespace BusinessLayer
{
	class PostingFixedAssets
	{
	protected:
		int id = 0;
		int userID = 0;
		int subaccountID = 0;
		int accountID = 0;
		int fixedAssetsID = 0;
		int inventoryID = 0;
	public:
		PostingFixedAssets(int pfaID, int uID, int sID, int aID, int faID, int iID) : id(pfaID), userID(uID),
			subaccountID(sID), accountID(aID), fixedAssetsID(faID), inventoryID(iID){};
		PostingFixedAssets(DataLayer::postingFixedAssetsCollection);
		PostingFixedAssets(){};
		~PostingFixedAssets(){};

		//Consume Product class Accessors
		int GetID();
		int GetUserID();
		int GetSubaccountID();
		int GetAccountID();
		int GetFixedAssetsID();
		int GetInventoryID();

		//Consume Product class Mutators
		void SetID(int);
		void SetUserID(int);
		void SetSubaccountID(int);
		void SetAccountID(int);
		void SetFixedAssetsID(int);
		void SetInventoryID(int);


		//Create, delete, update methods
		bool CreatePostingFixedAssets(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool UpdatePostingFixedAssets(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool DeletePostingFixedAssets(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
		bool CreatePostingFixedAssets(DataLayer::OrmasDal& ormasDal, int uID, int sID, int aID, int faID, int iID, std::string& errorMessage);
		bool UpdatePostingFixedAssets(DataLayer::OrmasDal& ormasDal, int uID, int sID, int aID, int faID, int iID, std::string& errorMessage);

		//Generate filter string for class
		std::string GenerateFilter(DataLayer::OrmasDal& ormasDal);
		bool GetPostingFixedAssetsByID(DataLayer::OrmasDal& ormasDal, int fID, std::string& errorMessage);
		bool GetPostingFixedAssetsByUserID(DataLayer::OrmasDal& ormasDal, int uID, std::string& errorMessage);
		bool GetPostingFixedAssetsByAccountID(DataLayer::OrmasDal& ormasDal, int aID, std::string& errorMessage);
		bool GetPostingFixedAssetsBySubaccountID(DataLayer::OrmasDal& ormasDal, int sID, std::string& errorMessage);
		bool GetPostingFixedAssetsByFixedAssetsID(DataLayer::OrmasDal& ormasDal, int faID, std::string& errorMessage);
		bool GetPostingFixedAssetsByInventoryID(DataLayer::OrmasDal& ormasDal, int iID, std::string& errorMessage);
		bool IsEmpty();
		void Clear();
	private:
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, int uID, int sID, int aID, int fID, int iID, std::string& errorMessage);
		bool IsDuplicate(DataLayer::OrmasDal& ormasDal, std::string& errorMessage);
	};
}
#endif //PostingFixedAssetsCLASS_H