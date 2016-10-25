#ifndef CREATEMSRDLG_H
#define CREATEMSRDLG_H
#include "ui_CreateMsrDlg.h"

class CreateMsrDlg :public QDialog, public Ui::CreateMeasure
{
	Q_OBJECT
public:
	CreateMsrDlg(QWidget *parent = 0);
	~CreateMsrDlg();
};
#endif //CREATEMSRDLG_H