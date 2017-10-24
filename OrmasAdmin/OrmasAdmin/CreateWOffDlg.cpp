#include "stdafx.h"
#include <QMessageBox>
#include "CreateWOffDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateWOffDlg::CreateWOffDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	writeOff->SetID(dialogBL->GenerateID());
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	clientEdit->setValidator(vInt);
	employeeEdit->setValidator(vInt);
	prodCountEdit->setValidator(vInt);
	clientEdit->setValidator(vInt);
	statusEdit->setValidator(vInt);
	currencyEdit->setValidator(vInt);
	sumEdit->setValidator(vDouble);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateWOffDlg::EditWriteOff);
	}
	else
	{
		clientEdit->setText("0");
		employeeEdit->setText("0");
		prodCountEdit->setText("0");
		clientEdit->setText("0");
		statusEdit->setText("0");
		sumEdit->setText("0");
		currencyEdit->setText("0");
		dateEdit->setDate(QDate::currentDate());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateWOffDlg::CreateWriteOff);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateWOffDlg::Close);
	QObject::connect(clientBtn, &QPushButton::released, this, &CreateWOffDlg::OpenCltDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateWOffDlg::OpenStsDlg);
	QObject::connect(employeeBtn, &QPushButton::released, this, &CreateWOffDlg::OpenEmpDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreateWOffDlg::OpenCurDlg);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateWOffDlg::OpenWOffListDlg);
}

CreateWOffDlg::~CreateWOffDlg()
{
	delete vDouble;
	delete vInt;
}

void CreateWOffDlg::SetWriteOffParams(int oClientID, QString oDate, int oEmployeeID, int oCount, double oSum, int oStatusID, int oCurrencyID)
{
	writeOff->SetClientID(oClientID);
	writeOff->SetDate(oDate.toUtf8().constData());
	writeOff->SetEmployeeID(oEmployeeID);
	writeOff->SetCount(oCount);
	writeOff->SetSum(oSum);
	writeOff->SetStatusID(oStatusID);
	writeOff->SetCurrencyID(oCurrencyID);
}

void CreateWOffDlg::FillEditElements(int oClientID, QString oDate, int oemployeeID, int oCount, double oSum, int oStatusID, int oCurrencyID)
{
	clientEdit->setText(QString::number(oClientID));
	dateEdit->setDate(QDate::fromString(oDate, "yyyy-MM-dd"));
	employeeEdit->setText(QString::number(oemployeeID));
	prodCountEdit->setText(QString::number(oCount));
	sumEdit->setText(QString::number(oSum));
	statusEdit->setText(QString::number(oStatusID));
	currencyEdit->setText(QString::number(oCurrencyID));
}

void CreateWOffDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("clientForm"))
			{
				clientEdit->setText(QString::number(ID));
			}
			if (childName == QString("statusForm"))
			{
				statusEdit->setText(QString::number(ID));
			}
			if (childName == QString("employeeForm"))
			{
				employeeEdit->setText(QString::number(ID));
			}
			if (childName == QString("currencyForm"))
			{
				currencyEdit->setText(QString::number(ID));
			}
		}
	}
}

bool CreateWOffDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetWriteOffParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 14)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 13)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 10)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 11)).toString().toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 15)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 16)).toString().toInt());
		FillEditElements(cTable->model()->data(cTable->model()->index(mIndex.row(), 14)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 13)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 10)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 11)).toString().toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 15)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 16)).toString().toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateWOffDlg::CreateWriteOff()
{
	errorMessage.clear();
	if (0 != clientEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != currencyEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();

		BusinessLayer::Status *status = new BusinessLayer::Status();
		status->SetName("WriteOffed");
		std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
		std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);

		if (statusVector.size() > 0)
		{
			SetWriteOffParams(clientEdit->text().toInt(), dateEdit->text(), employeeEdit->text().toInt(), prodCountEdit->text().toInt(),
				sumEdit->text().toInt(), statusVector.at(0).GetID(), currencyEdit->text().toInt());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->CreateWriteOff(writeOff, errorMessage))
			{
				if (0 != statusVector.size())
				{
					QList<QStandardItem*> writeOffItem;
					writeOffItem << new QStandardItem(QString::number(writeOff->GetID()))
						<< new QStandardItem(writeOff->GetDate().c_str())
						<< new QStandardItem(statusVector.at(0).GetCode().c_str())
						<< new QStandardItem(statusVector.at(0).GetName().c_str());

					BusinessLayer::Client *client = new BusinessLayer::Client();
					BusinessLayer::Employee *employee = new BusinessLayer::Employee();


					BusinessLayer::Currency *currency = new BusinessLayer::Currency;
					if (!client->GetClientByID(dialogBL->GetOrmasDal(), writeOff->GetClientID(), errorMessage)
						|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), writeOff->GetCurrencyID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete client;
						delete currency;
						delete status;
						return;
					}

					if (writeOff->GetEmployeeID() > 0)
					{
						if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), writeOff->GetEmployeeID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							delete employee;
							return;
						}
					}


					if (0 != writeOff->GetClientID())
					{
						writeOffItem << new QStandardItem(client->GetName().c_str())
							<< new QStandardItem(client->GetSurname().c_str())
							<< new QStandardItem(client->GetPhone().c_str())
							<< new QStandardItem(client->GetAddress().c_str())
							<< new QStandardItem(client->GetFirm().c_str());
					}
					else
					{
						writeOffItem << new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("");
					}
					if (0 != writeOff->GetEmployeeID())
					{
						writeOffItem << new QStandardItem(employee->GetName().c_str())
							<< new QStandardItem(employee->GetSurname().c_str())
							<< new QStandardItem(employee->GetPhone().c_str());
					}
					else
					{
						writeOffItem << new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("");
					}

					writeOffItem << new QStandardItem(QString::number(writeOff->GetCount()))
						<< new QStandardItem(QString::number(writeOff->GetSum()))
						<< new QStandardItem(currency->GetShortName().c_str())
						<< new QStandardItem(QString::number(writeOff->GetEmployeeID()))
						<< new QStandardItem(QString::number(writeOff->GetClientID()))
						<< new QStandardItem(QString::number(writeOff->GetStatusID()))
						<< new QStandardItem(QString::number(writeOff->GetCurrencyID()));

					QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
					itemModel->appendRow(writeOffItem);
					dialogBL->CommitTransaction(errorMessage);
					delete client;
					delete employee;
					delete currency;
				}
				else
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr("Cannot create this client! Role or location are wrong!")),
						QString(tr("Ok")));
					errorMessage.clear();
					delete status;
					return;
				}
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
			dialogBL->CancelTransaction(errorMessage);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("Please contact with Administrator, seems DB is not valid!")),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please recheck all fields, especially product list!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateWOffDlg::EditWriteOff()
{
	errorMessage.clear();
	if (0 != clientEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != currencyEdit->text().toInt())
	{
		if (writeOff->GetClientID() != clientEdit->text().toInt() || QString(writeOff->GetDate().c_str()) != dateEdit->text() ||
			writeOff->GetEmployeeID() != employeeEdit->text().toInt() || writeOff->GetCount() != prodCountEdit->text().toInt() ||
			writeOff->GetSum() != sumEdit->text().toInt()
			|| writeOff->GetCurrencyID() != currencyEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			BusinessLayer::Status *status = new BusinessLayer::Status();
			status->SetName("edited");
			std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
			std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);

			if (statusVector.size() > 0)
			{
				SetWriteOffParams(clientEdit->text().toInt(), dateEdit->text(), employeeEdit->text().toInt(), prodCountEdit->text().toInt(),
					sumEdit->text().toInt(), statusVector.at(0).GetID(), currencyEdit->text().toInt());
				dialogBL->StartTransaction(errorMessage);
				if (dialogBL->UpdateWriteOff(writeOff, errorMessage))
				{
					//updating WriteOff data
					QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
					QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
					itemModel->item(mIndex.row(), 1)->setText(writeOff->GetDate().c_str());

					BusinessLayer::Status *status = new BusinessLayer::Status();
					status->SetName(statusEdit->text().toUtf8().constData());
					std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
					std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);
					if (statusVector.size() > 0)
					{
						itemModel->item(mIndex.row(), 2)->setText(statusVector.at(0).GetCode().c_str());
						itemModel->item(mIndex.row(), 3)->setText(statusVector.at(0).GetName().c_str());
					}
					else
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr("This status does not valid, cannot create WriteOff!")),
							QString(tr("Ok")));
						return;
					}

					BusinessLayer::Client *client = new BusinessLayer::Client();
					BusinessLayer::Employee *employee = new BusinessLayer::Employee();

					BusinessLayer::Currency *currency = new BusinessLayer::Currency();

					if (!client->GetClientByID(dialogBL->GetOrmasDal(), writeOff->GetClientID(), errorMessage)
						|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), writeOff->GetCurrencyID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete employee;
						delete currency;
						delete client;
						delete status;
						return;
					}

					if (writeOff->GetEmployeeID() > 0)
					{
						if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), writeOff->GetEmployeeID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							delete employee;
							return;
						}
					}

					itemModel->item(mIndex.row(), 4)->setText(client->GetName().c_str());
					itemModel->item(mIndex.row(), 5)->setText(client->GetSurname().c_str());
					itemModel->item(mIndex.row(), 6)->setText(client->GetPhone().c_str());
					itemModel->item(mIndex.row(), 7)->setText(client->GetAddress().c_str());
					itemModel->item(mIndex.row(), 8)->setText(client->GetFirm().c_str());
					if (writeOff->GetEmployeeID() > 0)
					{
						itemModel->item(mIndex.row(), 9)->setText(employee->GetName().c_str());
						itemModel->item(mIndex.row(), 10)->setText(employee->GetSurname().c_str());
						itemModel->item(mIndex.row(), 11)->setText(employee->GetPhone().c_str());
					}
					else
					{
						itemModel->item(mIndex.row(), 9)->setText("");
						itemModel->item(mIndex.row(), 10)->setText("");
						itemModel->item(mIndex.row(), 11)->setText("");
					}

					itemModel->item(mIndex.row(), 12)->setText(QString::number(writeOff->GetCount()));
					itemModel->item(mIndex.row(), 13)->setText(QString::number(writeOff->GetSum()));
					itemModel->item(mIndex.row(), 14)->setText(currency->GetShortName().c_str());
					itemModel->item(mIndex.row(), 15)->setText(QString::number(writeOff->GetEmployeeID()));
					itemModel->item(mIndex.row(), 16)->setText(QString::number(writeOff->GetClientID()));
					itemModel->item(mIndex.row(), 17)->setText(QString::number(writeOff->GetStatusID()));
					itemModel->item(mIndex.row(), 18)->setText(QString::number(writeOff->GetCurrencyID()));

					emit itemModel->dataChanged(mIndex, mIndex);
					this->close();

					dialogBL->CommitTransaction(errorMessage);

					delete client;
					delete employee;
					delete currency;
					delete status;
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
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr("Please contact with Administrator, seems DB is not valid!")),
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
			QString(tr("Please recheck all fields, all of them must be filled!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateWOffDlg::Close()
{
	this->close();
}

void CreateWOffDlg::OpenCltDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Client"));
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
		dForm->createWOffDlg = this;
		dForm->setObjectName("clientForm");
		dForm->QtConnect<BusinessLayer::ClientView>();
		QMdiSubWindow *clientWindow = new QMdiSubWindow;
		clientWindow->setWidget(dForm);
		clientWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(clientWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
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

void CreateWOffDlg::OpenEmpDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Employee"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	BusinessLayer::Role *role = new BusinessLayer::Role();
	role->SetName("EXPEDITOR");
	std::string roleFilter = dialogBL->GenerateFilter<BusinessLayer::Role>(role);
	std::vector<BusinessLayer::Role> roleVector = dialogBL->GetAllDataForClass<BusinessLayer::Role>(errorMessage, roleFilter);

	if (roleVector.size() == 0)
	{
		delete role;
		QString message = tr("Sorry could not define the role for this employee!");
		mainForm->statusBar()->showMessage(message);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(message),
			QString(tr("Ok")));
		errorMessage = "";
		return;
	}

	BusinessLayer::Employee *employee = new BusinessLayer::Employee();
	employee->SetRoleID(roleVector.at(0).GetID());
	std::string employeeFilter = dialogBL->GenerateFilter<BusinessLayer::Employee>(employee);
	std::vector<BusinessLayer::EmployeeView> employeeVector = dialogBL->GetAllDataForClass<BusinessLayer::EmployeeView>(errorMessage, employeeFilter);
	if (employeeVector.size() == 0)
	{
		delete role;
		QString message = tr("Sorry could not find employee with \"expeditor\" role!");
		mainForm->statusBar()->showMessage(message);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(message),
			QString(tr("Ok")));
		errorMessage = "";
		return;
	}

	dForm->FillTable<BusinessLayer::EmployeeView>(errorMessage, employeeFilter);
	if (errorMessage.empty())
	{
		dForm->createWOffDlg = this;
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

void CreateWOffDlg::OpenStsDlg()
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
		dForm->createWOffDlg = this;
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

void CreateWOffDlg::OpenCurDlg()
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
		dForm->createWOffDlg = this;
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

void CreateWOffDlg::OpenWOffListDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Add product"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	BusinessLayer::WriteOffList *WriteOffList = new BusinessLayer::WriteOffList();
	WriteOffList->SetWriteOffID(writeOff->GetID());
	std::string WriteOffListFilter = dialogBL->GenerateFilter<BusinessLayer::WriteOffList>(WriteOffList);
	dForm->FillTable<BusinessLayer::WriteOffListView>(errorMessage, WriteOffListFilter);
	if (errorMessage.empty())
	{
		dForm->createWOffDlg = this;
		dForm->setObjectName("WriteOffListForm");
		dForm->QtConnect<BusinessLayer::WriteOffListView>();
		QMdiSubWindow *returnWindow = new QMdiSubWindow;
		returnWindow->setWidget(dForm);
		returnWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(returnWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All products are shown");
		mainForm->statusBar()->showMessage(message);
		dForm->writeOffID = writeOff->GetID();
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

