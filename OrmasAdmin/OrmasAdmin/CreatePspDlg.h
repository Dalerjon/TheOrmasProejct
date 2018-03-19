#ifndef CREATEPSPDLG_H
#define CREATEPSPDLG_H
#include "ui_CreatePspDlg.h"
#include "OrmasBL.h"

class CreatePspDlg : public QDialog, public Ui::CreatePayslip
{
	Q_OBJECT
public:
	CreatePspDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreatePspDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreatePayslip();
	void EditPayslip();
	void DeletePayslip(){};
	void Close();
	void OpenSlrDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Payslip *payslip = new BusinessLayer::Payslip();
	void SetPayslipParams(QString, double, int, int, int = 0);
	void FillEditElements(QString, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};

#endif //CREATEPspDLG_H