#include "stdafx.h"
#include <QMessageBox>
#include "CreateUserDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateUserDlg::CreateUserDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	activatedCmbBox->addItem("false");
	activatedCmbBox->addItem("true");
	nameEdit->setMaxLength(30);
	surnameEdit->setMaxLength(50);
	phoneEdit->setMaxLength(25);
	addressEdit->setMaxLength(30);
	passwordEdit->setMaxLength(30);
	emailEdit->setMaxLength(30);
	//ReqExp
	vInt = new QIntValidator(0, 1000000000, this);
	phoneEdit->setValidator(vInt);
	roleEdit->setValidator(vInt);
	
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateUserDlg::EditUser);
	}
	else
	{
		roleEdit->setText("0");
		QObject::connect(okBtn, &QPushButton::released, this, &CreateUserDlg::CreateUser);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateUserDlg::Close);
	QObject::connect(roleBtn, &QPushButton::released, this, &CreateUserDlg::OpenRoleDlg);
}

CreateUserDlg::~CreateUserDlg()
{
	delete user;
	delete vInt;
}

void CreateUserDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("roleForm"))
			{
				roleEdit->setText(QString::number(ID));
				BusinessLayer::Role role;
				if (role.GetRoleByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					roleNamePh->setText(role.GetName().c_str());
				}
			}
		}
	}
}

void CreateUserDlg::SetUserParams(QString uEmail, QString uName, QString uSurname, QString uPhone, QString uAddress,
	int uRoleID, QString uPassword, QString uActivated, int id)
{
	user->SetEmail(uEmail.toUtf8().constData());
	user->SetName(uName.toUtf8().constData());
	user->SetSurname(uSurname.toUtf8().constData());
	user->SetPhone(uPhone.toUtf8().constData());
	user->SetAddress(uAddress.toUtf8().constData());
	user->SetRoleID(uRoleID);
	user->SetPassword(uPassword.toUtf8().constData());
	user->SetActivated(uActivated == "true"? true : false);
	user->SetID(id);
}

void CreateUserDlg::FillEditElements(QString uEmail, QString uName, QString uSurname, QString uPhone, QString uAddress,
	int uRoleID, QString uPassword, QString uActivated)
{
	emailEdit->setText(uEmail);
	nameEdit->setText(uName);
	surnameEdit->setText(uSurname);
	phoneEdit->setText(uPhone);
	addressEdit->setText(uAddress);
	roleEdit->setText(QString::number(uRoleID));
	passwordEdit->setText(uPassword);
	int index = activatedCmbBox->findText(uActivated);
	activatedCmbBox->setCurrentIndex(index);
	BusinessLayer::Role role;
	if (role.GetRoleByID(dialogBL->GetOrmasDal(), uRoleID, errorMessage))
	{
		roleNamePh->setText(role.GetName().c_str());
	}
}

bool CreateUserDlg::FillDlgElements(QTableView* uTable)
{
	QModelIndex mIndex = uTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetUserParams(uTable->model()->data(uTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 4)).toString().toUtf8().constData(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 5)).toString().toUtf8().constData(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 9)).toInt(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 7)).toString().toUtf8().constData(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 8)).toString().toUtf8().constData(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(uTable->model()->data(uTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 4)).toString().toUtf8().constData(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 5)).toString().toUtf8().constData(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 9)).toInt(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 7)).toString().toUtf8().constData(),
			uTable->model()->data(uTable->model()->index(mIndex.row(), 8)).toString().toUtf8().constData());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateUserDlg::CreateUser()
{
	errorMessage.clear();
	if (!(nameEdit->text().isEmpty() || phoneEdit->text().isEmpty() || addressEdit->text().isEmpty() || emailEdit->text().isEmpty() ||
		surnameEdit->text().isEmpty() || passwordEdit->text().isEmpty()	|| activatedCmbBox->currentText().isEmpty()) &&
		0 != roleEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetUserParams(emailEdit->text(), nameEdit->text(), surnameEdit->text(), phoneEdit->text(), addressEdit->text(),
			roleEdit->text().toInt(), passwordEdit->text(), activatedCmbBox->currentText());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateUser(user, errorMessage))
		{
			BusinessLayer::Role *role = new BusinessLayer::Role();
			if (!role->GetRoleByID(dialogBL->GetOrmasDal(),user->GetRoleID(),errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));

				errorMessage.clear();
				delete role;
				return;
			}
			QList<QStandardItem*> UserItem;
			UserItem << new QStandardItem(QString::number(user->GetID())) << new QStandardItem(user->GetEmail().c_str())
				<< new QStandardItem(user->GetName().c_str()) << new QStandardItem(user->GetSurname().c_str())
				<< new QStandardItem(user->GetPhone().c_str()) << new QStandardItem(user->GetAddress().c_str())
				<< new QStandardItem(role->GetName().c_str()) << new QStandardItem(user->GetPassword().c_str())
				<< new QStandardItem(user->GetActivated() ? "true" : "false") << new QStandardItem(QString::number(user->GetRoleID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(UserItem);
					
			
			delete role;
			dialogBL->CommitTransaction(errorMessage);
			this->close();
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

void CreateUserDlg::EditUser()
{
	errorMessage.clear();
	if (!(nameEdit->text().isEmpty() || phoneEdit->text().isEmpty() || addressEdit->text().isEmpty() || emailEdit->text().isEmpty() ||
		surnameEdit->text().isEmpty() || passwordEdit->text().isEmpty() || activatedCmbBox->currentText().isEmpty()) &&
		0 != roleEdit->text().toInt())
	{
		if (QString(user->GetName().c_str()) != nameEdit->text() || QString(user->GetAddress().c_str()) != addressEdit->text() ||
			QString(user->GetPhone().c_str()) != phoneEdit->text() || QString(user->GetSurname().c_str()) != surnameEdit->text() ||
			QString(user->GetEmail().c_str()) != emailEdit->text() || user->GetRoleID() != roleEdit->text().toInt() ||
			QString(user->GetPassword().c_str()) != passwordEdit->text() ||	QString(user->GetActivated()? "true":"false") != activatedCmbBox->currentText())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetUserParams(emailEdit->text(), nameEdit->text(), surnameEdit->text(), phoneEdit->text(), addressEdit->text(),
				roleEdit->text().toInt(), passwordEdit->text(), activatedCmbBox->currentText(), user->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateUser(user, errorMessage))
			{
				//updating user data
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(user->GetName().c_str());
				itemModel->item(mIndex.row(), 9)->setText(user->GetEmail().c_str());
				itemModel->item(mIndex.row(), 10)->setText(user->GetSurname().c_str());
				itemModel->item(mIndex.row(), 2)->setText(user->GetAddress().c_str());
				itemModel->item(mIndex.row(), 3)->setText(user->GetPhone().c_str());
				
				//if role of user is changed, then update location data fields
				BusinessLayer::Role *role = new BusinessLayer::Role();
				if (!role->GetRoleByID(dialogBL->GetOrmasDal(), user->GetRoleID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));

					errorMessage.clear();
					delete role;
					return;
				}
				itemModel->item(mIndex.row(), 8)->setText(role->GetName().c_str());
				itemModel->item(mIndex.row(), 11)->setText(passwordEdit->text());
				itemModel->item(mIndex.row(), 12)->setText(user->GetActivated() ? "true" : "false");
				itemModel->item(mIndex.row(), 13)->setText(QString::number(user->GetRoleID()));
						
				emit itemModel->dataChanged(mIndex, mIndex);
				
				
				delete role;
				dialogBL->CommitTransaction(errorMessage);
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

void CreateUserDlg::Close()
{
	this->close();
}

void CreateUserDlg::OpenRoleDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Roles"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::Role>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createUserDlg = this;
		dForm->setObjectName("roleForm");
		dForm->QtConnect<BusinessLayer::Role>();
		QMdiSubWindow *roleWindow = new QMdiSubWindow;
		roleWindow->setWidget(dForm);
		roleWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(roleWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
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
