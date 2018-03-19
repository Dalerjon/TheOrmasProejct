#ifndef CREATESPLLISTDLG_H
#define CREATESPLLISTDLG_H
#include "ui_CreateSplListDlg.h"
#include "OrmasBL.h"

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
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::SpoilageList *spoilageList = new BusinessLayer::SpoilageList();
	void SetSpoilageListParams(int, int, int, double, int, int, int = 0);
	void FillEditElements(int, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};
#endif //CREATESPLLITDLG_H