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
	actionPurveyors->setVisible(false);
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
	actionProductionList->setVisible(false);
	actionProductionPlan->setVisible(false);
	actionProductionPlanList->setVisible(false);
	actionSpoilage->setVisible(false);
	actionSpoilageList->setVisible(false);
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
	actionPrices->setVisible(false);
	actionNetCost->setVisible(false);
	actionRefund->setVisible(false);
	actionWithdrawal->setVisible(false);
	actionAccounts->setVisible(false);
	actionAccountType->setVisible(false);
	actionChartOfAccounts->setVisible(false);
	actionCompanyAccounts->setVisible(false);
	actionEntry->setVisible(false);
	actionGenerateOneAccount->setVisible(false);
	actionGenerateAccounts->setVisible(false);
	actionOrderRaws->setVisible(false);
	actionReceiptRaws->setVisible(false);
	actionTransports->setVisible(false);
	actionReceiptProducts->setVisible(false);
	actionConsumptionRaws->setVisible(false);
	actionWriteOffRaws->setVisible(false);
	actionConsumptionProducts->setVisible(false);
	actionStock->setVisible(false);
	actionInventorization->setVisible(false);
	actionSpecifications->setVisible(false);
	actionSpecificationList->setVisible(false);
	actionJobprice->setVisible(false);
	actionJobsheet->setVisible(false);	
	actionPercentRate->setVisible(false);
	actionTimesheet->setVisible(false);
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
	actionPurveyors->setVisible(true);
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
	actionProductionList->setVisible(true);
	actionProductionPlan->setVisible(true);
	actionProductionPlanList->setVisible(true);
	actionSpoilage->setVisible(true);
	actionSpoilageList->setVisible(true);
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
	actionPayroll->setVisible(true);
	actionPayslip->setVisible(true);
	actionPrices->setVisible(true);
	actionNetCost->setVisible(true);
	actionRefund->setVisible(true);
	actionWithdrawal->setVisible(true);
	actionAccounts->setVisible(true);
	actionAccountType->setVisible(true);
	actionChartOfAccounts->setVisible(true);
	actionCompanyAccounts->setVisible(true);
	actionEntry->setVisible(true);
	actionGenerateAccounts->setVisible(true);
	actionGenerateOneAccount->setVisible(true);
	actionOrderRaws->setVisible(true);
	actionReceiptRaws->setVisible(true);
	actionTransports->setVisible(true);
	actionReceiptProducts->setVisible(true);
	actionConsumptionRaws->setVisible(true);
	actionWriteOffRaws->setVisible(true);
	actionConsumptionProducts->setVisible(true);
	actionStock->setVisible(true);
	actionInventorization->setVisible(true);
	actionSpecifications->setVisible(true);
	actionSpecificationList->setVisible(true);
	actionJobprice->setVisible(true);
	actionJobsheet->setVisible(true);
	actionPercentRate->setVisible(true);
	actionTimesheet->setVisible(true);
}

MainForm::~MainForm()
{
	delete loggedUser;
	delete userAccess;
}

void MainForm::CloseChildsByName()
{
	if (0 != this->findChild<QWidget*>("consumeProductListForm"))
		((DataForm*)this->findChild<QWidget*>("consumeProductListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("consumeRawListForm"))
		((DataForm*)this->findChild<QWidget*>("consumeRawListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("inventorizationListForm"))
		((DataForm*)this->findChild<QWidget*>("inventorizationListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("orderListForm"))
		((DataForm*)this->findChild<QWidget*>("orderListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("orderRawListForm"))
		((DataForm*)this->findChild<QWidget*>("orderRawListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("productionPlanListForm"))
		((DataForm*)this->findChild<QWidget*>("productionPlanListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("receiptProductListForm"))
		((DataForm*)this->findChild<QWidget*>("receiptProductListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("receiptRawListForm"))
		((DataForm*)this->findChild<QWidget*>("receiptRawListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("returnListForm"))
		((DataForm*)this->findChild<QWidget*>("returnListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("specificationListForm"))
		((DataForm*)this->findChild<QWidget*>("specificationListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("spoilageListForm"))
		((DataForm*)this->findChild<QWidget*>("spoilageListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("transportListForm"))
		((DataForm*)this->findChild<QWidget*>("transportListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("productionListForm"))
		((DataForm*)this->findChild<QWidget*>("productionListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("writeOffListForm"))
		((DataForm*)this->findChild<QWidget*>("writeOffListForm"))->CloseDataForm();
	if (0 != this->findChild<QWidget*>("writeOffRawListForm"))
		((DataForm*)this->findChild<QWidget*>("writeOffRawListForm"))->CloseDataForm();
}

void MainForm::CreateConnections()
{
	QObject::connect(actionAllUsers, &QAction::triggered, this, &MainForm::OpenUserForm);
	QObject::connect(actionClients, &QAction::triggered, this, &MainForm::OpenClientForm);
	QObject::connect(actionEmployees, &QAction::triggered, this, &MainForm::OpenEmployeeForm);
	QObject::connect(actionPurveyors, &QAction::triggered, this, &MainForm::OpenPurveyorForm);
	QObject::connect(actionAccess, &QAction::triggered, this, &MainForm::OpenAccessForm);
	QObject::connect(actionAccessItems, &QAction::triggered, this, &MainForm::OpenAccessItemForm);
	QObject::connect(actionUserPhoto, &QAction::triggered, this, &MainForm::OpenUserPhotoForm);
	QObject::connect(actionPosition, &QAction::triggered, this, &MainForm::OpenPositionForm);
	

	QObject::connect(actionProductType, &QAction::triggered, this, &MainForm::OpenProductTypeForm);
	QObject::connect(actionProducts, &QAction::triggered, this, &MainForm::OpenProductForm);
	QObject::connect(actionProductPhoto, &QAction::triggered, this, &MainForm::OpenProductPhotoForm);
	QObject::connect(actionSpecifications, &QAction::triggered, this, &MainForm::OpenSpecificationForm);
	QObject::connect(actionSpecificationList, &QAction::triggered, this, &MainForm::OpenSpecificationListForm);
	

	QObject::connect(actionOrders, &QAction::triggered, this, &MainForm::OpenOrderForm);
	QObject::connect(actionOrderList, &QAction::triggered, this, &MainForm::OpenOrderListForm);

	QObject::connect(actionReturns, &QAction::triggered, this, &MainForm::OpenReturnForm);
	QObject::connect(actionReturnList, &QAction::triggered, this, &MainForm::OpenReturnListForm);

	QObject::connect(actionProduction, &QAction::triggered, this, &MainForm::OpenProductionForm);
	QObject::connect(actionProductionList, &QAction::triggered, this, &MainForm::OpenProductionListForm);
	QObject::connect(actionJobprice, &QAction::triggered, this, &MainForm::OpenJobpriceForm);
	QObject::connect(actionJobsheet, &QAction::triggered, this, &MainForm::OpenJobsheetForm);
	QObject::connect(actionPercentRate, &QAction::triggered, this, &MainForm::OpenPercentRateForm);
	QObject::connect(actionTimesheet, &QAction::triggered, this, &MainForm::OpenTimesheetForm);
	QObject::connect(actionProductionPlan, &QAction::triggered, this, &MainForm::OpenProductionPlanForm);
	QObject::connect(actionProductionPlanList, &QAction::triggered, this, &MainForm::OpenProductionPlanListForm);
	QObject::connect(actionSpoilage, &QAction::triggered, this, &MainForm::OpenSpoilageForm);
	QObject::connect(actionSpoilageList, &QAction::triggered, this, &MainForm::OpenSpoilageListForm);

	QObject::connect(actionWriteOffs, &QAction::triggered, this, &MainForm::OpenWriteOffForm);
	QObject::connect(actionWriteOffList, &QAction::triggered, this, &MainForm::OpenWriteOffListForm);

	
	QObject::connect(actionBalances, &QAction::triggered, this, &MainForm::OpenBalanceForm);
	QObject::connect(actionPayments, &QAction::triggered, this, &MainForm::OpenPaymentForm);
	QObject::connect(actionRefund, &QAction::triggered, this, &MainForm::OpenRefundForm);
	QObject::connect(actionPrices, &QAction::triggered, this, &MainForm::OpenPriceForm);
	QObject::connect(actionNetCost, &QAction::triggered, this, &MainForm::OpenNetCostForm);
	QObject::connect(actionSalary, &QAction::triggered, this, &MainForm::OpenSalaryForm);
	QObject::connect(actionSalaryType, &QAction::triggered, this, &MainForm::OpenSalaryTypeForm);
	QObject::connect(actionPayroll, &QAction::triggered, this, &MainForm::OpenPayrollForm);
	QObject::connect(actionWithdrawal, &QAction::triggered, this, &MainForm::OpenWithdrawalForm);
	QObject::connect(actionPayslip, &QAction::triggered, this, &MainForm::OpenPayslipForm);
	QObject::connect(actionAccounts, &QAction::triggered, this, &MainForm::OpenAccountForm);
	QObject::connect(actionAccountType, &QAction::triggered, this, &MainForm::OpenAccountTypeForm);
	QObject::connect(actionChartOfAccounts, &QAction::triggered, this, &MainForm::OpenChartOfAccountsForm);
	QObject::connect(actionCompanyAccounts, &QAction::triggered, this, &MainForm::OpenCompanyAccountForm);
	QObject::connect(actionEntry, &QAction::triggered, this, &MainForm::OpenEntryForm);
	QObject::connect(actionGenerateAccounts, &QAction::triggered, this, &MainForm::GenerateAccountsForm);
	QObject::connect(actionGenerateOneAccount, &QAction::triggered, this, &MainForm::GenerateOneAccountForm);
	
	QObject::connect(actionStock, &QAction::triggered, this, &MainForm::OpenStockForm);
	QObject::connect(actionOrderRaws, &QAction::triggered, this, &MainForm::OpenOrderRawForm);
	QObject::connect(actionReceiptRaws, &QAction::triggered, this, &MainForm::OpenReceiptRawForm);
	QObject::connect(actionConsumptionRaws, &QAction::triggered, this, &MainForm::OpenConsumeRawForm);
	QObject::connect(actionWriteOffRaws, &QAction::triggered, this, &MainForm::OpenWriteOffRawForm);
	QObject::connect(actionTransports, &QAction::triggered, this, &MainForm::OpenTransportForm);
	QObject::connect(actionReceiptProducts, &QAction::triggered, this, &MainForm::OpenReceiptProductForm);
	QObject::connect(actionConsumptionProducts, &QAction::triggered, this, &MainForm::OpenConsumeProductForm);
	QObject::connect(actionInventorization, &QAction::triggered, this, &MainForm::OpenInventorizationForm);
	
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

void MainForm::OpenPurveyorForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("purveyorForm"));
	if (checkedWidget == nullptr)
	{
		errorMessage = "";
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Purveyors"));
		dForm->FillTable<BusinessLayer::PurveyorView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::PurveyorView>();
			dForm->setObjectName("purveyorForm");
			QMdiSubWindow *purveyorWindow = new QMdiSubWindow;
			purveyorWindow->setWidget(dForm);
			purveyorWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(purveyorWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All purveyors are shown");
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
		QString message = tr("All purveyors are shown");
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
		dForm->FillTable<BusinessLayer::AccessView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::AccessView>();
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
void MainForm::OpenSpecificationForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("specificationForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Specifications"));
		dForm->FillTable<BusinessLayer::SpecificationView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::SpecificationView>();
			dForm->setObjectName("specificationForm");
			QMdiSubWindow *specWindow = new QMdiSubWindow;
			specWindow->setWidget(dForm);
			specWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(specWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All specifications are shown");
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
		QString message = tr("All specifications are shown");
		statusBar()->showMessage(message);
	}

}
void MainForm::OpenSpecificationListForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("specificationListForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Spesicfication list"));
		dForm->FillTable<BusinessLayer::SpecificationListView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::SpecificationListView>();
			dForm->setObjectName("specificationListForm");
			QMdiSubWindow *specListWindow = new QMdiSubWindow;
			specListWindow->setWidget(dForm);
			specListWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(specListWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All products in the specification list are shown");
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
		QString message = tr("All products in the specification list are shown");
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

void MainForm::OpenJobpriceForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("jobpriceForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Jobprice"));
		dForm->FillTable<BusinessLayer::JobpriceView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::JobpriceView>();
			dForm->setObjectName("jobpriceForm");
			QMdiSubWindow *jobpriceWindow = new QMdiSubWindow;
			jobpriceWindow->setWidget(dForm);
			jobpriceWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(jobpriceWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All jobprices are shown");
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
		QString message = tr("All jobprices are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenJobsheetForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("jobsheetForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Jobsheet"));
		dForm->FillTable<BusinessLayer::JobsheetView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::JobsheetView>();
			dForm->setObjectName("jobsheetForm");
			QMdiSubWindow *jobsheetWindow = new QMdiSubWindow;
			jobsheetWindow->setWidget(dForm);
			jobsheetWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(jobsheetWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All jobsheets are shown");
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
		QString message = tr("All jobsheets are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenPercentRateForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("percentRateForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Percent rate"));
		dForm->FillTable<BusinessLayer::PercentRate>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::PercentRate>();
			dForm->setObjectName("percentRateForm");
			QMdiSubWindow *percentRateWindow = new QMdiSubWindow;
			percentRateWindow->setWidget(dForm);
			percentRateWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(percentRateWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All percent rates are shown");
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
		QString message = tr("All percent rates are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenTimesheetForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("timesheetForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Timesheet"));
		dForm->FillTable<BusinessLayer::TimesheetView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::TimesheetView>();
			dForm->setObjectName("timesheetForm");
			QMdiSubWindow *timesheetWindow = new QMdiSubWindow;
			timesheetWindow->setWidget(dForm);
			timesheetWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(timesheetWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All timesheets are shown");
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
		QString message = tr("All timesheets are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenProductionPlanForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("productionPlanForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Production plan"));
		dForm->FillTable<BusinessLayer::ProductionPlanView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::ProductionPlanView>();
			dForm->setObjectName("productionPlanForm");
			QMdiSubWindow *productionPlanWindow = new QMdiSubWindow;
			productionPlanWindow->setWidget(dForm);
			productionPlanWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(productionPlanWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All production plans are shown");
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
		QString message = tr("All production plan are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenProductionPlanListForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("productionPlanListForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Products in production plan list"));
		dForm->FillTable<BusinessLayer::ProductionPlanListView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::ProductionPlanListView>();
			dForm->setObjectName("productionPlanListForm");
			QMdiSubWindow *productionPlanListWindow = new QMdiSubWindow;
			productionPlanListWindow->setWidget(dForm);
			productionPlanListWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(productionPlanListWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All products in production plan list are shown");
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
		QString message = tr("All products in production plan list are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenSpoilageForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("spoilageForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Spoilage"));
		dForm->FillTable<BusinessLayer::SpoilageView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::SpoilageView>();
			dForm->setObjectName("spoilageForm");
			QMdiSubWindow *spoilageWindow = new QMdiSubWindow;
			spoilageWindow->setWidget(dForm);
			spoilageWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(spoilageWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All spoilage are shown");
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
		QString message = tr("All spoilage are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenSpoilageListForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("spoilageListForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Products in spoilage list"));
		dForm->FillTable<BusinessLayer::SpoilageListView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->QtConnect<BusinessLayer::SpoilageListView>();
			dForm->setObjectName("spoilageListForm");
			QMdiSubWindow *spoilageListWindow = new QMdiSubWindow;
			spoilageListWindow->setWidget(dForm);
			spoilageListWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(spoilageListWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All products in spoilage list are shown");
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
		QString message = tr("All products in spoilage list are shown");
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

void MainForm::OpenNetCostForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("netCostForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Net cost"));
		dForm->FillTable<BusinessLayer::NetCostView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("netCostForm");
			dForm->QtConnect<BusinessLayer::NetCostView>();
			QMdiSubWindow *netCostWindow = new QMdiSubWindow;
			netCostWindow->setWidget(dForm);
			netCostWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(netCostWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All net cost are shown");
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
		QString message = tr("All net cost are shown");
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

void MainForm::OpenAccountForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("accountForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Accounts"));
		dForm->FillTable<BusinessLayer::AccountView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("accountForm");
			dForm->QtConnect<BusinessLayer::AccountView>();
			QMdiSubWindow *accountWindow = new QMdiSubWindow;
			accountWindow->setWidget(dForm);
			accountWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(accountWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All accounts are shown");
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
		QString message = tr("All accounts are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenAccountTypeForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("accountTypeForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Account type"));
		dForm->FillTable<BusinessLayer::AccountType>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("accountTypeForm");
			dForm->QtConnect<BusinessLayer::AccountType>();
			QMdiSubWindow *accountTypeWindow = new QMdiSubWindow;
			accountTypeWindow->setWidget(dForm);
			accountTypeWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(accountTypeWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All account type are shown");
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
		QString message = tr("All account type are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenChartOfAccountsForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("chartOffAccountForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Chart of account"));
		dForm->FillTable<BusinessLayer::ChartOfAccountsView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("chartOffAccountForm");
			dForm->QtConnect<BusinessLayer::ChartOfAccountsView>();
			QMdiSubWindow *chartOfAccountWindow = new QMdiSubWindow;
			chartOfAccountWindow->setWidget(dForm);
			chartOfAccountWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(chartOfAccountWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("Chart of accounts are shown");
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
		QString message = tr("Chart of accounts are showns");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenCompanyAccountForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("companyAccountForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Company account relation"));
		dForm->FillTable<BusinessLayer::CompanyAccountRelation>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("companyAccountForm");
			dForm->QtConnect<BusinessLayer::CompanyAccountRelation>();
			QMdiSubWindow *companyAccountWindow = new QMdiSubWindow;
			companyAccountWindow->setWidget(dForm);
			companyAccountWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(companyAccountWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("Company account relations are shown");
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
		QString message = tr("Company account relations are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenEntryForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("entryForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Entries"));
		dForm->FillTable<BusinessLayer::EntryView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("entryForm");
			dForm->QtConnect<BusinessLayer::EntryView>();
			QMdiSubWindow *entryWindow = new QMdiSubWindow;
			entryWindow->setWidget(dForm);
			entryWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(entryWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All entries are shown");
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
		QString message = tr("All entries are shown");
		statusBar()->showMessage(message);
	}

}

void MainForm::GenerateAccountsForm()
{
	GenerateAcc *generateAccDlg = new GenerateAcc(oBL, this);
	generateAccDlg->setAttribute(Qt::WA_DeleteOnClose);
	generateAccDlg->setWindowTitle(tr("Generate accounts"));
	generateAccDlg->show();
}

void MainForm::GenerateOneAccountForm()s{
	GenerateOneAcc *generateOneAccDlg = new GenerateOneAcc(oBL, this);
	generateOneAccDlg->setAttribute(Qt::WA_DeleteOnClose);
	generateOneAccDlg->setWindowTitle(tr("Generate one account"));
	generateOneAccDlg->show();
}

void MainForm::OpenStockForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("stockForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Stock"));
		dForm->FillTable<BusinessLayer::StockView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("stockForm");
			dForm->QtConnect<BusinessLayer::StockView>();
			QMdiSubWindow *stockWindow = new QMdiSubWindow;
			stockWindow->setWidget(dForm);
			stockWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(stockWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All products are shown in the stock");
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
		QString message = tr("All products are shown in the stock");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenOrderRawForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("orderRawForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Order raw"));
		dForm->FillTable<BusinessLayer::OrderRawView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("orderRawForm");
			dForm->QtConnect<BusinessLayer::OrderRawView>();
			QMdiSubWindow *orderRawWindow = new QMdiSubWindow;
			orderRawWindow->setWidget(dForm);
			orderRawWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(orderRawWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All raws are shown in orders");
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
		QString message = tr("All raws are shown in orders");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenReceiptRawForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("receiptRawForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Receipt raw"));
		dForm->FillTable<BusinessLayer::ReceiptRawView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("receiptRawForm");
			dForm->QtConnect<BusinessLayer::ReceiptRawView>();
			QMdiSubWindow *receiptRawWindow = new QMdiSubWindow;
			receiptRawWindow->setWidget(dForm);
			receiptRawWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(receiptRawWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All raws are shown in receipt");
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
		QString message = tr("All raws are shown in receipt");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenConsumeRawForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("consumeRawForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Consume raw"));
		dForm->FillTable<BusinessLayer::ConsumeRawView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("consumeRawForm");
			dForm->QtConnect<BusinessLayer::ConsumeRawView>();
			QMdiSubWindow *consumeRawWindow = new QMdiSubWindow;
			consumeRawWindow->setWidget(dForm);
			consumeRawWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(consumeRawWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All raws are shown in consume");
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
		QString message = tr("All raws are shown in consume");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenWriteOffRawForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("writeOffRawForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Write-off raw"));
		dForm->FillTable<BusinessLayer::WriteOffRawView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("writeOffRawForm");
			dForm->QtConnect<BusinessLayer::WriteOffRawView>();
			QMdiSubWindow *writeOffRawWindow = new QMdiSubWindow;
			writeOffRawWindow->setWidget(dForm);
			writeOffRawWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(writeOffRawWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All raw are shown in write-off");
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
		QString message = tr("All raw are shown in write-off");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenTransportForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("transportForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Transports"));
		dForm->FillTable<BusinessLayer::TransportView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("transportForm");
			dForm->QtConnect<BusinessLayer::TransportView>();
			QMdiSubWindow *transportWindow = new QMdiSubWindow;
			transportWindow->setWidget(dForm);
			transportWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(transportWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All transports are shown");
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
		QString message = tr("All transports are shown");
		statusBar()->showMessage(message);
	}

}


void MainForm::OpenReceiptProductForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("receiptProductForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Receipt product"));
		dForm->FillTable<BusinessLayer::ReceiptProductView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("receiptProductForm");
			dForm->QtConnect<BusinessLayer::ReceiptProductView>();
			QMdiSubWindow *receiptProductWindow = new QMdiSubWindow;
			receiptProductWindow->setWidget(dForm);
			receiptProductWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(receiptProductWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All products are shown in receipt");
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
		QString message = tr("All products are shown in receipt");
		statusBar()->showMessage(message);
	}
}

void MainForm::OpenConsumeProductForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("consumeProductForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Consume product"));
		dForm->FillTable<BusinessLayer::ConsumeProductView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("consumeProductForm");
			dForm->QtConnect<BusinessLayer::ConsumeProductView>();
			QMdiSubWindow *consumeProductWindow = new QMdiSubWindow;
			consumeProductWindow->setWidget(dForm);
			consumeProductWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(consumeProductWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All products are shown in consume");
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
		QString message = tr("All products are shown in consume");
		statusBar()->showMessage(message);
	}

}

void MainForm::OpenInventorizationForm()
{
	QString message = tr("Loading...");
	statusBar()->showMessage(message);
	QWidget* checkedWidget = IsWindowExist(mdiArea->subWindowList(), QString("inventorizationForm"));
	if (checkedWidget == nullptr)
	{
		DataForm *dForm = new DataForm(oBL, this);
		dForm->setWindowTitle(tr("Inventorization"));
		dForm->FillTable<BusinessLayer::InventorizationView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("inventorizationForm");
			dForm->QtConnect<BusinessLayer::InventorizationView>();
			QMdiSubWindow *inventorizationWindow = new QMdiSubWindow;
			inventorizationWindow->setWidget(dForm);
			inventorizationWindow->setAttribute(Qt::WA_DeleteOnClose);
			mdiArea->addSubWindow(inventorizationWindow);
			dForm->show();
			dForm->topLevelWidget();
			dForm->activateWindow();
			QString message = tr("All inventorizations are shown");
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
		QString message = tr("All inventorizations are shown");
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
		dForm->FillTable<BusinessLayer::RelationView>(errorMessage);
		if (errorMessage.empty())
		{
			dForm->setObjectName("relationForm");
			dForm->QtConnect<BusinessLayer::RelationView>();
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