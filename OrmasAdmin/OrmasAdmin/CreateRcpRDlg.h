#ifndef CREATERCPRDLG_H
#define CREATERCPRDLG_H

#include "ui_CreateRcpRDlg.h"
#include "OrmasBL.h"

class CreateRcpRDlg : public QDialog, public Ui::CreateReceiptRaw
{
	Q_OBJECT
public:
	CreateRcpRDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateRcpRDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateReceiptRaw();
	void EditReceiptRaw();
	void DeleteReceiptRaw(){};
	void Close();
	void OpenEmpDlg();
	void OpenSkEmpDlg();
	void OpenStsDlg();
	void OpenCurDlg();
	void OpenRcpRListDlg();
	void StatusWasChenged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::ReceiptRaw *receiptRaw = new BusinessLayer::ReceiptRaw();
	void SetReceiptRawParams(int, QString, QString, int, int, double, int, int, int = 0);
	void FillEditElements(int, QString, QString, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	std::map<std::string, int> statusMap;
};
#endif //CREATERCPRDLG_H