#include "stdafx.h"
#include "CreateEtrRtDlg.h"

#include "MainForm.h"
#include "DataForm.h"



CreateEtrRtDlg::CreateEtrRtDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	parentForm = parent;
	vInt = new QIntValidator(0, 1000000000, this);
	debitEdit->setValidator(vInt);
	creditEdit->setValidator(vInt);
	debitEdit->setMaxLength(7);
	creditEdit->setMaxLength(7);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateEtrRtDlg::EditEntryRouting);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateEtrRtDlg::CreateEntryRouting);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateEtrRtDlg::Close);
}

CreateEtrRtDlg::~CreateEtrRtDlg()
{
	delete vInt;
}

void CreateEtrRtDlg::SetEntryRoutingParams(QString eOperation, int eDebit, int eCredit, int id)
{
	entryRouting->SetOperation(eOperation.toUtf8().constData());
	entryRouting->SetDebit(eDebit);
	entryRouting->SetCredit(eCredit);
	entryRouting->SetID(id);
}

void CreateEtrRtDlg::FillEditElements(QString eOperation, int eDebit, int eCredit)
{
	operationEdit->setText(eOperation);
	debitEdit->setText(QString::number(eDebit));
	creditEdit->setText(QString::number(eCredit));
}

bool CreateEtrRtDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetEntryRoutingParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 3)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 3)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateEtrRtDlg::CreateEntryRouting()
{
	errorMessage.clear();
	if (0 != debitEdit->text().toInt() && 0 != creditEdit->text().toInt() && !operationEdit->text().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*) parentForm;
		SetEntryRoutingParams(operationEdit->text(), debitEdit->text().toInt(), creditEdit->text().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateEntryRouting(entryRouting, errorMessage))
		{
			if (parentDataForm != nullptr)
			{
				if (!parentDataForm->IsClosed())
				{
					QList<QStandardItem*> entryRoutingItem;
					entryRoutingItem << new QStandardItem(QString::number(entryRouting->GetID()))
						<< new QStandardItem(entryRouting->GetOperation().c_str())
						<< new QStandardItem(QString::number(entryRouting->GetDebit()))
						<< new QStandardItem(QString::number(entryRouting->GetCredit()));
					QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
					itemModel->appendRow(entryRoutingItem);
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
			QString(tr("Please fill operation, debit and credit!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateEtrRtDlg::EditEntryRouting()
{
	errorMessage.clear();
	if (0 != debitEdit->text().toInt() && 0 != creditEdit->text().toInt() && !operationEdit->text().isEmpty())
	{
		if (QString(entryRouting->GetOperation().c_str()) != operationEdit->text() || entryRouting->GetCredit() != creditEdit->text().toInt()
			|| entryRouting->GetDebit() != debitEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*) parentForm;
			SetEntryRoutingParams(operationEdit->text(), debitEdit->text().toInt(), creditEdit->text().toInt(), entryRouting->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateEntryRouting(entryRouting, errorMessage))
			{
				if (parentDataForm != nullptr)
				{
					if (!parentDataForm->IsClosed())
					{
						QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
						QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
						itemModel->item(mIndex.row(), 1)->setText(entryRouting->GetOperation().c_str());
						itemModel->item(mIndex.row(), 2)->setText(QString::number(entryRouting->GetDebit()));
						itemModel->item(mIndex.row(), 3)->setText(QString::number(entryRouting->GetCredit()));
						emit itemModel->dataChanged(mIndex, mIndex);
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
			QString(tr("Please fill operation, debit and credit!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateEtrRtDlg::Close()
{
	this->parentWidget()->close();
}