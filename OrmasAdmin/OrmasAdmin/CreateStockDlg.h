#ifndef CREATESTOCKDLG_H
#define CREATESTOCKDLG_H
#include "ui_CreateStockDlg.h"
#include "OrmasBL.h"

class CreateStockDlg : public QDialog, public Ui::CreateStock
{
	Q_OBJECT
public:
	CreateStockDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateStockDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void AddProduct();
	void EditProduct();
	void DeleteProduct(){};
	void Close();
	void OpenProdDlg();
	void OpenStsDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Stock *stock = new BusinessLayer::Stock();
	void SetStockParams(int, int, double, int, int, int = 0);
	void FillEditElements(int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};
#endif //CREATESTOCKDLG_H