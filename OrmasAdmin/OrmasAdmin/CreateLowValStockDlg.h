#ifndef CREATELOWVALSTOCKDLG_H
#define CREATELOWVALSTOCKDLG_H
#include "ui_CreateLowValStockDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateLowValStockDlg : public QDialog, public Ui::CreateLowValueStock
{
	Q_OBJECT
public:
	CreateLowValStockDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateLowValStockDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void AddOtherStocks();
	void EditOtherStocks();
	void DeleteOtherStocks(){};
	void Close();
	void OpenOthStDlg();
	void TextEditChanged();
	void OpenStsDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::LowValueStock *lowVLStock = new BusinessLayer::LowValueStock();
	void SetLowValueStockParams(int, double, double, int, int, int, int = 0);
	void FillEditElements(int, double, double, int, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};
#endif //CREATELOWVALSTOCKDLG_H