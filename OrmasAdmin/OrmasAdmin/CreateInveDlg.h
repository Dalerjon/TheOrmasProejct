#ifndef CREATEINVEDLG_H
#define CREATEINVEDLG_H

#include "ui_CreateInveDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateInveDlg : public QDialog, public Ui::CreateInventory
{
	Q_OBJECT
public:
	CreateInveDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateInveDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateInventory();
	void EditInventory();
	void DeleteInventory(){};
	void Close();
	void OpenStsDlg();
	void OpenAccDlg();
	void OpenPurDlg();
	void OpenActDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::Inventory *inventory = new BusinessLayer::Inventory();
	BusinessLayer::InventoryUnion *inventoryUnion = new BusinessLayer::InventoryUnion();
	BusinessLayer::PostingFixedAssets *postingFixedAssets = new BusinessLayer::PostingFixedAssets();
	void SetInventoryParams(QString, double, QString, QString, int, QString, QString, QString, int, int, int = 0);
	void SetPostingFixedAssetsParams(int, int, int, int, int, int = 0);
	void SetInventoryUnionParams(BusinessLayer::Inventory*, BusinessLayer::PostingFixedAssets*);
	void FillEditElements(QString, double, QString, QString, int, QString, QString, QString, int, int, int);

	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	std::map<std::string, int> statusMap;
	void InitComboBox();
	void HideSpecButton();
	void GenerateInventoryNumber();
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};
#endif //CREATEInveDLG_H