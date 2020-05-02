#ifndef CREATERCPOTHSTDLG_H
#define CREATERCPOTHSTDLG_H

#include "ui_CreateRcpOthStDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateRcpOthStDlg : public QDialog, public Ui::CreateReceiptOthSt
{
	Q_OBJECT
public:
	CreateRcpOthStDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateRcpOthStDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateReceiptOtherStocks();
	void EditReceiptOtherStocks();
	void DeleteReceiptOtherStocks(){};
	void Close();
	void OpenEmpDlg();
	void OpenPurDlg();
	void OpenStsDlg();
	void OpenRcpOthStListDlg();
	void StatusWasChenged();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::ReceiptOtherStocks *receiptOtherStocks = new BusinessLayer::ReceiptOtherStocks();
	void SetReceiptOtherStocksParams(int, QString, QString, int, double, double, int, int, int = 0);
	void FillEditElements(int, QString, QString, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	std::map<std::string, int> statusMap;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	bool CheckAccess();
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};
#endif //CREATERCPOTHSTDLG_H