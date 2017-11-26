#include "stdafx.h"
#include <QMessageBox>
#include "MainForm.h"
#include "ExtraFunctions.h"

MainForm::MainForm(BusinessLayer::OrmasBL *ormasBL, BusinessLayer::User* user)
{
	setupUi(this);
	QString message = tr("Ready");
	statusBar()->showMessage(message);
	oBL = ormasBL;
	userAccess = new BusinessLayer::Access();
	loggedUser = user;
	CreateConnections();
	rights = userAccess->GetRightsList(&oBL->GetOrmasDal(), user);
	this->setWindowTitle(this->windowTitle() + " (" + user->GetName().c_str() + "." + user->GetSurname().c_str()+ ")");
	SetMenuItemsByAccess(rights);
}

void MainForm::SetMenuItemsByAccess(std::vector<int> rights)
{
	SetAllMenuInvisible();
	if (1 == rights.size())
	{
		if (userAccess->CheckAccess(&oBL->GetOrmasDal(), rights.at(0), "ALL"))
		{
			SetAllMenuVisible();
			return;
		}
	}
	if (0 < rights.size())
	{
		std::string errorMessage= "";
		BusinessLayer::AccessItem item;
		for each (auto id in rights)
		{
			if (userAccess->CheckAccess(&oBL->GetOrmasDal(), id, "MENU"))
			{
				item.Clear();
				item.GetAccessItemByID(oBL->GetOrmasDal(), id, errorMessage);
				if (errorMessage.empty())
				{
					if(0 != this->findChild<QMenu*>(QString(item.GetNameEng().c_str())))
						this->findChild<QMenu*>(QString(item.GetNameEng().c_str()))->setEnabled(true);
				}
			}
			if (userAccess->CheckAccess(&oBL->GetOrmasDal(), id, "MENUITEM"))
			{
				item.Clear();
				item.GetAccessItemByID(oBL->GetOrmasDal(), id, errorMessage);
				if (errorMessage.empty())
				{
					if(0 != this->findChild<QAction*>(QString(item.GetNameEng().c_str())))
						this->findChild<QAction*>(QString(item.GetNameEng().c_str()))->setVisible(true);
					if (0 != this->findChild<QAction*>(QString(item.GetNameEng().c_str())))
					{
						QList<QWidget *> widgetList = this->findChild<QAction*>(QString(item.GetNameEng().c_str()))->associatedWidgets();
						if (widgetList.size() == 1)
							widgetList.at(0)->setEnabled(true);
					}
						
				}
			}
		}
	}
}

void MainForm::SetAllMenuInvisible()
{
	menuUsers->setEnabled(false);
	menuProducts->setEnabled(false);
	menuOrders->setEnabled(false);
	menuReturns->setEnabled(false);
	menuWriteOffs->setEnabled(false);
	menuProductions->setEnabled(false);
	menuAccountings->setEnabled(false);
	menuReferences->setEnabled(false);
	menuHelp->setEnabled(true);
	actionAllUsers->setVisible(false);
	actionClients->setVisible(false);
	actionEmployees->setVisible(false);
	actionAccess->setVisible(false);
	actionProductType->setVisible(false);
	actionProducts->setVisible(false);
	actionOrders->setVisible(false);
	actionProductsList->setVisible(false);
	actionOrderList->setVisible(false);
	actionDeleteOrder->setVisible(false);
	actionReturns->setVisible(false);
	actionReturnList->setVisible(false);
	actionDeleteReturn->setVisible(false);
	actionCompany->setVisible(false);
	actionCurrency->setVisible(false);
	actionMeasure->setVisible(false);
	actionLocation->setVisible(false);
	actionRoles->setVisible(false);
	actionStatus->setVisible(false);
	actionProduction->setVisible(false);
	actionAccessItems->setVisible(false);
	actionPrices->setVisible(false);
	actionProductionList->setVisible(false);
	actionWriteOffs->setVisible(false);
	actionWriteOffList->setVisible(false);
	actionUserPhoto->setVisible(false);
	actionProductPhoto->setVisible(false);
	actionPosition->setVisible(false);
	actionRelation->setVisible(false);
	actionRelationType->setVisible(false);
	actionBalances->setVisible(false);
	actionSalary->setVisible(false);
	actionSalaryType->setVisible(false);
	actionPayments->setVisible(false);
	actionPayroll->setVisible(false);
	actionPayslip->setVisible(false);
	actionRefund->setVisible(false);
	actionWithdrawal->setVisible(false);
}

void MainForm::SetAllMenuVisible()
{
	menuUsers->setEnabled(true);
	menuProducts->setEnabled(true);
	menuOrders->setEnabled(true);
	menuReturns->setEnabled(true);
	menuWriteOffs->setEnabled(true);
	menuProductions->setEnabled(true);
	menuAccountings->setEnabled(true);
	menuReferences->setEnabled(true);
	menuHelp->setEnabled(true);
	actionAllUsers->setVisible(true);
	actionClients->setVisible(true);
	actionEmployees->setVisible(true);
	actionAccess->setVisible(true);
	actionProductType->setVisible(true);
	actionProducts->setVisible(true);
	actionOrders->setVisible(true);
	actionProductsList->setVisible(true);
	actionOrderList->setVisible(true);
	actionDeleteOrder->setVisible(true);
	actionReturns->setVisible(true);
	actionReturnList->setVisible(true);
	actionDeleteReturn->setVisible(true);
	actionCompany->setVisible(true);
	actionCurrency->setVisible(true);
	actionMeasure->setVisible(true);
	actionLocation->setVisible(true);
	actionRoles->setVisible(true);
	actionStatus->setVisible(true);
	actionProduction->setVisible(true);
	actionAccessItems->setVisible(true);
	actionPrices->setVisible(true);
	actionProductionList->setVisible(true);
	actionWriteOffs->setVisible(true);
	actionWriteOffList->setVisible(true);
	actionUserPhoto->setVisible(true);
	actionProductPhoto->setVisible(true);
	actionPosition->setVisible(true);
	actionRelation->setVisible(true);
	actionRelationType->setVisible(true);
	actionBalances->setVisible(true);
	actionSalary->setVisible(true);
	actionSalaryType->setVisible(true);
	actionPayments->setVisible(true);
	actionAbout->setVisible(true);
	actionPayroll->setVisible(true);
	actionPayslip->setVisible(true);
	actionRefund->setVisible(true);
	actionWithdrawal->setVisible(true);
}

MainForm::~MainForm()
{
	delete loggedUser;
	delete userAccess;
}

void MainForm::CloseChildsByName()
{
	if (0 != this->findChild<QWidget*>("orderListForm"))
		((DataForm*)this->findChild<QWidget*>("orderListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("returnListForm"))
		((DataForm*)this->findChild<QWidget*>("returnListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("productionListForm"))
		((DataForm*)this->findChild<QWidget*>("productionListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("writeOffListForm"))
		((DataForm*)this->findChild<QWidget*>("writeOffListForm"))->CloseDataForm();
}

void MainForm::CreateConnections()
{
	QObject::connect(actionAllUsers, &QAction::triggered, this, &MainForm::OpenUserForm);
	QObject::connect(actionClients, &QAction::triggered, this, &MainForm::OpenClientForm);
	QObject::connect(actionEmployees, &QAction::triggered, this, &MainForm::OpenEmployeeForm);
	QObject::connect(actionAccess, &QAction::triggered, this, &MainForm::OpenAccessForm);
	QObject::connect(actionAccessItems, &QAction::triggered, this, &MainForm::OpenAccessItemForm);
	QObject::connect(actionUserPhoto, &QAction::triggered, this, &MainForm::OpenUserPhotoForm);
	QObject::connect(actionPosition, &QAction::triggered, this, &MainForm::OpenPositionForm);
	

	QObject::connect(actionProductType, &QAction::triggered, this, &MainForm::OpenProductTypeForm);
	QObject::connect(actionProducts, &QAction::triggered, this, &MainForm::OpenProductForm);
	QObject::connect(actionProductPhoto, &QAction::triggered, this, &MainForm::OpenProductPhotoForm);
	

	QObject::connect(actionOrders, &QAction::triggered, this, &MainForm::OpenOrderForm);
	QObject::connect(actionOrderList, &QAction::triggered, this, &MainForm::OpenOrderListForm);

	QObject::connect(actionReturns, &QAction::triggered, this, &MainForm::OpenReturnForm);
	QObject::connect(actionReturnList, &QAction::triggered, this, &MainForm::OpenReturnListForm);

	QObject::connect(actionProduction, &QAction::triggered, this, &MainForm::OpenProductionForm);
	QObject::connect(actionProductionList, &QAction::triggered, this, &MainForm::OpenProductionListForm);

	QObject::connect(actionWriteOffs, &QAction::triggered, this, &MainForm::OpenWriteOffForm);
	QObject::connect(actionWriteOffList, &QAction::triggered, this, &MainForm::OpenWriteOffListForm);

	
	QObject::connect(actionBalances, &QAction::triggered, this, &MainForm::OpenBalanceForm);
	QObject::connect(actionPayments, &QAction::triggered, this, &MainForm::OpenPaymentForm);
	QObject::connect(actionRefund, &QAction::triggered, this, &MainForm::OpenRefundForm);
	QObject::connect(actionPrices, &QAction::triggered, this, &MainForm::OpenPriceForm);
	QObject::connect(actionSalary, &QAction::triggered, this, &MainForm::OpenSalaryForm);
	QObject::connect(actionSalaryType, &QAction::triggered, this, &MainForm::OpenSalaryTypeForm);
	QObject::connect(actionPayroll, &QAction::triggered, this, &MainForm::OpenPayrollForm);
	QObject::connect(actionWithdrawal, &QAction::triggered, this, &MainForm::OpenWithdrawalForm);
	QObject::connect(actionPayslip, &QAction::triggered, this, &MainForm::OpenPayslipForm);
	
	QObject::connect(actionCompany, &QAction::triggered, this, &MainForm::OpenCompanyForm);
	QObject::connect(actionCurrency, &QAction::triggered, this, &MainForm::OpenCurrencyForm);
	QObject::connect(actionMeasure, &QAction::triggered, this, &MainForm::OpenMeasureForm);
	QObject::connect(actionLocation, &QAction::triggered, this, &MainForm::OpenLocationForm);
	QObject::connect(actionRoles, &QAction::triggered, this, &MainForm::OpenRoleForm);
	QObject::connect(actionStatus, &QAction::triggered, this, &MainForm::OpenStatusForm);
	QObject::connect(actionRelation, &QAction::triggered, this, &MainForm::OpenRelationForm);
	QObject::connect(actionRelationType, &QAction::triggered, this, &MainForm::OpenRelationTypeForm);

	QObject::connect(actionAbout, &QAction::triggered, this, &MainForm::OpenAboutForm);
}

QMdiSubWindow* MainForm::GetWindowByName(QString name)
{
	return GetSubWindow(mdiArea->subWindowList(), name);
}

void MainForm::OpenUserForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("userForm"));
	if (checkedWidget == nullptr)
	{
		errorMessage = "";
		DataForm *dForm = new DataForm(oBL,this);
		dForm->setWindowTitle(tr("Users"));
		dForm->FillTable<BusinessLayer::UserView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::UserView>();
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

void MainForm::OpenClientForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("clientForm"));
	if (checkedWidget == nullptr)
	{
		errorMessage = "";
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Clients"));
		dForm->FillTable<BusinessLayer::ClientView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::ClientView>();
			dForm->setObjectName("clientForm");
			QMdiSubWindow *clientWindow = new QMdiSubWindow;
			clientWindow->setWidget(dForm);
			clientWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(clientWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All clients are shown");
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
		QString message = tr("All clients are shown");
		statusBar()->showMessage(message);
	}
}

void MainForm::OpenEmployeeForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("employeeForm"));
	if (checkedWidget == nullptr)
	{
		errorMessage = "";
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Employees"));
		dForm->FillTable<BusinessLayer::EmployeeView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::EmployeeView>();
			dForm->setObjectName("employeeForm");
			QMdiSubWindow *employeeWindow = new QMdiSubWindow;
			employeeWindow->setWidget(dForm);
			employeeWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(employeeWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All employees are shown");
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
		QString message = tr("All employees are shown");
		statusBar()->showMessage(message);
	}
}

void MainForm::OpenAccessForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("accessForm"));
	if (checkedWidget == nullptr)
	{
		errorMessage = "";
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Accesses"));
		dForm->FillTable<BusinessLayer::Access>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::Access>();
			dForm->setObjectName("accessForm");
			QMdiSubWindow *accessWindow = new QMdiSubWindow;
			accessWindow->setWidget(dForm);
			accessWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(accessWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All accesses are shown");
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
		QString message = tr("All accesses are shown");
		statusBar()->showMessage(message);
	}
}

void MainForm::OpenAccessItemForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("accessItemForm"));
	if (checkedWidget == nullptr)
	{
		errorMessage = "";
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Access items"));
		dForm->FillTable<BusinessLayer::AccessItem>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::AccessItem>();
			dForm->setObjectName("accessItemForm");
			QMdiSubWindow *accessItemWindow = new QMdiSubWindow;
			accessItemWindow->setWidget(dForm);
			accessItemWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(accessItemWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All access items are shown");
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
		QString message = tr("All access items are shown");
		statusBar()->showMessage(message);
	}
}

void MainForm::OpenUserPhotoForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("userPhotoForm"));
	if (checkedWidget == nullptr)
	{
		errorMessage = "";
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("User photo"));
		dForm->FillTable<BusinessLayer::Photo>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::Photo>();
			dForm->setObjectName("userPhotoForm");
			QMdiSubWindow *userPhotoWindow = new QMdiSubWindow;
			userPhotoWindow->setWidget(dForm);
			userPhotoWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(userPhotoWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All user photos are shown");
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
		QString message = tr("All user photos are shown");
		statusBar()->showMessage(message);
	}
}

void MainForm::OpenPositionForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("positionForm"));
	if (checkedWidget == nullptr)
	{
		errorMessage = "";
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Position"));
		dForm->FillTable<BusinessLayer::Position>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::Position>();
			dForm->setObjectName("positionForm");
			QMdiSubWindow *positionWindow = new QMdiSubWindow;
			positionWindow->setWidget(dForm);
			positionWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(positionWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All position are shown");
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
		QString message = tr("All position are shown");
		statusBar()->showMessage(message);
	}
}

void MainForm::OpenProductForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("productForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL,this);
		dForm->setWindowTitle(tr("Products"));
		dForm->FillTable<BusinessLayer::ProductView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::ProductView>();
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

void MainForm::OpenProductTypeForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("productTypeForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
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

void MainForm::OpenProductPhotoForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("productPhotoForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Product photo"));
		dForm->FillTable<BusinessLayer::Photo>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::Photo>();
			dForm->setObjectName("productPhotoForm");
			QMdiSubWindow *prodPhotoWindow = new QMdiSubWindow;
			prodPhotoWindow->setWidget(dForm);
			prodPhotoWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(prodPhotoWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All product photos are shown");
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
		QString message = tr("All product photos are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenOrderForm()
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
			dForm->QtConnect<BusinessLayer::OrderView>();
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

void MainForm::OpenOrderListForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("orderListForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Products in order list"));
		dForm->FillTable<BusinessLayer::OrderListView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::OrderListView>();
			dForm->setObjectName("orderListForm");
			QMdiSubWindow *orderListWindow = new QMdiSubWindow;
			orderListWindow->setWidget(dForm);
			orderListWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(orderListWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All products in order list are shown");
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
		QString message = tr("All products in order list are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenReturnForm()
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
			dForm->QtConnect<BusinessLayer::ReturnView>();
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

void MainForm::OpenReturnListForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("returnListForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Products in return list"));
		dForm->FillTable<BusinessLayer::ReturnListView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::ReturnListView>();
			dForm->setObjectName("returnListForm");
			QMdiSubWindow *returnListWindow = new QMdiSubWindow;
			returnListWindow->setWidget(dForm);
			returnListWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(returnListWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All products in return list are shown");
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
		QString message = tr("All products in return list are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenWriteOffForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("writeOffForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Write-off"));
		dForm->FillTable<BusinessLayer::WriteOffView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::WriteOffView>();
			dForm->setObjectName("writeOffForm");
			QMdiSubWindow *writeOfftWindow = new QMdiSubWindow;
			writeOfftWindow->setWidget(dForm);
			writeOfftWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(writeOfftWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All write-off are shown");
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
		QString message = tr("All write-off are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenWriteOffListForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("writeOffListForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Products in write-off list"));
		dForm->FillTable<BusinessLayer::WriteOffListView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::WriteOffListView>();
			dForm->setObjectName("writeOffListForm");
			QMdiSubWindow *writeOffListWindow = new QMdiSubWindow;
			writeOffListWindow->setWidget(dForm);
			writeOffListWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(writeOffListWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All products in write-off list are shown");
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
		QString message = tr("All products in write-off list are shown");
		statusBar()->showMessage(message);
	}

}


void MainForm::OpenProductionForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("productionForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Production"));
		dForm->FillTable<BusinessLayer::Production>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::Production>();
			dForm->setObjectName("productionForm");
			QMdiSubWindow *productionWindow = new QMdiSubWindow;
			productionWindow->setWidget(dForm);
			productionWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(productionWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All production are shown");
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
		QString message = tr("All production are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenProductionListForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("productionListForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Products in production list"));
		dForm->FillTable<BusinessLayer::ProductionListView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::ProductionListView>();
			dForm->setObjectName("productionListForm");
			QMdiSubWindow *productionListWindow = new QMdiSubWindow;
			productionListWindow->setWidget(dForm);
			productionListWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(productionListWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All products in production list are shown");
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
		QString message = tr("All products in production list are shown");
		statusBar()->showMessage(message);
	}

}


void MainForm::OpenBalanceForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("balanceForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Balances"));
		dForm->FillTable<BusinessLayer::BalanceView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("balanceForm");
			dForm->QtConnect<BusinessLayer::BalanceView>();
			QMdiSubWindow *balanceWindow = new QMdiSubWindow;
			balanceWindow->setWidget(dForm);
			balanceWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(balanceWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All balances are shown");
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
		QString message = tr("All balances are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenPaymentForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("paymentForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Payments"));
		dForm->FillTable<BusinessLayer::PaymentView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("paymentForm");
			dForm->QtConnect<BusinessLayer::PaymentView>();
			QMdiSubWindow *paymentWindow = new QMdiSubWindow;
			paymentWindow->setWidget(dForm);
			paymentWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(paymentWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All payments are shown");
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
		QString message = tr("All payments are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenRefundForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("refundForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Refunds"));
		dForm->FillTable<BusinessLayer::RefundView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("refundForm");
			dForm->QtConnect<BusinessLayer::RefundView>();
			QMdiSubWindow *refundWindow = new QMdiSubWindow;
			refundWindow->setWidget(dForm);
			refundWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(refundWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All refunds are shown");
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
		QString message = tr("All payments are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenPriceForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("priceForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Price"));
		dForm->FillTable<BusinessLayer::PriceView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("priceForm");
			dForm->QtConnect<BusinessLayer::PriceView>();
			QMdiSubWindow *priceWindow = new QMdiSubWindow;
			priceWindow->setWidget(dForm);
			priceWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(priceWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All prices are shown");
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
		QString message = tr("All prices are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenSalaryForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("salaryForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Salary"));
		dForm->FillTable<BusinessLayer::SalaryView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("salaryForm");
			dForm->QtConnect<BusinessLayer::SalaryView>();
			QMdiSubWindow *salaryWindow = new QMdiSubWindow;
			salaryWindow->setWidget(dForm);
			salaryWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(salaryWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All salary are shown");
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
		QString message = tr("All salary are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenSalaryTypeForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("salaryTypeForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Salary types"));
		dForm->FillTable<BusinessLayer::SalaryType>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("salaryTypeForm");
			dForm->QtConnect<BusinessLayer::SalaryType>();
			QMdiSubWindow *salaryTypeWindow = new QMdiSubWindow;
			salaryTypeWindow->setWidget(dForm);
			salaryTypeWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(salaryTypeWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All salary types are shown");
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
		QString message = tr("All salary types are shown");
		statusBar()->showMessage(message);
	}

}


void MainForm::OpenPayrollForm()
{
	ClcWagesDlg *wagesDlg = new ClcWagesDlg(oBL, this);
	wagesDlg->setAttribute(Qt::WA_DeleteOnClose);
	wagesDlg->setWindowTitle(tr("Calculate salary"));
	wagesDlg->show();
}

void MainForm::OpenWithdrawalForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("withdrawalForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Withdrawals"));
		dForm->FillTable<BusinessLayer::WithdrawalView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("withdrawalForm");
			dForm->QtConnect<BusinessLayer::WithdrawalView>();
			QMdiSubWindow *withdrawalWindow = new QMdiSubWindow;
			withdrawalWindow->setWidget(dForm);
			withdrawalWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(withdrawalWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All withdrawal are shown");
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
		QString message = tr("All withdrawals are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenPayslipForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("payslipForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Payslips"));
		dForm->FillTable<BusinessLayer::PayslipView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("payslipForm");
			dForm->QtConnect<BusinessLayer::PayslipView>();
			QMdiSubWindow *payslipWindow = new QMdiSubWindow;
			payslipWindow->setWidget(dForm);
			payslipWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(payslipWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All payslips are shown");
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
		QString message = tr("All withdrawals are shown");
		statusBar()->showMessage(message);
	}

}



void MainForm::OpenCompanyForm()
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

void MainForm::OpenCurrencyForm()
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

void MainForm::OpenMeasureForm()
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

void MainForm::OpenLocationForm()
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

void MainForm::OpenRoleForm()
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

void MainForm::OpenStatusForm()
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

void MainForm::OpenRelationForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("relationForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Relations"));
		dForm->FillTable<BusinessLayer::Relation>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("relationForm");
			dForm->QtConnect<BusinessLayer::Relation>();
			QMdiSubWindow *relationWindow = new QMdiSubWindow;
			relationWindow->setWidget(dForm);
			relationWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(relationWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All relations are shown");
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
		QString message = tr("All relations are shown");
		statusBar()->showMessage(message);
	}
}

void MainForm::OpenRelationTypeForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("relationTypeForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Relation types"));
		dForm->FillTable<BusinessLayer::RelationType>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("relationTypeForm");
			dForm->QtConnect<BusinessLayer::RelationType>();
			QMdiSubWindow *relationtypeWindow = new QMdiSubWindow;
			relationtypeWindow->setWidget(dForm);
			relationtypeWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(relationtypeWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All relation types are shown");
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
		QString message = tr("All relation types are shown");
		statusBar()->showMessage(message);
	}
}

void MainForm::OpenAboutForm(){}