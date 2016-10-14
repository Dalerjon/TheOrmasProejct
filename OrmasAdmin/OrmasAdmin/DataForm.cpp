#include "stdafx.h"
#include "DataForm.h"
#include "MainForm.h"
#include <QStandardItemModel>

DataForm::DataForm(QWidget *parent):QWidget(parent)
{
	setupUi(this);
}

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
	header << tr("ID") << tr("Name") << tr("Phone") << tr("Addres") << tr("Firm")
		<< tr("Firm number") << tr("Role ID") << tr("Region ID") << tr("Password");
	return header;
}

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
		<< new QStandardItem(QString(data.GetReturnDate().c_str())) << new QStandardItem(QString(data.GetWorkerID()))
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