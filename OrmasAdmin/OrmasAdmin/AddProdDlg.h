#ifndef ADDPRODDLG_H
#define ADDPRODDLG_H

#include "ui_AddProdDlg.h"
#include "OrmasBL.h"

class AddProdDlg : public QDialog, public Ui::AddProdDlg
{
	Q_OBJECT
public:
	AddProdDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~AddProdDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int orderID = 0;
	int returnID = 0;
	int productionID = 0;
private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenOrdDlg();
	void OpenRtrnDlg();
	void OpenProdnDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	void OpenCurDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::ProductList *productList = new BusinessLayer::ProductList();
	void SetProductParams(int, int, int, int, int, double, int, int, int = 0);
	void FillEditElements(int, int, int, int, int, double, int, int);
};
#endif //ADDPRODDLG_H