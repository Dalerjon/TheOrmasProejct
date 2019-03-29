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
		status->SetName("IN PROGRESS");
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
	QObject::connect(valueEdit, &QLineEdit::textChanged, this, &CreatePmtDlg::TextEditChanged);
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

			if (childName == QString("clientForm"))
			{
				userEdit->setText(QString::number(ID));
				BusinessLayer::User user;
				if (user.GetUserByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					namePh->setText(user.GetName().c_str());
					surnamePh->setText(user.GetSurname().c_str());
					phonePh->setText(user.GetPhone().c_str());
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

void CreatePmtDlg::SetPaymentParams(QString pDate, double pValue, int pUserID, int pCurrencyID, int pStatusID, int id)
{
	payment->SetDate(pDate.toUtf8().constData());
	payment->SetValue(pValue);
	payment->SetUserID(pUserID);
	payment->SetCurrencyID(pCurrencyID);
	payment->SetStatusID(pStatusID);
	payment->SetID(id);
}

void CreatePmtDlg::FillEditElements(QString pDate, double pValue, int pUserID, int pCurrencyID, int pStatusID)
{
	dateEdit->setDateTime(QDateTime::fromString(pDate, "dd.MM.yyyy hh:mm"));
	valueEdit->setText(QString::number(pValue,'f',3));
	userEdit->setText(QString::number(pUserID));
	statusEdit->setText(QString::number(pStatusID));
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(pCurrencyID)));
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
}

bool CreatePmtDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetPaymentParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 5)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 8)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 10)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 5)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 8)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 10)).toInt());
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
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("This document have an \"EXECUTED\" status. The document with \"EXECUTED\" status cannot be changed!")),
				QString(tr("Ok")));
			errorMessage.clear();
			delete status;
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

void CreatePmtDlg::CreatePayment()
{
	errorMessage.clear();
	if (0 != userEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && !currencyCmb->currentText().isEmpty()
		&& !dateEdit->text().isEmpty() && 0 != statusEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*) parentForm;
		SetPaymentParams(dateEdit->text(), valueEdit->text().toDouble(), userEdit->text().toInt(), currencyCmb->currentData().toInt(), statusEdit->text().toInt());
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
						!user->GetUserByID(dialogBL->GetOrmasDal(), payment->GetUserID(), errorMessage) ||
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
					QList<QStandardItem*> paymentItem;
					paymentItem << new QStandardItem(QString::number(payment->GetID()))
						<< new QStandardItem(payment->GetDate().c_str())
						<< new QStandardItem(user->GetName().c_str())
						<< new QStandardItem(user->GetSurname().c_str())
						<< new QStandardItem(user->GetPhone().c_str())
						<< new QStandardItem(QString::number(payment->GetValue(),'f',3))
						<< new QStandardItem(currency->GetShortName().c_str())
						<< new QStandardItem(status->GetName().c_str())
						<< new QStandardItem(QString::number(payment->GetUserID()))
						<< new QStandardItem(QString::number(payment->GetCurrencyID()))
						<< new QStandardItem(QString::number(payment->GetStatusID()));
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
	if (0 != userEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && !currencyCmb->currentText().isEmpty()
		&& !dateEdit->text().isEmpty() && 0 != statusEdit->text().toInt())
	{
		if (QString(payment->GetDate().c_str()) != dateEdit->text() || payment->GetUserID() != userEdit->text().toInt() 
			|| payment->GetValue() != valueEdit->text().toDouble() || payment->GetCurrencyID() != currencyCmb->currentData().toInt()
			|| payment->GetStatusID() != statusEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*) parentForm;
			SetPaymentParams(dateEdit->text(), valueEdit->text().toDouble(), userEdit->text().toInt(), currencyCmb->currentData().toInt(), statusEdit->text().toInt(), payment->GetID());
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
							!user->GetUserByID(dialogBL->GetOrmasDal(), payment->GetUserID(), errorMessage) ||
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
						QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
						QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
						itemModel->item(mIndex.row(), 1)->setText(payment->GetDate().c_str());
						itemModel->item(mIndex.row(), 2)->setText(user->GetName().c_str());
						itemModel->item(mIndex.row(), 3)->setText(user->GetSurname().c_str());
						itemModel->item(mIndex.row(), 4)->setText(user->GetPhone().c_str());
						itemModel->item(mIndex.row(), 5)->setText(QString::number(payment->GetValue(),'f',3));
						itemModel->item(mIndex.row(), 6)->setText(currency->GetShortName().c_str());
						itemModel->item(mIndex.row(), 7)->setText(status->GetName().c_str());
						itemModel->item(mIndex.row(), 8)->setText(QString::number(payment->GetUserID()));
						itemModel->item(mIndex.row(), 9)->setText(QString::number(payment->GetCurrencyID()));
						itemModel->item(mIndex.row(), 10)->setText(QString::number(payment->GetStatusID()));
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
	dForm->setWindowTitle(tr("Clients"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	BusinessLayer::Role *role = new BusinessLayer::Role();
	role->SetName("CLIENT");
	std::string roleFilter = dialogBL->GenerateFilter<BusinessLayer::Role>(role);
	std::vector<BusinessLayer::Role> roleVector = dialogBL->GetAllDataForClass<BusinessLayer::Role>(errorMessage, roleFilter);
	if (roleVector.size() == 0)
	{
		delete role;
		QString message = tr("Sorry could not define the role for this client!");
		mainForm->statusBar()->showMessage(message);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(message),
			QString(tr("Ok")));
		errorMessage = "";
		return;
	}
	BusinessLayer::Client *client = new BusinessLayer::Client();
	client->SetRoleID(roleVector.at(0).GetID());
	std::string clientFilter = dialogBL->GenerateFilter<BusinessLayer::Client>(client);
	std::vector<BusinessLayer::ClientView> clientVector = dialogBL->GetAllDataForClass<BusinessLayer::ClientView>(errorMessage, clientFilter);
	if (clientVector.size() == 0)
	{
		delete role;
		QString message = tr("Sorry could not find client!");
		mainForm->statusBar()->showMessage(message);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(message),
			QString(tr("Ok")));
		errorMessage = "";
		return;
	}

	dForm->FillTable<BusinessLayer::ClientView>(errorMessage, clientFilter);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("clientForm");
		dForm->QtConnect<BusinessLayer::ClientView>();
		QMdiSubWindow *clientWindow = new QMdiSubWindow;
		clientWindow->setWidget(dForm);
		clientWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(clientWindow);
		clientWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->HileSomeRow();
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
		QString message = tr("All clients are shown");
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
