#include "stdafx.h"
#include <QMessageBox>
#include "CreateOrdDlg.h"
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"

CreateOrdDlg::CreateOrdDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	order->SetID(dialogBL->GenerateID());
	QRegExp expr("\\d*");
	QRegExpValidator v(expr, 0);
	userEdit->setValidator(&v);
	workerEdit->setValidator(&v);
	prodCountEdit->setValidator(&v);
	userEdit->setValidator(&v);
	statusEdit->setValidator(&v);
	currencyEdit->setValidator(&v);
	sumEdit->setReadOnly(true);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateOrdDlg::EditOrder);
	}
	else
	{
		userEdit->setText("0");
		workerEdit->setText("0");
		prodCountEdit->setText("0");
		userEdit->setText("0");
		statusEdit->setText("0");
		sumEdit->setText("0");
		currencyEdit->setText("0");
		dateEdit->setDate(QDate::currentDate());
		QObject::connect(okBtn, &QPushButton::released, this, &CreateOrdDlg::CreateOrder);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateOrdDlg::Close);
	QObject::connect(userBtn, &QPushButton::released, this, &CreateOrdDlg::OpenUserDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateOrdDlg::OpenStsDlg);
	QObject::connect(workerBtn, &QPushButton::released, this, &CreateOrdDlg::OpenWorkerDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreateOrdDlg::OpenCurDlg);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateOrdDlg::OpenAddProdDlg);
}

void CreateOrdDlg::SetOrderParams(int oUserID, QString oDate, int oWorkerID, int oCount, double oSum, int oStatusID, int oCurrencyID)
{
	order->SetUserID(oUserID);
	order->SetDate(oDate.toUtf8().constData());
	order->SetWorkerID(oWorkerID);
	order->SetCount(oCount);
	order->SetSum(oSum);
	order->SetStatusID(oStatusID);
	order->SetCurrencyID(oCurrencyID);
}

void CreateOrdDlg::FillEditElements(int oUserID, QString oDate, int oWorkerID, int oCount, double oSum, int oStatusID, int oCurrencyID)
{
	userEdit->setText(QString::number(oUserID));
	dateEdit->setDate(QDate::fromString(oDate, "dd.MM.yyyy"));
	workerEdit->setText(QString::number(oWorkerID));
	prodCountEdit->setText(QString::number(oCount));
	sumEdit->setText(QString::number(oSum));
	statusEdit->setText(QString::number(oStatusID));
	currencyEdit->setText(QString::number(oCurrencyID));
}

void CreateOrdDlg::SetID(int ID, QString childName)
{
	if (0 != ID)
	{
		if (0 != childName.length())
		{
			if (childName == QString("clientForm"))
			{
				userEdit->setText(QString::number(ID));
			}
			if (childName == QString("statusForm"))
			{
				statusEdit->setText(QString::number(ID));
			}
			if (childName == QString("workerForm"))
			{
				workerEdit->setText(QString::number(ID));
			}
			if (childName == QString("currencyForm"))
			{
				currencyEdit->setText(QString::number(ID));
			}
		}
	}
}

bool CreateOrdDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetOrderParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 14)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 13)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 10)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 11)).toString().toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 15)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 16)).toString().toInt());
		FillEditElements(cTable->model()->data(cTable->model()->index(mIndex.row(), 14)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 1)).toString().toUtf8().constData(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 13)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 10)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 11)).toString().toDouble(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 15)).toString().toInt(),
			cTable->model()->data(cTable->model()->index(mIndex.row(), 16)).toString().toInt());
		return true;
	}
	else
	{
		return false;
	}
}

void CreateOrdDlg::CreateOrder()
{
	errorMessage.clear();
	if (0 != userEdit->text().toInt()  && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != currencyEdit->text().toInt())
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();

		BusinessLayer::Status *status = new BusinessLayer::Status();
		status->SetName("ordered");
		std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
		std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);

		if (statusVector.size() > 0)
		{
			SetOrderParams(userEdit->text().toInt(), dateEdit->text(), workerEdit->text().toInt(), prodCountEdit->text().toInt(),
				sumEdit->text().toInt(), statusVector.at(0).GetID(), currencyEdit->text().toInt());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->CreateOrder(order, errorMessage))
			{
				if (0 != statusVector.size())
				{
					QList<QStandardItem*> OrderItem;
					OrderItem << new QStandardItem(QString::number(order->GetID()))
						<< new QStandardItem(order->GetDate().c_str())
						<< new QStandardItem(statusVector.at(0).GetCode().c_str())
						<< new QStandardItem(statusVector.at(0).GetName().c_str());

					BusinessLayer::User *user = new BusinessLayer::User();
					//user->SetID(userEdit->text().toInt());
					//std::string userFilter = dialogBL->GenerateFilter<BusinessLayer::User>(user);
					//std::vector<BusinessLayer::UserView> userVector = dialogBL->GetAllDataForClass<BusinessLayer::UserView>(errorMessage, userFilter);
					
					BusinessLayer::User *worker = new BusinessLayer::User();
					//worker->SetID(workerEdit->text().toInt());
					//std::string workerFilter = dialogBL->GenerateFilter<BusinessLayer::User>(worker);
					//std::vector<BusinessLayer::UserView> workerVector = dialogBL->GetAllDataForClass<BusinessLayer::UserView>(errorMessage, workerFilter);
					
					BusinessLayer::Currency *currency = new BusinessLayer::Currency;
					if (!user->GetUserByID(dialogBL->GetOrmasDal(), order->GetUserID(), errorMessage)
						|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), order->GetCurrencyID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete user;
						delete currency;
						delete status;
						return;
					}

					if (order->GetWorkerID() > 0)
					{
						if (!worker->GetUserByID(dialogBL->GetOrmasDal(), order->GetWorkerID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							delete worker;
							return;
						}
					}
					

					if (0 != order->GetUserID())
					{
						OrderItem << new QStandardItem(user->GetName().c_str())
							<< new QStandardItem(user->GetPhone().c_str())
							<< new QStandardItem(user->GetAddress().c_str())
							<< new QStandardItem(user->GetFirm().c_str());
					}
					else
					{
						OrderItem << new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("");
					}
					if (0 != order->GetWorkerID())
					{
						OrderItem << new QStandardItem(worker->GetName().c_str())
								<< new QStandardItem(worker->GetPhone().c_str());
					}
					else
					{
						OrderItem << new QStandardItem("")
							<< new QStandardItem("");
					}

					OrderItem << new QStandardItem(QString::number(order->GetCount()))
						<< new QStandardItem(QString::number(order->GetSum()))
					    << new QStandardItem(currency->GetShortName().c_str())
						<< new QStandardItem(QString::number(order->GetWorkerID()))
						<< new QStandardItem(QString::number(order->GetUserID()))
						<< new QStandardItem(QString::number(order->GetStatusID()))
						<< new QStandardItem(QString::number(order->GetCurrencyID()));

					QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
					itemModel->appendRow(OrderItem);
					dialogBL->CommitTransaction(errorMessage);
					delete user;
					delete worker;
					delete currency;
				}
				else
				{
					dialogBL->CancelTransaction(errorMessage);
					QMessageBox::information(NULL, QString(tr("Warning")),
						QString(tr("Cannot create this user! Role or location are wrong!")),
						QString(tr("Ok")));
					errorMessage.clear();
					delete status;
					return;
				}
				delete status;
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
			dialogBL->CancelTransaction(errorMessage);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr("Please contact with Administrator, seems DB is not valid!")),
				QString(tr("Ok")));
		}
	}
	else
	{
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(tr("Please recheck all fields, especially product list!")),
			QString(tr("Ok")));
	}
	errorMessage.clear();
}

void CreateOrdDlg::EditOrder()
{
	errorMessage.clear();
	if (0 != userEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != currencyEdit->text().toInt())
	{
		if (order->GetUserID() != userEdit->text().toInt() || QString(order->GetDate().c_str()) != dateEdit->text() ||
			order->GetWorkerID() != workerEdit->text().toInt() || order->GetCount() != prodCountEdit->text().toInt() ||
			 order->GetSum() != sumEdit->text().toInt()
			|| order->GetCurrencyID() != currencyEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			BusinessLayer::Status *status = new BusinessLayer::Status();
			status->SetName("edited");
			std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
			std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);

			if (statusVector.size() > 0)
			{
				SetOrderParams(userEdit->text().toInt(), dateEdit->text(), workerEdit->text().toInt(), prodCountEdit->text().toInt(),
					sumEdit->text().toInt(), statusVector.at(0).GetID(), currencyEdit->text().toInt());
				dialogBL->StartTransaction(errorMessage);
				if (dialogBL->UpdateOrder(order, errorMessage))
				{
					//updating order data
					QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
					QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
					itemModel->item(mIndex.row(), 1)->setText(order->GetDate().c_str());
					
					BusinessLayer::Status *status = new BusinessLayer::Status();
					status->SetName(statusEdit->text().toUtf8().constData());
					std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
					std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);
					if (statusVector.size() > 0)
					{
						itemModel->item(mIndex.row(), 2)->setText(statusVector.at(0).GetCode().c_str());
						itemModel->item(mIndex.row(), 3)->setText(statusVector.at(0).GetName().c_str());
					}
					else
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr("This status does not valid, cannot create order!")),
							QString(tr("Ok")));
						return;
					}
										
					BusinessLayer::User *user = new BusinessLayer::User();
					//user->SetID(userEdit->text().toInt());
					//std::string userFilter = dialogBL->GenerateFilter<BusinessLayer::User>(user);
					//std::vector<BusinessLayer::UserView> userVector = dialogBL->GetAllDataForClass<BusinessLayer::UserView>(errorMessage, userFilter);
					
					BusinessLayer::User *worker = new BusinessLayer::User();
					//worker->SetID(workerEdit->text().toInt());
					//std::string workerFilter = dialogBL->GenerateFilter<BusinessLayer::User>(worker);
					//std::vector<BusinessLayer::UserView> workerVector = dialogBL->GetAllDataForClass<BusinessLayer::UserView>(errorMessage, workerFilter);
					
					BusinessLayer::Currency *currency = new BusinessLayer::Currency();

					if (!user->GetUserByID(dialogBL->GetOrmasDal(),order->GetUserID(),errorMessage)
						|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), order->GetCurrencyID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						errorMessage.clear();
						delete worker;
						delete currency;
						delete user;
						delete status;
						return;
					}

					if (order->GetWorkerID() > 0)
					{
						if (!worker->GetUserByID(dialogBL->GetOrmasDal(), order->GetWorkerID(), errorMessage))
						{
							dialogBL->CancelTransaction(errorMessage);
							QMessageBox::information(NULL, QString(tr("Warning")),
								QString(tr(errorMessage.c_str())),
								QString(tr("Ok")));
							errorMessage.clear();
							delete worker;
							return;
						}
					}

					itemModel->item(mIndex.row(), 4)->setText(user->GetName().c_str());
					itemModel->item(mIndex.row(), 5)->setText(user->GetPhone().c_str());
					itemModel->item(mIndex.row(), 6)->setText(user->GetAddress().c_str());
					itemModel->item(mIndex.row(), 7)->setText(user->GetFirm().c_str());
					if (order->GetWorkerID() > 0)
					{
						itemModel->item(mIndex.row(), 8)->setText(worker->GetName().c_str());
						itemModel->item(mIndex.row(), 9)->setText(worker->GetPhone().c_str());
					}
					else
					{
						itemModel->item(mIndex.row(), 8)->setText("");
						itemModel->item(mIndex.row(), 9)->setText("");
					}
					
					itemModel->item(mIndex.row(), 9)->setText(QString::number(order->GetCount()));
					itemModel->item(mIndex.row(), 10)->setText(QString::number(order->GetSum()));
					itemModel->item(mIndex.row(), 11)->setText(currency->GetShortName().c_str());
					itemModel->item(mIndex.row(), 12)->setText(QString::number(order->GetWorkerID()));
					itemModel->item(mIndex.row(), 13)->setText(QString::number(order->GetUserID()));
					itemModel->item(mIndex.row(), 14)->setText(QString::number(order->GetStatusID()));
					itemModel->item(mIndex.row(), 14)->setText(QString::number(order->GetCurrencyID()));
					
					emit itemModel->dataChanged(mIndex, mIndex);
					this->close();
					
					dialogBL->CommitTransaction(errorMessage);
					
					delete user;
					delete worker;
					delete currency;
					delete status;
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
				dialogBL->CancelTransaction(errorMessage);
				QMessageBox::information(NULL, QString(tr("Warning")),
					QString(tr("Please contact with Administrator, seems DB is not valid!")),
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

void CreateOrdDlg::Close()
{
	this->close();
}

void CreateOrdDlg::OpenUserDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("User"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	BusinessLayer::Role *role = new BusinessLayer::Role();
	role->SetName("CLIENT");
	std::string roleFilter = dialogBL->GenerateFilter<BusinessLayer::Role>(role);
	std::vector<BusinessLayer::Role> roleVector = dialogBL->GetAllDataForClass<BusinessLayer::Role>(errorMessage, roleFilter);
	if (roleVector.size() == 0)
	{
		delete role;
		QString message = tr("Sorry could not define the role for this user!");
		mainForm->statusBar()->showMessage(message);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(message),
			QString(tr("Ok")));
		errorMessage = "";
		return;
	}
	BusinessLayer::User *user = new BusinessLayer::User();
	user->SetRoleID(roleVector.at(0).GetID());
	std::string userFilter = dialogBL->GenerateFilter<BusinessLayer::User>(user);
	std::vector<BusinessLayer::UserView> userVector = dialogBL->GetAllDataForClass<BusinessLayer::UserView>(errorMessage, userFilter);
	if (userVector.size() == 0)
	{
		delete role;
		QString message = tr("Sorry could not find user with \"client\" role!");
		mainForm->statusBar()->showMessage(message);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(message),
			QString(tr("Ok")));
		errorMessage = "";
		return;
	}

	dForm->FillTable<BusinessLayer::UserView>(errorMessage,userFilter);
	if (errorMessage.empty())
	{
		dForm->createOrdDlg = this;
		dForm->setObjectName("clientForm");
		dForm->QtConnect<BusinessLayer::UserView>();
		QMdiSubWindow *clientWindow = new QMdiSubWindow;
		clientWindow->setWidget(dForm);
		clientWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(clientWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All clients are shown");
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

void CreateOrdDlg::OpenWorkerDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("User"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	BusinessLayer::Role *role = new BusinessLayer::Role();
	role->SetName("EXPEDITOR");
	std::string roleFilter = dialogBL->GenerateFilter<BusinessLayer::Role>(role);
	std::vector<BusinessLayer::Role> roleVector = dialogBL->GetAllDataForClass<BusinessLayer::Role>(errorMessage, roleFilter);
	
	if (roleVector.size() == 0)
	{
		delete role;
		QString message = tr("Sorry could not define the role for this worker!");
		mainForm->statusBar()->showMessage(message);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(message),
			QString(tr("Ok")));
		errorMessage = "";
		return;
	}

	BusinessLayer::User *user = new BusinessLayer::User();
	user->SetRoleID(roleVector.at(0).GetID());
	std::string userFilter = dialogBL->GenerateFilter<BusinessLayer::User>(user);
	std::vector<BusinessLayer::UserView> userVector = dialogBL->GetAllDataForClass<BusinessLayer::UserView>(errorMessage, userFilter);
	if (userVector.size() == 0)
	{
		delete role;
		QString message = tr("Sorry could not find worker with \"expeditor\" role!");
		mainForm->statusBar()->showMessage(message);
		QMessageBox::information(NULL, QString(tr("Warning")),
			QString(message),
			QString(tr("Ok")));
		errorMessage = "";
		return;
	}

	dForm->FillTable<BusinessLayer::UserView>(errorMessage, userFilter);
	if (errorMessage.empty())
	{
		dForm->createOrdDlg = this;
		dForm->setObjectName("workerForm");
		dForm->QtConnect<BusinessLayer::UserView>();
		QMdiSubWindow *workerWindow = new QMdiSubWindow;
		workerWindow->setWidget(dForm);
		workerWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(workerWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All clients are shown");
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

void CreateOrdDlg::OpenStsDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Status"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);

	dForm->FillTable<BusinessLayer::Status>(errorMessage);
	if (errorMessage.empty())
	{
		dForm->createOrdDlg = this;
		dForm->setObjectName("statusForm");
		dForm->QtConnect<BusinessLayer::Status>();
		QMdiSubWindow *statusWindow = new QMdiSubWindow;
		statusWindow->setWidget(dForm);
		statusWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(statusWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All statuses are shown");
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

void CreateOrdDlg::OpenCurDlg()
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
		dForm->createOrdDlg = this;
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

void CreateOrdDlg::OpenAddProdDlg()
{
	this->hide();
	this->setModal(false);
	this->show();
	DataForm *userParent = (DataForm *)parent();
	MainForm *mainForm = (MainForm *)userParent->GetParent();
	QString message = tr("Loading...");
	mainForm->statusBar()->showMessage(message);
	DataForm *dForm = new DataForm(dialogBL, mainForm);
	dForm->setWindowTitle(tr("Add product"));
	dForm->hide();
	dForm->setWindowModality(Qt::WindowModal);
	BusinessLayer::ProductList *prodList = new BusinessLayer::ProductList();
	prodList->SetOrderID(order->GetID());
	std::string prodListFilter = dialogBL->GenerateFilter<BusinessLayer::ProductList>(prodList);
	dForm->FillTable<BusinessLayer::ProductListView>(errorMessage, prodListFilter);
	if (errorMessage.empty())
	{
		dForm->createOrdDlg = this;
		dForm->setObjectName("addProdForm");
		dForm->QtConnect<BusinessLayer::ProductListView>();
		QMdiSubWindow *returnWindow = new QMdiSubWindow;
		returnWindow->setWidget(dForm);
		returnWindow->setAttribute(Qt::WA_DeleteOnClose);
		mainForm->mdiArea->addSubWindow(returnWindow);
		dForm->topLevelWidget();
		dForm->activateWindow();
		QApplication::setActiveWindow(dForm);
		dForm->show();
		dForm->raise();
		QString message = tr("All products are shown");
		mainForm->statusBar()->showMessage(message);
		dForm->orderID = order->GetID();
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

	