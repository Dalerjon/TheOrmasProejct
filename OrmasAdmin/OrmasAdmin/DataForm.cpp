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
	if (objectName() == "orderForm" || objectName() == "returnForm" || objectName() == "productionForm")
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
	/*if (createUserDlg != nullptr)
		createUserDlg = nullptr;
	if (createProdDlg != nullptr)
		createProdDlg = nullptr;*/
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
		else if (objectName() == "productionForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				productionID = id;
			BusinessLayer::ProductionList *productionList = new BusinessLayer::ProductionList();
			productionList->SetProductionID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::ProductionList>(productionList);
			delete productionList;
			checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("ProductionListForm"));
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
						QMdiSubWindow *prodListWindow = new QMdiSubWindow;
						prodListWindow->setWidget(dForm);
						prodListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(prodListWindow);
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
						QMdiSubWindow *prodListWindow = new QMdiSubWindow;
						prodListWindow->setWidget(dForm);
						prodListWindow->setAttribute(Qt::WA_DeleteOnClose);
						((MainForm*)parentWidget())->mdiArea->addSubWindow(prodListWindow);
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
		if (createOrdDlg != nullptr)
		{
			createOrdDlg->prodCountEdit->setText(QString::number(count));
			createOrdDlg->sumEdit->setText(QString::number(sum));
			createOrdDlg->currencyEdit->setText(QString::number(currencyID));
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

// Template specializations for generating headers of table ------------------------------
template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Access>()
{
	QStringList header;
	header << tr("ID") << tr("Role ID") << tr("Access item ID");
	return header;
}
template<>
QStringList DataForm::GetTableHeader<BusinessLayer::AccessItem>()
{
	QStringList header;
	header << tr("ID") << tr("Item english name") << tr("Item russian name") << tr("Division");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::BalanceView>()
{
	QStringList header;
	header << tr("ID") << tr("User name") << tr("User surname") << tr("Value") << tr("Currency name") << tr("User ID") << 
		 tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ClientView>()
{
	QStringList header;
	header << tr("ID") << tr("Name") << tr("Surname") << tr("Phone") << tr("Country name") << tr("Region name")
		<< tr("City name") << tr("Address") << tr("Firm") << tr("Firm number") << tr("Role name") << tr("Password") << tr("Email")
		<< tr("Avtivated") << tr("Role ID") << tr("Location ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Company>()
{
	QStringList header;
	header << tr("ID") << tr("Name") << tr("Address") << tr("Phone") << tr("Comment");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Currency>()
{
	QStringList header;
	header << tr("ID") << tr("Code") << tr("Short name") << tr("Name") << tr("Change unit") << tr("Main trade currency");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::EmployeeView>()
{
	QStringList header;
	header << tr("ID") << tr("Name") << tr("Surname") << tr("Position name") << tr("Phone") << tr("Address") 
		<< tr("Birth date") << tr("Role name") << tr("Hire date") << tr("Password") << tr("Email")
		<< tr("Avtivated") << tr("Role ID") << tr("Position ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Location>()
{
	QStringList header;
	header << tr("ID") << tr("Country name") << tr("Country code") << tr("Region name") << tr("City name");
	return header;
}


template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Measure>()
{
	QStringList header;
	header << tr("ID") << tr("Name") << tr("Short name") << tr("Change unit");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::OrderView>()
{
	QStringList header;
	header << tr("ID") << tr("Order date") << tr("Execution date") << tr("Status code") << tr("Status name") << tr("Client name") << tr("Client surname")
		<< tr("Client phone") << tr("Client address") << tr("Client firm") << tr("Employee name") << tr("Employee surname") 
		<< tr("Employee phone") << tr("Product count") << tr("Sum")	<< tr("Currency name") << tr("Employee ID") << tr("Client ID") 
		<< tr("Status ID") << tr("Currency ID") << tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::OrderListView>()
{
	QStringList header;
	header << tr("ID") << tr("Order ID") << tr("Product name") << tr("Price")
		<< tr("Currency name") << tr("Volume") << tr("Measure name") << tr("Count") << tr("Sum") << tr("Sum currency name") << tr("Status name")
		<< tr("Product ID") << tr("Status ID") << tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Photo>()
{
	QStringList header;
	header << tr("ID") << tr("User ID") << tr("Product ID") << tr("Source");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::PaymentView>()
{
	QStringList header;
	header << tr("ID") << tr("Date") << tr("Value") << tr("Currency name") << tr("User ID") << tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Position>()
{
	QStringList header;
	header << tr("ID") << tr("Name");
	return header;
}


template<>
QStringList DataForm::GetTableHeader<BusinessLayer::PriceView>()
{
	QStringList header;
	header << tr("ID") << tr("Date") << tr("Product name") << tr("Volume") << tr("Measure name") << tr("Value") 
		<< tr("Currency name") << tr("Currency ID") << tr("Product ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ProductType>()
{
	QStringList header;
	header << tr("ID") << tr("Name") << tr("Short name");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ProductView>()
{
	QStringList header;
	header << tr("ID") << tr("Name") << tr("Price") << tr("Currency name") << tr("Volume") << tr("Measure name") << tr("Product type name")
		<< tr("Shelf life") << tr("Company name") << tr("Company ID") << tr("Measure ID") << tr("Product type ID") << tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Production>()
{
	QStringList header;
	header << tr("ID") << tr("Production Date") << tr("Expiry Date") << tr("Session start") << tr("Session end") 
		<< tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ProductionListView>()
{
	QStringList header;
	header << tr("ID") << tr("Production ID") << tr("Product name") << tr("Price")
		<< tr("Currency name") << tr("Volume") << tr("Measure name") << tr("Count") << tr("Sum") << tr("Sum currency name") << tr("Status name")
		<< tr("Product ID") << tr("Status ID") << tr("Currency ID");
	return header;
}


template<>
QStringList DataForm::GetTableHeader<BusinessLayer::PayslipView>()
{
	QStringList header;
	header << tr("ID") << tr("Date") << tr("Value") << tr("Currency name") << tr("Salary ID") << tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Relation>()
{
	QStringList header;
	header << tr("ID") << tr("User 1") << tr("User 2") << tr("Relation type");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::RelationType>()
{
	QStringList header;
	header << tr("ID") << tr("Name") << tr("Comment");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ReturnView>()
{
	QStringList header;
	header << tr("ID") << tr("Return date") << tr("Execution date") << tr("Status code") << tr("Status name") << tr("Client name") << tr("Client surname")
		<< tr("Client phone") << tr("Client address") << tr("Client firm") << tr("Employee name") << tr("Employee surname")
		<< tr("Employee phone") << tr("Product count") << tr("Sum") << tr("Currency name") << tr("Employee ID") << tr("Client ID")
		<< tr("Status ID") << tr("Currency ID") << tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ReturnListView>()
{
	QStringList header;
	header << tr("ID") << tr("Return ID") << tr("Product name") << tr("Price")
		<< tr("Currency name") << tr("Volume") << tr("Measure name") << tr("Count") << tr("Sum") << tr("Sum currency name") << tr("Status name")
		<< tr("Product ID") << tr("Status ID") << tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::RefundView>()
{
	QStringList header;
	header << tr("ID") << tr("Date") << tr("Value") << tr("Currency name") << tr("User ID") << tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Role>()
{
	QStringList header;
	header << tr("ID") << tr("Code") << tr("Name") << tr("Comment");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::SalaryType>()
{
	QStringList header;
	header << tr("ID") << tr("Code") << tr("Name");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::SalaryView>()
{
	QStringList header;
	header << tr("ID") << tr("User ID") << tr("Employee name") << tr("Employee surname") << tr("Employee phone") 
		<< tr("Date") << tr("Value") << tr("Currency name") << tr("Salary type name") << tr("Currency ID")
		<< tr("Salary type ID") << tr("Is bonus?");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Status>()
{
	QStringList header;
	header << tr("ID") << tr("Code") << tr("Name") << tr("Comment");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::UserView>()
{
	QStringList header;
	header << tr("ID") << tr("Email") << tr("Name") << tr("Surname") << tr("Phone") << tr("Address") 
		<< tr("Role name") << tr("Password") << tr("Avtivated") << tr("Role ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::WithdrawalView>()
{
	QStringList header;
	header << tr("ID") << tr("Date") << tr("Value") << tr("Currency name") << tr("User ID") << tr("Currency ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::WriteOffView>()
{
	QStringList header;
	header << tr("ID") << tr("Write-off date") << tr("Status code") << tr("Status name") << tr("Client name") << tr("Client surname")
		<< tr("Client phone") << tr("Client address") << tr("Client firm") << tr("Employee name") << tr("Employee surname")
		<< tr("Employee phone") << tr("Product count") << tr("Sum") << tr("Currency name") << tr("Employee ID") << tr("Client ID")
		<< tr("Status ID") << tr("Currency ID") << tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::WriteOffListView>()
{
	QStringList header;
	header << tr("ID") << tr("Write-off ID") << tr("Product name") << tr("Price")
		<< tr("Currency name") << tr("Volume") << tr("Measure name") << tr("Count") << tr("Sum") << tr("Sum currency name") << tr("Status name")
		<< tr("Product ID") << tr("Status ID") << tr("Currency ID");
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
void DataForm::QtConnect<BusinessLayer::Currency>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtCurDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpCurDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCurDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createOrdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdDlg, SLOT(SetID(int, QString)));
	}
	if (createProdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createProdDlg, SLOT(SetID(int, QString)));
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
	if (createBlcDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createBlcDlg, SLOT(SetID(int, QString)));
	}
	if (createOrdListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdListDlg, SLOT(SetID(int, QString)));
	}
	if (createProdnListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createProdnListDlg, SLOT(SetID(int, QString)));
	}
	if (createRtrnListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRtrnListDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffListDlg, SLOT(SetID(int, QString)));
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
	if (createRfdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRfdDlg, SLOT(SetID(int, QString)));
	}
	if (createSlrDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createSlrDlg, SLOT(SetID(int, QString)));
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
	if (clcWagesDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), clcWagesDlg, SLOT(SetID(int, QString)));
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
	if (createOrdListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdListDlg, SLOT(SetID(int, QString)));
	}
	if (createProdnListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createProdnListDlg, SLOT(SetID(int, QString)));
	}
	if (createRtrnListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRtrnListDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffListDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffListDlg, SLOT(SetID(int, QString)));
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
	if (createOrdListDlg != nullptr || createOrdDlg != nullptr || createRtrnDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdListDlg, SLOT(SetID(int, QString)));
	}
	if (createProdnListDlg != nullptr || createOrdDlg != nullptr || createRtrnDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createProdnListDlg, SLOT(SetID(int, QString)));
	}
	if (createRtrnListDlg != nullptr || createOrdDlg != nullptr || createRtrnDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRtrnListDlg, SLOT(SetID(int, QString)));
	}
	if (createWOffListDlg != nullptr || createOrdDlg != nullptr || createRtrnDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createWOffListDlg, SLOT(SetID(int, QString)));
	}
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
void DataForm::QtConnect<BusinessLayer::UserView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtUserDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpUserDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelUserDlg);
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
