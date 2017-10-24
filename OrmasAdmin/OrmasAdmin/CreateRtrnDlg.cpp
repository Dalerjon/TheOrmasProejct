#include "stdafx.h"
#include <QMessageBox>
#include "CreateRtrnDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateRtrnDlg::CreateRtrnDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	ret->SetID(dialogBL->GenerateID());
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
		QObject::connect(okBtn, &QPushButton::released, this, &CreateRtrnDlg::EditReturn);
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
		QObject::connect(okBtn, &QPushButton::released, this, &CreateRtrnDlg::CreateReturn);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateRtrnDlg::Close);
	QObject::connect(clientBtn, &QPushButton::released, this, &CreateRtrnDlg::OpenCltDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateRtrnDlg::OpenStsDlg);
	QObject::connect(employeeBtn, &QPushButton::released, this, &CreateRtrnDlg::OpenEmpDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreateRtrnDlg::OpenCurDlg);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateRtrnDlg::OpenRtrnListDlg);
}

CreateRtrnDlg::~CreateRtrnDlg()
{
	delete vDouble;
	delete vInt;
}

void CreateRtrnDlg::SetReturnParams(int oClientID, QString oDate, int oEmployeeID, int oCount, double oSum, int oStatusID, int oCurrencyID)
{
	ret->SetClientID(oClientID);
	ret->SetDate(oDate.toUtf8().constData());
	ret->SetEmployeeID(oEmployeeID);
	ret->SetCount(oCount);
	ret->SetSum(oSum);
	ret->SetStatusID(oStatusID);
	ret->SetCurrencyID(oCurrencyID);
}

void CreateRtrnDlg::FillEditElements(int oClientID, QString oDate, int oemployeeID, int oCount, double oSum, int oStatusID, int oCurrencyID)
{
	clientEdit->setText(QString::number(oClientID));
	dateEdit->setDate(QDate::fromString(oDate, "yyyy-MM-dd"));
	employeeEdit->setText(QString::number(oemployeeID));
	prodCountEdit->setText(QString::number(oCount));
	sumEdit->setText(QString::number(oSum));
	statusEdit->setText(QString::number(oStatusID));
	currencyEdit->setText(QString::number(oCurrencyID));
}

void CreateRtrnDlg::SetID(int ID, QString childName)
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

bool CreateRtrnDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetReturnParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 14)).toString().toInt(),
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

void CreateRtrnDlg::CreateReturn()
{
	errorMessage.clear();
	if (0 != clientEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != currencyEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();

		BusinessLayer::Status *status = new BusinessLayer::Status();
		status->SetName("returned");
		std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
		std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);

		if (statusVector.size() > 0)
		{
			SetReturnParams(clientEdit->text().toInt(), dateEdit->text(), employeeEdit->text().toInt(), prodCountEdit->text().toInt(),
				sumEdit->text().toInt(), statusVector.at(0).GetID(), currencyEdit->text().toInt());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->CreateReturn(ret, errorMessage))
			{
				if (0 != statusVector.size())
				{
					QList<QStandardItem*> returnItem;
					returnItem << new QStandardItem(QString::number(ret->GetID()))
						<< new QStandardItem(ret->GetDate().c_str())
						<< new QStandardItem(statusVector.at(0).GetCode().c_str())
						<< new QStandardItem(statusVector.at(0).GetName().c_str());

					BusinessLayer::Client *client = new BusinessLayer::Client();
					BusinessLayer::Employee *employee = new BusinessLayer::Employee();


					BusinessLayer::Currency *currency = new BusinessLayer::Currency;
					if (!client->GetClientByID(dialogBL->GetOrmasDal(), ret->GetClientID(), errorMessage)
						|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), ret->GetCurrencyID(), errorMessage))
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

					if (ret->GetEmployeeID() > 0)
					{
						if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), ret->GetEmployeeID(), errorMessage))
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


					if (0 != ret->GetClientID())
					{
						returnItem << new QStandardItem(client->GetName().c_str())
							<< new QStandardItem(client->GetSurname().c_str())
							<< new QStandardItem(client->GetPhone().c_str())
							<< new QStandardItem(client->GetAddress().c_str())
							<< new QStandardItem(client->GetFirm().c_str());
					}
					else
					{
						returnItem << new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("");
					}
					if (0 != ret->GetEmployeeID())
					{
						returnItem << new QStandardItem(employee->GetName().c_str())
							<< new QStandardItem(employee->GetSurname().c_str())
							<< new QStandardItem(employee->GetPhone().c_str());
					}
					else
					{
						returnItem << new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("");
					}

					returnItem << new QStandardItem(QString::number(ret->GetCount()))
						<< new QStandardItem(QString::number(ret->GetSum()))
						<< new QStandardItem(currency->GetShortName().c_str())
						<< new QStandardItem(QString::number(ret->GetEmployeeID()))
						<< new QStandardItem(QString::number(ret->GetClientID()))
						<< new QStandardItem(QString::number(ret->GetStatusID()))
						<< new QStandardItem(QString::number(ret->GetCurrencyID()));

					QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
					itemModel->appendRow(returnItem);
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

void CreateRtrnDlg::EditReturn()
{
	errorMessage.clear();
	if (0 != clientEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != currencyEdit->text().toInt())
	{
		if (ret->GetClientID() != clientEdit->text().toInt() || QString(ret->GetDate().c_str()) != dateEdit->text() ||
			ret->GetEmployeeID() != employeeEdit->text().toInt() || ret->GetCount() != prodCountEdit->text().toInt() ||
			ret->GetSum() != sumEdit->text().toInt()
			|| ret->GetCurrencyID() != currencyEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			BusinessLayer::Status *status = new BusinessLayer::Status();
			status->SetName("edited");
			std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
			std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);

			if (statusVector.size() > 0)
			{
				SetReturnParams(clientEdit->text().toInt(), dateEdit->text(), employeeEdit->text().toInt(), prodCountEdit->text().toInt(),
					sumEdit->text().toInt(), statusVector.at(0).GetID(), currencyEdit->text().toInt());
				dialogBL->StartTransaction(errorMessage);
				if (dialogBL->UpdateReturn(ret, errorMessage))
				{
					//updating ret data
					QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
					QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
					itemModel->item(mIndex.row(), 1)->setText(ret->GetDate().c_str());

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
							QString(tr("This status does not valid, cannot create ret!")),
							QString(tr("Ok")));
						return;
					}

					BusinessLayer::Client *client = new BusinessLayer::Client();
					BusinessLayer::Employee *employee = new BusinessLayer::Employee();

					BusinessLayer::Currency *currency = new BusinessLayer::Currency();

					if (!client->GetClientByID(dialogBL->GetOrmasDal(), ret->GetClientID(), errorMessage)
						|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), ret->GetCurrencyID(), errorMessage))
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

					if (ret->GetEmployeeID() > 0)
					{
						if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), ret->GetEmployeeID(), errorMessage))
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
					if (ret->GetEmployeeID() > 0)
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

					itemModel->item(mIndex.row(), 12)->setText(QString::number(ret->GetCount()));
					itemModel->item(mIndex.row(), 13)->setText(QString::number(ret->GetSum()));
					itemModel->item(mIndex.row(), 14)->setText(currency->GetShortName().c_str());
					itemModel->item(mIndex.row(), 15)->setText(QString::number(ret->GetEmployeeID()));
					itemModel->item(mIndex.row(), 16)->setText(QString::number(ret->GetClientID()));
					itemModel->item(mIndex.row(), 17)->setText(QString::number(ret->GetStatusID()));
					itemModel->item(mIndex.row(), 18)->setText(QString::number(ret->GetCurrencyID()));

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

void CreateRtrnDlg::Close()
{
	this->close();
}

void CreateRtrnDlg::OpenCltDlg()
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
		dForm->createRtrnDlg = this;
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

void CreateRtrnDlg::OpenEmpDlg()
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
		dForm->createRtrnDlg = this;
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

void CreateRtrnDlg::OpenStsDlg()
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
		dForm->createRtrnDlg = this;
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

void CreateRtrnDlg::OpenCurDlg()
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
		dForm->createRtrnDlg = this;
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

void CreateRtrnDlg::OpenRtrnListDlg()
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
	BusinessLayer::ReturnList *ReturnList = new BusinessLayer::ReturnList();
	ReturnList->SetReturnID(ret->GetID());
	std::string ReturnListFilter = dialogBL->GenerateFilter<BusinessLayer::ReturnList>(ReturnList);
	dForm->FillTable<BusinessLayer::ReturnListView>(errorMessage, ReturnListFilter);
	if (errorMessage.empty())
	{
		dForm->createRtrnDlg = this;
		dForm->setObjectName("ReturnListForm");
		dForm->QtConnect<BusinessLayer::ReturnListView>();
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
		dForm->returnID = ret->GetID();
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