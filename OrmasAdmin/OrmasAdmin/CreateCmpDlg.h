#ifndef CREATECMPDLG_H
#define CREATECMPDLG_H
#include "ui_CreateCmpDlg.h"
#include "OrmasBL.h"

class CreateCmpDlg : public QDialog, public Ui::CreateCompany
{
	Q_OBJECT
public:
	CreateCmpDlg(QWidget *parent = 0);
	~CreateCmpDlg(){};
private slots:
	void CreateCompany();
	void UpdateCompany();
	void DeleteCompany();
private:
	BusinessLayer::Company company;
};

#endif //CREATECMPDLG_H