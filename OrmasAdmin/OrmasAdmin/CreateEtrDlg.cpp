#include "stdafx.h"
#include "CreateEtrDlg.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"


CreateEtrDlg::CreateEtrDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	daIDEdit->setValidator(vInt);
	valueEdit->setValidator(vDouble);
	caIDEdit->setValidator(vInt);
	valueEdit->setMaxLength(17);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateEtrDlg::EditEntry);
	}
	else
	{
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateEtrDlg::CreateEntry);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateEtrDlg::Close);
	QObject::connect(dAccBtn, &QPushButton::released, this, &CreateEtrDlg::OpenDAccDlg);
	QObject::connect(cAccBtn, &QPushButton::released, this, &CreateEtrDlg::OpenCAccDlg);
	QObject::connect(daNumberEdit, &QLineEdit::textChanged, this, &CreateEtrDlg::TextChanged);
	QObject::connect(caNumberEdit, &QLineEdit::textChanged, this, &CreateEtrDlg::TextChanged);
}

CreateEtrDlg::~CreateEtrDlg()
{
	delete vInt;
	delete vDouble;
}

void CreateEtrDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("debitingAccountForm"))
			{
				daIDEdit->setText(QString::number(ID));
				BusinessLayer::Account account;
				if (account.GetAccountByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					if (account.GetName(dialogBL->GetOrmasDal()).c_str() != nullptr)
						daNamePh->setText(account.GetName(dialogBL->GetOrmasDal()).c_str());
					daNumberEdit->setReadOnly(true);
					daNumberEdit->setText(account.GetNumber().c_str());
				}
			}
			if (childName == QString("creditingAccountForm"))
			{
				caIDEdit->setText(QString::number(ID));
				BusinessLayer::Account account;
				if (account.GetAccountByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					if (account.GetName(dialogBL->GetOrmasDal()).c_str() != nullptr)
						caNamePh->setText(account.GetName(dialogBL->GetOrmasDal()).c_str());
					caNumberEdit->setReadOnly(true);
					caNumberEdit->setText(account.GetNumber().c_str());
				}
			}
		}
	}
}

void CreateEtrDlg::SetEntryParams(QString eDate, int daID, double eValue, int caID, int id)
{
	entry->SetDate(eDate.toUtf8().constData());
	entry->SetDebitingAccountID(daID);
	entry->SetValue(eValue);
	entry->SetCreditingAccountID(caID);
	entry->SetID(id);
}

void CreateEtrDlg::FillEditElements(QString eDate, int daID, double eValue, int caID)
{
	dateEdit->setDate(QDate::fromString(eDate, "yyyy.MM.dd"));
	daIDEdit->setText(QString::number(daID));
	valueEdit->setText(QString::number(eValue));
	caIDEdit->setText(QString::number(caID));
	BusinessLayer::Account account1;
	if (account1.GetAccountByID(dialogBL->GetOrmasDal(), daID, errorMessage))
	{
		if (account1.GetName(dialogBL->GetOrmasDal()).c_str() != nullptr)
			daNamePh->setText(account1.GetName(dialogBL->GetOrmasDal()).c_str());
		daNumberEdit->setReadOnly(true);
		daNumberEdit->setText(account1.GetNumber().c_str());
	}
	BusinessLayer::Account account2;
	if (account2.GetAccountByID(dialogBL->GetOrmasDal(), caID, errorMessage))
	{
		if (account2.GetName(dialogBL->GetOrmasDal()).c_str() != nullptr)
			caNamePh->setText(account2.GetName(dialogBL->GetOrmasDal()).c_str());
		caNumberEdit->setReadOnly(true);
		caNumberEdit->setText(account2.GetNumber().c_str());
	}
}

bool CreateEtrDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetEntryParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 6)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 8)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 6)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 8)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateEtrDlg::CreateEntry()
{
	errorMessage.clear();
	if (0 != daIDEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && 0 != caIDEdit->text().toInt()
		&& !dateEdit->text().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetEntryParams(dateEdit->text(), daIDEdit->text().toInt(), dateEdit->text().toDouble(), caIDEdit->text().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateEntry(entry, errorMessage))
		{
			BusinessLayer::Account *dAccount = new BusinessLayer::Account;
			if (dAccount->GetAccountByID(dialogBL->GetOrmasDal(), daIDEdit->text().toInt(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete dAccount;
				return;
			}
			BusinessLayer::Account *cAccount = new BusinessLayer::Account;
			if (cAccount->GetAccountByID(dialogBL->GetOrmasDal(), caIDEdit->text().toInt(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete dAccount;
				delete cAccount;
				return;
			}

			QList<QStandardItem*> entryItem;
			entryItem << new QStandardItem(QString::number(entry->GetID()))
				<< new QStandardItem(entry->GetDate().c_str())
				<< new QStandardItem(dAccount->GetNumber().c_str())
				<< new QStandardItem(QString::number(entry->GetValue()))
				<< new QStandardItem(cAccount->GetNumber().c_str())
				<< new QStandardItem(QString::number(entry->GetDebitingAccountID()))
				<< new QStandardItem(QString::number(entry->GetCreditingAccountID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(entryItem);

			dialogBL->CommitTransaction(errorMessage);

			delete dAccount;
			delete cAccount;
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
			QString(tr("Please fill user, value, date and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateEtrDlg::EditEntry()
{
	errorMessage.clear();
	if (0 != daIDEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && 0 != caIDEdit->text().toInt()
		&& !dateEdit->text().isEmpty())
	{
		if (QString(entry->GetDate().c_str()) != dateEdit->text() || entry->GetCreditingAccountID() != caIDEdit->text().toInt()
			|| entry->GetValue() != valueEdit->text().toDouble() || entry->GetDebitingAccountID() != daIDEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetEntryParams(dateEdit->text(), daIDEdit->text().toInt(), dateEdit->text().toDouble(), caIDEdit->text().toInt(), entry->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateEntry(entry, errorMessage))
			{
				BusinessLayer::Account *dAccount = new BusinessLayer::Account;
				if (dAccount->GetAccountByID(dialogBL->GetOrmasDal(), daIDEdit->text().toInt(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete dAccount;
					return;
				}
				BusinessLayer::Account *cAccount = new BusinessLayer::Account;
				if (cAccount->GetAccountByID(dialogBL->GetOrmasDal(), caIDEdit->text().toInt(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete dAccount;
					delete cAccount;
					return;
				}
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(entry->GetDate().c_str());
				itemModel->item(mIndex.row(), 2)->setText(dAccount->GetNumber().c_str());
				itemModel->item(mIndex.row(), 3)->setText(QString::number(entry->GetValue()));
				itemModel->item(mIndex.row(), 4)->setText(cAccount->GetNumber().c_str());
				itemModel->item(mIndex.row(), 5)->setText(QString::number(entry->GetDebitingAccountID()));
				itemModel->item(mIndex.row(), 6)->setText(QString::number(entry->GetCreditingAccountID()));
				emit itemModel->dataChanged(mIndex, mIndex);

				dialogBL->CommitTransaction(errorMessage);

				delete dAccount;
				delete cAccount;
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
			QString(tr("Please fill user, value and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateEtrDlg::Close()
{
	this->close();
}

void CreateEtrDlg::OpenDAccDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Accounts"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::AccountView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createEtrDlg = this;
		dForm->setObjectName("debitingAccountForm");
		dForm->QtConnect<BusinessLayer::AccountView>();
		QMdiSubWindow *dAccountWindow = new QMdiSubWindow;
		dAccountWindow->setWidget(dForm);
		dAccountWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(dAccountWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All accounts are shown");
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

void CreateEtrDlg::OpenCAccDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Accounts"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::AccountView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createEtrDlg = this;
		dForm->setObjectName("creditingAccountForm");
		dForm->QtConnect<BusinessLayer::AccountView>();
		QMdiSubWindow *cAccountWindow = new QMdiSubWindow;
		cAccountWindow->setWidget(dForm);
		cAccountWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(cAccountWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All accounts are shown");
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

void CreateEtrDlg::TextChanged()
{
	if (daIDEdit->text().length() == 15)
	{
		BusinessLayer::Account account;
		if (account.GetAccountByNumber(dialogBL->GetOrmasDal(), daNumberEdit->text().toUtf8().constData(), errorMessage))
		{
			daIDEdit->setText(QString::number(account.GetID()));
			if (account.GetName(dialogBL->GetOrmasDal()).c_str() != nullptr)
				daNamePh->setText(account.GetName(dialogBL->GetOrmasDal()).c_str());
		}
		else
		{
			daNamePh->setText(tr("Incorrect account number!"));
		}
	}
	else
	{
		daNamePh->setText("");
	}
	if (caIDEdit->text().length() == 15)
	{
		BusinessLayer::Account account;
		if (account.GetAccountByNumber(dialogBL->GetOrmasDal(), daNumberEdit->text().toUtf8().constData(), errorMessage))
		{
			daIDEdit->setText(QString::number(account.GetID()));
			if (account.GetName(dialogBL->GetOrmasDal()).c_str() != nullptr)
				daNamePh->setText(account.GetName(dialogBL->GetOrmasDal()).c_str());
		}
		else
		{
			daNamePh->setText(tr("Incorrect account number!"));
		}
	}
	else
	{
		caNamePh->setText("");
	}
}