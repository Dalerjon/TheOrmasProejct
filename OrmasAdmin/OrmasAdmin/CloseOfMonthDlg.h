#ifndef CLOSEOFMONTH_H
#define CLOSEOFMONTH_H

#include "ui_CloseOfMonthDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"
#include "CloseOfMonthInfoDlg.h"

class CloseOfMonthDlg : public QDialog, public Ui::CloseOfMonth
{
	Q_OBJECT
public:
	CloseOfMonthDlg(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~CloseOfMonthDlg();
	BusinessLayer::OrmasBL *dialogBL;
	std::string errorMessage = "";
	private slots:
	void Calculate();
	void Close();
private:
	QWidget* parentForm;
	MainForm* mainForm;
};
#endif //CLOSEOFMONTH_H