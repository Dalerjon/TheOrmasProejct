#include "stdafx.h"

#include "CreateOrdRDlg.h"
#include "DataForm.h"

#include <map>

CreateOrdRDlg::CreateOrdRDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	parentForm = parent;
	DataForm *dataFormParent = (DataForm *)this->parentForm;
	mainForm = (MainForm *)dataFormParent->GetParent();
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	purveyorEdit->setValidator(vInt);
	employeeEdit->setValidator(vInt);
	prodCountEdit->setValidator(vDouble);
	statusEdit->setValidator(vInt);
	sumEdit->setValidator(vDouble);
	sumEdit->setMaxLength(17);
	dialogBL->StartTransaction(errorMessage);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateOrdRDlg::EditOrderRaw);
	}
	else
	{
		orderRaw->SetID(dialogBL->GenerateID());
		execDateWidget->setVisible(false);
		execDateEdit->setDateTime(QDateTime::currentDateTime());
		employeeEdit->setText("0");
		purveyorEdit->setText("0");
		prodCountEdit->setText("0");
		statusEdit->setText("0");
		sumEdit->setText("0");
		dateEdit->setDateTime(QDateTime::currentDateTime());

		BusinessLayer::Status *status = new BusinessLayer::Status();
		status->SetName("ORDERED");
		std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
		std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);
		delete status;
		if (statusVector.size() == 0)
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("Status are empty please contact with Admin")),
				QString(tr("Ok")));
			errorMessage.clear();
			return;
		}
		statusEdit->setText(QString::number(statusVector.at(0).GetID()));
		statusPh->setText(statusVector.at(0).GetName().c_str());

		QObject::connect(okBtn, &QPushButton::released, this, &CreateOrdRDlg::CreateOrderRaw);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateOrdRDlg::Close);
	QObject::connect(employeeBtn, &QPushButton::released, this, &CreateOrdRDlg::OpenEmpDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateOrdRDlg::OpenStsDlg);
	QObject::connect(purveyorBtn, &QPushButton::released, this, &CreateOrdRDlg::OpenPurDlg);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateOrdRDlg::OpenOrdRListDlg);
	QObject::connect(statusEdit, &QLineEdit::textChanged, this, &CreateOrdRDlg::StatusWasChenged);
	QObject::connect(prodCountEdit, &QLineEdit::textChanged, this, &CreateOrdRDlg::TextEditChanged);
	QObject::connect(sumEdit, &QLineEdit::textChanged, this, &CreateOrdRDlg::TextEditChanged);
	QObject::connect(this, SIGNAL(CloseCreatedForms()), ((MainForm*)((DataForm*)parent)->GetParent()), SLOT(CloseChildsByName()));
	InitComboBox();
}

CreateOrdRDlg::~CreateOrdRDlg()
{
	delete vDouble;
	delete vInt;
	emit CloseCreatedForms();
	dialogBL->CancelTransaction(errorMessage);
}

void CreateOrdRDlg::SetOrderRawParams(int oPurveyorID, QString oDate, QString oExecDate, int oEmployeeID, double oCount,
	double oSum, int oStatusID, int oCurrencyID, int id)
{
	orderRaw->SetPurveyorID(oPurveyorID);
	orderRaw->SetDate(oDate.toUtf8().constData());
	orderRaw->SetExecutionDate(oExecDate.toUtf8().constData());
	orderRaw->SetEmployeeID(oEmployeeID);
	orderRaw->SetCount(oCount);
	orderRaw->SetSum(oSum);
	orderRaw->SetStatusID(oStatusID);
	orderRaw->SetCurrencyID(oCurrencyID);
	orderRaw->SetID(id);
}

void CreateOrdRDlg::FillEditElements(int oPurveyorID, QString oDate, QString oExecDate, int oEmployeeID, double oCount,
	double oSum, int oStatusID, int oCurrencyID)
{
	purveyorEdit->setText(QString::number(oPurveyorID));
	dateEdit->setDateTime(QDateTime::fromString(oDate, "dd.MM.yyyy hh:mm"));
	if (!oExecDate.isEmpty())
	{
		execDateEdit->setDateTime(QDateTime::fromString(oExecDate, "dd.MM.yyyy hh:mm"));
	}
	employeeEdit->setText(QString::number(oEmployeeID));
	prodCountEdit->setText(QString::number(oCount));
	sumEdit->setText(QString::number(oSum));
	statusEdit->setText(QString::number(oStatusID));
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(oCurrencyID)));
	BusinessLayer::User user1;
	if (user1.GetUserByID(dialogBL->GetOrmasDal(), oPurveyorID, errorMessage))
	{
		prNamePh->setText(user1.GetName().c_str());
		prSurnamePh->setText(user1.GetSurname().c_str());
		prPhonePh->setText(user1.GetPhone().c_str());
	}
	BusinessLayer::User user2;
	if (user2.GetUserByID(dialogBL->GetOrmasDal(), oEmployeeID, errorMessage))
	{
		empNamePh->setText(user2.GetName().c_str());
		empSurnamePh->setText(user2.GetSurname().c_str());
		empPhonePh->setText(user2.GetPhone().c_str());
	}
	BusinessLayer::Status status;
	if (status.GetStatusByID(dialogBL->GetOrmasDal(), oStatusID, errorMessage))
	{
		statusPh->setText(status.GetName().c_str());
	}
}

void CreateOrdRDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			this->hide();
			this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
			this->show();
			this->raise();
			this->activateWindow();
			QApplication::setActiveWindow(this);

			if (childName == QString("purveyorForm"))
			{
				purveyorEdit->setText(QString::number(ID));
				BusinessLayer::User user;
				if (user.GetUserByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					prNamePh->setText(user.GetName().c_str());
					prSurnamePh->setText(user.GetSurname().c_str());
					prPhonePh->setText(user.GetPhone().c_str());
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

bool CreateOrdRDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetOrderRawParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 17)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 16)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 13)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 14)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 18)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 19)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(cTable->model()->data(cTable->model()->index(mIndex.row(), 17)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 16)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 13)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 14)).toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 18)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 19)).toInt());
		BusinessLayer::Status *status = new BusinessLayer::Status;
		if (!status->GetStatusByID(dialogBL->GetOrmasDal(), orderRaw->GetStatusID(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage.clear();
			delete status;
			return false;
		}
		if (0 == status->GetName().compare("EXECUTED"))
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("This document have an \"EXECUTED\" status. The document with \"EXECUTED\" status cannot be changed!")),
				QString(tr("Ok")));
			errorMessage.clear();
			delete status;
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

void CreateOrdRDlg::CreateOrderRaw()
{
	errorMessage.clear();
	if (0 != purveyorEdit->text().toInt() && 0 != employeeEdit->text().toInt()
		&& 0 != prodCountEdit->text().toDouble() && 0 != sumEdit->text().toDouble()
		&& 0 != statusEdit->text().toInt() && 0 != currencyCmb->currentData().toInt())
	{
		DataForm *parentDataForm = (DataForm*) parentForm;
		if (!execDateWidget->isVisible())
		{
			SetOrderRawParams(purveyorEdit->text().toInt(), dateEdit->text(), "", employeeEdit->text().toInt(), prodCountEdit->text().toDouble(),
				sumEdit->text().toDouble(), statusEdit->text().toInt(), currencyCmb->currentData().toInt(), orderRaw->GetID());
		}
		else
		{
			SetOrderRawParams(purveyorEdit->text().toInt(), dateEdit->text(), execDateEdit->text(), employeeEdit->text().toInt(), prodCountEdit->text().toDouble(),
				sumEdit->text().toDouble(), statusEdit->text().toInt(), currencyCmb->currentData().toInt(), orderRaw->GetID());
		}
		

		if (dialogBL->CreateOrderRaw(orderRaw, errorMessage))
		{
			if (parentDataForm != nullptr)
			{
				if (!parentDataForm->IsClosed())
				{
					BusinessLayer::Status *status = new BusinessLayer::Status;
					if (!status->GetStatusByID(dialogBL->GetOrmasDal(), orderRaw->GetStatusID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete status;
						return;
					}
					QList<QStandardItem*> orderRawItem;
					orderRawItem << new QStandardItem(QString::number(orderRaw->GetID()))
						<< new QStandardItem(orderRaw->GetDate().c_str())
						<< new QStandardItem(orderRaw->GetExecutionDate().c_str())
						<< new QStandardItem(status->GetCode().c_str())
						<< new QStandardItem(status->GetName().c_str());

					BusinessLayer::Purveyor *purveyor = new BusinessLayer::Purveyor();
					BusinessLayer::Employee *employee = new BusinessLayer::Employee();
					BusinessLayer::Currency *currency = new BusinessLayer::Currency;

					if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), orderRaw->GetEmployeeID(), errorMessage)
						|| !purveyor->GetPurveyorByID(dialogBL->GetOrmasDal(), orderRaw->GetPurveyorID(), errorMessage)
						|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), orderRaw->GetCurrencyID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete employee;
						delete purveyor;
						delete currency;
						delete status;
						return;
					}

					if (0 != orderRaw->GetPurveyorID())
					{
						orderRawItem << new QStandardItem(purveyor->GetName().c_str())
							<< new QStandardItem(purveyor->GetSurname().c_str())
							<< new QStandardItem(purveyor->GetPhone().c_str())
							<< new QStandardItem(purveyor->GetCompanyName().c_str());
					}
					else
					{
						orderRawItem << new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("");
					}

					if (0 != orderRaw->GetEmployeeID())
					{
						BusinessLayer::Position *ePosition = new BusinessLayer::Position();
						if (!ePosition->GetPositionByID(dialogBL->GetOrmasDal(), employee->GetPositionID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							delete ePosition;
							return;
						}
						orderRawItem << new QStandardItem(employee->GetName().c_str())
							<< new QStandardItem(employee->GetSurname().c_str())
							<< new QStandardItem(employee->GetPhone().c_str())
							<< new QStandardItem(ePosition->GetName().c_str());
					}
					else
					{
						orderRawItem << new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("");
					}


					orderRawItem << new QStandardItem(QString::number(orderRaw->GetCount()))
						<< new QStandardItem(QString::number(orderRaw->GetSum()))
						<< new QStandardItem(currency->GetShortName().c_str())
						<< new QStandardItem(QString::number(orderRaw->GetEmployeeID()))
						<< new QStandardItem(QString::number(orderRaw->GetPurveyorID()))
						<< new QStandardItem(QString::number(orderRaw->GetStatusID()))
						<< new QStandardItem(QString::number(orderRaw->GetCurrencyID()));

					QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
					itemModel->appendRow(orderRawItem);

					delete employee;
					delete purveyor;
					delete currency;
					delete status;
				}
			}
			dialogBL->CommitTransaction(errorMessage);

		
			Close();
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
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please recheck all fields, especially product list!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateOrdRDlg::EditOrderRaw()
{
	errorMessage.clear();
	if (0 != purveyorEdit->text().toInt() && 0 != employeeEdit->text().toInt()
		&& 0 != prodCountEdit->text().toDouble() && 0 != sumEdit->text().toDouble()
		&& 0 != statusEdit->text().toInt() && 0 != currencyCmb->currentData().toInt())
	{
		if (orderRaw->GetEmployeeID() != employeeEdit->text().toInt() || QString(orderRaw->GetDate().c_str()) != dateEdit->text() ||
			orderRaw->GetPurveyorID() != purveyorEdit->text().toInt() || QString(orderRaw->GetExecutionDate().c_str()) != execDateEdit->text() ||
			orderRaw->GetEmployeeID() != employeeEdit->text().toInt() || orderRaw->GetCount() != prodCountEdit->text().toDouble() ||
			orderRaw->GetSum() != sumEdit->text().toDouble()
			|| orderRaw->GetCurrencyID() != currencyCmb->currentData().toInt())
		{
			DataForm *parentDataForm = (DataForm*) parentForm;
			if (!execDateWidget->isVisible())
			{
				SetOrderRawParams(purveyorEdit->text().toInt(), dateEdit->text(), "", employeeEdit->text().toInt(), prodCountEdit->text().toDouble(),
					sumEdit->text().toDouble(), statusEdit->text().toInt(), currencyCmb->currentData().toInt(), orderRaw->GetID());
			}
			else
			{
				SetOrderRawParams(purveyorEdit->text().toInt(), dateEdit->text(), execDateEdit->text(), employeeEdit->text().toInt(), prodCountEdit->text().toDouble(),
					sumEdit->text().toDouble(), statusEdit->text().toInt(), currencyCmb->currentData().toInt(), orderRaw->GetID());
			}

			if (dialogBL->UpdateOrderRaw(orderRaw, errorMessage))
			{
				if (parentDataForm != nullptr)
				{
					if (!parentDataForm->IsClosed())
					{
						//updating OrderRaw data
						QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
						QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
						itemModel->item(mIndex.row(), 1)->setText(orderRaw->GetDate().c_str());
						itemModel->item(mIndex.row(), 2)->setText(orderRaw->GetExecutionDate().c_str());


						BusinessLayer::Purveyor *purveyor = new BusinessLayer::Purveyor();
						BusinessLayer::Employee *employee = new BusinessLayer::Employee();
						BusinessLayer::Currency *currency = new BusinessLayer::Currency;
						BusinessLayer::Status *status = new BusinessLayer::Status;
						if (!employee->GetEmployeeByID(dialogBL->GetOrmasDal(), orderRaw->GetEmployeeID(), errorMessage)
							|| !purveyor->GetPurveyorByID(dialogBL->GetOrmasDal(), orderRaw->GetPurveyorID(), errorMessage)
							|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), orderRaw->GetCurrencyID(), errorMessage)
							|| !status->GetStatusByID(dialogBL->GetOrmasDal(), orderRaw->GetStatusID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							delete employee;
							delete purveyor;
							delete currency;
							delete status;
							return;
						}

						itemModel->item(mIndex.row(), 3)->setText(status->GetCode().c_str());
						itemModel->item(mIndex.row(), 4)->setText(status->GetName().c_str());

						if (orderRaw->GetPurveyorID() > 0)
						{
							itemModel->item(mIndex.row(), 5)->setText(purveyor->GetName().c_str());
							itemModel->item(mIndex.row(), 6)->setText(purveyor->GetSurname().c_str());
							itemModel->item(mIndex.row(), 7)->setText(purveyor->GetPhone().c_str());
							itemModel->item(mIndex.row(), 8)->setText(purveyor->GetCompanyName().c_str());
						}
						else
						{
							itemModel->item(mIndex.row(), 5)->setText("");
							itemModel->item(mIndex.row(), 6)->setText("");
							itemModel->item(mIndex.row(), 7)->setText("");
							itemModel->item(mIndex.row(), 8)->setText("");
						}

						if (orderRaw->GetEmployeeID() > 0)
						{
							BusinessLayer::Position *ePosition = new BusinessLayer::Position();
							if (!ePosition->GetPositionByID(dialogBL->GetOrmasDal(), employee->GetPositionID(), errorMessage))
							{
								dialogBL->CancelTransaction(errorMessage);
								QMessageBox::information(NULL, QString(tr("Warning")),
									QString(tr(errorMessage.c_str())),
									QString(tr("Ok")));
								errorMessage.clear();
								delete ePosition;
								return;
							}
							itemModel->item(mIndex.row(), 9)->setText(employee->GetName().c_str());
							itemModel->item(mIndex.row(), 10)->setText(employee->GetSurname().c_str());
							itemModel->item(mIndex.row(), 11)->setText(employee->GetPhone().c_str());
							itemModel->item(mIndex.row(), 12)->setText(ePosition->GetName().c_str());
						}
						else
						{
							itemModel->item(mIndex.row(), 9)->setText("");
							itemModel->item(mIndex.row(), 10)->setText("");
							itemModel->item(mIndex.row(), 11)->setText("");
							itemModel->item(mIndex.row(), 12)->setText("");
						}


						itemModel->item(mIndex.row(), 13)->setText(QString::number(orderRaw->GetCount()));
						itemModel->item(mIndex.row(), 14)->setText(QString::number(orderRaw->GetSum()));
						itemModel->item(mIndex.row(), 15)->setText(currency->GetShortName().c_str());
						itemModel->item(mIndex.row(), 16)->setText(QString::number(orderRaw->GetEmployeeID()));
						itemModel->item(mIndex.row(), 17)->setText(QString::number(orderRaw->GetPurveyorID()));
						itemModel->item(mIndex.row(), 18)->setText(QString::number(orderRaw->GetStatusID()));
						itemModel->item(mIndex.row(), 19)->setText(QString::number(orderRaw->GetCurrencyID()));

						emit itemModel->dataChanged(mIndex, mIndex);
						delete employee;
						delete purveyor;
						delete currency;
						delete status;
					}
				}
				dialogBL->CommitTransaction(errorMessage);

				
				Close();
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
			Close();
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

void CreateOrdRDlg::Close()
{
	dialogBL->CancelTransaction(errorMessage);
	this->parentWidget()->close();
}

void CreateOrdRDlg::OpenPurDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Purveyors"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	BusinessLayer::Role *role = new BusinessLayer::Role();
	role->SetName("PURVEYOR");
	std::string roleFilter = dialogBL->GenerateFilter<BusinessLayer::Role>(role);
	std::vector<BusinessLayer::Role> roleVector = dialogBL->GetAllDataForClass<BusinessLayer::Role>(errorMessage, roleFilter);

	if (roleVector.size() == 0)
	{
		delete role;
		QString message = tr("Sorry could not define the role for this purveyor!");
		mainForm->statusBar()->showMessage(message);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(message),
			QString(tr("Ok")));
		errorMessage = "";
		return;
	}

	dForm->FillTable<BusinessLayer::PurveyorView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("purveyorForm");
		dForm->QtConnect<BusinessLayer::PurveyorView>();
		QMdiSubWindow *purveyorWindow = new QMdiSubWindow;
		purveyorWindow->setWidget(dForm);
		purveyorWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(purveyorWindow);
		purveyorWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->HileSomeRow();
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
		QString message = tr("All purveyors are shown");
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

void CreateOrdRDlg::OpenEmpDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Employees"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	BusinessLayer::Role *role = new BusinessLayer::Role();
	role->SetName("STOCK MANAGER");
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
		QString message = tr("Sorry could not find employee with \"stock employee\" role!");
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
		dForm->parentDialog = this;
		dForm->setObjectName("employeeForm");
		dForm->QtConnect<BusinessLayer::EmployeeView>();
		QMdiSubWindow *employeeWindow = new QMdiSubWindow;
		employeeWindow->setWidget(dForm);
		employeeWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(employeeWindow);
		employeeWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->HileSomeRow();
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
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

void CreateOrdRDlg::OpenStsDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Status"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	dForm->FillTable<BusinessLayer::Status>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("statusForm");
		dForm->QtConnect<BusinessLayer::Status>();
		QMdiSubWindow *statusWindow = new QMdiSubWindow;
		statusWindow->setWidget(dForm);
		statusWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(statusWindow);
		statusWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
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


void CreateOrdRDlg::OpenOrdRListDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Add product"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->orderRawID = orderRaw->GetID();
	BusinessLayer::OrderRawList orderRawList;
	orderRawList.SetOrderRawID(orderRaw->GetID());
	std::string orderRawListFilter = orderRawList.GenerateFilter(dialogBL->GetOrmasDal());
	dForm->FillTable<BusinessLayer::OrderRawListView>(errorMessage, orderRawListFilter);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("orderRawListForm");
		dForm->QtConnect<BusinessLayer::OrderRawListView>();
		QMdiSubWindow *orderRawWindow = new QMdiSubWindow;
		orderRawWindow->setWidget(dForm);
		orderRawWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(orderRawWindow);
		orderRawWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
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

void CreateOrdRDlg::StatusWasChenged()
{
	errorMessage = "";
	statusMap = BusinessLayer::Status::GetStatusesAsMap(dialogBL->GetOrmasDal(), errorMessage);
	if (statusEdit->text().toInt() == statusMap.find("EXECUTED")->second)
	{
		execDateWidget->setVisible(true);
		execDateEdit->setDateTime(QDateTime::currentDateTime());
	}
}

void CreateOrdRDlg::InitComboBox()
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

void CreateOrdRDlg::TextEditChanged()
{
	if (prodCountEdit->text().contains(","))
	{
		prodCountEdit->setText(prodCountEdit->text().replace(",", "."));
	}
	if (prodCountEdit->text().contains(".."))
	{
		prodCountEdit->setText(prodCountEdit->text().replace("..", "."));
	}
	if (sumEdit->text().contains(","))
	{
		sumEdit->setText(sumEdit->text().replace(",", "."));
	}
	if (sumEdit->text().contains(".."))
	{
		sumEdit->setText(sumEdit->text().replace("..", "."));
	}
}

