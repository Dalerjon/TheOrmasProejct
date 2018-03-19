#include "stdafx.h"
#include <QMessageBox>
#include "CreateSpecDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"
#include <map>

CreateSpecDlg::CreateSpecDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	employeeEdit->setValidator(vInt);
	productEdit->setValidator(vInt);
	sumEdit->setValidator(vDouble);
	sumEdit->setMaxLength(17);
	dialogBL->StartTransaction(errorMessage);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateSpecDlg::EditSpecification);
	}
	else
	{
		specification->SetID(dialogBL->GenerateID());
		employeeEdit->setText("0");
		productEdit->setText("0");
		sumEdit->setText("0");
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateSpecDlg::CreateSpecification);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateSpecDlg::Close);
	QObject::connect(employeeBtn, &QPushButton::released, this, &CreateSpecDlg::OpenEmpDlg);
	QObject::connect(productBtn, &QPushButton::released, this, &CreateSpecDlg::OpenProdDlg);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateSpecDlg::OpenSpecListDlg);
	QObject::connect(this, SIGNAL(CloseCreatedForms()), ((MainForm*)((DataForm*)parent)->GetParent()), SLOT(CloseChildsByName()));
	InitComboBox();
}

CreateSpecDlg::~CreateSpecDlg()
{
	delete vDouble;
	delete vInt;
	emit CloseCreatedForms();
	dialogBL->CancelTransaction(errorMessage);
}

void CreateSpecDlg::SetSpecificationParams(int pID, double sSum, int cID, int eID, QString sDate, int id)
{
	specification->SetProductID(pID);
	specification->SetSum(sSum);
	specification->SetCurrencyID(cID);
	specification->SetEmployeeID(eID);
	specification->SetDate(sDate.toUtf8().constData());
	specification->SetID(id);
}

void CreateSpecDlg::FillEditElements(int pID, double sSum, int cID, int eID, QString sDate)
{
	productEdit->setText(QString::number(pID));
	sumEdit->setText(QString::number(sSum));
	employeeEdit->setText(QString::number(eID));
	dateEdit->setDateTime(QDateTime::fromString(sDate, "yyyy.MM.dd hh:mm:ss"));
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(cID)));
	BusinessLayer::User user;
	if (user.GetUserByID(dialogBL->GetOrmasDal(), eID, errorMessage))
	{
		empNamePh->setText(user.GetName().c_str());
		empSurnamePh->setText(user.GetSurname().c_str());
		empPhonePh->setText(user.GetPhone().c_str());
	}
	BusinessLayer::Product product;
	if (product.GetProductByID(dialogBL->GetOrmasDal(), pID, errorMessage))
	{
		prodNamePh->setText(product.GetName().c_str());
		volumePh->setText(QString::number(product.GetVolume()));
		BusinessLayer::Measure measure;
		if (measure.GetMeasureByID(dialogBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			measurePh->setText(measure.GetName().c_str());
		}
	}
}

void CreateSpecDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("productForm"))
			{
				productEdit->setText(QString::number(ID));
				BusinessLayer::Product product;
				if (product.GetProductByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					prodNamePh->setText(product.GetName().c_str());
					volumePh->setText(QString::number(product.GetVolume()));
					BusinessLayer::Measure measure;
					if (measure.GetMeasureByID(dialogBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
					{
						measurePh->setText(measure.GetName().c_str());
					}
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

bool CreateSpecDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetSpecificationParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 9)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 3)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 10)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 11)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(cTable->model()->data(cTable->model()->index(mIndex.row(), 9)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 3)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 10)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 11)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateSpecDlg::CreateSpecification()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& !currencyCmb->currentText().isEmpty() && 0 != employeeEdit->text().toInt() && !dateEdit->text().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetSpecificationParams(productEdit->text().toInt(), sumEdit->text().toInt(), currencyCmb->currentData().toInt(),
			employeeEdit->text().toInt(), dateEdit->text(), specification->GetID());

		if (dialogBL->CreateSpecification(specification, errorMessage))
		{
			BusinessLayer::Product *product = new BusinessLayer::Product;
			BusinessLayer::Employee *employee = new BusinessLayer::Employee();
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;

			if (!product->GetProductByID(dialogBL->GetOrmasDal(), specification->GetProductID(), errorMessage)
				|| !employee->GetEmployeeByID(dialogBL->GetOrmasDal(), specification->GetEmployeeID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), specification->GetCurrencyID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete product;
				delete employee;
				delete currency;
				return;
			}

			BusinessLayer::Position *position = new BusinessLayer::Position;
			if (!position->GetPositionByID(dialogBL->GetOrmasDal(), employee->GetPositionID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete position;
				return;
			}
			
			QList<QStandardItem*> specificationItem;
			specificationItem << new QStandardItem(QString::number(specification->GetID()))
				<< new QStandardItem(specification->GetDate().c_str())
				<< new QStandardItem(product->GetName().c_str())
				<< new QStandardItem(QString::number(specification->GetSum()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(employee->GetName().c_str())
				<< new QStandardItem(employee->GetSurname().c_str())
				<< new QStandardItem(employee->GetPhone().c_str())
				<< new QStandardItem(position->GetName().c_str())
				<< new QStandardItem(QString::number(specification->GetProductID()))
				<< new QStandardItem(QString::number(specification->GetCurrencyID())) 
				<< new QStandardItem(QString::number(specification->GetEmployeeID()));

			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(specificationItem);
			dialogBL->CommitTransaction(errorMessage);
			delete product;
			delete employee;
			delete currency;
			delete product;
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

void CreateSpecDlg::EditSpecification()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& !currencyCmb->currentText().isEmpty() && 0 != employeeEdit->text().toInt() && !dateEdit->text().isEmpty())
	{
		if (specification->GetProductID() != productEdit->text().toInt() || QString(specification->GetDate().c_str()) != dateEdit->text() ||
			specification->GetEmployeeID() != employeeEdit->text().toInt() || specification->GetSum() != sumEdit->text().toInt()
			|| specification->GetCurrencyID() != currencyCmb->currentData().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetSpecificationParams(productEdit->text().toInt(), sumEdit->text().toInt(), currencyCmb->currentData().toInt(),
				employeeEdit->text().toInt(), dateEdit->text(), specification->GetID());

			if (dialogBL->UpdateSpecification(specification, errorMessage))
			{
				//updating Specification data
				BusinessLayer::Product *product = new BusinessLayer::Product;
				BusinessLayer::Employee *employee = new BusinessLayer::Employee();
				BusinessLayer::Currency *currency = new BusinessLayer::Currency;

				if (!product->GetProductByID(dialogBL->GetOrmasDal(), specification->GetProductID(), errorMessage)
					|| !employee->GetEmployeeByID(dialogBL->GetOrmasDal(), specification->GetEmployeeID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), specification->GetCurrencyID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete product;
					delete employee;
					delete currency;
					return;
				}

				BusinessLayer::Position *position = new BusinessLayer::Position;
				if (!position->GetPositionByID(dialogBL->GetOrmasDal(), employee->GetPositionID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete position;
					return;
				}
				
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(specification->GetDate().c_str());
				itemModel->item(mIndex.row(), 2)->setText(product->GetName().c_str());
				itemModel->item(mIndex.row(), 3)->setText(QString::number(specification->GetSum()));
				itemModel->item(mIndex.row(), 4)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 5)->setText(employee->GetName().c_str());
				itemModel->item(mIndex.row(), 6)->setText(employee->GetSurname().c_str());
				itemModel->item(mIndex.row(), 7)->setText(employee->GetPhone().c_str());
				itemModel->item(mIndex.row(), 8)->setText(position->GetName().c_str());
				itemModel->item(mIndex.row(), 9)->setText(QString::number(specification->GetProductID()));
				itemModel->item(mIndex.row(), 10)->setText(QString::number(specification->GetCurrencyID()));
				itemModel->item(mIndex.row(), 11)->setText(QString::number(specification->GetEmployeeID()));

				emit itemModel->dataChanged(mIndex, mIndex);
				dialogBL->CommitTransaction(errorMessage);
				
				delete product;
				delete employee;
				delete currency;
				
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

void CreateSpecDlg::Close()
{
	dialogBL->CancelTransaction(errorMessage);
	this->close();
}

void CreateSpecDlg::OpenEmpDlg()
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
		dForm->createSpecDlg = this;
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

void CreateSpecDlg::OpenProdDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Products"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	dForm->FillTable<BusinessLayer::ProductView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createSpecDlg = this;
		dForm->setObjectName("productForm");
		dForm->QtConnect<BusinessLayer::ProductView>();
		QMdiSubWindow *productWindow = new QMdiSubWindow;
		productWindow->setWidget(dForm);
		productWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(productWindow);
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

void CreateSpecDlg::OpenSpecListDlg()
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
	dForm->specificationID = specification->GetID();
	BusinessLayer::SpecificationList specificationList;
	specificationList.SetSpecificationID(specification->GetID());
	std::string specificationListFilter = specificationList.GenerateFilter(dialogBL->GetOrmasDal());
	dForm->FillTable<BusinessLayer::SpecificationListView>(errorMessage, specificationListFilter);
	if (errorMessage.empty())
	{
		dForm->createSpecDlg = this;
		dForm->setObjectName("specificationListForm");
		dForm->QtConnect<BusinessLayer::SpecificationListView>();
		QMdiSubWindow *specificationListWindow = new QMdiSubWindow;
		specificationListWindow->setWidget(dForm);
		specificationListWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(specificationListWindow);
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

void CreateSpecDlg::InitComboBox()
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

