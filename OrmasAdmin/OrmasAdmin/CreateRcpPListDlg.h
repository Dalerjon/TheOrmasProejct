#ifndef CREATERCPPLISTDLG_H
#define CREATERCPPLISTDLG_H
#include "ui_CreateRcpPListDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateRcpPListDlg : public QDialog, public Ui::CreateRcpPList
{
	Q_OBJECT
public:
	CreateRcpPListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateRcpPListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int receiptProductID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenRcpPDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void DataIsChanged();
private:
	BusinessLayer::ReceiptProductList *receiptProductList = new BusinessLayer::ReceiptProductList();
	void SetRcpPListParams(int, int, double, double, int, int, int = 0);
	void FillEditElements(int, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CREATEORDLITDLG_H