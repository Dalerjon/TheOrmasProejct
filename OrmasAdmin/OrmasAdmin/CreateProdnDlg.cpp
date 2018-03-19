#include "stdafx.h"
#include <QMessageBox>
#include "CreateProdnDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"


CreateProdnDlg::CreateProdnDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	dialogBL->StartTransaction(errorMessage);
	QDate currentDate = QDate::currentDate();
	int day = currentDate.day();
	int month = currentDate.month();
	int year = currentDate.year();
	std::string nextDay;
	nextDay = std::to_string(year);
	nextDay += ".";
	nextDay += std::to_string(month);
	nextDay += ".";
	nextDay += std::to_string(day+1);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateProdnDlg::EditProduction);
	}
	else
	{
		production->SetID(dialogBL->GenerateID());
		prdDateEdit->setDate(QDate::currentDate());
		expiryDateEdit->setDate(QDate::fromString(nextDay.c_str(), "yyyy.MM.dd"));
		sesStartTimeEdit->setTime(QTime::fromString("00:01","hh:mm"));
		sesEndTimeEdit->setTime(QTime::fromString("23:59", "hh:mm"));
		QObject::connect(okBtn, &QPushButton::released, this, &CreateProdnDlg::CreateProduction);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateProdnDlg::Close);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateProdnDlg::OpenProdnListDlg);
	QObject::connect(this, SIGNAL(CloseCreatedForms()), ((MainForm*)parent->parentWidget()), SLOT(CloseChildsByName()));
}

CreateProdnDlg::~CreateProdnDlg()
{
	dialogBL->CancelTransaction(errorMessage);
	emit CloseCreatedForms();
}


void CreateProdnDlg::SetProductionParams(QString pProductionDate, QString pExpiryDate, QString pSessionStart, QString pSessionEnd, int id)
{
	production->SetProductionDate(pProductionDate.toUtf8().constData());
	production->SetExpiryDate(pExpiryDate.toUtf8().constData());
	production->SetSessionStart(pSessionStart.toUtf8().constData());
	production->SetSessionEnd(pSessionEnd.toUtf8().constData());
	production->SetID(id);
}

void CreateProdnDlg::FillEditElements(QString pProductionDate, QString pExpiryDate, QString pSessionStart, QString pSessionEnd)
{
	prdDateEdit->setDate(QDate::fromString(pProductionDate, "yyyy.MM.dd"));
	expiryDateEdit->setDate(QDate::fromString(pExpiryDate, "yyyy.MM.dd"));
	std::string temp1 = pSessionStart.toStdString();
	std::string temp2 = pSessionEnd.toStdString();
	sesStartTimeEdit->setTime(QTime::fromString(pSessionStart, "hh:mm:ss"));
	sesEndTimeEdit->setTime(QTime::fromString(pSessionEnd, "hh:mm:ss"));
}


bool CreateProdnDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetProductionParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 4)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 4)).toString().toUtf8().constData());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateProdnDlg::CreateProduction()
{
	errorMessage.clear();
	if (!(prdDateEdit->text().isEmpty() || expiryDateEdit->text().isEmpty() || sesStartTimeEdit->text().isEmpty() ||
		sesEndTimeEdit->text().isEmpty()))
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetProductionParams(prdDateEdit->text(), expiryDateEdit->text(), sesStartTimeEdit->text(), sesEndTimeEdit->text(), production->GetID());
		
		if (dialogBL->CreateProduction(production, errorMessage))
		{
			QList<QStandardItem*> UserItem;
			UserItem << new QStandardItem(QString::number(production->GetID()))
				<< new QStandardItem(production->GetProductionDate().c_str())
				<< new QStandardItem(production->GetExpiryDate().c_str())
				<< new QStandardItem(production->GetSessionStart().c_str())
				<< new QStandardItem(production->GetSessionEnd().c_str());
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(UserItem);
			
			dialogBL->CommitTransaction(errorMessage);
			this->close();
		}
		else
		{
			dialogBL->CancelTransaction(errorMessage);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));

			errorMessage.clear();
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please recheck all fields, all of them must be filled!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateProdnDlg::EditProduction()
{
	errorMessage.clear();
	if (!(prdDateEdit->text().isEmpty() || expiryDateEdit->text().isEmpty() || sesStartTimeEdit->text().isEmpty() ||
		sesEndTimeEdit->text().isEmpty()))
	{
		if (prdDateEdit->text() != production->GetProductionDate().c_str() ||
			expiryDateEdit->text() != production->GetExpiryDate().c_str() ||
			sesStartTimeEdit->text() != production->GetSessionStart().c_str() ||
			sesEndTimeEdit->text() != production->GetSessionEnd().c_str())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetProductionParams(prdDateEdit->text(), expiryDateEdit->text(), sesStartTimeEdit->text(), sesEndTimeEdit->text(), production->GetID());
			if (dialogBL->UpdateProduction(production, errorMessage))
			{
				//updating production data
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(production->GetProductionDate().c_str());
				itemModel->item(mIndex.row(), 2)->setText(production->GetExpiryDate().c_str());
				itemModel->item(mIndex.row(), 3)->setText(production->GetSessionStart().c_str());
				itemModel->item(mIndex.row(), 4)->setText(production->GetSessionEnd().c_str());
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
			QString(tr("Please recheck all fields, all of them must be filled!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateProdnDlg::Close()
{
	dialogBL->CancelTransaction(errorMessage);
	this->close();
}

void CreateProdnDlg::OpenProdnListDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Add product"));
	dForm->hide();
	dForm->productionID = production->GetID();
	BusinessLayer::ProductionList pList;
	pList.SetProductionID(production->GetID());
	std::string filter = pList.GenerateFilter(dialogBL->GetOrmasDal());
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::ProductionListView>(errorMessage, filter);
	if (errorMessage.empty())
	{
		dForm->createProdnDlg = this;
		dForm->setObjectName("productionListForm");
		dForm->QtConnect<BusinessLayer::ProductionListView>();
		QMdiSubWindow *productionListWindow = new QMdiSubWindow;
		productionListWindow->setWidget(dForm);
		productionListWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(productionListWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All products are shown");
		mainForm->statusBar()->showMessage(message);
	}
	else
	{
		delete dForm;
		QString message = tr("End with error!");
		mainForm->statusBar()->showMessage(message);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr(errorMessage.c_str())),
			QString(tr("Ok")));
		errorMessage = "";
	}

}

