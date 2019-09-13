#ifndef CREATEWERDLG_H
#define CREATEWERDLG_H
#include "ui_CreateWERDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateWERDlg : public QDialog, public Ui::CreateWarehouseEmployee
{
	Q_OBJECT
public:
	CreateWERDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateWERDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateWarehouseEmployee();
	void EditWarehouseEmployee();
	void DeleteWarehouseEmployee(){};
	void Close();
	void OpenEmpDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::WarehouseEmployeeRelation *warehouseEmployee = new BusinessLayer::WarehouseEmployeeRelation();
	void SetWarehouseEmployeeParams(int, int, int = 0);
	void FillEditElements(int, int);
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATEWERDLG_H