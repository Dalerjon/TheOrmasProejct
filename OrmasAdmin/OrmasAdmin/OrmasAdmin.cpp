// OrmasDesktop.cpp : Defines the entry point for the application.
//


#include "stdafx.h"
#include <iostream>
#include "MainForm.h"
#include "OrmasBL.h"
#include "LoginForm.h"
#include "ConfigParser.h"
#include <QString>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QTranslator myTranslator;
	myTranslator.load("ormasadmin_ru");
	app.installTranslator(&myTranslator);
	QResource::registerResource("OrmasResource.rcc");
	BusinessLayer::OrmasBL *oBL = new BusinessLayer::OrmasBL();
	ConfigParser conParser;
	std::string executablePath = qApp->applicationDirPath().toStdString();
	executablePath += "/";
	executablePath += "appconfig.xml";
	conParser.LoadConfig(executablePath.c_str());
	if (conParser.IsEmpty())
	{
		QMessageBox::information(NULL, QString(QObject::tr("Error")),
			QString(QObject::tr("DB credentiials are wrong!")),
			QString(QObject::tr("Ok")));
		return -1;
	}
	if (!oBL->ConnectToDB(conParser.dbName, conParser.dbUsername, conParser.dbPassword, conParser.dbIPAddress, conParser.port))
	{
		QMessageBox::information(NULL, QString(QObject::tr("Error")),
			QString(QObject::tr("Cannot connect to DB!")),
			QString(QObject::tr("Ok")));
		return -1;
	}
	BusinessLayer::User *loggedUser = new BusinessLayer::User();
	LoginForm logForm(oBL, loggedUser);
	logForm.setWindowIcon(QIcon("./images/ormas.png"));
	logForm.exec();
	if (!loggedUser->IsEmpty())
	{
		MainForm startForm(oBL, loggedUser);
		startForm.setWindowState(Qt::WindowMaximized);
		startForm.show();
		startForm.setWindowIcon(QIcon("./images/ormas.png"));
		return app.exec();
	}
}

