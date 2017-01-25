#include "stdafx.h"
#include <QMessageBox>
#include "AddProdDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

AddProdDlg::AddProdDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	QRegExp expr("\\d*");
	QRegExpValidator v(expr, 0);
	productEdit->setValidator(&v);
	countEdit->setValidator(&v);
	orderEdit->setValidator(&v);
	returnEdit->setValidator(&v);
	productionEdit->setValidator(&v);
	statusEdit->setValidator(&v);
	currencyEdit->setValidator(&v);
	sumEdit->setReadOnly(true);
	if (true == updateFlag)
	{
		QObject::connect(addBtn, &QPushButton::released, this, &AddProdDlg::EditProductInList);
	}
	else
	{
		statusEdit->setText("0");
		productionEdit->setText("0");
		orderEdit->setText("0");
		returnEdit->setText("0");
		countEdit->setText("0");
		productEdit->setText("0");
		sumEdit->setText("0");
		currencyEdit->setText("0");
		editSectionWgt->hide();
		QObject::connect(addBtn, &QPushButton::released, this, &AddProdDlg::AddProductToList);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &AddProdDlg::Close);
	QObject::connect(orderBtn, &QPushButton::released, this, &AddProdDlg::OpenOrdDlg);
	QObject::connect(productBtn, &QPushButton::released, this, &AddProdDlg::OpenProdDlg);
	QObject::connect(productionBtn, &QPushButton::released, this, &AddProdDlg::OpenProdnDlg);
	QObject::connect(returnBtn, &QPushButton::released, this, &AddProdDlg::OpenRtrnDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &AddProdDlg::OpenStsDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &AddProdDlg::OpenCurDlg);
}

void AddProdDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("productForm"))
			{
				productEdit->setText(QString::number(ID));
			}
			if (childName == QString("orderForm"))
			{
				orderEdit->setText(QString::number(ID));
			}
			if (childName == QString("returnForm"))
			{
				returnEdit->setText(QString::number(ID));
			}
			if (childName == QString("productionForm"))
			{
				productionEdit->setText(QString::number(ID));
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

void AddProdDlg::SetProductParams(int pOrderID, int pRetrunID, int pProductionID, int pProductID, int pCount, double pSum, 
	int pStatusID, int pCurrencyID, int id)
{
	productList->SetOrderID(pOrderID);
	productList->SetReturnID(pRetrunID);
	productList->SetProductionID(pProductionID);
	productList->SetProductID(pProductID);
	productList->SetCount(pCount);
	productList->SetSum(pSum);
	productList->SetStatusID(pStatusID);
	productList->SetCurrencyID(pCurrencyID);
	productList->SetID(id);
}

void AddProdDlg::FillEditElements(int pOrderID, int pRetrunID, int pProductionID, int pProductID, int pCount, double pSum,
	int pStatusID, int pCurrencyID)
{
	orderEdit->setText(QString::number(pOrderID));
	returnEdit->setText(QString::number(pRetrunID));
	productionEdit->setText(QString::number(pProductionID));
	productEdit->setText(QString::number(pProductID));
	countEdit->setText(QString::number(pCount));
	sumEdit->setText(QString::number(pSum));
	statusEdit->setText(QString::number(pStatusID));
	currencyEdit->setText(QString::number(pCurrencyID));
}

bool AddProdDlg::FillDlgElements(QTableView* pTable)
{
	QModelIndex mIndex = pTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetProductParams(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 3)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 13)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 10)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 14)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 15)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 0)).toInt());
		FillEditElements(pTable->model()->data(pTable->model()->index(mIndex.row(), 1)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 2)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 3)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 13)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 9)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 10)).toDouble(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 14)).toInt(),
			pTable->model()->data(pTable->model()->index(mIndex.row(), 15)).toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void AddProdDlg::AddProductToList()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() || 0 != countEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		BusinessLayer::Status *status = new BusinessLayer::Status();
		if (0 != orderID)
		{
			status->SetName("ordered");
		}
		if (0 != returnID)
		{
			status->SetName("to return");
		}
		if (0 != productionID)
		{
			status->SetName("produced");
		}
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
				|| !sumCurrency->GetCurrencyByID(dialogBL->GetOrmasDal(), productList->GetCurrencyID(), errorMessage))
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

		
		if (0 != orderID)
		{
			SetProductParams(orderID, 0, 0, productEdit->text().toInt(),
				countEdit->text().toInt(), (countEdit->text().toInt() * product->GetPrice()), 
				statusVector.at(0).GetID(), product->GetCurrencyID());
		}
		if (0 != returnID)
		{
			SetProductParams(0, returnID, 0, productEdit->text().toInt(),
				countEdit->text().toInt(), (countEdit->text().toInt() * product->GetPrice()), statusVector.at(0).GetID(), 
				product->GetCurrencyID());
		}
		if (0 != productionID)
		{
			SetProductParams(0, 0, productionID, productEdit->text().toInt(),
				countEdit->text().toInt(), (countEdit->text().toInt() * product->GetPrice()), statusVector.at(0).GetID(), 
				product->GetCurrencyID());
		}

		dialogBL->StartTransaction(errorMessage);
		if (dialogBL->CreateProductList(productList, errorMessage))
		{
			QList<QStandardItem*> ProductListItem;
			ProductListItem << new QStandardItem(QString::number(productList->GetID()));
			if (0 != orderID)
			{
				ProductListItem << new QStandardItem(QString::number(orderID));
			}
			else
			{
				ProductListItem << new QStandardItem(QString::number(0));
			}
			if (0 != returnID)
			{
				ProductListItem << new QStandardItem(QString::number(returnID));
			}
			else
			{
				ProductListItem << new QStandardItem(QString::number(0));
			}
			if (0 != productionID)
			{
				ProductListItem << new QStandardItem(QString::number(productionID));
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
				<< new QStandardItem(QString::number(productList->GetCount()))
				<< new QStandardItem(QString::number(productList->GetSum()))
				<< new QStandardItem(sumCurrency->GetShortName().c_str())
				<< new QStandardItem(statusVector.at(0).GetName().c_str())
				<< new QStandardItem(QString::number(productList->GetProductID()))
				<< new QStandardItem(QString::number(productList->GetStatusID()))
				<< new QStandardItem(QString::number(productList->GetCurrencyID()));
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

void AddProdDlg::EditProductInList()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() || 0 != countEdit->text().toInt() || 0 != statusEdit->text().toInt() || 0 != sumEdit->text().toInt())
	{
		if (productEdit->text().toInt() != productList->GetProductID() || countEdit->text().toInt() != productList->GetCount()
			|| orderEdit->text().toInt() != productList->GetOrderID() || returnEdit->text().toInt() != productList->GetReturnID()
			|| productionEdit->text().toInt() != productList->GetProductionID() || sumEdit->text().toInt() != productList->GetSum()
			|| statusEdit->text().toInt() != productList->GetStatusID() || currencyEdit->text().toInt() != productList->GetCurrencyID())
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
			if (countEdit->text().toInt() != productList->GetCount())
			{
				sumEdit->setText(QString::number(countEdit->text().toInt() * product->GetPrice()));
			}
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetProductParams(orderEdit->text().toInt(), returnEdit->text().toInt(), productionEdit->text().toInt(), 
				productEdit->text().toInt(), countEdit->text().toInt(), sumEdit->text().toDouble(), statusEdit->text().toInt(),
				productList->GetID(), productList->GetCurrencyID());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->UpdateProductList(productList, errorMessage))
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
				itemModel->item(mIndex.row(), 1)->setText(QString::number(productList->GetOrderID()));
				itemModel->item(mIndex.row(), 2)->setText(QString::number(productList->GetReturnID()));
				itemModel->item(mIndex.row(), 3)->setText(QString::number(productList->GetProductionID()));
				itemModel->item(mIndex.row(), 4)->setText(product->GetName().c_str());
				itemModel->item(mIndex.row(), 5)->setText(QString::number(product->GetPrice()));
				itemModel->item(mIndex.row(), 6)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 7)->setText(QString::number(product->GetVolume()));
				itemModel->item(mIndex.row(), 8)->setText(measure->GetName().c_str());
				itemModel->item(mIndex.row(), 9)->setText(QString::number(productList->GetCount()));
				itemModel->item(mIndex.row(), 10)->setText(QString::number(productList->GetSum()));
				itemModel->item(mIndex.row(), 11)->setText(sumCurrency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 12)->setText(status->GetName().c_str());
				itemModel->item(mIndex.row(), 13)->setText(QString::number(productList->GetStatusID()));
				itemModel->item(mIndex.row(), 14)->setText(QString::number(product->GetMeasureID()));
				itemModel->item(mIndex.row(), 15)->setText(QString::number(productList->GetCurrencyID()));

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

void AddProdDlg::Close()
{
	this->close();
}

void AddProdDlg::OpenStsDlg()
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
		dForm->addProdDlg = this;
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

void AddProdDlg::OpenProdDlg()
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
		dForm->addProdDlg = this;
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

void AddProdDlg::OpenProdnDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Production"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::Production>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->addProdDlg = this;
		dForm->setObjectName("productionForm");
		dForm->QtConnect<BusinessLayer::Production>();
		QMdiSubWindow *productionWindow = new QMdiSubWindow;
		productionWindow->setWidget(dForm);
		productionWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(productionWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All productions are shown");
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

void AddProdDlg::OpenOrdDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Orders"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::OrderView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->addProdDlg = this;
		dForm->setObjectName("orderForm");
		dForm->QtConnect<BusinessLayer::OrderView>();
		QMdiSubWindow *orderWindow = new QMdiSubWindow;
		orderWindow->setWidget(dForm);
		orderWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(orderWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All orders are shown");
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

void AddProdDlg::OpenRtrnDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Returns"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::ReturnView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->addProdDlg = this;
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

void AddProdDlg::OpenCurDlg()
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
		dForm->addProdDlg = this;
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