#ifndef CREATEConOthStDLG_H
#define CREATEConOthStDLG_H

#include "ui_CreateConOthStDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateConOthStDlg : public QDialog, public Ui::CreateConsumeOthSt
{
	Q_OBJECT
public:
	CreateConOthStDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateConOthStDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateConsumeOtherStocks();
	void EditConsumeOtherStocks();
	void DeleteConsumeOtherStocks(){};
	void Close();
	void OpenEmpDlg();
	void OpenSkEmpDlg();
	void OpenStsDlg();
	void OpenConOthStListDlg();
	void StatusWasChenged();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::ConsumeOtherStocks *consumeOtherStocks = new BusinessLayer::ConsumeOtherStocks();
	void SetConsumeOtherStocksParams(int, QString, QString, int, double, double, int, int, int = 0);
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
#endif //CREATEConOthStDLG_H