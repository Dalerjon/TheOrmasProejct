#ifndef CREATERCPRLISTDLG_H
#define CREATERCPRLISTDLG_H
#include "ui_CreateRcpRListDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateRcpRListDlg : public QDialog, public Ui::CreateRcpRList
{
	Q_OBJECT
public:
	CreateRcpRListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateRcpRListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int receiptRawID = 0;
	int stockEmployeeID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenRcpRDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void DataIsChanged();
private:
	BusinessLayer::ReceiptRawList *receiptRawList = new BusinessLayer::ReceiptRawList();
	void SetRcpRListParams(int, int, double, double, int, int, int = 0);
	void FillEditElements(int, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CREATERCPRLISTDLG_H