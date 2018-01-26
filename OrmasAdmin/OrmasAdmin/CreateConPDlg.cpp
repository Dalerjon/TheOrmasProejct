#include "stdafx.h"
#include <QMessageBox>
#include "CreateConPDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"
#include <map>

CreateConPDlg::CreateConPDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
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
		QObject::connect(okBtn, &QPushButton::released, this, &CreateConPDlg::EditConsumeProduct);
	}
	else
	{
		consumeProduct->SetID(dialogBL->GenerateID());
		execDateWidget->setVisible(false);
		execDateEdit->setDateTime(QDateTime());
		employeeEdit->setText("0");
		stockEmployeeEdit->setText("0");
		prodCountEdit->setText("0");
		statusEdit->setText("0");
		sumEdit->setText("0");
		currencyEdit->setText("0");
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateConPDlg::CreateConsumeProduct);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateConPDlg::Close);
	QObject::connect(employeeBtn, &QPushButton::released, this, &CreateConPDlg::OpenEmpDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateConPDlg::OpenStsDlg);
	QObject::connect(stockEmployeeBtn, &QPushButton::released, this, &CreateConPDlg::OpenSkEmpDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreateConPDlg::OpenCurDlg);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateConPDlg::OpenConPListDlg);
	QObject::connect(statusEdit, &QLineEdit::textChanged, this, &CreateConPDlg::StatusWasChenged);
	QObject::connect(this, SIGNAL(CloseCreatedForms()), ((MainForm*)((DataForm*)parent)->GetParent()), SLOT(CloseChildsByName()));
}

CreateConPDlg::~CreateConPDlg()
{
	delete vDouble;
	delete vInt;
	emit CloseCreatedForms();
	dialogBL->CancelTransaction(errorMessage);
}

void CreateConPDlg::SetConsumeProductParams(int cEmployeeID, QString cDate, QString cExecDate, int cStockEmployeeID, int cCount, 
												double cSum, int cStatusID, int cCurrencyID, int id)
{
	consumeProduct->SetEmployeeID(cEmployeeID);
	consumeProduct->SetDate(cDate.toUtf8().constData());
	consumeProduct->SetExecutionDate(cExecDate.toUtf8().constData());
	consumeProduct->SetEmployeeID(cStockEmployeeID);
	consumeProduct->SetCount(cCount);
	consumeProduct->SetSum(cSum);
	consumeProduct->SetStatusID(cStatusID);
	consumeProduct->SetCurrencyID(cCurrencyID);
	consumeProduct->SetID(id);
}

void CreateConPDlg::FillEditElements(int cEmployeeID, QString cDate, QString cExecDate, int cStockEmployeeID, int cCount, double cSum,
										int cStatusID, int cCurrencyID)
{
	employeeEdit->setText(QString::number(cEmployeeID));
	dateEdit->setDateTime(QDateTime::fromString(cDate, "yyyy.MM.dd hh:mm:ss"));
	execDateEdit->setDateTime(QDateTime::fromString(cExecDate, "yyyy.MM.dd hh:mm:ss"));
	stockEmployeeEdit->setText(QString::number(cStockEmployeeID));
	prodCountEdit->setText(QString::number(cCount));
	sumEdit->setText(QString::number(cSum));
	statusEdit->setText(QString::number(cStatusID));
	currencyEdit->setText(QString::number(cCurrencyID));
}

void CreateConPDlg::SetID(int ID, QString childName)
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

bool CreateConPDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetConsumeProductParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 17)).toInt(),
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

void CreateConPDlg::CreateConsumeProduct()
{
	errorMessage.clear();
	if (0 != stockEmployeeEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && 0 != currencyEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetConsumeProductParams(employeeEdit->text().toInt(), dateEdit->text(), execDateEdit->text(), stockEmployeeEdit->text().toInt(), prodCountEdit->text().toInt(),
			sumEdit->text().toInt(), statusEdit->text().toInt(), currencyEdit->text().toInt(), consumeProduct->GetID());

		if (dialogBL->CreateConsumeProduct(consumeProduct, errorMessage))
		{
			BusinessLayer::Status *status = new BusinessLayer::Status;
			if (!status->GetStatusByID(dialogBL->GetOrmasDal(), consumeProduct->GetStatusID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete status;
				return;
			}
			QList<QStandardItem*> consumeProductItem;
			consumeProductItem << new QStandardItem(QString::number(consumeProduct->GetID()))
				<< new QStandardItem(consumeProduct->GetDate().c_str())
				<< new QStandardItem(consumeProduct->GetExecutionDate().c_str())
				<< new QStandardItem(status->GetCode().c_str())
				<< new QStandardItem(status->GetName().c_str());

			BusinessLayer::Employee *employee = new BusinessLayer::Employee();
			BusinessLayer::Employee *stockEmployee = new BusinessLayer::Employee();
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;

			if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), consumeProduct->GetEmployeeID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), consumeProduct->GetCurrencyID(), errorMessage))
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

			if (consumeProduct->GetStockEmployeeID() > 0)
			{
				if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), consumeProduct->GetStockEmployeeID(), errorMessage))
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

			if (0 != consumeProduct->GetEmployeeID())
			{
				BusinessLayer::Position *ePosition = new BusinessLayer::Position();
				if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), consumeProduct->GetEmployeeID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete ePosition;
					return;
				}
				consumeProductItem << new QStandardItem(employee->GetName().c_str())
					<< new QStandardItem(employee->GetSurname().c_str())
					<< new QStandardItem(employee->GetPhone().c_str())
					<< new QStandardItem(ePosition->GetName().c_str());
			}
			else
			{
				consumeProductItem << new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("");
			}
			if (0 != consumeProduct->GetStockEmployeeID())
			{
				BusinessLayer::Position *sePosition = new BusinessLayer::Position();
				if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), consumeProduct->GetStockEmployeeID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete sePosition;
					return;
				}
				consumeProductItem << new QStandardItem(stockEmployee->GetName().c_str())
					<< new QStandardItem(stockEmployee->GetSurname().c_str())
					<< new QStandardItem(stockEmployee->GetPhone().c_str())
					<< new QStandardItem(sePosition->GetName().c_str());
			}
			else
			{
				consumeProductItem << new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("");
			}

			consumeProductItem << new QStandardItem(QString::number(consumeProduct->GetCount()))
				<< new QStandardItem(QString::number(consumeProduct->GetSum()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(QString::number(consumeProduct->GetStockEmployeeID()))
				<< new QStandardItem(QString::number(consumeProduct->GetEmployeeID()))
				<< new QStandardItem(QString::number(consumeProduct->GetStatusID()))
				<< new QStandardItem(QString::number(consumeProduct->GetCurrencyID()));

			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(consumeProductItem);
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

void CreateConPDlg::EditConsumeProduct()
{
	errorMessage.clear();
	if (0 != stockEmployeeEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && 0 != currencyEdit->text().toInt())
	{
		if (consumeProduct->GetStockEmployeeID() != stockEmployeeEdit->text().toInt() || QString(consumeProduct->GetDate().c_str()) != dateEdit->text() ||
			QString(consumeProduct->GetExecutionDate().c_str()) != execDateEdit->text() ||
			consumeProduct->GetEmployeeID() != employeeEdit->text().toInt() || consumeProduct->GetCount() != prodCountEdit->text().toInt() ||
			consumeProduct->GetSum() != sumEdit->text().toInt()
			|| consumeProduct->GetCurrencyID() != currencyEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetConsumeProductParams(employeeEdit->text().toInt(), dateEdit->text(), execDateEdit->text(), stockEmployeeEdit->text().toInt(), prodCountEdit->text().toInt(),
				sumEdit->text().toInt(), statusEdit->text().toInt(), currencyEdit->text().toInt(), consumeProduct->GetID());

			if (dialogBL->UpdateConsumeProduct(consumeProduct, errorMessage))
			{
				//updating ConsumeProduct data
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(consumeProduct->GetDate().c_str());
				itemModel->item(mIndex.row(), 2)->setText(consumeProduct->GetExecutionDate().c_str());


				BusinessLayer::Employee *employee = new BusinessLayer::Employee();
				BusinessLayer::Employee *stockEmployee = new BusinessLayer::Employee();
				BusinessLayer::Currency *currency = new BusinessLayer::Currency();
				BusinessLayer::Status *status = new BusinessLayer::Status;

				if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), consumeProduct->GetEmployeeID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), consumeProduct->GetCurrencyID(), errorMessage)
					|| !status->GetStatusByID(dialogBL->GetOrmasDal(), consumeProduct->GetStatusID(), errorMessage))
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
				if (consumeProduct->GetStockEmployeeID() > 0)
				{
					if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), consumeProduct->GetStockEmployeeID(), errorMessage))
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
				if (consumeProduct->GetEmployeeID() > 0)
				{
					BusinessLayer::Position *ePosition = new BusinessLayer::Position();
					if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), consumeProduct->GetEmployeeID(), errorMessage))
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
				if (consumeProduct->GetStockEmployeeID() > 0)
				{
					BusinessLayer::Position *sePosition = new BusinessLayer::Position();
					if (!stockEmployee->GetEmployeeByID(dialogBL->GetOrmasDal(), consumeProduct->GetStockEmployeeID(), errorMessage))
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

				itemModel->item(mIndex.row(), 13)->setText(QString::number(consumeProduct->GetCount()));
				itemModel->item(mIndex.row(), 14)->setText(QString::number(consumeProduct->GetSum()));
				itemModel->item(mIndex.row(), 15)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 16)->setText(QString::number(consumeProduct->GetStockEmployeeID()));
				itemModel->item(mIndex.row(), 17)->setText(QString::number(consumeProduct->GetEmployeeID()));
				itemModel->item(mIndex.row(), 18)->setText(QString::number(consumeProduct->GetStatusID()));
				itemModel->item(mIndex.row(), 19)->setText(QString::number(consumeProduct->GetCurrencyID()));

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

void CreateConPDlg::Close()
{
	dialogBL->CancelTransaction(errorMessage);
	this->close();
}

void CreateConPDlg::OpenEmpDlg()
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
		dForm->createConPDlg = this;
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

void CreateConPDlg::OpenSkEmpDlg()
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
		dForm->createConPDlg = this;
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

void CreateConPDlg::OpenStsDlg()
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
		dForm->createConPDlg = this;
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

void CreateConPDlg::OpenCurDlg()
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
		dForm->createConPDlg = this;
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

void CreateConPDlg::OpenConPListDlg()
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
	dForm->consumeProductID = consumeProduct->GetID();
	BusinessLayer::ConsumeProductList consumeProductList;
	consumeProductList.SetConsumeProductID(consumeProduct->GetID());
	std::string consumeProductListFilter = consumeProductList.GenerateFilter(dialogBL->GetOrmasDal());
	dForm->FillTable<BusinessLayer::ConsumeProductListView>(errorMessage, consumeProductListFilter);
	if (errorMessage.empty())
	{
		dForm->createConPDlg = this;
		dForm->setObjectName("consumeProductListForm");
		dForm->QtConnect<BusinessLayer::ConsumeProductListView>();
		QMdiSubWindow *consumeProductWindow = new QMdiSubWindow;
		consumeProductWindow->setWidget(dForm);
		consumeProductWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(consumeProductWindow);
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

void CreateConPDlg::StatusWasChenged()
{
	errorMessage = "";
	statusMap = BusinessLayer::Status::GetStatusesAsMap(dialogBL->GetOrmasDal(), errorMessage);
	if (statusEdit->text().toInt() == statusMap.find("EXECUTED")->second)
	{
		execDateWidget->setVisible(true);
		execDateEdit->setDateTime(QDateTime::currentDateTime());
	}
}

