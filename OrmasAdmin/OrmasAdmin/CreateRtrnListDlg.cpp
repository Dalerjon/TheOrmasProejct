#include "stdafx.h"
#include <QMessageBox>
#include "CreateRtrnListDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateRtrnListDlg::CreateRtrnListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	productEdit->setValidator(vInt);
	countEdit->setValidator(vInt);
	returnEdit->setValidator(vInt);
	statusEdit->setValidator(vInt);
	currencyEdit->setValidator(vInt);
	sumEdit->setValidator(vDouble);
	if (true == updateFlag)
	{
		QObject::connect(addBtn, &QPushButton::released, this, &CreateRtrnListDlg::EditProductInList);
	}
	else
	{
		statusEdit->setText("0");
		returnEdit->setText("0");
		countEdit->setText("0");
		productEdit->setText("0");
		sumEdit->setText("0");
		currencyEdit->setText("0");
		editSectionWgt->hide();
		QObject::connect(addBtn, &QPushButton::released, this, &CreateRtrnListDlg::AddProductToList);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateRtrnListDlg::Close);
	QObject::connect(returnBtn, &QPushButton::released, this, &CreateRtrnListDlg::OpenRtrnDlg);
	QObject::connect(productBtn, &QPushButton::released, this, &CreateRtrnListDlg::OpenProdDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateRtrnListDlg::OpenStsDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreateRtrnListDlg::OpenCurDlg);
}

CreateRtrnListDlg::~CreateRtrnListDlg()
{
	delete vDouble;
	delete vInt;
}

void CreateRtrnListDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("productForm"))
			{
				productEdit->setText(QString::number(ID));
			}
			if (childName == QString("returnForm"))
			{
				returnEdit->setText(QString::number(ID));
			}
			if (childName == QString("statusForm"))
			{
				statusEdit->setText(QString::number(ID));
			}
			if (childName == QString("currencyForm"))
			{
				currencyEdit->setText(QString::number(ID));
			}
		}
	}
}

void CreateRtrnListDlg::SetReturnListParams(int pReturnID, int pProductID, int pCount, double pSum, int pStatusID, int pCurrencyID, int id)
{
	returnList->SetReturnID(pReturnID);
	returnList->SetProductID(pProductID);
	returnList->SetCount(pCount);
	returnList->SetSum(pSum);
	returnList->SetStatusID(pStatusID);
	returnList->SetCurrencyID(pCurrencyID);
	returnList->SetID(id);
}

void CreateRtrnListDlg::FillEditElements(int pReturnID, int pProductID, int pCount, double pSum, int pStatusID, int pCurrencyID)
{
	returnEdit->setText(QString::number(pReturnID));
	productEdit->setText(QString::number(pProductID));
	countEdit->setText(QString::number(pCount));
	sumEdit->setText(QString::number(pSum));
	statusEdit->setText(QString::number(pStatusID));
	currencyEdit->setText(QString::number(pCurrencyID));
}

bool CreateRtrnListDlg::FillDlgElements(QTableView* oTable)
{
	QModelIndex mIndex = oTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetReturnListParams(oTable->model()->data(oTable->model()->index(mIndex.row(), 1)).toInt(),
			oTable->model()->data(oTable->model()->index(mIndex.row(), 11)).toInt(),
			oTable->model()->data(oTable->model()->index(mIndex.row(), 7)).toInt(),
			oTable->model()->data(oTable->model()->index(mIndex.row(), 8)).toDouble(),
			oTable->model()->data(oTable->model()->index(mIndex.row(), 12)).toInt(),
			oTable->model()->data(oTable->model()->index(mIndex.row(), 13)).toInt(),
			oTable->model()->data(oTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(oTable->model()->data(oTable->model()->index(mIndex.row(), 1)).toInt(),
			oTable->model()->data(oTable->model()->index(mIndex.row(), 11)).toInt(),
			oTable->model()->data(oTable->model()->index(mIndex.row(), 7)).toInt(),
			oTable->model()->data(oTable->model()->index(mIndex.row(), 8)).toDouble(),
			oTable->model()->data(oTable->model()->index(mIndex.row(), 12)).toInt(),
			oTable->model()->data(oTable->model()->index(mIndex.row(), 13)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateRtrnListDlg::AddProductToList()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() || 0 != countEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		BusinessLayer::Status *status = new BusinessLayer::Status();
		status->SetName("returned");
		std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
		std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);
		delete status;
		if (statusVector.size() == 0)
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("Status are empty please contact with Admin")),
				QString(tr("Ok")));
			errorMessage.clear();
			return;
		}
		BusinessLayer::Product *product = new BusinessLayer::Product();
		//product->SetID(productEdit->text().toInt());
		//std::string productFilter = dialogBL->GenerateFilter<BusinessLayer::Product>(product);
		//std::vector<BusinessLayer::ProductView> productVector = dialogBL->GetAllDataForClass<BusinessLayer::ProductView>(errorMessage, productFilter);

		BusinessLayer::Measure *measure = new BusinessLayer::Measure();
		//measure->SetID(productVector.at(0).GetMeasureID());
		//std::string measureFilter = dialogBL->GenerateFilter<BusinessLayer::Measure>(measure);
		//std::vector<BusinessLayer::Measure> measureVector = dialogBL->GetAllDataForClass<BusinessLayer::Measure>(errorMessage, measureFilter);

		BusinessLayer::Currency *currency = new BusinessLayer::Currency();
		BusinessLayer::Currency *sumCurrency = new BusinessLayer::Currency();

		if (!product->GetProductByID(dialogBL->GetOrmasDal(), productEdit->text().toInt(), errorMessage))
		{
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage.clear();
			delete product;
			delete measure;
			delete currency;
			return;
		}
		else
		{
			if (!measure->GetMeasureByID(dialogBL->GetOrmasDal(), product->GetMeasureID(), errorMessage)
				|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), product->GetCurrencyID(), errorMessage)
				|| !sumCurrency->GetCurrencyByID(dialogBL->GetOrmasDal(), returnList->GetCurrencyID(), errorMessage))
			{
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete product;
				delete measure;
				delete currency;
				return;
			}
		}

		SetReturnListParams(returnID, productEdit->text().toInt(),
			countEdit->text().toInt(), (countEdit->text().toInt() * product->GetPrice()),
			statusVector.at(0).GetID(), product->GetCurrencyID());

		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateReturnList(returnList, errorMessage))
		{
			QList<QStandardItem*> ProductListItem;
			ProductListItem << new QStandardItem(QString::number(returnList->GetID()));
			if (0 != returnID)
			{
				ProductListItem << new QStandardItem(QString::number(returnID));
			}
			else
			{
				ProductListItem << new QStandardItem(QString::number(0));
			}
			ProductListItem << new QStandardItem(product->GetName().c_str())
				<< new QStandardItem(QString::number(product->GetPrice()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(QString::number(product->GetVolume()))
				<< new QStandardItem(measure->GetName().c_str())
				<< new QStandardItem(QString::number(returnList->GetCount()))
				<< new QStandardItem(QString::number(returnList->GetSum()))
				<< new QStandardItem(sumCurrency->GetShortName().c_str())
				<< new QStandardItem(statusVector.at(0).GetName().c_str())
				<< new QStandardItem(QString::number(returnList->GetProductID()))
				<< new QStandardItem(QString::number(returnList->GetStatusID()))
				<< new QStandardItem(QString::number(returnList->GetCurrencyID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(ProductListItem);

			delete measure;
			delete product;
			delete currency;
			this->close();
			dialogBL->CommitTransaction(errorMessage);
		}
		else
		{
			dialogBL->CancelTransaction(errorMessage);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("This product is not valid! Please delete it!")),
				QString(tr("Ok")));
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

void CreateRtrnListDlg::EditProductInList()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() || 0 != countEdit->text().toInt())
	{
		if (productEdit->text().toInt() != returnList->GetProductID() || countEdit->text().toInt() != returnList->GetCount()
			|| returnEdit->text().toInt() != returnList->GetReturnID() || sumEdit->text().toInt() != returnList->GetSum()
			|| statusEdit->text().toInt() != returnList->GetStatusID() || currencyEdit->text().toInt() != returnList->GetCurrencyID())
		{
			BusinessLayer::Product *product = new BusinessLayer::Product();
			//product->SetID(productEdit->text().toInt());
			//std::string productFilter = dialogBL->GenerateFilter<BusinessLayer::Product>(product);
			//std::vector<BusinessLayer::ProductView> productVector = dialogBL->GetAllDataForClass<BusinessLayer::ProductView>(errorMessage, productFilter);

			if (!product->GetProductByID(dialogBL->GetOrmasDal(), productEdit->text().toInt(), errorMessage))
			{
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete product;
				return;
			}
			if (countEdit->text().toInt() != returnList->GetCount())
			{
				sumEdit->setText(QString::number(countEdit->text().toInt() * product->GetPrice()));
			}
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetReturnListParams(returnEdit->text().toInt(),
				productEdit->text().toInt(), countEdit->text().toInt(), sumEdit->text().toDouble(), statusEdit->text().toInt(),
				returnList->GetCurrencyID(), returnList->GetID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateReturnList(returnList, errorMessage))
			{
				BusinessLayer::Measure *measure = new BusinessLayer::Measure();
				//measure->SetID(product->GetMeasureID());
				//std::string measureFilter = dialogBL->GenerateFilter<BusinessLayer::Measure>(measure);
				//std::vector<BusinessLayer::Measure> measureVector = dialogBL->GetAllDataForClass<BusinessLayer::Measure>(errorMessage, measureFilter);
				BusinessLayer::Status *status = new BusinessLayer::Status();
				//status->SetID(statusEdit->text().toInt());
				//std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
				//std::vector<BusinessLayer::Status>statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);
				BusinessLayer::Currency *currency = new BusinessLayer::Currency();
				BusinessLayer::Currency *sumCurrency = new BusinessLayer::Currency();
				if (!measure->GetMeasureByID(dialogBL->GetOrmasDal(), product->GetMeasureID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), product->GetCurrencyID(), errorMessage)
					|| !sumCurrency->GetCurrencyByID(dialogBL->GetOrmasDal(), currencyEdit->text().toInt(), errorMessage)
					|| !status->GetStatusByID(dialogBL->GetOrmasDal(), statusEdit->text().toInt(), errorMessage))
				{
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr(errorMessage.c_str())),
						QString(tr("Ok")));
					errorMessage.clear();
					delete product;
					delete measure;
					delete status;
					delete currency;
					return;
				}

				QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
				QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
				itemModel->item(mIndex.row(), 1)->setText(QString::number(returnList->GetReturnID()));
				itemModel->item(mIndex.row(), 2)->setText(product->GetName().c_str());
				itemModel->item(mIndex.row(), 3)->setText(QString::number(product->GetPrice()));
				itemModel->item(mIndex.row(), 4)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 5)->setText(QString::number(product->GetVolume()));
				itemModel->item(mIndex.row(), 6)->setText(measure->GetName().c_str());
				itemModel->item(mIndex.row(), 7)->setText(QString::number(returnList->GetCount()));
				itemModel->item(mIndex.row(), 8)->setText(QString::number(returnList->GetSum()));
				itemModel->item(mIndex.row(), 9)->setText(sumCurrency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 10)->setText(status->GetName().c_str());
				itemModel->item(mIndex.row(), 11)->setText(QString::number(returnList->GetStatusID()));
				itemModel->item(mIndex.row(), 12)->setText(QString::number(product->GetMeasureID()));
				itemModel->item(mIndex.row(), 13)->setText(QString::number(returnList->GetCurrencyID()));

				emit itemModel->dataChanged(mIndex, mIndex);
				this->close();
				delete product;
				delete measure;
				delete status;
				delete currency;
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
			QString(tr("Please recheck all fields, all of them must be filled!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateRtrnListDlg::Close()
{
	this->close();
}

void CreateRtrnListDlg::OpenStsDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Status"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::Status>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createRtrnListDlg = this;
		dForm->setObjectName("statusForm");
		dForm->QtConnect<BusinessLayer::Measure>();
		QMdiSubWindow *statusWindow = new QMdiSubWindow;
		statusWindow->setWidget(dForm);
		statusWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(statusWindow);
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

void CreateRtrnListDlg::OpenProdDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Products"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::ProductView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createRtrnListDlg = this;
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


void CreateRtrnListDlg::OpenRtrnDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("returns"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::ReturnView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createRtrnListDlg = this;
		dForm->setObjectName("returnForm");
		dForm->QtConnect<BusinessLayer::ReturnView>();
		QMdiSubWindow *returnWindow = new QMdiSubWindow;
		returnWindow->setWidget(dForm);
		returnWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(returnWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All returns are shown");
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


void CreateRtrnListDlg::OpenCurDlg()
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
		dForm->createRtrnListDlg = this;
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