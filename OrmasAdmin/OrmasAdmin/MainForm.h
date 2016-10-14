#ifndef MAINFORM_H
#define MAINFORM_H

#include "ui_MainForm.h"
#include "OrmasBL.h"
#include "DataForm.h"

class MainForm : public QMainWindow, private Ui::MainWindow
{
	Q_OBJECT

public:
	MainForm(BusinessLayer::OrmasBL ormasBL);
	BusinessLayer::OrmasBL oBL;
	QWidget* isWindowExist(QList<QMdiSubWindow*> mList, QString formName);
private slots :
	void ShowUsers();
	void CreateUser();
	void CheckAccess();
	void DeleteUser();
	void ShowProductsType();
	void ShowProducts();
	void ShowOrders();
	void ShowProductsList();
	void CreateOrder();
	void DeleteOrder();
	void ShowReturns();
	void CreateReturn();
	void DeleteReturn();
	void ShowCompanies();
	void ShowCurrencies();
	void ShowMeasures();
	void ShowRegions();
	void ShowRoles();
	void ShowStatus();
	void About();
private:
	void CreateConnections();
};
#endif //MAINFORM_h