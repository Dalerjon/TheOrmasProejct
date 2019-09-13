#include "stdafx.h"
#include "DataForm.h"
#include "MainForm.h"
#include "DocForm.h"
#include "AllDlgHeaders.h"


DataForm::DataForm(BusinessLayer::OrmasBL *ormasBL, QWidget *parent) :QWidget(parent)
{
	setupUi(this);
	tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tableView->verticalHeader()->hide();
	tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	filterWidget->hide();
	editBtn->setDisabled(true);
	deleteBtn->setDisabled(true);
	dataFormBL = ormasBL;
	parentForm = parent;
	loggedUser = ((MainForm*)parentForm)->GetLoggedUser();
	if (objectName() == "orderForm" || objectName() == "returnForm" || objectName() == "productionForm" || objectName() == "writeOffForm" ||
		objectName() == "consumeProductForm" || objectName() == "consumeRawForm" || objectName() == "inventorizationForm" ||
		objectName() == "orderRawForm" || objectName() == "receiptProductForm" || objectName() == "stockTransferForm" ||
		objectName() == "productionPlanForm" || objectName() == "spoilageForm" || objectName() == "productionConsumeRawForm" ||
		objectName() == "specificationForm" || objectName() == "transportForm" || objectName() == "writeOffRawForm")
	{
		connect(tableView, SIGNAL(cellClicked(int, int)), this, SLOT(OpenList(int, int)));
	}
	connect(filterBtn, &QPushButton::released, this, &DataForm::Filter);
	connect(clearBtn, &QPushButton::released, this, &DataForm::ClearFilter);
	HileSomeRow();
	this->setWindowIcon(QIcon("./images/ormas.png"));
}

// All Slots ----------------------------------------------------------------------------
void DataForm::CloseDataForm()
{
	QMdiSubWindow *dataFromWindow = ((MainForm*)parentForm)->GetWindowByName(this->objectName());
	if (dataFromWindow != nullptr)
		dataFromWindow->close();
}

void DataForm::Search(QString searchText)
{
	if (!searchText.isEmpty())
	{
		for (int i = 0; i <= tableView->model()->columnCount(); i++)
		{
			for (int j = 0; j <= tableView->model()->rowCount(); j++)
			{
				QModelIndex index = tableView->model()->index(j, i);
				if (index.data().toString().compare(searchText, Qt::CaseInsensitive) == 0
					|| index.data().toString().contains(searchText))
				{
					tableView->setCurrentIndex(index);
					((QStandardItemModel *)tableView->model())->item(j,i)->setBackground(Qt::yellow);
				}
			}
		}
	}
}

void DataForm::ClearFilter()
{
	for (int i = 0; i <= tableView->model()->rowCount(); i++)
	{
		tableView->showRow(i);
	}
	filterWidget->hide();
	filterTextLb->setText("");
}

void DataForm::Filter()
{
	QString filterText = valueEdit->text();
	if (!filterText.isEmpty())
	{
		for (int i = 0; i <= tableView->model()->rowCount(); i++)
		{
			QModelIndex index = tableView->model()->index(i, columnCmb->currentData().toInt());
			if (0 == typeCmb->currentData().toInt())
			{
				if (index.data().toString().compare(filterText, Qt::CaseInsensitive) > 0)
				{
					tableView->showRow(i);
				}
				else
				{
					tableView->hideRow(i);
				}
			}
			if (1 == typeCmb->currentData().toInt())
			{
				if (index.data().toString().compare(filterText, Qt::CaseInsensitive) < 0)
				{
					tableView->showRow(i);
				}
				else
				{
					tableView->hideRow(i);
				}
			}
			if (2 == typeCmb->currentData().toInt())
			{
				std::string test = index.data().toString().toStdString();
				if (index.data().toString().compare(filterText, Qt::CaseInsensitive) == 0 )
				{
					tableView->showRow(i);
				}
				else
				{
					tableView->hideRow(i);
				}
			}
			if (3 == typeCmb->currentData().toInt())
			{
				if (index.data().toString().contains(filterText))
				{
					tableView->showRow(i);
				}
				else
				{
					tableView->hideRow(i);
				}
			}
		}
	}
	QString filterTextRow = columnCmb->currentText() + " " + typeCmb->currentText() + " " + filterText;
	filterTextLb->setText(filterTextRow);
	filterWidget->show();
}

void DataForm::SetColumnFilter(QStringList header)
{
	for (int i = 0; i < header.size(); i++)
	{
		columnCmb->addItem(header.at(i), i);
		columnSearchCmb->addItem(header.at(i), i);
	}
}

void DataForm::SetTypeFilter()
{
	typeCmb->addItem(tr("MORE(>)"), 0);
	typeCmb->addItem(tr("LESS(<)"), 1);
	typeCmb->addItem(tr("EQUAL(=)"), 2);
	typeCmb->addItem(tr("LIKE"), 3);
}

bool DataForm::IsClosed()
{
	//This is wrong method, please reimplement it!
	if (orderID != 0 && productionID != 0 && writeOffID != 0 && consumeProductID != 0 && consumeRawID != 0 && inventorizationID != 0 && 
		productionPlanID != 0 && receiptProductID != 0 && stockTransferID != 0 && specificationID != 0 && spoilageID != 0 &&
		transportID != 0 && writeOffRawID != 0)
	{
		return true;
	}
	return false;
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

void DataForm::HileSomeRow()
{
	BusinessLayer::Access access;
	if (objectName() == "userForm")
	{
		std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionAllUsers");
		std::size_t pos = crud.find("CRUD");
		if (pos == std::string::npos)
		{
			tableView->setColumnHidden(7, true);
		}
	}
	if (objectName() == "clientForm")
	{
		std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionClients");
		std::size_t pos = crud.find("CRUD");
		if (pos == std::string::npos)
		{
			tableView->setColumnHidden(11, true);
		}
	}
	if (objectName() == "employeeForm" || objectName() == "stockEmployeeForm")
	{
		std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionEmployees");
		std::size_t pos = crud.find("CRUD");
		if (pos == std::string::npos)
		{
			tableView->setColumnHidden(9, true);
		}
	}
	if (objectName() == "purveyorForm")
	{
		std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionPurveyors");
		std::size_t pos = crud.find("CRUD");
		if (pos == std::string::npos)
		{
			tableView->setColumnHidden(10, true);
		}
	}
	if (objectName() == "borrowerForm")
	{
		std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionBorrowers");
		std::size_t pos = crud.find("CRUD");
		if (pos == std::string::npos)
		{
			tableView->setColumnHidden(7, true);
		}
	}
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

void DataForm::AcsDenied()
{
	QString message = tr("Access denied!");
	QMessageBox::information(NULL, QString(tr("Warning")),
		QString(tr("Access denied, contact with Administrator!")),
		QString(tr("Ok")));
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
						prodListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
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
						conProdListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
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
						conRawListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
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
						invListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
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
						orderRawListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
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
						prodListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
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
		else if (objectName() == "productionConusmeRawForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				consumeRawID = id;
			BusinessLayer::ProductionConsumeRawList *pConsumeRawList = new BusinessLayer::ProductionConsumeRawList();
			pConsumeRawList->SetProductionConsumeRawID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::ProductionConsumeRawList>(pConsumeRawList);
			delete pConsumeRawList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("productionConusmeRawListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Production consume raw list"));
					dForm->FillTable<BusinessLayer::ProductionConsumeRawListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("productionConusmeRawForm");
						QMdiSubWindow *pconRawListWindow = new QMdiSubWindow;
						pconRawListWindow->setWidget(dForm);
						pconRawListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(pconRawListWindow);
						pconRawListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All raws for  production consume product list are shown");
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
					QString message = tr("All raws for production consume product list are shown");
					((MainForm*)parentWidget())->statusBar()->showMessage(message);
				}
			}
		}
		else if (objectName() == "productionPlanForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				productionID = id;
			BusinessLayer::ProductionPlanList *productionPlanList = new BusinessLayer::ProductionPlanList();
			productionPlanList->SetProductionPlanID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::ProductionPlanList>(productionPlanList);
			delete productionPlanList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("productionPlanListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Production plan list products"));
					dForm->FillTable<BusinessLayer::ProductionPlanListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("productionPlanListForm");
						QMdiSubWindow *prodPlanListWindow = new QMdiSubWindow;
						prodPlanListWindow->setWidget(dForm);
						prodPlanListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(prodPlanListWindow);
						prodPlanListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All products for production plan list are shown");
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
						recProdListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
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
		else if (objectName() == "stockTransferForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				stockTransferID = id;
			BusinessLayer::StockTransferList *stockTransferList = new BusinessLayer::StockTransferList();
			stockTransferList->SetStockTransferID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::StockTransferList>(stockTransferList);
			delete stockTransferList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("stockTransferListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Receipt raw list"));
					dForm->FillTable<BusinessLayer::StockTransferListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("stockTransferListForm");
						QMdiSubWindow *stockTrListWindow = new QMdiSubWindow;
						stockTrListWindow->setWidget(dForm);
						stockTrListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(stockTrListWindow);
						stockTrListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All products for stock transfer list are shown");
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
						retListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
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
		else if (objectName() == "specificationForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				transportID = id;
			BusinessLayer::SpecificationList *specificationList = new BusinessLayer::SpecificationList();
			specificationList->SetSpecificationID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::SpecificationList>(specificationList);
			delete specificationList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("specificationListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Specification list products"));
					dForm->FillTable<BusinessLayer::SpecificationListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("specificationListForm");
						QMdiSubWindow *specListWindow = new QMdiSubWindow;
						specListWindow->setWidget(dForm);
						specListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(specListWindow);
						specListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All products for specification list are shown");
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
					QString message = tr("All products for specification list are shown");
					((MainForm*)parentWidget())->statusBar()->showMessage(message);
				}
			}
		}
		else if (objectName() == "spoilageForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				transportID = id;
			BusinessLayer::SpoilageList *spoilageList = new BusinessLayer::SpoilageList();
			spoilageList->SetSpoilageID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::SpoilageList>(spoilageList);
			delete spoilageList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("spoilageListForm"));
			if (errorMessage.empty())
			{
				if (checkedWidget == nullptr)
				{
					DataForm *dForm = new DataForm(dataFormBL, this);
					dForm->setWindowTitle(tr("Spoilage list products"));
					dForm->FillTable<BusinessLayer::SpoilageListView>(errorMessage, filterString);
					if (errorMessage.empty())
					{
						dForm->setObjectName("spoilageListForm");
						QMdiSubWindow *spoListWindow = new QMdiSubWindow;
						spoListWindow->setWidget(dForm);
						spoListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(spoListWindow);
						spoListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
						dForm->setWindowModality(Qt::WindowModal);
						dForm->show();
						dForm->topLevelWidget();
						dForm->activateWindow();
						QString message = tr("All products for spoilage list are shown");
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
					QString message = tr("All products for spoilage list are shown");
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
						tranListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
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
						wListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
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
						rawListWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
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
	if (parentDialog != nullptr)
	{
		std::string errorMessage = "";
		double sum = 0;
		double priceSum = 0;
		double count = 0;
		int currencyID = 0;
		if (parentDialog->objectName() == "CreateSpecification")
		{
			if (tableView->model()->rowCount() > 0)
			{
				BusinessLayer::Product product;
				for (int i = 0; i < tableView->model()->rowCount(); i++)
				{
					product.Clear();
					product.GetProductByID(dataFormBL->GetOrmasDal(), tableView->model()->data(tableView->model()->index(i, 5)).toInt(), errorMessage);
					count = count + tableView->model()->data(tableView->model()->index(i, 3)).toDouble();
					sum = sum + (tableView->model()->data(tableView->model()->index(i, 3)).toDouble() * product.GetPrice());
				}
				currencyID = product.GetCurrencyID();
			}
		}
		else if (parentDialog->objectName() == "CreateConsumeProduct" || parentDialog->objectName() == "CreateReceiptProduct"
			|| parentDialog->objectName() == "CreateStockTransfer")
		{
			if (tableView->model()->rowCount() > 0)
			{
				BusinessLayer::Product product;
				BusinessLayer::NetCost nCost;
				for (int i = 0; i < tableView->model()->rowCount(); i++)
				{
					product.Clear();
					product.GetProductByID(dataFormBL->GetOrmasDal(), tableView->model()->data(tableView->model()->index(i, 11)).toInt(), errorMessage);
					nCost.Clear();
					nCost.GetNetCostByProductID(dataFormBL->GetOrmasDal(), product.GetID(), errorMessage);
					count = count + tableView->model()->data(tableView->model()->index(i, 7)).toDouble();
					sum = sum + (tableView->model()->data(tableView->model()->index(i, 7)).toDouble() * nCost.GetValue());
					priceSum = priceSum + (tableView->model()->data(tableView->model()->index(i, 7)).toDouble() * product.GetPrice());
				}
				currencyID = product.GetCurrencyID();
			}
		}
		else if (parentDialog->objectName() == "CreateRecieptProduct" || parentDialog->objectName() == "CreateRecieptProduct")
		{
			if (tableView->model()->rowCount() > 0)
			{
				BusinessLayer::Product product;
				BusinessLayer::NetCost nCost;
				for (int i = 0; i < tableView->model()->rowCount(); i++)
				{
					product.Clear();
					product.GetProductByID(dataFormBL->GetOrmasDal(), tableView->model()->data(tableView->model()->index(i, 11)).toInt(), errorMessage);
					nCost.Clear();
					nCost.GetNetCostByProductID(dataFormBL->GetOrmasDal(), product.GetID(), errorMessage);
					count = count + tableView->model()->data(tableView->model()->index(i, 7)).toDouble();
					sum = sum + (tableView->model()->data(tableView->model()->index(i, 7)).toDouble() * nCost.GetValue());
					priceSum = priceSum + (tableView->model()->data(tableView->model()->index(i, 7)).toDouble() * product.GetPrice());
				}
				currencyID = product.GetCurrencyID();
			}
		}
		else if (parentDialog->objectName() == "CreateWriteOff" || parentDialog->objectName() == "CreateWriteOff")
		{
			if (tableView->model()->rowCount() > 0)
			{
				BusinessLayer::Product product;
				BusinessLayer::NetCost nCost;
				for (int i = 0; i < tableView->model()->rowCount(); i++)
				{
					product.Clear();
					product.GetProductByID(dataFormBL->GetOrmasDal(), tableView->model()->data(tableView->model()->index(i, 11)).toInt(), errorMessage);
					nCost.Clear();
					nCost.GetNetCostByProductID(dataFormBL->GetOrmasDal(), product.GetID(), errorMessage);
					count = count + tableView->model()->data(tableView->model()->index(i, 7)).toDouble();
					sum = sum + (tableView->model()->data(tableView->model()->index(i, 7)).toDouble() * nCost.GetValue());
					priceSum = priceSum + (tableView->model()->data(tableView->model()->index(i, 7)).toDouble() * product.GetPrice());
				}
				currencyID = product.GetCurrencyID();
			}
		}
		else
		{
			if (tableView->model()->rowCount() > 0)
			{
				for (int i = 0; i < tableView->model()->rowCount(); i++)
				{
					sum = sum + tableView->model()->data(tableView->model()->index(i, 8)).toDouble();
					count = count + tableView->model()->data(tableView->model()->index(i, 7)).toDouble();
				}
				currencyID = tableView->model()->data(tableView->model()->index(0, 13)).toInt();
			}
		}
		
		if (parentDialog->objectName() == "CreateConsumeProduct")
		{
			((CreateConPDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
			((CreateConPDlg*)parentDialog)->sumEdit->setText(QString::number(sum,'f',3));
			((CreateConPDlg*)parentDialog)->priceSumLb->setText(QString::number(priceSum, 'f', 3));
			((CreateConPDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreateConPDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
		else if (parentDialog->objectName() == "CreateConsumeRaw")
		{
			((CreateConRDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
			((CreateConRDlg*)parentDialog)->sumEdit->setText(QString::number(sum, 'f', 3));
			((CreateConRDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreateConRDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
		else if (parentDialog->objectName() == "CreateInventorization")
		{
			((CreateInvDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
			((CreateInvDlg*)parentDialog)->sumEdit->setText(QString::number(sum, 'f', 3));
			((CreateInvDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreateInvDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
		else if (parentDialog->objectName() == "CreateOrder")
		{
			((CreateOrdDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
			((CreateOrdDlg*)parentDialog)->sumEdit->setText(QString::number(sum, 'f', 3));
			((CreateOrdDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreateOrdDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
		else if (parentDialog->objectName() == "CreateOrderRaw")
		{
			((CreateOrdRDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
			((CreateOrdRDlg*)parentDialog)->sumEdit->setText(QString::number(sum, 'f', 3));
			((CreateOrdRDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreateOrdRDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
		else if (parentDialog->objectName() == "CreateReceiptProduct")
		{
			((CreateRcpPDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
			((CreateRcpPDlg*)parentDialog)->sumEdit->setText(QString::number(sum, 'f', 3));
			((CreateConPDlg*)parentDialog)->priceSumLb->setText(QString::number(priceSum, 'f', 3));
			((CreateRcpPDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreateRcpPDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
		else if (parentDialog->objectName() == "CreateStockTransfer")
		{
			((CreateStockTrDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
			((CreateStockTrDlg*)parentDialog)->sumEdit->setText(QString::number(sum, 'f', 3));
			((CreateStockTrDlg*)parentDialog)->priceSumLb->setText(QString::number(priceSum, 'f', 3));
			((CreateStockTrDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreateStockTrDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
		else if (parentDialog->objectName() == "CreateProductionConsumeRaw")
		{
			((CreateProdConRDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
			((CreateProdConRDlg*)parentDialog)->sumEdit->setText(QString::number(sum, 'f', 3));
			((CreateProdConRDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreateProdConRDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
		else if (parentDialog->objectName() == "CreateProductionPlan")
		{
			((CreatePPlanDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
			((CreatePPlanDlg*)parentDialog)->sumEdit->setText(QString::number(sum, 'f', 3));
			((CreatePPlanDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreatePPlanDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
		else if (parentDialog->objectName() == "CreateTransport")
		{
			((CreateTrsDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
			((CreateTrsDlg*)parentDialog)->sumEdit->setText(QString::number(sum, 'f', 3));
			((CreateTrsDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreateTrsDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
		else if (parentDialog->objectName() == "CreateReturn")
		{
			((CreateRtrnDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
			((CreateRtrnDlg*)parentDialog)->sumEdit->setText(QString::number(sum, 'f', 3));
			((CreateRtrnDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreateRtrnDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
		else if (parentDialog->objectName() == "CreateSpecification")
		{
			((CreateSpecDlg*)parentDialog)->prodCountPh->setText(QString::number(count, 'f', 3));
			((CreateSpecDlg*)parentDialog)->sumEdit->setText(QString::number(sum, 'f', 3));
			((CreateSpecDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreateSpecDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
		else if (parentDialog->objectName() == "CreateSpoilage")
		{
			((CreateSplDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
			((CreateSplDlg*)parentDialog)->sumEdit->setText(QString::number(sum, 'f', 3));
			((CreateSplDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreateSplDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
		else if (parentDialog->objectName() == "CreateWriteOff")
		{
			((CreateWOffDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
			((CreateWOffDlg*)parentDialog)->sumEdit->setText(QString::number(sum, 'f', 3));
			((CreateWOffDlg*)parentDialog)->priceSumLb->setText(QString::number(priceSum, 'f', 3));
			((CreateWOffDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreateWOffDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
		else if (parentDialog->objectName() == "CreateWriteOffR")
		{
			((CreateWOffRDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
			((CreateWOffRDlg*)parentDialog)->sumEdit->setText(QString::number(sum, 'f', 3));
			((CreateWOffRDlg*)parentDialog)->currencyCmb->setCurrentIndex(((CreateWOffRDlg*)parentDialog)->currencyCmb->findData(QVariant(currencyID)));
		}
	}
	if (parentDialog->objectName() == "CreateProduction")
	{
		int count = 0;
		if (tableView->model()->rowCount() > 0)
		{
			for (int i = 0; i < tableView->model()->rowCount(); i++)
			{
				count = count + tableView->model()->data(tableView->model()->index(i, 7)).toDouble();
			}
		}
		((CreateProdnDlg*)parentDialog)->prodCountEdit->setText(QString::number(count, 'f', 3));
	}
}

void DataForm::CrtAccDlg()
{
	CreateAccDlg *accountDlg = new CreateAccDlg(dataFormBL, false, this);
	accountDlg->setAttribute(Qt::WA_DeleteOnClose);
	accountDlg->setWindowTitle(tr("Create account"));
	QMdiSubWindow *accountWindow = new QMdiSubWindow;
	accountWindow->setWidget(accountDlg);
	accountWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(accountWindow);
	accountDlg->show();
}
void DataForm::UdpAccDlg()
{
	CreateAccDlg *accountDlg = new CreateAccDlg(dataFormBL, true, this);
	accountDlg->setAttribute(Qt::WA_DeleteOnClose);
	accountDlg->setWindowTitle(tr("Update account"));
	QMdiSubWindow *accountWindow = new QMdiSubWindow;
	accountWindow->setWidget(accountDlg);
	accountWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(accountWindow);
	if (accountDlg->FillDlgElements(tableView))
	{
		accountDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelAccDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Account account;
	account.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteAccount(&account, errorMessage))
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
			QString(tr("Account with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtAcctblDlg()
{
	CreateAcctbDlg *accountableDlg = new CreateAcctbDlg(dataFormBL, false, this);
	accountableDlg->setAttribute(Qt::WA_DeleteOnClose);
	accountableDlg->setWindowTitle(tr("Create accountable"));
	QMdiSubWindow *accountableWindow = new QMdiSubWindow;
	accountableWindow->setWidget(accountableDlg);
	accountableWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(accountableWindow);
	accountableDlg->show();
}
void DataForm::UdpAcctblDlg()
{
	CreateAcctbDlg *accountableDlg = new CreateAcctbDlg(dataFormBL, true, this);
	accountableDlg->setAttribute(Qt::WA_DeleteOnClose);
	accountableDlg->setWindowTitle(tr("Update accountable"));
	QMdiSubWindow *accountableWindow = new QMdiSubWindow;
	accountableWindow->setWidget(accountableDlg);
	accountableWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(accountableWindow);
	if (accountableDlg->FillDlgElements(tableView))
	{
		accountableDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelAcctblDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Accountable accountable;
	accountable.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteAccountable(&accountable, errorMessage))
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
			QString(tr("Accountable with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtAccTpDlg()
{
	CreateAccTpDlg *accountTpDlg = new CreateAccTpDlg(dataFormBL, false, this);
	accountTpDlg->setAttribute(Qt::WA_DeleteOnClose);
	accountTpDlg->setWindowTitle(tr("Create account type"));
	QMdiSubWindow *accountTpWindow = new QMdiSubWindow;
	accountTpWindow->setWidget(accountTpDlg);
	accountTpWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(accountTpWindow);
	accountTpDlg->show();
}
void DataForm::UdpAccTpDlg()
{
	CreateAccTpDlg *accountTpDlg = new CreateAccTpDlg(dataFormBL, true, this);
	accountTpDlg->setAttribute(Qt::WA_DeleteOnClose);
	accountTpDlg->setWindowTitle(tr("Update account type"));
	QMdiSubWindow *accountTpWindow = new QMdiSubWindow;
	accountTpWindow->setWidget(accountTpDlg);
	accountTpWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(accountTpWindow);
	if (accountTpDlg->FillDlgElements(tableView))
	{
		accountTpDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelAccTpDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::AccountType accountType;
	accountType.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteAccountType(&accountType, errorMessage))
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
			QString(tr("Account type with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtAcsDlg()
{
	CreateAcsDlg *accessDlg = new CreateAcsDlg(dataFormBL, false, this);
	accessDlg->setAttribute(Qt::WA_DeleteOnClose);
	accessDlg->setWindowTitle(tr("Create access"));
	QMdiSubWindow *accessWindow = new QMdiSubWindow;
	accessWindow->setWidget(accessDlg);
	accessWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(accessWindow);
	accessDlg->show();
}
void DataForm::UdpAcsDlg()
{
	CreateAcsDlg *accessDlg = new CreateAcsDlg(dataFormBL, true, this);
	accessDlg->setAttribute(Qt::WA_DeleteOnClose);
	accessDlg->setWindowTitle(tr("Update access"));
	QMdiSubWindow *accessWindow = new QMdiSubWindow;
	accessWindow->setWidget(accessDlg);
	accessWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(accessWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *accessItemWindow = new QMdiSubWindow;
	accessItemWindow->setWidget(accessItemDlg);
	accessItemWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(accessItemWindow);
	accessItemDlg->show();
}
void DataForm::UdpAcsItemDlg()
{
	CreateAcsItemDlg *accessItemDlg = new CreateAcsItemDlg(dataFormBL, true, this);
	accessItemDlg->setAttribute(Qt::WA_DeleteOnClose);
	accessItemDlg->setWindowTitle(tr("Update access item"));
	QMdiSubWindow *accessItemWindow = new QMdiSubWindow;
	accessItemWindow->setWidget(accessItemDlg);
	accessItemWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(accessItemWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *balanceWindow = new QMdiSubWindow;
	balanceWindow->setWidget(balanceDlg);
	balanceWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(balanceWindow);
	balanceDlg->show();
}
void DataForm::UdpBlcDlg()
{
	CreateBlcDlg *balanceDlg = new CreateBlcDlg(dataFormBL, true, this);
	balanceDlg->setAttribute(Qt::WA_DeleteOnClose);
	balanceDlg->setWindowTitle(tr("Update balance"));
	QMdiSubWindow *balanceWindow = new QMdiSubWindow;
	balanceWindow->setWidget(balanceDlg);
	balanceWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(balanceWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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

void DataForm::CrtBrhDlg()
{
	CreateBrhDlg *branchDlg = new CreateBrhDlg(dataFormBL, false, this);
	branchDlg->setAttribute(Qt::WA_DeleteOnClose);
	branchDlg->setWindowTitle(tr("Create branch"));
	QMdiSubWindow *branchWindow = new QMdiSubWindow;
	branchWindow->setWidget(branchDlg);
	branchWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(branchWindow);
	branchDlg->show();
}
void DataForm::UdpBrhDlg()
{
	CreateBrhDlg *branchDlg = new CreateBrhDlg(dataFormBL, true, this);
	branchDlg->setAttribute(Qt::WA_DeleteOnClose);
	branchDlg->setWindowTitle(tr("Update branch"));
	QMdiSubWindow *branchWindow = new QMdiSubWindow;
	branchWindow->setWidget(branchDlg);
	branchWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(branchWindow);
	if (branchDlg->FillDlgElements(tableView))
	{
		branchDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelBrhDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Branch branch;
	branch.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteBranch(&branch, errorMessage))
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
			QString(tr("Branch with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtBrwDlg()
{
	CreateBrwDlg *borroweDlg = new CreateBrwDlg(dataFormBL, false, this);
	borroweDlg->setAttribute(Qt::WA_DeleteOnClose);
	borroweDlg->setWindowTitle(tr("Create borrower"));
	QMdiSubWindow *borrowerWindow = new QMdiSubWindow;
	borrowerWindow->setWidget(borroweDlg);
	borrowerWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(borrowerWindow);
	borroweDlg->show();
}
void DataForm::UdpBrwDlg()
{
	CreateBrwDlg *borroweDlg = new CreateBrwDlg(dataFormBL, true, this);
	borroweDlg->setAttribute(Qt::WA_DeleteOnClose);
	borroweDlg->setWindowTitle(tr("Update borrower"));
	QMdiSubWindow *borrowerWindow = new QMdiSubWindow;
	borrowerWindow->setWidget(borroweDlg);
	borrowerWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(borrowerWindow);
	if (borroweDlg->FillDlgElements(tableView))
	{
		borrowerWindow->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelBrwDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Borrower borrower;
	borrower.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteBorrower(&borrower, errorMessage))
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
			QString(tr("Borrower with this id does not exist!")),
			QString(tr("Ok")));
	}
}


void DataForm::CrtCbxDlg()
{
	CreateCbxDlg *cashboxDlg = new CreateCbxDlg(dataFormBL, false, this);
	cashboxDlg->setAttribute(Qt::WA_DeleteOnClose);
	cashboxDlg->setWindowTitle(tr("Create cashbox"));
	QMdiSubWindow *cashboxWindow = new QMdiSubWindow;
	cashboxWindow->setWidget(cashboxDlg);
	cashboxWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(cashboxWindow);
	cashboxDlg->show();
}
void DataForm::UdpCbxDlg()
{
	CreateCbxDlg *cashboxDlg = new CreateCbxDlg(dataFormBL, true, this);
	cashboxDlg->setAttribute(Qt::WA_DeleteOnClose);
	cashboxDlg->setWindowTitle(tr("Update cashbox"));
	QMdiSubWindow *cashboxWindow = new QMdiSubWindow;
	cashboxWindow->setWidget(cashboxDlg);
	cashboxWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(cashboxWindow);
	if (cashboxDlg->FillDlgElements(tableView))
	{
		cashboxDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelCbxDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Cashbox cashbox;
	cashbox.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteCashbox(&cashbox, errorMessage))
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
			QString(tr("Cashbox with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtCASHERDlg()
{
	CreateCASHERDlg *cashRelDlg = new CreateCASHERDlg(dataFormBL, false, this);
	cashRelDlg->setAttribute(Qt::WA_DeleteOnClose);
	cashRelDlg->setWindowTitle(tr("Create cashbox-employee relation"));
	QMdiSubWindow *cashRelWindow = new QMdiSubWindow;
	cashRelWindow->setWidget(cashRelDlg);
	cashRelWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(cashRelWindow);
	cashRelDlg->show();
}
void DataForm::UdpCASHERDlg()
{
	CreateCASHERDlg *cashRelDlg = new CreateCASHERDlg(dataFormBL, true, this);
	cashRelDlg->setAttribute(Qt::WA_DeleteOnClose);
	cashRelDlg->setWindowTitle(tr("Update cashbox-employee relation"));
	QMdiSubWindow *cashRelWindow = new QMdiSubWindow;
	cashRelWindow->setWidget(cashRelDlg);
	cashRelWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(cashRelWindow);
	if (cashRelDlg->FillDlgElements(tableView))
	{
		cashRelDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelCASHERDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::CashboxEmployeeRelation cashRel;

	if (0 != id && cashRel.GetCashboxEmployeeByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		if (dataFormBL->DeleteCashboxEmployeeRelation(&cashRel, errorMessage))
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
			QString(tr("Cashbox-employee relation with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtCltDlg()
{
	CreateCltDlg *clientDlg = new CreateCltDlg(dataFormBL, false, this);
	clientDlg->setAttribute(Qt::WA_DeleteOnClose);
	clientDlg->setWindowTitle(tr("Create client"));
	QMdiSubWindow *clientWindow = new QMdiSubWindow;
	clientWindow->setWidget(clientDlg);
	clientWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(clientWindow);
	clientDlg->show();
}
void DataForm::UdpCltDlg()
{
	CreateCltDlg *clientDlg = new CreateCltDlg(dataFormBL, true, this);
	clientDlg->setAttribute(Qt::WA_DeleteOnClose);
	clientDlg->setWindowTitle(tr("Update client"));
	QMdiSubWindow *clientWindow = new QMdiSubWindow;
	clientWindow->setWidget(clientDlg);
	clientWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(clientWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *companyWindow = new QMdiSubWindow;
	companyWindow->setWidget(companyDlg);
	companyWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(companyWindow);
	companyDlg->show();
}
void DataForm::UdpCmpDlg()
{
	CreateCmpDlg *companyDlg = new CreateCmpDlg(dataFormBL,true, this);
	companyDlg->setAttribute(Qt::WA_DeleteOnClose);
	companyDlg->setWindowTitle(tr("Update company"));
	QMdiSubWindow *companyWindow = new QMdiSubWindow;
	companyWindow->setWidget(companyDlg);
	companyWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(companyWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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

void DataForm::CrtCERDlg()
{
	CreateCERDlg *ceRelDlg = new CreateCERDlg(dataFormBL, false, this);
	ceRelDlg->setAttribute(Qt::WA_DeleteOnClose);
	ceRelDlg->setWindowTitle(tr("Create company-employee relation"));
	QMdiSubWindow *ceRelWindow = new QMdiSubWindow;
	ceRelWindow->setWidget(ceRelDlg);
	ceRelWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(ceRelWindow);
	ceRelDlg->show();
}
void DataForm::UdpCERDlg()
{
	CreateCERDlg *ceRelDlg = new CreateCERDlg(dataFormBL, true, this);
	ceRelDlg->setAttribute(Qt::WA_DeleteOnClose);
	ceRelDlg->setWindowTitle(tr("Update company-employee relation"));
	QMdiSubWindow *ceRelWindow = new QMdiSubWindow;
	ceRelWindow->setWidget(ceRelDlg);
	ceRelWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(ceRelWindow);
	if (ceRelDlg->FillDlgElements(tableView))
	{
		ceRelDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelCERDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::CompanyEmployeeRelation ceRel;
	
	if (0 != id && ceRel.GetCompanyEmployeeByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		if (dataFormBL->DeleteCompanyEmployeeRelation(&ceRel, errorMessage))
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
			QString(tr("Company-employee relation with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtCARDlg()
{
	CreateCARDlg *caRelDlg = new CreateCARDlg(dataFormBL, false, this);
	caRelDlg->setAttribute(Qt::WA_DeleteOnClose);
	caRelDlg->setWindowTitle(tr("Create company-account relation"));
	QMdiSubWindow *caRelWindow = new QMdiSubWindow;
	caRelWindow->setWidget(caRelDlg);
	caRelWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(caRelWindow);
	caRelDlg->show();
}
void DataForm::UdpCARDlg()
{
	CreateCARDlg *caRelDlg = new CreateCARDlg(dataFormBL, true, this);
	caRelDlg->setAttribute(Qt::WA_DeleteOnClose);
	caRelDlg->setWindowTitle(tr("Update company-account relation"));
	QMdiSubWindow *caRelWindow = new QMdiSubWindow;
	caRelWindow->setWidget(caRelDlg);
	caRelWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(caRelWindow);
	if (caRelDlg->FillDlgElements(tableView))
	{
		caRelDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelCARDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::CompanyAccountRelation caRel;

	if (0 != id && caRel.GetCompanyAccountByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		if (dataFormBL->DeleteCompanyAccountRelation(&caRel, errorMessage))
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
			QString(tr("Company-account relation with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtCOADlg()
{
	CreateCOADlg *coAccDlg = new CreateCOADlg(dataFormBL, false, this);
	coAccDlg->setAttribute(Qt::WA_DeleteOnClose);
	coAccDlg->setWindowTitle(tr("Create chart of account"));
	QMdiSubWindow *coAccWindow = new QMdiSubWindow;
	coAccWindow->setWidget(coAccDlg);
	coAccWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(coAccWindow);
	coAccDlg->show();
}
void DataForm::UdpCOADlg()
{
	CreateCOADlg *coAccDlg = new CreateCOADlg(dataFormBL, true, this);
	coAccDlg->setAttribute(Qt::WA_DeleteOnClose);
	coAccDlg->setWindowTitle(tr("Update chart of account"));
	QMdiSubWindow *coAccWindow = new QMdiSubWindow;
	coAccWindow->setWidget(coAccDlg);
	coAccWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(coAccWindow);
	if (coAccDlg->FillDlgElements(tableView))
	{
		coAccDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelCOADlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ChartOfAccounts coAcc;
	coAcc.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteChartOfAccounts(&coAcc, errorMessage))
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
			QString(tr("Chart of account with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtConPDlg()
{
	CreateConPDlg *conPDlg = new CreateConPDlg(dataFormBL, false, this);
	conPDlg->setAttribute(Qt::WA_DeleteOnClose);
	conPDlg->setWindowTitle(tr("Create consume product"));
	QMdiSubWindow *conPWindow = new QMdiSubWindow;
	conPWindow->setWidget(conPDlg);
	conPWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(conPWindow);
	conPDlg->show();
}
void DataForm::UdpConPDlg()
{
	CreateConPDlg *conPDlg = new CreateConPDlg(dataFormBL, true, this);
	conPDlg->setAttribute(Qt::WA_DeleteOnClose);
	conPDlg->setWindowTitle(tr("Update consume product"));
	QMdiSubWindow *conPWindow = new QMdiSubWindow;
	conPWindow->setWidget(conPDlg);
	conPWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(conPWindow);
	if (conPDlg->FillDlgElements(tableView))
	{
		conPDlg->show();
	}
	/*else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}*/
}
void DataForm::DelConPDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ConsumeProduct consumeProdcut;
	consumeProdcut.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteConsumeProduct(&consumeProdcut, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
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

void DataForm::ViewConPDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ConsumeProduct consumeProdcut;
	if (!consumeProdcut.GetConsumeProductByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::ConsumeProductList consumeProdcutList;
	BusinessLayer::Employee employee;
	BusinessLayer::Employee stockEmployee;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;
	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), consumeProdcut.GetEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!employee.GetEmployeeByID(dataFormBL->GetOrmasDal(), consumeProdcut.GetEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!stockEmployee.GetEmployeeByID(dataFormBL->GetOrmasDal(), consumeProdcut.GetStockEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	
	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);
	
	QFile file;
	file.setFileName(":/docs/invoice.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	consumeProdcutList.SetConsumeProductID(consumeProdcut.GetID());
	std::string filter = consumeProdcutList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::ConsumeProductListView> vecConProdList = dataFormBL->GetAllDataForClass<BusinessLayer::ConsumeProductListView>(errorMessage, filter);
	if (vecConProdList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(consumeProdcut.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(consumeProdcut.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName1Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName1Ph"), QString(employee.GetSurname().c_str()) + " " + QString(employee.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName2Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName2Ph"), QString(stockEmployee.GetSurname().c_str()) + " " + QString(stockEmployee.GetName().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	BusinessLayer::NetCost netCost;
	QString tableBody;
	double sum = 0;
	for each (auto item in vecConProdList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		netCost.Clear();
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!netCost.GetNetCostByProductID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
		tableBody += "<td>" + QString::number(product.GetPrice(), 'f', 3) + "</td>";
		tableBody += "<td>" + QString::number(item.GetCount()*product.GetPrice(), 'f', 3) + "</td>";
		tableBody += "<td>" + QString(currency.GetShortName().c_str()) + "</td>";
		tableBody += "</tr>";
		sum += item.GetCount()*product.GetPrice();
		i++;
	}
	reportText.replace(QString("TableBodyPh"), tableBody, Qt::CaseInsensitive);
	reportText.replace(QString("SumPh"), QString::number(sum), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
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
	QMdiSubWindow *craeteConPListWindow = new QMdiSubWindow;
	craeteConPListWindow->setWidget(craeteConPListDlg);
	craeteConPListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteConPListWindow);
	craeteConPListDlg->show();
}
void DataForm::UdpConPListDlg()
{
	CreateConPListDlg *craeteConPListDlg = new CreateConPListDlg(dataFormBL, true, this);
	craeteConPListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteConPListDlg->setWindowTitle(tr("Update product in consume product list"));
	QMdiSubWindow *craeteConPListWindow = new QMdiSubWindow;
	craeteConPListWindow->setWidget(craeteConPListDlg);
	craeteConPListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteConPListWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *conRWindow = new QMdiSubWindow;
	conRWindow->setWidget(conRDlg);
	conRWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(conRWindow);
	conRDlg->show();
}
void DataForm::UdpConRDlg()
{
	CreateConRDlg *conRDlg = new CreateConRDlg(dataFormBL, true, this);
	conRDlg->setAttribute(Qt::WA_DeleteOnClose);
	conRDlg->setWindowTitle(tr("Update consume raw"));
	QMdiSubWindow *conRWindow = new QMdiSubWindow;
	conRWindow->setWidget(conRDlg);
	conRWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(conRWindow);
	if (conRDlg->FillDlgElements(tableView))
	{
		conRDlg->show();
	}
	/*else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}*/
}
void DataForm::DelConRDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ConsumeRaw consumeRaw;
	consumeRaw.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteConsumeRaw(&consumeRaw, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
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

void DataForm::ViewConRDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ConsumeRaw consumeRaw;
	if (!consumeRaw.GetConsumeRawByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::ConsumeRawList consumeRawList;
	BusinessLayer::Employee employee;
	BusinessLayer::Employee stockEmployee;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;
	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), consumeRaw.GetEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!employee.GetEmployeeByID(dataFormBL->GetOrmasDal(), consumeRaw.GetEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!stockEmployee.GetEmployeeByID(dataFormBL->GetOrmasDal(), consumeRaw.GetStockEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}

	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/invoice.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	consumeRawList.SetConsumeRawID(consumeRaw.GetID());
	std::string filter = consumeRawList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::ConsumeRawListView> vecConRawList = dataFormBL->GetAllDataForClass<BusinessLayer::ConsumeRawListView>(errorMessage, filter);
	if (vecConRawList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(consumeRaw.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(consumeRaw.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName1Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName1Ph"), QString(employee.GetSurname().c_str()) + " " + QString(employee.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName2Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName2Ph"), QString(stockEmployee.GetSurname().c_str()) + " " + QString(stockEmployee.GetName().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	QString tableBody;
	for each (auto item in vecConRawList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
	reportText.replace(QString("SumPh"), QString::number(consumeRaw.GetSum()), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
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
	QMdiSubWindow *craeteConRListWindow = new QMdiSubWindow;
	craeteConRListWindow->setWidget(craeteConRListDlg);
	craeteConRListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteConRListWindow);
	craeteConRListDlg->show();
}
void DataForm::UdpConRListDlg()
{
	CreateConRListDlg *craeteConRListDlg = new CreateConRListDlg(dataFormBL, true, this);
	craeteConRListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteConRListDlg->setWindowTitle(tr("Update raw in consume raw list"));
	QMdiSubWindow *craeteConRListWindow = new QMdiSubWindow;
	craeteConRListWindow->setWidget(craeteConRListDlg);
	craeteConRListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteConRListWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *currencyWindow = new QMdiSubWindow;
	currencyWindow->setWidget(currencyDlg);
	currencyWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(currencyWindow);
	currencyDlg->show();
}
void DataForm::UdpCurDlg()
{
	CreateCurDlg *currencyDlg = new CreateCurDlg(dataFormBL, true, this);
	currencyDlg->setAttribute(Qt::WA_DeleteOnClose);
	currencyDlg->setWindowTitle(tr("Update currency"));
	QMdiSubWindow *currencyWindow = new QMdiSubWindow;
	currencyWindow->setWidget(currencyDlg);
	currencyWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(currencyWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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

void DataForm::CrtDivDlg()
{
	CreateDivDlg *divisionDlg = new CreateDivDlg(dataFormBL, false, this);
	divisionDlg->setAttribute(Qt::WA_DeleteOnClose);
	divisionDlg->setWindowTitle(tr("Create division"));
	QMdiSubWindow *divisionWindow = new QMdiSubWindow;
	divisionWindow->setWidget(divisionDlg);
	divisionWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(divisionWindow);
	divisionDlg->show();
}
void DataForm::UdpDivDlg()
{
	CreateDivDlg *divisionDlg = new CreateDivDlg(dataFormBL, false, this);
	divisionDlg->setAttribute(Qt::WA_DeleteOnClose);
	divisionDlg->setWindowTitle(tr("Update division"));
	QMdiSubWindow *divisionWindow = new QMdiSubWindow;
	divisionWindow->setWidget(divisionDlg);
	divisionWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(divisionWindow);
	if (divisionDlg->FillDlgElements(tableView))
	{
		divisionDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelDivDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Division division;
	division.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteDivision(&division, errorMessage))
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
			QString(tr("Division with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtEmpDlg()
{
	CreateEmpDlg *employeeDlg = new CreateEmpDlg(dataFormBL, false, this);
	employeeDlg->setAttribute(Qt::WA_DeleteOnClose);
	employeeDlg->setWindowTitle(tr("Create employee"));
	QMdiSubWindow *employeeWindow = new QMdiSubWindow;
	employeeWindow->setWidget(employeeDlg);
	employeeWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(employeeWindow);
	employeeDlg->show();
}
void DataForm::UdpEmpDlg()
{
	CreateEmpDlg *employeeDlg = new CreateEmpDlg(dataFormBL, true, this);
	employeeDlg->setAttribute(Qt::WA_DeleteOnClose);
	employeeDlg->setWindowTitle(tr("Update employee"));
	QMdiSubWindow *employeeWindow = new QMdiSubWindow;
	employeeWindow->setWidget(employeeDlg);
	employeeWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(employeeWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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

void DataForm::CrtEmpPrdDlg()
{
	CreateEmpPrdDlg *epRelDlg = new CreateEmpPrdDlg(dataFormBL, false, this);
	epRelDlg->setAttribute(Qt::WA_DeleteOnClose);
	epRelDlg->setWindowTitle(tr("Create employee-product relation"));
	QMdiSubWindow *epRelWindow = new QMdiSubWindow;
	epRelWindow->setWidget(epRelDlg);
	epRelWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(epRelWindow);
	epRelWindow->show();
}
void DataForm::UdpEmpPrdDlg()
{
	CreateEmpPrdDlg *epRelDlg = new CreateEmpPrdDlg(dataFormBL, true, this);
	epRelDlg->setAttribute(Qt::WA_DeleteOnClose);
	epRelDlg->setWindowTitle(tr("Update employee-product relation"));
	QMdiSubWindow *epRelWindow = new QMdiSubWindow;
	epRelWindow->setWidget(epRelDlg);
	epRelWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(epRelWindow);
	if (epRelDlg->FillDlgElements(tableView))
	{
		epRelDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelEmpPrdDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::EmployeeProductRelation epRel;

	if (0 != id && epRel.GetEmployeeProductByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		if (dataFormBL->DeleteEmployeeProductRelation(&epRel, errorMessage))
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
			QString(tr("Employee-product relation with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtEtrDlg()
{
	CreateEtrDlg *entryDlg = new CreateEtrDlg(dataFormBL, false, this);
	entryDlg->setAttribute(Qt::WA_DeleteOnClose);
	entryDlg->setWindowTitle(tr("Create entry"));
	QMdiSubWindow *entryWindow = new QMdiSubWindow;
	entryWindow->setWidget(entryDlg);
	entryWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(entryWindow);
	entryDlg->show();
}
void DataForm::UdpEtrDlg()
{
	CreateEtrDlg *entryDlg = new CreateEtrDlg(dataFormBL, true, this);
	entryDlg->setAttribute(Qt::WA_DeleteOnClose);
	entryDlg->setWindowTitle(tr("Update entry"));
	QMdiSubWindow *entryWindow = new QMdiSubWindow;
	entryWindow->setWidget(entryDlg);
	entryWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(entryWindow);
	if (entryDlg->FillDlgElements(tableView))
	{
		entryDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelEtrDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Entry entry;
	entry.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteEntry(&entry, errorMessage))
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
			QString(tr("Entry with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtEtrRtDlg()
{
	CreateEtrRtDlg *entryRtDlg = new CreateEtrRtDlg(dataFormBL, false, this);
	entryRtDlg->setAttribute(Qt::WA_DeleteOnClose);
	entryRtDlg->setWindowTitle(tr("Create entry routing"));
	QMdiSubWindow *entryRtWindow = new QMdiSubWindow;
	entryRtWindow->setWidget(entryRtDlg);
	entryRtWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(entryRtWindow);
	entryRtDlg->show();
}
void DataForm::UdpEtrRtDlg()
{
	CreateEtrRtDlg *entryRtDlg = new CreateEtrRtDlg(dataFormBL, true, this);
	entryRtDlg->setAttribute(Qt::WA_DeleteOnClose);
	entryRtDlg->setWindowTitle(tr("Update entry routing"));
	QMdiSubWindow *entryRtWindow = new QMdiSubWindow;
	entryRtWindow->setWidget(entryRtDlg);
	entryRtWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(entryRtWindow);
	if (entryRtDlg->FillDlgElements(tableView))
	{
		entryRtDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelEtrRtDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::EntryRouting entryRouting;
	entryRouting.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteEntryRouting(&entryRouting, errorMessage))
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
			QString(tr("Entry routing with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtInvDlg()
{
	CreateInvDlg *invDlg = new CreateInvDlg(dataFormBL, false, this);
	invDlg->setAttribute(Qt::WA_DeleteOnClose);
	invDlg->setWindowTitle(tr("Create inventorization"));
	QMdiSubWindow *invWindow = new QMdiSubWindow;
	invWindow->setWidget(invDlg);
	invWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(invWindow);
	invDlg->show();
}
void DataForm::UdpInvDlg()
{
	CreateInvDlg *invDlg = new CreateInvDlg(dataFormBL, true, this);
	invDlg->setAttribute(Qt::WA_DeleteOnClose);
	invDlg->setWindowTitle(tr("Update inventorization"));
	QMdiSubWindow *invWindow = new QMdiSubWindow;
	invWindow->setWidget(invDlg);
	invWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(invWindow);
	if (invDlg->FillDlgElements(tableView))
	{
		invDlg->show();
	}
	/*else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}*/
}
void DataForm::DelInvDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Inventorization inv;
	inv.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteInventorization(&inv, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
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

void DataForm::ViewInvDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Inventorization inventorization;
	if (!inventorization.GetInventorizationByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::InventorizationList inventorizationList;
	BusinessLayer::Employee employee;
	BusinessLayer::Employee stockEmployee;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;
	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), inventorization.GetEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!employee.GetEmployeeByID(dataFormBL->GetOrmasDal(), inventorization.GetEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!stockEmployee.GetEmployeeByID(dataFormBL->GetOrmasDal(), inventorization.GetStockEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}

	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/inventarization.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	inventorizationList.SetInventorizationID(inventorization.GetID());
	std::string filter = inventorizationList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::InventorizationListView> vecConRawList = dataFormBL->GetAllDataForClass<BusinessLayer::InventorizationListView>(errorMessage, filter);
	if (vecConRawList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(inventorization.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(inventorization.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName1Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName1Ph"), QString(employee.GetSurname().c_str()) + " " + QString(employee.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName2Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName2Ph"), QString(stockEmployee.GetSurname().c_str()) + " " + QString(stockEmployee.GetName().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	QString tableBody;
	for each (auto item in vecConRawList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
	reportText.replace(QString("SumPh"), QString::number(inventorization.GetSum()), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
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
	QMdiSubWindow *craeteInvListWindow = new QMdiSubWindow;
	craeteInvListWindow->setWidget(craeteInvListDlg);
	craeteInvListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteInvListWindow);
	craeteInvListDlg->show();
}
void DataForm::UdpInvListDlg()
{
	CreateInvListDlg *craeteInvListDlg = new CreateInvListDlg(dataFormBL, true, this);
	craeteInvListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteInvListDlg->setWindowTitle(tr("Update product in inventorization list"));
	QMdiSubWindow *craeteInvListWindow = new QMdiSubWindow;
	craeteInvListWindow->setWidget(craeteInvListDlg);
	craeteInvListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteInvListWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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

void DataForm::CrtJbpDlg()
{
	CreateJbpDlg *jobpriceDlg = new CreateJbpDlg(dataFormBL, false, this);
	jobpriceDlg->setAttribute(Qt::WA_DeleteOnClose);
	jobpriceDlg->setWindowTitle(tr("Create jobprice"));
	QMdiSubWindow *jobpriceWindow = new QMdiSubWindow;
	jobpriceWindow->setWidget(jobpriceDlg);
	jobpriceWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(jobpriceWindow);
	jobpriceDlg->show();
}
void DataForm::UdpJbpDlg()
{
	CreateJbpDlg *jobpriceDlg = new CreateJbpDlg(dataFormBL, true, this);
	jobpriceDlg->setAttribute(Qt::WA_DeleteOnClose);
	jobpriceDlg->setWindowTitle(tr("Update jobprice"));
	QMdiSubWindow *jobpriceWindow = new QMdiSubWindow;
	jobpriceWindow->setWidget(jobpriceDlg);
	jobpriceWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(jobpriceWindow);
	if (jobpriceDlg->FillDlgElements(tableView))
	{
		jobpriceDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelJbpDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Jobprice jobprice;
	jobprice.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteJobprice(&jobprice, errorMessage))
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
			QString(tr("Jobprice with this id does not exist!")),
			QString(tr("Ok")));

	}
}

void DataForm::CrtJbsDlg()
{
	CreateJbsDlg *jobsheetDlg = new CreateJbsDlg(dataFormBL, false, this);
	jobsheetDlg->setAttribute(Qt::WA_DeleteOnClose);
	jobsheetDlg->setWindowTitle(tr("Create jobsheet"));
	QMdiSubWindow *jobsheetWindow = new QMdiSubWindow;
	jobsheetWindow->setWidget(jobsheetDlg);
	jobsheetWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(jobsheetWindow);
	jobsheetDlg->show();
}
void DataForm::UdpJbsDlg()
{
	CreateJbsDlg *jobsheetDlg = new CreateJbsDlg(dataFormBL, true, this);
	jobsheetDlg->setAttribute(Qt::WA_DeleteOnClose);
	jobsheetDlg->setWindowTitle(tr("Update jobsheet"));
	QMdiSubWindow *jobsheetWindow = new QMdiSubWindow;
	jobsheetWindow->setWidget(jobsheetDlg);
	jobsheetWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(jobsheetWindow);
	if (jobsheetDlg->FillDlgElements(tableView))
	{
		jobsheetDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelJbsDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Jobsheet jobsheet;
	jobsheet.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteJobsheet(&jobsheet, errorMessage))
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
			QString(tr("Jobsheet with this id does not exist!")),
			QString(tr("Ok")));

	}
}

void DataForm::CrtLcnDlg()
{
	CreateLcnDlg *locationDlg = new CreateLcnDlg(dataFormBL, false, this);
	locationDlg->setAttribute(Qt::WA_DeleteOnClose);
	locationDlg->setWindowTitle(tr("Create location"));
	QMdiSubWindow *locationWindow = new QMdiSubWindow;
	locationWindow->setWidget(locationDlg);
	locationWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(locationWindow);
	locationDlg->show();
}
void DataForm::UdpLcnDlg()
{
	CreateLcnDlg *locationDlg = new CreateLcnDlg(dataFormBL, true, this);
	locationDlg->setAttribute(Qt::WA_DeleteOnClose);
	locationDlg->setWindowTitle(tr("Update location"));
	QMdiSubWindow *locationWindow = new QMdiSubWindow;
	locationWindow->setWidget(locationDlg);
	locationWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(locationWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *measureWindow = new QMdiSubWindow;
	measureWindow->setWidget(measureDlg);
	measureWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(measureWindow);
	measureDlg->show();
}
void DataForm::UdpMsrDlg()
{
	CreateMsrDlg *measureDlg = new CreateMsrDlg(dataFormBL, true, this);
	measureDlg->setAttribute(Qt::WA_DeleteOnClose);
	measureDlg->setWindowTitle(tr("Update currency"));
	QMdiSubWindow *measureWindow = new QMdiSubWindow;
	measureWindow->setWidget(measureDlg);
	measureWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(measureWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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

void DataForm::CrtNetCDlg()
{
	CreateNetCDlg *netCostDlg = new CreateNetCDlg(dataFormBL, false, this);
	netCostDlg->setAttribute(Qt::WA_DeleteOnClose);
	netCostDlg->setWindowTitle(tr("Create net cost"));
	QMdiSubWindow *netCostWindow = new QMdiSubWindow;
	netCostWindow->setWidget(netCostDlg);
	netCostWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(netCostWindow);
	netCostDlg->show();
}
void DataForm::UdpNetCDlg()
{
	CreateNetCDlg *netCostDlg = new CreateNetCDlg(dataFormBL, true, this);
	netCostDlg->setAttribute(Qt::WA_DeleteOnClose);
	netCostDlg->setWindowTitle(tr("Update net cost"));
	QMdiSubWindow *netCostWindow = new QMdiSubWindow;
	netCostWindow->setWidget(netCostDlg);
	netCostWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(netCostWindow);
	if (netCostDlg->FillDlgElements(tableView))
	{
		netCostDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelNetCDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::NetCost netCost;
	netCost.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteNetCost(&netCost, errorMessage))
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
			QString(tr("Net cost with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtOrdDlg()
{
	CreateOrdDlg *orderDlg = new CreateOrdDlg(dataFormBL, false, this);
	orderDlg->setAttribute(Qt::WA_DeleteOnClose);
	orderDlg->setWindowTitle(tr("Create order"));
	QMdiSubWindow *orderWindow = new QMdiSubWindow;
	orderWindow->setWidget(orderDlg);
	orderWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(orderWindow);
	orderDlg->show();
}
void DataForm::UdpOrdDlg()
{
	CreateOrdDlg *orderDlg = new CreateOrdDlg(dataFormBL, true, this);
	orderDlg->setAttribute(Qt::WA_DeleteOnClose);
	orderDlg->setWindowTitle(tr("Update order"));
	QMdiSubWindow *orderWindow = new QMdiSubWindow;
	orderWindow->setWidget(orderDlg);
	orderWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(orderWindow);
	if (orderDlg->FillDlgElements(tableView))
	{
		orderDlg->show();
	}
	/*else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}*/
}
void DataForm::DelOrdDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Order order;
	order.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteOrder(&order, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
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

void DataForm::ViewOrdDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Order order;
	if (!order.GetOrderByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::OrderList orderList;
	BusinessLayer::Client client;
	BusinessLayer::Employee employee;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;
	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), order.GetEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!client.GetClientByID(dataFormBL->GetOrmasDal(), order.GetClientID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!employee.GetEmployeeByID(dataFormBL->GetOrmasDal(), order.GetEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}

	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/order.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	orderList.SetOrderID(order.GetID());
	std::string filter = orderList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::OrderListView> vecOrdList = dataFormBL->GetAllDataForClass<BusinessLayer::OrderListView>(errorMessage, filter);
	if (vecOrdList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(order.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(order.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName1Ph"), QString(client.GetFirm().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName1Ph"), QString(client.GetSurname().c_str()) + " " + QString(client.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName2Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName2Ph"), QString(employee.GetSurname().c_str()) + " " + QString(employee.GetName().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	BusinessLayer::NetCost netCost;
	QString tableBody;
	for each (auto item in vecOrdList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
	reportText.replace(QString("SumPh"), QString::number(order.GetSum()), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
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
	QMdiSubWindow *craeteOrdListWindow = new QMdiSubWindow;
	craeteOrdListWindow->setWidget(craeteOrdListDlg);
	craeteOrdListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteOrdListWindow);
	craeteOrdListDlg->show();
}
void DataForm::UdpOrdListDlg()
{
	CreateOrdListDlg *craeteOrdListDlg = new CreateOrdListDlg(dataFormBL, true, this);
	craeteOrdListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteOrdListDlg->setWindowTitle(tr("Update product in order list"));
	QMdiSubWindow *craeteOrdListWindow = new QMdiSubWindow;
	craeteOrdListWindow->setWidget(craeteOrdListDlg);
	craeteOrdListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteOrdListWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *orderRWindow = new QMdiSubWindow;
	orderRWindow->setWidget(orderRDlg);
	orderRWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(orderRWindow);
	orderRDlg->show();
}
void DataForm::UdpOrdRDlg()
{
	CreateOrdRDlg *orderRDlg = new CreateOrdRDlg(dataFormBL, true, this);
	orderRDlg->setAttribute(Qt::WA_DeleteOnClose);
	orderRDlg->setWindowTitle(tr("Update order raw"));
	QMdiSubWindow *orderRWindow = new QMdiSubWindow;
	orderRWindow->setWidget(orderRDlg);
	orderRWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(orderRWindow);
	if (orderRDlg->FillDlgElements(tableView))
	{
		orderRDlg->show();
	}
	/*else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}*/
}
void DataForm::DelOrdRDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::OrderRaw orderRaw;
	orderRaw.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteOrderRaw(&orderRaw, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
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

void DataForm::ViewOrdRDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::OrderRaw orderRaw;
	if (!orderRaw.GetOrderRawByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::OrderRawList orderRawList;
	BusinessLayer::Purveyor purveyor;
	BusinessLayer::Employee employee;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;
	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), orderRaw.GetEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!purveyor.GetPurveyorByID(dataFormBL->GetOrmasDal(), orderRaw.GetPurveyorID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!employee.GetEmployeeByID(dataFormBL->GetOrmasDal(), orderRaw.GetEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}

	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/order.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	orderRawList.SetOrderRawID(orderRaw.GetID());
	std::string filter = orderRawList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::OrderRawListView> vecOrdRawList = dataFormBL->GetAllDataForClass<BusinessLayer::OrderRawListView>(errorMessage, filter);
	if (vecOrdRawList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(orderRaw.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(orderRaw.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName2Ph"), QString(purveyor.GetCompanyName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName2Ph"), QString(purveyor.GetSurname().c_str()) + " " + QString(purveyor.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName1Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName1Ph"), QString(employee.GetSurname().c_str()) + " " + QString(employee.GetName().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	QString tableBody;
	for each (auto item in vecOrdRawList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
	reportText.replace(QString("SumPh"), QString::number(orderRaw.GetSum()), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
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
	QMdiSubWindow *craeteOrdRListWindow = new QMdiSubWindow;
	craeteOrdRListWindow->setWidget(craeteOrdRListDlg);
	craeteOrdRListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteOrdRListWindow);
	craeteOrdRListDlg->show();
}
void DataForm::UdpOrdRListDlg()
{
	CreateOrdRListDlg *craeteOrdRListDlg = new CreateOrdRListDlg(dataFormBL, true, this);
	craeteOrdRListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteOrdRListDlg->setWindowTitle(tr("Update raw in order list"));
	QMdiSubWindow *craeteOrdRListWindow = new QMdiSubWindow;
	craeteOrdRListWindow->setWidget(craeteOrdRListDlg);
	craeteOrdRListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteOrdRListWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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

void DataForm::CrtPcrDlg()
{
	CreatePcrDlg *percentRateDlg = new CreatePcrDlg(dataFormBL, false, this);
	percentRateDlg->setAttribute(Qt::WA_DeleteOnClose);
	percentRateDlg->setWindowTitle(tr("Create percent rate"));
	QMdiSubWindow *percentRateWindow = new QMdiSubWindow;
	percentRateWindow->setWidget(percentRateDlg);
	percentRateWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(percentRateWindow);
	percentRateDlg->show();
}
void DataForm::UdpPcrDlg()
{
	CreatePcrDlg *percentRateDlg = new CreatePcrDlg(dataFormBL, true, this);
	percentRateDlg->setAttribute(Qt::WA_DeleteOnClose);
	percentRateDlg->setWindowTitle(tr("Update percent rate"));
	QMdiSubWindow *percentRateWindow = new QMdiSubWindow;
	percentRateWindow->setWidget(percentRateDlg);
	percentRateWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(percentRateWindow);
	if (percentRateDlg->FillDlgElements(tableView))
	{
		percentRateDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelPcrDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::PercentRate percentRate;
	percentRate.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeletePercentRate(&percentRate, errorMessage))
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
			QString(tr("Percent rate with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtPhotoDlg()
{
	CreatePhtDlg *photoDlg = new CreatePhtDlg(dataFormBL, false, this);
	photoDlg->setAttribute(Qt::WA_DeleteOnClose);
	photoDlg->setWindowTitle(tr("Create photo"));
	QMdiSubWindow *photoWindow = new QMdiSubWindow;
	photoWindow->setWidget(photoDlg);
	photoWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(photoWindow);
	photoDlg->show();
}
void DataForm::UdpPhotoDlg()
{
	CreatePhtDlg *photoDlg = new CreatePhtDlg(dataFormBL, true, this);
	photoDlg->setAttribute(Qt::WA_DeleteOnClose);
	photoDlg->setWindowTitle(tr("Update photo"));
	QMdiSubWindow *photoWindow = new QMdiSubWindow;
	photoWindow->setWidget(photoDlg);
	photoWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(photoWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *paymentWindow = new QMdiSubWindow;
	paymentWindow->setWidget(paymentDlg);
	paymentWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(paymentWindow);
	paymentDlg->show();
}
void DataForm::UdpPmtDlg()
{
	CreatePmtDlg *paymentDlg = new CreatePmtDlg(dataFormBL, true, this);
	paymentDlg->setAttribute(Qt::WA_DeleteOnClose);
	paymentDlg->setWindowTitle(tr("Update payment"));
	QMdiSubWindow *paymentWindow = new QMdiSubWindow;
	paymentWindow->setWidget(paymentDlg);
	paymentWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(paymentWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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

void DataForm::ViewPmtDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Payment payment;
	if (!payment.GetPaymentByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::User user;
	BusinessLayer::Employee cashier;
	BusinessLayer::Employee accountant;
	BusinessLayer::Role role;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;

	if (0 == role.GetRoleIDByName(dataFormBL->GetOrmasDal(), "CHIEF ACCOUNTANT", errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot find 'CHIEF ACCOUNTANT' role!")),
			QString(tr("Ok")));
		return;
	}

	accountant.SetRoleID(role.GetID());
	std::string empFilter = accountant.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::EmployeeView> vecEmpRep = dataFormBL->GetAllDataForClass<BusinessLayer::EmployeeView>(errorMessage, empFilter);
	if (vecEmpRep.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot find 'CHIEF ACCOUNTANT' employee!")),
			QString(tr("Ok")));
		return;
	}
	else
	{
		accountant.SetName(vecEmpRep.at(0).GetName());
		accountant.SetSurname(vecEmpRep.at(0).GetSurname());
	}

	role.Clear();
	if (0 == role.GetRoleIDByName(dataFormBL->GetOrmasDal(), "CASHIER", errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot find 'CASHIER' role!")),
			QString(tr("Ok")));
		return;
	}

	cashier.SetRoleID(role.GetID());
	std::string casFilter = cashier.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::EmployeeView> vecCasRep = dataFormBL->GetAllDataForClass<BusinessLayer::EmployeeView>(errorMessage, casFilter);
	if (vecCasRep.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot find 'CASHIER' employee!")),
			QString(tr("Ok")));
		return;
	}
	else
	{
		cashier.SetName(vecCasRep.at(0).GetName());
		cashier.SetSurname(vecCasRep.at(0).GetSurname());
	}

	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), accountant.GetID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}

	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Income chash order"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/income.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();

	BusinessLayer::Account acc;
	if (!acc.GetAccountByNumber(dataFormBL->GetOrmasDal(), "10110", errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Can't find account!")),
			QString(tr("Ok")));
		return;
	}


	BusinessLayer::Balance balance;
	BusinessLayer::Subaccount subAcc;
	BusinessLayer::Currency currency;
	BusinessLayer::Account account;
	if (payment.GetUserID() > 0)
	{
		balance.SetUserID(payment.GetUserID());
		std::string filter = balance.GenerateFilter(dataFormBL->GetOrmasDal());
		std::vector<BusinessLayer::BalanceView> balanceVector = dataFormBL->GetAllDataForClass<BusinessLayer::BalanceView>(errorMessage, filter);
		if (0 < balanceVector.size())
		{
			for each (auto item in balanceVector)
			{
				subAcc.Clear();
				if (subAcc.GetSubaccountByID(dataFormBL->GetOrmasDal(), item.GetSubaccountID(), errorMessage))
				{
					if (subAcc.GetParentAccountID() == payment.GetAccountID())
					{
						balance.SetSubaccountID(subAcc.GetID());
					}
				}
			}
		}
		else
		{
			subAcc.Clear();
		}
		if (balance.GetSubaccountID() <= 0)
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Can't find subaccount for this payment!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), payment.GetCurrencyID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Can't find currency for this payment!")),
				QString(tr("Ok")));
			return;
		}
		subAcc.Clear();
		if (!subAcc.GetSubaccountByID(dataFormBL->GetOrmasDal(), balance.GetSubaccountID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Can't find subaccount for this user!")),
				QString(tr("Ok")));
			return;
		}
	}
	else if (payment.GetAccountID()>0)
	{
		account.Clear();
		if (!account.GetAccountByID(dataFormBL->GetOrmasDal(), payment.GetAccountID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			return;
		}
	}
	else
	{
		subAcc.Clear();
		if (!subAcc.GetSubaccountByID(dataFormBL->GetOrmasDal(), payment.GetSubaccountID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			return;
		}
		if (!account.GetAccountByID(dataFormBL->GetOrmasDal(), subAcc.GetParentAccountID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			return;
		}
	}
	
	//generating report
	reportText.replace(QString("ComNamePh"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("NumberPh"), QString::number(payment.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(payment.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("DebAccNumPh"), QString(acc.GetNumber().c_str()), Qt::CaseInsensitive);
	if (payment.GetUserID() > 0 )
	{
		reportText.replace(QString("CredAccNumPh"), QString(subAcc.GetNumber().c_str()), Qt::CaseInsensitive);
	}
	else
	{
		reportText.replace(QString("CredAccNumPh"), QString(account.GetNumber().c_str()), Qt::CaseInsensitive);
	}
	reportText.replace(QString("SumPh"), QString::number(payment.GetValue()), Qt::CaseInsensitive);
	reportText.replace(QString("FromWhoPh"), QString(payment.GetWho().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("TargetPh"), QString(payment.GetTarget().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("AccounantNamePh"), QString(accountant.GetSurname().c_str()) + " " + QString(accountant.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("CachierNamePh"), QString(cashier.GetSurname().c_str()) + " " + QString(cashier.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("CurrPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
}

void DataForm::CrtPosDlg()
{
	CreatePosDlg *positionDlg = new CreatePosDlg(dataFormBL, false, this);
	positionDlg->setAttribute(Qt::WA_DeleteOnClose);
	positionDlg->setWindowTitle(tr("Create position"));
	QMdiSubWindow *positionWindow = new QMdiSubWindow;
	positionWindow->setWidget(positionDlg);
	positionWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(positionWindow);
	positionDlg->show();
}
void DataForm::UdpPosDlg()
{
	CreatePosDlg *positionDlg = new CreatePosDlg(dataFormBL, true, this);
	positionDlg->setAttribute(Qt::WA_DeleteOnClose);
	positionDlg->setWindowTitle(tr("Update position"));
	QMdiSubWindow *positionWindow = new QMdiSubWindow;
	positionWindow->setWidget(positionDlg);
	positionWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(positionWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *priceWindow = new QMdiSubWindow;
	priceWindow->setWidget(priceDlg);
	priceWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(priceWindow);
	priceDlg->show();
}
void DataForm::UdpPrcDlg()
{
	CreatePrcDlg *priceDlg = new CreatePrcDlg(dataFormBL, true, this);
	priceDlg->setAttribute(Qt::WA_DeleteOnClose);
	priceDlg->setWindowTitle(tr("Update price"));
	QMdiSubWindow *priceWindow = new QMdiSubWindow;
	priceWindow->setWidget(priceDlg);
	priceWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(priceWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *prodTypeWindow = new QMdiSubWindow;
	prodTypeWindow->setWidget(prodTypeDlg);
	prodTypeWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(prodTypeWindow);
	prodTypeDlg->show();
}
void DataForm::UdpProdTpDlg()
{
	CreatePrdTpDlg *prodTypeDlg = new CreatePrdTpDlg(dataFormBL, true, this);
	prodTypeDlg->setAttribute(Qt::WA_DeleteOnClose);
	prodTypeDlg->setWindowTitle(tr("Update product type"));
	QMdiSubWindow *prodTypeWindow = new QMdiSubWindow;
	prodTypeWindow->setWidget(prodTypeDlg);
	prodTypeWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(prodTypeWindow);
	if (prodTypeDlg->FillDlgElements(tableView))
	{
		prodTypeDlg->show();
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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

void DataForm::CrtPrdBrnDlg()
{
	CreatePrdBrnDlg *pbRelDlg = new CreatePrdBrnDlg(dataFormBL, false, this);
	pbRelDlg->setAttribute(Qt::WA_DeleteOnClose);
	pbRelDlg->setWindowTitle(tr("Create product-branch relation"));
	QMdiSubWindow *pbRelWindow = new QMdiSubWindow;
	pbRelWindow->setWidget(pbRelDlg);
	pbRelWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(pbRelWindow);
	pbRelWindow->show();
}
void DataForm::UdpPrdBrnDlg()
{
	CreatePrdBrnDlg *pbRelDlg = new CreatePrdBrnDlg(dataFormBL, true, this);
	pbRelDlg->setAttribute(Qt::WA_DeleteOnClose);
	pbRelDlg->setWindowTitle(tr("Update product-branch relation"));
	QMdiSubWindow *pbRelWindow = new QMdiSubWindow;
	pbRelWindow->setWidget(pbRelDlg);
	pbRelWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(pbRelWindow);
	if (pbRelDlg->FillDlgElements(tableView))
	{
		pbRelDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelPrdBrnDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ProductBranchRelation pbRel;

	if (0 != id && pbRel.GetProductBranchByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		if (dataFormBL->DeleteProductBranchRelation(&pbRel, errorMessage))
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
			QString(tr("Product-branch relation with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtProdDlg()
{
	CreateProdDlg *prodDlg = new CreateProdDlg(dataFormBL, false, this);
	prodDlg->setAttribute(Qt::WA_DeleteOnClose);
	prodDlg->setWindowTitle(tr("Create product"));
	QMdiSubWindow *prodWindow = new QMdiSubWindow;
	prodWindow->setWidget(prodDlg);
	prodWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(prodWindow);
	prodDlg->show();
}
void DataForm::UdpProdDlg()
{
	CreateProdDlg *prodDlg = new CreateProdDlg(dataFormBL, true, this);
	prodDlg->setAttribute(Qt::WA_DeleteOnClose);
	prodDlg->setWindowTitle(tr("Update product"));
	QMdiSubWindow *prodWindow = new QMdiSubWindow;
	prodWindow->setWidget(prodDlg);
	prodWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(prodWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *prodnWindow = new QMdiSubWindow;
	prodnWindow->setWidget(prodnDlg);
	prodnWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(prodnWindow);
	prodnDlg->show();
}
void DataForm::UdpProdnDlg()
{
	CreateProdnDlg *prodnDlg = new CreateProdnDlg(dataFormBL, true, this);
	prodnDlg->setAttribute(Qt::WA_DeleteOnClose);
	prodnDlg->setWindowTitle(tr("Update production"));
	QMdiSubWindow *prodnWindow = new QMdiSubWindow;
	prodnWindow->setWidget(prodnDlg);
	prodnWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(prodnWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Production prodn;
	prodn.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteProduction(&prodn, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
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

void DataForm::ViewProdnDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Production production;
	if (!production.GetProductionByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::ProductionList productionList;
	
	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/production.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	productionList.SetProductionID(production.GetID());
	std::string filter = productionList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::ProductionListView> vecProdnList = dataFormBL->GetAllDataForClass<BusinessLayer::ProductionListView>(errorMessage, filter);
	if (vecProdnList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(production.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(production.GetProductionDate().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	BusinessLayer::NetCost netCost;
	QString tableBody;
	double sum = 0;
	for each (auto item in vecProdnList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		netCost.Clear();
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!netCost.GetNetCostByProductID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
		tableBody += "<td>" + QString::number(product.GetPrice()) + "</td>";
		tableBody += "<td>" + QString::number(item.GetCount() * product.GetPrice(), 'f', 3) + "</td>";
		tableBody += "<td>" + QString(currency.GetShortName().c_str()) + "</td>";
		tableBody += "</tr>";
		sum += item.GetCount() * product.GetPrice();
		i++;
	}
	reportText.replace(QString("TableBodyPh"), tableBody, Qt::CaseInsensitive);
	reportText.replace(QString("SumPh"), QString::number(sum, 'f', 3), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
}

void DataForm::CrtProdnStockDlg()
{
	CreateProdnStockDlg *prodnStockDlg = new CreateProdnStockDlg(dataFormBL, false, this);
	prodnStockDlg->setAttribute(Qt::WA_DeleteOnClose);
	prodnStockDlg->setWindowTitle(tr("Create production stock"));
	QMdiSubWindow *prodnStockWindow = new QMdiSubWindow;
	prodnStockWindow->setWidget(prodnStockDlg);
	prodnStockWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(prodnStockWindow);
	prodnStockDlg->show();
}
void DataForm::UdpProdnStockDlg()
{
	CreateProdnStockDlg *prodnStockDlg = new CreateProdnStockDlg(dataFormBL, true, this);
	prodnStockDlg->setAttribute(Qt::WA_DeleteOnClose);
	prodnStockDlg->setWindowTitle(tr("Update production stock"));
	QMdiSubWindow *prodnStockWindow = new QMdiSubWindow;
	prodnStockWindow->setWidget(prodnStockDlg);
	prodnStockWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(prodnStockWindow);
	if (prodnStockDlg->FillDlgElements(tableView))
	{
		prodnStockDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelProdnStockDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ProductionStock prodnStock;
	prodnStock.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteProductionStock(&prodnStock, errorMessage))
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
			QString(tr("Production stock with this id does not exist!")),
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
	QMdiSubWindow *craeteProdnListWindow = new QMdiSubWindow;
	craeteProdnListWindow->setWidget(craeteProdnListDlg);
	craeteProdnListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteProdnListWindow);
	craeteProdnListDlg->show();
}
void DataForm::UdpProdnListDlg()
{
	CreateProdnListDlg *craeteProdnListDlg = new CreateProdnListDlg(dataFormBL, true, this);
	craeteProdnListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteProdnListDlg->setWindowTitle(tr("Update product in production list"));
	QMdiSubWindow *craeteProdnListWindow = new QMdiSubWindow;
	craeteProdnListWindow->setWidget(craeteProdnListDlg);
	craeteProdnListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteProdnListWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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

void DataForm::CrtProdConRDlg()
{
	CreateProdConRDlg *pConRDlg = new CreateProdConRDlg(dataFormBL, false, this);
	pConRDlg->setAttribute(Qt::WA_DeleteOnClose);
	pConRDlg->setWindowTitle(tr("Create production consume raw"));
	QMdiSubWindow *pconRWindow = new QMdiSubWindow;
	pconRWindow->setWidget(pConRDlg);
	pconRWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(pconRWindow);
	pConRDlg->show();
}
void DataForm::UdpProdConRDlg()
{
	CreateProdConRDlg *pConRDlg = new CreateProdConRDlg(dataFormBL, true, this);
	pConRDlg->setAttribute(Qt::WA_DeleteOnClose);
	pConRDlg->setWindowTitle(tr("Update production consume raw"));
	QMdiSubWindow *pConRWindow = new QMdiSubWindow;
	pConRWindow->setWidget(pConRDlg);
	pConRWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(pConRWindow);
	if (pConRDlg->FillDlgElements(tableView))
	{
		pConRDlg->show();
	}
	/*else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}*/
}
void DataForm::DelProdConRDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ProductionConsumeRaw pConsumeRaw;
	pConsumeRaw.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteProductionConsumeRaw(&pConsumeRaw, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Prodcution consume raw with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::ViewProdConRDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ProductionConsumeRaw pConsumeRaw;
	if (!pConsumeRaw.GetProductionConsumeRawByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::ProductionConsumeRawList pConsumeRawList;
	BusinessLayer::Employee employee;
	BusinessLayer::Employee stockEmployee;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;
	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), pConsumeRaw.GetEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	/*if (!employee.GetEmployeeByID(dataFormBL->GetOrmasDal(), pConsumeRaw.GetEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}*/
	if (!stockEmployee.GetEmployeeByID(dataFormBL->GetOrmasDal(), pConsumeRaw.GetStockEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}

	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/invoice.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	pConsumeRawList.SetProductionConsumeRawID(pConsumeRaw.GetID());
	std::string filter = pConsumeRawList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::ProductionConsumeRawListView> vecConRawList = dataFormBL->GetAllDataForClass<BusinessLayer::ProductionConsumeRawListView>(errorMessage, filter);
	if (vecConRawList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(pConsumeRaw.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(pConsumeRaw.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName1Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName1Ph"), QString(employee.GetSurname().c_str()) + " " + QString(employee.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName2Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName2Ph"), QString(stockEmployee.GetSurname().c_str()) + " " + QString(stockEmployee.GetName().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	QString tableBody;
	for each (auto item in vecConRawList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
	reportText.replace(QString("SumPh"), QString::number(pConsumeRaw.GetSum()), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
}

void DataForm::CrtProdConRListDlg()
{
	CreateProdConRListDlg *craeteProdConRListDlg = new CreateProdConRListDlg(dataFormBL, false, this);
	if (0 != pConsumeRawID)
	{
		craeteProdConRListDlg->pConsumeRawID = pConsumeRawID;
	}
	craeteProdConRListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteProdConRListDlg->setWindowTitle(tr("Add raw to production consume raw list"));
	QMdiSubWindow *craeteConRListWindow = new QMdiSubWindow;
	craeteConRListWindow->setWidget(craeteProdConRListDlg);
	craeteConRListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteConRListWindow);
	craeteProdConRListDlg->show();
}
void DataForm::UdpProdConRListDlg()
{
	CreateProdConRListDlg *craeteProdConRListDlg = new CreateProdConRListDlg(dataFormBL, true, this);
	craeteProdConRListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteProdConRListDlg->setWindowTitle(tr("Update raw in production consume raw list"));
	QMdiSubWindow *craeteProdConRListWindow = new QMdiSubWindow;
	craeteProdConRListWindow->setWidget(craeteProdConRListDlg);
	craeteProdConRListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteProdConRListWindow);
	if (craeteProdConRListDlg->FillDlgElements(tableView))
	{
		craeteProdConRListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelProdConRListDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ProductionConsumeRawList pConsumeRawList;
	pConsumeRawList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteProductionConsumeRawList(&pConsumeRawList, errorMessage))
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

void DataForm::CrtPPlanDlg()
{
	CreatePPlanDlg *pPlanDlg = new CreatePPlanDlg(dataFormBL, false, this);
	pPlanDlg->setAttribute(Qt::WA_DeleteOnClose);
	pPlanDlg->setWindowTitle(tr("Create production plan"));
	QMdiSubWindow *pPlanWindow = new QMdiSubWindow;
	pPlanWindow->setWidget(pPlanDlg);
	pPlanWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(pPlanWindow);
	pPlanDlg->show();
}
void DataForm::UdpPPlanDlg()
{
	CreatePPlanDlg *pPlanDlg = new CreatePPlanDlg(dataFormBL, true, this);
	pPlanDlg->setAttribute(Qt::WA_DeleteOnClose);
	pPlanDlg->setWindowTitle(tr("Update production plan"));
	QMdiSubWindow *pPlanWindow = new QMdiSubWindow;
	pPlanWindow->setWidget(pPlanDlg);
	pPlanWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(pPlanWindow);
	if (pPlanDlg->FillDlgElements(tableView))
	{
		pPlanDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelPPlanDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ProductionPlan pPlan;
	pPlan.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);

		if (dataFormBL->DeleteProductionPlan(&pPlan, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Production plan with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtPPlanListDlg()
{
	CreatePPlanListDlg *craetePPlanListDlg = new CreatePPlanListDlg(dataFormBL, false, this);
	if (0 != productionPlanID)
	{
		craetePPlanListDlg->productionPlanID = productionPlanID;
	}
	craetePPlanListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craetePPlanListDlg->setWindowTitle(tr("Add product to production plan list"));
	QMdiSubWindow *craetePPlanListWindow = new QMdiSubWindow;
	craetePPlanListWindow->setWidget(craetePPlanListDlg);
	craetePPlanListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craetePPlanListWindow);
	craetePPlanListDlg->show();
}
void DataForm::UdpPPlanListDlg()
{
	CreatePPlanListDlg *craetePPlanListDlg = new CreatePPlanListDlg(dataFormBL, true, this);
	craetePPlanListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craetePPlanListDlg->setWindowTitle(tr("Update product in production plan list"));
	QMdiSubWindow *craetePPlanListWindow = new QMdiSubWindow;
	craetePPlanListWindow->setWidget(craetePPlanListDlg);
	craetePPlanListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craetePPlanListWindow);
	if (craetePPlanListDlg->FillDlgElements(tableView))
	{
		craetePPlanListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelPPlanListDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ProductionPlanList pPlanList;
	pPlanList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteProductionPlanList(&pPlanList, errorMessage))
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
			QString(tr("Product with this id does not exist in production paln list!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtPspDlg()
{
	CreatePspDlg *payslipDlg = new CreatePspDlg(dataFormBL, false, this);
	payslipDlg->setAttribute(Qt::WA_DeleteOnClose);
	payslipDlg->setWindowTitle(tr("Create payslip"));
	QMdiSubWindow *payslipWindow = new QMdiSubWindow;
	payslipWindow->setWidget(payslipDlg);
	payslipWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(payslipWindow);
	payslipDlg->show();
}
void DataForm::UdpPspDlg()
{
	CreatePspDlg *payslipDlg = new CreatePspDlg(dataFormBL, true, this);
	payslipDlg->setAttribute(Qt::WA_DeleteOnClose);
	payslipDlg->setWindowTitle(tr("Update payslip"));
	QMdiSubWindow *payslipWindow = new QMdiSubWindow;
	payslipWindow->setWidget(payslipDlg);
	payslipWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(payslipWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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

void DataForm::CrtPurDlg()
{
	CreatePurDlg *purveyorDlg = new CreatePurDlg(dataFormBL, false, this);
	purveyorDlg->setAttribute(Qt::WA_DeleteOnClose);
	purveyorDlg->setWindowTitle(tr("Create purveyor"));
	QMdiSubWindow *purveyorWindow = new QMdiSubWindow;
	purveyorWindow->setWidget(purveyorDlg);
	purveyorWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(purveyorWindow);
	purveyorDlg->show();
}
void DataForm::UdpPurDlg()
{
	CreatePurDlg *purveyorDlg = new CreatePurDlg(dataFormBL, true, this);
	purveyorDlg->setAttribute(Qt::WA_DeleteOnClose);
	purveyorDlg->setWindowTitle(tr("Update purveyor"));
	QMdiSubWindow *purveyorWindow = new QMdiSubWindow;
	purveyorWindow->setWidget(purveyorDlg);
	purveyorWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(purveyorWindow);
	if (purveyorDlg->FillDlgElements(tableView))
	{
		purveyorDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelPurDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Purveyor purveyor;
	purveyor.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeletePurveyor(&purveyor, errorMessage))
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
			QString(tr("Purveyor with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtRelDlg()
{
	CreateRelDlg *relationDlg = new CreateRelDlg(dataFormBL, false, this);
	relationDlg->setAttribute(Qt::WA_DeleteOnClose);
	relationDlg->setWindowTitle(tr("Create relation"));
	QMdiSubWindow *relationWindow = new QMdiSubWindow;
	relationWindow->setWidget(relationDlg);
	relationWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(relationWindow);
	relationDlg->show();
}
void DataForm::UdpRelDlg()
{
	CreateRelDlg *relationDlg = new CreateRelDlg(dataFormBL, true, this);
	relationDlg->setAttribute(Qt::WA_DeleteOnClose);
	relationDlg->setWindowTitle(tr("Update relation"));
	QMdiSubWindow *relationWindow = new QMdiSubWindow;
	relationWindow->setWidget(relationDlg);
	relationWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(relationWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *relationTypeWindow = new QMdiSubWindow;
	relationTypeWindow->setWidget(relationTypeDlg);
	relationTypeWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(relationTypeWindow);
	relationTypeDlg->show();
}
void DataForm::UdpRelTypeDlg()
{
	CreateRelTypeDlg *relationTypeDlg = new CreateRelTypeDlg(dataFormBL, true, this);
	relationTypeDlg->setAttribute(Qt::WA_DeleteOnClose);
	relationTypeDlg->setWindowTitle(tr("Update relation type"));
	QMdiSubWindow *relationTypeWindow = new QMdiSubWindow;
	relationTypeWindow->setWidget(relationTypeDlg);
	relationTypeWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(relationTypeWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *rcpPWindow = new QMdiSubWindow;
	rcpPWindow->setWidget(rcpPDlg);
	rcpPWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(rcpPWindow);
	rcpPDlg->show();
}
void DataForm::UdpRcpPDlg()
{
	CreateRcpPDlg *rcpPDlg = new CreateRcpPDlg(dataFormBL, true, this);
	rcpPDlg->setAttribute(Qt::WA_DeleteOnClose);
	rcpPDlg->setWindowTitle(tr("Update receipt product"));
	QMdiSubWindow *rcpPWindow = new QMdiSubWindow;
	rcpPWindow->setWidget(rcpPDlg);
	rcpPWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(rcpPWindow);
	if (rcpPDlg->FillDlgElements(tableView))
	{
		rcpPDlg->show();
	}
	/*else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}*/
}
void DataForm::DelRcpPDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ReceiptProduct receiptProdcut;
	receiptProdcut.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteReceiptProduct(&receiptProdcut, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
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

void DataForm::ViewRcpPDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ReceiptProduct receiptProdcut;
	if (!receiptProdcut.GetReceiptProductByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::ReceiptProductList receiptProdcutList;
	BusinessLayer::Employee employee;
	BusinessLayer::Employee stockEmployee;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;
	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), receiptProdcut.GetEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!employee.GetEmployeeByID(dataFormBL->GetOrmasDal(), receiptProdcut.GetEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!stockEmployee.GetEmployeeByID(dataFormBL->GetOrmasDal(), receiptProdcut.GetStockEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}

	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/invoice.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	receiptProdcutList.SetReceiptProductID(receiptProdcut.GetID());
	std::string filter = receiptProdcutList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::ReceiptProductListView> vecRcpProdList = dataFormBL->GetAllDataForClass<BusinessLayer::ReceiptProductListView>(errorMessage, filter);
	if (vecRcpProdList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(receiptProdcut.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(receiptProdcut.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName2Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName2Ph"), QString(employee.GetSurname().c_str()) + " " + QString(employee.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName1Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName1Ph"), QString(stockEmployee.GetSurname().c_str()) + " " + QString(stockEmployee.GetName().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	BusinessLayer::NetCost netCost;
	QString tableBody;
	double sum = 0;
	for each (auto item in vecRcpProdList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		netCost.Clear();
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!netCost.GetNetCostByProductID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
		tableBody += "<td>" + QString::number(product.GetPrice(), 'f', 3) + "</td>";
		tableBody += "<td>" + QString::number(item.GetCount()*product.GetPrice(), 'f', 3) + "</td>";
		tableBody += "<td>" + QString(currency.GetShortName().c_str()) + "</td>";
		tableBody += "</tr>";
		sum += item.GetCount() * product.GetPrice();
		i++;
	}
	reportText.replace(QString("TableBodyPh"), tableBody, Qt::CaseInsensitive);
	reportText.replace(QString("SumPh"), QString::number(sum, 'f',3), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
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
	QMdiSubWindow *craeteRcpPListWindow = new QMdiSubWindow;
	craeteRcpPListWindow->setWidget(craeteRcpPListDlg);
	craeteRcpPListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteRcpPListWindow);
	craeteRcpPListDlg->show();
}
void DataForm::UdpRcpPListDlg()
{
	CreateRcpPListDlg *craeteRcpPListDlg = new CreateRcpPListDlg(dataFormBL, true, this);
	craeteRcpPListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteRcpPListDlg->setWindowTitle(tr("Update product in receipt product list"));
	QMdiSubWindow *craeteRcpPListWindow = new QMdiSubWindow;
	craeteRcpPListWindow->setWidget(craeteRcpPListDlg);
	craeteRcpPListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteRcpPListWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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

void DataForm::CrtStockTrDlg()
{
	CreateStockTrDlg *StockTrDlg = new CreateStockTrDlg(dataFormBL, false, this);
	StockTrDlg->setAttribute(Qt::WA_DeleteOnClose);
	StockTrDlg->setWindowTitle(tr("Stock transfer"));
	QMdiSubWindow *StockTrWindow = new QMdiSubWindow;
	StockTrWindow->setWidget(StockTrDlg);
	StockTrWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(StockTrWindow);
	StockTrDlg->show();
}
void DataForm::UdpStockTrDlg()
{
	CreateStockTrDlg *StockTrDlg = new CreateStockTrDlg(dataFormBL, true, this);
	StockTrDlg->setAttribute(Qt::WA_DeleteOnClose);
	StockTrDlg->setWindowTitle(tr("Update stock transfer"));
	QMdiSubWindow *StockTrWindow = new QMdiSubWindow;
	StockTrWindow->setWidget(StockTrDlg);
	StockTrWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(StockTrWindow);
	if (StockTrDlg->FillDlgElements(tableView))
	{
		StockTrDlg->show();
	}
	/*else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}*/
}
void DataForm::DelStockTrDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::StockTransfer stockTransfer;
	stockTransfer.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteStockTransfer(&stockTransfer, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
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

void DataForm::ViewStockTrDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::StockTransfer stockTransfer;
	if (!stockTransfer.GetStockTransferByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::StockTransferList stockTransferList;
	BusinessLayer::Employee fromStockEmployee;
	BusinessLayer::Employee toStockEmployee;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;
	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), stockTransfer.GetEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!fromStockEmployee.GetEmployeeByID(dataFormBL->GetOrmasDal(), stockTransfer.GetEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!toStockEmployee.GetEmployeeByID(dataFormBL->GetOrmasDal(), stockTransfer.GetStockEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}

	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/invoice.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	stockTransferList.SetStockTransferID(stockTransfer.GetID());
	std::string filter = stockTransferList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::StockTransferListView> vecStockTrawList = dataFormBL->GetAllDataForClass<BusinessLayer::StockTransferListView>(errorMessage, filter);
	if (vecStockTrawList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(stockTransfer.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(stockTransfer.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName1Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName1Ph"), QString(fromStockEmployee.GetSurname().c_str()) + " " + QString(fromStockEmployee.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName2Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName2Ph"), QString(toStockEmployee.GetSurname().c_str()) + " " + QString(toStockEmployee.GetName().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	QString tableBody;
	double sum = 0;
	for each (auto item in vecStockTrawList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
		tableBody += "<td>" + QString::number(product.GetPrice(), 'f', 3) + "</td>";
		tableBody += "<td>" + QString::number(item.GetCount()*product.GetPrice(), 'f', 3) + "</td>";
		tableBody += "<td>" + QString(currency.GetShortName().c_str()) + "</td>";
		tableBody += "</tr>";
		sum += item.GetCount() * product.GetPrice();
		i++;
	}
	reportText.replace(QString("TableBodyPh"), tableBody, Qt::CaseInsensitive);
	reportText.replace(QString("SumPh"), QString::number(sum,'f', 3), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
}

void DataForm::CrtStockTrListDlg()
{
	CreateStockTrListDlg *craeteStockTrListDlg = new CreateStockTrListDlg(dataFormBL, false, this);
	if (0 != stockTransferID)
	{
		craeteStockTrListDlg->stockTransferID = stockTransferID;
	}
	craeteStockTrListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteStockTrListDlg->setWindowTitle(tr("Add product to stock transfer list"));
	QMdiSubWindow *craeteStockTrListWindow = new QMdiSubWindow;
	craeteStockTrListWindow->setWidget(craeteStockTrListDlg);
	craeteStockTrListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteStockTrListWindow);
	craeteStockTrListDlg->show();
}
void DataForm::UdpStockTrListDlg()
{
	CreateStockTrListDlg *craeteStockTrListDlg = new CreateStockTrListDlg(dataFormBL, true, this);
	craeteStockTrListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteStockTrListDlg->setWindowTitle(tr("Update raw in receipt raw list"));
	QMdiSubWindow *craeteStockTrListWindow = new QMdiSubWindow;
	craeteStockTrListWindow->setWidget(craeteStockTrListDlg);
	craeteStockTrListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteStockTrListWindow);
	if (craeteStockTrListDlg->FillDlgElements(tableView))
	{
		craeteStockTrListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelStockTrListDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::StockTransferList stockTransferList;
	stockTransferList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteStockTransferList(&stockTransferList, errorMessage))
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
	QMdiSubWindow *refundWindow = new QMdiSubWindow;
	refundWindow->setWidget(refundDlg);
	refundWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(refundWindow);
	refundDlg->show();
}
void DataForm::UdpRfdDlg()
{
	CreateRfdDlg *refundDlg = new CreateRfdDlg(dataFormBL, true, this);
	refundDlg->setAttribute(Qt::WA_DeleteOnClose);
	refundDlg->setWindowTitle(tr("Update refund"));
	QMdiSubWindow *refundWindow = new QMdiSubWindow;
	refundWindow->setWidget(refundDlg);
	refundWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(refundWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *roleWindow = new QMdiSubWindow;
	roleWindow->setWidget(roleDlg);
	roleWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(roleWindow);
	roleDlg->show();
}
void DataForm::UdpRoleDlg()
{
	CreateRoleDlg *roleDlg = new CreateRoleDlg(dataFormBL, true, this);
	roleDlg->setAttribute(Qt::WA_DeleteOnClose);
	roleDlg->setWindowTitle(tr("Update role"));
	QMdiSubWindow *roleWindow = new QMdiSubWindow;
	roleWindow->setWidget(roleDlg);
	roleWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(roleWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *returnWindow = new QMdiSubWindow;
	returnWindow->setWidget(returnDlg);
	returnWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(returnWindow);
	returnDlg->show();
}
void DataForm::UdpRtrnDlg()
{
	CreateRtrnDlg *returnDlg = new CreateRtrnDlg(dataFormBL, true, this);
	returnDlg->setAttribute(Qt::WA_DeleteOnClose);
	returnDlg->setWindowTitle(tr("Update return"));
	QMdiSubWindow *returnWindow = new QMdiSubWindow;
	returnWindow->setWidget(returnDlg);
	returnWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(returnWindow);
	if (returnDlg->FillDlgElements(tableView))
	{
		returnDlg->show();
	}
	/*else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}*/
}
void DataForm::DelRtrnDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Return ret;
	ret.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteReturn(&ret, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
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

void DataForm::ViewRtrnDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Return ret;
	if (!ret.GetReturnByID(dataFormBL->GetOrmasDal(), id, errorMessage))
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
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), ret.GetEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!client.GetClientByID(dataFormBL->GetOrmasDal(), ret.GetClientID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!employee.GetEmployeeByID(dataFormBL->GetOrmasDal(), ret.GetEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}

	DocForm *docForm = new DocForm(dataFormBL, this);
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
	std::string filter = returnList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::ReturnListView> vecRetList = dataFormBL->GetAllDataForClass<BusinessLayer::ReturnListView>(errorMessage, filter);
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
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
	docForm->show();
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
	QMdiSubWindow *craeteRtrnListWindow = new QMdiSubWindow;
	craeteRtrnListWindow->setWidget(craeteRtrnListDlg);
	craeteRtrnListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteRtrnListWindow);
	craeteRtrnListDlg->show();
}
void DataForm::UdpRtrnListDlg()
{
	CreateRtrnListDlg *craeteRtrnListDlg = new CreateRtrnListDlg(dataFormBL, true, this);
	craeteRtrnListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteRtrnListDlg->setWindowTitle(tr("Update product in return list"));
	QMdiSubWindow *craeteRtrnListWindow = new QMdiSubWindow;
	craeteRtrnListWindow->setWidget(craeteRtrnListDlg);
	craeteRtrnListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteRtrnListWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *salaryWindow = new QMdiSubWindow;
	salaryWindow->setWidget(salaryDlg);
	salaryWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(salaryWindow);
	salaryDlg->show();
}
void DataForm::UdpSlrDlg()
{
	CreateSlrDlg *salaryDlg = new CreateSlrDlg(dataFormBL, true, this);
	salaryDlg->setAttribute(Qt::WA_DeleteOnClose);
	salaryDlg->setWindowTitle(tr("Update salary"));
	QMdiSubWindow *salaryWindow = new QMdiSubWindow;
	salaryWindow->setWidget(salaryDlg);
	salaryWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(salaryWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *salaryTypeWindow = new QMdiSubWindow;
	salaryTypeWindow->setWidget(salaryTypeDlg);
	salaryTypeWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(salaryTypeWindow);
	salaryTypeDlg->show();
}
void DataForm::UdpSlrTypeDlg()
{
	CreateSlrTypeDlg *salaryTypeDlg = new CreateSlrTypeDlg(dataFormBL, true, this);
	salaryTypeDlg->setAttribute(Qt::WA_DeleteOnClose);
	salaryTypeDlg->setWindowTitle(tr("Update salary type"));
	QMdiSubWindow *salaryTypeWindow = new QMdiSubWindow;
	salaryTypeWindow->setWidget(salaryTypeDlg);
	salaryTypeWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(salaryTypeWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *statusWindow = new QMdiSubWindow;
	statusWindow->setWidget(statusDlg);
	statusWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(statusWindow);
	statusDlg->show();
}
void DataForm::UdpStsDlg()
{
	CreateStsDlg *statusDlg = new CreateStsDlg(dataFormBL, true, this);
	statusDlg->setAttribute(Qt::WA_DeleteOnClose);
	statusDlg->setWindowTitle(tr("Update status"));
	QMdiSubWindow *statusWindow = new QMdiSubWindow;
	statusWindow->setWidget(statusDlg);
	statusWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(statusWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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


void DataForm::CrtStsRuleDlg()
{
	CreateStsRuleDlg *statusRuleDlg = new CreateStsRuleDlg(dataFormBL, false, this);
	statusRuleDlg->setAttribute(Qt::WA_DeleteOnClose);
	statusRuleDlg->setWindowTitle(tr("Create status rule"));
	QMdiSubWindow *statusRuleWindow = new QMdiSubWindow;
	statusRuleWindow->setWidget(statusRuleDlg);
	statusRuleWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(statusRuleWindow);
	statusRuleDlg->show();
}
void DataForm::UdpStsRuleDlg()
{
	CreateStsRuleDlg *statusRuleDlg = new CreateStsRuleDlg(dataFormBL, true, this);
	statusRuleDlg->setAttribute(Qt::WA_DeleteOnClose);
	statusRuleDlg->setWindowTitle(tr("Update status rule"));
	QMdiSubWindow *statusRuleWindow = new QMdiSubWindow;
	statusRuleWindow->setWidget(statusRuleDlg);
	statusRuleWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(statusRuleWindow);
	if (statusRuleDlg->FillDlgElements(tableView))
	{
		statusRuleDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelStsRuleDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::StatusRule statusRule;
	statusRule.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteStatusRule (&statusRule, errorMessage))
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
			QString(tr("Status rule with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtSpecDlg()
{
	CreateSpecDlg *specPDlg = new CreateSpecDlg(dataFormBL, false, this);
	specPDlg->setAttribute(Qt::WA_DeleteOnClose);
	specPDlg->setWindowTitle(tr("Create specification"));
	QMdiSubWindow *specPWindow = new QMdiSubWindow;
	specPWindow->setWidget(specPDlg);
	specPWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(specPWindow);
	specPDlg->show();
}
void DataForm::UdpSpecDlg()
{
	CreateSpecDlg *specPDlg = new CreateSpecDlg(dataFormBL, true, this);
	specPDlg->setAttribute(Qt::WA_DeleteOnClose);
	specPDlg->setWindowTitle(tr("Update specification"));
	QMdiSubWindow *specPWindow = new QMdiSubWindow;
	specPWindow->setWidget(specPDlg);
	specPWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(specPWindow);
	if (specPDlg->FillDlgElements(tableView))
	{
		specPDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelSpecDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Specification specification;
	specification.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteSpecification(&specification, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Specification with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::ViewSpecDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Specification spec;
	if (!spec.GetSpecificationByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::SpecificationList specList;
	BusinessLayer::Employee employee;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;
	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), spec.GetEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!employee.GetEmployeeByID(dataFormBL->GetOrmasDal(), spec.GetEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}

	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/specification.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	specList.SetSpecificationID(spec.GetID());
	std::string filter = specList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::SpecificationListView> vecSpecList = dataFormBL->GetAllDataForClass<BusinessLayer::SpecificationListView>(errorMessage, filter);
	if (vecSpecList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(spec.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(spec.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName1Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName1Ph"), QString(employee.GetSurname().c_str()) + " " + QString(employee.GetName().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	QString tableBody;
	for each (auto item in vecSpecList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
		tableBody += "<td>" + QString::number(product.GetPrice()) + "</td>";
		tableBody += "<td>" + QString::number(item.GetCount()) + "</td>";
		tableBody += "<td>" + QString::number(item.GetCount()*product.GetPrice(),'f',3) + "</td>";
		tableBody += "</tr>";
		i++;
	}
	reportText.replace(QString("TableBodyPh"), tableBody, Qt::CaseInsensitive);
	reportText.replace(QString("SumPh"), QString::number(spec.GetSum(), 'f',3), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
}

void DataForm::CrtSpecListDlg()
{
	CreateSpecListDlg *specListDlg = new CreateSpecListDlg(dataFormBL, false, this);
	if (0 != specificationID)
	{
		specListDlg->specificationID = specificationID;
	}
	specListDlg->setAttribute(Qt::WA_DeleteOnClose);
	specListDlg->setWindowTitle(tr("Add product to specification list"));
	QMdiSubWindow *specListWindow = new QMdiSubWindow;
	specListWindow->setWidget(specListDlg);
	specListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(specListWindow);
	specListDlg->show();
}
void DataForm::UdpSpecListDlg()
{
	CreateSpecListDlg *specListDlg = new CreateSpecListDlg(dataFormBL, true, this);
	specListDlg->setAttribute(Qt::WA_DeleteOnClose);
	specListDlg->setWindowTitle(tr("Update product in specification list"));
	QMdiSubWindow *specListWindow = new QMdiSubWindow;
	specListWindow->setWidget(specListDlg);
	specListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(specListWindow);
	if (specListDlg->FillDlgElements(tableView))
	{
		specListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelSpecListDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::SpecificationList specificationList;
	specificationList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteSpecificationList(&specificationList, errorMessage))
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

void DataForm::CrtSplDlg()
{
	CreateSplDlg *spoilageDlg = new CreateSplDlg(dataFormBL, false, this);
	spoilageDlg->setAttribute(Qt::WA_DeleteOnClose);
	spoilageDlg->setWindowTitle(tr("Create spoilage"));
	QMdiSubWindow *spoilageWindow = new QMdiSubWindow;
	spoilageWindow->setWidget(spoilageDlg);
	spoilageWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(spoilageWindow);
	spoilageDlg->show();
}
void DataForm::UdpSplDlg()
{
	CreateSplDlg *spoilageDlg = new CreateSplDlg(dataFormBL, true, this);
	spoilageDlg->setAttribute(Qt::WA_DeleteOnClose);
	spoilageDlg->setWindowTitle(tr("Update spoilage"));
	QMdiSubWindow *spoilageWindow = new QMdiSubWindow;
	spoilageWindow->setWidget(spoilageDlg);
	spoilageWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(spoilageWindow);
	if (spoilageDlg->FillDlgElements(tableView))
	{
		spoilageDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelSplDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Spoilage spoilage;
	spoilage.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteSpoilage(&spoilage, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Spoilage with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::ViewSplDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Spoilage spoilage;
	if (!spoilage.GetSpoilageByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::SpoilageList splList;
	BusinessLayer::Employee employee;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;
	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), spoilage.GetEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!employee.GetEmployeeByID(dataFormBL->GetOrmasDal(), spoilage.GetEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	
	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/spoilage.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	splList.SetSpoilageID(spoilage.GetID());
	std::string filter = splList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::SpoilageListView> vecSplList = dataFormBL->GetAllDataForClass<BusinessLayer::SpoilageListView>(errorMessage, filter);
	if (vecSplList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(spoilage.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(spoilage.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName1Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName1Ph"), QString(employee.GetSurname().c_str()) + " " + QString(employee.GetName().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	BusinessLayer::NetCost netCost;
	QString tableBody;
	for each (auto item in vecSplList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		netCost.Clear();
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!netCost.GetNetCostByProductID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
	reportText.replace(QString("SumPh"), QString::number(spoilage.GetSum()), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
}

void DataForm::CrtSplListDlg()
{
	CreateSplListDlg *spoilageListDlg = new CreateSplListDlg(dataFormBL, false, this);
	if (0 != spoilageID)
	{
		spoilageListDlg->spoilageID = spoilageID;
	}
	spoilageListDlg->setAttribute(Qt::WA_DeleteOnClose);
	spoilageListDlg->setWindowTitle(tr("Add product to spoilage list"));
	QMdiSubWindow *spoilageListWindow = new QMdiSubWindow;
	spoilageListWindow->setWidget(spoilageListDlg);
	spoilageListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(spoilageListWindow);
	spoilageListDlg->show();
}
void DataForm::UdpSplListDlg()
{
	CreateSplListDlg *spoilageListDlg = new CreateSplListDlg(dataFormBL, true, this);
	spoilageListDlg->setAttribute(Qt::WA_DeleteOnClose);
	spoilageListDlg->setWindowTitle(tr("Update product in spoilage list"));
	QMdiSubWindow *spoilageListWindow = new QMdiSubWindow;
	spoilageListWindow->setWidget(spoilageListDlg);
	spoilageListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(spoilageListWindow);
	if (spoilageListDlg->FillDlgElements(tableView))
	{
		spoilageListDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelSplListDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::SpoilageList spoilageList;
	spoilageList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteSpoilageList(&spoilageList, errorMessage))
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
			QString(tr("Product with this id does not exist in spoilage list!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtStockDlg()
{
	CreateStockDlg *stockDlg = new CreateStockDlg(dataFormBL, false, this);
	stockDlg->setAttribute(Qt::WA_DeleteOnClose);
	stockDlg->setWindowTitle(tr("Create stock"));
	QMdiSubWindow *stockWindow = new QMdiSubWindow;
	stockWindow->setWidget(stockDlg);
	stockWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(stockWindow);
	stockDlg->show();
}
void DataForm::UdpStockDlg()
{
	CreateStockDlg *stockDlg = new CreateStockDlg(dataFormBL, true, this);
	stockDlg->setAttribute(Qt::WA_DeleteOnClose);
	stockDlg->setWindowTitle(tr("Update stock"));
	QMdiSubWindow *stockWindow = new QMdiSubWindow;
	stockWindow->setWidget(stockDlg);
	stockWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(stockWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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

void DataForm::CrtSAccDlg()
{
	CreateSAccDlg *sAccountDlg = new CreateSAccDlg(dataFormBL, false, this);
	sAccountDlg->setAttribute(Qt::WA_DeleteOnClose);
	sAccountDlg->setWindowTitle(tr("Create subaccount"));
	QMdiSubWindow *sAccountWindow = new QMdiSubWindow;
	sAccountWindow->setWidget(sAccountDlg);
	sAccountWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(sAccountWindow);
	sAccountDlg->show();
}
void DataForm::UdpSAccDlg()
{
	CreateSAccDlg *sAccountDlg = new CreateSAccDlg(dataFormBL, true, this);
	sAccountDlg->setAttribute(Qt::WA_DeleteOnClose);
	sAccountDlg->setWindowTitle(tr("Update subaccount"));
	QMdiSubWindow *sAccountWindow = new QMdiSubWindow;
	sAccountWindow->setWidget(sAccountDlg);
	sAccountWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(sAccountWindow);
	if (sAccountDlg->FillDlgElements(tableView))
	{
		sAccountDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelSAccDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Subaccount subaccount;
	subaccount.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteSubaccount(&subaccount, errorMessage))
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
			QString(tr("Subaccount with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtTmsDlg()
{
	CreateTmsDlg *tmsDlg = new CreateTmsDlg(dataFormBL, false, this);
	tmsDlg->setAttribute(Qt::WA_DeleteOnClose);
	tmsDlg->setWindowTitle(tr("Create timesheet"));
	QMdiSubWindow *tmsWindow = new QMdiSubWindow;
	tmsWindow->setWidget(tmsDlg);
	tmsWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(tmsWindow);
	tmsDlg->show();
}
void DataForm::UdpTmsDlg()
{
	CreateTmsDlg *tmsDlg = new CreateTmsDlg(dataFormBL, true, this);
	tmsDlg->setAttribute(Qt::WA_DeleteOnClose);
	tmsDlg->setWindowTitle(tr("Update timesheet"));
	QMdiSubWindow *tmsWindow = new QMdiSubWindow;
	tmsWindow->setWidget(tmsDlg);
	tmsWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(tmsWindow);
	if (tmsDlg->FillDlgElements(tableView))
	{
		tmsDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelTmsDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Timesheet timesheet;
	timesheet.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteTimesheet(&timesheet, errorMessage))
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
			QString(tr("Timesheet with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtTrsDlg()
{
	CreateTrsDlg *trsDlg = new CreateTrsDlg(dataFormBL, false, this);
	trsDlg->setAttribute(Qt::WA_DeleteOnClose);
	trsDlg->setWindowTitle(tr("Create transport"));
	QMdiSubWindow *trsWindow = new QMdiSubWindow;
	trsWindow->setWidget(trsDlg);
	trsWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(trsWindow);
	trsDlg->show();
}
void DataForm::UdpTrsDlg()
{
	CreateTrsDlg *trsDlg = new CreateTrsDlg(dataFormBL, true, this);
	trsDlg->setAttribute(Qt::WA_DeleteOnClose);
	trsDlg->setWindowTitle(tr("Update transport"));
	QMdiSubWindow *trsWindow = new QMdiSubWindow;
	trsWindow->setWidget(trsDlg);
	trsWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(trsWindow);
	if (trsDlg->FillDlgElements(tableView))
	{
		trsDlg->show();
	}
	/*else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}*/
}
void DataForm::DelTrsDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Transport transport;
	transport.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteTransport(&transport, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
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

void DataForm::ViewTrsDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Transport transport;
	if (!transport.GetTransportByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::TransportList transportList;
	BusinessLayer::Employee employee;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;
	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), transport.GetEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!employee.GetEmployeeByID(dataFormBL->GetOrmasDal(), transport.GetEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}

	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/transport.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	transportList.SetTransportID(transport.GetID());
	std::string filter = transportList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::TransportListView> vecTrsList = dataFormBL->GetAllDataForClass<BusinessLayer::TransportListView>(errorMessage, filter);
	if (vecTrsList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(transport.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(transport.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName1Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName1Ph"), QString(employee.GetSurname().c_str()) + " " + QString(employee.GetName().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	QString tableBody;
	double sum = 0;
	for each (auto item in vecTrsList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
		tableBody += "<td>" + QString::number(product.GetPrice(), 'f', 3) + "</td>";
		tableBody += "<td>" + QString::number(item.GetCount() * product.GetPrice(), 'f', 3) + "</td>";
		tableBody += "<td>" + QString(currency.GetShortName().c_str()) + "</td>";
		tableBody += "</tr>";
		i++;
		sum += item.GetCount() * product.GetPrice();
	}
	reportText.replace(QString("TableBodyPh"), tableBody, Qt::CaseInsensitive);
	reportText.replace(QString("SumPh"), QString::number(sum, 'f' ,3), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
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
	QMdiSubWindow *craeteTrsListWindow = new QMdiSubWindow;
	craeteTrsListWindow->setWidget(craeteTrsListDlg);
	craeteTrsListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteTrsListWindow);
	craeteTrsListDlg->show();
}
void DataForm::UdpTrsListDlg()
{
	CreateTrsListDlg *craeteTrsListDlg = new CreateTrsListDlg(dataFormBL, true, this);
	craeteTrsListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteTrsListDlg->setWindowTitle(tr("Update product in transport list"));
	QMdiSubWindow *craeteTrsListWindow = new QMdiSubWindow;
	craeteTrsListWindow->setWidget(craeteTrsListDlg);
	craeteTrsListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteTrsListWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *userWindow = new QMdiSubWindow;
	userWindow->setWidget(userDlg);
	userWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(userWindow);
	userDlg->show();
}
void DataForm::UdpUserDlg()
{
	CreateUserDlg *userDlg = new CreateUserDlg(dataFormBL, true, this);
	userDlg->setAttribute(Qt::WA_DeleteOnClose);
	userDlg->setWindowTitle(tr("Update user"));
	QMdiSubWindow *userWindow = new QMdiSubWindow;
	userWindow->setWidget(userDlg);
	userWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(userWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *withdrawalWindow = new QMdiSubWindow;
	withdrawalWindow->setWidget(withdrawalDlg);
	withdrawalWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(withdrawalWindow);
	withdrawalDlg->show();
}
void DataForm::UdpWdwDlg()
{
	CreateWdwDlg *withdrawalDlg = new CreateWdwDlg(dataFormBL, true, this);
	withdrawalDlg->setAttribute(Qt::WA_DeleteOnClose);
	withdrawalDlg->setWindowTitle(tr("Update withdrawal"));
	QMdiSubWindow *withdrawalWindow = new QMdiSubWindow;
	withdrawalWindow->setWidget(withdrawalDlg);
	withdrawalWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(withdrawalWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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


void DataForm::CrtWrhDlg()
{
	CreateWrhDlg *warehouseDlg = new CreateWrhDlg(dataFormBL, false, this);
	warehouseDlg->setAttribute(Qt::WA_DeleteOnClose);
	warehouseDlg->setWindowTitle(tr("Create warehouse"));
	QMdiSubWindow *warehouseWindow = new QMdiSubWindow;
	warehouseWindow->setWidget(warehouseDlg);
	warehouseWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(warehouseWindow);
	warehouseDlg->show();
}

void DataForm::UdpWrhDlg()
{
	CreateWrhDlg *warehouseDlg = new CreateWrhDlg(dataFormBL, true, this);
	warehouseDlg->setAttribute(Qt::WA_DeleteOnClose);
	warehouseDlg->setWindowTitle(tr("Update warehouse"));
	QMdiSubWindow *warehouseWindow = new QMdiSubWindow;
	warehouseWindow->setWidget(warehouseDlg);
	warehouseWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(warehouseWindow);
	if (warehouseDlg->FillDlgElements(tableView))
	{
		warehouseDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelWrhDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Warehouse warehouse;
	warehouse.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteWarehouse(&warehouse, errorMessage))
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
			QString(tr("Warehouse with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtWrhTpDlg()
{
	CreateWrhTypeDlg *wTypeDlg = new CreateWrhTypeDlg(dataFormBL, false, this);
	wTypeDlg->setAttribute(Qt::WA_DeleteOnClose);
	wTypeDlg->setWindowTitle(tr("Create warehouse type"));
	QMdiSubWindow *wTypeWindow = new QMdiSubWindow;
	wTypeWindow->setWidget(wTypeDlg);
	wTypeWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(wTypeWindow);
	wTypeDlg->show();
}
void DataForm::UdpWrhTpDlg()
{
	CreateWrhTypeDlg *wTypeDlg = new CreateWrhTypeDlg(dataFormBL, true, this);
	wTypeDlg->setAttribute(Qt::WA_DeleteOnClose);
	wTypeDlg->setWindowTitle(tr("Update warehouse type"));
	QMdiSubWindow *wTypeWindow = new QMdiSubWindow;
	wTypeWindow->setWidget(wTypeDlg);
	wTypeWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(wTypeWindow);
	if (wTypeDlg->FillDlgElements(tableView))
	{
		wTypeDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelWrhTpDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::WarehouseType wType;
	wType.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteWarehouseType(&wType, errorMessage))
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
			QString(tr("Warehouse type with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtWERDlg()
{
	CreateWERDlg *wRelDlg = new CreateWERDlg(dataFormBL, false, this);
	wRelDlg->setAttribute(Qt::WA_DeleteOnClose);
	wRelDlg->setWindowTitle(tr("Create warehouse-employee relation"));
	QMdiSubWindow *wRelWindow = new QMdiSubWindow;
	wRelWindow->setWidget(wRelDlg);
	wRelWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(wRelWindow);
	wRelDlg->show();
}
void DataForm::UdpWERDlg()
{
	CreateWERDlg *wRelDlg = new CreateWERDlg(dataFormBL, true, this);
	wRelDlg->setAttribute(Qt::WA_DeleteOnClose);
	wRelDlg->setWindowTitle(tr("Update warehouse-employee relation"));
	QMdiSubWindow *wRelWindow = new QMdiSubWindow;
	wRelWindow->setWidget(wRelDlg);
	wRelWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(wRelWindow);
	if (wRelDlg->FillDlgElements(tableView))
	{
		wRelDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelWERDlg()
{
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::WarehouseEmployeeRelation wareRel;

	if (0 != id && wareRel.GetWarehouseEmployeeByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		if (dataFormBL->DeleteWarehouseEmployeeRelation(&wareRel, errorMessage))
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
			QString(tr("Warehouse-employee relation with this id does not exist!")),
			QString(tr("Ok")));
	}
}

void DataForm::ViewWdwDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::Withdrawal withdrawal;
	if (!withdrawal.GetWithdrawalByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::User user;
	BusinessLayer::Employee cashier;
	BusinessLayer::Employee accountant;
	BusinessLayer::Employee owner;
	BusinessLayer::Role role;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;

	if (0 == role.GetRoleIDByName(dataFormBL->GetOrmasDal(), "CHIEF ACCOUNTANT", errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot find 'CHIEF ACCOUNTANT' role!")),
			QString(tr("Ok")));
		return;
	}

	accountant.SetRoleID(role.GetID());
	std::string empFilter = accountant.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::EmployeeView> vecEmpRep = dataFormBL->GetAllDataForClass<BusinessLayer::EmployeeView>(errorMessage, empFilter);
	if (vecEmpRep.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot find 'CHIEF ACCOUNTANT' employee!")),
			QString(tr("Ok")));
		return;
	}
	else
	{
		accountant.SetName(vecEmpRep.at(0).GetName());
		accountant.SetSurname(vecEmpRep.at(0).GetSurname());
	}

	role.Clear();
	if (0 == role.GetRoleIDByName(dataFormBL->GetOrmasDal(), "CASHIER", errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot find 'CASHIER' role!")),
			QString(tr("Ok")));
		return;
	}

	cashier.SetRoleID(role.GetID());
	std::string casFilter = cashier.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::EmployeeView> vecCasRep = dataFormBL->GetAllDataForClass<BusinessLayer::EmployeeView>(errorMessage, casFilter);
	if (vecCasRep.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot find 'CASHIER' employee!")),
			QString(tr("Ok")));
		return;
	}
	else
	{
		cashier.SetName(vecCasRep.at(0).GetName());
		cashier.SetSurname(vecCasRep.at(0).GetSurname());
	}

	role.Clear();
	if (0 == role.GetRoleIDByName(dataFormBL->GetOrmasDal(), "DIRECTOR", errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot find 'OWNER' role!")),
			QString(tr("Ok")));
		return;
	}

	owner.SetRoleID(role.GetID());
	std::string ownFilter = owner.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::EmployeeView> vecOwnRep = dataFormBL->GetAllDataForClass<BusinessLayer::EmployeeView>(errorMessage, ownFilter);
	if (vecOwnRep.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot find 'OWNER' employee!")),
			QString(tr("Ok")));
		return;
	}
	else
	{
		owner.SetName(vecOwnRep.at(0).GetName());
		owner.SetSurname(vecOwnRep.at(0).GetSurname());
	}

	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), accountant.GetID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	
	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Consumption chash order"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/consumption.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();

	BusinessLayer::Account acc;
	if (!acc.GetAccountByNumber(dataFormBL->GetOrmasDal(), "10110", errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Can't find account!")),
			QString(tr("Ok")));
		return;
	}

	BusinessLayer::Balance balance;
	BusinessLayer::Subaccount subAcc;
	BusinessLayer::Currency currency;
	BusinessLayer::Account account;
	if (withdrawal.GetUserID() > 0)
	{
		balance.SetUserID(withdrawal.GetUserID());
		std::string filter = balance.GenerateFilter(dataFormBL->GetOrmasDal());
		std::vector<BusinessLayer::BalanceView> balanceVector = dataFormBL->GetAllDataForClass<BusinessLayer::BalanceView>(errorMessage, filter);
		if (0 < balanceVector.size())
		{
			for each (auto item in balanceVector)
			{
				subAcc.Clear();
				if (subAcc.GetSubaccountByID(dataFormBL->GetOrmasDal(), item.GetSubaccountID(), errorMessage))
				{
					if (subAcc.GetParentAccountID() == withdrawal.GetAccountID())
					{
						balance.SetSubaccountID(subAcc.GetID());
					}
				}
			}
		}
		else
		{
			subAcc.Clear();
		}
		if (balance.GetSubaccountID() <= 0)
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Can't find subaccount for this withdrawal!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), withdrawal.GetCurrencyID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Can't find currency for this withdrawal!")),
				QString(tr("Ok")));
			return;
		}
		subAcc.Clear();
		if (!subAcc.GetSubaccountByID(dataFormBL->GetOrmasDal(), balance.GetSubaccountID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Can't find subaccount for this user!")),
				QString(tr("Ok")));
			return;
		}
	}
	else if (withdrawal.GetAccountID()>0)
	{
		account.Clear();
		if (!account.GetAccountByID(dataFormBL->GetOrmasDal(), withdrawal.GetAccountID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			return;
		}
	}
	else
	{
		subAcc.Clear();
		if (!subAcc.GetSubaccountByID(dataFormBL->GetOrmasDal(), withdrawal.GetSubaccountID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			return;
		}
		if (!account.GetAccountByID(dataFormBL->GetOrmasDal(), subAcc.GetParentAccountID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			return;
		}
	}

	//generating report
	reportText.replace(QString("ComNamePh"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("NumberPh"), QString::number(withdrawal.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(withdrawal.GetDate().c_str()), Qt::CaseInsensitive);
	if (withdrawal.GetUserID() > 0)
	{
		reportText.replace(QString("DebAccNumPh"), QString(subAcc.GetNumber().c_str()), Qt::CaseInsensitive);
	}
	else
	{
		reportText.replace(QString("DebAccNumPh"), QString(account.GetNumber().c_str()) , Qt::CaseInsensitive);
	}
	
	reportText.replace(QString("CredAccNumPh"), QString(acc.GetNumber().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("SumPh"), QString::number(withdrawal.GetValue()), Qt::CaseInsensitive);
	reportText.replace(QString("ToWhoPh"), QString(withdrawal.GetWho().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("TargetPh"), QString(withdrawal.GetTarget().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("OwnerNamePh"), QString(owner.GetSurname().c_str()) + " " + QString(owner.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("AccounantNamePh"), QString(accountant.GetSurname().c_str()) + " " + QString(accountant.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("CashierPh"), QString(cashier.GetSurname().c_str()) + " " + QString(cashier.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
}

void DataForm::CrtWOffDlg()
{
	CreateWOffDlg *writeOffDlg = new CreateWOffDlg(dataFormBL, false, this);
	writeOffDlg->setAttribute(Qt::WA_DeleteOnClose);
	writeOffDlg->setWindowTitle(tr("Create write-off"));
	QMdiSubWindow *writeOffWindow = new QMdiSubWindow;
	writeOffWindow->setWidget(writeOffDlg);
	writeOffWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(writeOffWindow);
	writeOffDlg->show();
}
void DataForm::UdpWOffDlg()
{
	CreateWOffDlg *writeOffDlg = new CreateWOffDlg(dataFormBL, true, this);
	writeOffDlg->setAttribute(Qt::WA_DeleteOnClose);
	writeOffDlg->setWindowTitle(tr("Update write-off"));
	QMdiSubWindow *writeOffWindow = new QMdiSubWindow;
	writeOffWindow->setWidget(writeOffDlg);
	writeOffWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(writeOffWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::WriteOff writeOff;
	writeOff.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteWriteOff(&writeOff, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
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

void DataForm::ViewWOffDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::WriteOff wOff;
	if (!wOff.GetWriteOffByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::WriteOffList wOffList;
	BusinessLayer::Employee employee;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;
	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), wOff.GetEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!employee.GetEmployeeByID(dataFormBL->GetOrmasDal(), wOff.GetEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}

	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/write_off.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	wOffList.SetWriteOffID(wOff.GetID());
	std::string filter = wOffList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::WriteOffListView> vecWOffList = dataFormBL->GetAllDataForClass<BusinessLayer::WriteOffListView>(errorMessage, filter);
	if (vecWOffList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(wOff.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(wOff.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName1Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName1Ph"), QString(employee.GetSurname().c_str()) + " " + QString(employee.GetName().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	QString tableBody;
	double sum = 0;
	for each (auto item in vecWOffList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
		tableBody += "<td>" + QString::number(product.GetPrice(), 'f', 3) + "</td>";
		tableBody += "<td>" + QString::number(item.GetCount() * product.GetPrice(), 'f', 3) + "</td>";
		tableBody += "<td>" + QString(currency.GetShortName().c_str()) + "</td>";
		tableBody += "</tr>";
		i++;
		sum += item.GetCount() * product.GetPrice();
	}
	reportText.replace(QString("TableBodyPh"), tableBody, Qt::CaseInsensitive);
	reportText.replace(QString("SumPh"), QString::number(sum, 'f',3), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
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
	QMdiSubWindow *craeteWOffListWindow = new QMdiSubWindow;
	craeteWOffListWindow->setWidget(craeteWOffListDlg);
	craeteWOffListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteWOffListWindow);
	craeteWOffListDlg->show();
}
void DataForm::UdpWOffListDlg()
{
	CreateWOffListDlg *craeteWOffListDlg = new CreateWOffListDlg(dataFormBL, true, this);
	craeteWOffListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteWOffListDlg->setWindowTitle(tr("Update product in write-off list"));
	QMdiSubWindow *craeteWOffListWindow = new QMdiSubWindow;
	craeteWOffListWindow->setWidget(craeteWOffListDlg);
	craeteWOffListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteWOffListWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
	QMdiSubWindow *writeOffRWindow = new QMdiSubWindow;
	writeOffRWindow->setWidget(writeOffRDlg);
	writeOffRWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(writeOffRWindow);
	writeOffRDlg->show();
}
void DataForm::UdpWOffRDlg()
{
	CreateWOffRDlg *writeOffRDlg = new CreateWOffRDlg(dataFormBL, true, this);
	writeOffRDlg->setAttribute(Qt::WA_DeleteOnClose);
	writeOffRDlg->setWindowTitle(tr("Update write-off raw"));
	QMdiSubWindow *writeOffRWindow = new QMdiSubWindow;
	writeOffRWindow->setWidget(writeOffRDlg);
	writeOffRWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(writeOffRWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::WriteOffRaw writeOffRaw;
	writeOffRaw.SetID(id);
	if (0 != id)
	{
		dataFormBL->StartTransaction(errorMessage);
		if (dataFormBL->DeleteWriteOffRaw(&writeOffRaw, errorMessage))
		{
			dataFormBL->CommitTransaction(errorMessage);
			tableView->model()->removeRow(tableView->selectionModel()->currentIndex().row());
			ChangeBtnState();
		}
		else
		{
			dataFormBL->CancelTransaction(errorMessage);
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

void DataForm::ViewWOffRDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::WriteOffRaw wOffRaw;
	if (!wOffRaw.GetWriteOffRawByID(dataFormBL->GetOrmasDal(), id, errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	BusinessLayer::WriteOffRawList wOffRawList;
	BusinessLayer::Employee employee;
	BusinessLayer::Company company;
	BusinessLayer::CompanyEmployeeRelation ceRel;
	int companyID = 0;
	companyID = ceRel.GetCompanyByEmployeeID(dataFormBL->GetOrmasDal(), wOffRaw.GetStockEmployeeID(), errorMessage);
	if (!company.GetCompanyByID(dataFormBL->GetOrmasDal(), companyID, errorMessage) || 0 == companyID)
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}
	if (!employee.GetEmployeeByID(dataFormBL->GetOrmasDal(), wOffRaw.GetStockEmployeeID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Connot show information for this row!")),
			QString(tr("Ok")));
		return;
	}

	DocForm *docForm = new DocForm(dataFormBL, this);
	docForm->setAttribute(Qt::WA_DeleteOnClose);
	docForm->setWindowTitle(tr("Print report"));
	QMdiSubWindow *printRepWindow = new QMdiSubWindow;
	printRepWindow->setWidget(docForm);
	printRepWindow->setAttribute(Qt::WA_DeleteOnClose);
	printRepWindow->resize(docForm->size().width() + 18, docForm->size().height() + 30);
	((MainForm*)parentForm)->mdiArea->addSubWindow(printRepWindow);

	QFile file;
	file.setFileName(":/docs/write_off.html");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("Cannot find report tamplate!")),
			QString(tr("Ok")));
		return;
	}
	QString reportText = file.readAll();
	wOffRawList.SetWriteOffRawID(wOffRaw.GetID());
	std::string filter = wOffRawList.GenerateFilter(dataFormBL->GetOrmasDal());
	std::vector<BusinessLayer::WriteOffRawListView> vecWOffRawList = dataFormBL->GetAllDataForClass<BusinessLayer::WriteOffRawListView>(errorMessage, filter);
	if (vecWOffRawList.size() == 0)
	{
		QMessageBox::information(NULL, QString(tr("Info")),
			QString(tr("List is empty!")),
			QString(tr("Ok")));
		return;
	}

	//generating report
	reportText.replace(QString("NumberPh"), QString::number(wOffRaw.GetID()), Qt::CaseInsensitive);
	reportText.replace(QString("DatePh"), QString(wOffRaw.GetDate().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("ComName1Ph"), QString(company.GetName().c_str()), Qt::CaseInsensitive);
	reportText.replace(QString("UserName1Ph"), QString(employee.GetSurname().c_str()) + " " + QString(employee.GetName().c_str()), Qt::CaseInsensitive);
	int i = 1;
	BusinessLayer::Product product;
	BusinessLayer::Measure measure;
	BusinessLayer::Currency currency;
	BusinessLayer::NetCost netCost;
	QString tableBody;
	for each (auto item in vecWOffRawList)
	{
		product.Clear();
		measure.Clear();
		currency.Clear();
		netCost.Clear();
		if (!product.GetProductByID(dataFormBL->GetOrmasDal(), item.GetProductID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Product is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!measure.GetMeasureByID(dataFormBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Info")),
				QString(tr("Measure is wrong!")),
				QString(tr("Ok")));
			return;
		}
		if (!currency.GetCurrencyByID(dataFormBL->GetOrmasDal(), product.GetCurrencyID(), errorMessage))
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
	reportText.replace(QString("SumPh"), QString::number(wOffRaw.GetSum()), Qt::CaseInsensitive);
	reportText.replace(QString("CurrencyPh"), QString(currency.GetShortName().c_str()), Qt::CaseInsensitive);

	docForm->webEngineView->setHtml(reportText);
	docForm->SetContent(reportText);
	docForm->webEngineView->show();
	docForm->show();
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
	QMdiSubWindow *craeteWOffRListWindow = new QMdiSubWindow;
	craeteWOffRListWindow->setWidget(craeteWOffRListDlg);
	craeteWOffRListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteWOffRListWindow);
	craeteWOffRListDlg->show();
}
void DataForm::UdpWOffRListDlg()
{
	CreateWOffRListDlg *craeteWOffRListDlg = new CreateWOffRListDlg(dataFormBL, true, this);
	craeteWOffRListDlg->setAttribute(Qt::WA_DeleteOnClose);
	craeteWOffRListDlg->setWindowTitle(tr("Update raw in write-off list"));
	QMdiSubWindow *craeteWOffRListWindow = new QMdiSubWindow;
	craeteWOffRListWindow->setWidget(craeteWOffRListDlg);
	craeteWOffRListWindow->setAttribute(Qt::WA_DeleteOnClose);
	((MainForm*)parentForm)->mdiArea->addSubWindow(craeteWOffRListWindow);
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
	int result = QMessageBox::question(this, QString(tr("Affirm")),
		QString(tr("Do you really want to delete these data? (WARNING! All data will be irretrievable lost)")),
		QString(tr("Yes")), QString(tr("No")));
	if (result == 1)
		return;
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
QStringList DataForm::GetTableHeader<BusinessLayer::Account>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Number") << QObject::tr("Start balance") << QObject::tr("Current balance")
	 << QObject::tr("Details");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::AccountType>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Type name") << QObject::tr("Type number") << QObject::tr("Comment");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::AccountableView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Information")
		<< QObject::tr("Employee phone") << QObject::tr("Employee address") << QObject::tr("Role name");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::AccessView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Role name") << QObject::tr("Item english name") << QObject::tr("Item russian name") 
		<< QObject::tr("Division") << QObject::tr("Role ID") << QObject::tr("Access item ID");
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
	header << QObject::tr("ID") << QObject::tr("User name") << QObject::tr("User surname") << QObject::tr("Subaccount number")
		<< QObject::tr("Current balance") << QObject::tr("Currency name") << QObject::tr("User ID") << QObject::tr("Account ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Branch>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Branch name") << QObject::tr("Branch address") << QObject::tr("Branch phone")
		<< QObject::tr("Commnet");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::BorrowerView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("User name") << QObject::tr("User surname") << QObject::tr("Comment")
		<< QObject::tr("User phone") << QObject::tr("User address")  << QObject::tr("Role name")
		<< QObject::tr("Password") << QObject::tr("User email") << QObject::tr("Activated") << QObject::tr("Role ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::CashboxView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Subaccount number") << QObject::tr("Information") << QObject::tr("Cashbox address")
		<< QObject::tr("Subaccount ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::CashboxEmployeeRelationView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Subaccount number") << QObject::tr("Cashbox address") << QObject::tr("User name")
		<< QObject::tr("User surname") << QObject::tr("User phone") << QObject::tr("Role name") << QObject::tr("Cashbox ID")
		<< QObject::tr("Employee ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ChartOfAccountsView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Number") << QObject::tr("Name") << QObject::tr("Type name")
		<< QObject::tr("Account type ID");
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
QStringList DataForm::GetTableHeader<BusinessLayer::CompanyAccountRelationView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Company name") << QObject::tr("Account number") 
		<< QObject::tr("Company ID") << QObject::tr("Account ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::CompanyEmployeeRelationView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Company name") << QObject::tr("Employee name") << QObject::tr("Employee surname") 
		<< QObject::tr("Employee Phone") << QObject::tr("Company ID") << QObject::tr("Account ID");
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
QStringList DataForm::GetTableHeader<BusinessLayer::Division>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Name") << QObject::tr("Code");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::EmployeeView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Name") << QObject::tr("Surname") << QObject::tr("Position name") 
		<< QObject::tr("Phone") << QObject::tr("Address") << QObject::tr("Birth date") << QObject::tr("Role name") 
		<< QObject::tr("Hire date") << QObject::tr("Password") << QObject::tr("Email")
		<< QObject::tr("Avtivated") << QObject::tr("Role ID") << QObject::tr("Position ID")
		<< QObject::tr("Division-Employee-ID") << QObject::tr("Division ID") << QObject::tr("Is contract?");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::EmployeeProductRelationView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Name") << QObject::tr("Surname") 
		<< QObject::tr("Phone") << QObject::tr("Product name") << QObject::tr("Price") << QObject::tr("Employee ID")
		<< QObject::tr("Product ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::EntryView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Date") << QObject::tr("Debiting account number") << QObject::tr("Value")
		<< QObject::tr("Crediting account number") << QObject::tr("Debiting account ID") << QObject::tr("Crediting account ID")
		<< QObject::tr("Description");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::EntryRouting>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Operation") << QObject::tr("Debit") 
		<< QObject::tr("Credit");
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
QStringList DataForm::GetTableHeader<BusinessLayer::JobpriceView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Product name") << QObject::tr("Value")
		<< QObject::tr("Currnecy name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Position name")
		<< QObject::tr("Product ID") << QObject::tr("Currency ID") << QObject::tr("Measure ID") 
		<< QObject::tr("Position ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::JobsheetView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Date") << QObject::tr("User name")
		<< QObject::tr("User surname") << QObject::tr("User phone") << QObject::tr("Product name") << QObject::tr("Count")
		<< QObject::tr("Measure name") << QObject::tr("Product ID") << QObject::tr("Measure ID");
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
QStringList DataForm::GetTableHeader<BusinessLayer::NetCostView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Date") << QObject::tr("Product name") << QObject::tr("Volume") << QObject::tr("Measure name")
		<< QObject::tr("Value") << QObject::tr("Currency name") << QObject::tr("Currency ID") << QObject::tr("Product ID") << QObject::tr("Is outdated?");
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
		<< QObject::tr("Status name") << QObject::tr("Purveyor name") << QObject::tr("Purveyor surname") << QObject::tr("Purveyor phone")
		<< QObject::tr("Purveyor company name") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
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
QStringList DataForm::GetTableHeader<BusinessLayer::PercentRate>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Value") << QObject::tr("Condition") << QObject::tr("Position ID");
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
	header << QObject::tr("ID") << QObject::tr("Date") << QObject::tr("User name") << QObject::tr("User surname") 
		<< QObject::tr("User Phone") << QObject::tr("Value") << QObject::tr("Currency name") << QObject::tr("Target")
		<< QObject::tr("Account number") << QObject::tr("Subccount number") << QObject::tr("From who") << QObject::tr("Status name") 
		<< QObject::tr("User ID") << QObject::tr("Currency ID") << QObject::tr("Status ID") << QObject::tr("Account ID") << QObject::tr("Subaccount ID");
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
		<< QObject::tr("Value") << QObject::tr("Currency name") << QObject::tr("Currency ID") << QObject::tr("Product ID") << QObject::tr("Is outdated?");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ProductType>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Name") << QObject::tr("Short name") << QObject::tr("Code");
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
QStringList DataForm::GetTableHeader<BusinessLayer::ProductBranchRelationView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Name") << QObject::tr("Address") << QObject::tr("Product name") 
		<< QObject::tr("Price") << QObject::tr("Product id") << QObject::tr("Branch ID");
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
QStringList DataForm::GetTableHeader<BusinessLayer::ProductionConsumeRawView>()
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
QStringList DataForm::GetTableHeader<BusinessLayer::ProductionConsumeRawListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Consume raw ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ProductionPlanView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Date") << QObject::tr("Count") << QObject::tr("Sum") << QObject::tr("Currency name")
		<< QObject::tr("Status name") << QObject::tr("Employee name") << QObject::tr("Employee surname")
		<< QObject::tr("Employee phone") << QObject::tr("Employee position") << QObject::tr("Employee ID") << QObject::tr("Status ID") 
		<< QObject::tr("Currency ID") << QObject::tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ProductionPlanListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Production plan ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ProductionStockView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Warehouse name") << QObject::tr("Subaccount number")
		<< QObject::tr("Status name") << QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID")
		<< QObject::tr("Warehouse ID");
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
QStringList DataForm::GetTableHeader<BusinessLayer::PurveyorView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Name") << QObject::tr("Surname") << QObject::tr("Phone") << QObject::tr("Country name")
		<< QObject::tr("Region name") << QObject::tr("City name") << QObject::tr("Address") << QObject::tr("Company name")
		<< QObject::tr("Role name") << QObject::tr("Password") << QObject::tr("Email")
		<< QObject::tr("Avtivated") << QObject::tr("Role ID") << QObject::tr("Location ID");
	return header;
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
QStringList DataForm::GetTableHeader<BusinessLayer::StockTransferView>()
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
QStringList DataForm::GetTableHeader<BusinessLayer::StockTransferListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Receipt raw ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}
template<>
QStringList DataForm::GetTableHeader<BusinessLayer::RelationView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("User 1 name") << QObject::tr("User 1 surname") << QObject::tr("User 1 Phone") 
		<< QObject::tr("Relation type name") << QObject::tr("User 2 name") << QObject::tr("User 2 surname") 
		<< QObject::tr("User 2 Phone") << QObject::tr("User 1") << QObject::tr("User 2") << QObject::tr("Relation type");
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
QStringList DataForm::GetTableHeader<BusinessLayer::StatusRuleView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Operation") << QObject::tr("Status name") << QObject::tr("Status ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::SpecificationView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Date") << QObject::tr("Product name")
		<< QObject::tr("Sum") << QObject::tr("Currnecy name") << QObject::tr("Employee name") << QObject::tr("Employee surname")
		<< QObject::tr("Employee phone") << QObject::tr("Employee position") << QObject::tr("Product ID")
		<< QObject::tr("Currency ID") << QObject::tr("Employee ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::SpecificationListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Specification ID") << QObject::tr("Product name")
		<< QObject::tr("Count") << QObject::tr("Measure name") << QObject::tr("Product ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::SpoilageView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Date") << QObject::tr("Count") << QObject::tr("Sum") << QObject::tr("Currency name")
		<< QObject::tr("Status name") << QObject::tr("Employee name") << QObject::tr("Employee surname")
		<< QObject::tr("Employee phone") << QObject::tr("Employee position") << QObject::tr("Employee ID") << QObject::tr("Status ID")
		<< QObject::tr("Currency ID") << QObject::tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::SpoilageListView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Spoilage ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Status name")
		<< QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::StockView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Product name") << QObject::tr("Price")
		<< QObject::tr("Currency name") << QObject::tr("Volume") << QObject::tr("Measure name") << QObject::tr("Count")
		<< QObject::tr("Sum") << QObject::tr("Sum currency name") << QObject::tr("Warehouse name") << QObject::tr("Subaccount number")
		<< QObject::tr("Status name") << QObject::tr("Product ID") << QObject::tr("Status ID") << QObject::tr("Currency ID")
		<< QObject::tr("Warehouse ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::SubaccountView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Parent account ID") << QObject::tr("Parent account Number") << QObject::tr("Number") 
		<< QObject::tr("Start balance") << QObject::tr("Current balance")
		<< QObject::tr("Currency name") << QObject::tr("Status name") << QObject::tr("Currency ID") << QObject::tr("Status ID")
		<< QObject::tr("Opened date") << QObject::tr("Closed date") << QObject::tr("Details");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::TimesheetView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
		<< QObject::tr("Date") << QObject::tr("Worked time") << QObject::tr("Salary ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::TransportView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Transportation date") << QObject::tr("Execution date") << QObject::tr("Status code")
		<< QObject::tr("Status name") << QObject::tr("User name") << QObject::tr("User surname") << QObject::tr("User phone")
		<< QObject::tr("Userposition") << QObject::tr("Employee name") << QObject::tr("Employee surname") << QObject::tr("Employee phone")
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
QStringList DataForm::GetTableHeader<BusinessLayer::WarehouseView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Warehouse name") << QObject::tr("Subaccount number") << QObject::tr("Type name")
		<< QObject::tr("Warehouse address") << QObject::tr("Warehouse phone") << QObject::tr("Warehouse type ID") 
		<< QObject::tr("Subaccount ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::WarehouseType>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Type code") << QObject::tr("Type purpose") << QObject::tr("Type name");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::WarehouseEmployeeRelationView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("User name") << QObject::tr("User surname") << QObject::tr("User phone")
		<< QObject::tr("Role name") << QObject::tr("Warehouse name") << QObject::tr("Subaccount number")
		<< QObject::tr("Warehouse ID") << QObject::tr("Employee ID");
	return header;
}


template<>
QStringList DataForm::GetTableHeader<BusinessLayer::WithdrawalView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Date") << QObject::tr("Value") << QObject::tr("Currency name") 
		<< QObject::tr("User name") << QObject::tr("User surname") << QObject::tr("User phone") << QObject::tr("Status name") << QObject::tr("Account number")
		<< QObject::tr("Subaccount number") << QObject::tr("To who") << QObject::tr("Target") << QObject::tr("User ID") << QObject::tr("Currency ID")
		<< QObject::tr("Subaccount ID") << QObject::tr("Status ID") << QObject::tr("Account ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::WriteOffView>()
{
	QStringList header;
	header << QObject::tr("ID") << QObject::tr("Write-off date") << QObject::tr("Execution date") << QObject::tr("Status code") << QObject::tr("Status name")
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
	header << QObject::tr("ID") << QObject::tr("Write-off date") << QObject::tr("Execution date") << QObject::tr("Status code")
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
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Account>(BusinessLayer::Account& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetNumber().c_str())
		<< new QStandardItem(QString::number(data.GetStartBalance(), 'f', 3))
		<< new QStandardItem(QString::number(data.GetCurrentBalance(), 'f', 3));
	return items;
}

// Template specializations for generating data ---------------------------------------------------------------------------
template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::AccountableView>(BusinessLayer::AccountableView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetSurname().c_str())
		<< new QStandardItem(data.GetInformation().c_str())
		<< new QStandardItem(data.GetPhone().c_str())
		<< new QStandardItem(data.GetAddress().c_str())
		<< new QStandardItem(data.GetRoleName().c_str());
	return items;
}


template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::AccountType>(BusinessLayer::AccountType& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(QString::number(data.GetNumber())) << new QStandardItem(data.GetComment().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::AccessView>(BusinessLayer::AccessView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) 
		<< new QStandardItem(data.GetRoleName().c_str())
		<< new QStandardItem(data.GetAccessItemEng().c_str())
		<< new QStandardItem(data.GetAccessItemRu().c_str())
		<< new QStandardItem(data.GetDivision().c_str())
		<< new QStandardItem(QString::number(data.GetRoleID()))
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
		<< new QStandardItem(data.GetSubaccountNumber().c_str())
		<< new QStandardItem(QString::number(data.GetCurrentBalance(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetUserID()))
		<< new QStandardItem(QString::number(data.GetSubaccountID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Branch>(BusinessLayer::Branch& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetAddress().c_str())
		<< new QStandardItem(data.GetPhone().c_str())
		<< new QStandardItem(data.GetComment().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::BorrowerView>(BusinessLayer::BorrowerView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetUserID()))
		<< new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetSurname().c_str())
		<< new QStandardItem(data.GetComment().c_str())
		<< new QStandardItem(data.GetPhone().c_str())
		<< new QStandardItem(data.GetAddress().c_str())
		<< new QStandardItem(data.GetRoleName().c_str())
		<< new QStandardItem(data.GetPassword().c_str())
		<< new QStandardItem(data.GetEmail().c_str())
		<< new QStandardItem(data.GetActivated() ? "true" : "false")
		<< new QStandardItem(QString::number(data.GetRoleID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::CashboxView>(BusinessLayer::CashboxView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetSubaccountNumber().c_str())
		<< new QStandardItem(data.GetInformation().c_str())
		<< new QStandardItem(data.GetAddress().c_str())
		<< new QStandardItem(QString::number(data.GetSubaccountID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::CashboxEmployeeRelationView>(BusinessLayer::CashboxEmployeeRelationView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetSubaccountNumber().c_str())
		<< new QStandardItem(data.GetCashboxAddress().c_str())
		<< new QStandardItem(data.GetUsername().c_str())
		<< new QStandardItem(data.GetUserSurname().c_str())
		<< new QStandardItem(data.GetUserPhone().c_str())
		<< new QStandardItem(data.GetRoleName().c_str())
		<< new QStandardItem(QString::number(data.GetCashboxID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ChartOfAccountsView>(BusinessLayer::ChartOfAccountsView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetNumber().c_str())
		<< new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetAccountTypeName().c_str())
		<< new QStandardItem(QString::number(data.GetAccountTypeID()));
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
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::CompanyAccountRelationView>(BusinessLayer::CompanyAccountRelationView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetCompanyName().c_str())
		<< new QStandardItem(data.GetAccountNumber().c_str())
		<< new QStandardItem(QString::number(data.GetCompanyID())) 
		<< new QStandardItem(QString::number(data.GetAccountID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::CompanyEmployeeRelationView>(BusinessLayer::CompanyEmployeeRelationView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetCompanyName().c_str())
		<< new QStandardItem(data.GetUsername().c_str())
		<< new QStandardItem(data.GetUserSurname().c_str())
		<< new QStandardItem(data.GetUserPhone().c_str())
		<< new QStandardItem(QString::number(data.GetCompanyID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()));
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Division>(BusinessLayer::Division& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetName().c_str()) << new QStandardItem(data.GetCode().c_str());
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
		<< new QStandardItem(QString::number(data.GetPositionID()))
		<< new QStandardItem(QString::number(data.GetDivisionEmployeeID()))
		<< new QStandardItem(QString::number(data.GetDivisionID()))
		<< new QStandardItem(data.GetIsContract() ? "true" : "false");
	return items;
}


template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::EmployeeProductRelationView>(BusinessLayer::EmployeeProductRelationView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetUsername().c_str())
		<< new QStandardItem(data.GetUserSurname().c_str())
		<< new QStandardItem(data.GetUserPhone().c_str())
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice(), 'f', 2))
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetProductID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::EntryView>(BusinessLayer::EntryView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetDebitingAccountNumber().c_str())
		<< new QStandardItem(QString::number(data.GetValue(), 'f', 3))
		<< new QStandardItem(data.GetCreditingAccountNumber().c_str())
		<< new QStandardItem(QString::number(data.GetDebitingAccountID()))
		<< new QStandardItem(QString::number(data.GetCreditingAccountID()))
		<< new QStandardItem(data.GetDescription().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::EntryRouting>(BusinessLayer::EntryRouting& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetOperation().c_str())
		<< new QStandardItem(QString::number(data.GetDebitAccountID()))
		<< new QStandardItem(QString::number(data.GetCreditAccountID()));
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::JobpriceView>(BusinessLayer::JobpriceView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetValue()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(data.GetPositionName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(QString::number(data.GetMeasureID()))
		<< new QStandardItem(QString::number(data.GetPositionID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::JobsheetView>(BusinessLayer::JobsheetView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()));
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
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::NetCostView>(BusinessLayer::NetCostView& data)
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
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(data.GetIsOutdated() ? "true" : "false");
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
		<< new QStandardItem(data.GetPurveyorName().c_str())
		<< new QStandardItem(data.GetPurveyorSurname().c_str())
		<< new QStandardItem(data.GetPurveyorPhone().c_str())
		<< new QStandardItem(data.GetPurveyorCompanyName().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetEmployeePosition().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetPurveyorID()))
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::PercentRate>(BusinessLayer::PercentRate& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) 
		<< new QStandardItem(QString::number(data.GetValue()))
		<< new QStandardItem(data.GetCondition().c_str()) 
		<< new QStandardItem(QString::number(data.GetPositionID()));
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
		<< new QStandardItem(data.GetUsername().c_str())
		<< new QStandardItem(data.GetUserSurname().c_str())
		<< new QStandardItem(data.GetUserPhone().c_str())
		<< new QStandardItem(QString::number(data.GetValue()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetTarget().c_str())
		<< new QStandardItem(data.GetAccountNumber().c_str())
		<< new QStandardItem(data.GetSubaccountNumber().c_str())
		<< new QStandardItem(data.GetWho().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetUserID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetAccountID()))
		<< new QStandardItem(QString::number(data.GetSubaccountID()));
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
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(data.GetIsOutdated() ? "true" : "false");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductType>(BusinessLayer::ProductType& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetShortName().c_str()) << new QStandardItem(data.GetCode().c_str());
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
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductBranchRelationView>(BusinessLayer::ProductBranchRelationView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetBranchName().c_str())
		<< new QStandardItem(data.GetBranchAddress().c_str())
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString(QString::number(data.GetPrice())))
		<< new QStandardItem(QString(QString::number(data.GetProductID())))
		<< new QStandardItem(QString::number(data.GetBranchID()));
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductionConsumeRawView>(BusinessLayer::ProductionConsumeRawView& data)
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetStockEmployeeID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductionConsumeRawListView>(BusinessLayer::ProductionConsumeRawListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetProductionConsumeRawID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetSum()/data.GetCount()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductionPlanView>(BusinessLayer::ProductionPlanView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetEmployeePosition().c_str())
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductionPlanListView>(BusinessLayer::ProductionPlanListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetProductionPlanID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductionStockView>(BusinessLayer::ProductionStockView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetWarehouseName().c_str())
		<< new QStandardItem(data.GetSubaccountNumber().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(QString::number(data.GetWarehouseID()));
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
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::PurveyorView>(BusinessLayer::PurveyorView& data)
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
		<< new QStandardItem(data.GetCompanyName().c_str())
		<< new QStandardItem(data.GetRoleName().c_str())
		<< new QStandardItem(data.GetPassword().c_str())
		<< new QStandardItem(data.GetEmail().c_str())
		<< new QStandardItem(data.GetActivated() ? "true" : "false")
		<< new QStandardItem(QString::number(data.GetRoleID()))
		<< new QStandardItem(QString::number(data.GetLocationID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::RelationView>(BusinessLayer::RelationView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetRelationName().c_str())
		<< new QStandardItem(data.GetUsername().c_str())
		<< new QStandardItem(data.GetUserSurname().c_str())
		<< new QStandardItem(data.GetUserPhone().c_str())
		<< new QStandardItem(QString::number(data.GetUser1ID()))
		<< new QStandardItem(QString::number(data.GetUser2ID())) 
		<< new QStandardItem(QString::number(data.GetRelationTypeID()));
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::StockTransferView>(BusinessLayer::StockTransferView& data)
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetStockEmployeeID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::StockTransferListView>(BusinessLayer::StockTransferListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetStockTransferID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::StatusRuleView>(BusinessLayer::StatusRuleView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetOperation().c_str())
		<< new QStandardItem(data.GetStatusName().c_str()) << new QStandardItem(QString::number(data.GetStatusID()));
	return items;
}


template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::SpecificationView>(BusinessLayer::SpecificationView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetEmployeePositionName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::SpecificationListView>(BusinessLayer::SpecificationListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetSpecificationID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::SpoilageView>(BusinessLayer::SpoilageView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetEmployeePosition().c_str())
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::SpoilageListView>(BusinessLayer::SpoilageListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetSpoilageID()))
		<< new QStandardItem(data.GetProductName().c_str())
		<< new QStandardItem(QString::number(data.GetPrice()))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetVolume()))
		<< new QStandardItem(data.GetMeasureName().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetWarehouseName().c_str())
		<< new QStandardItem(data.GetSubaccountNumber().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(QString::number(data.GetWarehouseID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::SubaccountView>(BusinessLayer::SubaccountView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(QString::number(data.GetParentAccountID()))
		<< new QStandardItem(data.GetParentAccountNumber().c_str())
		<< new QStandardItem(data.GetNumber().c_str())
		<< new QStandardItem(QString::number(data.GetStartBalance(), 'f', 3))
		<< new QStandardItem(QString::number(data.GetCurrentBalance(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(data.GetOpenedDate().c_str())
		<< new QStandardItem(data.GetClosedDate().c_str())
		<< new QStandardItem(data.GetDetails().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::TimesheetView>(BusinessLayer::TimesheetView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetUsername().c_str())
		<< new QStandardItem(data.GetUserPhone().c_str())
		<< new QStandardItem(data.GetUserPhone().c_str())
		<< new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(QString::number(data.GetWorkedTime()))
		<< new QStandardItem(QString::number(data.GetSalaryID()))
		<< new QStandardItem(icon, "Detail");
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
		<< new QStandardItem(data.GetUsername().c_str())
		<< new QStandardItem(data.GetUserSurname().c_str())
		<< new QStandardItem(data.GetUserPhone().c_str())
		<< new QStandardItem(data.GetUserPosition().c_str())
		<< new QStandardItem(data.GetEmployeeName().c_str())
		<< new QStandardItem(data.GetEmployeeSurname().c_str())
		<< new QStandardItem(data.GetEmployeePhone().c_str())
		<< new QStandardItem(data.GetEmployeePosition().c_str())
		<< new QStandardItem(QString::number(data.GetCount()))
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(QString::number(data.GetEmployeeID()))
		<< new QStandardItem(QString::number(data.GetUserID()))
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::WarehouseView>(BusinessLayer::WarehouseView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetSubaccountNumber().c_str())
		<< new QStandardItem(data.GetWarehouseTypeName().c_str())
		<< new QStandardItem(data.GetAddress().c_str())
		<< new QStandardItem(data.GetPhone().c_str())
		<< new QStandardItem(QString::number(data.GetWarehouseTypeID()))
		<< new QStandardItem(QString::number(data.GetSubaccountID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::WarehouseType>(BusinessLayer::WarehouseType& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetCode().c_str())
		<< new QStandardItem(data.GetPurpose().c_str())
		<< new QStandardItem(data.GetName().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::WarehouseEmployeeRelationView>(BusinessLayer::WarehouseEmployeeRelationView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID()))
		<< new QStandardItem(data.GetUsername().c_str())
		<< new QStandardItem(data.GetUserSurname().c_str())
		<< new QStandardItem(data.GetUserPhone().c_str())
		<< new QStandardItem(data.GetRoleName().c_str())
		<< new QStandardItem(data.GetWarehouseName().c_str())
		<< new QStandardItem(data.GetSubaccountNumber().c_str())
		<< new QStandardItem(QString::number(data.GetWarehouseID()))
		<< new QStandardItem(QString::number(data.GetEmployeeID()));
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
		<< new QStandardItem(data.GetUsername().c_str())
		<< new QStandardItem(data.GetUserSurname().c_str())
		<< new QStandardItem(data.GetUserPhone().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetAccountNumber().c_str())
		<< new QStandardItem(data.GetSubaccountNumber().c_str())
		<< new QStandardItem(data.GetWho().c_str())
		<< new QStandardItem(data.GetTarget().c_str())
		<< new QStandardItem(QString::number(data.GetUserID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(QString::number(data.GetSubaccountID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetAccountID()));
	return items;
}


template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::WriteOffView>(BusinessLayer::WriteOffView& data)
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
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
		<< new QStandardItem(QString::number(data.GetSum(), 'f', 3))
		<< new QStandardItem(data.GetCurrencyName().c_str())
		<< new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetStatusID()))
		<< new QStandardItem(QString::number(data.GetCurrencyID()));
	return items;
}
// Template specializations for connections ---------------------------------------------------------------------------
template<>
void DataForm::QtConnect<BusinessLayer::Account>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionAccounts");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtAccDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpAccDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelAccDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateCompanyAccount")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateCARDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateEntry")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateEtrDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePayment")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePmtDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWithdrawal")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWdwDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::AccountableView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionAccountables");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtAcctblDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpAcctblDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelAcctblDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}

	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::AccountType>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionAccountType");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtAccTpDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpAccTpDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelAccTpDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateChartOfAccounts")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateCOADlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}
template<>
void DataForm::QtConnect<BusinessLayer::AccessView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionAccess");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtAcsDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpAcsDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelAcsDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}	
	
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::AccessItem>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionAccessItems");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtAcsItemDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpAcsItemDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelAcsItemDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateAccess")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateAcsDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}


template<>
void DataForm::QtConnect<BusinessLayer::BalanceView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionBalances");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtBlcDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpBlcDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelBlcDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::Branch>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionBranch");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtBrhDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpBrhDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelBrhDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProductBranch")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePrdBrnDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::BorrowerView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionBorrowers");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtBrwDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpBrwDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelBrwDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::CashboxView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionCashbox");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtCbxDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpCbxDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCbxDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::CashboxEmployeeRelationView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionCashboxEmployee");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtCASHERDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpCASHERDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCASHERDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::ChartOfAccountsView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionChartOfAccounts");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtCOADlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpCOADlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCOADlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "GenerateOneAccount")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((GenerateOneAcc*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateAccount")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateAccDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSubaccount")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateAccDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ClientView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionClients");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtCltDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpCltDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCltDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateOrder")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateOrdDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateReturn")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRtrnDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWriteOff")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWOffDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePayment")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePmtDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::Company>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionCompany");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtCmpDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpCmpDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCmpDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}	
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProduct")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateProdDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::CompanyEmployeeRelationView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionCompanyEmployees");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtCERDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpCERDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCERDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::CompanyAccountRelationView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionCompanyAccounts");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtCARDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpCARDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCARDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::ConsumeProductView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionConsumptionProducts");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtConPDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpConPDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelConPDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewConPDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateConPList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateConPListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ConsumeProductListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionConsumptionProductsList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtConPListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpConPListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelConPListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateConsumeProduct")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateConPDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ConsumeRawView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionConsumptionRaws");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtConRDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpConRDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelConRDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}	
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewConRDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateConRList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateConRListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ConsumeRawListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionConsumptionRawsList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtConRListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpConRListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelConRListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateConsumeRaw")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateConRDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::Currency>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionCurrency");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtCurDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpCurDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCurDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::Division>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionDivision");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtDivDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpDivDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelDivDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::EmployeeView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionEmployees");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtEmpDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpEmpDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelEmpDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}	
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateAccountable")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateAcctbDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateBorrower")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateBrwDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateConsumeProduct")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateConPDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateConsumeRaw")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateConRDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateCompanyEmployee")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateCERDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateInventorization")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateInvDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateJobsheet")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateJbsDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateOrder")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateOrdDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateOrderRaw")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateOrdRDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateReceiptProduct")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRcpPDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateStockTransfer")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateStockTrDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProductionConsumeRaw")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateProdConRDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProductionPlan")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePPlanDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateReturn")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRtrnDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSpecification")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateSpecDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSalary")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateSlrDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSpoilage")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateSplDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateTransport")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateTrsDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWriteOff")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWOffDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWriteOffR")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWOffRDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CalcWages")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((ClcWagesDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateCashboxEmployee")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateCASHERDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWarehouseEmployee")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWERDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateEmployeeProduct")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateEmpPrdDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::EmployeeProductRelationView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionEmployeeProducts");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtEmpPrdDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpEmpPrdDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelEmpPrdDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::EntryView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionEntry");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtEtrDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpEtrDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelEtrDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}	
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}


template<>
void DataForm::QtConnect<BusinessLayer::EntryRouting>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionEntryRouting");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtEtrRtDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpEtrRtDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelEtrRtDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}


template<>
void DataForm::QtConnect<BusinessLayer::InventorizationView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionInventorization");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtInvDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpInvDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelInvDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewInvDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateInvList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateInvListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::InventorizationListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionInventorizationList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtInvListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpInvListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelInvListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateInventorization")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateInvDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::JobpriceView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionJobprice");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtJbpDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpJbpDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelJbpDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::JobsheetView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionJobsheet");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtJbsDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpJbsDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelJbsDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::Location>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionLocation");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtLcnDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpLcnDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelLcnDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateClient")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateCltDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePurveyor")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePurDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}


template<>
void DataForm::QtConnect<BusinessLayer::Measure>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionMeasure");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtMsrDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpMsrDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelMsrDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::NetCostView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionNetCost");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtNetCDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpNetCDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelNetCDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}


template<>
void DataForm::QtConnect<BusinessLayer::OrderView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionOrders");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtOrdDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpOrdDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelOrdDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewOrdDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateOrdList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateOrdListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::OrderListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionOrderList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtOrdListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpOrdListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelOrdListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateOrder")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateOrdDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::OrderRawView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionOrderRaws");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtOrdRDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpOrdRDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelOrdRDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewOrdRDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateOrdRList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateOrdRListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::OrderRawListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionOrderRawsList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtOrdRListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpOrdRListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelOrdRListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateOrderRaw")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateOrdRDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::PercentRate>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionPercentRate");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtPcrDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpPcrDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPcrDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::Photo>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionPhoto");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtPhotoDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpPhotoDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPhotoDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::PaymentView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionPayments");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtPmtDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpPmtDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPmtDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewPmtDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::Position>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionPosition");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtPosDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpPosDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPosDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateEmployee")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateEmpDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateJobsheet")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateJbsDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateJobprice")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateJbpDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePercentRate")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePrcDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateTimesheet")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateTmsDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::PriceView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionPrices");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtPrcDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpPrcDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPrcDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::ProductType>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionProductType");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtProdTpDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpProdTpDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelProdTpDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProduct")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateProdDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ProductView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionProducts");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtProdDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpProdDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelProdDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateConPList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateConPListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateConRList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateConRListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateInvList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateInvListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateOrdList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateOrdListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateOrdRList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateOrdRListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePrdnList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateProdnListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProdConRList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateProdConRListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePPlanList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePPlanListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProdnStock")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateStockDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateRcpPList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRcpPListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateStockTrList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateStockTrListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateRtrnList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRtrnListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSpecList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateSpecListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateStock")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateStockDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSpecList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateSpecListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSplList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateSplListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateTrsList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateTrsListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWOffList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWOffListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWOffRList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWOffRListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePhoto")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePhtDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateJobprice")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateJbpDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateJobsheet")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateJbsDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePrice")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePrcDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateNetCost")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateNetCDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSpecification")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateSpecDlg*)parentDialog), SLOT(SetID(int, QString)));
	}	
	if (parentDialog != nullptr && parentDialog->objectName() == "ReworkRaw")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((ReworkRawDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateEmployeeProduct")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateEmpPrdDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProductBranch")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePrdBrnDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ProductBranchRelationView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionBranchProducts");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtPrdBrnDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpPrdBrnDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPrdBrnDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::Production>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionProduction");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtProdnDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpProdnDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelProdnDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}	
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewProdnDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePrdnList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateProdnListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ProductionListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionProductionList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtProdnListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpProdnListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelProdnListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProduction")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateProdnDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ProductionConsumeRawView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionProductionConsumeRaws");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtProdConRDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpProdConRDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelProdConRDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewProdConRDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProdConRList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateProdConRListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ProductionConsumeRawListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionProductionConsumeRawsLis");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtProdConRListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpProdConRListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelProdConRListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProductionConsumeRaw")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateProdConRDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ProductionPlanView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionProductionPlan");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtPPlanDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpPPlanDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPPlanDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewPPlanDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePPlanList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePPlanListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ProductionPlanListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionProductionPlanList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtPPlanListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpPPlanListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPPlanListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProductionPlan")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePPlanDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ProductionStockView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionProductionStock");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtProdnStockDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpProdnStockDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelProdnStockDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::PayslipView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionPayslip");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtPspDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpPspDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPspDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::PurveyorView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionPurveyors");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtPurDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpPurDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelPurDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateOrderRaw")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateOrdRDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::RelationView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionRelation");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtRelDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpRelDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRelDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::RelationType>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionRelationType");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtRelTypeDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpRelTypeDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRelTypeDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateRelation")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRelDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}
template<>
void DataForm::QtConnect<BusinessLayer::ReceiptProductView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionReceiptProducts");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtRcpPDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpRcpPDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRcpPDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewRcpPDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateRcpPList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRcpPListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ReceiptProductListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionReceiptProductsList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtRcpPListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpRcpPListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRcpPListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateReceiptProduct")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRcpPDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::StockTransferView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionStockTransfers");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtStockTrDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpStockTrDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelStockTrDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewStockTrDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateStockTrList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateStockTrListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::StockTransferListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionStockTransfersList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtStockTrListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpStockTrListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelStockTrListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateStockTransfer")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateStockTrDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::RefundView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionRefund");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtRfdDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpRfdDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRfdDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::Role>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionRoles");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtRoleDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpRoleDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRoleDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateUser")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateUserDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateClient")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateCltDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateEmployee")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateEmpDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateAccess")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateAcsDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ReturnView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionReturns");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtRtrnDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpRtrnDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRtrnDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewRtrnDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateRtrnList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRtrnListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ReturnListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionReturnList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtRtrnListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpRtrnListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRtrnListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateReturn")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRtrnDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::SalaryView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionSalary");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtSlrDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpSlrDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelSlrDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePayslip")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePspDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateTimesheet")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateTmsDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::SalaryType>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionSalaryType");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtSlrTypeDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpSlrTypeDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelSlrTypeDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSalary")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateSlrDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::Status>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionStatus");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtStsDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpStsDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelStsDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}	
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateConsumeProduct")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateConPDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateConsumeRaw")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateConRDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateInventorization")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateInvDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateOrder")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateOrdDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateOrderRaw")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateOrdRDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePayment")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePmtDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProduction")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePPlanDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProductionConsumeRaw")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateConRDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateReceiptProduct")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRcpPDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateStockTransfer")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateStockTrDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateReturn")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRtrnDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSpoilage")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateSplDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateStock")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateStockDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateStatusRule")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateStsRuleDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateTransport")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateTrsDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWithdrawal")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWdwDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWriteOff")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWOffDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWriteOffR")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWOffRDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateConPList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateConPListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateConRList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateConRListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateInvList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateInvListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateOrdList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateOrdListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateOrdRList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateOrdRListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePrdnList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateProdnListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateProdConRList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateProdConRListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePPlanList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePPlanListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateRcpPList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRcpPListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateStockTrList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateStockTrListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateRtrnList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRtrnListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSpecList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateSpecListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSplList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateSplListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateTrsList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateTrsListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWOffList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWOffListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWOffRList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWOffRListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSubaccount")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateAccDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::StatusRuleView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionStatusRule");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtStsRuleDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpStsRuleDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelStsRuleDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::SpecificationView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionSpecifications");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtSpecDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpSpecDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelSpecDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewSpecDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSpecList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateSpecListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::SpecificationListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionSpecificationList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtSpecListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpSpecListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelSpecListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSpecification")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateSpecDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::SpoilageView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionSpoilage");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtSplDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpSplDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelSplDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewSplDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSplList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePPlanListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::SpoilageListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionSpoilageList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtSplListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpSplListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelSplListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSpoilage")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePPlanDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::StockView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionStock");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtStockDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpStockDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelStockDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}	
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::SubaccountView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionSubaccounts");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtSAccDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpSAccDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelSAccDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}	
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateCompanyAccount")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateCARDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateEntry")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateEtrDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWithdrawal")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWdwDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePayment")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePmtDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::TimesheetView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionTimesheet");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtTmsDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpTmsDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelTmsDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::TransportView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionTransports");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtTrsDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpTrsDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelTrsDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewTrsDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateTrsList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateTrsListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::TransportListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionTransportsList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtTrsListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpTrsListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelTrsListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateTransport")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateTrsDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::UserView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionAllUsers");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtUserDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpUserDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelUserDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateBalance")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateBlcDlg*)parentDialog), SLOT(SetID(int, QString)));
	}	
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePhoto")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePhtDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreatePayment")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreatePmtDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateRefund")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRfdDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateRelation")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateRelDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateSalary")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateSlrDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWithdrawal")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWdwDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::WarehouseView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionWarehouse");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtWrhDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpWrhDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelWrhDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::WarehouseType>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionWarehouseType");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtWrhTpDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpWrhTpDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelWrhTpDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::WarehouseEmployeeRelationView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionWarehouseEmployee");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtWERDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpWERDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelWERDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::WithdrawalView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionWithdrawal");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtWdwDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpWdwDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelWdwDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewWdwDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::WriteOffView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionWriteOffs");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtWOffDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpWOffDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelWOffDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewWOffDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWOffList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWOffListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::WriteOffListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionWriteOffList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtWOffListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpWOffListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelWOffListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWriteOff")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWOffDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::WriteOffRawView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionWriteOffRaws");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtWOffRDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpWOffRDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelWOffRDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	connect(viewBtn, &QPushButton::released, this, &DataForm::ViewWOffRDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWOffRList")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWOffRListDlg*)parentDialog), SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::WriteOffRawListView>()
{
	BusinessLayer::Access access;
	std::string crud = access.GetCRUDAccess(&dataFormBL->GetOrmasDal(), loggedUser, "actionWriteOffRawsList");
	std::size_t pos = crud.find("C");
	if (pos != std::string::npos)
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::CrtWOffRListDlg);
	}
	else
	{
		connect(createBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("U");
	if (pos != std::string::npos)
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::UdpWOffRListDlg);
	}
	else
	{
		connect(editBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	pos = crud.find("D");
	if (pos != std::string::npos)
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::DelWOffRListDlg);
	}
	else
	{
		connect(deleteBtn, &QPushButton::released, this, &DataForm::AcsDenied);
	}
	viewBtn->setVisible(false);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (parentDialog != nullptr && parentDialog->objectName() == "CreateWriteOffR")
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), ((CreateWOffRDlg*)parentDialog), SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
}



void DataForm::keyPressEvent(QKeyEvent *event) {
	if (QApplication::keyboardModifiers() & Qt::ControlModifier) 
	{
		int key = event->key();
		if (key == Qt::Key::Key_F) 
		{ 
			//event is Ctrl+F, search
			SearchInTableDlg *searchDlg = new SearchInTableDlg(this);
			searchDlg->setAttribute(Qt::WA_DeleteOnClose);
			searchDlg->setWindowTitle(tr("Search in table"));
			QMdiSubWindow *invWindow = new QMdiSubWindow;
			invWindow->setWidget(searchDlg);
			invWindow->setAttribute(Qt::WA_DeleteOnClose);
			((MainForm*)parentForm)->mdiArea->addSubWindow(invWindow);
			searchDlg->show();
		}
	}
}