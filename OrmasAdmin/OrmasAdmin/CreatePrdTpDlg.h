#ifndef CREATEPRDTPDLG_H
#define CREATEPRDTPDLG_H
#include "ui_CreatePrdTpDlg.h"
#include "OrmasBL.h"

class CreatePrdTpDlg :public QDialog, public Ui::CreateProductType
{
	Q_OBJECT
public:
	CreatePrdTpDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreatePrdTpDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
private slots:
	void CreateProductType();
	void EditProductType();
	void DeleteProductType(){};
	void Close();
private:
	BusinessLayer::ProductType *prodType = new BusinessLayer::ProductType();
	void SetProdTypeParams(QString, QString, QString, int = 0);
	void FillEditElements(QString, QString, QString);
	QWidget* parentForm;
};
#endif //CREATEPRDTPDLG_H