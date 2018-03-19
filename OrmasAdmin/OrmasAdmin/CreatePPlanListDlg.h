#ifndef CREATEPPLANLISTDLG_H
#define CREATEPPLANLISTDLG_H
#include "ui_CreatePPlanListDlg.h"
#include "OrmasBL.h"

class CreatePPlanListDlg : public QDialog, public Ui::CreatePPlanList
{
	Q_OBJECT
public:
	CreatePPlanListDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreatePPlanListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	int productionPlanID = 0;
	private slots:
	void AddProductToList();
	void EditProductInList();
	void DeleteProduct(){};
	void Close();
	void OpenPPlanDlg();
	void OpenProdDlg();
	void OpenStsDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::ProductionPlanList *productionPlanList = new BusinessLayer::ProductionPlanList();
	void SetproductionPlanListParams(int, int, int, double, int, int, int = 0);
	void FillEditElements(int, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
};
#endif //CREATEPPlanLITDLG_H