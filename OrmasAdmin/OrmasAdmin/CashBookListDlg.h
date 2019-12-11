#ifndef CASHBOOKLISTDLG_H
#define CASHBOOKLISTDLG_H

#include "ui_CashBookListDlg.h"
#include "OrmasBL.h"
#include "MainForm.h"

class CashBookListDlg : public QDialog, public Ui::CashBookList
{
	Q_OBJECT
public:
	CashBookListDlg(BusinessLayer::OrmasBL *ormasBL, QWidget *parent = 0);
	~CashBookListDlg();
	BusinessLayer::OrmasBL *dialogBL;
	std::string errorMessage = "";
	private slots:
	void Generate();
	void Close();
	void GetPrevMonthEnd(std::string, std::string&, std::string&, std::string&, std::string&);
	std::string GetCurrentDate();
private:
	double InSum = 0;
	double OutSum = 0;
	QWidget* parentForm;
	MainForm* mainForm;
	std::string currDate = "";
};
#endif //CASHBOOKLISTDLG_H