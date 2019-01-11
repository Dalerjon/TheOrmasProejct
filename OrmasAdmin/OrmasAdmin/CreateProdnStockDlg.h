#ifndef CREATEPRODNSTOCKDLG_H
#define CREATEPRODNSTOCKDLG_H
#include "ui_CreateProdnStockDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateProdnStockDlg : public QDialog, public Ui::CreateProdnStock
{
	Q_OBJECT
public:
	CreateProdnStockDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateProdnStockDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void AddProduct();
	void EditProduct();
	void DeleteProduct(){};
	void Close();
	void OpenProdDlg();
	void TextEditChanged();
	void OpenStsDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::ProductionStock *prodnStock = new BusinessLayer::ProductionStock();
	void SetProdnStockParams(int, double, double, int, int, int, int = 0);
	void FillEditElements(int, double, double, int, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CREATEPRODNSTOCKDLG_H