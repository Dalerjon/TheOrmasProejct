#include "stdafx.h"
#include <QMessageBox>
#include "CreateTrsListDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateTrsListDlg::CreateTrsListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	transportID = ((DataForm*)parent)->transportID;
	vDouble = new QDoubleValidator(0.00, 1000000000.00, 3, this);
	vInt = new QIntValidator(0, 1000000000, this);
	productEdit->setValidator(vInt);
	countEdit->setValidator(vInt);
	countEdit->setMaxLength(10);
	transportEdit->setValidator(vInt);
	statusEdit->setValidator(vInt);
	sumEdit->setValidator(vDouble);
	sumEdit->setMaxLength(17);
	if (true == updateFlag)
	{
		QObject::connect(addBtn, &QPushButton::released, this, &CreateTrsListDlg::EditProductInList);
	}
	else
	{
		statusEdit->setText("0");
		transportEdit->setText("0");
		countEdit->setText("0");
		productEdit->setText("0");
		sumEdit->setText("0");
		editSectionWgt->hide();
		QObject::connect(addBtn, &QPushButton::released, this, &CreateTrsListDlg::AddProductToList);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateTrsListDlg::Close);
	QObject::connect(transportBtn, &QPushButton::released, this, &CreateTrsListDlg::OpenTrsDlg);
	QObject::connect(productBtn, &QPushButton::released, this, &CreateTrsListDlg::OpenProdDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateTrsListDlg::OpenStsDlg);
	InitComboBox();
}

CreateTrsListDlg::~CreateTrsListDlg()
{
	delete vDouble;
	delete vInt;
}

void CreateTrsListDlg::SetID(int ID, QString childName)
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
			if (childName == QString("transportForm"))
			{
				transportEdit->setText(QString::number(ID));
			}
			if (childName == QString("statusForm"))
			{
				statusEdit->setText(QString::number(ID));
				BusinessLayer::Status status;
				if (status.GetStatusByID(dialogBL->GetOrmasDal(), ID, errorMessage))
				{
					statusPh->setText(status.GetName().c_str());
				}
			}
		}
	}
}

void CreateTrsListDlg::SetTrsListParams(int tTransportID, int tProductID, int tCount, double tSum, int tStatusID, int tCurrencyID, int id)
{
	transportList->SetTransportID(tTransportID);
	transportList->SetProductID(tProductID);
	transportList->SetCount(tCount);
	transportList->SetSum(tSum);
	transportList->SetStatusID(tStatusID);
	transportList->SetCurrencyID(tCurrencyID);
	transportList->SetID(id);
}

void CreateTrsListDlg::FillEditElements(int tTransportID, int tProductID, int tCount, double tSum, int tStatusID, int tCurrencyID)
{
	transportEdit->setText(QString::number(tTransportID));
	productEdit->setText(QString::number(tProductID));
	countEdit->setText(QString::number(tCount));
	sumEdit->setText(QString::number(tSum));
	statusEdit->setText(QString::number(tStatusID));
	currencyCmb->setCurrentIndex(currencyCmb->findData(QVariant(tCurrencyID)));
	BusinessLayer::Product product;
	if (product.GetProductByID(dialogBL->GetOrmasDal(), tProductID, errorMessage))
	{
		prodNamePh->setText(product.GetName().c_str());
		volumePh->setText(QString::number(product.GetVolume()));
		BusinessLayer::Measure measure;
		if (measure.GetMeasureByID(dialogBL->GetOrmasDal(), product.GetMeasureID(), errorMessage))
		{
			measurePh->setText(measure.GetName().c_str());
		}
	}
	BusinessLayer::Status status;
	if (status.GetStatusByID(dialogBL->GetOrmasDal(), tStatusID, errorMessage))
	{
		statusPh->setText(status.GetName().c_str());
	}
}

bool CreateTrsListDlg::FillDlgElements(QTableView* oTable)
{
	QModelIndex mIndex = oTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetTrsListParams(oTable->model()->data(oTable->model()->index(mIndex.row(), 1)).toInt(),
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

void CreateTrsListDlg::AddProductToList()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() || 0 != countEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();
		BusinessLayer::Status *status = new BusinessLayer::Status();
		status->SetName("TRANSPORTING");
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
				|| !sumCurrency->GetCurrencyByID(dialogBL->GetOrmasDal(), transportList->GetCurrencyID(), errorMessage))
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

		SetTrsListParams(transportID, productEdit->text().toInt(),
			countEdit->text().toInt(), (countEdit->text().toInt() * product->GetPrice()),
			statusVector.at(0).GetID(), product->GetCurrencyID());

		if (dialogBL->CreateTransportList(transportList, errorMessage))
		{
			QList<QStandardItem*> productListItem;
			productListItem << new QStandardItem(QString::number(transportList->GetID()));
			if (0 != transportID)
			{
				productListItem << new QStandardItem(QString::number(transportID));
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
				<< new QStandardItem(QString::number(transportList->GetCount()))
				<< new QStandardItem(QString::number(transportList->GetSum()))
				<< new QStandardItem(sumCurrency->GetShortName().c_str())
				<< new QStandardItem(statusVector.at(0).GetName().c_str())
				<< new QStandardItem(QString::number(transportList->GetProductID()))
				<< new QStandardItem(QString::number(transportList->GetStatusID()))
				<< new QStandardItem(QString::number(transportList->GetCurrencyID()));
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

void CreateTrsListDlg::EditProductInList()
{
	errorMessage.clear();
	if (0 != productEdit->text().toInt() || 0 != countEdit->text().toInt())
	{
		if (productEdit->text().toInt() != transportList->GetProductID() || countEdit->text().toInt() != transportList->GetCount()
			|| transportEdit->text().toInt() != transportList->GetTransportID() || sumEdit->text().toInt() != transportList->GetSum()
			|| statusEdit->text().toInt() != transportList->GetStatusID() || currencyCmb->currentData().toInt() != transportList->GetCurrencyID())
		{
			BusinessLayer::Product *product = new BusinessLayer::Product();
			if (!product->GetProductByID(dialogBL->GetOrmasDal(), productEdit->text().toInt(), errorMessage))
			{
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr(errorMessage.c_str())),
					QString(tr("Ok")));
				errorMessage.clear();
				delete product;
				return;
			}
			if (countEdit->text().toInt() != transportList->GetCount())
			{
				sumEdit->setText(QString::number(countEdit->text().toInt() * product->GetPrice()));
			}
			DataForm *parentDataForm = (DataForm*)parentWidget();
			SetTrsListParams(transportEdit->text().toInt(),
				productEdit->text().toInt(), countEdit->text().toInt(), sumEdit->text().toDouble(), statusEdit->text().toInt(),
				transportList->GetCurrencyID(), transportList->GetID());
			if (dialogBL->UpdateTransportList(transportList, errorMessage))
			{
				BusinessLayer::Measure *measure = new BusinessLayer::Measure();
				BusinessLayer::Status *status = new BusinessLayer::Status();
				BusinessLayer::Currency *currency = new BusinessLayer::Currency();
				BusinessLayer::Currency *sumCurrency = new BusinessLayer::Currency();
				if (!measure->GetMeasureByID(dialogBL->GetOrmasDal(), product->GetMeasureID(), errorMessage)
					|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), product->GetCurrencyID(), errorMessage)
					|| !sumCurrency->GetCurrencyByID(dialogBL->GetOrmasDal(), currencyCmb->currentData().toInt(), errorMessage)
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
				itemModel->item(mIndex.row(), 1)->setText(QString::number(transportList->GetTransportID()));
				itemModel->item(mIndex.row(), 2)->setText(product->GetName().c_str());
				itemModel->item(mIndex.row(), 3)->setText(QString::number(product->GetPrice()));
				itemModel->item(mIndex.row(), 4)->setText(currency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 5)->setText(QString::number(product->GetVolume()));
				itemModel->item(mIndex.row(), 6)->setText(measure->GetName().c_str());
				itemModel->item(mIndex.row(), 7)->setText(QString::number(transportList->GetCount()));
				itemModel->item(mIndex.row(), 8)->setText(QString::number(transportList->GetSum()));
				itemModel->item(mIndex.row(), 9)->setText(sumCurrency->GetShortName().c_str());
				itemModel->item(mIndex.row(), 10)->setText(status->GetName().c_str());
				itemModel->item(mIndex.row(), 11)->setText(QString::number(transportList->GetStatusID()));
				itemModel->item(mIndex.row(), 12)->setText(QString::number(product->GetMeasureID()));
				itemModel->item(mIndex.row(), 13)->setText(QString::number(transportList->GetCurrencyID()));

				emit itemModel->dataChanged(mIndex, mIndex);
				
				delete product;
				delete measure;
				delete status;
				delete currency;
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
			QString(tr("Please recheck all fields, all of them must be filled!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateTrsListDlg::Close()
{
	this->close();
}

void CreateTrsListDlg::OpenStsDlg()
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
		dForm->createTrsListDlg = this;
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

void CreateTrsListDlg::OpenProdDlg()
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
		dForm->createTrsListDlg = this;
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


void CreateTrsListDlg::OpenTrsDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *productParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)productParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Transports"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	dForm->FillTable<BusinessLayer::TransportView>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createTrsListDlg = this;
		dForm->setObjectName("transportForm");
		dForm->QtConnect<BusinessLayer::TransportView>();
		QMdiSubWindow *transportWindow = new QMdiSubWindow;
		transportWindow->setWidget(dForm);
		transportWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(transportWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All transports are shown");
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


void CreateTrsListDlg::InitComboBox()
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