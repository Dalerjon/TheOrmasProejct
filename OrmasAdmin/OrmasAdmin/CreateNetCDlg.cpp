#include "stdafx.h"
#include "CreateNetCDlg.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"


CreateNetCDlg::CreateNetCDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	productEdit->setValidator(vInt);
	valueEdit->setValidator(vDouble);
	valueEdit->setMaxLength(17);
	isOutdatedCmb->addItem("false");
	isOutdatedCmb->addItem("true");
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateNetCDlg::EditNetCost);
	}
	else
	{
		dateEdit->setDateTime(QDateTime::currentDateTime());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateNetCDlg::CreateNetCost);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateNetCDlg::Close);
	QObject::connect(productBtn, &QPushButton::released, this, &CreateNetCDlg::OpenPrdDlg);
	InitComboBox();
}

CreateNetCDlg::~CreateNetCDlg()
{
	delete vDouble;
	delete vInt;
}


void CreateNetCDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("productForm"))
			{
				productEdit->setText(QString::number(ID));
				BusinessLayer::Product product;
				if (product.GetProductByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					prodNamePh->setText(product.GetName().c_str());
					volumePh->setText(QString::number(product.GetVolume()));
					BusinessLayer::Measure measure;
					if (measure.GetMeasureByID(dialogBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
					{
						measurePh->setText(measure.GetShortName().c_str());
					}
				}
			}
		}
	}
}

void CreateNetCDlg::SetNetCostParams(QString nDate, double nValue, int nProductID, int nCurrencyID, QString nIsOutdated, int id)
{
	netCost->SetDate(nDate.toUtf8().constData());
	netCost->SetValue(nValue);
	netCost->SetProductID(nProductID);
	netCost->SetCurrencyID(nCurrencyID);
	netCost->SetIsOutdated(nIsOutdated == "true" ? true : false);
	netCost->SetID(id);
}

void CreateNetCDlg::FillEditElements(QString nDate, double nValue, int nProductID, int nCurrencyID, QString nIsOutdated)
{
	dateEdit->setDateTime(QDateTime::fromString(nDate, "yyyy.MM.dd hh:mm:ss"));
	valueEdit->setText(QString::number(nValue));
	productEdit->setText(QString::number(nProductID));
	int index = isOutdatedCmb->findText(nIsOutdated);
	isOutdatedCmb->setCurrentIndex(index);
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(nCurrencyID)));
	BusinessLayer::Product product;
	if (product.GetProductByID(dialogBL->GetOrmasDal(), nProductID, errorMessage))
	{
		prodNamePh->setText(product.GetName().c_str());
		volumePh->setText(QString::number(product.GetVolume()));
		BusinessLayer::Measure measure;
		if (measure.GetMeasureByID(dialogBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			measurePh->setText(measure.GetShortName().c_str());
		}
	}
}

bool CreateNetCDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetNetCostParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 5)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 8)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 7)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 5)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 8)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 7)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toString().toUtf8().constData());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateNetCDlg::CreateNetCost()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && !currencyCmb->currentText().isEmpty()
		&& !dateEdit->text().isEmpty())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetNetCostParams(dateEdit->text(), valueEdit->text().toDouble(), productEdit->text().toInt(),
			currencyCmb->currentData().toInt(), isOutdatedCmb->currentText());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateNetCost(netCost, errorMessage))
		{
			BusinessLayer::Product *product = new BusinessLayer::Product;
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;
			if (!product->GetProductByID(dialogBL->GetOrmasDal(), netCost->GetProductID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), netCost->GetCurrencyID(), errorMessage))
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
			QList<QStandardItem*> NetCostItem;
			NetCostItem << new QStandardItem(QString::number(netCost->GetID()))
				<< new QStandardItem(netCost->GetDate().c_str())
				<< new QStandardItem(product->GetName().c_str())
				<< new QStandardItem(QString::number(product->GetVolume()))
				<< new QStandardItem(measure->GetName().c_str())
				<< new QStandardItem(QString::number(netCost->GetValue()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(QString::number(netCost->GetCurrencyID()))
				<< new QStandardItem(QString::number(netCost->GetProductID()))
				<< new QStandardItem(netCost->GetIsOutdated() ? "true" : "false");;
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(NetCostItem);

			dialogBL->CommitTransaction(errorMessage);
			delete product;
			delete currency;
			delete measure;
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
			QString(tr("Please fill user, value, date and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateNetCDlg::EditNetCost()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && !currencyCmb->currentText().isEmpty()
		&& !dateEdit->text().isEmpty())
	{
		if (QString(netCost->GetDate().c_str()) != dateEdit->text() || netCost->GetProductID() != productEdit->text().toInt()
			|| netCost->GetValue() != valueEdit->text().toDouble() || netCost->GetCurrencyID() != currencyCmb->currentData().toInt()
			|| QString(netCost->GetIsOutdated() ? "true" : "false") != isOutdatedCmb->currentText())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetNetCostParams(dateEdit->text(), valueEdit->text().toDouble(), productEdit->text().toInt(),
				currencyCmb->currentData().toInt(), isOutdatedCmb->currentText(), netCost->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateNetCost(netCost, errorMessage))
			{
				BusinessLayer::Product *product = new BusinessLayer::Product;
				BusinessLayer::Currency *currency = new BusinessLayer::Currency;
				if (!product->GetProductByID(dialogBL->GetOrmasDal(), netCost->GetProductID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), netCost->GetCurrencyID(), errorMessage))
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
				itemModel->item(mIndex.row(), 1)->setText(netCost->GetDate().c_str());
				itemModel->item(mIndex.row(), 2)->setText(product->GetName().c_str());
				itemModel->item(mIndex.row(), 3)->setText(QString::number(product->GetVolume()));
				itemModel->item(mIndex.row(), 4)->setText(measure->GetName().c_str());
				itemModel->item(mIndex.row(), 5)->setText(QString::number(netCost->GetValue()));
				itemModel->item(mIndex.row(), 6)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 7)->setText(QString::number(netCost->GetCurrencyID()));
				itemModel->item(mIndex.row(), 8)->setText(QString::number(netCost->GetProductID()));
				itemModel->item(mIndex.row(), 9)->setText(netCost->GetIsOutdated() ? "true" : "false");
				emit itemModel->dataChanged(mIndex, mIndex);

				dialogBL->CommitTransaction(errorMessage);
				delete product;
				delete currency;
				delete measure;
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
			QString(tr("Please fill user, value and currency!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateNetCDlg::Close()
{
	this->close();
}

void CreateNetCDlg::OpenPrdDlg()
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
		dForm->createNetCDlg = this;
		dForm->setObjectName("productForm");
		dForm->QtConnect<BusinessLayer::ProductView>();
		QMdiSubWindow *productWindow = new QMdiSubWindow;
		productWindow->setWidget(dForm);
		productWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(productWindow);
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

void CreateNetCDlg::InitComboBox()
{
	std::vector<BusinessLayer::Currency> curVector = dialogBL->GetAllDataForClass<BusinessLayer::Currency>(errorMessage);
	if (!curVector.empty())
	{
		for (unsigned int i = 0; i < curVector.size(); i++)
		{
			currencyCmb->addItem(curVector[i].GetShortName().c_str(), QVariant(curVector[i].GetID()));
		}
	}
}