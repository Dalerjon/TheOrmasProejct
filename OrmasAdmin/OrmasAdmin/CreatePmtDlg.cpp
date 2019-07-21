#include "stdafx.h"
#include "CreatePmtDlg.h"
#include "DataForm.h"



CreatePmtDlg::CreatePmtDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
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
		QObject::connect(okBtn, &QPushButton::released, this, &CreatePmtDlg::EditPayment);
	}
	else
	{
		dateEdit->setDateTime(QDateTime::currentDateTime());

		BusinessLayer::Status *status = new BusinessLayer::Status();
		status->SetName("TO PAY");
		std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
		std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);
		delete status;
		if (statusVector.size() == 0)
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("Status are empty please contact with Admin")),
				QString(tr("Ok")));
			errorMessage.clear();
			return;
		}
		statusEdit->setText(QString::number(statusVector.at(0).GetID()));
		statusPh->setText(statusVector.at(0).GetName().c_str());

		QObject::connect(okBtn, &QPushButton::released, this, &CreatePmtDlg::CreatePayment);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreatePmtDlg::Close);
	QObject::connect(userBtn, &QPushButton::released, this, &CreatePmtDlg::OpenUserDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreatePmtDlg::OpenStatusDlg);
	QObject::connect(accBtn, &QPushButton::released, this, &CreatePmtDlg::OpenAccDlg);
	QObject::connect(accNumberEdit, &QLineEdit::textChanged, this, &CreatePmtDlg::AccTextChanged);
	QObject::connect(valueEdit, &QLineEdit::textChanged, this, &CreatePmtDlg::TextEditChanged);
	QObject::connect(accountCmb, &QComboBox::currentTextChanged, this, &CreatePmtDlg::AccountIsChenged);
	InitComboBox();
}

CreatePmtDlg::~CreatePmtDlg()
{
	delete vInt;
	delete vDouble;
}

void CreatePmtDlg::SetID(int ID, QString childName)
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
					accountCmb->setDisabled(true);
					accIDEdit->setText(QString::number(GetAccountIDFromCmb()));
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
			if (childName == QString("accountForm"))
			{
				accIDEdit->setText(QString::number(ID));
				BusinessLayer::Account account;
				if (account.GetAccountByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					accNumberEdit->setReadOnly(true);
					accNumberEdit->setText(account.GetNumber().c_str());
				}
				namePh->setText("");
				surnamePh->setText("");
				phonePh->setText("");
				userEdit->setText("");
			}
		}
	}
}

void CreatePmtDlg::SetPaymentParams(QString pDate, double pValue, QString pTarget, int pUserID, int pCurrencyID, int pStatusID, int accountID, int id)
{
	payment->SetDate(pDate.toUtf8().constData());
	payment->SetValue(pValue);
	payment->SetTarget(pTarget.toUtf8().constData());
	payment->SetUserID(pUserID);
	payment->SetCurrencyID(pCurrencyID);
	payment->SetStatusID(pStatusID);
	payment->SetAccountID(accountID);
	payment->SetID(id);
}

void CreatePmtDlg::FillEditElements(QString pDate, double pValue, QString pTarget, int pUserID, int pCurrencyID, int pStatusID, int pAccountID)
{
	accountCmb->setDisabled(true);
	dateEdit->setDateTime(QDateTime::fromString(pDate, "dd.MM.yyyy hh:mm"));
	valueEdit->setText(QString::number(pValue,'f',3));
	targetEdit->setText(pTarget);
	userEdit->setText(QString::number(pUserID));
	statusEdit->setText(QString::number(pStatusID));
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(pCurrencyID)));
	accIDEdit->setText(QString::number(pAccountID));
	BusinessLayer::User user;
	if (user.GetUserByID(dialogBL->GetOrmasDal(), pUserID, errorMessage))
	{
		namePh->setText(user.GetName().c_str());
		surnamePh->setText(user.GetSurname().c_str());
		phonePh->setText(user.GetPhone().c_str());
	}
	BusinessLayer::Status status;
	if (status.GetStatusByID(dialogBL->GetOrmasDal(), pStatusID, errorMessage))
	{
		statusPh->setText(status.GetName().c_str());
	}
	BusinessLayer::Account acc;
	if (acc.GetAccountByID(dialogBL->GetOrmasDal(), pAccountID, errorMessage))
	{
		accNumberEdit->setText(acc.GetNumber().c_str());
	}
}

bool CreatePmtDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetPaymentParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 5)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 7)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 10)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 11)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 12)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 13)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 5)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 7)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 10)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 11)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 12)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 13)).toInt());
		
		return CheckAccess();
	}
	else
	{
		return false;
	}
}

void CreatePmtDlg::CreatePayment()
{
	errorMessage.clear();
	if ( 0.0 != valueEdit->text().toDouble() && !currencyCmb->currentText().isEmpty()
		&& !dateEdit->text().isEmpty() && 0 != statusEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*) parentForm;
		SetPaymentParams(dateEdit->text(), valueEdit->text().toDouble(), targetEdit->text(), userEdit->text().toInt(), 
			currencyCmb->currentData().toInt(), statusEdit->text().toInt(), accIDEdit->text().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreatePayment(payment, errorMessage))
		{
			if (parentDataForm != nullptr)
			{
				if (!parentDataForm->IsClosed())
				{
					BusinessLayer::Currency *currency = new BusinessLayer::Currency;
					BusinessLayer::User *user = new BusinessLayer::User;
					BusinessLayer::Status *status = new BusinessLayer::Status;
					if (!currency->GetCurrencyByID(dialogBL->GetOrmasDal(), payment->GetCurrencyID(), errorMessage) ||
						!status->GetStatusByID(dialogBL->GetOrmasDal(), payment->GetStatusID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete currency;
						delete user;
						delete status;
						return;
					}
					if (userEdit->text().toInt() > 0)
					{
						if (!user->GetUserByID(dialogBL->GetOrmasDal(), payment->GetUserID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							delete currency;
							delete user;
							delete status;
							return;
						}
					}
					BusinessLayer::Account account;
					if (accIDEdit->text().toInt() > 0)
					{

						if (!account.GetAccountByID(dialogBL->GetOrmasDal(), payment->GetAccountID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							return;
						}
					}
					QList<QStandardItem*> paymentItem;
					paymentItem << new QStandardItem(QString::number(payment->GetID()))
						<< new QStandardItem(payment->GetDate().c_str());
					if (userEdit->text().toInt() > 0)
					{
						paymentItem << new QStandardItem(user->GetName().c_str())
							<< new QStandardItem(user->GetSurname().c_str())
							<< new QStandardItem(user->GetPhone().c_str());
					}
					else
					{
						paymentItem << new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("");
					}
					paymentItem << new QStandardItem(QString::number(payment->GetValue(), 'f', 3))
						<< new QStandardItem(currency->GetShortName().c_str())
						<< new QStandardItem(payment->GetTarget().c_str());
					if (accIDEdit->text().toInt() > 0)
					{
						paymentItem << new QStandardItem(account.GetNumber().c_str());
					}
					else
					{
						paymentItem << new QStandardItem("");
					}
					paymentItem << new QStandardItem(status->GetName().c_str())
						<< new QStandardItem(QString::number(payment->GetUserID()))
						<< new QStandardItem(QString::number(payment->GetCurrencyID()))
						<< new QStandardItem(QString::number(payment->GetStatusID()))
						<< new QStandardItem(QString::number(payment->GetAccountID()));
					QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
					itemModel->appendRow(paymentItem);
					delete currency;
					delete user;
					delete status;
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
			QString(tr("Please fill user, value, date and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreatePmtDlg::EditPayment()
{
	errorMessage.clear();
	if (0.0 != valueEdit->text().toDouble() && !currencyCmb->currentText().isEmpty()
		&& !dateEdit->text().isEmpty() && 0 != statusEdit->text().toInt())
	{
		if (QString(payment->GetDate().c_str()) != dateEdit->text()
			|| payment->GetValue() != valueEdit->text().toDouble() || payment->GetCurrencyID() != currencyCmb->currentData().toInt()
			|| payment->GetStatusID() != statusEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*) parentForm;
			SetPaymentParams(dateEdit->text(), valueEdit->text().toDouble(), targetEdit->text(), userEdit->text().toInt(),
				currencyCmb->currentData().toInt(), statusEdit->text().toInt(), accIDEdit->text().toInt(), payment->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdatePayment(payment, errorMessage))
			{
				if (parentDataForm != nullptr)
				{
					if (!parentDataForm->IsClosed())
					{
						BusinessLayer::Currency *currency = new BusinessLayer::Currency;
						BusinessLayer::User *user = new BusinessLayer::User;
						BusinessLayer::Status *status = new BusinessLayer::Status;
						if (!currency->GetCurrencyByID(dialogBL->GetOrmasDal(), payment->GetCurrencyID(), errorMessage) ||
							!status->GetStatusByID(dialogBL->GetOrmasDal(), payment->GetStatusID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							delete currency;
							delete user;
							delete status;
							return;
						}
						if (userEdit->text().toInt() > 0)
						{
							if (!user->GetUserByID(dialogBL->GetOrmasDal(), payment->GetUserID(), errorMessage))
							{
								dialogBL->CancelTransaction(errorMessage);
								QMessageBox::information(NULL, QString(tr("Warning")),
									QString(tr(errorMessage.c_str())),
									QString(tr("Ok")));
								errorMessage.clear();
								delete currency;
								delete user;
								delete status;
								return;
							}
						}
						BusinessLayer::Account account;
						if (accIDEdit->text().toInt() > 0)
						{

							if (!account.GetAccountByID(dialogBL->GetOrmasDal(), payment->GetAccountID(), errorMessage))
							{
								dialogBL->CancelTransaction(errorMessage);
								QMessageBox::information(NULL, QString(tr("Warning")),
									QString(tr(errorMessage.c_str())),
									QString(tr("Ok")));
								errorMessage.clear();
								return;
							}
						}
						QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
						QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
						itemModel->item(mIndex.row(), 1)->setText(payment->GetDate().c_str());
						if (userEdit->text().toInt() > 0)
						{
							itemModel->item(mIndex.row(), 2)->setText(user->GetName().c_str());
							itemModel->item(mIndex.row(), 3)->setText(user->GetSurname().c_str());
							itemModel->item(mIndex.row(), 4)->setText(user->GetPhone().c_str());
						}
						else
						{
							itemModel->item(mIndex.row(), 2)->setText("");
							itemModel->item(mIndex.row(), 3)->setText("");
							itemModel->item(mIndex.row(), 4)->setText("");
						}
						itemModel->item(mIndex.row(), 5)->setText(QString::number(payment->GetValue(),'f',3));
						itemModel->item(mIndex.row(), 6)->setText(currency->GetShortName().c_str());
						itemModel->item(mIndex.row(), 7)->setText(payment->GetTarget().c_str());
						if (accIDEdit->text().toInt() > 0)
						{
							itemModel->item(mIndex.row(), 8)->setText(account.GetNumber().c_str());
						}
						else
						{
							itemModel->item(mIndex.row(), 8)->setText("");
						}
						itemModel->item(mIndex.row(), 9)->setText(status->GetName().c_str());
						itemModel->item(mIndex.row(), 10)->setText(QString::number(payment->GetUserID()));
						itemModel->item(mIndex.row(), 11)->setText(QString::number(payment->GetCurrencyID()));
						itemModel->item(mIndex.row(), 12)->setText(QString::number(payment->GetStatusID()));
						itemModel->item(mIndex.row(), 13)->setText(QString::number(payment->GetAccountID()));
						emit itemModel->dataChanged(mIndex, mIndex);
						delete currency;
						delete user;
						delete status;
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
			QString(tr("Please fill user, value and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreatePmtDlg::Close()
{
	this->parentWidget()->close();
}

void CreatePmtDlg::OpenUserDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Users"));
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

void CreatePmtDlg::OpenStatusDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Status"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	dForm->FillTable<BusinessLayer::Status>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("statusForm");
		dForm->QtConnect<BusinessLayer::Status>();
		QMdiSubWindow *statusWindow = new QMdiSubWindow;
		statusWindow->setWidget(dForm);
		statusWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(statusWindow);
		statusWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
		QString message = tr("All statuses are shown");
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

void CreatePmtDlg::OpenAccDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Accounts"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	std::string filter = "";
	BusinessLayer::Account account;
	BusinessLayer::EntryRouting entryRouting;
	if (entryRouting.GetEntryRoutingByID(dialogBL->GetOrmasDal(), accountCmb->currentData().toInt(), errorMessage))
	{
		account.SetID(entryRouting.GetCreditAccountID());
		filter = account.GenerateFilter(dialogBL->GetOrmasDal());
	}
	dForm->FillTable<BusinessLayer::Account>(errorMessage, filter);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("accountForm");
		dForm->QtConnect<BusinessLayer::Account>();
		QMdiSubWindow *accountWindow = new QMdiSubWindow;
		accountWindow->setWidget(dForm);
		accountWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(accountWindow);
		accountWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		dForm->tableView->setColumnHidden(2, true);
		dForm->tableView->setColumnHidden(3, true);
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
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

void CreatePmtDlg::InitComboBox()
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
		entryRouting.SetDebitAccountID(account.GetID());
		std::string filter = entryRouting.GenerateFilter(dialogBL->GetOrmasDal());
		std::vector<BusinessLayer::EntryRouting> entRoutVec = dialogBL->GetAllDataForClass<BusinessLayer::EntryRouting>(errorMessage, filter);
		accountCmb->addItem(tr("All"), 0);
		if (!entRoutVec.empty())
		{
			for (unsigned int i = 0; i < entRoutVec.size(); i++)
			{
				account.Clear();
				if (!account.GetAccountByID(dialogBL->GetOrmasDal(), entRoutVec[i].GetCreditAccountID(), errorMessage))
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

int CreatePmtDlg::GetAccountIDFromCmb()
{
	BusinessLayer::Account account;
	BusinessLayer::EntryRouting entryRouting;
	if (entryRouting.GetEntryRoutingByID(dialogBL->GetOrmasDal(), accountCmb->currentData().toInt(), errorMessage))
	{
		return entryRouting.GetCreditAccountID();
	}
	else
	{
		return 0;
	}
}


void CreatePmtDlg::AccTextChanged()
{
	if (accNumberEdit->text().length() == 5)
	{
		BusinessLayer::Account account;
		if (account.GetAccountByNumber(dialogBL->GetOrmasDal(), accNumberEdit->text().toUtf8().constData(), errorMessage))
		{
			accIDEdit->setText(QString::number(account.GetID()));
		}
		else
		{
			accIDEdit->setText("");
		}
	}
}

void CreatePmtDlg::TextEditChanged()
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

void CreatePmtDlg::AccountIsChenged()
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

void CreatePmtDlg::SortTable(QTableView *table)
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
		balance.SetUserID(index.data().toInt());
		std::string filter = balance.GenerateFilter(dialogBL->GetOrmasDal());
		std::vector<BusinessLayer::BalanceView> balanceVector = dialogBL->GetAllDataForClass<BusinessLayer::BalanceView>(errorMessage, filter);
		if (0 < balanceVector.size())
		{
			if (!entryRouting.GetEntryRoutingByID(dialogBL->GetOrmasDal(), accountCmb->currentData().toInt(), errorMessage))
				continue;
			for each (auto item in balanceVector)
			{
				subAccount.Clear();
				if (!subAccount.GetSubaccountByID(dialogBL->GetOrmasDal(), item.GetSubaccountID(), errorMessage))
					continue;
				if (subAccount.GetParentAccountID() == entryRouting.GetCreditAccountID())
				{
					table->showRow(i);
					break;
				}
				else
				{
					table->hideRow(i);
				}
			}
		}
	}
	errorMessage = "";
}

bool CreatePmtDlg::CheckAccess()
{
	std::map<std::string, int> rolesMap = BusinessLayer::Role::GetRolesAsMap(dialogBL->GetOrmasDal(), errorMessage);
	if (0 == rolesMap.size())
		return false;
	BusinessLayer::Status *status = new BusinessLayer::Status;
	if (!status->GetStatusByID(dialogBL->GetOrmasDal(), payment->GetStatusID(), errorMessage))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr(errorMessage.c_str())),
			QString(tr("Ok")));
		errorMessage.clear();
		delete status;
		return false;
	}

	if (0 == status->GetName().compare("EXECUTED"))
	{
		if (mainForm->GetLoggedUser()->GetRoleID() == rolesMap.find("SUPERUSER")->second ||
			mainForm->GetLoggedUser()->GetRoleID() == rolesMap.find("CHIEF ACCOUNTANT")->second ||
			mainForm->GetLoggedUser()->GetRoleID() == rolesMap.find("ACCOUNTANT")->second)
		{
			return true;
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("This document have an \"EXECUTED\" status. The document with \"EXECUTED\" status cannot be changed!")),
				QString(tr("Ok")));
			errorMessage.clear();
			delete status;
			return false;
		}
	}

	if (0 == status->GetName().compare("ERROR"))
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("This document have an \"ERROR\" status. The document with \"ERROR\" status cannot be changed!")),
			QString(tr("Ok")));
		errorMessage.clear();
		delete status;
		return false;
	}

	return true;
}
