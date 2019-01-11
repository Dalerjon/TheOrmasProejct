#ifndef GENERATESPECREPDLG_H
#define GENERATESPECREPDLG_H

#include "ui_GenerateSpecRepDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class GenerateSpecRep : public QDialog, public Ui::GenerateSpecificationReport
{
	Q_OBJECT
public:
	GenerateSpecRep(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~GenerateSpecRep();
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