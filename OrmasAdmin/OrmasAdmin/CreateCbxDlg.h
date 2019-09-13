#ifndef CREATECbxDLG_H
#define CREATECbxDLG_H
#include "ui_CreateCbxDlg.h"
#include "OrmasBL.h"
#include <QStandardItemModel>

class CreateCbxDlg : public QDialog, public Ui::CreateCashbox
{
	Q_OBJECT
public:
	CreateCbxDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateCbxDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateCashbox();
	void EditCashbox();
	void DeleteCashbox(){};
	void Close();
private:
	BusinessLayer::Cashbox *cashbox = new BusinessLayer::Cashbox();
	BusinessLayer::Subaccount *subaccount = new BusinessLayer::Subaccount();
	void SetCashboxParams(int, QString, QString, int = 0);
	void FillEditElements(int, QString, QString);
	void InitComboBox();
	void InitComboBox(int);
	void GenerateSubaccount();
	QWidget* parentForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATECbxDLG_H