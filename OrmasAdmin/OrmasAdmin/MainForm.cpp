#include "stdafx.h"
#include <QMessageBox>
#include "MainForm.h"
#include "ExtraFunctions.h"

MainForm::MainForm(BusinessLayer::OrmasBL *ormasBL)
{
	setupUi(this);
	QString message = tr("Ready");
	statusBar()->showMessage(message);
	oBL = ormasBL;
	CreateConnections();
}


void MainForm::CreateConnections()
{
	QObject::connect(actionShowAllUser, &QAction::triggered, this, &MainForm::ShowUsers);
	QObject::connect(actionCreateUser, &QAction::triggered, this, &MainForm::CreateUser);
	QObject::connect(actionAccess, &QAction::triggered, this, &MainForm::CheckAccess);
	QObject::connect(actionDeleteUser, &QAction::triggered, this, &MainForm::DeleteUser);
	QObject::connect(actionProductsType, &QAction::triggered, this, &MainForm::ShowProductsType);
	QObject::connect(actionProducts, &QAction::triggered, this, &MainForm::ShowProducts);
	QObject::connect(actionShowAllOrders, &QAction::triggered, this, &MainForm::ShowOrders);
	QObject::connect(actionProductsList, &QAction::triggered, this, &MainForm::ShowProductsList);
	QObject::connect(actionCreateOrder, &QAction::triggered, this, &MainForm::CreateOrder);
	QObject::connect(actionDeleteOrder, &QAction::triggered, this, &MainForm::DeleteOrder);
	QObject::connect(actionShowAllReturns, &QAction::triggered, this, &MainForm::ShowReturns);
	QObject::connect(actionCreateReturn, &QAction::triggered, this, &MainForm::CreateReturn);
	QObject::connect(actionDeleteReturn, &QAction::triggered, this, &MainForm::DeleteReturn);
	QObject::connect(actionCompany, &QAction::triggered, this, &MainForm::ShowCompanies);
	QObject::connect(actionCurrency, &QAction::triggered, this, &MainForm::ShowCurrencies);
	QObject::connect(actionMeasure, &QAction::triggered, this, &MainForm::ShowMeasures);
	QObject::connect(actionLocation, &QAction::triggered, this, &MainForm::ShowLocations);
	QObject::connect(actionRoles, &QAction::triggered, this, &MainForm::ShowRoles);
	QObject::connect(actionStatus, &QAction::triggered, this, &MainForm::ShowStatus);
	QObject::connect(actionAbout, &QAction::triggered, this, &MainForm::About);
}

QMdiSubWindow* MainForm::GetWindowByName(QString name)
{
	return GetSubWindow(mdiArea->subWindowList(), name);
}

void MainForm::ShowUsers()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("userForm"));
	if (checkedWidget == nullptr)
	{
		errorMessage = "";
		DataForm *dForm = new DataForm(oBL,this);
		dForm->setWindowTitle(tr("Users"));
		dForm->FillTable<BusinessLayer::User>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("userForm");
			QMdiSubWindow *userWindow = new QMdiSubWindow;
			userWindow->setWidget(dForm);
			userWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(userWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All users are shown");
			statusBar()->showMessage(message);
		}
		else
		{
			delete dForm;
			QString message = tr("End with error!");
			statusBar()->showMessage(message);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage = "";
		}
	}
	else
	{
		checkedWidget->topLevelWidget();
		checkedWidget->activateWindow();
		QString message = tr("All users are shown");
		statusBar()->showMessage(message);
	}
}

void MainForm::CreateUser(){};
void MainForm::CheckAccess(){};
void MainForm::DeleteUser(){};

void MainForm::ShowProductsType()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("productTypeForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL,this);
		dForm->setWindowTitle(tr("Product types"));
		dForm->FillTable<BusinessLayer::ProductType>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::ProductType>();
			dForm->setObjectName("productTypeForm");
			QMdiSubWindow *prodTypeWindow = new QMdiSubWindow;
			prodTypeWindow->setWidget(dForm);
			prodTypeWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(prodTypeWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All product types are shown");
			statusBar()->showMessage(message);
		}
		else
		{
			delete dForm;
			QString message = tr("End with error!");
			statusBar()->showMessage(message);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage = "";
		}
	}
	else
	{
		checkedWidget->topLevelWidget();
		checkedWidget->activateWindow();
		QString message = tr("All product types are shown");
		statusBar()->showMessage(message);
	}
	
}

void MainForm::ShowProducts()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("productForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL,this);
		dForm->setWindowTitle(tr("Products"));
		dForm->FillTable<BusinessLayer::Product>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("productForm");
			QMdiSubWindow *productWindow = new QMdiSubWindow;
			productWindow->setWidget(dForm);
			productWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(productWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All products are shown");
			statusBar()->showMessage(message);
		}
		else
		{
			delete dForm;
			QString message = tr("End with error!");
			statusBar()->showMessage(message);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage = "";
		}
	}
	else
	{
		checkedWidget->topLevelWidget();
		checkedWidget->activateWindow();
		QString message = tr("All products are shown");
		statusBar()->showMessage(message);
	}
	
}

void MainForm::ShowOrders()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("orderForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL,this);
		dForm->setWindowTitle(tr("Orders"));
		dForm->FillTable<BusinessLayer::OrderView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("orderForm");
			QMdiSubWindow *orderWindow = new QMdiSubWindow;
			orderWindow->setWidget(dForm);
			orderWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(orderWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All orders are shown");
			statusBar()->showMessage(message);
		}
		else
		{
			delete dForm;
			QString message = tr("End with error!");
			statusBar()->showMessage(message);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage = "";
		}
	}
	else
	{
		checkedWidget->topLevelWidget();
		checkedWidget->activateWindow();
		QString message = tr("All orders are shown");
		statusBar()->showMessage(message);
	}
	
}

void MainForm::ShowProductsList()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("productListForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL,this);
		dForm->setWindowTitle(tr("Products lists"));
		dForm->FillTable<BusinessLayer::ProductList>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("productListForm");
			QMdiSubWindow *prodListWindow = new QMdiSubWindow;
			prodListWindow->setWidget(dForm);
			prodListWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(prodListWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All product lists are shown");
			statusBar()->showMessage(message);
		}
		else
		{
			delete dForm;
			QString message = tr("End with error!");
			statusBar()->showMessage(message);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage = "";
		}
	}
	else
	{
		checkedWidget->topLevelWidget();
		checkedWidget->activateWindow();
		QString message = tr("All product lists are shown");
		statusBar()->showMessage(message);
	}
	
}

void MainForm::CreateOrder(){}
void MainForm::DeleteOrder(){}

void MainForm::ShowReturns()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("returnForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL,this);
		dForm->setWindowTitle(tr("Returns"));
		dForm->FillTable<BusinessLayer::ReturnView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("returnForm");
			QMdiSubWindow *returnWindow = new QMdiSubWindow;
			returnWindow->setWidget(dForm);
			returnWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(returnWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All returns are shown");
			statusBar()->showMessage(message);
		}
		else
		{
			delete dForm;
			QString message = tr("End with error!");
			statusBar()->showMessage(message);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage = "";
		}
	}
	else
	{
		checkedWidget->topLevelWidget();
		checkedWidget->activateWindow();
		QString message = tr("All returns are shown");
		statusBar()->showMessage(message);
	}
	
}

void MainForm::CreateReturn(){}
void MainForm::DeleteReturn(){}

void MainForm::ShowCompanies()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("companyForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL,this);
		dForm->setWindowTitle(tr("Companies"));
		dForm->FillTable<BusinessLayer::Company>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("companyForm");
			dForm->QtConnect<BusinessLayer::Company>();
			QMdiSubWindow *companyWindow = new QMdiSubWindow;
			companyWindow->setWidget(dForm);
			companyWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(companyWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All companies are shown");
			statusBar()->showMessage(message);
		}
		else
		{
			delete dForm;
			QString message = tr("End with error!");
			statusBar()->showMessage(message);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage = "";
		}
	}
	else
	{
		checkedWidget->topLevelWidget();
		checkedWidget->activateWindow();
		QString message = tr("All companies are shown");
		statusBar()->showMessage(message);
	}
	
}

void MainForm::ShowCurrencies()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("currencyForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL,this);
		dForm->setWindowTitle(tr("Currencies"));
		dForm->FillTable<BusinessLayer::Currency>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("currencyForm");
			dForm->QtConnect<BusinessLayer::Currency>();
			QMdiSubWindow *currencyWindow = new QMdiSubWindow;
			currencyWindow->setWidget(dForm);
			currencyWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(currencyWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All currencies are shown");
			statusBar()->showMessage(message);
		}
		else
		{
			delete dForm;
			QString message = tr("End with error!");
			statusBar()->showMessage(message);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage = "";
		}
	}
	else
	{
		checkedWidget->topLevelWidget();
		checkedWidget->activateWindow();
		QString message = tr("All currencies are shown");
		statusBar()->showMessage(message);
	}
	
}

void MainForm::ShowMeasures()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("measureForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL,this);
		dForm->setWindowTitle(tr("Measures"));
		dForm->FillTable<BusinessLayer::Measure>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("measureForm");
			dForm->QtConnect<BusinessLayer::Measure>();
			QMdiSubWindow *measureWindow = new QMdiSubWindow;
			measureWindow->setWidget(dForm);
			measureWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(measureWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All measures are shown");
			statusBar()->showMessage(message);
		}
		else
		{
			delete dForm;
			QString message = tr("End with error!");
			statusBar()->showMessage(message);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage = "";
		}
	}
	else
	{
		checkedWidget->topLevelWidget();
		checkedWidget->activateWindow();
		QString message = tr("All measures are shown");
		statusBar()->showMessage(message);
	}
	
}

void MainForm::ShowLocations()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("locationForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL,this);
		dForm->setWindowTitle(tr("Locations"));
		dForm->FillTable<BusinessLayer::Location>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("locationForm");
			dForm->QtConnect<BusinessLayer::Location>();
			QMdiSubWindow *locationWindow = new QMdiSubWindow;
			locationWindow->setWidget(dForm);
			locationWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(locationWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All locations are shown");
			statusBar()->showMessage(message);
		}
		else
		{
			delete dForm;
			QString message = tr("End with error!");
			statusBar()->showMessage(message);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage = "";
		}
	}
	else
	{
		checkedWidget->topLevelWidget();
		checkedWidget->activateWindow();
		QString message = tr("All locations are shown");
		statusBar()->showMessage(message);
	}
	
}

void MainForm::ShowRoles()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("roleForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Roles"));
		dForm->FillTable<BusinessLayer::Role>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("roleForm");
			dForm->QtConnect<BusinessLayer::Role>();
			QMdiSubWindow *roleWindow = new QMdiSubWindow;
			roleWindow->setWidget(dForm);
			roleWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(roleWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All roles are shown");
			statusBar()->showMessage(message);
		}
		else
		{
			delete dForm;
			QString message = tr("End with error!");
			statusBar()->showMessage(message);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			errorMessage = "";
		}
	}
	else
	{
		checkedWidget->topLevelWidget();
		checkedWidget->activateWindow();
		QString message = tr("All roles are shown");
		statusBar()->showMessage(message);
	}
	
}

void MainForm::ShowStatus()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("statusForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL,this);
		dForm->setWindowTitle(tr("Statuses"));
		dForm->FillTable<BusinessLayer::Status>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("statusForm");
			dForm->QtConnect<BusinessLayer::Status>();
			QMdiSubWindow *statusWindow = new QMdiSubWindow;
			statusWindow->setWidget(dForm);
			statusWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(statusWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All statuses are shown");
			statusBar()->showMessage(message);
		}
		else
		{
			delete dForm;
			QString message = tr("End with error!");
			statusBar()->showMessage(message);
			QMessageBox::information(NULL, QString(tr("Warning")),
				QString(tr(errorMessage.c_str())),
				QString(tr("Ok")));
			QMessageBox msgBox;
			errorMessage = "";
		}
	}
	else
	{
		checkedWidget->topLevelWidget();
		checkedWidget->activateWindow();
		QString message = tr("All statuses are shown");
		statusBar()->showMessage(message);
	}
	
}

void MainForm::About(){}