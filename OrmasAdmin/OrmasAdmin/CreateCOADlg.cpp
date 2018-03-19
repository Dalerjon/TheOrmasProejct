#include "stdafx.h"
#include "CreateCOADlg.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"


CreateCOADlg::CreateCOADlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	numberEdit->setValidator(vInt);
	nameEdit->setMaxLength(150);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateCOADlg::EditChartOfAccounts);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateCOADlg::CreateChartOfAccounts);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateCOADlg::Close);
	QObject::connect(accTypeBtn, &QPushButton::released, this, &CreateCOADlg::OpenAccTpDlg);
}

CreateCOADlg::~CreateCOADlg()
{
	delete vInt;
	delete vDouble;
}

void CreateCOADlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("accountTypeForm"))
			{
				accTypeEdit->setText(QString::number(ID));
				BusinessLayer::AccountType accType;
				if (accType.GetAccountTypeByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					accTypeNamePh->setText(accType.GetName().c_str());
				}
			}
		}
	}
}

void CreateCOADlg::SetChartOfAccountsParams(QString cName,  int cNumber, int atID, int id)
{
	chartOfAccounts->SetName(cName.toUtf8().constData());
	chartOfAccounts->SetNumber(cNumber);
	chartOfAccounts->SetAccountTypeID(atID);
	chartOfAccounts->SetID(id);
}

void CreateCOADlg::FillEditElements(QString cName, int cNumber, int atID)
{
	nameEdit->setText(cName);
	numberEdit->setText(QString::number(cNumber));
	accTypeEdit->setText(QString::number(atID));
	BusinessLayer::AccountType accType;
	if (accType.GetAccountTypeByID(dialogBL->GetOrmasDal(), atID, errorMessage))
	{
		accTypeNamePh->setText(accType.GetName().c_str());
	}
}

bool CreateCOADlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetChartOfAccountsParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 4)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 4)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateCOADlg::CreateChartOfAccounts()
{
	errorMessage.clear();
	if (!nameEdit->text().isEmpty() && 0 != numberEdit->text().toInt() && 0 != accTypeEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetChartOfAccountsParams(nameEdit->text(), numberEdit->text().toInt(), accTypeEdit->text().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateChartOfAccounts(chartOfAccounts, errorMessage))
		{
			BusinessLayer::AccountType *accType = new BusinessLayer::AccountType();
			if (!accType->GetAccountTypeByID(dialogBL->GetOrmasDal(), chartOfAccounts->GetAccountTypeID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete accType;
				return;
			}

			QList<QStandardItem*> chartOfAccountsItem;
			chartOfAccountsItem << new QStandardItem(QString::number(chartOfAccounts->GetID()))
				<< new QStandardItem(chartOfAccounts->GetName().c_str())
				<< new QStandardItem(QString::number(chartOfAccounts->GetNumber()))
				<< new QStandardItem(QString::number(chartOfAccounts->GetAccountTypeID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(chartOfAccountsItem);

			dialogBL->CommitTransaction(errorMessage);

			delete accType;
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

void CreateCOADlg::EditChartOfAccounts()
{
	errorMessage.clear();
	if (!nameEdit->text().isEmpty() && 0 != numberEdit->text().toInt() && 0 != accTypeEdit->text().toInt())
	{
		if (QString(chartOfAccounts->GetName().c_str()) != nameEdit->text() || chartOfAccounts->GetNumber() != numberEdit->text().toInt()
			|| chartOfAccounts->GetAccountTypeID() != accTypeEdit->text().toDouble())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetChartOfAccountsParams(nameEdit->text(), numberEdit->text().toInt(), accTypeEdit->text().toInt(), chartOfAccounts->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateChartOfAccounts(chartOfAccounts, errorMessage))
			{
				BusinessLayer::AccountType *accType = new BusinessLayer::AccountType();
				if (!accType->GetAccountTypeByID(dialogBL->GetOrmasDal(), chartOfAccounts->GetAccountTypeID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete accType;
					return;
				}

				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(chartOfAccounts->GetName().c_str());
				itemModel->item(mIndex.row(), 2)->setText(QString::number(chartOfAccounts->GetNumber()));
				itemModel->item(mIndex.row(), 3)->setText(accType->GetName().c_str());
				itemModel->item(mIndex.row(), 4)->setText(QString::number(chartOfAccounts->GetAccountTypeID()));
				emit itemModel->dataChanged(mIndex, mIndex);

				dialogBL->CommitTransaction(errorMessage);

				delete accType;
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

void CreateCOADlg::Close()
{
	this->close();
}

void CreateCOADlg::OpenAccTpDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Account types"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::AccountType>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createCOADlg = this;
		dForm->setObjectName("accountTypeForm");
		dForm->QtConnect<BusinessLayer::AccountType>();
		QMdiSubWindow *accTypeWindow = new QMdiSubWindow;
		accTypeWindow->setWidget(dForm);
		accTypeWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(accTypeWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All account types are shown");
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