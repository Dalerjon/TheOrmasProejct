#include "stdafx.h"
#include "CreateWdwDlg.h"
#include "DataForm.h"


CreateWdwDlg::CreateWdwDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	parentForm = parent;
	DataForm *dataFormParent = (DataForm *)this->parentForm;
	mainForm = (MainForm *)dataFormParent->GetParent();
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	userEdit->setValidator(vInt);
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
	QObject::connect(userBtn, &QPushButton::released, this, &CreateWdwDlg::OpenUserDlg);
	QObject::connect(valueEdit, &QLineEdit::textChanged, this, &CreateWdwDlg::TextEditChanged);
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
			this->hide();
			this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
			this->show();
			this->raise();
			this->activateWindow();
			QApplication::setActiveWindow(this);

			if (childName == QString("userForm"))
			{
				userEdit->setText(QString::number(ID));
				BusinessLayer::User user;
				if (user.GetUserByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					namePh->setText(user.GetName().c_str());
					surnamePh->setText(user.GetSurname().c_str());
					phonePh->setText(user.GetPhone().c_str());
				}
				BusinessLayer::Balance balance;
				BusinessLayer::Subaccount subaccount;
				BusinessLayer::Currency currency;
				if (balance.GetBalanceByUserID(dialogBL->GetOrmasDal(), user.GetID(), errorMessage))
				{
					if (subaccount.GetSubaccountByID(dialogBL->GetOrmasDal(), balance.GetSubaccountID(), errorMessage))
					{
						balanceEdit->setText(QString::number(subaccount.GetCurrentBalance()));
						if (currency.GetCurrencyByID(dialogBL->GetOrmasDal(), subaccount.GetCurrencyID(), errorMessage))
						{
							currencyNameEdit->setText(currency.GetName().c_str());
						}
					}
				}
			}
		}
	}
}

void CreateWdwDlg::SetWithdrawalParams(QString wDate, double wValue, int wUserID, int wCurrencyID, int id)
{
	withdrawal->SetDate(wDate.toUtf8().constData());
	withdrawal->SetValue(wValue);
	withdrawal->SetUserID(wUserID);
	withdrawal->SetCurrencyID(wCurrencyID);
	withdrawal->SetID(id);
}

void CreateWdwDlg::FillEditElements(QString wDate, double wValue, int wUserID, int wCurrencyID)
{
	dateEdit->setDateTime(QDateTime::fromString(wDate, "dd.MM.yyyy hh:mm"));
	valueEdit->setText(QString::number(wValue));
	userEdit->setText(QString::number(wUserID));
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(wCurrencyID)));
	BusinessLayer::User user;
	if (user.GetUserByID(dialogBL->GetOrmasDal(), wUserID, errorMessage))
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
	if (0 != userEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && !currencyCmb->currentText().isEmpty()
		&& !dateEdit->text().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*) parentForm;
		SetWithdrawalParams(dateEdit->text(), valueEdit->text().toDouble(), userEdit->text().toInt(), currencyCmb->currentData().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateWithdrawal(withdrawal, errorMessage))
		{
			if (parentDataForm != nullptr)
			{
				if (!parentDataForm->IsClosed())
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
					delete currency;
				}
			}
			dialogBL->CommitTransaction(errorMessage);
			
			Close();
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
	if (0 != userEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && !currencyCmb->currentText().isEmpty()
		&& !dateEdit->text().isEmpty())
	{
		if (QString(withdrawal->GetDate().c_str()) != dateEdit->text() || withdrawal->GetUserID() != userEdit->text().toInt()
			|| withdrawal->GetValue() != valueEdit->text().toDouble() || withdrawal->GetCurrencyID() != currencyCmb->currentData().toInt())
		{
			DataForm *parentDataForm = (DataForm*) parentForm;
			SetWithdrawalParams(dateEdit->text(), valueEdit->text().toDouble(), userEdit->text().toInt(), currencyCmb->currentData().toInt(), withdrawal->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateWithdrawal(withdrawal, errorMessage))
			{
				if (parentDataForm != nullptr)
				{
					if (!parentDataForm->IsClosed())
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
						delete currency;
					}
				}
				dialogBL->CommitTransaction(errorMessage);
				
				Close();
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
			Close();
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
	this->parentWidget()->close();
}

void CreateWdwDlg::OpenUserDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("users"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::UserView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("userForm");
		dForm->QtConnect<BusinessLayer::UserView>();
		QMdiSubWindow *userWindow = new QMdiSubWindow;
		userWindow->setWidget(dForm);
		userWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(userWindow);
		userWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->HileSomeRow();
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
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

void CreateWdwDlg::TextEditChanged()
{
	if (valueEdit->text().contains(","))
	{
		valueEdit->setText(valueEdit->text().replace(",", "."));
	}
	if (valueEdit->text().contains(".."))
	{
		valueEdit->setText(valueEdit->text().replace("..", "."));
	}
}