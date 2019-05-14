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
	saIDEdit->setValidator(vInt);
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
	QObject::connect(subAccBtn, &QPushButton::released, this, &CreateWdwDlg::OpenSAccDlg);
	QObject::connect(saNumberEdit, &QLineEdit::textChanged, this, &CreateWdwDlg::SATextChanged);
	QObject::connect(userEdit, &QLineEdit::textChanged, this, &CreateWdwDlg::UserIsChanged);
	QObject::connect(accountCmb, &QComboBox::currentTextChanged, this, &CreateWdwDlg::AccountIsChenged);
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
			if (childName == QString("subaccountForm"))
			{
				saIDEdit->setText(QString::number(ID));
				BusinessLayer::Subaccount subaccount;
				if (subaccount.GetSubaccountByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					saNumberEdit->setReadOnly(true);
					saNumberEdit->setText(subaccount.GetNumber().c_str());
				}
				namePh->setText("");
				surnamePh->setText("");
				phonePh->setText("");
				userEdit->setText("");
			}
		}
	}
}

void CreateWdwDlg::SetWithdrawalParams(QString wDate, double wValue, int wUserID, int wSubAccId, QString wTarget, int wCurrencyID, int id)
{
	withdrawal->SetDate(wDate.toUtf8().constData());
	withdrawal->SetValue(wValue);
	withdrawal->SetUserID(wUserID);
	withdrawal->SetSubaccountID(wSubAccId);
	withdrawal->SetTarget(wTarget.toUtf8().constData());
	withdrawal->SetCurrencyID(wCurrencyID);
	withdrawal->SetID(id);
}

void CreateWdwDlg::FillEditElements(QString wDate, double wValue, int wUserID, int wSubAccId, QString wTarget, int wCurrencyID)
{
	dateEdit->setDateTime(QDateTime::fromString(wDate, "dd.MM.yyyy hh:mm"));
	valueEdit->setText(QString::number(wValue,'f',3));
	userEdit->setText(QString::number(wUserID));
	saIDEdit->setText(QString::number(wSubAccId));
	targetEdit->setText(wTarget);
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(wCurrencyID)));
	BusinessLayer::User user;
	if (user.GetUserByID(dialogBL->GetOrmasDal(), wUserID, errorMessage))
	{
		namePh->setText(user.GetName().c_str());
		surnamePh->setText(user.GetSurname().c_str());
		phonePh->setText(user.GetPhone().c_str());
	}
	BusinessLayer::Subaccount sub;
	if (sub.GetSubaccountByID(dialogBL->GetOrmasDal(), wSubAccId, errorMessage))
	{
		saNumberEdit->setText(sub.GetNumber().c_str());
	}
}

bool CreateWdwDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetWithdrawalParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 8)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 10)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 6)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 8)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 10)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 6)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toInt());
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
	if (0 != saIDEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && !currencyCmb->currentText().isEmpty()
		&& !dateEdit->text().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*) parentForm;
		SetWithdrawalParams(dateEdit->text(), valueEdit->text().toDouble(), userEdit->text().toInt(), saIDEdit->text().toInt(), targetEdit->text(), currencyCmb->currentData().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateWithdrawal(withdrawal, errorMessage))
		{
			if (parentDataForm != nullptr)
			{
				if (!parentDataForm->IsClosed())
				{
					BusinessLayer::Currency currency;
					if (!currency.GetCurrencyByID(dialogBL->GetOrmasDal(), withdrawal->GetCurrencyID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						return;
					}
					BusinessLayer::User user;
					if (!userEdit->text().isEmpty())
					{
						if (!user.GetUserByID(dialogBL->GetOrmasDal(), withdrawal->GetUserID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							return;
						}
					}
					BusinessLayer::Subaccount subacc;
					if (!subacc.GetSubaccountByID(dialogBL->GetOrmasDal(), withdrawal->GetSubaccountID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						return;
					}
					QList<QStandardItem*> withdrawalItem;
					withdrawalItem << new QStandardItem(QString::number(withdrawal->GetID()))
						<< new QStandardItem(withdrawal->GetDate().c_str())
						<< new QStandardItem(QString::number(withdrawal->GetValue(),'f',3));
					if (userEdit->text().isEmpty() || user.IsEmpty())
					{
						withdrawalItem << new QStandardItem("")
							<< new QStandardItem("");
					}
					else
					{
						withdrawalItem << new QStandardItem(user.GetName().c_str())
							<< new QStandardItem(user.GetSurname().c_str());
					}
					withdrawalItem << new QStandardItem(subacc.GetNumber().c_str())
						<< new QStandardItem(withdrawal->GetTarget().c_str())
						<< new QStandardItem(currency.GetShortName().c_str())
						<< new QStandardItem(QString::number(withdrawal->GetUserID()))
						<< new QStandardItem(QString::number(withdrawal->GetCurrencyID()))
						<< new QStandardItem(QString::number(withdrawal->GetSubaccountID()));
					QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
					itemModel->appendRow(withdrawalItem);
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
			QString(tr("Please fill employee or subaccout, value and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateWdwDlg::EditWithdrawal()
{
	errorMessage.clear();
	if (0 != saIDEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && !currencyCmb->currentText().isEmpty()
		&& !dateEdit->text().isEmpty())
	{
		if (QString(withdrawal->GetDate().c_str()) != dateEdit->text() || withdrawal->GetSubaccountID() != saIDEdit->text().toInt()
			|| withdrawal->GetValue() != valueEdit->text().toDouble() || withdrawal->GetCurrencyID() != currencyCmb->currentData().toInt())
		{
			DataForm *parentDataForm = (DataForm*) parentForm;
			SetWithdrawalParams(dateEdit->text(), valueEdit->text().toDouble(), userEdit->text().toInt(), saIDEdit->text().toInt(), targetEdit->text(), currencyCmb->currentData().toInt(), withdrawal->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateWithdrawal(withdrawal, errorMessage))
			{
				if (parentDataForm != nullptr)
				{
					if (!parentDataForm->IsClosed())
					{
						BusinessLayer::Currency currency;
						if (!currency.GetCurrencyByID(dialogBL->GetOrmasDal(), withdrawal->GetCurrencyID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							return;
						}
						BusinessLayer::User user;
						if (!userEdit->text().isEmpty())
						{
							if (!user.GetUserByID(dialogBL->GetOrmasDal(), withdrawal->GetUserID(), errorMessage))
							{
								dialogBL->CancelTransaction(errorMessage);
								QMessageBox::information(NULL, QString(tr("Warning")),
									QString(tr(errorMessage.c_str())),
									QString(tr("Ok")));
								errorMessage.clear();
								return;
							}
						}
						BusinessLayer::Subaccount subacc;
						if (!subacc.GetSubaccountByID(dialogBL->GetOrmasDal(), withdrawal->GetSubaccountID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							return;
						}
						QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
						QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
						itemModel->item(mIndex.row(), 1)->setText(withdrawal->GetDate().c_str());
						itemModel->item(mIndex.row(), 2)->setText(QString::number(withdrawal->GetValue(),'f',3));
						if (userEdit->text().isEmpty() || user.IsEmpty())
						{
							itemModel->item(mIndex.row(), 3)->setText("");
							itemModel->item(mIndex.row(), 4)->setText("");
						}
						else
						{
							itemModel->item(mIndex.row(), 3)->setText(user.GetName().c_str());
							itemModel->item(mIndex.row(), 4)->setText(user.GetSurname().c_str());
						}
						itemModel->item(mIndex.row(), 5)->setText(subacc.GetNumber().c_str());
						itemModel->item(mIndex.row(), 6)->setText(withdrawal->GetTarget().c_str());
						itemModel->item(mIndex.row(), 7)->setText(currency.GetShortName().c_str());
						itemModel->item(mIndex.row(), 8)->setText(QString::number(withdrawal->GetUserID()));
						itemModel->item(mIndex.row(), 9)->setText(QString::number(withdrawal->GetCurrencyID()));
						itemModel->item(mIndex.row(), 10)->setText(QString::number(withdrawal->GetSubaccountID()));
						emit itemModel->dataChanged(mIndex, mIndex);
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
			QString(tr("Please fill employee or subaccout, value and currency!")),
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
		SortTable(dForm->tableView);
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

void CreateWdwDlg::OpenSAccDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Subccounts"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	std::string filter = "";
	BusinessLayer::Subaccount sabaccount;
	BusinessLayer::EntryRouting entryRouting;
	if (entryRouting.GetEntryRoutingByID(dialogBL->GetOrmasDal(), accountCmb->currentData().toInt(), errorMessage))
	{
		sabaccount.SetParentAccountID(entryRouting.GetDebitAccountID());
		filter = sabaccount.GenerateFilter(dialogBL->GetOrmasDal());
	}
	dForm->FillTable<BusinessLayer::SubaccountView>(errorMessage, filter);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("subaccountForm");
		dForm->QtConnect<BusinessLayer::SubaccountView>();
		QMdiSubWindow *dSAccountWindow = new QMdiSubWindow;
		dSAccountWindow->setWidget(dForm);
		dSAccountWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(dSAccountWindow);
		dSAccountWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
		QString message = tr("All subaccounts are shown");
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

	BusinessLayer::ChartOfAccounts coAcc;
	BusinessLayer::Account account;
	BusinessLayer::Account account10110;
	BusinessLayer::EntryRouting entryRouting;
	if (account.GetAccountByNumber(dialogBL->GetOrmasDal(), "10110", errorMessage))
	{
		std::string comboText = "";
		entryRouting.SetCreditAccountID(account.GetID());
		std::string filter = entryRouting.GenerateFilter(dialogBL->GetOrmasDal());
		std::vector<BusinessLayer::EntryRouting> entRoutVec = dialogBL->GetAllDataForClass<BusinessLayer::EntryRouting>(errorMessage, filter);
		accountCmb->addItem(tr("All"), 0);
		if (!entRoutVec.empty())
		{
			for (unsigned int i = 0; i < entRoutVec.size(); i++)
			{
				account.Clear();
				if (!account.GetAccountByID(dialogBL->GetOrmasDal(), entRoutVec[i].GetDebitAccountID(), errorMessage))
					continue;
				coAcc.Clear();
				if (!coAcc.GetChartOfAccountsByNumber(dialogBL->GetOrmasDal(), account.GetNumber(), errorMessage))
					continue;
				comboText = "";
				comboText += account.GetNumber();
				comboText += " - ";
				comboText += coAcc.GetName();
				accountCmb->addItem(comboText.c_str(), QVariant(entRoutVec[i].GetID()));
			}
		}
		else
		{
			errorMessage = "";
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

void CreateWdwDlg::AccountIsChenged()
{
	if (accountCmb->currentData().toInt() == 0)
	{
		targetEdit->setText("");
	}
	else
	{
		BusinessLayer::EntryRouting entRouting;
		if (entRouting.GetEntryRoutingByID(dialogBL->GetOrmasDal(), accountCmb->currentData().toInt(), errorMessage))
		{
			targetEdit->setText(entRouting.GetOperation().c_str());
		}
		else
		{
			targetEdit->setText("");
		}
	}
}

void CreateWdwDlg::SATextChanged()
{
	if (saNumberEdit->text().length() == 5 || saNumberEdit->text().length() == 6)
	{
		BusinessLayer::Account account;
		if (account.GetAccountByNumber(dialogBL->GetOrmasDal(), saNumberEdit->text().toUtf8().constData(), errorMessage))
		{
			saIDEdit->setText(QString::number(account.GetID()));
		}
		else
		{
			saIDEdit->setText("");
		}
	}
	else if (saNumberEdit->text().length() == 15)
	{
		BusinessLayer::Subaccount subaccount;
		if (subaccount.GetSubaccountByNumber(dialogBL->GetOrmasDal(), saNumberEdit->text().toUtf8().constData(), errorMessage))
		{
			saIDEdit->setText(QString::number(subaccount.GetID()));
		}
		else
		{
			saIDEdit->setText("");
		}
	}
	else
	{
		saIDEdit->setText("");
	}
}

void CreateWdwDlg::UserIsChanged()
{
	BusinessLayer::Balance balance;
	BusinessLayer::Subaccount suba;
	if (balance.GetBalanceByUserID(dialogBL->GetOrmasDal(), userEdit->text().toInt(), errorMessage))
	{
		if (suba.GetSubaccountByID(dialogBL->GetOrmasDal(), balance.GetSubaccountID(), errorMessage))
		{
			saIDEdit->setText(QString::number(suba.GetID()));
			saNumberEdit->setText(suba.GetNumber().c_str());
		}
	}
}

void CreateWdwDlg::SortTable(QTableView *table)
{
	BusinessLayer::Balance balance;
	BusinessLayer::Subaccount subAccount;
	BusinessLayer::EntryRouting entryRouting;
	for (int i = 0; i < table->model()->rowCount(); i++)
	{
		balance.Clear();
		subAccount.Clear();
		entryRouting.Clear();
		QModelIndex index = table->model()->index(i, 0);
		if (!balance.GetBalanceByUserID(dialogBL->GetOrmasDal(), index.data().toInt(), errorMessage))
			continue;
		if (!subAccount.GetSubaccountByID(dialogBL->GetOrmasDal(), balance.GetSubaccountID(), errorMessage))
			continue;
		
		if (!entryRouting.GetEntryRoutingByID(dialogBL->GetOrmasDal(), accountCmb->currentData().toInt(), errorMessage))
			continue;
		if (subAccount.GetParentAccountID() == entryRouting.GetDebitAccountID())
		{
			table->showRow(i);
		}
		else
		{
			table->hideRow(i);
		}
	}
	errorMessage = "";
}