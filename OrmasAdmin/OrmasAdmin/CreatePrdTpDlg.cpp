#include "stdafx.h"
#include <QMessageBox>
#include "CreatePrdTpDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreatePrdTpDlg::CreatePrdTpDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	nameEdit->setMaxLength(50);
	shortNameEdit->setMaxLength(10);	
	dialogBL = ormasBL;
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreatePrdTpDlg::EditProductType);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreatePrdTpDlg::CreateProductType);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreatePrdTpDlg::Close);
}

void CreatePrdTpDlg::SetProdTypeParams(QString pName, QString pShortName, int id)
{
	prodType->SetName(pName.toUtf8().constData());
	prodType->SetShortName(pShortName.toUtf8().constData());
	prodType->SetID(id);
}

void CreatePrdTpDlg::FillEditElements(QString pName, QString pShortName)
{
	nameEdit->setText(pName);
	shortNameEdit->setText(pShortName);
}

bool CreatePrdTpDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetProdTypeParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData());
		return true;
	}
	else
	{
		return false;
	}
}

void CreatePrdTpDlg::CreateProductType()
{
	errorMessage.clear();
	if (!(nameEdit->text().isEmpty() || shortNameEdit->text().isEmpty()))
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetProdTypeParams(nameEdit->text(), shortNameEdit->text());
		if (dialogBL->CreateProductType(prodType, errorMessage))
		{
			QList<QStandardItem*> prodTypeItem;
			prodTypeItem << new QStandardItem(QString::number(prodType->GetID())) << new QStandardItem(prodType->GetName().c_str())
				<< new QStandardItem(prodType->GetShortName().c_str());
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(prodTypeItem);
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

void CreatePrdTpDlg::EditProductType()
{
	errorMessage.clear();
	if (!(nameEdit->text().isEmpty() || shortNameEdit->text().isEmpty()))
	{
		if (QString(prodType->GetName().c_str()) != nameEdit->text() || QString(prodType->GetShortName().c_str()) != shortNameEdit->text())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetProdTypeParams(nameEdit->text(), shortNameEdit->text(), GetIDFromTable(parentDataForm->tableView, errorMessage));
			if (dialogBL->UpdateProductType(prodType, errorMessage))
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
			QString(tr("Please fill name, phone and address!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreatePrdTpDlg::Close()
{
	this->close();
}

