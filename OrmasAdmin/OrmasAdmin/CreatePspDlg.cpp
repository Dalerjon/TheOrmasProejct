#include "stdafx.h"
#include "CreatePspDlg.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"


CreatePspDlg::CreatePspDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	salaryEdit->setValidator(vInt);
	valueEdit->setValidator(vDouble);
	currencyEdit->setValidator(vInt);
	valueEdit->setMaxLength(17);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreatePspDlg::EditPayslip);
	}
	else
	{
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreatePspDlg::CreatePayslip);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreatePspDlg::Close);
	QObject::connect(salaryBtn, &QPushButton::released, this, &CreatePspDlg::OpenSlrDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreatePspDlg::OpenCurDlg);
}

CreatePspDlg::~CreatePspDlg()
{
	delete vInt;
	delete vDouble;
}

void CreatePspDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("salaryForm"))
			{
				salaryEdit->setText(QString::number(ID));
			}
			if (childName == QString("currencyForm"))
			{
				currencyEdit->setText(QString::number(ID));
			}
		}
	}
}

void CreatePspDlg::SetPayslipParams(QString pDate, double pValue, int pSalaryID, int pCurrencyID, int id)
{
	Payslip->SetDate(pDate.toUtf8().constData());
	Payslip->SetValue(pValue);
	Payslip->SetSalaryID(pSalaryID);
	Payslip->SetCurrencyID(pCurrencyID);
	Payslip->SetID(id);
}

void CreatePspDlg::FillEditElements(QString pDate, double pValue, int pSalaryID, int pCurrencyID)
{
	dateEdit->setDateTime(QDateTime::fromString(pDate, "yyyy.MM.dd hh:mm:ss"));
	valueEdit->setText(QString::number(pValue));
	salaryEdit->setText(QString::number(pSalaryID));
	currencyEdit->setText(QString::number(pCurrencyID));
}

bool CreatePspDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetPayslipParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
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

void CreatePspDlg::CreatePayslip()
{
	errorMessage.clear();
	if (0 != salaryEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && 0 != currencyEdit->text().toInt()
		&& !dateEdit->text().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetPayslipParams(dateEdit->text(), valueEdit->text().toDouble(), salaryEdit->text().toInt(), currencyEdit->text().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreatePayslip(Payslip, errorMessage))
		{
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;
			if (!currency->GetCurrencyByID(dialogBL->GetOrmasDal(), Payslip->GetCurrencyID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete currency;
				return;
			}
			QList<QStandardItem*> payslipItem;
			payslipItem << new QStandardItem(QString::number(Payslip->GetID()))
				<< new QStandardItem(Payslip->GetDate().c_str())
				<< new QStandardItem(QString::number(Payslip->GetValue()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(QString::number(Payslip->GetSalaryID()))
				<< new QStandardItem(QString::number(Payslip->GetCurrencyID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(payslipItem);
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

void CreatePspDlg::EditPayslip()
{
	errorMessage.clear();
	if (0 != salaryEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && 0 != currencyEdit->text().toInt()
		&& !dateEdit->text().isEmpty())
	{
		if (QString(Payslip->GetDate().c_str()) != dateEdit->text() || Payslip->GetSalaryID() != salaryEdit->text().toInt()
			|| Payslip->GetValue() != valueEdit->text().toDouble() || Payslip->GetCurrencyID() != currencyEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetPayslipParams(dateEdit->text(), valueEdit->text().toDouble(), salaryEdit->text().toInt(), currencyEdit->text().toInt(), Payslip->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdatePayslip(Payslip, errorMessage))
			{
				BusinessLayer::Currency *currency = new BusinessLayer::Currency;
				if (!currency->GetCurrencyByID(dialogBL->GetOrmasDal(), Payslip->GetCurrencyID(), errorMessage))
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
				itemModel->item(mIndex.row(), 1)->setText(Payslip->GetDate().c_str());
				itemModel->item(mIndex.row(), 2)->setText(QString::number(Payslip->GetValue()));
				itemModel->item(mIndex.row(), 3)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 4)->setText(QString::number(Payslip->GetSalaryID()));
				itemModel->item(mIndex.row(), 5)->setText(QString::number(Payslip->GetCurrencyID()));
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

void CreatePspDlg::Close()
{
	this->close();
}

void CreatePspDlg::OpenSlrDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Salaries"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::SalaryView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createPspDlg = this;
		dForm->setObjectName("salaryForm");
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

void CreatePspDlg::OpenCurDlg()
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
		dForm->createPspDlg = this;
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