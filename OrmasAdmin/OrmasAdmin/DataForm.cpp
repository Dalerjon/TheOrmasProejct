#include "stdafx.h"
#include "DataForm.h"
#include "MainForm.h"
#include <QStandardItemModel>

DataForm::DataForm(QWidget *parent):QWidget(parent)
{
	setupUi(this);
}

// All Slots ----------------------------------------------------------------------------
void DataForm::CloseDataForm()
{
	this->close();
}

void DataForm::CrtCompanyDlg()
{
	CreateCmpDlg *companyDlg = new CreateCmpDlg(this);
	companyDlg->setAttribute(Qt::WA_DeleteOnClose);
	companyDlg->setWindowTitle(tr("Create company"));
	companyDlg->show();
}
void DataForm::UdpCompanyDlg(){};
void DataForm::DelCompanyDlg(){};
void DataForm::CrtCurrencyDlg()
{
	CreateCurDlg *currencyDlg = new CreateCurDlg(this);
	currencyDlg->setAttribute(Qt::WA_DeleteOnClose);
	currencyDlg->setWindowTitle(tr("Create currency"));
	currencyDlg->show();
}
void DataForm::UdpCurrencyDlg(){};
void DataForm::DelCurrencyDlg(){};
void DataForm::CrtMeasureDlg()
{
	CreateMsrDlg *measureDlg = new CreateMsrDlg(this);
	measureDlg->setAttribute(Qt::WA_DeleteOnClose);
	measureDlg->setWindowTitle(tr("Create measure"));
	measureDlg->show();
}
void DataForm::UdpMeasureDlg(){};
void DataForm::DelMeasureDlg(){};
void DataForm::CrtProdTpDlg()
{
	CreatePrdTpDlg *prodTypeDlg = new CreatePrdTpDlg(this);
	prodTypeDlg->setAttribute(Qt::WA_DeleteOnClose);
	prodTypeDlg->setWindowTitle(tr("Create product type"));
	prodTypeDlg->show();
}
void DataForm::UdpProdTpDlg(){};
void DataForm::DelProdTpDlg(){};
void DataForm::CrtRegionDlg()
{
	CreateRgnDlg *regionDlg = new CreateRgnDlg(this);
	regionDlg->setAttribute(Qt::WA_DeleteOnClose);
	regionDlg->setWindowTitle(tr("Create region"));
	regionDlg->show();
}
void DataForm::UdpRegionDlg(){};
void DataForm::DelRegionDlg(){};
void DataForm::CrtRoleDlg()
{
	CreateRoleDlg *roleDlg = new CreateRoleDlg(this);
	roleDlg->setAttribute(Qt::WA_DeleteOnClose);
	roleDlg->setWindowTitle(tr("Create region"));
	roleDlg->show();
}
void DataForm::UdpRoleDlg(){};
void DataForm::DelRoleDlg(){};
void DataForm::CrtStatusDlg()
{
	CreateStsDlg *statusDlg = new CreateStsDlg(this);
	statusDlg->setAttribute(Qt::WA_DeleteOnClose);
	statusDlg->setWindowTitle(tr("Create status"));
	statusDlg->show();
}
void DataForm::UdpStatusDlg(){};
void DataForm::DelStatusDlg(){};

// Template specializations for generating headers of table ------------------------------
template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Company>()
{
	QStringList header;
	header << tr("ID") << tr("Name") << tr("Address") << tr("Phone") << tr("comment");
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
QStringList DataForm::GetTableHeader<BusinessLayer::Order>()
{
	QStringList header;
	header << tr("ID") << tr("User ID") << tr("Return date") << tr("Worker ID") << tr("Firm name");
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
QStringList DataForm::GetTableHeader<BusinessLayer::Region>()
{
	QStringList header;
	header << tr("ID") << tr("Code") << tr("Name");
	return header;
}

template<>
QStringList DataForm::GetTableHeader<BusinessLayer::Return>()
{
	QStringList header;
	header << tr("ID") << tr("User ID") << tr("Return date") << tr("Worker ID") << tr("Firm name");
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
		<< tr("Firm number") << tr("Role ID") << tr("Region ID") << tr("Password");
	return header;
}

// Template specializations for generating data ---------------------------------------------------------------------------
template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Company>(BusinessLayer::Company& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString(data.GetID())) << new QStandardItem(QString(data.GetName().c_str()))
		<< new QStandardItem(QString(data.GetAddress().c_str())) << new QStandardItem(QString(data.GetPhone().c_str()))
		<< new QStandardItem(QString(data.GetComment().c_str()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Currency>(BusinessLayer::Currency& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString(data.GetID())) << new QStandardItem(QString(data.GetCode()))
		<< new QStandardItem(QString(data.GetShortName().c_str())) << new QStandardItem(QString(data.GetName().c_str()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Measure>(BusinessLayer::Measure& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString(data.GetID())) << new QStandardItem(QString(data.GetName().c_str()))
		<< new QStandardItem(QString(data.GetShortName().c_str()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Order>(BusinessLayer::Order& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString(data.GetID())) << new QStandardItem(QString(data.GetUserID()))
		<< new QStandardItem(QString(data.GetDate().c_str())) << new QStandardItem(QString(data.GetWorkerID()))
		<< new QStandardItem(QString(data.GetFirmName().c_str()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Product>(BusinessLayer::Product& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString(data.GetID())) << new QStandardItem(QString(data.GetCompanyID()))
		<< new QStandardItem(QString(data.GetName().c_str())) << new QStandardItem(QString(QString::number(data.GetVolume())))
		<< new QStandardItem(QString(data.GetMeasureID())) << new QStandardItem(QString(QString::number(data.GetPrice())))
		<< new QStandardItem(QString(data.GetProductTypeID())) << new QStandardItem(QString(data.GetProduceDate().c_str()))
		<< new QStandardItem(QString(data.GetEndDate().c_str()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductList>(BusinessLayer::ProductList& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString(data.GetID())) << new QStandardItem(QString(data.GetOrderID()))
		<< new QStandardItem(QString(data.GetReturnID())) << new QStandardItem(QString(data.GetProductID()))
		<< new QStandardItem(QString(data.GetCount()));
	return items;
}
	
template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::ProductType>(BusinessLayer::ProductType& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString(data.GetID())) << new QStandardItem(QString(data.GetName().c_str()))
		<< new QStandardItem(QString(data.GetShortName().c_str()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Region>(BusinessLayer::Region& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString(data.GetID())) << new QStandardItem(QString(data.GetCode().c_str()))
		<< new QStandardItem(QString(data.GetName().c_str()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Return>(BusinessLayer::Return& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString(data.GetID())) << new QStandardItem(QString(data.GetUserID()))
		<< new QStandardItem(QString(data.GetDate().c_str())) << new QStandardItem(QString(data.GetWorkerID()))
		<< new QStandardItem(QString(data.GetFirmName().c_str()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Role>(BusinessLayer::Role& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString(data.GetID())) << new QStandardItem(QString(data.GetName().c_str()))
		<< new QStandardItem(QString(data.GetComment().c_str()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::Status>(BusinessLayer::Status& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString(data.GetID())) << new QStandardItem(QString(data.GetCode().c_str()))
		<< new QStandardItem(QString(data.GetName().c_str())) << new QStandardItem(QString(data.GetComment().c_str()));
	return items;
}

template<>
QList<QStandardItem*> DataForm::GetDataFromClass<BusinessLayer::User>(BusinessLayer::User& data)
{
	QList<QStandardItem*> items;
	items << new QStandardItem(QString(data.GetID())) << new QStandardItem(QString(data.GetName().c_str()))
		<< new QStandardItem(QString(data.GetPhone().c_str())) << new QStandardItem(QString(data.GetAddress().c_str()))
		<< new QStandardItem(QString(data.GetFirm().c_str())) << new QStandardItem(QString(data.GetFirmNumber().c_str()))
		<< new QStandardItem(QString(data.GetRoleID())) << new QStandardItem(QString(data.GetRegionID()))
		<< new QStandardItem(QString(data.GetPassword().c_str()));
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
}

template<>
void DataForm::QtConnect<BusinessLayer::Currency>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtCurrencyDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpCurrencyDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelCurrencyDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
}

template<>
void DataForm::QtConnect<BusinessLayer::Measure>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtMeasureDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpMeasureDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelMeasureDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
}

template<>
void DataForm::QtConnect<BusinessLayer::ProductType>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtProdTpDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpProdTpDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelProdTpDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
}

template<>
void DataForm::QtConnect<BusinessLayer::Region>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtRegionDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpRegionDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRegionDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
}

template<>
void DataForm::QtConnect<BusinessLayer::Role>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtRoleDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpRoleDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelRoleDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
}

template<>
void DataForm::QtConnect<BusinessLayer::Status>()
{
	connect(createBtn, &QPushButton::released, this, &DataForm::CrtStatusDlg);
	connect(editBtn, &QPushButton::released, this, &DataForm::UdpStatusDlg);
	connect(deleteBtn, &QPushButton::released, this, &DataForm::DelStatusDlg);
	connect(closeBtn, &QPushButton::released, this, &DataForm::CloseDataForm);
}