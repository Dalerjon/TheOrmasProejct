#include "stdafx.h"
#include "CreatePrcDlg.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"


CreatePrcDlg::CreatePrcDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	productEdit->setValidator(vInt);
	valueEdit->setValidator(vDouble);
	currencyEdit->setValidator(vInt);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreatePrcDlg::EditPrice);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreatePrcDlg::CreatePrice);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreatePrcDlg::Close);
	QObject::connect(productBtn, &QPushButton::released, this, &CreatePrcDlg::OpenPrdDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreatePrcDlg::OpenCurDlg);
}

CreatePrcDlg::~CreatePrcDlg()
{
	delete vDouble;
	delete vInt;
}


void CreatePrcDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("productForm"))
			{
				productEdit->setText(QString::number(ID));
			}
			if (childName == QString("currencyForm"))
			{
				currencyEdit->setText(QString::number(ID));
			}
		}
	}
}

void CreatePrcDlg::SetPriceParams(QString pDate, double pValue, int pProductID, int pCurrencyID, int id)
{
	price->SetDate(pDate.toUtf8().constData());
	price->SetValue(pValue);
	price->SetProductID(pProductID);
	price->SetCurrencyID(pCurrencyID);
	price->SetID(id);
}

void CreatePrcDlg::FillEditElements(QString pDate, double pValue, int pProductID, int pCurrencyID)
{
	dateEdit->setDate(QDate::fromString(pDate, "yyyy-MM-dd"));
	valueEdit->setText(QString::number(pValue));
	productEdit->setText(QString::number(pProductID));
	currencyEdit->setText(QString::number(pCurrencyID));
}

bool CreatePrcDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetPriceParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 3)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 8)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 7)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 3)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 8)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 7)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreatePrcDlg::CreatePrice()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && 0 != currencyEdit->text().toInt()
		&& !dateEdit->text().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetPriceParams(dateEdit->text(), valueEdit->text().toDouble(), productEdit->text().toInt(), currencyEdit->text().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreatePrice(price, errorMessage))
		{
			BusinessLayer::Product *product = new BusinessLayer::Product;
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;
			if (!product->GetProductByID(dialogBL->GetOrmasDal(), price->GetProductID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), price->GetCurrencyID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete product;
				delete currency;
				
				return;
			}
			BusinessLayer::Measure *measure = new BusinessLayer::Measure();
			if (!measure->GetMeasureByID(dialogBL->GetOrmasDal(), product->GetMeasureID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete measure;
			}
			QList<QStandardItem*> PriceItem;
			PriceItem << new QStandardItem(QString::number(price->GetID()))
				<< new QStandardItem(price->GetDate().c_str())
				<< new QStandardItem(product->GetName().c_str())
				<< new QStandardItem(QString::number(product->GetVolume()))
				<< new QStandardItem(measure->GetName().c_str())
				<< new QStandardItem(QString::number(price->GetValue()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(QString::number(price->GetCurrencyID()))
				<< new QStandardItem(QString::number(price->GetProductID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(PriceItem);
			this->close();
			dialogBL->CommitTransaction(errorMessage);
			delete product;
			delete currency;
			delete measure;
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
			QString(tr("Please fill user, value, date and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreatePrcDlg::EditPrice()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && 0 != currencyEdit->text().toInt()
		&& !dateEdit->text().isEmpty())
	{
		if (QString(price->GetDate().c_str()) != dateEdit->text() || price->GetProductID() != productEdit->text().toInt()
			|| price->GetValue() != valueEdit->text().toDouble() || price->GetCurrencyID() != currencyEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetPriceParams(dateEdit->text(), valueEdit->text().toDouble(), productEdit->text().toInt(), currencyEdit->text().toInt(), price->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdatePrice(price, errorMessage))
			{
				BusinessLayer::Product *product = new BusinessLayer::Product;
				BusinessLayer::Currency *currency = new BusinessLayer::Currency;
				if (!product->GetProductByID(dialogBL->GetOrmasDal(), price->GetProductID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), price->GetCurrencyID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete product;
					delete currency;

					return;
				}
				BusinessLayer::Measure *measure = new BusinessLayer::Measure();
				if (!measure->GetMeasureByID(dialogBL->GetOrmasDal(), product->GetMeasureID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete measure;
				}
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(price->GetDate().c_str());
				itemModel->item(mIndex.row(), 2)->setText(product->GetName().c_str());
				itemModel->item(mIndex.row(), 3)->setText(QString::number(product->GetVolume()));
				itemModel->item(mIndex.row(), 4)->setText(measure->GetName().c_str());
				itemModel->item(mIndex.row(), 5)->setText(QString::number(price->GetValue()));
				itemModel->item(mIndex.row(), 6)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 7)->setText(QString::number(price->GetCurrencyID()));
				itemModel->item(mIndex.row(), 8)->setText(QString::number(price->GetProductID()));
				emit itemModel->dataChanged(mIndex, mIndex);
				this->close();
				dialogBL->CommitTransaction(errorMessage);
				delete product;
				delete currency;
				delete measure;
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

void CreatePrcDlg::Close()
{
	this->close();
}

void CreatePrcDlg::OpenPrdDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Products"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::ProductView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createPrcDlg = this;
		dForm->setObjectName("productForm");
		dForm->QtConnect<BusinessLayer::ProductView>();
		QMdiSubWindow *userWindow = new QMdiSubWindow;
		userWindow->setWidget(dForm);
		userWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(userWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All products are shown");
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

void CreatePrcDlg::OpenCurDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Currencies"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::Currency>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createPrcDlg = this;
		dForm->setObjectName("currencyForm");
		dForm->QtConnect<BusinessLayer::Currency>();
		QMdiSubWindow *returnWindow = new QMdiSubWindow;
		returnWindow->setWidget(dForm);
		returnWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(returnWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All currency are shown");
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