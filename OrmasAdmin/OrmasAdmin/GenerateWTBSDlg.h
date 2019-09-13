#ifndef GENERATEWTBSDLG_H
#define GENERATEWTBSDLG_H

#include "ui_GenerateWTBSDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class GenerateWTBS : public QDialog, public Ui::GenerateWarehouseTurnover
{
	Q_OBJECT
public:
	GenerateWTBS(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~GenerateWTBS();
	BusinessLayer::OrmasBL *dialogBL;
	std::string errorMessage = "";
	private slots:
	void Generate();
	void Close();
	void InitComboBox();
	std::string GetPrevMonthEnd(std::string);
private:
	QWidget* parentForm;
	MainForm* mainForm;
	std::string prevFromMonth;
	std::string prevTillMonth;
};
#endif