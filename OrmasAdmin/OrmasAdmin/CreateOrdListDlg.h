#ifndef CREATEORDLISTDLG_H
#define CREATEORDLISTDLG_H
#include "ui_CreateOrdListDlg.h"
#include "OrmasBL.h"

class CreateOrdListDlg : public QDialog, public Ui::CreateOrdList
{
	Q_OBJECT
public:
	CreateOrdListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateOrdListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int orderID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenOrdDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	void OpenCurDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::OrderList *orderList = new BusinessLayer::OrderList();
	void SetOrderListParams(int, int, int, double, int, int, int = 0);
	void FillEditElements(int, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
};
#endif //CREATEORDLITDLG_H