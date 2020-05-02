#ifndef CREATEConOthStLISTDLG_H
#define CREATEConOthStLISTDLG_H
#include "ui_CreateConOthStListDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreateConOthStListDlg : public QDialog, public Ui::CreateConOthStList
{
	Q_OBJECT
public:
	CreateConOthStListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateConOthStListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int consumeOtherStocksID = 0;
	int employeeID = 0;
	private slots:
	void AddOtherStocksToList();
	void EditOtherStocksInList();
	void DeleteOtherStocks(){};
	void Close();
	void OpenConOthStDlg();
	void OpenOthStDlg();
	void OpenStsDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void DataIsChanged();
private:
	BusinessLayer::ConsumeOtherStocksList *consumeOtherStocksList = new BusinessLayer::ConsumeOtherStocksList();
	void SetConOthStListParams(int, int, double, double, int, int, int = 0);
	void FillEditElements(int, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};
#endif //CREATEORDLITDLG_H