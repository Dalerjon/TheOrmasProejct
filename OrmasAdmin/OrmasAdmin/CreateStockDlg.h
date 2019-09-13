#ifndef CREATESTOCKDLG_H
#define CREATESTOCKDLG_H
#include "ui_CreateStockDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

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
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::Stock *stock = new BusinessLayer::Stock();
	void SetStockParams(int, double, double, int, int, int, int = 0);
	void FillEditElements(int, double, double, int, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};
#endif //CREATESTOCKDLG_H