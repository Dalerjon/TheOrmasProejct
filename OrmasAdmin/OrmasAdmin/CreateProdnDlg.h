#ifndef CREATEPRODUCTIONDLG_H
#define CREATEPRODUCTIONDLG_H
#include "ui_CreateProdnDlg.h"
#include "OrmasBL.h"

class CreateProdnDlg : public QDialog, public Ui::CreateProduction
{
	Q_OBJECT
public:
	CreateProdnDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateProdnDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateProduction();
	void EditProduction();
	void DeleteProduction(){};
	void Close();
	void OpenProdnListDlg();
    signals:
	void CloseCreatedForms();
private:
	BusinessLayer::Production *production = new BusinessLayer::Production();
	void SetProductionParams(QString, QString, QString, QString, int=0);
	void FillEditElements(QString, QString, QString, QString);
};

#endif //CREATEPRODNDLG_H
