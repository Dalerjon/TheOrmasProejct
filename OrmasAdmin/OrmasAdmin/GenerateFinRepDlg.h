#ifndef GENERATEFINREPDLG_H
#define GENERATEFINREPDLG_H

#include "ui_GenerateFinRepDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class GenerateFinRep : public QDialog, public Ui::GenerateFinancialReport
{
	Q_OBJECT
public:
	GenerateFinRep(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~GenerateFinRep();
	BusinessLayer::OrmasBL *dialogBL;
	std::string errorMessage = "";
	private slots:
	void Generate();
	void Close();
private:
	BusinessLayer::FinancialReport *fReport = new BusinessLayer::FinancialReport();
	QWidget* parentForm;
	MainForm* mainForm;
	std::string prevFromMonth;
	std::string prevTillMonth;
};
#endif