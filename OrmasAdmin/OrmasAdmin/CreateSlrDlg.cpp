#include "stdafx.h"
#include "CreateSlrDlg.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"


CreateSlrDlg::CreateSlrDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	bonusCmb->addItem("false");
	bonusCmb->addItem("true");
	employeeEdit->setValidator(vInt);
	valueEdit->setValidator(vDouble);
	valueEdit->setMaxLength(17);
	currencyEdit->setValidator(vInt);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateSlrDlg::EditSalary);
	}
	else
	{
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateSlrDlg::CreateSalary);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateSlrDlg::Close);
	QObject::connect(employeeBtn, &QPushButton::released, this, &CreateSlrDlg::OpenEmpDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreateSlrDlg::OpenCurDlg);
	QObject::connect(slrTypeBtn, &QPushButton::released, this, &CreateSlrDlg::OpenSlrTypeDlg);
}

CreateSlrDlg::~CreateSlrDlg()
{
	delete vDouble;
	delete vInt;
}


void CreateSlrDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("employeeForm"))
			{
				employeeEdit->setText(QString::number(ID));
			}
			if (childName == QString("currencyForm"))
			{
				currencyEdit->setText(QString::number(ID));
			}
			if (childName == QString("slrTypeForm"))
			{
				salaryTypeEdit->setText(QString::number(ID));
			}
		}
	}
}

void CreateSlrDlg::SetSalaryParams(int sEmployeeID, double sValue, int sCurrencyID, int sSalaryTypeID, QString sDate, QString sBonus, int id)
{
	salary->SetEmployeeID(sEmployeeID);
	salary->SetValue(sValue);
	salary->SetCurrencyID(sCurrencyID);
	salary->SetSalaryTypeID(sSalaryTypeID);
	salary->SetDate(sDate.toUtf8().constData());
	salary->SetIsBonus(sBonus == "true" ? true : false);
	salary->SetID(id);
}

void CreateSlrDlg::FillEditElements(int sEmployeeID, double sValue, int sCurrencyID, int sSalaryTypeID, QString sDate, QString sBonus)
{
	employeeEdit->setText(QString::number(sEmployeeID));
	valueEdit->setText(QString::number(sValue));
	currencyEdit->setText(QString::number(sCurrencyID));
	salaryTypeEdit->setText(QString::number(sSalaryTypeID));
	dateEdit->setDate(QDate::fromString(sDate, "dd.MM.yyyy"));
	int index = bonusCmb->findText(sBonus);
	bonusCmb->setCurrentIndex(index);
}

bool CreateSlrDlg::FillDlgElements(QTableView* sTable)
{
	QModelIndex mIndex = sTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetSalaryParams(sTable->model()->data(sTable->model()->index(mIndex.row(), 1)).toInt(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 6)).toDouble(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 9)).toInt(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 10)).toInt(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 5)).toString().toUtf8().constData(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 11)).toString().toUtf8().constData(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(sTable->model()->data(sTable->model()->index(mIndex.row(), 1)).toInt(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 6)).toDouble(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 9)).toInt(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 10)).toInt(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 5)).toString().toUtf8().constData(),
			sTable->model()->data(sTable->model()->index(mIndex.row(), 11)).toString().toUtf8().constData());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateSlrDlg::CreateSalary()
{
	errorMessage.clear();
	if (!(0 != employeeEdit->text().toInt() || 0.0 != valueEdit->text().toDouble() || 0 != currencyEdit->text().toInt()
		|| dateEdit->text().isEmpty()) || 0 != salaryTypeEdit->text().toInt() || bonusCmb->currentText().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetSalaryParams(employeeEdit->text().toInt(), valueEdit->text().toDouble(), currencyEdit->text().toInt(), salaryTypeEdit->text().toInt(), dateEdit->text(), bonusCmb->currentText());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateSalary(salary, errorMessage))
		{
			BusinessLayer::Employee *employee = new BusinessLayer::Employee();
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;
			BusinessLayer::SalaryType *salaryType = new BusinessLayer::SalaryType;
			if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), salary->GetEmployeeID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), salary->GetCurrencyID(), errorMessage)
				|| !salaryType->GetSalaryTypeByID(dialogBL->GetOrmasDal(), salary->GetSalaryTypeID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete employee;
				delete currency;
				delete salaryType;
				return;
			}

			QList<QStandardItem*> salaryItem;
			salaryItem << new QStandardItem(QString::number(salary->GetID()))
				<< new QStandardItem(QString::number(salary->GetEmployeeID()))
				<< new QStandardItem(employee->GetName().c_str())
				<< new QStandardItem(employee->GetSurname().c_str())
				<< new QStandardItem(employee->GetPhone().c_str())
				<< new QStandardItem(salary->GetDate().c_str())
				<< new QStandardItem(QString::number(salary->GetValue()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(salaryType->GetName().c_str())
				<< new QStandardItem(QString::number(salary->GetCurrencyID()))
				<< new QStandardItem(QString::number(salary->GetSalaryTypeID()))
				<< new QStandardItem(salary->GetIsBonus() ? "true" : "false");
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(salaryItem);
			this->close();
			dialogBL->CommitTransaction(errorMessage);
			delete employee;
			delete currency;
			delete salaryType;
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
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please fill employee, value, date and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateSlrDlg::EditSalary()
{
	errorMessage.clear();
	if (!(0 != employeeEdit->text().toInt() || 0.0 != valueEdit->text().toDouble() || 0 != currencyEdit->text().toInt()
		|| dateEdit->text().isEmpty()) || 0 != salaryTypeEdit->text().toInt() || bonusCmb->currentText().isEmpty())
	{
		if (QString(salary->GetDate().c_str()) != dateEdit->text() || salary->GetEmployeeID() != employeeEdit->text().toInt()
			|| salary->GetValue() != valueEdit->text().toDouble() || salary->GetCurrencyID() != currencyEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetSalaryParams(employeeEdit->text().toInt(), valueEdit->text().toDouble(), currencyEdit->text().toInt(), salaryTypeEdit->text().toInt(), dateEdit->text(), bonusCmb->currentText(), salary->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateSalary(salary, errorMessage))
			{
				BusinessLayer::Employee *employee = new BusinessLayer::Employee();
				BusinessLayer::Currency *currency = new BusinessLayer::Currency;
				BusinessLayer::SalaryType *salaryType = new BusinessLayer::SalaryType;
				if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), salary->GetEmployeeID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), salary->GetCurrencyID(), errorMessage)
					|| !salaryType->GetSalaryTypeByID(dialogBL->GetOrmasDal(), salary->GetSalaryTypeID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete employee;
					delete currency;
					delete salaryType;
					return;
				}

				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(QString::number(salary->GetEmployeeID()));
				itemModel->item(mIndex.row(), 2)->setText(employee->GetName().c_str());
				itemModel->item(mIndex.row(), 3)->setText(employee->GetSurname().c_str());
				itemModel->item(mIndex.row(), 4)->setText(employee->GetPhone().c_str());
				itemModel->item(mIndex.row(), 5)->setText(salary->GetDate().c_str());
				itemModel->item(mIndex.row(), 6)->setText(QString::number(salary->GetValue()));
				itemModel->item(mIndex.row(), 7)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 8)->setText(salaryType->GetName().c_str());
				itemModel->item(mIndex.row(), 9)->setText(QString::number(salary->GetCurrencyID()));
				itemModel->item(mIndex.row(), 10)->setText(QString::number(salary->GetSalaryTypeID()));
				itemModel->item(mIndex.row(), 11)->setText(salary->GetIsBonus() ? "true" : "false");
				emit itemModel->dataChanged(mIndex, mIndex);
				this->close();
				dialogBL->CommitTransaction(errorMessage);
				delete employee;
				delete currency;
				delete salaryType;
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
			QString(tr("Please fill employee, value and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateSlrDlg::Close()
{
	this->close();
}

void CreateSlrDlg::OpenEmpDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *employeeParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)employeeParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Employees"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::EmployeeView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createSlrDlg = this;
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


void CreateSlrDlg::OpenCurDlg()
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
		dForm->createSlrDlg = this;
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

void CreateSlrDlg::OpenSlrTypeDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Salary type"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::SalaryType>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createSlrDlg = this;
		dForm->setObjectName("slrTypeForm");
		dForm->QtConnect<BusinessLayer::SalaryType>();
		QMdiSubWindow *returnWindow = new QMdiSubWindow;
		returnWindow->setWidget(dForm);
		returnWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(returnWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All salary types are shown");
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