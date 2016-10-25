#ifndef CREATECURDLG_H
#define CREATECURDLG_H
#include "ui_CreateCurDlg.h"

class CreateCurDlg : public QDialog, public Ui::CreateCurrency
{
	Q_OBJECT
public:
	CreateCurDlg(QWidget *parent = 0);
	~CreateCurDlg();
	void CreateCompany();
	void UpdateCompany();
	void DeleteCompany();

};
#endif //CREATECURDLG_H