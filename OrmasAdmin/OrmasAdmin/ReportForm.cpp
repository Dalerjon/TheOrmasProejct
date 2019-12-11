#include "stdafx.h"
#include "ReportForm.h"
#include "MainForm.h"
#include "DocForm.h"

ReportForm::ReportForm(BusinessLayer::OrmasBL *ormasBL, QWidget *parent) :QWidget(parent)
{
	setupUi(this);
	tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tableView->verticalHeader()->hide();
	tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	reportFormBL = ormasBL;
	parentForm = parent;
	connect(closeBtn, &QPushButton::released, this, &ReportForm::CloseReportForm);
	connect(viewBtn, &QPushButton::released, this, &ReportForm::View);
}

void ReportForm::GetIDValue(QModelIndex index)
{
	int id = GetIDFromTable(tableView, index);
	emit SendID(id, objectName());
	CloseReportForm();
}

void ReportForm::CloseReportForm()
{
	QMdiSubWindow *reprotFromWindow = ((MainForm*)parentForm)->GetWindowByName(this->objectName());
	if (reprotFromWindow != nullptr)
		reprotFromWindow->close();
}

void ReportForm::FillStockTable(std::string fromDate, std::string tillDate, int warehouseID, std::string prevMonthEndDate)
{
	this->setObjectName("WTBS");
	BusinessLayer::Status status;
	if (!status.GetStatusByName(reportFormBL->GetOrmasDal(), "EXECUTED", errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Please contact with administrator, you have same troubles with statuses!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::Status statusReturn;
	if (!statusReturn.GetStatusByName(reportFormBL->GetOrmasDal(), "RETURN", errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Please contact with administrator, you have same troubles with statuses!")),
			QString(tr("Ok")));
		return;
	}

	BusinessLayer::WarehouseType wType;
	BusinessLayer::Warehouse warehouse;
	if (!warehouse.GetWarehouseByID(reportFormBL->GetOrmasDal(), warehouseID, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Please contact with administrator, you have same troubles with warehouses!")),
			QString(tr("Ok")));
		return;
	}

	std::map<int, double> stockCount;
	std::map<int, double> stockSum;
	std::map<int, double> stockHistoryCount;
	std::map<int, double> stockHistorySum;


	BusinessLayer::Stock stock;
	stock.SetWarehouseID(warehouse.GetID());
	std::string filterStock = stock.GenerateFilter(reportFormBL->GetOrmasDal());
	std::vector<BusinessLayer::StockView> vecStock = reportFormBL->GetAllDataForClass<BusinessLayer::StockView>(errorMessage, filterStock);


	BusinessLayer::StockHistory stockHistoryEnd;
	stockHistoryEnd.SetWarehouseID(warehouse.GetID());
	if (!tillDate.empty())
	{
		stockHistoryEnd.SetHistoryDate(tillDate);
	}
	std::string filterStockHistoryEnd = stockHistoryEnd.GenerateFilter(reportFormBL->GetOrmasDal());
	std::vector<BusinessLayer::StockHistoryView> vecStockHistoryEnd = reportFormBL->GetAllDataForClass<BusinessLayer::StockHistoryView>(errorMessage, filterStockHistoryEnd);
	if (vecStockHistoryEnd.size() > 0)
	{
		for each (auto stockItem in vecStockHistoryEnd)
		{
			if (stockCount.find(stockItem.GetProductID()) != stockCount.end())
			{
				stockCount.find(stockItem.GetProductID())->second = stockCount.find(stockItem.GetProductID())->second + stockItem.GetCount();
				stockSum.find(stockItem.GetProductID())->second = stockSum.find(stockItem.GetProductID())->second + stockItem.GetSum();
			}
			else
			{
				stockCount.insert(std::make_pair(stockItem.GetProductID(), stockItem.GetCount()));
				stockSum.insert(std::make_pair(stockItem.GetProductID(), stockItem.GetSum()));
			}
		}
	}
	else
	{
		if (vecStock.size() > 0)
		{
			for each (auto stockItem in vecStock)
			{
				if (stockCount.find(stockItem.GetProductID()) != stockCount.end())
				{
					stockCount.find(stockItem.GetProductID())->second = stockCount.find(stockItem.GetProductID())->second + stockItem.GetCount();
					stockSum.find(stockItem.GetProductID())->second = stockSum.find(stockItem.GetProductID())->second + stockItem.GetSum();
				}
				else
				{
					stockCount.insert(std::make_pair(stockItem.GetProductID(), stockItem.GetCount()));
					stockSum.insert(std::make_pair(stockItem.GetProductID(), stockItem.GetSum()));
				}
			}
		}
	}

	BusinessLayer::StockHistory stockHistory;
	stockHistory.SetWarehouseID(warehouse.GetID());
	if (!prevMonthEndDate.empty())
	{
		stockHistory.SetHistoryDate(prevMonthEndDate);
	}
	std::string filterStockHistory = stockHistory.GenerateFilter(reportFormBL->GetOrmasDal());
	std::vector<BusinessLayer::StockHistoryView> vecStockHistory = reportFormBL->GetAllDataForClass<BusinessLayer::StockHistoryView>(errorMessage, filterStockHistory);

	if (vecStockHistory.size() > 0)
	{
		for each (auto stockHistoryItem in vecStockHistory)
		{
			if (stockHistoryCount.find(stockHistoryItem.GetProductID()) != stockHistoryCount.end())
			{
				stockHistoryCount.find(stockHistoryItem.GetProductID())->second = stockHistoryCount.find(stockHistoryItem.GetProductID())->second + stockHistoryItem.GetCount();
				stockHistorySum.find(stockHistoryItem.GetProductID())->second = stockHistorySum.find(stockHistoryItem.GetProductID())->second + stockHistoryItem.GetSum();
			}
			else
			{
				stockHistoryCount.insert(std::make_pair(stockHistoryItem.GetProductID(), stockHistoryItem.GetCount()));
				stockHistorySum.insert(std::make_pair(stockHistoryItem.GetProductID(), stockHistoryItem.GetSum()));
			}
		}
	}


	std::map<std::string, int> warehouseTypeMap;
	warehouseTypeMap = wType.GetWarehouseTypesAsMap(reportFormBL->GetOrmasDal(), errorMessage);
	if (warehouse.GetWarehouseTypeID() == warehouseTypeMap.find("RAW")->second)
	{
		//select consume raw from warehouse
		std::vector<int> employeeIDList;
		BusinessLayer::Employee employee;
		BusinessLayer::WarehouseEmployeeRelation weRelation;
		employeeIDList = weRelation.GetEmployeeIDListByWarehouseID(reportFormBL->GetOrmasDal(), warehouse.GetID());
		std::string empIDListFilter = employee.GenerateINFilterForEmployee(reportFormBL->GetOrmasDal(), employeeIDList);
		
		BusinessLayer::ConsumeRaw consumeRaw;
		consumeRaw.SetStatusID(status.GetID());
		std::string filterprRaw = consumeRaw.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		std::vector<std::string> filterList;
		filterList.push_back(filterprRaw);
		filterList.push_back(empIDListFilter);
		filterprRaw = reportFormBL->GetOrmasDal().ConcatenateFilters(filterList);
		std::vector<BusinessLayer::ConsumeRawView> vecConRaw = reportFormBL->GetAllDataForClass<BusinessLayer::ConsumeRawView>(errorMessage, filterprRaw);
	

		//Returned raws for warehouse
		BusinessLayer::ConsumeRaw consumeRawReturn;
		consumeRawReturn.SetStatusID(statusReturn.GetID());
		std::string filterprRawReturn = consumeRawReturn.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		std::vector<std::string> filterListReturn;
		filterListReturn.push_back(filterprRawReturn);
		filterListReturn.push_back(empIDListFilter);
		filterprRawReturn = reportFormBL->GetOrmasDal().ConcatenateFilters(filterListReturn);
		std::vector<BusinessLayer::ConsumeRawView> vecConRawReturn = reportFormBL->GetAllDataForClass<BusinessLayer::ConsumeRawView>(errorMessage, filterprRawReturn);

		
		// select receipt raw for warehouse
		filterList.clear();
		BusinessLayer::OrderRaw orderRaw;
		orderRaw.SetStatusID(status.GetID());
		std::string filterorRaw = orderRaw.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterList.push_back(filterorRaw);
		filterList.push_back(empIDListFilter);
		filterorRaw = reportFormBL->GetOrmasDal().ConcatenateFilters(filterList);
		std::vector<BusinessLayer::OrderRawView> vecOrdRaw = reportFormBL->GetAllDataForClass<BusinessLayer::OrderRawView>(errorMessage, filterorRaw);
		

		// select receipt raw for return status
		filterListReturn.clear();
		BusinessLayer::OrderRaw orderRawReturn;
		orderRawReturn.SetStatusID(statusReturn.GetID());
		std::string filterorRawReturn = orderRawReturn.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterListReturn.push_back(filterorRawReturn);
		filterListReturn.push_back(empIDListFilter);
		filterorRawReturn = reportFormBL->GetOrmasDal().ConcatenateFilters(filterListReturn);
		std::vector<BusinessLayer::OrderRawView> vecOrdRawReturn = reportFormBL->GetAllDataForClass<BusinessLayer::OrderRawView>(errorMessage, filterorRawReturn);

		// select receipt raw for warehouse
		filterList.clear();
		BusinessLayer::WriteOffRaw writeOffRaw;
		writeOffRaw.SetStatusID(status.GetID());
		std::string filterwoRaw = writeOffRaw.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterList.push_back(filterwoRaw);
		filterList.push_back(empIDListFilter);
		filterwoRaw = reportFormBL->GetOrmasDal().ConcatenateFilters(filterList);
		std::vector<BusinessLayer::WriteOffRawView> vecWOffRaw = reportFormBL->GetAllDataForClass<BusinessLayer::WriteOffRawView>(errorMessage, filterwoRaw);


		// select receipt raw for return status
		filterListReturn.clear();
		BusinessLayer::WriteOffRaw writeOffRawReturn;
		writeOffRawReturn.SetStatusID(statusReturn.GetID());
		std::string filterworRawReturn = writeOffRawReturn.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterListReturn.push_back(filterworRawReturn);
		filterListReturn.push_back(empIDListFilter);
		filterworRawReturn = reportFormBL->GetOrmasDal().ConcatenateFilters(filterListReturn);
		std::vector<BusinessLayer::WriteOffRawView> vecWOffRawReturn = reportFormBL->GetAllDataForClass<BusinessLayer::WriteOffRawView>(errorMessage, filterworRawReturn);
		
		std::map<int, double> consumeCount;
		std::map<int, double> consumeSum;
		std::map<int, double> orderCount;
		std::map<int, double> orderSum;
		std::map<int, double> writeOffCount;
		std::map<int, double> writeOffSum;

		std::map<int, double> consumeCountReturn;
		std::map<int, double> consumeSumReturn;
		std::map<int, double> orderCountReturn;
		std::map<int, double> orderSumReturn;
		std::map<int, double> writeOffCountReturn;
		std::map<int, double> writeOffSumReturn;
		

		if (vecConRaw.size() > 0)
		{
			BusinessLayer::ConsumeRawList consumeRawList;
			std::string consumeRawListFilter;
			std::vector<BusinessLayer::ConsumeRawListView> vecConRawList;

			for each (auto item in vecConRaw)
			{
				consumeRawList.Clear();
				consumeRawListFilter.clear();
				consumeRawList.SetConsumeRawID(item.GetID());
				consumeRawListFilter = consumeRawList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecConRawList.clear();
				vecConRawList = reportFormBL->GetAllDataForClass<BusinessLayer::ConsumeRawListView>(errorMessage, consumeRawListFilter);
				if (vecConRawList.size() > 0)
				{
					for each (auto listItem in vecConRawList)
					{
						if (consumeCount.find(listItem.GetProductID()) != consumeCount.end())
						{
							consumeCount.find(listItem.GetProductID())->second = consumeCount.find(listItem.GetProductID())->second + listItem.GetCount();
							consumeSum.find(listItem.GetProductID())->second = consumeSum.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							consumeCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							consumeSum.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecConRawReturn.size() > 0)
		{
			BusinessLayer::ConsumeRawList consumeRawList;
			std::string consumeRawListFilter;
			std::vector<BusinessLayer::ConsumeRawListView> vecConRawList;

			for each (auto item in vecConRawReturn)
			{
				consumeRawList.Clear();
				consumeRawListFilter.clear();
				consumeRawList.SetConsumeRawID(item.GetID());
				consumeRawListFilter = consumeRawList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecConRawList.clear();
				vecConRawList = reportFormBL->GetAllDataForClass<BusinessLayer::ConsumeRawListView>(errorMessage, consumeRawListFilter);
				if (vecConRawList.size() > 0)
				{
					for each (auto listItem in vecConRawList)
					{
						if (consumeCountReturn.find(listItem.GetProductID()) != consumeCountReturn.end())
						{
							consumeCountReturn.find(listItem.GetProductID())->second = consumeCountReturn.find(listItem.GetProductID())->second + listItem.GetCount();
							consumeSumReturn.find(listItem.GetProductID())->second = consumeSumReturn.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							consumeCountReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							consumeSumReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecOrdRaw.size() > 0)
		{
			BusinessLayer::OrderRawList orderRawList;
			std::string orderRawListFilter;
			std::vector<BusinessLayer::OrderRawListView> vecOrdRawList;

			for each (auto item in vecOrdRaw)
			{
				orderRawList.Clear();
				orderRawListFilter.clear();
				orderRawList.SetOrderRawID(item.GetID());
				orderRawListFilter = orderRawList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecOrdRawList.clear();
				vecOrdRawList = reportFormBL->GetAllDataForClass<BusinessLayer::OrderRawListView>(errorMessage, orderRawListFilter);
				if (vecOrdRawList.size() > 0)
				{
					for each (auto listItem in vecOrdRawList)
					{
						if (orderCount.find(listItem.GetProductID()) != orderCount.end())
						{
							orderCount.find(listItem.GetProductID())->second = orderCount.find(listItem.GetProductID())->second + listItem.GetCount();
							orderSum.find(listItem.GetProductID())->second = orderSum.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							orderCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							orderSum.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecOrdRawReturn.size() > 0)
		{
			BusinessLayer::OrderRawList orderRawList;
			std::string orderRawListFilter;
			std::vector<BusinessLayer::OrderRawListView> vecOrdRawList;

			for each (auto item in vecOrdRawReturn)
			{
				orderRawList.Clear();
				orderRawListFilter.clear();
				orderRawList.SetOrderRawID(item.GetID());
				orderRawListFilter = orderRawList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecOrdRawList.clear();
				vecOrdRawList = reportFormBL->GetAllDataForClass<BusinessLayer::OrderRawListView>(errorMessage, orderRawListFilter);
				if (vecOrdRawList.size() > 0)
				{
					for each (auto listItem in vecOrdRawList)
					{
						if (orderCountReturn.find(listItem.GetProductID()) != orderCountReturn.end())
						{
							orderCountReturn.find(listItem.GetProductID())->second = orderCountReturn.find(listItem.GetProductID())->second + listItem.GetCount();
							orderSumReturn.find(listItem.GetProductID())->second = orderSumReturn.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							orderCountReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							orderSumReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}

		if (vecWOffRaw.size() > 0)
		{
			BusinessLayer::WriteOffRawList writeOffList;
			std::string writeOffRawListFilter;
			std::vector<BusinessLayer::WriteOffRawListView> vecWOffRawList;

			for each (auto item in vecWOffRaw)
			{
				writeOffList.Clear();
				writeOffRawListFilter.clear();
				writeOffList.SetWriteOffRawID(item.GetID());
				writeOffRawListFilter = writeOffList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecWOffRawList.clear();
				vecWOffRawList = reportFormBL->GetAllDataForClass<BusinessLayer::WriteOffRawListView>(errorMessage, writeOffRawListFilter);
				if (vecWOffRawList.size() > 0)
				{
					for each (auto listItem in vecWOffRawList)
					{
						if (writeOffCount.find(listItem.GetProductID()) != writeOffCount.end())
						{
							writeOffCount.find(listItem.GetProductID())->second = writeOffCount.find(listItem.GetProductID())->second + listItem.GetCount();
							writeOffSum.find(listItem.GetProductID())->second = writeOffSum.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							writeOffCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							writeOffSum.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecWOffRawReturn.size() > 0)
		{
			BusinessLayer::WriteOffRawList writeOffList;
			std::string writeOffRawListFilter;
			std::vector<BusinessLayer::WriteOffRawListView> vecWOffRawList;

			for each (auto item in vecWOffRawReturn)
			{
				writeOffList.Clear();
				writeOffRawListFilter.clear();
				writeOffList.SetWriteOffRawID(item.GetID());
				writeOffRawListFilter = writeOffList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecWOffRawList.clear();
				vecWOffRawList = reportFormBL->GetAllDataForClass<BusinessLayer::WriteOffRawListView>(errorMessage, writeOffRawListFilter);
				if (vecWOffRawList.size() > 0)
				{
					for each (auto listItem in vecWOffRawList)
					{
						if (writeOffCountReturn.find(listItem.GetProductID()) != writeOffCountReturn.end())
						{
							writeOffCountReturn.find(listItem.GetProductID())->second = writeOffCountReturn.find(listItem.GetProductID())->second + listItem.GetCount();
							writeOffSumReturn.find(listItem.GetProductID())->second = writeOffSumReturn.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							writeOffCountReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							writeOffSumReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		

		QStringList header;
		header << QObject::tr("Product name") << QObject::tr("Start count saldo ") << QObject::tr("Start sum saldo") 
			<< QObject::tr("In count") << QObject::tr("In sum") << QObject::tr("Out count") << QObject::tr("Out sum")
			<< QObject::tr("End count saldo") << QObject::tr("End sum saldo") << QObject::tr("Product ID")
			<< QObject::tr("Warehouse ID") << QObject::tr("Start date") << QObject::tr("End date") << QObject::tr("Prev month end date");
		QStandardItemModel *itemModel = new QStandardItemModel(this);
		itemModel->setHorizontalHeaderLabels(header);
		tableView->setModel(itemModel);
		tableView->hideColumn(9);
		tableView->hideColumn(10);
		tableView->hideColumn(11);
		tableView->hideColumn(12);
		tableView->hideColumn(13);

		QList<QStandardItem*> wtosItem;
		BusinessLayer::Product product;

		for each (auto mapItem in stockCount)
		{
			product.Clear();
			if (!product.GetProductByID(reportFormBL->GetOrmasDal(), mapItem.first, errorMessage))
				continue;
			wtosItem << new QStandardItem(product.GetName().c_str());
			if (stockHistoryCount.find(mapItem.first) != stockHistoryCount.end())
			{
				wtosItem << new QStandardItem(QString::number(stockHistoryCount.find(mapItem.first)->second, 'f', 3))
					<< new QStandardItem(QString::number(stockHistorySum.find(mapItem.first)->second, 'f', 3));
			}
			else
			{
				wtosItem << new QStandardItem("0")
					<< new QStandardItem("0");
			}
			if (orderCount.find(mapItem.first) != orderCount.end() || consumeCountReturn.find(mapItem.first) != consumeCountReturn.end()
				|| writeOffCountReturn.find(mapItem.first) != writeOffCountReturn.end())
			{
				double tempCount = 0;
				double tempSum = 0;
				if (orderCount.find(mapItem.first) != orderCount.end())
				{
					tempCount += orderCount.find(mapItem.first)->second;
					tempSum += orderSum.find(mapItem.first)->second;
				}
				if (consumeCountReturn.find(mapItem.first) != consumeCountReturn.end())
				{
					tempCount += consumeCountReturn.find(mapItem.first)->second;
					tempSum += consumeSumReturn.find(mapItem.first)->second;
				}
				if (writeOffCountReturn.find(mapItem.first) != writeOffCountReturn.end())
				{
					tempCount += writeOffCountReturn.find(mapItem.first)->second;
					tempSum += writeOffCountReturn.find(mapItem.first)->second;
				}
				wtosItem << new QStandardItem(QString::number(tempCount, 'f', 3))
					<< new QStandardItem(QString::number(tempSum, 'f', 3));
			}
			else
			{
				wtosItem << new QStandardItem("0")
					<< new QStandardItem("0");
			}
			if (consumeCount.find(mapItem.first) != consumeCount.end() || orderCountReturn.find(mapItem.first) != orderCountReturn.end()
				|| writeOffCount.find(mapItem.first) != writeOffCount.end())
			{
				double tempCount = 0;
				double tempSum = 0;
				if (consumeCount.find(mapItem.first) != consumeCount.end())
				{
					tempCount += consumeCount.find(mapItem.first)->second;
					tempSum += consumeSum.find(mapItem.first)->second;
				}
				if (orderCountReturn.find(mapItem.first) != orderCountReturn.end())
				{
					tempCount += orderCountReturn.find(mapItem.first)->second;
					tempSum += orderSumReturn.find(mapItem.first)->second;
				}
				if (writeOffCount.find(mapItem.first) != writeOffCount.end())
				{
					tempCount += writeOffCount.find(mapItem.first)->second;
					tempSum += writeOffSum.find(mapItem.first)->second;
				}
				wtosItem << new QStandardItem(QString::number(tempCount, 'f', 3))
					<< new QStandardItem(QString::number(tempSum, 'f', 3));
			}
			else
			{
				wtosItem << new QStandardItem("0")
					<< new QStandardItem("0");
			}
			if (stockCount.find(mapItem.first) != stockCount.end())
			{
				wtosItem << new QStandardItem(QString::number(stockCount.find(mapItem.first)->second, 'f', 3))
					<< new QStandardItem(QString::number(stockSum.find(mapItem.first)->second, 'f', 3));
			}
			else
			{
				wtosItem << new QStandardItem("0")
					<< new QStandardItem("0");
			}
			wtosItem << new QStandardItem(QString::number(mapItem.first))
				<< new QStandardItem(QString::number(warehouse.GetID()))
				<< new QStandardItem(fromDate.c_str())
				<< new QStandardItem(tillDate.c_str())
				<< new QStandardItem(prevMonthEndDate.c_str());
			itemModel = (QStandardItemModel *)this->tableView->model();
			itemModel->appendRow(wtosItem);
			wtosItem.clear();
		}
	}
	if (warehouse.GetWarehouseTypeID() == warehouseTypeMap.find("PRODUCT")->second)
	{
		//select consume raw from warehouse
		std::vector<int> employeeIDList;
		BusinessLayer::Employee employee;
		BusinessLayer::WarehouseEmployeeRelation weRelation;
		employeeIDList = weRelation.GetEmployeeIDListByWarehouseID(reportFormBL->GetOrmasDal(), warehouse.GetID());
		std::string empIDListFilter = employee.GenerateINFilterForEmployee(reportFormBL->GetOrmasDal(), employeeIDList);

		std::vector<int> userIDList;
		BusinessLayer::User user;
		BusinessLayer::WarehouseEmployeeRelation wuRelation;
		userIDList = wuRelation.GetEmployeeIDListByWarehouseID(reportFormBL->GetOrmasDal(), warehouse.GetID());
		std::string userIDListFilter = user.GenerateINFilter(reportFormBL->GetOrmasDal(), employeeIDList);
		
		BusinessLayer::ReceiptProduct receiptProduct;
		receiptProduct.SetStatusID(status.GetID());
		std::string filterrcProduct = receiptProduct.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		std::vector<std::string> filterList;
		filterList.push_back(filterrcProduct);
		filterList.push_back(empIDListFilter);
		filterrcProduct = reportFormBL->GetOrmasDal().ConcatenateFilters(filterList);
		std::vector<BusinessLayer::ReceiptProductView> vecRecProd = reportFormBL->GetAllDataForClass<BusinessLayer::ReceiptProductView>(errorMessage, filterrcProduct);


		//Returned products for warehouse
		BusinessLayer::ReceiptProduct receiptProductReturn;
		receiptProductReturn.SetStatusID(statusReturn.GetID());
		std::string filterrcProductReturn = receiptProductReturn.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		std::vector<std::string> filterListReturn;
		filterListReturn.push_back(filterrcProductReturn);
		filterListReturn.push_back(empIDListFilter);
		filterrcProductReturn = reportFormBL->GetOrmasDal().ConcatenateFilters(filterListReturn);
		std::vector<BusinessLayer::ReceiptProductView> vecRecProdReturn = reportFormBL->GetAllDataForClass<BusinessLayer::ReceiptProductView>(errorMessage, filterrcProductReturn);


		// select consume products for warehouse
		filterList.clear();
		BusinessLayer::ConsumeProduct consumeProduct;
		consumeProduct.SetStatusID(status.GetID());
		std::string filterpProduct= consumeProduct.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterList.push_back(filterpProduct);
		filterList.push_back(empIDListFilter);
		filterpProduct = reportFormBL->GetOrmasDal().ConcatenateFilters(filterList);
		std::vector<BusinessLayer::ConsumeProductView> vecConProd = reportFormBL->GetAllDataForClass<BusinessLayer::ConsumeProductView>(errorMessage, filterpProduct);


		// select consume products for return status
		filterListReturn.clear();
		BusinessLayer::ConsumeProduct consumeProductReturn;
		consumeProductReturn.SetStatusID(statusReturn.GetID());
		std::string filterpProductReturn = consumeProductReturn.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterListReturn.push_back(filterpProductReturn);
		filterListReturn.push_back(empIDListFilter);
		filterpProductReturn = reportFormBL->GetOrmasDal().ConcatenateFilters(filterListReturn);
		std::vector<BusinessLayer::ConsumeProductView> vecConProdReturn = reportFormBL->GetAllDataForClass<BusinessLayer::ConsumeProductView>(errorMessage, filterpProductReturn);

		// select write-off products for warehouse
		filterList.clear();
		BusinessLayer::WriteOff writeOff;
		writeOff.SetStatusID(status.GetID());
		std::string filterwo = writeOff.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterList.push_back(filterwo);
		filterList.push_back(empIDListFilter);
		filterwo = reportFormBL->GetOrmasDal().ConcatenateFilters(filterList);
		std::vector<BusinessLayer::WriteOffView> vecWOff = reportFormBL->GetAllDataForClass<BusinessLayer::WriteOffView>(errorMessage, filterwo);


		// select write-off products for return status
		filterListReturn.clear();
		BusinessLayer::WriteOff writeOffReturn;
		writeOffReturn.SetStatusID(statusReturn.GetID());
		std::string filterworReturn = writeOffReturn.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterListReturn.push_back(filterworReturn);
		filterListReturn.push_back(empIDListFilter);
		filterworReturn = reportFormBL->GetOrmasDal().ConcatenateFilters(filterListReturn);
		std::vector<BusinessLayer::WriteOffView> vecWOffReturn = reportFormBL->GetAllDataForClass<BusinessLayer::WriteOffView>(errorMessage, filterworReturn);

		// select return products for warehouse
		filterList.clear();
		BusinessLayer::Return ret;
		ret.SetStatusID(status.GetID());
		std::string filterRet = ret.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterList.push_back(filterRet);
		filterList.push_back(empIDListFilter);
		filterRet = reportFormBL->GetOrmasDal().ConcatenateFilters(filterList);
		std::vector<BusinessLayer::ReturnView> vecRet = reportFormBL->GetAllDataForClass<BusinessLayer::ReturnView>(errorMessage, filterRet);


		// select return products for return status
		filterListReturn.clear();
		BusinessLayer::Return retReturn;
		retReturn.SetStatusID(statusReturn.GetID());
		std::string filterRetReturn = retReturn.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterListReturn.push_back(filterRetReturn);
		filterListReturn.push_back(empIDListFilter);
		filterRetReturn = reportFormBL->GetOrmasDal().ConcatenateFilters(filterListReturn);
		std::vector<BusinessLayer::ReturnView> vecRetReturn = reportFormBL->GetAllDataForClass<BusinessLayer::ReturnView>(errorMessage, filterworReturn);

		// select stock transfers for warehouse
		filterList.clear();
		BusinessLayer::StockTransfer sInTransfer;
		sInTransfer.SetStatusID(status.GetID());
		std::string filterInStockTra = sInTransfer.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterList.push_back(filterInStockTra);
		filterList.push_back(empIDListFilter);
		filterInStockTra = reportFormBL->GetOrmasDal().ConcatenateFilters(filterList);
		std::vector<BusinessLayer::StockTransferView> vecStockInTra = reportFormBL->GetAllDataForClass<BusinessLayer::StockTransferView>(errorMessage, filterInStockTra);


		// select stock transfers for return status
		filterListReturn.clear();
		BusinessLayer::StockTransfer sInTransferReturn;
		sInTransferReturn.SetStatusID(statusReturn.GetID());
		std::string filterInStockTraReturn = sInTransferReturn.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterListReturn.push_back(filterInStockTraReturn);
		filterListReturn.push_back(empIDListFilter);
		filterInStockTraReturn = reportFormBL->GetOrmasDal().ConcatenateFilters(filterListReturn);
		std::vector<BusinessLayer::StockTransferView> vecStockInTraReturn = reportFormBL->GetAllDataForClass<BusinessLayer::StockTransferView>(errorMessage, filterInStockTraReturn);

		// select stock transfers for warehouse
		filterList.clear();
		BusinessLayer::StockTransfer sOutTransfer;
		sOutTransfer.SetStatusID(status.GetID());
		std::string filterOutStockTra = sOutTransfer.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterList.push_back(filterOutStockTra);
		filterList.push_back(userIDListFilter);
		filterOutStockTra = reportFormBL->GetOrmasDal().ConcatenateFilters(filterList);
		std::vector<BusinessLayer::StockTransferView> vecStockOutTra = reportFormBL->GetAllDataForClass<BusinessLayer::StockTransferView>(errorMessage, filterOutStockTra);


		// select stock transfers for return status
		filterListReturn.clear();
		BusinessLayer::StockTransfer sOutTransferReturn;
		sOutTransferReturn.SetStatusID(statusReturn.GetID());
		std::string filterOutStockTraReturn = sOutTransferReturn.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterListReturn.push_back(filterOutStockTraReturn);
		filterListReturn.push_back(userIDListFilter);
		filterOutStockTraReturn = reportFormBL->GetOrmasDal().ConcatenateFilters(filterListReturn);
		std::vector<BusinessLayer::StockTransferView> vecStockOutTraReturn = reportFormBL->GetAllDataForClass<BusinessLayer::StockTransferView>(errorMessage, filterOutStockTraReturn);

		std::map<int, double> receiptCount;
		std::map<int, double> receiptSum;
		std::map<int, double> consumeCount;
		std::map<int, double> consumeSum;
		std::map<int, double> returnCount;
		std::map<int, double> returnSum;
		std::map<int, double> writeOffCount;
		std::map<int, double> writeOffSum;
		std::map<int, double> stockInTraCount;
		std::map<int, double> stockOutTraCount;
		std::map<int, double> stockInTraSum;
		std::map<int, double> stockOutTraSum;

		std::map<int, double> receiptCountReturn;
		std::map<int, double> receiptSumReturn;
		std::map<int, double> consumeCountReturn;
		std::map<int, double> consumeSumReturn;
		std::map<int, double> returnCountReturn;
		std::map<int, double> returnSumReturn;
		std::map<int, double> writeOffCountReturn;
		std::map<int, double> writeOffSumReturn;
		std::map<int, double> stockInTraCountReturn;
		std::map<int, double> stockInTraSumReturn;
		std::map<int, double> stockOutTraCountReturn;
		std::map<int, double> stockOutTraSumReturn;


		if (vecRecProd.size() > 0)
		{
			BusinessLayer::ReceiptProductList receiptProductList;
			std::string receiptProductListFilter;
			std::vector<BusinessLayer::ReceiptProductListView> vecRcpProdList;

			for each (auto item in vecRecProd)
			{
				receiptProductList.Clear();
				receiptProductListFilter.clear();
				receiptProductList.SetReceiptProductID(item.GetID());
				receiptProductListFilter = receiptProductList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecRcpProdList.clear();
				vecRcpProdList = reportFormBL->GetAllDataForClass<BusinessLayer::ReceiptProductListView>(errorMessage, receiptProductListFilter);
				if (vecRcpProdList.size() > 0)
				{
					for each (auto listItem in vecRcpProdList)
					{
						if (receiptCount.find(listItem.GetProductID()) != receiptCount.end())
						{
							receiptCount.find(listItem.GetProductID())->second = receiptCount.find(listItem.GetProductID())->second + listItem.GetCount();
							receiptSum.find(listItem.GetProductID())->second = receiptSum.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							receiptCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							receiptSum.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecRecProdReturn.size() > 0)
		{
			BusinessLayer::ReceiptProductList receiptProductList;
			std::string receiptProductListFilter;
			std::vector<BusinessLayer::ReceiptProductListView> vecRcpProdList;

			for each (auto item in vecRecProdReturn)
			{
				receiptProductList.Clear();
				receiptProductListFilter.clear();
				receiptProductList.SetReceiptProductID(item.GetID());
				receiptProductListFilter = receiptProductList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecRcpProdList.clear();
				vecRcpProdList = reportFormBL->GetAllDataForClass<BusinessLayer::ReceiptProductListView>(errorMessage, receiptProductListFilter);
				if (vecRcpProdList.size() > 0)
				{
					for each (auto listItem in vecRcpProdList)
					{
						if (receiptCountReturn.find(listItem.GetProductID()) != receiptCountReturn.end())
						{
							receiptCountReturn.find(listItem.GetProductID())->second = receiptCountReturn.find(listItem.GetProductID())->second + listItem.GetCount();
							receiptSumReturn.find(listItem.GetProductID())->second = receiptSumReturn.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							receiptCountReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							receiptSumReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecConProd.size() > 0)
		{
			BusinessLayer::ConsumeProductList consumeProductList;
			std::string condumeProductListFilter;
			std::vector<BusinessLayer::ConsumeProductListView> vecConProdList;

			for each (auto item in vecConProd)
			{
				consumeProductList.Clear();
				condumeProductListFilter.clear();
				consumeProductList.SetConsumeProductID(item.GetID());
				condumeProductListFilter = consumeProductList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecConProdList.clear();
				vecConProdList = reportFormBL->GetAllDataForClass<BusinessLayer::ConsumeProductListView>(errorMessage, condumeProductListFilter);
				if (vecConProdList.size() > 0)
				{
					for each (auto listItem in vecConProdList)
					{
						if (consumeCount.find(listItem.GetProductID()) != consumeCount.end())
						{
							consumeCount.find(listItem.GetProductID())->second = consumeCount.find(listItem.GetProductID())->second + listItem.GetCount();
							consumeSum.find(listItem.GetProductID())->second = consumeSum.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							consumeCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							consumeSum.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecConProdReturn.size() > 0)
		{
			BusinessLayer::ConsumeProductList consumeProductList;
			std::string condumeProductListFilter;
			std::vector<BusinessLayer::ConsumeProductListView> vecConProdList;

			for each (auto item in vecConProdReturn)
			{
				consumeProductList.Clear();
				condumeProductListFilter.clear();
				consumeProductList.SetConsumeProductID(item.GetID());
				condumeProductListFilter = consumeProductList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecConProdList.clear();
				vecConProdList = reportFormBL->GetAllDataForClass<BusinessLayer::ConsumeProductListView>(errorMessage, condumeProductListFilter);
				if (vecConProdList.size() > 0)
				{
					for each (auto listItem in vecConProdList)
					{
						if (consumeCountReturn.find(listItem.GetProductID()) != consumeCountReturn.end())
						{
							consumeCountReturn.find(listItem.GetProductID())->second = consumeCountReturn.find(listItem.GetProductID())->second + listItem.GetCount();
							consumeSumReturn.find(listItem.GetProductID())->second = consumeSumReturn.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							consumeCountReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							consumeSumReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}

		if (vecWOff.size() > 0)
		{
			BusinessLayer::WriteOffList writeOffList;
			std::string writeOffListFilter;
			std::vector<BusinessLayer::WriteOffListView> vecWOffList;

			for each (auto item in vecWOff)
			{
				writeOffList.Clear();
				writeOffListFilter.clear();
				writeOffList.SetWriteOffID(item.GetID());
				writeOffListFilter = writeOffList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecWOffList.clear();
				vecWOffList = reportFormBL->GetAllDataForClass<BusinessLayer::WriteOffListView>(errorMessage, writeOffListFilter);
				if (vecWOffList.size() > 0)
				{
					for each (auto listItem in vecWOffList)
					{
						if (writeOffCount.find(listItem.GetProductID()) != writeOffCount.end())
						{
							writeOffCount.find(listItem.GetProductID())->second = writeOffCount.find(listItem.GetProductID())->second + listItem.GetCount();
							writeOffSum.find(listItem.GetProductID())->second = writeOffSum.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							writeOffCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							writeOffSum.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecWOffReturn.size() > 0)
		{
			BusinessLayer::WriteOffList writeOffList;
			std::string writeOffListFilter;
			std::vector<BusinessLayer::WriteOffListView> vecWOffList;

			for each (auto item in vecWOffReturn)
			{
				writeOffList.Clear();
				writeOffListFilter.clear();
				writeOffList.SetWriteOffID(item.GetID());
				writeOffListFilter = writeOffList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecWOffList.clear();
				vecWOffList = reportFormBL->GetAllDataForClass<BusinessLayer::WriteOffListView>(errorMessage, writeOffListFilter);
				if (vecWOffList.size() > 0)
				{
					for each (auto listItem in vecWOffList)
					{
						if (writeOffCountReturn.find(listItem.GetProductID()) != writeOffCountReturn.end())
						{
							writeOffCountReturn.find(listItem.GetProductID())->second = writeOffCountReturn.find(listItem.GetProductID())->second + listItem.GetCount();
							writeOffSumReturn.find(listItem.GetProductID())->second = writeOffSumReturn.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							writeOffCountReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							writeOffSumReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}

		if (vecRet.size() > 0)
		{
			BusinessLayer::ReturnList returnList;
			std::string returnListFilter;
			std::vector<BusinessLayer::ReturnListView> vecReturnList;

			for each (auto item in vecRet)
			{
				returnList.Clear();
				returnListFilter.clear();
				returnList.SetReturnID(item.GetID());
				returnListFilter = returnList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecReturnList.clear();
				vecReturnList = reportFormBL->GetAllDataForClass<BusinessLayer::ReturnListView>(errorMessage, returnListFilter);
				if (vecReturnList.size() > 0)
				{
					for each (auto listItem in vecReturnList)
					{
						if (returnCount.find(listItem.GetProductID()) != returnCount.end())
						{
							returnCount.find(listItem.GetProductID())->second = returnCount.find(listItem.GetProductID())->second + listItem.GetCount();
							returnSum.find(listItem.GetProductID())->second = returnSum.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							returnCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							returnSum.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecRetReturn.size() > 0)
		{
			BusinessLayer::ReturnList returnList;
			std::string returnListFilter;
			std::vector<BusinessLayer::ReturnListView> vecReturnList;

			for each (auto item in vecRetReturn)
			{
				returnList.Clear();
				returnListFilter.clear();
				returnList.SetReturnID(item.GetID());
				returnListFilter = returnList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecReturnList.clear();
				vecReturnList = reportFormBL->GetAllDataForClass<BusinessLayer::ReturnListView>(errorMessage, returnListFilter);
				if (vecReturnList.size() > 0)
				{
					for each (auto listItem in vecReturnList)
					{
						if (returnCountReturn.find(listItem.GetProductID()) != returnCountReturn.end())
						{
							returnCountReturn.find(listItem.GetProductID())->second = returnCountReturn.find(listItem.GetProductID())->second + listItem.GetCount();
							returnSumReturn.find(listItem.GetProductID())->second = returnSumReturn.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							returnCountReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							returnSumReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}

		if (vecStockInTra.size() > 0)
		{
			BusinessLayer::StockTransferList stTraList;
			std::string stTraListFilter;
			std::vector<BusinessLayer::StockTransferListView> vecStTraList;

			for each (auto item in vecStockInTra)
			{
				stTraList.Clear();
				stTraListFilter.clear();
				stTraList.SetStockTransferID(item.GetID());
				stTraListFilter = stTraList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecStTraList.clear();
				vecStTraList = reportFormBL->GetAllDataForClass<BusinessLayer::StockTransferListView>(errorMessage, stTraListFilter);
				if (vecStTraList.size() > 0)
				{
					for each (auto listItem in vecStTraList)
					{
						if (stockInTraCount.find(listItem.GetProductID()) != stockInTraCount.end())
						{
							stockInTraCount.find(listItem.GetProductID())->second = stockInTraCount.find(listItem.GetProductID())->second + listItem.GetCount();
							stockInTraSum.find(listItem.GetProductID())->second = stockInTraSum.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							stockInTraCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							stockInTraSum.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecStockInTraReturn.size() > 0)
		{
			BusinessLayer::StockTransferList stTraListReturn;
			std::string stTraListFilterReturn;
			std::vector<BusinessLayer::StockTransferListView> vecStTraListReturn;

			for each (auto item in vecStockInTraReturn)
			{
				stTraListReturn.Clear();
				stTraListFilterReturn.clear();
				stTraListReturn.SetStockTransferID(item.GetID());
				stTraListFilterReturn = stTraListReturn.GenerateFilter(reportFormBL->GetOrmasDal());
				vecStTraListReturn.clear();
				vecStTraListReturn = reportFormBL->GetAllDataForClass<BusinessLayer::StockTransferListView>(errorMessage, stTraListFilterReturn);
				if (vecStTraListReturn.size() > 0)
				{
					for each (auto listItem in vecStTraListReturn)
					{
						if (stockInTraCountReturn.find(listItem.GetProductID()) != stockInTraCountReturn.end())
						{
							stockInTraCountReturn.find(listItem.GetProductID())->second = stockInTraCountReturn.find(listItem.GetProductID())->second + listItem.GetCount();
							stockInTraSumReturn.find(listItem.GetProductID())->second = stockInTraSumReturn.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							stockInTraCountReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							stockInTraSumReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}

		if (vecStockOutTra.size() > 0)
		{
			BusinessLayer::StockTransferList stTraList;
			std::string stTraListFilter;
			std::vector<BusinessLayer::StockTransferListView> vecStTraList;

			for each (auto item in vecStockOutTra)
			{
				stTraList.Clear();
				stTraListFilter.clear();
				stTraList.SetStockTransferID(item.GetID());
				stTraListFilter = stTraList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecStTraList.clear();
				vecStTraList = reportFormBL->GetAllDataForClass<BusinessLayer::StockTransferListView>(errorMessage, stTraListFilter);
				if (vecStTraList.size() > 0)
				{
					for each (auto listItem in vecStTraList)
					{
						if (stockOutTraCount.find(listItem.GetProductID()) != stockOutTraCount.end())
						{
							stockOutTraCount.find(listItem.GetProductID())->second = stockOutTraCount.find(listItem.GetProductID())->second + listItem.GetCount();
							stockOutTraSum.find(listItem.GetProductID())->second = stockOutTraSum.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							stockOutTraCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							stockOutTraSum.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecStockOutTraReturn.size() > 0)
		{
			BusinessLayer::StockTransferList stTraListReturn;
			std::string stTraListFilterReturn;
			std::vector<BusinessLayer::StockTransferListView> vecStTraListReturn;

			for each (auto item in vecStockOutTraReturn)
			{
				stTraListReturn.Clear();
				stTraListFilterReturn.clear();
				stTraListReturn.SetStockTransferID(item.GetID());
				stTraListFilterReturn = stTraListReturn.GenerateFilter(reportFormBL->GetOrmasDal());
				vecStTraListReturn.clear();
				vecStTraListReturn = reportFormBL->GetAllDataForClass<BusinessLayer::StockTransferListView>(errorMessage, stTraListFilterReturn);
				if (vecStTraListReturn.size() > 0)
				{
					for each (auto listItem in vecStTraListReturn)
					{
						if (stockOutTraCountReturn.find(listItem.GetProductID()) != stockOutTraCountReturn.end())
						{
							stockOutTraCountReturn.find(listItem.GetProductID())->second = stockOutTraCountReturn.find(listItem.GetProductID())->second + listItem.GetCount();
							stockOutTraSumReturn.find(listItem.GetProductID())->second = stockOutTraSumReturn.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							stockOutTraCountReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							stockOutTraSumReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}


		QStringList header;
		header << QObject::tr("Product name") << QObject::tr("Start count saldo ") << QObject::tr("Start sum saldo")
			<< QObject::tr("In count") << QObject::tr("In sum") << QObject::tr("Out count") << QObject::tr("Out sum")
			<< QObject::tr("End count saldo") << QObject::tr("End sum saldo") << QObject::tr("Product ID")
			<< QObject::tr("Warehouse ID")  
			<< QObject::tr("Start date") << QObject::tr("End date") << QObject::tr("Prev month end date");
		QStandardItemModel *itemModel = new QStandardItemModel(this);
		itemModel->setHorizontalHeaderLabels(header);
		tableView->setModel(itemModel);
		tableView->hideColumn(9);
		tableView->hideColumn(10);
		tableView->hideColumn(11);
		tableView->hideColumn(12);
		tableView->hideColumn(13);
		

		QList<QStandardItem*> wtosItem;
		BusinessLayer::Product product;

		for each (auto mapItem in stockCount)
		{
			product.Clear();
			if (!product.GetProductByID(reportFormBL->GetOrmasDal(), mapItem.first, errorMessage))
				continue;
			wtosItem << new QStandardItem(product.GetName().c_str());
			if (stockHistoryCount.find(mapItem.first) != stockHistoryCount.end())
			{
				wtosItem << new QStandardItem(QString::number(stockHistoryCount.find(mapItem.first)->second, 'f', 3))
					<< new QStandardItem(QString::number(stockHistorySum.find(mapItem.first)->second, 'f', 3));
			}
			else
			{
				wtosItem << new QStandardItem("0")
					<< new QStandardItem("0");
			}
			if (receiptCount.find(mapItem.first) != receiptCount.end() || consumeCountReturn.find(mapItem.first) != consumeCountReturn.end()
				|| writeOffCountReturn.find(mapItem.first) != writeOffCountReturn.end() || returnCount.find(mapItem.first) != returnCount.end()
				|| stockInTraCount.find(mapItem.first) != stockInTraCount.end()
				|| stockOutTraCountReturn.find(mapItem.first) != stockOutTraCountReturn.end())
			{
				double tempCount = 0;
				double tempSum = 0;
				if (receiptCount.find(mapItem.first) != receiptCount.end())
				{
					tempCount += receiptCount.find(mapItem.first)->second;
					tempSum += receiptSum.find(mapItem.first)->second;
				}
				if (returnCount.find(mapItem.first) != returnCount.end())
				{
					tempCount += returnCount.find(mapItem.first)->second;
					tempSum += returnSum.find(mapItem.first)->second;
				}
				if (consumeCountReturn.find(mapItem.first) != consumeCountReturn.end())
				{
					tempCount += consumeCountReturn.find(mapItem.first)->second;
					tempSum += consumeSumReturn.find(mapItem.first)->second;
				}
				if (writeOffCountReturn.find(mapItem.first) != writeOffCountReturn.end())
				{
					tempCount += writeOffCountReturn.find(mapItem.first)->second;
					tempSum += writeOffSumReturn.find(mapItem.first)->second;
				}
				if (stockInTraCount.find(mapItem.first) != stockInTraCount.end())
				{
					tempCount += stockInTraCount.find(mapItem.first)->second;
					tempSum += stockInTraSum.find(mapItem.first)->second;
				}
				if (stockOutTraCountReturn.find(mapItem.first) != stockOutTraCountReturn.end())
				{
					tempCount += stockOutTraCountReturn.find(mapItem.first)->second;
					tempSum += stockOutTraSumReturn.find(mapItem.first)->second;
				}
				wtosItem << new QStandardItem(QString::number(tempCount, 'f', 3))
					<< new QStandardItem(QString::number(tempSum, 'f', 3));
			}
			else
			{
				wtosItem << new QStandardItem("0")
					<< new QStandardItem("0");
			}
			if (consumeCount.find(mapItem.first) != consumeCount.end() || receiptCountReturn.find(mapItem.first) != receiptCountReturn.end()
				|| writeOffCount.find(mapItem.first) != writeOffCount.end() || returnCountReturn.find(mapItem.first) != returnCountReturn.end()
				|| stockInTraCountReturn.find(mapItem.first) != stockInTraCountReturn.end() 
				|| stockInTraCountReturn.find(mapItem.first) != stockInTraCountReturn.end())
			{
				double tempCount = 0;
				double tempSum = 0;
				if (consumeCount.find(mapItem.first) != consumeCount.end())
				{
					tempCount += consumeCount.find(mapItem.first)->second;
					tempSum += consumeSum.find(mapItem.first)->second;
				}
				if (receiptCountReturn.find(mapItem.first) != receiptCountReturn.end())
				{
					tempCount += receiptCountReturn.find(mapItem.first)->second;
					tempSum += receiptSumReturn.find(mapItem.first)->second;
				}
				if (returnCountReturn.find(mapItem.first) != returnCountReturn.end())
				{
					tempCount += returnCountReturn.find(mapItem.first)->second;
					tempSum += returnSumReturn.find(mapItem.first)->second;
				}
				if (writeOffCount.find(mapItem.first) != writeOffCount.end())
				{
					tempCount += writeOffCount.find(mapItem.first)->second;
					tempSum += writeOffSum.find(mapItem.first)->second;
				}
				if (stockInTraCountReturn.find(mapItem.first) != stockInTraCountReturn.end())
				{
					tempCount += stockInTraCountReturn.find(mapItem.first)->second;
					tempSum += stockInTraSumReturn.find(mapItem.first)->second;
				}
				if (stockOutTraCount.find(mapItem.first) != stockOutTraCount.end())
				{
					tempCount += stockOutTraCount.find(mapItem.first)->second;
					tempSum += stockOutTraSum.find(mapItem.first)->second;
				}
				wtosItem << new QStandardItem(QString::number(tempCount, 'f', 3))
					<< new QStandardItem(QString::number(tempSum, 'f', 3));
			}
			else
			{
				wtosItem << new QStandardItem("0")
					<< new QStandardItem("0");
			}
			if (stockCount.find(mapItem.first) != stockCount.end())
			{
				wtosItem << new QStandardItem(QString::number(stockCount.find(mapItem.first)->second, 'f', 3))
					<< new QStandardItem(QString::number(stockSum.find(mapItem.first)->second, 'f', 3));
			}
			else
			{
				wtosItem << new QStandardItem("0")
					<< new QStandardItem("0");
			}
			wtosItem << new QStandardItem(QString::number(mapItem.first))
				<< new QStandardItem(QString::number(warehouse.GetID()))
				<< new QStandardItem(fromDate.c_str())
				<< new QStandardItem(tillDate.c_str())
				<< new QStandardItem(prevMonthEndDate.c_str());
			itemModel = (QStandardItemModel *)this->tableView->model();
			itemModel->appendRow(wtosItem);
			wtosItem.clear();
		}
	}
	if (warehouse.GetWarehouseTypeID() == warehouseTypeMap.find("PRODUCTION")->second)
	{

		//select consume raw from warehouse
		std::vector<int> employeeIDList;
		BusinessLayer::Employee employee;
		BusinessLayer::WarehouseEmployeeRelation weRelation;
		employeeIDList = weRelation.GetEmployeeIDListByWarehouseID(reportFormBL->GetOrmasDal(), warehouse.GetID());
		std::string empIDListFilter = employee.GenerateINFilterForEmployee(reportFormBL->GetOrmasDal(), employeeIDList);

		std::vector<int> userIDList;
		BusinessLayer::User user;
		BusinessLayer::WarehouseEmployeeRelation wuRelation;
		userIDList = wuRelation.GetEmployeeIDListByWarehouseID(reportFormBL->GetOrmasDal(), warehouse.GetID());
		std::string userIDListFilter = user.GenerateINFilter(reportFormBL->GetOrmasDal(), employeeIDList);


		BusinessLayer::ConsumeRaw consumeRaw;
		consumeRaw.SetStatusID(status.GetID());
		std::string filterprRaw = consumeRaw.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		std::vector<std::string> filterPList;
		filterPList.push_back(filterprRaw);
		filterPList.push_back(userIDListFilter);
		filterprRaw = reportFormBL->GetOrmasDal().ConcatenateFilters(filterPList);
		std::vector<BusinessLayer::ConsumeRawView> vecConRaw = reportFormBL->GetAllDataForClass<BusinessLayer::ConsumeRawView>(errorMessage, filterprRaw);


		//Returned raws for warehouse
		BusinessLayer::ConsumeRaw consumeRawReturn;
		consumeRawReturn.SetStatusID(statusReturn.GetID());
		std::string filterprRawReturn = consumeRawReturn.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		std::vector<std::string> filterListPReturn;
		filterListPReturn.push_back(filterprRawReturn);
		filterListPReturn.push_back(userIDListFilter);
		filterprRawReturn = reportFormBL->GetOrmasDal().ConcatenateFilters(filterListPReturn);
		std::vector<BusinessLayer::ConsumeRawView> vecConRawReturn = reportFormBL->GetAllDataForClass<BusinessLayer::ConsumeRawView>(errorMessage, filterprRawReturn);


		BusinessLayer::ProductionConsumeRaw pConsumeRaw;
		pConsumeRaw.SetStatusID(status.GetID());
		std::string filterprPRaw = pConsumeRaw.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		std::vector<std::string> filterList;
		filterList.push_back(filterprPRaw);
		filterList.push_back(empIDListFilter);
		filterprRaw = reportFormBL->GetOrmasDal().ConcatenateFilters(filterList);
		std::vector<BusinessLayer::ProductionConsumeRawView> vecPConRaw = reportFormBL->GetAllDataForClass<BusinessLayer::ProductionConsumeRawView>(errorMessage, filterprRaw);


		//Returned raws for warehouse
		BusinessLayer::ProductionConsumeRaw pConsumeRawReturn;
		pConsumeRawReturn.SetStatusID(statusReturn.GetID());
		std::string filterpcRawReturn = pConsumeRawReturn.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		std::vector<std::string> filterListReturn;
		filterListReturn.push_back(filterpcRawReturn);
		filterListReturn.push_back(empIDListFilter);
		filterpcRawReturn = reportFormBL->GetOrmasDal().ConcatenateFilters(filterListReturn);
		std::vector<BusinessLayer::ProductionConsumeRawView> vecPConRawReturn = reportFormBL->GetAllDataForClass<BusinessLayer::ProductionConsumeRawView>(errorMessage, filterpcRawReturn);


		// select receipt raw for warehouse
		BusinessLayer::ReceiptProduct receiptProduct;
		receiptProduct.SetStatusID(status.GetID());
		std::string filterrcProduct = receiptProduct.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		std::vector<std::string> filterRcpList;
		filterRcpList.push_back(filterrcProduct);
		filterRcpList.push_back(userIDListFilter);
		filterrcProduct = reportFormBL->GetOrmasDal().ConcatenateFilters(filterRcpList);
		std::vector<BusinessLayer::ReceiptProductView> vecRecProd = reportFormBL->GetAllDataForClass<BusinessLayer::ReceiptProductView>(errorMessage, filterrcProduct);


		//Returned products for warehouse
		BusinessLayer::ReceiptProduct receiptProductReturn;
		receiptProductReturn.SetStatusID(statusReturn.GetID());
		std::string filterrcProductReturn = receiptProductReturn.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		std::vector<std::string> filterListRcpReturn;
		filterListRcpReturn.push_back(filterrcProductReturn);
		filterListRcpReturn.push_back(userIDListFilter);
		filterrcProductReturn = reportFormBL->GetOrmasDal().ConcatenateFilters(filterListRcpReturn);
		std::vector<BusinessLayer::ReceiptProductView> vecRecProdReturn = reportFormBL->GetAllDataForClass<BusinessLayer::ReceiptProductView>(errorMessage, filterrcProductReturn);


		std::map<int, double> consumeCount;
		std::map<int, double> consumeSum;
		std::map<int, double> pConsumeCount;
		std::map<int, double> pConsumeSum;
		std::map<int, double> receiptCount;
		std::map<int, double> receiptSum;

		std::map<int, double> consumeCountReturn;
		std::map<int, double> consumeSumReturn;
		std::map<int, double> pConsumeCountReturn;
		std::map<int, double> pConsumeSumReturn;
		std::map<int, double> receiptCountReturn;
		std::map<int, double> receiptSumReturn;


		if (vecConRaw.size() > 0)
		{
			BusinessLayer::ConsumeRawList consumeRawList;
			std::string consumeRawListFilter;
			std::vector<BusinessLayer::ConsumeRawListView> vecConRawList;

			for each (auto item in vecConRaw)
			{
				consumeRawList.Clear();
				consumeRawListFilter.clear();
				consumeRawList.SetConsumeRawID(item.GetID());
				consumeRawListFilter = consumeRawList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecConRawList.clear();
				vecConRawList = reportFormBL->GetAllDataForClass<BusinessLayer::ConsumeRawListView>(errorMessage, consumeRawListFilter);
				if (vecConRawList.size() > 0)
				{
					for each (auto listItem in vecConRawList)
					{
						if (consumeCount.find(listItem.GetProductID()) != consumeCount.end())
						{
							consumeCount.find(listItem.GetProductID())->second = consumeCount.find(listItem.GetProductID())->second + listItem.GetCount();
							consumeSum.find(listItem.GetProductID())->second = consumeSum.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							consumeCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							consumeSum.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecConRawReturn.size() > 0)
		{
			BusinessLayer::ConsumeRawList consumeRawList;
			std::string consumeRawListFilter;
			std::vector<BusinessLayer::ConsumeRawListView> vecConRawList;

			for each (auto item in vecConRawReturn)
			{
				consumeRawList.Clear();
				consumeRawListFilter.clear();
				consumeRawList.SetConsumeRawID(item.GetID());
				consumeRawListFilter = consumeRawList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecConRawList.clear();
				vecConRawList = reportFormBL->GetAllDataForClass<BusinessLayer::ConsumeRawListView>(errorMessage, consumeRawListFilter);
				if (vecConRawList.size() > 0)
				{
					for each (auto listItem in vecConRawList)
					{
						if (consumeCountReturn.find(listItem.GetProductID()) != consumeCountReturn.end())
						{
							consumeCountReturn.find(listItem.GetProductID())->second = consumeCountReturn.find(listItem.GetProductID())->second + listItem.GetCount();
							consumeSumReturn.find(listItem.GetProductID())->second = consumeSumReturn.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							consumeCountReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							consumeSumReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		
		if (vecPConRaw.size() > 0)
		{
			BusinessLayer::ProductionConsumeRawList consumeRawList;
			std::string consumeRawListFilter;
			std::vector<BusinessLayer::ProductionConsumeRawListView> vecConRawList;

			for each (auto item in vecPConRaw)
			{
				consumeRawList.Clear();
				consumeRawListFilter.clear();
				consumeRawList.SetProductionConsumeRawID(item.GetID());
				consumeRawListFilter = consumeRawList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecConRawList.clear();
				vecConRawList = reportFormBL->GetAllDataForClass<BusinessLayer::ProductionConsumeRawListView>(errorMessage, consumeRawListFilter);
				if (vecConRawList.size() > 0)
				{
					for each (auto listItem in vecConRawList)
					{
						if (pConsumeCount.find(listItem.GetProductID()) != pConsumeCount.end())
						{
							pConsumeCount.find(listItem.GetProductID())->second = pConsumeCount.find(listItem.GetProductID())->second + listItem.GetCount();
							pConsumeSum.find(listItem.GetProductID())->second = pConsumeSum.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							pConsumeCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							pConsumeSum.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecPConRawReturn.size() > 0)
		{
			BusinessLayer::ProductionConsumeRawList consumeRawList;
			std::string consumeRawListFilter;
			std::vector<BusinessLayer::ProductionConsumeRawListView> vecConRawList;

			for each (auto item in vecPConRawReturn)
			{
				consumeRawList.Clear();
				consumeRawListFilter.clear();
				consumeRawList.SetProductionConsumeRawID(item.GetID());
				consumeRawListFilter = consumeRawList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecConRawList.clear();
				vecConRawList = reportFormBL->GetAllDataForClass<BusinessLayer::ProductionConsumeRawListView>(errorMessage, consumeRawListFilter);
				if (vecConRawList.size() > 0)
				{
					for each (auto listItem in vecConRawList)
					{
						if (pConsumeCountReturn.find(listItem.GetProductID()) != pConsumeCountReturn.end())
						{
							pConsumeCountReturn.find(listItem.GetProductID())->second = pConsumeCountReturn.find(listItem.GetProductID())->second + listItem.GetCount();
							pConsumeSumReturn.find(listItem.GetProductID())->second = pConsumeSumReturn.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							pConsumeCountReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							pConsumeSumReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}

		if (vecRecProd.size() > 0)
		{
			BusinessLayer::ReceiptProductList receiptProductList;
			std::string receiptProductListFilter;
			std::vector<BusinessLayer::ReceiptProductListView> vecRcpProdList;

			for each (auto item in vecRecProd)
			{
				receiptProductList.Clear();
				receiptProductListFilter.clear();
				receiptProductList.SetReceiptProductID(item.GetID());
				receiptProductListFilter = receiptProductList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecRcpProdList.clear();
				vecRcpProdList = reportFormBL->GetAllDataForClass<BusinessLayer::ReceiptProductListView>(errorMessage, receiptProductListFilter);
				if (vecRcpProdList.size() > 0)
				{
					for each (auto listItem in vecRcpProdList)
					{
						if (receiptCount.find(listItem.GetProductID()) != receiptCount.end())
						{
							receiptCount.find(listItem.GetProductID())->second = receiptCount.find(listItem.GetProductID())->second + listItem.GetCount();
							receiptSum.find(listItem.GetProductID())->second = receiptSum.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							receiptCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							receiptSum.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecRecProdReturn.size() > 0)
		{
			BusinessLayer::ReceiptProductList receiptProductList;
			std::string receiptProductListFilter;
			std::vector<BusinessLayer::ReceiptProductListView> vecRcpProdList;

			for each (auto item in vecRecProdReturn)
			{
				receiptProductList.Clear();
				receiptProductListFilter.clear();
				receiptProductList.SetReceiptProductID(item.GetID());
				receiptProductListFilter = receiptProductList.GenerateFilter(reportFormBL->GetOrmasDal());
				vecRcpProdList.clear();
				vecRcpProdList = reportFormBL->GetAllDataForClass<BusinessLayer::ReceiptProductListView>(errorMessage, receiptProductListFilter);
				if (vecRcpProdList.size() > 0)
				{
					for each (auto listItem in vecRcpProdList)
					{
						if (receiptCountReturn.find(listItem.GetProductID()) != receiptCountReturn.end())
						{
							receiptCountReturn.find(listItem.GetProductID())->second = receiptCountReturn.find(listItem.GetProductID())->second + listItem.GetCount();
							receiptSumReturn.find(listItem.GetProductID())->second = receiptSumReturn.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							receiptCountReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							receiptSumReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}

		QStringList header;
		header << QObject::tr("Product name") << QObject::tr("Start count saldo ") << QObject::tr("Start sum saldo")
			<< QObject::tr("In count") << QObject::tr("In sum") << QObject::tr("Out count") << QObject::tr("Out sum")
			<< QObject::tr("End count saldo") << QObject::tr("End sum saldo") << QObject::tr("Product ID")
			<< QObject::tr("Warehouse ID") << QObject::tr("Start date") << QObject::tr("End date") << QObject::tr("Prev month end date");
		QStandardItemModel *itemModel = new QStandardItemModel(this);
		itemModel->setHorizontalHeaderLabels(header);
		tableView->setModel(itemModel);
		tableView->hideColumn(9);
		tableView->hideColumn(10);
		tableView->hideColumn(11);
		tableView->hideColumn(12);
		tableView->hideColumn(13);

		QList<QStandardItem*> wtosItem;
		BusinessLayer::Product product;

		for each (auto mapItem in stockCount)
		{
			product.Clear();
			if (!product.GetProductByID(reportFormBL->GetOrmasDal(), mapItem.first, errorMessage))
				continue;
			wtosItem << new QStandardItem(product.GetName().c_str());
			if (stockHistoryCount.find(mapItem.first) != stockHistoryCount.end())
			{
				wtosItem << new QStandardItem(QString::number(stockHistoryCount.find(mapItem.first)->second, 'f', 3))
					<< new QStandardItem(QString::number(stockHistorySum.find(mapItem.first)->second, 'f', 3));
			}
			else
			{
				wtosItem << new QStandardItem("0")
					<< new QStandardItem("0");
			}
			if (pConsumeCountReturn.find(mapItem.first) != pConsumeCountReturn.end() || consumeCount.find(mapItem.first) != consumeCount.end()
				|| receiptCount.find(mapItem.first) != receiptCount.end() || receiptCountReturn.find(mapItem.first) != receiptCountReturn.end())
			{
				double tempCount = 0;
				double tempSum = 0;
				if (pConsumeCountReturn.find(mapItem.first) != pConsumeCountReturn.end())
				{
					tempCount += pConsumeCountReturn.find(mapItem.first)->second;
					tempSum += pConsumeSumReturn.find(mapItem.first)->second;
				}
				if (consumeCount.find(mapItem.first) != consumeCount.end())
				{
					tempCount += consumeCount.find(mapItem.first)->second;
					tempSum += consumeSum.find(mapItem.first)->second;
				}
				if (receiptCount.find(mapItem.first) != receiptCount.end())
				{
					tempCount += receiptCount.find(mapItem.first)->second;
					tempSum += receiptSum.find(mapItem.first)->second;
				}
				if (receiptCountReturn.find(mapItem.first) != receiptCountReturn.end())
				{
					tempCount += receiptCountReturn.find(mapItem.first)->second;
					tempSum += receiptSumReturn.find(mapItem.first)->second;
				}
				wtosItem << new QStandardItem(QString::number(tempCount, 'f', 3))
					<< new QStandardItem(QString::number(tempSum, 'f', 3));
			}
			else
			{
				wtosItem << new QStandardItem("0")
					<< new QStandardItem("0");
			}
			if (pConsumeCount.find(mapItem.first) != pConsumeCount.end() || consumeCountReturn.find(mapItem.first) != consumeCountReturn.end()
				|| receiptCount.find(mapItem.first) != receiptCount.end() || receiptCountReturn.find(mapItem.first) != receiptCountReturn.end())
			{
				double tempCount = 0;
				double tempSum = 0;
				if (pConsumeCount.find(mapItem.first) != pConsumeCount.end())
				{
					tempCount += pConsumeCount.find(mapItem.first)->second;
					tempSum += pConsumeSum.find(mapItem.first)->second;
				}
				if (consumeCountReturn.find(mapItem.first) != consumeCountReturn.end())
				{
					tempCount += consumeCountReturn.find(mapItem.first)->second;
					tempSum += consumeSumReturn.find(mapItem.first)->second;
				}
				if (receiptCount.find(mapItem.first) != receiptCount.end())
				{
					tempCount += receiptCount.find(mapItem.first)->second;
					tempSum += receiptSum.find(mapItem.first)->second;
				}
				if (receiptCountReturn.find(mapItem.first) != receiptCountReturn.end())
				{
					tempCount += receiptCountReturn.find(mapItem.first)->second;
					tempSum += receiptSumReturn.find(mapItem.first)->second;
				}
				wtosItem << new QStandardItem(QString::number(tempCount, 'f', 3))
					<< new QStandardItem(QString::number(tempSum, 'f', 3));
			}
			else
			{
				wtosItem << new QStandardItem("0")
					<< new QStandardItem("0");
			}
			if (stockCount.find(mapItem.first) != stockCount.end())
			{
				wtosItem << new QStandardItem(QString::number(stockCount.find(mapItem.first)->second, 'f', 3))
					<< new QStandardItem(QString::number(stockSum.find(mapItem.first)->second, 'f', 3));
			}
			else
			{
				wtosItem << new QStandardItem("0")
					<< new QStandardItem("0");
			}
			wtosItem << new QStandardItem(QString::number(mapItem.first))
				<< new QStandardItem(QString::number(warehouse.GetID()))
				<< new QStandardItem(fromDate.c_str())
				<< new QStandardItem(tillDate.c_str())
				<< new QStandardItem(prevMonthEndDate.c_str());
			itemModel = (QStandardItemModel *)this->tableView->model();
			itemModel->appendRow(wtosItem);
			wtosItem.clear();
		}
	}
}

void ReportForm::FillAccCrdTable(std::string fromDate, std::string tillDate, std::string prevMonthEndDate)
{
	this->setObjectName("AccCrd");
	BusinessLayer::Account acc;
	BusinessLayer::ChartOfAccounts coAcc;
	BusinessLayer::AccountHistory accHistory;
	BusinessLayer::Entry entry;
	std::vector<BusinessLayer::Account> vecAcc;
	std::vector<BusinessLayer::AccountHistory> vecAccHistory;
	std::vector<BusinessLayer::ExtendedEntryView> vecEntryDeb;
	std::vector<BusinessLayer::ExtendedEntryView> vecEntryCred;
	std::string filterDebit;
	std::string filterCredit;
	std::string filterAccHistory;
	vecAcc = reportFormBL->GetAllDataForClass<BusinessLayer::Account>(errorMessage);
	double debSum = 0.0;
	double credSum = 0.0;


	QStringList header;
	header << QObject::tr("Account ID") << QObject::tr("Account name") << QObject::tr("Account number") << QObject::tr("Start saldo")
		<< QObject::tr("Debit") << QObject::tr("Credit") << QObject::tr("End saldo") 
		<< QObject::tr("Start date") << QObject::tr("End date") << QObject::tr("Prev month end date");
	QStandardItemModel *itemModel = new QStandardItemModel(this);
	itemModel->setHorizontalHeaderLabels(header);
	tableView->setModel(itemModel);
	tableView->hideColumn(0);
	tableView->hideColumn(7);
	tableView->hideColumn(8);
	tableView->hideColumn(9);

	BusinessLayer::AccountHistory accHistoryEnd;
	std::vector<BusinessLayer::AccountHistory> vecAccHistoryEnd;

	QList<QStandardItem*> wtosItem;

	for each (auto accItem in vecAcc)
	{
		accHistoryEnd.Clear();
		accHistoryEnd.SetAccountID(accItem.GetID());
		if (!tillDate.empty())
		{
			accHistoryEnd.SetTillDate(tillDate);
		}
		filterAccHistory.clear();
		filterAccHistory = accHistoryEnd.GenerateFilter(reportFormBL->GetOrmasDal());
		vecAccHistoryEnd = reportFormBL->GetAllDataForClass<BusinessLayer::AccountHistory>(errorMessage, filterAccHistory);

		coAcc.Clear();
		if (!coAcc.GetChartOfAccountsByNumber(reportFormBL->GetOrmasDal(), accItem.GetNumber(), errorMessage))
			continue;

		acc.Clear();
		if (acc.GetAccountByID(reportFormBL->GetOrmasDal(), accItem.GetID(), errorMessage))
		{
			filterDebit.clear();
			entry.Clear();
			vecEntryDeb.clear();
			entry.SetDebitingAccountID(accItem.GetID());
			filterDebit = entry.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
			vecEntryDeb = reportFormBL->GetAllDataForClass<BusinessLayer::ExtendedEntryView>(errorMessage, filterDebit);
		}
		acc.Clear();
		if (acc.GetAccountByID(reportFormBL->GetOrmasDal(), accItem.GetID(), errorMessage))
		{
			filterCredit.clear();
			entry.Clear();
			vecEntryCred.clear();
			entry.SetCreditingAccountID(accItem.GetID());
			filterCredit = entry.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
			vecEntryCred = reportFormBL->GetAllDataForClass<BusinessLayer::ExtendedEntryView>(errorMessage, filterCredit);
		}
		debSum = 0;
		credSum = 0;
		for each (auto debEntryItem in vecEntryDeb)
		{
			debSum += debEntryItem.GetValue();
		}
		for each (auto credEntryItem in vecEntryCred)
		{
			credSum += credEntryItem.GetValue();
		}


		filterAccHistory.clear();
		accHistory.SetAccountID(accItem.GetID());
		accHistory.SetTillDate(prevMonthEndDate);
		filterAccHistory = accHistory.GenerateFilter(reportFormBL->GetOrmasDal());
		vecAccHistory = reportFormBL->GetAllDataForClass<BusinessLayer::AccountHistory>(errorMessage, filterAccHistory);

		if (vecAccHistory.size() == 0)
			continue;
		wtosItem << new QStandardItem(QString::number(accItem.GetID()))
			<< new QStandardItem(coAcc.GetName().c_str())
			<< new QStandardItem(coAcc.GetNumber().c_str())
			<< new QStandardItem(QString::number(vecAccHistory.at(0).GetCurrentBalance(), 'f', 3))
			<< new QStandardItem(QString::number(debSum, 'f', 3))
			<< new QStandardItem(QString::number(credSum, 'f', 3));
		if (vecAccHistoryEnd.size()>0)
		{
			wtosItem << new QStandardItem(QString::number(vecAccHistoryEnd.at(0).GetCurrentBalance(), 'f', 3));
		}
		else
		{
			wtosItem << new QStandardItem(QString::number(acc.GetCurrentBalance(), 'f', 3));
		}
		wtosItem << new QStandardItem(fromDate.c_str())
			<< new QStandardItem(tillDate.c_str())
			<< new QStandardItem(prevMonthEndDate.c_str());
		itemModel = (QStandardItemModel *)this->tableView->model();
		itemModel->appendRow(wtosItem);
		wtosItem.clear();
	}
	
	int parentPosition = -1;
	double totalDebSum = 0.0;
	double totalCredSum = 0.0;
	std::string parentPattern = "";
	bool isHaveChild = false;
	itemModel = (QStandardItemModel *)this->tableView->model();
	for (int i = 0; i < tableView->model()->rowCount(); i++)
	{
		if (parentPosition == -1)
		{
			parentPosition = i;
			parentPattern = itemModel->item(i, 2)->text().toStdString().substr(0, 3);
		}
		else
		{
			if (itemModel->item(i, 2)->text().toStdString().substr(0, 3).compare(parentPattern) == 0
				&& i != parentPosition)
			{
				isHaveChild = true;
				totalDebSum += itemModel->item(i, 4)->text().toDouble();
				totalCredSum += itemModel->item(i, 5)->text().toDouble();
			}
			else
			{
				if (isHaveChild == true)
				{
					itemModel->item(parentPosition, 4)->setText(QString::number(totalDebSum, 'f', 3));
					itemModel->item(parentPosition, 5)->setText(QString::number(totalCredSum, 'f', 3));
					isHaveChild = false;
					parentPosition = i;
					parentPattern = itemModel->item(i, 2)->text().toStdString().substr(0, 3);
					totalDebSum = 0;
					totalCredSum = 0;
				}
				else
				{
					parentPosition = i;
					parentPattern = itemModel->item(i, 2)->text().toStdString().substr(0, 3);
					totalDebSum = 0;
					totalCredSum = 0;
				}
			}
		}
	}
}

void ReportForm::FillAccCrdTable(std::string fromDate, std::string tillDate, std::vector<int> subAccIDVec, std::string prevMonthEndDate)
{
	this->setObjectName("SubaccCrd");
	BusinessLayer::Subaccount subacc;
	BusinessLayer::SubaccountHistory saccHistory;
	BusinessLayer::Entry entry;
	std::vector<BusinessLayer::SubaccountView> vecSubacc;
	std::vector<BusinessLayer::SubaccountHistory> vecSubAccHistory;
	std::vector<BusinessLayer::ExtendedEntryView> vecEntryDeb;
	std::vector<BusinessLayer::ExtendedEntryView> vecEntryCred;
	std::string filterDebit;
	std::string filterCredit;
	std::string filterSub;
	std::string filterSubHistory;
	std::string filterAccHistory;
	double debSum = 0.0;
	double credSum = 0.0;
	
	BusinessLayer::SubaccountHistory saccHistoryEnd;
	std::vector<BusinessLayer::SubaccountHistory> vecSubAccHistoryEnd;

	QList<QStandardItem*> wtosItem;

	if (subAccIDVec.size() <= 0)
		return;

	QStringList header;
	header << QObject::tr("Subaccount ID") << QObject::tr("Subaccount number") << QObject::tr("Start saldo") 
		<< QObject::tr("Debit") << QObject::tr("Credit") << QObject::tr("End saldo");
	tableView->hideColumn(0);

	QStandardItemModel *itemModel = new QStandardItemModel(this);
	itemModel->setHorizontalHeaderLabels(header);
	tableView->setModel(itemModel);

	for each (auto subaccIDItem in subAccIDVec)
	{
		subacc.Clear();
		if (!subacc.GetSubaccountByID(reportFormBL->GetOrmasDal(), subaccIDItem, errorMessage))
			continue;
		
		saccHistoryEnd.Clear();
		vecSubAccHistoryEnd.clear();
		saccHistoryEnd.SetSubaccountID(subaccIDItem);
		if (!tillDate.empty())
		{
			saccHistoryEnd.SetTillDate(tillDate);
		}
		filterAccHistory.clear();
		filterAccHistory = saccHistoryEnd.GenerateFilter(reportFormBL->GetOrmasDal());
		vecSubAccHistoryEnd = reportFormBL->GetAllDataForClass<BusinessLayer::SubaccountHistory>(errorMessage, filterAccHistory);


		filterDebit.clear();
		entry.Clear();
		vecEntryDeb.clear();
		entry.SetDebitingAccountID(subacc.GetParentAccountID());
		filterDebit = entry.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		vecEntryDeb = reportFormBL->GetAllDataForClass<BusinessLayer::ExtendedEntryView>(errorMessage, filterDebit);

		filterCredit.clear();
		entry.Clear();
		vecEntryCred.clear();
		entry.SetCreditingAccountID(subacc.GetParentAccountID());
		filterCredit = entry.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		vecEntryCred = reportFormBL->GetAllDataForClass<BusinessLayer::ExtendedEntryView>(errorMessage, filterCredit);

		debSum = 0;
		credSum = 0;

		filterAccHistory.clear();
		saccHistory.Clear();
		vecSubAccHistory.clear();
		saccHistory.SetSubaccountID(subacc.GetID());
		saccHistory.SetTillDate(prevMonthEndDate);
		filterAccHistory = saccHistory.GenerateFilter(reportFormBL->GetOrmasDal());
		vecSubAccHistory = reportFormBL->GetAllDataForClass<BusinessLayer::SubaccountHistory>(errorMessage, filterAccHistory);

		if (vecSubAccHistory.size() == 0)
			return;

		BusinessLayer::EntrySubaccountRelation esRel;
		std::vector<BusinessLayer::EntrySubaccountRelation> vecESRel;
		std::string esFilter;
		for each (auto  debit in vecEntryDeb)
		{
			esRel.Clear();
			vecESRel.clear();
			esFilter.clear();
			esRel.SetEntryID(debit.GetID());
			esFilter = esRel.GenerateFilter(reportFormBL->GetOrmasDal());
			vecESRel = reportFormBL->GetAllDataForClass<BusinessLayer::EntrySubaccountRelation>(errorMessage, esFilter);
			if (vecESRel.size() > 0)
			{
				if (debit.GetSubaccountID() == subacc.GetID())
				{
					if (vecESRel.size() == 1)
					{
						debSum += debit.GetValue();
					}
					else if (vecESRel.size() == 2 && vecESRel.at(0).GetSubaccountID() == subacc.GetID())
					{
						debSum += debit.GetValue();
					}
				}
			}
		}

		for each (auto  credit in vecEntryCred)
		{
			esRel.Clear();
			vecESRel.clear();
			esFilter.clear();
			esRel.SetEntryID(credit.GetID());
			esFilter = esRel.GenerateFilter(reportFormBL->GetOrmasDal());
			vecESRel = reportFormBL->GetAllDataForClass<BusinessLayer::EntrySubaccountRelation>(errorMessage, esFilter);
			if (vecESRel.size() > 0)
			{
				if (credit.GetSubaccountID() == subacc.GetID())
				{
					if (vecESRel.size() == 1)
					{
						credSum += credit.GetValue();
					}
					else if (vecESRel.size() == 2 && vecESRel.at(1).GetSubaccountID() == subacc.GetID())
					{
						credSum += credit.GetValue();
					}
				}
			}
		}
		
		header << QObject::tr("Subaccount ID") << QObject::tr("Subaccount number") << QObject::tr("Start saldo")
			<< QObject::tr("Debit") << QObject::tr("Credit") << QObject::tr("End saldo");

		wtosItem << new QStandardItem(QString::number(subacc.GetID()))
			<< new QStandardItem(subacc.GetNumber().c_str())
			<< new QStandardItem(QString::number(vecSubAccHistory.at(0).GetCurrentBalance(), 'f', 3))
			<< new QStandardItem(QString::number(debSum, 'f', 3))
			<< new QStandardItem(QString::number(credSum, 'f', 3));
		if (vecSubAccHistoryEnd.size() > 0)
		{
			wtosItem << new QStandardItem(QString::number(vecSubAccHistoryEnd.at(0).GetCurrentBalance(), 'f', 3));
		}
		else
		{
			wtosItem << new QStandardItem(QString::number(subacc.GetCurrentBalance(), 'f', 3));
		}
		itemModel = (QStandardItemModel *)this->tableView->model();
		itemModel->appendRow(wtosItem);
		wtosItem.clear();


	}
	
}


void ReportForm::FillAccCrdTable(std::string fromDate, std::string tillDate, int accID, std::string prevMonthEndDate)
{
	this->setObjectName("OneAccCrd");
	BusinessLayer::Account acc;
	BusinessLayer::Subaccount subacc;
	BusinessLayer::ChartOfAccounts coAcc;
	BusinessLayer::AccountHistory accHistory;
	BusinessLayer::SubaccountHistory saccHistory;
	BusinessLayer::Entry entry;
	std::vector<BusinessLayer::Account> vecAcc;
	std::vector<BusinessLayer::SubaccountView> vecSubacc;
	std::vector<BusinessLayer::AccountHistory> vecAccHistory;
	std::vector<BusinessLayer::SubaccountHistory> vecSubAccHistory;
	std::vector<BusinessLayer::ExtendedEntryView> vecEntryDeb;
	std::vector<BusinessLayer::ExtendedEntryView> vecEntryCred;
	std::string filterDebit;
	std::string filterCredit;
	std::string filterSub;
	std::string filterSubHistory;
	std::string filterAccHistory;
	double debSum = 0.0;
	double credSum = 0.0;
	bool haveAChild = false;

	BusinessLayer::AccountHistory accHistoryEnd;
	std::vector<BusinessLayer::AccountHistory> vecAccHistoryEnd;

	BusinessLayer::SubaccountHistory saccHistoryEnd;
	std::vector<BusinessLayer::SubaccountHistory> vecSubAccHistoryEnd;

	QList<QStandardItem*> wtosItem;

	acc.Clear();
	if (!acc.GetAccountByID(reportFormBL->GetOrmasDal(), accID, errorMessage))
	{
		subacc.Clear();
		if (!subacc.GetSubaccountByID(reportFormBL->GetOrmasDal(), accID, errorMessage))
		{
			return;
		}
		else
		{
			acc.Clear();
		}
	}

	if (!acc.IsEmpty())
	{
		BusinessLayer::Account tempAccount;
		if (tempAccount.HaveSubaccount(reportFormBL->GetOrmasDal(), accID))
		{
			haveAChild = true;
		}
		else
		{
			haveAChild = false;
		}
		
		QStringList header;
		if (haveAChild == false)
		{
			header << QObject::tr("Date") << QObject::tr("Description") << QObject::tr("Start saldo") << QObject::tr("Debit account number")
				<< QObject::tr("Debit") << QObject::tr("Credit") << QObject::tr("Credit account number") << QObject::tr("End saldo")
				<< QObject::tr("Operation ID");
			tableView->hideColumn(7);
		}
		else
		{
			header << QObject::tr("Subaccount ID") << QObject::tr("Subaccount number") << QObject::tr("Start saldo")
				<< QObject::tr("Debit") << QObject::tr("Credit") << QObject::tr("End saldo")
				<< QObject::tr("Start date") << QObject::tr("End date") << QObject::tr("Prev month end date")
				<< QObject::tr("Operation ID");
			tableView->hideColumn(0);
			tableView->hideColumn(6);
			tableView->hideColumn(7);
			tableView->hideColumn(8);
			tableView->hideColumn(9);
		}
		QStandardItemModel *itemModel = new QStandardItemModel(this);
		itemModel->setHorizontalHeaderLabels(header);
		tableView->setModel(itemModel);

		if (haveAChild == true)
		{
			subacc.Clear();
			subacc.SetParentAccountID(acc.GetID());
			filterSub.clear();
			filterSub = subacc.GenerateFilter(reportFormBL->GetOrmasDal());
			vecSubacc = reportFormBL->GetAllDataForClass<BusinessLayer::SubaccountView>(errorMessage, filterSub);
			
			if (vecSubacc.size() > 0)
			{
				std::vector<int> subIDList;
				for each (auto item in vecSubacc)
				{
					subIDList.push_back(item.GetID());
				}
				FillAccCrdTable(fromDate, tillDate, subIDList, prevMonthEndDate);
			}
		}
		else
		{
			accHistoryEnd.Clear();
			accHistoryEnd.SetAccountID(acc.GetID());
			if (!tillDate.empty())
			{
				accHistoryEnd.SetTillDate(tillDate);
			}
			filterAccHistory.clear();
			filterAccHistory = accHistoryEnd.GenerateFilter(reportFormBL->GetOrmasDal());
			vecAccHistoryEnd = reportFormBL->GetAllDataForClass<BusinessLayer::AccountHistory>(errorMessage, filterAccHistory);

			coAcc.Clear();
			if (!coAcc.GetChartOfAccountsByNumber(reportFormBL->GetOrmasDal(), acc.GetNumber(), errorMessage))
				return;

			filterDebit.clear();
			entry.Clear();
			vecEntryDeb.clear();
			entry.SetDebitingAccountID(acc.GetID());
			filterDebit = entry.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
			vecEntryDeb = reportFormBL->GetAllDataForClass<BusinessLayer::ExtendedEntryView>(errorMessage, filterDebit);

			filterCredit.clear();
			entry.Clear();
			vecEntryCred.clear();
			entry.SetCreditingAccountID(acc.GetID());
			filterCredit = entry.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
			vecEntryCred = reportFormBL->GetAllDataForClass<BusinessLayer::ExtendedEntryView>(errorMessage, filterCredit);

			debSum = 0;
			credSum = 0;
			
			filterAccHistory.clear();
			accHistory.SetAccountID(acc.GetID());
			accHistory.SetTillDate(prevMonthEndDate);
			filterAccHistory = accHistory.GenerateFilter(reportFormBL->GetOrmasDal());
			vecAccHistory = reportFormBL->GetAllDataForClass<BusinessLayer::AccountHistory>(errorMessage, filterAccHistory);

			wtosItem << new QStandardItem("")
				<< new QStandardItem("");
			if(vecAccHistory.size() == 0)
			{
				wtosItem << new QStandardItem(QString::number(0, 'f', 3));
			}
			else
			{
				wtosItem << new QStandardItem(QString::number(vecAccHistory.at(0).GetCurrentBalance(), 'f', 3));
			}
			wtosItem << new QStandardItem("")
				<< new QStandardItem("")
				<< new QStandardItem("")
				<< new QStandardItem("")
				<< new QStandardItem("")
				<< new QStandardItem("");
			itemModel = (QStandardItemModel *)this->tableView->model();
			itemModel->appendRow(wtosItem);
			wtosItem.clear();

			int count = 0;

			for each (auto  debit in vecEntryDeb)
			{
				wtosItem << new QStandardItem(debit.GetDate().c_str())
					<< new QStandardItem(debit.GetDescription().c_str())
					<< new QStandardItem("")
					<< new QStandardItem(debit.GetDebitingAccountNumber().c_str())
					<< new QStandardItem(QString::number(debit.GetValue(), 'f', 3))
					<< new QStandardItem("")
					<< new QStandardItem(debit.GetCreditingAccountNumber().c_str())
					<< new QStandardItem("")
					<< new QStandardItem(QString::number(debit.GetOperationID()));
				itemModel = (QStandardItemModel *)this->tableView->model();
				itemModel->appendRow(wtosItem);
				wtosItem.clear();
				debSum += debit.GetValue();
				count++;
			}

			for each (auto  credit in vecEntryCred)
			{
				wtosItem << new QStandardItem(credit.GetDate().c_str())
					<< new QStandardItem(credit.GetDescription().c_str())
					<< new QStandardItem("")
					<< new QStandardItem(credit.GetDebitingAccountNumber().c_str())
					<< new QStandardItem("")
					<< new QStandardItem(QString::number(credit.GetValue(), 'f', 3))
					<< new QStandardItem(credit.GetCreditingAccountNumber().c_str())
					<< new QStandardItem("")
					<< new QStandardItem(QString::number(credit.GetOperationID()));
				itemModel = (QStandardItemModel *)this->tableView->model();
				itemModel->appendRow(wtosItem);
				wtosItem.clear();
				credSum += credit.GetValue();
				count++;
			}
			this->tableView->model()->sort(0);
			wtosItem << new QStandardItem("")
				<< new QStandardItem("")
				<< new QStandardItem("")
				<< new QStandardItem("")
				<< new QStandardItem(QString::number(debSum, 'f', 3))
				<< new QStandardItem(QString::number(credSum, 'f', 3))
				<< new QStandardItem("")
				<< new QStandardItem("")
				<< new QStandardItem("");
			itemModel = (QStandardItemModel *)this->tableView->model();
			itemModel->appendRow(wtosItem);
			wtosItem.clear();

			wtosItem << new QStandardItem("")
				<< new QStandardItem("")
				<< new QStandardItem("")
				<< new QStandardItem("")
				<< new QStandardItem("")
				<< new QStandardItem("")
				<< new QStandardItem("");
			if (vecAccHistoryEnd.size() > 0)
			{
				wtosItem << new QStandardItem(QString::number(vecAccHistoryEnd.at(0).GetCurrentBalance(), 'f', 3));
			}
			else
			{
				wtosItem << new QStandardItem(QString::number(acc.GetCurrentBalance(), 'f', 3));
			}
			wtosItem << new QStandardItem("");
			itemModel = (QStandardItemModel *)this->tableView->model();
			itemModel->appendRow(wtosItem);
			wtosItem.clear();

		}
	}
	else if (!subacc.IsEmpty())
	{
		QStringList header;
		header << QObject::tr("Date") << QObject::tr("Description") << QObject::tr("Start saldo") << QObject::tr("Debit account number")
				<< QObject::tr("Debit") << QObject::tr("Credit") << QObject::tr("Credit account number") << QObject::tr("End saldo")
				<< QObject::tr("Operation ID");
			tableView->hideColumn(7);
		
		QStandardItemModel *itemModel = new QStandardItemModel(this);
		itemModel->setHorizontalHeaderLabels(header);
		tableView->setModel(itemModel);

		saccHistoryEnd.Clear();
		saccHistoryEnd.SetSubaccountID(subacc.GetID());
		if (!tillDate.empty())
		{
			saccHistoryEnd.SetTillDate(tillDate);
		}
		filterAccHistory.clear();
		filterAccHistory = saccHistoryEnd.GenerateFilter(reportFormBL->GetOrmasDal());
		vecSubAccHistoryEnd = reportFormBL->GetAllDataForClass<BusinessLayer::SubaccountHistory>(errorMessage, filterAccHistory);


		filterDebit.clear();
		entry.Clear();
		vecEntryDeb.clear();
		entry.SetDebitingAccountID(subacc.GetParentAccountID());
		filterDebit = entry.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		vecEntryDeb = reportFormBL->GetAllDataForClass<BusinessLayer::ExtendedEntryView>(errorMessage, filterDebit);

		filterCredit.clear();
		entry.Clear();
		vecEntryCred.clear();
		entry.SetCreditingAccountID(subacc.GetParentAccountID());
		filterCredit = entry.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		vecEntryCred = reportFormBL->GetAllDataForClass<BusinessLayer::ExtendedEntryView>(errorMessage, filterCredit);

		debSum = 0;
		credSum = 0;

		filterAccHistory.clear();
		saccHistory.SetSubaccountID(subacc.GetID());
		saccHistory.SetTillDate(prevMonthEndDate);
		filterAccHistory = saccHistory.GenerateFilter(reportFormBL->GetOrmasDal());
		vecSubAccHistory = reportFormBL->GetAllDataForClass<BusinessLayer::SubaccountHistory>(errorMessage, filterAccHistory);

		wtosItem << new QStandardItem("")
			<< new QStandardItem("");
		if (vecSubAccHistory.size() == 0)
		{
			wtosItem << new QStandardItem(QString::number(0, 'f', 3));
		}
		else
		{
			wtosItem << new QStandardItem(QString::number(vecSubAccHistory.at(0).GetCurrentBalance(), 'f', 3));
		}
		wtosItem << new QStandardItem("")
			<< new QStandardItem("")
			<< new QStandardItem("")
			<< new QStandardItem("")
			<< new QStandardItem("")
			<< new QStandardItem("");
		itemModel = (QStandardItemModel *)this->tableView->model();
		itemModel->appendRow(wtosItem);
		wtosItem.clear();

		int count = 0;

		BusinessLayer::EntrySubaccountRelation esRel;
		std::vector<BusinessLayer::EntrySubaccountRelation> vecESRel;
		std::string esFilter;
		for each (auto  debit in vecEntryDeb)
		{
			esRel.Clear();
			vecESRel.clear();
			esFilter.clear();
			esRel.SetEntryID(debit.GetID());
			esFilter = esRel.GenerateFilter(reportFormBL->GetOrmasDal());
			vecESRel = reportFormBL->GetAllDataForClass<BusinessLayer::EntrySubaccountRelation>(errorMessage, esFilter);
			if (vecESRel.size() > 0)
			{
				if (debit.GetSubaccountID() == subacc.GetID())
				{
					if (vecESRel.size() == 1)
					{
						wtosItem << new QStandardItem(debit.GetDate().c_str())
							<< new QStandardItem(debit.GetDescription().c_str())
							<< new QStandardItem("")
							<< new QStandardItem(debit.GetDebitingAccountNumber().c_str())
							<< new QStandardItem(QString::number(debit.GetValue(), 'f', 3))
							<< new QStandardItem("")
							<< new QStandardItem(debit.GetCreditingAccountNumber().c_str())
							<< new QStandardItem("")
							<< new QStandardItem(QString::number(debit.GetOperationID()));
						itemModel = (QStandardItemModel *)this->tableView->model();
						itemModel->appendRow(wtosItem);
						wtosItem.clear();
						debSum += debit.GetValue();
						count++;
					}
					else if (vecESRel.size() == 2 && vecESRel.at(0).GetSubaccountID() == subacc.GetID())
					{
						wtosItem << new QStandardItem(debit.GetDate().c_str())
							<< new QStandardItem(debit.GetDescription().c_str())
							<< new QStandardItem("")
							<< new QStandardItem(debit.GetDebitingAccountNumber().c_str())
							<< new QStandardItem(QString::number(debit.GetValue(), 'f', 3))
							<< new QStandardItem("")
							<< new QStandardItem(debit.GetCreditingAccountNumber().c_str())
							<< new QStandardItem("")
							<< new QStandardItem(QString::number(debit.GetOperationID()));
						itemModel = (QStandardItemModel *)this->tableView->model();
						itemModel->appendRow(wtosItem);
						wtosItem.clear();
						debSum += debit.GetValue();
						count++;
					}
				}
			}
		}

		for each (auto  credit in vecEntryCred)
		{
			esRel.Clear();
			vecESRel.clear();
			esFilter.clear();
			esRel.SetEntryID(credit.GetID());
			esFilter = esRel.GenerateFilter(reportFormBL->GetOrmasDal());
			vecESRel = reportFormBL->GetAllDataForClass<BusinessLayer::EntrySubaccountRelation>(errorMessage, esFilter);
			if (vecESRel.size() > 0)
			{
				if (credit.GetSubaccountID() == subacc.GetID())
				{
					if (vecESRel.size() == 1)
					{
						wtosItem << new QStandardItem(credit.GetDate().c_str())
							<< new QStandardItem(credit.GetDescription().c_str())
							<< new QStandardItem("")
							<< new QStandardItem(credit.GetDebitingAccountNumber().c_str())
							<< new QStandardItem("")
							<< new QStandardItem(QString::number(credit.GetValue(), 'f', 3))
							<< new QStandardItem(credit.GetCreditingAccountNumber().c_str())
							<< new QStandardItem("")
							<< new QStandardItem(QString::number(credit.GetOperationID()));
						itemModel = (QStandardItemModel *)this->tableView->model();
						itemModel->appendRow(wtosItem);
						wtosItem.clear();
						credSum += credit.GetValue();
						count++;
					}
					else if (vecESRel.size() == 2 && vecESRel.at(1).GetSubaccountID() == subacc.GetID())
					{
						wtosItem << new QStandardItem(credit.GetDate().c_str())
							<< new QStandardItem(credit.GetDescription().c_str())
							<< new QStandardItem("")
							<< new QStandardItem(credit.GetDebitingAccountNumber().c_str())
							<< new QStandardItem("")
							<< new QStandardItem(QString::number(credit.GetValue(), 'f', 3))
							<< new QStandardItem(credit.GetCreditingAccountNumber().c_str())
							<< new QStandardItem("")
							<< new QStandardItem(QString::number(credit.GetOperationID()));
						itemModel = (QStandardItemModel *)this->tableView->model();
						itemModel->appendRow(wtosItem);
						wtosItem.clear();
						credSum += credit.GetValue();
						count++;
					}
				}
			}
		}
		this->tableView->model()->sort(0);
		wtosItem << new QStandardItem("")
			<< new QStandardItem("")
			<< new QStandardItem("")
			<< new QStandardItem("")
			<< new QStandardItem(QString::number(debSum, 'f', 3))
			<< new QStandardItem(QString::number(credSum, 'f', 3))
			<< new QStandardItem("")
			<< new QStandardItem("")
			<< new QStandardItem("");
		itemModel = (QStandardItemModel *)this->tableView->model();
		itemModel->appendRow(wtosItem);
		wtosItem.clear();

		wtosItem << new QStandardItem("")
			<< new QStandardItem("")
			<< new QStandardItem("")
			<< new QStandardItem("")
			<< new QStandardItem("")
			<< new QStandardItem("")
			<< new QStandardItem("");
		if (vecSubAccHistoryEnd.size() > 0)
		{
			wtosItem << new QStandardItem(QString::number(vecSubAccHistoryEnd.at(0).GetCurrentBalance(), 'f', 3));
		}
		else
		{
			wtosItem << new QStandardItem(QString::number(subacc.GetCurrentBalance(), 'f', 3));
		}
		wtosItem << new QStandardItem("");
		itemModel = (QStandardItemModel *)this->tableView->model();
		itemModel->appendRow(wtosItem);
		wtosItem.clear();
	}
}

void ReportForm::View()
{
	if (this->objectName() == "WTBS")
	{
		ViewWTBS();
	}
	else if (this->objectName() == "AccCrd")
	{
		ViewAcc();
	}
	else if (this->objectName() == "SubaccCrd")
	{
		ViewSubacc();
	}
	else if (this->objectName() == "OneAccCrd")
	{
		ViewOneAcc();
	}
}

void ReportForm::ViewWTBS()
{

}

void ReportForm::ViewAcc()
{

}

void ReportForm::ViewSubacc()
{

}

void ReportForm::ViewOneAcc()
{

}
