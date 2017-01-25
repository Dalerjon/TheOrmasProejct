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
	activaredCmbBox->addItem("false");
	activaredCmbBox->addItem("true");
	locationEdit->setReadOnly(true);
	nameEdit->setMaxLength(30);
	phoneEdit->setMaxLength(25);
	addressEdit->setMaxLength(30);
	firmEdit->setMaxLength(30);
	firmNumEdit->setMaxLength(5);
	passwordEdit->setMaxLength(30);
	QRegExp expr("\\d*");
	QRegExpValidator v(expr, 0);
	locationEdit->setValidator(&v);
	roleEdit->setValidator(&v);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateUserDlg::EditUser);
	}
	else
	{
		locationEdit->setText("0");
		roleEdit->setText("0");
		QObject::connect(okBtn, &QPushButton::released, this, &CreateUserDlg::CreateUser);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateUserDlg::Close);
	QObject::connect(locationBtn, &QPushButton::released, this, &CreateUserDlg::OpenLcnDlg);
	QObject::connect(roleBtn, &QPushButton::released, this, &CreateUserDlg::OpenRoleDlg);
}

CreateUserDlg::~CreateUserDlg()
{
	delete user;
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
			}
			if (childName == QString("locationForm"))
			{
				locationEdit->setText(QString::number(ID));
			}
		}
	}
}

void CreateUserDlg::SetUserParams(QString uName, QString uPhone, QString uAddress, QString uFirm, QString uFirmNumber, 
	int uRoleID, int uLocationID, QString uPassword, QString uActivated, int id)
{
	user->SetName(uName.toUtf8().constData());
	user->SetPhone(uPhone.toUtf8().constData());
	user->SetAddress(uAddress.toUtf8().constData());
	user->SetFirm(uFirm.toUtf8().constData());
	user->SetFirmNumber(uFirmNumber.toUtf8().constData());
	user->SetRoleID(uRoleID);
	user->SetLocationID(uLocationID);
	user->SetPassword(uPassword.toUtf8().constData());
	user->SetActivated(uActivated == "true"? true : false);
	user->SetID(id);
}

void CreateUserDlg::FillEditElements(QString uName, QString uPhone, QString uAddress, QString uFirm, QString uFirmNumber,
	int uRoleID, int uLocationID, QString uPassword, QString uActivated)
{
	nameEdit->setText(uName);
	phoneEdit->setText(uPhone);
	addressEdit->setText(uAddress);
	firmEdit->setText(uFirm);
	firmNumEdit->setText(uFirmNumber);
	roleEdit->setText(QString::number(uRoleID));
	locationEdit->setText(QString::number(uLocationID));
	passwordEdit->setText(uPassword);
	int index = activaredCmbBox->findText(uActivated);
	activaredCmbBox->setCurrentIndex(index);
}

bool CreateUserDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetUserParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 9)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 10)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 13)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 14)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 11)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 12)).toString().toUtf8().constData() == "Yes" ? "true" : "false",
			cTable->model()->data(cTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 9)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 10)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 13)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 14)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 11)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 12)).toString().toUtf8().constData() == "Yes" ? "true" : "false");
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
	if (!(nameEdit->text().isEmpty() || phoneEdit->text().isEmpty() || addressEdit->text().isEmpty() || firmEdit->text().isEmpty() ||
		firmNumEdit->text().isEmpty() || passwordEdit->text().isEmpty()	|| activaredCmbBox->currentText().isEmpty()) &&
		0 != roleEdit->text().toInt() && 0 != locationEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetUserParams(nameEdit->text(), phoneEdit->text(), addressEdit->text(), firmEdit->text(),
			firmNumEdit->text(), roleEdit->text().toInt(), locationEdit->text().toInt(), passwordEdit->text(),
			activaredCmbBox->currentText());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateUser(user, errorMessage))
		{
			BusinessLayer::Role *role = new BusinessLayer::Role();
			//role->SetID(roleEdit->text().toInt());
			//std::string roleFilter = dialogBL->GenerateFilter<BusinessLayer::Role>(role);
			//std::vector<BusinessLayer::Role> roleVector = dialogBL->GetAllDataForClass<BusinessLayer::Role>(errorMessage, roleFilter);
			BusinessLayer::Location *location = new BusinessLayer::Location();
			//location->SetID(locationEdit->text().toInt());
			//std::string locationFilter = dialogBL->GenerateFilter<BusinessLayer::Location>(location);
			//std::vector<BusinessLayer::Location> locationVector = dialogBL->GetAllDataForClass<BusinessLayer::Location>(errorMessage, locationFilter);
			if (!role->GetRoleByID(dialogBL->GetOrmasDal(),user->GetRoleID(),errorMessage)
				|| !location->GetLocationByID(dialogBL->GetOrmasDal(), user->GetLocationID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));

				errorMessage.clear();
				delete location;
				delete role;
				return;
			}
			QList<QStandardItem*> UserItem;
			UserItem << new QStandardItem(QString::number(user->GetID())) << new QStandardItem(user->GetName().c_str())
				<< new QStandardItem(user->GetPhone().c_str()) << new QStandardItem(user->GetAddress().c_str())
				<< new QStandardItem(location->GetCountryName().c_str()) 
				<< new QStandardItem(location->GetCountryCode().c_str())
				<< new QStandardItem(location->GetRegionName().c_str())
				<< new QStandardItem(location->GetCityName().c_str())
				<< new QStandardItem(role->GetName().c_str()) << new QStandardItem(user->GetFirm().c_str())
				<< new QStandardItem(user->GetFirmNumber().c_str()) << new QStandardItem(user->GetPassword().c_str())
				<< new QStandardItem(user->GetActivated()?"Yes":"No") << new QStandardItem(QString::number(user->GetRoleID()))
				<< new QStandardItem(QString::number(user->GetLocationID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(UserItem);
					
			this->close();
			
			delete location;
			delete role;
			dialogBL->CommitTransaction(errorMessage);
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
	if (!(nameEdit->text().isEmpty() || phoneEdit->text().isEmpty() || addressEdit->text().isEmpty() || firmEdit->text().isEmpty() ||
		firmNumEdit->text().isEmpty() || passwordEdit->text().isEmpty() || activaredCmbBox->currentText().isEmpty()) &&
		0 != roleEdit->text().toInt() && 0 != locationEdit->text().toInt())
	{
		if (QString(user->GetName().c_str()) != nameEdit->text() || QString(user->GetAddress().c_str()) != addressEdit->text() ||
			QString(user->GetPhone().c_str()) != phoneEdit->text() || QString(user->GetFirm().c_str()) != firmEdit->text() ||
			QString(user->GetFirmNumber().c_str()) != firmNumEdit->text() || user->GetRoleID() != roleEdit->text().toInt() ||
			user->GetLocationID() != locationEdit->text().toInt() || QString(user->GetPassword().c_str()) != passwordEdit->text() ||
			QString(user->GetActivated()? "true":"false") != activaredCmbBox->currentText())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetUserParams(nameEdit->text(), phoneEdit->text(), addressEdit->text(), firmEdit->text(),
				firmNumEdit->text(), roleEdit->text().toInt(), locationEdit->text().toInt(), passwordEdit->text(),
				activaredCmbBox->currentText(), user->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateUser(user, errorMessage))
			{
				//updating user data
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(user->GetName().c_str());
				itemModel->item(mIndex.row(), 2)->setText(user->GetAddress().c_str());
				itemModel->item(mIndex.row(), 3)->setText(user->GetPhone().c_str());
				
				//if location of user is changed, then update location data fields
				BusinessLayer::Location *location = new BusinessLayer::Location();
				//location->SetID(locationEdit->text().toInt());
				//std::string locationFilter = dialogBL->GenerateFilter<BusinessLayer::Location>(location);
				//std::vector<BusinessLayer::Location> locationVector = dialogBL->GetAllDataForClass<BusinessLayer::Location>(errorMessage, locationFilter);
				
				//if role of user is changed, then update location data fields
				BusinessLayer::Role *role = new BusinessLayer::Role();
				//role->SetID(roleEdit->text().toInt());
				//std::string roleFilter = dialogBL->GenerateFilter<BusinessLayer::Role>(role);
				//std::vector<BusinessLayer::Role> roleVector = dialogBL->GetAllDataForClass<BusinessLayer::Role>(errorMessage, roleFilter);
				if (!role->GetRoleByID(dialogBL->GetOrmasDal(), user->GetRoleID(), errorMessage)
					|| !location->GetLocationByID(dialogBL->GetOrmasDal(), user->GetLocationID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));

					errorMessage.clear();
					delete location;
					delete role;
					return;
				}
				itemModel->item(mIndex.row(), 4)->setText(location->GetCountryName().c_str());
				itemModel->item(mIndex.row(), 5)->setText(location->GetCountryCode().c_str());
				itemModel->item(mIndex.row(), 6)->setText(location->GetRegionName().c_str());
				itemModel->item(mIndex.row(), 7)->setText(location->GetCityName().c_str());
				itemModel->item(mIndex.row(), 8)->setText(role->GetName().c_str());
				itemModel->item(mIndex.row(), 9)->setText(user->GetFirm().c_str());
				itemModel->item(mIndex.row(), 10)->setText(user->GetFirmNumber().c_str());
				itemModel->item(mIndex.row(), 11)->setText(passwordEdit->text());
				itemModel->item(mIndex.row(), 12)->setText(activaredCmbBox->currentText());
				itemModel->item(mIndex.row(), 13)->setText(QString::number(user->GetRoleID()));
				itemModel->item(mIndex.row(), 14)->setText(QString::number(user->GetLocationID()));				
						
				emit itemModel->dataChanged(mIndex, mIndex);
				this->close();
				
				delete location;
				delete role;
				dialogBL->CommitTransaction(errorMessage);
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

void CreateUserDlg::OpenLcnDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Locations"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::Location>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createUserDlg = this;
		dForm->setObjectName("locationForm");
		dForm->QtConnect<BusinessLayer::Location>();
		QMdiSubWindow *locationWindow = new QMdiSubWindow;
		locationWindow->setWidget(dForm);
		locationWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(locationWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All locations are shown");
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
