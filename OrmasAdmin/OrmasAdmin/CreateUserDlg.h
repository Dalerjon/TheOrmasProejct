#ifndef CREATEUSERDLG_H
#define CREATEUSERDLG_H
#include "ui_CreateUserDlg.h"
#include "OrmasBL.h"

class CreateUserDlg : public QDialog, public Ui::CreateUser
{
	Q_OBJECT
public:
	CreateUserDlg(BusinessLayer::OrmasBL *ormasBL, bool updateFlag, QWidget *parent = 0);
	~CreateUserDlg();
	BusinessLayer::OrmasBL *dialogBL;
	bool FillDlgElements(QTableView*);
	std::string errorMessage;
	private slots:
	void CreateUser();
	void EditUser();
	void DeleteUser(){};
	void Close();
	void OpenRoleDlg();
	public slots:
	void SetID(int ID, QString childName);
private:
	BusinessLayer::User *user = new BusinessLayer::User();
	void SetUserParams(QString, QString, QString, QString, QString, int, QString, QString, int = 0);
	void FillEditElements(QString, QString, QString, QString, QString, int, QString, QString);
	QIntValidator *vInt = nullptr;
};

#endif //CREATEUSERDLG_H