#include "stdafx.h"
#include "CreateJbpDlg.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateJbpDlg::CreateJbpDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	productEdit->setValidator(vInt);
	positionEdit->setValidator(vInt);
	valueEdit->setValidator(vDouble);
	volumeEdit->setValidator(vDouble);
	valueEdit->setMaxLength(17);
	volumeEdit->setMaxLength(17);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateJbpDlg::EditJobprice);
	}
	else
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateJbpDlg::CreateJobprice);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateJbpDlg::Close);
	QObject::connect(productBtn, &QPushButton::released, this, &CreateJbpDlg::OpenProdDlg);
	QObject::connect(positionBtn, &QPushButton::released, this, &CreateJbpDlg::OpenPosDlg);
	InitComboBox();
}

CreateJbpDlg::~CreateJbpDlg()
{
	delete vInt;
	delete vDouble;
}

void CreateJbpDlg::SetID(int ID, QString childName)
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
						measurePh->setText(measure.GetName().c_str());
					}
				}
			}
			if (childName == QString("positionForm"))
			{
				positionEdit->setText(QString::number(ID));
				BusinessLayer::Position position;
				if (position.GetPositionByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					prodNamePh->setText(position.GetName().c_str());
				}
			}
		}
	}
}

void CreateJbpDlg::SetJobpriceParams(int pID, double jValue, int cID, double jVolume, int mID, int posID,  int id)
{
	jobprice->SetProductID(pID);
	jobprice->SetValue(jValue);
	jobprice->SetCurrencyID(cID);
	jobprice->SetVolume(jVolume);
	jobprice->SetMeasureID(mID);
	jobprice->SetPositionID(posID);
	jobprice->SetID(id);
}

void CreateJbpDlg::FillEditElements(int pID, double jValue, int cID, double jVolume, int mID, int posID)
{
	productEdit->setText(QString::number(pID));
	valueEdit->setText(QString::number(jValue));
	volumeEdit->setText(QString::number(jVolume));
	positionEdit->setText(QString::number(posID));
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(cID)));
	measureCmb->setCurrentIndex(currencyCmb->findData(QVariant(mID)));
	BusinessLayer::Product product;
	if (product.GetProductByID(dialogBL->GetOrmasDal(), pID, errorMessage))
	{
		prodNamePh->setText(product.GetName().c_str());
		volumePh->setText(QString::number(product.GetVolume()));
		BusinessLayer::Measure measure;
		if (measure.GetMeasureByID(dialogBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			measurePh->setText(measure.GetName().c_str());
		}
	}
	BusinessLayer::Position position;
	if (position.GetPositionByID(dialogBL->GetOrmasDal(), posID, errorMessage))
	{
		prodNamePh->setText(position.GetName().c_str());
	}
}

bool CreateJbpDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetJobpriceParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 7)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 8)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 4)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 10)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 7)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 8)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 4)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 10)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateJbpDlg::CreateJobprice()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && !currencyCmb->currentText().isEmpty()
		&& 0.0 != volumeEdit->text().toDouble() && !measureCmb->currentText().isEmpty() && 0 != positionEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetJobpriceParams(productEdit->text().toInt(), valueEdit->text().toDouble(), currencyCmb->currentData().toInt(),
			volumeEdit->text().toDouble(), measureCmb->currentData().toInt(), positionEdit->text().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateJobprice(jobprice, errorMessage))
		{
			BusinessLayer::Product *product = new BusinessLayer::Product;
			BusinessLayer::Currency *currency = new BusinessLayer::Currency;
			BusinessLayer::Measure *measure = new BusinessLayer::Measure;
			BusinessLayer::Position *position = new BusinessLayer::Position;
			if (!product->GetProductByID(dialogBL->GetOrmasDal(), jobprice->GetProductID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), jobprice->GetCurrencyID(), errorMessage)
				|| !measure->GetMeasureByID(dialogBL->GetOrmasDal(), jobprice->GetMeasureID(), errorMessage)
				|| !position->GetPositionByID(dialogBL->GetOrmasDal(), jobprice->GetPositionID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete product;
				delete currency;
				delete measure;
				delete position;
				return;
			}
			QList<QStandardItem*> jobpriceItem;
			jobpriceItem << new QStandardItem(QString::number(jobprice->GetID()))
				<< new QStandardItem(product->GetName().c_str())
				<< new QStandardItem(QString::number(jobprice->GetValue()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(QString::number(jobprice->GetVolume()))
				<< new QStandardItem(measure->GetName().c_str())
				<< new QStandardItem(position->GetName().c_str())
				<< new QStandardItem(QString::number(jobprice->GetProductID()))
				<< new QStandardItem(QString::number(jobprice->GetCurrencyID()))
				<< new QStandardItem(QString::number(jobprice->GetMeasureID()))
				<< new QStandardItem(QString::number(jobprice->GetPositionID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(jobpriceItem);
		
			dialogBL->CommitTransaction(errorMessage);
			delete product;
			delete currency;
			delete measure;
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
			QString(tr("Please fill all fields!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateJbpDlg::EditJobprice()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() && 0.0 != valueEdit->text().toDouble() && !currencyCmb->currentText().isEmpty()
		&& 0.0 != volumeEdit->text().toDouble() && !measureCmb->currentText().isEmpty() && 0 != positionEdit->text().toInt())
	{
		if (jobprice->GetProductID() != productEdit->text().toInt() || jobprice->GetValue() != valueEdit->text().toDouble() 
			|| jobprice->GetCurrencyID() != currencyCmb->currentData().toInt() || jobprice->GetValue() != valueEdit->text().toDouble()
			|| jobprice->GetMeasureID() != measureCmb->currentData().toInt() || jobprice->GetPositionID() != positionEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetJobpriceParams(productEdit->text().toInt(), valueEdit->text().toDouble(), currencyCmb->currentData().toInt(),
				volumeEdit->text().toDouble(), measureCmb->currentData().toInt(), positionEdit->text().toInt(), jobprice->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateJobprice(jobprice, errorMessage))
			{
				BusinessLayer::Product *product = new BusinessLayer::Product;
				BusinessLayer::Currency *currency = new BusinessLayer::Currency;
				BusinessLayer::Measure *measure = new BusinessLayer::Measure;
				BusinessLayer::Position *position = new BusinessLayer::Position;
				if (!product->GetProductByID(dialogBL->GetOrmasDal(), jobprice->GetProductID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), jobprice->GetCurrencyID(), errorMessage)
					|| !measure->GetMeasureByID(dialogBL->GetOrmasDal(), jobprice->GetMeasureID(), errorMessage)
					|| !position->GetPositionByID(dialogBL->GetOrmasDal(), jobprice->GetPositionID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete product;
					delete currency;
					delete measure;
					delete position;
					return;
				}
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(QString::number(jobprice->GetID()));
				itemModel->item(mIndex.row(), 2)->setText(product->GetName().c_str());
				itemModel->item(mIndex.row(), 3)->setText(QString::number(jobprice->GetValue()));
				itemModel->item(mIndex.row(), 4)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 5)->setText(QString::number(jobprice->GetVolume()));
				itemModel->item(mIndex.row(), 6)->setText(measure->GetName().c_str());
				itemModel->item(mIndex.row(), 7)->setText(position->GetName().c_str());
				itemModel->item(mIndex.row(), 8)->setText(QString::number(jobprice->GetProductID()));
				itemModel->item(mIndex.row(), 9)->setText(QString::number(jobprice->GetCurrencyID()));
				itemModel->item(mIndex.row(), 10)->setText(QString::number(jobprice->GetMeasureID()));
				itemModel->item(mIndex.row(), 11)->setText(QString::number(jobprice->GetPositionID()));
				emit itemModel->dataChanged(mIndex, mIndex);
			
				dialogBL->CommitTransaction(errorMessage);
				delete product;
				delete currency;
				delete measure;
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
			QString(tr("Please fill all fields!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateJbpDlg::Close()
{
	this->close();
}

void CreateJbpDlg::OpenProdDlg()
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
		dForm->createJbpDlg = this;
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

void CreateJbpDlg::OpenPosDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Positions"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::Position>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createJbpDlg = this;
		dForm->setObjectName("positionForm");
		dForm->QtConnect<BusinessLayer::Position>();
		QMdiSubWindow *positionWindow = new QMdiSubWindow;
		positionWindow->setWidget(dForm);
		positionWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(positionWindow);
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

void CreateJbpDlg::InitComboBox()
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