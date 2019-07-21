#ifndef CREATERCPPDLG_H
#define CREATERCPPDLG_H

#include "ui_CreateRcpPDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateRcpPDlg : public QDialog, public Ui::CreateReceiptProduct
{
	Q_OBJECT
public:
	CreateRcpPDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateRcpPDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateReceiptProduct();
	void EditReceiptProduct();
	void DeleteReceiptProduct(){};
	void Close();
	void OpenEmpDlg();
	void OpenSkEmpDlg();
	void OpenStsDlg();
	void OpenRcpPListDlg();
	void StatusWasChenged();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::ReceiptProduct *receiptProduct = new BusinessLayer::ReceiptProduct();
	void SetReceiptProductParams(int, QString, QString, int, double, double, int, int, int = 0);
	void FillEditElements(int, QString, QString, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	std::map<std::string, int> statusMap;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	bool CheckAccess();
};
#endif //CREATERCPPDLG_H