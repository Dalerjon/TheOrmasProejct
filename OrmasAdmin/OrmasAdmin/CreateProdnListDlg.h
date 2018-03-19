#ifndef CREATEPRDNLISTDLG_H
#define CREATEPRDNLISTDLG_H
#include "ui_CreatePrdnListDlg.h"
#include "OrmasBL.h"

class CreateProdnListDlg : public QDialog, public Ui::CreatePrdnList
{
	Q_OBJECT
public:
	CreateProdnListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateProdnListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int productionID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenPrdnDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::ProductionList *productionList = new BusinessLayer::ProductionList();
	void SetProductionListParams(int, int, int, double, int, int, int = 0);
	void FillEditElements(int, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};
#endif //CREATEPRDNLITDLG_H