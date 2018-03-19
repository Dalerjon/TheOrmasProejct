#include "stdafx.h"
#include <QMessageBox>
#include "CreateSplDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"
#include <map>

CreateSplDlg::CreateSplDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
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
		QObject::connect(okBtn, &QPushButton::released, this, &CreateSplDlg::EditSpoilage);
	}
	else
	{
		spoilage->SetID(dialogBL->GenerateID());
		employeeEdit->setText("0");
		prodCountEdit->setText("0");
		statusEdit->setText("0");
		sumEdit->setText("0");
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateSplDlg::CreateSpoilage);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateSplDlg::Close);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateSplDlg::OpenStsDlg);
	QObject::connect(employeeBtn, &QPushButton::released, this, &CreateSplDlg::OpenEmpDlg);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateSplDlg::OpenSplListDlg);
	QObject::connect(this, SIGNAL(CloseCreatedForms()), ((MainForm*)((DataForm*)parent)->GetParent()), SLOT(CloseChildsByName()));
	InitComboBox();
}

CreateSplDlg::~CreateSplDlg()
{
	delete vDouble;
	delete vInt;
	emit CloseCreatedForms();
	dialogBL->CancelTransaction(errorMessage);
}

void CreateSplDlg::SetSpoilageParams(QString sDate, int sEmployeeID, int sCount, double sSum, int sStatusID, int sCurrencyID, int id)
{
	spoilage->SetDate(sDate.toUtf8().constData());
	spoilage->SetEmployeeID(sEmployeeID);
	spoilage->SetCount(sCount);
	spoilage->SetSum(sSum);
	spoilage->SetStatusID(sStatusID);
	spoilage->SetCurrencyID(sCurrencyID);
	spoilage->SetID(id);
}

void CreateSplDlg::FillEditElements(QString sDate, int sEmployeeID, int sCount, double sSum, int sStatusID, int sCurrencyID)
{
	dateEdit->setDateTime(QDateTime::fromString(sDate, "yyyy.MM.dd hh:mm:ss"));
	employeeEdit->setText(QString::number(sEmployeeID));
	prodCountEdit->setText(QString::number(sCount));
	sumEdit->setText(QString::number(sSum));
	statusEdit->setText(QString::number(sStatusID));
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(sCurrencyID)));
	BusinessLayer::User user;
	if (user.GetUserByID(dialogBL->GetOrmasDal(), sEmployeeID, errorMessage))
	{
		empNamePh->setText(user.GetName().c_str());
		empSurnamePh->setText(user.GetSurname().c_str());
		empPhonePh->setText(user.GetPhone().c_str());
	}
	BusinessLayer::Status status;
	if (status.GetStatusByID(dialogBL->GetOrmasDal(), sStatusID, errorMessage))
	{
		statusPh->setText(status.GetName().c_str());
	}
}

void CreateSplDlg::SetID(int ID, QString childName)
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

bool CreateSplDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetSpoilageParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
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

void CreateSplDlg::CreateSpoilage()
{
	errorMessage.clear();
	if (!dateEdit->text().isEmpty() && 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && !currencyCmb->currentText().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetSpoilageParams(dateEdit->text(), employeeEdit->text().toInt(), prodCountEdit->text().toInt(),
			sumEdit->text().toInt(), statusEdit->text().toInt(), currencyCmb->currentData().toInt(), spoilage->GetID());

		if (dialogBL->CreateSpoilage(spoilage, errorMessage))
		{
			BusinessLayer::Status *status = new BusinessLayer::Status;
			if (!status->GetStatusByID(dialogBL->GetOrmasDal(), spoilage->GetStatusID(), errorMessage))
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
			if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), spoilage->GetEmployeeID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), spoilage->GetCurrencyID(), errorMessage))
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
			if (0 != spoilage->GetEmployeeID())
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


			QList<QStandardItem*> spoilageItem;
			spoilageItem << new QStandardItem(QString::number(spoilage->GetID()))
				<< new QStandardItem(QString::number(spoilage->GetCount()))
				<< new QStandardItem(QString::number(spoilage->GetSum()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(status->GetName().c_str());

			if (0 != spoilage->GetEmployeeID())
			{
				spoilageItem << new QStandardItem(employee->GetName().c_str())
					<< new QStandardItem(employee->GetSurname().c_str())
					<< new QStandardItem(employee->GetPhone().c_str())
					<< new QStandardItem(position->GetName().c_str());
			}
			else
			{
				spoilageItem << new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("")
					<< new QStandardItem("");
			}

			spoilageItem << new QStandardItem(QString::number(spoilage->GetEmployeeID()))
				<< new QStandardItem(QString::number(spoilage->GetStatusID()))
				<< new QStandardItem(QString::number(spoilage->GetCurrencyID()));

			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(spoilageItem);
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

void CreateSplDlg::EditSpoilage()
{
	errorMessage.clear();
	if (0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != statusEdit->text().toInt() && !currencyCmb->currentText().isEmpty())
	{
		if (QString(spoilage->GetDate().c_str()) != dateEdit->text() ||
			spoilage->GetEmployeeID() != employeeEdit->text().toInt() || spoilage->GetCount() != prodCountEdit->text().toInt() ||
			spoilage->GetSum() != sumEdit->text().toInt()
			|| spoilage->GetCurrencyID() != currencyCmb->currentData().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetSpoilageParams(dateEdit->text(), employeeEdit->text().toInt(), prodCountEdit->text().toInt(),
				sumEdit->text().toInt(), statusEdit->text().toInt(), currencyCmb->currentData().toInt(), spoilage->GetID());

			if (dialogBL->UpdateSpoilage(spoilage, errorMessage))
			{
				//updating Spoilage data
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(spoilage->GetDate().c_str());
				
				BusinessLayer::Employee *employee = new BusinessLayer::Employee();
				BusinessLayer::Currency *currency = new BusinessLayer::Currency();
				BusinessLayer::Status *status = new BusinessLayer::Status;
				BusinessLayer::Position *position = new BusinessLayer::Position;

				if (!currency->GetCurrencyByID(dialogBL->GetOrmasDal(), spoilage->GetCurrencyID(), errorMessage)
					|| !status->GetStatusByID(dialogBL->GetOrmasDal(), spoilage->GetStatusID(), errorMessage)
					|| !employee->GetEmployeeByID(dialogBL->GetOrmasDal(), spoilage->GetEmployeeID(), errorMessage))
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

				if (0 != spoilage->GetEmployeeID())
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

				itemModel->item(mIndex.row(), 2)->setText(QString::number(spoilage->GetCount()));
				itemModel->item(mIndex.row(), 3)->setText(QString::number(spoilage->GetSum()));
				itemModel->item(mIndex.row(), 4)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 5)->setText(status->GetName().c_str());
				if (spoilage->GetEmployeeID() > 0)
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

				
				
				itemModel->item(mIndex.row(), 10)->setText(QString::number(spoilage->GetEmployeeID()));
				itemModel->item(mIndex.row(), 11)->setText(QString::number(spoilage->GetStatusID()));
				itemModel->item(mIndex.row(), 12)->setText(QString::number(spoilage->GetCurrencyID()));

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

void CreateSplDlg::Close()
{
	dialogBL->CancelTransaction(errorMessage);
	this->close();
}


void CreateSplDlg::OpenEmpDlg()
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
		dForm->createSplDlg = this;
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

void CreateSplDlg::OpenStsDlg()
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
		dForm->createSplDlg = this;
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

void CreateSplDlg::OpenSplListDlg()
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
	dForm->spoilageID = spoilage->GetID();
	BusinessLayer::SpoilageList SpoilageList;
	SpoilageList.SetSpoilageID(spoilage->GetID());
	std::string SpoilageListFilter = SpoilageList.GenerateFilter(dialogBL->GetOrmasDal());
	dForm->FillTable<BusinessLayer::SpoilageListView>(errorMessage, SpoilageListFilter);
	if (errorMessage.empty())
	{
		dForm->createSplDlg = this;
		dForm->setObjectName("spoilageListForm");
		dForm->QtConnect<BusinessLayer::SpoilageListView>();
		QMdiSubWindow *SpoilageListWindow = new QMdiSubWindow;
		SpoilageListWindow->setWidget(dForm);
		SpoilageListWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(SpoilageListWindow);
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

void CreateSplDlg::InitComboBox()
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
