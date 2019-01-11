#ifndef CREATECASHERDLG_H
#define CREATECASHERDLG_H
#include "ui_CreateCASHERDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateCASHERDlg : public QDialog, public Ui::CreateCashboxEmployee
{
	Q_OBJECT
public:
	CreateCASHERDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateCASHERDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateCashboxEmployee();
	void EditCashboxEmployee();
	void DeleteCashboxEmployee(){};
	void Close();
	void OpenEmpDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::CashboxEmployeeRelation *cashboxEmployee = new BusinessLayer::CashboxEmployeeRelation();
	void SetCashboxEmployeeParams(int, int, int = 0);
	void FillEditElements(int, int);
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
};

#endif //CREATECASHERDLG_H