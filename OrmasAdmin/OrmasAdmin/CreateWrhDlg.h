#ifndef CREATEWrhDLG_H
#define CREATEWrhDLG_H
#include "ui_CreateWrhDlg.h"
#include "OrmasBL.h"

class CreateWrhDlg : public QDialog, public Ui::CreateWarehouse
{
	Q_OBJECT
public:
	CreateWrhDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateWrhDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateWarehouse();
	void EditWarehouse();
	void DeleteWarehouse(){};
	void Close();
private:
	BusinessLayer::Warehouse *warehouse = new BusinessLayer::Warehouse();
	BusinessLayer::Subaccount *subaccount = new BusinessLayer::Subaccount();
	void SetWarehouseParams(QString, QString, QString,int, int, int = 0);
	void FillEditElements(QString, QString, QString, int, int);
	void InitComboBox();
	void InitComboBox(int);
	void GenerateSubaccount();
	QWidget* parentForm;
};

#endif //CREATEWrhDLG_H