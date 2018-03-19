#include "stdafx.h"
#include "CreateAccDlg.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateAccDlg::CreateAccDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	numberEdit->setMaxLength(20);
	statusEdit->setValidator(vInt);
	startBalanceEdit->setValidator(vDouble);
	currentBalanceEdit->setValidator(vDouble);
	startBalanceEdit->setMaxLength(17);
	currentBalanceEdit->setMaxLength(17);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateAccDlg::EditAccount);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateAccDlg::CreateAccount);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateAccDlg::Close);
	QObject::connect(chartOfAccBtn, &QPushButton::released, this, &CreateAccDlg::OpenCOADlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateAccDlg::OpenStsDlg);
	InitComboBox();
}

CreateAccDlg::~CreateAccDlg()
{
	delete vInt;
	delete vDouble;
}

void CreateAccDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("chartOfAccountForm"))
			{
				chartOfAccEdit->setText(QString::number(ID));
				BusinessLayer::ChartOfAccounts coAcc;
				if (coAcc.GetChartOfAccountsByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					accNamePh->setText(coAcc.GetName().c_str());
				}
			}
			if (childName == QString("statusForm"))
			{
				statusEdit->setText(QString::number(ID));
				BusinessLayer::Status status;
				if (status.GetStatusByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					statusPh->setText(status.GetName().c_str());
				}
			}
		}
	}
}

void CreateAccDlg::SetAccountParams(QString aNumber, double aStartBalance, double aCurrentBalance, int cID, int sID, 
	QString aOpenedDate, QString aClosedDate, QString aDetails, int id)
{
	account->SetNumber(aNumber.toUtf8().constData());
	account->SetStartBalance(aStartBalance);
	account->SetCurrentBalance(aCurrentBalance);
	account->SetCurrencyID(cID);
	account->SetStatusID(sID);
	account->SetOpenedDate(aOpenedDate.toUtf8().constData());
	account->SetClosedDate(aClosedDate.toUtf8().constData());
	account->SetDetails(aDetails.toUtf8().constData());
	account->SetID(id);
}

void CreateAccDlg::FillEditElements(QString aNumber, double aStartBalance, double aCurrentBalance, int cID, int sID,
	QString aOpenedDate, QString aClosedDate, QString aDetails)
{
	numberEdit->setText(aNumber);
	startBalanceEdit->setText(QString::number(aStartBalance));
	currentBalanceEdit->setText(QString::number(aCurrentBalance));
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(cID)));
	statusEdit->setText(QString::number(sID));
	openedDateEdit->setDate(QDate::fromString(aOpenedDate, "yyyy.MM.dd"));
	detailsEdit->setText(aDetails);
	BusinessLayer::ChartOfAccounts aoAcc;
	if (aoAcc.GetChartOfAccountsByNumber(dialogBL->GetOrmasDal(), aNumber.left(4).toInt(), errorMessage))
	{
		
		chartOfAccEdit->setText(QString::number(aoAcc.GetID()));
		accNamePh->setText(aoAcc.GetName().c_str());
		
	}
}

bool CreateAccDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetAccountParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 3)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 6)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 7)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 8)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 10)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 3)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 6)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 7)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 8)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 10)).toString().toUtf8().constData());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateAccDlg::CreateAccount()
{
	errorMessage.clear();
	if (!numberEdit->text().isEmpty() && !currencyCmb->currentText().isEmpty() &&
		!openedDateEdit->text().isEmpty() && 0 != statusEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetAccountParams(numberEdit->text(), startBalanceEdit->text().toDouble(), currentBalanceEdit->text().toDouble(), 
			currencyCmb->currentData().toInt(), statusEdit->text().toInt(), 
			openedDateEdit->text(), "", detailsEdit->text());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateAccount(account, errorMessage))
		{
			BusinessLayer::Status *status = new BusinessLayer::Status;
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;
			if (!status->GetStatusByID(dialogBL->GetOrmasDal(), account->GetStatusID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), account->GetCurrencyID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete currency;
				delete status;
				return;
			}
			QList<QStandardItem*> accountItem;
			accountItem << new QStandardItem(QString::number(account->GetID()))
				<< new QStandardItem(account->GetNumber().c_str())
				<< new QStandardItem(QString::number(account->GetStartBalance()))
				<< new QStandardItem(QString::number(account->GetCurrentBalance()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(status->GetName().c_str())
				<< new QStandardItem(QString::number(account->GetCurrencyID()))
				<< new QStandardItem(QString::number(account->GetStatusID()))
				<< new QStandardItem(account->GetOpenedDate().c_str())
				<< new QStandardItem(account->GetClosedDate().c_str())
				<< new QStandardItem(account->GetDetails().c_str());
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(accountItem);

			dialogBL->CommitTransaction(errorMessage);
			delete currency;
			delete status;
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
			QString(tr("Please fill all fields!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateAccDlg::EditAccount()
{
	errorMessage.clear();
	if (!numberEdit->text().isEmpty() && !currencyCmb->currentText().isEmpty() &&
		!openedDateEdit->text().isEmpty() && 0 != statusEdit->text().toInt())
	{
		if (QString(account->GetNumber().c_str()) != numberEdit->text()	|| account->GetStartBalance() != startBalanceEdit->text().toDouble()
			|| account->GetCurrentBalance() != currentBalanceEdit->text().toDouble() || account->GetCurrencyID() != currencyCmb->currentData().toInt()
			|| account->GetStatusID() != statusEdit->text().toInt() || QString(account->GetOpenedDate().c_str()) != openedDateEdit->text()
			|| QString(account->GetDetails().c_str()) != detailsEdit->text())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetAccountParams(numberEdit->text(), startBalanceEdit->text().toDouble(), currentBalanceEdit->text().toDouble(),
				currencyCmb->currentData().toInt(), statusEdit->text().toInt(),
				openedDateEdit->text(), "", detailsEdit->text(), account->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateAccount(account, errorMessage))
			{
				BusinessLayer::Status *status = new BusinessLayer::Status;
				BusinessLayer::Currency *currency = new BusinessLayer::Currency;
				if (!status->GetStatusByID(dialogBL->GetOrmasDal(), account->GetStatusID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), account->GetCurrencyID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete currency;
					delete status;
					return;
				}
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(QString::number(account->GetID()));
				itemModel->item(mIndex.row(), 2)->setText(account->GetNumber().c_str());
				itemModel->item(mIndex.row(), 3)->setText(QString::number(account->GetStartBalance()));
				itemModel->item(mIndex.row(), 4)->setText(QString::number(account->GetCurrentBalance()));
				itemModel->item(mIndex.row(), 5)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 6)->setText(status->GetName().c_str());
				itemModel->item(mIndex.row(), 7)->setText(QString::number(account->GetCurrencyID()));
				itemModel->item(mIndex.row(), 8)->setText(QString::number(account->GetStatusID()));
				itemModel->item(mIndex.row(), 9)->setText(account->GetOpenedDate().c_str());
				itemModel->item(mIndex.row(), 10)->setText(account->GetClosedDate().c_str());
				itemModel->item(mIndex.row(), 11)->setText(account->GetDetails().c_str());
				emit itemModel->dataChanged(mIndex, mIndex);

				dialogBL->CommitTransaction(errorMessage);
				delete currency;
				delete status;
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
			QString(tr("Please fill all fields!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateAccDlg::Close()
{
	this->close();
}

void CreateAccDlg::OpenStsDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Status"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::Status>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createAccDlg = this;
		dForm->setObjectName("statusForm");
		dForm->QtConnect<BusinessLayer::Status>();
		QMdiSubWindow *statusWindow = new QMdiSubWindow;
		statusWindow->setWidget(dForm);
		statusWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(statusWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All status are shown");
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

void CreateAccDlg::OpenCOADlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Chart of accounts"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::ChartOfAccountsView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createAccDlg = this;
		dForm->setObjectName("chartOfAccountForm");
		dForm->QtConnect<BusinessLayer::ChartOfAccountsView>();
		QMdiSubWindow *coAccWindow = new QMdiSubWindow;
		coAccWindow->setWidget(dForm);
		coAccWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(coAccWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("Chart of accounts are shown");
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

void CreateAccDlg::InitComboBox()
{
	std::vector<BusinessLayer::Currency> curVector = dialogBL->GetAllDataForClass<BusinessLayer::Currency>(errorMessage);
	if (!curVector.empty())
	{
		for (unsigned int i = 0; i < curVector.size(); i++)
		{
			currencyCmb->addItem(curVector[i].GetShortName().c_str(), QVariant(curVector[i].GetID()));
		}
	}
}