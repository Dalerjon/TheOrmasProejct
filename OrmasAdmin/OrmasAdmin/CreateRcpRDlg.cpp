#include "stdafx.h"
#include <QMessageBox>
#include "CreateRcpRDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"
#include <map>

CreateRcpRDlg::CreateRcpRDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
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
	currencyEdit->setValidator(vInt);
	sumEdit->setValidator(vDouble);
	sumEdit->setMaxLength(17);
	dialogBL->StartTransaction(errorMessage);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateRcpRDlg::EditReceiptRaw);
	}
	else
	{
		receiptRaw->SetID(dialogBL->GenerateID());
		execDateWidget->setVisible(false);
		execDateEdit->setDateTime(QDateTime());
		employeeEdit->setText("0");
		stockEmployeeEdit->setText("0");
		prodCountEdit->setText("0");
		statusEdit->setText("0");
		sumEdit->setText("0");
		currencyEdit->setText("0");
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateRcpRDlg::CreateReceiptRaw);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateRcpRDlg::Close);
	QObject::connect(employeeBtn, &QPushButton::released, this, &CreateRcpRDlg::OpenEmpDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateRcpRDlg::OpenStsDlg);
	QObject::connect(stockEmployeeBtn, &QPushButton::released, this, &CreateRcpRDlg::OpenSkEmpDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreateRcpRDlg::OpenCurDlg);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateRcpRDlg::OpenRcpRListDlg);
	QObject::connect(statusEdit, &QLineEdit::textChanged, this, &CreateRcpRDlg::StatusWasChenged);
	QObject::connect(this, SIGNAL(CloseCreatedForms()), ((MainForm*)((DataForm*)parent)->GetParent()), SLOT(CloseChildsByName()));
}

CreateRcpRDlg::~CreateRcpRDlg()
{
	delete vDouble;
	delete vInt;
	emit CloseCreatedForms();
	dialogBL->CancelTransaction(errorMessage);
}

void CreateRcpRDlg::SetReceiptRawParams(int rEmployeeID, QString rDate, QString rExecDate, int rStockEmployeeID, int rCount,
	double rSum, int rStatusID, int rCurrencyID, int id)
{
	receiptRaw->SetEmployeeID(rEmployeeID);
	receiptRaw->SetDate(rDate.toUtf8().constData());
	receiptRaw->SetExecutionDate(rExecDate.toUtf8().constData());
	receiptRaw->SetEmployeeID(rStockEmployeeID);
	receiptRaw->SetCount(rCount);
	receiptRaw->SetSum(rSum);
	receiptRaw->SetStatusID(rStatusID);
	receiptRaw->SetCurrencyID(rCurrencyID);
	receiptRaw->SetID(id);
}

void CreateRcpRDlg::FillEditElements(int rEmployeeID, QString rDate, QString rExecDate, int rStockEmployeeID, int rCount,
	double rSum, int rStatusID, int rCurrencyID)
{
	employeeEdit->setText(QString::number(rEmployeeID));
	dateEdit->setDateTime(QDateTime::fromString(rDate, "yyyy.MM.dd hh:mm:ss"));
	execDateEdit->setDateTime(QDateTime::fromString(rExecDate, "yyyy.MM.dd hh:mm:ss"));
	stockEmployeeEdit->setText(QString::number(rStockEmployeeID));
	prodCountEdit->setText(QString::number(rCount));
	sumEdit->setText(QString::number(rSum));
	statusEdit->setText(QString::number(rStatusID));
	currencyEdit->setText(QString::number(rCurrencyID));
}

void CreateRcpRDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("clientForm"))
			{
				employeeEdit->setText(QString::number(ID));
			}
			if (childName == QString("statusForm"))
			{
				statusEdit->setText(QString::number(ID));
			}
			if (childName == QString("employeeForm"))
			{
				stockEmployeeEdit->setText(QString::number(ID));
			}
			if (childName == QString("currencyForm"))
			{
				currencyEdit->setText(QString::number(ID));
			}
		}
	}
}

bool CreateRcpRDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetReceiptRawParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 17)).toInt(),
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

void CreateRcpRDlg::CreateReceiptRaw()
{
	errorMessage.clear();
	if (0 != stockEmployeeEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && 0 != currencyEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetReceiptRawParams(employeeEdit->text().toInt(), dateEdit->text(), execDateEdit->text(), stockEmployeeEdit->text().toInt(), prodCountEdit->text().toInt(),
			sumEdit->text().toInt(), statusEdit->text().toInt(), currencyEdit->text().toInt(), receiptRaw->GetID());

		if (dialogBL->CreateReceiptRaw(receiptRaw, errorMessage))
		{
			BusinessLayer::Status *status = new BusinessLayer::Status;
			if (!status->GetStatusByID(dialogBL->GetOrmasDal(), receiptRaw->GetStatusID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete status;
				return;
			}
			QList<QStandardItem*> ReceiptRawItem;
			ReceiptRawItem << new QStandardItem(QString::number(receiptRaw->GetID()))
				<< new QStandardItem(receiptRaw->GetDate().c_str())
				<< new QStandardItem(receiptRaw->GetExecutionDate().c_str())
				<< new QStandardItem(status->GetCode().c_str())
				<< new QStandardItem(status->GetName().c_str());

			BusinessLayer::Employee *employee = new BusinessLayer::Employee();
			BusinessLayer::Employee *stockEmployee = new BusinessLayer::Employee();
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;

			if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), receiptRaw->GetEmployeeID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), receiptRaw->GetCurrencyID(), errorMessage))
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

			if (receiptRaw->GetStockEmployeeID() > 0)
			{
				if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), receiptRaw->GetStockEmployeeID(), errorMessage))
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

			if (0 != receiptRaw->GetEmployeeID())
			{
				BusinessLayer::Position *ePosition = new BusinessLayer::Position();
				if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), receiptRaw->GetEmployeeID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete ePosition;
					return;
				}
				ReceiptRawItem << new QStandardItem(employee->GetName().c_str())
					<< new QStandardItem(employee->GetSurname().c_str())
					<< new QStandardItem(employee->GetPhone().c_str())
					<< new QStandardItem(ePosition->GetName().c_str());
			}
			else
			{
				ReceiptRawItem << new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("");
			}
			if (0 != receiptRaw->GetStockEmployeeID())
			{
				BusinessLayer::Position *sePosition = new BusinessLayer::Position();
				if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), receiptRaw->GetStockEmployeeID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete sePosition;
					return;
				}
				ReceiptRawItem << new QStandardItem(stockEmployee->GetName().c_str())
					<< new QStandardItem(stockEmployee->GetSurname().c_str())
					<< new QStandardItem(stockEmployee->GetPhone().c_str())
					<< new QStandardItem(sePosition->GetName().c_str());
			}
			else
			{
				ReceiptRawItem << new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("");
			}

			ReceiptRawItem << new QStandardItem(QString::number(receiptRaw->GetCount()))
				<< new QStandardItem(QString::number(receiptRaw->GetSum()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(QString::number(receiptRaw->GetStockEmployeeID()))
				<< new QStandardItem(QString::number(receiptRaw->GetEmployeeID()))
				<< new QStandardItem(QString::number(receiptRaw->GetStatusID()))
				<< new QStandardItem(QString::number(receiptRaw->GetCurrencyID()));

			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(ReceiptRawItem);
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

void CreateRcpRDlg::EditReceiptRaw()
{
	errorMessage.clear();
	if (0 != stockEmployeeEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && 0 != currencyEdit->text().toInt())
	{
		if (receiptRaw->GetStockEmployeeID() != stockEmployeeEdit->text().toInt() || QString(receiptRaw->GetDate().c_str()) != dateEdit->text() ||
			QString(receiptRaw->GetExecutionDate().c_str()) != execDateEdit->text() ||
			receiptRaw->GetEmployeeID() != employeeEdit->text().toInt() || receiptRaw->GetCount() != prodCountEdit->text().toInt() ||
			receiptRaw->GetSum() != sumEdit->text().toInt()
			|| receiptRaw->GetCurrencyID() != currencyEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetReceiptRawParams(employeeEdit->text().toInt(), dateEdit->text(), execDateEdit->text(), stockEmployeeEdit->text().toInt(), prodCountEdit->text().toInt(),
				sumEdit->text().toInt(), statusEdit->text().toInt(), currencyEdit->text().toInt(), receiptRaw->GetID());

			if (dialogBL->UpdateReceiptRaw(receiptRaw, errorMessage))
			{
				//updating ReceiptRaw data
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(receiptRaw->GetDate().c_str());
				itemModel->item(mIndex.row(), 2)->setText(receiptRaw->GetExecutionDate().c_str());


				BusinessLayer::Employee *employee = new BusinessLayer::Employee();
				BusinessLayer::Employee *stockEmployee = new BusinessLayer::Employee();
				BusinessLayer::Currency *currency = new BusinessLayer::Currency();
				BusinessLayer::Status *status = new BusinessLayer::Status;

				if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), receiptRaw->GetEmployeeID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), receiptRaw->GetCurrencyID(), errorMessage)
					|| !status->GetStatusByID(dialogBL->GetOrmasDal(), receiptRaw->GetStatusID(), errorMessage))
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
				if (receiptRaw->GetStockEmployeeID() > 0)
				{
					if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), receiptRaw->GetStockEmployeeID(), errorMessage))
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
				if (receiptRaw->GetEmployeeID() > 0)
				{
					BusinessLayer::Position *ePosition = new BusinessLayer::Position();
					if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), receiptRaw->GetEmployeeID(), errorMessage))
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
				if (receiptRaw->GetStockEmployeeID() > 0)
				{
					BusinessLayer::Position *sePosition = new BusinessLayer::Position();
					if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), receiptRaw->GetStockEmployeeID(), errorMessage))
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

				itemModel->item(mIndex.row(), 13)->setText(QString::number(receiptRaw->GetCount()));
				itemModel->item(mIndex.row(), 14)->setText(QString::number(receiptRaw->GetSum()));
				itemModel->item(mIndex.row(), 15)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 16)->setText(QString::number(receiptRaw->GetStockEmployeeID()));
				itemModel->item(mIndex.row(), 17)->setText(QString::number(receiptRaw->GetEmployeeID()));
				itemModel->item(mIndex.row(), 18)->setText(QString::number(receiptRaw->GetStatusID()));
				itemModel->item(mIndex.row(), 19)->setText(QString::number(receiptRaw->GetCurrencyID()));

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

void CreateRcpRDlg::Close()
{
	dialogBL->CancelTransaction(errorMessage);
	this->close();
}

void CreateRcpRDlg::OpenEmpDlg()
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
		dForm->createRcpRDlg = this;
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

void CreateRcpRDlg::OpenSkEmpDlg()
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
		dForm->createRcpRDlg = this;
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

void CreateRcpRDlg::OpenStsDlg()
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
		dForm->createRcpRDlg = this;
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

void CreateRcpRDlg::OpenCurDlg()
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
		dForm->createRcpRDlg = this;
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

void CreateRcpRDlg::OpenRcpRListDlg()
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
	dForm->receiptRawID = receiptRaw->GetID();
	BusinessLayer::ReceiptRawList receiptRawList;
	receiptRawList.SetReceiptRawID(receiptRaw->GetID());
	std::string receiptRawListFilter = receiptRawList.GenerateFilter(dialogBL->GetOrmasDal());
	dForm->FillTable<BusinessLayer::ReceiptRawListView>(errorMessage, receiptRawListFilter);
	if (errorMessage.empty())
	{
		dForm->createRcpRDlg = this;
		dForm->setObjectName("receiptRawListForm");
		dForm->QtConnect<BusinessLayer::ReceiptRawListView>();
		QMdiSubWindow *ReceiptRawWindow = new QMdiSubWindow;
		ReceiptRawWindow->setWidget(dForm);
		ReceiptRawWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(ReceiptRawWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All receipt raws are shown");
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

void CreateRcpRDlg::StatusWasChenged()
{
	errorMessage = "";
	statusMap = BusinessLayer::Status::GetStatusesAsMap(dialogBL->GetOrmasDal(), errorMessage);
	if (statusEdit->text().toInt() == statusMap.find("EXECUTED")->second)
	{
		execDateWidget->setVisible(true);
		execDateEdit->setDateTime(QDateTime::currentDateTime());
	}
}