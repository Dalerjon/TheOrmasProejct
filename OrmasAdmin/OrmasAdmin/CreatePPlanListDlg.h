#ifndef CREATEPPLANLISTDLG_H
#define CREATEPPLANLISTDLG_H
#include "ui_CreatePPlanListDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

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
	void TextEditChanged();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void DataIsChanged();
private:
	BusinessLayer::ProductionPlanList *productionPlanList = new BusinessLayer::ProductionPlanList();
	void SetproductionPlanListParams(int, int, double, double, int, int, int = 0);
	void FillEditElements(int, int, double, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	void InitComboBox();
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CREATEPPlanLITDLG_H