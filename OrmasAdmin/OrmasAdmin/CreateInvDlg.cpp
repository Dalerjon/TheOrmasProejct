#include "stdafx.h"
#include <QMessageBox>
#include "CreateInvDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"
#include <map>

CreateInvDlg::CreateInvDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	employeeEdit->setValidator(vInt);
	stockEmployeeEdit->setValidator(vInt);
	prodCountEdit->setValidator(vInt);
	statusEdit->setValidator(vInt);
	sumEdit->setValidator(vDouble);
	sumEdit->setMaxLength(17);
	dialogBL->StartTransaction(errorMessage);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateInvDlg::EditInventorization);
	}
	else
	{
		inventorization->SetID(dialogBL->GenerateID());
		execDateWidget->setVisible(false);
		execDateEdit->setDateTime(QDateTime());
		employeeEdit->setText("0");
		stockEmployeeEdit->setText("0");
		prodCountEdit->setText("0");
		statusEdit->setText("0");
		sumEdit->setText("0");
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateInvDlg::CreateInventorization);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateInvDlg::Close);
	QObject::connect(employeeBtn, &QPushButton::released, this, &CreateInvDlg::OpenEmpDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateInvDlg::OpenStsDlg);
	QObject::connect(stockEmployeeBtn, &QPushButton::released, this, &CreateInvDlg::OpenSkEmpDlg);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateInvDlg::OpenInvListDlg);
	QObject::connect(statusEdit, &QLineEdit::textChanged, this, &CreateInvDlg::StatusWasChenged);
	QObject::connect(this, SIGNAL(CloseCreatedForms()), ((MainForm*)((DataForm*)parent)->GetParent()), SLOT(CloseChildsByName()));
	InitComboBox();
}

CreateInvDlg::~CreateInvDlg()
{
	delete vDouble;
	delete vInt;
	emit CloseCreatedForms();
	dialogBL->CancelTransaction(errorMessage);
}

void CreateInvDlg::SetInventorizationParams(int iEmployeeID, QString iDate, QString iExecDate, int iStockEmployeeID, int iCount,
	double iSum, int iStatusID, int iCurrencyID, int id)
{
	inventorization->SetEmployeeID(iEmployeeID);
	inventorization->SetDate(iDate.toUtf8().constData());
	inventorization->SetExecutionDate(iExecDate.toUtf8().constData());
	inventorization->SetEmployeeID(iStockEmployeeID);
	inventorization->SetCount(iCount);
	inventorization->SetSum(iSum);
	inventorization->SetStatusID(iStatusID);
	inventorization->SetCurrencyID(iCurrencyID);
	inventorization->SetID(id);
}

void CreateInvDlg::FillEditElements(int iEmployeeID, QString iDate, QString iExecDate, int iStockEmployeeID, int iCount,
	double iSum, int iStatusID, int iCurrencyID)
{
	employeeEdit->setText(QString::number(iEmployeeID));
	dateEdit->setDateTime(QDateTime::fromString(iDate, "yyyy.MM.dd hh:mm:ss"));
	execDateEdit->setDateTime(QDateTime::fromString(iExecDate, "yyyy.MM.dd hh:mm:ss"));
	stockEmployeeEdit->setText(QString::number(iStockEmployeeID));
	prodCountEdit->setText(QString::number(iCount));
	sumEdit->setText(QString::number(iSum));
	statusEdit->setText(QString::number(iStatusID));
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(iCurrencyID)));
	BusinessLayer::User user1;
	if (user1.GetUserByID(dialogBL->GetOrmasDal(), iEmployeeID, errorMessage))
	{
		empNamePh->setText(user1.GetName().c_str());
		empSurnamePh->setText(user1.GetSurname().c_str());
		empPhonePh->setText(user1.GetPhone().c_str());
	}
	BusinessLayer::User user2;
	if (user2.GetUserByID(dialogBL->GetOrmasDal(), iStockEmployeeID, errorMessage))
	{
		empStockNamePh->setText(user2.GetName().c_str());
		empStockSurnamePh->setText(user2.GetSurname().c_str());
		empStockPhonePh->setText(user2.GetPhone().c_str());
	}
	BusinessLayer::Status status;
	if (status.GetStatusByID(dialogBL->GetOrmasDal(), iStatusID, errorMessage))
	{
		statusPh->setText(status.GetName().c_str());
	}
}

void CreateInvDlg::SetID(int ID, QString childName)
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
					empNamePh->setText(user.GetName().c_str());
					empSurnamePh->setText(user.GetSurname().c_str());
					empPhonePh->setText(user.GetPhone().c_str());
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
			if (childName == QString("employeeStockForm"))
			{
				stockEmployeeEdit->setText(QString::number(ID));
				BusinessLayer::User user;
				if (user.GetUserByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					empStockNamePh->setText(user.GetName().c_str());
					empStockSurnamePh->setText(user.GetSurname().c_str());
					empStockPhonePh->setText(user.GetPhone().c_str());
				}
			}
		}
	}
}

bool CreateInvDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetInventorizationParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 17)).toInt(),
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

void CreateInvDlg::CreateInventorization()
{
	errorMessage.clear();
	if (0 != stockEmployeeEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && !currencyCmb->currentText().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetInventorizationParams(employeeEdit->text().toInt(), dateEdit->text(), execDateEdit->text(), stockEmployeeEdit->text().toInt(), prodCountEdit->text().toInt(),
			sumEdit->text().toInt(), statusEdit->text().toInt(), currencyCmb->currentData().toInt(), inventorization->GetID());

		if (dialogBL->CreateInventorization(inventorization, errorMessage))
		{
			BusinessLayer::Status *status = new BusinessLayer::Status;
			if (!status->GetStatusByID(dialogBL->GetOrmasDal(), inventorization->GetStatusID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete status;
				return;
			}
			QList<QStandardItem*> inventorizationItem;
			inventorizationItem << new QStandardItem(QString::number(inventorization->GetID()))
				<< new QStandardItem(inventorization->GetDate().c_str())
				<< new QStandardItem(inventorization->GetExecutionDate().c_str())
				<< new QStandardItem(status->GetCode().c_str())
				<< new QStandardItem(status->GetName().c_str());

			BusinessLayer::Employee *employee = new BusinessLayer::Employee();
			BusinessLayer::Employee *stockEmployee = new BusinessLayer::Employee();
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;

			if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), inventorization->GetEmployeeID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), inventorization->GetCurrencyID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete employee;
				delete currency;
				delete status;
				return;
			}

			if (inventorization->GetStockEmployeeID() > 0)
			{
				if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), inventorization->GetStockEmployeeID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete stockEmployee;
					return;
				}
			}

			if (0 != inventorization->GetEmployeeID())
			{
				BusinessLayer::Position *ePosition = new BusinessLayer::Position();
				if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), inventorization->GetEmployeeID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete ePosition;
					return;
				}
				inventorizationItem << new QStandardItem(employee->GetName().c_str())
					<< new QStandardItem(employee->GetSurname().c_str())
					<< new QStandardItem(employee->GetPhone().c_str())
					<< new QStandardItem(ePosition->GetName().c_str());
			}
			else
			{
				inventorizationItem << new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("");
			}
			if (0 != inventorization->GetStockEmployeeID())
			{
				BusinessLayer::Position *sePosition = new BusinessLayer::Position();
				if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), inventorization->GetStockEmployeeID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete sePosition;
					return;
				}
				inventorizationItem << new QStandardItem(stockEmployee->GetName().c_str())
					<< new QStandardItem(stockEmployee->GetSurname().c_str())
					<< new QStandardItem(stockEmployee->GetPhone().c_str())
					<< new QStandardItem(sePosition->GetName().c_str());
			}
			else
			{
				inventorizationItem << new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("");
			}

			inventorizationItem << new QStandardItem(QString::number(inventorization->GetCount()))
				<< new QStandardItem(QString::number(inventorization->GetSum()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(QString::number(inventorization->GetStockEmployeeID()))
				<< new QStandardItem(QString::number(inventorization->GetEmployeeID()))
				<< new QStandardItem(QString::number(inventorization->GetStatusID()))
				<< new QStandardItem(QString::number(inventorization->GetCurrencyID()));

			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(inventorizationItem);
			dialogBL->CommitTransaction(errorMessage);
			delete stockEmployee;
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

void CreateInvDlg::EditInventorization()
{
	errorMessage.clear();
	if (0 != stockEmployeeEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && !currencyCmb->currentText().isEmpty())
	{
		if (inventorization->GetStockEmployeeID() != stockEmployeeEdit->text().toInt() || QString(inventorization->GetDate().c_str()) != dateEdit->text() ||
			QString(inventorization->GetExecutionDate().c_str()) != execDateEdit->text() ||
			inventorization->GetEmployeeID() != employeeEdit->text().toInt() || inventorization->GetCount() != prodCountEdit->text().toInt() ||
			inventorization->GetSum() != sumEdit->text().toInt()
			|| inventorization->GetCurrencyID() != currencyCmb->currentData().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetInventorizationParams(employeeEdit->text().toInt(), dateEdit->text(), execDateEdit->text(), stockEmployeeEdit->text().toInt(), prodCountEdit->text().toInt(),
				sumEdit->text().toInt(), statusEdit->text().toInt(), currencyCmb->currentData().toInt(), inventorization->GetID());

			if (dialogBL->UpdateInventorization(inventorization, errorMessage))
			{
				//updating Inventorization data
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(inventorization->GetDate().c_str());
				itemModel->item(mIndex.row(), 2)->setText(inventorization->GetExecutionDate().c_str());


				BusinessLayer::Employee *employee = new BusinessLayer::Employee();
				BusinessLayer::Employee *stockEmployee = new BusinessLayer::Employee();
				BusinessLayer::Currency *currency = new BusinessLayer::Currency();
				BusinessLayer::Status *status = new BusinessLayer::Status;

				if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), inventorization->GetEmployeeID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), inventorization->GetCurrencyID(), errorMessage)
					|| !status->GetStatusByID(dialogBL->GetOrmasDal(), inventorization->GetStatusID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete stockEmployee;
					delete currency;
					delete employee;
					delete status;
					return;
				}
				if (inventorization->GetStockEmployeeID() > 0)
				{
					if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), inventorization->GetStockEmployeeID(), errorMessage))
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
				if (inventorization->GetEmployeeID() > 0)
				{
					BusinessLayer::Position *ePosition = new BusinessLayer::Position();
					if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), inventorization->GetEmployeeID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete ePosition;
						return;
					}
					itemModel->item(mIndex.row(), 5)->setText(employee->GetName().c_str());
					itemModel->item(mIndex.row(), 6)->setText(employee->GetSurname().c_str());
					itemModel->item(mIndex.row(), 7)->setText(employee->GetPhone().c_str());
					itemModel->item(mIndex.row(), 8)->setText(ePosition->GetName().c_str());
				}
				else
				{
					itemModel->item(mIndex.row(), 5)->setText("");
					itemModel->item(mIndex.row(), 6)->setText("");
					itemModel->item(mIndex.row(), 7)->setText("");
					itemModel->item(mIndex.row(), 8)->setText("");
				}
				if (inventorization->GetStockEmployeeID() > 0)
				{
					BusinessLayer::Position *sePosition = new BusinessLayer::Position();
					if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), inventorization->GetStockEmployeeID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete sePosition;
						return;
					}
					itemModel->item(mIndex.row(), 9)->setText(stockEmployee->GetName().c_str());
					itemModel->item(mIndex.row(), 10)->setText(stockEmployee->GetSurname().c_str());
					itemModel->item(mIndex.row(), 11)->setText(stockEmployee->GetPhone().c_str());
					itemModel->item(mIndex.row(), 12)->setText(sePosition->GetName().c_str());
				}
				else
				{
					itemModel->item(mIndex.row(), 9)->setText("");
					itemModel->item(mIndex.row(), 10)->setText("");
					itemModel->item(mIndex.row(), 11)->setText("");
					itemModel->item(mIndex.row(), 12)->setText("");
				}

				itemModel->item(mIndex.row(), 13)->setText(QString::number(inventorization->GetCount()));
				itemModel->item(mIndex.row(), 14)->setText(QString::number(inventorization->GetSum()));
				itemModel->item(mIndex.row(), 15)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 16)->setText(QString::number(inventorization->GetStockEmployeeID()));
				itemModel->item(mIndex.row(), 17)->setText(QString::number(inventorization->GetEmployeeID()));
				itemModel->item(mIndex.row(), 18)->setText(QString::number(inventorization->GetStatusID()));
				itemModel->item(mIndex.row(), 19)->setText(QString::number(inventorization->GetCurrencyID()));

				emit itemModel->dataChanged(mIndex, mIndex);

				dialogBL->CommitTransaction(errorMessage);

				delete employee;
				delete stockEmployee;
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

void CreateInvDlg::Close()
{
	dialogBL->CancelTransaction(errorMessage);
	this->close();
}

void CreateInvDlg::OpenEmpDlg()
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
		dForm->createInvDlg = this;
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

void CreateInvDlg::OpenSkEmpDlg()
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
	role->SetName("STOCK MANAGEER");
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
		dForm->createInvDlg = this;
		dForm->setObjectName("stockEmployeeForm");
		dForm->QtConnect<BusinessLayer::EmployeeView>();
		QMdiSubWindow *stockEmployeeWindow = new QMdiSubWindow;
		stockEmployeeWindow->setWidget(dForm);
		stockEmployeeWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(stockEmployeeWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All stock employees are shown");
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

void CreateInvDlg::OpenStsDlg()
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
		dForm->createInvDlg = this;
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


void CreateInvDlg::OpenInvListDlg()
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
	dForm->inventorizationID = inventorization->GetID();
	BusinessLayer::InventorizationList inventorizationList;
	inventorizationList.SetInventorizationID(inventorization->GetID());
	std::string inventorizationListFilter = inventorizationList.GenerateFilter(dialogBL->GetOrmasDal());
	dForm->FillTable<BusinessLayer::InventorizationListView>(errorMessage, inventorizationListFilter);
	if (errorMessage.empty())
	{
		dForm->createInvDlg = this;
		dForm->setObjectName("inventorizationListForm");
		dForm->QtConnect<BusinessLayer::InventorizationListView>();
		QMdiSubWindow *inventorizationWindow = new QMdiSubWindow;
		inventorizationWindow->setWidget(dForm);
		inventorizationWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(inventorizationWindow);
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

void CreateInvDlg::StatusWasChenged()
{
	errorMessage = "";
	statusMap = BusinessLayer::Status::GetStatusesAsMap(dialogBL->GetOrmasDal(), errorMessage);
	if (statusEdit->text().toInt() == statusMap.find("EXECUTED")->second)
	{
		execDateWidget->setVisible(true);
		execDateEdit->setDateTime(QDateTime::currentDateTime());
	}
}

void CreateInvDlg::InitComboBox()
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