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
	header << tr("ID") << tr("Code") << tr("Short name") << tr("Name");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Measure>()
{
	QStringList header;
	header << tr("ID") << tr("Name") << tr("Short name");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::OrderView>()
{
	QStringList header;
	header << tr("ID") << tr("Order date") << tr("Client name") << tr("Client phone") << tr("Client address")
		<< tr("Firm") << tr("Worker name") << tr("Worker phone") << tr("Worker ID") << tr("User ID");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Product>()
{
	QStringList header;
	header << tr("ID") << tr("Company ID") << tr("Name") << tr("Volume") << tr("Measure ID")
		<< tr("Price") << tr("Product type ID") << tr("Produce date") << tr("End date");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::ProductList>()
{
	QStringList header;
	header << tr("ID") << tr("Order ID") << tr("Return ID") << tr("Product ID") << tr("Count");
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
	header << tr("ID") << tr("Order date") << tr("Client name") << tr("Client phone") << tr("Client address")
		<< tr("Firm") << tr("Worker name") << tr("Worker phone") << tr("Worker ID") << tr("User ID");
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
QStringList DataForm::GetTableHeader<BusinessLayer::User>()
{
	QStringList header;
	header << tr("ID") << tr("Name") << tr("Phone") << tr("Address") << tr("Firm")
		<< tr("Firm number") << tr("Role ID") << tr("Location ID") << tr("Password") << tr("Avtivated");
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
		<< new QStandardItem(data.GetShortName().c_str()) << new QStandardItem(data.GetName().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Measure>(BusinessLayer::Measure& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetShortName().c_str());
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::OrderView>(BusinessLayer::OrderView& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetClientName().c_str()) << new QStandardItem(data.GetClientPhone().c_str())
		<< new QStandardItem(data.GetClientAddress().c_str()) << new QStandardItem(data.GetFirm().c_str())
		<< new QStandardItem(data.GetWorkerName().c_str()) << new QStandardItem(data.GetWorkerPhone().c_str())
		<< new QStandardItem(QString::number(data.GetWorkerID())) << new QStandardItem(QString::number(data.GetUserID()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Product>(BusinessLayer::Product& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(QString::number(data.GetCompanyID()))
		<< new QStandardItem(data.GetName().c_str()) << new QStandardItem(QString(QString::number(data.GetVolume())))
		<< new QStandardItem(QString::number(data.GetMeasureID())) << new QStandardItem(QString(QString::number(data.GetPrice())))
		<< new QStandardItem(QString::number(data.GetProductTypeID())) << new QStandardItem(QString::number(data.GetShelfLife()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductList>(BusinessLayer::ProductList& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(QString::number(data.GetOrderID()))
		<< new QStandardItem(QString::number(data.GetReturnID())) << new QStandardItem(QString::number(data.GetProductID()))
		<< new QStandardItem(QString::number(data.GetCount()));
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
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetDate().c_str())
		<< new QStandardItem(data.GetClientName().c_str()) << new QStandardItem(data.GetClientPhone().c_str())
		<< new QStandardItem(data.GetClientAddress().c_str()) << new QStandardItem(data.GetFirm().c_str())
		<< new QStandardItem(data.GetWorkerName().c_str()) << new QStandardItem(data.GetWorkerPhone().c_str())
		<< new QStandardItem(QString::number(data.GetWorkerID())) << new QStandardItem(QString::number(data.GetUserID())); 
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
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::User>(BusinessLayer::User& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString::number(data.GetID())) << new QStandardItem(data.GetName().c_str())
		<< new QStandardItem(data.GetPhone().c_str()) << new QStandardItem(data.GetAddress().c_str())
		<< new QStandardItem(data.GetFirm().c_str()) << new QStandardItem(data.GetFirmNumber().c_str())
		<< new QStandardItem(QString::number(data.GetRoleID())) << new QStandardItem(QString::number(data.GetLocationID()))
		<< new QStandardItem(data.GetPassword().c_str());
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
}

template<>
void DataForm::QtConnect<BusinessLayer::Currency>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtCurrencyDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpCurrencyDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCurrencyDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}

template<>
void DataForm::QtConnect<BusinessLayer::Measure>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtMeasureDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpMeasureDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelMeasureDlg);
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
}

template<>
void DataForm::QtConnect<BusinessLayer::Location>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtLocationDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpLocationDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelLocationDlg);
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
}

template<>
void DataForm::QtConnect<BusinessLayer::Status>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtStatusDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpStatusDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelStatusDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
	connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(ChangeBtnState()));
}