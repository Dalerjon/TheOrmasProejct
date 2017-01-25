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
	if (createUserDlg != nullptr)
		createUserDlg = nullptr;
	if (createProdDlg != nullptr)
		createProdDlg = nullptr;
	CloseDataForm();
}

void DataForm::OpenList(int row, int column)
{
	if (column == tableView->model()->columnCount() - 1 && row > 0)
	{
		std::string errorMessage = "";
		std::string filterString = "";
		int id = 0;
		if (objectName() == "orderForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				orderID = id;
			BusinessLayer::ProductList *prodList = new BusinessLayer::ProductList();
			prodList->SetOrderID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::ProductList>(prodList);
			delete prodList;
		}
		else if(objectName() == "returnForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				returnID = id;
			BusinessLayer::ProductList *prodList = new BusinessLayer::ProductList();
			prodList->SetReturnID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::ProductList>(prodList);
			delete prodList;
		}
		else if (objectName() == "productionForm")
		{
			id = GetIDFromTable(tableView, errorMessage);
			if (0 != id)
				productionID = id;
			BusinessLayer::ProductList *prodList = new BusinessLayer::ProductList();
			prodList->SetReturnID(id);
			filterString = dataFormBL->GenerateFilter<BusinessLayer::ProductList>(prodList);
			delete prodList;
		}
		if (errorMessage.empty())
		{

			QString message = tr("Loading...");
			((MainForm*)parentWidget())->statusBar()->showMessage(message);
			QWidget* checkedWidget = IsWindowExist(((MainForm*)parentWidget())->mdiArea->subWindowList(), QString("productListForm"));
			if (checkedWidget == nullptr)
			{
				DataForm *dForm = new DataForm(dataFormBL, this);
				dForm->setWindowTitle(tr("Products lists"));
				dForm->FillTable<BusinessLayer::ProductListView>(errorMessage, filterString);
				if (errorMessage.empty())
				{
					dForm->setObjectName("productListForm");
					QMdiSubWindow *prodListWindow = new QMdiSubWindow;
					prodListWindow->setWidget(dForm);
					prodListWindow->setAttribute(Qt::WA_DeleteOnClose);
					((MainForm*)parentWidget())->mdiArea->addSubWindow(prodListWindow);
					dForm->setWindowModality(Qt::WindowModal);
					dForm->show();
					dForm->topLevelWidget();
					dForm->activateWindow();
					QString message = tr("All product lists are shown");
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
				QString message = tr("All product lists are shown");
				((MainForm*)parentWidget())->statusBar()->showMessage(message);
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
	if (createOrdDlg != nullptr || createRtrnDlg != nullptr)
	{

		double sum = 0;
		int count = 0;
		int currencyID = 0;
		if (tableView->model()->rowCount() > 0)
		{
			for (int i = 0; i < tableView->model()->rowCount(); i++)
			{
				sum = sum + tableView->model()->data(tableView->model()->index(i, 10)).toDouble();
				count = count + tableView->model()->data(tableView->model()->index(i, 9)).toDouble();
			}
			currencyID = tableView->model()->data(tableView->model()->index(0, 15)).toInt();
		}
		if (createOrdDlg != nullptr)
		{
			createOrdDlg->prodCountEdit->setText(QString::number(count));
			createOrdDlg->sumEdit->setText(QString::number(sum));
			createOrdDlg->currencyEdit->setText(QString::number(currencyID));
		}
		else
		{
			createRtrnDlg->prodCountEdit->setText(QString::number(count));
			createRtrnDlg->sumEdit->setText(QString::number(sum));
			createRtrnDlg->currencyEdit->setText(QString::number(currencyID));
		}
	}
	if (createProdnDlg != nullptr)
	{
		int count = 0;
		if (tableView->model()->rowCount() > 0)
		{
			for (int i = 0; i < tableView->model()->rowCount(); i++)
			{
				count = count + tableView->model()->data(tableView->model()->index(i, 9)).toDouble();
			}
		}
		createProdnDlg->prodCountEdit->setText(QString::number(count));
	}
}

void DataForm::CrtCompanyDlg()
{
	CreateCmpDlg *companyDlg = new CreateCmpDlg(dataFormBL,false,this);
	companyDlg->setAttribute(Qt::WA_DeleteOnClose);
	companyDlg->setWindowTitle(tr("Create company"));
	companyDlg->show();
}
void DataForm::UdpCompanyDlg()
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
void DataForm::DelCompanyDlg()
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

void DataForm::CrtCurrencyDlg()
{
	CreateCurDlg *currencyDlg = new CreateCurDlg(dataFormBL, false, this);
	currencyDlg->setAttribute(Qt::WA_DeleteOnClose);
	currencyDlg->setWindowTitle(tr("Create currency"));
	currencyDlg->show();
}
void DataForm::UdpCurrencyDlg()
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
void DataForm::DelCurrencyDlg()
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
void DataForm::CrtMeasureDlg()
{
	CreateMsrDlg *measureDlg = new CreateMsrDlg(dataFormBL, false, this);
	measureDlg->setAttribute(Qt::WA_DeleteOnClose);
	measureDlg->setWindowTitle(tr("Create measure"));
	measureDlg->show();
}
void DataForm::UdpMeasureDlg()
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
void DataForm::DelMeasureDlg()
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

void DataForm::CrtProdListDlg()
{
	AddProdDlg *addProdDlg = new AddProdDlg(dataFormBL, false, this);
	if (0 != orderID)
	{
		addProdDlg->orderID = orderID;
		addProdDlg->returnID = 0;
		addProdDlg->productionID = 0;
	}
	if (0 != returnID)
	{
		addProdDlg->orderID = 0;
		addProdDlg->returnID = returnID;
		addProdDlg->productionID = 0;
	}
	if (0 != productionID)
	{
		addProdDlg->orderID = 0;
		addProdDlg->returnID = 0;
		addProdDlg->productionID = productionID;
	}
	addProdDlg->setAttribute(Qt::WA_DeleteOnClose);
	addProdDlg->setWindowTitle(tr("Add product to list"));
	addProdDlg->show();
}
void DataForm::UdpProdListDlg()
{
	AddProdDlg *addProdDlg = new AddProdDlg(dataFormBL, true, this);
	addProdDlg->setAttribute(Qt::WA_DeleteOnClose);
	addProdDlg->setWindowTitle(tr("Update product in list"));
	if (addProdDlg->FillDlgElements(tableView))
	{
		addProdDlg->show();
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please select one row at first!")),
			QString(tr("Ok")));
	}
}
void DataForm::DelProdListDlg()
{
	std::string errorMessage = "";
	int id = GetIDFromTable(tableView, errorMessage);
	BusinessLayer::ProductList prodList;
	prodList.SetID(id);
	if (0 != id)
	{
		if (dataFormBL->DeleteProductList(&prodList, errorMessage))
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
			QString(tr("Product with this id does not exist in list!")),
			QString(tr("Ok")));
	}
}

void DataForm::CrtLocationDlg()
{
	CreateLcnDlg *locationDlg = new CreateLcnDlg(dataFormBL, false, this);
	locationDlg->setAttribute(Qt::WA_DeleteOnClose);
	locationDlg->setWindowTitle(tr("Create location"));
	locationDlg->show();
}
void DataForm::UdpLocationDlg()
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
void DataForm::DelLocationDlg()
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
void DataForm::CrtStatusDlg()
{
	CreateStsDlg *statusDlg = new CreateStsDlg(dataFormBL, false, this);
	statusDlg->setAttribute(Qt::WA_DeleteOnClose);
	statusDlg->setWindowTitle(tr("Create status"));
	statusDlg->show();
}
void DataForm::UdpStatusDlg()
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
void DataForm::DelStatusDlg()
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

// Template specializations for generating headers of table ------------------------------
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
	header << tr("ID") << tr("Order date") << tr("Status code") << tr("Status name") << tr("Client name") << tr("Client phone") 
		<< tr("Client address") << tr("Firm") << tr("Worker name") << tr("Worker phone") << tr("Product count") << tr("Sum") 
		<< tr("Currency name") << tr("Worker ID") << tr("User ID") << tr("Currency ID") << tr("Product list");
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
QStringList DataForm::GetTableHeader<BusinessLayer::ProductListView>()
{
	QStringList header;
	header << tr("ID") << tr("Order ID") << tr("Return ID") << tr("Production ID") << tr("Product name") << tr("Price") 
		<< tr("Currency name") << tr("Volume") << tr("Measure name") << tr("Count") << tr("Sum") << tr("Sum currency name")  << tr("Status name")
		<< tr("Product ID") << tr("Status ID") << tr("Currency ID");
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
QStringList DataForm::GetTableHeader<BusinessLayer::Production>()
{
	QStringList header;
	header << tr("ID") << tr("Production Date") << tr("Expiry Date") << tr("Session start") << tr("Session end") 
		<< tr("Product list");
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
QStringList DataForm::GetTableHeader<BusinessLayer::ReturnView>()
{
	QStringList header;
	header << tr("ID") << tr("Return date") << tr("Status code") << tr("Status name") << tr("Client name") << tr("Client phone")
		<< tr("Client address") << tr("Firm") << tr("Worker name") << tr("Worker phone") << tr("Product count") << tr("Sum")
		<< tr("Currency name") << tr("Worker ID") << tr("User ID") << tr("Currency ID") << tr("Product list");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Role>()
{
	QStringList header;
	header << tr("ID") << tr("Name") << tr("Comment");
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
	header << tr("ID") << tr("Name") << tr("Phone") << tr("Address") << tr("Country name") << tr("Country code") << tr("Region name") 
		<< tr("City name") << tr("Role name") << tr("Firm")	<< tr("Firm number") << tr("Password") << tr("Avtivated") 
		<< tr("Role ID") << tr("Location ID");
	return header;
}

// Template specializations for generating data ---------------------------------------------------------------------------
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
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetStatusCode().c_str()) << new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetClientName().c_str()) << new QStandardItem(data.GetClientPhone().c_str())
		<< new QStandardItem(data.GetClientAddress().c_str()) << new QStandardItem(data.GetFirm().c_str())
		<< new QStandardItem(data.GetWorkerName().c_str()) << new QStandardItem(data.GetWorkerPhone().c_str())
		<< new QStandardItem(QString::number(data.GetCount())) << new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str()) << new QStandardItem(QString::number(data.GetWorkerID())) 
		<< new QStandardItem(QString::number(data.GetUserID())) << new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon,"Detail");
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
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductListView>(BusinessLayer::ProductListView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) 
		<< new QStandardItem(QString::number(data.GetOrderID()))
		<< new QStandardItem(QString::number(data.GetReturnID())) 
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
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductType>(BusinessLayer::ProductType& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetShortName().c_str());
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
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Location>(BusinessLayer::Location& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetCountryName().c_str())
		<< new QStandardItem(data.GetCountryCode().c_str()) << new QStandardItem(data.GetRegionName().c_str())
		<< new QStandardItem(data.GetCityName().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ReturnView>(BusinessLayer::ReturnView& data)
{
	QList<QStandardItem*> items;
	QIcon icon;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetStatusCode().c_str()) << new QStandardItem(data.GetStatusName().c_str())
		<< new QStandardItem(data.GetClientName().c_str()) << new QStandardItem(data.GetClientPhone().c_str())
		<< new QStandardItem(data.GetClientAddress().c_str()) << new QStandardItem(data.GetFirm().c_str())
		<< new QStandardItem(data.GetWorkerName().c_str()) << new QStandardItem(data.GetWorkerPhone().c_str())
		<< new QStandardItem(QString::number(data.GetCount())) << new QStandardItem(QString::number(data.GetSum()))
		<< new QStandardItem(data.GetCurrencyName().c_str()) << new QStandardItem(QString::number(data.GetWorkerID()))
		<< new QStandardItem(QString::number(data.GetUserID())) << new QStandardItem(QString::number(data.GetCurrencyID()))
		<< new QStandardItem(icon, "Detail");
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Role>(BusinessLayer::Role& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetComment().c_str());
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
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetPhone().c_str()) << new QStandardItem(data.GetAddress().c_str())
		<< new QStandardItem(data.GetCountryName().c_str()) << new QStandardItem(data.GetCountryCode().c_str())
		<< new QStandardItem(data.GetRegionName().c_str()) << new QStandardItem(data.GetCityName().c_str())
		<< new QStandardItem(data.GetRoleName().c_str()) << new QStandardItem(data.GetFirm().c_str())
		<< new QStandardItem(data.GetFirmNumber().c_str()) << new QStandardItem(data.GetPassword().c_str())
		<< new QStandardItem(data.GetActivated()?"Yes":"No") << new QStandardItem(QString::number(data.GetRoleID()))
		<< new QStandardItem(QString::number(data.GetLocationID()));
	return items;
}

// Template specializations for connections ---------------------------------------------------------------------------
template<>
void DataForm::QtConnect<BusinessLayer::Company>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtCompanyDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpCompanyDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCompanyDlg);
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
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtCurrencyDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpCurrencyDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCurrencyDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (addProdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), addProdDlg, SLOT(SetID(int, QString)));
	}
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
}

template<>
void DataForm::QtConnect<BusinessLayer::Measure>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtMeasureDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpMeasureDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelMeasureDlg);
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
	if (addProdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), addProdDlg, SLOT(SetID(int, QString)));
	}
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
void DataForm::QtConnect<BusinessLayer::Production>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtProdnDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpProdnDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelProdnDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (addProdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), addProdDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::ProductListView>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtProdListDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpProdListDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelProdListDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createProdnDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createProdnDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
	if (createOrdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createOrdDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
	}
	if (createRtrnDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createRtrnDlg, SLOT(SetID(int, QString)));
		connect(tableView->model(), SIGNAL(rowsInserted(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
		connect(tableView->model(), SIGNAL(rowsRemoved(QModelIndex, int, int)), this, SLOT(OnRowsNumberChanged()));
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
	if (addProdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), addProdDlg, SLOT(SetID(int, QString)));
	}
}

template<>
void DataForm::QtConnect<BusinessLayer::Location>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtLocationDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpLocationDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelLocationDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (createUserDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), createUserDlg, SLOT(SetID(int, QString)));
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
	if (addProdDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), addProdDlg, SLOT(SetID(int, QString)));
	}
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
}

template<>
void DataForm::QtConnect<BusinessLayer::Status>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtStatusDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpStatusDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelStatusDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
	if (addProdDlg != nullptr || createOrdDlg != nullptr || createRtrnDlg != nullptr)
	{
		connect(tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(GetIDValue(QModelIndex)));
		connect(this, SIGNAL(SendID(int, QString)), addProdDlg, SLOT(SetID(int, QString)));
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
}