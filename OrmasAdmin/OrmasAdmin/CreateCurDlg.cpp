#include "stdafx.h"
#include <QMessageBox>
#include "CreateCurDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateCurDlg::CreateCurDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	vInt = new QIntValidator(0, 1000000000, this);
	codeEdit->setValidator(vInt);
	codeEdit->setMaxLength(3);
	shortNameEdit->setMaxLength(3);
	nameEdit->setMaxLength(20);
	unitEdit->setValidator(vInt);
	unitEdit->setMaxLength(10);
	mainTradeCmbBox->addItem("false");
	mainTradeCmbBox->addItem("true");
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

CreateCurDlg::~CreateCurDlg()
{
	delete vInt;
}

void CreateCurDlg::SetCurrencyParams(int cCode, QString cShortName, QString cName, int cUnit, QString cMainTrade, int id)
{
	currency->SetCode(cCode);
	currency->SetShortName(cShortName.toUtf8().constData());
	currency->SetName(cName.toUtf8().constData());
	currency->SetID(id);
	currency->SetUnit(cUnit);
	currency->SetMainTrade(cMainTrade == "true" ? true : false);
}

void CreateCurDlg::FillEditElements(int cCode, QString cShortName, QString cName, int cUnit, QString cMainTrade)
{
	codeEdit->setText(QString::number(cCode));
	shortNameEdit->setText(cShortName);
	nameEdit->setText(cName);
	unitEdit->setText(QString::number(cUnit));
	int index = mainTradeCmbBox->findText(cMainTrade);
	mainTradeCmbBox->setCurrentIndex(index);
}

bool CreateCurDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetCurrencyParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 4)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 5)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 2)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 3)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 4)).toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 5)).toString().toUtf8().constData());
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
	if (!(codeEdit->text().isEmpty() || shortNameEdit->text().isEmpty() || nameEdit->text().isEmpty()) || unitEdit->text().isEmpty()
		|| mainTradeCmbBox->currentText().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetCurrencyParams(codeEdit->text().toInt(), shortNameEdit->text(), nameEdit->text(), unitEdit->text().toInt(),
			mainTradeCmbBox->currentText());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateCurrency(currency,errorMessage))
		{
			QList<QStandardItem*> companyItem;
			companyItem << new QStandardItem(QString::number(currency->GetID())) << new QStandardItem(QString::number(currency->GetCode()))
				<< new QStandardItem(currency->GetShortName().c_str()) << new QStandardItem(currency->GetName().c_str())
				<< new QStandardItem(QString::number(currency->GetUnit())) << new QStandardItem(currency->GetMainTrade()?"true":"false");
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(companyItem);
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
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please fill code, name and short name!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateCurDlg::EditCurrency()
{
	errorMessage.clear();
	if (!(codeEdit->text().isEmpty() || shortNameEdit->text().isEmpty() || nameEdit->text().isEmpty()) || unitEdit->text().isEmpty()
		|| mainTradeCmbBox->currentText().isEmpty())
	{
		if (currency->GetCode() != nameEdit->text().toInt() || QString(currency->GetShortName().c_str()) != shortNameEdit->text()
			|| QString(currency->GetName().c_str()) != nameEdit->text() || currency->GetUnit() != nameEdit->text().toInt()
			|| QString(currency->GetMainTrade() ? "true" : "false") != mainTradeCmbBox->currentText())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetCurrencyParams(codeEdit->text().toInt(), shortNameEdit->text(), nameEdit->text(), unitEdit->text().toInt(),
				mainTradeCmbBox->currentText(), currency->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateCurrency(currency,errorMessage))
			{
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(QString::number(currency->GetCode()));
				itemModel->item(mIndex.row(), 2)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 3)->setText(currency->GetName().c_str());
				itemModel->item(mIndex.row(), 4)->setText(QString::number(currency->GetUnit()));
				itemModel->item(mIndex.row(), 5)->setText(currency->GetMainTrade() ? "true" : "false");
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
			QString(tr("Please fill code, name and short name!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateCurDlg::Close()
{
	this->close();
}
