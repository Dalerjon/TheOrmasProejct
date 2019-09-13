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
	connect(viewBtn, &QPushButton::released, this, &ReportForm::ViewWTBS);
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
		BusinessLayer::StockTransfer sTransfer;
		sTransfer.SetStatusID(status.GetID());
		std::string filterStockTra = ret.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterList.push_back(filterStockTra);
		filterList.push_back(empIDListFilter);
		filterStockTra = reportFormBL->GetOrmasDal().ConcatenateFilters(filterList);
		std::vector<BusinessLayer::StockTransferView> vecStockTra = reportFormBL->GetAllDataForClass<BusinessLayer::StockTransferView>(errorMessage, filterStockTra);


		// select stock transfers for return status
		filterListReturn.clear();
		BusinessLayer::StockTransfer sTransferReturn;
		sTransferReturn.SetStatusID(statusReturn.GetID());
		std::string filterStockTraReturn = sTransferReturn.GenerateFilterForPeriod(reportFormBL->GetOrmasDal(), fromDate, tillDate);
		filterListReturn.push_back(filterStockTraReturn);
		filterListReturn.push_back(empIDListFilter);
		filterStockTraReturn = reportFormBL->GetOrmasDal().ConcatenateFilters(filterListReturn);
		std::vector<BusinessLayer::StockTransferView> vecStockTraReturn = reportFormBL->GetAllDataForClass<BusinessLayer::StockTransferView>(errorMessage, filterStockTraReturn);

		std::map<int, double> receiptCount;
		std::map<int, double> receiptSum;
		std::map<int, double> consumeCount;
		std::map<int, double> consumeSum;
		std::map<int, double> returnCount;
		std::map<int, double> returnSum;
		std::map<int, double> writeOffCount;
		std::map<int, double> writeOffSum;
		std::map<int, double> stockTraCount;
		std::map<int, double> stockTraSum;

		std::map<int, double> receiptCountReturn;
		std::map<int, double> receiptSumReturn;
		std::map<int, double> consumeCountReturn;
		std::map<int, double> consumeSumReturn;
		std::map<int, double> returnCountReturn;
		std::map<int, double> returnSumReturn;
		std::map<int, double> writeOffCountReturn;
		std::map<int, double> writeOffSumReturn;
		std::map<int, double> stockTraCountReturn;
		std::map<int, double> stockTraSumReturn;


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
						if (consumeCount.find(listItem.GetProductID()) != consumeCount.end())
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

		if (vecStockTra.size() > 0)
		{
			BusinessLayer::StockTransferList stTraList;
			std::string stTraListFilter;
			std::vector<BusinessLayer::StockTransferListView> vecStTraList;

			for each (auto item in vecStockTra)
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
						if (stockTraCount.find(listItem.GetProductID()) != stockTraCount.end())
						{
							stockTraCount.find(listItem.GetProductID())->second = stockTraCount.find(listItem.GetProductID())->second + listItem.GetCount();
							stockTraSum.find(listItem.GetProductID())->second = stockTraSum.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							stockTraCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							stockTraSum.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
						}
					}
				}
			}
		}
		if (vecStockTraReturn.size() > 0)
		{
			BusinessLayer::StockTransferList stTraListReturn;
			std::string stTraListFilterReturn;
			std::vector<BusinessLayer::StockTransferListView> vecStTraListReturn;

			for each (auto item in vecStockTraReturn)
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
						if (stockTraCountReturn.find(listItem.GetProductID()) != stockTraCount.end())
						{
							stockTraCountReturn.find(listItem.GetProductID())->second = stockTraCountReturn.find(listItem.GetProductID())->second + listItem.GetCount();
							stockTraSumReturn.find(listItem.GetProductID())->second = stockTraSumReturn.find(listItem.GetProductID())->second + listItem.GetSum();
						}
						else
						{
							stockTraCountReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							stockTraSumReturn.insert(std::make_pair(listItem.GetProductID(), listItem.GetSum()));
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
				|| stockTraCountReturn.find(mapItem.first) != stockTraCountReturn.end())
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
				if (stockTraCountReturn.find(mapItem.first) != stockTraCountReturn.end())
				{
					tempCount += stockTraCountReturn.find(mapItem.first)->second;
					tempSum += stockTraSumReturn.find(mapItem.first)->second;
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
				|| stockTraCount.find(mapItem.first) != stockTraCount.end())
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
				if (writeOffCount.find(mapItem.first) != writeOffCount.end())
				{
					tempCount += stockTraCount.find(mapItem.first)->second;
					tempSum += stockTraSum.find(mapItem.first)->second;
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

	}


	/*BusinessLayer::ProductionConsumeRaw prRaw;
	prRaw.SetStatusID(status.GetID());
	std::string filterprRaw = prRaw.GenerateFilterForPeriod(dialogBL->GetOrmasDal(), fromDateEdit->text().toUtf8().constData(), tillDateEdit->text().toUtf8().constData());
	std::vector<BusinessLayer::ProductionConsumeRawView> vecConRaw = dialogBL->GetAllDataForClass<BusinessLayer::ProductionConsumeRawView>(errorMessage, filterprRaw);
	if (vecConRaw.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find any consumption raw in production for this period!")),
			QString(tr("Ok")));
		return;
	}

	BusinessLayer::Production production;
	std::string filter = production.GenerateFilterForPeriod(dialogBL->GetOrmasDal(), fromDateEdit->text().toUtf8().constData(), tillDateEdit->text().toUtf8().constData());
	std::vector<BusinessLayer::Production> vecProdn = dialogBL->GetAllDataForClass<BusinessLayer::Production>(errorMessage, filter);
	if (vecProdn.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find any production document for this period!")),
			QString(tr("Ok")));
		return;
	}
	else
	{
		//generating report
		std::map<int, double> prodnProductCount;
		std::map<int, double> consumeProductCount;
		std::map<int, double> specProductCount;

		if (vecProdn.size() > 0)
		{
			BusinessLayer::ProductionList productionList;
			std::string prodnListFilter;
			std::vector<BusinessLayer::ProductionListView> vecProdnList;

			for each (auto item in vecProdn)
			{
				productionList.Clear();
				prodnListFilter.clear();
				productionList.SetProductionID(item.GetID());
				prodnListFilter = productionList.GenerateFilter(dialogBL->GetOrmasDal());
				vecProdnList.clear();
				vecProdnList = dialogBL->GetAllDataForClass<BusinessLayer::ProductionListView>(errorMessage, prodnListFilter);
				if (vecProdnList.size() > 0)
				{
					for each (auto listItem in vecProdnList)
					{
						if (prodnProductCount.find(listItem.GetProductID()) != prodnProductCount.end())
						{
							prodnProductCount.find(listItem.GetProductID())->second = prodnProductCount.find(listItem.GetProductID())->second + listItem.GetCount();
						}
						else
						{
							prodnProductCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
						}
					}
				}
			}


			if (vecConRaw.size() > 0)
			{
				BusinessLayer::ProductionConsumeRawList cRawList;
				std::string cRawListFilter;
				std::vector<BusinessLayer::ProductionConsumeRawListView> vecCRawList;
				for each (auto item in vecConRaw)
				{
					cRawList.Clear();
					cRawListFilter.clear();
					cRawList.SetProductionConsumeRawID(item.GetID());
					cRawListFilter = cRawList.GenerateFilter(dialogBL->GetOrmasDal());
					vecCRawList.clear();
					vecCRawList = dialogBL->GetAllDataForClass<BusinessLayer::ProductionConsumeRawListView>(errorMessage, cRawListFilter);
					if (vecCRawList.size() > 0)
					{
						for each (auto listItem in vecCRawList)
						{
							if (consumeProductCount.find(listItem.GetProductID()) != consumeProductCount.end())
							{
								consumeProductCount.find(listItem.GetProductID())->second = consumeProductCount.find(listItem.GetProductID())->second + listItem.GetCount();
							}
							else
							{
								consumeProductCount.insert(std::make_pair(listItem.GetProductID(), listItem.GetCount()));
							}
						}
					}
				}
			}

			BusinessLayer::Specification specification;
			BusinessLayer::SpecificationList specList;
			std::vector<BusinessLayer::SpecificationListView> vecSpecList;
			std::string specFilter;

			for each (auto product in prodnProductCount)
			{
				specification.Clear();
				if (!specification.GetSpecificationByProductID(dialogBL->GetOrmasDal(), product.first, errorMessage))
				{
					QMessageBox::information(NULL, QString(tr("Info")),
						QString(tr("This product does't have specification! Cannot print it")),
						QString(tr("Ok")));
					return;
				}
				specFilter.clear();
				specList.Clear();
				specList.SetSpecificationID(specification.GetID());
				specFilter = specList.GenerateFilter(dialogBL->GetOrmasDal());
				vecSpecList.clear();
				vecSpecList = dialogBL->GetAllDataForClass<BusinessLayer::SpecificationListView>(errorMessage, specFilter);
				if (vecSpecList.size() > 0)
				{
					for each (auto specItem in vecSpecList)
					{
						if (specProductCount.find(specItem.GetProductID()) != specProductCount.end())
						{
							specProductCount.find(specItem.GetProductID())->second = specProductCount.find(specItem.GetProductID())->second + (specItem.GetCount() * product.second);
						}
						else
						{
							specProductCount.insert(std::make_pair(specItem.GetProductID(), (specItem.GetCount() * product.second)));
						}
					}
				}
			}

			BusinessLayer::Product product;
			BusinessLayer::Measure measure;

			reportText.replace(QString("fromDatePh"), fromDateEdit->text(), Qt::CaseInsensitive);
			reportText.replace(QString("tillDatePh"), tillDateEdit->text(), Qt::CaseInsensitive);
			double sum = 0;
			double difSum = 0;
			double prodSum = 0;
			QString producedTableBody;
			for each (auto producedProduct in prodnProductCount)
			{
				product.Clear();
				product.GetProductByID(dialogBL->GetOrmasDal(), producedProduct.first, errorMessage);
				producedTableBody += "<tr>";
				producedTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString::number(producedProduct.first) + "</td>";
				producedTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString(product.GetName().c_str()) + "</td>";
				producedTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString::number(producedProduct.second) + "</td>";
				producedTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString::number(product.GetPrice()) + "</td>";
				producedTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString::number(producedProduct.second * product.GetPrice()) + "</td>";
				producedTableBody += "</tr>";
				prodSum += producedProduct.second * product.GetPrice();
			}
			reportText.replace(QString("ProductTableBodyPh"), producedTableBody, Qt::CaseInsensitive);

			QString specTableBody;
			for each (auto specProduct in specProductCount)
			{
				product.Clear();
				if (product.GetProductByID(dialogBL->GetOrmasDal(), specProduct.first, errorMessage))
				{
					measure.Clear();
					if (measure.GetMeasureByID(dialogBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
					{
						specTableBody += "<tr>";
						specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString(product.GetName().c_str()) + "</td>";
						specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString::number(specProduct.second) + "</td>";
						specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString(measure.GetShortName().c_str()) + "</td>";
						if (consumeProductCount.find(product.GetID()) != consumeProductCount.end())
						{
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString::number(consumeProductCount.find(product.GetID())->second) + "</td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString(measure.GetShortName().c_str()) + "</td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString::number(consumeProductCount.find(product.GetID())->second - specProduct.second) + "</td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString(measure.GetShortName().c_str()) + "</td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString::number((consumeProductCount.find(product.GetID())->second - specProduct.second) * product.GetPrice()) + "</td>";
							difSum += (consumeProductCount.find(product.GetID())->second - specProduct.second) * product.GetPrice();
							sum += consumeProductCount.find(product.GetID())->second * product.GetPrice();
						}
						else
						{
							specTableBody += "<td style='border: 1px solid black; text - align: center; '> 0 </td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString(measure.GetShortName().c_str()) + "</td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString::number(specProduct.second * -1) + "</td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString(measure.GetShortName().c_str()) + "</td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString::number(specProduct.second * -1 * product.GetPrice()) + "</td>";
							difSum += specProduct.second * -1 * product.GetPrice();
						}
					}
				}
			}
			for each (auto consumedProduct in consumeProductCount)
			{
				product.Clear();
				if (product.GetProductByID(dialogBL->GetOrmasDal(), consumedProduct.first, errorMessage))
				{
					measure.Clear();
					if (measure.GetMeasureByID(dialogBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
					{
						if (specProductCount.find(product.GetID()) == specProductCount.end())
						{

							specTableBody += "<tr>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString(product.GetName().c_str()) + "</td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '> 0 </td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString(measure.GetShortName().c_str()) + "</td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString::number(consumedProduct.second) + "</td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString(measure.GetShortName().c_str()) + "</td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString::number(consumedProduct.second) + "</td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString(measure.GetShortName().c_str()) + "</td>";
							specTableBody += "<td style='border: 1px solid black; text - align: center; '>" + QString::number(consumedProduct.second * product.GetPrice()) + "</td>";
							difSum += consumedProduct.second * product.GetPrice();
							sum += consumedProduct.second * product.GetPrice();
						}
					}
				}
			}
			reportText.replace(QString("SpecTableBodyPh"), specTableBody, Qt::CaseInsensitive);
			reportText.replace(QString("SumPh"), QString::number(difSum, 'f', 3), Qt::CaseInsensitive);
			reportText.replace(QString("AllSummPh"), QString::number(sum, 'f', 3), Qt::CaseInsensitive);
			reportText.replace(QString("AllProdPh"), QString::number(prodSum, 'f', 3), Qt::CaseInsensitive);

			docForm->webEngineView->setHtml(reportText);
			docForm->SetContent(reportText);
			docForm->webEngineView->show();
			docForm->show();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Cannot generate report for this period!")),
				QString(tr("Ok")));
		}
	}
	Close();
	*/
}

void ReportForm::ViewWTBS()
{
	/*DocForm *docForm = new DocForm(reportFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print warehouse turnover balance sheet"));
	QMdiSubWindow *generateWTBSWindow = new QMdiSubWindow;
	generateWTBSWindow->setWidget(docForm);
	generateWTBSWindow->setAttribute(Qt::WA_DeleteOnClose);
	generateWTBSWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(generateWTBSWindow);

	//read template
	QFile file;
	file.setFileName(":/docs/warehouse_turnover.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find warehouse turnover tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	
	
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Return ret;
	if (!ret.GetReturnByID(reportFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::ReturnList returnList;
	BusinessLayer::Client client;
	BusinessLayer::Employee employee;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;
	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(reportFormBL->GetOrmasDal(), ret.GetEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(reportFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!client.GetClientByID(reportFormBL->GetOrmasDal(), ret.GetClientID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!employee.GetEmployeeByID(reportFormBL->GetOrmasDal(), ret.GetEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}

	DocForm *docForm = new DocForm(reportFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/return.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	returnList.SetReturnID(ret.GetID());
	std::string filter = returnList.GenerateFilter(reportFormBL->GetOrmasDal());
	std::vector<BusinessLayer::ReturnListView> vecRetList = reportFormBL->GetAllDataForClass<BusinessLayer::ReturnListView>(errorMessage, filter);
	if (vecRetList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(ret.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(ret.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName1Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName1Ph"), QString(employee.GetSurname().c_str()) + " " + QString(employee.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName2Ph"), QString(client.GetFirm().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName2Ph"), QString(client.GetSurname().c_str()) + " " + QString(client.GetName().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	QString tableBody;
	for each (auto item in vecRetList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		if (!product.GetProductByID(reportFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(reportFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(reportFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Currency is wrong!")),
				QString(tr("Ok")));
			return;
		}
		tableBody += "<tr>";
		tableBody += "<td>" + QString::number(i) + "</td>";
		tableBody += "<td>" + QString(product.GetName().c_str()) + "</td>";
		tableBody += "<td>" + QString(measure.GetShortName().c_str()) + "</td>";
		tableBody += "<td>" + QString::number(item.GetCount()) + "</td>";
		tableBody += "<td>" + QString::number(item.GetSum() / item.GetCount(), 'f', 3) + "</td>";
		tableBody += "<td>" + QString::number(item.GetSum()) + "</td>";
		tableBody += "<td>" + QString(currency.GetShortName().c_str()) + "</td>";
		tableBody += "</tr>";
		i++;
	}
	reportText.replace(QString("TableBodyPh"), tableBody, Qt::CaseInsensitive);
	reportText.replace(QString("SumPh"), QString::number(ret.GetSum()), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();*/
}