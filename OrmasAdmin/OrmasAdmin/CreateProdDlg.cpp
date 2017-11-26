#include "stdafx.h"
#include <QMessageBox>
#include "CreateProdDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"


CreateProdDlg::CreateProdDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	companyEdit->setValidator(vInt);
	measureEdit->setValidator(vInt);
	prodTypeEdit->setValidator(vInt);
	shelfLifeEdit->setValidator(vInt);
	currencyEdit->setValidator(vInt);
	volumeEdit->setValidator(vDouble);
	volumeEdit->setMaxLength(17);
	priceEdit->setValidator(vDouble);
	priceEdit->setMaxLength(17);
	nameEdit->setMaxLength(20);
	
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateProdDlg::EditProduct);
	}
	else
	{
		companyEdit->setText("0");
		measureEdit->setText("0");
		prodTypeEdit->setText("0");
		shelfLifeEdit->setText("0");
		currencyEdit->setText("0");
		priceEdit->setText("0");
		volumeEdit->setText("0");
		QObject::connect(okBtn, &QPushButton::released, this, &CreateProdDlg::CreateProduct);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateProdDlg::Close);
	QObject::connect(companyBtn, &QPushButton::released, this, &CreateProdDlg::OpenCmpDlg);
	QObject::connect(measureBtn, &QPushButton::released, this, &CreateProdDlg::OpenMsrDlg);
	QObject::connect(prodTypeBtn, &QPushButton::released, this, &CreateProdDlg::OpenPrdTpDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreateProdDlg::OpenCurDlg);
}

CreateProdDlg::~CreateProdDlg()
{
	delete vDouble;
	delete vInt;
}

void CreateProdDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("companyForm"))
			{
				companyEdit->setText(QString::number(ID));
			}
			if (childName == QString("measureForm"))
			{
				measureEdit->setText(QString::number(ID));
			}
			if (childName == QString("prodTypeForm"))
			{
				prodTypeEdit->setText(QString::number(ID));
			}
			if (childName == QString("currencyForm"))
			{
				currencyEdit->setText(QString::number(ID));
			}
		}
	}
}

void CreateProdDlg::SetProductParams(int pCountryID, QString pProductName, double pVolume, int pMeasureID, double pPrice, 
	int pProductTypeID, int pShelfLife, int pCurrencyID, int id)
{
	product->SetCompanyID(pCountryID);
	product->SetName(pProductName.toUtf8().constData());
	product->SetVolume(pVolume);
	product->SetMeasureID(pMeasureID);
	product->SetPrice(pPrice);
	product->SetProductTypeID(pProductTypeID);
	product->SetShelfLife(pShelfLife);
	product->SetCurrencyID(pCurrencyID);
	product->SetID(id);
}

void CreateProdDlg::FillEditElements(int pCountryID, QString pProductName, double pVolume, int pMeasureID, double pPrice,
	int pProductTypeID, int pShelfLife, int pCurrencyID)
{
	companyEdit->setText(QString::number(pCountryID));
	nameEdit->setText(pProductName);
	volumeEdit->setText(QString::number(pVolume));
	measureEdit->setText(QString::number(pMeasureID));
	priceEdit->setText(QString::number(pPrice));
	prodTypeEdit->setText(QString::number(pProductTypeID));
	shelfLifeEdit->setText(QString::number(pShelfLife));
	currencyEdit->setText(QString::number(pCurrencyID));
}

bool CreateProdDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetProductParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 4)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 10)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 11)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 7)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 12)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 4)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 10)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 11)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 7)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 12)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateProdDlg::CreateProduct()
{
	errorMessage.clear();
	if (0 != companyEdit->text().toInt() && !nameEdit->text().isEmpty() && 0 != volumeEdit->text().toInt()
		&& 0 != measureEdit->text().toInt() && 0 != priceEdit->text()
		&& 0 != prodTypeEdit->text().toInt() && 0 != shelfLifeEdit->text().toInt() && 0 != currencyEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		SetProductParams(companyEdit->text().toInt(), nameEdit->text(), volumeEdit->text().toDouble(), measureEdit->text().toInt(),
			priceEdit->text().toDouble(), prodTypeEdit->text().toInt(), shelfLifeEdit->text().toInt(), currencyEdit->text().toInt());
		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateProduct(product, errorMessage))
		{
			BusinessLayer::Company *company = new BusinessLayer::Company();
			BusinessLayer::Measure *measure = new BusinessLayer::Measure();
			BusinessLayer::ProductType *prodType = new BusinessLayer::ProductType();
			BusinessLayer::Currency *currency = new BusinessLayer::Currency();

			if (!company->GetCompanyByID(dialogBL->GetOrmasDal(), product->GetCompanyID(), errorMessage)
				|| !measure->GetMeasureByID(dialogBL->GetOrmasDal(), product->GetMeasureID(), errorMessage)
				|| !prodType->GetProductTypeByID(dialogBL->GetOrmasDal(), product->GetProductTypeID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), product->GetCurrencyID(), errorMessage))
			{
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				
				errorMessage.clear();
				delete company;
				delete measure;
				delete prodType;
				delete currency;
				return;
			}
			QList<QStandardItem*> ProductionItem;
			ProductionItem << new QStandardItem(QString::number(product->GetID()))
				<< new QStandardItem(product->GetName().c_str())
				<< new QStandardItem(QString::number(product->GetPrice()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(QString::number(product->GetVolume()))
				<< new QStandardItem(measure->GetName().c_str())
				<< new QStandardItem(prodType->GetShortName().c_str())
				<< new QStandardItem(QString::number(product->GetShelfLife()))
				<< new QStandardItem(company->GetName().c_str())
				<< new QStandardItem(QString::number(product->GetCompanyID()))
				<< new QStandardItem(QString::number(product->GetMeasureID()))
				<< new QStandardItem(QString::number(product->GetProductTypeID()))
				<< new QStandardItem(QString::number(product->GetCurrencyID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(ProductionItem);
			dialogBL->CommitTransaction(errorMessage);

			delete company;
			delete measure;
			delete prodType;
			delete currency;
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
			QString(tr("Please recheck all fields, all of them must be filled!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateProdDlg::EditProduct()
{
	errorMessage.clear();
	if (0 != companyEdit->text().toInt() && !nameEdit->text().isEmpty() && 0 != volumeEdit->text().toInt()
		&& 0 != measureEdit->text().toInt() && 0 != priceEdit->text()
		&& 0 != prodTypeEdit->text().toInt() && 0 != shelfLifeEdit->text().toInt() && 0 != currencyEdit->text().toInt())
	{
		if (product->GetCompanyID() != companyEdit->text().toInt() || QString(product->GetName().c_str()) != nameEdit->text() || 
			product->GetVolume() != volumeEdit->text().toDouble() || product->GetMeasureID() != measureEdit->text().toInt() ||
			product->GetPrice() != priceEdit->text().toDouble() || product->GetProductTypeID() != prodTypeEdit->text().toInt() ||
			product->GetShelfLife() != shelfLifeEdit->text().toInt() || product->GetCurrencyID() != currencyEdit->text().toInt())
			{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetProductParams(companyEdit->text().toInt(), nameEdit->text(), volumeEdit->text().toDouble(), measureEdit->text().toInt(),
				priceEdit->text().toDouble(), prodTypeEdit->text().toInt(), shelfLifeEdit->text().toInt(), currencyEdit->text().toInt(), 
				product->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateProduct(product, errorMessage))
			{
				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(product->GetName().c_str());
				itemModel->item(mIndex.row(), 2)->setText(QString::number(product->GetPrice()));
								
				BusinessLayer::Company *company = new BusinessLayer::Company();
				BusinessLayer::Measure *measure = new BusinessLayer::Measure();
				BusinessLayer::ProductType *prodType = new BusinessLayer::ProductType();
				BusinessLayer::Currency *currency = new BusinessLayer::Currency();
				
				if (!company->GetCompanyByID(dialogBL->GetOrmasDal(), product->GetCompanyID(), errorMessage)
					|| !measure->GetMeasureByID(dialogBL->GetOrmasDal(), product->GetMeasureID(), errorMessage)
					|| !prodType->GetProductTypeByID(dialogBL->GetOrmasDal(), product->GetProductTypeID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), product->GetCurrencyID(), errorMessage))
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete company;
					delete measure;
					delete prodType;
					delete currency;
					return;
				}

				itemModel->item(mIndex.row(), 3)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 4)->setText(QString::number(product->GetVolume()));
				itemModel->item(mIndex.row(), 5)->setText(measure->GetName().c_str());
				itemModel->item(mIndex.row(), 6)->setText(prodType->GetShortName().c_str());
				itemModel->item(mIndex.row(), 7)->setText(shelfLifeEdit->text());
				itemModel->item(mIndex.row(), 8)->setText(company->GetName().c_str());
				itemModel->item(mIndex.row(), 9)->setText(QString::number(product->GetCompanyID()));
				itemModel->item(mIndex.row(), 10)->setText(QString::number(product->GetMeasureID()));
				itemModel->item(mIndex.row(), 11)->setText(QString::number(product->GetProductTypeID()));
				itemModel->item(mIndex.row(), 12)->setText(QString::number(product->GetCurrencyID()));
				
				emit itemModel->dataChanged(mIndex, mIndex);
				this->close();
				dialogBL->CommitTransaction(errorMessage);

				delete company;
				delete measure;
				delete prodType;
				delete currency;
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
			QString(tr("Please recheck all fields, all of them must be filled!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateProdDlg::Close()
{
	this->close();
}

void CreateProdDlg::OpenCmpDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Companies"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::Company>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createProdDlg = this;
		dForm->setObjectName("companyForm");
		dForm->QtConnect<BusinessLayer::Company>();
		QMdiSubWindow *companyWindow = new QMdiSubWindow;
		companyWindow->setWidget(dForm);
		companyWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(companyWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All companies are shown");
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

void CreateProdDlg::OpenMsrDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Measures"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::Measure>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createProdDlg = this;
		dForm->setObjectName("measureForm");
		dForm->QtConnect<BusinessLayer::Measure>();
		QMdiSubWindow *measureWindow = new QMdiSubWindow;
		measureWindow->setWidget(dForm);
		measureWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(measureWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All measures are shown");
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

void CreateProdDlg::OpenPrdTpDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Product types"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::ProductType>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createProdDlg = this;
		dForm->setObjectName("prodTypeForm");
		dForm->QtConnect<BusinessLayer::ProductType>();
		QMdiSubWindow *roleWindow = new QMdiSubWindow;
		roleWindow->setWidget(dForm);
		roleWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(roleWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All product types are shown");
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

void CreateProdDlg::OpenCurDlg()
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
		dForm->createProdDlg = this;
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