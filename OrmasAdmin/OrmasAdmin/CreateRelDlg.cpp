#include "stdafx.h"
#include "CreateRelDlg.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"


CreateRelDlg::CreateRelDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	vInt = new QIntValidator(0, 1000000000, this);
	user1Edit->setValidator(vInt);
	user2Edit->setValidator(vInt);
	relTypeEdit->setValidator(vInt);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateRelDlg::EditRelation);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateRelDlg::CreateRelation);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateRelDlg::Close);
	QObject::connect(user1Btn, &QPushButton::released, this, &CreateRelDlg::OpenUser1Dlg);
	QObject::connect(user2Btn, &QPushButton::released, this, &CreateRelDlg::OpenUser2Dlg);
	QObject::connect(relTypeBtn, &QPushButton::released, this, &CreateRelDlg::OpenRelTypeDlg);
}

CreateRelDlg::~CreateRelDlg()
{
	delete vInt;
}


void CreateRelDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("user1Form"))
			{
				user1Edit->setText(QString::number(ID));
			}
			if (childName == QString("user2Form"))
			{
				user2Edit->setText(QString::number(ID));
			}
			if (childName == QString("relTypeForm"))
			{
				relTypeEdit->setText(QString::number(ID));
			}
		}
	}
}

void CreateRelDlg::SetRelationParams(int rUser1ID, int rUser2ID, int rRelTypeID, int id)
{
	relation->SetUser1ID(rUser1ID);
	relation->SetUser2ID(rUser2ID);
	relation->SetRelationTypeID(rRelTypeID);
	relation->SetID(id);
}

void CreateRelDlg::FillEditElements(int rUser1ID, int rUser2ID, int rRelTypeID)
{
	user1Edit->setText(QString::number(rUser1ID));
	user2Edit->setText(QString::number(rUser2ID));
	relTypeEdit->setText(QString::number(rRelTypeID));
}

bool CreateRelDlg::FillDlgElements(QTableView* bTable)
{
	QModelIndex mIndex = bTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetRelationParams(bTable->model()->data(bTable->model()->index(mIndex.row(), 1)).toInt(),
			bTable->model()->data(bTable->model()->index(mIndex.row(), 2)).toInt(),
			bTable->model()->data(bTable->model()->index(mIndex.row(), 3)).toInt(),
			bTable->model()->data(bTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(bTable->model()->data(bTable->model()->index(mIndex.row(), 1)).toInt(),
			bTable->model()->data(bTable->model()->index(mIndex.row(), 2)).toInt(),
			bTable->model()->data(bTable->model()->index(mIndex.row(), 3)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateRelDlg::CreateRelation()
{
	errorMessage.clear();
	if (0 != user1Edit->text().toInt() || 0 != user2Edit->text().toInt() || 0 != relTypeEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetRelationParams(user1Edit->text().toInt(), user2Edit->text().toInt(), relTypeEdit->text().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateRelation(relation, errorMessage))
		{
			QList<QStandardItem*> relationItem;
			relationItem << new QStandardItem(QString::number(relation->GetID())) << new QStandardItem(QString::number(relation->GetUser1ID()))
				<< new QStandardItem(QString::number(relation->GetUser2ID())) << new QStandardItem(QString::number(relation->GetRelationTypeID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(relationItem);
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
			QString(tr("Please fill user1, user2 and relation type!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateRelDlg::EditRelation()
{
	errorMessage.clear();
	if(0 != user1Edit->text().toInt() || 0 != user2Edit->text().toInt() || 0 != relTypeEdit->text().toInt())
	{
		if (relation->GetUser1ID() != user1Edit->text().toInt() || relation->GetUser2ID() != user2Edit->text().toInt()
			|| relation->GetRelationTypeID() != relTypeEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetRelationParams(user1Edit->text().toInt(), user2Edit->text().toInt(), relTypeEdit->text().toInt(), relation->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateRelation(relation, errorMessage))
			{
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(QString::number(relation->GetUser1ID()));
				itemModel->item(mIndex.row(), 2)->setText(QString::number(relation->GetUser1ID()));
				itemModel->item(mIndex.row(), 3)->setText(QString::number(relation->GetRelationTypeID()));
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
			QString(tr("Please fill user, value and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateRelDlg::Close()
{
	this->close();
}

void CreateRelDlg::OpenUser1Dlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("First user"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::UserView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createRelDlg = this;
		dForm->setObjectName("user1Form");
		dForm->QtConnect<BusinessLayer::UserView>();
		QMdiSubWindow *userWindow = new QMdiSubWindow;
		userWindow->setWidget(dForm);
		userWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(userWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All users are shown");
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

void CreateRelDlg::OpenUser2Dlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Second user"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::UserView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createRelDlg = this;
		dForm->setObjectName("user2Form");
		dForm->QtConnect<BusinessLayer::UserView>();
		QMdiSubWindow *userWindow = new QMdiSubWindow;
		userWindow->setWidget(dForm);
		userWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(userWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All users are shown");
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

void CreateRelDlg::OpenRelTypeDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Relation types"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::RelationType>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createRelDlg = this;
		dForm->setObjectName("relTypeForm");
		dForm->QtConnect<BusinessLayer::RelationType>();
		QMdiSubWindow *returnWindow = new QMdiSubWindow;
		returnWindow->setWidget(dForm);
		returnWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(returnWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All relation types are shown");
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