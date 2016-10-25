#ifndef CREATESTSDLG_H
#define CREATESTSDLG_H
#include "ui_CreateStsDlg.h"

class CreateStsDlg :public QDialog, public Ui::CreateStatus
{
	Q_OBJECT
public:
	CreateStsDlg(QWidget *parent = 0);
	~CreateStsDlg();
};
#endif //CREATESTSDLG_H