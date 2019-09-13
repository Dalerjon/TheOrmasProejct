#ifndef CREATEEMPDLG_H
#define CREATEEMPDLG_H

#include "ui_CreateEmpDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateEmpDlg : public QDialog, public Ui::CreateEmployee
{
	Q_OBJECT
public:
	CreateEmpDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateEmpDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateEmployee();
	void EditEmployee();
	void DeleteEmployee(){};
	void Close();
	void OpenRoleDlg();
	void OpenPsnDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Employee *employee = new BusinessLayer::Employee();
	BusinessLayer::DivisionEmployeeRelation *divisionEmployee = new BusinessLayer::DivisionEmployeeRelation();
	void SetEmployeeParams(QString, QString, QString, QString, QString, int, QString, QString, int, QString, QString, int = 0);
	void SetDivisionEmployeeParams(int, int, QString, int = 0);
	void FillEditElements(QString, QString, QString, QString, QString, int, QString, QString, int, QString, QString);
	void FillEditElements(int, QString);
	QIntValidator *vInt = nullptr;
	QWidget* parentForm;
	MainForm* mainForm;
	void InitComboBox();
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATEEMPDLG_H