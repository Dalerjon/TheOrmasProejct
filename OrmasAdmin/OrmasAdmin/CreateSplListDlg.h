#ifndef CREATESPLLISTDLG_H
#define CREATESPLLISTDLG_H
#include "ui_CreateSplListDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include <QStandardItemModel>

class CreateSplListDlg : public QDialog, public Ui::CreateSplList
{
	Q_OBJECT
public:
	CreateSplListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateSplListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int spoilageID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenSplDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void DataIsChanged();
private:
	BusinessLayer::SpoilageList *spoilageList = new BusinessLayer::SpoilageList();
	void SetSpoilageListParams(int, int, double, double, int, int, int = 0);
	void FillEditElements(int, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
	QStandardItemModel *itemModel;
	QModelIndex mIndex;
};
#endif //CREATESPLLITDLG_H