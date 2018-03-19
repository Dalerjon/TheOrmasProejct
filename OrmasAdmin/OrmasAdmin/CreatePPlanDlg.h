#ifndef CREATEPPLANDLG_H
#define CREATEPPLANDLG_H

#include "ui_CreatePPlanDlg.h"
#include "OrmasBL.h"

class CreatePPlanDlg : public QDialog, public Ui::CreateProductionPlan
{
	Q_OBJECT
public:
	CreatePPlanDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreatePPlanDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateProductionPlan();
	void EditProductionPlan();
	void DeleteProductionPlan(){};
	void Close();
	void OpenEmpDlg();
	void OpenStsDlg();
	void OpenPPlanListDlg();
	public slots:
	void SetID(int ID, QString childName);
signals:
	void CloseCreatedForms();
private:
	BusinessLayer::ProductionPlan *productionPlan = new BusinessLayer::ProductionPlan();
	void SetProductionPlanParams(QString, int, int, double, int, int, int = 0);
	void FillEditElements(QString, int, int, double, int, int);
	QDoubleValidator *vDouble = nullptr;
	QIntValidator *vInt = nullptr;
	std::map<std::string, int> statusMap;
	void InitComboBox();
};
#endif //CREATEPPlan