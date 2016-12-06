#include "stdafx.h"
#include <QMessageBox>
#include "CreateCurDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateCurDlg::CreateCurDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	QRegExp expr("\\d*");
	QRegExpValidator v(expr, 0);
	codeEdit->setValidator(&v);
	codeEdit->setMaxLength(3);
	shortNameEdit->setMaxLength(3);
	nameEdit->setMaxLength(20);
	dialogBL = ormasBL;
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateCurDlg::EditCurrency);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateCurDlg::CreateCurrency);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateCurDlg::Close);
}

void CreateCurDlg::SetCurrencyParams(int cCode, QString cShortName, QString cName, int id)
{
	currency->SetCode(cCode);
	currency->SetShortName(cShortName.toUtf8().constData());
	currency->SetName(cName.toUtf8().constData());
	currency->SetID(id);
}

void CreateCurDlg::FillEditElements(int cCode, QString cShortName, QString cName)
{
	codeEdit->setText(QString::number(cCode));
	shortNameEdit->setText(cShortName);
	nameEdit->setText(cName);
}

bool CreateCurDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetCurrencyParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateCurDlg::CreateCurrency()
{
	errorMessage.clear();
	if (!(codeEdit->text().isEmpty() || shortNameEdit->text().isEmpty() || nameEdit->text().isEmpty()))
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetCurrencyParams(codeEdit->text().toInt(), shortNameEdit->text(), nameEdit->text());
		if (dialogBL->CreateCurrency(currency,errorMessage))
		{
			QList<QStandardItem*> companyItem;
			companyItem << new QStandardItem(QString::number(currency->GetID())) << new QStandardItem(QString::number(currency->GetCode()))
				<< new QStandardItem(currency->GetShortName().c_str()) << new QStandardItem(currency->GetName().c_str());
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(companyItem);
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
			QString(tr("Please fill code, name and short name!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateCurDlg::EditCurrency()
{
	errorMessage.clear();
	if (!(codeEdit->text().isEmpty() || shortNameEdit->text().isEmpty() || nameEdit->text().isEmpty()))
	{
		if (currency->GetCode() != nameEdit->text().toInt() || QString(currency->GetShortName().c_str()) != shortNameEdit->text()
			|| QString(currency->GetName().c_str()) != nameEdit->text())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetCurrencyParams(codeEdit->text().toInt(), shortNameEdit->text(), nameEdit->text(), GetIDFromTable(parentDataForm->tableView, errorMessage));
			if (dialogBL->UpdateCurrency(currency,errorMessage))
			{
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(codeEdit->text());
				itemModel->item(mIndex.row(), 2)->setText(shortNameEdit->text());
				itemModel->item(mIndex.row(), 3)->setText(nameEdit->text());
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
			QString(tr("Please fill code, name and short name!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateCurDlg::Close()
{
	this->close();
}
