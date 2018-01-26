#ifndef CREATEORDRLISTDLG_H
#define CREATEORDRLISTDLG_H
#include "ui_CreateOrdRListDlg.h"
#include "OrmasBL.h"

class CreateOrdRListDlg : public QDialog, public Ui::CreateOrdRList
{
	Q_OBJECT
public:
	CreateOrdRListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateOrdRListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int orderRawID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenOrdRDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	void OpenCurDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::OrderRawList *orderRawList = new BusinessLayer::OrderRawList();
	void SetOrdRListParams(int, int, int, double, int, int, int = 0);
	void FillEditElements(int, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
};
#endif //CREATEORDRLISTDLG_H