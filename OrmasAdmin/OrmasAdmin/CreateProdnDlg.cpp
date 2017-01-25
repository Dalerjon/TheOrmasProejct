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
	production->SetID(dialogBL->GenerateID());
	dialogBL = ormasBL;
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateProdnDlg::EditProduction);
	}
	else
	{
		prdDateEdit->setDate(QDate::currentDate());
		sesStartTimeEdit->setTime(QTime::currentTime());
		expiryDateEdit->setDate(QDate::currentDate());
		sesEndTimeEdit->setTime(QTime::currentTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateProdnDlg::CreateProduction);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateProdnDlg::Close);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateProdnDlg::OpenAddProdDlg);
}

void CreateProdnDlg::SetProductionParams(QString pProductionDate, QString pExpiryDate, QString pSessionStart, QString pSessionEnd)
{
	production->SetProductionDate(pProductionDate.toUtf8().constData());
	production->SetExpiryDate(pExpiryDate.toUtf8().constData());
	production->SetSessionStart(pSessionStart.toUtf8().constData());
	production->SetSessionEnd(pSessionEnd.toUtf8().constData());
}

void CreateProdnDlg::FillEditElements(QString pProductionDate, QString pExpiryDate, QString pSessionStart, QString pSessionEnd)
{
	prdDateEdit->setDate(QDate::fromString(pProductionDate,"dd.MM.yyyy"));
	expiryDateEdit->setDate(QDate::fromString(pExpiryDate, "dd.MM.yyyy"));
	sesStartTimeEdit->setTime(QTime::fromString(pSessionStart, "H:mm"));
	sesEndTimeEdit->setTime(QTime::fromString(pSessionEnd, "H:mm"));
}


bool CreateProdnDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetProductionParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 4)).toString().toUtf8().constData());
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
		SetProductionParams(prdDateEdit->text(), expiryDateEdit->text(), sesStartTimeEdit->text(), sesEndTimeEdit->text());
		dialogBL->StartTransaction(errorMessage);
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
			this->close();
			dialogBL->CommitTransaction(errorMessage);
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
			SetProductionParams(prdDateEdit->text(), expiryDateEdit->text(), sesStartTimeEdit->text(), sesEndTimeEdit->text());
			dialogBL->StartTransaction(errorMessage);
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
				this->close();
				dialogBL->CommitTransaction(errorMessage);
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
	this->close();
}

void CreateProdnDlg::OpenAddProdDlg()
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
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::ProductListView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createProdnDlg = this;
		dForm->setObjectName("addProdForm");
		dForm->QtConnect<BusinessLayer::ProductListView>();
		QMdiSubWindow *returnWindow = new QMdiSubWindow;
		returnWindow->setWidget(dForm);
		returnWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(returnWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All products are shown");
		mainForm->statusBar()->showMessage(message);
		dForm->productionID = production->GetID();
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

