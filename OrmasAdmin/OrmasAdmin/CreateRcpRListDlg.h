#ifndef CREATERCPRLISTDLG_H
#define CREATERCPRLISTDLG_H
#include "ui_CreateRcpRListDlg.h"
#include "OrmasBL.h"

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
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenRcpRDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::ReceiptRawList *receiptRawList = new BusinessLayer::ReceiptRawList();
	void SetRcpRListParams(int, int, int, double, int, int, int = 0);
	void FillEditElements(int, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};
#endif //CREATERCPRLISTDLG_H