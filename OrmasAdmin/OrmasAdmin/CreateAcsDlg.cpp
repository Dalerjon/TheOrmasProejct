#include "stdafx.h"
#include "CreateAcsDlg.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"


CreateAcsDlg::CreateAcsDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	vInt = new QIntValidator(0, 1000000000, this);
	roleEdit->setValidator(vInt);
	acsItemEdit->setValidator(vInt);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateAcsDlg::EditAccess);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateAcsDlg::CreateAccess);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateAcsDlg::Close);
	QObject::connect(roleBtn, &QPushButton::released, this, &CreateAcsDlg::OpenRoleDlg);
	QObject::connect(acsItemBtn, &QPushButton::released, this, &CreateAcsDlg::OpenAcsItemDlg);
}

CreateAcsDlg::~CreateAcsDlg()
{
	delete vInt;
}


void CreateAcsDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("roleForm"))
			{
				roleEdit->setText(QString::number(ID));
			}
			if (childName == QString("accessItemForm"))
			{
				acsItemEdit->setText(QString::number(ID));
			}
		}
	}
}


void CreateAcsDlg::SetAccessParams(int aRoleID, int aAccessTypeID, int id)
{
	access->SetRoleID(aRoleID);
	access->SetAccessItemID(aAccessTypeID);
	access->SetID(id);
}

void CreateAcsDlg::FillEditElements(int aRoleID, int aAccessTypeID)
{
	roleEdit->setText(QString::number(aRoleID));
	acsItemEdit->setText(QString::number(aAccessTypeID));
}

bool CreateAcsDlg::FillDlgElements(QTableView* aTable)
{
	QModelIndex mIndex = aTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetAccessParams(aTable->model()->data(aTable->model()->index(mIndex.row(), 1)).toInt(),
			aTable->model()->data(aTable->model()->index(mIndex.row(), 2)).toInt(),
			aTable->model()->data(aTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(aTable->model()->data(aTable->model()->index(mIndex.row(), 1)).toInt(),
			aTable->model()->data(aTable->model()->index(mIndex.row(), 2)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateAcsDlg::CreateAccess()
{
	errorMessage.clear();
	if (!roleEdit->text().isEmpty() && !acsItemEdit->text().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetAccessParams(roleEdit->text().toInt(), acsItemEdit->text().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateAccess(access, errorMessage))
		{
			QList<QStandardItem*> accessItem;
			accessItem << new QStandardItem(QString::number(access->GetID())) << new QStandardItem(QString::number(access->GetRoleID()))
				<< new QStandardItem(QString::number(access->GetAccessItemID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(accessItem);
			this->close();
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
			QString(tr("Please fill role, access item!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateAcsDlg::EditAccess()
{
	errorMessage.clear();
	if (!roleEdit->text().isEmpty() && !acsItemEdit->text().isEmpty())
	{
		if (access->GetRoleID() != roleEdit->text().toInt() || access->GetAccessItemID() != acsItemEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetAccessParams(roleEdit->text().toInt(), acsItemEdit->text().toInt(), access->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateAccess(access, errorMessage))
			{
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(QString::number(access->GetRoleID()));
				itemModel->item(mIndex.row(), 2)->setText(QString::number(access->GetAccessItemID()));
				emit itemModel->dataChanged(mIndex, mIndex);
				this->close();
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
			QString(tr("Please enter role and access item!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateAcsDlg::Close()
{
	this->close();
}

void CreateAcsDlg::OpenRoleDlg()
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
		dForm->createAcsDlg = this;
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


void CreateAcsDlg::OpenAcsItemDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Access Item"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::AccessItem>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createAcsDlg = this;
		dForm->setObjectName("accessItemForm");
		dForm->QtConnect<BusinessLayer::AccessItem>();
		QMdiSubWindow *returnWindow = new QMdiSubWindow;
		returnWindow->setWidget(dForm);
		returnWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(returnWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All access items are shown");
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
