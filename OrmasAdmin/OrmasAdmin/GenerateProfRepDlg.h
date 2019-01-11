#ifndef GENERATEPROFREPDLG_H
#define GENERATEPROFREPDLG_H

#include "ui_GenerateProfRepDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class GenerateProfRep : public QDialog, public Ui::GenerateProfitabilityReport
{
	Q_OBJECT
public:
	GenerateProfRep(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~GenerateProfRep();
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