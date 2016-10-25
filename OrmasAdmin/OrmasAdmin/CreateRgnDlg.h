#ifndef CREATERGNDLG_H
#define CREATERGNDLG_H
#include "ui_CreateRgnDlg.h"

class CreateRgnDlg :public QDialog, public Ui::CreateRegion
{
	Q_OBJECT
public:
	CreateRgnDlg(QWidget *parent = 0);
	~CreateRgnDlg();
};
#endif //CREATERGNDLG