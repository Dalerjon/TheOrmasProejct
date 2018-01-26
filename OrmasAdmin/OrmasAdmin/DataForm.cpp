#include "stdafx.h"
#include <QStandardItemModel>
#include <QtWidgets/QMdiArea>
#include <QMessageBox>
#include "DataForm.h"
#include "MainForm.h"
#include "ExtraFunctions.h"

DataForm::DataForm(BusinessLayer::OrmasBL *ormasBL, QWidget *parent) :QWidget(parent)
{
	setupUi(this);
	tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tableView->verticalHeader()->hide();
	tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	editBtn->setDisabled(true);
	deleteBtn->setDisabled(true);
	dataFormBL = ormasBL;
	parentForm = parent;
	if (objectName() == "orderForm" || objectName() == "returnForm" || objectName() == "productionForm" || objectName() == "writeOffForm" ||
		objectName() == "consumeProductForm" || objectName() == "consumeRawForm" || objectName() == "inventorizationForm" ||
		objectName() == "orderRawForm" || objectName() == "receiptProductForm" || objectName() == "receiptRawForm" ||
		objectName() == "transportForm" || objectName() == "writeOffRawForm")
	{
		connect(tableView, SIGNAL(cellClicked(int, int)), this, SLOT(OpenList(int, int)));
	}
}

// All Slots ----------------------------------------------------------------------------
void DataForm::CloseDataForm()
{
	QMdiSubWindow *dataFromWindow = ((MainForm*)parentForm)->GetWindowByName(this->objectName());
	if (dataFromWindow != nullptr)
		dataFromWindow->close();
}

void DataForm::ChangeBtnState()
{
	if (0 < tableView->model()->rowCount())
	{
		EnableButtons();
	}
	else
	{
		DisableButtons();
	}
}
void DataForm::DisableButtons()
{
	editBtn->setDisabled(true);
	deleteBtn->setDisabled(true);
}
void DataForm::EnableButtons()
{
	editBtn->setDisabled(false);
	deleteBtn->setDisabled(false);
}

QWidget* DataForm::GetParent()
{
	return parentForm;
}

void DataForm::GetIDValue(QModelIndex index)
{
	int id = GetIDFromTable(tableView, index);
	emit SendID(id, objectName());
	CloseDataForm();
}

void DataForm::OpenList(int row, int column)
{
	if (column == tableView->model()->columnCount() - 1 && row > 0)
	{
		std::string errorMessage = "";
		std::string filterString = "";
		int id = 0;
		QString message = tr("Loading...");
		((MainForm*)parentWidget())->statusBar()->showMessage(message);
		QWidget* checkedWidget = nullptr;
		if (objectName() == "orderForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				orderID = id;
			BusinessLayer::OrderList *orderList = new BusinessLayer::OrderList();
			orderList->SetOrderID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::OrderList>(orderList);
			delete orderList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("orderListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Order list products"));
					dForm->FillTable<BusinessLayer::OrderListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("orderListForm");
						QMdiSubWindow *prodListWindow = new QMdiSubWindow;
						prodListWindow->setWidget(dForm);
						prodListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(prodListWindow);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All products for order list are shown");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
					}
					else
					{
						delete dForm;
						QString message = tr("End with error!");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage = "";
					}
				}
				else
				{
					checkedWidget->topLevelWidget();
					checkedWidget->activateWindow();
					QString message = tr("All products for order list are shown");
					((MainForm*)parentWidget())->statusBar()->showMessage(message);
				}
			}
		}
		else if (objectName() == "conusmeProductForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				consumeProductID = id;
			BusinessLayer::ConsumeProductList *consumeProductList = new BusinessLayer::ConsumeProductList();
			consumeProductList->SetConsumeProductID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::ConsumeProductList>(consumeProductList);
			delete consumeProductList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("conusmeProductListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Consume product list"));
					dForm->FillTable<BusinessLayer::ConsumeProductListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("conusmeProductListForm");
						QMdiSubWindow *conProdListWindow = new QMdiSubWindow;
						conProdListWindow->setWidget(dForm);
						conProdListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(conProdListWindow);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All products for consume product list are shown");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
					}
					else
					{
						delete dForm;
						QString message = tr("End with error!");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage = "";
					}
				}
				else
				{
					checkedWidget->topLevelWidget();
					checkedWidget->activateWindow();
					QString message = tr("All products for consume product list are shown");
					((MainForm*)parentWidget())->statusBar()->showMessage(message);
				}
			}
		}
		else if (objectName() == "conusmeRawForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				consumeRawID = id;
			BusinessLayer::ConsumeRawList *consumeRawList = new BusinessLayer::ConsumeRawList();
			consumeRawList->SetConsumeRawID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::ConsumeRawList>(consumeRawList);
			delete consumeRawList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("conusmeRawListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Consume raw list"));
					dForm->FillTable<BusinessLayer::ConsumeRawListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("conusmeRawListForm");
						QMdiSubWindow *conRawListWindow = new QMdiSubWindow;
						conRawListWindow->setWidget(dForm);
						conRawListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(conRawListWindow);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All raws for consume product list are shown");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
					}
					else
					{
						delete dForm;
						QString message = tr("End with error!");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage = "";
					}
				}
				else
				{
					checkedWidget->topLevelWidget();
					checkedWidget->activateWindow();
					QString message = tr("All raws for consume product list are shown");
					((MainForm*)parentWidget())->statusBar()->showMessage(message);
				}
			}
		}
		else if (objectName() == "inventorizationForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				inventorizationID = id;
			BusinessLayer::InventorizationList *inventorizationList = new BusinessLayer::InventorizationList();
			inventorizationList->SetInventorizationID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::InventorizationList>(inventorizationList);
			delete inventorizationList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("inventorizationListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Inventorization list"));
					dForm->FillTable<BusinessLayer::InventorizationListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("inventorizationListForm");
						QMdiSubWindow *invListWindow = new QMdiSubWindow;
						invListWindow->setWidget(dForm);
						invListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(invListWindow);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All products for inventorization list are shown");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
					}
					else
					{
						delete dForm;
						QString message = tr("End with error!");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage = "";
					}
				}
				else
				{
					checkedWidget->topLevelWidget();
					checkedWidget->activateWindow();
					QString message = tr("All products for inventorization list are shown");
					((MainForm*)parentWidget())->statusBar()->showMessage(message);
				}
			}
		}
		else if (objectName() == "orderRawForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				orderRawID = id;
			BusinessLayer::OrderRawList *orderRawList = new BusinessLayer::OrderRawList();
			orderRawList->SetOrderRawID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::OrderRawList>(orderRawList);
			delete orderRawList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("orderRawListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Order raw list"));
					dForm->FillTable<BusinessLayer::OrderRawListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("orderRawListForm");
						QMdiSubWindow *orderRawListWindow = new QMdiSubWindow;
						orderRawListWindow->setWidget(dForm);
						orderRawListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(orderRawListWindow);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All raws for order list are shown");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
					}
					else
					{
						delete dForm;
						QString message = tr("End with error!");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage = "";
					}
				}
				else
				{
					checkedWidget->topLevelWidget();
					checkedWidget->activateWindow();
					QString message = tr("All raws for order list are shown");
					((MainForm*)parentWidget())->statusBar()->showMessage(message);
				}
			}
		}
		else if (objectName() == "productionForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				productionID = id;
			BusinessLayer::ProductionList *productionList = new BusinessLayer::ProductionList();
			productionList->SetProductionID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::ProductionList>(productionList);
			delete productionList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("productionListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Production list products"));
					dForm->FillTable<BusinessLayer::ProductionListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("productionListForm");
						QMdiSubWindow *prodListWindow = new QMdiSubWindow;
						prodListWindow->setWidget(dForm);
						prodListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(prodListWindow);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All products for production list are shown");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
					}
					else
					{
						delete dForm;
						QString message = tr("End with error!");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage = "";
					}
				}
				else
				{
					checkedWidget->topLevelWidget();
					checkedWidget->activateWindow();
					QString message = tr("All products for production list are shown");
					((MainForm*)parentWidget())->statusBar()->showMessage(message);
				}
			}
		}
		else if (objectName() == "receiptProductForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				receiptProductID = id;
			BusinessLayer::ReceiptProductList *receiptProductList = new BusinessLayer::ReceiptProductList();
			receiptProductList->SetReceiptProductID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::ReceiptProductList>(receiptProductList);
			delete receiptProductList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("receiptProductListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Receipt product list"));
					dForm->FillTable<BusinessLayer::ReceiptProductListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("receiptProductListForm");
						QMdiSubWindow *recProdListWindow = new QMdiSubWindow;
						recProdListWindow->setWidget(dForm);
						recProdListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(recProdListWindow);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All products for receipt product list are shown");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
					}
					else
					{
						delete dForm;
						QString message = tr("End with error!");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage = "";
					}
				}
				else
				{
					checkedWidget->topLevelWidget();
					checkedWidget->activateWindow();
					QString message = tr("All products for receipt product list are shown");
					((MainForm*)parentWidget())->statusBar()->showMessage(message);
				}
			}
		}
		else if (objectName() == "receiptRawForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				receiptRawID = id;
			BusinessLayer::ReceiptRawList *receiptRawList = new BusinessLayer::ReceiptRawList();
			receiptRawList->SetReceiptRawID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::ReceiptRawList>(receiptRawList);
			delete receiptRawList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("receiptRawListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Receipt raw list"));
					dForm->FillTable<BusinessLayer::ReceiptRawListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("receiptRawListForm");
						QMdiSubWindow *recRawListWindow = new QMdiSubWindow;
						recRawListWindow->setWidget(dForm);
						recRawListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(recRawListWindow);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All raws for receipt product list are shown");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
					}
					else
					{
						delete dForm;
						QString message = tr("End with error!");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage = "";
					}
				}
				else
				{
					checkedWidget->topLevelWidget();
					checkedWidget->activateWindow();
					QString message = tr("All raws for receipt product list are shown");
					((MainForm*)parentWidget())->statusBar()->showMessage(message);
				}
			}
		}
		else if(objectName() == "returnForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				returnID = id;
			BusinessLayer::ReturnList *returnList = new BusinessLayer::ReturnList();
			returnList->SetReturnID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::ReturnList>(returnList);
			delete returnList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("returnListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Return list products"));
					dForm->FillTable<BusinessLayer::ReturnListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("returnListForm");
						QMdiSubWindow *retListWindow = new QMdiSubWindow;
						retListWindow->setWidget(dForm);
						retListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(retListWindow);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All products for return list are shown");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
					}
					else
					{
						delete dForm;
						QString message = tr("End with error!");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage = "";
					}
				}
				else
				{
					checkedWidget->topLevelWidget();
					checkedWidget->activateWindow();
					QString message = tr("All products for return list are shown");
					((MainForm*)parentWidget())->statusBar()->showMessage(message);
				}
			}
		}
		else if (objectName() == "transportForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				transportID = id;
			BusinessLayer::TransportList *transportList = new BusinessLayer::TransportList();
			transportList->SetTransportID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::TransportList>(transportList);
			delete transportList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("transportListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Transport list products"));
					dForm->FillTable<BusinessLayer::TransportListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("transportListForm");
						QMdiSubWindow *tranListWindow = new QMdiSubWindow;
						tranListWindow->setWidget(dForm);
						tranListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(tranListWindow);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All products for transport list are shown");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
					}
					else
					{
						delete dForm;
						QString message = tr("End with error!");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage = "";
					}
				}
				else
				{
					checkedWidget->topLevelWidget();
					checkedWidget->activateWindow();
					QString message = tr("All products for transport list are shown");
					((MainForm*)parentWidget())->statusBar()->showMessage(message);
				}
			}
		}
		else if (objectName() == "writeOffForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				productionID = id;
			BusinessLayer::WriteOffList *writeOffList = new BusinessLayer::WriteOffList();
			writeOffList->SetWriteOffID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::WriteOffList>(writeOffList);
			delete writeOffList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("writeOffListForm")); if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Write-off list products"));
					dForm->FillTable<BusinessLayer::WriteOffListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("writeOffListForm");
						QMdiSubWindow *wListWindow = new QMdiSubWindow;
						wListWindow->setWidget(dForm);
						wListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(wListWindow);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All products for write-off list are shown");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
					}
					else
					{
						delete dForm;
						QString message = tr("End with error!");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage = "";
					}
				}
				else
				{
					checkedWidget->topLevelWidget();
					checkedWidget->activateWindow();
					QString message = tr("All products for write-off list are shown");
					((MainForm*)parentWidget())->statusBar()->showMessage(message);
				}
			}
		}
		else if (objectName() == "writeOffRawForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				writeOffRawID = id;
			BusinessLayer::WriteOffRawList *writeOffRawList = new BusinessLayer::WriteOffRawList();
			writeOffRawList->SetWriteOffRawID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::WriteOffRawList>(writeOffRawList);
			delete writeOffRawList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("writeOffRawListForm")); if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Write-off raw list products"));
					dForm->FillTable<BusinessLayer::WriteOffRawListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("writeOffRawListForm");
						QMdiSubWindow *rawListWindow = new QMdiSubWindow;
						rawListWindow->setWidget(dForm);
						rawListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(rawListWindow);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All raws for write-off raw list are shown");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
					}
					else
					{
						delete dForm;
						QString message = tr("End with error!");
						((MainForm*)parentWidget())->statusBar()->showMessage(message);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage = "";
					}
				}
				else
				{
					checkedWidget->topLevelWidget();
					checkedWidget->activateWindow();
					QString message = tr("All raws for write-off raw list are shown");
					((MainForm*)parentWidget())->statusBar()->showMessage(message);
				}
			}
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage = "";
		}
	}
}

void DataForm::OnRowsNumberChanged()
{
	if (createOrdDlg != nullptr || createRtrnDlg != nullptr || createWOffDlg != nullptr)
	{

		double sum = 0;
		int count = 0;
		int currencyID = 0;
		if (tableView->model()->rowCount() > 0)
		{
			for (int i = 0; i < tableView->model()->rowCount(); i++)
			{
				sum = sum + tableView->model()->data(tableView->model()->index(i, 8)).toDouble();
				count = count + tableView->model()->data(tableView->model()->index(i, 7)).toDouble();
			}
			currencyID = tableView->model()->data(tableView->model()->index(0, 13)).toInt();
		}
		
		if (createConPDlg != nullptr)
		{
			createConPDlg->prodCountEdit->setText(QString::number(count));
			createConPDlg->sumEdit->setText(QString::number(sum));
			createConPDlg->currencyEdit->setText(QString::number(currencyID));
		}
		else if (createConRDlg != nullptr)
		{
			createConRDlg->prodCountEdit->setText(QString::number(count));
			createConRDlg->sumEdit->setText(QString::number(sum));
			createConRDlg->currencyEdit->setText(QString::number(currencyID));
		}
		else if (createInvDlg != nullptr)
		{
			createInvDlg->prodCountEdit->setText(QString::number(count));
			createInvDlg->sumEdit->setText(QString::number(sum));
			createInvDlg->currencyEdit->setText(QString::number(currencyID));
		}
		else if (createOrdDlg != nullptr)
		{
			createOrdDlg->prodCountEdit->setText(QString::number(count));
			createOrdDlg->sumEdit->setText(QString::number(sum));
			createOrdDlg->currencyEdit->setText(QString::number(currencyID));
		}
		else if (createOrdRDlg != nullptr)
		{
			createOrdRDlg->prodCountEdit->setText(QString::number(count));
			createOrdRDlg->sumEdit->setText(QString::number(sum));
			createOrdRDlg->currencyEdit->setText(QString::number(currencyID));
		}
		else if (createRcpPDlg != nullptr)
		{
			createRcpPDlg->prodCountEdit->setText(QString::number(count));
			createRcpPDlg->sumEdit->setText(QString::number(sum));
			createRcpPDlg->currencyEdit->setText(QString::number(currencyID));
		}
		else if (createRcpRDlg != nullptr)
		{
			createRcpRDlg->prodCountEdit->setText(QString::number(count));
			createRcpRDlg->sumEdit->setText(QString::number(sum));
			createRcpRDlg->currencyEdit->setText(QString::number(currencyID));
		}
		else if (createTrsDlg != nullptr)
		{
			createTrsDlg->prodCountEdit->setText(QString::number(count));
			createTrsDlg->sumEdit->setText(QString::number(sum));
			createTrsDlg->currencyEdit->setText(QString::number(currencyID));
		}
		else if (createRtrnDlg != nullptr)
		{
			createRtrnDlg->prodCountEdit->setText(QString::number(count));
			createRtrnDlg->sumEdit->setText(QString::number(sum));
			createRtrnDlg->currencyEdit->setText(QString::number(currencyID));
		}
		else if (createWOffDlg != nullptr)
		{
			createWOffDlg->prodCountEdit->setText(QString::number(count));
			createWOffDlg->sumEdit->setText(QString::number(sum));
			createWOffDlg->currencyEdit->setText(QString::number(currencyID));
		}
		else if (createWOffRDlg != nullptr)
		{
			createWOffRDlg->prodCountEdit->setText(QString::number(count));
			createWOffRDlg->sumEdit->setText(QString::number(sum));
			createWOffRDlg->currencyEdit->setText(QString::number(currencyID));
		}
	}
	if (createProdnDlg != nullptr)
	{
		int count = 0;
		if (tableView->model()->rowCount() > 0)
		{
			for (int i = 0; i < tableView->model()->rowCount(); i++)
			{
				count = count + tableView->model()->data(tableView->model()->index(i, 7)).toDouble();
			}
		}
		createProdnDlg->prodCountEdit->setText(QString::number(count));
	}
}

void DataForm::CrtAcsDlg()
{
	CreateAcsDlg *accessDlg = new CreateAcsDlg(dataFormBL, false, this);
	accessDlg->setAttribute(Qt::WA_DeleteOnClose);
	accessDlg->setWindowTitle(tr("Create access"));
	accessDlg->show();
}
void DataForm::UdpAcsDlg()
{
	CreateAcsDlg *accessDlg = new CreateAcsDlg(dataFormBL, true, this);
	accessDlg->setAttribute(Qt::WA_DeleteOnClose);
	accessDlg->setWindowTitle(tr("Update access"));
	if (accessDlg->FillDlgElements(tableView))
	{
		accessDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelAcsDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Access access;
	access.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteAccess(&access, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Access with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtAcsItemDlg()
{
	CreateAcsItemDlg *accessItemDlg = new CreateAcsItemDlg(dataFormBL, false, this);
	accessItemDlg->setAttribute(Qt::WA_DeleteOnClose);
	accessItemDlg->setWindowTitle(tr("Create access item"));
	accessItemDlg->show();
}
void DataForm::UdpAcsItemDlg()
{
	CreateAcsItemDlg *accessItemDlg = new CreateAcsItemDlg(dataFormBL, true, this);
	accessItemDlg->setAttribute(Qt::WA_DeleteOnClose);
	accessItemDlg->setWindowTitle(tr("Update access item"));
	if (accessItemDlg->FillDlgElements(tableView))
	{
		accessItemDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelAcsItemDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::AccessItem accessItem;
	accessItem.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteAccessItem(&accessItem, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Access item with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtBlcDlg()
{
	CreateBlcDlg *balanceDlg = new CreateBlcDlg(dataFormBL, false, this);
	balanceDlg->setAttribute(Qt::WA_DeleteOnClose);
	balanceDlg->setWindowTitle(tr("Create balance"));
	balanceDlg->show();
}
void DataForm::UdpBlcDlg()
{
	CreateBlcDlg *balanceDlg = new CreateBlcDlg(dataFormBL, true, this);
	balanceDlg->setAttribute(Qt::WA_DeleteOnClose);
	balanceDlg->setWindowTitle(tr("Update balance"));
	if (balanceDlg->FillDlgElements(tableView))
	{
		balanceDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelBlcDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Balance balance;
	balance.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteBalance(&balance, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Balance with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtCltDlg()
{
	CreateCltDlg *clientDlg = new CreateCltDlg(dataFormBL, false, this);
	clientDlg->setAttribute(Qt::WA_DeleteOnClose);
	clientDlg->setWindowTitle(tr("Create client"));
	clientDlg->show();
}
void DataForm::UdpCltDlg()
{
	CreateCltDlg *clientDlg = new CreateCltDlg(dataFormBL, true, this);
	clientDlg->setAttribute(Qt::WA_DeleteOnClose);
	clientDlg->setWindowTitle(tr("Update client"));
	if (clientDlg->FillDlgElements(tableView))
	{
		clientDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelCltDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Client client;
	client.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteClient(&client, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Client with this id does not exist!")),
			QString(tr("Ok")));
	}
}


void DataForm::CrtCmpDlg()
{
	CreateCmpDlg *companyDlg = new CreateCmpDlg(dataFormBL,false,this);
	companyDlg->setAttribute(Qt::WA_DeleteOnClose);
	companyDlg->setWindowTitle(tr("Create company"));
	companyDlg->show();
}
void DataForm::UdpCmpDlg()
{
	CreateCmpDlg *companyDlg = new CreateCmpDlg(dataFormBL,true, this);
	companyDlg->setAttribute(Qt::WA_DeleteOnClose);
	companyDlg->setWindowTitle(tr("Update company"));
	if (companyDlg->FillDlgElements(tableView))
	{
		companyDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelCmpDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Company company;
	company.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteCompany(&company, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Company with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtConPDlg()
{
	CreateConPDlg *conPDlg = new CreateConPDlg(dataFormBL, false, this);
	conPDlg->setAttribute(Qt::WA_DeleteOnClose);
	conPDlg->setWindowTitle(tr("Create consume product"));
	conPDlg->show();
}
void DataForm::UdpConPDlg()
{
	CreateConPDlg *conPDlg = new CreateConPDlg(dataFormBL, true, this);
	conPDlg->setAttribute(Qt::WA_DeleteOnClose);
	conPDlg->setWindowTitle(tr("Update consume product"));
	if (conPDlg->FillDlgElements(tableView))
	{
		conPDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelConPDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ConsumeProduct consumeProdcut;
	consumeProdcut.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteConsumeProduct(&consumeProdcut, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Consume product with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtConPListDlg()
{
	CreateConPListDlg *craeteConPListDlg = new CreateConPListDlg(dataFormBL, false, this);
	if (0 != consumeProductID)
	{
		craeteConPListDlg->consumeProductID = consumeProductID;
	}
	craeteConPListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteConPListDlg->setWindowTitle(tr("Add product to consume product list"));
	craeteConPListDlg->show();
}
void DataForm::UdpConPListDlg()
{
	CreateConPListDlg *craeteConPListDlg = new CreateConPListDlg(dataFormBL, true, this);
	craeteConPListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteConPListDlg->setWindowTitle(tr("Update product in consume product list"));
	if (craeteConPListDlg->FillDlgElements(tableView))
	{
		craeteConPListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelConPListDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ConsumeProductList consumeProductList;
	consumeProductList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteConsumeProductList(&consumeProductList, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Wrong id, cannot delete data from this row!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtConRDlg()
{
	CreateConRDlg *conRDlg = new CreateConRDlg(dataFormBL, false, this);
	conRDlg->setAttribute(Qt::WA_DeleteOnClose);
	conRDlg->setWindowTitle(tr("Create consume raw"));
	conRDlg->show();
}
void DataForm::UdpConRDlg()
{
	CreateConRDlg *conRDlg = new CreateConRDlg(dataFormBL, true, this);
	conRDlg->setAttribute(Qt::WA_DeleteOnClose);
	conRDlg->setWindowTitle(tr("Update consume raw"));
	if (conRDlg->FillDlgElements(tableView))
	{
		conRDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelConRDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ConsumeRaw consumeRaw;
	consumeRaw.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteConsumeRaw(&consumeRaw, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Consume raw with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtConRListDlg()
{
	CreateConRListDlg *craeteConRListDlg = new CreateConRListDlg(dataFormBL, false, this);
	if (0 != consumeRawID)
	{
		craeteConRListDlg->consumeRawID = consumeRawID;
	}
	craeteConRListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteConRListDlg->setWindowTitle(tr("Add raw to consume raw list"));
	craeteConRListDlg->show();
}
void DataForm::UdpConRListDlg()
{
	CreateConRListDlg *craeteConRListDlg = new CreateConRListDlg(dataFormBL, true, this);
	craeteConRListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteConRListDlg->setWindowTitle(tr("Update raw in consume raw list"));
	if (craeteConRListDlg->FillDlgElements(tableView))
	{
		craeteConRListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelConRListDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ConsumeRawList consumeRawList;
	consumeRawList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteConsumeRawList(&consumeRawList, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Wrong id, cannot delete data from this row!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtCurDlg()
{
	CreateCurDlg *currencyDlg = new CreateCurDlg(dataFormBL, false, this);
	currencyDlg->setAttribute(Qt::WA_DeleteOnClose);
	currencyDlg->setWindowTitle(tr("Create currency"));
	currencyDlg->show();
}
void DataForm::UdpCurDlg()
{
	CreateCurDlg *currencyDlg = new CreateCurDlg(dataFormBL, true, this);
	currencyDlg->setAttribute(Qt::WA_DeleteOnClose);
	currencyDlg->setWindowTitle(tr("Update currency"));
	if (currencyDlg->FillDlgElements(tableView))
	{
		currencyDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelCurDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Currency currency;
	currency.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteCurrency(&currency,errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Currency with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtEmpDlg()
{
	CreateEmpDlg *employeeDlg = new CreateEmpDlg(dataFormBL, false, this);
	employeeDlg->setAttribute(Qt::WA_DeleteOnClose);
	employeeDlg->setWindowTitle(tr("Create employee"));
	employeeDlg->show();
}
void DataForm::UdpEmpDlg()
{
	CreateEmpDlg *employeeDlg = new CreateEmpDlg(dataFormBL, true, this);
	employeeDlg->setAttribute(Qt::WA_DeleteOnClose);
	employeeDlg->setWindowTitle(tr("Update employee"));
	if (employeeDlg->FillDlgElements(tableView))
	{
		employeeDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelEmpDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Employee employee;
	employee.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteEmployee(&employee, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Employee with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtInvDlg()
{
	CreateInvDlg *invDlg = new CreateInvDlg(dataFormBL, false, this);
	invDlg->setAttribute(Qt::WA_DeleteOnClose);
	invDlg->setWindowTitle(tr("Create inventorization"));
	invDlg->show();
}
void DataForm::UdpInvDlg()
{
	CreateInvDlg *invDlg = new CreateInvDlg(dataFormBL, true, this);
	invDlg->setAttribute(Qt::WA_DeleteOnClose);
	invDlg->setWindowTitle(tr("Update inventorization"));
	if (invDlg->FillDlgElements(tableView))
	{
		invDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelInvDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Inventorization inv;
	inv.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteInventorization(&inv, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Inventorization with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtInvListDlg()
{
	CreateInvListDlg *craeteInvListDlg = new CreateInvListDlg(dataFormBL, false, this);
	if (0 != inventorizationID)
	{
		craeteInvListDlg->inventorizationID = inventorizationID;
	}
	craeteInvListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteInvListDlg->setWindowTitle(tr("Add product to inventorization list"));
	craeteInvListDlg->show();
}
void DataForm::UdpInvListDlg()
{
	CreateInvListDlg *craeteInvListDlg = new CreateInvListDlg(dataFormBL, true, this);
	craeteInvListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteInvListDlg->setWindowTitle(tr("Update product in inventorization list"));
	if (craeteInvListDlg->FillDlgElements(tableView))
	{
		craeteInvListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelInvListDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::InventorizationList invList;
	invList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteInventorizationList(&invList, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Wrong id, cannot delete data from this row!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtLcnDlg()
{
	CreateLcnDlg *locationDlg = new CreateLcnDlg(dataFormBL, false, this);
	locationDlg->setAttribute(Qt::WA_DeleteOnClose);
	locationDlg->setWindowTitle(tr("Create location"));
	locationDlg->show();
}
void DataForm::UdpLcnDlg()
{
	CreateLcnDlg *locationDlg = new CreateLcnDlg(dataFormBL, true, this);
	locationDlg->setAttribute(Qt::WA_DeleteOnClose);
	locationDlg->setWindowTitle(tr("Update location"));
	if (locationDlg->FillDlgElements(tableView))
	{
		locationDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelLcnDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Location location;
	location.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteLocation(&location, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Location with this id does not exist!")),
			QString(tr("Ok")));

	}
}


void DataForm::CrtMsrDlg()
{
	CreateMsrDlg *measureDlg = new CreateMsrDlg(dataFormBL, false, this);
	measureDlg->setAttribute(Qt::WA_DeleteOnClose);
	measureDlg->setWindowTitle(tr("Create measure"));
	measureDlg->show();
}
void DataForm::UdpMsrDlg()
{
	CreateMsrDlg *measureDlg = new CreateMsrDlg(dataFormBL, true, this);
	measureDlg->setAttribute(Qt::WA_DeleteOnClose);
	measureDlg->setWindowTitle(tr("Update currency"));
	if (measureDlg->FillDlgElements(tableView))
	{
		measureDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelMsrDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Measure measure;
	measure.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteMeasure(&measure,errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Measure with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtOrdDlg()
{
	CreateOrdDlg *orderDlg = new CreateOrdDlg(dataFormBL, false, this);
	orderDlg->setAttribute(Qt::WA_DeleteOnClose);
	orderDlg->setWindowTitle(tr("Create order"));
	orderDlg->show();
}
void DataForm::UdpOrdDlg()
{
	CreateOrdDlg *orderDlg = new CreateOrdDlg(dataFormBL, true, this);
	orderDlg->setAttribute(Qt::WA_DeleteOnClose);
	orderDlg->setWindowTitle(tr("Update order"));
	if (orderDlg->FillDlgElements(tableView))
	{
		orderDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelOrdDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Order order;
	order.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteOrder(&order, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Order with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtOrdListDlg()
{
	CreateOrdListDlg *craeteOrdListDlg = new CreateOrdListDlg(dataFormBL, false, this);
	if (0 != orderID)
	{
		craeteOrdListDlg->orderID = orderID;
	}
	craeteOrdListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteOrdListDlg->setWindowTitle(tr("Add product to order list"));
	craeteOrdListDlg->show();
}
void DataForm::UdpOrdListDlg()
{
	CreateOrdListDlg *craeteOrdListDlg = new CreateOrdListDlg(dataFormBL, true, this);
	craeteOrdListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteOrdListDlg->setWindowTitle(tr("Update product in order list"));
	if (craeteOrdListDlg->FillDlgElements(tableView))
	{
		craeteOrdListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelOrdListDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::OrderList orderList;
	orderList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteOrderList(&orderList, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Product with this id does not exist in order list!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtOrdRDlg()
{
	CreateOrdRDlg *orderRDlg = new CreateOrdRDlg(dataFormBL, false, this);
	orderRDlg->setAttribute(Qt::WA_DeleteOnClose);
	orderRDlg->setWindowTitle(tr("Create order raw"));
	orderRDlg->show();
}
void DataForm::UdpOrdRDlg()
{
	CreateOrdRDlg *orderRDlg = new CreateOrdRDlg(dataFormBL, true, this);
	orderRDlg->setAttribute(Qt::WA_DeleteOnClose);
	orderRDlg->setWindowTitle(tr("Update order raw"));
	if (orderRDlg->FillDlgElements(tableView))
	{
		orderRDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelOrdRDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::OrderRaw orderRaw;
	orderRaw.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteOrderRaw(&orderRaw, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Order raw with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtOrdRListDlg()
{
	CreateOrdRListDlg *craeteOrdRListDlg = new CreateOrdRListDlg(dataFormBL, false, this);
	if (0 != orderRawID)
	{
		craeteOrdRListDlg->orderRawID = orderRawID;
	}
	craeteOrdRListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteOrdRListDlg->setWindowTitle(tr("Add raw to order list"));
	craeteOrdRListDlg->show();
}
void DataForm::UdpOrdRListDlg()
{
	CreateOrdRListDlg *craeteOrdRListDlg = new CreateOrdRListDlg(dataFormBL, true, this);
	craeteOrdRListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteOrdRListDlg->setWindowTitle(tr("Update raw in order list"));
	if (craeteOrdRListDlg->FillDlgElements(tableView))
	{
		craeteOrdRListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelOrdRListDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::OrderRawList orderRawList;
	orderRawList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteOrderRawList(&orderRawList, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Raw with this id does not exist in order list!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtPhotoDlg()
{
	CreatePhtDlg *photoDlg = new CreatePhtDlg(dataFormBL, false, this);
	photoDlg->setAttribute(Qt::WA_DeleteOnClose);
	photoDlg->setWindowTitle(tr("Create photo"));
	photoDlg->show();
}
void DataForm::UdpPhotoDlg()
{
	CreatePhtDlg *photoDlg = new CreatePhtDlg(dataFormBL, true, this);
	photoDlg->setAttribute(Qt::WA_DeleteOnClose);
	photoDlg->setWindowTitle(tr("Update photo"));
	if (photoDlg->FillDlgElements(tableView))
	{
		photoDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelPhotoDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Photo photo;
	photo.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeletePhoto(&photo, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Photo with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtPmtDlg()
{
	CreatePmtDlg *paymentDlg = new CreatePmtDlg(dataFormBL, false, this);
	paymentDlg->setAttribute(Qt::WA_DeleteOnClose);
	paymentDlg->setWindowTitle(tr("Create payment"));
	paymentDlg->show();
}
void DataForm::UdpPmtDlg()
{
	CreatePmtDlg *paymentDlg = new CreatePmtDlg(dataFormBL, true, this);
	paymentDlg->setAttribute(Qt::WA_DeleteOnClose);
	paymentDlg->setWindowTitle(tr("Update payment"));
	if (paymentDlg->FillDlgElements(tableView))
	{
		paymentDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelPmtDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Payment payment;
	payment.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeletePayment(&payment, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Payment with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtPosDlg()
{
	CreatePosDlg *positionDlg = new CreatePosDlg(dataFormBL, false, this);
	positionDlg->setAttribute(Qt::WA_DeleteOnClose);
	positionDlg->setWindowTitle(tr("Create position"));
	positionDlg->show();
}
void DataForm::UdpPosDlg()
{
	CreatePosDlg *positionDlg = new CreatePosDlg(dataFormBL, true, this);
	positionDlg->setAttribute(Qt::WA_DeleteOnClose);
	positionDlg->setWindowTitle(tr("Update position"));
	if (positionDlg->FillDlgElements(tableView))
	{
		positionDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelPosDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Position position;
	position.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeletePosition(&position, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Position with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtPrcDlg()
{
	CreatePrcDlg *priceDlg = new CreatePrcDlg(dataFormBL, false, this);
	priceDlg->setAttribute(Qt::WA_DeleteOnClose);
	priceDlg->setWindowTitle(tr("Create price"));
	priceDlg->show();
}
void DataForm::UdpPrcDlg()
{
	CreatePrcDlg *priceDlg = new CreatePrcDlg(dataFormBL, true, this);
	priceDlg->setAttribute(Qt::WA_DeleteOnClose);
	priceDlg->setWindowTitle(tr("Update price"));
	if (priceDlg->FillDlgElements(tableView))
	{
		priceDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelPrcDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Price price;
	price.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeletePrice(&price, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Price with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtProdTpDlg()
{
	CreatePrdTpDlg *prodTypeDlg = new CreatePrdTpDlg(dataFormBL, false, this);
	prodTypeDlg->setAttribute(Qt::WA_DeleteOnClose);
	prodTypeDlg->setWindowTitle(tr("Create product type"));
	prodTypeDlg->show();
}
void DataForm::UdpProdTpDlg()
{
	CreatePrdTpDlg *prodTpDlg = new CreatePrdTpDlg(dataFormBL, true, this);
	prodTpDlg->setAttribute(Qt::WA_DeleteOnClose);
	prodTpDlg->setWindowTitle(tr("Update product type"));
	if (prodTpDlg->FillDlgElements(tableView))
	{
		prodTpDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelProdTpDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ProductType prodTp;
	prodTp.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteProductType(&prodTp,errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Product type with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtProdDlg()
{
	CreateProdDlg *prodDlg = new CreateProdDlg(dataFormBL, false, this);
	prodDlg->setAttribute(Qt::WA_DeleteOnClose);
	prodDlg->setWindowTitle(tr("Create product"));
	prodDlg->show();
}
void DataForm::UdpProdDlg()
{
	CreateProdDlg *prodDlg = new CreateProdDlg(dataFormBL, true, this);
	prodDlg->setAttribute(Qt::WA_DeleteOnClose);
	prodDlg->setWindowTitle(tr("Update product"));
	if (prodDlg->FillDlgElements(tableView))
	{
		prodDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelProdDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Product prod;
	prod.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteProduct(&prod, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Product with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtProdnDlg()
{
	CreateProdnDlg *prodnDlg = new CreateProdnDlg(dataFormBL, false, this);
	prodnDlg->setAttribute(Qt::WA_DeleteOnClose);
	prodnDlg->setWindowTitle(tr("Create production"));
	prodnDlg->show();
}
void DataForm::UdpProdnDlg()
{
	CreateProdnDlg *prodnDlg = new CreateProdnDlg(dataFormBL, true, this);
	prodnDlg->setAttribute(Qt::WA_DeleteOnClose);
	prodnDlg->setWindowTitle(tr("Update production"));
	if (prodnDlg->FillDlgElements(tableView))
	{
		prodnDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelProdnDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Production prodn;
	prodn.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteProduction(&prodn, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Production with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtProdnListDlg()
{
	CreateProdnListDlg *craeteProdnListDlg = new CreateProdnListDlg(dataFormBL, false, this);
	if (0 != productionID)
	{
		craeteProdnListDlg->productionID = productionID;
	}
	craeteProdnListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteProdnListDlg->setWindowTitle(tr("Add product to production list"));
	craeteProdnListDlg->show();
}
void DataForm::UdpProdnListDlg()
{
	CreateProdnListDlg *craeteProdnListDlg = new CreateProdnListDlg(dataFormBL, true, this);
	craeteProdnListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteProdnListDlg->setWindowTitle(tr("Update product in production list"));
	if (craeteProdnListDlg->FillDlgElements(tableView))
	{
		craeteProdnListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelProdnListDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ProductionList productionList;
	productionList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteProductionList(&productionList, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Product with this id does not exist in production list!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtPspDlg()
{
	CreatePspDlg *payslipDlg = new CreatePspDlg(dataFormBL, false, this);
	payslipDlg->setAttribute(Qt::WA_DeleteOnClose);
	payslipDlg->setWindowTitle(tr("Create payslip"));
	payslipDlg->show();
}
void DataForm::UdpPspDlg()
{
	CreatePspDlg *payslipDlg = new CreatePspDlg(dataFormBL, true, this);
	payslipDlg->setAttribute(Qt::WA_DeleteOnClose);
	payslipDlg->setWindowTitle(tr("Update payslip"));
	if (payslipDlg->FillDlgElements(tableView))
	{
		payslipDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelPspDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Payslip payslip;
	payslip.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeletePayslip(&payslip, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Payslip with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtRelDlg()
{
	CreateRelDlg *relationDlg = new CreateRelDlg(dataFormBL, false, this);
	relationDlg->setAttribute(Qt::WA_DeleteOnClose);
	relationDlg->setWindowTitle(tr("Create relation"));
	relationDlg->show();
}
void DataForm::UdpRelDlg()
{
	CreateRelDlg *relationDlg = new CreateRelDlg(dataFormBL, true, this);
	relationDlg->setAttribute(Qt::WA_DeleteOnClose);
	relationDlg->setWindowTitle(tr("Update relation"));
	if (relationDlg->FillDlgElements(tableView))
	{
		relationDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelRelDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Relation relation;
	relation.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteRelation(&relation, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Relation with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtRelTypeDlg()
{
	CreateRelTypeDlg *relationTypeDlg = new CreateRelTypeDlg(dataFormBL, false, this);
	relationTypeDlg->setAttribute(Qt::WA_DeleteOnClose);
	relationTypeDlg->setWindowTitle(tr("Create relation type"));
	relationTypeDlg->show();
}
void DataForm::UdpRelTypeDlg()
{
	CreateRelTypeDlg *relationTypeDlg = new CreateRelTypeDlg(dataFormBL, true, this);
	relationTypeDlg->setAttribute(Qt::WA_DeleteOnClose);
	relationTypeDlg->setWindowTitle(tr("Update relation type"));
	if (relationTypeDlg->FillDlgElements(tableView))
	{
		relationTypeDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelRelTypeDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::RelationType relationType;
	relationType.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteRelationType(&relationType, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Relation type with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtRcpPDlg()
{
	CreateRcpPDlg *rcpPDlg = new CreateRcpPDlg(dataFormBL, false, this);
	rcpPDlg->setAttribute(Qt::WA_DeleteOnClose);
	rcpPDlg->setWindowTitle(tr("Create receipt product"));
	rcpPDlg->show();
}
void DataForm::UdpRcpPDlg()
{
	CreateRcpPDlg *rcpPDlg = new CreateRcpPDlg(dataFormBL, true, this);
	rcpPDlg->setAttribute(Qt::WA_DeleteOnClose);
	rcpPDlg->setWindowTitle(tr("Update receipt product"));
	if (rcpPDlg->FillDlgElements(tableView))
	{
		rcpPDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelRcpPDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ReceiptProduct receiptProdcut;
	receiptProdcut.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteReceiptProduct(&receiptProdcut, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Receipt product with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtRcpPListDlg()
{
	CreateRcpPListDlg *craeteRcpPListDlg = new CreateRcpPListDlg(dataFormBL, false, this);
	if (0 != receiptProductID)
	{
		craeteRcpPListDlg->receiptProductID = receiptProductID;
	}
	craeteRcpPListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteRcpPListDlg->setWindowTitle(tr("Add product to receipt product list"));
	craeteRcpPListDlg->show();
}
void DataForm::UdpRcpPListDlg()
{
	CreateRcpPListDlg *craeteRcpPListDlg = new CreateRcpPListDlg(dataFormBL, true, this);
	craeteRcpPListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteRcpPListDlg->setWindowTitle(tr("Update product in receipt product list"));
	if (craeteRcpPListDlg->FillDlgElements(tableView))
	{
		craeteRcpPListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelRcpPListDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ReceiptProductList receiptProductList;
	receiptProductList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteReceiptProductList(&receiptProductList, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Wrong id, cannot delete data from this row!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtRcpRDlg()
{
	CreateConRDlg *rcpRDlg = new CreateConRDlg(dataFormBL, false, this);
	rcpRDlg->setAttribute(Qt::WA_DeleteOnClose);
	rcpRDlg->setWindowTitle(tr("Receipt receipt raw"));
	rcpRDlg->show();
}
void DataForm::UdpRcpRDlg()
{
	CreateConRDlg *rcpRDlg = new CreateConRDlg(dataFormBL, true, this);
	rcpRDlg->setAttribute(Qt::WA_DeleteOnClose);
	rcpRDlg->setWindowTitle(tr("Update receipt raw"));
	if (rcpRDlg->FillDlgElements(tableView))
	{
		rcpRDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelRcpRDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ReceiptRaw receiptRaw;
	receiptRaw.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteReceiptRaw(&receiptRaw, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Consume raw with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtRcpRListDlg()
{
	CreateRcpRListDlg *craeteRcpRListDlg = new CreateRcpRListDlg(dataFormBL, false, this);
	if (0 != receiptRawID)
	{
		craeteRcpRListDlg->receiptRawID = receiptRawID;
	}
	craeteRcpRListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteRcpRListDlg->setWindowTitle(tr("Add raw to receipt raw list"));
	craeteRcpRListDlg->show();
}
void DataForm::UdpRcpRListDlg()
{
	CreateRcpRListDlg *craeteRcpRListDlg = new CreateRcpRListDlg(dataFormBL, true, this);
	craeteRcpRListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteRcpRListDlg->setWindowTitle(tr("Update raw in receipt raw list"));
	if (craeteRcpRListDlg->FillDlgElements(tableView))
	{
		craeteRcpRListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelRcpRListDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ReceiptRawList receiptRawList;
	receiptRawList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteReceiptRawList(&receiptRawList, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Wrong id, cannot delete data from this row!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtRfdDlg()
{
	CreateRfdDlg *refundDlg = new CreateRfdDlg(dataFormBL, false, this);
	refundDlg->setAttribute(Qt::WA_DeleteOnClose);
	refundDlg->setWindowTitle(tr("Create refund"));
	refundDlg->show();
}
void DataForm::UdpRfdDlg()
{
	CreateRfdDlg *refundDlg = new CreateRfdDlg(dataFormBL, true, this);
	refundDlg->setAttribute(Qt::WA_DeleteOnClose);
	refundDlg->setWindowTitle(tr("Update refund"));
	if (refundDlg->FillDlgElements(tableView))
	{
		refundDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelRfdDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Refund refund;
	refund.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteRefund(&refund, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Refund with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtRoleDlg()
{
	CreateRoleDlg *roleDlg = new CreateRoleDlg(dataFormBL, false, this);
	roleDlg->setAttribute(Qt::WA_DeleteOnClose);
	roleDlg->setWindowTitle(tr("Create role"));
	roleDlg->show();
}
void DataForm::UdpRoleDlg()
{
	CreateRoleDlg *roleDlg = new CreateRoleDlg(dataFormBL, true, this);
	roleDlg->setAttribute(Qt::WA_DeleteOnClose);
	roleDlg->setWindowTitle(tr("Update role"));
	if (roleDlg->FillDlgElements(tableView))
	{
		roleDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelRoleDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Role role;
	role.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteRole(&role, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Role with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtRtrnDlg()
{
	CreateRtrnDlg *returnDlg = new CreateRtrnDlg(dataFormBL, false, this);
	returnDlg->setAttribute(Qt::WA_DeleteOnClose);
	returnDlg->setWindowTitle(tr("Create return"));
	returnDlg->show();
}
void DataForm::UdpRtrnDlg()
{
	CreateRtrnDlg *returnDlg = new CreateRtrnDlg(dataFormBL, true, this);
	returnDlg->setAttribute(Qt::WA_DeleteOnClose);
	returnDlg->setWindowTitle(tr("Update return"));
	if (returnDlg->FillDlgElements(tableView))
	{
		returnDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelRtrnDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Return ret;
	ret.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteReturn(&ret, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Return with this id does not exist!")),
			QString(tr("Ok")));

	}
}

void DataForm::CrtRtrnListDlg()
{
	CreateRtrnListDlg *craeteRtrnListDlg = new CreateRtrnListDlg(dataFormBL, false, this);
	if (0 != returnID)
	{
		craeteRtrnListDlg->returnID = returnID;
	}
	craeteRtrnListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteRtrnListDlg->setWindowTitle(tr("Add product to return list"));
	craeteRtrnListDlg->show();
}
void DataForm::UdpRtrnListDlg()
{
	CreateRtrnListDlg *craeteRtrnListDlg = new CreateRtrnListDlg(dataFormBL, true, this);
	craeteRtrnListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteRtrnListDlg->setWindowTitle(tr("Update product in return list"));
	if (craeteRtrnListDlg->FillDlgElements(tableView))
	{
		craeteRtrnListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelRtrnListDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ReturnList returnList;
	returnList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteReturnList(&returnList, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Product with this id does not exist in return list!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtSlrDlg()
{
	CreateSlrDlg *salaryDlg = new CreateSlrDlg(dataFormBL, false, this);
	salaryDlg->setAttribute(Qt::WA_DeleteOnClose);
	salaryDlg->setWindowTitle(tr("Create salary"));
	salaryDlg->show();
}
void DataForm::UdpSlrDlg()
{
	CreateSlrDlg *salaryDlg = new CreateSlrDlg(dataFormBL, true, this);
	salaryDlg->setAttribute(Qt::WA_DeleteOnClose);
	salaryDlg->setWindowTitle(tr("Update salary"));
	if (salaryDlg->FillDlgElements(tableView))
	{
		salaryDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelSlrDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Salary salary;
	salary.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteSalary(&salary, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Salary with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtSlrTypeDlg()
{
	CreateSlrTypeDlg *salaryTypeDlg = new CreateSlrTypeDlg(dataFormBL, false, this);
	salaryTypeDlg->setAttribute(Qt::WA_DeleteOnClose);
	salaryTypeDlg->setWindowTitle(tr("Create salary type" ));
	salaryTypeDlg->show();
}
void DataForm::UdpSlrTypeDlg()
{
	CreateSlrTypeDlg *salaryTypeDlg = new CreateSlrTypeDlg(dataFormBL, true, this);
	salaryTypeDlg->setAttribute(Qt::WA_DeleteOnClose);
	salaryTypeDlg->setWindowTitle(tr("Update salary type"));
	if (salaryTypeDlg->FillDlgElements(tableView))
	{
		salaryTypeDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelSlrTypeDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::SalaryType salaryType;
	salaryType.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteSalaryType(&salaryType, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Salary type with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtStsDlg()
{
	CreateStsDlg *statusDlg = new CreateStsDlg(dataFormBL, false, this);
	statusDlg->setAttribute(Qt::WA_DeleteOnClose);
	statusDlg->setWindowTitle(tr("Create status"));
	statusDlg->show();
}
void DataForm::UdpStsDlg()
{
	CreateStsDlg *statusDlg = new CreateStsDlg(dataFormBL, true, this);
	statusDlg->setAttribute(Qt::WA_DeleteOnClose);
	statusDlg->setWindowTitle(tr("Update status"));
	if (statusDlg->FillDlgElements(tableView))
	{
		statusDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelStsDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Status status;
	status.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteStatus(&status,errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Status with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtStockDlg()
{
	CreateStockDlg *stockDlg = new CreateStockDlg(dataFormBL, false, this);
	stockDlg->setAttribute(Qt::WA_DeleteOnClose);
	stockDlg->setWindowTitle(tr("Create stock"));
	stockDlg->show();
}
void DataForm::UdpStockDlg()
{
	CreateStockDlg *stockDlg = new CreateStockDlg(dataFormBL, true, this);
	stockDlg->setAttribute(Qt::WA_DeleteOnClose);
	stockDlg->setWindowTitle(tr("Update stock"));
	if (stockDlg->FillDlgElements(tableView))
	{
		stockDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelStockDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Stock stock;
	stock.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteStock(&stock, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Receipt product with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtTrsDlg()
{
	CreateTrsDlg *trsDlg = new CreateTrsDlg(dataFormBL, false, this);
	trsDlg->setAttribute(Qt::WA_DeleteOnClose);
	trsDlg->setWindowTitle(tr("Create transport"));
	trsDlg->show();
}
void DataForm::UdpTrsDlg()
{
	CreateTrsDlg *trsDlg = new CreateTrsDlg(dataFormBL, true, this);
	trsDlg->setAttribute(Qt::WA_DeleteOnClose);
	trsDlg->setWindowTitle(tr("Update transport"));
	if (trsDlg->FillDlgElements(tableView))
	{
		trsDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelTrsDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Transport transport;
	transport.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteTransport(&transport, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Transport with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtTrsListDlg()
{
	CreateTrsListDlg *craeteTrsListDlg = new CreateTrsListDlg(dataFormBL, false, this);
	if (0 != transportID)
	{
		craeteTrsListDlg->transportID = transportID;
	}
	craeteTrsListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteTrsListDlg->setWindowTitle(tr("Add product to transport list"));
	craeteTrsListDlg->show();
}
void DataForm::UdpTrsListDlg()
{
	CreateTrsListDlg *craeteTrsListDlg = new CreateTrsListDlg(dataFormBL, true, this);
	craeteTrsListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteTrsListDlg->setWindowTitle(tr("Update product in transport list"));
	if (craeteTrsListDlg->FillDlgElements(tableView))
	{
		craeteTrsListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelTrsListDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::TransportList transportList;
	transportList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteTransportList(&transportList, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Wrong id, cannot delete data from this row!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtUserDlg()
{
	CreateUserDlg *userDlg = new CreateUserDlg(dataFormBL, false, this);
	userDlg->setAttribute(Qt::WA_DeleteOnClose);
	userDlg->setWindowTitle(tr("Create user"));
	userDlg->show();
}
void DataForm::UdpUserDlg()
{
	CreateUserDlg *userDlg = new CreateUserDlg(dataFormBL, true, this);
	userDlg->setAttribute(Qt::WA_DeleteOnClose);
	userDlg->setWindowTitle(tr("Update user"));
	if (userDlg->FillDlgElements(tableView))
	{
		userDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelUserDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::User user;
	user.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteUser(&user, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("User with this id does not exist!")),
			QString(tr("Ok")));
	}
}


void DataForm::CrtWdwDlg()
{
	CreateWdwDlg *withdrawalDlg = new CreateWdwDlg(dataFormBL, false, this);
	withdrawalDlg->setAttribute(Qt::WA_DeleteOnClose);
	withdrawalDlg->setWindowTitle(tr("Create withdrawal"));
	withdrawalDlg->show();
}
void DataForm::UdpWdwDlg()
{
	CreateWdwDlg *withdrawalDlg = new CreateWdwDlg(dataFormBL, true, this);
	withdrawalDlg->setAttribute(Qt::WA_DeleteOnClose);
	withdrawalDlg->setWindowTitle(tr("Update withdrawal"));
	if (withdrawalDlg->FillDlgElements(tableView))
	{
		withdrawalDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelWdwDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Withdrawal withdrawal;
	withdrawal.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteWithdrawal(&withdrawal, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Withdrawal with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtWOffDlg()
{
	CreateWOffDlg *writeOffDlg = new CreateWOffDlg(dataFormBL, false, this);
	writeOffDlg->setAttribute(Qt::WA_DeleteOnClose);
	writeOffDlg->setWindowTitle(tr("Create write-off"));
	writeOffDlg->show();
}
void DataForm::UdpWOffDlg()
{
	CreateWOffDlg *writeOffDlg = new CreateWOffDlg(dataFormBL, true, this);
	writeOffDlg->setAttribute(Qt::WA_DeleteOnClose);
	writeOffDlg->setWindowTitle(tr("Update write-off"));
	if (writeOffDlg->FillDlgElements(tableView))
	{
		writeOffDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelWOffDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::WriteOff writeOff;
	writeOff.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteWriteOff(&writeOff, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Write-off with this id does not exist!")),
			QString(tr("Ok")));

	}
}

void DataForm::CrtWOffListDlg()
{
	CreateWOffListDlg *craeteWOffListDlg = new CreateWOffListDlg(dataFormBL, false, this);
	if (0 != writeOffID)
	{
		craeteWOffListDlg->writeOffID = writeOffID;
	}
	craeteWOffListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteWOffListDlg->setWindowTitle(tr("Add product to write-off list"));
	craeteWOffListDlg->show();
}
void DataForm::UdpWOffListDlg()
{
	CreateWOffListDlg *craeteWOffListDlg = new CreateWOffListDlg(dataFormBL, true, this);
	craeteWOffListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteWOffListDlg->setWindowTitle(tr("Update product in write-off list"));
	if (craeteWOffListDlg->FillDlgElements(tableView))
	{
		craeteWOffListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelWOffListDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::WriteOffList writeOffList;
	writeOffList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteWriteOffList(&writeOffList, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Product with this id does not exist in write-off list!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtWOffRDlg()
{
	CreateWOffRDlg *writeOffRDlg = new CreateWOffRDlg(dataFormBL, false, this);
	writeOffRDlg->setAttribute(Qt::WA_DeleteOnClose);
	writeOffRDlg->setWindowTitle(tr("Create write-off raw"));
	writeOffRDlg->show();
}
void DataForm::UdpWOffRDlg()
{
	CreateWOffRDlg *writeOffRDlg = new CreateWOffRDlg(dataFormBL, true, this);
	writeOffRDlg->setAttribute(Qt::WA_DeleteOnClose);
	writeOffRDlg->setWindowTitle(tr("Update write-off raw"));
	if (writeOffRDlg->FillDlgElements(tableView))
	{
		writeOffRDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelWOffRDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::WriteOffRaw writeOffRaw;
	writeOffRaw.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteWriteOffRaw(&writeOffRaw, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Write-off raw with this id does not exist!")),
			QString(tr("Ok")));

	}
}

void DataForm::CrtWOffRListDlg()
{
	CreateWOffRListDlg *craeteWOffRListDlg = new CreateWOffRListDlg(dataFormBL, false, this);
	if (0 != writeOffRawID)
	{
		craeteWOffRListDlg->writeOffRawID = writeOffRawID;
	}
	craeteWOffRListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteWOffRListDlg->setWindowTitle(tr("Add raw to write-off list"));
	craeteWOffRListDlg->show();
}
void DataForm::UdpWOffRListDlg()
{
	CreateWOffRListDlg *craeteWOffRListDlg = new CreateWOffRListDlg(dataFormBL, true, this);
	craeteWOffRListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteWOffRListDlg->setWindowTitle(tr("Update raw in write-off list"));
	if (craeteWOffRListDlg->FillDlgElements(tableView))
	{
		craeteWOffRListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelWOffRListDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::WriteOffRawList writeOffRawList;
	writeOffRawList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteWriteOffRawList(&writeOffRawList, errorMessage))
		{
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Wrong id, cannot delete data from this row!")),
			QString(tr("Ok")));
	}
}

// Template specializations for generating headers of table ------------------------------
template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Access>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Role ID") << QObject::tr("Access item ID");
	return header;
}
template<>
QStringList DataForm::GetTableHeader<BusinessLayer::AccessItem>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Item english name") << QObject::tr("Item russian name") << QObject::tr("Division");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::BalanceView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("User name") << QObject::tr("User surname") << QObject::tr("Value") 
		<< QObject::tr("Currency name") << QObject::tr("User ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ClientView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Name") << QObject::tr("Surname") << QObject::tr("Phone") << QObject::tr("Country name")
		<< QObject::tr("Region name") << QObject::tr("City name") << QObject::tr("Address") << QObject::tr("Firm") 
		<< QObject::tr("Firm number") << QObject::tr("Role name") << QObject::tr("Password") << QObject::tr("Email")
		<< QObject::tr("Avtivated") << QObject::tr("Role ID") << QObject::tr("Location ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Company>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Name") << QObject::tr("Address") << QObject::tr("Phone") << QObject::tr("Comment");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ConsumeProductView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Consume date") << QObject::tr("Execution date") << QObject::tr("Status code")
		<< QObject::tr("Status name") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Product count") << QObject::tr("Sum") << QObject::tr("Currency name")
		<< QObject::tr("Employee ID") << QObject::tr("Client ID") << QObject::tr("Status ID") << QObject::tr("Currency ID")
		<< QObject::tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ConsumeProductListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Consume ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ConsumeRawView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Consume raw date") << QObject::tr("Execution date") << QObject::tr("Status code")
		<< QObject::tr("Status name") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Product count") << QObject::tr("Sum") << QObject::tr("Currency name")
		<< QObject::tr("Employee ID") << QObject::tr("Client ID") << QObject::tr("Status ID") << QObject::tr("Currency ID")
		<< QObject::tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ConsumeRawListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Consume raw ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Currency>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Code") << QObject::tr("Short name") << QObject::tr("Name") 
		<< QObject::tr("Change unit") << QObject::tr("Main trade currency");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::EmployeeView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Name") << QObject::tr("Surname") << QObject::tr("Position name") 
		<< QObject::tr("Phone") << QObject::tr("Address") << QObject::tr("Birth date") << QObject::tr("Role name") 
		<< QObject::tr("Hire date") << QObject::tr("Password") << QObject::tr("Email")
		<< QObject::tr("Avtivated") << QObject::tr("Role ID") << QObject::tr("Position ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::InventorizationView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Inventorization date") << QObject::tr("Execution date") << QObject::tr("Status code")
		<< QObject::tr("Status name") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Product count") << QObject::tr("Sum") << QObject::tr("Currency name")
		<< QObject::tr("Employee ID") << QObject::tr("Client ID") << QObject::tr("Status ID") << QObject::tr("Currency ID")
		<< QObject::tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::InventorizationListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Inventorization ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Location>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Country name") << QObject::tr("Country code") 
		<< QObject::tr("Region name") << QObject::tr("City name");
	return header;
}


template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Measure>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Name") << QObject::tr("Short name") << QObject::tr("Change unit");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::OrderView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Order date") << QObject::tr("Execution date") << QObject::tr("Status code") 
		<< QObject::tr("Status name") << QObject::tr("Client name") << QObject::tr("Client surname") << QObject::tr("Client phone") 
		<< QObject::tr("Client address") << QObject::tr("Client firm") << QObject::tr("Employee name") << QObject::tr("Employee surname")
		<< QObject::tr("Employee phone") << QObject::tr("Product count") << QObject::tr("Sum") << QObject::tr("Currency name") 
		<< QObject::tr("Employee ID") << QObject::tr("Client ID") << QObject::tr("Status ID") << QObject::tr("Currency ID") 
		<< QObject::tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::OrderListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Order ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count") 
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::OrderRawView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Order raw date") << QObject::tr("Execution date") << QObject::tr("Status code")
		<< QObject::tr("Status name") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Product count") << QObject::tr("Sum") << QObject::tr("Currency name")
		<< QObject::tr("Employee ID") << QObject::tr("Client ID") << QObject::tr("Status ID") << QObject::tr("Currency ID")
		<< QObject::tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::OrderRawListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Order raw ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}


template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Photo>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("User ID") << QObject::tr("Product ID") << QObject::tr("Source");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::PaymentView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Date") << QObject::tr("Value") << QObject::tr("Currency name") << QObject::tr("User ID")
		<< QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Position>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Name");
	return header;
}


template<>
QStringList DataForm::GetTableHeader<BusinessLayer::PriceView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Date") << QObject::tr("Product name") << QObject::tr("Volume") << QObject::tr("Measure name")
		<< QObject::tr("Value") << QObject::tr("Currency name") << QObject::tr("Currency ID") << QObject::tr("Product ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ProductType>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Name") << QObject::tr("Short name");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ProductView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Name") << QObject::tr("Price") << QObject::tr("Currency name") << QObject::tr("Volume") 
		<< QObject::tr("Measure name") << QObject::tr("Product type name") << QObject::tr("Shelf life") << QObject::tr("Company name") 
		<< QObject::tr("Company ID") << QObject::tr("Measure ID") << QObject::tr("Product type ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Production>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Production Date") << QObject::tr("Expiry Date") << QObject::tr("Session start") 
		<< QObject::tr("Session end") << QObject::tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ProductionListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Production ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}


template<>
QStringList DataForm::GetTableHeader<BusinessLayer::PayslipView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Date") << QObject::tr("Value") << QObject::tr("Currency name") 
		<< QObject::tr("Salary ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Relation>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("User 1") << QObject::tr("User 2") << QObject::tr("Relation type");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::RelationType>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Name") << QObject::tr("Comment");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ReturnView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Return date") << QObject::tr("Execution date") << QObject::tr("Status code") 
		<< QObject::tr("Status name") << QObject::tr("Client name") << QObject::tr("Client surname")
		<< QObject::tr("Client phone") << QObject::tr("Client address") << QObject::tr("Client firm") << QObject::tr("Employee name")
		<< QObject::tr("Employee surname") << QObject::tr("Employee phone") << QObject::tr("Product count") << QObject::tr("Sum")
		<< QObject::tr("Currency name") << QObject::tr("Employee ID") << QObject::tr("Client ID")
		<< QObject::tr("Status ID") << QObject::tr("Currency ID") << QObject::tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ReturnListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Return ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count") 
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::RefundView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Date") << QObject::tr("Value") << QObject::tr("Currency name") << QObject::tr("User ID") 
		<< QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Role>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Code") << QObject::tr("Name") << QObject::tr("Comment");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::SalaryType>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Code") << QObject::tr("Name");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::SalaryView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("User ID") << QObject::tr("Employee name") << QObject::tr("Employee surname") 
		<< QObject::tr("Employee phone") << QObject::tr("Date") << QObject::tr("Value") << QObject::tr("Currency name") 
		<< QObject::tr("Salary type name") << QObject::tr("Currency ID") << QObject::tr("Salary type ID") << QObject::tr("Is bonus?");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Status>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Code") << QObject::tr("Name") << QObject::tr("Comment");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::StockView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::TransportView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Transportation date") << QObject::tr("Execution date") << QObject::tr("Status code")
		<< QObject::tr("Status name") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Product count") << QObject::tr("Sum") << QObject::tr("Currency name")
		<< QObject::tr("Employee ID") << QObject::tr("Client ID") << QObject::tr("Status ID") << QObject::tr("Currency ID")
		<< QObject::tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::TransportListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Transport ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}


template<>
QStringList DataForm::GetTableHeader<BusinessLayer::UserView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Email") << QObject::tr("Name") << QObject::tr("Surname") << QObject::tr("Phone") 
		<< QObject::tr("Address") << QObject::tr("Role name") << QObject::tr("Password") << QObject::tr("Avtivated") << QObject::tr("Role ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::WithdrawalView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Date") << QObject::tr("Value") << QObject::tr("Currency name") 
		<< QObject::tr("User ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::WriteOffView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Write-off date") << QObject::tr("Status code") << QObject::tr("Status name") 
		<< QObject::tr("Client name") << QObject::tr("Client surname") << QObject::tr("Client phone") << QObject::tr("Client address")
		<< QObject::tr("Client firm") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone") 
		<< QObject::tr("Product count") << QObject::tr("Sum") << QObject::tr("Currency name") << QObject::tr("Employee ID")
		<< QObject::tr("Client ID") << QObject::tr("Status ID") << QObject::tr("Currency ID") << QObject::tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::WriteOffListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Write-off ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count") << QObject::tr("Sum") 
		<< QObject::tr("Sum currency name") << QObject::tr("Status name") << QObject::tr("Product ID") << QObject::tr("Status ID") 
		<< QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::WriteOffRawView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Write-off date") << QObject::tr("Status code")
		<< QObject::tr("Status name") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Product count") << QObject::tr("Sum") << QObject::tr("Currency name")
		<< QObject::tr("Employee ID") << QObject::tr("Client ID") << QObject::tr("Status ID") << QObject::tr("Currency ID")
		<< QObject::tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::WriteOffRawListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Write-off raw ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}


// Template specializations for generating data ---------------------------------------------------------------------------
template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Access>(BusinessLayer::Access& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(QString::number(data.GetRoleID()))
		<< new QStandardItem(QString::number(data.GetAccessItemID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::AccessItem>(BusinessLayer::AccessItem& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetNameEng().c_str())
		<< new QStandardItem(data.GetNameRu().c_str()) << new QStandardItem(data.GetDivision().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::BalanceView>(BusinessLayer::BalanceView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) 
		<< new QStandardItem(data.GetUsername().c_str())
		<< new QStandardItem(data.GetUserSurname().c_str()) 
		<< new QStandardItem(QString::number(data.GetValue()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetUserID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ClientView>(BusinessLayer::ClientView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetSurname().c_str())
		<< new QStandardItem(data.GetPhone().c_str())
		<< new QStandardItem(data.GetCountryName().c_str())
		<< new QStandardItem(data.GetRegionName().c_str())
		<< new QStandardItem(data.GetCityName().c_str())
		<< new QStandardItem(data.GetAddress().c_str())
		<< new QStandardItem(data.GetFirm().c_str())
		<< new QStandardItem(data.GetFirmNumber().c_str())
		<< new QStandardItem(data.GetRoleName().c_str())
		<< new QStandardItem(data.GetPassword().c_str())
		<< new QStandardItem(data.GetEmail().c_str())
		<< new QStandardItem(data.GetActivated() ? "true" : "false")
		<< new QStandardItem(QString::number(data.GetRoleID()))
		<< new QStandardItem(QString::number(data.GetLocationID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Company>(BusinessLayer::Company& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetAddress().c_str()) << new QStandardItem(data.GetPhone().c_str())
		<< new QStandardItem(data.GetComment().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ConsumeProductView>(BusinessLayer::ConsumeProductView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetExecutionDate().c_str())
		<< new QStandardItem(data.GetStatusCode().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetEmployeePosition().c_str())
		<< new QStandardItem(data.GetStockEmployeeName().c_str())
		<< new QStandardItem(data.GetStockEmployeeSurname().c_str())
		<< new QStandardItem(data.GetStockEmployeePhone().c_str())
		<< new QStandardItem(data.GetStockEmployeePosition().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetStockEmployeeID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ConsumeProductListView>(BusinessLayer::ConsumeProductListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetConsumeProductID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ConsumeRawView>(BusinessLayer::ConsumeRawView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetExecutionDate().c_str())
		<< new QStandardItem(data.GetStatusCode().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetEmployeePosition().c_str())
		<< new QStandardItem(data.GetStockEmployeeName().c_str())
		<< new QStandardItem(data.GetStockEmployeeSurname().c_str())
		<< new QStandardItem(data.GetStockEmployeePhone().c_str())
		<< new QStandardItem(data.GetStockEmployeePosition().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetStockEmployeeID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ConsumeRawListView>(BusinessLayer::ConsumeRawListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetConsumeRawID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Currency>(BusinessLayer::Currency& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(QString::number(data.GetCode()))
		<< new QStandardItem(data.GetShortName().c_str()) << new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(QString::number(data.GetUnit())) << new QStandardItem(data.GetMainTrade()?"true":"false");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::EmployeeView>(BusinessLayer::EmployeeView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetSurname().c_str())
		<< new QStandardItem(data.GetPositionName().c_str())
		<< new QStandardItem(data.GetPhone().c_str())
		<< new QStandardItem(data.GetAddress().c_str())
		<< new QStandardItem(data.GetBirthDate().c_str())
		<< new QStandardItem(data.GetRoleName().c_str())
		<< new QStandardItem(data.GetHireDate().c_str())
		<< new QStandardItem(data.GetPassword().c_str())
		<< new QStandardItem(data.GetEmail().c_str())
		<< new QStandardItem(data.GetActivated() ? "true" : "false")
		<< new QStandardItem(QString::number(data.GetRoleID()))
		<< new QStandardItem(QString::number(data.GetPositionID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::InventorizationView>(BusinessLayer::InventorizationView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetExecutionDate().c_str())
		<< new QStandardItem(data.GetStatusCode().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetEmployeePosition().c_str())
		<< new QStandardItem(data.GetStockEmployeeName().c_str())
		<< new QStandardItem(data.GetStockEmployeeSurname().c_str())
		<< new QStandardItem(data.GetStockEmployeePhone().c_str())
		<< new QStandardItem(data.GetStockEmployeePosition().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetStockEmployeeID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::InventorizationListView>(BusinessLayer::InventorizationListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetInventorizationID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Location>(BusinessLayer::Location& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetCountryName().c_str())
		<< new QStandardItem(data.GetCountryCode().c_str()) << new QStandardItem(data.GetRegionName().c_str())
		<< new QStandardItem(data.GetCityName().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Measure>(BusinessLayer::Measure& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetShortName().c_str()) << new QStandardItem(QString::number(data.GetUnit()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::OrderView>(BusinessLayer::OrderView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID())) 
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetExecutionDate().c_str())
		<< new QStandardItem(data.GetStatusCode().c_str()) 
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetClientName().c_str()) 
		<< new QStandardItem(data.GetClientSurname().c_str())
		<< new QStandardItem(data.GetClientPhone().c_str())
		<< new QStandardItem(data.GetClientAddress().c_str()) 
		<< new QStandardItem(data.GetClientFirm().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str()) 
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(QString::number(data.GetCount())) 
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str()) 
		<< new QStandardItem(QString::number(data.GetEmployeeID())) 
		<< new QStandardItem(QString::number(data.GetClientID())) 
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon,"Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::OrderListView>(BusinessLayer::OrderListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetOrderID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::OrderRawView>(BusinessLayer::OrderRawView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetExecutionDate().c_str())
		<< new QStandardItem(data.GetStatusCode().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetEmployeePosition().c_str())
		<< new QStandardItem(data.GetStockEmployeeName().c_str())
		<< new QStandardItem(data.GetStockEmployeeSurname().c_str())
		<< new QStandardItem(data.GetStockEmployeePhone().c_str())
		<< new QStandardItem(data.GetStockEmployeePosition().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetStockEmployeeID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::OrderRawListView>(BusinessLayer::OrderRawListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetOrderRawID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Photo>(BusinessLayer::Photo& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(QString::number(data.GetUserID()))
		<< new QStandardItem(QString::number(data.GetProductID())) << new QStandardItem(data.GetSource().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::PaymentView>(BusinessLayer::PaymentView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(QString::number(data.GetValue()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetUserID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Position>(BusinessLayer::Position& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetName().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::PriceView>(BusinessLayer::PriceView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetValue()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(QString::number(data.GetProductID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductType>(BusinessLayer::ProductType& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetShortName().c_str());
	return items;
}


template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductView>(BusinessLayer::ProductView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(QString(QString::number(data.GetPrice())))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString(QString::number(data.GetVolume())))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(data.GetProductTypeName().c_str())
		<< new QStandardItem(QString::number(data.GetShelfLife()))
		<< new QStandardItem(data.GetCompanyName().c_str())
		<< new QStandardItem(QString::number(data.GetCompanyID()))
		<< new QStandardItem(QString::number(data.GetMeasureID()))
		<< new QStandardItem(QString::number(data.GetProductTypeID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Production>(BusinessLayer::Production& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetProductionDate().c_str())
		<< new QStandardItem(data.GetExpiryDate().c_str()) << new QStandardItem(data.GetSessionStart().c_str())
		<< new QStandardItem(data.GetSessionEnd().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductionListView>(BusinessLayer::ProductionListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetProductionID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::PayslipView>(BusinessLayer::PayslipView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(QString::number(data.GetValue()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetSalaryID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Relation>(BusinessLayer::Relation& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(QString::number(data.GetUser1ID()))
		<< new QStandardItem(QString::number(data.GetUser2ID())) << new QStandardItem(QString::number(data.GetRelationTypeID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::RelationType>(BusinessLayer::RelationType& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetComment().c_str());
	return items;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ReceiptProductView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Receipt date") << QObject::tr("Execution date") << QObject::tr("Status code")
		<< QObject::tr("Status name") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Product count") << QObject::tr("Sum") << QObject::tr("Currency name")
		<< QObject::tr("Employee ID") << QObject::tr("Client ID") << QObject::tr("Status ID") << QObject::tr("Currency ID")
		<< QObject::tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ReceiptProductListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Receipt ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ReceiptRawView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Receipt date") << QObject::tr("Execution date") << QObject::tr("Status code")
		<< QObject::tr("Status name") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Employee position") << QObject::tr("Product count") << QObject::tr("Sum") << QObject::tr("Currency name")
		<< QObject::tr("Employee ID") << QObject::tr("Client ID") << QObject::tr("Status ID") << QObject::tr("Currency ID")
		<< QObject::tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ReceiptRawListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Receipt raw ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ReceiptProductView>(BusinessLayer::ReceiptProductView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetExecutionDate().c_str())
		<< new QStandardItem(data.GetStatusCode().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetEmployeePosition().c_str())
		<< new QStandardItem(data.GetStockEmployeeName().c_str())
		<< new QStandardItem(data.GetStockEmployeeSurname().c_str())
		<< new QStandardItem(data.GetStockEmployeePhone().c_str())
		<< new QStandardItem(data.GetStockEmployeePosition().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetStockEmployeeID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ReceiptProductListView>(BusinessLayer::ReceiptProductListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetReceiptProductID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ReceiptRawView>(BusinessLayer::ReceiptRawView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetExecutionDate().c_str())
		<< new QStandardItem(data.GetStatusCode().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetEmployeePosition().c_str())
		<< new QStandardItem(data.GetStockEmployeeName().c_str())
		<< new QStandardItem(data.GetStockEmployeeSurname().c_str())
		<< new QStandardItem(data.GetStockEmployeePhone().c_str())
		<< new QStandardItem(data.GetStockEmployeePosition().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetStockEmployeeID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ReceiptRawListView>(BusinessLayer::ReceiptRawListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetReceiptRawID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::RefundView>(BusinessLayer::RefundView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(QString::number(data.GetValue()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetUserID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Role>(BusinessLayer::Role& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) 
		<< new QStandardItem(data.GetCode().c_str())
		<< new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetComment().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ReturnView>(BusinessLayer::ReturnView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetExecutionDate().c_str())
		<< new QStandardItem(data.GetStatusCode().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetClientName().c_str())
		<< new QStandardItem(data.GetClientSurname().c_str())
		<< new QStandardItem(data.GetClientPhone().c_str())
		<< new QStandardItem(data.GetClientAddress().c_str())
		<< new QStandardItem(data.GetClientFirm().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetClientID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ReturnListView>(BusinessLayer::ReturnListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetReturnID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::SalaryView>(BusinessLayer::SalaryView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(QString::number(data.GetValue()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetSalaryTypeName().c_str())
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(QString::number(data.GetSalaryTypeID()))
		<< new QStandardItem(data.GetIsBonus() ? "true": "false");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::SalaryType>(BusinessLayer::SalaryType& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetCode().c_str())
		<< new QStandardItem(data.GetName().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Status>(BusinessLayer::Status& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetCode().c_str())
		<< new QStandardItem(data.GetName().c_str()) << new QStandardItem(data.GetComment().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::StockView>(BusinessLayer::StockView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::TransportView>(BusinessLayer::TransportView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetExecutionDate().c_str())
		<< new QStandardItem(data.GetStatusCode().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetEmployeePosition().c_str())
		<< new QStandardItem(data.GetStockEmployeeName().c_str())
		<< new QStandardItem(data.GetStockEmployeeSurname().c_str())
		<< new QStandardItem(data.GetStockEmployeePhone().c_str())
		<< new QStandardItem(data.GetStockEmployeePosition().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetStockEmployeeID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::TransportListView>(BusinessLayer::TransportListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetTransportID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::UserView>(BusinessLayer::UserView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetEmail().c_str())
		<< new QStandardItem(data.GetName().c_str()) << new QStandardItem(data.GetSurname().c_str())
		<< new QStandardItem(data.GetPhone().c_str()) << new QStandardItem(data.GetAddress().c_str())
		<< new QStandardItem(data.GetRoleName().c_str()) << new QStandardItem(data.GetPassword().c_str())
		<< new QStandardItem(data.GetActivated()? "true":"false") << new QStandardItem(QString::number(data.GetRoleID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::WithdrawalView>(BusinessLayer::WithdrawalView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(QString::number(data.GetValue()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetUserID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}


template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::WriteOffView>(BusinessLayer::WriteOffView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetStatusCode().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetClientName().c_str())
		<< new QStandardItem(data.GetClientSurname().c_str())
		<< new QStandardItem(data.GetClientPhone().c_str())
		<< new QStandardItem(data.GetClientAddress().c_str())
		<< new QStandardItem(data.GetClientFirm().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetClientID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::WriteOffListView>(BusinessLayer::WriteOffListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetWriteOffID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::WriteOffRawView>(BusinessLayer::WriteOffRawView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetStatusCode().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetEmployeePosition().c_str())
		<< new QStandardItem(data.GetStockEmployeeName().c_str())
		<< new QStandardItem(data.GetStockEmployeeSurname().c_str())
		<< new QStandardItem(data.GetStockEmployeePhone().c_str())
		<< new QStandardItem(data.GetStockEmployeePosition().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetStockEmployeeID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::WriteOffRawListView>(BusinessLayer::WriteOffRawListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetWriteOffRawID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}
// Template specializations for connections ---------------------------------------------------------------------------
template<>
void DataForm::QtConnect<BusinessLayer::Access>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtAcsDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpAcsDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelAcsDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::AccessItem>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtAcsItemDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpAcsItemDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelAcsItemDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createAcsDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createAcsDlg, SLOT(SetID(int, QString)));
	}
}


template<>
void DataForm::QtConnect<BusinessLayer::BalanceView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtBlcDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpBlcDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelBlcDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::ClientView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtCltDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpCltDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCltDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createOrdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdDlg, SLOT(SetID(int, QString)));
	}
	if (createRtrnDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRtrnDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::Company>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtCmpDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpCmpDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCmpDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createProdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createProdDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ConsumeProductView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtConPDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpConPDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelConPDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createConPListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConPListDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ConsumeProductListView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtConPListDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpConPListDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelConPListDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createConPDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConPDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ConsumeRawView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtConRDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpConRDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelConRDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createConRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConRListDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ConsumeRawListView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtConRListDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpConRListDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelConRListDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createConRDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConRDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::Currency>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtCurDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpCurDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCurDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createBlcDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createBlcDlg, SLOT(SetID(int, QString)));
	}
	if (createConPDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConPDlg, SLOT(SetID(int, QString)));
	}
	if (createConRDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConRDlg, SLOT(SetID(int, QString)));
	}
	if (createInvDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createInvDlg, SLOT(SetID(int, QString)));
	}
	if (createOrdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdDlg, SLOT(SetID(int, QString)));
	}
	if (createOrdRDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdRDlg, SLOT(SetID(int, QString)));
	}
	if (createProdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createProdDlg, SLOT(SetID(int, QString)));
	}
	if (createPmtDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createPmtDlg, SLOT(SetID(int, QString)));
	}
	if (createPspDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createPspDlg, SLOT(SetID(int, QString)));
	}
	if (createPrcDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createPrcDlg, SLOT(SetID(int, QString)));
	}
	if (createRcpPDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpPDlg, SLOT(SetID(int, QString)));
	}
	if (createRcpRDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpRDlg, SLOT(SetID(int, QString)));
	}
	if (createRfdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRfdDlg, SLOT(SetID(int, QString)));
	}
	if (createRtrnDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRtrnDlg, SLOT(SetID(int, QString)));
	}
	if (createSlrDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createSlrDlg, SLOT(SetID(int, QString)));
	}
	if (createStockDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createStockDlg, SLOT(SetID(int, QString)));
	}
	if (createTrsDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createTrsDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffDlg, SLOT(SetID(int, QString)));
	}
	if (createConPListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConPListDlg, SLOT(SetID(int, QString)));
	}
	if (createConRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConRListDlg, SLOT(SetID(int, QString)));
	}
	if (createInvListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createInvListDlg, SLOT(SetID(int, QString)));
	}
	if (createOrdListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdListDlg, SLOT(SetID(int, QString)));
	}
	if (createOrdRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdRListDlg, SLOT(SetID(int, QString)));
	}
	if (createProdnListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createProdnListDlg, SLOT(SetID(int, QString)));
	}
	if (createRcpPListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpPListDlg, SLOT(SetID(int, QString)));
	}
	if (createRcpRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpRListDlg, SLOT(SetID(int, QString)));
	}
	if (createRtrnListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRtrnListDlg, SLOT(SetID(int, QString)));
	}
	if (createTrsListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createTrsListDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffListDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffRListDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::EmployeeView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtEmpDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpEmpDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelEmpDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createConPDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConPDlg, SLOT(SetID(int, QString)));
	}
	if (createConRDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConRDlg, SLOT(SetID(int, QString)));
	}
	if (createInvDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createInvDlg, SLOT(SetID(int, QString)));
	}
	if (createOrdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdDlg, SLOT(SetID(int, QString)));
	}
	if (createOrdRDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdDlg, SLOT(SetID(int, QString)));
	}
	if (createRcpPDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpPDlg, SLOT(SetID(int, QString)));
	}
	if (createRcpRDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpRDlg, SLOT(SetID(int, QString)));
	}
	if (createRtrnDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRtrnDlg, SLOT(SetID(int, QString)));
	}
	if (createTrsDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createTrsDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffRDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffRDlg, SLOT(SetID(int, QString)));
	}
	if (clcWagesDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), clcWagesDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::InventorizationView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtInvDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpInvDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelInvDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createInvListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createInvListDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::InventorizationListView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtInvListDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpInvListDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelInvListDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createInvDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createInvDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::Location>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtLcnDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpLcnDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelLcnDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createCltDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createCltDlg, SLOT(SetID(int, QString)));
	}
}


template<>
void DataForm::QtConnect<BusinessLayer::Measure>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtMsrDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpMsrDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelMsrDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createProdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createProdDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::OrderView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtOrdDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpOrdDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelOrdDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createOrdListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdListDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::OrderListView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtOrdListDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpOrdListDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelOrdListDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createOrdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::OrderRawView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtOrdRDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpOrdRDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelOrdRDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createOrdRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdRListDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::OrderRawListView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtOrdRListDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpOrdRListDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelOrdRListDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createOrdRDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdRDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::Photo>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtPhotoDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpPhotoDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPhotoDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::PaymentView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtPmtDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpPmtDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPmtDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::Position>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtPosDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpPosDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPosDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createEmpDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createEmpDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::PriceView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtPrcDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpPrcDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPrcDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::ProductType>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtProdTpDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpProdTpDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelProdTpDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createProdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createProdDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ProductView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtProdDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpProdDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelProdDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createConPListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConPListDlg, SLOT(SetID(int, QString)));
	}
	if (createConRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConRListDlg, SLOT(SetID(int, QString)));
	}
	if (createInvListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createInvListDlg, SLOT(SetID(int, QString)));
	}
	if (createOrdListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdListDlg, SLOT(SetID(int, QString)));
	}
	if (createOrdRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdRListDlg, SLOT(SetID(int, QString)));
	}
	if (createProdnListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createProdnListDlg, SLOT(SetID(int, QString)));
	}
	if (createRcpPListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpPListDlg, SLOT(SetID(int, QString)));
	}
	if (createRcpRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpRListDlg, SLOT(SetID(int, QString)));
	}
	if (createRtrnListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRtrnListDlg, SLOT(SetID(int, QString)));
	}
	if (createTrsListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createTrsListDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffListDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffRListDlg, SLOT(SetID(int, QString)));
	}
	if (createPhtDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createPhtDlg, SLOT(SetID(int, QString)));
	}
	if (createPrcDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createPrcDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::Production>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtProdnDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpProdnDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelProdnDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createProdnListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createProdnListDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ProductionListView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtProdnListDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpProdnListDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelProdnListDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createProdnDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createProdnDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::PayslipView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtPspDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpPspDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPspDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::Relation>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtRelDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpRelDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRelDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::RelationType>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtRelTypeDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpRelTypeDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRelTypeDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createRelDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRelDlg, SLOT(SetID(int, QString)));
	}
}
template<>
void DataForm::QtConnect<BusinessLayer::ReceiptProductView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtRcpPDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpRcpPDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRcpPDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createRcpPListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpPListDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ReceiptProductListView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtRcpPListDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpRcpPListDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRcpPListDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createRcpPDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpPDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ReceiptRawView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtRcpRDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpRcpRDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRcpRDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createRcpRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpRListDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ReceiptRawListView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtRcpRListDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpRcpRListDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRcpRListDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createRcpRDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpRDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::RefundView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtRfdDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpRfdDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRfdDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::Role>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtRoleDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpRoleDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRoleDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createUserDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createUserDlg, SLOT(SetID(int, QString)));
	}
	/*if (createOrdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdDlg, SLOT(SetID(int, QString)));
	}
	if (createRtrnDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRtrnDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffDlg, SLOT(SetID(int, QString)));
	}*/
	if (createCltDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createCltDlg, SLOT(SetID(int, QString)));
	}
	if (createEmpDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createEmpDlg, SLOT(SetID(int, QString)));
	}
	if (createAcsDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createAcsDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ReturnView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtRtrnDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpRtrnDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRtrnDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createRtrnListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRtrnListDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ReturnListView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtRtrnListDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpRtrnListDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRtrnListDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createRtrnDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRtrnDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::SalaryView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtSlrDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpSlrDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelSlrDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createPspDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createPspDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::SalaryType>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtSlrTypeDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpSlrTypeDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelSlrTypeDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createSlrDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createSlrDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::Status>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtStsDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpStsDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelStsDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createConPDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConPDlg, SLOT(SetID(int, QString)));
	}
	if (createConRDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConRDlg, SLOT(SetID(int, QString)));
	}
	if (createInvDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createInvDlg, SLOT(SetID(int, QString)));
	}
	if (createOrdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdDlg, SLOT(SetID(int, QString)));
	}
	if (createOrdRDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdRDlg, SLOT(SetID(int, QString)));
	}
	if (createRcpPDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpPDlg, SLOT(SetID(int, QString)));
	}
	if (createRcpRDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpRDlg, SLOT(SetID(int, QString)));
	}
	if (createRtrnDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRtrnDlg, SLOT(SetID(int, QString)));
	}
	if (createStockDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createStockDlg, SLOT(SetID(int, QString)));
	}
	if (createTrsDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createTrsDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffDlg, SLOT(SetID(int, QString)));
	}
	if (createConPListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConPListDlg, SLOT(SetID(int, QString)));
	}
	if (createConRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createConRListDlg, SLOT(SetID(int, QString)));
	}
	if (createInvListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createInvListDlg, SLOT(SetID(int, QString)));
	}
	if (createOrdListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdListDlg, SLOT(SetID(int, QString)));
	}
	if (createOrdRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdRListDlg, SLOT(SetID(int, QString)));
	}
	if (createProdnListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createProdnListDlg, SLOT(SetID(int, QString)));
	}
	if (createRcpPListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpPListDlg, SLOT(SetID(int, QString)));
	}
	if (createRcpRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRcpRListDlg, SLOT(SetID(int, QString)));
	}
	if (createRtrnListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRtrnListDlg, SLOT(SetID(int, QString)));
	}
	if (createTrsListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createTrsListDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffListDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffRListDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::StockView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtStockDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpStockDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelStockDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::TransportView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtTrsDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpTrsDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelTrsDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createTrsListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createTrsListDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::TransportListView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtTrsListDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpTrsListDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelTrsListDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createTrsDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createTrsDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::UserView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtUserDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpUserDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelUserDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createBlcDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createBlcDlg, SLOT(SetID(int, QString)));
	}	
	if (createPhtDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createPhtDlg, SLOT(SetID(int, QString)));
	}
	if (createPmtDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createPmtDlg, SLOT(SetID(int, QString)));
	}
	if (createRfdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRfdDlg, SLOT(SetID(int, QString)));
	}
	if (createRelDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRelDlg, SLOT(SetID(int, QString)));
	}
	if (createSlrDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createSlrDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::WithdrawalView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtWdwDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpWdwDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelWdwDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::WriteOffView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtWOffDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpWOffDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelWOffDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createWOffListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffListDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::WriteOffListView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtWOffListDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpWOffListDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelWOffListDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createWOffDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::WriteOffRawView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtWOffRDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpWOffRDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelWOffRDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createWOffRListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffRListDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::WriteOffRawListView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtWOffRListDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpWOffRListDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelWOffRListDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createWOffRDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffRDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}