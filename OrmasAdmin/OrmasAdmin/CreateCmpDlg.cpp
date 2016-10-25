#include "stdafx.h"
#include "CreateCmpDlg.h"
#include <QMessageBox>

CreateCmpDlg::CreateCmpDlg(QWidget *parent) :QDialog(parent)
{
	setupUi(this);
}

void CreateCmpDlg::CreateCompany()
{
	if (!(nameEdit->text().isEmpty() || phoneEdit->text().isEmpty() || addressEdit->text().isEmpty()))
	{
		
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText(tr("Please fill name, phone and address!"));
		msgBox.exec();
	}
}
