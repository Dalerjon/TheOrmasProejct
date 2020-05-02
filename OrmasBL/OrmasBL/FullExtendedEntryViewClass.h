#ifndef FULLEXTENDEDENTRYVIEWCLASS_H
#define FULLEXTENDEDENTRYVIEWCLASS_H

#include "EntryClass.h"
#include "OrmasDAL.h"
namespace BusinessLayer{
	class FullExtendedEntryView : public Entry
	{
		int operationID = 0;
		int subaccountID = 0;
		std::string debitingAccountNumber = "";
		std::string creditingAccountNumber = "";
		int consumeOtherStocksID = 0;
		int consumeRawID = 0;
		int consumeProductID = 0;
		int fixedAssetsID = 0;
		int fixedAssetsOperID = 0;
		int inventoryID = 0;
		int orderID = 0;
		int orderRawID = 0;
		int paymentID = 0;
		int payslipID = 0;
		int productionConRawID = 0;
		int receiptProductID = 0;
		int receiptOtherStocksID = 0;
		int returnID = 0;
		int spoilageID = 0;
		int stockTransferID = 0;
		int withdrawalID = 0;
		int writeOffID = 0;
		int writeOffRawID = 0;
		int productID = 0;
		int otherStocksID = 0;
	public:
		FullExtendedEntryView(DataLayer::entriesFullJoinViewCollection);
		FullExtendedEntryView(){};
		~FullExtendedEntryView(){};

		// EntryView class Accessors
		std::string GetDebitingAccountNumber();
		std::string GetCreditingAccountNumber();
		int GetOperationID();
		int GetSubaccountID();
		int GetConsumeRawID();
		int GetConsumeProductID();
		int GetConsumeOtherStocksID();
		int GetFixedAssetsID();
		int GetFixedAssetsOperID();
		int GetInventoryID();
		int GetOrderID();
		int GetOrderRawID();
		int GetPaymentID();
		int GetPayslipID();
		int GetProductionConRawID();
		int GetReceiptProductID();
		int GetReceiptOtherStocksID();
		int GetReturnID();
		int GetSpoilageID();
		int GetStockTransferID();
		int GetWithdrawalID();
		int GetWriteOFFID();
		int GetWriteOFFRawID();
		int GetProductID();
		int GetOtherStocksID();
	};
}
#endif