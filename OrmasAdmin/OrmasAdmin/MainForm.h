#ifndef MAINFORM_H
#define MAINFORM_H

#include "ui_MainForm.h"
#include "OrmasBL.h"
#include "DataForm.h"
#include "ClcWagesDlg.h"
#include "GenerateAccDlg.h"
#include "GenerateOneAccDlg.h"

class MainForm : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT

public:
	MainForm(BusinessLayer::OrmasBL *ormasBL, BusinessLayer::User* user);
	~MainForm();
	BusinessLayer::OrmasBL *oBL;
	QMdiSubWindow* GetWindowByName(QString);
	std::string errorMessage = "";
	std::vector<int> rights;
private slots :
	void OpenUserForm();
	void OpenClientForm();
	void OpenEmployeeForm();
	void OpenPurveyorForm();
	void OpenAccessForm();
	void OpenAccessItemForm();
	void OpenUserPhotoForm(); 
	void OpenPositionForm();

	void OpenProductForm();
	void OpenProductTypeForm();
	void OpenProductPhotoForm();
	void OpenSpecificationForm();
	void OpenSpecificationListForm();

	void OpenOrderForm();	
	void OpenOrderListForm();

	void OpenReturnForm();
	void OpenReturnListForm();

	void OpenProductionForm();
	void OpenProductionListForm();
	void OpenJobpriceForm();
	void OpenJobsheetForm();
	void OpenPercentRateForm();
	void OpenTimesheetForm();
	void OpenProductionPlanForm();
	void OpenProductionPlanListForm();
	void OpenSpoilageForm();
	void OpenSpoilageListForm();

	void OpenWriteOffForm();
	void OpenWriteOffListForm();

	void OpenBalanceForm();
	void OpenPaymentForm();
	void OpenRefundForm();
	void OpenPriceForm();
	void OpenNetCostForm();
	void OpenSalaryForm();
	void OpenSalaryTypeForm();
	void OpenPayrollForm();
	void OpenWithdrawalForm();
	void OpenPayslipForm();
	void OpenAccountForm();
	void OpenAccountTypeForm();
	void OpenChartOfAccountsForm();
	void OpenCompanyAccountForm();
	void OpenEntryForm();
	void GenerateAccountsForm();
	void GenerateOneAccountForm();

	void OpenStockForm();
	void OpenOrderRawForm();
	void OpenReceiptRawForm();
	void OpenConsumeRawForm();
	void OpenWriteOffRawForm();
	void OpenTransportForm();
	void OpenReceiptProductForm();
	void OpenConsumeProductForm();
	void OpenInventorizationForm();

	void OpenCompanyForm();
	void OpenCurrencyForm();
	void OpenMeasureForm();
	void OpenLocationForm();
	void OpenRoleForm();
	void OpenStatusForm();
	void OpenRelationForm();
	void OpenRelationTypeForm();
	
	void OpenAboutForm();

	void CloseChildsByName();
private:
	void CreateConnections();
	BusinessLayer::User *loggedUser = nullptr;
	BusinessLayer::Access *userAccess = nullptr;
	void SetMenuItemsByAccess(std::vector<int> rights);
	void SetAllMenuInvisible();
	void SetAllMenuVisible();
};
#endif //MAINFORM_h