#include "stdafx.h"
#include "CreateBlcDlg.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"


CreateBlcDlg::CreateBlcDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	userEdit->setValidator(vInt);
	valueEdit->setValidator(vDouble);
	valueEdit->setMaxLength(17);
	currencyEdit->setValidator(vInt);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateBlcDlg::EditBalance);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateBlcDlg::CreateBalance);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateBlcDlg::Close);
	QObject::connect(userBtn, &QPushButton::released, this, &CreateBlcDlg::OpenUserDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreateBlcDlg::OpenCurDlg);
}

CreateBlcDlg::~CreateBlcDlg()
{
	delete vInt;
	delete vDouble;
}

void CreateBlcDlg::SetID(int ID, QString childName)
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

void CreateBlcDlg::SetBalanceParams(int bUserID, double bValue, int bCurrencyID, int id)
{
	balance->SetUserID(bUserID);
	balance->SetValue(bValue);
	balance->SetCurrencyID(bCurrencyID);
	balance->SetID(id);
}

void CreateBlcDlg::FillEditElements(int bUserID, double bValue, int bCurrencyID)
{
	userEdit->setText(QString::number(bUserID));
	valueEdit->setText(QString::number(bValue));
	currencyEdit->setText(QString::number(bCurrencyID));
}

bool CreateBlcDlg::FillDlgElements(QTableView* bTable)
{
	QModelIndex mIndex = bTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetBalanceParams(bTable->model()->data(bTable->model()->index(mIndex.row(), 5)).toInt(),
			bTable->model()->data(bTable->model()->index(mIndex.row(), 3)).toDouble(),
			bTable->model()->data(bTable->model()->index(mIndex.row(), 6)).toInt(),
			bTable->model()->data(bTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(bTable->model()->data(bTable->model()->index(mIndex.row(), 5)).toInt(),
			bTable->model()->data(bTable->model()->index(mIndex.row(), 3)).toDouble(),
			bTable->model()->data(bTable->model()->index(mIndex.row(), 6)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateBlcDlg::CreateBalance()
{
	errorMessage.clear();
	if (0 != userEdit->text().toInt() && 0 != currencyEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetBalanceParams(userEdit->text().toInt(), valueEdit->text().toDouble(), currencyEdit->text().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateBalance(balance, errorMessage))
		{
			QList<QStandardItem*> balanceItem;
			BusinessLayer::User *user = new BusinessLayer::User();
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;
			if (!user->GetUserByID(dialogBL->GetOrmasDal(), balance->GetUserID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), balance->GetCurrencyID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete user;
				delete currency;
				return;
			}

			balanceItem << new QStandardItem(QString::number(balance->GetID()));

			if (0 != balance->GetUserID())
			{
				balanceItem << new QStandardItem(user->GetName().c_str())
					<< new QStandardItem(user->GetSurname().c_str());
			}
			else
			{
				balanceItem << new QStandardItem("")
					<< new QStandardItem("");
			}

			balanceItem << new QStandardItem(QString::number(balance->GetValue())) << new QStandardItem(currency->GetShortName().c_str()) 
				<< new QStandardItem(QString::number(balance->GetUserID()))
				<< new QStandardItem(QString::number(balance->GetCurrencyID()));

			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(balanceItem);
			this->close();
			dialogBL->CommitTransaction(errorMessage);
			delete user;
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
			QString(tr("Please fill user, value and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateBlcDlg::EditBalance()
{
	errorMessage.clear();
	if (0 != userEdit->text().toInt() && 0 != currencyEdit->text().toInt())
	{
		if (balance->GetUserID() != userEdit->text().toInt() || balance->GetValue() != valueEdit->text().toDouble()
			|| balance->GetCurrencyID() != currencyEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetBalanceParams(userEdit->text().toInt(), valueEdit->text().toDouble(), currencyEdit->text().toInt(), balance->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateBalance(balance, errorMessage))
			{
				BusinessLayer::User *user = new BusinessLayer::User();
				BusinessLayer::Currency *currency = new BusinessLayer::Currency;
				if (!user->GetUserByID(dialogBL->GetOrmasDal(), balance->GetUserID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), balance->GetCurrencyID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete user;
					delete currency;
					return;
				}

				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				if (0 != balance->GetUserID())
				{
					itemModel->item(mIndex.row(), 1)->setText(user->GetName().c_str());
					itemModel->item(mIndex.row(), 2)->setText(user->GetSurname().c_str());
				}
				else
				{
					itemModel->item(mIndex.row(), 1)->setText("");
					itemModel->item(mIndex.row(), 2)->setText("");
				}
				
				itemModel->item(mIndex.row(), 3)->setText(QString::number(balance->GetValue()));
				itemModel->item(mIndex.row(), 4)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 5)->setText(QString::number(balance->GetUserID()));
				itemModel->item(mIndex.row(), 6)->setText(QString::number(balance->GetCurrencyID()));
				emit itemModel->dataChanged(mIndex, mIndex);
				this->close();
				dialogBL->CommitTransaction(errorMessage);
				delete user;
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

void CreateBlcDlg::Close()
{
	this->close();
}

void CreateBlcDlg::OpenUserDlg()
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
		dForm->createBlcDlg = this;
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

void CreateBlcDlg::OpenCurDlg()
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
		dForm->createBlcDlg = this;
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