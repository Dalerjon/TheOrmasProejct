#ifndef CREATEOTHSTYPEDLG_H
#define CREATEOTHSTYPEDLG_H
#include "ui_CreateOthSTypeDlg.h"
#include "OrmasBL.h"
#include <QStandardItemModel>

class CreateOthSTypeDlg :public QDialog, public Ui::CreateOthSType
{
	Q_OBJECT
public:
	CreateOthSTypeDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateOthSTypeDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateOtherStocksType();
	void EditOtherStocksType();
	void DeleteOtherStocksType(){};
	void Close();
private:
	BusinessLayer::OtherStocksType *othSType = new BusinessLayer::OtherStocksType();
	void SetOthSTypeParams(QString, QString, QString, int = 0);
	void FillEditElements(QString, QString, QString);
	QWidget* parentForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};
#endif //CREATEOthSTypeDLG_H