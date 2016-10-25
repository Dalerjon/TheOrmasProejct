#ifndef CREATEPRDTPDLG_H
#define CREATEPRDTPDLG_H
#include "ui_CreatePrdTpDlg.h"

class CreatePrdTpDlg :public QDialog, public Ui::CreateProductType
{
	Q_OBJECT
public:
	CreatePrdTpDlg(QWidget *parent = 0);
	~CreatePrdTpDlg();
};
#endif //CREATEPRDTPDLG_H