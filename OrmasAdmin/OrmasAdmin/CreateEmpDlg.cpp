#include "stdafx.h"

#include "CreateEmpDlg.h"
#include "DataForm.h"


CreateEmpDlg::CreateEmpDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	parentForm = parent;
	DataForm *dataFormParent = (DataForm *)this->parentForm;
	mainForm = (MainForm *)dataFormParent->GetParent();
	activatedCmbBox->addItem("false");
	activatedCmbBox->addItem("true");
	positionEdit->setReadOnly(true);
	emailEdit->setMaxLength(30);
	surnameEdit->setMaxLength(50);
	nameEdit->setMaxLength(40);
	phoneEdit->setMaxLength(20);
	addressEdit->setMaxLength(50);
	passwordEdit->setMaxLength(30);
	vInt = new QIntValidator(0, 1000000000, this);
	positionEdit->setValidator(vInt);
	roleEdit->setValidator(vInt);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateEmpDlg::EditEmployee);
	}
	else
	{
		positionEdit->setText("0");
		roleEdit->setText("0");
		QObject::connect(okBtn, &QPushButton::released, this, &CreateEmpDlg::CreateEmployee);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateEmpDlg::Close);
	QObject::connect(positionBtn, &QPushButton::released, this, &CreateEmpDlg::OpenPsnDlg);
	QObject::connect(roleBtn, &QPushButton::released, this, &CreateEmpDlg::OpenRoleDlg);
}

CreateEmpDlg::~CreateEmpDlg()
{
	delete employee;
	delete vInt;
}

void CreateEmpDlg::SetID(int ID, QString childName)
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

			if (childName == QString("roleForm"))
			{
				roleEdit->setText(QString::number(ID));
				BusinessLayer::Role role;
				if (role.GetRoleByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					roleNamePh->setText(role.GetName().c_str());
				}
			}
			if (childName == QString("positionForm"))
			{
				positionEdit->setText(QString::number(ID));
				BusinessLayer::Position position;
				if (position.GetPositionByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					positionNamePh->setText(position.GetName().c_str());
				}
			}
		}
	}
}

void CreateEmpDlg::SetEmployeeParams(QString eEmail, QString eName, QString eSurname, QString ePhone, QString eAddress,
	int eRoleID, QString ePassword, QString eActivated, int ePositionID, QString eBirthDate, QString eHireNumber, int id)
{
	employee->SetEmail(eEmail.toUtf8().constData());
	employee->SetName(eName.toUtf8().constData());
	employee->SetSurname(eSurname.toUtf8().constData());
	employee->SetPhone(ePhone.toUtf8().constData());
	employee->SetAddress(eAddress.toUtf8().constData());
	employee->SetRoleID(eRoleID);
	employee->SetPassword(ePassword.toUtf8().constData());
	employee->SetActivated(eActivated == "true" ? true : false);
	employee->SetPositionID(ePositionID);
	employee->SetBirthDate(eBirthDate.toUtf8().constData());
	employee->SetHireDate(eHireNumber.toUtf8().constData());
	employee->SetID(id);
}

void CreateEmpDlg::FillEditElements(QString eEmail, QString eName, QString eSurname, QString ePhone, QString eAddress,
	int eRoleID, QString ePassword, QString eActivated, int ePositionID, QString eBirthDate, QString eHireNumber)
{
	emailEdit->setText(eEmail);
	nameEdit->setText(eName);
	surnameEdit->setText(eSurname);
	phoneEdit->setText(ePhone);
	addressEdit->setText(eAddress);
	passwordEdit->setText(ePassword);
	int index = activatedCmbBox->findText(eActivated);
	activatedCmbBox->setCurrentIndex(index);
	roleEdit->setText(QString::number(eRoleID));
	positionEdit->setText(QString::number(ePositionID));
	birthDateEdit->setDate(QDate::fromString(eBirthDate, "dd.MM.yyyy"));
	hireDateEdit->setDate(QDate::fromString(eHireNumber, "dd.MM.yyyy"));
	BusinessLayer::Role role;
	if (role.GetRoleByID(dialogBL->GetOrmasDal(), eRoleID, errorMessage))
	{
		roleNamePh->setText(role.GetName().c_str());
	}
	BusinessLayer::Position position;
	if (position.GetPositionByID(dialogBL->GetOrmasDal(), ePositionID, errorMessage))
	{
		positionNamePh->setText(position.GetName().c_str());
	}
}

bool CreateEmpDlg::FillDlgElements(QTableView* eTable)
{
	QModelIndex mIndex = eTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetEmployeeParams(eTable->model()->data(eTable->model()->index(mIndex.row(), 10)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 4)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 5)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 12)).toInt(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 9)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 11)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 13)).toInt(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 6)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 8)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(eTable->model()->data(eTable->model()->index(mIndex.row(), 10)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 4)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 5)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 12)).toInt(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 9)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 11)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 13)).toInt(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 6)).toString().toUtf8().constData(),
			eTable->model()->data(eTable->model()->index(mIndex.row(), 8)).toString().toUtf8().constData());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateEmpDlg::CreateEmployee()
{
	errorMessage.clear();
	if (!nameEdit->text().isEmpty() && !surnameEdit->text().isEmpty() && !phoneEdit->text().isEmpty()
		&& !addressEdit->text().isEmpty() && !birthDateEdit->text().isEmpty() && !hireDateEdit->text().isEmpty()
		&& !passwordEdit->text().isEmpty() && !activatedCmbBox->currentText().isEmpty() && 0 != roleEdit->text().toInt() && 0 != positionEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*) parentForm;
		
		BusinessLayer::Role *clientRole = new BusinessLayer::Role();
		clientRole->SetName("CLIENT");
		std::string clientRoleFilter = dialogBL->GenerateFilter<BusinessLayer::Role>(clientRole);
		std::vector<BusinessLayer::Role> clietnRoleVector = dialogBL->GetAllDataForClass<BusinessLayer::Role>(errorMessage, clientRoleFilter);

		if (clietnRoleVector.size() < 1)
		{
			errorMessage = "Please contact with admin, program have fatal issue, client role doesn't exist!";
			QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr(errorMessage.c_str())),
			QString(tr("Ok")));
			errorMessage.clear();
			return;
		}
		else
		{
			if (roleEdit->text().toInt() == clietnRoleVector.at(0).GetID())
			{
				errorMessage = "Employee cannot be a client of company! Please choose correct role!";
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				return;
			}
		}

		SetEmployeeParams(emailEdit->text(), nameEdit->text(), surnameEdit->text(), phoneEdit->text(), addressEdit->text(),
			roleEdit->text().toInt(), passwordEdit->text(), activatedCmbBox->currentText(), positionEdit->text().toInt(),
			birthDateEdit->date().toString("dd.MM.yyyy"), hireDateEdit->date().toString("dd.MM.yyyy"));
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateEmployee(employee, errorMessage))
		{
			if (parentDataForm != nullptr)
			{
				if (!parentDataForm->IsClosed())
				{

					BusinessLayer::Role *role = new BusinessLayer::Role();
					BusinessLayer::Position *position = new BusinessLayer::Position();
					if (!role->GetRoleByID(dialogBL->GetOrmasDal(), employee->GetRoleID(), errorMessage)
						|| !position->GetPositionByID(dialogBL->GetOrmasDal(), employee->GetPositionID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));

						errorMessage.clear();
						delete position;
						delete role;
						return;
					}
					QList<QStandardItem*> EmployeeItem;
					EmployeeItem << new QStandardItem(QString::number(employee->GetID()))
						<< new QStandardItem(employee->GetName().c_str())
						<< new QStandardItem(employee->GetSurname().c_str())
						<< new QStandardItem(position->GetName().c_str())
						<< new QStandardItem(employee->GetPhone().c_str())
						<< new QStandardItem(employee->GetAddress().c_str())
						<< new QStandardItem(employee->GetBirthDate().c_str())
						<< new QStandardItem(role->GetName().c_str())
						<< new QStandardItem(employee->GetHireDate().c_str())
						<< new QStandardItem(employee->GetPassword().c_str())
						<< new QStandardItem(employee->GetEmail().c_str())
						<< new QStandardItem(employee->GetActivated() ? "true" : "false")
						<< new QStandardItem(QString::number(employee->GetRoleID()))
						<< new QStandardItem(QString::number(employee->GetPositionID()));
					QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
					itemModel->appendRow(EmployeeItem);

					delete position;
					delete role;
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

			errorMessage.clear();
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

void CreateEmpDlg::EditEmployee()
{
	errorMessage.clear();
	if (!nameEdit->text().isEmpty() && !surnameEdit->text().isEmpty() && !phoneEdit->text().isEmpty()
		&& !addressEdit->text().isEmpty() && !birthDateEdit->text().isEmpty() && !hireDateEdit->text().isEmpty()
		&& !passwordEdit->text().isEmpty() && !activatedCmbBox->currentText().isEmpty() && 0 != roleEdit->text().toInt() && 0 != positionEdit->text().toInt())
	{
		if (QString(employee->GetEmail().c_str()) != emailEdit->text() || QString(employee->GetName().c_str()) != nameEdit->text() ||
			QString(employee->GetSurname().c_str()) != surnameEdit->text() || QString(employee->GetAddress().c_str()) != addressEdit->text() ||
			QString(employee->GetPhone().c_str()) != phoneEdit->text() || QString(employee->GetBirthDate().c_str()) != birthDateEdit->date().toString("dd.MM.yyyy") ||
			QString(employee->GetHireDate().c_str()) != hireDateEdit->date().toString("dd.MM.yyyy") || employee->GetRoleID() != roleEdit->text().toInt() ||
			employee->GetPositionID() != positionEdit->text().toInt() || QString(employee->GetPassword().c_str()) != passwordEdit->text() ||
			QString(employee->GetActivated() ? "true" : "false") != activatedCmbBox->currentText())
		{
			DataForm *parentDataForm = (DataForm*) parentForm;
			
			BusinessLayer::Role *clientRole = new BusinessLayer::Role();
			clientRole->SetName("CLIENT");
			std::string clientRoleFilter = dialogBL->GenerateFilter<BusinessLayer::Role>(clientRole);
			std::vector<BusinessLayer::Role> clietnRoleVector = dialogBL->GetAllDataForClass<BusinessLayer::Role>(errorMessage, clientRoleFilter);

			if (clietnRoleVector.size() < 1)
			{
				errorMessage = "Please contact with admin, program have fatal issue, client role doesn't exist!";
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				return;
			}
			else
			{
				if (roleEdit->text().toInt() == clietnRoleVector.at(0).GetID())
				{
					errorMessage = "Employee cannot be a client of company! Please choose correct role!";
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					return;
				}
			}
			
			SetEmployeeParams(emailEdit->text(), nameEdit->text(), surnameEdit->text(), phoneEdit->text(), addressEdit->text(),
				roleEdit->text().toInt(), passwordEdit->text(), activatedCmbBox->currentText(), positionEdit->text().toInt(),
				birthDateEdit->date().toString("dd.MM.yyyy"), hireDateEdit->date().toString("dd.MM.yyyy"), employee->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateEmployee(employee, errorMessage))
			{
				if (parentDataForm != nullptr)
				{
					if (!parentDataForm->IsClosed())
					{
						//updating Emp data
						QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
						QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
						itemModel->item(mIndex.row(), 1)->setText(employee->GetName().c_str());
						itemModel->item(mIndex.row(), 2)->setText(employee->GetSurname().c_str());


						//if location of Employee is changed, then update location data fields
						BusinessLayer::Position *position = new BusinessLayer::Position();

						//if role of Employee is changed, then update location data fields
						BusinessLayer::Role *role = new BusinessLayer::Role();

						if (!role->GetRoleByID(dialogBL->GetOrmasDal(), employee->GetRoleID(), errorMessage)
							|| !position->GetPositionByID(dialogBL->GetOrmasDal(), employee->GetPositionID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));

							errorMessage.clear();
							delete position;
							delete role;
							return;
						}
						itemModel->item(mIndex.row(), 3)->setText(position->GetName().c_str());
						itemModel->item(mIndex.row(), 4)->setText(employee->GetPhone().c_str());
						itemModel->item(mIndex.row(), 5)->setText(employee->GetAddress().c_str());
						itemModel->item(mIndex.row(), 6)->setText(employee->GetBirthDate().c_str());
						itemModel->item(mIndex.row(), 7)->setText(role->GetName().c_str());
						itemModel->item(mIndex.row(), 8)->setText(employee->GetHireDate().c_str());
						itemModel->item(mIndex.row(), 9)->setText(employee->GetPassword().c_str());
						itemModel->item(mIndex.row(), 10)->setText(employee->GetEmail().c_str());
						itemModel->item(mIndex.row(), 11)->setText(employee->GetActivated() ? "true" : "false");
						itemModel->item(mIndex.row(), 12)->setText(QString::number(employee->GetRoleID()));
						itemModel->item(mIndex.row(), 13)->setText(QString::number(employee->GetPositionID()));

						emit itemModel->dataChanged(mIndex, mIndex);
						delete position;
						delete role;
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

void CreateEmpDlg::Close()
{
	this->parentWidget()->close();
}

void CreateEmpDlg::OpenPsnDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Position"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::Position>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("positionForm");
		dForm->QtConnect<BusinessLayer::Position>();
		QMdiSubWindow *positionWindow = new QMdiSubWindow;
		positionWindow->setWidget(dForm);
		positionWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(positionWindow);
		positionWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
		QString message = tr("All positions are shown");
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

void CreateEmpDlg::OpenRoleDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Roles"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::Role>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->parentDialog = this;
		dForm->setObjectName("roleForm");
		dForm->QtConnect<BusinessLayer::Role>();
		QMdiSubWindow *roleWindow = new QMdiSubWindow;
		roleWindow->setWidget(dForm);
		roleWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(roleWindow);
		roleWindow->resize(dForm->size().width() + 18, dForm->size().height() + 30);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		dForm->setWindowFlags(dForm->windowFlags() | Qt::WindowStaysOnTopHint);
		QString message = tr("All roles are shown");
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
