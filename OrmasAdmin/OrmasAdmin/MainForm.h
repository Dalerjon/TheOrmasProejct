#ifndef MAINFORM_H
#define MAINFORM_H

#include "ui_MainForm.h"
#include "OrmasBL.h"
#include "DataForm.h"

class MainForm : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT

public:
	MainForm(BusinessLayer::OrmasBL *ormasBL, BusinessLayer::User* user);
	BusinessLayer::OrmasBL *oBL;
	QMdiSubWindow* GetWindowByName(QString);
	std::string errorMessage = "";
private slots :
	void ShowUsers();
	void CreateUser();
	void CheckRights();
	void DeleteUser();

	void ShowProductsType();
	void ShowProducts();
	void ShowProduction();
	void ShowProductsList();

	void ShowOrders();	
	void CreateOrder();
	void DeleteOrder();

	void ShowReturns();
	void CreateReturn();
	void DeleteReturn();

	void ShowCompanies();
	void ShowCurrencies();
	void ShowMeasures();
	void ShowLocations();
	void ShowRoles();
	void ShowStatus();
	void About();
private:
	void CreateConnections();
	BusinessLayer::User *loggedUser = new BusinessLayer::User();
	void CheckAccess(std::string&);
};
#endif //MAINFORM_h