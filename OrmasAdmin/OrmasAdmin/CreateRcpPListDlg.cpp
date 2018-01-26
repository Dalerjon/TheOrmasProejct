#include "stdafx.h"
#include <QMessageBox>
#include "CreateRcpPListDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateRcpPListDlg::CreateRcpPListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	receiptProductID = ((DataForm*)parent)->receiptProductID;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	productEdit->setValidator(vInt);
	countEdit->setValidator(vInt);
	countEdit->setMaxLength(10);
	receiptProductEdit->setValidator(vInt);
	statusEdit->setValidator(vInt);
	currencyEdit->setValidator(vInt);
	sumEdit->setValidator(vDouble);
	sumEdit->setMaxLength(17);
	if (true == updateFlag)
	{
		QObject::connect(addBtn, &QPushButton::released, this, &CreateRcpPListDlg::EditProductInList);
	}
	else
	{
		statusEdit->setText("0");
		receiptProductEdit->setText("0");
		countEdit->setText("0");
		productEdit->setText("0");
		sumEdit->setText("0");
		currencyEdit->setText("0");
		editSectionWgt->hide();
		QObject::connect(addBtn, &QPushButton::released, this, &CreateRcpPListDlg::AddProductToList);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateRcpPListDlg::Close);
	QObject::connect(receiptProductBtn, &QPushButton::released, this, &CreateRcpPListDlg::OpenRcpPDlg);
	QObject::connect(productBtn, &QPushButton::released, this, &CreateRcpPListDlg::OpenProdDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateRcpPListDlg::OpenStsDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreateRcpPListDlg::OpenCurDlg);
}

CreateRcpPListDlg::~CreateRcpPListDlg()
{
	delete vDouble;
	delete vInt;
}

void CreateRcpPListDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("productForm"))
			{
				productEdit->setText(QString::number(ID));
			}
			if (childName == QString("receiptProductForm"))
			{
				receiptProductEdit->setText(QString::number(ID));
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

void CreateRcpPListDlg::SetRcpPListParams(int rReceiptProductID, int rProductID, int rCount, double rSum, int rStatusID, int rCurrencyID, int id)
{
	receiptProductList->SetReceiptProductID(rReceiptProductID);
	receiptProductList->SetProductID(rProductID);
	receiptProductList->SetCount(rCount);
	receiptProductList->SetSum(rSum);
	receiptProductList->SetStatusID(rStatusID);
	receiptProductList->SetCurrencyID(rCurrencyID);
	receiptProductList->SetID(id);
}

void CreateRcpPListDlg::FillEditElements(int rReceiptProductID, int rProductID, int rCount, double rSum, int rStatusID, int rCurrencyID)
{
	receiptProductEdit->setText(QString::number(rReceiptProductID));
	productEdit->setText(QString::number(rProductID));
	countEdit->setText(QString::number(rCount));
	sumEdit->setText(QString::number(rSum));
	statusEdit->setText(QString::number(rStatusID));
	currencyEdit->setText(QString::number(rCurrencyID));
}

bool CreateRcpPListDlg::FillDlgElements(QTableView* oTable)
{
	QModelIndex mIndex = oTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetRcpPListParams(oTable->model()->data(oTable->model()->index(mIndex.row(), 1)).toInt(),
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

void CreateRcpPListDlg::AddProductToList()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() || 0 != countEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		BusinessLayer::Status *status = new BusinessLayer::Status();
		status->SetName("RECEIPTED");
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
				|| !sumCurrency->GetCurrencyByID(dialogBL->GetOrmasDal(), receiptProductList->GetCurrencyID(), errorMessage))
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

		SetRcpPListParams(receiptProductID, productEdit->text().toInt(),
			countEdit->text().toInt(), (countEdit->text().toInt() * product->GetPrice()),
			statusVector.at(0).GetID(), product->GetCurrencyID());

		if (dialogBL->CreateReceiptProductList(receiptProductList, errorMessage))
		{
			QList<QStandardItem*> productListItem;
			productListItem << new QStandardItem(QString::number(receiptProductList->GetID()));
			if (0 != receiptProductID)
			{
				productListItem << new QStandardItem(QString::number(receiptProductID));
			}
			else
			{
				productListItem << new QStandardItem(QString::number(0));
			}
			productListItem << new QStandardItem(product->GetName().c_str())
				<< new QStandardItem(QString::number(product->GetPrice()))
				<< new QStandardItem(currency->GetShortName().c_str())
				<< new QStandardItem(QString::number(product->GetVolume()))
				<< new QStandardItem(measure->GetName().c_str())
				<< new QStandardItem(QString::number(receiptProductList->GetCount()))
				<< new QStandardItem(QString::number(receiptProductList->GetSum()))
				<< new QStandardItem(sumCurrency->GetShortName().c_str())
				<< new QStandardItem(statusVector.at(0).GetName().c_str())
				<< new QStandardItem(QString::number(receiptProductList->GetProductID()))
				<< new QStandardItem(QString::number(receiptProductList->GetStatusID()))
				<< new QStandardItem(QString::number(receiptProductList->GetCurrencyID()));
			QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
			itemModel->appendRow(productListItem);

			delete measure;
			delete product;
			delete currency;
			this->close();
		}
		else
		{
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

void CreateRcpPListDlg::EditProductInList()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() || 0 != countEdit->text().toInt())
	{
		if (productEdit->text().toInt() != receiptProductList->GetProductID() || countEdit->text().toInt() != receiptProductList->GetCount()
			|| receiptProductEdit->text().toInt() != receiptProductList->GetReceiptProductID() || sumEdit->text().toInt() != receiptProductList->GetSum()
			|| statusEdit->text().toInt() != receiptProductList->GetStatusID() || currencyEdit->text().toInt() != receiptProductList->GetCurrencyID())
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
			if (countEdit->text().toInt() != receiptProductList->GetCount())
			{
				sumEdit->setText(QString::number(countEdit->text().toInt() * product->GetPrice()));
			}
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetRcpPListParams(receiptProductEdit->text().toInt(),
				productEdit->text().toInt(), countEdit->text().toInt(), sumEdit->text().toDouble(), statusEdit->text().toInt(),
				receiptProductList->GetCurrencyID(), receiptProductList->GetID());
			if (dialogBL->UpdateReceiptProductList(receiptProductList, errorMessage))
			{
				BusinessLayer::Measure *measure = new BusinessLayer::Measure();
				BusinessLayer::Status *status = new BusinessLayer::Status();
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
				itemModel->item(mIndex.row(), 1)->setText(QString::number(receiptProductList->GetReceiptProductID()));
				itemModel->item(mIndex.row(), 2)->setText(product->GetName().c_str());
				itemModel->item(mIndex.row(), 3)->setText(QString::number(product->GetPrice()));
				itemModel->item(mIndex.row(), 4)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 5)->setText(QString::number(product->GetVolume()));
				itemModel->item(mIndex.row(), 6)->setText(measure->GetName().c_str());
				itemModel->item(mIndex.row(), 7)->setText(QString::number(receiptProductList->GetCount()));
				itemModel->item(mIndex.row(), 8)->setText(QString::number(receiptProductList->GetSum()));
				itemModel->item(mIndex.row(), 9)->setText(sumCurrency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 10)->setText(status->GetName().c_str());
				itemModel->item(mIndex.row(), 11)->setText(QString::number(receiptProductList->GetStatusID()));
				itemModel->item(mIndex.row(), 12)->setText(QString::number(product->GetMeasureID()));
				itemModel->item(mIndex.row(), 13)->setText(QString::number(receiptProductList->GetCurrencyID()));

				emit itemModel->dataChanged(mIndex, mIndex);
				this->close();
				delete product;
				delete measure;
				delete status;
				delete currency;
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
			QString(tr("Please recheck all fields, all of them must be filled!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateRcpPListDlg::Close()
{
	this->close();
}

void CreateRcpPListDlg::OpenStsDlg()
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
		dForm->createRcpPListDlg = this;
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

void CreateRcpPListDlg::OpenProdDlg()
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
		dForm->createRcpPListDlg = this;
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


void CreateRcpPListDlg::OpenRcpPDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Receipt products"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::ReceiptProductView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createRcpPListDlg = this;
		dForm->setObjectName("receiptProductForm");
		dForm->QtConnect<BusinessLayer::ReceiptProductView>();
		QMdiSubWindow *receiptProductWindow = new QMdiSubWindow;
		receiptProductWindow->setWidget(dForm);
		receiptProductWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(receiptProductWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All receipt products are shown");
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


void CreateRcpPListDlg::OpenCurDlg()
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
		dForm->createRcpPListDlg = this;
		dForm->setObjectName("currencyForm");
		dForm->QtConnect<BusinessLayer::Currency>();
		QMdiSubWindow *currencyWindow = new QMdiSubWindow;
		currencyWindow->setWidget(dForm);
		currencyWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(currencyWindow);
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