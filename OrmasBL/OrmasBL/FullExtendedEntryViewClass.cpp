#include "stdafx.h"
#include "FullExtendedEntryViewClass.h"

namespace BusinessLayer{
	FullExtendedEntryView::FullExtendedEntryView(DataLayer::entriesFullJoinViewCollection eCollection)
	{
		id = std::get<0>(eCollection);
		date = std::get<1>(eCollection);
		debitingAccountNumber = std::get<2>(eCollection);
		value = std::get<3>(eCollection);
		creditingAccountNumber = std::get<4>(eCollection);
		operationID = std::get<5>(eCollection);
		subaccountID = std::get<6>(eCollection);
		debitingAccountID = std::get<7>(eCollection);
		creditingAccountID = std::get<8>(eCollection);
		description = std::get<9>(eCollection);
		consumeProductID = std::get<10>(eCollection);
		consumeRawID = std::get<11>(eCollection);
		fixedAssetsID = std::get<12>(eCollection);
		fixedAssetsOperID = std::get<13>(eCollection);
		inventoryID = std::get<14>(eCollection);
		orderID = std::get<15>(eCollection);
		orderRawID = std::get<16>(eCollection);
		paymentID = std::get<17>(eCollection);
		payslipID = std::get<18>(eCollection);
		productionConRawID = std::get<19>(eCollection);
		receiptProductID = std::get<20>(eCollection);
		returnID = std::get<21>(eCollection);
		spoilageID = std::get<22>(eCollection);
		stockTransferID = std::get<23>(eCollection);
		withdrawalID = std::get<24>(eCollection);
		writeOffID = std::get<25>(eCollection);
		writeOffRawID = std::get<26>(eCollection);
		productID = std::get<27>(eCollection);
		otherStocksID = std::get<28>(eCollection);
		receiptOtherStocksID = std::get<29>(eCollection);
		consumeOtherStocksID = std::get<30>(eCollection);
	}

	std::string FullExtendedEntryView::GetDebitingAccountNumber()
	{
		return debitingAccountNumber;
	}

	std::string FullExtendedEntryView::GetCreditingAccountNumber()
	{
		return creditingAccountNumber;
	}

	int FullExtendedEntryView::GetOperationID()
	{
		return operationID;
	}

	int FullExtendedEntryView::GetSubaccountID()
	{
		return subaccountID;
	}

	int FullExtendedEntryView::GetConsumeRawID()
	{
		return consumeRawID;
	}

	int FullExtendedEntryView::GetConsumeProductID()
	{
		return productID;
	}

	int FullExtendedEntryView::GetConsumeOtherStocksID()
	{
		return otherStocksID;
	}

	int FullExtendedEntryView::GetFixedAssetsID()
	{
		return fixedAssetsID;
	}

	int FullExtendedEntryView::GetFixedAssetsOperID()
	{
		return fixedAssetsOperID;
	}

	int FullExtendedEntryView::GetInventoryID()
	{
		return inventoryID;
	}


	int FullExtendedEntryView::GetOrderID()
	{
		return orderID;
	}

	int FullExtendedEntryView::GetOrderRawID()
	{
		return orderRawID;
	}

	int FullExtendedEntryView::GetPaymentID()
	{
		return paymentID;
	}

	int FullExtendedEntryView::GetPayslipID()
	{
		return payslipID;
	}

	int FullExtendedEntryView::GetProductionConRawID()
	{
		return productionConRawID;
	}

	int FullExtendedEntryView::GetReceiptProductID()
	{
		return receiptProductID;
	}


	int FullExtendedEntryView::GetReceiptOtherStocksID()
	{
		return otherStocksID;
	}

	int FullExtendedEntryView::GetReturnID()
	{
		return returnID;
	}

	int FullExtendedEntryView::GetSpoilageID()
	{
		return spoilageID;
	}

	int FullExtendedEntryView::GetStockTransferID()
	{
		return stockTransferID;
	}

	int FullExtendedEntryView::GetWithdrawalID()
	{
		return withdrawalID;
	}

	int FullExtendedEntryView::GetWriteOFFID()
	{
		return writeOffID;
	}

	int FullExtendedEntryView::GetWriteOFFRawID()
	{
		return writeOffRawID;
	}

	int FullExtendedEntryView::GetProductID()
	{
		return productID;
	}

	int FullExtendedEntryView::GetOtherStocksID()
	{
		return otherStocksID;
	}
}