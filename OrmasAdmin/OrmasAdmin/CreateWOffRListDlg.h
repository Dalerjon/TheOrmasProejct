#ifndef CREATEWOFFRLISTDLG_H
#define CREATEWOFFRLISTDLG_H
#include "ui_CreateWOffRListDlg.h"
#include "OrmasBL.h"

class CreateWOffRListDlg : public QDialog, public Ui::CreateWOffRList
{
	Q_OBJECT
public:
	CreateWOffRListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateWOffRListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int writeOffRawID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenWOffRDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	void OpenCurDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::WriteOffRawList *writeOffRawList = new BusinessLayer::WriteOffRawList();
	void SetWOffRListParams(int, int, int, double, int, int, int = 0);
	void FillEditElements(int, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
};
#endif //CREATEWOFFRLISTDLG_H