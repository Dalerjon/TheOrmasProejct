#ifndef CREATEPMTDLG_H
#define CREATEPMTDLG_H
#include "ui_CreatePmtDlg.h"
#include "OrmasBL.h"

class CreatePmtDlg : public QDialog, public Ui::CreatePayment
{
	Q_OBJECT
public:
	CreatePmtDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreatePmtDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreatePayment();
	void EditPayment();
	void DeletePayment(){};
	void Close();
	void OpenUserDlg();
	void OpenCurDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Payment *payment = new BusinessLayer::Payment();
	void SetPaymentParams(QString, double, int, int, int = 0);
	void FillEditElements(QString, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
};

#endif //CREATEPMTDLG_H