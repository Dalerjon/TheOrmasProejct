#ifndef CASHINFODLG_H
#define CASHINFODLG_H

#include "ui_CashInfoDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CashInfoDlg : public QDialog, public Ui::CashInfo
{
	Q_OBJECT
public:
	CashInfoDlg(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~CashInfoDlg();
	BusinessLayer::OrmasBL *dialogBL;
	std::string errorMessage = "";
	private slots:
	void Close();
private:
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CASHINFODLG_H