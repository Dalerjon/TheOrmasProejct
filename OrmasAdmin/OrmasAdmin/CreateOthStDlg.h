#ifndef CREATEOTHSTDLG_H
#define CREATEOTHSTDLG_H
#include "ui_CreateOthStDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateOthStDlg : public QDialog, public Ui::CreateOtherStocks
{
	Q_OBJECT
public:
	CreateOthStDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateOthStDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateOtherStocks();
	void EditOtherStocks();
	void DeleteOtherStocks(){};
	void Close();
	void OpenCmpDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::OtherStocks *otherStocks = new BusinessLayer::OtherStocks();
	void SetOtherStocksParams(int, QString, double, int, double, int, int = 0);
	void FillEditElements(int, QString, double, int, double, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};
#endif //CREATEOTHSTDLG_H