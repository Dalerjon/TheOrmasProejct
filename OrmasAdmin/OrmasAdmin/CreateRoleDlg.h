#ifndef CREATEROLEDLG_H
#define CREATEROLEDLG_H
#include "ui_CreateRoleDlg.h"

class CreateRoleDlg :public QDialog, public Ui::CreateRole
{
	Q_OBJECT
public:
	CreateRoleDlg(QWidget *parent = 0);
	~CreateRoleDlg();
};
#endif //CREATEROLEDLG_H