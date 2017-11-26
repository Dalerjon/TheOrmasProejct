// OrmasDesktop.cpp : Defines the entry point for the application.
//


#include "stdafx.h"
#include <iostream>
#include <QApplication>
#include <QtGUI>
#include <QWidget>
#include <QMenu>
#include "MainForm.h"
#include "OrmasBL.h"
#include "LoginForm.h"
#include <QResource>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QTranslator myTranslator;
	myTranslator.load("ormasadmin_ru");
	app.installTranslator(&myTranslator);
	QResource::registerResource("OrmasResource.rcc");
	BusinessLayer::OrmasBL *oBL = new BusinessLayer::OrmasBL();
	oBL->ConnectToDB("OrmasDB", "postgres", "postgres", "127.0.0.1", 5432);
	BusinessLayer::User *loggedUser = new BusinessLayer::User();
	LoginForm logForm(oBL, loggedUser);
	logForm.exec();
	if (!loggedUser->IsEmpty())
	{
		MainForm startForm(oBL, loggedUser);
		startForm.show();
		return app.exec();
	}
}

