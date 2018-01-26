#include "stdafx.h"
#include <QMessageBox>
#include "CreateOrdDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"
#include <map>

CreateOrdDlg::CreateOrdDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	clientEdit->setValidator(vInt);
	employeeEdit->setValidator(vInt);
	prodCountEdit->setValidator(vInt);
	statusEdit->setValidator(vInt);
	currencyEdit->setValidator(vInt);
	sumEdit->setValidator(vDouble);
	sumEdit->setMaxLength(17);
	dialogBL->StartTransaction(errorMessage);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateOrdDlg::EditOrder);
	}
	else
	{
		order->SetID(dialogBL->GenerateID());
		execDateWidget->setVisible(false);
		execDateEdit->setDateTime(QDateTime());
		clientEdit->setText("0");
		employeeEdit->setText("0");
		prodCountEdit->setText("0");
		statusEdit->setText("0");
		sumEdit->setText("0");
		currencyEdit->setText("0");
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateOrdDlg::CreateOrder);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateOrdDlg::Close);
	QObject::connect(clientBtn, &QPushButton::released, this, &CreateOrdDlg::OpenCltDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateOrdDlg::OpenStsDlg);
	QObject::connect(employeeBtn, &QPushButton::released, this, &CreateOrdDlg::OpenEmpDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreateOrdDlg::OpenCurDlg);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateOrdDlg::OpenOrdListDlg);
	QObject::connect(statusEdit, &QLineEdit::textChanged, this, &CreateOrdDlg::StatusWasChenged);
	QObject::connect(this, SIGNAL(CloseCreatedForms()), ((MainForm*)((DataForm*)parent)->GetParent()), SLOT(CloseChildsByName()));
}

CreateOrdDlg::~CreateOrdDlg()
{
	delete vDouble;
	delete vInt;
	emit CloseCreatedForms();
	dialogBL->CancelTransaction(errorMessage);
}

void CreateOrdDlg::SetOrderParams(int oClientID, QString oDate, QString oExecDate, int oEmployeeID, int oCount, double oSum, int oStatusID, int oCurrencyID, int id)
{
	order->SetClientID(oClientID);
	order->SetDate(oDate.toUtf8().constData());
	order->SetExecutionDate(oExecDate.toUtf8().constData());
	order->SetEmployeeID(oEmployeeID);
	order->SetCount(oCount);
	order->SetSum(oSum);
	order->SetStatusID(oStatusID);
	order->SetCurrencyID(oCurrencyID);
	order->SetID(id);
}

void CreateOrdDlg::FillEditElements(int oClientID, QString oDate, QString oExecDate, int oEmployeeID, int oCount, double oSum, int oStatusID, int oCurrencyID)
{
	clientEdit->setText(QString::number(oClientID));
	dateEdit->setDateTime(QDateTime::fromString(oDate, "yyyy.MM.dd hh:mm:ss"));
	execDateEdit->setDateTime(QDateTime::fromString(oExecDate, "yyyy.MM.dd hh:mm:ss"));
	employeeEdit->setText(QString::number(oEmployeeID));
	prodCountEdit->setText(QString::number(oCount));
	sumEdit->setText(QString::number(oSum));
	statusEdit->setText(QString::number(oStatusID));
	currencyEdit->setText(QString::number(oCurrencyID));
}

void CreateOrdDlg::SetID(int ID, QString childName)
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

bool CreateOrdDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetOrderParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 17)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 16)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 13)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 14)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 18)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 19)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(cTable->model()->data(cTable->model()->index(mIndex.row(), 17)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 16)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 13)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 14)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 18)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 19)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateOrdDlg::CreateOrder()
{
	errorMessage.clear();
	if (0 != clientEdit->text().toInt()  && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && 0 != currencyEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetOrderParams(clientEdit->text().toInt(), dateEdit->text(), execDateEdit->text(), employeeEdit->text().toInt(), prodCountEdit->text().toInt(),
			sumEdit->text().toInt(), statusEdit->text().toInt(), currencyEdit->text().toInt(), order->GetID());
			
		if (dialogBL->CreateOrder(order, errorMessage))
		{
			BusinessLayer::Status *status = new BusinessLayer::Status;
			if (!status->GetStatusByID(dialogBL->GetOrmasDal(), order->GetStatusID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete status;
				return;
			}
			QList<QStandardItem*> orderItem;
			orderItem << new QStandardItem(QString::number(order->GetID()))
					<< new QStandardItem(order->GetDate().c_str())
					<< new QStandardItem(order->GetExecutionDate().c_str())
					<< new QStandardItem(status->GetCode().c_str())
					<< new QStandardItem(status->GetName().c_str());
			
			BusinessLayer::Client *client = new BusinessLayer::Client();
			BusinessLayer::Employee *employee = new BusinessLayer::Employee();
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;
			
			if (!client->GetClientByID(dialogBL->GetOrmasDal(), order->GetClientID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), order->GetCurrencyID(), errorMessage))
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

			if (order->GetEmployeeID() > 0)
			{
				if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), order->GetEmployeeID(), errorMessage))
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
			
			if (0 != order->GetClientID())
			{
				orderItem << new QStandardItem(client->GetName().c_str())
					<< new QStandardItem(client->GetSurname().c_str())
					<< new QStandardItem(client->GetPhone().c_str())
					<< new QStandardItem(client->GetAddress().c_str())
					<< new QStandardItem(client->GetFirm().c_str());
			}
			else
			{
				orderItem << new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("");
			}
			if (0 != order->GetEmployeeID())
			{
				orderItem << new QStandardItem(employee->GetName().c_str())
					<< new QStandardItem(employee->GetSurname().c_str())
					<< new QStandardItem(employee->GetPhone().c_str());
			}
			else
			{
				orderItem << new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("");
			}

			orderItem << new QStandardItem(QString::number(order->GetCount()))
				<< new QStandardItem(QString::number(order->GetSum()))
			    << new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(QString::number(order->GetEmployeeID()))
				<< new QStandardItem(QString::number(order->GetClientID()))
				<< new QStandardItem(QString::number(order->GetStatusID()))
				<< new QStandardItem(QString::number(order->GetCurrencyID()));
			
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(orderItem);
			dialogBL->CommitTransaction(errorMessage);
			delete client;
			delete employee;
			delete currency;
			delete status;
			this->close();
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

void CreateOrdDlg::EditOrder()
{
	errorMessage.clear();
	if (0 != clientEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && 0 != currencyEdit->text().toInt())
	{
		if (order->GetClientID() != clientEdit->text().toInt() || QString(order->GetDate().c_str()) != dateEdit->text() ||
			QString(order->GetExecutionDate().c_str()) != execDateEdit->text() ||
			order->GetEmployeeID() != employeeEdit->text().toInt() || order->GetCount() != prodCountEdit->text().toInt() ||
			 order->GetSum() != sumEdit->text().toInt()
			|| order->GetCurrencyID() != currencyEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetOrderParams(clientEdit->text().toInt(), dateEdit->text(), execDateEdit->text(), employeeEdit->text().toInt(), prodCountEdit->text().toInt(),
				sumEdit->text().toInt(), statusEdit->text().toInt(), currencyEdit->text().toInt(), order->GetID());
			
			if (dialogBL->UpdateOrder(order, errorMessage))
			{
				//updating order data
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(order->GetDate().c_str());
				itemModel->item(mIndex.row(), 2)->setText(order->GetExecutionDate().c_str());
				
							
				BusinessLayer::Client *client = new BusinessLayer::Client();
				BusinessLayer::Employee *employee = new BusinessLayer::Employee();
				BusinessLayer::Currency *currency = new BusinessLayer::Currency();
				BusinessLayer::Status *status = new BusinessLayer::Status;

				if (!client->GetClientByID(dialogBL->GetOrmasDal(),order->GetClientID(),errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), order->GetCurrencyID(), errorMessage)
					|| !status->GetStatusByID(dialogBL->GetOrmasDal(), order->GetStatusID(), errorMessage))
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
				if (order->GetEmployeeID() > 0)
				{
					if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), order->GetEmployeeID(), errorMessage))
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
				itemModel->item(mIndex.row(), 3)->setText(status->GetCode().c_str());
				itemModel->item(mIndex.row(), 4)->setText(status->GetName().c_str());
				itemModel->item(mIndex.row(), 5)->setText(client->GetName().c_str());
				itemModel->item(mIndex.row(), 6)->setText(client->GetSurname().c_str());
				itemModel->item(mIndex.row(), 7)->setText(client->GetPhone().c_str());
				itemModel->item(mIndex.row(), 8)->setText(client->GetAddress().c_str());
				itemModel->item(mIndex.row(), 9)->setText(client->GetFirm().c_str());
				if (order->GetEmployeeID() > 0)
				{
					itemModel->item(mIndex.row(), 10)->setText(employee->GetName().c_str());
					itemModel->item(mIndex.row(), 11)->setText(employee->GetSurname().c_str());
					itemModel->item(mIndex.row(), 12)->setText(employee->GetPhone().c_str());
				}
				else
				{
					itemModel->item(mIndex.row(), 10)->setText("");
					itemModel->item(mIndex.row(), 11)->setText("");
					itemModel->item(mIndex.row(), 12)->setText("");
				}
				
				itemModel->item(mIndex.row(), 13)->setText(QString::number(order->GetCount()));
				itemModel->item(mIndex.row(), 14)->setText(QString::number(order->GetSum()));
				itemModel->item(mIndex.row(), 15)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 16)->setText(QString::number(order->GetEmployeeID()));
				itemModel->item(mIndex.row(), 17)->setText(QString::number(order->GetClientID()));
				itemModel->item(mIndex.row(), 18)->setText(QString::number(order->GetStatusID()));
				itemModel->item(mIndex.row(), 19)->setText(QString::number(order->GetCurrencyID()));
				
				emit itemModel->dataChanged(mIndex, mIndex);
				
				dialogBL->CommitTransaction(errorMessage);
				
				delete client;
				delete employee;
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
			QString(tr("Please recheck all fields, all of them must be filled!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateOrdDlg::Close()
{
	dialogBL->CancelTransaction(errorMessage);
	this->close();
}

void CreateOrdDlg::OpenCltDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
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

	dForm->FillTable<BusinessLayer::ClientView>(errorMessage,clientFilter);
	if (errorMessage.empty())
	{
		dForm->createOrdDlg = this;
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

void CreateOrdDlg::OpenEmpDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Employees"));
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
		dForm->createOrdDlg = this;
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

void CreateOrdDlg::OpenStsDlg()
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
		dForm->createOrdDlg = this;
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

void CreateOrdDlg::OpenCurDlg()
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
		dForm->createOrdDlg = this;
		dForm->setObjectName("currencyForm");
		dForm->QtConnect<BusinessLayer::Currency>();
		QMdiSubWindow *currencyWindow = new QMdiSubWindow;
		currencyWindow->setWidget(dForm);
		currencyWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(currencyWindow);
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

void CreateOrdDlg::OpenOrdListDlg()
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
	dForm->orderID = order->GetID();
	BusinessLayer::OrderList orderList;
	orderList.SetOrderID(order->GetID());
	std::string orderListFilter = orderList.GenerateFilter(dialogBL->GetOrmasDal());
	dForm->FillTable<BusinessLayer::OrderListView>(errorMessage, orderListFilter);
	if (errorMessage.empty())
	{
		dForm->createOrdDlg = this;
		dForm->setObjectName("orderListForm");
		dForm->QtConnect<BusinessLayer::OrderListView>();
		QMdiSubWindow *orderListWindow = new QMdiSubWindow;
		orderListWindow->setWidget(dForm);
		orderListWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(orderListWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All products are shown");
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

void CreateOrdDlg::StatusWasChenged()
{
	errorMessage = "";
	statusMap = BusinessLayer::Status::GetStatusesAsMap(dialogBL->GetOrmasDal(), errorMessage);
	if (statusEdit->text().toInt() == statusMap.find("EXECUTED")->second)
	{
		execDateWidget->setVisible(true);
		execDateEdit->setDateTime(QDateTime::currentDateTime());
	}
}

