#ifndef CREATESLRDLG_H
#define CREATESLRDLG_H
#include "ui_CreateSlrDlg.h"
#include "OrmasBL.h"

class CreateSlrDlg : public QDialog, public Ui::CreateSalary
{
	Q_OBJECT
public:
	CreateSlrDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateSlrDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateSalary();
	void EditSalary();
	void DeleteSalary(){};
	void Close();
	void OpenUserDlg();
	void OpenCurDlg();
	void OpenSlrTypeDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Salary *salary = new BusinessLayer::Salary();
	void SetSalaryParams(int, double, int, int, QString, QString, int = 0);
	void FillEditElements(int, double, int, int, QString, QString);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
};

#endif //CREATESLRDLG_H