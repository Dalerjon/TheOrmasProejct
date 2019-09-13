#ifndef CREATEWRHTYPEDLG_H
#define CREATEWRHTYPEDLG_H
#include "ui_CreateWrhTpDlg.h"
#include "OrmasBL.h"
#include <QStandardItemModel>

class CreateWrhTypeDlg : public QDialog, public Ui::CreateWarehouseType
{
	Q_OBJECT
public:
	CreateWrhTypeDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateWrhTypeDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateWarehouseType();
	void EditWarehouseType();
	void DeleteWarehouseType(){};
	void Close();
private:
	BusinessLayer::WarehouseType *warehouseType = new BusinessLayer::WarehouseType();
	void SetWarehouseTypeParams(QString, QString, QString, int = 0);
	void FillEditElements(QString, QString, QString);
	QWidget* parentForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};

#endif //CREATEWRHTYPEDLG_H