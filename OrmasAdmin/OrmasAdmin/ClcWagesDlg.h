#ifndef CLCWAGESDLG_H
#define CLCWAGESDLG_H

#include "ui_ClcWagesDlg.h"
#include "OrmasBL.h"

class ClcWagesDlg : public QDialog, public Ui::CalculateWages
{
	Q_OBJECT
public:
	ClcWagesDlg(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~ClcWagesDlg();
	BusinessLayer::OrmasBL *dialogBL;
	std::string errorMessage ="";
	private slots:
	void Calculate();
	void Close();
	void ChangeState();
	void OpenEmpDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Access *access = new BusinessLayer::Access();
	double sum = 0;
};
#endif