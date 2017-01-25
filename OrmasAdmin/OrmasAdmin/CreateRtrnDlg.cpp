#include "stdafx.h"
#include <QMessageBox>
#include "MainForm.h"
#include "DataForm.h"
#include "ExtraFunctions.h"
#include "CreateRtrnDlg.h"

CreateRtrnDlg::CreateRtrnDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent) :QDialog(parent)
{
	setupUi(this);
	//setModal(true);
	dialogBL = ormasBL;
	ret->SetID(dialogBL->GenerateID());
	QRegExp expr("\\d*");
	QRegExpValidator v(expr, 0);
	userEdit->setValidator(&v);
	workerEdit->setValidator(&v);
	prodCountEdit->setValidator(&v);
	userEdit->setValidator(&v);
	statusEdit->setValidator(&v);
	sumEdit->setReadOnly(true);
	currencyEdit->setValidator(&v);
	if (true == updateFlag)
	{
		QObject::connect(okBtn, &QPushButton::released, this, &CreateRtrnDlg::EditReturn);
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
		QObject::connect(okBtn, &QPushButton::released, this, &CreateRtrnDlg::CreateReturn);
	}
	QObject::connect(cancelBtn, &QPushButton::released, this, &CreateRtrnDlg::Close);
	QObject::connect(userBtn, &QPushButton::released, this, &CreateRtrnDlg::OpenUserDlg);
	QObject::connect(statusBtn, &QPushButton::released, this, &CreateRtrnDlg::OpenStsDlg);
	QObject::connect(workerBtn, &QPushButton::released, this, &CreateRtrnDlg::OpenWorkerDlg);
	QObject::connect(currencyBtn, &QPushButton::released, this, &CreateRtrnDlg::OpenCurDlg);
	QObject::connect(addProdBtn, &QPushButton::released, this, &CreateRtrnDlg::OpenAddProdDlg);
}

void CreateRtrnDlg::SetReturnParams(int rUserID, QString rDate, int rWorkerID, int rCount, double rSum, int rStatusID, int rCurrencyID)
{
	ret->SetUserID(rUserID);
	ret->SetDate(rDate.toUtf8().constData());
	ret->SetWorkerID(rWorkerID);
	ret->SetCount(rCount);
	ret->SetSum(rSum);
	ret->SetStatusID(rStatusID);
	ret->SetCurrencyID(rCurrencyID);
}

void CreateRtrnDlg::FillEditElements(int rUserID, QString rDate, int rWorkerID, int rCount, double rSum, int rStatusID, int rCurrencyID)
{
	userEdit->setText(QString::number(rUserID));
	dateEdit->setDate(QDate::fromString(rDate, "dd.MM.yyyy"));
	workerEdit->setText(QString::number(rWorkerID));
	prodCountEdit->setText(QString::number(rCount));
	sumEdit->setText(QString::number(rSum));
	currencyEdit->setText(QString::number(rCurrencyID));
}

void CreateRtrnDlg::SetID(int ID, QString childName)
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

bool CreateRtrnDlg::FillDlgElements(QTableView* cTable)
{
	QModelIndex mIndex = cTable->selectionModel()->currentIndex();
	if (mIndex.row() >= 0)
	{
		SetReturnParams(cTable->model()->data(cTable->model()->index(mIndex.row(), 14)).toString().toInt(),
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

void CreateRtrnDlg::CreateReturn()
{
	errorMessage.clear();
	if ((0 != userEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt() && 0 != sumEdit->text().toInt()
		&& 0 != currencyEdit->text().toInt()))
	{
		DataForm *parentDataForm = (DataForm*)parentWidget();

		BusinessLayer::Status *status = new BusinessLayer::Status();
		status->SetName("to return");
		std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
		std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);

		if (statusVector.size() > 0)
		{
			SetReturnParams(userEdit->text().toInt(), dateEdit->text(), workerEdit->text().toInt(), prodCountEdit->text().toInt(),
				sumEdit->text().toInt(), statusVector.at(0).GetID(), currencyEdit->text().toInt());
			dialogBL->StartTransaction(errorMessage);
			if (dialogBL->CreateReturn(ret, errorMessage))
			{
				if (0 != statusVector.size())
				{
					QList<QStandardItem*> RetrunItem;
					RetrunItem << new QStandardItem(QString::number(ret->GetID()))
						<< new QStandardItem(ret->GetDate().c_str())
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

					if (!user->GetUserByID(dialogBL->GetOrmasDal(), ret->GetUserID(), errorMessage)
						|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), ret->GetCurrencyID(), errorMessage))
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
					if (ret->GetWorkerID() > 0)
					{
						if (!worker->GetUserByID(dialogBL->GetOrmasDal(), ret->GetWorkerID(), errorMessage))
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
					if (0 != ret->GetUserID())
					{
						RetrunItem << new QStandardItem(user->GetName().c_str())
							<< new QStandardItem(user->GetPhone().c_str())
							<< new QStandardItem(user->GetAddress().c_str())
							<< new QStandardItem(user->GetFirm().c_str());
					}
					else
					{
						RetrunItem << new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("")
							<< new QStandardItem("");
					}
					if (0 != ret->GetWorkerID())
					{
						RetrunItem << new QStandardItem(worker->GetName().c_str())
							<< new QStandardItem(worker->GetPhone().c_str());
					}
					else
					{
						RetrunItem << new QStandardItem("")
							<< new QStandardItem("");
					}

					RetrunItem << new QStandardItem(QString::number(ret->GetCount()))
						<< new QStandardItem(QString::number(ret->GetSum()))
						<< new QStandardItem(currency->GetShortName().c_str())
						<< new QStandardItem(QString::number(ret->GetWorkerID()))
						<< new QStandardItem(QString::number(ret->GetUserID()))
						<< new QStandardItem(QString::number(ret->GetStatusID()))
						<< new QStandardItem(QString::number(ret->GetCurrencyID()));

					QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
					itemModel->appendRow(RetrunItem);
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
						QString(tr("Cannot create this user! Role or location are wrong!")),
						QString(tr("Ok")));
					errorMessage.clear();
					return;
				}
				
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

void CreateRtrnDlg::EditReturn()
{
	errorMessage.clear();
	if ((0 != userEdit->text().toInt() && !dateEdit->text().isEmpty()
		&& 0 != prodCountEdit->text().toInt()  && 0 != sumEdit->text().toInt()
		&& 0 != currencyEdit->text().toInt()))
	{
		if (ret->GetUserID() != userEdit->text().toInt() || QString(ret->GetDate().c_str()) != dateEdit->text() ||
			ret->GetWorkerID() != workerEdit->text().toInt() || ret->GetCount() != prodCountEdit->text().toInt() || 
			ret->GetSum() != sumEdit->text().toInt() ||
			ret->GetCurrencyID() != currencyEdit->text().toInt())
		{
			DataForm *parentDataForm = (DataForm*)parentWidget();
			BusinessLayer::Status *status = new BusinessLayer::Status();
			status->SetName("edited");
			std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
			std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);

			if (statusVector.size() > 0)
			{
				SetReturnParams(userEdit->text().toInt(), dateEdit->text(), workerEdit->text().toInt(), prodCountEdit->text().toInt(),
					sumEdit->text().toInt(), statusVector.at(0).GetID(), currencyEdit->text().toInt());
				dialogBL->StartTransaction(errorMessage);
				if (dialogBL->UpdateReturn(ret, errorMessage))
				{
					//updating return data
					QStandardItemModel *itemModel = (QStandardItemModel *)parentDataForm->tableView->model();
					QModelIndex mIndex = parentDataForm->tableView->selectionModel()->currentIndex();
					itemModel->item(mIndex.row(), 1)->setText(dateEdit->text());

					BusinessLayer::Status *status = new BusinessLayer::Status();
					status->SetName(statusEdit->text().toUtf8().constData());
					std::string statusFilter = dialogBL->GenerateFilter<BusinessLayer::Status>(status);
					std::vector<BusinessLayer::Status> statusVector = dialogBL->GetAllDataForClass<BusinessLayer::Status>(errorMessage, statusFilter);
					if (statusVector.size() > 1)
					{
						itemModel->item(mIndex.row(), 2)->setText(statusVector.at(0).GetCode().c_str());
						itemModel->item(mIndex.row(), 3)->setText(statusVector.at(0).GetName().c_str());
					}
					else
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr("This status does not exist, cannot create return!")),
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
					
					if (!user->GetUserByID(dialogBL->GetOrmasDal(), ret->GetUserID(), errorMessage)
						|| !currency->GetCurrencyByID(dialogBL->GetOrmasDal(), ret->GetCurrencyID(), errorMessage))
					{
						dialogBL->CancelTransaction(errorMessage);
						QMessageBox::information(NULL, QString(tr("Warning")),
							QString(tr(errorMessage.c_str())),
							QString(tr("Ok")));
						
						errorMessage.clear();
						delete currency;
						delete user;
						delete status;
						return;
					}
					if (ret->GetWorkerID() > 0)
					{
						if (!worker->GetUserByID(dialogBL->GetOrmasDal(), ret->GetWorkerID(), errorMessage))
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
					if (ret->GetWorkerID()>0)
					{
						itemModel->item(mIndex.row(), 8)->setText(worker->GetName().c_str());
						itemModel->item(mIndex.row(), 9)->setText(worker->GetPhone().c_str());
					}
					else
					{
						itemModel->item(mIndex.row(), 8)->setText("");
						itemModel->item(mIndex.row(), 9)->setText("");
					}
					itemModel->item(mIndex.row(), 9)->setText(QString::number(ret->GetCount()));
					itemModel->item(mIndex.row(), 10)->setText(QString::number(ret->GetSum()));
					itemModel->item(mIndex.row(), 11)->setText(currency->GetShortName().c_str());
					itemModel->item(mIndex.row(), 12)->setText(QString::number(ret->GetWorkerID()));
					itemModel->item(mIndex.row(), 13)->setText(QString::number(ret->GetUserID()));
					itemModel->item(mIndex.row(), 14)->setText(QString::number(ret->GetStatusID()));
					itemModel->item(mIndex.row(), 14)->setText(QString::number(ret->GetCurrencyID()));
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

void CreateRtrnDlg::Close()
{
	this->close();
}

void CreateRtrnDlg::OpenUserDlg()
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
			QString(tr(errorMessage.c_str())),
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
	dForm->FillTable<BusinessLayer::UserView>(errorMessage, userFilter);
	if (errorMessage.empty())
	{
		dForm->createRtrnDlg = this;
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

void CreateRtrnDlg::OpenWorkerDlg()
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
		dForm->createRtrnDlg = this;
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

void CreateRtrnDlg::OpenStsDlg()
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
		dForm->createRtrnDlg = this;
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

void CreateRtrnDlg::OpenCurDlg()
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
		dForm->createRtrnDlg = this;
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

void CreateRtrnDlg::OpenAddProdDlg()
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
	prodList->SetReturnID(ret->GetID());
	std::string prodListFilter = dialogBL->GenerateFilter<BusinessLayer::ProductList>(prodList);
	dForm->FillTable<BusinessLayer::ProductListView>(errorMessage, prodListFilter);
	if (errorMessage.empty())
	{
		dForm->createRtrnDlg = this;
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
		dForm->returnID = ret->GetID();
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