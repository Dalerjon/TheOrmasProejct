#include "stdafx.h"
#include <QMessageBox>
#include "CreatePPlanDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"
#include <map>

CreatePPlanDlg::CreatePPlanDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	employeeEdit->setValidator(vInt);
	prodCountEdit->setValidator(vInt);
	statusEdit->setValidator(vInt);
	sumEdit->setValidator(vDouble);
	sumEdit->setMaxLength(17);
	dialogBL->StartTransaction(errorMessage);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreatePPlanDlg::EditProductionPlan);
	}
	else
	{
		productionPlan->SetID(dialogBL->GenerateID());
		employeeEdit->setText("0");
		prodCountEdit->setText("0");
		statusEdit->setText("0");
		sumEdit->setText("0");
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreatePPlanDlg::CreateProductionPlan);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreatePPlanDlg::Close);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreatePPlanDlg::OpenStsDlg);
	QObject::connect(employeeBtn, &QPushButton::released, this, &CreatePPlanDlg::OpenEmpDlg);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreatePPlanDlg::OpenPPlanListDlg);
	QObject::connect(this, SIGNAL(CloseCreatedForms()), ((MainForm*)((DataForm*)parent)->GetParent()), SLOT(CloseChildsByName()));
	InitComboBox();
}

CreatePPlanDlg::~CreatePPlanDlg()
{
	delete vDouble;
	delete vInt;
	emit CloseCreatedForms();
	dialogBL->CancelTransaction(errorMessage);
}

void CreatePPlanDlg::SetProductionPlanParams(QString pDate, int pEmployeeID, int pCount, double pSum, int pStatusID, int pCurrencyID, int id)
{
	productionPlan->SetDate(pDate.toUtf8().constData());
	productionPlan->SetEmployeeID(pEmployeeID);
	productionPlan->SetCount(pCount);
	productionPlan->SetSum(pSum);
	productionPlan->SetStatusID(pStatusID);
	productionPlan->SetCurrencyID(pCurrencyID);
	productionPlan->SetID(id);
}

void CreatePPlanDlg::FillEditElements(QString pDate, int pEmployeeID, int pCount, double pSum, int pStatusID, int pCurrencyID)
{
	dateEdit->setDateTime(QDateTime::fromString(pDate, "yyyy.MM.dd hh:mm:ss"));
	employeeEdit->setText(QString::number(pEmployeeID));
	prodCountEdit->setText(QString::number(pCount));
	sumEdit->setText(QString::number(pSum));
	statusEdit->setText(QString::number(pStatusID));
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(pCurrencyID)));
	BusinessLayer::User user;
	if (user.GetUserByID(dialogBL->GetOrmasDal(), pEmployeeID, errorMessage))
	{
		empNamePh->setText(user.GetName().c_str());
		empSurnamePh->setText(user.GetSurname().c_str());
		empPhonePh->setText(user.GetPhone().c_str());
	}
	BusinessLayer::Status status;
	if (status.GetStatusByID(dialogBL->GetOrmasDal(), pStatusID, errorMessage))
	{
		statusPh->setText(status.GetName().c_str());
	}
}

void CreatePPlanDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
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
				BusinessLayer::User user;
				if (user.GetUserByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					empNamePh->setText(user.GetName().c_str());
					empSurnamePh->setText(user.GetSurname().c_str());
					empPhonePh->setText(user.GetPhone().c_str());
				}
			}
		}
	}
}

bool CreatePPlanDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetProductionPlanParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 10)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 2)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 3)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 11)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 12)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 10)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 2)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 3)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 11)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 12)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreatePPlanDlg::CreateProductionPlan()
{
	errorMessage.clear();
	if (!dateEdit->text().isEmpty() && 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && !currencyCmb->currentText().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetProductionPlanParams(dateEdit->text(), employeeEdit->text().toInt(), prodCountEdit->text().toInt(),
			sumEdit->text().toInt(), statusEdit->text().toInt(), currencyCmb->currentData().toInt(), productionPlan->GetID());

		if (dialogBL->CreateProductionPlan(productionPlan, errorMessage))
		{
			BusinessLayer::Status *status = new BusinessLayer::Status;
			if (!status->GetStatusByID(dialogBL->GetOrmasDal(), productionPlan->GetStatusID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete status;
				return;
			}
			BusinessLayer::Employee *employee = new BusinessLayer::Employee();
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;
			if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), productionPlan->GetEmployeeID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), productionPlan->GetCurrencyID(), errorMessage))
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

			BusinessLayer::Position *position = new BusinessLayer::Position;
			if (0 != productionPlan->GetEmployeeID())
			{
				if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), employee->GetPositionID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete employee;
					delete currency;
					delete status;
					delete position;
					return;
				}
			}


			QList<QStandardItem*> productionPlanItem;
			productionPlanItem << new QStandardItem(QString::number(productionPlan->GetID()))
				<< new QStandardItem(QString::number(productionPlan->GetCount()))
				<< new QStandardItem(QString::number(productionPlan->GetSum()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(status->GetName().c_str());

			if (0 != productionPlan->GetEmployeeID())
			{
				productionPlanItem << new QStandardItem(employee->GetName().c_str())
					<< new QStandardItem(employee->GetSurname().c_str())
					<< new QStandardItem(employee->GetPhone().c_str())
					<< new QStandardItem(position->GetName().c_str());
			}
			else
			{
				productionPlanItem << new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("");
			}

			productionPlanItem << new QStandardItem(QString::number(productionPlan->GetEmployeeID()))
				<< new QStandardItem(QString::number(productionPlan->GetStatusID()))
				<< new QStandardItem(QString::number(productionPlan->GetCurrencyID()));

			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(productionPlanItem);
			dialogBL->CommitTransaction(errorMessage);
			delete employee;
			delete currency;
			delete status;
			delete position;
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

void CreatePPlanDlg::EditProductionPlan()
{
	errorMessage.clear();
	if (0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && !currencyCmb->currentText().isEmpty())
	{
		if (QString(productionPlan->GetDate().c_str()) != dateEdit->text() ||
			productionPlan->GetEmployeeID() != employeeEdit->text().toInt() || productionPlan->GetCount() != prodCountEdit->text().toInt() ||
			productionPlan->GetSum() != sumEdit->text().toInt()
			|| productionPlan->GetCurrencyID() != currencyCmb->currentData().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetProductionPlanParams(dateEdit->text(), employeeEdit->text().toInt(), prodCountEdit->text().toInt(),
				sumEdit->text().toInt(), statusEdit->text().toInt(), currencyCmb->currentData().toInt(), productionPlan->GetID());

			if (dialogBL->UpdateProductionPlan(productionPlan, errorMessage))
			{
				//updating ProductionPlan data
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(productionPlan->GetDate().c_str());

				BusinessLayer::Employee *employee = new BusinessLayer::Employee();
				BusinessLayer::Currency *currency = new BusinessLayer::Currency();
				BusinessLayer::Status *status = new BusinessLayer::Status;
				BusinessLayer::Position *position = new BusinessLayer::Position;

				if (!currency->GetCurrencyByID(dialogBL->GetOrmasDal(), productionPlan->GetCurrencyID(), errorMessage)
					|| !status->GetStatusByID(dialogBL->GetOrmasDal(), productionPlan->GetStatusID(), errorMessage)
					|| !employee->GetEmployeeByID(dialogBL->GetOrmasDal(), productionPlan->GetEmployeeID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete employee;
					delete currency;
					delete status;
					delete position;
					return;
				}

				if (0 != productionPlan->GetEmployeeID())
				{
					if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), employee->GetPositionID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete employee;
						delete currency;
						delete status;
						delete position;
						return;
					}
				}

				itemModel->item(mIndex.row(), 2)->setText(QString::number(productionPlan->GetCount()));
				itemModel->item(mIndex.row(), 3)->setText(QString::number(productionPlan->GetSum()));
				itemModel->item(mIndex.row(), 4)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 5)->setText(status->GetName().c_str());
				if (productionPlan->GetEmployeeID() > 0)
				{
					itemModel->item(mIndex.row(), 6)->setText(employee->GetName().c_str());
					itemModel->item(mIndex.row(), 7)->setText(employee->GetSurname().c_str());
					itemModel->item(mIndex.row(), 8)->setText(employee->GetPhone().c_str());
					itemModel->item(mIndex.row(), 9)->setText(position->GetName().c_str());
				}
				else
				{
					itemModel->item(mIndex.row(), 6)->setText("");
					itemModel->item(mIndex.row(), 7)->setText("");
					itemModel->item(mIndex.row(), 8)->setText("");
					itemModel->item(mIndex.row(), 9)->setText("");
				}



				itemModel->item(mIndex.row(), 10)->setText(QString::number(productionPlan->GetEmployeeID()));
				itemModel->item(mIndex.row(), 11)->setText(QString::number(productionPlan->GetStatusID()));
				itemModel->item(mIndex.row(), 12)->setText(QString::number(productionPlan->GetCurrencyID()));

				emit itemModel->dataChanged(mIndex, mIndex);

				dialogBL->CommitTransaction(errorMessage);

				delete position;
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

void CreatePPlanDlg::Close()
{
	dialogBL->CancelTransaction(errorMessage);
	this->close();
}


void CreatePPlanDlg::OpenEmpDlg()
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
	role->SetName("PRODUCT MANAGER");
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
		QString message = tr("Sorry could not find employee with \"PRODUCT MANAGER\" role!");
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
		dForm->createPPlanDlg = this;
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
		QString message = tr("All employees are shown");
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

void CreatePPlanDlg::OpenStsDlg()
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
		dForm->createPPlanDlg = this;
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

void CreatePPlanDlg::OpenPPlanListDlg()
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
	dForm->productionPlanID = productionPlan->GetID();
	BusinessLayer::ProductionPlanList ProductionPlanList;
	ProductionPlanList.SetProductionPlanID(productionPlan->GetID());
	std::string ProductionPlanListFilter = ProductionPlanList.GenerateFilter(dialogBL->GetOrmasDal());
	dForm->FillTable<BusinessLayer::ProductionPlanListView>(errorMessage, ProductionPlanListFilter);
	if (errorMessage.empty())
	{
		dForm->createPPlanDlg = this;
		dForm->setObjectName("productionPlanListForm");
		dForm->QtConnect<BusinessLayer::ProductionPlanListView>();
		QMdiSubWindow *ProductionPlanListWindow = new QMdiSubWindow;
		ProductionPlanListWindow->setWidget(dForm);
		ProductionPlanListWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(ProductionPlanListWindow);
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

void CreatePPlanDlg::InitComboBox()
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
