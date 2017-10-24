#ifndef CREATEROLEDLG_H
#define CREATEROLEDLG_H
#include "ui_CreateRoleDlg.h"
#include "OrmasBL.h"

class CreateRoleDlg :public QDialog, public Ui::CreateRole
{
	Q_OBJECT
public:
	CreateRoleDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateRoleDlg(){};
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
private slots:
	void CreateRole();
	void EditRole();
	void DeleteRole(){};
	void Close();
	void TextEditChanged();
private:
	BusinessLayer::Role *role = new BusinessLayer::Role();
	void SetRoleParams(QString, QString ,QString, int = 0);
	void FillEditElements(QString, QString, QString);
};
#endif //CREATEROLEDLG_H