#include "stdafx.h"
#include "CreatePcrDlg.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"


CreatePcrDlg::CreatePcrDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	valueEdit->setValidator(vDouble);
	positionEdit->setValidator(vInt);
	valueEdit->setMaxLength(17);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreatePcrDlg::EditPercentRate);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreatePcrDlg::CreatePercentRate);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreatePcrDlg::Close);
	QObject::connect(positionBtn, &QPushButton::released, this, &CreatePcrDlg::OpenPosDlg);
}

CreatePcrDlg::~CreatePcrDlg()
{
	delete vInt;
	delete vDouble;
}

void CreatePcrDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("positionForm"))
			{
				positionEdit->setText(QString::number(ID));
			}
		}
	}
}

void CreatePcrDlg::SetPercentRateParams(double pValue, QString pCondition, int posID, int id)
{
	percentRate->SetValue(pValue);
	percentRate->SetCondition(pCondition.toUtf8().constData());
	percentRate->SetPositionID(posID);
	percentRate->SetID(id);
}

void CreatePcrDlg::FillEditElements(double pValue, QString pCondition, int posID)
{
	valueEdit->setText(QString::number(pValue));
	conditionEdit->setText(pCondition);
	positionEdit->setText(QString::number(posID));
}

bool CreatePcrDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetPercentRateParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 3)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 3)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreatePcrDlg::CreatePercentRate()
{
	errorMessage.clear();
	if (0.0 != valueEdit->text().toDouble() && 0 != positionEdit->text().toInt()
		&& !conditionEdit->text().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetPercentRateParams(valueEdit->text().toDouble(), conditionEdit->text(), positionEdit->text().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreatePercentRate(percentRate, errorMessage))
		{
			BusinessLayer::Position *position = new BusinessLayer::Position;
			if (!position->GetPositionByID(dialogBL->GetOrmasDal(), percentRate->GetPositionID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete position;
				return;
			}
			QList<QStandardItem*> PercentRateItem;
			PercentRateItem << new QStandardItem(QString::number(percentRate->GetID()))
				<< new QStandardItem(QString::number(percentRate->GetValue()))
				<< new QStandardItem(percentRate->GetCondition().c_str())
				<< new QStandardItem(QString::number(percentRate->GetPositionID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(PercentRateItem);
			
			dialogBL->CommitTransaction(errorMessage);
			delete position;
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
			QString(tr("Please fill position, condition and value!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreatePcrDlg::EditPercentRate()
{
	errorMessage.clear();
	if (0.0 != valueEdit->text().toDouble() && 0 != positionEdit->text().toInt()
		&& !conditionEdit->text().isEmpty())
	{
		if (percentRate->GetValue() != valueEdit->text().toDouble() || QString(percentRate->GetCondition().c_str()) != conditionEdit->text() ||
			percentRate->GetPositionID() != positionEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetPercentRateParams(valueEdit->text().toDouble(), conditionEdit->text(), positionEdit->text().toInt(), percentRate->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdatePercentRate(percentRate, errorMessage))
			{
				BusinessLayer::Position *position = new BusinessLayer::Position;
				if (!position->GetPositionByID(dialogBL->GetOrmasDal(), percentRate->GetPositionID(), errorMessage))
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
				itemModel->item(mIndex.row(), 1)->setText(QString::number(percentRate->GetValue()));
				itemModel->item(mIndex.row(), 2)->setText(percentRate->GetCondition().c_str());
				itemModel->item(mIndex.row(), 3)->setText(QString::number(percentRate->GetPositionID()));
				emit itemModel->dataChanged(mIndex, mIndex);
				
				dialogBL->CommitTransaction(errorMessage);
				delete position;
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
			QString(tr("Please fill position, condition and value!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreatePcrDlg::Close()
{
	this->close();
}

void CreatePcrDlg::OpenPosDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("positions"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::Position>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createPcrDlg = this;
		dForm->setObjectName("positionForm");
		dForm->QtConnect<BusinessLayer::Position>();
		QMdiSubWindow *currencyWindow = new QMdiSubWindow;
		currencyWindow->setWidget(dForm);
		currencyWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(currencyWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
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