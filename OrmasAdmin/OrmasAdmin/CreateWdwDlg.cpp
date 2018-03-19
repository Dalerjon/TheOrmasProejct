#include "stdafx.h"
#include "CreateWdwDlg.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"


CreateWdwDlg::CreateWdwDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	employeeEdit->setValidator(vInt);
	valueEdit->setValidator(vDouble);
	valueEdit->setMaxLength(17);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateWdwDlg::EditWithdrawal);
	}
	else
	{
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateWdwDlg::CreateWithdrawal);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateWdwDlg::Close);
	QObject::connect(employeeBtn, &QPushButton::released, this, &CreateWdwDlg::OpenEmployeeDlg);
	InitComboBox();
}

CreateWdwDlg::~CreateWdwDlg()
{
	delete vInt;
	delete vDouble;
}

void CreateWdwDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("employeeForm"))
			{
				employeeEdit->setText(QString::number(ID));
				BusinessLayer::User user;
				if (user.GetUserByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					namePh->setText(user.GetName().c_str());
					surnamePh->setText(user.GetSurname().c_str());
					phonePh->setText(user.GetPhone().c_str());
				}
			}
		}
	}
}

void CreateWdwDlg::SetWithdrawalParams(QString wDate, double wValue, int wEmployeeID, int wCurrencyID, int id)
{
	withdrawal->SetDate(wDate.toUtf8().constData());
	withdrawal->SetValue(wValue);
	withdrawal->SetUserID(wEmployeeID);
	withdrawal->SetCurrencyID(wCurrencyID);
	withdrawal->SetID(id);
}

void CreateWdwDlg::FillEditElements(QString wDate, double wValue, int wEmployeeID, int wCurrencyID)
{
	dateEdit->setDateTime(QDateTime::fromString(wDate, "yyyy.MM.dd hh:mm:ss"));
	valueEdit->setText(QString::number(wValue));
	employeeEdit->setText(QString::number(wEmployeeID));
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(wCurrencyID)));
	BusinessLayer::User user;
	if (user.GetUserByID(dialogBL->GetOrmasDal(), wEmployeeID, errorMessage))
	{
		namePh->setText(user.GetName().c_str());
		surnamePh->setText(user.GetSurname().c_str());
		phonePh->setText(user.GetPhone().c_str());
	}
}

bool CreateWdwDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetWithdrawalParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
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

void CreateWdwDlg::CreateWithdrawal()
{
	errorMessage.clear();
	if (0 != employeeEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && !currencyCmb->currentText().isEmpty()
		&& !dateEdit->text().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetWithdrawalParams(dateEdit->text(), valueEdit->text().toDouble(), employeeEdit->text().toInt(), currencyCmb->currentData().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateWithdrawal(withdrawal, errorMessage))
		{
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;
			if (!currency->GetCurrencyByID(dialogBL->GetOrmasDal(), withdrawal->GetCurrencyID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete currency;
				return;
			}
			QList<QStandardItem*> withdrawalItem;
			withdrawalItem << new QStandardItem(QString::number(withdrawal->GetID()))
				<< new QStandardItem(withdrawal->GetDate().c_str())
				<< new QStandardItem(QString::number(withdrawal->GetValue()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(QString::number(withdrawal->GetUserID()))
				<< new QStandardItem(QString::number(withdrawal->GetCurrencyID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(withdrawalItem);
			
			dialogBL->CommitTransaction(errorMessage);
			delete currency;
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
			QString(tr("Please fill employee, value, date and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateWdwDlg::EditWithdrawal()
{
	errorMessage.clear();
	if (0 != employeeEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && !currencyCmb->currentText().isEmpty()
		&& !dateEdit->text().isEmpty())
	{
		if (QString(withdrawal->GetDate().c_str()) != dateEdit->text() || withdrawal->GetUserID() != employeeEdit->text().toInt()
			|| withdrawal->GetValue() != valueEdit->text().toDouble() || withdrawal->GetCurrencyID() != currencyCmb->currentData().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetWithdrawalParams(dateEdit->text(), valueEdit->text().toDouble(), employeeEdit->text().toInt(), currencyCmb->currentData().toInt(), withdrawal->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateWithdrawal(withdrawal, errorMessage))
			{
				BusinessLayer::Currency *currency = new BusinessLayer::Currency;
				if (!currency->GetCurrencyByID(dialogBL->GetOrmasDal(), withdrawal->GetCurrencyID(), errorMessage))
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
				itemModel->item(mIndex.row(), 1)->setText(withdrawal->GetDate().c_str());
				itemModel->item(mIndex.row(), 2)->setText(QString::number(withdrawal->GetValue()));
				itemModel->item(mIndex.row(), 3)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 4)->setText(QString::number(withdrawal->GetUserID()));
				itemModel->item(mIndex.row(), 5)->setText(QString::number(withdrawal->GetCurrencyID()));
				emit itemModel->dataChanged(mIndex, mIndex);
				
				dialogBL->CommitTransaction(errorMessage);
				delete currency;
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
			QString(tr("Please fill employee, value and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateWdwDlg::Close()
{
	this->close();
}

void CreateWdwDlg::OpenEmployeeDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *employeeParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)employeeParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("employees"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::EmployeeView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createWdwDlg = this;
		dForm->setObjectName("employeeForm");
		dForm->QtConnect<BusinessLayer::EmployeeView>();
		QMdiSubWindow *employeeWindow = new QMdiSubWindow;
		employeeWindow->setWidget(dForm);
		employeeWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(employeeWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All employees are shown");
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

void CreateWdwDlg::InitComboBox()
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