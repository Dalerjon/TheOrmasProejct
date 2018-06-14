#ifndef CREATECERDLG_H
#define CREATECERDLG_H
#include "ui_CreateCERDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateCERDlg : public QDialog, public Ui::CreateCompanyEmployee
{
	Q_OBJECT
public:
	CreateCERDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateCERDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateCompanyEmployee();
	void EditCompanyEmployee();
	void DeleteCompanyEmployee(){};
	void Close();
	void OpenEmpDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::CompanyEmployeeRelation *companyEmployee = new BusinessLayer::CompanyEmployeeRelation();
	void SetCompanyEmployeeParams(int, int, int = 0);
	void FillEditElements(int, int);
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
};

#endif //CREATECERDLG_H