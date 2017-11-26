#ifndef CREATERFDDLG_H
#define CREATERFDDLG_H
#include "ui_CreateRfdDlg.h"
#include "OrmasBL.h"

class CreateRfdDlg : public QDialog, public Ui::CreateRefund
{
	Q_OBJECT
public:
	CreateRfdDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateRfdDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateRefund();
	void EditRefund();
	void DeleteRefund(){};
	void Close();
	void OpenUserDlg();
	void OpenCurDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Refund *Refund = new BusinessLayer::Refund();
	void SetRefundParams(QString, double, int, int, int = 0);
	void FillEditElements(QString, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
};

#endif //CREATERfdDLG_H