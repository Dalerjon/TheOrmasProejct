#include "stdafx.h"
#include "LoginForm.h"

LoginForm::LoginForm(BusinessLayer::OrmasBL *ormasBL, BusinessLayer::User* user)
{
	setupUi(this);
	messageLb->setStyleSheet("color : red");
	loggedUser = user;
	oBL = ormasBL;
	CreateConnections();
}

void LoginForm::CreateConnections()
{
	QObject::connect(cancelBtn, &QPushButton::released, this, &LoginForm::Close);
	QObject::connect(okBtn, &QPushButton::released, this, &LoginForm::CheckCredentials);
}

void LoginForm::CheckCredentials()
{
	std::string errorMessage = "";
	if (userEdit->text().isEmpty() && passwordEdit->text().isEmpty())
	{
		messageLb->setText("Please fill up username and password fields!");
	}
	if (loggedUser->GetUserByCredentials(oBL->GetOrmasDal(), userEdit->text().toUtf8().constData(), passwordEdit->text().toUtf8().constData()))
	{
		BusinessLayer::Role *userRole = new BusinessLayer::Role();
		if (!userRole->GetRoleByID(oBL->GetOrmasDal(), loggedUser->GetRoleID(), errorMessage))
		{
			userEdit->setText("");
			passwordEdit->setText("");
			messageLb->setText(tr("Wrong username or password!"));
			return;
		}
		if (userRole->GetName() == "CLIENT")
		{
			userEdit->setText("");
			passwordEdit->setText("");
			messageLb->setText(tr("Wrong username or password!"));
			return;
		}
		this->close();
	}
	else
	{
		userEdit->setText("");
		passwordEdit->setText("");
		messageLb->setText(tr("Wrong username or password!"));
	}
}

void LoginForm::Close()
{
	
	this->close();
}