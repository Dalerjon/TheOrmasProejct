#ifndef CREATEINVLISTDLG_H
#define CREATEINVLISTDLG_H
#include "ui_CreateInvListDlg.h"
#include "OrmasBL.h"

class CreateInvListDlg : public QDialog, public Ui::CreateInvList
{
	Q_OBJECT
public:
	CreateInvListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateInvListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int inventorizationID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenInvDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::InventorizationList *inventorizationList = new BusinessLayer::InventorizationList();
	void SetInvListParams(int, int, int, double, int, int, int = 0);
	void FillEditElements(int, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};
#endif //CREATEORDLITDLG_H