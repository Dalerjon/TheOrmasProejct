#ifndef LOGINFORM_H
#define LOGINFORM_H

#include "ui_LoginForm.h"
#include "OrmasBL.h"


class LoginForm : public QDialog, public Ui::LoginDlg
{
	Q_OBJECT
public:
	LoginForm(BusinessLayer::OrmasBL *ormasBL, BusinessLayer::User* user);
	~LoginForm(){};
	BusinessLayer::OrmasBL *oBL;
	private slots :
	void CheckCredentials();
	void Close();
private:
	void CreateConnections();
	BusinessLayer::User* loggedUser = new BusinessLayer::User();
};

#endif //LOGINFORM_H