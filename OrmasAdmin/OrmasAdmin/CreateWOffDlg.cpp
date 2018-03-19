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
	dialogBL->StartTransaction(errorMessage);
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	clientEdit->setValidator(vInt);
	employeeEdit->setValidator(vInt);
	prodCountEdit->setValidator(vInt);
	clientEdit->setValidator(vInt);
	statusEdit->setValidator(vInt);
	sumEdit->setValidator(vDouble);
	sumEdit->setMaxLength(17);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateWOffDlg::EditWriteOff);
	}
	else
	{
		writeOff->SetID(dialogBL->GenerateID());
		clientEdit->setText("0");
		employeeEdit->setText("0");
		prodCountEdit->setText("0");
		clientEdit->setText("0");
		statusEdit->setText("0");
		sumEdit->setText("0");
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateWOffDlg::CreateWriteOff);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateWOffDlg::Close);
	QObject::connect(clientBtn, &QPushButton::released, this, &CreateWOffDlg::OpenCltDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateWOffDlg::OpenStsDlg);
	QObject::connect(employeeBtn, &QPushButton::released, this, &CreateWOffDlg::OpenEmpDlg);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateWOffDlg::OpenWOffListDlg);
	QObject::connect(this, SIGNAL(CloseCreatedForms()), ((MainForm*)((DataForm*)parent)->GetParent()), SLOT(CloseChildsByName()));
	InitComboBox();
}

CreateWOffDlg::~CreateWOffDlg()
{
	delete vDouble;
	delete vInt;
	emit CloseCreatedForms();
	dialogBL->CancelTransaction(errorMessage);
}

void CreateWOffDlg::SetWriteOffParams(int wClientID, QString wDate, int wEmployeeID, int wCount, double wSum, int wStatusID, int wCurrencyID, int id)
{
	writeOff->SetClientID(wClientID);
	writeOff->SetDate(wDate.toUtf8().constData());
	writeOff->SetEmployeeID(wEmployeeID);
	writeOff->SetCount(wCount);
	writeOff->SetSum(wSum);
	writeOff->SetStatusID(wStatusID);
	writeOff->SetCurrencyID(wCurrencyID);
	writeOff->SetID(id);
}

void CreateWOffDlg::FillEditElements(int wClientID, QString wDate, int wEmployeeID, int wCount, double wSum, int wStatusID, int wCurrencyID)
{
	clientEdit->setText(QString::number(wClientID));
	dateEdit->setDateTime(QDateTime::fromString(wDate, "yyyy.MM.dd hh:mm:ss"));
	employeeEdit->setText(QString::number(wEmployeeID));
	prodCountEdit->setText(QString::number(wCount));
	sumEdit->setText(QString::number(wSum));
	statusEdit->setText(QString::number(wStatusID));
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(wCurrencyID)));
	BusinessLayer::User employee;
	if (employee.GetUserByID(dialogBL->GetOrmasDal(), wEmployeeID, errorMessage))
	{
		empNamePh->setText(employee.GetName().c_str());
		empSurnamePh->setText(employee.GetSurname().c_str());
		empPhonePh->setText(employee.GetPhone().c_str());
	}
	BusinessLayer::User client;
	if (client.GetUserByID(dialogBL->GetOrmasDal(), wClientID, errorMessage))
	{
		clNamePh->setText(client.GetName().c_str());
		clSurnamePh->setText(client.GetSurname().c_str());
		clPhonePh->setText(client.GetPhone().c_str());
	}
	BusinessLayer::Status status;
	if (status.GetStatusByID(dialogBL->GetOrmasDal(), wStatusID, errorMessage))
	{
		statusPh->setText(status.GetName().c_str());
	}
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
				BusinessLayer::User client;
				if (client.GetUserByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					clNamePh->setText(client.GetName().c_str());
					clSurnamePh->setText(client.GetSurname().c_str());
					clPhonePh->setText(client.GetPhone().c_str());
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
			if (childName == QString("employeeForm"))
			{
				employeeEdit->setText(QString::number(ID));
				BusinessLayer::User employee;
				if (employee.GetUserByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					empNamePh->setText(employee.GetName().c_str());
					empSurnamePh->setText(employee.GetSurname().c_str());
					empPhonePh->setText(employee.GetPhone().c_str());
				}
			}
		}
	}
}

bool CreateWOffDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetWriteOffParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 16)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 15)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 12)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 13)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 17)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 18)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(cTable->model()->data(cTable->model()->index(mIndex.row(), 16)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 15)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 12)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 13)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 17)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 18)).toInt());
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
		&& 0 != statusEdit->text().toInt() && !currencyCmb->currentText().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();

		SetWriteOffParams(clientEdit->text().toInt(), dateEdit->text(), employeeEdit->text().toInt(), prodCountEdit->text().toInt(),
			sumEdit->text().toInt(), statusEdit->text().toInt(), currencyCmb->currentData().toInt(), writeOff->GetID());
		
		if (dialogBL->CreateWriteOff(writeOff, errorMessage))
		{
			QList<QStandardItem*> writeOffItem;
			writeOffItem << new QStandardItem(QString::number(writeOff->GetID()))
				<< new QStandardItem(writeOff->GetDate().c_str());
				
			BusinessLayer::Client *client = new BusinessLayer::Client();
			BusinessLayer::Employee *employee = new BusinessLayer::Employee();
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;
			BusinessLayer::Status *status = new BusinessLayer::Status;
			if (!client->GetClientByID(dialogBL->GetOrmasDal(), writeOff->GetClientID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), writeOff->GetCurrencyID(), errorMessage)
				|| !status->GetStatusByID(dialogBL->GetOrmasDal(), writeOff->GetStatusID(), errorMessage))
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

			writeOffItem << new QStandardItem(status->GetCode().c_str())
				<< new QStandardItem(status->GetName().c_str());


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

void CreateWOffDlg::EditWriteOff()
{
	errorMessage.clear();
	if (0 != clientEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && !currencyCmb->currentText().isEmpty())
	{
		if (writeOff->GetClientID() != clientEdit->text().toInt() || QString(writeOff->GetDate().c_str()) != dateEdit->text() ||
			writeOff->GetEmployeeID() != employeeEdit->text().toInt() || writeOff->GetCount() != prodCountEdit->text().toInt() ||
			writeOff->GetSum() != sumEdit->text().toInt() || writeOff->GetCurrencyID() != currencyCmb->currentData().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetWriteOffParams(clientEdit->text().toInt(), dateEdit->text(), employeeEdit->text().toInt(), prodCountEdit->text().toInt(),
				sumEdit->text().toInt(), statusEdit->text().toInt(), currencyCmb->currentData().toInt(), writeOff->GetID());

			if (dialogBL->UpdateWriteOff(writeOff, errorMessage))
			{
				//updating WriteOff data
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(writeOff->GetDate().c_str());

				BusinessLayer::Status *status = new BusinessLayer::Status();
				status->SetID(statusEdit->text().toInt());
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

void CreateWOffDlg::Close()
{
	dialogBL->CancelTransaction(errorMessage);
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
	dForm->writeOffID = writeOff->GetID();
	BusinessLayer::WriteOffList writeOffList;
	writeOffList.SetWriteOffID(writeOff->GetID());
	std::string writeOffListFilter = writeOffList.GenerateFilter(dialogBL->GetOrmasDal());
	dForm->FillTable<BusinessLayer::WriteOffListView>(errorMessage, writeOffListFilter);
	if (errorMessage.empty())
	{
		dForm->createWOffDlg = this;
		dForm->setObjectName("writeOffListForm");
		dForm->QtConnect<BusinessLayer::WriteOffListView>();
		QMdiSubWindow *writeOffListWindow = new QMdiSubWindow;
		writeOffListWindow->setWidget(dForm);
		writeOffListWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(writeOffListWindow);
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

void CreateWOffDlg::InitComboBox()
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
