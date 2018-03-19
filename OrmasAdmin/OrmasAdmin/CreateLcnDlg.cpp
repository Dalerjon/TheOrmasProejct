#include "stdafx.h"
#include <QMessageBox>
#include "CreateLcnDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateLcnDlg::CreateLcnDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	countryNameEdit->setMaxLength(30);
	countryCodeEdit->setMaxLength(4);
	regionNameEdit->setMaxLength(30);
	cityNameEdit->setMaxLength(30);
	dialogBL = ormasBL;
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateLcnDlg::EditLocation);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateLcnDlg::CreateLocation);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateLcnDlg::Close);
}

void CreateLcnDlg::SetLocationParams(QString lCountryName, QString lCountryCode, QString lRegionName, QString lCityName, int id)
{
	location->SetCountryName(lCountryName.toUtf8().constData());
	location->SetCountryCode(lCountryCode.toUtf8().constData());
	location->SetRegionName(lRegionName.toUtf8().constData());
	location->SetCityName(lCityName.toUtf8().constData());
	location->SetID(id);
}

void CreateLcnDlg::FillEditElements(QString lCountryName, QString lCountryCode, QString lRegionName, QString lCityName)
{
	countryNameEdit->setText(lCountryName);
	countryCodeEdit->setText(lCountryCode);
	regionNameEdit->setText(lRegionName);
	cityNameEdit->setText(lCityName);
}

bool CreateLcnDlg::FillDlgElements(QTableView* rTable)
{
	QModelIndex mIndex = rTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetLocationParams(rTable->model()->data(rTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			rTable->model()->data(rTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			rTable->model()->data(rTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData(),
			rTable->model()->data(rTable->model()->index(mIndex.row(), 4)).toString().toUtf8().constData(),
			rTable->model()->data(rTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(rTable->model()->data(rTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			rTable->model()->data(rTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			rTable->model()->data(rTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData(),
			rTable->model()->data(rTable->model()->index(mIndex.row(), 4)).toString().toUtf8().constData());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateLcnDlg::CreateLocation()
{
	errorMessage.clear();
	if (!(countryNameEdit->text().isEmpty() || countryCodeEdit->text().isEmpty() || regionNameEdit->text().isEmpty()
		|| cityNameEdit->text().isEmpty()))
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetLocationParams(countryNameEdit->text(), countryCodeEdit->text(), regionNameEdit->text(), cityNameEdit->text());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateLocation(location, errorMessage))
		{
			QList<QStandardItem*> LocationItem;
			LocationItem << new QStandardItem(QString::number(location->GetID())) << new QStandardItem(location->GetCountryName().c_str())
				<< new QStandardItem(location->GetCountryCode().c_str()) << new QStandardItem(location->GetRegionName().c_str())
				<< new QStandardItem(location->GetCityName().c_str());
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(LocationItem);
			
			dialogBL->CommitTransaction(errorMessage);
			this->close();
		}
		else
		{
			dialogBL->CancelTransaction(errorMessage);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please fill counrty, region and city names! Also fill country code!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateLcnDlg::EditLocation()
{
	errorMessage.clear();
	if (!(countryNameEdit->text().isEmpty() || countryCodeEdit->text().isEmpty() || regionNameEdit->text().isEmpty()
		|| cityNameEdit->text().isEmpty()))
	{
		if (QString(location->GetCountryName().c_str()) != countryNameEdit->text()
			|| QString(location->GetCountryCode().c_str()) != countryCodeEdit->text()
			|| QString(location->GetRegionName().c_str()) != regionNameEdit->text()
			|| QString(location->GetCityName().c_str()) != cityNameEdit->text())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetLocationParams(countryNameEdit->text(), countryCodeEdit->text(), regionNameEdit->text(), cityNameEdit->text(),
				location->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateLocation(location, errorMessage))
			{
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(location->GetCountryName().c_str());
				itemModel->item(mIndex.row(), 2)->setText(location->GetCountryCode().c_str());
				itemModel->item(mIndex.row(), 3)->setText(location->GetRegionName().c_str());
				itemModel->item(mIndex.row(), 4)->setText(location->GetCityName().c_str());
				emit itemModel->dataChanged(mIndex, mIndex);
				
				dialogBL->CommitTransaction(errorMessage);
				this->close();
			}
			else
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
			}
		}
		else
		{
			this->close();
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please fill counrty, region and city names! Also fill country code!")),
			QString(tr("Ok")));
	}
}

void CreateLcnDlg::Close()
{
	this->close();
}
