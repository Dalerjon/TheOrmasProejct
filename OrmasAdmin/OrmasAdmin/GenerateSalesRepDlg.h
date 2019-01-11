#ifndef GENERATESALESREPDLG_H
#define GENERATESALESREPDLG_H

#include "ui_GenerateSalesRepDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class GenerateSalesRep : public QDialog, public Ui::GenerateSalesReport
{
	Q_OBJECT
public:
	GenerateSalesRep(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~GenerateSalesRep();
	BusinessLayer::OrmasBL *dialogBL;
	std::string errorMessage = "";
	private slots:
	void Generate();
	void Close();
private:
	QWidget* parentForm;
	MainForm* mainForm;
	std::string prevFromMonth;
	std::string prevTillMonth;
};
#endif