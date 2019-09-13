#ifndef CREATEStockTrDLG_H
#define CREATEStockTrDLG_H

#include "ui_CreateStockTrDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>


class CreateStockTrDlg : public QDialog, public Ui::CreateStockTransfer
{
	Q_OBJECT
public:
	CreateStockTrDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateStockTrDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateStockTransfer();
	void EditStockTransfer();
	void DeleteStockTransfer(){};
	void Close();
	void OpenEmpDlg();
	void OpenSkEmpDlg();
	void OpenStsDlg();
	void OpenStockTrListDlg();
	void StatusWasChenged();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::StockTransfer *stockTransfer = new BusinessLayer::StockTransfer();
	void SetStockTransferParams(int, QString, QString, int, double, double, int, int, int = 0);
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
#endif //CREATEStockTrDLG_H