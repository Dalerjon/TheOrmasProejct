#ifndef MAINFORM_H
#define MAINFORM_H

#include "ui_MainForm.h"
#include "OrmasBL.h"

class MainForm : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT

public:
	MainForm(BusinessLayer::OrmasBL *ormasBL, BusinessLayer::User* user);
	~MainForm();
	BusinessLayer::OrmasBL *oBL;
	QMdiSubWindow* GetWindowByName(QString);
	BusinessLayer::User* GetLoggedUser();
	std::string errorMessage = "";
	std::vector<int> rights;
private slots :
	void OpenUserForm();
	void OpenClientForm();
	void OpenEmployeeForm();
	void OpenPurveyorForm();
	void OpenCompanyEmployeeForm();
	void OpenCashboxEmployeeForm();
	void OpenWarehouseEmployeeForm();
	void OpenAccessForm();
	void OpenAccessItemForm();
	void OpenUserPhotoForm(); 
	void OpenPositionForm();

	void OpenProductForm();
	void OpenProductTypeForm();
	void OpenProductPhotoForm();
	void OpenSpecificationForm();
	void OpenSpecificationListForm();
	void OpenPriceForm();
	void OpenNetCostForm();

	void OpenOrderForm();	
	void OpenOrderListForm();

	void OpenReturnForm();
	void OpenReturnListForm();

	void OpenProductionForm();
	void OpenProductionListForm();
	void OpenProductionStockForm();
	void OpenProductionConsumeRawForm();
	void OpenProductionPlanForm();
	void OpenProductionPlanListForm();
	void OpenJobpriceForm();
	void OpenJobsheetForm();
	void OpenPercentRateForm();
	void OpenTimesheetForm();
	void OpenSpoilageForm();
	void OpenSpoilageListForm();
	void ReworkRawForm();

	void OpenWriteOffForm();
	void OpenWriteOffListForm();

	void OpenBalanceForm();
	void OpenAccountForm();
	void OpenSubaccountForm();
	void GenerateAccountsForm();
	void GenerateOneAccountForm();	
	void OpenSalaryForm();
	void OpenSalaryTypeForm();
	void OpenPayrollForm();
	void OpenAccountTypeForm();
	void OpenChartOfAccountsForm();
	void OpenCompanyAccountForm();
	void OpenEntryForm();
	void OpenEntryRoutingForm();
	void OpenCloseOfMonthForm();
	void OpenCashboxForm();
	void OpenWarehouseForm();
	
	void OpenCashForm();
	void OpenPaymentForm();
	void OpenRefundForm();
	void OpenWithdrawalForm();
	void OpenPayslipForm();
	void OpenCashBookListForm();

	void OpenStockForm();
	void OpenStockRawForm();
	void OpenStockProductForm();
	void OpenOrderRawForm();
	void OpenReceiptRawForm();
	void OpenConsumeRawForm();
	void OpenWriteOffRawForm();
	void OpenTransportForm();
	void OpenReceiptProductForm();
	void OpenConsumeProductForm();
	void OpenInventorizationForm();

	void CompanyBalanceInfo();
	void FinancialReportForm();
	void CompanyBalanceForm();
	void SpecificationReportForm();
	void ProfitabilityReportForm();
	void SalesReportForm();
	void AccountCardForm();

	void OpenCompanyForm();
	void OpenCurrencyForm();
	void OpenMeasureForm();
	void OpenLocationForm();
	void OpenRoleForm();
	void OpenStatusForm();
	void OpenStatusRuleForm();
	void OpenRelationForm();
	void OpenRelationTypeForm();
	void OpenDivisionForm();
	void OpenWarehouseTypeForm();
	void OpenBranchForm();
	
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