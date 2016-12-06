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

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	BusinessLayer::OrmasBL *oBL = new BusinessLayer::OrmasBL();
	oBL->ConnectToDB("OrmasDB", "postgres", "postgres", "127.0.0.1", 5432);
	MainForm startForm(oBL);
	startForm.show();
	return app.exec();
}

