#include "stdafx.h"
#include <QMessageBox>
#include "CreateWOffRDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"
#include <map>

CreateWOffRDlg::CreateWOffRDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	stockEmployeeEdit->setValidator(vInt);
	prodCountEdit->setValidator(vInt);
	statusEdit->setValidator(vInt);
	currencyEdit->setValidator(vInt);
	sumEdit->setValidator(vDouble);
	sumEdit->setMaxLength(17);
	dialogBL->StartTransaction(errorMessage);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateWOffRDlg::EditWriteOffRaw);
	}
	else
	{
		writeOffRaw->SetID(dialogBL->GenerateID());
		execDateWidget->setVisible(false);
		employeeEdit->setText("0");
		stockEmployeeEdit->setText("0");
		prodCountEdit->setText("0");
		statusEdit->setText("0");
		sumEdit->setText("0");
		currencyEdit->setText("0");
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateWOffRDlg::CreateWriteOffRaw);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateWOffRDlg::Close);
	QObject::connect(employeeBtn, &QPushButton::released, this, &CreateWOffRDlg::OpenEmpDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateWOffRDlg::OpenStsDlg);
	QObject::connect(stockEmployeeBtn, &QPushButton::released, this, &CreateWOffRDlg::OpenSkEmpDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreateWOffRDlg::OpenCurDlg);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateWOffRDlg::OpenWOffRListDlg);
	QObject::connect(statusEdit, &QLineEdit::textChanged, this, &CreateWOffRDlg::StatusWasChenged);
	QObject::connect(this, SIGNAL(CloseCreatedForms()), ((MainForm*)((DataForm*)parent)->GetParent()), SLOT(CloseChildsByName()));
}

CreateWOffRDlg::~CreateWOffRDlg()
{
	delete vDouble;
	delete vInt;
	emit CloseCreatedForms();
	dialogBL->CancelTransaction(errorMessage);
}

void CreateWOffRDlg::SetWriteOffRawParams(int wEmployeeID, QString wDate, int wStockEmployeeID, int wCount,
	double wSum, int wStatusID, int wCurrencyID, int id)
{
	writeOffRaw->SetEmployeeID(wEmployeeID);
	writeOffRaw->SetDate(wDate.toUtf8().constData());
	writeOffRaw->SetEmployeeID(wStockEmployeeID);
	writeOffRaw->SetCount(wCount);
	writeOffRaw->SetSum(wSum);
	writeOffRaw->SetStatusID(wStatusID);
	writeOffRaw->SetCurrencyID(wCurrencyID);
	writeOffRaw->SetID(id);
}

void CreateWOffRDlg::FillEditElements(int wEmployeeID, QString wDate, int wStockEmployeeID, int wCount,
	double wSum, int wStatusID, int wCurrencyID)
{
	employeeEdit->setText(QString::number(wEmployeeID));
	dateEdit->setDateTime(QDateTime::fromString(wDate, "yyyy.MM.dd hh:mm:ss"));
	stockEmployeeEdit->setText(QString::number(wStockEmployeeID));
	prodCountEdit->setText(QString::number(wCount));
	sumEdit->setText(QString::number(wSum));
	statusEdit->setText(QString::number(wStatusID));
	currencyEdit->setText(QString::number(wCurrencyID));
}

void CreateWOffRDlg::SetID(int ID, QString childName)
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

bool CreateWOffRDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetWriteOffRawParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 16)).toInt(),
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

void CreateWOffRDlg::CreateWriteOffRaw()
{
	errorMessage.clear();
	if (0 != stockEmployeeEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && 0 != currencyEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetWriteOffRawParams(employeeEdit->text().toInt(), dateEdit->text(), stockEmployeeEdit->text().toInt(), prodCountEdit->text().toInt(),
			sumEdit->text().toInt(), statusEdit->text().toInt(), currencyEdit->text().toInt(), writeOffRaw->GetID());

		if (dialogBL->CreateWriteOffRaw(writeOffRaw, errorMessage))
		{
			BusinessLayer::Status *status = new BusinessLayer::Status;
			if (!status->GetStatusByID(dialogBL->GetOrmasDal(), writeOffRaw->GetStatusID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete status;
				return;
			}
			QList<QStandardItem*> writeOffRawItem;
			writeOffRawItem << new QStandardItem(QString::number(writeOffRaw->GetID()))
				<< new QStandardItem(writeOffRaw->GetDate().c_str())
				<< new QStandardItem(status->GetCode().c_str())
				<< new QStandardItem(status->GetName().c_str());

			BusinessLayer::Employee *employee = new BusinessLayer::Employee();
			BusinessLayer::Employee *stockEmployee = new BusinessLayer::Employee();
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;

			if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), writeOffRaw->GetEmployeeID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), writeOffRaw->GetCurrencyID(), errorMessage))
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

			if (writeOffRaw->GetStockEmployeeID() > 0)
			{
				if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), writeOffRaw->GetStockEmployeeID(), errorMessage))
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

			if (0 != writeOffRaw->GetEmployeeID())
			{
				BusinessLayer::Position *ePosition = new BusinessLayer::Position();
				if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), writeOffRaw->GetEmployeeID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete ePosition;
					return;
				}
				writeOffRawItem << new QStandardItem(employee->GetName().c_str())
					<< new QStandardItem(employee->GetSurname().c_str())
					<< new QStandardItem(employee->GetPhone().c_str())
					<< new QStandardItem(ePosition->GetName().c_str());
			}
			else
			{
				writeOffRawItem << new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("");
			}
			if (0 != writeOffRaw->GetStockEmployeeID())
			{
				BusinessLayer::Position *sePosition = new BusinessLayer::Position();
				if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), writeOffRaw->GetStockEmployeeID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete sePosition;
					return;
				}
				writeOffRawItem << new QStandardItem(stockEmployee->GetName().c_str())
					<< new QStandardItem(stockEmployee->GetSurname().c_str())
					<< new QStandardItem(stockEmployee->GetPhone().c_str())
					<< new QStandardItem(sePosition->GetName().c_str());
			}
			else
			{
				writeOffRawItem << new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("");
			}

			writeOffRawItem << new QStandardItem(QString::number(writeOffRaw->GetCount()))
				<< new QStandardItem(QString::number(writeOffRaw->GetSum()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(QString::number(writeOffRaw->GetStockEmployeeID()))
				<< new QStandardItem(QString::number(writeOffRaw->GetEmployeeID()))
				<< new QStandardItem(QString::number(writeOffRaw->GetStatusID()))
				<< new QStandardItem(QString::number(writeOffRaw->GetCurrencyID()));

			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(writeOffRawItem);
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

void CreateWOffRDlg::EditWriteOffRaw()
{
	errorMessage.clear();
	if (0 != stockEmployeeEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && 0 != currencyEdit->text().toInt())
	{
		if (writeOffRaw->GetStockEmployeeID() != stockEmployeeEdit->text().toInt() || QString(writeOffRaw->GetDate().c_str()) != dateEdit->text() ||
			writeOffRaw->GetEmployeeID() != employeeEdit->text().toInt() || writeOffRaw->GetCount() != prodCountEdit->text().toInt() ||
			writeOffRaw->GetSum() != sumEdit->text().toInt()
			|| writeOffRaw->GetCurrencyID() != currencyEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetWriteOffRawParams(employeeEdit->text().toInt(), dateEdit->text(), stockEmployeeEdit->text().toInt(), prodCountEdit->text().toInt(),
				sumEdit->text().toInt(), statusEdit->text().toInt(), currencyEdit->text().toInt(), writeOffRaw->GetID());

			if (dialogBL->UpdateWriteOffRaw(writeOffRaw, errorMessage))
			{
				//updating WriteOffRaw data
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(writeOffRaw->GetDate().c_str());

				BusinessLayer::Employee *employee = new BusinessLayer::Employee();
				BusinessLayer::Employee *stockEmployee = new BusinessLayer::Employee();
				BusinessLayer::Currency *currency = new BusinessLayer::Currency();
				BusinessLayer::Status *status = new BusinessLayer::Status;

				if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), writeOffRaw->GetEmployeeID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), writeOffRaw->GetCurrencyID(), errorMessage)
					|| !status->GetStatusByID(dialogBL->GetOrmasDal(), writeOffRaw->GetStatusID(), errorMessage))
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
				if (writeOffRaw->GetStockEmployeeID() > 0)
				{
					if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), writeOffRaw->GetStockEmployeeID(), errorMessage))
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
				itemModel->item(mIndex.row(), 2)->setText(status->GetCode().c_str());
				itemModel->item(mIndex.row(), 3)->setText(status->GetName().c_str());
				if (writeOffRaw->GetEmployeeID() > 0)
				{
					BusinessLayer::Position *ePosition = new BusinessLayer::Position();
					if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), writeOffRaw->GetEmployeeID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete ePosition;
						return;
					}
					itemModel->item(mIndex.row(), 4)->setText(employee->GetName().c_str());
					itemModel->item(mIndex.row(), 5)->setText(employee->GetSurname().c_str());
					itemModel->item(mIndex.row(), 6)->setText(employee->GetPhone().c_str());
					itemModel->item(mIndex.row(), 7)->setText(ePosition->GetName().c_str());
				}
				else
				{
					itemModel->item(mIndex.row(), 4)->setText("");
					itemModel->item(mIndex.row(), 5)->setText("");
					itemModel->item(mIndex.row(), 6)->setText("");
					itemModel->item(mIndex.row(), 7)->setText("");
				}
				if (writeOffRaw->GetStockEmployeeID() > 0)
				{
					BusinessLayer::Position *sePosition = new BusinessLayer::Position();
					if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), writeOffRaw->GetStockEmployeeID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete sePosition;
						return;
					}
					itemModel->item(mIndex.row(), 8)->setText(stockEmployee->GetName().c_str());
					itemModel->item(mIndex.row(), 9)->setText(stockEmployee->GetSurname().c_str());
					itemModel->item(mIndex.row(), 10)->setText(stockEmployee->GetPhone().c_str());
					itemModel->item(mIndex.row(), 11)->setText(sePosition->GetName().c_str());
				}
				else
				{
					itemModel->item(mIndex.row(), 8)->setText("");
					itemModel->item(mIndex.row(), 9)->setText("");
					itemModel->item(mIndex.row(), 10)->setText("");
					itemModel->item(mIndex.row(), 11)->setText("");
				}

				itemModel->item(mIndex.row(), 12)->setText(QString::number(writeOffRaw->GetCount()));
				itemModel->item(mIndex.row(), 13)->setText(QString::number(writeOffRaw->GetSum()));
				itemModel->item(mIndex.row(), 14)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 15)->setText(QString::number(writeOffRaw->GetStockEmployeeID()));
				itemModel->item(mIndex.row(), 16)->setText(QString::number(writeOffRaw->GetEmployeeID()));
				itemModel->item(mIndex.row(), 17)->setText(QString::number(writeOffRaw->GetStatusID()));
				itemModel->item(mIndex.row(), 18)->setText(QString::number(writeOffRaw->GetCurrencyID()));

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

void CreateWOffRDlg::Close()
{
	dialogBL->CancelTransaction(errorMessage);
	this->close();
}

void CreateWOffRDlg::OpenEmpDlg()
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
		dForm->createWOffRDlg = this;
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

void CreateWOffRDlg::OpenSkEmpDlg()
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
		dForm->createWOffRDlg = this;
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

void CreateWOffRDlg::OpenStsDlg()
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
		dForm->createWOffRDlg = this;
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

void CreateWOffRDlg::OpenCurDlg()
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
		dForm->createWOffRDlg = this;
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

void CreateWOffRDlg::OpenWOffRListDlg()
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
	dForm->writeOffRawID = writeOffRaw->GetID();
	BusinessLayer::WriteOffRawList writeOffRawList;
	writeOffRawList.SetWriteOffRawID(writeOffRaw->GetID());
	std::string writeOffRawListFilter = writeOffRawList.GenerateFilter(dialogBL->GetOrmasDal());
	dForm->FillTable<BusinessLayer::WriteOffRawListView>(errorMessage, writeOffRawListFilter);
	if (errorMessage.empty())
	{
		dForm->createWOffRDlg = this;
		dForm->setObjectName("writeOffRawListForm");
		dForm->QtConnect<BusinessLayer::WriteOffRawListView>();
		QMdiSubWindow *writeOffRawWindow = new QMdiSubWindow;
		writeOffRawWindow->setWidget(dForm);
		writeOffRawWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(writeOffRawWindow);
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

void CreateWOffRDlg::StatusWasChenged()
{
	errorMessage = "";
	statusMap = BusinessLayer::Status::GetStatusesAsMap(dialogBL->GetOrmasDal(), errorMessage);
	if (statusEdit->text().toInt() == statusMap.find("EXECUTED")->second)
	{
		execDateWidget->setVisible(true);
	}
}