#ifndef CREATERCPOTHSTLISTDLG_H
#define CREATERCPOTHSTLISTDLG_H
#include "ui_CreateRcpOthStListDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateRcpOthStListDlg : public QDialog, public Ui::CreateRcpOthStList
{
	Q_OBJECT
public:
	CreateRcpOthStListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateRcpOthStListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int receiptOtherStocksID = 0;
	int employeeID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenRcpOthStDlg();
	void OpenOthStDlg();
	void OpenStsDlg();
	void TextEditChanged();
	void InspectPrice();
	void SetProductData(int);
	public slots:
	void SetID(int ID, QString childName);
signals:
	void DataIsChanged();
private:
	BusinessLayer::ReceiptOtherStocksList *receiptOtherStocksList = new BusinessLayer::ReceiptOtherStocksList();
	void SetRcpOthStListParams(int, int, double, double, int, int, int = 0);
	void FillEditElements(int, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	bool BlockWrongPrice(QString, QString);
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CREATERCPOTHSTLISTDLG_H