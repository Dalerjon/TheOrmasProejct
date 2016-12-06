#include "stdafx.h"
#include <QMessageBox>
#include "CreateMsrDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateMsrDlg::CreateMsrDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	shortNameEdit->setMaxLength(4);
	nameEdit->setMaxLength(15);
	dialogBL = ormasBL;
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateMsrDlg::EditMeasure);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateMsrDlg::CreateMeasure);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateMsrDlg::Close);
}

void CreateMsrDlg::SetMeasureParams(QString mName, QString mShortName, int id)
{
	measure->SetName(mName.toUtf8().constData());
	measure->SetShortName(mShortName.toUtf8().constData());
	measure->SetID(id);
}

void CreateMsrDlg::FillEditElements(QString mName, QString mShortName)
{
	nameEdit->setText(mName);
	shortNameEdit->setText(mShortName);
}

bool CreateMsrDlg::FillDlgElements(QTableView* mTable)
{
	QModelIndex mIndex = mTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetMeasureParams(mTable->model()->data(mTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			mTable->model()->data(mTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			mTable->model()->data(mTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(mTable->model()->data(mTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			mTable->model()->data(mTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateMsrDlg::CreateMeasure()
{
	errorMessage.clear();
	if (!(nameEdit->text().isEmpty() || shortNameEdit->text().isEmpty()))
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetMeasureParams(nameEdit->text(), shortNameEdit->text());
		if (dialogBL->CreateMeasure(measure,errorMessage))
		{
			QList<QStandardItem*> measureItem;
			measureItem << new QStandardItem(QString::number(measure->GetID())) << new QStandardItem(measure->GetName().c_str())
				<< new QStandardItem(measure->GetShortName().c_str());
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(measureItem);
			this->close();
		}
		else
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please fill name and short name!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateMsrDlg::EditMeasure()
{
	errorMessage.clear();
	if (!(nameEdit->text().isEmpty() || shortNameEdit->text().isEmpty()))
	{
		if (QString(measure->GetName().c_str()) != nameEdit->text() || QString(measure->GetShortName().c_str()) != shortNameEdit->text())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetMeasureParams(nameEdit->text(), shortNameEdit->text(), GetIDFromTable(parentDataForm->tableView, errorMessage));
			if (dialogBL->UpdateMeasure(measure,errorMessage))
			{
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(nameEdit->text());
				itemModel->item(mIndex.row(), 2)->setText(shortNameEdit->text());
				emit itemModel->dataChanged(mIndex, mIndex);
				this->close();
			}
			else
			{
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
			QString(tr("Please fill name and short name!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateMsrDlg::Close()
{
	this->close();
}
