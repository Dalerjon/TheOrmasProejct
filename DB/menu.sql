-----------------------------------MENU--------------------------------------------------------------

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
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionAccess', 'actionAccess', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProductType', 'actionProductType', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProducts', 'actionProducts', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionOrders', 'actionOrders', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProductsList', 'actionProductsList', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionOrderList', 'actionOrderList', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionDeleteOrder', 'actionDeleteOrder', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionReturns', 'actionReturns', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionReturnList', 'actionReturnList', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionDeleteReturn', 'actionDeleteReturn', 'MENUITEM');
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
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionAbout', 'actionAbout', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProduction', 'actionProduction', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionAccessItems', 'actionAccessItems', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionPrices', 'actionPrices', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProductionList', 'actionProductionList', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionWriteOffs', 'actionWriteOffs', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionWriteOffList', 'actionWriteOffList', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionUserPhoto', 'actionUserPhoto', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionProductPhoto', 'actionProductPhoto', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionPosition', 'actionPosition', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionRelation', 'actionRelation', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionRelationType', 'actionRelationType', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionBalances', 'actionBalances', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionSalary', 'actionSalary', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionSalaryType', 'actionSalaryType', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionPayments', 'actionPayments', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionPayroll', 'actionPayroll', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionWithdrawal', 'actionWithdrawal', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionRefund', 'actionRefund', 'MENUITEM');
INSERT INTO "OrmasSchema".access_items(
            access_item_id, access_item_eng, access_item_ru, access_division)
    VALUES ((SELECT nextval('"OrmasSchema".id_seq')), 'actionPayslip', 'actionPayslip', 'MENUITEM');
