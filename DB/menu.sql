﻿-----------------------------------MENU--------------------------------------------------------------

INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'ALL', 'ALL', 'ALL');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'menuUsers', 'menuUsers', 'MENU');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'menuProducts', 'menuProducts', 'MENU');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'menuOrders', 'menuOrders', 'MENU');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'menuReturns', 'menuReturns', 'MENU');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'menuReferences', 'menuReferences', 'MENU');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'menuHelp', 'menuHelp', 'MENU');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'menuProductions', 'menuProductions', 'MENU');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'menuWriteOffs', 'menuWriteOffs', 'MENU');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'menuAccountings', 'menuAccountings', 'MENU');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'menuStock', 'menuStock', 'MENU');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'menuCash', 'menuCash', 'MENU');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'menuReports', 'menuReports', 'MENU');
	
------------------------------------MENUITEM------------------------------------------------------------

INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionAllUsers', 'actionAllUsers', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionClients', 'actionClients', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionEmployees', 'actionEmployees', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionPurveyors', 'actionPurveyors', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionCompanyEmployees', 'actionCompanyEmployees', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionAccess', 'actionAccess', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionAccessItem', 'actionAccessItem', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionUserPhoto', 'actionUserPhoto', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionPosition', 'actionPosition', 'MENUITEM');
-----------------------------------------------------------------------------------------------------------
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProducts', 'actionProducts', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProductType', 'actionProductType', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProductPhoto', 'actionProductPhoto', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionSpecifications', 'actionSpecifications', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionSpecificationList', 'actionSpecificationList', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionPrices', 'actionPrices', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionNetCost', 'actionNetCost', 'MENUITEM');
---------------------------------------------------------------------------------------------------------------
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionOrders', 'actionOrders', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionOrderList', 'actionOrderList', 'MENUITEM');
-------------------------------------------------------------------------------------------------------------------
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionReturns', 'actionReturns', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionReturnList', 'actionReturnList', 'MENUITEM');
-------------------------------------------------------------------------------------------------------------------
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionWriteOffs', 'actionWriteOffs', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionWriteOffList', 'actionWriteOffList', 'MENUITEM');
----------------------------------------------------------------------------------------------------------------	
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProduction', 'actionProduction', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProductsList', 'actionProductsList', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProductionStock', 'actionProductionStock	', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProductionConsumeRaws', 'actionProductionConsumeRaws	', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProductionPlan', 'actionProductionPlan', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProductionPlanList', 'actionProductionPlanList', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionJobprice', 'actionJobprice', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionJobsheet', 'actionJobsheet', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionPercentRate', 'actionPercentRate', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionTimesheet', 'actionTimesheet', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionSpoilage', 'actionSpoilage', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionSpoilageList', 'actionSpoilageList', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionReworkRaws', 'actionReworkRaws', 'MENUITEM');	
----------------------------------------------------------------------------------------------------------	
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionBalances', 'actionBalances', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionAccounts', 'actionAccounts', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionSubaccounts', 'actionSubaccounts', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionGenerateOneAccount', 'actionGenerateOneAccount', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionGenerateAccounts', 'actionGenerateAccounts', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionSalary', 'actionSalary', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionSalaryType', 'actionSalaryType', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionPayroll', 'actionPayroll', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionAccountType', 'actionAccountType', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionChartOfAccounts', 'actionChartOfAccounts', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionCompanyAccounts', 'actionCompanyAccounts', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionEntry', 'actionEntry', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionEntryRouting', 'actionEntryRouting', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionCloseOfMonth', 'actionCloseOfMonth', 'MENUITEM');
---------------------------------------------------------------------------------------------------
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionPayments', 'actionPayments', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionRefund', 'actionRefund', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionWithdrawal', 'actionWithdrawal', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionPayslip', 'actionPayslip', 'MENUITEM');
----------------------------------------------------------------------------------------------------
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionStock', 'actionStock', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionRawStock', 'actionRawStock', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProductStock', 'actionProductStock', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionOrderRaws', 'actionOrderRaws', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionReceiptRaws', 'actionReceiptRaws', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionConsumptionRaws', 'actionConsumptionRaws', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionWriteOffRaws', 'actionWriteOffRaws', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionTransports', 'actionTransports', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionReceiptProducts', 'actionReceiptProducts', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionConsumptionProducts', 'actionConsumptionProducts', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionInventorization', 'actionInventorization', 'MENUITEM');
-------------------------------------------------------------------------------------------------------------	
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionCompanyBalanceInfo', 'actionCompanyBalanceInfo', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionFinancialReport', 'actionFinancialReport', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionCompanyBalance', 'actionCompanyBalance', 'MENUITEM');
-------------------------------------------------------------------------------------------------------------	
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionCompany', 'actionCompany', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionCurrency', 'actionCurrency', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionMeasure', 'actionMeasure', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionLocation', 'actionLocation', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionRoles', 'actionRoles', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionStatus', 'actionStatus', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionStatusRule', 'actionStatusRule', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionRelation', 'actionRelation', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionRelationType', 'actionRelationType', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionDivision', 'actionDivision', 'MENUITEM');
-------------------------------------------------------------------------------------------------------------
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionAbout', 'actionAbout', 'MENUITEM');

