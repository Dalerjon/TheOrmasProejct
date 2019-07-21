#ifndef CREATEPRDBRNDLG_H
#define CREATEPRDBRNDLG_H
#include "ui_CreatePrdBrnDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CreatePrdBrnDlg : public QDialog, public Ui::CreateProductBranch
{
	Q_OBJECT
public:
	CreatePrdBrnDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreatePrdBrnDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateProductBranch();
	void EditProductBranch();
	void DeleteProductBranch(){};
	void Close();
	void OpenBrnDlg();
	void OpenProdDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::ProductBranchRelation *productBranch = new BusinessLayer::ProductBranchRelation();
	void SetProductBranchParams(int, int, int = 0);
	void FillEditElements(int, int);
	QIntValidator *vInt = nullptr;
	QWidget* parentForm;
	MainForm* mainForm;
};

#endif //CREATEPrdBrnDLG_H