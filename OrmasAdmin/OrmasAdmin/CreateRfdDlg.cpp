#include "stdafx.h"
#include "CreateRfdDlg.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"


CreateRfdDlg::CreateRfdDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	userEdit->setValidator(vInt);
	valueEdit->setValidator(vDouble);
	currencyEdit->setValidator(vInt);
	valueEdit->setMaxLength(17);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateRfdDlg::EditRefund);
	}
	else
	{
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateRfdDlg::CreateRefund);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateRfdDlg::Close);
	QObject::connect(userBtn, &QPushButton::released, this, &CreateRfdDlg::OpenUserDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreateRfdDlg::OpenCurDlg);
}

CreateRfdDlg::~CreateRfdDlg()
{
	delete vInt;
	delete vDouble;
}

void CreateRfdDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("userForm"))
			{
				userEdit->setText(QString::number(ID));
			}
			if (childName == QString("currencyForm"))
			{
				currencyEdit->setText(QString::number(ID));
			}
		}
	}
}

void CreateRfdDlg::SetRefundParams(QString pDate, double pValue, int pUserID, int pCurrencyID, int id)
{
	Refund->SetDate(pDate.toUtf8().constData());
	Refund->SetValue(pValue);
	Refund->SetUserID(pUserID);
	Refund->SetCurrencyID(pCurrencyID);
	Refund->SetID(id);
}

void CreateRfdDlg::FillEditElements(QString pDate, double pValue, int pUserID, int pCurrencyID)
{
	dateEdit->setDateTime(QDateTime::fromString(pDate, "yyyy.MM.dd hh:mm:ss"));
	valueEdit->setText(QString::number(pValue));
	userEdit->setText(QString::number(pUserID));
	currencyEdit->setText(QString::number(pCurrencyID));
}

bool CreateRfdDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetRefundParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 4)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 5)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 4)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 5)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateRfdDlg::CreateRefund()
{
	errorMessage.clear();
	if (0 != userEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && 0 != currencyEdit->text().toInt()
		&& !dateEdit->text().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetRefundParams(dateEdit->text(), valueEdit->text().toDouble(), userEdit->text().toInt(), currencyEdit->text().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateRefund(Refund, errorMessage))
		{
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;
			if (!currency->GetCurrencyByID(dialogBL->GetOrmasDal(), Refund->GetCurrencyID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete currency;
				return;
			}
			QList<QStandardItem*> RefundItem;
			RefundItem << new QStandardItem(QString::number(Refund->GetID()))
				<< new QStandardItem(Refund->GetDate().c_str())
				<< new QStandardItem(QString::number(Refund->GetValue()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(QString::number(Refund->GetUserID()))
				<< new QStandardItem(QString::number(Refund->GetCurrencyID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(RefundItem);
			this->close();
			dialogBL->CommitTransaction(errorMessage);
			delete currency;
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
			QString(tr("Please fill user, value, date and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateRfdDlg::EditRefund()
{
	errorMessage.clear();
	if (0 != userEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && 0 != currencyEdit->text().toInt()
		&& !dateEdit->text().isEmpty())
	{
		if (QString(Refund->GetDate().c_str()) != dateEdit->text() || Refund->GetUserID() != userEdit->text().toInt()
			|| Refund->GetValue() != valueEdit->text().toDouble() || Refund->GetCurrencyID() != currencyEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetRefundParams(dateEdit->text(), valueEdit->text().toDouble(), userEdit->text().toInt(), currencyEdit->text().toInt(), Refund->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateRefund(Refund, errorMessage))
			{
				BusinessLayer::Currency *currency = new BusinessLayer::Currency;
				if (!currency->GetCurrencyByID(dialogBL->GetOrmasDal(), Refund->GetCurrencyID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete currency;
					return;
				}
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(Refund->GetDate().c_str());
				itemModel->item(mIndex.row(), 2)->setText(QString::number(Refund->GetValue()));
				itemModel->item(mIndex.row(), 3)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 4)->setText(QString::number(Refund->GetUserID()));
				itemModel->item(mIndex.row(), 5)->setText(QString::number(Refund->GetCurrencyID()));
				emit itemModel->dataChanged(mIndex, mIndex);
				this->close();
				dialogBL->CommitTransaction(errorMessage);
				delete currency;
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
			QString(tr("Please fill user, value and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateRfdDlg::Close()
{
	this->close();
}

void CreateRfdDlg::OpenUserDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Users"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::UserView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createRfdDlg = this;
		dForm->setObjectName("userForm");
		dForm->QtConnect<BusinessLayer::UserView>();
		QMdiSubWindow *userWindow = new QMdiSubWindow;
		userWindow->setWidget(dForm);
		userWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(userWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All users are shown");
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

void CreateRfdDlg::OpenCurDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Currencies"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::Currency>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createRfdDlg = this;
		dForm->setObjectName("currencyForm");
		dForm->QtConnect<BusinessLayer::Currency>();
		QMdiSubWindow *returnWindow = new QMdiSubWindow;
		returnWindow->setWidget(dForm);
		returnWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(returnWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All currency are shown");
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