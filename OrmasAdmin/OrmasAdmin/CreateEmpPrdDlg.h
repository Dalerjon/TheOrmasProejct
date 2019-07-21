#ifndef CREATEEMPPRDDLG_H
#define CREATEEMPPRDDLG_H
#include "ui_CreateEmpPrdDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateEmpPrdDlg : public QDialog, public Ui::CreateEmployeeProduct
{
	Q_OBJECT
public:
	CreateEmpPrdDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateEmpPrdDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateEmployeeProduct();
	void EditEmployeeProduct();
	void DeleteEmployeeProduct(){};
	void Close();
	void OpenEmpDlg();
	void OpenProdDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::EmployeeProductRelation *employeeProduct = new BusinessLayer::EmployeeProductRelation();
	void SetEmployeeProductParams(int, int, int = 0);
	void FillEditElements(int, int);
	QIntValidator *vInt = nullptr;
	QWidget* parentForm;
	MainForm* mainForm;
};

#endif //CREATEEMPPRDDLG_H