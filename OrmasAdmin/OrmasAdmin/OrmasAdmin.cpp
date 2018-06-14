// OrmasDesktop.cpp : Defines the entry point for the application.
//


#include "stdafx.h"
#include <iostream>
#include "MainForm.h"
#include "OrmasBL.h"
#include "LoginForm.h"


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QTranslator myTranslator;
	myTranslator.load("ormasadmin_ru");
	app.installTranslator(&myTranslator);
	QResource::registerResource("OrmasResource.rcc");
	BusinessLayer::OrmasBL *oBL = new BusinessLayer::OrmasBL();
	oBL->ConnectToDB("SogdianaDB", "postgres", "postgres", "127.0.0.1", 5432);
	BusinessLayer::User *loggedUser = new BusinessLayer::User();
	LoginForm logForm(oBL, loggedUser);
	logForm.exec();
	if (!loggedUser->IsEmpty())
	{
		MainForm startForm(oBL, loggedUser);
		startForm.setWindowState(Qt::WindowMaximized);
		startForm.show();
		return app.exec();
	}
}

